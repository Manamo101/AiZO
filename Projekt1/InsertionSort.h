#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include <iostream>

template <typename T = int>
class InsertionSort{
    public:
    inline static void insertionSort(T arr[], int n){

        for (int i = 1; i < n; i++){
            T value = arr[i];
            int j;
            for (j = i; j > 0 && arr[j-1] > value; j--){
                arr[j] = arr[j-1];
            }
            arr[j] = value;
        }
    }

    inline static void insertionSort(T arr[], int n, int gap){
        for (int i = 0; i < n && i < gap; i++){
            for (int j = i; j < n; j+=gap){
                T value = arr[j];
                int k;
                for (k = j; k-gap >= 0 && arr[k-gap] > value; k-=gap){
                    arr[k] = arr[k-gap];
                }
                arr[k] = value;
            }
        }
    }
};

#endif