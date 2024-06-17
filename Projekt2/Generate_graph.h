#ifndef GENERATE_GRAPH_H
#define GENERATE_GRAPH_H

#include "graph_list.h"


// tworzenie grafu
class Generate_graph {
    public:
        // informacja o typie grafu
        enum graph_type {
            directed,
            undirected
        };
        
        // parsowanie grafu w postaci macierzowej do postaci listy (w celu zachowania takiej struktury grafu)
        static Graph_list** parse_to_adjacency_list(int vertices, int edges, int **matrix, graph_type type);

        // funkcje do użytku zewnętrzenego tworząca zadany graf
        static int** create_graph_incidence_matrix(int vertices, int edges, graph_type type);
        static Graph_list** create_graph_adjacentcy_list(int vertices, int** matrix, graph_type type);
    private:
        // stworzenie grafu pełnego w postaci macierzowej
        static int** complete_incidence_matrix(int vertices, graph_type type);
        
        // do MST dodaje stopniowo krawędzie aż osiągnie wymaganą gęstość
        static int** densify_incidence_matrix(int vertices, int** mst, int density, graph_type type);

        // funkcja sprawdzająca czy nie wystąpił cykl pomiędzy dwoma wierzchołami
        static bool is_cycle(int** graph, int vertices, int edges, int v1, int v2);

};
#endif