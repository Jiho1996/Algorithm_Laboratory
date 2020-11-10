#include<stdio.h>
#include<string.h>
#include<math.h>

int w[10][10];
int dp[10];
int n;
int cost = 0;

void input() { // 행과 열 그리고 행렬 전체를 출력하는 함수입니다.
	int i, j;
	printf("travel 도시개수 입력 : "); // tsp알고리즘이므로 행을 도시개수라고 표현했습니다.
	scanf("%d", &n);

	for (i=0;i<n;i++)
	{
		printf("\n---열 element 입력 ---%d행\n", i + 1);
		for (j = 0;j < n;j++)
			scanf("%d", &w[i][j]);

		dp[i] = 0;
	}
	printf("\n\nCost List:"); // 행렬 전체를 출력합니다.

	for (i = 0;i < n;i++) {
		printf("\n");

		for (j=0;j<n;j++)
			printf("\t%d", w[i][j]);

	}
}
void min_cost(int city) {

	/*최단(최적)경로 함수. 
	최단거리를 구하는 함수로,
	node_city에 city값을 1씩 증가시키고
	tsp(city) 값을 대입하여 최단거리를 구현할것입니다.
	*/

	int i,node_city;

		dp[city]=1;
		printf("%d-->",city+1); // 원래 0부터 시작이므로 1을더해줘야한다.
		node_city=tsp(city);
		if (node_city == 999) {
			node_city = 0;
			printf("%d", node_city + 1);
			cost += w[city][node_city]; //cost에 대입함으로써 저장.
			return;
		}
	min_cost(node_city); //min_cost함수를 재실행합니다.
}

int tsp(int c) {

	/*tsp 함수입니다.
	가중치를 저장하는 배열을 구현한 함수로,
	nc, kmin, min을 각각 선언해 w배열에 가중치를 저장시켜줄것입니다.
	*/

	int i, nc = 999;
	int min = 999, kmin;
	
	for (int i = 0;i < n; i++)//n은 행의 개수
	{
		if((w[c][i] !=0)&&(dp[i]==0))
			if (w[c][i] + w[i][c] < min) 
			{
				min = w[i][0] + w[c][i]; 
				kmin = w[c][i];
				nc = i;
			}
	}
	if (min != 999)
		cost += kmin; 
	return nc;
}

int main()
{
	input(); //입력받기

	printf("\n\nPath :\n");
	min_cost(0); //시작점이므로 0삽입합니다.
	printf("\n\n최적 비용 : %d\n", cost);

	return 0;
}