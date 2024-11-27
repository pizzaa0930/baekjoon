#include <stdio.h>
#include <string.h>
#include <stdlib.h> // atoi �Լ� ����� ���� �߰��� �ڵ�

void printHelp() {
    printf("����: ./program [�ɼ�] [����]\n");
    printf("�ɼ�:\n");
    printf("  -h, --help     ������ �����ݴϴ�\n");
    printf("  -n [����]      �Է��� ���ڸ�ŭ �ݺ��մϴ�\n");
    printf("  -s [���ڿ�]    �Է��� ���ڿ��� ����մϴ�\n");
}

int main(int argc, char* argv[]) {
    // ���ڰ� ���� ���
    if (argc == 1) {
        printf("���޵� ���ڰ� �����ϴ�.\n");
        printf("������ ������ -h �Ǵ� --help�� �Է��ϼ���.\n");
        return 0;
    }


    // ���� ó��
    for (int i = 1; i < argc; i++) {
        // ���� �ɼ�
        if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            printHelp();
            return 0;
        }
        // ���� �ݺ� �ɼ�
        else if (strcmp(argv[i], "-n") == 0) {
            if (i + 1 < argc) {
                int count = atoi(argv[i + 1]);
                printf("-n �ɼ��� ���õǾ����ϴ�. %d�� �ݺ��մϴ�:\n", count);
                for (int j = 0; j < count; j++) {
                    printf("�ݺ� %d\n", j + 1);
                }
                i++; // ���� ���ڴ� �̹� ó�������Ƿ� �ǳʶ�
            } else {
                printf("����: -n �ɼǿ��� ���ڰ� �ʿ��մϴ�.\n");
            }
        }
        // ���ڿ� ��� �ɼ�
        else if (strcmp(argv[i], "-s") == 0) {
            if (i + 1 < argc) {
                printf("-s �ɼ��� ���õǾ����ϴ�. �Է��� ���ڿ�: %s\n", argv[i + 1]);
                i++; // ���� ���ڴ� �̹� ó�������Ƿ� �ǳʶ�
            } else {
                printf("����: -s �ɼǿ��� ���ڿ��� �ʿ��մϴ�.\n");
            }
        }
        // �� �� ���� �ɼ�
        else {
            printf("�� �� ���� �ɼ� �Ǵ� �����Դϴ�: %s\n", argv[i]);
        }
    }

    // ��� ���� ���
    printf("\n��ü ���� ���:\n");
    for (int i = 0; i < argc; i++) {
        printf("argv[%d]: %s\n", i, argv[i]);
    }

    return 0;
}
