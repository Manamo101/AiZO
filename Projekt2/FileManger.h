#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <iostream>

using namespace std;


// pobranie informacji z pliku
class FIleManger {
    public:
        // informacja o rodzaju grafu
        enum type {
            directed,
            undirected
        };
        // pobranie inforamcji o strukturze grafu
        static int** get_graph(string filename, type type);
        // pobranie informacji o ilości wierzchołków
        static int get_vertices(string filename);
        // pobranie informacji o ilości krawędzi
        static int get_edges(string filename);
};

#endif