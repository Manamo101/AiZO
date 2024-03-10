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
		static const int RANDOM_INDEX = 0;
		inline QuickSort(T arr[], int start, int end){
			quickSort(arr, start, end);
		}

		inline static int partition(T arr[], int start, int end){
			T pivot;
			if (pivotIndex == LEFT_INDEX) 
				pivot = arr[start];
			else if (pivotIndex == RIGHT_INDEX) 
				pivot = arr[end-1];
			else if (pivotIndex == RANDOM_INDEX){
				srand(time(NULL));
				pivot = arr[(rand()%(end-start) + start)];
			}
			else
				pivot = arr[start];

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
		inline static void quickSort(T arr[], int start, int end) {
			if (start >= end)
				return;
		
			int p = partition(arr, start, end);
			quickSort(arr, start, p);
			quickSort(arr, p + 1, end);
		}
};
#endif  