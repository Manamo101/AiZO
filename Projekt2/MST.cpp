#include "MST.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits.h>
#include "Timer.h"
#include "Timer.cpp"

using namespace std;

struct Prim{
    int v = -1;
    int key = INT_MAX;
    bool used = false;
};


bool compare_vector(Prim* a, Prim* b){
            return (*a).key > (*b).key;
        }

int** MST::Prim_Matrix(int ** graph, int edges, int vertices, Generate_graph::graph_type type, print prt){
    int ** mst = new int*[vertices];
    for (int i = 0; i < vertices; ++i){
        mst[i] = new int[vertices];
        for (int j = 0; j < vertices - 1; ++j){
            mst[i][j] = 0;
        }
    }

    Timer timer;

    vector<Prim*> queue;
    int* key = new int[vertices];
    int* p = new int[vertices];
    Prim* prims = new Prim[vertices];
    for (int i = 0; i < vertices; ++i) {
        prims[i].v = i;
        key[i] = INT_MAX;
        p[i] = NULL;
        if (i == 0) {
            key[i] = 0;
            prims[i].key = 0;
        }
        queue.push_back(&prims[i]);
    }
    
    while (!queue.empty()) {
        std::sort(queue.begin(), queue.end(), compare_vector);
        Prim *vertex = queue.back();
        queue.pop_back();
        (*vertex).used = true;
        int u = (*vertex).v;

        for (int e = 0; e < edges; ++e) {
            if (graph[u][e] > 0 && type == Generate_graph::graph_type::undirected) {
                for (int v = 0; v < vertices; ++v) {
                    if (graph[v][e] && v != u) {
                        if (prims[v].used == false && graph[v][e] < key[v]) {
                            prims[v].key = graph[v][e];
                            key[v] = graph[v][e];
                            p[v] = u;
                        }
                    }
                }
            }
            else if (graph[u][e] != 0 && type == Generate_graph::graph_type::directed) {
                for (int v = 0; v < vertices; ++v) {
                    if (graph[v][e] && v != u) {
                        if (prims[v].used == false && graph[v][e] < key[v]) {
                            prims[v].key = graph[v][e];
                            key[v] = graph[v][e];
                            p[v] = u;
                        }
                    }
                }
            }
        }
    }
    float time = timer.stop();
    if (prt == MST::print::yes)
        std::cout << "mst Prim matrix time = " << time << "ms" << endl;

    int edge = 0;
    int total = 0;
    for (int i = 1; i < vertices; ++i){
        if (type == Generate_graph::graph_type::directed) {
            mst[i][edge] = key[i];
            mst[p[i]][edge] = -key[i];
        }
        else if (type == Generate_graph::graph_type::undirected) {
            total += key[i];
            mst[i][edge] = key[i];
            mst[p[i]][edge] = key[i];
        }
        ++edge;
    }
    if (type == Generate_graph::graph_type::undirected && prt == MST::print::yes)
        std::cout << "total = " << total << endl;

    delete [] prims;
    delete [] key;
    delete [] p;

    queue.clear();
    // delete &queue;

    return mst;
}

Graph_list** MST::Prim_List(Graph_list** graph, int edges, int vertices, print prt){
    Timer timer;

    vector<Prim*> queue;
    int* key = new int[vertices];
    int* p = new int[vertices];
    Prim* prims = new Prim[vertices];


    for (int i = 0; i < vertices; ++i) {
        prims[i].v = i;
        key[i] = INT_MAX;
        p[i] = NULL;
        // może losowanie?
        if (i == 0) {
            key[i] = 0;
            prims[i].key = 0;
        }
        queue.push_back(&prims[i]);
    }
    
    while (!queue.empty()) {
        std::sort(queue.begin(), queue.end(), compare_vector);
        Prim *vertex = queue.back();
        queue.pop_back();
        (*vertex).used = true;
        int u = (*vertex).v;

        Graph_list *l = graph[u];
        while (l) {
            int v = l->v;
            int w = l->w;
            if (prims[v].used == false && w < key[v]) {
                key[v] = w;
                prims[v].key = w;
                p[v] = u;
            }
            l = l->next;
        }
    }

    float time = timer.stop();

    Graph_list **mst = new Graph_list* [vertices];
    for (int i = 0; i < vertices; ++i)
        mst[i] = NULL;

    int total = 0;
    for (int i = 1; i < vertices; ++i){
        Graph_list *l = new Graph_list();
        l->w = key[i];
        l->v = p[i];
        l->next = mst[i];
        mst[i] = l;    

        l = new Graph_list();
        l->w = key[i];
        l->v = i;
        l->next = mst[p[i]];
        mst[p[i]] = l;

        total += key[i];
    }
    if (prt == MST::print::yes){
        std::cout << "mst Prim list time = " << time << "ms" << endl;
        std::cout << "total = " << total << endl;
    }

    delete [] prims;
    delete [] key;
    delete [] p;
    queue.clear();
    // delete &queue;

    return mst;
}