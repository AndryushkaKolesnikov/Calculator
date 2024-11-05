#include "calculate.h"
#include "ui_calculate.h"

Calculate::Calculate(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculate)
{
    widgetOriginaryCalculate = new OriginaryCalculation;
    widgetCalculatingDate = new CalculatingDate;
    widgetCalculatingTime = new CalculatingTime;
    widgetTimeConvert = new TimeConvert;
    ui->setupUi(this);
    // Создание стека виджетов
    stackWidgetMain = new QStackedWidget;
    stackWidgetMain->addWidget(widgetOriginaryCalculate);
    stackWidgetMain->addWidget(widgetCalculatingDate);
    stackWidgetMain->addWidget(widgetCalculatingTime);
    stackWidgetMain->addWidget(widgetTimeConvert);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(stackWidgetMain);
    ui->centralwidget->setLayout(layout);

    // Главное меню
    QMenu* menuCalculators = new QMenu(QObject::tr("Calculators"));
    menuCalculators->addAction(QObject::tr("Usual"),
                     this, SLOT(ShowOriginary()));
    menuCalculators->addAction(QObject::tr("Calculating the date"),
                     this, SLOT(ShowComboBox()));
    menuCalculators->addAction(QObject::tr("Calculating the time"),
                     this, SLOT(ShowTime()));

    QMenu* menuConverter = new QMenu(QObject::tr("Converters"));
    menuConverter->addAction(QObject::tr("Time"),
                             this, SLOT(ShowTimeConvert()));
    QMenu* menu2 = new QMenu(QObject::tr("Parameters"));
    menu2->addAction(QObject::tr("About Qt"),
                     qApp, SLOT(aboutQt()));

    menuBar()->addMenu(menuCalculators);
    menuBar()->addMenu(menuConverter);
    menuBar()->addMenu(menu2);
}
//...................................................................
Calculate::~Calculate()
{
    delete ui;
}
//...................................................................
// Обычный калькулятор
void Calculate::ShowOriginary()
{
    stackWidgetMain->setCurrentWidget(widgetOriginaryCalculate);
}
//...................................................................
// Вычисление даты
void Calculate::ShowComboBox()
{
    stackWidgetMain->setCurrentWidget(widgetCalculatingDate);
}
//...................................................................
// Длительность времени
void Calculate::ShowTime()
{
    stackWidgetMain->setCurrentWidget(widgetCalculatingTime);
}
//...................................................................
// Конвертер единиц времени
void Calculate::ShowTimeConvert()
{
    stackWidgetMain->setCurrentWidget(widgetTimeConvert);
}
