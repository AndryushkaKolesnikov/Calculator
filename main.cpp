#include "calculate.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Calculate calculate;
    calculate.setWindowTitle(QObject::tr("Calculator"));
    calculate.show();
    a.setFont(QFont("Segoe UI", 10, QFont::Normal));
    return a.exec();
}
