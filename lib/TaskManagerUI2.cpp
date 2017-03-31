#include "TaskManagerUI2.h"

#include "ui_mainwindow.h"

#include <memory>

#include <QInputDialog>

#include <QDebug>
#include "ui_task.h"

TaskManagerUI2::~TaskManagerUI2()
{
}

TaskManagerUI2::TaskManagerUI2(QWidget *parent)
    : QMainWindow(parent), TaskManager(),
      ui(std::make_unique<Ui::TaskManagerUI>())
{
    ui->setupUi(this);
    connect(ui->addTaskButton, &QPushButton::clicked, this, &TaskManagerUI2::addTask);
}

void TaskManagerUI2::updateStatus()
{
    int completedCount = 0;

    for (const auto & task : m_tasks)
    {
        if (task->isDone())
        {
            completedCount++;
        }
    }
    unsigned long todos = m_tasks.size() - static_cast<unsigned long>(completedCount);

    ui->statusLabel->setText(
                QString("Status: %1 todo / %2 completed").arg(todos).arg(completedCount));
}

void TaskManagerUI2::addTask()
{
    QString name = getTaskNameFromUser();

    if (name.isEmpty())
    {
        return;
    }

    addNamedTask(name);
    updateStatus();
}

void TaskManagerUI2::removeTask(TaskUI2 *task)
{
    qDebug() << "Remove task";
    ui->tasksLayout->removeWidget(task);

    auto compare = [task](const std::unique_ptr<Task> & taskPtr)
    {
        return task == taskPtr.get();
    };

    m_tasks.erase(std::remove_if(m_tasks.begin(), m_tasks.end(), compare));
}

void TaskManagerUI2::taskStatusChanged(TaskUI2 *task)
{
    qDebug() << "Status changed";
    Q_UNUSED(task);
    updateStatus();
}

QString TaskManagerUI2::getTaskNameFromUser()
{
    bool ok = false;
    QString name = QInputDialog::getText(this,
                                         tr("Add task"),
                                         tr("Task name"),
                                         QLineEdit::Normal,
                                         tr("Untitled task"), &ok);
    return ok ? name : "";
}

void TaskManagerUI2::addNamedTask(const QString &name)
{
    qDebug() << "Adding new task";

    auto task = std::make_unique<TaskUI2>(name);

    ui->tasksLayout->addWidget(task.get());
    connect(task.get(), &TaskUI2::removed, this, &TaskManagerUI2::removeTask);
    connect(task.get(), &TaskUI2::statusChanged, this, &TaskManagerUI2::taskStatusChanged);

    m_tasks.push_back(std::move(task));

}
