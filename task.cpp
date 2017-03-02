#include "task.h"
#include "ui_task.h"
#include <QtDebug>
#include <QInputDialog>

Task::Task(const QString &name, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Task)
{
    ui->setupUi(this);
    setName(name);
    connect(ui->editButton, &QPushButton::clicked, this, &Task::rename);
    connect(ui->removeButton, &QPushButton::clicked, [this] { emit removed(this); });
    connect(ui->checkbox, &QCheckBox::toggled, this, &Task::checked);

}

void Task::setName(const QString &name)
{
    ui->checkbox->setText(name);
}

bool Task::isCompleted()
{
    return ui->checkbox->isChecked();
}

void Task::rename()
{
    QString name = getTaskNameFromUser();

    if (name.isEmpty())
    {
        return;
    }

    setName(name);
}

void Task::checked(bool checked)
{
    QFont font(ui->checkbox->font());
    font.setStrikeOut(checked);
    ui->checkbox->setFont(font);
    emit statusChanged(this);
}

QString Task::getTaskNameFromUser()
{
    bool ok = false;
    QString name = QInputDialog::getText(this,
                                         tr("Add task"),
                                         tr("Task name"),
                                         QLineEdit::Normal,
                                         tr("Untitled task"), &ok);
    return ok ? name : "";
}

Task::~Task()
{
    delete ui;
}
