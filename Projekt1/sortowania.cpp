#include <iostream>
#include "QuickSort.h"
#include "QuickSort.cpp"
#include "InsertionSort.h"
#include "InsertionSort.cpp"
#include "ShellSort.h"
#include "ShellSort.cpp"
#include "Timer.h"
#include "Timer.cpp"
#include "ArrayGenerator.h"
#include "ArrayGenerator.cpp"
#include "HeapSort.h"
#include "HeapSort.cpp"
#include "BubbleSort.h"

using namespace std;

int main()
{
    typedef int T;
    int n = 10;

    ArrayGenerator<T> arrayGenerator;
    // T *arr = new T[9]{7,5,9,6,7,8,10,1,11}; // length: 9
    T *arr = arrayGenerator.randomArray(n);
    // T *arr = arrayGenerator.partlySortedRandomArray(n, 33);
    Timer timer;
    // InsertionSort<T>::insertionSort(arr, n);
    QuickSort<T, QuickSort<>::RIGHT_INDEX>::quickSortDesc(arr, 0, n-1);

    // ShellSort<T, ShellSort<>::SHELL_VERSION>::shellSort(arr, n);
    // HeapSort<T>::heapSort(arr, n);
    timer.stop();
    arrayGenerator.printTable(arr, n);
    delete [] arr;




    return 0;
}