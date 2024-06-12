#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <iostream>

using namespace std;

class FIleManger {
    public:
        enum type {
            directed,
            undirected
        };
        static int** get_graph(string filename, type type);
        static int get_vertices(string filename);
        static int get_edges(string filename);
};

#endif