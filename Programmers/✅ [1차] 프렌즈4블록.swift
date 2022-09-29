//
//  [1차] 프렌즈4블록.swift
//  Coding_Test_Swift
//
//  Created by Woody on 2022/09/23.
//

func solution(_ m:Int, _ n:Int, _ board:[String]) -> Int {
    var board = board.map { Array($0) }
    var checkedBoard: [[Bool]] = Array.init(repeating: Array.init(repeating: false, count: n), count: m)

    func checkBoard() {
        for i in 0..<m-1 {
            for j in 0..<n-1 {
                if  board[i][j] != "X" &&
                    board[i][j] == board[i+1][j] &&
                    board[i+1][j] == board[i+1][j+1] &&
                    board[i+1][j+1] == board[i][j+1] {
                    checkedBoard[i][j] = true
                    checkedBoard[i+1][j] = true
                    checkedBoard[i][j+1] = true
                    checkedBoard[i+1][j+1] = true
                }
            }
        }
    }

    var ans: Int = 0
    while true {
        checkedBoard = Array.init(repeating: Array.init(repeating: false, count: n), count: m)
        checkBoard()
        var flag: Bool = false
        for i in 0..<m {
            for j in 0..<n {
                if checkedBoard[i][j] == true {
                    ans += 1
                    board[i][j] = "X"
                    flag = true
                }
            }
        }
        if flag == false { break }

        for i in (1..<m).reversed() {
            for j in (0..<n).reversed() {
                if board[i][j] == "X" {
                    var index: Int = 1
                    while i - index >= 0 {
                        if board[i-index][j] != "X" { break }
                        index += 1
                    }
                    if i - index >= 0 {
                        board[i][j] = board[i-index][j]
                        board[i-index][j] = "X"
                    }
                }
            }
        }
    }

    return ans
}

print(solution(4, 5, ["CCBDE", "AAADE", "AAABF", "CCBBF"]))

print(solution(6, 6, ["TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ"]))
