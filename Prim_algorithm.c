
#include<stdio.h>
#include<stdbool.h> 

#define INF 9999999

// �׷����� ���� ��
#define V 8


// 8x8�׷��� ����

int G[V][V] = {
                { 0, 11, 9, 8,, 0, 0, 0 },
                { 11, 0, 3, 0, 8, 8, 0, 0 },
                { 9, 3, 0, 15, 0, 12, 1, 0 },
                { 8, 0, 15, 0, 0, 0, 10, 0 },
                { 0, 8, 0, 0, 0, 7, 0, 4 },
                {0, 8, 12, 0, 7, 0, 0, 5},
                {0, 0, 1, 10, 0, 0, 0, 2},
                {0, 0, 0, 0, 4, 5, 2, 0} };

int main() {
    int weigh = 0;
    int no_edge;  // edge�� ����

    // ������ ������ �����ϴ� �迭 �������������� �������� ó��
    int selected[V];

    // seleceted, false �ʱ�ȭ
    memset(selected, false, sizeof(selected));

    // edge���� 0���� ����
    no_edge = 0;

    // MST�� edge���� �׻� v-1���� �۴�.
    

    //0��° ���� �����ϰ� true.
    selected[0] = true;

    int x;  //  ���ȣ
    int y;  //  ����ȣ

    // edge�� weigh print
    printf("Edge : Weight\n");

    while (no_edge < V - 1) {
        //1�ܰ迡�� ������ �������� ���� �Ÿ� ����Ѵ�.
        int min = INF;
        x = 0;
        y = 0;

        for (int i = 0; i < V; i++) {
            if (selected[i]) {
                for (int j = 0; j < V; j++) {
                    if (!selected[j] && G[i][j]) {  // ����x, edge ����.
                        if (min > G[i][j]) {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        printf("%d - %d : %d\n", x+1, y+1, G[x][y]); //���
        selected[y] = true;
        no_edge++;
        weigh = weigh + G[x][y]; // weigh�� ���
    }
    printf("\n����ġ�� �� : %d", weigh);

    return 0;
}