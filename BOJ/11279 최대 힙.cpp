//#include <iostream>
//#include <algorithm>
//#include <queue>
//#include <vector>
//using namespace std;
//
//struct compare {
//    bool operator() (int a, int b) {
//        return a < b;
//    }
//};
//int n;
//priority_queue<int, vector<int>, compare> numbers;
//
//int main(void) {
//    ios::sync_with_stdio(false);
//    cin.tie(0); cout.tie(0);
//    cin >> n;
//    
//    for (int i = 0 ; i < n ; i++) {
//        int temp;
//        cin >> temp;
//        if (temp == 0) {
//            if (numbers.empty()) {
//                cout << "0\n";
//            } else {
//                cout << numbers.top() << "\n";
//                numbers.pop();
//                
//            }
//        } else {
//            numbers.push(temp);
//        }
//    }
//    
//    return 0;
//}
