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
        static Graph_list** complete_adjacency_list(int vertices, int **matrix, graph_type type);

};
#endif