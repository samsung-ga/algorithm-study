//
//  최솟값 만들기.swift
//  Coding_Test_Swift
//
//  Created by Woody on 2022/09/22.
//

import Foundation

func addArray(X: [Int], Y: [Int]) -> Int {
    var ans = 0
    for a in X.enumerated() {
        let index = a.offset
        let element = a.element
        ans += element * Y[index]
    }
    return ans
}

func solution(_ A:[Int], _ B:[Int]) -> Int
{
    let A = A.sorted { $0 < $1 }
    let B = B.sorted { $0 > $1 }
    var ans: Int = 0

    if A.count <= B.count {
        ans = addArray(X: A, Y: B)
    } else {
        ans = addArray(X: B, Y: A)
    }

    return ans
}

