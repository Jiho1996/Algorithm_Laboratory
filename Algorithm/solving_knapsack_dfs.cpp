#include<stdio.h>
int weightset[] = { 0, 2,5,7,3,1 };
int profitset[] = { 0,20,30,35,12,3 };
//ITEM이 가방에 들어있는지 판별기준
int include[] = { 1 , 0 , 0 , 0 , 0 , 0 };
int bestset[] = { 0, 0, 0, 0, 0, 0 };
int maxprofit = 0;
int W = 9;

_Bool promissing_depth_first(int index, int profit, int weight) {
	int j, k;
	int bound, toweight;
	if (weight >= W)
		return 0;
	else {
		j = index + 1;
		bound = profit;
		toweight = weight;
		// 무게가 가득찰때까지 남은 ITEM을 넣어줌.

		while ((j <= 5) && (toweight + weightset[j] <= W)) {
			toweight += weightset[j];
			bound = bound + profitset[j];
			j++;
		}
		k = j;
		// 다음 아이템을 쪼개서 최대로 넣어줌.
		if (k <= 5)
			bound += (W - toweight) * profitset[k] / weightset[k];
		return bound > maxprofit;
	}
}

void knapsack_depth_first(int index, int profit, int weight) {
	if (weight <= W && profit > maxprofit) {
		maxprofit = profit;
		for (int i = 0;i < 6;i++)
			bestset[i] = include[i]; // 가장 최대의 profit를 가진 노드의 정보 저장

	}
	if (promissing_depth_first(index, profit, weight)) {
		include[index + 1] = 1; // 다음item넣음
		knapsack_depth_first(index + 1, profit + profitset[index + 1], weight + weightset[index + 1]);
		include[index + 1] = 0;// 다음 item 안넣음.
		knapsack_depth_first(index + 1, profit, weight);
	}

}

