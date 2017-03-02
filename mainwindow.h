#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "task.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void addTask();
    void removeTask(Task* task);

private:
    QString getTaskNameFromUser();
    void addNamedTask(const QString& name);

    Ui::MainWindow *ui;
    QVector<Task*> m_tasks;
};

#endif // MAINWINDOW_H
