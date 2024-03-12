#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// "=" 선 그리는 함수
void Print_Line() {
    for (int i = 0; i < 50; i++) {
        printf("=");
    }
    printf("\n");
}
// 맵 채킹 함수
void Check_Map(int* y, int* x, char move) {    // &y와 &x의 주소 전달

    // 'a' 입력시 
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
            *x = *x + 1;    // map[y][x]에서 좌로 이동(x-1) 할 시 x+1로 위치 재지정
        }
    }
    // 'd' 입력시
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
            *x = *x - 1;    // map[y][x]에서 좌로 이동(x+1) 할 시 x-1로 위치 재지정
        }
    }
    // 'w' 입력시
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
    // 's' 입력시
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
// 이동 옵션 함수
void Move(int* y, int* x, char move) {

    int check_Y = *y;       // check_Y 변수에 인자값 *y 저장
    int check_X = *x;       // check_X 변수에 인자값 *x 저장

    if (move == 'w') {
        check_Y--;                              // 우선 이동
        Check_Map(&check_Y, &check_X, move);    // 맵 채킹
        *y = check_Y;                           // *y로 역참조
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
// 도어락 그리는 함수
void Draw_doorlock() {
    printf(" ┌───────┐\n");
    printf(" │ 1 2 3 │\n");
    printf(" │       │\n");
    printf(" │ 4 5 6 │\n");
    printf(" │       │\n");
    printf(" │ * 0 # │\n");
    printf(" └───────┘\n");

    return;
}