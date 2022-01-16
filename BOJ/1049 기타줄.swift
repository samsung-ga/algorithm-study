import Foundation

if let nm = readLine()?.components(separatedBy: .whitespaces),
   let n = Int(nm[0]),
   var m = Int(nm[1]) {
  var minSet: Int = 100000
  var minOne: Int = 100000
  while m > 0 {
    m -= 1
    if let brand = readLine()?.components(separatedBy: .whitespaces),
       let set = Int(brand[0]),
       let one = Int(brand[1]) {
      minSet = min(set, minSet)
      minOne = min(one, minOne)
    }
  }
  
  let set = n / 6
  let one = n % 6

  if minSet > minOne * 6 {
    print(minOne*n)
  } else {
    print(minSet*set + min(minSet, one*minOne))
  }
  
}


