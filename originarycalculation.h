#ifndef ORIGINARYCALCULATION_H
#define ORIGINARYCALCULATION_H

#include <QWidget>
#include <QtWidgets>
class OriginaryCalculation : public QWidget
{
    Q_OBJECT
private:
    QLCDNumber* plcd;
    QStack<QString> stk;
    QString strDisplay;
    QLabel* storyLabel;
public:
    explicit OriginaryCalculation(QWidget *parent = nullptr);
    QPushButton* createButton(const QString&);
    void calculate();

public slots:
    void slotButtonClicked();
};

#endif // ORIGINARYCALCULATION_H
