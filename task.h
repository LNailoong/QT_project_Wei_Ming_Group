#ifndef TASK_H
#define TASK_H
#include "reminder.h"
#include <QDateTime>
#include <QDate>
#include <QDateTimeEdit>
#include <QString>
#include <vector>
#include <QVector>

enum class TaskType {
    IN_TO_DO_LIST = 0,      // to do list中的任务
    SCHEDULED_EVENT = 2  // 有起始时间的任务
};
class Task
{
public:
    uuid_t uuid;
    TaskType type;
    QString title;
    QString content;
    QVector<Reminder> reminders;
    QDateTime startTime;
    QDate date;
    bool isFinished;

    Task();
    Task(const Task& task1);
    void addReminder(const Reminder &reminder);//添加提醒
    void delReminder(uuid_t target_uuid);//删除提醒
    ~Task();

    friend bool operator== (const Task &task1, const Task &task2);
    Task& operator =(const Task& task1);
};

#endif // TASK_H
