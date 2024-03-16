#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <iostream>

//using namespace std;

// klasa pomocniczna do generacji tablic częściowo posortowanych
template <typename T = int>
class BubbleSort{
    public:
        int nStop = 0; // zmienna określające przedterminowe zatrzymanie sortowania skutkującym posortowaniem nStop liczb
        inline BubbleSort(T arr[], int n, int nStop){
            this->nStop = nStop;
            sort(arr, n);
        }
    private:
        inline void sort(T arr[], int n){
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