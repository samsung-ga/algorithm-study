#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int row[16];
int n;
int result;

bool promising(int i) {
    int k = 1;
    bool decision = true;
    while(k < i && decision) {
        if (row[k] == row[i] || abs(row[k] - row[i]) == i-k) {
            decision = false;
        }
        k++;
    }
    return decision;
}
void queens(int i) {
    if (promising(i)) {
        if (i == n) {
            result++;
        } else {
            for (int j = 1; j <= n; j++) {
                row[i+1] = j;
                queens(i+1);
            }
        }
    }
}

int main() {
    cin >> n;
    queens(0);
    cout << result;
    return 0;
}
