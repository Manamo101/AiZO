#ifndef CLIManager_H
#define CLIManager_H

#include <iostream>

// klasa odpowiedzialna za iterakcję z użytkownikiem
class CLIManager {

public:
    // pozyskanie informacji o wyborze typu danych (int lub float)
    // zwraca: zapiasany słownie typ danych
    static std::string getType();

    // pozysanie informacji o nazwie pliku
    // zwraca: ścieżkę do pliku
    static std::string getFilename();

    // pozyskanie informacji o górnej granicy losowanych wartości
    // zwraca: zakres górny
    static int getRangeRandom();

    // pozyskanie inforamcji o wyborze tablicy o zadanych wartościach (losowych bądź z pliku)
    // zwraca: inforamcje o typie
    static char getTableType();

    // pozyskanie inforamcji o ilości elementach w dla nowej losowej tablicy
    // zwraca: długość tablicy
    static int getNumberOfElements();

    // pozyskanie informacji o wersji algrytmy shella
    // zwraca: znak wersji
    static char getShellsortVersion();

    // pozyskanie informacji o pivocie algorytmu szybkiego
    // zwraca: znak pivota
    static char getQuicksortPivot();

    // wypisanie na ekranie zawartości tablicy
    // argumenty: tablica, długość tablicy
    static void printTable(int arr[], int n);

    // wypisanie na ekranie zawartości tablicy
    // argumenty: tablica, długość tablicy
    static void printTable(float arr[], int n);

    // wypisanie menu wyboru na ekranie
    static void printMenu();

    // funkcja czekająca na wciśnięcie przycisku ESCAPE
    static void wyjdz();
};
#endif