import Foundation

func solution(_ lottos:[Int], _ win_nums:[Int]) -> [Int] {

    let zeroCount: Int = lottos.filter { $0 == 0 }.count
    let matchCount: Int = lottos.filter { win_nums.contains($0) }.count
    
    let max = 7-(matchCount+zeroCount)
    let min = 7-matchCount
    return [max > 6 ? 6 : max, min > 6 ? 6 : min]
}
