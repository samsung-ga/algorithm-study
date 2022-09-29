//
//  n^2 배열 자르기.swift
//  Coding_Test_Swift
//
//  Created by Woody on 2022/09/23.
//

import Foundation

func solution(_ n:Int, _ left:Int64, _ right:Int64) -> [Int] {
    if n == 1 { return [1] }
    var result: [Int64] = []
    for i in left...right {
        let row = (i / Int64(n)) + 1
        let column = (i % Int64(n)) + 1
        result.append(max(Int64(row), Int64(column)))
    }
    return result.map { Int($0) }
}
