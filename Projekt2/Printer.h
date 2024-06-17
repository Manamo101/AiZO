#ifndef PRINTER_H
#define PRINTER_H

#include "graph_list.h"

// wizulane przedstawienie postaci grafu
class Printer{
    public:
        //  wypisuje graf w postaci macierzy 
        static void print_matrix_graph(int ** matrix, int vertices, int edges);
        // wypisuje graf w postaci listy
        static void print_list_graph(Graph_list** list, int vertices);
};

#endif