import Foundation

/// 모두 누르기가 가능한 숫자인지 체크하는 함수
func checkNumbers(_ number: Int, errorNums: [String]) -> Bool {
    let numberString: String = String(number)
    return numberString.filter { errorNums.contains(String($0)) }.isEmpty
}
/// 자릿수 계산하는 함수
func getNumber(_ number: Int) -> Int {
    if number == 0 { return 1 }
    
    var number: Int = number
    var result: Int = 0
    while number > 0 {
        number /= 10
        result += 1
    }
    return result
}
if let n = readLine(),
   let n = Int(n),
   let errorNum = readLine(),
   let errorNum = Int(errorNum) {
    var errors: [String] = []
    
    
    if errorNum != 0 { // 고장이 안났다면
        errors = readLine()?.components(separatedBy: .whitespaces) ?? []
    }
    
    let stupidNUmber: Int = abs(n-100)
    if (n <= 103 && n >= 97) || errorNum == 10 { // 고장이 전부 났다면
        print(stupidNUmber)
    } else {
        for i in 0...1000000 {
            let minusNumber = n - i
            let plusNumber = n + i
            
            if minusNumber >= 0 &&
                checkNumbers(minusNumber, errorNums: errors) {
                let result: Int = getNumber(minusNumber) + i
                print(min(stupidNUmber, result))
                break
            }
            
            if checkNumbers(plusNumber, errorNums: errors) {
                let result: Int = getNumber(plusNumber) + i
                print(min(stupidNUmber, result))
                break
            }
        }
    }
}

/*
 질문에서 찾은 TC
 
 틀린 테스트 케이스 1
 77
 9
 0 1 2 3 4 6 7 8 9
 23
  
 틀린 테스트 케이스 2
 500000
 9
 0 1 2 3 4 6 7 8 9
 */
