#include <stdio.h>
#include <stdlib.h>


typedef struct _TreeNode {
    char value;
    struct _TreeNode* left;
    struct _TreeNode* right;
}TreeNode;

//��� ���� �Լ�
TreeNode* NewNode(char value) 
{
    TreeNode* New;
    New = (TreeNode*)malloc(sizeof(TreeNode));
    New->value = value;
    New->left = NULL;
    New->right = NULL;
    return New;
}
//��Ʈ Ž�� �Լ�
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
//������ �Լ�
void insert_TreeNode(TreeNode* H, char X, char Y, char Z) 
{
    H->value = X;
    if (Y != '.')
    {
        H->left = NewNode(Y); //���� �ڽ�
    }
    if (Z != '.')
    {
        H->right = NewNode(Z); // ������ �ڽ�
    }
}

void treeInOrder(TreeNode* H) //���� ��ȸ (����Լ� ���)
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
    getchar(); //���� ���� ����
    for (int i = 0;i < n;i++) //Ʈ�� �����
    {
        char parent, leftChild, rightChild;
        scanf("%c %c %c", &parent, &leftChild, &rightChild);
        getchar(); //���� ���� ����
        tmp = search_Node(H, parent);
        if (tmp != NULL)
            insert_TreeNode(tmp, parent, leftChild, rightChild);
        else
            insert_TreeNode(H, parent, leftChild, rightChild);
    }
    
    treeInOrder(H);

}