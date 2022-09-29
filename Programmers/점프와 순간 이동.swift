//
//  점프와 순간 이동.swift
//  Coding_Test_Swift
//
//  Created by Woody on 2022/09/23.
//

import Foundation

// MARK: 정답 코드

func solution(_ n:Int) -> Int
{
    var ans:Int = 0
    var n = n
    while n > 0 {
        ans += (n%2)
        n /= 2
    }
    return ans
}


// MARK: 시간 초과

func solution(_ n:Int) -> Int
{
    typealias Count = Int
    typealias Number = Int
    var ans:Int = 1
    var queue: [(Number,Count)] = [(1,1)]
    var index: Int = 0
    while true {
        let first = queue[index].0
        let count = queue[index].1
        index += 1

        if first == n {
            ans = count
            break
        }
        queue.append((first*2, count))
        queue.append((first+1, count+1))
    }

    return ans
}

print(solution(5))
print(solution(6))
print(solution(5000))
