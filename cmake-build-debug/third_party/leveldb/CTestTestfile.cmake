# CMake generated Testfile for 
# Source directory: /Users/reebdeve/CLionProjects/CatLog/third_party/leveldb
# Build directory: /Users/reebdeve/CLionProjects/CatLog/cmake-build-debug/third_party/leveldb
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(leveldb_tests "/Users/reebdeve/CLionProjects/CatLog/cmake-build-debug/bin/leveldb_tests")
set_tests_properties(leveldb_tests PROPERTIES  _BACKTRACE_TRIPLES "/Users/reebdeve/CLionProjects/CatLog/third_party/leveldb/CMakeLists.txt;361;add_test;/Users/reebdeve/CLionProjects/CatLog/third_party/leveldb/CMakeLists.txt;0;")
add_test(c_test "/Users/reebdeve/CLionProjects/CatLog/cmake-build-debug/bin/c_test")
set_tests_properties(c_test PROPERTIES  _BACKTRACE_TRIPLES "/Users/reebdeve/CLionProjects/CatLog/third_party/leveldb/CMakeLists.txt;387;add_test;/Users/reebdeve/CLionProjects/CatLog/third_party/leveldb/CMakeLists.txt;390;leveldb_test;/Users/reebdeve/CLionProjects/CatLog/third_party/leveldb/CMakeLists.txt;0;")
add_test(env_posix_test "/Users/reebdeve/CLionProjects/CatLog/cmake-build-debug/bin/env_posix_test")
set_tests_properties(env_posix_test PROPERTIES  _BACKTRACE_TRIPLES "/Users/reebdeve/CLionProjects/CatLog/third_party/leveldb/CMakeLists.txt;387;add_test;/Users/reebdeve/CLionProjects/CatLog/third_party/leveldb/CMakeLists.txt;398;leveldb_test;/Users/reebdeve/CLionProjects/CatLog/third_party/leveldb/CMakeLists.txt;0;")
subdirs("third_party/googletest")
subdirs("third_party/benchmark")
