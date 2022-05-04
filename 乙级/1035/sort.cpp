//
// Created by 经纬 on 2022/5/3.
//
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void Insertion(vector<int>& v, vector<vector<int>>& matrix) {
    for (int i = 0; i < v.size(); ++i) {
        sort(v.begin(), v.begin() + i + 1);
        matrix.push_back(v);
    }
}
void Merge(vector<int>& v, int l, int m, int r) {
    vector<int> lv(v.begin() + l, v.begin() + m + 1);
    vector<int> rv(v.begin() + m + 1, v.begin() + r + 1);
    int i1 = 0, i2 = 0, i = l;
    int n1 = lv.size(), n2 = rv.size();
    while (i1 < n1 && i2 < n2) {
        if (lv[i1] <= rv[i2]) {
            v[i++] = lv[i1++];
        } else {
            v[i++] = rv[i2++];
        }
    }
    while (i1 < n1) {
        v[i++] = lv[i1++];
    }
    while (i2 < n2) {
        v[i++] = rv[i2++];
    }
}
void MergeSort(vector<int>& v, int l, int r, vector<vector<int>>& matrix) {
    if (l < r) {
        int m = l + (r - l) / 2;
        MergeSort(v, l, m, matrix);
        MergeSort(v, m + 1, r, matrix);
        Merge(v, l, m, r);
        matrix.push_back(v);
    }
}