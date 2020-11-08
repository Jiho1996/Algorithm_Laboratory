#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 13
struct node // 노드생성
{
    int data;
    struct node* next;
};
struct node* head[TABLE_SIZE] = { NULL }, * c;
void insert(int key) // 체이닝
{
    int i;
    i = key % 13; // mod13
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = key;
    newnode->next = NULL;
    if (head[i] == NULL) // null값이라면, node그대로 대입.
        head[i] = newnode;
    else // 아니라면, 연결리스트로 체이닝
    {
        c = head[i];
        while (c->next != NULL)
        {
            c = c->next;
        }
        c->next = newnode;
    }
}
void display() // 연결리스트 출력함수
{
    int i;
    for (i = 9;i < TABLE_SIZE;i++)
    {
         printf("\narr[%d] : ", i);
         if (head[i] == NULL)
         {
             printf("NULL");

         }
         else
         {
             for (c = head[i];c != NULL;c = c->next)
                 printf("%d->", c->data);
         }
     }
     
    }

main()
{
    insert(10); 
    insert(20);  
    insert(30);  
    insert(40);  
    insert(33);
    insert(46);
    insert(50);
    insert(60);

    display();
}