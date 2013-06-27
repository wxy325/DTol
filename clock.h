#ifndef CLOCK_H
#define CLOCK_H

class CLock
    {
    public:
        CLock();
        ~CLock();
        int Lock();
        int Unlock();

    private:
        pthread_mutex_t m_Mutex;
    };
#endif // CLOCK_H
