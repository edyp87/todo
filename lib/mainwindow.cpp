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
    updateStatus();
    connect(ui->addTaskButton, &QPushButton::clicked,
            this, &MainWindow::addTask);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateStatus()
{
    int completedCount = 0;

    for (auto task : m_tasks)
    {
        if (task->isCompleted())
        {
            completedCount++;
        }
    }
    int todos = m_tasks.size() - completedCount;

    ui->statusLabel->setText(
                QString("Status: %1 todo / %2 completed").arg(todos).arg(completedCount));
}

void MainWindow::addTask()
{
    QString name = getTaskNameFromUser();

    if (name.isEmpty())
    {
        return;
    }

    addNamedTask(name);
    updateStatus();
}

void MainWindow::removeTask(Task *task)
{
    m_tasks.removeOne(task);
    ui->tasksLayout->removeWidget(task);
    task->setParent(0);
    delete task;
    updateStatus();
}

void MainWindow::taskStatusChanged(Task *task)
{
    Q_UNUSED(task);
    updateStatus();
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
    connect(task, &Task::statusChanged, this, &MainWindow::taskStatusChanged);
}
