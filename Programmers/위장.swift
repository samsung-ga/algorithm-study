import Foundation

func solution(_ clothes:[[String]]) -> Int {
    var clothesKind: [String: Int] = [:]
    
    clothes.forEach {
        var count: Int = clothesKind[$0[1]] ?? 1
        count += 1
        clothesKind[$0[1]] = count
    }
    
    var result: Int = 1
    for key in clothesKind.keys {
        result *= clothesKind[key]!
    }
    return result - 1
}
