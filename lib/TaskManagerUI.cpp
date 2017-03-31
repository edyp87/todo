#include "TaskManagerUI.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QInputDialog>

TaskManagerUI::TaskManagerUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TaskManagerUI),
    m_tasks()
{
    ui->setupUi(this);
    updateStatus();
    connect(ui->addTaskButton, &QPushButton::clicked,
            this, &TaskManagerUI::addTask);
}

TaskManagerUI::~TaskManagerUI()
{
    delete ui;
}

void TaskManagerUI::updateStatus()
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

void TaskManagerUI::addTask()
{
    QString name = getTaskNameFromUser();

    if (name.isEmpty())
    {
        return;
    }

    addNamedTask(name);
    updateStatus();
}

void TaskManagerUI::removeTask(TaskUI *task)
{
    m_tasks.removeOne(task);
    ui->tasksLayout->removeWidget(task);
    task->setParent(0);
    delete task;
    updateStatus();
}

void TaskManagerUI::taskStatusChanged(TaskUI *task)
{
    Q_UNUSED(task);
    updateStatus();
}

QString TaskManagerUI::getTaskNameFromUser()
{
    bool ok = false;
    QString name = QInputDialog::getText(this,
                                         tr("Add task"),
                                         tr("Task name"),
                                         QLineEdit::Normal,
                                         tr("Untitled task"), &ok);
    return ok ? name : "";
}

void TaskManagerUI::addNamedTask(const QString &name)
{
    qDebug() << "Adding new task";
    TaskUI * task = new TaskUI(name);
    m_tasks.append(task);
    ui->tasksLayout->addWidget(task);
    connect(task, &TaskUI::removed, this, &TaskManagerUI::removeTask);
    connect(task, &TaskUI::statusChanged, this, &TaskManagerUI::taskStatusChanged);
}
