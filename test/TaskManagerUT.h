#pragma once

#include <QObject>

#include "TaskManager.h"

#include <memory>

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
    std::unique_ptr<TaskManager> sut;
};
