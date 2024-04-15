#include <iostream>
#include <fstream>
#include "FileManagment.h"

using namespace std;

int FileManagment::getArraySize(string filename){
    ifstream file(filename); // inicjalizacja zmiennej służącej do połączenia się z plikiem
    int size; // utworzenie zmiennej przechowującej rozmiar tablicy
    file >> size; // pobranie rozmiaru tablicy
    file.close(); // zamknięcie strumienia
    return size; // zwrócenie żądanej wartości
}
int* FileManagment::getArray(string filename) {
    ifstream file(filename); // inicjalizacja zmiennej służącej do połączenia się z plikiem
    int size; // utworzenie zmiennej przechowującej rozmiar tablicy
    file >> size; // pobranie rozmiaru tablicy
    int *arr = new int[size]; // inicjalizacja tablicy
    for (int i = 0; i < size; i++) {
        file >> arr[i]; //przypisanie tablicy wartości z pliku
    }
    file.close(); // zamknięcie strumienia
    return arr; // zwrócenie tablicy
}