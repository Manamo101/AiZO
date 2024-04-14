#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

// klasa posiadająca funkcje zawierające algorytmy sortowania przez wstawianie
// paramentr: typ danych (domyślnie integer)
template <typename T = int>
class InsertionSort{
    public:
    // sortowanie przez wstawianie
    // arugmenty: tablica do posortowania, długość tablicy
    static void insertionSort(T arr[], int n);

    // sortowanie przez wstawianie przystosowane do wykorzystania dla algorytmu Shella
    // argumenty: tablica do posortowania, długość tablicy, szerokość luk
    static void insertionSort(T arr[], int n, int gap);
};
#endif