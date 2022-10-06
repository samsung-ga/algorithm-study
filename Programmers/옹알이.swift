//
//  옹알이.swift
//  Coding_Test_Swift
//
//  Created by Woody on 2022/10/06.
//

import Foundation

func solution(_ babbling:[String]) -> Int {
    let words: [String] = ["aya", "ye", "woo", "ma"]
    let babblings: [String] = babbling.split(separator: " ").flatMap { $0 }
    var count: Int = 0
    for element in babblings {
        var element: String = element
        var flag: Bool = true
        for word in words {
            if word == "aya" {
                element = element.replacingOccurrences(of: word, with: "A")
            } else if word == "ye" {
                element = element.replacingOccurrences(of: word, with: "B")
            } else if word == "woo" {
                element = element.replacingOccurrences(of: word, with: "C")
            } else if word == "ma" {
                element = element.replacingOccurrences(of: word, with: "D")
            }
        }

        var beforeWord: String = ""
        for chr in element {
            if beforeWord == String(chr) ||
               !(chr == "A" || chr == "B" || chr == "C" || chr == "D") {
                flag = false
                break
            }
            beforeWord = String(chr)
        }
        if flag { count += 1}
    }
    return count
}
