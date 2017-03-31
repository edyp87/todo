#include "TaskUT.h"
#include "TaskManagerUT.h"

#include <QTest>

template <typename Testcase>
void runTest(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Testcase tc;
    QTest::qExec(&tc, argc, argv);
}

int main(int argc, char *argv[])
{
    runTest<TaskUT>(argc, argv);
    runTest<TaskManagerUT>(argc, argv);
}
