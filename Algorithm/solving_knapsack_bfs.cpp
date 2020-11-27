#include <stdio.h>

typedef struct Node_breadth_first { //��� ����
	int level;
	int profit;
	int weight;
	struct Node_breadth_first* next;
}node_breadth_first;

typedef struct Queue_breadth { // ť ����ü ����
	node_breadth_first* front; //�Ǿ�
	node_breadth_first* rear; // �ǵ�
	int count; // ���� ����
}Queue_breadth;

void InitQueue_breadth(Queue_breadth* queue) ; // ť �ʱ�ȭ
int IsEmpty_breadth(Queue_breadth* queue); // ť ������� Ȯ��
void Push_breadth(Queue_breadth *queue, node_breadth_first* data); // ť�� ���� 
node_breadth_first* Pop_breadth(Queue_breadth *queue); //ť���� ����
		int weightset[] = { 0,2,5,7,3,1 };
		int profitset[] = { 0,20,30,35,12,3 };
		Queue_breadth* breadth_first_queue ; // ������ ���濡 ������� �Ǻ�
		int promissing[] = {1, 0, 0, 0, 0, 0 };
		int maxprofit = 0;
		int W = 9;

	int bound_breadth (node_breadth_first *node) {
		int result = 0;
		int index;
		int toweight = 0;
		if (node->weight >= W) //���� �ʰ���
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
				if (index <= 5) // �ɰ��� �ִ� ���Կ� profit�� ������ش�.
					result = result + (W - toweight) * profitset[index] / weightset[index];
				return result;
			}
		}
		void knapsack_breadth_first(node_breadth_first* root) {
			node_breadth_first* Parent_Node; // �θ���� ���� �ʱ�ȭ
			node_breadth_first* Child_Node; // �ڽĳ��� ���� �ʱ�ȭ
			Parent_Node = (node_breadth_first*)malloc(sizeof(node_breadth_first));
			Child_Node = (node_breadth_first*)malloc(sizeof(node_breadth_first));
			int WEIGHT = 0;
			int level = 0;
			Push_breadth(breadth_first_queue, root); // �Ѹ��� ť����
			printf("\n\n 0Level \n");
			while (!IsEmpty_breadth(breadth_first_queue)) {
				Parent_Node = Pop_breadth(breadth_first_queue); // ť�� ����ϳ�dequeue
				if (level < Parent_Node->level) {
					printf("\n\n");
					level++;
					printf("%d level 'n", Parent_Node->level);
				}
				printf(" ������� ; profit = $%2d weight = %2d bound = $%2d \n", Parent_Node->profit, Parent_Node->weight, bound_breadth(Parent_Node));
				Child_Node->level = Parent_Node->level + 1;
				Child_Node->profit = Parent_Node->profit + profitset[Parent_Node->level+1];
				Child_Node->weight = Parent_Node->weight + weightset[Parent_Node->level + 1];

				if ((Child_Node->weight <= W) && (Child_Node->profit > maxprofit))//�ִ����Ͱ���
					maxprofit = Child_Node->profit;
				if (bound_breadth(Child_Node) > maxprofit)//�������˻�
					Push_breadth(breadth_first_queue, Child_Node);
			}
			printf("\n\n max profit ; %d \n\n", maxprofit);
		}

		void InitQueue_breath(Queue_breadth* queue) {
			queue->front= queue->rear = NULL; // front rear null�� ����
			queue->count = 0;
		}
		int IsEmpty_breadth(Queue_breadth* queue) {
			return queue->count == 0; // �������� 0�̸� �����
		}
		void Push_breadth(Queue_breadth* queue, node_breadth_first* data) {
			node_breadth_first* now = (node_breadth_first*)malloc(sizeof(node_breadth_first)); //������
			now->profit = data->profit;//�����ͼ���
			now->weight = data->weight;
			now->level = data->level;
			now->next = NULL;

			if (IsEmpty_breadth(queue)) { // ť����
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
			if (IsEmpty_breadth(queue)) { //ť ����
				return now;
			}
			now = queue->front; // �Ǿ� ��� now�� ���
			queue->front = now->next; // �Ǿ��� now�������� ����
			queue->count--;//�������� 1����
			return now;
		}

