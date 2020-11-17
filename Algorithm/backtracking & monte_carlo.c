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

	int m = 2; // ����� ������ �ڽ��� ����
	int mprod = 1; // ������ �ڽ��� ������ ���� ���� ����
	int t; // ��� �ڽ� ����
	int numnodes = 1; // �� ����� ����
	int chk = 1; // ���� ����

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
		if (chk == -2) { // �ڽĳ�尡 ��� �����ҽ�,
			if (num) { // ���� �ڽ� �߰�.
				index++;
				weight = weight + w[index];
			}
			else { // ������ �ڽ� �߰�
				index++;
			}
		}
		else if (chk == -1) { // ī�带 ������ ���� ������.
			index++;
			weight = weight + w[index];
		}
		else if (chk == 2) { // ī�带 �������� �������� ������.
			index++;
		}
	}
	return numnodes;

}


int* sorting(int w[]) { 
	// ���ľ˰��� , �������� �ʴ´ٸ� ���� ã�� �� ���°�� �߻�

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

/* ������ �˰���
	1. weight - ���� i ���� ���Ե� ������ weight��
 if weight + w[i+1] > W => �������� ����
	2. total - ���� weight�� �� weight 
 if weight + total < W => ������������
 */
int promising(int index, int weight, int total) {
	return ((weight + total >= W) && (weight == W || weight + w[index + 1] <= W));
}

void sum_of_subsets(int index, int weight, int total) {
	if (promising(index, weight, total)) {
		if (weight == W) {
			printf("\n   [%d] : ", num++);
			for (int j = 0; j < index + 1; j++)
				if (arr[j]) // ��� w���Ҹ� ���
					printf(" w%d(%d) ", j + 1, w[j]);
			printf("\n");
		}
		else {
			arr[index + 1] = 1; // ���� ��� ����
			sum_of_subsets(index + 1, weight + w[index + 1], total - w[index + 1]);
			arr[index + 1] = 0; // ������ ��� ����
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
	printf("��հ� : %d\n", avg / 10);
}
