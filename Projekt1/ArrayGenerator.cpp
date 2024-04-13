#include <iostream>
#include <ctime>
#include <cstdlib>
#include "ArrayGenerator.h"
#include "QuickSort.h"

using namespace std;

template <typename T = int>
T* ArrayGenerator<T>::randomArray(int n){
    T *arr = new T[n];
    srand(time(0));
    for (int i = 0; i < n; i++){
        if (typeid(T) == typeid(int)){
            arr[i] = (T)rand();
        }
        if (typeid(T) == typeid(float)){
            arr[i] = (T)(rand() - 1 + rand()/(float)RAND_MAX);
        }
    } 
    return arr;
}

template <typename T = int>
T* ArrayGenerator<T>::randomArray(T arr[],int n, int min){
    int minValue = arr[min];
    srand(time(0));
    for (int i = min + 1; i < n; i++){
        if (typeid(T) == typeid(int)){
            arr[i] = (T)(rand()%(RAND_MAX - minValue) + minValue);
        }
        if (typeid(T) == typeid(float)){
            arr[i] = (T)((rand() - 1)%(RAND_MAX - minValue) + minValue + rand()/(float)RAND_MAX);
        }
    } 
    return arr;
}

template <typename T = int>
T* ArrayGenerator<T>::partlySortedRandomArray(int n, int precentage){
    if (precentage > 100) return NULL;
    T *arr = randomArray(n);
    QuickSort<T, QuickSort<>::LEFT_INDEX>::quickSort(arr, 0, n -1);
    randomArray(arr, n, n*precentage/100);
    return arr;
}

template <typename T = int>
T* ArrayGenerator<T>::sortedArrayDesc(int n){
    T *arr = randomArray(n);
    QuickSort<T, QuickSort<>::LEFT_INDEX>::quickSortDesc(arr, 0, n - 1);
    return arr;
}

template <typename T = int>
void ArrayGenerator<T>::printTable(T arr[], int n){
    for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
}

template <typename T = int>
bool ArrayGenerator<T>::isSorted(T arr[], int n){
    for (int i = 0; i < n - 1; i++){
        if (arr[i] > arr[i + 1])
            return false;
    }
    return true;
}