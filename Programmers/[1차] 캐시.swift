func checkMinValue(_ cache: [String: Int]) -> String {
    var leastRecentlyUsed: String = cache.first?.key ?? ""
    
    for citi in cache {
        if citi.value < cache[leastRecentlyUsed]! {
            leastRecentlyUsed = citi.key
        }
    }
    return leastRecentlyUsed
}

func solution(_ cacheSize:Int, _ cities:[String]) -> Int {
    var cache: [String: Int] = [:]
    var times: Int = 0
    
    cities.enumerated().forEach {
        let citiName: String = $0.element.uppercased()
        let citiNumber: Int = $0.offset
        // 캐시 확인
        if let _ = cache[citiName] {
            // 캐시에 있다면 +1초 , 캐시값 + 1, 캐시 업데이트
            times += 1
            cache[citiName] = citiNumber
        } else {
            // 캐시에 없다면 +5초 , 캐시에 저장 - 캐시가 꽉 차 있으면 제일 이전에 쓰인거 확인해서 교체
            times += 5
            if cache.count < cacheSize {
                cache[citiName] = citiNumber
            } else {
                let lru = checkMinValue(cache)
                if !lru.isEmpty {
                    cache.removeValue(forKey: lru)
                    cache[citiName] = citiNumber
                }
            }
        }
    }
    
    return times
}
