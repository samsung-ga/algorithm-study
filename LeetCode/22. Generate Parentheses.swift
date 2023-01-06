//
//  22. Generate Parentheses.swift
//  Problem_Solving
//
//  Created by Woody on 2023/01/06.
//

import Foundation

class Solution {

    var n: Int!
    var result: [String] = []
    
    func generateParenthesis(_ n: Int) -> [String] {
        self.n = n
        backtracking("", 0, 0)
        return result
    }

    func backtracking(_ par: String, _ a: Int, _ b: Int) {
        if a < b { return }
        if a == n {
            var par = par
            for _ in 0..<a-b {
                par += ")"
                
            }
            result.append(par)
            return
        }

        backtracking(par + "(", a+1, b)
        backtracking(par + ")",a, b+1)
    }
}
