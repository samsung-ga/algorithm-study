//#include <iostream>
//#include <algorithm>
//#include <queue>
//#include <vector>
//using namespace std;
//
//int n;
//vector<int> times;
//int main(void) {
//    cin >> n;
//    for (int i = 0; i < n; i++) {
//        int temp;
//        cin >> temp;
//        times.push_back(temp);
//    }
//    
//    sort(times.begin(), times.end());
//    
//    int sum = 0;
//    for (int i = 0; i < n; i++) {
//        int temp = 0;
//        for (int j = 0; j <= i; j++) {
//            temp += times[j];
//        }
//        sum += temp;
//    }
//    
//    cout << sum;
//    
//    return 0;
//}
