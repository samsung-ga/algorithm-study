# Algorithm_Study
알고리즘 공부하자...

## 목표
- 모든 알고리즘 문제들을 1문제당 30분안에 풀 수 있는 역량 기르기
- 카카오나 네이버의 코딩테스트 문제들을 손쉽게 풀 수 있게 하기 

## 방식

> 1. 기한: 7/27 ~ 8/10
> 2. 주말을 제외하고 1일1문제
> 3. [백준](https://www.acmicpc.net), [swexpertacademy](https://swexpertacademy.com/main/code/problem/problemList.do?) 등의 코테문제에서 단계별로 풀기



## 문제풀이

**참고자료**

- [2018 kakao blind requirement](https://programmers.co.kr/learn/challenges)



## 정리 

**반올림** 

- math.h 라이브러리의 round 메소드 사용한다.
- 그 외에 ceil (올림), floor(내림) 메소드가 있다.
- 만약, 소수 첫째자리에서 반올림하고 싶다면, 반올림하고 싶은 수 + 0.5 를 int 형으로 바꾸어주는 방법도 가능하다.
- [swexpertacademy 2071 평균값구하기 문제](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5QRnJqA5cDFAUq&categoryId=AV5QRnJqA5cDFAUq&categoryType=CODE)

**각 자리수에 접근하기**

- char 배열을 통해 접근이 가능하다.
- string 의 to_string()을 이용하여 int를 string으로 바꿀 수 있다.
- [swexpertacademy 2056 연일월 달력 문제](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5QLkdKAz4DFAUq&categoryId=AV5QLkdKAz4DFAUq&categoryType=CODE)

