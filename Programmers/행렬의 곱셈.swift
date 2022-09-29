//
//  행렬의 곱셈.swift
//  Coding_Test_Swift
//
//  Created by Woody on 2022/09/23.
//

import Foundation

func solution(_ arr1:[[Int]], _ arr2:[[Int]]) -> [[Int]] {

    let a = arr1.count
    let b = arr1[0].count
    let c = arr2.count
    var answer: [[Int]] = []
    for i in 0..<a {
        var ans: [Int] = []
        for j in 0..<b {
            var temp: Int = 0
            for z in 0..<c {
                temp += arr1[i][z] * arr2[z][j]
            }
            ans.append(temp)
        }
        answer.append(ans)
    }

    return answer
}

print(solution([[1, 4], [3, 2], [4, 1]], [[3, 3], [3, 3]]))
print(solution([[2, 3, 2], [4, 2, 4], [3, 1, 4]], [[5, 4, 3], [2, 4, 1], [3, 1, 1]]))
//a11 * b11 + a12 * b
