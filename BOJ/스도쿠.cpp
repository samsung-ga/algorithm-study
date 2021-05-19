#include <iostream>

using namespace std;

int sudoku[9][9];
int check = 0;
int row[9][10];
int col[9][10];
int square[9][10];
int n;

void printSudoku() {
    cout << "sudoku " << n+1 << "\n";
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << sudoku[i][j] << " ";
        }
        cout << "\n";
    }
}

void dfs(int n) {
    if (n==81) {
        if (!check) {
            printSudoku();
            check = 1;
        }
        return;
    }
    int a = n / 9;
    int b = n % 9;
    int square_num = a/3*3 + b/3;
    if (sudoku[a][b] == 0) {
        for (int i = 1; i <= 9; i++) {
            if (!row[a][i] && !col[b][i] && !square[square_num][i]) {
                row[a][i] = 1;
                col[b][i] = 1;
                square[square_num][i] = 1;
                sudoku[a][b] = i;
                dfs(n+1);
                row[a][i] = 0;
                col[b][i] = 0;
                square[square_num][i] = 0;
                sudoku[a][b] = 0;
            }
        }
    } else {
        dfs(n+1);
    }
    
}

int main(void) {
    cin >> n;
    while(n--) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cin >> sudoku[i][j];
                if (sudoku[i][j] != 0) {
                    row[i][sudoku[i][j]] = 1;
                    col[j][sudoku[i][j]] = 1;
                    int square_num = i/3*3+j/3;
                    square[square_num][sudoku[i][j]] = 1;
                }
            }
        }
        dfs(0);
    }
    
    return 0;
}

