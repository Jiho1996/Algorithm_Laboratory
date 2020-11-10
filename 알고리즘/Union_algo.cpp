#include <stdio.h>
#define MAX_N 100
int parent[MAX_N];
#define rank 100
#define size 100

void MakeSet(char input) // 자기자신만을 원소로 갖는 집합 만들기.
{
    parent[input] = input;
}

int Find(char input) // input을 원소로 갖는 집합 함수
{
    if (parent[input] == input) return input;
    return Find(parent[input]);
}

void Union(char p, char q) { // input1을 원소로 가진 집합과 input2를 가진 집합의 합집합
    p = Find(p);
    q = Find(q);
    parent[p] = q;
}

int main()
{
    //초기 문제상태 만들기.
    char i;
    for (i = 97;i <= 106;i++) { // init
        MakeSet(i);
    }
    printf("(a)\n\n");
    
    Union('b', 'a'); // b를 a에 연결

    printf("a parent : %c\n", Find('a')); // a부모값 출력
    printf("b parent : %c\n", Find('b'));  // b 부모값 출력
    printf("c parent : %c\n", Find('c')); // c 부모값 출력

    printf("\n\n");

   
    Union('c', 'a'); // c를 a에 연결.

    printf("a parent : %c <---Union 후의 값\n", Find('a')); // a부모값 출력
    printf("b parent : %c <---Union 후의 값\n", Find('b'));  // b 부모값 출력
    printf("c parent : %c <---Union 후의 값\n", Find('c')); // c 부모값 출력
  
    printf("\n\n");

    printf("(b)\n\n");

    
    Union('e', 'd'); // e를 d에연결
    Union('g', 'f'); // g를 f에 연결
    Union('h', 'f'); // h를 f에 연결
    Union('i', 'f'); // i를 f에 연결

    printf("d parent : %c\n", Find('d')); // d부모값 출력
    printf("e parent : %c\n", Find('e'));  // e 부모값 출력
    printf("f parent : %c\n", Find('f')); // f 부모값 출력
    printf("g parent : %c\n", Find('g')); // g 부모값 출력
    printf("h parent : %c\n", Find('h')); // h 부모값 출력
    printf("i parent : %c\n", Find('i')); // i 부모값 출력

    printf("\n\n");

    Union('f', 'd');

   
  
    printf("f parent : %c <---Union 후의 값\n\n\n", Find('f')); // f 부모값 출력
  
    printf("After, (a),(b) Union\n\n");


    Union('a', 'd');

    printf("a parent : %c  <---Union 후의 값\n", Find('a')); // a부모값 출력
   

}
