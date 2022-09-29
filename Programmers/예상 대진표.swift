//
//  예상 대진표.swift
//  Coding_Test_Swift
//
//  Created by Woody on 2022/09/23.
//

import Foundation

func solution(_ n:Int, _ a:Int, _ b:Int) -> Int
{
    var answer: Int = 0

    var firstPersonIndex = n + a - 1
    var secondPersonIndex = n + b - 1

    while firstPersonIndex != secondPersonIndex {
        firstPersonIndex /= 2
        secondPersonIndex /= 2
        answer += 1
    }
    return answer
}

print(solution(8, 4, 7))
