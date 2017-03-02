#ifndef TASK_H
#define TASK_H

#include <QWidget>

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

signals:
    void removed(Task* task);

private:
    QString getTaskNameFromUser();

    Ui::Task *ui;
};

#endif // TASK_H
