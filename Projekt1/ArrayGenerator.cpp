#include <iostream>
#include <ctime>
#include <cstdlib>
#include "ArrayGenerator.h"

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
T* ArrayGenerator<T>::partlySortedRandomArray(int n, int precentage){
    if (precentage > 100) return NULL;
    T *arr = randomArray(n);
    BubbleSort<T> bubblesort(arr, n, (float)(n*precentage/100));
    return arr;
}

template <typename T = int>
void ArrayGenerator<T>::printTable(T arr[], int n){
    for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
}