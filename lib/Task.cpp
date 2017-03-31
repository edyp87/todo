#include "Task.h"

Task::Task(QString _name, unsigned _id)
    : name(_name),
      id(_id),
      done(false)
{

}

void Task::setName(QString _name)
{
    name = _name;
}

void Task::finish()
{
    done = true;
}

void Task::undone()
{
    done = false;
}

bool Task::isDone() const
{
    return done;
}

QString Task::getName() const
{
    return name;
}

unsigned Task::getId() const
{
    return id;
}
