# 그래프에서 정점끼리의 최단 경로를 구하는 문제

[참고](https://hsp1116.tistory.com/42) 이 블로그를 참고하였다.

- 하나의 정점에서 다른 하나의 정점까지의 최단 경로를 구하는 문제 (single source and single destination shortest path problem)
- 하나의 정점에서 다른 모든 정점까지의 최단 경로를 구하는 문제 (single source shortest path problem)
- 하나의 목적지로 가는 모든 최단 경로를 구하는 문제 (single destinatino shortest path problem)
- 모든 최단 경로르 구하는 문제 (all pairs shortest path problem)





## 다익스트라 알고리즘

위 문제 중 두번째 방법으로, 하나의 정점에서 다른 모든 정점까지의 최단 경로를 구한다. 간선들은 모두 양의 간선들을 가져야 한다.

다익스트라 알고리즘의 기본 로직은, 첫 정점을 기준으로 연결되어있는 정점들을 추가해가며, 최단 거리를 갱신하는 것이다. 정점을 잇기 전까지는 시작점을 제외한 정점들을 모두 무한대 값을 가진다.

