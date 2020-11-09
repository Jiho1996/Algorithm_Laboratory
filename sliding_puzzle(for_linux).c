#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <termio.h>
#include <string.h>
#include <unistd.h>

int getch(void)
{
    int ch;
    struct termios buf;
    struct termios save;

    tcgetattr(0, &save);
    buf = save;
    buf.c_lflag &= ~(ICANON | ECHO);
    buf.c_cc[VMIN] = 1;
    buf.c_cc[VTIME] = 0;
    tcsetattr(0, TCSAFLUSH, &buf);
    ch = getchar();
    tcsetattr(0, TCSAFLUSH, &save);
    return ch;
}



void initialize(int* puzzle, int sel)
{
    if (sel == 1) {
        for (int i = 0;i < 15;i++)
            puzzle[i] = i + 1;
        puzzle[15] = 0;
    }
    else if (sel == 2) {
        srand((unsigned int)time(NULL));
        int i;
        int s, d;
        int tmp;
        for (i = 0; i < 16; i++)
            puzzle[i] = i;
        for (i = 0; i < 16; i++)
        {
            s = rand() % 16;
            d = rand() % 16;
            tmp = puzzle[s];
            puzzle[s] = puzzle[d];
            puzzle[d] = tmp;
        }
        for (i = 0; i < 16; i++)
            if (puzzle[i] == 0)
            {
                puzzle[i] = puzzle[15];
                puzzle[15] = 0;
                break;
            }
    }
}
int input(int* puzzle)
{
    char key;
    int index;
    for (index = 0; index < 16; index++)
        if (puzzle[index] == 0)
            break;
    while (1)
    {

        key = getch();

        switch (key)
        {
        case 'i':
            if (index < 12)
            {
                puzzle[index] = puzzle[index + 4];
                puzzle[index + 4] = 0;
            }
            return 0;
        case 'j':
            if (((index + 1) % 4) != 0)
            {
                puzzle[index] = puzzle[index + 1];
                puzzle[index + 1] = 0;
            }
            return 0;
        case 'k':
            if (index > 3)
            {
                puzzle[index] = puzzle[index - 4];
                puzzle[index - 4] = 0;
            }
            return 0;
        case 'l':
            if ((index % 4) != 0)
            {
                puzzle[index] = puzzle[index - 1];
                puzzle[index - 1] = 0;
            }
            return 0;
        case 27:
            return 1;
        default:
            printf("i, j, k, l 만 입력해주세요\n");
        }
    }
}
int verifyPuzzle(int* puzzle)
{
    int i;
    int verify = 0;
    for (i = 0; i < 16; i++)
        if (puzzle[i] == i + 1)
            verify++;
    if (verify == 15)
        return 1;
    return 0;
}


void print(int* puzzle) {
    system("clear");
    for (int i = 0; i < 16; i++) {
        if (puzzle[i])
            printf("%3d", puzzle[i]);
        else
            printf("   ");
        if ((i + 1) % 4 == 0)
            putchar('\n');
    }
}


int main(int argc, char** argv)
{
    int puzzle[16], flag = 0, sel;

    if (strcmp(argv[1], "1") == 0) sel = 1;
    else if (strcmp(argv[1], "2") == 0) sel = 2;
    else {
        printf("매개변수 에러\n");
        exit(0);
    }

    initialize(puzzle, sel);
    while (1)
    {
        print(puzzle);
        if (flag == 1 && verifyPuzzle(puzzle))
        {
            printf("축하합니다.\n");
            break;
        }
        if (input(puzzle))
            break;
        flag = 1;
    }
    printf("프로그램을 종료합니다. .\n");
	sleep(3);
    return 0;
}
