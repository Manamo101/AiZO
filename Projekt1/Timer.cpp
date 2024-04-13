#include <iostream>
#include <chrono>
#include "Timer.h"

using namespace std;
using namespace std::chrono;


float Timer::stop(){
    const auto end = high_resolution_clock::now();
    // int time = duration_cast<milliseconds>(end - start).count();
    // cout<<duration_cast<microseconds>(end - start).count() << "us\n" ;
    // cout<<duration_cast<nanoseconds>(end - start).count() << "ns\n" ;
    return duration_cast<microseconds>(end - start).count()/(float)1000;
}
