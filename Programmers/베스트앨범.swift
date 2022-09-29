//
//  베스트앨범.swift
//  Coding_Test_Swift
//
//  Created by Woody on 2022/09/24.
//

import Foundation

func solution(_ genres:[String], _ plays:[Int]) -> [Int] {
    typealias Index = Int
    typealias Time = Int
    var genresDictionary: [String: (Int, [(Index,Time)])] = [:]
    for i in 0..<genres.count {
        let playTime = genresDictionary[genres[i]] ?? (0, [])
        genresDictionary[genres[i]] = (playTime.0 + plays[i], playTime.1 + [(i, plays[i])])
    }
    let sortedGenresDictionary = genresDictionary.sorted { first, second in
        return first.value.0 > second.value.0
    }
    var answers: [Int] = []
    for sortedGenre in sortedGenresDictionary {
        var songs = sortedGenre.value.1
        songs.sort { first, second in
            if first.1 == second.1 {
                return first.0 < second.0
            } else {
                return first.1 > second.1
            }
        }
        let index = songs.prefix(2).map { $0.0 }
        answers.append(contentsOf: index)
    }
    return answers
}
