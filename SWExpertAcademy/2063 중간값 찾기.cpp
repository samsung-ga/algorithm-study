//
//  2063 중간값 찾기.cpp
//  swexpert
//
//  Created by 이재용 on 2020/07/26.
//  Copyright © 2020 jaeyong Lee. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    
    int nums[200];
    
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    sort(nums, nums + n);
    
    cout << nums[n/2] << "\n";
    
    return 0;
}
