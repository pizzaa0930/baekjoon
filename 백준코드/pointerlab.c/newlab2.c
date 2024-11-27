#include <stdio.h>
#include <string.h>
#include <stdlib.h> // atoi 함수 사용을 위해 추가한 코드

void printHelp() {
    printf("사용법: ./program [옵션] [인자]\n");
    printf("옵션:\n");
    printf("  -h, --help     도움말을 보여줍니다\n");
    printf("  -n [숫자]      입력한 숫자만큼 반복합니다\n");
    printf("  -s [문자열]    입력한 문자열을 출력합니다\n");
}

int main(int argc, char* argv[]) {
    // 인자가 없는 경우
    if (argc == 1) {
        printf("전달된 인자가 없습니다.\n");
        printf("도움말을 보려면 -h 또는 --help를 입력하세요.\n");
        return 0;
    }


    // 인자 처리
    for (int i = 1; i < argc; i++) {
        // 도움말 옵션
        if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            printHelp();
            return 0;
        }
        // 숫자 반복 옵션
        else if (strcmp(argv[i], "-n") == 0) {
            if (i + 1 < argc) {
                int count = atoi(argv[i + 1]);
                printf("-n 옵션이 선택되었습니다. %d번 반복합니다:\n", count);
                for (int j = 0; j < count; j++) {
                    printf("반복 %d\n", j + 1);
                }
                i++; // 다음 인자는 이미 처리했으므로 건너뜀
            } else {
                printf("에러: -n 옵션에는 숫자가 필요합니다.\n");
            }
        }
        // 문자열 출력 옵션
        else if (strcmp(argv[i], "-s") == 0) {
            if (i + 1 < argc) {
                printf("-s 옵션이 선택되었습니다. 입력한 문자열: %s\n", argv[i + 1]);
                i++; // 다음 인자는 이미 처리했으므로 건너뜀
            } else {
                printf("에러: -s 옵션에는 문자열이 필요합니다.\n");
            }
        }
        // 알 수 없는 옵션
        else {
            printf("알 수 없는 옵션 또는 인자입니다: %s\n", argv[i]);
        }
    }

    // 모든 인자 출력
    printf("\n전체 인자 목록:\n");
    for (int i = 0; i < argc; i++) {
        printf("argv[%d]: %s\n", i, argv[i]);
    }

    return 0;
}
