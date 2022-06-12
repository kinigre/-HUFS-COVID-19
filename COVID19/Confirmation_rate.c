/*
학과: 컴퓨터공학부
학번: 202203493	
이름: 최담록
주제:코로나 19의 개인 확진율, 사망률 입니다.
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Infor.h"

extern void init_struct(info *n);
extern void buffer_parser(char(*save)[MAX_COL], int row, info* arr);
extern void remove_newline(char *save, int len);
extern int read_data(char *file_name, char(*arr)[MAX_COL]);

void show_data(char(*save)[MAX_ROW], int row, info* arr);
void search_by_country(int row, info* arr);

int main() {
	info data[MAX_ROW] = { 0 };
	char save[MAX_ROW][MAX_COL] = { 0 };
	int row = read_data("COVID19_Data.csv",save)-2;
	show_data(save, row, data);
	printf("종료");
	return 0;
}

void search_by_country(int len, info* arr) {
	char name[50] = { 0 };
	printf("국가명 입력(영어): ");
	fgets(name, sizeof(name), stdin);
	remove_newline(name, sizeof(name));
	for (int i = 0; i < len; i++) { 
		if (strcmp(name, arr[i].country_name) == 0) { 
			//print_one(i, row, arr); 
			return; 
		} 
	}
	printf("찾는 정보가 없습니다.\n");
}

void run_data(char(*save)[MAX_ROW], int row, info* arr) {
    buffer_parser(save, row, arr);
    int mode = 0;
    do {
        printf("------------------------------------------\n");
        printf("    1. 국가별 코로나 현황 검색\n");
        printf("    2. 특정 열에 따라 정렬하기\n");
        printf("    3. 모든 내용 출력하기\n");
        printf("    0. 프로그램 종료\n");
        printf("------------------------------------------\n");
        printf("\n");
        printf("메뉴를 선택하세요 >> ");
        scanf("%d", &mode);
        printf("\n");
        if (mode < 0 || mode > 3) { printf("잘못된 값을 입력했습니다.\n"); continue; }
        else if (mode == 0) { break; }
        else if (mode == 1) { search_by_name(row, arr); }
        else if (mode == 2) { sort_by_column(row, arr); }
        else if (mode == 3) { print_all(row, arr); }
        else { printf("프로그램 오류\n"); continue; }
    } while (mode != 0);
}