#include <iostream>
#include <vector>
#define INF 999999999
using namespace std;

vector<pair<int,int>> edge;
int W[5][5] = {
    {0,1,3,INF,INF},
    {1,0,3,6,INF},
    {3,3,0,4,2},
    {INF,6,4,0,5},
    {INF,INF,2,5,0}
};
int N=5;

void prim() {
    int min,vnear = 0;
    int nearest[5];
    int distance[5];
    for (int i = 1; i < 5; i++) {
        nearest[i] = 0;
        distance[i] = W[0][i];
    }
    
    while(--N) {
        min = INF;
        for (int j = 1; j < 5; j++) {
            if (distance[j] < min && distance[j] >=0) {
                min = distance[j];
                vnear=j;
            }
        }
        edge.push_back(make_pair(nearest[vnear],vnear));
        distance[vnear] = -1;
        for (int j = 0; j < 5; j++) {
            if (W[vnear][j] < distance[j]) {
                distance[j] = W[vnear][j];
                nearest[j] = vnear;
            }
        }
    }
}

int main(void) {
    
    prim();
    for (int i = 0; i < edge.size(); i++) {
        cout << "(" << edge[i].first << "," << edge[i].second << ")\n";
    }
    return 0;
}
