//
//  괄호 회전하기.swift
//  Coding_Test_Swift
//
//  Created by Woody on 2022/09/23.
//

import Foundation

func checkIsCorrect(_ s: String) -> Bool {
    var check: Bool = true
    var stack: [String] = []
    let stringArray = Array(s).map { String($0) }

    for string in stringArray {
        if string == "(" || string == "[" || string == "{" {
            stack.append(string)
        } else {
            if string == ")" {
                if let last = stack.last,
                   last == "(" {
                    stack.popLast()
                } else {
                    check = false
                    break
                }
            } else if string == "]" {
                if let last = stack.last,
                   last == "[" {
                    stack.removeLast()
                } else {
                    check = false
                    break
                }
            } else {
                if let last = stack.last,
                   last == "{" {
                    stack.removeLast()
                } else {
                    check = false
                    break
                }
            }
        }
    }
    return stack.isEmpty ? check : false
}

func solution(_ s:String) -> Int {
    let stringCount = s.count
    var ans: Int = 0
    for i in 0..<stringCount {
        let add = s.prefix(i)
        let temp = s.dropFirst(i) + add
        if checkIsCorrect(String(temp)) {
            ans += 1
        }
    }
    return ans
}

print(solution("[](){}"))
print(solution("}]()[{"))
print(solution("[)(]"))

//let s = "123".dropFirst(0)
//print(s)
