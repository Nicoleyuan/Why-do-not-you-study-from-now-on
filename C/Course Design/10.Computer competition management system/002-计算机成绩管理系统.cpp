#include <stdio.h>/*输入、输出函数*/
#include <Windows.h>/*系统头文件*/
#include <string.h>/*字符串处理函数*/
#include <conio.h>/*控制台输入输出*/
#include <stdlib.h>/*实用工具函数*/
#include <time.h>
#define N 1
struct member//定义结构体保存选手信息 
{
	int bid,score[6],sum;//
	char name[20],classroom[20],topic[30];
	struct member *next;
}; 
typedef struct member link;
void welcome();//欢迎界面函数 
int menu();//主菜单函数 
struct member *creat();//信息录入
struct member *show(link *h);//信息显示 
struct member *order1(link *h); //排序函数（按编号排序） 
struct member *order2(link *h); //排序函数（按成绩排序） 
struct member *insert(link *news);//信息添加 
struct member *change(link *h);//信息修改
void copy(link *pa,link *pb);//交换结构体数据函数 
struct member *del(link *h);//信息删除
struct member *del_all(link *h);//删除全部数据 
void search(link *h);//信息查询 
void sort(link *h);//信息统计 
void points();//提示函数
struct member *read();//读取文件函数 
void save(link *h);//保存数据函数 
int sum_num=0;//定义全局变量sum_num表示总人数 
void welcome()//欢迎界面函数 
{	int i,j;
	for(i=0;i<6;i++)
	{
	system("cls");
	for(j=0;j<i;j++)//显示欢迎界面 
	printf("\n");	
	printf("\t\t\t   欢迎进入");
	printf("\n\t\t\t计算机操作系统");
	Sleep(200);
	}
}
int menu()//主菜单函数 
{
	int choice;
		//显示主菜单 
		system("cls");
		printf("\n\n\n\n\n\n");
		printf("\t\t\t\t     菜单选择");
		printf("\n\t\t\t****************************************\n");
		printf("\t\t\t*\t\t\t\t       *");
		printf("\n\t\t\t*\t1. 信息录入\t\t       *"); 
		printf("\n\t\t\t*\t2. 信息显示\t\t       *");
		printf("\n\t\t\t*\t3. 信息添加\t\t       *");
		printf("\n\t\t\t*\t4. 信息修改\t\t       *");
		printf("\n\t\t\t*\t5. 信息删除\t\t       *");
		printf("\n\t\t\t*\t6. 信息查询\t\t       *");
		printf("\n\t\t\t*\t7. 信息统计\t\t       *");
		printf("\n\t\t\t*\t8. 提示  \t\t       *");
		printf("\n\t\t\t*\t0. 退出  \t\t       *");
		printf("\n\t\t\t****************************************\n"); 
	printf("请输入选择：\n");
	scanf("%d",&choice); 
	return choice; 
}
struct member *creat()//信息录入 
{	
	int i;
	link *head,*tail,*news;
	sum_num=0;
	head=NULL;//建立空链表 
	do
	{
	tail=news;
	news=(struct member *)malloc(sizeof(struct member));//申请新结点用于存储信息 
	if(head==NULL)
	{
		head=tail=news;
		tail->bid=0;
	}
	else 
	tail->next=news;//让新结构体指针指向链尾 
	printf("选手%d:\n",tail->bid+1);
	news->bid=tail->bid+1;
	printf("请输入姓名：(当姓名为“NULL”后不再输入)\n");
	scanf("%s",news->name);
	printf("隶属班级："); 
	scanf("%s",news->classroom);
	printf("参赛课题："); 
	scanf("%s",news->topic);
	printf("评委打分(0~10)随机生成~\n");
	srand((int)time(NULL));
	for(i=0;i<6;i++)
	{
	   news->score[i]=rand()%11;
	}
	news->sum=0;//计算总成绩（初始化为0） 
	for(i=0;i<6;i++)
	news->sum+=news->score[i];
	sum_num++;
	news->next=NULL;
	}while(strcmp(news->name,"NULL")!=0);
	tail->next=NULL;
	free(news);
	sum_num--;
	save(head);
	printf("录入成功！");
	getch(); 
	return head;
}
struct member *show(link *h)//信息显示 
{
	link *p1;
	int k;
	p1=h;
	while(1)
	{    
		system("cls");//显示二级菜单 
		printf("\n\n\n\n\n\n");
		printf("\t\t\t\t1. 按选手编号顺序显示\n");
		printf("\t\t\t\t2. 按竞赛成绩顺序显示\n");
		printf("\t\t\t\t0. 返回上一级目录\n");
		printf("请输入选择：\n");
		scanf("%d",&k);
		switch(k)
		{
			case 1:
			p1=order1(h);//按编号进行排序 
			break;
			case 2:
			p1=order2(h);//按总成绩进行排序 
			break;
			case 0:
			return h;//返回头指针，退出显示函数 
			break;
			default:
			printf("请输入限定的选项！");
			break;
		}
		if(k==1||k==2)//显示选手信息
		{
		if(h==NULL)
		{
		printf("当前没有选手信息录入！\n");
		getch();
		} 
		else
		{
			system("cls");
			printf("\n\n\n\n");
			printf("*****************************************************************************\n");
			printf("编号：姓名：隶属班级：参赛课题：评委打分：1    2    3    4     5     6    总分：\n");
			for(;p1!=NULL;p1=p1->next)//依次显示选手信息 
			{
			printf(" %2d    %-6s %-4s      %-6s           %2d   %2d   %2d   %2d    %2d    %2d     %2d\n",
			p1->bid,p1->name,p1->classroom,p1->topic,p1->score[0],p1->score[1],p1->score[2],p1->score[3],p1->score[4],p1->score[5],p1->sum);
			} 
			printf("按任意键返回......"); 
			getch();
		}
		}
	}
	return h;
}
struct member *order1(link *h)//按编号排序 
{
	link *p1,*p2;
	link t;
	for(p1=p2=h;p1!=NULL;p1=p1->next)
		for(p2=p1->next;p2!=NULL;p2=p2->next)
		if(p1->bid>p2->bid)
		{
			copy(&t,p1);
			copy(p1,p2);
			copy(p2,&t);
		}
	return h;
}
struct member *order2(link *h)//按总成绩排序 
{
	link *p1,*p2;
	link t;
	for(p1=p2=h;p1!=NULL;p1=p1->next)
		for(p2=p1->next;p2!=NULL;p2=p2->next)
		if(p1->sum>p2->sum)//交换两个指针指向的结构体中数据 
		{
		copy(&t,p1);
		copy(p1,p2);
		copy(p2,&t);
		}
	return h;
}
void copy(link *pa,link *pb)//交换结构体数据函数 
{
	int i;
	pa->bid=pb->bid;
	strcpy(pa->name,pb->name);
	strcpy(pa->classroom,pb->classroom);
	strcpy(pa->topic,pb->topic);
	for(i=0;i<6;i++)
	{
		pa->score[i]=pb->score[i];
	}
	pa->sum=pb->sum;
}
struct member *insert(link *h)//信息添加 
{
	int i,k=1;
	link *news,*tail;
	news=tail=h;
	while(news!=NULL)
	{
		tail=news;
		news=news->next;
	}
	news=(struct member *)malloc(sizeof(struct member));
	if(h==NULL)
	{
		h=tail=news;
		h->bid=0;
	}
	else 
	tail->next=news;
	printf("选手%d:\n",tail->bid+1);
	printf("请输入姓名：(当姓名为“NULL”时不再输入)\n");
	scanf("%s",news->name);
	if(strcmp(news->name,"NULL")==0)
	{
		news=NULL; 
		printf("\n\n\n\n\t\t\t返回中......");
		Sleep(80);
		return h;
	}
	news->bid=tail->bid+1;
	printf("隶属班级："); 
	scanf("%s",news->classroom);
	printf("参赛课题："); 
	scanf("%s",news->topic);
	printf("评委打分(0~10)随机生成~\n");
	getch();
	srand((int)time(NULL));
	for(i=0;i<6;i++)
	{
	   news->score[i]=rand()%11;
	}
	news->sum=0;
	for(i=0;i<6;i++)
	news->sum+=news->score[i];
	sum_num++;
	news->next=NULL;
	printf("\n添加成功!\n");
	getch(); 
	return h;
}
struct member *change(link *h)//这里对姓名不加限定！！！ 
{
	link *p1;
	int k,i,choice,flag;
	system("cls");
	printf("\n\n\n\n\t请输入需要修改的选手信息的编号:");
	scanf("%d",&k);
	for(p1=h;p1!=NULL;p1=p1->next) 
	if(p1->bid==k) 
	{ flag=1;
	printf("*****************************************************************************\n");
	printf("编号：姓名：隶属班级：参赛课题：评委打分：1    2    3    4     5     6    总分：\n");
	printf(" %2d    %-6s %-4s      %-6s           %2d   %2d   %2d   %2d    %2d    %2d     %2d\n",
	p1->bid,p1->name,p1->classroom,p1->topic,p1->score[0],p1->score[1],p1->score[2],p1->score[3],p1->score[4],p1->score[5],p1->sum);
	printf("\t1.修改姓名\t2.修改班级\t3.修改课题\n\t4.修改全部\t0.返回\n");
	while(flag)
	{
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: 
			printf("请输入姓名："); 
			scanf("%s",p1->name); 
			printf("\t修改成功！\n");
			break;
			case 2:
			printf("隶属班级："); 
			scanf("%s",p1->classroom);
			printf("\t修改成功！\n");  
			break;
			case 3:
			printf("参赛课题："); 
			scanf("%s",p1->topic);
			printf("\t修改成功！\n"); 
			break;
			case 4:
			printf("请输入姓名：");
			scanf("%s",p1->name);
			printf("隶属班级："); 
			scanf("%s",p1->classroom);
			printf("参赛课题："); 
			scanf("%s",p1->topic);
			printf("\t修改成功！\n");
			break;
			case 0: flag=0; break;
			default: printf("输入错误！\n");
			break;
		} 
		save(h);
	}
	return h;
	}
	printf("\t该编号的选手信息尚未被录入！\n\t输入任意键返回上一层......\n");
	getch();
	return h;
}
struct member *del(link *h)
{   int choice,flag;
	char s[20];
	link *p1=h,*p2;
	system("cls");
	printf("\n\n\n\n\n\t请输入您需要删除的选手信息的姓名：\n");
	scanf("%s",s);
	if(h==NULL)
	{
		printf("当前未有信息录入，无法执行删除");
		getchar();
		return h; 
	}
	if(strcmp(h->name,s)==0)
	{
		printf("*****************************************************************************\n");
		printf("编号：姓名：隶属班级：参赛课题：评委打分：1    2    3    4     5     6    总分：\n");
		printf(" %2d    %-6s %-4s      %-6s           %2d   %2d   %2d   %2d    %2d    %2d     %2d\n",
		p1->bid,p1->name,p1->classroom,p1->topic,p1->score[0],p1->score[1],p1->score[2],p1->score[3],p1->score[4],p1->score[5],p1->sum);
		printf("请确认是否要删除该选手信息：\n\t1.删除\t2.不删除并返回\n");
		scanf("%d",&choice);
		flag=1;
		while(flag)
		switch(choice)
		{
			case 1:
			p1=h;
			h=h->next;
			free(p1);
			save(h);
			printf("删除成功！\n");
			getch();
			return h;
			break;
			case 2: flag=0; break;
			default: printf("请输入1(删除)或2(不删除)选项:\n"); 
			break; 
	    }
		printf("该选手信息没有被删除！\n"); getch();
		return h;	
	}
	for(p2=p1->next;p2!=NULL;) 
	{
		if(strcmp(p2->name,s)==0) 
	{
		printf("*****************************************************************************\n");
		printf("编号：姓名：隶属班级：参赛课题：评委打分：1    2    3    4     5     6    总分：\n");
		printf(" %2d    %-6s %-4s      %-6s           %2d   %2d   %2d   %2d    %2d    %2d     %2d\n",
		p2->bid,p2->name,p2->classroom,p2->topic,p2->score[0],p2->score[1],p2->score[2],p2->score[3],p2->score[4],p2->score[5],p2->sum);
		printf("请确认是否要删除该选手信息：\n\t1.删除\t2.不删除并返回\n");
		scanf("%d",&choice);
		flag=1;
		while(flag)
		switch(choice)
		{
		case 1:
		p1->next=p2->next;
		sum_num--;
		free(p2);
		save(h);
		printf("\t删除成功！\n");
		getch();
		return h;
		break;
		case 2: flag=0; break;
		default: printf("请输入1(删除)或2(不删除)选项:\n"); 
		break; 
		}
		printf("该选手信息没有被删除！\n"); getch();
		return h;
	}
	p1=p2;
	p2=p1->next;
	}  
	printf("\t该编号的选手信息尚未被录入!\n");
	getch();
	return h;
}
struct member *del_all(link *h)
{
	link *p1,*p2;
	for(p1=p2=h;p1;)
	{
		p2=p1;
		p1=p1->next;
		free(p2);
	}
	return NULL;
 } 
void search(link *h)//查询函数 
{	link *p1;
	int k;
	system("cls");
	printf("\n\n\n\n\n\t\t\t请输入您要查询的选手信息的编号：\n");
	scanf("%d",&k);
	for(p1=h;p1!=NULL;p1=p1->next) 
	{
		if(p1->bid==k) 
		{
		printf("\n\n\n\n");
		printf("*****************************************************************************\n");
		printf("编号：姓名：隶属班级：参赛课题：评委打分：1    2    3    4    5    6    总分：\n");
		printf("  %d   %-5s   %-4s      %-4s              %d    %d    %d    %d    %d    %d     %d\n",
		p1->bid,p1->name,p1->classroom,p1->topic,p1->score[0],p1->score[1],p1->score[2],p1->score[3],p1->score[4],p1->score[5],p1->sum);
		getch();
		return;
		}
	}
	if(p1==NULL)
	{
	printf("该编号的选手信息尚未被录入！\n");
	getch();
	}
}
void sort(link *h)
{
	int k,m,choice,count,count1;
	char s[20];
	link *p1;
	system("cls");
	printf("\n\n\n");
	printf("\t\t\t******************************************************\n");
	printf("\t\t\t1.根据成绩进行统计\n\t\t\t2.根据班级进行统计\n\t\t\t0.返回上一级目录\n"); 
	while(1)
	{	printf("请输入选项：\n");
		scanf("%d",&k);
		if(k==0)  break;
		switch(k)
		{
		case 1: count1=0;
			printf("请输入一个成绩作为临界，将显示得分大于该成绩的选手信息：\n");
			scanf("%d",&m);
			printf("*****************************************************************************\n");
			printf("编号：姓名：隶属班级：参赛课题：评委打分：1    2    3    4     5     6    总分：\n");
			for(p1=h;p1!=NULL;p1=p1->next)			
			if(p1->sum>m)
			{
				printf(" %2d    %-6s %-4s      %-6s           %2d   %2d   %2d   %2d    %2d    %2d     %2d\n",
			p1->bid,p1->name,p1->classroom,p1->topic,p1->score[0],p1->score[1],p1->score[2],p1->score[3],p1->score[4],p1->score[5],p1->sum);
				count1++;
			}
			if(count1==0) printf("没有大于该成绩的选手的信息被录入！\n");
			break;
		case 2:
			count=0;
			printf("请输入班级：\n");
			scanf("%s",s);
			for(p1=h;p1!=NULL;p1=p1->next)
			if(strcmp(p1->classroom,s)==0)
			count++; 
			printf("该班级参赛人数为: %d人\n",count);
			if(count)
			{
			printf("是否显示这些选手的信息?\n输入 1 将显示信息，输入其他数字不显示信息\n");
			scanf("%d",&choice);
			if(choice==1)
			{
			printf("编号：姓名：隶属班级：参赛课题：评委打分：1    2    3    4     5     6    总分：\n");
			for(p1=h;p1!=NULL;p1=p1->next)
			if(strcmp(p1->classroom,s)==0)
		    printf(" %2d    %-6s %-4s      %-6s           %2d   %2d   %2d   %2d    %2d    %2d     %2d\n",
			p1->bid,p1->name,p1->classroom,p1->topic,p1->score[0],p1->score[1],p1->score[2],p1->score[3],p1->score[4],p1->score[5],p1->sum);
			}
			}
			break;
		default: break;
		}
	}
}
struct member *read()
{
	FILE *fp;
	int k;
	link *p1,*p2,*h;
	p1=p1=h=NULL;
	fp=fopen("计算机管理系统.txt","r");
	if(fp==NULL) return NULL;
	while(!feof(fp))
	{
		p2=p1;
		p1=(link *)malloc(sizeof(link));
		k=fread(p1,sizeof(link),1,fp);
		if(k!=1)
		if(h==NULL) return NULL;
		if(h==NULL)
		h=p1;
		else p2->next=p1;
	}
	p2->next=NULL;
	fclose(fp);
	return h;
}
void save(link *h)
{
	FILE *fp;
	link *p1=h;
	fp=fopen("计算机管理系统.txt","w");
	if(h==NULL)
	{
		printf("数据保存失败！(无数据录入)\n");
		getch();
		return;
	}
	while(p1!=NULL)
	{
		fwrite(p1,sizeof(link),1,fp);
		p1=p1->next;
	}
	fclose(fp);
}
void points()
{	
	printf("\t计算机竞赛管理系统提示功能：\n");
	printf("\t首先打开系统，进入主菜单。\n");
	printf("\t1.信息录入：可以录入选手信息。当姓名输入为“NULL”后，继续输入余下数据，便可退出该功能。\n");
	printf("\t  “NULL”选手信息不保存，例如可以将成绩都输入为0。成绩请输入0~10之间的数字，若输入字母，\n");
	printf("\t  可能导致系统中断！（对以下功能同样适用）注：信息录入将重置数据库，以前的数据将被删除。\n");
	printf("\t  故信息录入功能也可以用于删除所有数据。\n");
	printf("\t2.信息显示：可以将已有的选手信息按一定顺序显示，用于查看。\n");
	printf("\t3.信息添加：一次可以添加一名选手的信息。\n");
	printf("\t4.信息修改：需要输入保存的选手信息编号，可对该选手信息进行更改。\n");
	printf("\t5.信息删除：输入要指定的选手姓名，可将该选手信息删除。\n");
	printf("\t6.信息查询：输入要查询的选手信息编号，即可显示该选手信息。\n");
	printf("\t7.信息统计：可以显示成绩高于用户输入的分数的选手信息和计算一个班级的选手人数并显示信息。\n");
	printf("\t8.退出：将正常退出系统。\n");
	printf("\t9.注：请从主菜单正常退出，以确保数据的完整保存！\n");
	printf("\t  如果您想删除所有选手信息，可以使用录入功能。");
	printf("\t  请保证录入功能下输入的第一个选手的姓名不是 NULL\n");
	printf("输入任意键返回...");
	getch();
}
int main()
{
	struct member *head;
	int choice;
	printf("\n\n\n\n\n\t文件读取中\n");
	head=read();
	welcome();
	while(1) 
	{
	choice=menu();
	switch(choice)
	{
		case 1:
		head=del_all(head);
		head=creat();//录入会使原数据消失！！！ 
		break; 
		case 2:
		head=show(head);
		break;
		case 3:
		head=insert(head);
		break;
		case 4:
		head=change(head);
		break;
		case 5:
		head=del(head);
		break;
		case 6:
		search(head);
		break;
		case 7:
		sort(head);
		break;
		case 8:
		points();
		break;
		case 0:
	    save(head);
		printf("数据保存成功！"); 
		return 0;
		break;
		default:
		printf("输入出错，请选择规定的选项!\n");//输入字母会出错！ 
		printf("输入任意键返回菜单......");	
		getch();//之前忘了！ 
		break;
	}
	}
	return 0;
}