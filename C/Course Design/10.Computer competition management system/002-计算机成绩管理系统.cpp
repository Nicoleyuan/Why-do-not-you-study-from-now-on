#include <stdio.h>/*���롢�������*/
#include <Windows.h>/*ϵͳͷ�ļ�*/
#include <string.h>/*�ַ���������*/
#include <conio.h>/*����̨�������*/
#include <stdlib.h>/*ʵ�ù��ߺ���*/
#include <time.h>
#define N 1
struct member//����ṹ�屣��ѡ����Ϣ 
{
	int bid,score[6],sum;//
	char name[20],classroom[20],topic[30];
	struct member *next;
}; 
typedef struct member link;
void welcome();//��ӭ���溯�� 
int menu();//���˵����� 
struct member *creat();//��Ϣ¼��
struct member *show(link *h);//��Ϣ��ʾ 
struct member *order1(link *h); //����������������� 
struct member *order2(link *h); //�����������ɼ����� 
struct member *insert(link *news);//��Ϣ��� 
struct member *change(link *h);//��Ϣ�޸�
void copy(link *pa,link *pb);//�����ṹ�����ݺ��� 
struct member *del(link *h);//��Ϣɾ��
struct member *del_all(link *h);//ɾ��ȫ������ 
void search(link *h);//��Ϣ��ѯ 
void sort(link *h);//��Ϣͳ�� 
void points();//��ʾ����
struct member *read();//��ȡ�ļ����� 
void save(link *h);//�������ݺ��� 
int sum_num=0;//����ȫ�ֱ���sum_num��ʾ������ 
void welcome()//��ӭ���溯�� 
{	int i,j;
	for(i=0;i<6;i++)
	{
	system("cls");
	for(j=0;j<i;j++)//��ʾ��ӭ���� 
	printf("\n");	
	printf("\t\t\t   ��ӭ����");
	printf("\n\t\t\t���������ϵͳ");
	Sleep(200);
	}
}
int menu()//���˵����� 
{
	int choice;
		//��ʾ���˵� 
		system("cls");
		printf("\n\n\n\n\n\n");
		printf("\t\t\t\t     �˵�ѡ��");
		printf("\n\t\t\t****************************************\n");
		printf("\t\t\t*\t\t\t\t       *");
		printf("\n\t\t\t*\t1. ��Ϣ¼��\t\t       *"); 
		printf("\n\t\t\t*\t2. ��Ϣ��ʾ\t\t       *");
		printf("\n\t\t\t*\t3. ��Ϣ���\t\t       *");
		printf("\n\t\t\t*\t4. ��Ϣ�޸�\t\t       *");
		printf("\n\t\t\t*\t5. ��Ϣɾ��\t\t       *");
		printf("\n\t\t\t*\t6. ��Ϣ��ѯ\t\t       *");
		printf("\n\t\t\t*\t7. ��Ϣͳ��\t\t       *");
		printf("\n\t\t\t*\t8. ��ʾ  \t\t       *");
		printf("\n\t\t\t*\t0. �˳�  \t\t       *");
		printf("\n\t\t\t****************************************\n"); 
	printf("������ѡ��\n");
	scanf("%d",&choice); 
	return choice; 
}
struct member *creat()//��Ϣ¼�� 
{	
	int i;
	link *head,*tail,*news;
	sum_num=0;
	head=NULL;//���������� 
	do
	{
	tail=news;
	news=(struct member *)malloc(sizeof(struct member));//�����½�����ڴ洢��Ϣ 
	if(head==NULL)
	{
		head=tail=news;
		tail->bid=0;
	}
	else 
	tail->next=news;//���½ṹ��ָ��ָ����β 
	printf("ѡ��%d:\n",tail->bid+1);
	news->bid=tail->bid+1;
	printf("������������(������Ϊ��NULL����������)\n");
	scanf("%s",news->name);
	printf("�����༶��"); 
	scanf("%s",news->classroom);
	printf("�������⣺"); 
	scanf("%s",news->topic);
	printf("��ί���(0~10)�������~\n");
	srand((int)time(NULL));
	for(i=0;i<6;i++)
	{
	   news->score[i]=rand()%11;
	}
	news->sum=0;//�����ܳɼ�����ʼ��Ϊ0�� 
	for(i=0;i<6;i++)
	news->sum+=news->score[i];
	sum_num++;
	news->next=NULL;
	}while(strcmp(news->name,"NULL")!=0);
	tail->next=NULL;
	free(news);
	sum_num--;
	save(head);
	printf("¼��ɹ���");
	getch(); 
	return head;
}
struct member *show(link *h)//��Ϣ��ʾ 
{
	link *p1;
	int k;
	p1=h;
	while(1)
	{    
		system("cls");//��ʾ�����˵� 
		printf("\n\n\n\n\n\n");
		printf("\t\t\t\t1. ��ѡ�ֱ��˳����ʾ\n");
		printf("\t\t\t\t2. �������ɼ�˳����ʾ\n");
		printf("\t\t\t\t0. ������һ��Ŀ¼\n");
		printf("������ѡ��\n");
		scanf("%d",&k);
		switch(k)
		{
			case 1:
			p1=order1(h);//����Ž������� 
			break;
			case 2:
			p1=order2(h);//���ܳɼ��������� 
			break;
			case 0:
			return h;//����ͷָ�룬�˳���ʾ���� 
			break;
			default:
			printf("�������޶���ѡ�");
			break;
		}
		if(k==1||k==2)//��ʾѡ����Ϣ
		{
		if(h==NULL)
		{
		printf("��ǰû��ѡ����Ϣ¼�룡\n");
		getch();
		} 
		else
		{
			system("cls");
			printf("\n\n\n\n");
			printf("*****************************************************************************\n");
			printf("��ţ������������༶���������⣺��ί��֣�1    2    3    4     5     6    �ܷ֣�\n");
			for(;p1!=NULL;p1=p1->next)//������ʾѡ����Ϣ 
			{
			printf(" %2d    %-6s %-4s      %-6s           %2d   %2d   %2d   %2d    %2d    %2d     %2d\n",
			p1->bid,p1->name,p1->classroom,p1->topic,p1->score[0],p1->score[1],p1->score[2],p1->score[3],p1->score[4],p1->score[5],p1->sum);
			} 
			printf("�����������......"); 
			getch();
		}
		}
	}
	return h;
}
struct member *order1(link *h)//��������� 
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
struct member *order2(link *h)//���ܳɼ����� 
{
	link *p1,*p2;
	link t;
	for(p1=p2=h;p1!=NULL;p1=p1->next)
		for(p2=p1->next;p2!=NULL;p2=p2->next)
		if(p1->sum>p2->sum)//��������ָ��ָ��Ľṹ�������� 
		{
		copy(&t,p1);
		copy(p1,p2);
		copy(p2,&t);
		}
	return h;
}
void copy(link *pa,link *pb)//�����ṹ�����ݺ��� 
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
struct member *insert(link *h)//��Ϣ��� 
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
	printf("ѡ��%d:\n",tail->bid+1);
	printf("������������(������Ϊ��NULL��ʱ��������)\n");
	scanf("%s",news->name);
	if(strcmp(news->name,"NULL")==0)
	{
		news=NULL; 
		printf("\n\n\n\n\t\t\t������......");
		Sleep(80);
		return h;
	}
	news->bid=tail->bid+1;
	printf("�����༶��"); 
	scanf("%s",news->classroom);
	printf("�������⣺"); 
	scanf("%s",news->topic);
	printf("��ί���(0~10)�������~\n");
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
	printf("\n��ӳɹ�!\n");
	getch(); 
	return h;
}
struct member *change(link *h)//��������������޶������� 
{
	link *p1;
	int k,i,choice,flag;
	system("cls");
	printf("\n\n\n\n\t��������Ҫ�޸ĵ�ѡ����Ϣ�ı��:");
	scanf("%d",&k);
	for(p1=h;p1!=NULL;p1=p1->next) 
	if(p1->bid==k) 
	{ flag=1;
	printf("*****************************************************************************\n");
	printf("��ţ������������༶���������⣺��ί��֣�1    2    3    4     5     6    �ܷ֣�\n");
	printf(" %2d    %-6s %-4s      %-6s           %2d   %2d   %2d   %2d    %2d    %2d     %2d\n",
	p1->bid,p1->name,p1->classroom,p1->topic,p1->score[0],p1->score[1],p1->score[2],p1->score[3],p1->score[4],p1->score[5],p1->sum);
	printf("\t1.�޸�����\t2.�޸İ༶\t3.�޸Ŀ���\n\t4.�޸�ȫ��\t0.����\n");
	while(flag)
	{
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: 
			printf("������������"); 
			scanf("%s",p1->name); 
			printf("\t�޸ĳɹ���\n");
			break;
			case 2:
			printf("�����༶��"); 
			scanf("%s",p1->classroom);
			printf("\t�޸ĳɹ���\n");  
			break;
			case 3:
			printf("�������⣺"); 
			scanf("%s",p1->topic);
			printf("\t�޸ĳɹ���\n"); 
			break;
			case 4:
			printf("������������");
			scanf("%s",p1->name);
			printf("�����༶��"); 
			scanf("%s",p1->classroom);
			printf("�������⣺"); 
			scanf("%s",p1->topic);
			printf("\t�޸ĳɹ���\n");
			break;
			case 0: flag=0; break;
			default: printf("�������\n");
			break;
		} 
		save(h);
	}
	return h;
	}
	printf("\t�ñ�ŵ�ѡ����Ϣ��δ��¼�룡\n\t���������������һ��......\n");
	getch();
	return h;
}
struct member *del(link *h)
{   int choice,flag;
	char s[20];
	link *p1=h,*p2;
	system("cls");
	printf("\n\n\n\n\n\t����������Ҫɾ����ѡ����Ϣ��������\n");
	scanf("%s",s);
	if(h==NULL)
	{
		printf("��ǰδ����Ϣ¼�룬�޷�ִ��ɾ��");
		getchar();
		return h; 
	}
	if(strcmp(h->name,s)==0)
	{
		printf("*****************************************************************************\n");
		printf("��ţ������������༶���������⣺��ί��֣�1    2    3    4     5     6    �ܷ֣�\n");
		printf(" %2d    %-6s %-4s      %-6s           %2d   %2d   %2d   %2d    %2d    %2d     %2d\n",
		p1->bid,p1->name,p1->classroom,p1->topic,p1->score[0],p1->score[1],p1->score[2],p1->score[3],p1->score[4],p1->score[5],p1->sum);
		printf("��ȷ���Ƿ�Ҫɾ����ѡ����Ϣ��\n\t1.ɾ��\t2.��ɾ��������\n");
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
			printf("ɾ���ɹ���\n");
			getch();
			return h;
			break;
			case 2: flag=0; break;
			default: printf("������1(ɾ��)��2(��ɾ��)ѡ��:\n"); 
			break; 
	    }
		printf("��ѡ����Ϣû�б�ɾ����\n"); getch();
		return h;	
	}
	for(p2=p1->next;p2!=NULL;) 
	{
		if(strcmp(p2->name,s)==0) 
	{
		printf("*****************************************************************************\n");
		printf("��ţ������������༶���������⣺��ί��֣�1    2    3    4     5     6    �ܷ֣�\n");
		printf(" %2d    %-6s %-4s      %-6s           %2d   %2d   %2d   %2d    %2d    %2d     %2d\n",
		p2->bid,p2->name,p2->classroom,p2->topic,p2->score[0],p2->score[1],p2->score[2],p2->score[3],p2->score[4],p2->score[5],p2->sum);
		printf("��ȷ���Ƿ�Ҫɾ����ѡ����Ϣ��\n\t1.ɾ��\t2.��ɾ��������\n");
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
		printf("\tɾ���ɹ���\n");
		getch();
		return h;
		break;
		case 2: flag=0; break;
		default: printf("������1(ɾ��)��2(��ɾ��)ѡ��:\n"); 
		break; 
		}
		printf("��ѡ����Ϣû�б�ɾ����\n"); getch();
		return h;
	}
	p1=p2;
	p2=p1->next;
	}  
	printf("\t�ñ�ŵ�ѡ����Ϣ��δ��¼��!\n");
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
void search(link *h)//��ѯ���� 
{	link *p1;
	int k;
	system("cls");
	printf("\n\n\n\n\n\t\t\t��������Ҫ��ѯ��ѡ����Ϣ�ı�ţ�\n");
	scanf("%d",&k);
	for(p1=h;p1!=NULL;p1=p1->next) 
	{
		if(p1->bid==k) 
		{
		printf("\n\n\n\n");
		printf("*****************************************************************************\n");
		printf("��ţ������������༶���������⣺��ί��֣�1    2    3    4    5    6    �ܷ֣�\n");
		printf("  %d   %-5s   %-4s      %-4s              %d    %d    %d    %d    %d    %d     %d\n",
		p1->bid,p1->name,p1->classroom,p1->topic,p1->score[0],p1->score[1],p1->score[2],p1->score[3],p1->score[4],p1->score[5],p1->sum);
		getch();
		return;
		}
	}
	if(p1==NULL)
	{
	printf("�ñ�ŵ�ѡ����Ϣ��δ��¼�룡\n");
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
	printf("\t\t\t1.���ݳɼ�����ͳ��\n\t\t\t2.���ݰ༶����ͳ��\n\t\t\t0.������һ��Ŀ¼\n"); 
	while(1)
	{	printf("������ѡ�\n");
		scanf("%d",&k);
		if(k==0)  break;
		switch(k)
		{
		case 1: count1=0;
			printf("������һ���ɼ���Ϊ�ٽ磬����ʾ�÷ִ��ڸóɼ���ѡ����Ϣ��\n");
			scanf("%d",&m);
			printf("*****************************************************************************\n");
			printf("��ţ������������༶���������⣺��ί��֣�1    2    3    4     5     6    �ܷ֣�\n");
			for(p1=h;p1!=NULL;p1=p1->next)			
			if(p1->sum>m)
			{
				printf(" %2d    %-6s %-4s      %-6s           %2d   %2d   %2d   %2d    %2d    %2d     %2d\n",
			p1->bid,p1->name,p1->classroom,p1->topic,p1->score[0],p1->score[1],p1->score[2],p1->score[3],p1->score[4],p1->score[5],p1->sum);
				count1++;
			}
			if(count1==0) printf("û�д��ڸóɼ���ѡ�ֵ���Ϣ��¼�룡\n");
			break;
		case 2:
			count=0;
			printf("������༶��\n");
			scanf("%s",s);
			for(p1=h;p1!=NULL;p1=p1->next)
			if(strcmp(p1->classroom,s)==0)
			count++; 
			printf("�ð༶��������Ϊ: %d��\n",count);
			if(count)
			{
			printf("�Ƿ���ʾ��Щѡ�ֵ���Ϣ?\n���� 1 ����ʾ��Ϣ�������������ֲ���ʾ��Ϣ\n");
			scanf("%d",&choice);
			if(choice==1)
			{
			printf("��ţ������������༶���������⣺��ί��֣�1    2    3    4     5     6    �ܷ֣�\n");
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
	fp=fopen("���������ϵͳ.txt","r");
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
	fp=fopen("���������ϵͳ.txt","w");
	if(h==NULL)
	{
		printf("���ݱ���ʧ�ܣ�(������¼��)\n");
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
	printf("\t�������������ϵͳ��ʾ���ܣ�\n");
	printf("\t���ȴ�ϵͳ���������˵���\n");
	printf("\t1.��Ϣ¼�룺����¼��ѡ����Ϣ������������Ϊ��NULL���󣬼��������������ݣ�����˳��ù��ܡ�\n");
	printf("\t  ��NULL��ѡ����Ϣ�����棬������Խ��ɼ�������Ϊ0���ɼ�������0~10֮������֣���������ĸ��\n");
	printf("\t  ���ܵ���ϵͳ�жϣ��������¹���ͬ�����ã�ע����Ϣ¼�뽫�������ݿ⣬��ǰ�����ݽ���ɾ����\n");
	printf("\t  ����Ϣ¼�빦��Ҳ��������ɾ���������ݡ�\n");
	printf("\t2.��Ϣ��ʾ�����Խ����е�ѡ����Ϣ��һ��˳����ʾ�����ڲ鿴��\n");
	printf("\t3.��Ϣ��ӣ�һ�ο������һ��ѡ�ֵ���Ϣ��\n");
	printf("\t4.��Ϣ�޸ģ���Ҫ���뱣���ѡ����Ϣ��ţ��ɶԸ�ѡ����Ϣ���и��ġ�\n");
	printf("\t5.��Ϣɾ��������Ҫָ����ѡ���������ɽ���ѡ����Ϣɾ����\n");
	printf("\t6.��Ϣ��ѯ������Ҫ��ѯ��ѡ����Ϣ��ţ�������ʾ��ѡ����Ϣ��\n");
	printf("\t7.��Ϣͳ�ƣ�������ʾ�ɼ������û�����ķ�����ѡ����Ϣ�ͼ���һ���༶��ѡ����������ʾ��Ϣ��\n");
	printf("\t8.�˳����������˳�ϵͳ��\n");
	printf("\t9.ע��������˵������˳�����ȷ�����ݵ��������棡\n");
	printf("\t  �������ɾ������ѡ����Ϣ������ʹ��¼�빦�ܡ�");
	printf("\t  �뱣֤¼�빦��������ĵ�һ��ѡ�ֵ��������� NULL\n");
	printf("�������������...");
	getch();
}
int main()
{
	struct member *head;
	int choice;
	printf("\n\n\n\n\n\t�ļ���ȡ��\n");
	head=read();
	welcome();
	while(1) 
	{
	choice=menu();
	switch(choice)
	{
		case 1:
		head=del_all(head);
		head=creat();//¼���ʹԭ������ʧ������ 
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
		printf("���ݱ���ɹ���"); 
		return 0;
		break;
		default:
		printf("���������ѡ��涨��ѡ��!\n");//������ĸ����� 
		printf("������������ز˵�......");	
		getch();//֮ǰ���ˣ� 
		break;
	}
	}
	return 0;
}