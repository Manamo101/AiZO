#ifndef ARRAY_GENERATOR_H
#define ARRAY_GENERATOR_H

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

template <typename T = int>
class ArrayGenerator{
    public:
        inline T* randomArray(int n){
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
        inline T* partlySortedRandomArray(int n, int precentage){ // percentage - zmienna określająca procent posortowania wartości w zakresie od 0% do 100%
            if (precentage > 100) return NULL;
            T *arr = randomArray(n);
            BubbleSort<T> bubblesort(arr, n, (float)(n*precentage/100));
            return arr;
        }
};

#endif