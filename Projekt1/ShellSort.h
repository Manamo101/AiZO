#ifndef SHELLSORT_H
#define SHELLSORT_H

#include "InsertionSort.h"

// klasa posiadająca funkcje zawierające algorytmy sortowania przez kopcowanie
// paramentry: typ danych, wersja sortowania (domyślnie integer oraz Shella)
template<typename T = int, int version = 1> 
class ShellSort{
    public:
		// stałe będące parametrami informującymi o algorytmie przerw pomiędzy wartościami
        static const int SHELL_VERSION = 1;
        static const int KNUTH_VERSION = 2;

        // sortowanaie Shella
        // argumenty: tablica do posortowania, długość tablicy
        static void shellSort(T arr[], int n);
    private:
        // algorytm wyliczania przerw Knutha
        // argumenty: tablica do posortowania, długość tablicy, wartość skoku
        static void knuthVersionShellSort(T arr[], int n, int k);
        // algorytm wyliczania przew Shella
        // argumenty: tablica do posortowania, długość tablicy
        static void shellVersionShellSort(T arr[], int n);
};

#endif