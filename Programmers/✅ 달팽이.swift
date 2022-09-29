//
//  달팽이.swift
//  Coding_Test_Swift
//
//  Created by Woody on 2022/09/29.
//

import Foundation

func solution(_ n:Int) -> [Int] {
    var triangle: [[Int]] = []
    for i in 0..<n {
        let temp : [Int] = Array.init(repeating: 0, count: i+1)
        triangle.append(temp)
    }

    var column: Int = -1
    var row: Int = 0
    var count: Int = 0
    for i in stride(from: n, to: 0, by: -3) {
        for _ in 0..<i {
            count += 1
            column += 1
            triangle[column][row] = count
        }

        guard 0 <= i-1 else { continue }

        for _ in 0..<i-1 {
            count += 1
            row += 1
            triangle[column][row] = count
        }

        guard 0 <= i-2 else { continue }

        for _ in 0..<i-2 {
            count += 1
            column -= 1
            row -= 1
            triangle[column][row] = count
        }
    }

    return triangle.flatMap { $0 }
}

print(solution(4))
print(solution(5))
