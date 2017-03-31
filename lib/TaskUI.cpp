#include "TaskUI.h"
#include "ui_task.h"
#include <QDebug>
#include <QInputDialog>
TaskUI::~TaskUI()
{
    qDebug() << "Removing TaskUI";
}

TaskUI::TaskUI(QString name)
    :Task(name), ui(std::make_unique<Ui::Task>())
{
    ui->setupUi(this);
    setName(name);
    connect(ui->removeButton, &QPushButton::clicked, [this] { emit removed(this); });
    connect(ui->editButton, &QPushButton::clicked, this, &TaskUI::rename);
    connect(ui->checkbox, &QCheckBox::toggled, this, &TaskUI::checked);
}

void TaskUI::setName(QString name)
{
    Task::setName(name);
    ui->checkbox->setText(name);
}

void TaskUI::rename()
{
    QString name = getTaskNameFromUser();

    if (name.isEmpty())
    {
        return;
    }

    setName(name);
}

void TaskUI::checked(bool checked)
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

QString TaskUI::getTaskNameFromUser()
{
    bool ok = false;
    QString name = QInputDialog::getText(this,
                                         tr("Add TaskUI"),
                                         tr("TaskUI name"),
                                         QLineEdit::Normal,
                                         tr("Untitled TaskUI"), &ok);
    return ok ? name : "";
}
