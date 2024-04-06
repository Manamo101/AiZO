#ifndef ARRAY_GENERATOR_H
#define ARRAY_GENERATOR_H

#include <iostream>
#include <ctime>
#include <cstdlib>

template <typename T = int>
class ArrayGenerator{
    public:
        T* randomArray(int n);
        T* partlySortedRandomArray(int n, int precentage); // percentage - zmienna określająca procent posortowania wartości w zakresie od 0% do 100%
        void printTable(T arr[], int n);
    private:
        T* randomArray(T arr[], int n, int min);
};

#endif