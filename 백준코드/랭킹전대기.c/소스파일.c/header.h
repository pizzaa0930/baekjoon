#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <string.h>

// �Լ� ������Ÿ��
void processPlayers(int p, int m, int level[], char name[][17], int room[][300], int *room_count, int room_size[]);
void printRooms(int m, int room_count, int level[], char name[][17], int room[][300], int room_size[]);

#endif
