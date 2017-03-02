#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_tasks()
{
    ui->setupUi(this);
    connect(ui->addTaskButton, &QPushButton::clicked,
            this, &MainWindow::addTask);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addTask()
{
    QString name = getTaskNameFromUser();

    if (name.isEmpty())
    {
        return;
    }

    addNamedTask(name);
}

void MainWindow::removeTask(Task *task)
{
    m_tasks.removeOne(task);
    ui->tasksLayout->removeWidget(task);
    task->setParent(0);
    delete task;
}

QString MainWindow::getTaskNameFromUser()
{
    bool ok = false;
    QString name = QInputDialog::getText(this,
                                         tr("Add task"),
                                         tr("Task name"),
                                         QLineEdit::Normal,
                                         tr("Untitled task"), &ok);
    return ok ? name : "";
}

void MainWindow::addNamedTask(const QString &name)
{
    qDebug() << "Adding new task";
    Task * task = new Task(name);
    m_tasks.append(task);
    ui->tasksLayout->addWidget(task);
    connect(task, &Task::removed, this, &MainWindow::removeTask);
}
