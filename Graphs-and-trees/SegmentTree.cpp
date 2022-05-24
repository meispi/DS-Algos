#include<bits/stdc++.h>

using namespace std;

int merge(int v1, int v2){
    int val;
    // val = v1 + v2; // rangeSumQuery
    val = min(v1, v2); // rangeMinQuery
    return val;
}

void constructTree(vector<int> &arr, vector<int> &segtree, int low, int high, int pos){
    if(low == high){
        segtree[pos] = arr[low];
        return;
    }
    int mid = (low+high)/2;
    constructTree(arr, segtree, low, mid, 2*pos+1);
    constructTree(arr, segtree, mid+1, high, 2*pos+2);
    segtree[pos] = merge(segtree[2*pos+1], segtree[2*pos+2]);
}

void updateSegTree(vector<int> &segtree, int ind, int del, int low, int high, int pos){
    if(ind < low || ind > high)
        return;

    if(low == high){
        segtree[pos] += del;
        return;
    }

    int mid = (low+high)/2;
    updateSegTree(segtree, ind, del, low, mid, 2*pos+1);
    updateSegTree(segtree, ind, del, mid+1, high, 2*pos+2);
    segtree[pos] = merge(segtree[2*pos+1], segtree[2*pos+2]);
}

int rangeQuery(vector<int> &segtree, int beg, int end, int low, int high, int pos){
    if(beg <= low && end >= high) // total overlap
        return segtree[pos];
    if(beg > high || end < low) // no overlap
        // return 0; // rangeSumQuery
        return INT_MAX; // rangeMinQuery
    int mid = (low+high)/2;
    return merge(rangeQuery(segtree, beg, end, low, mid, 2*pos+1), rangeQuery(segtree, beg, end, mid+1, high, 2*pos+2));
}

vector<int> createSegTree(vector<int> &arr){
    int sz = arr.size();
    int n = 2*pow(2, ceil(log2(sz)))-1;
    vector<int> segtree(n, INT_MAX);
    constructTree(arr, segtree, 0, sz-1, 0);
    return segtree;
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11, -1, 4, 8};
    int n = arr.size();
    vector<int> segtree = createSegTree(arr);
    cout << rangeQuery(segtree, 3, 6, 0, n-1, 0) << "\n";
    return 0;
}