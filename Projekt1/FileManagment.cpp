#include <iostream>
#include <fstream>
#include "FileManagment.h"

using namespace std;

int FileManagment::getArraySize(string filename){
    ifstream file(filename);
    int size;
    file >> size;
    file.close();
    return size;
}
int* FileManagment::getArray(string filename) {
    ifstream file(filename);
    int size;
    file >> size;
    int *arr = new int[size];
    for (int i = 0; i < size; i++) {
        file >> arr[i];
    }
    file.close();
    return arr;
}