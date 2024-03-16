#ifndef QUICKSORT_H 
#define QUICKSORT_H 

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
template <typename T = int, int pivotIndex = -1>
class QuickSort{
	public:
		static const int LEFT_INDEX = -1;
		static const int RIGHT_INDEX = 1;
		static const int RANDOM_INDEX = 2;
		static const int MIDDLE_INDEX = 0;
		//Paramentr start oznacza początek rozpatywanej części tablicy, natomiast end jej koniec (włącznie)
		inline static void quickSort(T arr[], int start, int end){
			if (start >= end)
				return;
		
			int p = partition(arr, start, end);
			quickSort(arr, start, p);
			quickSort(arr, p + 1, end);
		}
	private:
		// funkcja odpowiedzialna za poprawne ułożenie danych wg wskazań algorytmu
		inline static int partition(T arr[], int start, int end){
			int index = getPivot(arr, start, end);
			T pivot = arr[index];

			int l = start, r = end;
			while (true) {
				while (arr[l] < pivot) l++;

				while (arr[r] > pivot) r--;

				if (l < r){
					swap(arr[l], arr[r]);
					l++;
					r--;
				}
				else{
					if (r == end) r++;
					return r;
				}
			}
		}
		inline static int getPivot(T arr[],int start, int end){
			// if (pivotIndex == LEFT_INDEX) 
			// 	return start;
			// else if (pivotIndex == RIGHT_INDEX) 
			// 	return end-1;
			// else if (pivotIndex == RANDOM_INDEX){
			// 	srand(time(NULL));
			// 	return rand() % (end - start) + start;
			// }
			// else if (pivotIndex == MIDDLE_INDEX){
			// 	return (end + start) / 2;
			// }
			// else
			// 	return start;

			switch (pivotIndex){
				case LEFT_INDEX:
					return start;
				case RIGHT_INDEX:
					return end-1;
				case MIDDLE_INDEX:
					return	(start + end) / 2;
				case RANDOM_INDEX:
					srand(time(NULL));
					return rand() % (end - start) + start;
				default:
					return start;
			}
		}
};
#endif  