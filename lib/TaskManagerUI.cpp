#include "TaskManagerUI.h"

#include "ui_mainwindow.h"

#include <memory>

#include <QInputDialog>

#include <QDebug>
#include "ui_task.h"

TaskManagerUI::~TaskManagerUI()
{
}

TaskManagerUI::TaskManagerUI(QWidget *parent)
    : QMainWindow(parent), TaskManager(),
      ui(std::make_unique<Ui::TaskManagerUI>())
{
    ui->setupUi(this);
    connect(ui->addTaskButton, &QPushButton::clicked, this, &TaskManagerUI::addTask);
}

void TaskManagerUI::updateStatus()
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
    qDebug() << "Remove task";
    ui->tasksLayout->removeWidget(task);

    auto compare = [task](const std::unique_ptr<Task> & taskPtr)
    {
        return task == taskPtr.get();
    };

    m_tasks.erase(std::remove_if(m_tasks.begin(), m_tasks.end(), compare));
}

void TaskManagerUI::taskStatusChanged(TaskUI *task)
{
    qDebug() << "Status changed";
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

    auto task = std::make_unique<TaskUI>(name);

    ui->tasksLayout->addWidget(task.get());
    connect(task.get(), &TaskUI::removed, this, &TaskManagerUI::removeTask);
    connect(task.get(), &TaskUI::statusChanged, this, &TaskManagerUI::taskStatusChanged);

    m_tasks.push_back(std::move(task));

}
