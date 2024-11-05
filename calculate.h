#ifndef CALCULATE_H
#define CALCULATE_H

#include "originarycalculation.h"
#include "calculatingdate.h"
#include "calculatingtime.h"
#include "timeconvert.h"

#include <QMainWindow>
#include <QtWidgets>
QT_BEGIN_NAMESPACE
namespace Ui {
class Calculate;
}
QT_END_NAMESPACE

class Calculate : public QMainWindow
{
    Q_OBJECT
private:
    Ui::Calculate *ui;
    QWidget* centralWidget;
    QStackedWidget* stackWidgetMain;

    OriginaryCalculation* widgetOriginaryCalculate;
    CalculatingDate* widgetCalculatingDate;
    CalculatingTime* widgetCalculatingTime;
    TimeConvert* widgetTimeConvert;

public:
    Calculate(QWidget *parent = nullptr);
    ~Calculate();

public slots:
    void ShowOriginary();
    void ShowComboBox();
    void ShowTime();
    void ShowTimeConvert();

};
#endif // CALCULATE_H
