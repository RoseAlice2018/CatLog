//
// Created by Reeb Deve on 2022/4/8.
//

#ifndef CATLOG_MUTEX_H
#define CATLOG_MUTEX_H
#include <mutex>
namespace CatLog{
    /**
     * @brief 互斥锁
     */
    class Mutex {
    public:
        /**
         * @brief 构造函数
         * @param mutex
         */
        Mutex(std::mutex mutex){

        }
        /**
         * @brief 析构函数
         */
        ~Mutex(){
            m_mutex.unlock();
        };
        /**
         * @brief lock
         */
         void Lock(){
             m_mutex.lock();
         };
        /**
         *@brief unlock
         */
         void unlock(){
             m_mutex.unlock();
         }
    private:
        std::mutex m_mutex;
    };

    class  MutexLock {
            public:
            MutexLock(std::mutex* mu):mu_(mu) {
                this->mu_->lock();
            }
            ~MutexLock() { this->mu_->unlock(); }

            MutexLock(const MutexLock&) = delete;
            MutexLock& operator=(const MutexLock&) = delete;

            private:
            std::mutex* const mu_;
    };
}

#endif //CATLOG_MUTEX_H
