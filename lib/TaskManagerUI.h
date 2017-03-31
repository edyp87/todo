#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "TaskUI.h"

namespace Ui {
class TaskManagerUI;
}

class TaskManagerUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit TaskManagerUI(QWidget *parent = 0);
    ~TaskManagerUI();
    void updateStatus();

public slots:
    void addTask();
    void removeTask(TaskUI* task);
    void taskStatusChanged(TaskUI * task);

private:
    QString getTaskNameFromUser();
    void addNamedTask(const QString& name);

    Ui::TaskManagerUI *ui;
    QVector<TaskUI*> m_tasks;
};

#endif // MAINWINDOW_H
