//
//  15658 연산자 끼워넣기(2).cpp
//  codingtest
//
//  Created by 이재용 on 2020/08/08.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int maxx = INT_MIN;
int minn = INT_MAX;

void solve(int index, int n, int sum, vector<int> v, int plus, int minus, int multi, int divide) {
    if (index == n) {
        maxx = sum > maxx ? sum : maxx;
        minn = sum < minn ? sum : minn;
        return;
    }
    if (plus) {
        solve(index+1, n, sum+v[index], v, plus-1, minus, multi, divide);
    }
    if (minus) {
        solve(index+1, n, sum-v[index], v, plus, minus-1, multi, divide);
    }
    if (multi) {
        solve(index+1, n, sum*v[index], v, plus, minus, multi-1, divide);
    }
    if (divide) {
        solve(index+1, n, sum/v[index], v, plus, minus, multi, divide-1);
    }
    
}
int main(void) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<int> oper(4);
    for (int i = 0; i < 4; i++) {
        cin >> oper[i];
    }
    
    solve(1, n, v[0], v, oper[0], oper[1], oper[2], oper[3]);
    
    cout << maxx << "\n" << minn << "\n";
    return 0;
}

