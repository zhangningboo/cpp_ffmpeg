#include <iostream>
#include <ctime>
#include <thread>

extern "C" {
    #include "libavcodec/avcodec.h"
}

int main() {

    // cpu 跳数
    clock_t begin = clock();
    int fps = 0;
    for (;;) {
        fps++;
        this_thread::sleep_for(10);
        // CLOCKS_PER_SEC CPU每秒的跳数
        auto interval = (clock() - begin) / (CLOCKS_PER_SEC / 1000);  // 间隔毫秒数
        if ( interval > 1000) {

        }
    }
    
    return 0;
}