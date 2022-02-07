import Foundation

func search(dictionary: [String: Int], target: String) -> Int? {
    return dictionary[target]
}

func solution(_ msg:String) -> [Int] {
    var dictionary: [String: Int] = [:]
    let alphabets: [String] = "abcdefghijklmnopqrstuvwxyz".uppercased().map { String($0) }
    
    for (index, alphabet) in alphabets.enumerated() {
        dictionary[alphabet] = index + 1
    }
    
    var message: String = msg
    var startNumber: Int = 27
    var countIndex: Int = 0
    var temp: Int = 0
    var result: [Int] = []
    while !message.isEmpty {
        let startIndex = message.startIndex
        let endIndex = message.index(message.startIndex, offsetBy: countIndex, limitedBy: message.endIndex) ?? message.startIndex
        let printChar: Int? = search(dictionary: dictionary, target: String(message[startIndex...endIndex]))
        if printChar == nil {
            result.append(temp)
            dictionary[String(message[startIndex...endIndex])] = startNumber
            while countIndex > 0 {
                message.removeFirst()
                countIndex -= 1
            }
            startNumber += 1
            countIndex = 0
        } else {
            temp = printChar!
            countIndex += 1
            if message.count == countIndex {
                result.append(temp)
                while countIndex > 0 {
                    message.removeFirst()
                    countIndex -= 1
                }
            }
        }
        
    }
    return result
}

print(solution("ABABABABABABABAB"))
