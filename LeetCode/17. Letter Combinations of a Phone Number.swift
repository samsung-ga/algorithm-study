//
//  17. Letter Combinations of a Phone Number.swift
//  Problem_Solving
//
//  Created by Woody on 2022/12/27.
//

import Foundation

class Solution {
    func letterCombinations(_ digits: String) -> [String] {
        guard digits.isEmpty == false else { return [] }
        let numbers: [String: [String]] = [
            "2" : ["a","b","c"],
            "3" : ["d","e","f"],
            "4" : ["g","h","i"],
            "5" : ["j","k","l"],
            "6" : ["m","n","o"],
            "7" : ["p","q","r","s"],
            "8" : ["t","u","v"],
            "9" : ["w","x","y","z"]
        ]

        var ret: [String] = [""]

        for digit in digits {
            ret = ret.flatMap { item in
                (numbers[String(digit)] ?? []).map { item + $0 }
            }
        }
        return ret
    }
}
