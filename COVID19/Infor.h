#pragma once

#ifndef __Info
#define __Info

#define MAX_ROW 300
#define MAX_COL 1000

typedef struct node {
	char country_name[MAX_ROW]; //나라 이름
	int population; //인구
	int confirmed; //확진자
	int critical;//위중증
	int dead; //사망자
	int active; //치료중인 사람

}info;

#endif 
