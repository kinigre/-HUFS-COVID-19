#pragma once

#ifndef __Info
#define __Info

#define MAX_ROW 300
#define MAX_COL 1000

typedef struct node {
	char country_name[MAX_ROW]; //���� �̸�
	int population; //�α�
	int confirmed; //Ȯ����
	int critical;//������
	int dead; //�����
	int active; //ġ������ ���

}info;

#endif 
