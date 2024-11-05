#include "calculatingtime.h"

CalculatingTime::CalculatingTime(QWidget *parent)
    : QWidget{parent}
{
    QLabel* LabelBeginTime = new QLabel(QObject::tr("First time"));
    TimeEditBeginTime = new QTimeEdit;
    QLabel* LabelEndTime = new QLabel(QObject::tr("Second time"));
    TimeEditEndTime = new QTimeEdit;
    QLabel* Label = new QLabel(QObject::tr("different: "));
    LabelDifferent = new QLabel;
    QVBoxLayout* VLayout = new QVBoxLayout;
    VLayout->addWidget(LabelBeginTime);
    VLayout->addWidget(TimeEditBeginTime);
    VLayout->addWidget(LabelEndTime);
    VLayout->addWidget(TimeEditEndTime);
    VLayout->addWidget(Label);
    VLayout->addWidget(LabelDifferent);
    setLayout(VLayout);

    connect(TimeEditBeginTime, SIGNAL(timeChanged(QTime)),
            this, SLOT(slotCalculatingDifference()));
    connect(TimeEditEndTime, SIGNAL(timeChanged(QTime)),
            this, SLOT(slotCalculatingDifference()));
}
//...................................................................
void CalculatingTime::slotCalculatingDifference()
{
    QTime TimeBegin(TimeEditBeginTime->time());
    QTime TimeEnd(TimeEditEndTime->time());
    if (TimeBegin == TimeEnd) {
        LabelDifferent->setText("The same time");
    }
    int IntDifference = std::abs(TimeBegin.secsTo(TimeEnd));
    int IntHours = IntDifference/3600;
    int IntMinuts = std::abs((IntDifference % 3600) / 60);

    QString String = QString::number(IntHours) + ":"
                     + QString::number(IntMinuts);
    LabelDifferent->setText(String);
}
