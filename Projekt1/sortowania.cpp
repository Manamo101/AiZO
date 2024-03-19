#include <iostream>
#include "QuickSort.h"
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "ShellSort.h"
#include "Timer.h"
#include "ArrayGenerator.h"

using namespace std;

int main()
{
    typedef int T;
    int n = 10;

    ArrayGenerator<T> arrayGenerator;
    // T *arr = new T[12]{32,17,84,21,56,42,86,19,7,41,25,51}; // length: 12
    T *arr = arrayGenerator.randomArray(n);
    //T *arr = arrayGenerator.partlySortedRandomArray(n, 66);
    Timer timer;
    //QuickSort<T, QuickSort<>::MIDDLE_INDEX>::quickSort(arr, 0, n-1);

    // InsertionSort<T>::insertionSort(arr, 12, 5);
    // InsertionSort<T>::insertionSort(arr, 12, 3);
    // InsertionSort<T>::insertionSort(arr, 12, 1);

    ShellSort<T, ShellSort<>::KNUTH_VERSION>::shellSort(arr, n);
    timer.stop();
    
    arrayGenerator.printTable(arr, n);
    delete [] arr;

    return 0;
}