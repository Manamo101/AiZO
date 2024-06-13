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
    // int vertices = 400;
    // int density = 99;
    // int edges_full = vertices * (vertices - 1) / 2;
    // int edges_density = edges_full * density/(float)100;
    // Generate_graph::graph_type type = Generate_graph::graph_type::directed;
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
        // Printer::print_matrix_graph(file_graph, v_file, e_file);
    // }

    // int ** matrix = Generate_graph::create_graph_incidence_matrix(vertices, edges_density, type);
    // int ** matrix = Generate_graph::complete_incidence_matrix(vertices, type);
    // Graph_list **list = Generate_graph::parse_to_adjacency_list(vertices, edges_density, matrix, type);
    // cout << "juz" << endl;
    // Printer::print_matrix_graph(matrix, vertices, edges_density);
    // Printer::print_list_graph(list, vertices);

    // MST mst;
    // int** mstm = mst.Prim_Matrix(matrix, edges_density, vertices, type, MST::yes);
    // Printer::print_matrix_graph(mstm, vertices, vertices - 1);
    // Graph_list** mstl = mst.Prim_List(list, edges_full, vertices, MST::yes);
    // Printer::print_list_graph(mstl, vertices);
    
    // ShortPath sp;
    // sp.Dijkstra_Matrix(matrix, edges_density, vertices, 1, 3);
    // sp.Dijkstra_List(list, e_file, v_file, 1, 4);
    // sp.BF_Matrix(matrix, edges_density, vertices, 0, vertices - 1);
    // sp.BF_List(list, edges_density, vertices, 0, vertices - 1);

    // // usuwanie
    // for(int i = 0; i < vertices; ++i) {
    //     Graph_list *p = list[i];
    //     while(p) {
    //         Graph_list *r = p;
    //         p = p->next;
    //         delete r;
    //     }
    // }
    // delete [] list;

    char tryb;
    char key;
    string filename = "graf_nieskierowany.txt";
    int e_file, v_file;
    int density, v;
    int** file_graph;
    int ** matrix;
    int edges_density;
    int edges_full;
    Graph_list **list;
    Graph_list **file_list;

    cout << "Podaj rodzaj algorytmu ktory chcesz zmierzyc (m - minimalne drzewo rozpinajace, s - najkrotsza droga): ";
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

            switch (key)
            {
            case '1':
                cout << "podaj nazwe pliku: ";
                cin >> filename;
                e_file = FIleManger::get_edges(filename);
                if (e_file == NULL)
                    break;
                v_file = FIleManger::get_vertices(filename);
                matrix = FIleManger::get_graph(filename, FIleManger::undirected);
                list = Generate_graph::parse_to_adjacency_list(v_file, e_file, matrix, type);
                cout << "\nWczytano graf. Wciscij jakikolwiek przycisk\n";
                while (!getch());
                break;
            case '2':
                cout << "podaj liczbe wierzcholkow: ";
                cin >> v;
                cout << "podaj gestosc krawedzi w %: ";
                cin >> density;
                edges_full = v * (v - 1) / 2;
                edges_density = edges_full * density/(float)100;
                matrix = Generate_graph::create_graph_incidence_matrix(v, edges_density, type);
                list = Generate_graph::parse_to_adjacency_list(v_file, e_file, matrix, type);
                cout << "\nUtworzono graf. Wciscij jakikolwiek przycisk\n";
                while (!getch());
                break;
            case '3':
                Printer::print_matrix_graph(matrix, v, edges_density);
                Printer::print_list_graph(list, v);
                cout << "\nWciscij jakikolwiek przycisk\n";
                while (!getch());
                break;
            default:
                break;
            }
        }
        while (key != '5');
    }




    // for (int i = 0; i < vertices; ++i){
    //     delete [] matrix[i];
    // }
    // delete [] matrix;
    return 0;
}

void print_menu_mst() {
    cout << "\n1. wczytaj dane z pliku\n";
    cout << "2. wygeneruj graf losowo\n";
    cout << "3. wyswietl graf\n";
    cout << "4. Algorytm Prima";
    cout << "5. wyjdz";
    cout << "podaj odpowiednia liczbe: ";
}