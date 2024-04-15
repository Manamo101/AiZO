#include <iostream>
#include <ctime>
#include <cstdlib>
#include "ArrayGenerator.h"
#include "QuickSort.h"

using namespace std;

template <typename T = int>
T* ArrayGenerator<T>::randomArray(int n, int max){
    T *arr = new T[n]; // stworzenie tablicy
    srand(time(0)); //ustawienie ziarna
    for (int i = 0; i < n; i++){
        if (typeid(T) == typeid(int)){ // ustalenie typu
            arr[i] = rand() % max; // wylosowanie wartości
        }
        if (typeid(T) == typeid(float)){
            arr[i] = (rand() % max - 1 + rand() / (float)RAND_MAX);
        }
    } 
    return arr;
}

template <typename T = int>
T* ArrayGenerator<T>::randomArray(T arr[],int n, int min){
    int minValue = arr[min]; // ustalenie limitu
    srand(time(0)); //ustawienie ziarna
    for (int i = min + 1; i < n; i++){
        if (typeid(T) == typeid(int)){ // ustalenie typu
            arr[i] = (T)(rand()%(RAND_MAX - minValue) + minValue); // wylosowanie wartości
        }
        if (typeid(T) == typeid(float)){
            arr[i] = (T)((rand() - 1)%(RAND_MAX - minValue) + minValue + rand()/(float)RAND_MAX);
        }
    } 
    return arr;
}

template <typename T = int>
T* ArrayGenerator<T>::hardCopy(T arr[], int n){
    T* newAray = new T[n]; // utworzenie tablicy
    for (int i = 0; i < n; i++) {
        newAray[i] = arr[i]; // skopiowanie wartości z jednej do drugiej
    }
    return newAray;
}


template <typename T = int>
T* ArrayGenerator<T>::partlySortedRandomArray(int n, int precentage){
    if (precentage > 100) return NULL; // sprawdzenie poprawności
    T *arr = randomArray(n); // inicjalizacja losowej tablicy
    QuickSort<T, QuickSort<>::LEFT_INDEX>::quickSort(arr, 0, n -1); // posortowanie tablicy
    randomArray(arr, n, n*precentage/100); // ponowne wylosowanie z ograniczeniem dolnej wartości oraz indeksu
    return arr;
}

template <typename T = int>
T* ArrayGenerator<T>::sortedArrayDesc(int n){
    T *arr = randomArray(n); // inicjalizacja losowej tablicy
    QuickSort<T, QuickSort<>::LEFT_INDEX>::quickSortDesc(arr, 0, n - 1); // posortowanie tablicy malejąco
    return arr;
}

template <typename T = int>
bool ArrayGenerator<T>::isSorted(T arr[], int n){
    for (int i = 0; i < n - 1; i++){
        if (arr[i] > arr[i + 1]) // sprawdzenie czy wartość kolejna jest mniejsze od poprzedniej
            return false;
    }
    return true;
}