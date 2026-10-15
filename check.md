HW09 - 7번 확인: 각 정점 쌍의 실제 최단경로 출력 여부

[확인 항목] 서로 다른 두 정점으로 이루어진 모든 정점 쌍에 대해 실제
최단경로와 최단거리가 출력되는가?

[실행 결과] 프로그램은 정점 10개(0~9)에 대해 서로 다른 정점 쌍 45개의
경로와 거리를 모두 출력했다. 출력 마지막 부분에서 다음 결과를 확인했다.

Total vertex pairs : 45
Valid paths : 45
Errors : 0
Result : ALL 45 PATHS PASSED

[45개 정점 쌍의 최단경로 및 거리]
Graph
Vertices : 10
Edges : 20

Edges
Edge Weight
(0, 1) 66
(1, 2) 54
(1, 3) 55
(3, 4) 17
(3, 5) 49
(2, 6) 89
(4, 7) 33
(3, 8) 48
(1, 9) 75
(2, 4) 58
(6, 3) 35
(8, 6) 47
(6, 9) 46
(3, 7) 3
(5, 4) 74
(2, 5) 27
(3, 9) 94
(9, 4) 90
(9, 5) 81
(7, 2) 79

========== Shortest Paths ==========

0 -> 1
Path : 0 -> 1
Distance : 66

0 -> 2
Path : 0 -> 1 -> 2
Distance : 120

0 -> 3
Path : 0 -> 1 -> 3
Distance : 121

0 -> 4
Path : 0 -> 1 -> 3 -> 4
Distance : 138

0 -> 5
Path : 0 -> 1 -> 2 -> 5
Distance : 147

0 -> 6
Path : 0 -> 1 -> 3 -> 6
Distance : 156

0 -> 7
Path : 0 -> 1 -> 3 -> 7
Distance : 124

0 -> 8
Path : 0 -> 1 -> 3 -> 8
Distance : 169

0 -> 9
Path : 0 -> 1 -> 9
Distance : 141

1 -> 2
Path : 1 -> 2
Distance : 54

1 -> 3
Path : 1 -> 3
Distance : 55

1 -> 4
Path : 1 -> 3 -> 4
Distance : 72

1 -> 5
Path : 1 -> 2 -> 5
Distance : 81

1 -> 6
Path : 1 -> 3 -> 6
Distance : 90

1 -> 7
Path : 1 -> 3 -> 7
Distance : 58

1 -> 8
Path : 1 -> 3 -> 8
Distance : 103

1 -> 9
Path : 1 -> 9
Distance : 75

2 -> 3
Path : 2 -> 4 -> 3
Distance : 75

2 -> 4
Path : 2 -> 4
Distance : 58

2 -> 5
Path : 2 -> 5
Distance : 27

2 -> 6
Path : 2 -> 6
Distance : 89

2 -> 7
Path : 2 -> 4 -> 3 -> 7
Distance : 78

2 -> 8
Path : 2 -> 4 -> 3 -> 8
Distance : 123

2 -> 9
Path : 2 -> 5 -> 9
Distance : 108

3 -> 4
Path : 3 -> 4
Distance : 17

3 -> 5
Path : 3 -> 5
Distance : 49

3 -> 6
Path : 3 -> 6
Distance : 35

3 -> 7
Path : 3 -> 7
Distance : 3

3 -> 8
Path : 3 -> 8
Distance : 48

3 -> 9
Path : 3 -> 6 -> 9
Distance : 81

4 -> 5
Path : 4 -> 3 -> 5
Distance : 66

4 -> 6
Path : 4 -> 3 -> 6
Distance : 52

4 -> 7
Path : 4 -> 3 -> 7
Distance : 20

4 -> 8
Path : 4 -> 3 -> 8
Distance : 65

4 -> 9
Path : 4 -> 9
Distance : 90

5 -> 6
Path : 5 -> 3 -> 6
Distance : 84

5 -> 7
Path : 5 -> 3 -> 7
Distance : 52

5 -> 8
Path : 5 -> 3 -> 8
Distance : 97

5 -> 9
Path : 5 -> 9
Distance : 81

6 -> 7
Path : 6 -> 3 -> 7
Distance : 38

6 -> 8
Path : 6 -> 8
Distance : 47

6 -> 9
Path : 6 -> 9
Distance : 46

7 -> 8
Path : 7 -> 3 -> 8
Distance : 51

7 -> 9
Path : 7 -> 3 -> 6 -> 9
Distance : 84

8 -> 9
Path : 8 -> 6 -> 9
Distance : 93

Total vertex pairs : 45

========== Graph Verification ==========
Vertices : 10
Edges : 20 (expected 20)
Self-loop : 0
Asymmetric : 0
Invalid weights : 0
Connected : Yes
Result : GRAPH VALID

========== Verification ==========
Valid paths : 45
Errors : 0
Result : ALL 45 PATHS PASSED

[결론] 실행 결과에서 서로 다른 정점 쌍 45개 모두에 대해 경로와 거리가
출력되었다. 또한 경로 검증 결과 Valid paths가 45이고 Errors가 0이므로,
출력된 각 경로의 간선 연결과 가중치 합이 계산된 거리와 일치함을
확인했다.

주의: 이 검증 결과만으로 최단거리의 최적성이 독립적으로 증명되는 것은
아니다. 최단거리 계산은 Floyd-Warshall 알고리즘의 결과를 사용한다.
