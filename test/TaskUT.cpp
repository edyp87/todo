#include <QString>
#include <QtTest>

#include "task.h"

class QtTestingTest : public QObject
{
    Q_OBJECT

public:
    QtTestingTest();

private Q_SLOTS:
    void shouldSetName();

private:
    Task sut;
};

QtTestingTest::QtTestingTest()
    : sut("name")
{

}

void QtTestingTest::shouldSetName()
{
    sut.setName("newName");

}

QTEST_MAIN(QtTestingTest)

#include "TaskUT.moc"
