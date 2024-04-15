#ifndef FILEMANAGMENT_H
#define FILEMANAGMENT_H

#include <iostream>

//klasa zajmująca się wyciąganiem danych z pliku
class FileManagment {
    public:

    // dowiaduje się o długości tablicy na podstawie 1. wiersza pliku
    // argumenty: ścieżka pliku
    // zwraca: ilość elementów podanych w pliku
    static int getArraySize(std::string filename);

    // pobiera wartości z pliku i ładuje je do tablicy
    // argumenty: ścieżka pliku
    // zwraca: tablica
    static int* getArray(std::string filename);
};

#endif