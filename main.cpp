//
// Created by Reeb Deve on 2022/5/15.
//
#include <iostream>
#include "leveldb/db.h"

int main()
{
    std::cout<<"hello world"<<std::endl;
    leveldb::DB* db;
    leveldb::Options options;
    options.create_if_missing = true;
    leveldb::Status status = leveldb::DB::Open(options,"/tmp/testdb",&db);
    assert(status.ok());
    return 0;
}
