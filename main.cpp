//
// Created by Reeb Deve on 2022/5/15.
//
#include <iostream>
#include "leveldb/db.h"
#include "Log/CatLog1.h"

int main()
{
    CatLog::Logger::ptr logger(new CatLog::Logger);
    logger->addAppender(CatLog::LogAppender::ptr(new CatLog::StdoutLogAppender));
    std::cout<<"Hello CatLog "<<std::endl;
    CatLog::FileLogAppender::ptr file_appender(new CatLog::FileLogAppender("./log.txt"));
    CatLog::LogFormatter::ptr fmt(new CatLog::LogFormatter("%d%T%p%T%m%n"));
    file_appender->setFormatter(fmt);
    file_appender->setLevel(CatLog::LogLevel::ERROR);

    logger->addAppender(file_appender);

    CatLog_LOG_INFO(logger) << "test" ;


    std::cout<<"hello world"<<std::endl;
    leveldb::DB* db;
    leveldb::Options options;
    options.create_if_missing = true;
    leveldb::Status status = leveldb::DB::Open(options,"/tmp/testdb",&db);
    assert(status.ok());
    return 0;
}
