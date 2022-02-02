import Foundation

func getString(original: String, from: Int, to: Int) -> String {
    let startIndex = original.startIndex
    let start = original.index(startIndex, offsetBy: from)
    let end = original.index(startIndex, offsetBy: to)
    return String(original[start...end])
}
func solution(_ lines:[String]) -> Int {
    var endIntTime = [Int]()
    var startIntTime = [Int]()

    lines.forEach {
        let strings = $0.split(separator: " ")
        let strings1 = String(strings[1])
        let hour = Int(getString(original: strings1, from: 0, to: 1))!
        let minute = Int(getString(original: strings1, from: 3, to: 4))!
        let second = Int(getString(original: strings1, from: 6, to: 7))!
        let millisecond =  Int(getString(original: strings1, from: 9, to: 11))!
        let timeInt: Int = (hour * 3600 + minute * 60 + second) * 1000 + millisecond
        endIntTime.append(timeInt)
        
        var strings2 = String(strings[2])
        strings2.removeLast()
        startIntTime.append(timeInt - Int(Double(strings2)! * 1000) + 1)
        
    }

    var maxResult: Int = 0
    for i in 0...lines.count-1 {
        var count = 0
        let currentTime = endIntTime[i]
        for j in i...lines.count-1 {
            if currentTime > startIntTime[j] - 1000 {
                count += 1
            }
        }
        maxResult = max(maxResult, count)
    }
    
    return maxResult
}




print(solution([
    "2016-09-15 20:59:57.421 0.351s",
    "2016-09-15 20:59:58.233 1.181s",
    "2016-09-15 20:59:58.299 0.8s",
    "2016-09-15 20:59:58.688 1.041s",
    "2016-09-15 20:59:59.591 1.412s",
    "2016-09-15 21:00:00.464 1.466s",
    "2016-09-15 21:00:00.741 1.581s",
    "2016-09-15 21:00:00.748 2.31s",
    "2016-09-15 21:00:00.966 0.381s",
    "2016-09-15 21:00:02.066 2.62s"
    ]))

