#include <iostream>
#include <iomanip>
#include "graph_list.h"
#include "Generate_graph.h"
#include "Generate_graph.cpp"
#include "Printer.cpp"

using namespace std;

int main(){
    // przykład macierzy incydencji oraz listy sąsiedztwa z przykładu grafu na ćwiczeniach
    int **incidence_matrix = new int*[5]{
            new int[7]{1,0,0,0,0,3,0},
            new int[7]{1,6,0,0,0,0,3},
            new int[7]{0,0,0,2,4,3,3},
            new int[7]{0,6,5,0,4,0,0},
            new int[7]{0,0,5,2,0,0,0},
        };

    int vertices = 5;
    Generate_graph::graph_type type = Generate_graph::graph_type::undirected;
    // int **matrix = incidence_matrix;

    int **matrix = Generate_graph::complete_incidence_matrix(vertices, type);
    Graph_list **list = Generate_graph::complete_adjacency_list(vertices, matrix, type);
    
    Printer::print_matrix_graph(matrix, vertices);
    Printer::print_list_graph(list, vertices);

    return 0;
}