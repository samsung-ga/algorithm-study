import Foundation

var numbers: [Int] = []

for _ in stride(from: 0, to: 9, by: 1) {
    if let num = readLine(),
       let num = Int(num) {
        numbers.append(num)
    }
}

numbers.sort()
var flag = false
let sum = numbers.reduce(0, +)
for i in 0..<numbers.count-1 {
    for j in i+1..<numbers.count {
        var count = sum
        count -= numbers[i]
        count -= numbers[j]

        if count == 100 {
            numbers.remove(at: j)
            numbers.remove(at: i)
            flag = true
            break
        }
    }
    if flag {
        break
    }
}

for key in numbers {
    print(key)
}
