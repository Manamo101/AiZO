#ifndef SHELLSORT_H
#define SHELLSORT_H

#include <iostream>
#include <cmath>
#include "InsertionSort.h"

template<typename T = int, int version = 1> 
class ShellSort{
    public:
        static const int SHELL_VERSION = 1;
        static const int KNUTH_VERSION = 2;

        static void shellSort(T arr[], int n){
            switch (version){
            case SHELL_VERSION:
                shellVersionShellSort(arr, n);
                break;
            case KNUTH_VERSION:
                knuthVersionShellSort(arr, n, 1);
                break;
            default:
                shellVersionShellSort(arr, n);
                break;
            }
        }
    private:
        static void knuthVersionShellSort(T arr[], int n, int k){
            int gap = (3 * k - 1) / 2;
            if (gap > ceil(n/3))
                return;
            knuthVersionShellSort(arr, n, k * 3);
            InsertionSort<>::insertionSort(arr, n, gap);
        }
        static void shellVersionShellSort(T arr[], int n){
            int N = n/2;
            while (N > 0){
                InsertionSort<>::insertionSort(arr, n, N);
                N/=2;
            }
        }
};

#endif