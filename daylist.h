#ifndef DAYLIST_H
#define DAYLIST_H
#include "task.h"


class DayList
{
public:
    DayList();
    QVector<Task> daytask;
    QString theme;
    QString dayschedule;
    QDateTime daytime;

    void addnewtask(const Task& _task);
    void addtheme(QString _theme);
    void add_dayschedule(QString s);
};

#endif // DAYLIST_H
