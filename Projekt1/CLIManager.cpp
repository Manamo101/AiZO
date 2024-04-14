#include <iostream>
#include <fstream>
#include <conio.h>
#include "CLIManager.h"

using namespace std;

string CLIManager::getType(){
    string type;
    while(true){
        cout << "podaj rodzaj danych (int, float): ";  
        cin >> type;
        if (type == "float")
            return type;
        else if(type == "int")
            return type;
        else
            cout << "niepoprawny zapis!" << endl;
    }
}

string CLIManager::getFilename() {
    string filename;
    while (true) {
        ifstream file;
        cout<< "podaj nazwe pliku: ";
        cin >> filename;
        file.open(filename);
        if (file.good()){
            return filename;
        }
        else
            cout << "Plik nie istnieje!" << endl;
        
    }
}

int CLIManager::getRangeRandom() {
    while(true) {
        int range;
        cout << "podaj maksymalny zakres losowanych liczb: ";
        cin >> range;
        if ( 0 < range && range <= INT32_MAX)
            return range;
        cout << "niewlasciwy zakres!" << endl;
    }
}

 char CLIManager::getTableType() {
    char sign;
    while (true) {
        cout << "Podaj rodzaj tablicy (r - losowa / f - wczytana z pliku): ";
        cin >> sign;
        if (sign == 'r' || sign == 'f')
            return sign;
        cout << "niewlasciwy wybor!" << endl;
    }
 }

int CLIManager::getNumberOfElements(){
    int n;
    while (true) {
        cout << "podaj liczbe elementow: ";
        cin >> n;
        if (0 < n)
            return n;
        cout << "niewlasciwa liczba";
    }
}

char CLIManager::getShellsortVersion(){
    char sign;
    while (true) {
        cout << "Podaj wersje (s - Shella / k - Knutha): ";
        cin >> sign;
        if (sign == 's' || sign == 'k')
            return sign;
        cout << "niewlasciwy wybor!" << endl;
    }
}


char CLIManager::getQuicksortPivot(){
    char sign;
    while (true) {
        cout << "Wybierz pivot (l - lewy / m - srodkowy / p - prawy / r - losowy): ";
        cin >> sign;
        if (sign == 'l' || sign == 'm' || sign == 'p' || sign == 'r')
            return sign;
        cout << "niewlasciwy wybor!" << endl;
    }
}
void CLIManager::printTable(float arr[], int n){
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void CLIManager::printTable(int arr[], int n){
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void CLIManager::printMenu() {
    cout << "\n1. Wyswietl tablice\n";
    cout << "2. Wylosuj zawartosc losowej tablicy\n";
    cout << "3. Uzyj Insertionsort\n";
    cout << "4. Uzyj Heapsort\n";
    cout << "5. Uzyj Shellsort\n";
    cout << "6. Uzyj Quicksort\n";
    cout << "Aby wyjsc wcisnij klawisz ESC\n\n";
}

void CLIManager::wyjdz() {
    cout << "wcisnij klawisz Enter, aby kontynowac\n";
    int enter = 13;
    while (getch() != enter); 
}