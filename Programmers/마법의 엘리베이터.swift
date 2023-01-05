//
//  마법의 엘리베이터.swift
//  Problem_Solving
//
//  Created by Woody on 2023/01/05.
//

import Foundation

func solution(_ storey:Int) -> Int {
        
    var count = 0
    var next = false
    
    var minRet = Int.max
    var queue: [(Int,Int)] = []
    queue.append((storey,0))
    while queue.isEmpty == false {
        let first = queue.removeFirst()
        let storey = first.0
        let current = first.1
        let num = storey % 10
        
        if storey == 0 {
            minRet = min(minRet, current)
        }
        // 4가지 경우 존재
        // 1. 올림 o + 다음 올림 o
        // 2. 올림 x + 다음 올림 o
        // 3. 올림 o + 다음 올림 x
        // 4. 올림 x + 다음 올림 x
        
        if num < 5 {
            queue.append((storey/10, current + num))
        } else {
            if storey < 10 {
                queue.append((0, current + num))
            } else {
                queue.append(((storey+10)/10, current + (10 - num)))
            }
            
        }
    }
    
    return minRet
}

