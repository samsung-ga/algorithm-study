//
//  7. Reverse Integer.swift
//  Problem_Solving
//
//  Created by Woody on 2022/12/21.
//

import Foundation

class Solution {
    func reverse(_ x: Int) -> Int {
        var x: Int = x
        var ret: Int = 0
        while x != 0 {
            // -1231 % 10 = -1
            let temp = x % 10
            x = x / 10
            ret = (ret * 10) + temp
        }
        guard ret >= Int32.min && ret <= Int32.max else { return 0 }
        return ret
    }
}
