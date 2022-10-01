//
//  두 큐 합 같게 만들기.swift
//  Coding_Test_Swift
//
//  Created by Woody on 2022/10/01.
//

import Foundation

func solution(_ queue1:[Int], _ queue2:[Int]) -> Int {
    var queue1: [Int] = queue1
    var queue2: [Int] = queue2

    var limit: Int = queue1.count * 2

    var index1: Int = 0
    var index2: Int = 0
    var sum1 = queue1.reduce(0, +)
    var sum2 = queue2.reduce(0, +)

    var count: Int = 0
    var flag: Bool = false
    while queue1.count <= limit {
        if sum1 == sum2 {
            flag = true
            break
        }

        if sum1 < sum2 {
            sum2 -= queue2[index2]
            sum1 += queue2[index2]
            queue1.append(queue2[index2])
            index2 += 1
        } else {
            sum1 -= queue1[index1]
            sum2 += queue1[index1]
            queue2.append(queue1[index1])
            index1 += 1
        }

        count += 1
    }

    return flag == false ? -1 : count
}
