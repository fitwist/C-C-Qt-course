#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include "chartview.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ChartView *chartView = new ChartView();
    QMainWindow window;
    window.setCentralWidget(chartView);
    window.resize(1366, 768);
    window.show();

    return a.exec();
}
