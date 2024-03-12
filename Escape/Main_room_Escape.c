#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

// 아이템 구조체 선언(업데이트 예정)
struct Item {
    int use_item1;      // 열쇠
    int use_item2;      // 라이터
    int use_item3;      // 횟불
};
// 함수들은 Fuction_set.c에 모여있음
// 선 그리는 함수
void Print_Line();
// 맵 표시 함수 (얜 구조체 떄문에 안넘어가짐)
void Draw_Map(int y, int x, struct Item item) {   // map 배열의 [y]좌표 [x]좌표 받아오기

    system("cls");  // 이전 맵 지우기

    char map[5][5];

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            map[i][j] = ' ';    // 맵에서 빈 공간 공백으로 채우기
        }
    }
    // 맵 그리기 map[y][x] 인덱스 설정
    map[0][0] = 'O';
    map[0][1] = 'O';
    map[0][2] = 'O';
    map[1][2] = 'O';
    map[2][2] = 'O';
    map[2][3] = 'O';
    map[2][4] = 'O';
    map[3][2] = 'O';
    map[4][2] = 'O';
    map[y][x] = 'X';  // 시작 위치 변경

    Print_Line();

    for (int i = 0; i < 5; i++) {
        printf("|");
        for (int j = 0; j < 5; j++) {
            printf(" %c", map[i][j]);
        }
        printf(" |");
        //현재 위치 나타내는 코드
        if (i == 1) {                   // 현재 위치
            printf(" 현재 위치: ");

            if (y == 4 && x == 2) {     // map[4][2] 처음 방
                printf("시작의 방");
            }
            else if (y == 3 && x == 2) {     // map[3][2] 두번째로 만나는 방
                printf("지하실 입구");
            }
            else if (y == 2 && x == 2) {     // map[2][2] 지하실
                printf("지하실 내부");
            }
            else if (y == 2 && x == 3) {     // map[2][3] 지하실 우측방 1
                printf("지하실 우측방 1");
            }
            else if (y == 2 && x == 4) {     // map[2][4] 지하실 우측방 2
                printf("지하실 우측방 2");
            }
            else if (y == 1 && x == 2) {     // map[1][2] 지하실 내부1
                printf("지하실 내부 1");
            }
            else if (y == 0 && x == 2) {     // map[0][2] 지하실 내부1
                printf("지하실 내부 2");
            }
            else if (y == 0 && x == 1) {     // map[0][1] 지하실 내부1
                printf("지하실 내부 3");
            }
            else if (y == 0 && x == 0) {     // map[0][0] 지하실 내부1
                printf("지하실 내부 출구");
            }
            else {
                printf("버그 걸림 ㅅㄱ");
            }
        }
        //현재 소유 아이템 표시 (구조체로 업데이트 예정)
        if (i == 3) {
            printf(" 아이템:");
            if (item.use_item1 == 1) {
                printf(" 열쇠");
            }
            if (item.use_item2 == 1) {
                printf(" 라이터");
            }
            if (item.use_item3 == 1) {
                printf(" 횟불");
            }
        }
        
        if (i == 4) {   // 개발 후 삭제예정
            printf(" 현재 map[y][x]좌표 = (%d, %d)", y, x);
        }
        
        printf("\n");
    }
    Print_Line();
}
// 맵 채킹 함수
void Check_Map(int* y, int* x, char move);
// 이동 옵션 함수
void Move(int* y, int* x, char move);
// 도어락 그리는 함수
void Draw_doorlock();

int main() {

    int x = 2;              // 초기 시작 위치의 x 좌표
    int y = 4;              // 초기 시작 위치의 y 좌표
    int hidden_ending = 0;  // 히든엔딩 조건 변수 선언
    char move = NULL;       // NULL값으로 초기화

    struct Item item;       // main 함수 구조체 정의

    item.use_item1 = 0;      // 아이템 구조체 값
    item.use_item2 = 0;
    item.use_item3 = 0;

    int item_get_1 = 1;     // 아이템 획득을 단 한번만 하기 위한 조건 변수 선언
    int item_get_2 = 1;
    int item_get_3 = 1;
    
    int room_check1 = 0;    // map[3][2]의 오픈 여부 확인
    int room_check2 = 0;    // map[2][2]의 오픈 여부 확인
    int room_check3 = 0;    // map[2][3]의 오픈 여부 확인
    int room_check4 = 0;    // map[2][4]의 오픈 여부 확인
    int room_check5 = 0;    // map[1][2]의 오픈 여부 확인

    while (1) {

        char choice = NULL;  // 튜토리얼 반복문 지역변수 선언

        Draw_Map(y, x, item);
        printf("\n\n\n 1: 게임 설명 2: 설명 스킵\n\n\n\n");
        Print_Line();
        printf("입력: ");
        scanf("%c", &choice);

        if (choice == '1') {
            Draw_Map(y, x, item);
            printf("\n\n\n간단한 방탈출이며 조작은 입력창에\n");
            printf(" w a s d 입력으로 가능합니다.\n\n\n");
            Print_Line();
            system("pause");

            Draw_Map(y, x, item);
            printf("\n\n\n맵의 O 는 갈 수 있는 지역이고\n");
            printf("맵의 X 는 현재 위치 입니다.\n\n\n");
            Print_Line();
            system("pause");

            Draw_Map(y, x, item);
            printf("\n\n\n");
            printf("게임을 시작하겠습니다.\n");
            printf("\n\n\n");
            Print_Line();
            system("pause");
            break;
        }
        if (choice == '2') {
            Draw_Map(y, x, item);
            printf("\n\n\n게임을 시작하겠습니다.\n\n\n\n");
            Print_Line();
            system("pause");
            break;
        }
        if (choice == '7') {
            Draw_Map(y, x, item);
            printf("\n\n\n 개발자 모드(모든 문 열림) \n\n\n\n");
            Print_Line();
            system("pause");
        // 모든 문 열림
        room_check1 = 1;  
        room_check2 = 1;
        // 모든 아이템 활성
        item.use_item1 = 1;      // 아이템 구조체 값
        item.use_item2 = 1;
        item.use_item3 = 1;
        break;
        }
    }
    while (1) {     // 게임끝날때 까지 무한반복
        // map[4][2]
        if (y == 4 && x == 2) {     
      
            char choice_start;

            while (1) {
              
                Draw_Map(y, x, item);
                printf("\n\n\n1. 주변을 둘러본다 2. 가만히 있는다. 3. 이동\n\n\n\n");
                Print_Line();
                printf("입력: ");
                scanf(" %c", &choice_start);

                if (choice_start == '1') {
                    if (item_get_1 == 1) {    /// 아이템 얻는건 단 한번
                        Draw_Map(y, x, item);
                        printf("\n\n\n열쇠를 주웠다.\n\n\n\n");
                        item.use_item1 = 1;  // 아이템 변수에 값을 할당 (아이템 활성)
                        Print_Line();
                        system("pause");

                        item_get_1 = 0;
                    }
                    else {
                        Draw_Map(y, x, item);
                        printf("\n\n\n더 볼건 없는것 같다.\n\n\n\n");
                        Print_Line();
                        system("pause");
                    }
                }
                else if (choice_start == '2') {
                    Draw_Map(y, x, item);
                    printf("\n\n\n가만히 있는건 좋은 생각이 아닌듯하다...\n\n\n\n");
                    hidden_ending++;
                    Print_Line();
                    system("pause");

                    if (hidden_ending == 10) {
                        Draw_Map(y, x, item);
                        printf("\n\n\n[히든엔딩] 지하실에서 오래오래 살았습니다.\n\n\n\n");
                        Print_Line();
                        return 1;
                    }
                }
                else if (choice_start == '3') {
                    Draw_Map(y, x, item);
                    printf("\n\n\n이동할 방향을 입력하세요 (w, a, s, d) \n\n\n\n");
                    Print_Line();
                    scanf(" %c", &move);
                    Move(&y, &x, move);
                    break;
                }
            }
        }
        // map[3][2]
        if (y == 3 && x == 2) {
            // 이 조건문은 한번만 실행
            if (item.use_item1 == 1) {
                item.use_item1 = 0;  // 아이템 사용 후 구조체 초기화

                Draw_Map(y, x, item);
                printf("\n\n\n 열쇠를 사용하여 문을 열었다. \n\n\n\n");
                Print_Line();
                system("pause");

                room_check1 = 1;    // 문열림 여부 변수 변경 (0 = 잠긴 상태 1 = 열린 상태)
            }
            // 문이 잠겨있을시 못들어가게 하는 코드
            if (room_check1 == 0) {
                move = 's';             // 문이 잠겨있을시 자동으로 뒤로가는 코드
                Move(&y, &x, move);
                Draw_Map(y, x, item);
                printf("\n\n\n 문이 잠겨있다. \n\n\n\n");
                Print_Line();
                system("pause");
            }
            // 문이 열려있으면 실행
            else if (room_check1 == 1) {
                while (1) {
                    char choice;     // 선택 메뉴 변수 선언

                    Draw_Map(y, x, item);
                    printf("\n\n\n 1. 주변 확인하기 2. 이동 \n\n\n\n");
                    Print_Line();
                    printf("입력: ");
                    scanf("%c", &choice);

                    if (choice == '1') {
                        Draw_Map(y, x, item);
                        printf("\n\n\n 벽에 무언가가 적혀있다 \n\n\n\n");
                        Print_Line();
                        system("pause");

                        Draw_Map(y, x, item);       // 정답은 원의 개수 : 2083
                        printf("\n 7777 -> 0    9612 -> ?\n");
                        printf("\n 9831 -> 3    1573 -> ?\n");
                        printf("\n 6818 -> 5    8888 -> ?\n");
                        printf("\n 6542 -> 1    8763 -> ?\n\n");
                        Print_Line();
                        system("pause");

                    }
                    if (choice == '2') {
                        Draw_Map(y, x, item);
                        printf("\n\n\n이동할 방향을 입력하세요 (w, a, s, d) \n\n\n\n");
                        Print_Line();
                        printf("입력: ");
                        scanf(" %c", &move);
                        Move(&y, &x, move);
                        break;
                    }
                }
            }
        }
        // map[2][2] (현재 개발중인 맵)
        if (y == 2 && x == 2) {

            char choice;                // 선택지 변수 선언
            char pw[10];                // 정답 입력 변수 문자열 선언
            char answer[10] = "2083";   // pw[10] 비교 정답 변수

            if (room_check2 == 0) {
                move = 's';             // 문이 잠겨있을시 자동으로 뒤로가는 코드
                Move(&y, &x, move);
                Draw_Map(y, x, item);
                printf("\n\n\n 도어락으로 문이 잠겨있다. \n\n\n\n");
                Print_Line();
                system("pause");

                while (1) {
                    Draw_Map(y, x, item);
                    printf("\n\n\n 1. 입력하기 2. 뒤로가기 \n\n\n\n");
                    Print_Line();
                    printf("입력: ");
                    scanf("%c", &choice);

                    if (choice == '1') {
                        Draw_Map(y, x, item);
                        Draw_doorlock();
                        Print_Line();
                        printf("입력: ");
                        scanf("%s", pw);

                        if (strcmp(pw, answer) == 0) {      // 둘의 문자열이 동일시 strcmp는 0을 반환
                            room_check2 = 1;                // map[2][2] 맵 오픈

                            Draw_Map(y, x, item);
                            printf("\n\n\n 문이 열렸다. \n\n\n\n");
                            Print_Line();
                            system("pause");
                            break;
                        }
                        else {
                            Draw_Map(y, x, item);
                            printf("\n\n\n 정답이 아닌듯 하다. \n\n\n\n");
                            Print_Line();
                            system("pause");
                        }
                    }
                    else if (choice == '2') {
                        break;
                    }        
                }
            }
            else if (room_check2 == 1) {

                char choice = NULL;             // 선택지 변수 선언
                char door_choice = NULL;        // 방 선택 변수 선언

                while (1) {
                    Draw_Map(y, x, item);
                    printf("\n\n 정면과 우측에 각각 문이 보인다. \n");
                    printf("\n 1. 둘러보기 2. 이동 \n\n\n");
                    Print_Line();
                    printf("입력: ");
                    scanf(" %c", &choice);

                    if (choice == '1') {
                        while (1) {
                            Draw_Map(y, x, item);
                            printf("\n\n\n 1. 정면 문 살펴보기 2. 우측 문 살펴보기 3. 뒤로가기\n\n\n\n");
                            Print_Line();
                            printf("입력: ");
                            scanf(" %c", &door_choice);

                            if (door_choice == '1') {
                                Draw_Map(y, x, item);
                                printf("\n\n\n 문이 잠겨있진 않은 것 같다. \n\n\n\n");
                                Print_Line();
                                system("pause");

                                Draw_Map(y, x, item);
                                printf("\n\n\n 문 옆에 뭐라고 써져있다. \n\n\n\n");
                                Print_Line();
                                system("pause");


                                Draw_Map(y, x, item);
                                printf("\n\n\n 818 821 683 ??8 432 854\n");
                                printf(" 086 488 756 886 489 72\n\n\n");
                                Print_Line();
                                system("pause");

                            }
                            else if (door_choice == '2') {
                                Draw_Map(y, x, item);
                                printf("\n\n\n  \n\n\n\n");
                                Print_Line();
                                system("pause");
                            }
                            else if (door_choice == '3') {
                                break;
                            }
                        }
                    }
                    else if (choice == '2') {
                        Draw_Map(y, x, item);
                        printf("\n\n\n이동할 방향을 입력하세요 (w, a, s, d) \n\n\n\n");
                        Print_Line();
                        printf("입력: ");
                        scanf(" %c", &move);
                        Move(&y, &x, move);
                        break;
                    }
                }
            }
        }
        // map[2][3] (현재 개발중)
        if (y == 2 && x == 3) {

            char choice = NULL;
            room_check3 = 1;   // 기본값 문열림

            if (room_check3 == 0) {
                Draw_Map(y, x, item);
                printf("\n\n\n기본값 열림 이 콘솔창 보일 시 버그\n\n\n\n");
                Print_Line();
                printf("입력: ");
                scanf(" %c", &move);
                Move(&y, &x, move);
            }
            else if (room_check3 == 1) {

                while (1) {

                    Draw_Map(y, x, item);
                    printf("\n\n\n1. 둘러보기 2. 이동\n\n\n\n");
                    Print_Line();
                    printf("입력: ");
                    scanf("%c", &choice);

                    if (choice == '1') {
                        if (item_get_2 == 1) {
                            item.use_item2 = 1;     // 아이템 임시 활성
                            item.use_item3 = 1;     // 아이템 임시 활성

                            Draw_Map(y, x, item);
                            printf("\n\n\n아이템 임시 활성\n\n\n\n");
                            Print_Line();
                            system("pause");

                            item_get_2 = 0;     // 아이템 획득은 단 한번만
                            break;
                        }
                        else {
                            Draw_Map(y, x, item);
                            printf("\n\n\n더 볼게 없는듯 하다\n\n\n\n");
                            Print_Line();
                            system("pause");
                        }
                        
                    }
                    else if (choice == '2') {
                        Draw_Map(y, x, item);
                        printf("\n\n\n이동할 방향을 입력하세요 (w, a, s, d) \n\n\n\n");
                        Print_Line();
                        printf("입력: ");
                        scanf(" %c", &move);
                        Move(&y, &x, move);
                        break;
                    }
                }
            }
        }
        // map[2][4] (개발 예정)
        if (y == 2 && x == 4) {
            Draw_Map(y, x, item);
            printf("\n\n\nmap[2][4] 개발중\n\n\n\n");
            Print_Line();
            printf("입력: ");
            scanf(" %c", &move);
            Move(&y, &x, move);
        }
        // map[1][2] (개발 예정)
        if (y == 1 && x == 2) {
            char item_choice;
            if (room_check5 == 0) {
                Draw_Map(y, x, item);
                printf("\n\n\n방이 너무 어두워서 갈 수 없을거 같다...\n\n\n\n");
                Print_Line();
                system("pause");

                while (1) {
                    Draw_Map(y, x, item);
                    printf("\n\n\n 1. 아이템 사용 2. 뒤로가기\n\n\n\n");
                    Print_Line();
                    printf("입력: ");
                    scanf("%c", &item_choice);

                    if (item_choice == '1') {
                        if (item.use_item2 == 1 && item.use_item3 == 1) {
                            item.use_item2 = 0;     // 아이템 사용 후 삭제
                            item.use_item3 = 0;

                            Draw_Map(y, x, item);
                            printf("\n\n\n횟불에 불을 붙였다.\n\n\n\n");
                            Print_Line();
                            system("pause");

                            Draw_Map(y, x, item);
                            printf("\n\n\n방이 밝아졌다.\n\n\n\n");
                            Print_Line();
                            system("pause");

                            room_check5 = 1;
                            break;      // 조건 만족 후 반복 탈출
                        }
                        else {
                            Draw_Map(y, x, item);
                            printf("\n\n\n쓸만한 아이템이 없다...\n\n\n\n");
                            Print_Line();
                            system("pause");
                        }
                        
                    }
                    else if (item_choice == '2') {
                        move = 's';
                        Move(&y, &x, move);
                        break;
                    }            
                }
                
                }
            else if (room_check5 == 1){
                Draw_Map(y, x, item);
                printf("\n\n\n횟불 킨 후 맵 개발중(이동은 가능)\n\n\n\n");
                Print_Line();
                printf("입력: ");
                scanf(" %c", &move);
                Move(&y, &x, move);
            }
        }
        // map[0][2] (개발 예정)
        if (y == 0 && x == 2) {
            Draw_Map(y, x, item);
            printf("\n\n\nmap[0][2] 개발중\n\n\n\n");
            Print_Line();
            printf("입력: ");
            scanf(" %c", &move);
            Move(&y, &x, move);
        }
        // map[0][1] (개발 예정)
        if (y == 0 && x == 1) {
            Draw_Map(y, x, item);
            printf("\n\n\nmap[0][1] 개발중 (다음맵은 탈출구)\n\n\n\n");
            Print_Line();
            printf("입력: ");
            scanf(" %c", &move);
            Move(&y, &x, move);
        }
        // map[0][0] (개발 예정)
        if (y == 0 && x == 0) {
            Draw_Map(y, x, item);
            printf("\n\n\n탈출\n\n\n\n");
            Print_Line();
            printf("입력: ");
            scanf(" %c", &move);
            Move(&y, &x, move);
        }
    }
}