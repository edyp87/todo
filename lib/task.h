#ifndef TASK_H
#define TASK_H

#include <QWidget>

#include <memory>

namespace Ui {
class Task;
}

class Task : public QWidget
{
    Q_OBJECT

public:
    explicit Task(const QString& name, QWidget *parent = 0);

    void setName(const QString& name);
    bool isCompleted();

    ~Task();

public slots:
    void rename();

private slots:
    void checked(bool checked);

signals:
    void removed(Task* task);
    void statusChanged(Task * task);

private:
    QString getTaskNameFromUser();

    std::unique_ptr<Ui::Task> ui;
};

#endif // TASK_H
