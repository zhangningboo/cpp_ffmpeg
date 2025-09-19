cmake_minimum_required(VERSION 3.16)
project(sleep_test)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(ENV{PKG_CONFIG_PATH} "/data/workspace/cpp_ffmpeg/install/x264-20250815/lib/pkgconfig:$ENV{PKG_CONFIG_PATH}")
set(ENV{PKG_CONFIG_PATH} "/data/workspace/cpp_ffmpeg/install/x265_4.1/lib/pkgconfig:$ENV{PKG_CONFIG_PATH}")
set(ENV{PKG_CONFIG_PATH} "/data/workspace/cpp_ffmpeg/install/fdk-aac/lib/pkgconfig:$ENV{PKG_CONFIG_PATH}")
set(ENV{PKG_CONFIG_PATH} "/data/workspace/cpp_ffmpeg/install/FFmpeg-n4.3.9/lib/pkgconfig:$ENV{PKG_CONFIG_PATH}")
find_package(PkgConfig REQUIRED)

pkg_check_modules(X264 REQUIRED IMPORTED_TARGET x264)  # IMPORTED_TARGET后的值为pkgconfig文件夹下.pc文件的名字
pkg_check_modules(X265 REQUIRED IMPORTED_TARGET x265)
pkg_check_modules(FDKAAC REQUIRED IMPORTED_TARGET fdk-aac)
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
    PkgConfig::X264
    PkgConfig::X265
    PkgConfig::FDKAAC
    PkgConfig::AVFORMAT
    PkgConfig::AVCODEC
    PkgConfig::AVUTIL
    PkgConfig::SWSCALE
    PkgConfig::SWRESAMPLE
)

# export LD_LIBRARY_PATH=/data/workspace/cpp_ffmpeg/install/x264-20250815/lib:$LD_LIBRARY_PATH
# export LD_LIBRARY_PATH=/data/workspace/cpp_ffmpeg/install/x265_4.1/lib:$LD_LIBRARY_PATH
# export LD_LIBRARY_PATH=/data/workspace/cpp_ffmpeg/install/fdk-aac/lib:$LD_LIBRARY_PATH
# export LD_LIBRARY_PATH=/data/workspace/cpp_ffmpeg/install/FFmpeg-n4.3.9/lib:$LD_LIBRARY_PATH