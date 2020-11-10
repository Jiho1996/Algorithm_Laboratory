#include<stdio.h>

#define size 8

int arr[size];


void init() //값 초기화 함수
{
    int i;
    for (i = 0; i < 13; i++)
        arr[i] = 0; // null값을 0으로 채운다.
}

void insert(int value) // 선형조사법 함수
{
    int key = value % 13; //mod13이다.

    if (arr[key] == 0) //값이 들어있지 않다면,
    {
        arr[key] = value; //그대로 받은 value값 대입
    }
    else
    {   
        for (int a = 1; a < 13;a++) { // 값이 들어있다면
            if (arr[key + a] == 0) { // 다음 칸에 값이 0이라면,
                arr[key + a] = value; // 다음 칸에 받은 value값 대입
                break;
            }
            else
                continue; //  // 아니라면 계속 continue
        }
  
    }
}

void qinsert(int value) //이차원 조사법
{
    int key = value % 13; // mod13

    if (arr[key] == 0)
    {
        arr[key] = value;
    }
    else
    {
        for (int a = 1; a < 13;a++) {
            if (arr[key + a * a] == 0) { // 이차원 조사법이므로 선형조사법에서 배수로 증가하게 만들면된다.
                arr[key + a * a] = value;
                break;
            }
            else
                continue;
        }
        
    }
}


void print() //배열 출력함수.
{
    int i;
    for (i = 0; i < 13; i++)
        printf("arr[%d] = %d\n", i, arr[i]);
}

int main()
{
    init(); // 값 초기화 함수

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