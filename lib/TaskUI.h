#ifndef TASKUI2_H
#define TASKUI2_H

#include <Task.h>

#include <memory>

#include <QWidget>

namespace Ui {
class Task;
}

class TaskUI : public QWidget, public Task
{

Q_OBJECT

public:
    ~TaskUI();
    TaskUI(QString name = "Unnamed task");

    void setName(QString name) override;

signals:
    void removed(TaskUI* task);
    void statusChanged(TaskUI * task);

public slots:
    void rename();

private slots:
    void checked(bool checked);

private:
    QString getTaskNameFromUser();

    std::unique_ptr<Ui::Task> ui;
};

#endif // TASKUI2_H
