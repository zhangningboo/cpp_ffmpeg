## 编译ffmpeg
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

## 工程编译
```shell
$ cmake -B build -S .
$ cmake --build build -j
```
