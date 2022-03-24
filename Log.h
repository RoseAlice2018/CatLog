/**
 * @file log.h
 * @brief 日志库头文件
 * @author RoseAlice2018
 * @email wangty200011@163.com
 * @data  2022-3-22
 */
#ifndef  __CATLOG__H__
#define __CATLOG__H__

#include <string>
#include <memory>
#include <stddef.h>
namespace CatLog{
    class Logger;
    /**
     * @brief 日志级别
     */
    class LogLevel{
        public:
            /**
             * @brief 日志级别枚举
             */
            enum Level{
                // 未知级别
                UNKNOW = 0,
                // DEBUG级别
                DEBUG = 1,
                // INFO级别
                INFO = 2,
                // WARN级别
                WARN = 3,
                // ERROR级别
                ERROR = 4,
                // FATAL级别
                FATAL = 5
            };

            /**
             * @brief 将日志级别转换成文本输出
             * @param[in] level 日志级别
             */
            static const char* Tostring(LogLevel::Level level);

            /**
             * @brief 将文本转换成日志级别
             * @param[in] str 日志级别文本
             */
            static LogLevel::Level FromString(const std::string& str);
    };
    /**
     * @brief 日志事件
     */
    class LogEvent{
        public:
            typedef std::shared_ptr<LogEvent> ptr;
            /**
             * @brief 构造函数
             * @param[in] logger 日志器
             * @param[in] level 日志级别
             * @param[in] file 文件名
             * @param[in] line 文件行号
             * @param[in] elapse 程序启动依赖的耗时
             * @param[in] thread_id 线程id
             * @param[in] fiber_id 协程id
             * @param[in] time 日志事件（秒）
             * @param[in] thread_name 线程名称
             */
            LogEvent(std::shared_ptr<Logger>logger,LogLevel::Level LogLevel
                    ,const char* file,__int32_t line,__uint32_t elapse,
                    ,__uint32_t thread_id,__uint32_t fiber_id,uint)
            
            /**
             * @brief 返回文件名
             */
        private:
            // 文件名
            const char* m_file = nullptr;
            // 行号
            __int32_t m_line = 0;
            // 程序启动开始到现在的毫秒数
            __uint32_t m_elpase = 0;
            // 线程ID
            __uint32_t m_threadId = 0;
            // 协程ID
            __uint32_t m_fiberId = 0;
            // 时间戳
            __uint64_t m_time = 0;
            // 线程名称
            std::string m_threadName;
            // 日志内容流
            std::stringstream m_ss;
            // 日志器
            std::shared_ptr<Logger> m_logger;
            // 日志等级
            LogLevel::Level m_level;
    };
    /**
     * @brief 日志事件包装器
     */
    class LogEventWrap{
        public:
            /**
             * @brief 构造函数
             * @param[in] e 日志事件
             */
            LogEventWrap(LogEvent::ptr e);

            /**
             * @brief 析构函数
             */
            ~LogEventWrap();

            /**
             * @brief 获取日志事件
             */
            LogEvent::ptr getEvent() const {return m_event;}

            /**
             * @brief 获取日志内容流
             */
            std::stringstream& getSS();

        private:
            /**
             * @brief 日志事件
             */
            LogEvent::ptr m_event;
    };
    

}

#endif