#ifndef QUICKSORT_H 
#define QUICKSORT_H 

// klasa posiadająca funkcje zawierające algorytmy sortowania szybkiego
// paramentry: typ danych, miejsce pivota (domyślnie integer oraz lewy)
template <typename T = int, int pivotIndex = -1>
class QuickSort{
	public:
		// stałe będące parametrami informującymi o pozyji pivota
		static const int LEFT_INDEX = -1;
		static const int RIGHT_INDEX = 1;
		static const int RANDOM_INDEX = 2;
		static const int MIDDLE_INDEX = 0;

		// sortowanie szybkie rosnąco
        // argumenty: tablica do posortowania, indeks początkowy, indeks końcowy
		static void quickSort(T arr[], int start, int end);
		// sortowanie szybkie malejąco
        // argumenty: tablica do posortowania, indeks początkowy, indeks końcowy
		static void quickSortDesc(T arr[], int start, int end);
	private:
		// funkcja odpowiedzialna za poprawne ułożenie danych wg wskazań algorytmu
        // argumenty: tablica do posortowania, indeks początkowy, indeks końcowy
		// zwarca: wartość indeksu służący do podzielania tablicy
		static int partition(T arr[], int start, int end);
		static int partitionDesc(T arr[], int start, int end);
		
		// funkcja zwracająca indeks pivota wg zadanego parametru
        // argumenty: tablica do posortowania, indeks początkowy, indeks końcowy
		// zwraca: indeks pivota
		static int getPivot(T arr[],int start, int end);
};
#endif  