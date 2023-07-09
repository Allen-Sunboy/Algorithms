#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void paintEvent(QPaintEvent *event);

    //最近点对，存储的2个数分别是原数组的下标
    QPair<long long, long long> closestPair;

    QPair<QPair<long long, long long>, QPair<long long, long long> > closest;

    long long closestDistance;

private slots:
    void on_ButtonRandom_clicked();

    void on_ButtonClear_clicked();

    void on_ButtonSolve_clicked();

    void on_ButtonAdd_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
