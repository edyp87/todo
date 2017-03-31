#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <vector>
#include <QString>
#include <Task.h>
#include <memory>

class TaskManager
{
public:
    virtual ~TaskManager() = default;

    TaskManager();
    unsigned addTask(QString name);
    Task & getTask(unsigned id);
    void removeTask(unsigned id);
    unsigned long getNumberOfTasks() const;

private:
    unsigned generateNewTaskId() const;

protected:
    std::vector<std::unique_ptr<Task>> m_tasks;
};

#endif // TASKMANAGER_H
