//
//  수식 최대화.swift
//  Coding_Test_Swift
//
//  Created by Woody on 2022/09/26.
//

import Foundation

func calculate(num1: Int, num2: Int, operatorString: String) -> Int {
    if operatorString == "+" {
        return num1 + num2
    } else if operatorString == "-" {
        return num1 - num2
    } else {
        return num1 * num2
    }
    return 0
}

func solution(_ expression:String) -> Int64 {

    // MARK: +, -, * 경우의 수 모두 구하기 -> 6가지
    let operators: [String] = ["+","-","*"]
    var numbersFiltered: [[String]] = []
    var visited: [Bool] = Array.init(repeating: false, count: operators.count)
    func dfs(now: [String]) {
        if now.count == 3 {
            numbersFiltered.append(now)
            return
        }

        for i in 0..<operators.count {
            if visited[i] == false {
                visited[i] = true
                dfs(now: now + [operators[i]])
                visited[i] = false
            }
        }
    }
    dfs(now: [])

    var maxAnswer: Int64 = 0 // 답
    for numbersFilter in numbersFiltered {

        // MARK: expression을 배열로 만들기
        var expressionArray: [String] = []
        var temp: String = ""
        for i in 0..<expression.count {
            let chr = String(Array(expression)[i])
            if chr == "+" || chr == "-" || chr == "*" {
                expressionArray.append(temp)
                if chr == "+" { expressionArray.append("+") }
                else if chr == "-" { expressionArray.append("-") }
                else { expressionArray.append("*") }
                temp = ""
            } else {
                temp.append(chr)
            }
        }
        expressionArray.append(temp)

        // MARK: 수식 계산하기
        var answer: Int64 = 0
        for number in numbersFilter {
            var index: Int = 0
            while expressionArray.count > 1, index < expressionArray.count {
                if expressionArray[index] == number {
                    let result = Int64(calculate(
                        num1: Int(expressionArray[index-1])!,
                        num2: Int(expressionArray[index+1])!,
                        operatorString: number
                    ))
                    expressionArray.remove(at: index)
                    expressionArray.remove(at: index)
                    expressionArray.remove(at: index-1)
                    expressionArray.insert(String(result), at: index-1)
                    answer = result
                    index = 0
                } else {
                    index += 1
                }
            }
        }
        maxAnswer = max(abs(answer), maxAnswer)
    }
    return maxAnswer
}
