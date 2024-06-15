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
    // przykład macierzy incydencji oraz listy sąsiedztwa z przykładu grafu na ćwiczeniach
    int **incidence_matrix = new int*[5]{
            new int[7]{1,0,0,0,0,3,0},
            new int[7]{1,6,0,0,0,0,3},
            new int[7]{0,0,0,2,4,3,3},
            new int[7]{0,6,5,0,4,0,0},
            new int[7]{0,0,5,2,0,0,0},
        };

    int **incidence_matrix2 = new int*[4]{
            new int[5]{6,3,0,0,0},
            new int[5]{6,0,1,3,0},
            new int[5]{0,3,1,0,5},
            new int[5]{0,0,0,3,5}
        };
    /*
    int vertices = 500;
    int density = 50;
    int edges_full = vertices * (vertices - 1) / 2;
    int edges_density = edges_full * density/(float)100;
    Generate_graph::graph_type type = Generate_graph::graph_type::directed;
    // int **matrix = incidence_matrix2;

    // string filename = "graf_nieskierowany.txt";
    // cout << "podaj nazwe pliku: ";
    // cin >> filename;
    // int e_file = FIleManger::get_edges(filename);
    // int v_file = FIleManger::get_vertices(filename);
    // int** file_graph = FIleManger::get_graph(filename, FIleManger::directed);
    // Graph_list **list = Generate_graph::parse_to_adjacency_list(v_file, e_file, file_graph, type);
    // if (file_graph) {
    //     int v_file = FIleManger::get_vertices(filename);
    //     int e_file = FIleManger::get_edges(filename);
    //     Printer::print_matrix_graph(file_graph, v_file, e_file);
    // }

    // int ** matrix = Generate_graph::complete_incidence_matrix(vertices, type);
    // int ** matrix = Generate_graph::create_graph_incidence_matrix(vertices, edges_density, type);
    // Graph_list **list = Generate_graph::parse_to_adjacency_list(vertices, edges_density, matrix, type);
    // cout << "juz" << endl;
    // Printer::print_matrix_graph(matrix, vertices, edges_density);
    // Printer::print_list_graph(list, vertices);

    // MST mst;
    // int** mstm = mst.Prim_Matrix(matrix, edges_density, vertices, type, MST::yes);
    // Printer::print_matrix_graph(mstm, vertices, vertices - 1);
    // Graph_list** mstl = mst.Prim_List(list, edges_density, vertices, MST::yes);
    // Printer::print_list_graph(mstl, vertices);
    
    ShortPath sp;
    // sp.Dijkstra_Matrix(matrix, edges_density, vertices, 0, vertices - 1);
    // sp.Dijkstr/a_List(list, edges_density, vertices, 0, vertices - 1);
    // sp.BF_Matrix(matrix, edges_density, vertices, 0, vertices - 1);
    // sp.BF_List(list, edges_density, vertices, 0, vertices - 1);
    */

// /**
    char tryb;
    char key;
    string filename = "graf_nieskierowany.txt";
    int density, vertices;
    int edges;
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
        // p = mst_list[i];
        // while(p) {
        //     Graph_list *r = p;
        //     p = p->next;
        //     delete r;
        // }
    }
    delete [] list;
    // delete [] mst_list;

    for (int i = 0; i < vertices; ++i){
        delete [] matrix[i];
        // delete [] mst_matrix[i];
    }
    delete [] matrix;
    // delete [] mst_matrix;
    return 0;
}
