import Foundation

func check(_ p: String) -> Bool {
    var resultString: String = ""
    for (_, element) in p.enumerated() {
        if element == "(" {
            resultString.append("(")
        } else {
            if resultString.isEmpty {
                return false
            } else {
                resultString.removeLast()
            }
        }
    }
    return resultString.isEmpty
}

func solution(_ p: String) -> String {
     if p.isEmpty { return "" }
    var startCount: Int = 0
    var endCount: Int = 0
    var u: String = ""
    var v: String = ""
    for (index, element) in p.enumerated() {
        u.append(element)
        if element == "(" {
            startCount += 1
        } else {
            endCount += 1
        }
        if startCount == endCount {
            if let index = p.index(p.startIndex, offsetBy: index+1, limitedBy: p.endIndex) {
                v = String(p[index...])
            } else {
                v = ""
            }
            break
        }
    }
    
    if check(u) {
        return u + solution(v)
    } else {
        var temp: String = ""
        temp.append("(")
        temp.append(solution(v))
        temp.append(")")
        u.removeFirst()
        u.removeLast()
        let c1 = u.replacingOccurrences(of: "(", with: "*")
        let c2 = c1.replacingOccurrences(of: ")", with: "(")
        let c3 = c2.replacingOccurrences(of: "*", with: ")")
        temp.append(c3)
        return temp
    }
}


