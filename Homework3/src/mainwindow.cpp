#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "method.h"

#include <QScreen>
#include <QRandomGenerator>
#include <QMessageBox>
#include <QElapsedTimer>
#include <QTime>
#include <QPainter>
#include <QPaintEvent>

#include <random>

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QScreen *screen = QGuiApplication::primaryScreen();
    QSize screenSize = screen->size();
    int screenWidth = screenSize.width();
    int screenHeight = screenSize.height();

    this->resize(screenWidth - 200, screenHeight - 400);
    this->move(100, 100);

    closestPair = QPair(-1, -1);

    ui->label_3->setText("暴力法用时（毫秒）：");
    ui->label_4->setText("分治法用时（毫秒）：");
    ui->label_5->setText("最近点对：");

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::paintEvent(QPaintEvent *event)
{
    const QRect &rect = event->rect();
    QPainter painter(this);
    painter.eraseRect(rect);
    painter.setPen((QPen(Qt::black, 5)));


    if(amount <= 100)
    {
        for(int i = 0; i < amount; i++)
        {
            if(i == closestPair.first || i == closestPair.second)
            {
                painter.setPen((QPen(Qt::red, 5)));
            }
            painter.drawEllipse(points[i].x, points[i].y, 10, 10);
            painter.setPen((QPen(Qt::black, 5)));
        }
    }

}


void MainWindow::on_ButtonAdd_clicked()
{
    long long x0 = ui->spinBoxX->value();
    long long y0 = ui->spinBoxY->value();
    points[amount].x = x0;
    points[amount].y = y0;
    amount++;

    update();
}


void MainWindow::on_ButtonSolve_clicked()
{
    if(amount <= 1)
    {
        QMessageBox::warning(this, "错误", "当前点的个数少于2个！");
        return;
    }

    QElapsedTimer timer;

    timer.start();

    QPair<QPair<long long, long long>, long long> result2 = closest_2();

    long long time2 = timer.elapsed();

    closestPair = result2.first;

    QString str2 = "分治法用时（毫秒）：";
    str2 += QString::number(time2);
    ui->label_4->setText(str2);

    update();

    QString str3 = "最近点对：(";
    str3 += QString::number(points[closestPair.first].x);
    str3 += ", ";
    str3 += QString::number(points[closestPair.first].y);
    str3 += ") (";
    str3 += QString::number(points[closestPair.second].x);
    str3 += ", ";
    str3 += QString::number(points[closestPair.second].y);
    str3 += ")";
    ui->label_5->setText(str3);

    timer.start();

    QPair<QPair<long long, long long>, long long> result1 = closest_1();

    long long time1 = timer.elapsed();
    QString str1 = "暴力法用时（毫秒）：";
    str1 += QString::number(time1);
    ui->label_3->setText(str1);

}


void MainWindow::on_ButtonRandom_clicked()
{
    long long value = ui->spinBoxAmount->value();
    amount = value;
    std::uniform_int_distribution<int> u(0, value * 10); //设置随机数的范围
    std::default_random_engine e;
    QTime now = QTime::currentTime();
    e.seed(now.msec());
    for(int i = 0; i < amount; i++)
    {
        points[i].x = u(e);
        points[i].y = u(e);
    }

    QElapsedTimer timer;

    timer.start();

    QPair<QPair<long long, long long>, long long> result2 = closest_2();

    long long time2 = timer.elapsed();

    closestPair = result2.first;

    QString str2 = "分治法用时（毫秒）：";
    str2 += QString::number(time2);
    ui->label_4->setText(str2);

    update();

    QString str3 = "最近点对：(";
    str3 += QString::number(points[closestPair.first].x);
    str3 += ", ";
    str3 += QString::number(points[closestPair.first].y);
    str3 += ") (";
    str3 += QString::number(points[closestPair.second].x);
    str3 += ", ";
    str3 += QString::number(points[closestPair.second].y);
    str3 += ")";
    ui->label_5->setText(str3);

    if(amount <= 30000)
    {
        timer.start();

        QPair<QPair<long long, long long>, long long> result1 = closest_1();

        long long time1 = timer.elapsed();
        QString str1 = "暴力法用时（毫秒）：";
        str1 += QString::number(time1);
        ui->label_3->setText(str1);
    }
    else
    {
        ui->label_3->setText("暴力法用时（毫秒）：");
    }

}


void MainWindow::on_ButtonClear_clicked()
{
    amount = 0;
    closestPair = QPair(-1, -1);
    update();
    ui->label_3->setText("暴力算法用时（毫秒）：");
    ui->label_4->setText("分治法用时（毫秒）：");
    ui->label_5->setText("最近点对：");

}
