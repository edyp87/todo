#ifndef Task_H
#define Task_H

#include <QString>

class Task
{
public:
    virtual ~Task() = default;

    Task(QString name = "Unnamed task", unsigned _id = 0);

    virtual void setName(QString name);
    virtual void finish();
    virtual void undone();
    virtual bool isDone() const;
    virtual QString getName() const;
    virtual unsigned getId() const;

private:
    QString name;
    unsigned id;
    bool done;
};

#endif // Task_H
