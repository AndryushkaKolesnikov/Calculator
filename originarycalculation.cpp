#include "originarycalculation.h"

OriginaryCalculation::OriginaryCalculation(QWidget *parent)
    : QWidget{parent}
{
    plcd = new QLCDNumber(12);
    plcd->setSegmentStyle(QLCDNumber::Flat);
    plcd->setMinimumSize(150, 50);

    QChar aButtom[4][4] = {{'7', '8', '9', '/'},
                           {'4', '5', '6', '*'},
                           {'1', '2', '3', '-'},
                           {'0', '_', '=', '+'}};

    // Layout setup
    QGridLayout* gridLayout = new QGridLayout;
    gridLayout->addWidget(plcd, 0, 0, 1, 4);
    gridLayout->addWidget(createButton("CE"), 1, 3);

    for(int i = 0; i<4; ++i){
        for(int j = 0; j < 4; ++j) {
            gridLayout->addWidget(createButton(aButtom[i][j]),
                                  i+2, j);
        }
    }
    storyLabel = new QLabel("Журнал");
    storyLabel->setAlignment(Qt::AlignHCenter);
    QHBoxLayout* HBoxLayout = new QHBoxLayout;
    HBoxLayout->addLayout(gridLayout);
    HBoxLayout->addWidget(storyLabel);
    setLayout(HBoxLayout);
}
//...................................................................
void OriginaryCalculation::slotButtonClicked()
{
    QString str = ((QPushButton*)sender())->text();

    if (str == "CE") {
        stk.clear();
        strDisplay = "";
        plcd->display("0");
        return;
    }
    if (str.contains(QRegExp("[0-9]"))) {
        strDisplay +=str;
        plcd->display(strDisplay.toDouble());
    }
    else if (str == ".") {
        strDisplay += str;
        plcd->display(strDisplay);
    }
    else {
        if (stk.count() >= 2) {
            stk.push(QString().setNum(plcd->value()));
            calculate();
            stk.clear();
            stk.push(QString().setNum(plcd->value()));
            if (str != "=") {
                stk.push(str);
            }
        }
        else {
            stk.push(QString().setNum(plcd->value()));
            stk.push(str);
            strDisplay = "";
        }
    }
}
//...................................................................
void OriginaryCalculation::calculate()
{
    qreal fOperand2 = stk.pop().toFloat();
    QString strOperation = stk.pop();
    qreal fOperand1 = stk.pop().toFloat();
    qreal fResult = 0;

    if (strOperation == "+") {
        fResult = fOperand1 + fOperand2;
    }
    if (strOperation == "-") {
        fResult = fOperand1 - fOperand2;
    }
    if (strOperation == "/") {
        fResult = fOperand1 - fOperand2;
    }
    if (strOperation == "*") {
        fResult = fOperand1 * fOperand2;
    }
    QString str = storyLabel->text() + "\n" + QString::number(fOperand1)
                  + strOperation + QString::number(fOperand2) + " = " +
                  QString::number(fResult);
    storyLabel->setText(str);
    plcd->display(fResult);
}
//...................................................................
QPushButton* OriginaryCalculation::createButton(const QString& str)
{
    QPushButton* pcmd = new QPushButton(str);
    pcmd->setMinimumSize(40, 40);
    connect(pcmd, SIGNAL(clicked()), SLOT(slotButtonClicked()));
    return pcmd;
}
