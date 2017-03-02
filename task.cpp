#include "task.h"
#include "ui_task.h"
#include <QtDebug>

Task::Task(const QString &name, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Task)
{
    ui->setupUi(this);
    setName(name);
}

void Task::setName(const QString &name)
{
    ui->checkbox->setText(name);
}

bool Task::isCompleted()
{
    return ui->checkbox->isChecked();
}

Task::~Task()
{
    delete ui;
}
