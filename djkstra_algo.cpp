#include <stdio.h>


#define	INFINITE 9999	// �Ÿ��� �ʱⰪ
#define	NUM_VERTICES 7	// ������ ����

// ��������Ʈ ����ü
typedef struct Adjacency
{
	struct Adjacency* link;		// ����
	int vertex;					// ����
	int weight;					// ����
}Adjacency;

// ���� ����Ʈ
Adjacency* Graph_list[NUM_VERTICES];

void initGraph();
void insertEdge(int, int, int);
void ShortestPath(int, int);

void main()
{
	int start, end;
	
	// �׷��� ����.
	initGraph();
	while (100) {
		// ����, ���� �Է�
		printf("���� >> v");
		scanf("%d", &start);
		getchar();
		printf("���� >> v");
		scanf("%d", &end);

		ShortestPath(start - 1, end - 1); // �˰��� ����
	}
	
}

// �׷����� �ʱ�ȭ���ִ� �Լ� - ���� ����ŭ ��������� �Ѵ�.
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
	Adjacency* node;	// ������ ���� ���

	// �ܹ������� ����
	node = (Adjacency*)malloc(sizeof(Adjacency));
	node->vertex = end;
	node->weight = weight;
	node->link = Graph_list[start];
	Graph_list[start] = node;

	
}

void ShortestPath(int start, int end)
{
	int distance[NUM_VERTICES];		// �Ÿ�
	int	pathcnt[NUM_VERTICES];		// ��� ��
	int check[NUM_VERTICES];		// ���� �ȿ� �ִ��� ����
	Adjacency* tmp;					// �ֱٿ� ���� ������ �����ϱ� ���� ����ü ������
	int cycle, min, now, i;			// cycle : �۾� Ƚ��, 
									// min = �ִܰŸ��� ���� �񱳰�, 
	now = 0;					// now : �ֱٿ� ���� ����

	// �ʱ�ȭ ����
	for (i = 0; i < NUM_VERTICES; i++)
	{
		distance[i] = INFINITE;		// �Ÿ��� �������� �ʱ�ȭ
		pathcnt[i] = 0;				// ��μ��� 0���� �ʱ�ȭ
		check[i] = 0;				// PQ�� �ִ��� ������ ���� ( PQ�� ����ִٸ� 0 )
	}
	distance[start] = 0;			// �ʱ� start ���� - �ڽű����� �Ÿ��� 0
	cycle = 0;

	while (cycle < NUM_VERTICES - 1)		// ��� ������ ���� �ϱ� ���ؼ�
	{
		min = INFINITE;		// �ּҰ� �������� �ʱ�ȭ
		for (i = 0; i < NUM_VERTICES; i++)
			if (distance[i] < min && !check[i])		// ���� ���� ���� �� �Ÿ��� �ּ��� �������κ��� ����
			{
				min = distance[i];
				now = i;	// ���濡 ���� ���� ��ġ
			}

		check[now] = 1;			// ���� �ȿ� �ֱ�
		tmp = Graph_list[now];	// ���濡 ���� ���� ������ ����ü ������

		while (tmp != NULL)
		{
			if (!check[tmp->vertex])	// ���� ���� �����̶��
			{
				// ������ �Ÿ� = ���� �ִܰŸ� -- �ٸ� ��θ� ���� ���� �ִܰŸ�
				if (min + tmp->weight == distance[tmp->vertex])
					pathcnt[tmp->vertex] += pathcnt[now];		// �ִܰ�� ���� ����

				//  ������ �Ÿ� < ���� �ִܰŸ� --> ���� ��ȭ
				if (min + tmp->weight < distance[tmp->vertex])
				{
					distance[tmp->vertex] = min + tmp->weight;	// �ִܰŸ� ����
					if (now == start) pathcnt[tmp->vertex] = 1;				// ���� ������������ �������̶�� ��μ� 1
					else			pathcnt[tmp->vertex] = pathcnt[now];	// �� �̿ܿ��� �θ���ġ�� ��μ�
				}
			}	// if
			tmp = tmp->link;	// ���� ���� ����, ���� �˻�
		}	// while

		cycle++;
		if (now == end) break;		// ���� ������ ���� ������ ���ٸ� ����
	}	// while

	printf("v%d, v%d �ִܰŸ� = %d\n", start+1, end+1, distance[end]); // ����� ���
	printf("\n");
}