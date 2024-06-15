#include <iostream>
#include <random>
#include <ctime>
#include <limits.h>
#include "MST.h"
#include "Generate_graph.h"

using namespace std;

Graph_list** Generate_graph::parse_to_adjacency_list(int vertices, int edges, int** matrix, graph_type type){
    Graph_list **list = new Graph_list* [vertices];
    // int edges = vertices * (vertices - 1) / 2;

    for (int i = 0; i < vertices; ++i)
        list[i] = NULL;

    int a, b;
    Graph_list *l;
    for (int i = 0; i < edges; ++i){
        a = 0;
        b = 0;
        int index_a = NULL, index_b = NULL;
        int j;
        if (type == graph_type::directed){
            for (j = 0; j < vertices; ++j){
                if (matrix[j][i] > 0){
                    a = matrix[j][i];
                    index_a = j;
                }
                if (matrix[j][i] < 0){
                    b = matrix[j][i];
                    index_b = j;
                }
            }
            if (a > 0 && b < 0){
                l = new Graph_list();
                l->w = a;
                l->v = index_b;
                l->next = list[index_a];
                list[index_a] = l;

                // l = new Graph_list();
                // l->w = b;
                // l->v = index_a;
                // l->next = list[index_b];
                // list[index_b] = l;
            }
        }
        else {
            for (j = 0; j < vertices; ++j){
                if (matrix[j][i] > 0){
                    if (a == 0){
                        a = matrix[j][i];
                        index_a = j;
                    }
                    else {
                        b = matrix[j][i];
                        index_b = j;
                    }
                }
            }
            if (a > 0 && b > 0){
                l = new Graph_list();
                l->w = a;
                l->v = index_b;
                l->next = list[index_a];
                list[index_a] = l;

                l = new Graph_list();
                l->w = b;
                l->v = index_a;
                l->next = list[index_b];
                list[index_b] = l;
            }
        }
    }

    return list;
}

int** Generate_graph::complete_incidence_matrix(int vertices, graph_type type){
    srand(time(NULL));
    int edges = vertices * (vertices - 1) / 2;
    int **matrix = new int* [vertices];

    for (int i = 0; i < vertices; ++i){
        matrix[i] = new int [edges];
        for (int j = 0; j < edges; j++)
            matrix[i][j] = 0;
    }

    int a = 0;
    int b = a + 1;
    int limit = vertices - 1;
    int beginning = 0;
    for (int i = 0; i < edges; ++i){
        int random_value;
        if (type == graph_type::undirected)
            random_value = rand() % (INT_MAX - 1) + 1; //losowanie wartości
        else
            random_value = rand() % 2 == 0 ? rand() : -rand(); //losowanie wartości oraz znaku
        matrix[a][i] = random_value;
        matrix[b][i] = type == graph_type::undirected  ? random_value : -random_value;
        if (b == limit){
            ++beginning;
            a = beginning;
            b = a + 1;
        }
        else {
            ++b;
        }
    }
    return matrix;
}

int** Generate_graph::densify_incidence_matrix(int vertices, int** mst, int edges, graph_type type) {
    // int edges = (vertices * (vertices - 1) / 2);
    // edges *= density/(float)100;
    int** matrix = new int*[vertices];
    // for (int i = 0; i < vertices; ++i)
    //     matrix[i] = new int[edges];
    for (int i = 0; i < vertices; ++i) {
        matrix[i] = new int[edges];
        for (int j = 0; j < edges; ++j) {
            if (j < vertices - 1) {
                matrix[i][j] = mst[i][j];
            }
            else {
                matrix[i][j] = 0;
            }
        }
    }
    // return matrix;

    srand(time(NULL));
    // int edge_counter = vertices - 1;
    int v1, v2, w;
    for (int i = vertices - 1; i < edges; ++i) {
        // do {
            v1 = rand() % vertices;
            do
                v2 = rand() % vertices;
            while (v1 == v2);
        // }
        // while (is_cycle(matrix, vertices, edges, v1, v2));
        w = (rand() % (INT_MAX - 1) + 1); // losowanie wagi
        if (type == Generate_graph::graph_type::undirected){
            matrix[v1][i] = w;
            matrix[v2][i] = w;
        }
        else if (type == Generate_graph::graph_type::directed) {
            w = rand() % 2 ? w : -w; // losowanie kierunku
            matrix[v1][i] = w;
            matrix[v2][i] = -w;

        }
        // ++edge_counter;
    }

    return matrix;
}

bool Generate_graph::is_cycle(int** graph, int vertices, int edges, int v1, int v2) {
    for (int i = 0; i < edges; ++i) {
        if (graph[v1][i] != 0 && graph[v2][i] != 0)
            return true;
    }
    return false;
}

int** Generate_graph::create_graph_incidence_matrix(int vertices, int edges, graph_type type){
    int** graph = Generate_graph::complete_incidence_matrix(vertices, type);
    int edges_full = vertices * (vertices - 1) / 2;
    MST mst;
    int** mstm = mst.Prim_Matrix(graph, edges_full, vertices, type, MST::print::no);
    int** matrix = Generate_graph::densify_incidence_matrix(vertices, mstm, edges, type);

    for (int i = 0; i < vertices; i++) {
        delete [] graph[i];
        delete [] mstm[i];
    }
    delete [] graph;
    delete [] mstm;

    return matrix;
}

// Graph_list** Generate_graph::create_graph_adjacentcy_list(int vertices, int** matrix, graph_type type){
    // Graph_list** graph = Ge
// }
