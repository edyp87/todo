#ifndef Task_H
#define Task_H

#include <QString>

class Task
{
public:
    Task(QString name = "Unnamed task", unsigned _id = 0);
    void setName(QString name);
    void finish();
    void undone();
    bool isDone() const;
    QString getName() const;
    unsigned getId() const;

private:
    QString name;
    unsigned id;
    bool done;
};

#endif // Task_H
