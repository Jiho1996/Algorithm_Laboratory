#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _word {
    char eng[15];
    char kor[30];
    struct _word* next;
    struct _word* prev;
}Word;

Word* Insert(Word* head, char str[]) {
    Word* nw = malloc(sizeof(Word));
    Word* cur = head;

    char* ptr = strtok(str, " ");
    strcpy(nw->eng, ptr);
    ptr = strtok(NULL, " ");
    strcpy(nw->kor, ptr);
    nw->kor[strlen(nw->kor) - 1] = '\0';

    if (cur == NULL) {
        head = nw;
        head->prev = NULL;
        head->next = NULL;
        return nw;
    }

    while ((strcmp(cur->eng, nw->eng) == -1) && (cur->next != NULL)) {
        cur = cur->next;
    }

    if (cur->prev == NULL) {
        head = nw;
    }
    else {
        cur->prev->next = nw;
    }

    nw->prev = cur->prev;
    nw->next = cur;
    cur->prev = nw;

    return head;
}

int main() {
    int opt;
    while (1) {
        printf(">>영어 단어 맞추기 프로그램<<\n");
        printf("1) 영어 단어 맞추기\n");
        printf("2) 프로그램 종료\n");
        printf("번호를 선택하세요 : ");
        scanf("%d", &opt);
        printf("\n");
        if (opt == 1) {
            Word* w = malloc(sizeof(Word));
            w = NULL;
            char line[50];
            int correct = 0, incorrect = 0;
            Word* temp;
            char input[15];

            FILE* fp = fopen("dic.txt", "r");
            while (fgets(line, sizeof(line), fp) != NULL) {
                w = Insert(w, line);
            }

            temp = w;
            while (temp->next != NULL) {
                printf("%s : ", temp->kor);
                scanf("%s", input);
                if (strcmp(input, ".quit") == 0)
                    break;
                else if (strcmp(temp->eng, input) == 0) {
                    printf("correct!\n");
                    correct++;
                }
                else {
                    printf("incorrect!\n");
                    incorrect++;
                }
                temp = temp->next;
            }
            printf("\n점수: %.2lf점\n", (double)correct / (correct + incorrect) * 100);
        }
        else if (opt == 2) {
            break;
        }
    }
}
