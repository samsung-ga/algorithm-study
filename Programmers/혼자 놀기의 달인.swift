//
//  혼자 놀기의 달인.swift
//  Problem_Solving
//
//  Created by Woody on 2023/01/05.
//

import Foundation

func solution(_ cards:[Int]) -> Int {
    
    var maxRet: Int = 0
    
    for (index, card) in cards.enumerated() {
        var box1Count: Int = 0
        var box2Count: Int = 0
        var cardDic: [Int: Bool] = [:]
        for i in 0..<cards.count {
            cardDic[i+1] = false
        }
        
        cardDic[index+1] = true
        box1Count += 1
        // 그룹 1
        var cur = card
        while cardDic[cur]! == false {
            cardDic[cur] = true
            cur = cards[cur-1]
            box1Count += 1
        }
        
        // 그룹 2
        for i in 0..<cards.count {
            var tempCount = 0
            if i == index { continue }
            if cardDic[i+1] == true { continue }
            cardDic[i+1] = true
            tempCount += 1
            var cur2 = cards[i]
            while cardDic[cur2]! == false {
                cardDic[cur2] = true
                cur2 = cards[cur2-1]
                tempCount += 1
            }
            box2Count = max(box2Count, tempCount)
        }
    
        maxRet = max(maxRet, box2Count * box1Count)
    }
    
    return maxRet
}
