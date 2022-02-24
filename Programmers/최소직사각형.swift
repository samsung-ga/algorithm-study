import Foundation

func solution(_ sizes:[[Int]]) -> Int {
    var _sizes: [[Int]] = []
    sizes.forEach {
        let width = max($0[0], $0[1])
        let height = min($0[0], $0[1])
        
        _sizes.append([width,height])
    }
    
    var resultWidth: Int = 0
    var resultHeight: Int = 0
    _sizes.forEach {
        resultWidth = max(resultWidth, $0[0])
        resultHeight = max(resultHeight, $0[1])
    }
    
    return resultWidth * resultHeight
}
