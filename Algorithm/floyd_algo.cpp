#include <stdio.h>

#include <stdlib.h>

#define Count_Vertice 7

#define INF 1000



int W[Count_Vertice][Count_Vertice] = {

	// W[i][j]는 i에서 j까지의 직행거리, Far_distance란 큰 수는 바로 갈 수 없는 경우를 표시 

  {0,4,INF,INF,INF,10,INF},
  {3,0,INF,18,INF,INF,INF},
  {INF,6,0,INF,INF,INF,INF},
  {INF,5,15,0,2,19,5},
  {INF,INF,12,1,0,INF,INF},
  {INF,INF,INF,INF,INF,0,10},
  {INF,INF,INF,8,INF,INF,0}

};
int D[Count_Vertice][Count_Vertice];	// D[i][j]는 i에서 j까지 가는 최소 거리를 저장 

int P[Count_Vertice][Count_Vertice];	// P[i][j]는 i에서 j까지 가는 데 거치는 최고 차수 정점을 저장 



void Floyd() {

	int i, j, k;

	for (i = 0; i < Count_Vertice; i++)	// 배열 초기화 

		for (j = 0; j < Count_Vertice; j++) {

			P[i][j] = -1;

			D[i][j] = W[i][j];

		}

	for (k = 0; k < Count_Vertice; k++)

		for (i = 0; i < Count_Vertice; i++)

			for (j = 0; j < Count_Vertice; j++)

				if (D[i][j] > D[i][k] + D[k][j]) {

					/* k를 거칠 시 D[i][j]가 더 짧아지는 경우 */

					D[i][j] = D[i][k] + D[k][j];

					P[i][j] = k;

				}

}



int main(int argc, char* argv[]) {

	Floyd();

	int a, b;

	/*	printf("출발점과 도착점을 입력하시오. (1 ~ %d)\n", Count_Vertice );

		scanf("%d %d", &a, &b);*/
	printf("\n* 행렬 N : \n");
	for (int i = 0; i < Count_Vertice;i++) {
		printf("\n");
		for (int j = 0; j < Count_Vertice; j++) {
			printf("%3d ", D[i][j]);
		}

	}

	printf("\n\n");
	printf("* 행렬 P: \n");
	for (int i = 0; i < Count_Vertice;i++) {
		printf("\n");
		for (int j = 0; j < Count_Vertice; j++) {
			printf("%3d ", P[i][j]+1);
		}
	}
	printf("\n\n");

	printf("v3에서 v6으로 가는 최단거리 경로는 %d 이다.", D[2][5]);
	printf("\n");
}



