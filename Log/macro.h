//
// Created by Reeb Deve on 2022/5/16.
//

#ifndef CATLOG_MACRO_H
#define CATLOG_MACRO_H


#include <string.h>
#include <assert.h>
#include "CatLog1.h"
#include "util.h"

#if defined __GNUC__ || defined __llvm__
/// LIKCLY 宏的封装, 告诉编译器优化,条件大概率成立
#   define SYLAR_LIKELY(x)       __builtin_expect(!!(x), 1)
/// LIKCLY 宏的封装, 告诉编译器优化,条件大概率不成立
#   define SYLAR_UNLIKELY(x)     __builtin_expect(!!(x), 0)
#else
#   define SYLAR_LIKELY(x)      (x)
#   define SYLAR_UNLIKELY(x)      (x)
#endif

/// 断言宏封装
#define SYLAR_ASSERT(x) \
    if(SYLAR_UNLIKELY(!(x))) { \
        SYLAR_LOG_ERROR(SYLAR_LOG_ROOT()) << "ASSERTION: " #x \
            << "\nbacktrace:\n" \
            << sylar::BacktraceToString(100, 2, "    "); \
        assert(x); \
    }

/// 断言宏封装
#define SYLAR_ASSERT2(x, w) \
    if(SYLAR_UNLIKELY(!(x))) { \
        SYLAR_LOG_ERROR(SYLAR_LOG_ROOT()) << "ASSERTION: " #x \
            << "\n" << w \
            << "\nbacktrace:\n" \
            << sylar::BacktraceToString(100, 2, "    "); \
        assert(x); \
    }


#endif //CATLOG_MACRO_H
