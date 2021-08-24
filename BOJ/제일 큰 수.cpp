//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int n;
//vector<int> nums;
//
//bool comp(int a, int b) {
//  string aString = to_string(a);
//  string bString = to_string(b);
//  if (aString.size() == bString.size()) {
//    for (int i = 0; i < aString.size(); i++) {
//      if (aString[i] == bString[i]) {
//        continue;
//      } else {
//        return aString[i] > bString[i];
//      }
//    }
//  } else {
//    for (int i = 0; i < min(aString.size(),bString.size()); i++) {
//      if (aString[i] == bString[i]) {
//        continue;
//      } else {
//        return aString[i] > bString[i];
//      }
//    }
//    string ab = aString + bString;
//    string ba = bString + aString;
//    return ab > ba;
//  }
//  return false;
//}
//
//int main(void) {
//  cin >> n;
//  for (int i = 0;i < n; i++) {
//    int temp;
//    cin >> temp;
//    nums.push_back(temp);
//  }
//  sort(nums.begin(), nums.end(), comp);
//  
//  if (nums[0] == 0) {
//    cout << 0;
//  } else {
//    for (int i = 0; i < nums.size(); i++) {
//      cout << nums[i];
//    }
//  }
//  
//  return 0;
//}
