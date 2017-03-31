#include "TaskManagerUT.h"

#include <QTest>

TaskManagerUT::TaskManagerUT()
{

}

void TaskManagerUT::init()
{
    sut = std::make_unique<TaskManager>();
}

void TaskManagerUT::shouldCreateNewTaskAndReturnId()
{
    QCOMPARE(sut->addTask(QString("Name")), 0u);
    QCOMPARE(sut->addTask(QString("Name")), 1u);
    QCOMPARE(sut->addTask(QString("Name")), 2u);
    QCOMPARE(sut->getNumberOfTasks(), 3ul);
}

void TaskManagerUT::tasksCanBeRemoved()
{
    QCOMPARE(sut->addTask(QString("Name")), 0u);
    QCOMPARE(sut->addTask(QString("Name")), 1u);
    QCOMPARE(sut->getNumberOfTasks(), 2ul);
    sut->removeTask(1u);
    QCOMPARE(sut->getNumberOfTasks(), 1ul);
}

void TaskManagerUT::tasksIdsAreGeneratedUniquely()
{
    QCOMPARE(sut->addTask(QString("Name")), 0u);
    QCOMPARE(sut->addTask(QString("Name")), 1u);
    QCOMPARE(sut->addTask(QString("Name")), 2u);
    sut->removeTask(1u);
    QCOMPARE(sut->addTask(QString("Name")), 1u);
}

