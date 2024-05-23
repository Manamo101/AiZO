#include <iostream>
#include <random>
#include <ctime>
#include "Generate_graph.h"

Graph_list* Generate_graph::complete_adjacency_list(int vertices){
    return NULL;

}

int** Generate_graph::complete_incidence_matrix(int vertices){
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
        int random_value = rand();
        matrix[a][i] = random_value;
        matrix[b][i] = -random_value;
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