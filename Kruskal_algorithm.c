#include <stdio.h>

#define MAX 30

typedef struct edge {
    int u, v, w; // u와 v는 vertex, w는 가중치.
} edge;

typedef struct edge_list {
    edge data[MAX];
    int n;
} edge_list;

edge_list elist;

int Graph[MAX][MAX], n;
edge_list spanlist;

void kruskalAlgo();
int find(int a[], int vertexno);
void Union(int a[], int c1, int c2);
void sort();
void print();

// kruskal알고리즘 선언.
void kruskalAlgo() {

    // 가장낮은 weigh - 가장높은 weigh 모든 edge 정렬.
    // 가장낮은 무게로 edge를 잡고 spanning tree 계속해서 추가
    // 모든 정점에 도달할때까지 edge 계속 추가.
    int a[MAX], i, j, cno1, cno2;
    elist.n = 0;

    for (i = 1; i < n; i++)
        for (j = 0; j < i; j++) {
            if (Graph[i][j] != 0) {
                elist.data[elist.n].u = i;
                elist.data[elist.n].v = j;
                elist.data[elist.n].w = Graph[i][j];
                elist.n++;
            }
        }

    sort();

    for (i = 0; i < n; i++)
        a[i] = i;

    spanlist.n = 0;

    for (i = 0; i < elist.n; i++) {
        cno1 = find(a, elist.data[i].u);
        cno2 = find(a, elist.data[i].v);

        if (cno1 != cno2) {
            spanlist.data[spanlist.n] = elist.data[i];
            spanlist.n = spanlist.n + 1;
            Union(a, cno1, cno2);
        }
    }
}
//Union과 find알고리즘을 통해 두정점이 동일한 cluster에 속하는지 여부를 확인하고
// 그에 따라 edge를 추가.
int find(int a[], int vertexno) {
    return (a[vertexno]);
}

void Union(int a[], int c1, int c2) {
    int i;

    for (i = 0; i < n; i++)
        if (a[i] == c2)
            a[i] = c1;
}

// Sorting 알고리즘
void sort() {
    int i, j;
    edge temp;

    for (i = 1; i < elist.n; i++)
        for (j = 0; j < elist.n - 1; j++)
            if (elist.data[j].w > elist.data[j + 1].w) {
                temp = elist.data[j];
                elist.data[j] = elist.data[j + 1];
                elist.data[j + 1] = temp;
            }
}

// 결과 출력.
void print() {
    int i, cost = 0;

    for (i = 0; i < spanlist.n; i++) {
        printf("\n%d - %d : %d", spanlist.data[i].u, spanlist.data[i].v, spanlist.data[i].w);
        cost = cost + spanlist.data[i].w;
    }

    printf("\n가중치 합: %d\n", cost);
}

int main() {
    int i, j, total_cost;

    n = 9;
    //그래프 설정
    Graph[1][1] = 0;
    Graph[1][2] = 11;
    Graph[1][3] = 9;
    Graph[1][4] = 8;
    Graph[1][5] = 0;
    Graph[1][6] = 0;
    Graph[1][7] = 0;
    Graph[1][8] = 0;
    Graph[1][9] = 0;

    Graph[2][1] = 11;
    Graph[2][2] = 0;
    Graph[2][3] = 3;
    Graph[2][4] = 0;
    Graph[2][5] = 8;
    Graph[2][6] = 0;
    Graph[2][7] = 0;
    Graph[2][8] = 0;
    Graph[2][9] = 0;

    Graph[3][1] = 9;
    Graph[3][2] = 3;
    Graph[3][3] = 0;
    Graph[3][4] = 15;
    Graph[3][5] = 0;
    Graph[3][6] = 12;
    Graph[3][7] = 1;
    Graph[3][8] = 0;
    Graph[3][9] = 0;

    Graph[4][1] = 8;
    Graph[4][2] = 0;
    Graph[4][3] = 15;
    Graph[4][4] = 0;
    Graph[4][5] = 0;
    Graph[4][6] = 0;
    Graph[4][7] = 10;
    Graph[4][8] = 0;
    Graph[4][9] = 0;

    Graph[5][1] = 0;
    Graph[5][2] = 8;
    Graph[5][3] = 0;
    Graph[5][4] = 0;
    Graph[5][5] = 0;
    Graph[5][6] = 7;
    Graph[5][7] = 0;
    Graph[5][8] = 4;
    Graph[5][9] = 0;

    Graph[6][1] = 0;
    Graph[6][2] = 8;
    Graph[6][3] = 12;
    Graph[6][4] = 0;
    Graph[6][5] = 7;
    Graph[6][6] = 0;
    Graph[6][7] = 0;
    Graph[6][8] = 5;
    Graph[6][9] = 0;

    Graph[7][1] = 0;
    Graph[7][2] = 0;
    Graph[7][3] = 1;
    Graph[7][4] = 10;
    Graph[7][5] = 0;
    Graph[7][6] = 0;
    Graph[7][7] = 0;
    Graph[7][8] = 2;
    Graph[7][9] = 0;

    Graph[8][1] = 0;
    Graph[8][2] = 0;
    Graph[8][3] = 0;
    Graph[8][4] = 0;
    Graph[8][5] = 4;
    Graph[8][6] = 5;
    Graph[8][7] = 2;
    Graph[8][8] = 0;
    Graph[8][9] = 0;

    kruskalAlgo();
    print();
}