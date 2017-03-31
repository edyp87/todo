#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "TaskUI.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void updateStatus();

public slots:
    void addTask();
    void removeTask(TaskUI* task);
    void taskStatusChanged(TaskUI * task);

private:
    QString getTaskNameFromUser();
    void addNamedTask(const QString& name);

    Ui::MainWindow *ui;
    QVector<TaskUI*> m_tasks;
};

#endif // MAINWINDOW_H
