#include <stdio.h>


#define	INFINITE 9999	// 거리의 초기값
#define	NUM_VERTICES 7	// 정점의 개수

// 인접리스트 구조체
typedef struct Adjacency
{
	struct Adjacency* link;		// 연결
	int vertex;					// 정점
	int weight;					// 무게
}Adjacency;

// 인접 리스트
Adjacency* Graph_list[NUM_VERTICES];

void initGraph();
void insertEdge(int, int, int);
void ShortestPath(int, int);

void main()
{
	int start, end;
	
	// 그래프 생성.
	initGraph();
	while (100) {
		// 시점, 종점 입력
		printf("시점 >> v");
		scanf("%d", &start);
		getchar();
		printf("종점 >> v");
		scanf("%d", &end);

		ShortestPath(start - 1, end - 1); // 알고리즘 실행
	}
	
}

// 그래프를 초기화해주는 함수 - 간선 수만큼 연결해줘야 한다.
void initGraph() {
	
	insertEdge(0, 1, 4);	
	insertEdge(0, 5, 10);	

	insertEdge(1, 0, 3);	
	insertEdge(1, 3, 18);	

	insertEdge(2, 1, 6);	
	
	
	insertEdge(3, 1, 5);	
	insertEdge(3, 4, 2);
	insertEdge(3, 6, 5);
	insertEdge(3, 5, 19);

	insertEdge(4, 2, 12);
	insertEdge(4, 3, 1);

	insertEdge(5, 6, 10);

	insertEdge(6, 3, 8);

}

void insertEdge(int start, int end, int weight)
{
	Adjacency* node;	// 연결을 위한 노드

	// 단방향으로 연결
	node = (Adjacency*)malloc(sizeof(Adjacency));
	node->vertex = end;
	node->weight = weight;
	node->link = Graph_list[start];
	Graph_list[start] = node;

	
}

void ShortestPath(int start, int end)
{
	int distance[NUM_VERTICES];		// 거리
	int	pathcnt[NUM_VERTICES];		// 경로 수
	int check[NUM_VERTICES];		// 가방 안에 있는지 여부
	Adjacency* tmp;					// 최근에 들어온 정점을 저장하기 위한 구조체 포인터
	int cycle, min, now, i;			// cycle : 작업 횟수, 
									// min = 최단거리를 위한 비교값, 
	now = 0;					// now : 최근에 들어온 정점

	// 초기화 과정
	for (i = 0; i < NUM_VERTICES; i++)
	{
		distance[i] = INFINITE;		// 거리를 무한으로 초기화
		pathcnt[i] = 0;				// 경로수를 0으로 초기화
		check[i] = 0;				// PQ에 있는지 없는지 여부 ( PQ에 들어있다면 0 )
	}
	distance[start] = 0;			// 초기 start 설정 - 자신까지의 거리는 0
	cycle = 0;

	while (cycle < NUM_VERTICES - 1)		// 모든 정점에 대해 하기 위해서
	{
		min = INFINITE;		// 최소값 무한으로 초기화
		for (i = 0; i < NUM_VERTICES; i++)
			if (distance[i] < min && !check[i])		// 가방 밖의 정점 중 거리가 최소인 정점으로부터 시작
			{
				min = distance[i];
				now = i;	// 가방에 넣을 정점 위치
			}

		check[now] = 1;			// 가방 안에 넣기
		tmp = Graph_list[now];	// 가방에 새로 들어온 정점의 구조체 포인터

		while (tmp != NULL)
		{
			if (!check[tmp->vertex])	// 가방 밖의 정점이라면
			{
				// 수행한 거리 = 기존 최단거리 -- 다른 경로를 통한 같은 최단거리
				if (min + tmp->weight == distance[tmp->vertex])
					pathcnt[tmp->vertex] += pathcnt[now];		// 최단경로 개수 증가

				//  수행한 거리 < 기존 최단거리 --> 간선 완화
				if (min + tmp->weight < distance[tmp->vertex])
				{
					distance[tmp->vertex] = min + tmp->weight;	// 최단거리 갱신
					if (now == start) pathcnt[tmp->vertex] = 1;				// 만약 시작점에서의 연결점이라면 경로수 1
					else			pathcnt[tmp->vertex] = pathcnt[now];	// 그 이외에는 부모위치의 경로수
				}
			}	// if
			tmp = tmp->link;	// 다음 인접 정점, 간선 검사
		}	// while

		cycle++;
		if (now == end) break;		// 현재 정점이 도착 정점과 같다면 종료
	}	// while

	printf("v%d, v%d 최단거리 = %d\n", start+1, end+1, distance[end]); // 결과물 출력
	printf("\n");
}