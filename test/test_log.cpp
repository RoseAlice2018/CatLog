//
// Created by Reeb Deve on 2022/5/3.
//

#include <iostream>
#include "CatLog.h"

int main(int argc,char** argv){
    CatLogNew::Logger::ptr logger(new CatLogNew::Logger);
    logger->addAppender(CatLogNew::LogAppender::ptr(new CatLogNew::StdoutLogAppender));

    CatLogNew::FileLogAppender::ptr file_appender(new CatLogNew::FileLogAppender("./log.txt"));
    CatLogNew::LogFormatter::ptr fmt(new CatLogNew::LogFormatter("%d%T%p%T%m%n"));
    file_appender->setFormatter(fmt);
    file_appender->setLevel(CatLogNew::LogLevel::ERROR);

    logger->addAppender(file_appender);
    //Todo LogEvent 测试
    std::cout<<"hello CatLog" << std::endl;

    CAT_LOG_INFO(logger)<<"test marco";
    CAT_LOG_ERROR(logger)<<"test marco error";

    CAT_LOG_FMT_ERROR(logger,"test macro fmt error %s","aa");
    return 0;
}