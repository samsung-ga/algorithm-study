//
//  JadenCase 문자열 만들기.swift
//  Coding_Test_Swift
//
//  Created by Woody on 2022/09/22.
//

import Foundation

extension StringProtocol {
    var firstUpperCased: String {
        guard let first = first else { return "" }
        return String(first).uppercased() + dropFirst()
    }
}

func solution(_ s: String) -> String {
    var lowerArr: [String] = s.lowercased().components(separatedBy: .whitespaces)
    var result: String = ""
    for string in lowerArr {
        guard let first = string.first else { continue }
        result += " " + String(first).uppercased() + string.dropFirst()
    }
    if s.first! != " " { result.removeFirst() }
    return result
}

print(solution("3people unFollowed me"))

print(solution("333PEOHKD unUDJHFDK"))
print(solution("for the last week"))
