#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include <time.h>
void edit();
void line();
void welcome();
void mainmuen();
void edit();
void edit1();
int add1();
void edit2();
void dele1();
void change1();
void view1();
void view2();
struct Q1 *create1();
void write1(struct Q1 *head);
struct Q1 *del1(struct Q1 *head,int No);
struct Q1 *polish1(struct Q1 *head,int No);
int add2();
void dele2();
struct Q2 *del2(struct Q2 *head,int No);
struct Q2 *create2();
void write2(struct Q2 *head);
void change2();
struct Q2 *polish2(struct Q2 *head,int No);
int test();
void analyse();


struct Q1
{
	int No;
	char a[200], A[20], B[20], C[20], D[20], right;
	struct Q1 *next;
};
struct Q2
{
	int No;
	char a[200], right;
	struct Q2 *next;
};

struct inf
{
	int num;
	int score;
};

int main() {
	int choice;
	welcome();     //欢迎界面
	while (1) {
		mainmuen();
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			edit();
			break;
		case 2:
			test();
			break;
		case 3:
			analyse();
			break;
		case 0:
			return 0;
		default:printf("输入错误，请重新输入！"); system("PAUSE");
			break;
		}
	}
}

void line()
{
	printf("\t\t--------------------------------\n");
}

void welcome()  //欢迎界面
{
	line();
	line();
	printf("\n\n\t\t\t欢迎进入考试系统\n\n\n");
	line();
	line();

	system("PAUSE");

}

void mainmuen() {
	system("CLS");
	line();
	line();
	printf("\n\n\n\t\t\t1.编辑题库\n\n");
	printf("\t\t\t2.开始考试\n\n");
	printf("\t\t\t3.考试分析\n\n");
	printf("\t\t\t0.退出系统\n\n\n");
	line();
	line();
	printf("\t\t输入您的选择");
}


void edit() {
	int choice;
	while (1) {
		system("CLS");
		line();
		line();
		printf("\t\t\t1.编辑选择题\n\n");
		printf("\t\t\t2.编辑判断题\n\n");
		printf("\t\t\t0.返回上一级\n\n");
		line();
		line();
		printf("\t\t\t输入你的选择");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			edit1();
			break;
		case 2:
			edit2();
			break;
		case 0:return;
		default:printf("\t\t\t输入错误，请重新输入！"); system("PAUSE");
			break;
		}
	}

}

void edit1() {
	int choice;
	while (1) {
		system("CLS");
		line();
		line();
		printf("\n\t\t\t1.添加\n");
		printf("\t\t\t2.删除\n");
		printf("\t\t\t3.修改\n");
		printf("\t\t\t4.查看\n");
		printf("\t\t\t0.返回\n");
		line();
		line();
		scanf("%d", &choice);
		switch (choice) {
		case 1:add1(); break;
		case 2:dele1(); break;
		case 3:change1(); break;
		case 4:view1(); break;
		case 0:return;
		default:printf("\t\t\t选择错误!"); system("PAUSE");
		}
	}
}


int add1()    //增加题目
{
	struct Q1 question;
	printf("输入你的题号：\n");
	scanf("%d", &question.No);
	printf("输入你的题干：\n");
	scanf("%s", question.a);
	printf("输入A答案：\n");
	scanf("%s", question.A);
	printf("输入B答案：\n");
	scanf("%s", question.B);
	printf("输入C答案：\n");
	scanf("%s", question.C);
	printf("输入D答案：\n");
	scanf("%s", question.D);
	printf("输入正确答案：\n");
	scanf("%s", &question.right);
	FILE *fp;
	fp = fopen("file1", "a");
	if (fp == NULL)
	{
		printf("ERROR!");
		exit(0);
	}
	fwrite(&question, sizeof(struct Q1), 1, fp);
	fclose(fp);
	return 0;
}

void dele1()   //删除题目
{
	struct Q1 *head;
	int No;
	printf("输入你要删除的题目序号：");
	scanf("%d", &No);
	head = del1(create1(), No);
	write1(head);
	printf("删除成功");
	system("PAUSE");
}

void change1()   //编辑选择题
{
	struct Q1 *head;
	int No;
	printf("输入你要编辑的题目序号：");
	scanf("%d", &No);
	head = polish1(create1(), No);
	write1(head);
	printf("修改成功");
	system("PAUSE");
}
void view1()
{
	int i = 0;
	struct Q1 test1[100];
	int random[100] = { 0 };
	FILE *fp;
	fp = fopen("file1", "r");
	if (fp == NULL)
	{
		printf("ERROR!");
		exit(0); system("CLS");
	}
	while (!feof(fp))
	{
		fread(&test1[i + 1], sizeof(struct Q1), 1, fp);
		i++;
	}
	printf("一共有%d道选择题", i-1);
	fclose(fp);
	for (int k = 1; k <= i; k++)
	{
		random[k] = k;
	}
	i--;
	for (int j = 1; j <= i; j++)
	{
		printf("\n\n\n%d.\n%s\nA.%s\nB.%s\nC.%s\nD.%s", j, test1[j].a, test1[j].A, test1[j].B, test1[j].C, test1[j].D);
	}
	printf("\n");
	system("PAUSE");
}
struct Q1 *create1()   //建立链表，把文件写入链表
{
	struct Q1 *head, *tail, *niu;  // 这个奇怪的命名方式我也不想
	head = tail = niu = NULL;
	niu = tail = (struct Q1 *)malloc(sizeof(struct Q1));
	FILE *fp;
	fp = fopen("file1", "r");
	if (fp == NULL)
	{
		printf("ERROR!");
		exit(0);
	}
	fread(niu, sizeof(struct Q1), 1, fp);
	niu->next = NULL;
	while (!feof(fp))
	{
		if (head == NULL)
			head = niu;
		else
			tail->next = niu;
		tail = niu;
		niu = (struct Q1 *)malloc(sizeof(struct Q1));
		fread(niu, sizeof(struct Q1), 1, fp);
		niu->next = NULL;

	}
	return head;
}

struct Q1 *del1(struct Q1 *head, int No)  //删除链表中的节点
{
	struct Q1 *prior = NULL, *current;
	FILE *fp;
	fp = fopen("file1", "r");
	if (fp == NULL)
	{
		printf("ERROR!");
		exit(0);
	}

	if (head == NULL)
		printf("\n题库为空！");
	else
	{
		current = head;
		while (No != current->No&&current->next)
		{
			prior = current;
			current = current->next;
		}
		if (No == current->No)
		{
			if (current == head)
				head = current->next;
			else
				prior->next = current->next;
			printf("题号%d的题目被删除！", No);
		}
	}
	return head;
}

struct Q1 *polish1(struct Q1 *head, int No)
{
	struct Q1 *prior, *current;
	FILE *fp;
	fp = fopen("file1", "r");
	if (fp == NULL)
	{
		printf("ERROR!");
		exit(0);
	}

	if (head == NULL)
		printf("\n题库为空！");
	else
	{
		current = head;
		while (No != current->No&&current->next)
		{
			prior = current;
			current = current->next;
		}
		if (No == current->No)
		{
			printf("输入你的新题干：\n");
			scanf("%s", &current->a);
			printf("输入A答案：\n");
			scanf("%s", &current->A);
			printf("输入B答案：\n");
			scanf("%s", &current->B);
			printf("输入C答案：\n");
			scanf("%s", &current->C);
			printf("输入D答案：\n");
			scanf("%s", &current->D);
			printf("输入正确答案：\n");
			scanf("%c", &current->right);
		}
		else
			printf("查无此题！");
	}
	return head;
}

void write1(struct Q1 *head)   //把结构体写入文件
{
	struct Q1 *current;
	current = head;
	FILE *fp;
	fp = fopen("file1", "w");
	if (fp == NULL)
	{
		printf("ERROR!");
		exit(0);
	}
	while (current != NULL)
	{
		fwrite(current, sizeof(struct Q1), 1, fp);
		current = current->next;
	}

	fclose(fp);
}


void edit2() {
	int choice;

	while (1) {
		system("CLS");
		printf("1.添加\n");
		printf("2.删除\n");
		printf("3.修改\n");
		printf("4.查看\n");
		printf("0.返回\n");
		scanf("%d", &choice);
		switch (choice) {
		case 1:add2(); break;
		case 2:dele2(); break;
		case 3:change2(); break;
		case 4:view2(); break;
		case 0:return;
		default:printf("选择错误!");
		}
	}
}

int add2()    //增加判断题
{
	struct Q2 question;
	printf("输入你的题号：\n");
	scanf("%d", &question.No);
	printf("输入你的题干：\n");
	scanf("%s", question.a);
	do {
		printf("输入正确答案：\n");
		scanf("%s", &question.right);
	} while (question.right != 'T'&&question.right != 'F');
	//输入正确答案
	FILE *fp;
	fp = fopen("file2", "a");
	if (fp == NULL)
	{
		printf("ERROR!");
		exit(0);
	}
	fwrite(&question, sizeof(struct Q2), 1, fp);
	fclose(fp);
	return 0;
}

void dele2()   //删除题目
{
	struct Q2 *head;
	int No;
	printf("输入你要删除的题目序号：");
	scanf("%d", &No);
	head = del2(create2(), No);
	write2(head);
	printf("删除成功");
}

void view2()
{
	int i = 0;
	struct Q2 test1[100];
	int random[100] = { 0 };
	FILE *fp;
	fp = fopen("file2", "r");
	if (fp == NULL)
	{
		printf("ERROR!");
		exit(0);
	}
	while (!feof(fp))
	{
		fread(&test1[i + 1], sizeof(struct Q2), 1, fp);
		i++;
	}
	printf("一共有%d道判断题", i-1);
	fclose(fp);
	for (int k = 1; k <= i; k++)
	{
		random[k] = k;
	}
	i--;
	for (int j = 1; j <= i; j++)
	{
		printf("\n\n\n%d.\n%s\n", j, test1[j].a);
	}
	printf("\n");
	system("PAUSE");
}
struct Q2 *del2(struct Q2 *head, int No)  //删除链表中的节点
{
	struct Q2 *prior = NULL, *current;
	FILE *fp;
	fp = fopen("file2", "r");
	if (fp == NULL)
	{
		printf("ERROR!");
		exit(0);
	}

	if (head == NULL)
		printf("\n题库为空！");
	else
	{
		current = head;
		while (No != current->No&&current->next)
		{
			prior = current;
			current = current->next;
		}
		if (No == current->No)
		{
			if (current == head)
				head = current->next;
			else
				prior->next = current->next;
			printf("题号%d的题目被删除！", No);
		}
	}return head;
}


struct Q2 *create2()   //建立链表，把文件写入链表
{
	struct Q2 *head, *tail, *niu;  // 这个奇怪的命名方式我也不想
	head = tail = niu = NULL;
	niu = tail = (struct Q2 *)malloc(sizeof(struct Q2));
	FILE *fp;
	fp = fopen("file2", "r");
	if (fp == NULL)
	{
		printf("ERROR!");
		exit(0);
	}
	fread(niu, sizeof(struct Q2), 1, fp);
	niu->next = NULL;
	while (!feof(fp))
	{
		if (head == NULL)
			head = niu;
		else
			tail->next = niu;
		tail = niu;
		niu = (struct Q2 *)malloc(sizeof(struct Q2));
		fread(niu, sizeof(struct Q2), 1, fp);
		niu->next = NULL;

	}
	return head;
}


void write2(struct Q2 *head)   //把结构体写入文件
{
	struct Q2 *current;
	current = head;
	FILE *fp;
	fp = fopen("file2", "w");
	if (fp == NULL)
	{
		printf("ERROR!");
		exit(0);
	}
	while (current != NULL)
	{
		fwrite(current, sizeof(struct Q2), 1, fp);
		current = current->next;
	}

	fclose(fp);
}

void change2()   //编辑选择题
{
	struct Q2 *head;
	int No;
	printf("输入你要编辑的题目序号：");
	scanf("%d", &No);
	head = polish2(create2(), No);
	write2(head);
	printf("修改成功");
}


struct Q2 *polish2(struct Q2 *head, int No)
{
	struct Q2 *prior, *current, question;
	FILE *fp;
	fp = fopen("file2", "r");
	if (fp == NULL)
	{
		printf("ERROR!");
		exit(0);
	}

	if (head == NULL)
		printf("\n题库为空！");
	else
	{
		current = head;
		while (No != current->No&&current->next)
		{
			prior = current;
			current = current->next;
		}
		if (No == current->No)
		{
			scanf("%d", &question.No);
			printf("输入你的题干：\n");
			gets(current->a);
			do {
				printf("输入正确答案：\n");
				scanf("%c", &current->right);
			} while (question.right != 'T' || question.right != 'F');
			//输入正确答案
		}
		else
			printf("查无此题！");
	}
	return head;
}

int test()    //考试函数   返回选择题分数
{
	int i = 0, count = 0,k = 1,j = 1,q=1,p;
	char answer1[11], answer2[11];
	struct Q1 test1[100];
	struct Q2 test2[100];
	int score1 = 0, score2 = 0;
	int random[11] = { 0 };
	struct inf student;
	printf("考试开始 请输入您的学号！：");
	scanf("%d", &student.num);
	FILE *fp;
	fp = fopen("file1", "r");
	if (fp == NULL)
	{
		printf("ERROR!");
		exit(0);
	}
	while (!feof(fp))
	{
		fread(&test1[i + 1], sizeof(struct Q1), 1, fp);
		i++;
	}

	fclose(fp);
	srand((int)time(NULL));
	for(q=1;q<=10;){
            count=0;
        random[q]=rand()%i+1;
        for(p=1;p<q;p++){
            if(random[q]==random[p])
                count++;
        }
		if(!count)
			q++;
	}
	printf("下面开始选择题考试！");
	system("PAUSE");
	for (j = 1; j <= 10; j++)
	{
		printf("\n\n\n%d.\n%s\nA.%s\nB.%s\nC.%s\nD.%s", j, test1[j].a, test1[j].A, test1[j].B, test1[j].C, test1[j].D);
	}
	printf("输入你的答案");
	scanf("%s", answer1 + 1);
	for (k = 1; k <= 10; k++)
	{
		if (answer1[k] == test1[k].right)
			score1 += 5;
	}
	fp = fopen("file2", "r");
	if (fp == NULL)
	{
		printf("ERROR!");
		exit(0);
	}
	i = 0;
	while (!feof(fp))
	{
		fread(&test2[i + 1], sizeof(struct Q2), 1, fp);
		i++;
	}
	fclose(fp);

	printf("下面开始判断题考试！");
	system("PAUSE");
	for ( j = 1; j <= 10; j++)
	{
		printf("\n\n\n%d.\n%s", j, test2[j].a);
	}
	printf("输入你的答案");
	scanf("%s", answer2 + 1);
	for (k = 1; k <= 10; k++)
	{
		if (answer2[k] == test2[k].right)
			score2 += 5;
	}


	student.score = score1 + score2;
	for (j = 1; j <= 10; j++) {
		printf("\n\n\n%d.\n%s\nA.%s\nB.%s\nC.%s\nD.%s", j, test1[j].a, test1[j].A, test1[j].B, test1[j].C, test1[j].D);
		printf("\n考生答案：%c", answer1[j]);
		printf("\n标准答案：%c", test1[j].right);
		if (answer1[j] == test1[j].right)
			printf("本题正确！");
		else
			printf("本题错误！");
	}
	for (j = 1; j <= 10; j++)
	{
		printf("\n\n\n%d.\n%s", j, test2[j].a);
		printf("\n考生答案：%c", answer2[j]);
		printf("\n标准答案：%c", test2[j].right);
		if (answer2[j] == test2[j].right)
			printf("本题正确！");
		else
			printf("本题错误！");
	}
	printf("你的成绩是：%d", student.score);
	fp = fopen("num_name", "a");
	if (fp == NULL)
	{
		printf("ERROR!");
		exit(0);
	}
	fwrite(&student, sizeof(struct inf), 1, fp);  //把成绩写入文件中
	fclose(fp);
	system("PAUSE");
	return 0;
}

void analyse() {
	int j,k;
	system("CLS");
	int i, sum = 0, group[11] = { 0 };
	float ave;
	struct inf student[80];
	FILE *fp;
	fp = fopen("num_name", "r");
	if (fp == NULL) {
		printf("ERROR!");
		exit(0);
	}
	for (i = 1; !feof(fp); i++)
	{
		fread(&student[i], sizeof(struct inf), 1, fp);
	}

    i--;
	for (j = 1; j<i; j++)
		for (k = j; k <= i; k++)     //对成绩进行排序
			if (student[j].num>student[k].num) {
				student[79].num = student[k].num;
				student[79].score = student[k].score;
				student[k].num = student[j].num;
				student[k].score = student[j].score;
				student[j].num = student[79].num;
				student[j].score = student[79].score;
			}
	printf("学号\t\t成绩");
	i--;
	for (j = 1; j <= i; j++) {
		printf("\n%d\t\t%d", student[j].num, student[j].score);//打印结果
		sum += student[j].score;   //统计总分
	}
	ave = sum / (float)i;
	for (j = 1; j <= i; j++) {
		switch (student[j].score / 10) {
		case 10:group[10]++; break;
		case  9:group[9]++; break;
		case  8:group[8]++; break;
		case  7:group[7]++; break;
		case  6:group[6]++; break;
		case  5:group[5]++; break;
		case  4:group[4]++; break;
		case  3:group[3]++; break;
		case  2:group[2]++; break;
		case  1:group[1]++; break;
		case  0:group[0]++; break;
		}
	}
	printf("\n最高分：%d\t学号：%d", student[i].score, student[i].num);
	printf("\n最低分：%d\t学号：%d", student[1].score, student[1].num);
	printf("\n平均分：%f\t人数：%d", ave, i);
	printf("\n成绩分布统计：\n");
	printf("满分人数为：%d\n", group[10]);
	for (j = 9; j >= 0; j--)
		printf("%-2d~%2d区间人数为%d\n", 10 * j, 10 * j + 9, group[j]);
	system("PAUSE");
}

