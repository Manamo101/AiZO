#ifndef PRINTER_H
#define PRINTER_H

#include "graph_list.h"

class Printer{
    public:
        static void print_matrix_graph(int ** matrix, int vertices);
        static void print_list_graph(Graph_list** list, int vertices);
};

#endif