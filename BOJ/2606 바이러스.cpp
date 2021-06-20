#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int map[101][101];
bool check[101][101];
bool node[101];
int n;
int result;

void dfs(int k) {
    for (int i = 1; i <= n; i++) {
        if (map[k][i] == 1 && node[i]) {
            node[i] = false;
            result++;
            dfs(i);
        }
    }
}

int main(void) {
    cin >> n;
    int temp;
    cin >> temp;
    for (int i = 0; i < temp; i++) {
        int a,b;
        cin >> a >> b;
        map[a][b] = 1;
        map[b][a] = 1;
    }
    
    for (int i = 0; i <= n; i++) {
        node[i] = true;
    }
    node[1] = false;
    dfs(1);
    cout << result << "\n";
    return 0;
}
