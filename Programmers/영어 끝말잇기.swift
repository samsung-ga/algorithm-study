//
//  영어 끝말잇기.swift
//  Coding_Test_Swift
//
//  Created by Woody on 2022/09/23.
//

import Foundation

func solution(_ n:Int, _ words:[String]) -> [Int] {
    var storage: [String] = [words[0]]
    var flag: Bool = true
    for i in 1..<words.count {
        if storage[i-1].last! == words[i].first!,
           storage.contains(words[i]) == false {
            storage.append(words[i])
            continue
        }
        storage.append(words[i]) // 해당 차례를 알아야 하기 떄문에 append
        flag = false
        break
    }
    if flag { return [0,0] }
    let number: Int = storage.count % n == 0 ? n : storage.count % n
    let personIndex: Int = (storage.count-1) / n + 1
    return [number, personIndex]
}
