#include<bits/stdc++.h>
using namespace std;

int prtn(vector<int>& arr,int& low,int& high){
    int pvt = arr[high];
    int i = low - 1;
    for(int j = low;j < high;){
        if(arr[j] < pvt){
            i += 1;
            swap(arr[i],arr[j]);
        }else{
            j += 1;
        }
    }
    swap(arr[i + 1],arr[high]);
    return i + 1;
}

void quicksort(vector<int>& arr,int low,int high){
    if(low < high){
        int pvt = prtn(arr,low,high);
        quicksort(arr,low,pvt - 1);
        quicksort(arr,pvt + 1,high);
    }
}

void Quicksort(vector<int>& arr){
    quicksort(arr,0,arr.size()-1);
}

int main() {
    vector<int> arr = {1,25001,3,37501,5,25003,7,43751,9};
    Quicksort(arr);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}