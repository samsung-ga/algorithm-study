import Foundation

func sliceString(str: String, by: Int) -> [String] {
    var string = str
    var result = [String]()
    while string.count > 0 {
        if string.count < by {
            result.append(string)
            return result
        }
        let sliceIndex = string.index(string.startIndex, offsetBy: by)
        result.append(String(string[string.startIndex..<sliceIndex]))
        string = String(string[sliceIndex...])
    }
    return result
}

func solution(_ s:String) -> Int {
    let length: Int = s.count
    var minResult: Int = length
    
    if length < 2 { return 1 }
    for divide in 1...length/2 {
        let stringArray: [String] = sliceString(str: s, by: divide)
        var previousStr = stringArray.first!
        var count = 1
        var resultString = ""
        stringArray.enumerated().forEach {
            if stringArray.count == 1 {
                resultString += "\(previousStr)"
            } else {
                if $0.offset != 0 {
                    if $0.element == previousStr {
                        count += 1
                        if $0.offset == stringArray.count - 1 {
                            resultString += "\(count)\(previousStr)"
                        }
                    } else {
                        if count == 1 {
                            resultString += "\(previousStr)"
                        } else {
                            resultString += "\(count)\(previousStr)"
                        }
                        previousStr = $0.element
                        count = 1
                        if $0.offset == stringArray.count - 1 {
                            resultString += "\(previousStr)"
                        }
                    }
                }
            }
        }
        minResult = min(minResult, resultString.count)
    }
    return minResult
}


print(solution("a"))
