//
// Created by Reeb Deve on 2022/5/15.
//
#include <iostream>
#include <stdlib.h>
#include "CatLog1.h"
#include "leveldb/db.h"
// Comma-separated list of operations to run in the specified order
//   Actual benchmarks:
//      fillseq       -- write N values in sequential key order in async mode
//      fillrandom    -- write N values in random key order in async mode
//      overwrite     -- overwrite N values in random key order in async mode
//      fillsync      -- write N/100 values in random key order in sync mode
//      fill100K      -- write N/1000 100K values in random order in async mode
//      deleteseq     -- delete N keys in sequential order
//      deleterandom  -- delete N keys in random order
//      readseq       -- read N times sequentially
//      readreverse   -- read N times in reverse order
//      readaddrseq
//      readaddrreverse
//      fetchvaluefromaddr
//      readrandom    -- read N times in random order
//      readmissing   -- read N missing keys in random order
//      readhot       -- read N times in random order from 1% section of DB
//      seekrandom    -- N random seeks
//      seekordered   -- N ordered seeks
//      open          -- cost of opening a DB
//      crc32c        -- repeated crc32c of 4K of data
//   Meta operations:
//      compact     -- Compact the entire DB
//      stats       -- Print DB stats
//      sstables    -- Print sstable info
//      heapprofile -- Dump a heap profile (if supported by this port)
static const char* FLAGS_benchmarks =
        "fillseq,"
        "fillsync,"
        "fillrandom,"
        "overwrite,"
        "readrandom,"
        "readrandom,"  // Extra run to allow previous compactions to quiesce
        "readseq,"
        "readreverse,"
        "readaddrseq,"
        "fetchvaluefromaddr,"
        "readaddrreverse,"
        "fetchvaluefromaddr,"
        "compact,"
        "readrandom,"
        "readseq,"
        "readreverse,"
        "fill100K,"
        "crc32c,"
        "snappycomp,"
        "snappyuncomp,";
// Number of key/values to place in database
static int FLAGS_num = 1000000;

// Number of read operations to do. If negative, do FLAGS_num reads.
static int FLAGS_reads = -1;

// Number of concurrent threads to run.
static int FLAGS_threads = 1;

// Size of each value
static int FLAGS_value_size = 100;

// Arrange to generate values that shrink to this fraction of
// their original size after compression
static double FLAGS_compression_ratio = 0.5;

// Print histogram of operation timings
static bool FLAGS_histogram = false;

// Count the number of string comparisons performed
static bool FLAGS_comparisons = false;

// Number of bytes to buffer in memtable before compacting
// (initialized to default value by "main")
static int FLAGS_write_buffer_size = 0;

// Number of bytes written to each file.
// (initialized to default value by "main")
static int FLAGS_max_file_size = 0;


// Approximate size of user data packed per block (before compression.
// (initialized to default value by "main")
static int FLAGS_block_size = 0;

// Number of bytes to use as a cache of uncompressed data.
// Negative means use default settings.
static int FLAGS_cache_size = -1;

// Maximum number of files to keep open at the same time (use default if == 0)
static int FLAGS_open_files = 0;

// Bloom filter bits per key.
// Negative means use default settings.
static int FLAGS_bloom_bits = -1;

// Common key prefix length.
static int FLAGS_key_prefix = 0;


// If true, do not destroy the existing database.  If you set this
// flag and also specify a benchmark that wants a fresh database, that
// benchmark will fail.
static bool FLAGS_use_existing_db = false;

// If true, reuse existing log/MANIFEST files when re-opening a database.
static bool FLAGS_reuse_logs = false;

// Use the db with the following name.
static const char* FLAGS_db = nullptr;







void LogTest()
{
    CatLog::Logger::ptr logger(new CatLog::Logger);
    logger->addAppender(CatLog::LogAppender::ptr(new CatLog::StdoutLogAppender));
    CatLog::FileLogAppender::ptr file_appender(new CatLog::FileLogAppender("./log.txt"));
    CatLog::LogFormatter::ptr fmt(new CatLog::LogFormatter("%d%T%p%T%m%n"));
    file_appender->setFormatter(fmt);
    file_appender->setLevel(CatLog::LogLevel::ERROR);
    CatLog::DataBaseAppender::ptr database_appender(new CatLog::DataBaseAppender());
    database_appender->setLevel(CatLog::LogLevel::ERROR);
    database_appender->setFormatter(fmt);

    logger->addAppender(file_appender);
    logger->addAppender(database_appender);
    //CatLog_LOG_INFO(logger) << "test" ;
    CatLog::LogEvent::ptr event(new CatLog::LogEvent(logger, CatLog::LogLevel::ERROR,
                                                     __FILE__, __LINE__, 0, CatLog::GetThreadId(),
                                                     CatLog::GetFiberId(), time(0), CatLog::Thread::GetName()));
    event->getSS()<<"test i am happy to have a dog";
    logger->log(CatLog::LogLevel::ERROR,event);
    std::string res = database_appender->getLog(std::to_string(event->getTime()));
    std::cout<<res<<std::endl;
}
int levedbtest(int argc,char** argv)
{
    FLAGS_write_buffer_size = leveldb::Options().write_buffer_size;
    FLAGS_max_file_size = leveldb::Options().max_file_size;
    FLAGS_block_size = leveldb::Options().block_size;
    FLAGS_open_files = leveldb::Options().max_open_files;
    std::string default_db_path;

    return 0;
}
int main()
{
    LogTest();
    return 0;
}
