#include <iostream>
#include <chrono>
#include "Timer.h"

using namespace std::chrono;

float Timer::stop() {
    // czas po zakończeniu
    const auto end = high_resolution_clock::now();

    // zwrócenie różnicy czasu, tj. szybkości algorytmu 
    return duration_cast<microseconds>(end - start).count() / (float)1000;
}
