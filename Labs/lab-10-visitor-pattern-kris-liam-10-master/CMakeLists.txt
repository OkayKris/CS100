CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
ADD_SUBDIRECTORY(googletest)
SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(main src/main.cpp src/operators.cpp src/base.cpp src/visitor.cpp)
ADD_EXECUTABLE(test utest/unit_test.cpp src/operators.cpp src/base.cpp src/visitor.cpp)
TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)