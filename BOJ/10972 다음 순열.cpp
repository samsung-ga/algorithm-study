//
//  10972 다음 순열.cpp
//  codingtest
//
//  Created by 이재용 on 2020/07/30.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
int arr[10];

// 순서 상관 없는 순열 구하기
void Permutation(vector<int>& arr, int start, int end) {
    if (start == end) {
        for (const auto it : arr) {
            cout << it << " ";
        }
        cout << "\n";
    } else {
        for (int i = start; i <= end; i++) {
            swap(arr[start], arr[i]);
            Permutation(arr, start + 1, end);
            swap(arr[start], arr[i]);
        }
    }
}

// 순서 상관 있는 순열 구하기
bool nnext_permutation(int *first, int *last) {
    if (first == last) return false; // size 0
    int *i = first;
    i++;
    if (first == last) return false; // size 1
    i = last;
    i--;

    while(true) {
        int *ii = i;
        --i;
        if (*i < *ii) {
            int *j = last;
            while (*i >= *j) { j--; }
            swap(*i, *j);
            reverse(ii, last);
            return true;
        }
        if (i == first) {
            reverse(first, last);
            return false;
        }
    }
}

int main(void) {
    
    int n;
    cin >> n;
    
    vector<int> v(n);
    
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    if (next_permutation(v.begin(), v.end())) {
        for (int i = 0; i < n; i++) {
            cout << v[i] << " ";
        }
    } else {
        cout << "-1";
    }
    
    return 0;
}

