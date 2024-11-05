#include "timeconvert.h"

TimeConvert::TimeConvert(QWidget *parent)
    : QWidget{parent}
{
    QVBoxLayout* HLayout = new QVBoxLayout;
    LCDNumber1 = new QLCDNumber(20);
    ComboBox1 = new QComboBox;
    LCDNumber2 = new QLCDNumber(20);
    ComboBox2 = new QComboBox;
    QStringList List;
    List << "микросекунд" << "милисекунд" << "секунд"
         << "минут" << "часы" << "дней" << "недель" << "лет";
    ComboBox1->addItems(List);
    ComboBox2->addItems(List);
    connect(ComboBox1, SIGNAL(currentIndexChanged(int)),
            this, SLOT(slotTranslationToSec()));

    connect(ComboBox2, SIGNAL(currentIndexChanged(int)),
            this, SLOT(slotTranslationToSec()));

    QChar aButtom[3][3] = {{'7', '8', '9'},
                           {'4', '5', '6'},
                           {'1', '2', '3'}};
    QGridLayout* GridLayout = new QGridLayout;
    GridLayout->addWidget(createButton("CE"), 0, 1);
    GridLayout->addWidget(createButton("0"), 4, 1);
    GridLayout->addWidget(createButton("."), 4, 2);
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j) {
            GridLayout->addWidget(createButton(aButtom[i][j]),
                                  i+1, j);
        }
    }
    HLayout->addWidget(LCDNumber1);
    HLayout->addWidget(ComboBox1);
    HLayout->addWidget(LCDNumber2);
    HLayout->addWidget(ComboBox2);
    HLayout->addLayout(GridLayout);
    setLayout(HLayout);
}
//...................................................................
QPushButton* TimeConvert::createButton(const QString& str)
{
    QPushButton* pcmd = new QPushButton(str);
    pcmd->setMinimumSize(40, 40);
    connect(pcmd, SIGNAL(clicked()), SLOT(slotButtonClicked()));
    return pcmd;
}
//...................................................................
void TimeConvert::slotButtonClicked()
{
    QString str = ((QPushButton*)sender())->text();
    if (str == "CE") {
        Comma = true;
        LCDNumber1->display("0");
        LCDNumber2->display("0");
        strDisplay = "";
        return;
    }
    if (str.contains(QRegExp("[0-9]"))) {
        strDisplay += str;
        LCDNumber1->display(strDisplay);

    }
    else {
        if (Comma == true) {
            strDisplay += str;
            LCDNumber1->display(strDisplay);
            Comma = false;
        }
    }
    slotTranslationToSec();
}
// Перевод в секунды
//...................................................................
void TimeConvert::slotTranslationToSec()
{
    double value(LCDNumber1->value());
    int currentIndex(ComboBox1->currentIndex());
    switch(currentIndex) {
    case 0:
        value *= 0.000001;
        break;
    case 1:
        value *= 0.001;
        break;
    case 3:
        value *= 60;
        break;
    case 4:
        value *= 3600;
        break;
    case 5:
        value *= 86400;
        break;
    case 6:
        value *= 604800;
        break;
    case 7:
        value *= 31557600;
        break;
    }
    TranslateToDifference(value);
}
// Перевод в нужные единицы измерения
//...................................................................
void TimeConvert::TranslateToDifference(double value)
{
    int currentIndex(ComboBox2->currentIndex());
    switch (currentIndex) {
    case 0:
        value *= 1000000;
        break;
    case 1:
        value *= 1000;
        break;
    case 3:
        value *= 0.016667;
        break;
    case 4:
        value *= 0.000278;
        break;
    case 5:
        value *= 0.000012;
        break;
    case 6:
        value *= 0.000002;
        break;
    case 7:
        value *= 0.000000031688088;
        break;
    }
    LCDNumber2->display(value);
}
