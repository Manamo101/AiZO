#ifndef GENERATE_GRAPH_H
#define GENERATE_GRAPH_H

#include "graph_list.h"

class Generate_graph {
    public:
        enum graph_type {
            directed,
            undirected
        };

        static int** complete_incidence_matrix(int vertices, graph_type type);
        static Graph_list** parse_to_adjacency_list(int vertices, int edges, int **matrix, graph_type type);
        static int** densify_incidence_matrix(int vertices, int** mst, int density, graph_type type);
        static bool is_cycle(int** graph, int vertices, int edges, int v1, int v2);
        static int** create_graph_incidence_matrix(int vertices, int edges, graph_type type);
        static Graph_list** create_graph_adjacentcy_list(int vertices, int** matrix, graph_type type);

};
#endif