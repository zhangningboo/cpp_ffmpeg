#include <iostream>

extern "C" {
    #include "libavcodec/avcodec.h"
}

int main() {

    std::cout << avcodec_configuration() << std::endl;
    // 创建frame对象
    AVFrame* frame1 = av_frame_alloc();
    // 图像参数
    frame1->width = 401;
    frame1->height = 300;
    frame1->format = AV_PIX_FMT_ARGB;
    // 分配空间，16字节对齐，默认32字节
    int ret = av_frame_get_buffer(frame1, 16);
    if (ret != 0) {
        char buf[1024] = {0};
        av_strerror(ret, buf, sizeof(buf));
        std::cout << buf << std::endl;
    }
    std::cout << "frame1 linesize[0]: " << frame1->linesize[0] << std::endl;  // 1600 = 400 * 4, 1616 = 4 * [401, 402, 403, 404]
    if (frame1->buf[0]) {
        std::cout << "frame1 ref count" << av_buffer_get_ref_count(frame1->buf[0]) << std::endl;
    }
    AVFrame* frame2 = av_frame_alloc();
    // 创建了frame，不代表frame有内容了，将frame2的内容，使用frame1内容填充
    av_frame_ref(frame2, frame1);
    std::cout << "frame1 ref count" << av_buffer_get_ref_count(frame1->buf[0]) << std::endl;
    std::cout << "frame2 ref count" << av_buffer_get_ref_count(frame2->buf[0]) << std::endl;
    // buf的引用计数减一，【并将buf清零，置为NULL】：将frame2的buf置为NULL，取消了对原buf内容的引用
    av_frame_unref(frame2);
    std::cout << "frame2 buf is NULL: " << (frame2->buf[0] == NULL) << std::endl;
    // 释放frame对象空间，buf的引用计数减一
    // 若buf已经为空，则只删除frame对象空间
    av_frame_free(&frame1);
    // std::cout << "frame1 ref count" << av_buffer_get_ref_count(frame2->buf[0]) << std::endl;  // 会报错，因为buf已经清零
    // 释放frame对象空间，buf的引用计数减一
    av_frame_free(&frame2);
    return 0;
}