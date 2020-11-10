#include <stdio.h>

#include <stdlib.h>

#define Count_Vertice 7

#define INF 1000



int W[Count_Vertice][Count_Vertice] = {

	// W[i][j]�� i���� j������ ����Ÿ�, Far_distance�� ū ���� �ٷ� �� �� ���� ��츦 ǥ�� 

  {0,4,INF,INF,INF,10,INF},
  {3,0,INF,18,INF,INF,INF},
  {INF,6,0,INF,INF,INF,INF},
  {INF,5,15,0,2,19,5},
  {INF,INF,12,1,0,INF,INF},
  {INF,INF,INF,INF,INF,0,10},
  {INF,INF,INF,8,INF,INF,0}

};
int D[Count_Vertice][Count_Vertice];	// D[i][j]�� i���� j���� ���� �ּ� �Ÿ��� ���� 

int P[Count_Vertice][Count_Vertice];	// P[i][j]�� i���� j���� ���� �� ��ġ�� �ְ� ���� ������ ���� 



void Floyd() {

	int i, j, k;

	for (i = 0; i < Count_Vertice; i++)	// �迭 �ʱ�ȭ 

		for (j = 0; j < Count_Vertice; j++) {

			P[i][j] = -1;

			D[i][j] = W[i][j];

		}

	for (k = 0; k < Count_Vertice; k++)

		for (i = 0; i < Count_Vertice; i++)

			for (j = 0; j < Count_Vertice; j++)

				if (D[i][j] > D[i][k] + D[k][j]) {

					/* k�� ��ĥ �� D[i][j]�� �� ª������ ��� */

					D[i][j] = D[i][k] + D[k][j];

					P[i][j] = k;

				}

}



int main(int argc, char* argv[]) {

	Floyd();

	int a, b;

	/*	printf("������� �������� �Է��Ͻÿ�. (1 ~ %d)\n", Count_Vertice );

		scanf("%d %d", &a, &b);*/
	printf("\n* ��� N : \n");
	for (int i = 0; i < Count_Vertice;i++) {
		printf("\n");
		for (int j = 0; j < Count_Vertice; j++) {
			printf("%3d ", D[i][j]);
		}

	}

	printf("\n\n");
	printf("* ��� P: \n");
	for (int i = 0; i < Count_Vertice;i++) {
		printf("\n");
		for (int j = 0; j < Count_Vertice; j++) {
			printf("%3d ", P[i][j]+1);
		}
	}
	printf("\n\n");

	printf("v3���� v6���� ���� �ִܰŸ� ��δ� %d �̴�.", D[2][5]);
	printf("\n");
}



