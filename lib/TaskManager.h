#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <vector>
#include <QString>
#include <Task.h>
#include <memory>

class TaskManager
{
public:
    TaskManager();
    unsigned addTask(QString name);
    void removeTask(unsigned id);
    unsigned long getNumberOfTasks() const;

private:
    unsigned generateNewTaskId() const;
    std::vector<Task> m_tasks;
};

#endif // TASKMANAGER_H
