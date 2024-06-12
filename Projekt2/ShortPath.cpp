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

struct path{
    int v = -1;
    int d = INT_MAX;
    int p = -1;
};

bool compare_vector2(path* a, path* b){
    return (*a).d > (*b).d;
}

class Compare2 {
    public:
        bool operator() (path a, path b){
            return a.d > b.d;
        }
};

void ShortPath::Dijkstra_Matrix(int ** graph, int edges, int vertices, int start, int stop) {
    if (start >= vertices){
        cout << "nieprawidlowa liczba!" << endl;
        return;
    }

    Timer timer;

    vector<path*> queue;
    path* dijkstras = new path[vertices];

    for (int i = 0; i < vertices; ++i) {
        dijkstras[i].v = i;
        if (i == start)
            dijkstras[i].d = 0;
        queue.push_back(&dijkstras[i]);
    }

    while (!queue.empty()) {
    sort(queue.begin(), queue.end(), compare_vector2);
        path* vertex = queue.back();
        queue.pop_back();
        int u = (*vertex).v;

        for (int e = 0; e < edges; ++e) {   
            if (graph[u][e] > 0) {
                for (int v = 0; v < vertices; ++v) {
                    if (graph[v][e] && v != u) {
                        if (graph[u][e] + dijkstras[u].d < dijkstras[v].d && graph[u][e] + dijkstras[u].d >= 0) {
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
    int pre = dijkstras[stop].p;
    cout << stop;
    while (pre != -1) {
        cout << " <- " << pre;
        pre = dijkstras[pre].p;
    }
    cout << endl << "total cost = " << dijkstras[stop].d << endl;
    // cout << "from 0 to whatever you want\n";
    // for (int i = 0; i < vertices; ++i){
    //     cout << "to " << i << " from " << dijkstras[i].p << " length " << dijkstras[i].d << endl;
    // }

    delete [] dijkstras;
    queue.clear();
    // delete &queue;
}

void ShortPath::Dijkstra_List(Graph_list ** graph, int edges, int vertices, int start, int stop) {

        if (start >= vertices){
        cout << "nieprawidlowa liczba!" << endl;
        return;
    }

    Timer timer;

    vector<path*> queue;
    path* dijkstras = new path[vertices];

    for (int i = 0; i < vertices; ++i) {
        dijkstras[i].v = i;
        if (i == start)
            dijkstras[i].d = 0;
        queue.push_back(&dijkstras[i]);
    }

    while (!queue.empty()) {
        sort(queue.begin(), queue.end(), compare_vector2);
        path* vertex = queue.back();
        queue.pop_back();
        int u = (*vertex).v;

        Graph_list *l = graph[u];
        while(l) {
            int v = l->v;
            int w = l->w;
            if (w > 0 && w + dijkstras[u].d < dijkstras[v].d && w + dijkstras[u].d >= 0) {
                dijkstras[v].d = w + dijkstras[u].d;
                dijkstras[v].p = u;
            }
            l = l->next;
        }
    }

    float time = timer.stop();

    cout << "Dijkstra list time = " << time << "ms" << endl;
    int pre = dijkstras[stop].p;
    cout << stop;
    while (pre != -1) {
        cout << " <- " << pre;
        pre = dijkstras[pre].p;
    }
    cout << endl << "total cost = " << dijkstras[stop].d << endl;
    // cout << "from 0 to whatever you want\n";
    // for (int i = 0; i < vertices; ++i){
    //     cout << "to " << i << " from " << dijkstras[i].p << " length " << dijkstras[i].d << endl;
    // }

    delete [] dijkstras;
    queue.clear();
    // delete &queue;
}

void ShortPath::BF_Matrix(int ** graph, int edges, int vertices, int start, int stop) {

    Timer timer;

    path* BFs = new path[vertices];
    int * d = new int[vertices];
    int * p = new int[vertices];
    for (int i = 0; i < vertices; ++i) {
        d[i] = INT_MAX;
        p[i] = -1;
    }
    d[start] = 0;

    bool relaxation = true;
    for (int i = 0; i < vertices - 1 && relaxation; ++i) {
        relaxation = false;
    for (int u = 0; u < vertices; ++u) {
        for (int e = 0; e < edges; ++e) {
            if (graph[u][e] > 0) {
                for (int v = 0; v < vertices; ++v) {
                    if (graph[v][e] < 0 && v != u ){
                        if (d[v] > d[u] + graph[u][e] && d[u] + graph[u][e] >= 0) {
                        d[v] = d[u] + graph[u][e];
                        p[v] = u;
                        relaxation = true;
                        }
                    }
                }
            }
        }
    }
    }
    for (int u = 0; u < vertices; ++u) {
        for (int e = 0; e < edges; ++e) {
            if (graph[u][e] > 0) {
                for (int v = 0; v < vertices; ++v) {
                    if (graph[v][e] < 0 && d[v] > d[u] + graph[u][e] && d[u] + graph[u][e] >= 0) {
                        cout << "Cykl ujemny!!!\n";
                        return;
                    }
                }
            }
        }
    }
    float time = timer.stop();
    cout << "BF matrix time = " << time << " ms" << endl;

    // cout << "from 0 to whatever you want\n";
    // for (int i = 0; i < vertices; ++i){
    //     cout << "to " << i << " from " << p[i] << " length " << d[i] << endl;
    // }
    int pre = p[stop];
    cout << stop;
    while (pre != -1) {
        cout << " <- " << pre;
        pre = p[pre];
    }
    cout << endl << "total cost = " << d[stop] << endl;

    delete [] d;
    delete [] p;
    delete [] BFs;

}

void ShortPath::BF_List(Graph_list** graph, int edges, int vertices, int start, int stop) {

    Timer timer;

    path* BFs = new path[vertices];
    int * d = new int[vertices];
    int * p = new int[vertices];
    for (int i = 0; i < vertices; ++i) {
        d[i] = INT_MAX;
        p[i] = -1;
    }
    d[start] = 0;

    bool relaxation = true;
    for (int i = 0; i < vertices - 1 && relaxation; ++i) {
        relaxation = false;
    for (int u = 0; u < vertices; ++u) {
        Graph_list *l = graph[u];
        while(l) {
            int v = l->v;
            int w = l->w;
            if (w > 0 && d[v] > d[u] + w && d[u] + w >= 0) {
                d[v] = d[u] + w;
                p[v] = u;
                relaxation = true;
            }
            l = l->next;
        }
    }
    }
    for (int u = 0; u < vertices; ++u) {
        Graph_list *l = graph[u];
        while(l) {
            int v = l->v;
            int w = l->w;
            if (w > 0 && d[v] > d[u] + w && d[u] + w >= 0) {
                cout << "Cykl ujemny!!!\n";
                return;
            }
            l = l->next;
        }
    }
    float time = timer.stop();
    cout << "BF list time = " << time << " ms" << endl;

    // cout << "from 0 to whatever you want\n";
    // for (int i = 0; i < vertices; ++i){
    //     cout << "to " << i << " from " << p[i] << " length " << d[i] << endl;
    // }
    int pre = p[stop];
    cout << stop;
    while (pre != -1) {
        cout << " <- " << pre;
        pre = p[pre];
    }
    cout << endl << "total cost = " << d[stop] << endl;

    delete [] d;
    delete [] p;
    delete [] BFs;
}