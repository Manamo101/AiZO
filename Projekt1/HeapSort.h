#ifndef HEAPSORT_H
#define HEAPSORT_H

// klasa posiadająca funkcje zawierające algorytmy sortowania przez kopcowanie
// paramentr: typ danych (domyślnie integer)
template <typename T = int>
class HeapSort{
    public:
        // sortowanie przez kopcowanie
        // argumenty: tablica do posortowania, długość tablicy
        static void heapSort(T arr[], int n);
    private:
        //naprawa kopca w górę
        // argumenty: tablica do posortowania, długość tablicy, indeks rodzica
        static void fixHeap(T arr[], int n, int parent);
        // stworzenie kopca
        // argumenty: tablica do posortowania, długość tablicy
        static void createHeap(T arr[], int n);
};
#endif