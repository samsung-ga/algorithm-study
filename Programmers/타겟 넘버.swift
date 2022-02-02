import Foundation

func solution(_ numbers:[Int], _ target:Int) -> Int {
    var result: [[Int]] = [[Int]]()
    

    func dfs(_ original: [Int],_ index: Int, _ count: Int, _ targetValue: Int, _ resultArray: [Int]) {
        if index == original.count {
            if count == targetValue {
                result.append(resultArray)
            }
            return
        }
        dfs(original, index+1, count + original[index], targetValue, resultArray + [original[index]])
        dfs(original, index+1, count - original[index], targetValue, resultArray + [-original[index]])
    
    }
    dfs(numbers, 0, 0, target, [])

    return result.count
}
