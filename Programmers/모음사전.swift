//
//  모음사전.swift
//  Coding_Test_Swift
//
//  Created by Woody on 2022/09/23.
//

import Foundation

func solution(_ word:String) -> Int {
    let words: [String] = ["A","E","I","O","U"]
    var dictionarys: [String] = []

    func dfs(newWord: String, count: Int) {
        if count == words.count {
            return
        }
        for i in 0..<words.count {
            let new = newWord + words[i]
            dictionarys.append(new)
            dfs(newWord: new, count: count+1)
        }
    }

    dfs(newWord: "", count: 0)

    dictionarys.sort()
    return dictionarys.firstIndex(of: word)! + 1
}
