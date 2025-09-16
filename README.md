## 编译
```shell
$ apt search x264
$ apt search x265
$ apt search libfdk-aac
$ apt install libfdk-aac2 libfdk-aac-dev
$ ./configure \
    --prefix=/data/workspace/cpp_ffmpeg/install/FFmpeg-n7.1.2 \
    --enable-shared \
    --enable-static \
    --disable-programs \
    --disable-ffplay \
    --disable-ffmpeg \
    --disable-ffprobe \
    --enable-gpl \
    --enable-libx264 \
    --enable-libx265 \
    --enable-libfdk-aac \
    --enable-nonfree
$ make -j6
$ make install
```
export LD_LIBRARY_PATH=/data/workspace/cpp_ffmpeg/install/FFmpeg-n4.3.9/lib:$LD_LIBRARY_PATH
./build/ffmpeg_demo_bin

cmake_minimum_required(VERSION 3.15)
project(MyApp CXX)

# 告诉 pkg-config 去哪里找 .pc 文件
set(ENV{PKG_CONFIG_PATH} "/opt/ffmpeg/lib/pkgconfig:$ENV{PKG_CONFIG_PATH}")

# 引入 pkg-config 模块
find_package(PkgConfig REQUIRED)

# 查找 FFmpeg 组件
pkg_check_modules(AVFORMAT REQUIRED IMPORTED_TARGET libavformat)
pkg_check_modules(AVCODEC  REQUIRED IMPORTED_TARGET libavcodec)
pkg_check_modules(AVUTIL   REQUIRED IMPORTED_TARGET libavutil)
pkg_check_modules(SWSCALE  REQUIRED IMPORTED_TARGET libswscale)
pkg_check_modules(SWRESAMPLE REQUIRED IMPORTED_TARGET libswresample)

# 你的可执行文件
add_executable(my_app main.cpp)

# 链接 FFmpeg 库
target_link_libraries(my_app
    PRIVATE
    PkgConfig::AVFORMAT
    PkgConfig::AVCODEC
    PkgConfig::AVUTIL
    PkgConfig::SWSCALE
    PkgConfig::SWRESAMPLE
)
