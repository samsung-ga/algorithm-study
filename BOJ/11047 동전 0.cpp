//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//int n, k;
//vector<int> coins;
//int main(void) {
//    cin >> n >> k;
//    
//    for (int i = 0; i < n; i++) {
//        int temp;
//        cin >> temp;
//        coins.push_back(temp);
//    }
//
//    int profit = 0;
//    int coin_sum = 0;
//    for (int i = n-1; i > -1; i--) {
//        if (coins[i] < k) {
//            while (coins[i]+profit <= k) {
//                profit += coins[i];
//                coin_sum++;
//            }
//        }
//        if (profit == k) {
//            break;
//        }
//    }
//    
//    cout << coin_sum;
//    
//    return 0;
//}
