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
- next_permutation의 시간 복잡도는 O(N)이다.
- [다음 순열](https://www.acmicpc.net/problem/10972) 

**조합**

- 순열과 같은 algorithm헤더파일의 메소드로 구현 가능하다. 이 때, 0,1로 이루어진 배열을 하나 더 만들어 주어 이 배열을 do while문을 이용하여 돌려야 한다.

- 조합을 구하는 문제를 순열로 풀 경우 시간 초과가 나기 쉽다.

- [로또💵](https://www.acmicpc.net/problem/6603) : 기본 조합 문제

  [연산자 끼워넣기](https://www.acmicpc.net/problem/14888) : 응용 조합 문제 4C2

  [암호 만들기](https://www.acmicpc.net/problem/1759) : 다른 조건이 포함된 조합 문제

  [부분수열의 합](https://www.acmicpc.net/problem/1182) : 응용 조합 문제 시간 초과 안된다! 20C1+20C2 + ... + 20C20 

**순열 조합의 dfs 풀이법**

> 기본적인 풀이법
>
> N과 M 문제 - 백트래킹

```c++
// 순열일경우
int visited[];
void dfs(int index, vector<int> result, vector<int> v, int n) {
  if (index == n) {
    for (int i = 0; i < result.size(); i++) {
      cout << result[i] << " ";
    }
    cout << "\n";
  }
  // 조합일경우
  // int smallest = result.empty() ? 0 : result.back();
  for (int i = 0; i < v.size(); i++) {
    if (visited[v[i]] == false) { // 순열일경우
    	result.push(v[i]);
    	visited[v[i]] = true; // 순열일경우
    	dfs(index+1, result, v, n);
  	  visited[v[i]] = false; // 순열일경우
  		result.pop();  
    }
  }
}
```

- 순열일 경우 순서가 상관 있으므로 visited라는 배열을 따로 만들어 방문했는지 안했는지 체크해준다.

- 조합일 경우 순서가 상관 없으므로 가장 작은 index + 1 값부터 새 배열에 집어넣는다.

- 중복순열일 경우 모든 수를 정렬시키면 되므로 기본 dfs 형태에서 0부터 배열크기까지 반복문을 돌린다.

- 중복조합일 경우 순서가 상관 없으므로 가장 작은 index 값부터 새 배열에 집어넣는다. 


**최대공약수 최소공배수**

- 최대공약수는 두 수중 작은 수까지 for문을 돌려, 두 수가 모두 나누어지는 값이 최대공약수이다. 시간 복잡도: O(N)
- **유클리드 호제법** 이용 : a = b*q + p 의 상황에서 a와 b의 최대공약수는 b와 p의 최대공약수와 같다. 시간 복잡도: O(logN)
- [BOJ 2609 최대공약수와 최소공배수](https://www.acmicpc.net/problem/2609)
- [최소공배수](https://www.acmicpc.net/problem/1934)

**에라토스테네스의 체**

- 소수 찾기 알고리즘이다. 평범하게 수 하나가 소수인지 아닌지 확인하기 위한 알고리즘의 시간 복잡도는 O(N)이다. 즉, 1부터 N까지 소수판별 알고리즘의 시간복잡도는 O(N^2)이다.
- 에라토스테네스의 체를 이용하면 하나의 수를 소수판별하는데 시간 복잡도는 O(√N)이다. 즉 1부터 N까지 소수판별 알고리즘의 시간복잡도는 O(N√N)이다.
- 알고리즘: 2부터 탐색을 시작하여 자기자신을 제외한 배수를 모두 소수판별에서 제거한다.

**절대값**

- abs()
- 정수 절대값을 구하는 함수는 cstdlib 헤더파일에 존재하고, 실수 절대값 함수는 cmath에 존재한다.
- [참고](https://blockdmask.tistory.com/335)

**집합**

- c++에서는 swift와 다르게 집합을 직접 구현해주어야 한다. 라이브러리 `set`헤더파일이 존재하지만 사용하기 어렵고, vector로 구현해도 시간 차이는 별로 없다!
- `vector`헤더파일의 erase메소드는 iter를 가리켜주어야하고 iter는 아래와 같이 선언가능하다.

```c++
#include <vector>
vector<int> v;
vector<int>::iterator iter = v.begin();

// i는 지우고 싶은 index
int i = 0;
v.erase(iter + i);
```

**동적 계획법 == 다이나믹 프로그래밍(DP)**

- 동적 계획법에서 어떤 부분 문제는 두 개 이상의 문제를 푸는데 사용될 수 있기 때문에, 이 문제의 답을 여러 번 계산하는 대신 한 번만 계산하고 계산 결과를 재활용함으로써 속도의 향상을 꾀할 수 있습니다. 그러기 위해서는 각 문제의 답을 메모리에 저장해두는데 이 메모리의 장소를 `캐시(cache)`라고 부르며, 두 번 이상 계산되는 부분 문제를 `중복되는 부분 문제(overlapping subproblems)` 라고 한다.

- 동적 계획법 알고리즘에서 가장 유명한 예는 `조합(이항계수)`이다.  n개의 서로 다른 원소 중에서 r개의 원소를 순서없이 골라내는 예이다. 이는 nCr = n-1Cr-1 + n-1Cr 이라는 점화식이 성립하여 캐시를 만들어 저장 가능합니다.

- 위와 같이 함수의 결과를 저장하는 장소를 마련해 두고, 한 번 계산한 값을 저장해 뒀다 재활용하는 최적화 기법을 `메모이제이션`이라고 합니다. 메모이제이션을 적용할 수 있는 경우는 입력값이 같으면 출력도 항상 같은 함수입니다.

- 즉, 점화식 세우기!!!!!!!!!

- 이중배열의 경우도 있습니다. 이중배열일 경우, 어떤 방식으로 세워야 할지 잘 생각해야한다. 한정된 배열을 만들어야 한다. 

  ex) `dp[101][10]`

**그래프 알고리즘**

👉 [자세히](./Graph) : 내일 더 공부..



## 주의할 점❗️

- 항상 수의 범위 체크: 더할 때 int형 범위를 넘기면 long long 써주기

  ex) [GCD 합](https://www.acmicpc.net/problem/9613)

- C++에서 cin 과 cout 은 속도가 굉장히 느리기 때문에 아래의 명령어를 꼭 써주어야한다. 아니면 계속 시간초과가 나오게 될 수 있다.

  ```c++
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ```

  ex) [6588 골드바흐의 추측](https://www.acmicpc.net/problem/6588)

- 알고리즘 문제를 풀 때 먼저 브루트 포스를 생각하고 그 후에 줄이는 방법을 생각해보자

- 함수를 만들면 `return;` 을 해주어야 한다.

- "런타임오류"는 범위를 초과했을 경우에도 생긴다. 아래와 같은 상황을 조심하자.

  ```c++
  bool visited[1000];
  // 맞는 경우
  if (x - 1 >= 0 && visited[x - 1] == false) {}
  // 틀린 경우
  if (visited[x - 1] == false && x - 1 >= 0) {}
  ```

- 출력 값에 큰 수를 나눈 나머지를 구하라는 문제들이 있다.

  <img src="https://user-images.githubusercontent.com/56102421/91835129-ea0fdb00-ec83-11ea-90a2-9da74b20a2eb.png" width="50%"> 

  이런 경우 dp문제인 경우가 많고, 나눈 값을 저장해야 한다. 나오는 모든 결과값을 나누어주자

- 그래프 다루는 문제에서 주의할 점!!!은 가로 세로가 다른 그래프인 경우에 n과 m이 행인지 열인지 헤갈릴 경우가 있다. 조심하자!! 이중배열에서 앞은 무조건 가로줄, 뒤는 무조건 세로줄 

  이런 것때매 헤갈리므로 원래는 테두리를 접근 불가능한 수로 둘러쌓게 만들어줬는데.. 이번엔 안그렇게 해볼라하니까 x,y헤갈려서 헤맴 ㅠ 테두리로 감싸주는 것이 제일 좋은 방법인듯!!



## 