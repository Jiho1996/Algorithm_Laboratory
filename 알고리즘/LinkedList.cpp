#include <stdio.h>
#include <stdlib.h>


typedef struct _TreeNode {
    char value;
    struct _TreeNode* left;
    struct _TreeNode* right;
}TreeNode;

//노드 생성 함수
TreeNode* NewNode(char value) 
{
    TreeNode* New;
    New = (TreeNode*)malloc(sizeof(TreeNode));
    New->value = value;
    New->left = NULL;
    New->right = NULL;
    return New;
}
//노트 탐색 함수
TreeNode* search_Node(TreeNode* H, char value)
{
    if (H != NULL) {
        if (H->value == value) {
            return H;
        }
        else {
            TreeNode* tmp = search_Node(H->left, value);
            if (tmp != NULL) {
                return tmp;
            }

            return search_Node(H->right, value);
        }
    }
    return NULL;
}
//노드삽입 함수
void insert_TreeNode(TreeNode* H, char X, char Y, char Z) 
{
    H->value = X;
    if (Y != '.')
    {
        H->left = NewNode(Y); //왼쪽 자식
    }
    if (Z != '.')
    {
        H->right = NewNode(Z); // 오른쪽 자식
    }
}

void treeInOrder(TreeNode* H) //중위 순회 (재귀함수 사용)
{
    if (H == NULL)
        return;
        treeInOrder(H->left);
        printf("%c", H->value);
        treeInOrder(H->right);
}


int main()
{
    TreeNode* H = NewNode(NULL);
    TreeNode* tmp;
    int n;
    scanf("%d", &n);
    getchar(); //엔터 버퍼 방지
    for (int i = 0;i < n;i++) //트리 만들기
    {
        char parent, leftChild, rightChild;
        scanf("%c %c %c", &parent, &leftChild, &rightChild);
        getchar(); //엔터 버퍼 방지
        tmp = search_Node(H, parent);
        if (tmp != NULL)
            insert_TreeNode(tmp, parent, leftChild, rightChild);
        else
            insert_TreeNode(H, parent, leftChild, rightChild);
    }
    
    treeInOrder(H);

}