////
////  1931 회의실 배정.cpp
////  codingtest
////
////  Created by 이재용 on 2021/01/21.
////  Copyright © 2021 jaeyong Lee. All rights reserved.
////
//
//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//int n,m,a,b;
//int main(void) {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
//    
//    cin >> n;
//    vector<pair<int, int>> v;
//    for (int i = 0; i < n; i++) {
//        cin >> a >> b;
//        v.push_back({ b,a });
//    }
//    sort(v.begin(), v.end());
//    
//    a = 0, b = 0;
//    for (int i = 0; i < v.size(); i++) {
//        if (v[i].second < a) continue;
//        a = v[i].first;
//        b++;
//    }
//    cout << b;
//
//}
