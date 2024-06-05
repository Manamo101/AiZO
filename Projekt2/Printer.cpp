#include <iostream>
#include <stdio.h>
#include <iomanip>
#include "Printer.h"

using namespace std;

void Printer::print_matrix_graph(int **matrix, int vertices, int edges){
    cout << "Macierz incydencji" << endl << endl;
    cout << "     ";
    for (int j = 0; j < edges; ++j){
            printf("%5s%i ", "e",j);
        }
        cout << endl;
    for (int i = 0; i < vertices; ++i){
        cout << setw(3) << "v" << i << " ";
        for (int j = 0; j < edges; ++j){
            cout << setw(6) << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl << endl;
}

void Printer::print_list_graph(Graph_list **list, int vertices){
    cout << "Lista sasiedztwa" << endl;
    for(int i = 0; i < vertices; i++){
    cout << "v [" << i << "] =";
    Graph_list *l =  list[i];
    while(l){
      cout << setw (3) << l->v << ":" << l->w;
      l = l->next;
    }
    cout << endl;
  }
}