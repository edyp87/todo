#include <QString>
#include <QtTest>

#include "TaskUT.h"

TaskUT::TaskUT()
    : sut{}
{

}

void TaskUT::shouldHaveDefaultNameWhenNotSpecified()
{
    QCOMPARE(QString("Unnamed task"), sut.getName());
}

void TaskUT::shouldHaveSpecifiedNameAfterConstruction()
{
    sut = Task("newName");
    QCOMPARE(QString("newName"), sut.getName());
}

void TaskUT::shouldHaveDefaultIdWhenNotSpecified()
{
    QCOMPARE(0u, sut.getId());
}

void TaskUT::shouldHaveSpecifiedIdAfterConstruction()
{
    sut = Task("newName", 12u);
    QCOMPARE(12u, sut.getId());
}

void TaskUT::shouldSetName()
{
    sut.setName("newName");
    QCOMPARE(QString("newName"), sut.getName());
}

void TaskUT::canBeFinished()
{
    QVERIFY(not sut.isDone());
    sut.finish();
    QVERIFY(sut.isDone());

}

void TaskUT::canBeUndone()
{
    sut.finish();
    QVERIFY(sut.isDone());
    sut.undone();
    QVERIFY(not sut.isDone());
}
