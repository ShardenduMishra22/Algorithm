#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void Merge(vector<int>& arr, int l, int r, int mid) {
        int n1 = mid - l + 1;
        int n2 = r - mid;

        vector<int> L(n1), R(n2);
        for (int i = 0; i < n1; i++) {
            L[i] = arr[l + i];
        }
        for (int i = 0; i < n2; i++) {
            R[i] = arr[mid + 1 + i];
        }

        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k++] = L[i++]; 
            } else {
                arr[k++] = R[j++];
            }
        }

        while (i < n1) {
            arr[k++] = L[i++]; 
        }
        while (j < n2) {
            arr[k++] = R[j++]; 
        }
    }

    void MergeSort(vector<int>& arr, int l, int r) {
        if (l >= r) {
            return;
        }
        int mid = l + (r - l) / 2;
        MergeSort(arr, l, mid);
        MergeSort(arr, mid + 1, r);
        Merge(arr, l, r, mid);
    }

    vector<int> sortArray(vector<int>& arr) {
        if (arr.size() <= 1) return arr;
        MergeSort(arr, 0, arr.size() - 1);
        return arr;
    }
};
