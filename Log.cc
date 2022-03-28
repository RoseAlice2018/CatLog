
#include "Log.h"
namespace CatLog{
    /**
     * @brief loglevel类实现
     */
    const char* LogLevel::ToString(LogLevel::Level level){
        switch(level){
            #define XX(name)\
                case LogLevel::name:\
                    return #name; \
                    break;
                
                XX(DEBUG);
                XX(INFO);
                XX(WARN);
                XX(ERROR);
                XX(FATAL);
            #undef

            default:
                return "UNKNOW";
        }
        return "UNKNOW";
    }  

    LogLevel::Level LogLevel::FromString(const std::string& str)
    {
        #define XX(level,v)\
            if(str == #v){ \
                return LogLevel::level;\
            }
            XX(DEBUG,debug);
            XX(INFO,info);
            XX(WARN,warn);
            XX(ERROR,error);
            XX(FATAL,fatal);

            XX(DEBUG,DEBUG);
            XX(INFO,INFO);
            XX(WARN,WARN);
            XX(ERROR,ERROR)

            return LogLevel::UNKNOW;
        #undef XX
    }

    /**
     * @brief logeventwrap 包装类实现
     */
    LogEventWrap::LogEventWrap(LogEvent::ptr e):m_event(e){

    }

    //Todo 
    LogEventWrap::~LogEventWrap(){
        
    }

    //Todo
    void LogEvent::format(const char* fmt, ...){
        
    }

    //Todo
    void LogEvent::format(const char* fmt,va_list al){

    }

    std::stringstream& LogEventWrap::getSS(){
        return m_event->getSS();  
    }
    
    /**
     * @brief logAppender类实现
     */
    void LogAppender::setFormatter(LogFormatter::ptr val)
    {
        MutexType::Lock lock(m_mutex);
        m_formatter = val;
        if(m_formatter){
            m_hasFormatter = true;
        }
        else 
        {
            m_hasFormatter = false;
        }
    }
    
    LogFormatter::ptr LogAppender::getFormatter(){
        MutexType::Lock lock(m_mutex);
        return m_formatter;
    }

    /**
     * @brief logFormatter 日志格式化
     */
    class MessageFormatItem : public LogFormatter::FormatItem{
        public:
            MessageFormatItem(const std::string& str = ""){}
            void format(std::ostream& os,Logger::ptr logger,LogLevel::Level level,
                LogEvent::ptr event)override{
                    os<< event->getContent();
                }
    };
    
    class LevelFormatItem : public LogFormatter::FormatItem{
        public:
            LevelFormatItem(const std::string& str = ""){}
            void format(std::ostream& os,Logger::ptr logger,
                LogLevel::Level level,LogEvent::ptr event)override{
                    os << LogLevel::Tostring(level);                    
                }
    };

    class ElapseFormatItem : public LogFormatter::FormatItem{
        public:
            ElapseFormatItem(const std::string& str = ""){}
            void format(std::ostream& os,Logger::ptr logger,LogLevel::Level level,
                LogEvent::ptr event)override{
                    os << event->getElapse();
                }
    };

    class NameFormatItem : public LogFormatter::FormatItem{
        public:
            NameFormatItem(const std::string& str = ""){}
            void format(std::ostream& os,Logger::ptr logger,LogLevel::Level level,
                LogEvent::ptr event)override{
                    os << event->getLogger()->getName();
                }
    };

    class ThreadIdFormatItem : public LogFormatter::FormatItem{
        public:
            ThreadIdFormatItem(const std::string& str = ""){}
            void format(std::ostream& os,Logger::ptr logger,LogLevel::Level level,
                LogEvent::ptr event)override{
                    os << event->getThreadId();
                }
    };

    class ThreadNameFormatItem : public LogFormatter::FormatItem{
        public:
            ThreadIdFormatItem(const std::string& str = ""){}
            void format(std::ostream& os,Logger::ptr logger,LogLevel::Level level,
                LogEvent::ptr event)override{
                    os << event->getThreadName();
                }
    };

    class DataTimeFormatItem : public LogFormatter::FormatItem{
        public:
            DataTimeFormatItem(const std::string& format = "%Y-%m-%d %H:%M:%S")
                :m_format(format){
                    if(m_format.empty()){
                        m_format = "%Y-%m-%d %H:%M:%S";
                    }
                }
            
            void format(std::ostream& os,Logger::ptr logger,LogLevel::Level level,
                LogEvent::ptr event)override{
                    struct tm tm;
                    time_t time = event->getTime();
                    localtime_r(&time,&tm); 
                    char buf[64];
                    strftime(buf,sizeof(buf),m_format.c_str(),&tm);
                    os << buf;               
                }
    };

    class FilenameFormatItem : public LogFormatter::FormatItem {
        public:
            FilenameFormatItem(const std::string& str = "") {}
            void format(std::ostream& os, Logger::ptr logger, LogLevel::Level level,
             LogEvent::ptr event) override {
                os << event->getFile();
            }
    };

    class LineFormatItem : public LogFormatter::FormatItem {
        public:
            LineFormatItem(const std::string& str = "") {}
            void format(std::ostream& os, Logger::ptr logger, LogLevel::Level level, 
                LogEvent::ptr event) override {
                os << event->getLine();
            }
    };

    class NewLineFormatItem : public LogFormatter::FormatItem {
        public:
            NewLineFormatItem(const std::string& str = "") {}
            void format(std::ostream& os, Logger::ptr logger, LogLevel::Level level, 
            LogEvent::ptr event) override {
                os << std::endl;
            }
    };

    class StringFormatItem : public LogFormatter::FormatItem {
        public:
            StringFormatItem(const std::string& str)
                :m_string(str) {}
            void format(std::ostream& os, Logger::ptr logger, LogLevel::Level level, 
                LogEvent::ptr event) override {
                os << m_string;
            }
        private:
            std::string m_string;
    };

    class TabFormatItem : public LogFormatter::FormatItem {
        public:
            TabFormatItem(const std::string& str = "") {}
        void format(std::ostream& os, Logger::ptr logger, LogLevel::Level level,
             LogEvent::ptr event) override {
            os << "\t";
        }
    private:
        std::string m_string;
    };

}