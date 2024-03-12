#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

// ������ ����ü ����(������Ʈ ����)
struct Item {
    int use_item1;      // ����
    int use_item2;      // ������
    int use_item3;      // Ƚ��
};
// �Լ����� Fuction_set.c�� ������
// �� �׸��� �Լ�
void Print_Line();
// �� ǥ�� �Լ� (�� ����ü ������ �ȳѾ��)
void Draw_Map(int y, int x, struct Item item) {   // map �迭�� [y]��ǥ [x]��ǥ �޾ƿ���

    system("cls");  // ���� �� �����

    char map[5][5];

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            map[i][j] = ' ';    // �ʿ��� �� ���� �������� ä���
        }
    }
    // �� �׸��� map[y][x] �ε��� ����
    map[0][0] = 'O';
    map[0][1] = 'O';
    map[0][2] = 'O';
    map[1][2] = 'O';
    map[2][2] = 'O';
    map[2][3] = 'O';
    map[2][4] = 'O';
    map[3][2] = 'O';
    map[4][2] = 'O';
    map[y][x] = 'X';  // ���� ��ġ ����

    Print_Line();

    for (int i = 0; i < 5; i++) {
        printf("|");
        for (int j = 0; j < 5; j++) {
            printf(" %c", map[i][j]);
        }
        printf(" |");
        //���� ��ġ ��Ÿ���� �ڵ�
        if (i == 1) {                   // ���� ��ġ
            printf(" ���� ��ġ: ");

            if (y == 4 && x == 2) {     // map[4][2] ó�� ��
                printf("������ ��");
            }
            else if (y == 3 && x == 2) {     // map[3][2] �ι�°�� ������ ��
                printf("���Ͻ� �Ա�");
            }
            else if (y == 2 && x == 2) {     // map[2][2] ���Ͻ�
                printf("���Ͻ� ����");
            }
            else if (y == 2 && x == 3) {     // map[2][3] ���Ͻ� ������ 1
                printf("���Ͻ� ������ 1");
            }
            else if (y == 2 && x == 4) {     // map[2][4] ���Ͻ� ������ 2
                printf("���Ͻ� ������ 2");
            }
            else if (y == 1 && x == 2) {     // map[1][2] ���Ͻ� ����1
                printf("���Ͻ� ���� 1");
            }
            else if (y == 0 && x == 2) {     // map[0][2] ���Ͻ� ����1
                printf("���Ͻ� ���� 2");
            }
            else if (y == 0 && x == 1) {     // map[0][1] ���Ͻ� ����1
                printf("���Ͻ� ���� 3");
            }
            else if (y == 0 && x == 0) {     // map[0][0] ���Ͻ� ����1
                printf("���Ͻ� ���� �ⱸ");
            }
            else {
                printf("���� �ɸ� ����");
            }
        }
        //���� ���� ������ ǥ�� (����ü�� ������Ʈ ����)
        if (i == 3) {
            printf(" ������:");
            if (item.use_item1 == 1) {
                printf(" ����");
            }
            if (item.use_item2 == 1) {
                printf(" ������");
            }
            if (item.use_item3 == 1) {
                printf(" Ƚ��");
            }
        }
        
        if (i == 4) {   // ���� �� ��������
            printf(" ���� map[y][x]��ǥ = (%d, %d)", y, x);
        }
        
        printf("\n");
    }
    Print_Line();
}
// �� äŷ �Լ�
void Check_Map(int* y, int* x, char move);
// �̵� �ɼ� �Լ�
void Move(int* y, int* x, char move);
// ����� �׸��� �Լ�
void Draw_doorlock();

int main() {

    int x = 2;              // �ʱ� ���� ��ġ�� x ��ǥ
    int y = 4;              // �ʱ� ���� ��ġ�� y ��ǥ
    int hidden_ending = 0;  // ���翣�� ���� ���� ����
    char move = NULL;       // NULL������ �ʱ�ȭ

    struct Item item;       // main �Լ� ����ü ����

    item.use_item1 = 0;      // ������ ����ü ��
    item.use_item2 = 0;
    item.use_item3 = 0;

    int item_get_1 = 1;     // ������ ȹ���� �� �ѹ��� �ϱ� ���� ���� ���� ����
    int item_get_2 = 1;
    int item_get_3 = 1;
    
    int room_check1 = 0;    // map[3][2]�� ���� ���� Ȯ��
    int room_check2 = 0;    // map[2][2]�� ���� ���� Ȯ��
    int room_check3 = 0;    // map[2][3]�� ���� ���� Ȯ��
    int room_check4 = 0;    // map[2][4]�� ���� ���� Ȯ��
    int room_check5 = 0;    // map[1][2]�� ���� ���� Ȯ��

    while (1) {

        char choice = NULL;  // Ʃ�丮�� �ݺ��� �������� ����

        Draw_Map(y, x, item);
        printf("\n\n\n 1: ���� ���� 2: ���� ��ŵ\n\n\n\n");
        Print_Line();
        printf("�Է�: ");
        scanf("%c", &choice);

        if (choice == '1') {
            Draw_Map(y, x, item);
            printf("\n\n\n������ ��Ż���̸� ������ �Է�â��\n");
            printf(" w a s d �Է����� �����մϴ�.\n\n\n");
            Print_Line();
            system("pause");

            Draw_Map(y, x, item);
            printf("\n\n\n���� O �� �� �� �ִ� �����̰�\n");
            printf("���� X �� ���� ��ġ �Դϴ�.\n\n\n");
            Print_Line();
            system("pause");

            Draw_Map(y, x, item);
            printf("\n\n\n");
            printf("������ �����ϰڽ��ϴ�.\n");
            printf("\n\n\n");
            Print_Line();
            system("pause");
            break;
        }
        if (choice == '2') {
            Draw_Map(y, x, item);
            printf("\n\n\n������ �����ϰڽ��ϴ�.\n\n\n\n");
            Print_Line();
            system("pause");
            break;
        }
        if (choice == '7') {
            Draw_Map(y, x, item);
            printf("\n\n\n ������ ���(��� �� ����) \n\n\n\n");
            Print_Line();
            system("pause");
        // ��� �� ����
        room_check1 = 1;  
        room_check2 = 1;
        // ��� ������ Ȱ��
        item.use_item1 = 1;      // ������ ����ü ��
        item.use_item2 = 1;
        item.use_item3 = 1;
        break;
        }
    }
    while (1) {     // ���ӳ����� ���� ���ѹݺ�
        // map[4][2]
        if (y == 4 && x == 2) {     
      
            char choice_start;

            while (1) {
              
                Draw_Map(y, x, item);
                printf("\n\n\n1. �ֺ��� �ѷ����� 2. ������ �ִ´�. 3. �̵�\n\n\n\n");
                Print_Line();
                printf("�Է�: ");
                scanf(" %c", &choice_start);

                if (choice_start == '1') {
                    if (item_get_1 == 1) {    /// ������ ��°� �� �ѹ�
                        Draw_Map(y, x, item);
                        printf("\n\n\n���踦 �ֿ���.\n\n\n\n");
                        item.use_item1 = 1;  // ������ ������ ���� �Ҵ� (������ Ȱ��)
                        Print_Line();
                        system("pause");

                        item_get_1 = 0;
                    }
                    else {
                        Draw_Map(y, x, item);
                        printf("\n\n\n�� ���� ���°� ����.\n\n\n\n");
                        Print_Line();
                        system("pause");
                    }
                }
                else if (choice_start == '2') {
                    Draw_Map(y, x, item);
                    printf("\n\n\n������ �ִ°� ���� ������ �ƴѵ��ϴ�...\n\n\n\n");
                    hidden_ending++;
                    Print_Line();
                    system("pause");

                    if (hidden_ending == 10) {
                        Draw_Map(y, x, item);
                        printf("\n\n\n[���翣��] ���Ͻǿ��� �������� ��ҽ��ϴ�.\n\n\n\n");
                        Print_Line();
                        return 1;
                    }
                }
                else if (choice_start == '3') {
                    Draw_Map(y, x, item);
                    printf("\n\n\n�̵��� ������ �Է��ϼ��� (w, a, s, d) \n\n\n\n");
                    Print_Line();
                    scanf(" %c", &move);
                    Move(&y, &x, move);
                    break;
                }
            }
        }
        // map[3][2]
        if (y == 3 && x == 2) {
            // �� ���ǹ��� �ѹ��� ����
            if (item.use_item1 == 1) {
                item.use_item1 = 0;  // ������ ��� �� ����ü �ʱ�ȭ

                Draw_Map(y, x, item);
                printf("\n\n\n ���踦 ����Ͽ� ���� ������. \n\n\n\n");
                Print_Line();
                system("pause");

                room_check1 = 1;    // ������ ���� ���� ���� (0 = ��� ���� 1 = ���� ����)
            }
            // ���� ��������� ������ �ϴ� �ڵ�
            if (room_check1 == 0) {
                move = 's';             // ���� ��������� �ڵ����� �ڷΰ��� �ڵ�
                Move(&y, &x, move);
                Draw_Map(y, x, item);
                printf("\n\n\n ���� ����ִ�. \n\n\n\n");
                Print_Line();
                system("pause");
            }
            // ���� ���������� ����
            else if (room_check1 == 1) {
                while (1) {
                    char choice;     // ���� �޴� ���� ����

                    Draw_Map(y, x, item);
                    printf("\n\n\n 1. �ֺ� Ȯ���ϱ� 2. �̵� \n\n\n\n");
                    Print_Line();
                    printf("�Է�: ");
                    scanf("%c", &choice);

                    if (choice == '1') {
                        Draw_Map(y, x, item);
                        printf("\n\n\n ���� ���𰡰� �����ִ� \n\n\n\n");
                        Print_Line();
                        system("pause");

                        Draw_Map(y, x, item);       // ������ ���� ���� : 2083
                        printf("\n 7777 -> 0    9612 -> ?\n");
                        printf("\n 9831 -> 3    1573 -> ?\n");
                        printf("\n 6818 -> 5    8888 -> ?\n");
                        printf("\n 6542 -> 1    8763 -> ?\n\n");
                        Print_Line();
                        system("pause");

                    }
                    if (choice == '2') {
                        Draw_Map(y, x, item);
                        printf("\n\n\n�̵��� ������ �Է��ϼ��� (w, a, s, d) \n\n\n\n");
                        Print_Line();
                        printf("�Է�: ");
                        scanf(" %c", &move);
                        Move(&y, &x, move);
                        break;
                    }
                }
            }
        }
        // map[2][2] (���� �������� ��)
        if (y == 2 && x == 2) {

            char choice;                // ������ ���� ����
            char pw[10];                // ���� �Է� ���� ���ڿ� ����
            char answer[10] = "2083";   // pw[10] �� ���� ����

            if (room_check2 == 0) {
                move = 's';             // ���� ��������� �ڵ����� �ڷΰ��� �ڵ�
                Move(&y, &x, move);
                Draw_Map(y, x, item);
                printf("\n\n\n ��������� ���� ����ִ�. \n\n\n\n");
                Print_Line();
                system("pause");

                while (1) {
                    Draw_Map(y, x, item);
                    printf("\n\n\n 1. �Է��ϱ� 2. �ڷΰ��� \n\n\n\n");
                    Print_Line();
                    printf("�Է�: ");
                    scanf("%c", &choice);

                    if (choice == '1') {
                        Draw_Map(y, x, item);
                        Draw_doorlock();
                        Print_Line();
                        printf("�Է�: ");
                        scanf("%s", pw);

                        if (strcmp(pw, answer) == 0) {      // ���� ���ڿ��� ���Ͻ� strcmp�� 0�� ��ȯ
                            room_check2 = 1;                // map[2][2] �� ����

                            Draw_Map(y, x, item);
                            printf("\n\n\n ���� ���ȴ�. \n\n\n\n");
                            Print_Line();
                            system("pause");
                            break;
                        }
                        else {
                            Draw_Map(y, x, item);
                            printf("\n\n\n ������ �ƴѵ� �ϴ�. \n\n\n\n");
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

                char choice = NULL;             // ������ ���� ����
                char door_choice = NULL;        // �� ���� ���� ����

                while (1) {
                    Draw_Map(y, x, item);
                    printf("\n\n ����� ������ ���� ���� ���δ�. \n");
                    printf("\n 1. �ѷ����� 2. �̵� \n\n\n");
                    Print_Line();
                    printf("�Է�: ");
                    scanf(" %c", &choice);

                    if (choice == '1') {
                        while (1) {
                            Draw_Map(y, x, item);
                            printf("\n\n\n 1. ���� �� ���캸�� 2. ���� �� ���캸�� 3. �ڷΰ���\n\n\n\n");
                            Print_Line();
                            printf("�Է�: ");
                            scanf(" %c", &door_choice);

                            if (door_choice == '1') {
                                Draw_Map(y, x, item);
                                printf("\n\n\n ���� ������� ���� �� ����. \n\n\n\n");
                                Print_Line();
                                system("pause");

                                Draw_Map(y, x, item);
                                printf("\n\n\n �� ���� ����� �����ִ�. \n\n\n\n");
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
                        printf("\n\n\n�̵��� ������ �Է��ϼ��� (w, a, s, d) \n\n\n\n");
                        Print_Line();
                        printf("�Է�: ");
                        scanf(" %c", &move);
                        Move(&y, &x, move);
                        break;
                    }
                }
            }
        }
        // map[2][3] (���� ������)
        if (y == 2 && x == 3) {

            char choice = NULL;
            room_check3 = 1;   // �⺻�� ������

            if (room_check3 == 0) {
                Draw_Map(y, x, item);
                printf("\n\n\n�⺻�� ���� �� �ܼ�â ���� �� ����\n\n\n\n");
                Print_Line();
                printf("�Է�: ");
                scanf(" %c", &move);
                Move(&y, &x, move);
            }
            else if (room_check3 == 1) {

                while (1) {

                    Draw_Map(y, x, item);
                    printf("\n\n\n1. �ѷ����� 2. �̵�\n\n\n\n");
                    Print_Line();
                    printf("�Է�: ");
                    scanf("%c", &choice);

                    if (choice == '1') {
                        if (item_get_2 == 1) {
                            item.use_item2 = 1;     // ������ �ӽ� Ȱ��
                            item.use_item3 = 1;     // ������ �ӽ� Ȱ��

                            Draw_Map(y, x, item);
                            printf("\n\n\n������ �ӽ� Ȱ��\n\n\n\n");
                            Print_Line();
                            system("pause");

                            item_get_2 = 0;     // ������ ȹ���� �� �ѹ���
                            break;
                        }
                        else {
                            Draw_Map(y, x, item);
                            printf("\n\n\n�� ���� ���µ� �ϴ�\n\n\n\n");
                            Print_Line();
                            system("pause");
                        }
                        
                    }
                    else if (choice == '2') {
                        Draw_Map(y, x, item);
                        printf("\n\n\n�̵��� ������ �Է��ϼ��� (w, a, s, d) \n\n\n\n");
                        Print_Line();
                        printf("�Է�: ");
                        scanf(" %c", &move);
                        Move(&y, &x, move);
                        break;
                    }
                }
            }
        }
        // map[2][4] (���� ����)
        if (y == 2 && x == 4) {
            Draw_Map(y, x, item);
            printf("\n\n\nmap[2][4] ������\n\n\n\n");
            Print_Line();
            printf("�Է�: ");
            scanf(" %c", &move);
            Move(&y, &x, move);
        }
        // map[1][2] (���� ����)
        if (y == 1 && x == 2) {
            char item_choice;
            if (room_check5 == 0) {
                Draw_Map(y, x, item);
                printf("\n\n\n���� �ʹ� ��ο��� �� �� ������ ����...\n\n\n\n");
                Print_Line();
                system("pause");

                while (1) {
                    Draw_Map(y, x, item);
                    printf("\n\n\n 1. ������ ��� 2. �ڷΰ���\n\n\n\n");
                    Print_Line();
                    printf("�Է�: ");
                    scanf("%c", &item_choice);

                    if (item_choice == '1') {
                        if (item.use_item2 == 1 && item.use_item3 == 1) {
                            item.use_item2 = 0;     // ������ ��� �� ����
                            item.use_item3 = 0;

                            Draw_Map(y, x, item);
                            printf("\n\n\nȽ�ҿ� ���� �ٿ���.\n\n\n\n");
                            Print_Line();
                            system("pause");

                            Draw_Map(y, x, item);
                            printf("\n\n\n���� �������.\n\n\n\n");
                            Print_Line();
                            system("pause");

                            room_check5 = 1;
                            break;      // ���� ���� �� �ݺ� Ż��
                        }
                        else {
                            Draw_Map(y, x, item);
                            printf("\n\n\n������ �������� ����...\n\n\n\n");
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
                printf("\n\n\nȽ�� Ų �� �� ������(�̵��� ����)\n\n\n\n");
                Print_Line();
                printf("�Է�: ");
                scanf(" %c", &move);
                Move(&y, &x, move);
            }
        }
        // map[0][2] (���� ����)
        if (y == 0 && x == 2) {
            Draw_Map(y, x, item);
            printf("\n\n\nmap[0][2] ������\n\n\n\n");
            Print_Line();
            printf("�Է�: ");
            scanf(" %c", &move);
            Move(&y, &x, move);
        }
        // map[0][1] (���� ����)
        if (y == 0 && x == 1) {
            Draw_Map(y, x, item);
            printf("\n\n\nmap[0][1] ������ (�������� Ż�ⱸ)\n\n\n\n");
            Print_Line();
            printf("�Է�: ");
            scanf(" %c", &move);
            Move(&y, &x, move);
        }
        // map[0][0] (���� ����)
        if (y == 0 && x == 0) {
            Draw_Map(y, x, item);
            printf("\n\n\nŻ��\n\n\n\n");
            Print_Line();
            printf("�Է�: ");
            scanf(" %c", &move);
            Move(&y, &x, move);
        }
    }
}