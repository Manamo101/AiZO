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
    int n = 1280000;
    float time = 0;
    int count = 50;

    for (int i = 0; i < count; i++){
        ArrayGenerator<T> arrayGenerator;
        // T *arr = arrayGenerator.randomArray(n); 
        // InsertionSort<T>::insertionSort(arr, n);
        // HeapSort<T>::heapSort(arr, n);
        // QuickSort<T, QuickSort<>::LEFT_INDEX>::quickSort(arr, 0, n - 1);
        T *arr = arrayGenerator.sortedArrayDesc(n);
        // T *arr = arrayGenerator.partlySortedRandomArray(n, 100);
        Timer timer;
        // InsertionSort<T>::insertionSort(arr, n);
        QuickSort<T, QuickSort<>::RANDOM_INDEX>::quickSort(arr, 0, n - 1);
        // ShellSort<T, ShellSort<>::SHELL_VERSION>::shellSort(arr, n);
        // HeapSort<T>::heapSort(arr, n);
        time += timer.stop();
        cout<<arrayGenerator.isSorted(arr, n)<<"    ";
        cout<<i + 1<<".     "<<time / (float)(i+1)<<endl;
        // arrayGenerator.printTable(arr, n);
        delete [] arr;
    }
    time /= (float)count;
    cout<<endl<<"finish time: "<<time;


    return 0;
}