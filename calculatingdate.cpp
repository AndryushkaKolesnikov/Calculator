#include "calculatingdate.h"

CalculatingDate::CalculatingDate(QWidget *parent)
    : QWidget{parent}
{
    LabelAnswer1 = new QLabel;
    LabelAnswer2 = new QLabel;

    // Общий
    QRadioButton* radioButton1 = new QRadioButton(
        QObject::tr("The difference between the dates"));
    QRadioButton* radioButton2 = new QRadioButton(
        QObject::tr("Add or subtract"));
    radioButton1->setChecked(true);
    connect(radioButton1, SIGNAL(toggled(bool)),
            this, SLOT(ShowCalculationDate(bool)));
    HLayoutMainDate = new QVBoxLayout;
    HLayoutMainDate->addWidget(radioButton1);
    HLayoutMainDate->addWidget(radioButton2);

    // Разница между датами
    QWidget* widget1 = new QWidget;
    QHBoxLayout* HLayoutWidget1 = new QHBoxLayout;

    QVBoxLayout* VLayout1 = new QVBoxLayout;
    QLabel* LabelC1 = new QLabel(QObject::tr("With"));
    DateEditC1 = new QDateEdit;
    QLabel* LabelDo = new QLabel(QObject::tr("Before"));
    DateEditDo = new QDateEdit;
    QLabel* LabelR = new QLabel(QObject::tr("Difference:"));
    QCalendarWidget* CalendarWidget11 = new QCalendarWidget;
    CalendarWidget11->setFixedSize(350, 350);
    QCalendarWidget* CalendarWidget12 = new QCalendarWidget;
    CalendarWidget12->setFixedSize(350, 350);

    connect(DateEditC1, SIGNAL(dateChanged(QDate)),
            CalendarWidget11, SLOT(setSelectedDate(QDate)));

    connect(DateEditDo, SIGNAL(dateChanged(QDate)),
            CalendarWidget12, SLOT(setSelectedDate(QDate)));

    connect(CalendarWidget11, SIGNAL(clicked(QDate)),
            DateEditC1, SLOT(setDate(QDate)));

    connect(CalendarWidget12, SIGNAL(clicked(QDate)),
            DateEditDo, SLOT(setDate(QDate)));
    // Соединение со слотом вычисления разницы
    connect(DateEditC1, SIGNAL(dateChanged(QDate)),
            this, SLOT(CalculateDifference()));

    connect(DateEditDo, SIGNAL(dateChanged(QDate)),
            this, SLOT(CalculateDifference()));

    VLayout1->addWidget(LabelC1);
    VLayout1->addWidget(DateEditC1);
    VLayout1->addWidget(LabelDo);
    VLayout1->addWidget(DateEditDo);
    VLayout1->addWidget(LabelR);
    VLayout1->addWidget(LabelAnswer1);
    HLayoutWidget1->addLayout(VLayout1);
    HLayoutWidget1->addWidget(CalendarWidget11);
    HLayoutWidget1->addWidget(CalendarWidget12);
    widget1->setLayout(HLayoutWidget1);

    // Добавить или вычесть дни
    QWidget* widget2 = new QWidget;
    QHBoxLayout* HLayoutWidget2 = new QHBoxLayout;

    QVBoxLayout* VLayout2 = new QVBoxLayout;
    QLabel* LabelC2 = new QLabel(QObject::tr("With"));
    DateEditC2 = new QDateEdit;
    VLayout2->addWidget(LabelC2);
    VLayout2->addWidget(DateEditC2);
    RadioButtonAdd = new QRadioButton(QObject::tr("Add"));
    RadioButtonSubtract = new QRadioButton(QObject::tr("Subtract"));
    RadioButtonAdd->setChecked(true);
    QHBoxLayout* HLayout = new QHBoxLayout;
    HLayout->addWidget(RadioButtonAdd);
    HLayout->addWidget(RadioButtonSubtract);
    QLabel* LabelYears = new QLabel(QObject::tr("Years"));
    SpinBoxYears = new QSpinBox;
    QLabel* LabelMonths = new QLabel(QObject::tr("Months"));
    SpinBoxMonths = new QSpinBox;
    QLabel* LabelDays = new QLabel(QObject::tr("Days"));
    SpinBoxDays = new QSpinBox;
    QGridLayout* GridLayout = new QGridLayout;
    GridLayout->addWidget(LabelYears, 0, 0);
    GridLayout->addWidget(SpinBoxYears, 1, 0);
    GridLayout->addWidget(LabelMonths, 0, 1);
    GridLayout->addWidget(SpinBoxMonths, 1, 1);
    GridLayout->addWidget(LabelDays, 0, 2);
    GridLayout->addWidget(SpinBoxDays, 1, 2);
    QLabel* LabelDate = new QLabel(QObject::tr("Date"));
    VLayout2->addLayout(HLayout);
    VLayout2->addLayout(GridLayout);
    VLayout2->addWidget(LabelDate);
    VLayout2->addWidget(LabelAnswer2);

    QCalendarWidget* CalendarWidget21 = new QCalendarWidget;
    CalendarWidget21->setFixedSize(350, 350);
    CalendarWidget22 = new QCalendarWidget;
    CalendarWidget22->setFixedSize(350, 350);

    connect(DateEditC2, SIGNAL(dateChanged(QDate)),
            CalendarWidget21, SLOT(setSelectedDate(QDate)));

    connect(CalendarWidget21, SIGNAL(clicked(QDate)),
            DateEditC2, SLOT(setDate(QDate)));
    // соединение со слотом добавить или вычесть
    connect(DateEditC2, SIGNAL(dateChanged(QDate)),
            this, SLOT(AddOrSubtract()));

    connect(SpinBoxDays, SIGNAL(valueChanged(int)),
            this, SLOT(AddOrSubtract()));

    connect(SpinBoxMonths, SIGNAL(valueChanged(int)),
            this, SLOT(AddOrSubtract()));

    connect(SpinBoxYears, SIGNAL(valueChanged(int)),
            this, SLOT(AddOrSubtract()));

    HLayoutWidget2->addLayout(VLayout2);
    HLayoutWidget2->addWidget(CalendarWidget21);
    HLayoutWidget2->addWidget(CalendarWidget22);
    widget2->setLayout(HLayoutWidget2);

    stackWidgetMain = new QStackedWidget;
    stackWidgetMain->addWidget(widget1);
    stackWidgetMain->addWidget(widget2);

    HLayoutMainDate->addWidget(stackWidgetMain);
    setLayout(HLayoutMainDate);
    }
//...................................................................
void CalculatingDate::ShowCalculationDate(bool b)
{
    if(b == true) stackWidgetMain->setCurrentIndex(0);
    else stackWidgetMain->setCurrentIndex(1);
}
//...................................................................
void CalculatingDate::CalculateDifference()
{
    QDate dateC(DateEditC1->date());
    QDate dateDo(DateEditDo->date());
    if(dateDo == dateC){
        LabelAnswer1->setText(QObject::tr("The same date"));
        return;
    }
    int Result;
    Result = std::abs(dateC.daysTo(dateDo));
    QString str = QString::number(Result);
    LabelAnswer1->setText(str + QObject::tr(" days"));
}
//...................................................................
void CalculatingDate::AddOrSubtract()
{
    QDate dateC(DateEditC2->date());
    if (RadioButtonAdd->isChecked()) {
        dateC = dateC.addYears(SpinBoxYears->value());
        dateC = dateC.addMonths(SpinBoxMonths->value());
        dateC = dateC.addDays(SpinBoxDays->value());

    }
    else {
        dateC = dateC.addDays(-(SpinBoxDays->value()));
        dateC = dateC.addMonths(-(SpinBoxMonths->value()));
        dateC = dateC.addYears(-(SpinBoxYears->value()));
    }
    QString str;
    str = dateC.toString("dd.MM.yyyy");
    LabelAnswer2->setText(str);
    CalendarWidget22->setSelectedDate(dateC);
}
