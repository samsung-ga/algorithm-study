import Foundation

func solution(_ s:String) -> Int{
    var result = [Character]()
    var arr = Array(s)

    for index in arr.indices {
        if result.isEmpty { result.append(arr[index]) }
        else {
            if result.last! == arr[index] {
                result.removeLast()
            } else {
                result.append(arr[index])
            }
        }
    }
    return result.isEmpty ? 1 : 0
}
