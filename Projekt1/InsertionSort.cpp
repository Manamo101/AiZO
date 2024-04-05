#include "InsertionSort.h"

template <typename T = int>
void InsertionSort<T>::insertionSort(T arr[], int n){
    for (int i = 1; i < n; i++){ // przejście po całej tablicy (za wyjątkiem 1. ponieważ jest to niepotrzebne)
        T value = arr[i]; // zmienna z aktualną wartością
        int j; // zmienna pomocnicza pętli
        for (j = i; j > 0 && arr[j-1] > value; j--){ // przesuwanie wartości
            arr[j] = arr[j-1]; // zmiana wartości
        }
        arr[j] = value; // zakończenie przesunięcia wstawiając wartość przed wartościami większymi
    }
}

template <typename T = int>
void InsertionSort<T>::insertionSort(T arr[], int n, int gap){
    for (int i = 0; i < n && i < gap; i++){ // przejscie po tablicy o szerokości skoku
        for (int j = i; j < n; j+=gap){ // pętla idąca co n-tą watość skoku
            T value = arr[j]; // zmienna z aktualną wartością
            int k; // zmienna pomocnicza pętli
            for (k = j; k-gap >= 0 && arr[k-gap] > value; k-=gap){ // przesuwanie wartości z uwzględnieniem skoku
                arr[k] = arr[k-gap]; // zmiana wartości
            }
            arr[k] = value; // zakończenie przesunięcia wstawiając wartość przed wartościami większymi
        }
    }
}