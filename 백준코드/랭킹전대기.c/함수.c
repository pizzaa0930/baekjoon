#include <stdio.h>
#include <string.h>

// 방 정보를 저장할 구조체 정의
typedef struct {
    int players[300];  
    int size;         
    int base_level;    
} Room;

Room rooms[300]; 
int room_count = 0; 

// 플레이어 정보를 저장
typedef struct {
    int level;         
    char name[17];   
} Player;

Player players[300];

// 플레이어를 방에 배치
void place_player(int player_index, int max_room_size) {
    int level = players[player_index].level;
    for (int i = 0; i < room_count; i++) {
        if (rooms[i].size < max_room_size &&
            level >= rooms[i].base_level - 10 &&
            level <= rooms[i].base_level + 10) {
            // 방에 입장 가능
            rooms[i].players[rooms[i].size++] = player_index;
            return;
        }
    }
    // 입장 가능한 방이 없으므로 새로운 방 생성
    rooms[room_count].players[0] = player_index;
    rooms[room_count].size = 1;
    rooms[room_count].base_level = level;
    room_count++;
}

// 방의 플레이어들을 닉네임 사전순으로 정렬
void sort_players_in_room(Room* room) {
    for (int i = 0; i < room->size - 1; i++) {
        for (int j = i + 1; j < room->size; j++) {
            if (strcmp(players[room->players[i]].name, players[room->players[j]].name) > 0) {
                int temp = room->players[i];
                room->players[i] = room->players[j];
                room->players[j] = temp;
            }
        }
    }
}

// 방 상태 출력
void print_room_states(int max_room_size) {
    for (int i = 0; i < room_count; i++) {
        if (rooms[i].size == max_room_size) {
            printf("Started!\n");
        } else {
            printf("Waiting!\n");
        }
        sort_players_in_room(&rooms[i]);
        for (int j = 0; j < rooms[i].size; j++) {
            int player_index = rooms[i].players[j];
            printf("%d %s\n", players[player_index].level, players[player_index].name);
        }
    }
}

int main() {
    int p, m;
    scanf("%d %d", &p, &m);

    for (int i = 0; i < p; i++) {
        scanf("%d %s", &players[i].level, players[i].name);
    }

    for (int i = 0; i < p; i++) {
        place_player(i, m);
    }

    print_room_states(m);

    return 0;
}
