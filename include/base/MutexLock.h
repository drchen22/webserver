#pragma once

#include "noncopyable.h"
#include <pthread.h>
#include <cstdio>
#include <utility>


class MutexLock : noncopyable
{
public:
    MutexLock()
    {
        pthread_mutex_init(&mutex_, NULL);
    }
    ~MutexLock() {
        pthread_mutex_lock(&mutex_);
        pthread_mutex_destroy(&mutex_);
    }

    void lock() {
        pthread_mutex_lock(&mutex_);
    }

    void unlock() {
        pthread_mutex_unlock(&mutex_);
    }

    pthread_mutex_t* get() {
        return &mutex_;
    }
    


    private:
        pthread_mutex_t mutex_;

        friend class Condition;
};


class MutexLockGuard : noncopyable {
    public:
        explicit MutexLockGuard(MutexLock& mutex) 
        : mutex_(mutex) {
            mutex_.lock();  
        }


    private:
        MutexLock& mutex_;
};