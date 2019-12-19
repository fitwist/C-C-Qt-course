#include "ui_chartview.h"
#include <QtCharts/QScatterSeries>
#include <QValueAxis>
#include <QtCharts/QLegendMarker>
#include <QtGui/QImage>
#include <QtGui/QPainter>
#include <QtCore/QtMath>
#include <QFile>
#include <QTextStream>
#include <QPointF>
#include "chartview.h"
#include <QDebug>

ChartView::ChartView(QWidget *parent) :
    QChartView(new QChart(), parent)
{

    QScatterSeries *series0 = new QScatterSeries();
    series0->setMarkerShape(QScatterSeries::MarkerShapeCircle);
    series0->setMarkerSize(10.0);

    QFile plot_data;
    QString data;
    QStringList coordinateList;

    plot_data.setFileName("/home/helen/Документы/C-C-Qt-course/24_tochechnaya_diagramma/dataset.csv");
    plot_data.open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream ts(&plot_data);
    QString line;
    while(!ts.atEnd()) {
        line = ts.readLine();
        QStringList list = line.split(" ");
        double x,y;
        x = list.at(0).toDouble();
        y = list.at(1).toDouble();
        qDebug() << x;
        qDebug() << y;
        series0->append(x,y);
    }

    plot_data.close();

    setRenderHint(QPainter::Antialiasing);
    chart()->addSeries(series0);

    chart()->setTitle("Точечная диаграмма");
    chart()->createDefaultAxes();
    chart()->setDropShadowEnabled(false);

    chart()->legend()->setMarkerShape(QLegend::MarkerShapeFromSeries);

}

