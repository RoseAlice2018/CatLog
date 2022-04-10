//
// Created by Reeb Deve on 2022/4/10.
//

#ifndef CATLOG_CATLOG_H
#define CATLOG_CATLOG_H
#include <string>
namespace CatLogNew{
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
             UNKNOW = 0,
             DEBUG  = 1,
             INFO   = 2,
             WARN   = 3,
             ERROR  = 4,
             FATAL  = 5
         };
         /**
          * @brief 将日志级别转换成文本输出
          * @param[in] level 日志级别
          */
          static std::string Tostring(LogLevel::Level level);

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
         */
        LogEvent(std::shared_ptr<Logger> logger,LogLevel::Level level,
                 std::stringstream ss,std::string service_Name,
                 uint64_t time,uint32_t fiberId,uint32_t threadId);
        /**
         * @brief  返回文件名
         */
        const char* getFileName() const {return m_file;}
        /**
         * @brief  返回行号
         */
        int32_t getLine() const {return m_line;}
        /**
         * @brief 返回线程ID
         */
        uint32_t getThreadId() const {return m_threadId;}
        /**
         * @brief 返回协程ID
         */
        uint32_t getFiberId() const  {return m_fiberId;}
        /**
         * @brief 返回时间
         */
        uint64_t getTime()    const {return m_time;}
        /**
         * @brief 返回服务名称
         */
        const std::string& getServiceName() {return m_serviceName;}
        /**
         * @brief 返回日志内容
         */
        std::string getContent() {return m_ss.str();}
        /**
         * @brief 返回日志器
         */
        std::shared_ptr<Logger> getLogger()const {return m_logger;}
        /**
         * @brief 返回日志级别
         */
        LogLevel::Level getLevel() const {return m_level;}
        /**
         * @brief 返回日志内容字符串流
         */
        std::stringstream& getSS() {return m_ss;}
    private:
        // 文件名
        const char* m_file = nullptr;
        // 行号
        int32_t m_line = 0;
        // 线程ID
        uint32_t m_threadId = 0;
        // 协程ID
        uint32_t m_fiberId = 0;
        // 时间戳
        uint64_t m_time = 0;
        // 服务名称
        std::string m_serviceName;
        // 日志内容流
        std::stringstream m_ss;
        // 日志器
        std::shared_ptr<Logger> m_logger;
        // 日志等级
        LogLevel::Level m_level;
    };

}

#endif //CATLOG_CATLOG_H
