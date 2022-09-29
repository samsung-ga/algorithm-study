//
//  다음 큰 수.swift
//  Coding_Test_Swift
//
//  Created by Woody on 2022/09/22.
//

import Foundation

func radixTo(_ radix: Int, with number: Int) -> String {
    var result: String = ""
    var number: Int = number
    while number > 0 {
        result.append("\(number % radix)")
        number /= radix
    }
    return String(result.reversed())
}
let number = 10

let radix2: String = radixTo(2, with: 10)
let radix3: String = radixTo(3, with: 10)
print(radix2)
print(radix3)

let radix2_2: String = String(number, radix: 2)
let radix3_3: String = String(number, radix: 3)
print(radix2_2)
print(radix3_3)
let radixNil: String = String(28918, radix: 3)
print(radixNil)

func solution(_ n:Int) -> Int {
    var n = n
    let oneCount: Int = String(n, radix: 2).filter { $0 == "1" }.count
    while true {
        n += 1
        if String(n, radix: 2).filter({ $0 == "1" }).count == oneCount {
            return n
        }
    }

    return 0
}

print(solution(78))

print(solution(15))
