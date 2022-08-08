import Foundation

func solution(_ N:Int, _ stages:[Int]) -> [Int] {
    var stageList: [Int] = Array.init(repeating: 0, count: N+2) // 1 ~ (5 + 1)
    var usersWhoReachStage: Int = stages.count
    stages.forEach {
        stageList[$0] += 1
    }

    var failRateList: [(Int, Double)] = []
    for (i, stage) in stageList.enumerated() {
        if i == 0 || i == stageList.count - 1 { continue }
        let failure: Double = Double(stage) / Double(usersWhoReachStage)
        failRateList.append((i,failure))
        usersWhoReachStage -= stage

    }
    return failRateList.sorted {
        if $0.1 == $1.1 {
            return $0.0 < $1.0
        } else {
            return $0.1 > $1.1
        }
    }.map {
        $0.0
    }
}
