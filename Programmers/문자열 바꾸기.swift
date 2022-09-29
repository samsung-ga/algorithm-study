//
//  문자열 바꾸기.swift
//  Coding_Test_Swift
//
//  Created by Woody on 2022/09/24.
//

import Foundation

func canChange(_ firstWord: String, _ secondWord: String) -> Bool {
    let firstArray = Array(firstWord)
    let secondArray = Array(secondWord)

    var count: Int = 0
    for index in 0..<firstArray.count {
        if firstArray[index] != secondArray[index] {
            count += 1
        }
    }

    return count == 1
}
func solution(_ begin:String, _ target:String, _ words:[String]) -> Int {
    if words.contains(target) == false { return 0 }

    var queue: [(String,Int)] = [(begin,0)]
    var index: Int = 0
    var visited: [Bool] = Array.init(repeating: false, count: words.count)
    var answer = 0
    while index < queue.count {
        let current = queue[index].0
        let num = queue[index].1
        index += 1

        if current == target {
            answer = num
            break
        }
        for i in 0..<words.count {
            if visited[i] == false,
               canChange(current, words[i]) {
                visited[i] = true
                queue.append((words[i],num+1))
            }
        }
    }
    return answer
}


print(solution("hit", "cog", ["hot", "dot", "dog", "lot", "log", "cog"]))

print(solution("hit", "cog", ["hot", "dot", "dog", "lot", "log"]))
