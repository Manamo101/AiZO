#include <iostream>
#include "QuickSort.h"
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "Timer.h"
#include "ArrayGenerator.h"

using namespace std;

int main()
{
    ArrayGenerator<float> arrayGenerator;
    int n = 80000;
    auto *arr = arrayGenerator.randomArray(n);
    //auto *arr = arrayGenerator.partlySortedRandomArray(n, 66);
    Timer timer;
    QuickSort<float, QuickSort<>::MIDDLE_INDEX> quick(arr,0,n-1);
    //BubbleSort bubble(arr, n, 100);
    timer.stop();
    

    // for (int i = 0; i < n; i++) {
    //     cout << arr[i] << " ";
    // }
    delete [] arr;
    return 0;
}