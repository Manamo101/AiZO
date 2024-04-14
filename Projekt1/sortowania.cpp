#include <iostream>
#include <conio.h>
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
#include "CLIManager.h"
#include "CLIManager.cpp"
#include "FileManagment.h"
#include "FileManagment.cpp"

using namespace std;

int main() {
    int fileArraySize, randomArraySize;
    int* fileArray, *randomIntArray;
    float *randomFloatArray;
    int maxRangeRandom;
    string filename, type;

    filename = CLIManager::getFilename();
    fileArraySize = FileManagment::getArraySize(filename);
    fileArray = FileManagment::getArray(filename);
    ArrayGenerator<> gen;
    type = CLIManager::getType();
    maxRangeRandom = CLIManager::getRangeRandom();
    
    randomArraySize = 10;
    if (type == "float") {
        ArrayGenerator<float> generator;
        randomFloatArray = generator.randomArray(randomArraySize, maxRangeRandom);
    } 
    else {
        ArrayGenerator<int> generator;
        randomIntArray = generator.randomArray(randomArraySize, maxRangeRandom);
    }
    cout << "\nzainicjalizowano wstepnie losowa tablice o rozmiarze " << randomArraySize << endl;
    

    
    float *copyf;
    int *copyi;
    char selected;
    do {
        CLIManager::printMenu();
        selected = getch();
        // cout << selected << endl;
        char tableType;
        int time;
        switch(selected) {
            case '1':
                char sign;
                sign = CLIManager::getTableType();
                if (sign == 'f')
                    CLIManager::printTable(fileArray, fileArraySize);
                else {
                    if (type == "int")
                        CLIManager::printTable(randomIntArray, randomArraySize);
                    else 
                        CLIManager::printTable(randomFloatArray, randomArraySize);
                }
                CLIManager::wyjdz();
                break;
            case '2':
                randomArraySize = CLIManager::getNumberOfElements();
                if (type == "float") {
                ArrayGenerator<float> generator;
                randomFloatArray = generator.randomArray(randomArraySize, maxRangeRandom);
                } 
                else {
                    ArrayGenerator<int> generator;
                    randomIntArray = generator.randomArray(randomArraySize, maxRangeRandom);
                }
                cout << "Zainicjalizowano tablice\n";
                CLIManager::wyjdz();
                break;
            case '3':
                cout << "InsertionSort" << endl;
                tableType = CLIManager::getTableType();
                if (tableType == 'f') {
                    ArrayGenerator<int> generator;
                    copyi = generator.hardCopy(fileArray, fileArraySize);
                    Timer timer;
                    InsertionSort<int>::insertionSort(copyi, fileArraySize);
                    time = timer.stop();
                    cout << "Posortowanie wykonalo sie w " << time << "ms" << endl;
                    cout << "Tablica po posortowaniu:" << endl;
                    CLIManager::printTable(copyi, fileArraySize);
                }
                else {
                    if (type == "float") {
                        ArrayGenerator<float> generator;
                        copyf = generator.hardCopy(randomFloatArray, randomArraySize);
                        Timer timer;
                        InsertionSort<float>::insertionSort(copyf, randomArraySize);
                        time = timer.stop();
                        cout << "Posortowanie wykonalo sie w " << time << "ms" << endl;
                        cout << "Tablica po posortowaniu:" << endl;
                        CLIManager::printTable(copyf, randomArraySize);
                    }
                    else {
                        ArrayGenerator<int> generator;
                        copyi = generator.hardCopy(randomIntArray, randomArraySize);
                        Timer timer;
                        InsertionSort<int>::insertionSort(copyi, randomArraySize);
                        time = timer.stop();
                        cout << "Posortowanie wykonalo sie w " << time << "ms" << endl;
                        cout << "Tablica po posortowaniu:" << endl;
                        CLIManager::printTable(copyi, randomArraySize);
                    }
                }
                CLIManager::wyjdz();
                break;
            case '4': 
                cout << "Heapsort" << endl;
                tableType = CLIManager::getTableType();
                if (tableType == 'f') {
                    ArrayGenerator<int> generator;
                    copyi = generator.hardCopy(fileArray, fileArraySize);
                    Timer timer;
                    HeapSort<int>::heapSort(copyi, fileArraySize);
                    time = timer.stop();
                    cout << "Posortowanie wykonalo sie w " << time << "ms" << endl;
                    cout << "Tablica po posortowaniu:" << endl;
                    CLIManager::printTable(copyi, fileArraySize);
                }
                else {
                    if (type == "float") {
                        ArrayGenerator<float> generator;
                        copyf = generator.hardCopy(randomFloatArray, randomArraySize);
                        Timer timer;
                        HeapSort<float>::heapSort(copyf, randomArraySize);
                        time = timer.stop();
                        cout << "Posortowanie wykonalo sie w " << time << "ms" << endl;
                        cout << "Tablica po posortowaniu:" << endl;
                        CLIManager::printTable(copyf, randomArraySize);
                    }
                    else {
                        ArrayGenerator<int> generator;
                        copyi = generator.hardCopy(randomIntArray, randomArraySize);
                        Timer timer;
                        HeapSort<int>::heapSort(copyi, randomArraySize);
                        time = timer.stop();
                        cout << "Posortowanie wykonalo sie w " << time << "ms" << endl;
                        cout << "Tablica po posortowaniu:" << endl;
                        CLIManager::printTable(copyi, randomArraySize);
                    }
                }
                CLIManager::wyjdz();
                break;
            case '5': 
                cout << "Shellsort" << endl;
                int shellsortVersion;
                shellsortVersion = CLIManager::getShellsortVersion();
                tableType = CLIManager::getTableType();
                if (tableType == 'f') {
                    ArrayGenerator<int> generator;
                    copyi = generator.hardCopy(fileArray, fileArraySize);
                    if (shellsortVersion == 's'){
                        Timer timer;
                        ShellSort<int, ShellSort<>::SHELL_VERSION>::shellSort(copyi, fileArraySize);
                        time = timer.stop();
                    }
                    else if (shellsortVersion == 'k'){
                        Timer timer;
                        ShellSort<int, ShellSort<>::KNUTH_VERSION>::shellSort(copyi, fileArraySize);
                        time = timer.stop();
                    }
                    cout << "Posortowanie wykonalo sie w " << time << "ms" << endl;
                    cout << "Tablica po posortowaniu:" << endl;
                    CLIManager::printTable(copyi, fileArraySize);
                }
                else {
                    if (type == "float") {
                        ArrayGenerator<float> generator;
                        copyf = generator.hardCopy(randomFloatArray, randomArraySize);
                        if (shellsortVersion == 's'){
                            Timer timer;
                            ShellSort<float, ShellSort<>::SHELL_VERSION>::shellSort(copyf, randomArraySize);
                            time = timer.stop();
                        }
                            else if (shellsortVersion == 'k'){
                            Timer timer;
                            ShellSort<float, ShellSort<>::KNUTH_VERSION>::shellSort(copyf, randomArraySize);
                            time = timer.stop();
                        }
                        cout << "Posortowanie wykonalo sie w " << time << "ms" << endl;
                        cout << "Tablica po posortowaniu:" << endl;
                        CLIManager::printTable(copyf, randomArraySize);
                    }
                    else {
                        ArrayGenerator<int> generator;
                        copyi = generator.hardCopy(randomIntArray, randomArraySize);
                        if (shellsortVersion == 's'){
                            Timer timer;
                            ShellSort<int, ShellSort<>::SHELL_VERSION>::shellSort(copyi, randomArraySize);
                            time = timer.stop();
                        }
                        else if (shellsortVersion == 'k'){
                            Timer timer;
                            ShellSort<int, ShellSort<>::KNUTH_VERSION>::shellSort(copyi, randomArraySize);
                            time = timer.stop();
                        }
                        cout << "Posortowanie wykonalo sie w " << time << "ms" << endl;
                        cout << "Tablica po posortowaniu:" << endl;
                        CLIManager::printTable(copyi, randomArraySize);
                    }
                }
                CLIManager::wyjdz();
                break;
            case '6': 
                cout << "Quicksort" << endl;
                int quicksortPivot;
                quicksortPivot = CLIManager::getQuicksortPivot();
                tableType = CLIManager::getTableType();
                if (tableType == 'f') {
                    ArrayGenerator<int> generator;
                    copyi = generator.hardCopy(fileArray, fileArraySize);
                    if (quicksortPivot == 'l'){
                        Timer timer;
                        QuickSort<int, QuickSort<>::LEFT_INDEX>::quickSort(copyi, 0, fileArraySize - 1);
                        time = timer.stop();
                    }
                    else if (quicksortPivot == 'm'){
                        Timer timer;
                        QuickSort<int, QuickSort<>::MIDDLE_INDEX>::quickSort(copyi, 0, fileArraySize - 1);
                        time = timer.stop();
                    }
                    else if (quicksortPivot == 'p'){
                        Timer timer;
                        QuickSort<int, QuickSort<>::RIGHT_INDEX>::quickSort(copyi, 0, fileArraySize - 1);
                        time = timer.stop();
                    }
                    else if (quicksortPivot == 'r'){
                        Timer timer;
                        QuickSort<int, QuickSort<>::RANDOM_INDEX>::quickSort(copyi, 0, fileArraySize - 1);
                        time = timer.stop();
                    }
                    cout << "Posortowanie wykonalo sie w " << time << "ms" << endl;
                    cout << "Tablica po posortowaniu:" << endl;
                    CLIManager::printTable(copyi, fileArraySize);
                }
                else {
                    if (type == "float") {
                        ArrayGenerator<float> generator;
                        copyf = generator.hardCopy(randomFloatArray, randomArraySize);
                        if (quicksortPivot == 'l'){
                            Timer timer;
                            QuickSort<float, QuickSort<>::LEFT_INDEX>::quickSort(copyf, 0, randomArraySize - 1);
                            time = timer.stop();
                        }
                        else if (quicksortPivot == 'm'){
                            Timer timer;
                            QuickSort<float, QuickSort<>::MIDDLE_INDEX>::quickSort(copyf, 0, randomArraySize - 1);
                            time = timer.stop();
                        }
                        else if (quicksortPivot == 'p'){
                            Timer timer;
                            QuickSort<float, QuickSort<>::RIGHT_INDEX>::quickSort(copyf, 0, randomArraySize - 1);
                            time = timer.stop();
                        }
                        else if (quicksortPivot == 'r'){
                            Timer timer;
                            QuickSort<float, QuickSort<>::RANDOM_INDEX>::quickSort(copyf, 0, randomArraySize - 1);
                            time = timer.stop();
                        }
                        cout << "Posortowanie wykonalo sie w " << time << "ms" << endl;
                        cout << "Tablica po posortowaniu:" << endl;
                        CLIManager::printTable(copyf, randomArraySize);
                    }
                    else {
                        ArrayGenerator<int> generator;
                        copyi = generator.hardCopy(randomIntArray, randomArraySize);
                        if (quicksortPivot == 'l'){
                            Timer timer;
                            QuickSort<int, QuickSort<>::LEFT_INDEX>::quickSort(copyi, 0, randomArraySize - 1);
                            time = timer.stop();
                        }
                        else if (quicksortPivot == 'm'){
                            Timer timer;
                            QuickSort<int, QuickSort<>::MIDDLE_INDEX>::quickSort(copyi, 0, randomArraySize - 1);
                            time = timer.stop();
                        }
                        else if (quicksortPivot == 'p'){
                            Timer timer;
                            QuickSort<int, QuickSort<>::RIGHT_INDEX>::quickSort(copyi, 0, randomArraySize - 1);
                            time = timer.stop();
                        }
                        else if (quicksortPivot == 'r'){
                            Timer timer;
                            QuickSort<int, QuickSort<>::RANDOM_INDEX>::quickSort(copyi, 0, randomArraySize - 1);
                            time = timer.stop();
                        }
                        cout << "Posortowanie wykonalo sie w " << time << "ms" << endl;
                        cout << "Tablica po posortowaniu:" << endl;
                        CLIManager::printTable(copyi, randomArraySize);
                    }
                }
                CLIManager::wyjdz();
                break;
        }
    }
    while(selected != 27);

    delete [] fileArray;
    delete [] randomIntArray;
    delete [] randomFloatArray;
    delete [] copyi;
    delete [] copyf;

    return 0;
}