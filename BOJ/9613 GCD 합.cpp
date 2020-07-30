//
//  9613 GCD 합.cpp
//  codingtest
//
//  Created by 이재용 on 2020/07/31.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int GCD(int a, int b) {
    if (a % b == 0) return b;
    return GCD(b, a%b);
}
int main(void) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int m;
        int arr[102];
        cin >> m;
        for (int j = 0; j < m; j++) {
            cin >> arr[j];
        }
        long long sum = 0;
        for (int j = 0; j < m - 1; j++) {
            for (int k = j+1; k < m; k++) {
                int a = arr[j] > arr[k] ? arr[j]: arr[k];
                int b = arr[j] < arr[k] ? arr[j]: arr[k];
                sum += GCD(a, b);
            }
        }
        cout << sum << "\n";
    }
    return 0;
}

