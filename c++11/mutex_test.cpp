/*
* Created by smtech on 15-10-23.
* mutex test for c++11
*/

#include <mutex>
#include <thread>
#include <unistd.h>
#include <iostream>

std::mutex mtx;
int critical = 0;

void p() {
    while (true) {
        mtx.lock();
        critical++;
        std::cout<<"p"<<std::this_thread::get_id()<<" "<<critical<<std::endl;
        sleep(1);
        critical--;
        mtx.unlock();
        sleep(1);
    }
}

int main() {
    // std::thread t1(p);
    // std::thread t2(p);
    // t1.join();
    // t2.join();
    return 0;
}
