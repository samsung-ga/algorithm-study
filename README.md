# Algorithm_Study
알고리즘 공부하자...

## 목표
- 모든 알고리즘 문제들을 1문제당 30분안에 풀 수 있는 역량 기르기
- 카카오나 네이버의 코딩테스트 문제들을 손쉽게 풀 수 있게 하기 

## 방식

> 1. 기한: 7/27 ~ 
> 2. Notion으로 과제 칸반보드를 통해 과제 리스트 확인하고 풀기
> 3. 문제풀이 질문이나 풀이 공유는 **질문/코드리뷰** 이용
> 4. [백준](https://www.acmicpc.net), [swexpertacademy](https://swexpertacademy.com/main/code/problem/problemList.do?) 등의 코테문제에서 단계별로 풀기



## 주차별 주제

**문제 풀이**

1st week: 

- **브루트 포스 - 1**

  <s>[일곱 난쟁이 - BOJ](https://www.acmicpc.net/problem/2309)</s>

  <s>[날짜 계산 - BOJ](https://www.acmicpc.net/problem/1476)</s>

  <s>[테트로미노 - BOJ](https://www.acmicpc.net/problem/14500)</s>

  <s>[1,2,3 더하기 - BOJ](https://www.acmicpc.net/problem/9095)</s> 

  <s>[다음 순열 - BOJ](https://www.acmicpc.net/problem/10972)</s>

  <s>[이전 순열 - BOJ](https://www.acmicpc.net/problem/10973)</s>

  <s>[모든 순열 - BOJ](https://www.acmicpc.net/problem/10974)</s>

- **수학**

  <s>[나머지](https://www.acmicpc.net/problem/10430)</s>

  <s>[최대공약수와 최소공배수](https://www.acmicpc.net/problem/2609)</s>

  <s>[최소공배수](https://www.acmicpc.net/problem/1934)</s>

  <s>[GCD 합](https://www.acmicpc.net/problem/9613)</s>

  <s>[소수 찾기](https://www.acmicpc.net/problem/1978)</s>

  [골드바흐의 추측](https://www.acmicpc.net/problem/6588)  대체 왜 시간초과?



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

**순열**

- algorithm 헤더파일의 next_permutation(), prev_permutation()을 통해 do while 문을 이용하여 사전순 순서대로 출력이 가능하다. 
- 직접 구현하는 알고리즘은 두가지 블로그를 참고하였다. 👉  [순서 상관 없이 출력](https://minusi.tistory.com/entry/%EC%88%9C%EC%97%B4-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-Permutation-Algorithm) / [순서 상관있이 출력](https://jeonggyun.tistory.com/110)
- 알고리즘: 
  1. 뒤에서부터 탐색하여 오름차순으로 구성되어있는 쌍을 찾고 i,ii 로 지정한다.  
  2. 또 뒤에서부터 탐색하여 i로 지정한 수보다 큰 수를 찾고 j로 지정한다.
  3. i와 j를 swap한다.
  4. ii를 포함한 뒤 모든 수를 reverse 한다.

**최대공약수 최소공배수**

- 최대공약수는 두 수중 작은 수까지 for문을 돌려, 두 수가 모두 나누어지는 값이 최대공약수이다. 시간 복잡도: O(N)
- **유클리드 호제법** 이용 : a = b*q + p 의 상황에서 a와 b의 최대공약수는 b와 p의 최대공약수와 같다. 시간 복잡도: O(logN)
- [BOJ 2609 최대공약수와 최소공배수](https://www.acmicpc.net/problem/2609)
- [최소공배수](https://www.acmicpc.net/problem/1934)

**에라토스테네스의 체**

- 소수 찾기 알고리즘이다. 평범하게 수 하나가 소수인지 아닌지 확인하기 위한 알고리즘의 시간 복잡도는 O(N)이다. 즉, 1부터 N까지 소수판별 알고리즘의 시간복잡도는 O(N^2)이다.
- 에라토스테네스의 체를 이용하면 하나의 수를 소수판별하는데 시간 복잡도는 O(√N)이다. 즉 1부터 N까지 소수판별 알고리즘의 시간복잡도는 O(N√N)이다.
- 알고리즘:
  1. 2부터 탐색을 시작하여 자기자신을 제외한 배수를 모두 소수판별에서 제거한다.



## 주의할 점❗️

- 항상 수의 범위 체크: 더할 때 int형 범위를 넘기면 long long 써주기

  ex) [GCD 합](https://www.acmicpc.net/problem/9613)

- C++에서 cin 과 cout 은 속도가 굉장히 느리기 때문에 아래의 명령어를 꼭 써주어야한다. 아니면 계속 시간초과가 나오게 될 수 있다.

  ```c++
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ```

  ex) [6588 골드바흐의 추측](https://www.acmicpc.net/problem/6588)



## 참고자료

- [2018 kakao blind requirement](https://programmers.co.kr/learn/challenges)



## 스터디원

[이현우](https://github.com/l2hyunwoo)

[홍민정](https://github.com/meanjung)

[이재용]()