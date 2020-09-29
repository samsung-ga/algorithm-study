//
//  2352 반도체 설계.cpp
//  codingtest
//
//  Created by 이재용 on 2020/09/29.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int port[40001];
int lis[40001];
int main(void) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> port[i];
    }
    int lis_length = 0;
    lis[1] = port[1];
    lis_length++;
    for (int i = 2; i <= n; i++) {
        if(lis[lis_length] < port[i]) {
            lis[++lis_length] = port[i];
        } else {
            lis[lower_bound(lis+1, lis+lis_length, port[i]) - lis] = port[i];
        }
    }
    cout << lis_length++ << "\n";
}

