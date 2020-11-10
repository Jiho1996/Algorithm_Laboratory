#include <stdio.h>
#define MAX_N 100
int parent[MAX_N];
#define rank 100
#define size 100

void MakeSet(char input) // �ڱ��ڽŸ��� ���ҷ� ���� ���� �����.
{
    parent[input] = input;
}

int Find(char input) // input�� ���ҷ� ���� ���� �Լ�
{
    if (parent[input] == input) return input;
    return Find(parent[input]);
}

void Union(char p, char q) { // input1�� ���ҷ� ���� ���հ� input2�� ���� ������ ������
    p = Find(p);
    q = Find(q);
    parent[p] = q;
}

int main()
{
    //�ʱ� �������� �����.
    char i;
    for (i = 97;i <= 106;i++) { // init
        MakeSet(i);
    }
    printf("(a)\n\n");
    
    Union('b', 'a'); // b�� a�� ����

    printf("a parent : %c\n", Find('a')); // a�θ� ���
    printf("b parent : %c\n", Find('b'));  // b �θ� ���
    printf("c parent : %c\n", Find('c')); // c �θ� ���

    printf("\n\n");

   
    Union('c', 'a'); // c�� a�� ����.

    printf("a parent : %c <---Union ���� ��\n", Find('a')); // a�θ� ���
    printf("b parent : %c <---Union ���� ��\n", Find('b'));  // b �θ� ���
    printf("c parent : %c <---Union ���� ��\n", Find('c')); // c �θ� ���
  
    printf("\n\n");

    printf("(b)\n\n");

    
    Union('e', 'd'); // e�� d������
    Union('g', 'f'); // g�� f�� ����
    Union('h', 'f'); // h�� f�� ����
    Union('i', 'f'); // i�� f�� ����

    printf("d parent : %c\n", Find('d')); // d�θ� ���
    printf("e parent : %c\n", Find('e'));  // e �θ� ���
    printf("f parent : %c\n", Find('f')); // f �θ� ���
    printf("g parent : %c\n", Find('g')); // g �θ� ���
    printf("h parent : %c\n", Find('h')); // h �θ� ���
    printf("i parent : %c\n", Find('i')); // i �θ� ���

    printf("\n\n");

    Union('f', 'd');

   
  
    printf("f parent : %c <---Union ���� ��\n\n\n", Find('f')); // f �θ� ���
  
    printf("After, (a),(b) Union\n\n");


    Union('a', 'd');

    printf("a parent : %c  <---Union ���� ��\n", Find('a')); // a�θ� ���
   

}
