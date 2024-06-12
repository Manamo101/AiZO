#include "FileManger.h"
#include <iostream>
#include <fstream>

using namespace std;

int** FIleManger::get_graph(string filename, type type) {
    ifstream file(filename);
    if (!file.good()) {
        cout << "niepoprawna nazwa!" << endl;
        return NULL;
    }
    int v, e;
    int ** graph;
    // graph = new int*[5];
        // for (int i = 0; i < 5; ++i)
            // graph[i] = new int[7]{0};
    bool first = true;
    for (int num = 0; !file.eof(); ++num) {
        if (first) {
        file >> e;
        file >> v;
        graph = new int*[v];
        for (int i = 0; i < v; ++i)
            graph[i] = new int[e]{0};
        first = false;
        }
        int a, b, w;
        file >> a;
        file >> b;
        file >> w;
        graph[a][num] = w;
        graph[b][num] = type == FIleManger::undirected ? w : -w;
    }
    file.close();
    return graph;
}

int FIleManger::get_vertices(string filename) {
    ifstream file(filename);
    if (!file.good()) {
        cout << "niepoprawna nazwa!" << endl;
        return NULL;
    }
    int v;
    file >> v; 
    file >> v; 
    file.close();
    return v;
}
int FIleManger::get_edges(string filename) {
    ifstream file(filename);
    if (!file.good()) {
        cout << "niepoprawna nazwa!" << endl;
        return NULL;
    }
    int e;
    file >> e; 
    file.close();
    return e;
}