#include<stdio.h>
#include<string.h>
#include<math.h>

int w[10][10];
int dp[10];
int n;
int cost = 0;

void input() { // ��� �� �׸��� ��� ��ü�� ����ϴ� �Լ��Դϴ�.
	int i, j;
	printf("travel ���ð��� �Է� : "); // tsp�˰����̹Ƿ� ���� ���ð������ ǥ���߽��ϴ�.
	scanf("%d", &n);

	for (i=0;i<n;i++)
	{
		printf("\n---�� element �Է� ---%d��\n", i + 1);
		for (j = 0;j < n;j++)
			scanf("%d", &w[i][j]);

		dp[i] = 0;
	}
	printf("\n\nCost List:"); // ��� ��ü�� ����մϴ�.

	for (i = 0;i < n;i++) {
		printf("\n");

		for (j=0;j<n;j++)
			printf("\t%d", w[i][j]);

	}
}
void min_cost(int city) {

	/*�ִ�(����)��� �Լ�. 
	�ִܰŸ��� ���ϴ� �Լ���,
	node_city�� city���� 1�� ������Ű��
	tsp(city) ���� �����Ͽ� �ִܰŸ��� �����Ұ��Դϴ�.
	*/

	int i,node_city;

		dp[city]=1;
		printf("%d-->",city+1); // ���� 0���� �����̹Ƿ� 1����������Ѵ�.
		node_city=tsp(city);
		if (node_city == 999) {
			node_city = 0;
			printf("%d", node_city + 1);
			cost += w[city][node_city]; //cost�� ���������ν� ����.
			return;
		}
	min_cost(node_city); //min_cost�Լ��� ������մϴ�.
}

int tsp(int c) {

	/*tsp �Լ��Դϴ�.
	����ġ�� �����ϴ� �迭�� ������ �Լ���,
	nc, kmin, min�� ���� ������ w�迭�� ����ġ�� ��������ٰ��Դϴ�.
	*/

	int i, nc = 999;
	int min = 999, kmin;
	
	for (int i = 0;i < n; i++)//n�� ���� ����
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
	input(); //�Է¹ޱ�

	printf("\n\nPath :\n");
	min_cost(0); //�������̹Ƿ� 0�����մϴ�.
	printf("\n\n���� ��� : %d\n", cost);

	return 0;
}