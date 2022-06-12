#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"Infor.h"

void init_struct(info *i) {
	memset(i->country_name, '\0', MAX_COL);
    i->confirmed = 0;
    i->critical = 0;
    i->dead = 0;
    i->population = 0;
    i->active = 0;
}

int read_data(char *file_name, char(*arr)[MAX_COL]) {
	FILE* fp = fopen(file_name, "rt");
	if (fp == NULL) { 
        printf("파일이 열리지 않습니다.\n"); 
        exit(1); 
    }
	int cnt = 0;
	while (feof(fp)!=0 && cnt < MAX_ROW) { 
        fgets(arr[cnt], MAX_COL, fp); 
        remove_newline(arr[cnt], MAX_COL); 
        cnt++; 
    }
	fclose(fp);

	return cnt;
}

void remove_newline(char* buffer, int len) {
    for (int i = 0; i < len; i++)
    {
        if (buffer[i] == '\n') {
            buffer[i] = '\0';
        }
    }
}

void buffer_parser(char(*input)[MAX_COL], int row, info *arr) {
    int str_cnt = 0;
    int index_parser = 0;
    int name_parser = 0;
    char* tmp;
    if (arr == NULL || input == NULL) { return; }
    for (int i = 0; i < row; i++) {
        str_cnt = 0;
        index_parser = 0;
        name_parser = 0;
        init_struct(&arr[i]);
        for (int j = 0; j < MAX_COL; j++) {
            if (input[i + 1][j] == ',' && index_parser == 0) index_parser = j; 
            else if (input[i + 1][j] == ',' && name_parser == 0) name_parser = j;
            else if (index_parser != 0 && name_parser != 0) break;
        }
        strncpy(arr[i].country_name, &input[i + 1][index_parser + 1], name_parser - index_parser - 1);
        tmp = input[i + 1] + name_parser + 1;
        
        //문자열 카운트
        str_cnt = sscanf(tmp, "%d,%d,%d,%d,%d,%d,\n",&arr[i].population, &arr[i].confirmed, &arr[i].critical, &arr[i].dead, &arr[i].active);
        if (str_cnt < 4) { 
            printf("Cannot parse the string! [%d]\n", str_cnt);
            exit(1); 
        }

        /* Debugging */ /* printf("Total %d in [%d] ", row, i); print_one(i, row, arr); */
    }
    return;
}
