import Foundation

func getLength(_ number: Int, xChannels: [Int]) -> Int? {
    // number = 0 인 경우 length를 제대로 못 구하는 예외 처리
    if number == 0 {
        if xChannels.contains(0) {
            return nil
        } else {
            return 1
        }
    }

    var number = number
    var length = 0

    while number > 0 {
        if xChannels.contains(number%10) {
            return nil
        }
        number /= 10
        length += 1
    }
    return length
}

func solution() {
    let finalNumber = Int(readLine()!)!
    let xCount = Int(readLine()!)!
    var xChannels = [Int]()
    if xCount != 0 {
        xChannels = readLine()!.split(separator: " ").map { Int(String($0))! }
    }

    var result: Int = abs(finalNumber - 100)
    for channel in 0...1000000 {
        if let length = getLength(channel, xChannels: xChannels) {
            result = min(result, length + abs(finalNumber - channel))
        }
    }
    print(result)
}

solution()
