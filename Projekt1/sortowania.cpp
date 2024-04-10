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
    int n = 10000;
    int time = 0;
    int count = 50;

    for (int i = 0; i < count; i++){
        ArrayGenerator<T> arrayGenerator;
        // T *arr = arrayGenerator.randomArray(n);
        // InsertionSort<T>::insertionSort(arr, n);
        // QuickSort<T, QuickSort<>::LEFT_INDEX>::quickSort(arr, 0, n - 1);
        T *arr = arrayGenerator.sortedArrayDesc(n);
        // T *arr = arrayGenerator.partlySortedRandomArray(n, 33);
        Timer timer;
        InsertionSort<T>::insertionSort(arr, n);
        // QuickSort<T, QuickSort<>::LEFT_INDEX>::quickSort(arr, 0, n - 1);
        // ShellSort<T, ShellSort<>::KNUTH_VERSION>::shellSort(arr, n);
        // HeapSort<T>::heapSort(arr, n);
        time += timer.stop();
        // arrayGenerator.printTable(arr, n);
        delete [] arr;
    }
    time /= count;
    cout<<time;


    return 0;
}