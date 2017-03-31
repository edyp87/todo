#ifndef TASK_H
#define TASK_H

#include <QWidget>

#include <memory>

namespace Ui {
class Task;
}

class TaskUI : public QWidget
{
    Q_OBJECT

public:
    explicit TaskUI(const QString& name, QWidget *parent = 0);

    void setName(const QString& name);
    bool isCompleted();

    ~TaskUI();

public slots:
    void rename();

private slots:
    void checked(bool checked);

signals:
    void removed(TaskUI* task);
    void statusChanged(TaskUI * task);

private:
    QString getTaskNameFromUser();

    std::unique_ptr<Ui::Task> ui;
};

#endif // TASK_H
