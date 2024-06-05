#include "MST.h"
#include <iostream>
#include <vector>
#include <queue>
#include <random>
#include <ctime>
#include <limits.h>
#include <deque>
#include "Timer.h"
#include "Timer.cpp"

using namespace std;

struct Prim{
    int v = -1;
    int key = INT_MAX;
};

class Compare{
    public:
        bool operator() (Prim a, Prim b){
            return a.key > b.key;
        }
};

int** MST::Prim_Matrix(int ** graph, int edges, int vertices, Generate_graph::graph_type type){
    // priority_queue<Prim, vector<Prim>, Compare> queue;
    // priority_queue<Prim, vector<Prim>, Compare> tmp;

    // int ** mst = new int*[v];
    // for (int i = 0; i < v; ++i){
    //     mst[i] = new int[e];
    //     for (int j = 0; j < v; ++j){
    //         mst[i][j] = 0;
    //     }
    // }

    // Prim* prim = new Prim[v]; 
    // for (int i = 0; i < v; ++i){
    //     prim[i].v = i;
    // }

    // priority_queue<Prim, vector<Prim>, Compare> queue;
    // queue.push(prim[0]);

    // priority_queue<Prim, vector<Prim>, Compare> tmp;
    
    // bool contains;
    // while (!queue.empty()) {
    //     Prim vertex = queue.top();
    //     queue.pop();

    //     for (int i = 0; i < e; ++i) {
    //         if (graph[vertex.v][i] > 0) {
    //             for (int j = 0; j < v; ++j) {
    //                 if (graph[j][i]) {

    //                     contains = false;
    //                     tmp = queue;
    //                     while (!tmp.empty())
    //                     {
    //                         if (tmp.top().v == vertex.v){
    //                             contains = true;
    //                             break;
    //                         }
    //                         tmp.pop();
    //                     }

    //                     if (contains &&  graph[vertex.v][i] < )
                        
    //                 }
    //             }
    //         }
    //     }

    // }
    // return NULL;

    priority_queue<Prim, vector<Prim>, Compare> queue;
    priority_queue<Prim, vector<Prim>, Compare> tmp;
    priority_queue<Prim, vector<Prim>, Compare> tmp2;

    // priority_queue<int, vector<int>, greater<int>> queue;
    // priority_queue<int, vector<int>, greater<int>> tmp;

    int ** mst = new int*[vertices];
    for (int i = 0; i < vertices; ++i){
        mst[i] = new int[vertices];
        for (int j = 0; j < vertices - 1; ++j){
            mst[i][j] = 0;
        }
    }

    int* key = new int[vertices];
    int* p = new int[vertices];

    srand(time(NULL));

    Timer timer;
    for (int i = 0; i < vertices; ++i) {
        Prim prim;
        prim.key = INT_MAX;
        prim.v = i;
        key[i] = INT_MAX;
        p[i] = NULL;
        if (i == 0) {
            key[i] = 0;
            prim.key = 0;
        }
        queue.push(prim);
    }
    
    bool contains;
    while (!queue.empty()) {
        Prim vertex = queue.top();
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
                            priority_queue<Prim, vector<Prim>, Compare> tmp2;
                            while (!(queue.top().v == v)) {
                                tmp2.push(queue.top());
                                queue.pop();
                            }
                            key[v] = graph[v][e];
                            p[v] = u;
                            Prim prim = queue.top();
                            queue.pop();
                            prim.key = graph[v][e];
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
    cout << time << endl;
    int edge = 0;
    for (int i = 1; i < vertices; ++i){
        if (type == Generate_graph::graph_type::directed) {
            mst[i][edge] = key[i] > 0 ? -key[i] : key[i];
            mst[p[i]][edge] = key[i] > 0 ? key[i] : -key[i];
        }
        else if (type == Generate_graph::graph_type::undirected) {
            mst[i][edge] = key[i];
            mst[p[i]][edge] = key[i];
        }
        ++edge;
    }
    return mst;
}

Graph_list** MST::Prim_List(Graph_list** graph, int edges, int vertices){

    priority_queue<Prim, vector<Prim>, Compare> queue;
    priority_queue<Prim, vector<Prim>, Compare> tmp;
    priority_queue<Prim, vector<Prim>, Compare> tmp2;


    Graph_list **list = new Graph_list* [vertices];

    for (int i = 0; i < vertices; ++i)
        list[i] = NULL;

    int* key = new int[vertices];
    int* p = new int[vertices];

    srand(time(NULL));

    for (int i = 0; i < vertices; ++i) {
        Prim prim;
        prim.key = INT_MAX;
        prim.v = i;
        key[i] = INT_MAX;
        p[i] = NULL;
        if (i == 0) {
            key[i] = 0;
            prim.key = 0;
        }
        queue.push(prim);
    }
    
    bool contains;
    while (!queue.empty()) {
        Prim vertex = queue.top();
        queue.pop();
        int u = vertex.v;

        Graph_list *l = graph[u];
        while (l) {
            int v = l->v;
            int w = l->w;
            contains = false;
            tmp = queue;
            while (!tmp.empty()) {
                // bo może mieć kilka krawędzi
                // chociaż jeśli ma kilka o tej samej wadze to lipa
                if (tmp.top().v == v && tmp.top().key == key[v]){
                // if (tmp.top().v == v){
                    contains = true;
                    break;
                }
                tmp.pop();
            }
            if (contains && w < key[v]) {
                priority_queue<Prim, vector<Prim>, Compare> tmp2;
                while (!(queue.top().v == v)) {
                    tmp2.push(queue.top());
                    queue.pop();
                }
                key[v] = w;
                p[v] = u;
                Prim prim = queue.top();
                queue.pop();
                prim.key = w;
                queue.push(prim);
                while (!tmp2.empty()) {
                    queue.push(tmp2.top());
                    tmp2.pop();
                }
            }
            l = l->next;
        }
    }
    // int **mstx = new int* [vertices];
    // for (int i = 0; i < vertices; ++i){
    //     mstx[i] = new int[vertices];
    //     for (int j = 0; j < vertices - 1; ++j){
    //         mstx[i][j] = 0;
    //     }
    // }
    // int edge = 0;
    // for (int i = 1; i < vertices; ++i){
    //     mstx[i][edge] = key[i];
    //     mstx[p[i]][edge] = key[i];
    //     cout << mstx[i][edge] << "   " << mstx[p[i]][edge] << endl;
    //     ++edge;
    // }

    Graph_list **mst = new Graph_list* [vertices];
    for (int i = 0; i < vertices; ++i)
        mst[i] = NULL;

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
    }
    return mst;
}