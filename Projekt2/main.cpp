#include <iostream>
#include <iomanip>
#include <windows.h>
#include "graph_list.h"
#include "Generate_graph.h"
#include "Generate_graph.cpp"
#include "Printer.cpp"
#include "MST.h"
#include "MST.cpp"
#include "ShortPath.h"
#include "ShortPath.cpp"

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

    int **incidence_matrix2 = new int*[4]{
            new int[5]{6,3,0,0,0},
            new int[5]{6,0,1,3,0},
            new int[5]{0,3,1,0,5},
            new int[5]{0,0,0,3,5}
        };

    int vertices = 100;
    int density = 100;
    int edges_full = vertices * (vertices - 1) / 2;
    int edges_density = edges_full * density/(float)100;
    Generate_graph::graph_type type = Generate_graph::graph_type::directed;
    // int **matrix = incidence_matrix2;

    int ** matrix = Generate_graph::create_graph_incidence_matrix(vertices, edges_density, type);
    // int ** matrix = Generate_graph::complete_incidence_matrix(vertices, type);
    Graph_list **list = Generate_graph::parse_to_adjacency_list(vertices, edges_density, matrix, type);
    
    // Printer::print_matrix_graph(matrix, vertices, edges_density);
    // Printer::print_list_graph(list, vertices);

    // MST mst;
    // int** mstm = mst.Prim_Matrix(matrix, edges_full, vertices, type, MST::no);
    // Printer::print_matrix_graph(mstm, vertices, vertices - 1);
    // int** sth = Generate_graph::densify_incidence_matrix(vertices, mstm, edges_density, type);
    // Printer::print_matrix_graph(sth, vertices, edges_density);

    // Graph_list** mstl = mst.Prim_List(list, edges_full, vertices);
    // Graph_list **list2 = Generate_graph::parse_to_adjacency_list(vertices, edges_density, sth, type);
    // Printer::print_list_graph(mstl, vertices);
    
    ShortPah sp;
    sp.Dijkstra_Matrix(matrix, edges_density, vertices, 0);
    sp.Dijkstra_List(list, edges_density, vertices, 0);

    // usuwanie
    for(int i = 0; i < vertices; ++i) {
        Graph_list *p = list[i];
        while(p) {
            Graph_list *r = p;
            p = p->next;
            delete r;
        }
    }
    delete [] list;

    for (int i = 0; i < vertices; ++i){
        delete [] matrix[i];
    }
    delete [] matrix;
    return 0;
}