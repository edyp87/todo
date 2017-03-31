#ifndef TASKUT_H
#define TASKUT_H

#include <QObject>

#include "Task.h"

class TaskUT : public QObject
{
    Q_OBJECT

public:
    TaskUT();

private Q_SLOTS:
    void shouldHaveDefaultNameWhenNotSpecified();
    void shouldHaveSpecifiedNameAfterConstruction();
    void shouldHaveDefaultIdWhenNotSpecified();
    void shouldHaveSpecifiedIdAfterConstruction();
    void shouldSetName();
    void canBeFinished();
    void canBeUndone();

private:
    Task sut;
};

#endif // TASKUT_H
