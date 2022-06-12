/*
�а�: ��ǻ�Ͱ��к�
�й�: 202203493	
�̸�: �ִ��
����:�ڷγ� 19�� ���� Ȯ����, ����� �Դϴ�.
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
	printf("����");
	return 0;
}

void search_by_country(int len, info* arr) {
	char name[50] = { 0 };
	printf("������ �Է�(����): ");
	fgets(name, sizeof(name), stdin);
	remove_newline(name, sizeof(name));
	for (int i = 0; i < len; i++) { 
		if (strcmp(name, arr[i].country_name) == 0) { 
			//print_one(i, row, arr); 
			return; 
		} 
	}
	printf("ã�� ������ �����ϴ�.\n");
}

void run_data(char(*save)[MAX_ROW], int row, info* arr) {
    buffer_parser(save, row, arr);
    int mode = 0;
    do {
        printf("------------------------------------------\n");
        printf("    1. ������ �ڷγ� ��Ȳ �˻�\n");
        printf("    2. Ư�� ���� ���� �����ϱ�\n");
        printf("    3. ��� ���� ����ϱ�\n");
        printf("    0. ���α׷� ����\n");
        printf("------------------------------------------\n");
        printf("\n");
        printf("�޴��� �����ϼ��� >> ");
        scanf("%d", &mode);
        printf("\n");
        if (mode < 0 || mode > 3) { printf("�߸��� ���� �Է��߽��ϴ�.\n"); continue; }
        else if (mode == 0) { break; }
        else if (mode == 1) { search_by_name(row, arr); }
        else if (mode == 2) { sort_by_column(row, arr); }
        else if (mode == 3) { print_all(row, arr); }
        else { printf("���α׷� ����\n"); continue; }
    } while (mode != 0);
}