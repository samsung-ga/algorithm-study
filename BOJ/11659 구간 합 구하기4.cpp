//#include <iostream>
//#include <algorithm>
//#include <queue>
//#include <vector>
//using namespace std;
//
//int n, m, sum;
//vector<int> numbers;
//
//int main(void) {
//    ios::sync_with_stdio(false);
//    cin.tie(0); cout.tie(0);
//    cin >> n >> m;
//    
//    for (int i = 0; i < n; i++) {
//        int temp;
//        cin >> temp;
//        sum += temp;
//        numbers.push_back(sum);
//    }
//    
//    for (int i = 0; i < m; i++) {
//        int a, b, result;
//        cin >> a >> b;
//        if (a == 1) {
//            result = numbers[b-1];
//        } else {
//            result = numbers[b-1] - numbers[a-2];
//        }
//        cout << result << "\n";
//    }
//    
//}
