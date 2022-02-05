#include<bits/stdc++.h>

using namespace std;

void merge(vector<int> &arr, int beg, int mid, int end){
    int m = mid-beg+1, n = end-mid;
    vector<int> left, right;
    for(int i = 0;i < m;i++)
        left.push_back(arr[beg+i]);
    for(int i = 0;i < n;i++)
        right.push_back(arr[mid+1+i]);
    int i = 0, j = 0, k = beg;
    while(i < m && j < n){
        if(left[i] < right[j]){
            arr[k] = left[i];
            i++;
            k++;
        }
        else{
            arr[k] = right[j];
            j++;
            k++;
        }
    }
    while(i < m){
        arr[k] = left[i];
        i++;
        k++;
    }
    while(j < n){
        arr[k] = right[j];
        j++;
        k++;
    }
}
void mergesort(vector<int> &arr, int beg, int end){
    if(end > beg){
        int mid = (beg+end)/2;
        mergesort(arr, beg, mid);
        mergesort(arr, mid+1, end);
        merge(arr, beg, mid, end);
    }
}

int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    mergesort(arr, 0, arr.size()-1);
    for(auto i : arr)
        cout << i << " ";
    return 0;
}