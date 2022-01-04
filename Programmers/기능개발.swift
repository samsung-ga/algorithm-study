import Foundation

func solution(_ progresses:[Int], _ speeds:[Int]) -> [Int] {
    var leftDays: [Int] = []
    
    progresses.enumerated().forEach {
        let lp: Int = 100 - $1
        let day: Int = lp % speeds[$0] == 0 ? lp / speeds[$0] : lp / speeds[$0] + 1
        leftDays.append(day)
    }
    
    var result: [Int] = []
    var done: [Int] = []

    for (index, day) in leftDays.enumerated() {
        if done.contains(index) { continue }
        
        if index == leftDays.count - 1 {
            done.append(index)
            result.append(1)
        } else if leftDays[index] < leftDays[index+1] {
            done.append(index)
            result.append(1)
        } else {
            var i: Int = index
            var count: Int = 0
            while (leftDays[index] >= leftDays[i+1]) {
                done.append(i)
                count += 1
                i += 1
                if i == leftDays.count - 1 {
                    break
                }
            }
            done.append(i)
            count += 1
            result.append(count)
        }
    }
    
    return result
}
