#ifndef TIMECONVERT_H
#define TIMECONVERT_H

#include <QWidget>
#include <QtWidgets>

class TimeConvert : public QWidget
{
    Q_OBJECT
private:
    QComboBox* ComboBox1;
    QComboBox* ComboBox2;
    bool Comma = true;
    QLCDNumber* LCDNumber1;
    QLCDNumber* LCDNumber2;
    QString strDisplay;

public:
    explicit TimeConvert(QWidget *parent = nullptr);
    QPushButton* createButton(const QString&);
    void TranslateToDifference(double);

public slots:
    void slotButtonClicked();
    void slotTranslationToSec();
};


#endif // TIMECONVERT_H
