//
//  과제 진행하기.swift
//  algorithm
//
//  Created by Woody Lee on 2023/04/02.
//

import Foundation

func solution(_ plans:[[String]]) -> [String] {
    struct Plan {
        let name: String
        let start: Int
        var playtime: Int
        
        
        init(name: String, start: String, playtime: Int) {
            self.name = name
            self.playtime = playtime
            
            let time = start.components(separatedBy: ":")
            self.start = Int(time[0])! * 60 + Int(time[1])!
        }
    }
    
    let plans = plans
        .map { Plan(name: $0[0], start: $0[1], playtime: Int($0[2])!) }
        .sorted { $0.start < $1.start }

    var nextPlan: Plan = plans[1]
    var stack: [(Plan,Int)] = []
    var ret: [String] = []
    
    for i in 0..<plans.count-1 {
        nextPlan = plans[i + 1]
        let currentPlan = plans[i]
        var currentPlanEndTime = currentPlan.start + currentPlan.playtime
        if currentPlanEndTime <= nextPlan.start {
            ret.append(currentPlan.name)
            
            while stack.isEmpty == false {
                guard let stored = stack.popLast() else { break }
                let storedPlan = stored.0
                let storedPlanLastPlaytime = stored.1
                let storedPlanEndTime = currentPlanEndTime + storedPlanLastPlaytime
                
                if storedPlanEndTime <= nextPlan.start {
                    ret.append(storedPlan.name)
                    currentPlanEndTime = storedPlanEndTime
                } else {
                    let last = storedPlanEndTime - nextPlan.start
                    stack.append((storedPlan, last))
                    break
                }
            }
        } else {
            let last = currentPlanEndTime - nextPlan.start
            stack.append((currentPlan, last))
        }
    }
    
    ret.append(nextPlan.name)
    while stack.isEmpty == false {
        guard let storedPlan = stack.popLast() else { return [] }
        ret.append(storedPlan.0.name)
    }
    
    return ret
}

let ans = solution(
    [["aaa", "12:00", "20"], ["bbb", "12:10", "30"], ["ccc", "12:40", "10"]]
)
print(ans)

