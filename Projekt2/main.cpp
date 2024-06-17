#include <iostream>
#include <iomanip>
#include <conio.h>
#include <windows.h>
#include "graph_list.h"
#include "Generate_graph.h"
#include "Generate_graph.cpp"
#include "Printer.cpp"
#include "MST.h"
#include "MST.cpp"
#include "ShortPath.h"
#include "ShortPath.cpp"
#include "FileManger.h"
#include "FileManager.cpp"

using namespace std;

int main(){

// /**
    char tryb;
    char key;
    string filename = "graf_nieskierowany.txt";
    int density= 0, vertices = 0;
    int edges = 0;
    int edges_full;
    int start, stop;
    int ** matrix = NULL;
    int ** mst_matrix = NULL;
    Graph_list **list = NULL;
    Graph_list **mst_list = NULL;

    cout << "Podaj rodzaj algorytmu ktory chcesz zmierzyc: m - minimalne drzewo rozpinajace, s - najkrotsza droga\n";
    while (true) {
        cin >> tryb;
        if (tryb == 'm' || tryb == 's')
            break;
        cout << "Podano zly znak!\n Podaj znak ponownie: ";
    }

    if (tryb == 'm') {
        Generate_graph::graph_type type = Generate_graph::graph_type::undirected;

        do {
            cout << "\n1. wczytaj dane z pliku\n";
            cout << "2. wygeneruj graf losowo\n";
            cout << "3. wyswietl graf\n";
            cout << "4. Algorytm Prima\n";
            cout << "5. wyjdz\n";
            cout << "podaj odpowiednia liczbe: ";
            cin >> key;
            cout << endl;

            switch (key)
            {
            case '1':
                cout << "podaj nazwe pliku: ";
                cin >> filename;
                edges = FIleManger::get_edges(filename);
                if (edges == NULL)
                    break;
                vertices = FIleManger::get_vertices(filename);
                matrix = FIleManger::get_graph(filename, FIleManger::undirected);
                list = Generate_graph::parse_to_adjacency_list(vertices, edges, matrix, type);
                cout << "\nWczytano graf. Wciscij jakikolwiek przycisk\n";
                while (!getch());
                break;
            case '2':
                cout << "podaj liczbe wierzcholkow: ";
                cin >> vertices;
                cout << "podaj gestosc krawedzi w %: ";
                cin >> density;
                cout << endl;
                edges_full = vertices * (vertices - 1) / 2;
                edges = edges_full * density/(float)100;
                matrix = Generate_graph::create_graph_incidence_matrix(vertices, edges, type);
                list = Generate_graph::parse_to_adjacency_list(vertices, edges, matrix, type);
                cout << "\nUtworzono graf. Wciscij jakikolwiek przycisk\n";
                while (!getch());
                break;
            case '3':
                Printer::print_matrix_graph(matrix, vertices, edges);
                Printer::print_list_graph(list, vertices);
                cout << "\nWciscij jakikolwiek przycisk\n";
                while (!getch());
                break;
            case '4':
                MST mst;
                mst_matrix = mst.Prim_Matrix(matrix, edges, vertices, Generate_graph::graph_type::undirected, MST::print::yes);
                mst_list = mst.Prim_List(list, edges, vertices, MST::print::yes);
                Printer::print_matrix_graph(mst_matrix, vertices, vertices - 1);
                Printer::print_list_graph(mst_list, vertices);
                cout << "\nWciscij jakikolwiek przycisk\n";
                while (!getch());
                break;
            default:
                break;
            }
        }
        while (key != '5');
    }
    if (tryb == 's') {
        Generate_graph::graph_type type = Generate_graph::graph_type::directed;

        do {
            cout << "\n1. wczytaj dane z pliku\n";
            cout << "2. wygeneruj graf losowo\n";
            cout << "3. wyswietl graf\n";
            cout << "4. Algorytm Dijkstry\n";
            cout << "5. Algorytm Bellmana-Forda\n";
            cout << "6. wyjdz\n";
            cout << "podaj odpowiednia liczbe: ";
            cin >> key;
            cout << endl;

            switch (key){
            case '1':
                cout << "podaj nazwe pliku: ";
                cin >> filename;
                edges = FIleManger::get_edges(filename);
                if (edges == NULL)
                    break;
                vertices = FIleManger::get_vertices(filename);
                matrix = FIleManger::get_graph(filename, FIleManger::directed);
                list = Generate_graph::parse_to_adjacency_list(vertices, edges, matrix, type);
                cout << "\nWczytano graf. Wciscij jakikolwiek przycisk\n";
                while (!getch());
                break;
            case '2':
                cout << "podaj liczbe wierzcholkow: ";
                cin >> vertices;
                cout << "podaj gestosc krawedzi w %: ";
                cin >> density;
                cout << endl;
                edges_full = vertices * (vertices - 1) / 2;
                edges = edges_full * density/(float)100;
                matrix = Generate_graph::create_graph_incidence_matrix(vertices, edges, type);
                list = Generate_graph::parse_to_adjacency_list(vertices, edges, matrix, type);
                cout << "\nUtworzono graf. Wciscij jakikolwiek przycisk\n";
                while (!getch());
                break;
            case '3':
                Printer::print_matrix_graph(matrix, vertices, edges);
                Printer::print_list_graph(list, vertices);
                cout << "\nWciscij jakikolwiek przycisk\n";
                while (!getch());
                break;
            case '4':
                cout << "podaj wierzcholek poczatkowy: ";
                cin >> start;
                cout << "podaj wierzcholek koncowy: ";
                cin >> stop;
                cout << endl;
                ShortPath sp;
                sp.Dijkstra_Matrix(matrix, edges, vertices, start, stop);
                sp.Dijkstra_List(list, edges, vertices, start, stop);
                cout << "\nWciscij jakikolwiek przycisk\n";
                while (!getch());
                break;
            case '5':
                cout << "podaj wierzcholek poczatkowy: ";
                cin >> start;
                cout << "podaj wierzcholek koncowy: ";
                cin >> stop;
                cout << endl;
                ShortPath sp2;
                sp2.BF_Matrix(matrix, edges, vertices, start, stop);
                sp2.BF_List(list, edges, vertices, start, stop);
                cout << "\nWciscij jakikolwiek przycisk\n";
                while (!getch());
                break;
            default:
                break;
            }  
        }
        while (key != '6');
    }
// */


    // usuwanie
    for(int i = 0; i < vertices; ++i) {
        Graph_list *p = list[i];
        while(p) {
            Graph_list *r = p;
            p = p->next;
            delete r;
        }
        p = mst_list[i];
        while(p) {
            Graph_list *r = p;
            p = p->next;
            delete r;
        }
    }
    delete [] list;
    delete [] mst_list;

    for (int i = 0; i < vertices; ++i){
        delete [] matrix[i];
        delete [] mst_matrix[i];
    }
    delete [] matrix;
    delete [] mst_matrix;
    return 0;
}
