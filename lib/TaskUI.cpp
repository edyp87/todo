#include "TaskUI.h"
#include "ui_task.h"
#include <QtDebug>
#include <QInputDialog>
#include <memory>

TaskUI::TaskUI(const QString &name, QWidget *parent) :
    QWidget(parent),
    ui(std::make_unique<Ui::Task>())
{
    ui->setupUi(this);
    setName(name);
    connect(ui->editButton, &QPushButton::clicked, this, &TaskUI::rename);
    connect(ui->removeButton, &QPushButton::clicked, [this] { emit removed(this); });
    connect(ui->checkbox, &QCheckBox::toggled, this, &TaskUI::checked);

}

void TaskUI::setName(const QString &name)
{
    ui->checkbox->setText(name);
}

bool TaskUI::isCompleted()
{
    return ui->checkbox->isChecked();
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

TaskUI::~TaskUI()
{
}
