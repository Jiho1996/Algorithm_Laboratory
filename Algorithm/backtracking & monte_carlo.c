#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
#include<time.h>

int w[6] = { 2, 10, 13, 17, 22, 42 }; 
int arr[6] = { 0, 0, 0, 0, 0, 0 };
int W;
int total;
int num = 1;


int estimate_sum_of_subsets(int index, int weight, int total) {

	int m = 2; // 노드의 유망한 자식의 개수
	int mprod = 1; // 유망한 자식의 개수의 곱을 갖는 변수
	int t; // 노드 자식 개수
	int numnodes = 1; // 총 노드의 개수
	int chk = 1; // 정보 저장

	while (m != 0) {
		m = 0;
		chk = 1;

		weight = weight + w[index + 1];
		total = total - w[index + 1];
		if (promising(index + 1, weight, total)) {
			m++;
			chk = chk * -1;
		}
		weight = weight - w[index + 1];
		if (promising(index + 1, weight, total)) {
			m++;
			chk = chk * 2;
		}
		mprod = mprod * m;
		numnodes = numnodes + mprod * 2;
		num = rand() % 2;
		if (chk == -2) { // 자식노드가 모두 유망할시,
			if (num) { // 왼쪽 자식 추가.
				index++;
				weight = weight + w[index];
			}
			else { // 오른쪽 자식 추가
				index++;
			}
		}
		else if (chk == -1) { // 카드를 포함할 때만 유망함.
			index++;
			weight = weight + w[index];
		}
		else if (chk == 2) { // 카드를 포함하지 않을때만 유망함.
			index++;
		}
	}
	return numnodes;

}


int* sorting(int w[]) { 
	// 정렬알고리즘 , 정렬하지 않는다면 답을 찾을 수 없는경우 발생

	int* sorted_W = (int*)malloc(sizeof(int) * 6);
	int temp;
	for (int i=0; i<5; i++)
		for (int j =1; j<6;j++)
			if (w[i] > w[j]) {
				temp = w[i];
				w[i] = w[j];
				w[j] = temp;
			}
	return sorted_W;
}

/* 되추적 알고리즘
	1. weight - 수준 i 까지 포함된 노드들의 weight합
 if weight + w[i+1] > W => 유망하지 않음
	2. total - 남은 weight의 총 weight 
 if weight + total < W => 유망하지않음
 */
int promising(int index, int weight, int total) {
	return ((weight + total >= W) && (weight == W || weight + w[index + 1] <= W));
}

void sum_of_subsets(int index, int weight, int total) {
	if (promising(index, weight, total)) {
		if (weight == W) {
			printf("\n   [%d] : ", num++);
			for (int j = 0; j < index + 1; j++)
				if (arr[j]) // 모든 w원소를 출력
					printf(" w%d(%d) ", j + 1, w[j]);
			printf("\n");
		}
		else {
			arr[index + 1] = 1; // 왼쪽 노드 생성
			sum_of_subsets(index + 1, weight + w[index + 1], total - w[index + 1]);
			arr[index + 1] = 0; // 오른쪽 노드 생성
			sum_of_subsets(index + 1, weight, total - w[index + 1]);
		}
	}
}

int main() {
	W = 52;
	int avg = 0;
	int mon[10];
	printf("\n\n");

	for (int i = 0; i < 6; i++) {
		printf("w[%d] = %d ", i + 1, w[i]);
		total += w[i];
	}
	printf("\n\n");
	printf(" Total = %d   W = 52   \n\n", total);
	sum_of_subsets(-1, 0, total);
	printf("\n\n");

	for (int i = 0; i < 10;i++) {
		printf("%d\n" ,mon[i]= estimate_sum_of_subsets(-1, 0, total));
		avg += mon[i];
	}
	printf("평균값 : %d\n", avg / 10);
}
