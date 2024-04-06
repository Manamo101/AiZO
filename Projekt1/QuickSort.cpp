#include <iostream>
#include "QuickSort.h"

using namespace std;

template <typename T = int, int pivotIndex = -1>
void QuickSort<T, pivotIndex>::quickSort(T arr[], int start, int end){
    if (start >= end) //sprawdzenie czy talica nie jest jednoelementowa
        return;

    int p = partition(arr, start, end); //odpowiedznie rozmieszczenie wartości
    quickSort(arr, start, p); // rekurencyjne wywołanie dwóch podtablic
    quickSort(arr, p + 1, end);
}

template <typename T = int, int pivotIndex = -1>
void QuickSort<T, pivotIndex>::quickSortDesc(T arr[], int start, int end){
    if (start >= end) //sprawdzenie czy talica nie jest jednoelementowa
        return;

    int p = partitionDesc(arr, start, end); //odpowiedznie rozmieszczenie wartości
    quickSortDesc(arr, start, p); // rekurencyjne wywołanie dwóch podtablic
    quickSortDesc(arr, p + 1, end);
}

template <typename T = int, int pivotIndex = -1>
int QuickSort<T, pivotIndex>::partition(T arr[], int start, int end){
    int index = getPivot(arr, start, end); // uzyskanie adresu pivota
    T pivot = arr[index]; // storzenie zmiennej przechowującej wartość pivota

    int l = start, r = end; // zmienne pomocnicze przechodzące po tablicy
    while (true) {
        while (arr[l] < pivot) l++; // znalezienie liczby niepasującej z lewej strony
        while (arr[r] > pivot) r--; // znalezienie liczby niepasującej z prawej strony

        if (l < r){ // sprawdzenie czy sprawdzona została cała tablica
            swap(arr[l], arr[r]); // zamiana stronami niepasujących elementów
            l++; // inkrementacje w celu dalszych poszukiwań
            r--;
        }
        else{
            if (r == end) r++; // jeśli prawy pivot jest na skrajnej pozycji zmniejszamy, aby móc dokonać podziału na dwie podtablice
            return r; // tablica wstępnie posortowana
        }
    }
}

template <typename T = int, int pivotIndex = -1>
int QuickSort<T, pivotIndex>::partitionDesc(T arr[], int start, int end){
    int index = getPivot(arr, start, end); // uzyskanie adresu pivota
    T pivot = arr[index]; // storzenie zmiennej przechowującej wartość pivota

    int l = start, r = end; // zmienne pomocnicze przechodzące po tablicy
    while (true) {
        while (arr[l] > pivot) l++; // znalezienie liczby niepasującej z lewej strony
        while (arr[r] < pivot) r--; // znalezienie liczby niepasującej z prawej strony

        if (l < r){ // sprawdzenie czy sprawdzona została cała tablica
            swap(arr[l], arr[r]); // zamiana stronami niepasujących elementów
            l++; // inkrementacje w celu dalszych poszukiwań
            r--;
        }
        else{
            if (r == end) r++; // jeśli prawy pivot jest na skrajnej pozycji zmniejszamy, aby móc dokonać podziału na dwie podtablice
            return r; // tablica wstępnie posortowana
        }
    }
}


template <typename T = int, int pivotIndex = -1>
int QuickSort<T, pivotIndex>::getPivot(T arr[],int start, int end){
    switch (pivotIndex){ // zwrócenie odpowiedniej wartości dla pasującego parametru
        case LEFT_INDEX:
            return start;
        case RIGHT_INDEX:
            return end-1;
        case MIDDLE_INDEX:
            return	(start + end) / 2;
        case RANDOM_INDEX:
            srand(time(NULL));
            return rand() % (end - start) + start;
        default: //parametr domyślny - lewy pivot
            return start;
    }
}