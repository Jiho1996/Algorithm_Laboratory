#include <stdio.h>

typedef struct Node_breadth_first { //노드 정의
	int level;
	int profit;
	int weight;
	struct Node_breadth_first* next;
}node_breadth_first;

typedef struct Queue_breadth { // 큐 구조체 정의
	node_breadth_first* front; //맨앞
	node_breadth_first* rear; // 맨뒤
	int count; // 보관 개수
}Queue_breadth;

void InitQueue_breadth(Queue_breadth* queue) ; // 큐 초기화
int IsEmpty_breadth(Queue_breadth* queue); // 큐 비었는지 확인
void Push_breadth(Queue_breadth *queue, node_breadth_first* data); // 큐에 보관 
node_breadth_first* Pop_breadth(Queue_breadth *queue); //큐에서 꺼냄
		int weightset[] = { 0,2,5,7,3,1 };
		int profitset[] = { 0,20,30,35,12,3 };
		Queue_breadth* breadth_first_queue ; // 아이템 가방에 들었는지 판별
		int promissing[] = {1, 0, 0, 0, 0, 0 };
		int maxprofit = 0;
		int W = 9;

	int bound_breadth (node_breadth_first *node) {
		int result = 0;
		int index;
		int toweight = 0;
		if (node->weight >= W) //무게 초과시
		return 0 ;
		else {
			result - node->profit;
			index = node->level + 1;
			toweight - node->weight;
			while (index <= 5 && toweight + weightset[index] <= W) {
				toweight - toweight + weightset[index];
				result = result + profitset[index];
				index++;
			}
				if (index <= 5) // 쪼개서 최대 무게에 profit을 만들어준다.
					result = result + (W - toweight) * profitset[index] / weightset[index];
				return result;
			}
		}
		void knapsack_breadth_first(node_breadth_first* root) {
			node_breadth_first* Parent_Node; // 부모노드로 변수 초기화
			node_breadth_first* Child_Node; // 자식노드로 변수 초기화
			Parent_Node = (node_breadth_first*)malloc(sizeof(node_breadth_first));
			Child_Node = (node_breadth_first*)malloc(sizeof(node_breadth_first));
			int WEIGHT = 0;
			int level = 0;
			Push_breadth(breadth_first_queue, root); // 뿌리에 큐삽입
			printf("\n\n 0Level \n");
			while (!IsEmpty_breadth(breadth_first_queue)) {
				Parent_Node = Pop_breadth(breadth_first_queue); // 큐에 노드하나dequeue
				if (level < Parent_Node->level) {
					printf("\n\n");
					level++;
					printf("%d level 'n", Parent_Node->level);
				}
				printf(" 노드정보 ; profit = $%2d weight = %2d bound = $%2d \n", Parent_Node->profit, Parent_Node->weight, bound_breadth(Parent_Node));
				Child_Node->level = Parent_Node->level + 1;
				Child_Node->profit = Parent_Node->profit + profitset[Parent_Node->level+1];
				Child_Node->weight = Parent_Node->weight + weightset[Parent_Node->level + 1];

				if ((Child_Node->weight <= W) && (Child_Node->profit > maxprofit))//최대이익갱신
					maxprofit = Child_Node->profit;
				if (bound_breadth(Child_Node) > maxprofit)//유망도검사
					Push_breadth(breadth_first_queue, Child_Node);
			}
			printf("\n\n max profit ; %d \n\n", maxprofit);
		}

		void InitQueue_breath(Queue_breadth* queue) {
			queue->front= queue->rear = NULL; // front rear null로 설정
			queue->count = 0;
		}
		int IsEmpty_breadth(Queue_breadth* queue) {
			return queue->count == 0; // 보관개수 0이면 빈상태
		}
		void Push_breadth(Queue_breadth* queue, node_breadth_first* data) {
			node_breadth_first* now = (node_breadth_first*)malloc(sizeof(node_breadth_first)); //노드생성
			now->profit = data->profit;//데이터설정
			now->weight = data->weight;
			now->level = data->level;
			now->next = NULL;

			if (IsEmpty_breadth(queue)) { // 큐공백
				queue->front = now;
			}
			else
			{
				queue->rear->next = now;
			}
			queue->rear = now;
			queue->count++;
		}

		node_breadth_first* Pop_breadth(Queue_breadth* queue) {
			int re = 0;
			node_breadth_first* now = NULL;
			if (IsEmpty_breadth(queue)) { //큐 공백
				return now;
			}
			now = queue->front; // 맨앞 노드 now에 기억
			queue->front = now->next; // 맨앞은 now다음노드로 설정
			queue->count--;//보관개서 1감소
			return now;
		}

