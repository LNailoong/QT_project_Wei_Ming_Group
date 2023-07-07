#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QPainter>
#include<QMediaPlayer>
#include<QString>
#include<QTableWidgetItem>
#include<QTableWidget>
#include "daylist.h"
#include "task.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
enum Color{
    RED=1,
    YELLOW=2,
    PINK=3,
    PURPLE=4
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent*);

    QString currName[13][8];//curriculum
    QString currPlace[13][8];//curriculum
    int currColor[13][8];//curriculum

    QVector<DayList> bank_daylist;


    void refresh();
    void refresh(const QDateTime &dateTime);
    void month_schedule_refresh(const QDateTime &dateTime);

private slots:
    void on_dateEdit_dateTimeChanged(const QDateTime &dateTime);

    void on_tableWidget_2_itemChanged(QTableWidgetItem *item);

    void on_themeConfirm_clicked();

    void on_calendarWidget_clicked(const QDate &date);

    void on_save_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
