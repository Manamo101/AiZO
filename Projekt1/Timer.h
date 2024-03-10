#ifndef TIMER_H
#define TIMER_H

#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Timer{
private:
    const high_resolution_clock::time_point start = high_resolution_clock::now();

public:
    inline int stop(){
        const auto end = high_resolution_clock::now();
        int time = duration_cast<milliseconds>(end - start).count();
        cout<< "\n" << time << "ms\n";
        cout<<duration_cast<microseconds>(end - start).count() << "us\n" ;
        cout<<duration_cast<nanoseconds>(end - start).count() << "ns\n" ;
        return time;
    }
};


#endif