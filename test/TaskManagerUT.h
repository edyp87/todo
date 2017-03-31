#pragma once

#include <QObject>

#include "TaskManager.h"

class TaskManagerUT : public QObject
{
    Q_OBJECT

public:
    TaskManagerUT();

private Q_SLOTS:
    void init();

    void shouldCreateNewTaskAndReturnId();
    void tasksCanBeRemoved();
    void tasksIdsAreGeneratedUniquely();

private:
    TaskManager sut;
};
