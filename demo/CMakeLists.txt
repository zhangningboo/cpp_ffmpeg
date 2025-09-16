cmake_minimum_required(VERSION 3.16)
project(ffmpeg_demo)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(ENV{PKG_CONFIG_PATH} "/data/workspace/cpp_ffmpeg/install/FFmpeg-n4.3.9/lib/pkgconfig:$ENV{PKG_CONFIG_PATH}")
find_package(PkgConfig REQUIRED)
pkg_check_modules(AVFORMAT REQUIRED IMPORTED_TARGET libavformat)
pkg_check_modules(AVCODEC  REQUIRED IMPORTED_TARGET libavcodec)
pkg_check_modules(AVUTIL   REQUIRED IMPORTED_TARGET libavutil)
pkg_check_modules(SWSCALE  REQUIRED IMPORTED_TARGET libswscale)
pkg_check_modules(SWRESAMPLE REQUIRED IMPORTED_TARGET libswresample)

# 生成可执行文件
set(PROJECT_EXEC_NAME ${PROJECT_NAME}_bin)
add_executable(${PROJECT_EXEC_NAME} main.cpp)
target_include_directories(${PROJECT_EXEC_NAME} PUBLIC include)
target_link_libraries(${PROJECT_EXEC_NAME} PRIVATE
    pthread
    stdc++
    PkgConfig::AVFORMAT
    PkgConfig::AVCODEC
    PkgConfig::AVUTIL
    PkgConfig::SWSCALE
    PkgConfig::SWRESAMPLE
)