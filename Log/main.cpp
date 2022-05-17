//
// Created by Reeb Deve on 2022/5/15.
//
#include <iostream>

#include "CatLog1.h"
#include "leveldb/db.h"

int main()
{
    CatLog::Logger::ptr logger(new CatLog::Logger);
    logger->addAppender(CatLog::LogAppender::ptr(new CatLog::StdoutLogAppender));
    CatLog::FileLogAppender::ptr file_appender(new CatLog::FileLogAppender("./log.txt"));
    CatLog::LogFormatter::ptr fmt(new CatLog::LogFormatter("%d%T%p%T%m%n"));
    file_appender->setFormatter(fmt);
    file_appender->setLevel(CatLog::LogLevel::ERROR);
    CatLog::DataBaseAppender::ptr database_appender(new CatLog::DataBaseAppender(leveldb::DB()));
    database_appender->setLevel(CatLog::LogLevel::ERROR);
    database_appender->setFormatter(fmt);

    logger->addAppender(file_appender);
    logger->addAppender(database_appender);
    CatLog_LOG_INFO(logger) << "test" ;

    return 0;
}