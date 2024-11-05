#ifndef CALCULATINGTIME_H
#define CALCULATINGTIME_H

#include <QWidget>
#include <QtWidgets>

class CalculatingTime : public QWidget
{
    Q_OBJECT
private:
    QTimeEdit* TimeEditBeginTime;
    QTimeEdit* TimeEditEndTime;
    QLabel* LabelDifferent;

public:
    explicit CalculatingTime(QWidget *parent = nullptr);

public slots:
    void slotCalculatingDifference();
};

#endif // CALCULATINGTIME_H
