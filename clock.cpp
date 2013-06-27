#include "clock.h"

CLock::CLock()
{
    pthread_mutex_init(&m_Mutex, NULL);
}

CLock::~CLock()
{
    pthread_mutex_destroy(&m_Mutex);
}

int CLock::Lock()
{
    int nRetCode = pthread_mutex_lock(&m_Mutex);
    return (nRetCode == 0);
}

int CLock::Unlock()
{
    int nRetCode = pthread_mutex_unlock(&m_Mutex);
    return (nRetCode == 0);
}
