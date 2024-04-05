#include "HeapSort.h"

// using namespace std;

template <typename T = int>
void HeapSort<T>::heapSort(T arr[], int n) {
    // stworzenie kopca
    createHeap(arr, n);

    for (int i = n - 1; i >= 0; i--) {
      // zamiana wartości
      swap(arr[0], arr[i]);
  
      // naprawa kopca
      fixHeap(arr, i, 0);
   }

}

template <typename T = int>
void HeapSort<T>::fixHeap(T arr[], int n, int parent) {
    int largest = parent; // największy element
    int left = 2*parent + 1; // lewy potomek
    int right = 2*parent + 2; // prawy potomek

    // sprawdzenie czy lewy potomek jest większy od rodzica
    if (left < n && arr[left] > arr[largest])
    largest = left;

    // sprawdzenie czy prawy potomek jest większy od rodzica
    if (right < n && arr[right] > arr[largest])
    largest = right;

    // sprawdzenie czy potrzebna jest zamiana potomka z rodzicem
    if (largest != parent) {
        //zamiana potomka z rodzicem
        swap(arr[parent], arr[largest]);
        // naprawa kopca potomka, w którym zamieniono wartości
        fixHeap(arr, n, largest);
    }
}

template <typename T = int>
void HeapSort<T>::createHeap(T arr[], int n){
    for (int i = n / 2 - 1; i >= 0; i--){ // pętla idzie idzie do góry od najmniejszego rodzica
        fixHeap(arr, n, i); //naprawa kopca poczynając od i-tego węzła
    }
}

