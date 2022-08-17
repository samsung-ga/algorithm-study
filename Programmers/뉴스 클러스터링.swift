//
//  뉴스 클러스터링.swift
//  Coding_Test_Swift
//
//  Created by Woody on 2022/08/16.
//

//import Foundation
//
//func checkStringSpecialRule(_ str: String) -> Bool {
//    for character in str {
//        if "~₩!@#$%^&*()_-+=}{\";:/?.>,<\\| 1234567890".contains(character) {
//            return false
//        }
//    }
//    return true
//}
//
//func makeMultiSet(_ str: String) -> [String]{
//    var multiSet = [String]()
//    for index in 0..<str.count - 1 {
//        let tempString: String = "\(Array(str.lowercased())[index])\(Array(str.lowercased())[index+1])"
//        let checkSpeialString: Bool = checkStringSpecialRule(tempString)
//        if checkSpeialString {
//            multiSet.append(tempString)
//        }
//    }
//    return multiSet
//}
//
//func calculateSimilarity(_ strArray1: [String], _ strArray2: [String]) -> Int {
//    var tempArray1: [String] = strArray1
//    var tempArray2: [String] = strArray2
//
//    var intersectionSet: [String] = []
//    var unionSet: [String] = []
//
//    if strArray1.count <= strArray2.count {
//        tempArray1 = strArray1
//        tempArray2 = strArray2
//    } else {
//        tempArray1 = strArray2
//        tempArray2 = strArray1
//    }
//
//    for element1 in tempArray1 {
//        for (index, element2) in tempArray2.enumerated() {
//            if element1 == element2 {
//                intersectionSet.append(element1)
//                tempArray2.remove(at: index)
//                break
//            }
//        }
//    }
//
//    unionSet = tempArray1 + tempArray2
//
//    return (intersectionSet.count * 65536 / unionSet.count )
//}
//
//func solution(_ str1:String, _ str2:String) -> Int {
//    let multiSet1 = makeMultiSet(str1)
//    let multiSet2 = makeMultiSet(str2)
//
//    if multiSet1.isEmpty && multiSet2.isEmpty {
//        return 65536
//    }
//
//    let result = calculateSimilarity(multiSet1, multiSet2)
//    return result
//}
//
//let s1 = solution("FRANCE", "french")
//print(s1)
//let s2 = solution("handshake", "shake hands")
//print(s2)
//let s3 = solution("aa1+aa2", "AAAA12")
//print(s3)
//let s4 = solution("E=M*C^2", "e=m*c^2")
//print(s4)
