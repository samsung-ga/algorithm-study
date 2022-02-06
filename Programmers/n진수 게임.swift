import Foundation


func changeRadix(_ n: Int, _ target: Int) -> String {
    return String(target, radix: n, uppercase: true)
}
func solution(_ n:Int, _ t:Int, _ m:Int, _ p:Int) -> String {
    let total: Int = t * m
    var totalNumber: String = ""
    var result: String = ""
    for i in 0..<total {
        totalNumber.append(changeRadix(n, i))
    }
    for (i,num) in totalNumber.enumerated() {
        if (i+1) % m == p || ((m == p) && (i+1) % m == 1){
            result.append(num)
            if result.count == t {
                break
            }
        }
    }
    
    print(stride(from: p-1, to: total, by: m).reduce("", { $0 + String(totalNumber[totalNumber.index(result.startIndex, offsetBy: $1)])}))
    return result
}

print(solution(2, 4, 2, 1))
print(solution(16, 16, 2, 1))
