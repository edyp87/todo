#include <QString>
#include <QtTest>

#include "task.h"

class QtTestingTest : public QObject
{
    Q_OBJECT

public:
    QtTestingTest();

private Q_SLOTS:
    void testCase1();

private:
    Task sut;
};

QtTestingTest::QtTestingTest()
    : sut("name")
{

}

void QtTestingTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

QTEST_MAIN(QtTestingTest)

#include "TaskUT.moc"
