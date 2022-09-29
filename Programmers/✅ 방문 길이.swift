//
//  방문 길이.swift
//  Coding_Test_Swift
//
//  Created by Woody on 2022/09/23.
//

import Foundation

// MARK: 길이라는 것을 알아야함 - 왼쪽에서 오른쪽, 오른쪽에서 왼쪽 모두 같은 길.
func solution(_ dirs:String) -> Int {
    struct Direction: Hashable {
        let start: Point
        let end: Point
    }

    struct Point: Hashable {
        let x: Int
        let y: Int
    }
    var dictionary: [Direction: Int] = [:]

    var sourcePoint: Point = Point(x: 0, y: 0)
    for dir in dirs {
        var nextPoint: Point
        if dir == "U" {
            nextPoint = Point(x: sourcePoint.x, y: sourcePoint.y + 1)
        } else if dir == "D" {
            nextPoint = Point(x: sourcePoint.x, y: sourcePoint.y - 1)
        } else if dir == "R" {
            nextPoint = Point(x: sourcePoint.x + 1, y: sourcePoint.y)
        } else {
            nextPoint = Point(x: sourcePoint.x - 1, y: sourcePoint.y)
        }

        // 좌표계를 넘어가는 길은 방지해야한다.
        if nextPoint.x < -5 || nextPoint.x > 5 || nextPoint.y > 5 || nextPoint.y < -5 { continue }

        // 이미 방문한 길인지 확인해주는 로직
        let direction = Direction(start: sourcePoint, end: nextPoint)
        // 왼쪽에서 오른쪽, 오른쪽에서 왼쪽 모두 같은 길.
        let direction2 = Direction(start: nextPoint, end: sourcePoint)
        if dictionary[direction] == nil &&
            dictionary[direction2] == nil {
            dictionary[direction] = 1
            dictionary[direction2] = 1
        }
        sourcePoint = nextPoint
    }

    return dictionary.count / 2
}
