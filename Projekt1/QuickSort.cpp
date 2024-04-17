#include <iostream>
#include "QuickSort.h"

using namespace std;

template <typename T = int, int pivotIndex = -1>
void QuickSort<T, pivotIndex>::quickSort(T arr[], int start, int end){

    // inicjalizacja tablicy działającej na zasadzie stosu
    int *stack = new int[end - start + 1]; 
  
    // wskaźnik na szczyt stosu
    int top = -1; 
  
    // położenie na stos 2 początkowych szerokości tabliy 
    stack[++top] = start; 
    stack[++top] = end; 
  
    // pętlą pracująca na indeksach pobranych ze stosu
    while (top >= 0) { 
        // zabranie ze stosu informacji o szerokości liczonej podtablicy
        end = stack[top--]; 
        start = stack[top--]; 

        // odpowiedznie rozmieszczenie wartości
        int p = partition(arr, start, end); 

        // odłożenie na stos lewej części podtablicy
        if (p > start) { 
            stack[++top] = start; 
            stack[++top] = p; 
        } 

        // odłożenie na stos prawej częsci podtablicy
        if (p + 1 < end) { 
            stack[++top] = p + 1; 
            stack[++top] = end; 
        } 
    }
    delete [] stack;
}

template <typename T = int, int pivotIndex = -1>
void QuickSort<T, pivotIndex>::quickSortDesc(T arr[], int start, int end){

    // inicjalizacja tablicy działającej na zasadzie stosu
    int *stack = new int[end - start + 1]; 
  
    // wskaźnik na szczyt stosu
    int top = -1; 
  
    // położenie na stos 2 początkowych szerokości tabliy 
    stack[++top] = start; 
    stack[++top] = end; 
  
    // pętlą pracująca na indeksach pobranych ze stosu
    while (top >= 0) { 
        // zabranie ze stosu informacji o szerokości liczonej podtablicy
        end = stack[top--]; 
        start = stack[top--]; 

        // odpowiedznie rozmieszczenie wartości
        int p = partitionDesc(arr, start, end); 

        // odłożenie na stos lewej części podtablicy
        if (p > start) { 
            stack[++top] = start; 
            stack[++top] = p; 
        } 

        // odłożenie na stos prawej częsci podtablicy
        if (p + 1 < end) { 
            stack[++top] = p + 1; 
            stack[++top] = end; 
        } 
    }
    delete [] stack;

}

template <typename T = int, int pivotIndex = -1>
int QuickSort<T, pivotIndex>::partition(T arr[], int start, int end){
    int index = getPivot(arr, start, end); // uzyskanie adresu pivota
    T pivot = arr[index]; // storzenie zmiennej przechowującej wartość pivota

    int l = start, r = end; // zmienne pomocnicze przechodzące po tablicy
    while (true) {
        while (arr[l] < pivot) l++; // znalezienie liczby niepasującej z lewej strony
        while (arr[r] > pivot) r--; // znalezienie liczby niepasującej z prawej strony

        if (l < r){ // sprawdzenie czy sprawdzona została cała tablica
            swap(arr[l], arr[r]); // zamiana stronami niepasujących elementów
            l++; // inkrementacje w celu dalszych poszukiwań
            r--;
        }
        else{
            if (r == end) r++; // jeśli prawy pivot jest na skrajnej pozycji zmniejszamy, aby móc dokonać podziału na dwie podtablice
            return r; // tablica wstępnie posortowana
        }
    }
}

template <typename T = int, int pivotIndex = -1>
int QuickSort<T, pivotIndex>::partitionDesc(T arr[], int start, int end){
    int index = getPivot(arr, start, end); // uzyskanie adresu pivota
    T pivot = arr[index]; // storzenie zmiennej przechowującej wartość pivota

    int l = start, r = end; // zmienne pomocnicze przechodzące po tablicy
    while (true) {
        while (arr[l] > pivot) l++; // znalezienie liczby niepasującej z lewej strony
        while (arr[r] < pivot) r--; // znalezienie liczby niepasującej z prawej strony

        if (l < r){ // sprawdzenie czy sprawdzona została cała tablica
            swap(arr[l], arr[r]); // zamiana stronami niepasujących elementów
            l++; // inkrementacje w celu dalszych poszukiwań
            r--;
        }
        else{
            if (r == end) r++; // jeśli prawy pivot jest na skrajnej pozycji zmniejszamy, aby móc dokonać podziału na dwie podtablice
            return r; // tablica wstępnie posortowana
        }
    }
}


template <typename T = int, int pivotIndex = -1>
int QuickSort<T, pivotIndex>::getPivot(T arr[],int start, int end){
    switch (pivotIndex){ // zwrócenie odpowiedniej wartości dla pasującego parametru
        case LEFT_INDEX:
            return start;
        case RIGHT_INDEX:
            return end-1;
        case MIDDLE_INDEX:
            return	(start + end) / 2;
        case RANDOM_INDEX:
            srand(time(NULL));
            return rand() % (end - start) + start;
        default: //parametr domyślny - lewy pivot
            return start;
    }
}