#ifndef ARRAY_GENERATOR_H
#define ARRAY_GENERATOR_H

#include <iostream>
#include <ctime>
#include <cstdlib>

template <typename T = int>
class ArrayGenerator{
    public:
        T* randomArray(int n, int max);
        T* partlySortedRandomArray(int n, int precentage); // percentage - zmienna określająca procent posortowania wartości w zakresie od 0% do 100%
        T* sortedArrayDesc(int n);
        T* hardCopy(T arr[], int n);
        bool isSorted(T arr[], int n);
    private:
        T* randomArray(T arr[], int n, int min);
};

#endif