#ifndef TASKMANAGERUI2_H
#define TASKMANAGERUI2_H

#include <TaskManager.h>

#include <QMainWindow>

#include <memory>

#include <TaskUI2.h>

namespace Ui {
class TaskManagerUI;
}

class TaskManagerUI2 : public QMainWindow, public TaskManager
{

Q_OBJECT

public:

    virtual ~TaskManagerUI2();

    TaskManagerUI2(QWidget *parent = 0);
    void updateStatus();

public slots:
    void addTask();
    void removeTask(TaskUI2 *task);
    void taskStatusChanged(TaskUI2 * task);

private:
    QString getTaskNameFromUser();
    void addNamedTask(const QString& name);

    std::unique_ptr<Ui::TaskManagerUI> ui;
};

#endif // TASKMANAGERUI2_H
