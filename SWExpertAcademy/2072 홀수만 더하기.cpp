//
//  2072 홀수만 더하기.cpp
//  swexpert
//
//  Created by 이재용 on 2020/07/25.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
using namespace std;

int t;

int main(void) {
    cin >> t;
    for(int i = 0; i < t; i++) {
        int arr[10];
        for (int j = 0; j < 10; j++) {
            cin >> arr[j];
        }
        int sum = 0;
        for (int j = 0; j < 10; j++) {
            if (arr[j] % 2 != 0) {
                sum += arr[j];
            }
        }
        cout << sum << endl;
    }
    return 0;
}
