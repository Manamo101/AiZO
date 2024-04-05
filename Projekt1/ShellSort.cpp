#include <cmath>
#include "ShellSort.h"

template<typename T = int, int version = 1> 
void ShellSort<T, version>::shellSort(T arr[], int n){
            switch (version){ // wybór odpowiedniego algorytmu na podstawie podanego parametru
            case SHELL_VERSION:
                shellVersionShellSort(arr, n);
                break;
            case KNUTH_VERSION:
                knuthVersionShellSort(arr, n, 1);
                break;
            default: // wersja domyślna Shella
                shellVersionShellSort(arr, n);
                break;
            }
        }

template<typename T = int, int version = 1> 
void ShellSort<T, version>::knuthVersionShellSort(T arr[], int n, int k){
    int gap = (3 * k - 1) / 2; // obliczenie wartości skoku
    if (gap > ceil(n/3)) // warunek skończenia zwiększania wartości
        return;
    knuthVersionShellSort(arr, n, k * 3); // rekurencyjne wywołanie następnej funcji o większym skoku
    InsertionSort<>::insertionSort(arr, n, gap); // posortowanie wartości przez wstawianie
}

template<typename T = int, int version = 1> 
void ShellSort<T, version>::shellVersionShellSort(T arr[], int n){
    int N = n/2; // obliczenie wartości skoku
    while (N > 0){ // iteracyjne sortowanie
        InsertionSort<>::insertionSort(arr, n, N); // posortowanie wartości przez wstawianie
        N/=2; // zmniejszenie wartości skoku
    }
}