#ifndef TIMER_H
#define TIMER_H

#include <chrono>

// klasa odpowiedzialna za odmierzanie czasu wykonania algorytmów
class Timer{
private:
    // zmienna pamiętająca czas od momentu startu
    const std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

public:
    //funkcja kończąca mierzenie czasu
    //zwraca: czas wykonania
    float stop();
};
#endif TIMER_H