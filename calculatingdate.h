#ifndef CALCULATINGDATE_H
#define CALCULATINGDATE_H

#include <QWidget>
#include <QtWidgets>

class CalculatingDate : public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout* HLayoutMainDate;
    QStackedWidget* stackWidgetMain;
    QLabel* LabelAnswer1;
    QDateEdit* DateEditC1;
    QDateEdit* DateEditDo;

    QLabel* LabelAnswer2;
    QDateEdit* DateEditC2;
    QRadioButton* RadioButtonAdd;
    QRadioButton* RadioButtonSubtract;
    QSpinBox* SpinBoxYears;
    QSpinBox* SpinBoxMonths;
    QSpinBox* SpinBoxDays;
    QCalendarWidget* CalendarWidget22;

public:
    explicit CalculatingDate(QWidget *parent = nullptr);

public slots:
    void ShowCalculationDate(bool);
    void CalculateDifference();
    void AddOrSubtract();
};

#endif // CALCULATINGDATE_H
