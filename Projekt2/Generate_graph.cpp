#include <iostream>
#include <random>
#include <ctime>
#include "Generate_graph.h"

using namespace std;

Graph_list** Generate_graph::complete_adjacency_list(int vertices, int** matrix, graph_type type){
    Graph_list **list = new Graph_list* [vertices];
    int edges = vertices * (vertices - 1) / 2;

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
            random_value = rand(); //losowanie wartości
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