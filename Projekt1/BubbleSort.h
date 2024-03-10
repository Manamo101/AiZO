#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <iostream>

using namespace std;

// klasa pomocniczna do generacji tablic częściowo posortowanych
class BubbleSort{
    public:
        int nStop = 0; // zmienna określające przedterminowe zatrzymanie sortowania skutkującym posortowaniem nStop liczb
        inline BubbleSort(int arr[], int n, int nStop){
            this->nStop = nStop;
            sort(arr, n);
        }
    private:
        inline void sort(int arr[], int n){
            for (int i = 0; i < nStop; i++){
                for (int j = 0; j < n-i-1; j++){
                    if (arr[j] > arr[j+1]){
                        swap(arr[j],arr[j+1]);
                    }
                }
            }
        }
};



#endif