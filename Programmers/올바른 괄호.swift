//
//  올바른 괄호.swift
//  Coding_Test_Swift
//
//  Created by Woody on 2022/09/17.
//

import Foundation

func solution(_ s:String) -> Bool {
    var count: Int = 0

    for chr in s {
        let charString = String(chr)

        if charString == "(" {
            count += 1
        } else {
            count -= 1
        }

        if count < 0 {
            return false
        }
    }

    return count == 0
}

print(solution("()()"))
print(solution("(())()"))
print(solution(")()("))
print(solution("(()("))

// MARK: 아래는 시간 초과 코드
func solution2(_ s:String) -> Bool {
    var queue: [String] = []
    for chr in s {
        let chrString = String(chr)
        if chrString == "(" {
            queue.append("(")
        } else {
            if let _ = queue.first {
                queue.removeFirst()
            } else {
                return false
            }
        }
    }

    return queue.isEmpty
}
