#ifndef CLIManager_H
#define CLIManager_H

#include <iostream>

class CLIManager {
private:
    /* data */
public:
    static std::string getType();
    static std::string getFilename();
    static int getRangeRandom();
    static char getTableType();
    static int getNumberOfElements();
    static char getShellsortVersion();
    static char getQuicksortPivot();
    static void printTable(int arr[], int n);
    static void printTable(float arr[], int n);
    static void printMenu();
    static void wyjdz();
};
#endif