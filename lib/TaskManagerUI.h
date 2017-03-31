#ifndef TASKMANAGERUI2_H
#define TASKMANAGERUI2_H

#include <TaskManager.h>

#include <QMainWindow>

#include <memory>

#include <TaskUI.h>

namespace Ui {
class TaskManagerUI;
}

class TaskManagerUI : public QMainWindow, public TaskManager
{

Q_OBJECT

public:

    virtual ~TaskManagerUI();

    TaskManagerUI(QWidget *parent = 0);
    void updateStatus();

public slots:
    void addTask();
    void removeTask(TaskUI *task);
    void taskStatusChanged(TaskUI * task);

private:
    QString getTaskNameFromUser();
    void addNamedTask(const QString& name);

    std::unique_ptr<Ui::TaskManagerUI> ui;
};

#endif // TASKMANAGERUI2_H
