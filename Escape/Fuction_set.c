#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// "=" �� �׸��� �Լ�
void Print_Line() {
    for (int i = 0; i < 50; i++) {
        printf("=");
    }
    printf("\n");
}
// �� äŷ �Լ�
void Check_Map(int* y, int* x, char move) {    // &y�� &x�� �ּ� ����

    // 'a' �Է½� 
    if (move == 'a') {
        if (*y == 0 && (*x == 0 || *x == 1 || *x == 2)) {
            return;
        }
        else if (*y == 1 && *x == 2) {
            return;
        }
        else if (*y == 2 && (*x == 2 || *x == 3 || *x == 4)) {
            return;
        }
        else if (*y == 3 && *x == 3) {
            return;
        }
        else if (*y == 4 && *x == 3) {
            return;
        }
        else {
            *x = *x + 1;    // map[y][x]���� �·� �̵�(x-1) �� �� x+1�� ��ġ ������
        }
    }
    // 'd' �Է½�
    else if (move == 'd') {
        if (*y == 0 && (*x == 0 || *x == 1 || *x == 2)) {
            return;
        }
        else if (*y == 1 && *x == 2) {
            return;
        }
        else if (*y == 2 && (*x == 2 || *x == 3 || *x == 4)) {
            return;
        }
        else if (*y == 3 && *x == 2) {
            return;
        }
        else if (*y == 4 && *x == 2) {
            return;
        }
        else {
            *x = *x - 1;    // map[y][x]���� �·� �̵�(x+1) �� �� x-1�� ��ġ ������
        }
    }
    // 'w' �Է½�
    else if (move == 'w') {
        if (*y == 0 && (*x == 0 || *x == 1 || *x == 2)) {
            return;
        }
        else if (*y == 1 && *x == 2) {
            return;
        }
        else if (*y == 2 && (*x == 2 || *x == 3 || *x == 4)) {
            return;
        }
        else if (*y == 3 && *x == 2) {
            return;
        }
        else if (*y == 4 && *x == 2) {
            return;
        }
        else {
            *y = *y + 1;
        }
    }
    // 's' �Է½�
    else if (move == 's') {
        if (*y == 0 && (*x == 0 || *x == 1 || *x == 2)) {
            return;
        }
        else if (*y == 1 && *x == 2) {
            return;
        }
        else if (*y == 2 && (*x == 2 || *x == 3 || *x == 4)) {
            return;
        }
        else if (*y == 3 && *x == 2) {
            return;
        }
        else if (*y == 4 && *x == 2) {
            return;
        }
        else {
            *y = *y - 1;
        }
    }
}
// �̵� �ɼ� �Լ�
void Move(int* y, int* x, char move) {

    int check_Y = *y;       // check_Y ������ ���ڰ� *y ����
    int check_X = *x;       // check_X ������ ���ڰ� *x ����

    if (move == 'w') {
        check_Y--;                              // �켱 �̵�
        Check_Map(&check_Y, &check_X, move);    // �� äŷ
        *y = check_Y;                           // *y�� ������
    }
    else if (move == 's') {
        check_Y++;
        Check_Map(&check_Y, &check_X, move);
        *y = check_Y;
    }
    else if (move == 'a') {
        check_X--;
        Check_Map(&check_Y, &check_X, move);
        *x = check_X;
    }
    else if (move == 'd') {
        check_X++;
        Check_Map(&check_Y, &check_X, move);
        *x = check_X;
    }
}
// ����� �׸��� �Լ�
void Draw_doorlock() {
    printf(" ������������������\n");
    printf(" �� 1 2 3 ��\n");
    printf(" ��       ��\n");
    printf(" �� 4 5 6 ��\n");
    printf(" ��       ��\n");
    printf(" �� * 0 # ��\n");
    printf(" ������������������\n");

    return;
}