//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
//int main(void) {
//  int test_case;
//  cin >> test_case;
//
//  while (test_case--) {
//    int n;
//    cin >> n;
//    vector<int> heights;
//    for (int i = 0; i < n; i++) {
//      int temp;
//      cin >> temp;
//      heights.push_back(temp);
//    }
//
//    sort(heights.begin(), heights.end());
//    
//    int result = 0;
//    for (int i = 0; i < n-1; i++) {
//      result = max(abs(heights[i]-heights[i+1]),result);
//    }
//    for (int i = 0; i < n-2; i++) {
//      result = max(abs(heights[i]-heights[i+2]),result);
//    }
//
//    cout << result << "\n";
//  }
//
//  return 0;
//}
