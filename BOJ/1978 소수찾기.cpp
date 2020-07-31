//
//  1978 소수찾기.cpp
//  codingtest
//
//  Created by 이재용 on 2020/07/31.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    int n;
    int arr[100];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int num = n;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            num--;
        } else {
            for (int j = 2; j < arr[i] ; j++) {
                if (arr[i] % j == 0) {
                    num--;
                    break;
                }
            }
        }
    }
    cout << num << "\n";
    return 0;
}

