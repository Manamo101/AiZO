#ifndef PRINTER_H
#define PRINTER_H

#include <iostream>
#include <stdio.h>
#include <iomanip>
#include "Printer.h"

using namespace std;

void Printer::print_matrix_graph(int **matrix, int vertices){
    cout << "Macierz incydencji" << endl << endl;
    cout << "     ";
    for (int j = 0; j < vertices * (vertices - 1) / 2; ++j){
            printf("%5s%i ", "e",j);
        }
        cout << endl;
    for (int i = 0; i < vertices; ++i){
        cout << setw(3) << "v" << i << " ";
        for (int j = 0; j < vertices * (vertices - 1) / 2; ++j){
            cout << setw(6) << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

#endif