//
// Created by Reeb Deve on 2022/4/10.
//

#ifndef CATLOG_CATLOG_H
#define CATLOG_CATLOG_H
#include <string>
#include <list>
#include <sstream>
#include <vector>
#include <iostream>
#include <map>
#include <fstream>
/**
 * @brief 使用流式方式将日志级别level的日志写入logger
 */
#define CAT_LOG_LEVEL(logger,level) \
    if(logger->getLevel() <= level) \
       CatLogNew::LogEventWrap(CatLogNew::LogEvent::ptr(new CatLogNew::LogEvent(logger, level, \
                        __FILE__, __LINE__, 0, CatLogNew::GetThreadId(),\
                CatLogNew::GetFiberId(), time(0), CatLogNew::Thread::GetName()))).getSS()

/**
 * @brief 使用流式方式将日志级别debug的日志写入到logger
 */
#define CAT_LOG_DEBUG(logger) CAT_LOG_LEVEL(logger,CATLOGNEW::LogLevel::DEBUG)

/**
 * @brief 使用流式方式将日志级别info的日志写入到logger
 */

#define CAT_LOG_INFO(logger) CAT_LOG_LEVEL(logger,CATLOGNEW::LogLevel::INFO)

/**
 * @brief 使用流式方式将日志级别warn的日志写入到logger
 */
#define CAT_LOG_WARN(logger) CAT_LOG_LEVEL(logger,CATLOGNEW::LogLevel::WARN)

/**
 * @brief 使用流式方式将日志级别error的日志写入到logger
 */
#define CAT_LOG_ERROR(logger) CAT_LOG_LEVEL(logger,CATLOGNEW::LogLevel::ERROR)

/**
 * @brief 使用流式方式将日志级别fatal到日志写入到logger
 */
#define CAT_LOG_FATAL(logger) CAT_LOG_LEVEL(logger,CATLOGNEW::LogLevel::FATAL)



/**
 * @brief 使用格式化方式将日志级别level到日志写入到logger
 */
#define CAT_LOG_FMT_LEVEL(logger, level, fmt, ...) \
    if(logger->getLevel() <= level) \
        CatLogNew::LogEventWrap(CatLogNew::LogEvent::ptr(new CatLogNew::LogEvent(logger, level, \
                        __FILE__, __LINE__, 0, CatLogNew::GetThreadId(),\
                CatLogNew::GetFiberId(), time(0), CatLogNew::Thread::GetName()))).getEvent()->format(fmt, __VA_ARGS__)

/**
 * @brief 使用格式化方式将日志级别debug的日志写入到logger
 */
#define CAT_LOG_FMT_DEBUG(logger, fmt, ...) CAT_LOG_FMT_LEVEL(logger, CatLogNew::LogLevel::DEBUG, fmt, __VA_ARGS__)


/**
 * @brief 使用格式化方式将日志级别INFO的日志写入到logger
 */
#define CAT_LOG_FMT_INFO(logger, fmt, ...) CAT_LOG_FMT_LEVEL(logger, CatLogNew::LogLevel::INFO, fmt, __VA_ARGS__)

/**
 * @brief 使用格式化方式将日志级别WARN的日志写入到logger
 */
#define CAT_LOG_FMT_WARN(logger, fmt, ...) CAT_LOG_FMT_LEVEL(logger, CatLogNew::LogLevel::WARN, fmt, __VA_ARGS__)

/**
 * @brief 使用格式化方式将日志级别ERROR的日志写入到logger
 */
#define CAT_LOG_FMT_ERROR(logger, fmt, ...) CAT_LOG_FMT_LEVEL(logger, CatLogNew::LogLevel::ERROR, fmt, __VA_ARGS__)


/**
 * @brief 使用格式化方式将日志级别FATAL的日志写入到logger
 */
#define CAT_LOG_FMT_FATAL(logger, fmt, ...) CAT_LOG_FMT_LEVEL(logger, CatLogNew::LogLevel::FATAL, fmt, __VA_ARGS__)

/**
 * @brief 获取主日志器
 */
#define CAT_LOG_ROOT() CatLogNew::LoggerMgr::GetInstance()->getRoot();

/**
 * @brief 获取name到日志器
 */

#define CAT_LOG_NAME(name) CatLogNew::LoggerMgr::GetInstance()->getLogger(name)

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

        /**
         * @brief 格式化写入日志内容
         */
        void format(const char* fmt,...);
        /**
         * @brief 格式化写入日志内容
         */
        void format(const char* fmt,va_list al);
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

    /**
     * @brief 日志格式化
     */
    class LogFormatter{
    public:
        typedef std::shared_ptr<LogFormatter> ptr;
        /**
         * @brief 构造函数
         * @param[in] pattern 格式模板
         * @details
         * %m 消息
         * %p 日志级别
         * %r 累计毫秒数
         * %c 日志名称
         * %t 线程id
         * %n 换行
         * %d 时间
         * %f 文件名
         * %l 行号
         * %T 制表符
         * %F 协程id
         * %N 线程名称
         *
         * 默认格式 "%d{%Y-%m-%d %H:%M:%S}%T%t%T%N%T%F%T[%p]%T[%c]%T%f:%l%T%m%n"
         */
        explicit LogFormatter(const std::string& pattern);

        /**
         * @brief 返回格式化日志文本
         * @param[in] logger 日志器
         * @param[in] level  日志级别
         * @param[in] event  日志事件
         */
        std::string format(std::shared_ptr<Logger> logger,LogLevel::Level level,LogEvent::ptr event);
        std::ostream& format(std::ostream& ofs,std::shared_ptr<Logger> logger,LogLevel::Level level,
                             LogEvent::ptr event);
    public:
        /**
         * @brief 日志内容项格式化
         */
        class FormatItem{
        public:
            typedef std::shared_ptr<FormatItem> ptr;
            /**
             * @brief 析构函数
             */
            virtual ~FormatItem();
            /**
             * @brief 格式化日志到流
             * @param[in,out] os 日志输出流
             * @param[in] logger 日志器
             * @param[in] level 日志等级
             * @param[in] event 日志事件
             */
            virtual void format(std::ostream& os,std::shared_ptr<Logger> logger,
                                LogLevel::Level level,LogEvent::ptr event) = 0;
        };
        /**
         * @brief 初始化，解析日志模板
         */
        void init();

        /**
         * @brief 是否有错误
         */
        bool isError() const {return m_error;}

        /**
         * @brief 返回日志模板
         */
        const std::string getPattern() const {return m_pattern;}

    private:
        // 日志格式模板
        std::string m_pattern;
        // 日志格式解析后格式
        std::vector<FormatItem::ptr> m_items;
        // 是否有错误
        bool m_error = false;
    };
    /**
     * @brief 日志输出目标
     */
    class LogAppender{
        friend class Logger;

    public:
        typedef std::shared_ptr<LogAppender> ptr;
        /**
         * @brief 析构函数
         */
        virtual ~LogAppender(){}

        /**
         *@brief 写入日志
         *@param[in] logger 日志器
         *@param[in] level 日志级别
         *@param[in] event 日志事件
         */
        virtual void log(std::shared_ptr<Logger>logger,LogLevel::Level level,
                         LogEvent::ptr event) = 0;
        /**
         * @brief 将日志输出目标的配置转成YAML String
         */
        virtual std::string toYamlString() = 0;
        /**
         * @brief 更换日志格式器
         */
        void setFormatter(LogFormatter::ptr val);
        /**
         * @brief 获取日志格式器
         */
        LogFormatter::ptr getFormatter();
        /**
         * @brief 获取日志级别
         */
        LogLevel::Level getLevel()const{return m_level;}

        /**
         * @brief 设置日志级别
         */
        void setLevel(LogLevel::Level val){m_level = val;}
    protected:
        // 日志级别
        LogLevel::Level m_level = LogLevel::DEBUG;
        // 是否有自己的日志格式器
        bool m_hasFormatter = false;
        // Mutex
        //Todo Mutex

        // 日志格式器
        LogFormatter::ptr m_formatter;
    };

    /**
     * @brief 日志器
     */

class Logger : public std::enable_shared_from_this<Logger>{
    // Todo 友元类 LoggerManager

public:
    typedef std::shared_ptr<Logger> ptr;
    /**
     * @brief 构造函数
     * @param[in] name 日志器名称
     */
    Logger(const std::string& name = "root");

    /**
     * @brief 写日志
     * @param[in] level 日志级别
     * @param[in] event 日志事件
     */
     void log(LogLevel::Level level,LogEvent::ptr event);

     /**
      * @brief 写debug级别日志
      * @param[in] event 日志事件
      */
     void debug(LogEvent::ptr event);

     /**
      * @brief 写info级别日志
      * @param[in] event 日志事件
      */
     void info(LogEvent::ptr event);

     /**
      *@brief 写warn级别日志
      * @param[in] event 日志事件
      */
     void warn(LogEvent::ptr event);

     /**
      * @brief 写error级别日志
      * @param[in] event 日志事件
      */
     void error(LogEvent::ptr event);

     /**
      * @brief 写fatal级别日志
      * @param[in] event 日志事件
      */
     void fatal(LogEvent::ptr event);

     /**
      * @brief 添加日志目标
      * @param[in] appender 日志目标
      */
     void addAppender(LogAppender::ptr appender);

     /**
      * @brief 删除日志目标
      * @param[in] appender 日志目标
      */
     void delAppender(LogAppender::ptr appender);

     /**
      * @brief 清空日志目标
      */
     void clearAppenders();

     /**
      * @brief 返回日志级别
      */
     LogLevel::Level getLevel() const{return m_level;}

     /**
      * @brief 设置日志级别
      */
     void setLevel(LogLevel::Level val){m_level = val;}

     /**
      * @brief 返回日志名称
      */
     const std::string& getName() const {return m_name;}

     /**
      * @brief 设置日志格式器
      */
     void setFormatter(LogFormatter::ptr val);

     /**
      * @brief 设置日志格式模板
      */
     void setFormatter(const std::string& val);

     /**
      * @brief 获取日志格式器
      */
     LogFormatter::ptr getFormatter();

     /**
      * @brief 将日志器的配置转换成YAML String
      */
     std::string toYamlString();

private:
    // 日志名称
    std::string m_name;
    // 日志级别
    LogLevel::Level m_level;
    // Todo Mutex

    // 日志目标集合
    std::list<LogAppender::ptr> m_appenders;
    // 日志格式器
    LogFormatter::ptr m_formatter;
    // 主日志器
    Logger::ptr m_root;
};

    /**
     * @brief 输出到控制台
     */
    class StdoutLogAppender : public LogAppender{
    public:
        typedef std::shared_ptr<StdoutLogAppender> ptr;
        void log(Logger::ptr logger,LogLevel::Level level,LogEvent::ptr event)override;
        std::string toYamlString() override;
    };

    /**
     * @brief 输出到文件的Appender
     */
    class FileLogAppender : public LogAppender{
    public:
        typedef std::shared_ptr<FileLogAppender> ptr;
        FileLogAppender(const std::string& filename);
        void log(Logger::ptr logger,LogLevel::Level level,LogEvent::ptr event);
        std::string toYamlString() override;

        /**
         * @brief 重新打开日志文件
         * @return 成功返回true
         */
         bool reopen();

    private:
        // 文件路径
        std::string m_filename;
        // 文件流
        std::ofstream m_filestream;
        // 上次重新打开时间
        uint64_t m_lastTime = 0;
    };
    /**
     * @brief 日志器管理类
     */
    class LoggerManager{
    public:
        //Todo Mutex
        /**
         * @brief 构造函数
         */
        LoggerManager();

        /**
         * @brief 获取日志器
         * @param[in] name 日志器名称
         */
        Logger::ptr getLogger(const std::string& name);

        /**
         * @brief 初始化
         */
        void init();

        /**
         * @brief 返回主日志器
         */
        std::string toYamlString();

    private:
        // Todo Mutex

        // 日志器容器
        std::map<std::string,Logger::ptr> m_loggers;
        Logger::ptr m_root;
    };

    // Todo 日志器管理类单例模式
}

#endif //CATLOG_CATLOG_H
