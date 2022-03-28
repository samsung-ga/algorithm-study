import Foundation

func lastComputer(n: Int, k: Int) -> Int {
    var a = 1
    var k = k
    if k == 0 {
        k = 4
    }
    for _ in 0..<k {
        a *= n
        a %= 10
    }
    return a
}
if let testcase = readLine(),
    var testcase = Int(testcase) {
    while testcase > 0 {
        testcase -= 1
        if let ab = readLine()?.components(separatedBy: .whitespaces),
           let a = Int(ab[0]),
           let b = Int(ab[1]) {
            if a % 10 == 0 {
                print("10")
            } else {
                let temp = b % 4
                print(lastComputer(n: a, k: temp))
            }
            
        }
    }
}
