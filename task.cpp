#include "task.h"

Task::Task()
{
    title="";
    content="";
    uuid=get_uuid();
    isFinished=0;
}
//添加提醒
void Task::addReminder(const Reminder &reminder) {
    this->reminders.push_back(reminder);
}
//删除提醒
void Task::delReminder(uuid_t target_uuid)
{
    QVector<Reminder>::iterator ite;
    //遍历
    for(ite=reminders.begin();ite!=reminders.end();ite++)
    {
        if((*ite).uuid==target_uuid)
        {
            reminders.erase(ite);
            break;
        }
    }
}
//判断两事件是否一模一样
bool operator== (const Task &task1, const Task &task2)
{
    return task1.type == task2.type &&
           task1.title == task2.title &&
           task1.startTime == task2.startTime &&
           task1.reminders == task2.reminders &&
           task1.date == task2.date &&
           task1.isFinished == task2.isFinished &&
           task1.uuid == task2.uuid;
}
//重载赋值号
Task& Task::operator =(const Task& task1)
{
    type = task1.type;
    content=task1.content;
    title = task1.title;
    startTime = task1.startTime;
    reminders = task1.reminders;
    date = task1.date;
    isFinished=task1.isFinished;
    return *this;
}
Task::Task(const Task& task1)
{
    type = task1.type;
    title = task1.title;
    startTime = task1.startTime;
    content=task1.content;
    reminders = task1.reminders;
    date = task1.date;
    isFinished=task1.isFinished;
    uuid=task1.uuid;
}
Task::~Task() {}
