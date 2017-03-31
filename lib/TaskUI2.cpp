#include "TaskUI2.h"
#include "ui_task.h"
#include <QDebug>
#include <QInputDialog>
TaskUI2::~TaskUI2()
{
    qDebug() << "Removing TaskUI2";
}

TaskUI2::TaskUI2(QString name)
    :Task(name), ui(std::make_unique<Ui::Task>())
{
    ui->setupUi(this);
    setName(name);
    connect(ui->removeButton, &QPushButton::clicked, [this] { emit removed(this); });
    connect(ui->editButton, &QPushButton::clicked, this, &TaskUI2::rename);
    connect(ui->checkbox, &QCheckBox::toggled, this, &TaskUI2::checked);
}

void TaskUI2::setName(QString name)
{
    Task::setName(name);
    ui->checkbox->setText(name);
}

void TaskUI2::rename()
{
    QString name = getTaskNameFromUser();

    if (name.isEmpty())
    {
        return;
    }

    setName(name);
}

void TaskUI2::checked(bool checked)
{
    if (checked)
    {
        Task::finish();
    }
    else
    {
        Task::undone();
    }

    QFont font(ui->checkbox->font());
    font.setStrikeOut(checked);
    ui->checkbox->setFont(font);
    emit statusChanged(this);
}

QString TaskUI2::getTaskNameFromUser()
{
    bool ok = false;
    QString name = QInputDialog::getText(this,
                                         tr("Add TaskUI"),
                                         tr("TaskUI name"),
                                         QLineEdit::Normal,
                                         tr("Untitled TaskUI"), &ok);
    return ok ? name : "";
}
