//
//  2309 일곱 난쟁이.cpp
//  swexpert
//
//  Created by 이재용 on 2020/07/28.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
    int heights[9];
    
    for (int i = 0; i < 9; i++) {
        cin >> heights[i];
    }
    
    sort(heights, heights + 9);
    
    // 9명의 난쟁이 키 구하기 > 100
    int sum = 0;
    for (int i = 0; i < 9; i++) {
        sum += heights[i];
    }
    
    
    int a = 0;
    int b = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = i+1; j < 9; j++) {
            if (sum - heights[i] - heights[j] == 100) {
                a = i; b = j;
            }
        }
    }
    
    for (int i = 0; i < 9; i++) {
        if (a != i && b != i) {
            cout << heights[i] << "\n";
        }
    }
    
    return 0;
}
