# 그래프에서 정점끼리의 최단 경로를 구하는 문제

[참고](https://hsp1116.tistory.com/42) 이 블로그를 참고하였다.

- 하나의 정점에서 다른 하나의 정점까지의 최단 경로를 구하는 문제 (single source and single destination shortest path problem)
- 하나의 정점에서 다른 모든 정점까지의 최단 경로를 구하는 문제 (single source shortest path problem)
- 하나의 목적지로 가는 모든 최단 경로를 구하는 문제 (single destinatino shortest path problem)
- 모든 최단 경로르 구하는 문제 (all pairs shortest path problem)



**그래프**

- 대개 선형으로 구성하기 어려운 계층 구조를 트리 자료구조를 이용한다. 여기서 더 나아가 그래프는 계층적인 구조보다 좀더 일반적이고 강력한 자료구조이다.

- 두가지로 구현 가능하다.

  인접 리스트 표현

  ```c++
  vector<list<int>> adjacent;
  ```

  가중치 등 간선이 추가적인 속성을 가지고 싶을 때엔 구조체를 만들거나 pair<int,int> 를 사용해준다.

  ```c++
  struct Edge {
  	int vertex; // 간선의 반대쪽 끝 점 번호
  	int weight; // 간선의 가중치
  }
  ```

  인접 행렬 표현

  ```c++
  vector<vector<bool>> adjacent;
  ```

  가중치 등 간선이 추가적인 속성을 가지고 싶을 때엔 int형으로 바꾸어 가중치 값을 저장한다.

**그래프 탐색 문제**

- DFS는 stack, BFS는 queue를 이용한다.
- ***최단거리문제***: 최단 거리 문제는 DFS로 할 수 없습니다. 각 칸에 처음으로 도달한 순간이 가장 빠르게 도달한 경로라는 보장이 없기 때문에 매번 재방문을 해야 하는데, 이것이 반복되면 시간 복잡도가 지수 형태가 되어 너무 오래 걸리게 됩니다.



## 다익스트라 알고리즘

위 문제 중 두번째 방법으로, 하나의 정점에서 다른 모든 정점까지의 최단 경로를 구한다. 간선들은 모두 양의 간선들을 가져야 한다.

다익스트라 알고리즘의 기본 로직은, 첫 정점을 기준으로 연결되어있는 정점들을 추가해가며, 최단 거리를 갱신하는 것이다. 정점을 잇기 전까지는 시작점을 제외한 정점들을 모두 무한대 값을 가진다.

❗️다익스트라 알고리즘을 아직 다 공부하진 않았지만 visited[]배열이 따로 필요하지 않는다!!! 왜냐면 모든 정점까지의 최단 경로를 구하므로 하나의 정점에서 멀어질수록 distance배열의 크기는 커질 것이고(거리가 머니까) 그 distance배열의 크기를 비교하여 너비우선탐색을 하므로 이전 노드를 다시 조사하지 않는다!! 여기서 중요한 점은 조사할 노드를 다시 queue에 push하는 코드를 distance배열을 갱신하는 코드 밑에 두어야한다!