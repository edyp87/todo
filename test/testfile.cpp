#include <QString>
#include <QtTest>

class QtTestingTest : public QObject
{
    Q_OBJECT

public:
    QtTestingTest();

private Q_SLOTS:
    void testCase1();
};

QtTestingTest::QtTestingTest()
{
}

void QtTestingTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(QtTestingTest)

#include "testfile.moc"
