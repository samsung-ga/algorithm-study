import Foundation

enum Number: Int {
    case zero = 0
    case one
    case two
    case three
    case four
    case five
    case six
    case seven
    case eight
    case nine
    
    static let allCase: [Number] = [zero,one,two,three,four,five,six,seven,eight,nine]
}

func solution(_ s:String) -> Int {
    var result: String = s
    Number.allCase.forEach {
        if s.contains("\($0)") {
            result = result.replacingOccurrences(of: "\($0)", with: "\($0.rawValue)")
        }
    }
    
    return Int(result)!
}

print(solution("one4seveneight"))
