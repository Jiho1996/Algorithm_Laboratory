#include<stdio.h>

#define size 8

int arr[size];


void init() //�� �ʱ�ȭ �Լ�
{
    int i;
    for (i = 0; i < 13; i++)
        arr[i] = 0; // null���� 0���� ä���.
}

void insert(int value) // ��������� �Լ�
{
    int key = value % 13; //mod13�̴�.

    if (arr[key] == 0) //���� ������� �ʴٸ�,
    {
        arr[key] = value; //�״�� ���� value�� ����
    }
    else
    {   
        for (int a = 1; a < 13;a++) { // ���� ����ִٸ�
            if (arr[key + a] == 0) { // ���� ĭ�� ���� 0�̶��,
                arr[key + a] = value; // ���� ĭ�� ���� value�� ����
                break;
            }
            else
                continue; //  // �ƴ϶�� ��� continue
        }
  
    }
}

void qinsert(int value) //������ �����
{
    int key = value % 13; // mod13

    if (arr[key] == 0)
    {
        arr[key] = value;
    }
    else
    {
        for (int a = 1; a < 13;a++) {
            if (arr[key + a * a] == 0) { // ������ ������̹Ƿ� ������������� ����� �����ϰ� �����ȴ�.
                arr[key + a * a] = value;
                break;
            }
            else
                continue;
        }
        
    }
}


void print() //�迭 ����Լ�.
{
    int i;
    for (i = 0; i < 13; i++)
        printf("arr[%d] = %d\n", i, arr[i]);
}

int main()
{
    init(); // �� �ʱ�ȭ �Լ�

    insert(10); 
    insert(20);  
    insert(30);  
    insert(40);  
    insert(33);
    insert(46);
    insert(50);
    insert(60);
    print();

    printf("\n\n");

    init();
    qinsert(10); 
    qinsert(20);  
    qinsert(30);  
    qinsert(40);  
    qinsert(33);
    qinsert(46);
    qinsert(50);
    qinsert(60);
    print();
  
    return 0;
}