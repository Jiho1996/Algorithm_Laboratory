
#include<stdio.h>
#include<stdbool.h> 

#define INF 9999999

// 그래프의 정점 수
#define V 8


// 8x8그래프 생성

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
    int no_edge;  // edge의 갯수

    // 선택한 정점을 추적하는 배열 선택하지않을시 거짓으로 처리
    int selected[V];

    // seleceted, false 초기화
    memset(selected, false, sizeof(selected));

    // edge수를 0으로 설정
    no_edge = 0;

    // MST의 edge수는 항상 v-1보다 작다.
    

    //0번째 정점 선택하고 true.
    selected[0] = true;

    int x;  //  행번호
    int y;  //  열번호

    // edge와 weigh print
    printf("Edge : Weight\n");

    while (no_edge < V - 1) {
        //1단계에서 선택한 정점으로 부터 거리 계산한다.
        int min = INF;
        x = 0;
        y = 0;

        for (int i = 0; i < V; i++) {
            if (selected[i]) {
                for (int j = 0; j < V; j++) {
                    if (!selected[j] && G[i][j]) {  // 선택x, edge 존재.
                        if (min > G[i][j]) {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        printf("%d - %d : %d\n", x+1, y+1, G[x][y]); //출력
        selected[y] = true;
        no_edge++;
        weigh = weigh + G[x][y]; // weigh합 계산
    }
    printf("\n가중치의 합 : %d", weigh);

    return 0;
}