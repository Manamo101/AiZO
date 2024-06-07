#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>
#include <deque>
#include "Timer.h"
// #include "Timer.cpp"
#include "ShortPath.h"

using namespace std;

struct Dijkstra{
    int v = -1;
    int d = INT_MAX;
    int p = NULL;
};

bool compare_vector2(Dijkstra* a, Dijkstra* b){
    return (*a).d > (*b).d;
}

class Compare2 {
    public:
        bool operator() (Dijkstra a, Dijkstra b){
            return a.d > b.d;
        }
};

void ShortPah::Dijkstra_Matrix(int ** graph, int edges, int vertices, int start) {
    /*
    priority_queue<Dijkstra, vector<Dijkstra>, Compare> queue;
    priority_queue<Dijkstra, vector<Dijkstra>, Compare> tmp;
    priority_queue<Dijkstra, vector<Dijkstra>, Compare> tmp2;

    // priority_queue<int, vector<int>, greater<int>> queue;
    // priority_queue<int, vector<int>, greater<int>> tmp;

    // int ** mst = new int*[vertices];
    // for (int i = 0; i < vertices; ++i){
    //     mst[i] = new int[vertices];
    //     for (int j = 0; j < vertices - 1; ++j){
    //         mst[i][j] = 0;
    //     }
    // }

    int* key = new int[vertices];
    int* p = new int[vertices];

    Timer timer;
    for (int i = 0; i < vertices; ++i) {
        Dijkstra dijkstra;
        dijkstra.key = INT_MAX;
        dijkstra.v = i;
        key[i] = INT_MAX;
        p[i] = NULL;
        if (i == 0) {
            key[i] = 0;
            dijkstra.key = 0;
        }
        queue.push(dijkstra);
    }
    
    bool contains;
    while (!queue.empty()) {
        Dijkstra vertex = queue.top();
        queue.pop();
        int u = vertex.v;

        for (int e = 0; e < edges; ++e) {
            if (graph[u][e] > 0) {
                for (int v = 0; v < vertices; ++v) {
                    if (graph[v][e] && v != u) {

                        contains = false;
                        tmp = queue;
                        while (!tmp.empty()) {
                        if (tmp.top().v == v && tmp.top().key == key[v]){
                            // if (tmp.top().v == v){
                                contains = true;
                                break;
                            }
                            tmp.pop();
                        }

                        if (contains && graph[v][e] < key[v]) {
                            priority_queue<Dijkstra, vector<Dijkstra>, Compare> tmp2;
                            while (!(queue.top().v == v && queue.top().key == key[v])) {
                                tmp2.push(queue.top());
                                queue.pop();
                            }
                            key[v] = graph[v][e];
                            p[v] = u;
                            Dijkstra dijkstra = queue.top();
                            queue.pop();
                            dijkstra.key = graph[v][e];
                            queue.push(prim);
                            while (!tmp2.empty()) {
                                queue.push(tmp2.top());
                                tmp2.pop();
                            }
                        }
                    }
                }
            }
        }
    }
    float time = timer.stop();

    cout << "time Dijkstra's mst alg = " << time << endl;
    // int edge = 0;
    // for (int i = 1; i < vertices; ++i){
    //     if (type == Generate_graph::graph_type::directed) {
    //         mst[i][edge] = key[i] > 0 ? -key[i] : key[i];
    //         mst[p[i]][edge] = key[i] > 0 ? key[i] : -key[i];
    //     }
    //     else if (type == Generate_graph::graph_type::undirected) {
    //         mst[i][edge] = key[i];
    //         mst[p[i]][edge] = key[i];
    //     }
    //     ++edge;
    */


    if (start >= vertices){
        cout << "nieprawidlowa liczba!" << endl;
        return;
    }


    Timer timer;

    vector<Dijkstra*> queue;
    Dijkstra* dijkstras = new Dijkstra[vertices];

    for (int i = 0; i < vertices; ++i) {
        dijkstras[i].v = i;
        if (i == start)
            dijkstras[i].d = 0;
        queue.push_back(&dijkstras[i]);
    }

    while (!queue.empty()) {
    sort(queue.begin(), queue.end(), compare_vector2);
        Dijkstra* vertex = queue.back();
        queue.pop_back();
        int u = (*vertex).v;

        for (int e = 0; e < edges; ++e) {   
            if (graph[u][e] > 0) {
                for (int v = 0; v < vertices; ++v) {
                    if (graph[v][e] && v != u) {
                        if (graph[u][e] + dijkstras[u].d < dijkstras[v].d) {
                            dijkstras[v].d = graph[u][e] + dijkstras[u].d;
                            dijkstras[v].p = u;
                        }
                    }
                }
            }
        }
    }

    float time = timer.stop();

    cout << "Dijkstra matrix time = " << time << "ms" << endl;
    // cout << "from 0 to whatever you want\n";
    // for (int i = 0; i < vertices; ++i){
    //     cout << "to " << i << " from " << dijkstras[i].p << " length " << dijkstras[i].d << endl;
    // }

    delete [] dijkstras;
    queue.clear();
    delete &queue;
}

void ShortPah::Dijkstra_List(Graph_list ** graph, int edges, int vertices, int start) {
        if (start >= vertices){
        cout << "nieprawidlowa liczba!" << endl;
        return;
    }


    Timer timer;

    vector<Dijkstra*> queue;
    Dijkstra* dijkstras = new Dijkstra[vertices];

    for (int i = 0; i < vertices; ++i) {
        dijkstras[i].v = i;
        if (i == start)
            dijkstras[i].d = 0;
        queue.push_back(&dijkstras[i]);
    }

    while (!queue.empty()) {
        sort(queue.begin(), queue.end(), compare_vector2);
        Dijkstra* vertex = queue.back();
        queue.pop_back();
        int u = (*vertex).v;

        Graph_list *l = graph[u];
        while(l) {
            int v = l->v;
            int w = l->w;
            if (w > 0 && w + dijkstras[u].d < dijkstras[v].d) {
                dijkstras[v].d = w + dijkstras[u].d;
                dijkstras[v].p = u;
            }
            l = l->next;
        }
    }

    float time = timer.stop();

    cout << "Dijkstra list time = " << time << "ms" << endl;
    // cout << "from 0 to whatever you want\n";
    // for (int i = 0; i < vertices; ++i){
    //     cout << "to " << i << " from " << dijkstras[i].p << " length " << dijkstras[i].d << endl;
    // }

    delete [] dijkstras;
    queue.clear();
    delete &queue;
}