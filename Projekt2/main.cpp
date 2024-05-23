#include <iostream>
#include <iomanip>
#include "graph_list.h"
#include "Generate_graph.h"
#include "Generate_graph.cpp"
#include "Printer.cpp"

using namespace std;

int main(){
    // przykład macierzy incydencji oraz listy sąsiedztwa z przykładu grafu na ćwiczeniach
    int incidence_matrix[5][7] = {
            {1,0,0,0,0,1,0},
            {1,1,0,0,0,0,1},
            {0,0,0,1,1,1,1},
            {0,1,1,0,1,0,0},
            {0,0,1,1,0,0,0},
        };
    Graph_list graph, graph1;
    graph.w = 10;
    graph1.w = 5;
    graph.next = &graph1;

    int vertices = 5;
    int **matrix = Generate_graph::complete_incidence_matrix(vertices);

    Printer::print_matrix_graph(matrix, vertices);

    return 0;
}