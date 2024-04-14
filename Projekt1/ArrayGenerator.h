#ifndef ARRAY_GENERATOR_H
#define ARRAY_GENERATOR_H


// klasa odpowiedzalna za działania związane z przetwarzaniem tablic
// parametr: typ danych (domyślnie int)
template <typename T = int>
class ArrayGenerator{
    public:
        // generuje tablicę wypełnioną losowymi wartościami
        // argumenty: długość tablicy, limit górny wartości
        // zwraca: tablica z losowymi wartościami w podanym przedziale
        T* randomArray(int n, int max);

        // generuje tablice wypełnioną w częsci posortowaną (licząc od początku), a w części losową (nie mniejszą od pierwszej części)
        // argumenty: długość tablicy, procent posortowania wartości w zakresie od 0% do 100%
        // zwraca: tablicę
        T* partlySortedRandomArray(int n, int precentage);

        // generuje tablicę posortowaną malejąco
        // argumenty: długość tablicy
        // zwraca: posortowana malejąco tablica
        T* sortedArrayDesc(int n);

        // tworzy twardą kopię tablicy
        // argumenty: tablica do skopiowania, długość tablicy
        // zwraca: kopia tablicy
        T* hardCopy(T arr[], int n);

        // sprawdza czy czy elementy tablicy ułożone są rosnąco
        // argumenty: tablica do skopiowania, długość tablicy
        // zwraca: prawda, gdy posortowane; fałsz, gdy nieposortowane
        bool isSorted(T arr[], int n);
    private:
        // generuje tablicę wypełnioną losowymi wartościami nie mniejszymy od wartości indeksu podanego w argumentcie
        // argumenty: tablica do zapełnienia, długość tablicy, indeks od którego zacząć losować wartości
        // zwraca: tablica
        T* randomArray(T arr[], int n, int min);
};

#endif