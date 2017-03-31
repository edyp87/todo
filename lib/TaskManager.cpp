#include "TaskManager.h"

TaskManager::TaskManager()
{

}

unsigned TaskManager::addTask(QString name)
{
    auto id = generateNewTaskId();
    m_tasks.push_back(std::make_unique<Task>(name, id));
    return id;

}

Task &TaskManager::getTask(unsigned id)
{
    auto doIdsMatch = [id](const std::unique_ptr<Task> & task)
    {
        return id == task->getId();
    };

    return **std::find_if(m_tasks.begin(), m_tasks.end(), doIdsMatch);
}

void TaskManager::removeTask(unsigned id)
{
    auto doIdsMatch = [id](const std::unique_ptr<Task> & task)
    {
        return id == task->getId();
    };

    m_tasks.erase(std::remove_if(m_tasks.begin(), m_tasks.end(), doIdsMatch));
}

unsigned long TaskManager::getNumberOfTasks() const
{
    return m_tasks.size();
}

unsigned TaskManager::generateNewTaskId() const
{
    for (unsigned id = 0u; id < std::numeric_limits<unsigned>::max(); ++id)
    {
        auto compareIds = [id](const std::unique_ptr<Task> & task)
        {
            return task->getId() == id;
        };
        auto foundTask = std::find_if(m_tasks.begin(), m_tasks.end(), compareIds);
        if (foundTask == m_tasks.end())
        {
            return id;
        }
    }
    return 0u;
}
