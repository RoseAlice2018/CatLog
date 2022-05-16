//
// Created by Reeb Deve on 2022/5/16.
//

#ifndef CATLOG_NONCOPYABLE_H
#define CATLOG_NONCOPYABLE_H



namespace CatLog {

/**
 * @brief 对象无法拷贝,赋值
 */
    class Noncopyable {
    public:
        /**
         * @brief 默认构造函数
         */
        Noncopyable() = default;

        /**
         * @brief 默认析构函数
         */
        ~Noncopyable() = default;

        /**
         * @brief 拷贝构造函数(禁用)
         */
        Noncopyable(const Noncopyable&) = delete;

        /**
         * @brief 赋值函数(禁用)
         */
        Noncopyable& operator=(const Noncopyable&) = delete;
    };

}


#endif //CATLOG_NONCOPYABLE_H
