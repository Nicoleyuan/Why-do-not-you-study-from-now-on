#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<malloc.h>
#include<time.h>
#define LEN sizeof(struct readerinf)
#define LON sizeof(struct bookinf)
FILE *pf,*pb;
struct borrow                /*���屻��ͼ�����Ϣ*/
{
	long int book;
    int outyear;             /*Ϊ�鿴�û���Ϣʱ�����Բ鿴�鱾����ʱ������*/
	int outmonth;
	int outday;
	long int tim;            /*Ϊ�򻯳��ں�������*/
};
struct bookinf                /*����ͼ��ṹ��*/
{
	char name[31];
	char author[21];
	char pubcompany[100];      /*������*/
	char pubdate[20];         /*����ʱ��*/
	int price;                /*�۸�*/
	long int ISBN;                 /*ͼ����*/
	char category[30];             /*����*/
    int condition;            /*�Ƿ��ڼ� 1:�ڼ� 0:�ѽ� 2:�ٽ�*/
	int borrowednum;          /*���Ĵ���*/
    struct bookinf *next;
};
struct readerinf              /*����ѧ���ṹ��*/
{
	char name[30]; 
	char sex[4]; 
	char birthday[20]; 	        /*��������*/
	char college[20];           /*ѧԺ*/
	char secretnum[10];         /*secretnum=(����-20)*2 */
	long int ID;                /*ѧ��*/
	char type[20];              /*��������*/
	int balance;                /*������*/
	int bornum;                 /*��ǰ������*/ 
	int outdatenum;             /*����ͼ����*/
	struct borrow b[30];        /*һ���ṹ���������¼ͼ��ͳ���ʱ��*/
	struct readerinf *next;		/*ָ����һλͬѧ��ָ��*/
};
struct readerinf *head1,*p1,*p2;
struct bookinf *head2,*b1,*b2;


void cuihuan();
/*�����Ƕ�ϵͳ����Աģ��ʹ�ú���������*/

void managementone();                                  /*�������Ա�ĸ��ֲ���*/
struct readerinf *creat();                             /*��ʼ��������*/ 
struct readerinf *addperson(struct readerinf *head);   /*����û�����*/
struct readerinf *delperson(struct readerinf *head);   /*ɾ���û�����*/
void showperson(struct readerinf *head);               /*�鿴�û���Ϣ*/
void delsecret(struct readerinf *head);                /*����û�����*/
void storagereader(struct readerinf *p);            /*��������Ϣ�����ļ�*/

/*�����Ƕ�ͼ�����Աģ��ʹ�ú���������*/
void managementtwo();                                  /*�������Ա�ĸ��ֲ���*/
struct bookinf *addbook(struct bookinf *head);        /*���ͼ��*/
struct bookinf *delbook(struct bookinf *head);        /*ɾ��ͼ��*/
void rewritebook(struct bookinf *b);                /*�޸�ͼ����Ϣ*/


/*�����ǶԶ���ģ�麯��ʹ�õ�����*/
struct readerinf *loadthree();                 /*��½*/
void operation();                                      /*������ߵĸ��ֲ���*/
struct bookinf *begin();                               /*��ʼ��������*/
void borrowbook(struct bookinf *b1,struct readerinf *p);                 /*����*/
void renewbook(struct readerinf *p);                  /*����*/  
void returnbook(struct readerinf *p);                 /*����*/
void checkbook(struct bookinf *b);                  /*����ͼ��*/
void rewritereader(struct readerinf *p3);            /*�޸Ķ�����Ϣ*/
void storagebook(struct bookinf *b);                /*��������Ϣ�����ļ�*/




int fh1=4;/*�����ϲ㹦�����裬�����޸�*/

char a[5]={'<','@','D','H'},c;/*ʵ������Ϊ2468*/

/*
�������ܣ�ѡ���û����ͣ������Ӧ��½����
*/
void main()
{   
	int op;
	while(1)
	{
		printf("\t\t|-----------------------------------------------|\n");
		printf("\t\t|\t\tͼ����Ĺ���ϵͳ                |\n");
		printf("\t\t|-----------------------------------------------|\n");
		printf("\t\t|\t\t��ѡ�����ֽ��в���              |\n");
		printf("\t\t|\t\t1.ϵͳ����Ա                    |\n");
		printf("\t\t|\t\t2.ͼ�����Ա                    |\n");
		printf("\t\t|\t\t3.���߲���                      |\n");
		printf("\t\t|\t\t4.�߻�֪ͨ                      |\n");
		printf("\t\t|\t\t5.�˳�ϵͳ                      |\n");
		printf("\t\t|\t\t������0--5!                     |\n");
		printf("\t\t|-----------------------------------------------|\n\n");
		printf("\n\n\n����������:");
		scanf("%d",&op);
		switch(op)
		{
		case 1:system("cls");
					managementone();break;		
		case 2:system("cls");
				   managementtwo();break;
		case 3:system("cls");
					if((p1=loadthree())!=NULL)			
		operation();break;
		case 4:system("cls");
			cuihuan();break;
		case 5:exit(0);break;
		
		default : printf("û�ж�Ӧ��ϵͳָ����֤����\n");
		}
	}
}

/*������ϵͳ����Աģ���еĺ�������*/



/*
�������ܣ�ϵͳ����Աѡ���Ӧ���ܣ����в���
*/
void managementone()                                   
{
	int choice=0;
	head1=creat();
	while(choice!=fh1)
	{   
		printf("\t\t|-----------------------------------------------|\n");
		printf("\t\t|\t\tͼ����Ĺ���ϵͳ                |\n");
		printf("\t\t|-----------------------------------------------|\n");
		printf("\t\t|\t\t����û��밴0                   |\n");
		printf("\t\t|\t\tɾ���û��밴1                   |\n");
		printf("\t\t|\t\t�鿴�û���Ϣ�밴2               |\n");
		printf("\t\t|\t\t����û������밴3               |\n");
		printf("\t\t|\t\t�����ϲ��밴4		        |\n");
		printf("\t\t|-----------------------------------------------|\n");
		printf("\n\n\n����������ѡ��:");
		scanf("%d",&choice);
		switch (choice)
		{
		case 0:
			system("cls");head1=addperson(head1);break; /*����û�*/
		case 1:system("cls");head1=delperson(head1);break; /*ɾ���û�*/
		case 2:system("cls");showperson(head1);break;    /*�鿴�û���Ϣ*/
		case 3:system("cls");delsecret(head1);break;     /*����û�����*/
		case 4:system("cls");choice=4;break;             /*����*/
		default: printf("û�ж�Ӧ��ϵͳָ����֤����\n");break;	
		}	
	}	
	storagereader(head1);
}


/*
�������ܣ���ȡ�ļ��е���Ϣ�����������ж�Ӧλ��
���������head--����ͷָ��
�������̣�
    1.���ļ�
	2.�ļ�û�н������ȡ�ļ���Ϣ����������
	3.�ļ������򷵻�ͷָ��
*/
struct readerinf *creat(void)       /*��ʼ��������Ϣ������*/
{
	int i;
	struct readerinf *head;
	pf=fopen("reader.txt","r+");
	if(pf==NULL)
	{
		printf("���ܴ��ļ�\n");
		exit(0);
	}
	if(pf==NULL)                /*���ļ�Ϊ���ļ�*/
		head=NULL;
	else
	{
		p2=(struct readerinf*)malloc(LEN);
		fscanf(pf,"%s %s %s %s %s %d %s %d %d %d",
			p2->name,p2->sex,p2->birthday,p2->college,p2->secretnum,
			&p2->ID,p2->type,&p2->balance,&p2->bornum,&p2->outdatenum);
		for(i=0;i<(p2->bornum);i++)
		{
			fscanf(pf,"%d%d%d%d%d",&p2->b[i].book,&p2->b[i].outyear,
				&p2->b[i].outmonth,&p2->b[i].outday,&p2->b[i].tim);
		}
		head=p2;
		while(!feof(pf))
		{
			p1=(struct readerinf*)malloc(LEN);          /*����һ��ռ��P1*/
			fscanf(pf,"%s %s %s %s %s %d %s %d %d %d",
				p1->name,p1->sex,p1->birthday,p1->college,p1->secretnum,
				&p1->ID,p1->type,&p1->balance,&p1->bornum,&p1->outdatenum);/*��ȡ��Ϣ*/
			for(i=0;i<(p1->bornum);i++)
			{
				fscanf(pf,"%d%d%d%d%d",&p1->b[i].book,&p1->b[i].outyear,
					&p1->b[i].outmonth,&p1->b[i].outday,&p1->b[i].tim);
			}
			p2->next=p1;
			p2=p1;
		}
		p2->next=NULL;
		fclose(pf);
	}
	return(head);
}	
/*
�������ܣ�����û�
����/�����������Ϊ����ָͷ��head
�������̣�
    1.������Ϊ�գ�����һ��ռ��ͷָ��
	2.��������һ��ռ��p
	3.�����û�����Ϣ�������������
	4.��pָ��Ľڵ�����������
*/
struct readerinf *addperson(struct readerinf *head)          
{
	int j;
	struct readerinf *p,*p3;
	printf("������Ҫ����û�����Ϣ\n");
	printf("���� �Ա� �������� ѧԺ  ����   ѧ��/����   �������� ���Ķ��� ������ ����ͼ����\n");
	if(head==NULL)
	{	
		head=(struct readerinf*)malloc(LEN);
		scanf("%s	%s	%s	%s %s	%d	%s	%d	%d	%d",
			head->name,head->sex,head->birthday,head->college,head->secretnum,
			&head->ID,head->type,&head->balance,&head->bornum,&head->outdatenum);
		head->next=NULL;
		for(j=0;head->secretnum[j]!='\0';j++)
			head->secretnum[j]=(head->secretnum[j]-20)*2;
		printf("��ӳɹ���\n");
	}
	else
	{
		p3=head;                    /*ÿ�����һ��ͼ�飬���ö������������ж�����Ƿ����*/
		while(p3->next!=NULL)
			p3=p3->next;            /*�ҵ�����ĩβ�ڵ�*/
		p=(struct readerinf*) malloc(LEN);
		p->next=NULL;
		scanf("%s %s %s %s %s %d %s %d %d %d",
			p->name,p->sex,p->birthday,p->college,p->secretnum,
			&p->ID,p->type,&p->balance,&p->bornum,&p->outdatenum);
		for(j=0;p->secretnum[j]!='\0';j++)
			p->secretnum[j]=(p->secretnum[j]-20)*2;
		p3->next=p;                /*��p���ӵ�����ĩβ�ڵ�֮��*/
		printf("��ӳɹ���\n");
	}
	return(head);                    /*��Ϊ�п�����������ͷָ����ܸı䣬������Ҫ����ֵ*/
}
/*
�������ܣ�ɾ���û�
����/�����������Ϊ����ͷָ��head
�������̣�
    1.����Ҫɾ���û���ID
	2.��Ϊͷָ����û�����ʹ��һ���ڵ�Ϊͷ�ڵ�
	3.����Ѱ�Ҹ��û�
	4.���ҵ����û�����ɾ���ýڵ�
	5.�������û�������޴��û���
*/
struct readerinf *delperson(struct readerinf *head)          
{
	int n;
	struct readerinf *p,*p3;
	printf("������Ҫɾ���û���ID\n");
	scanf("%d",&n);
	if(head->ID==n)
		head=head->next;
	else
	{
		p3=head;
		while(p3->ID!=n&&p3->next!=NULL)
		{
			p=p3;
			p3=p3->next;
		}
		if(p3->ID==n)
		{
			p->next=p3->next;
			printf("ɾ���ɹ���\n");
		}
		else
			printf("�޴��û�\n");
	}
	return(head);                     /*��Ϊ����ͷָ��ı�������������Ҫ����ֵ*/
}
/*
�������ܣ��鿴�û���Ϣ
���������head--����ͷָ��
�������̣�
    1.����Ҫ�鿴�û���ID
	2.Ѱ�Ҹû�
	3.���ҵ����û�����������û���Ϣ
	4.��������ͼ����Ϣ�����
	5.�������û�������޴��û���
*/
void showperson(struct readerinf *head)         
{
	int n,m,i,j;
	char a[10];
	struct readerinf *p;
	struct bookinf *b,*b1;
	b=begin();
	p=head;
	printf("������Ҫ�鿴�û���ID\n");
	scanf("%d",&n);
	while(p->ID!=n&&p->next!=NULL)
		p=p->next;
	if(p->ID==n)
	{
		strcpy(a,p->secretnum);
		for(j=0;a[j]!='\0';j++)
			a[j]=(a[j]/2+20);
		m=p->bornum;
		printf("���� �Ա� �������� ѧԺ  ���� ѧ��/����  �������� ���Ķ��� ������ ����ͼ����\n");
		printf("%s  %s  %s  %s %s  %d   %s       %d       %d       %d\n",
			p->name,p->sex,p->birthday,p->college,a,p->ID,
			p->type,p->balance,p->bornum,p->outdatenum);
		printf("\n\n����ͼ����Ϣ\n");
		printf("���� ���� ������ ����ʱ�� �۸� ͼ���� ���� �Ƿ��ڼ� ���Ĵ��� ����ʱ��\n");
		for(i=0;i<m;i++)
		{
			b1=b;
			while(b1->ISBN!=p->b[i].book&&b1->next!=NULL)
				b1=b1->next;
			printf("%s %s %s %s %d %d %s %d %d %d��%d��%d��\n",
				b1->name,b1->author,b1->pubcompany,
				b1->pubdate,b1->price,b1->ISBN,
				b1->category,b1->condition,b1->borrowednum,
				p->b[i].outyear,p->b[i].outmonth,p->b[i].outday);
		}
	} 
	else
		printf("�޴��û�\n");
	system("pause");
	system("cls");
}
/*
�������ܣ�����û�����
���������head--����ͷָ��
*/
void delsecret(struct readerinf *head)        
{
	int n;
	struct readerinf *p;
	p=head;
	printf("��������������û���ID\n");
	scanf("%d",&n);
	while(p->ID!=n&&p->next!=NULL)
		p=p->next;
	if(p->ID==n)
		strcpy(p->secretnum, "8888");/*ʵ������Ϊ0000*/
	else
		printf("�޴��û�\n");
}
/*
�������ܣ��������ж�����Ϣ�����ļ�
*/
void storagereader(struct readerinf *p)          
{
	int n=1,i=0;
	pf=fopen("reader.txt","w+");
	while(p!=NULL)
	{
		if(n!=1)
			fprintf(pf,"\n");
		fprintf(pf,"%s %s %s %s %s %d %s %d %d %d",
			p->name,p->sex,p->birthday,p->college,p->secretnum,
			p->ID,p->type,p->balance,p->bornum,p->outdatenum);
		for(i=0;i<(p->bornum);i++)/*��������ͼ����Ŀ��������ͼ�����Ϣ�����ļ�*/
		{
			fprintf(pf," %d %d %d %d %d",p->b[i].book,p->b[i].outyear,
				p->b[i].outmonth,p->b[i].outday,p->b[i].tim);/*�˴������ʽǰ����Ӹ��ո�*/
		}
		n++;
		p1=p;
		p=p->next;
		free(p1);
	}
	fclose(pf);
}
/*�����Ƕ�ͼ�����Աģ��ʹ�ú����Ķ���*/


/*
�������ܣ�ͼ�����Աѡ���Ӧ���ܣ����в���
*/
void managementtwo()                                  
{
	int choice=0;
	head2=begin();		
	while(choice!=fh1)
	{
		printf("\t\t|-----------------------------------------------|\n");
		printf("\t\t|\t\tͼ����Ĺ���ϵͳ                |\n");
		printf("\t\t|-----------------------------------------------|\n");
		printf("\t\t|\t\t���ͼ���밴0                   |\n");
		printf("\t\t|\t\tɾ��ͼ���밴1                   |\n");
		printf("\t\t|\t\t�޸�ͼ����Ϣ�밴2               |\n");
		printf("\t\t|\t\t�����ϲ��밴3                   |\n");
		printf("\t\t|\t\t������0--3������ָ�����!     |\n");
		printf("\t\t|-----------------------------------------------|\n");
		printf("\n\n\n����������ѡ��:");
		scanf("%d",&choice);
		switch (choice)
		{
		case 0:system("cls");head2=addbook(head2);break;
		case 1:system("cls");head2=delbook(head2);break;
		case 2:system("cls");rewritebook(head2);break;
		case 3:system("cls");main();break;
		default : printf("û�ж�Ӧ��ϵͳָ����֤����\n");break;	
		}	
	}
	storagebook(head2);	
}
/*
�������ܣ����ͼ��
����/�����������Ϊ����ָͷ��head
�������̣�
    1.������Ϊ�գ�����һ��ռ��ͷָ��
	2.��������һ��ռ��p
	3.����ͼ�����Ϣ
	4.��pָ��Ľڵ�����������
*/
struct bookinf *addbook(struct bookinf *head)      
{
	struct bookinf *b,*b3;
	printf("������Ҫ���ͼ�����Ϣ\n");
	printf("���� ���� ������ ����ʱ�� �۸� ͼ���� ���� �Ƿ��ڼ� ���Ĵ���\n");
	if(head==NULL)
	{	
		head=(struct bookinf*)malloc(LON);
		scanf("%s %s %s %s %d %d %s %d %d",
			head->name,head->author,head->pubcompany,head->pubdate,&head->price,
			&head->ISBN,head->category,&head->condition,&head->borrowednum);
		head->next=NULL;
		printf("��ӳɹ���\n");
	}
	else
	{
		b3=head;                 /*��˴������ʡȥfree��䣬Ҳ���ö������������ж�����Ƿ����*/
		b=(struct bookinf*) malloc(LON);
		b->next=NULL;
		scanf("%s %s %s %s %d %d %s %d %d",
			b->name,b->author,b->pubcompany,b->pubdate,&b->price,
			&b->ISBN,b->category,&b->condition,&b->borrowednum);
		while(b3->next!=NULL)
			b3=b3->next;  
		b3->next=b;
		printf("��ӳɹ���\n");
	}
	return(head);/*��Ϊ�п�����������ͷָ����ܸı䣬������Ҫ����ֵ*/
}
/*
�������ܣ�ɾ��ͼ��
����/�����������Ϊ����ͷָ��head
�������̣�
    1.����Ҫɾ��ͼ���ISBN
	2.��Ϊͷָ���ͼ�飬��ʹ��һ���ڵ�Ϊͷ�ڵ�
	3.����Ѱ�Ҹ�ͼ��
	4.���ҵ���ͼ�飬��ɾ���ýڵ�
	5.�������û�������޴�ͼ�顱
*/
struct bookinf *delbook(struct bookinf *head)        
{
	int n;
	struct bookinf *b,*b3;
	printf("������Ҫɾ��ͼ���ISBN\n");
	scanf("%d",&n);
	if(head->ISBN==n)
		head=head->next;
	else
	{
		b3=head;
		while(b3->ISBN!=n&&b3->next!=NULL)
		{
			b=b3;
			b3=b3->next;
		}
		if(b3->ISBN==n)
		{
			b->next=b3->next;
			printf("ɾ���ɹ���\n");
		}
		else
			printf("�޴�ͼ��\n");
				system("pause");
		system("cls");
	}
	return(head);/*��Ϊ����ͷָ��ı�������������Ҫ����ֵ*/
}
/*
�������ܣ��޸�ͼ����Ϣ
���������head--����ͷָ��
�������̣�
    1.����Ҫ�޸�ͼ���ISBN
	2.Ѱ�Ҹ�ͼ��
	3.���ҵ���ͼ�飬�������޸���Ϣ
	4.�������û�������޴�ͼ�顱
*/
void rewritebook(struct bookinf *b)                
{
	int n;
	char a[31],au[21],c[30],d[20];
	printf("������Ҫ�޸�ͼ���ISBN\n");
	scanf("%d",&n);
	while(b->ISBN!=n&&b->next!=NULL)
		b=b->next;
	if(b->ISBN==n)
	{
		printf("������Ҫ�޸�ͼ���ȫ����Ϣ\n");
		printf("���� ���� ������ ����ʱ�� �۸� ͼ���� ���� �Ƿ��ڼ� ���Ĵ���:\n");
		scanf("%s %s %s %s %d %d %s %d %d",
			a,b,c,d,&b->price,&b->ISBN,b->category,
			&b->condition,&b->borrowednum);
		strcpy(b->name,a);
		strcpy(b->author,au);
		strcpy(b->pubcompany,c);
		strcpy(b->pubdate,d);
		printf("�޸ĳɹ�!");
	}
	else
		printf("�޴�ͼ��\n");
			system("pause");
		system("cls");
}



/*�����ǶԶ���ģ�麯��ʹ�õĶ���*/


/*
�������ܣ����ߵ�½
���������1--��½�ɹ���0--�����ϲ�
�������̣�
    1.���û���Ϣ�ļ�����������
	2. �����û������������ϲ�����4
	3. ��������û���������������롣������ȷ�򷵻�1��
	4. ����������롣
*/
struct readerinf * loadthree()                 
{
	
	int i=0,j=1,n=0;
	char c;
	struct readerinf *p;
	head1=creat();
	p=head1;
	printf("\t\t|-----------------------------------------------|\n");
	printf("\t\t\t\t    �û���¼\n");
	printf("\t\t|-----------------------------------------------|\n(PS:�����ʺ�1000 ����6666\n");
	printf("�������û�ID:");
	scanf("%d",&n);
	if(fh1==n)
		return(NULL);
	while(p->ID!=n&&p->next!=NULL)
		p=p->next;
	if(p->ID==n)
	{
		printf("����������:");
		while(n!=j)
		{
			n=0;
			for(j=0;p->secretnum[j]!='\0';)
			{
				c=getch();
				if(p->secretnum[j]==(c-20)*2)
					n++;
				j++;
			}
			if(n!=j)
				printf("���������������!����������:\n");
		}
		return(p);
	}
	else
	{
		printf("�û�������\n");
		system("pause");
		system("cls");
	}
	
}
/*
�������ܣ�����ѡ���Ӧ���ܣ����в���
*/
void operation()                                   
{
	int choice=0;                                /*p1Ϊ���ߵ�¼���Ӧ��ָ��*/
	while(choice!=fh1)
	{
		printf("\n+++++++++++++++++++++++++++++++++++++++++\n");
		printf("�����밴1\n");

		printf("�����밴2\n");
		printf("�����밴3\n");
		printf("��Ѱͼ���밴4\n");
		printf("�޸Ķ�����Ϣ�밴5\n");
		scanf("%d",&choice);
		switch (choice)
		{
		case 1:system("cls");head2=begin();borrowbook(head2,p1);storagebook(head2);break;

		case 2:system("cls");returnbook(p1);break;
		case 3:system("cls");choice=4;break;
		case 4:system("cls");head2=begin();checkbook(head2);storagebook(head2);break;
		case 5:system("cls");rewritereader(p1);break;
		default : printf("û�ж�Ӧ��ϵͳָ����֤����\n");break;	
		}
	}
	storagereader(head1);/*�������Ϊp1������,head1��loadthree()���Ѿ�����ֵ*/
}
/*
�������ܣ���ȡͼ���ļ��е���Ϣ������������
���������head--����ͷָ��
�������̣�
    1.���ļ�
	2.�ļ�û�н������ȡ�ļ���Ϣ����������
	3.�ļ������򷵻�ͷָ��
*/
struct bookinf *begin(void)                         
{   
	struct bookinf *head;
	pb=fopen("book.txt","r+");
	if(pb==NULL)
	{
		printf("���ܴ��ļ�\n");
		exit(0);
	}
	if(pb==NULL)
		head=NULL;
	else
	{
		b2=(struct bookinf*)malloc(LON);
		fscanf(pb,"%s %s %s %s %d %d %s %d %d",
			b2->name,b2->author,b2->pubcompany,b2->pubdate,&b2->price,
			&b2->ISBN,b2->category,&b2->condition,&b2->borrowednum);
		head=b2;
		while(!feof(pb))
		{
			b1=(struct bookinf*)malloc(LON);
			fscanf(pb,"%s %s %s %s %d %d %s %d %d",
				b1->name,b1->author,b1->pubcompany,b1->pubdate,&b1->price,
				&b1->ISBN,b1->category,&b1->condition,&b1->borrowednum);
			b2->next=b1;
			b2=b1;
		}
		b2->next=NULL;
		fclose(pb);
	}
	return(head);
}
/*
�������ܣ�����
���������b1--ͼ��ͷָ�룬p--��½�����ָ��
�������̣�
    1.��ȡϵͳʱ��
	2.�ж϶�������
	3.��Ϊ��ʦ�ɽ�30��������6���£���ʿ���ɽ�20��������3���£�˶ʿ���ɽ�10��������2���£��������ɽ�6��������1���£�
	4.�ж�����ͼ�����Ƿ񵽴�����
	5.��û��������Ҫ��ͼ��ISBN�����������
	6.����ͼ��
	7.���и�������ģ���û������߶���û�и���	
*/
void borrowbook(struct bookinf *b1,struct readerinf *p)                /*����*/
{
	struct bookinf *b;
	int n,m;
	struct tm *t;
	time_t tt;
	time(&tt);
	t=localtime(&tt);
	tt=mktime(t);
	b=b1;
	if(strcmp(p->type,"������")==0)
	{
		if(p->bornum<10)
		{
			printf("������Ҫ��ͼ���ISBN\n");
			scanf("%d",&n);
			while(b->ISBN!=n&&b->next!=NULL)
				b=b->next;
			if(b->ISBN==n)
			{
				if(b->condition=1)
				{
					b->condition=0;
					b->borrowednum++;
					m=p->bornum;
					p->bornum++;
					p->b[m].book=n;
					p->b[m].tim=tt+2592000;
					p->b[m].outday=t->tm_mday;
					if(t->tm_mon+1==12)
					{
						p->b[m].outyear=(t->tm_year+1901);
						p->b[m].outmonth=1;
					}
					else
					{
						p->b[m].outyear=(t->tm_year+1900);
						p->b[m].outmonth=t->tm_mon+2;
					}
					printf("���ĳɹ���\n");
				}
				else
					printf("��ͼ���Ѿ�����\n");
			}
			else
				printf("�޴�ͼ��\n");
		}
		else
			printf("���Ľ������Ѵ����ޣ������ٽ�\n");
	}
	if(strcmp(p->type,"��ʦ")==0)
	{
		if(p->bornum<30)
		{
			printf("������Ҫ��ͼ���ISBN\n");
			scanf("%d",&n);
			while(b->ISBN!=n&&b->next!=NULL)
				b=b->next;
			if(b->ISBN==n)
			{
				if(b->condition=1)
				{
					b->condition=0;
					b->borrowednum++;
					m=p->bornum;
					p->bornum++;
					p->b[m].book=n;
					p->b[m].outday=t->tm_mday;
					p->b[m].tim=tt+2592000*5;
					if(t->tm_mon+1>7)
					{
						p->b[m].outyear=t->tm_year+1901;
						p->b[m].outmonth=(t->tm_mon-5);/*������ѧ�Ƶ��õ��Ĺ�ʽ*/
					}
					else
					{
						p->b[m].outyear=t->tm_year+1900;
						p->b[m].outmonth=t->tm_mon+5;
					}
					printf("���ĳɹ���\n");
				}
				else
					printf("��ͼ���Ѿ�����\n");
			}
			else
				printf("�޴�ͼ��\n");
		}
		else
			printf("���Ľ������Ѵ����ޣ������ٽ�\n");
	}
	if(strcmp(p->type,"��ʿ��")==0)
		{
		if(p->bornum<20)
		{
			printf("������Ҫ��ͼ���ISBN\n");
			scanf("%d",&n);
			while(b->ISBN!=n&&b->next!=NULL)
				b=b->next;
			if(b->ISBN==n)
			{
				if(b->condition=1)
				{
					b->condition=0;
					b->borrowednum++;
					m=p->bornum;
					p->bornum++;
					p->b[m].book=n;
					p->b[m].outday=t->tm_mday;
					p->b[m].tim=tt+2592000*3;
					if(t->tm_mon+1>4)
					{
						p->b[m].outyear=t->tm_year+1901;
						p->b[m].outmonth=(t->tm_mon-8);/*������ѧ�Ƶ��õ��Ĺ�ʽ*/
					}
					else
					{
						p->b[m].outyear=t->tm_year+1900;
						p->b[m].outmonth=t->tm_mon+8;
					}
					printf("���ĳɹ���\n");
				}
				else
					printf("��ͼ���Ѿ�����\n");
			}
			else
				printf("�޴�ͼ��\n");
		}
		else
			printf("���Ľ������Ѵ����ޣ������ٽ�\n");
	}

		if(strcmp(p->type,"˶ʿ��")==0)
		{
		if(p->bornum<10)
		{
			printf("������Ҫ��ͼ���ISBN\n");
			scanf("%d",&n);
			while(b->ISBN!=n&&b->next!=NULL)
				b=b->next;
			if(b->ISBN==n)
			{
				if(b->condition=1)
				{
					b->condition=0;
					b->borrowednum++;
					m=p->bornum;
					p->bornum++;
					p->b[m].book=n;
					p->b[m].outday=t->tm_mday;
					p->b[m].tim=tt+2592000*2;
					if(t->tm_mon+1>3)
					{
						p->b[m].outyear=t->tm_year+1901;
						p->b[m].outmonth=(t->tm_mon-9);/*������ѧ�Ƶ��õ��Ĺ�ʽ*/
					}
					else
					{
						p->b[m].outyear=t->tm_year+1900;
						p->b[m].outmonth=t->tm_mon+9;
					}
					printf("���ĳɹ���\n");
				}
				else
					printf("��ͼ���Ѿ�����\n");
			}
			else
				printf("�޴�ͼ��\n");
		}
		else
			printf("���Ľ������Ѵ����ޣ������ٽ�\n");
	}
}



/*
�������ܣ�����
���������p--���ߵ�½���Ӧָ��
�������̣�
    1.����Ҫ��ͼ��ISBN
	2.���Ҹ�ͼ��
	3.�����˸��鱻��ͼ������1�����ж��Ƿ���
	4.��������ʹ����ͼ������1
	5.��������ͼ������b[30];
	6.��û����飬�������δ���ͼ�顱
*/
void returnbook(struct readerinf *p)                 
{
	int n,d,m;
	struct tm *t;
	struct bookinf *b;
	time_t tt;
	b1=b=begin();
	time(&tt);
	t=localtime(&tt);
	printf("������Ҫ��ͼ���ISBN\n");/*��Ϊ��Щ�����Ŀ��Ϊһ����ֹ����*/
	scanf("%d",&n);
	for(d=0;p->b[d].book!=n&&d<p->bornum;d++);
	while(b->ISBN!=n&&b->next!=NULL)
		b=b->next;
	if(p->b[d].book==n)
	{
		b->condition=1;        /*��������������������϶�����*/
		p->bornum=p->bornum-1;
		if((t->tm_year+1900+(t->tm_mon+1)/12.0)==(p->b[d].outyear+(p->b[d].outmonth)/12.0))  /*��������ͼ����*/
		{
			if(p->b[d].outday<t->tm_mday)
				p->outdatenum--;
		}
		if((t->tm_year+1900+(t->tm_mon+1)/12.0)>(p->b[d].outyear+(p->b[d].outmonth)/12.0))
			p->outdatenum--;
		m=p->bornum;
		for(;d<m;d++)      /*��������ͼ������*/
		{
			p->b[d].book=p->b[d+1].book;
			p->b[d].outday=p->b[d+1].outday;
            p->b[d].outmonth=p->b[d+1].outmonth;
			p->b[d].outyear=p->b[d+1].outyear;
			p->b[d].tim=p->b[d+1].tim;
		}
		p->b[m].book=0;
		p->b[m].outday=0;
		p->b[m].outmonth=0;
		p->b[m].outyear=0;
		p->b[m].tim=0;
		printf("����ɹ���\n");
	}
	else
		printf("δ���ͼ��\n");
	storagebook(b1);
}
/*
�������ܣ�����ͼ��
*/
void checkbook(struct bookinf *b)                  
{
	char a[31],n=0;
	printf("������Ҫ����ͼ�������:");
	scanf("%s",a);
	while(b!=NULL)/*��Ϊ��ĳ�������Ŀ����1�����*/
	{	
		if(strcmp(b->name,a)==0)
		{
			printf("���� ���� ������ ����ʱ�� �۸� ͼ���� ͼ����� �Ƿ��ڼ� ���Ĵ���\n");
			printf("%s %s %s %s %d %d %s %d %d\n",
				b->name,b->author,b->pubcompany,
				b->pubdate,b->price,b->ISBN,
				b->category,b->condition,b->borrowednum);
			n=1;
		}
		b=b->next;
	}
	if(n==0)
		printf("�޴�ͼ��\n");
				system("pause");
		system("cls");
}
/*
�������ܣ��޸Ķ�����Ϣ
*/
void rewritereader(struct readerinf *p3)            
{
	struct readerinf *p;
	char a[30],b[4],c[20],d[20],e[10];
	long int n;
	p=p3;
	printf("��������Ҫ�޸ĵ���Ϣ\n");
	printf("���� �Ա� �������� ѧԺ ���� ѧ��:\n");/*��ʵ���������ֻ���޸�һ������Ϣ*/
	scanf("%s %s %s %s %s %s %d",a,b,c,d,e,&n);
	strcpy(p->name,a);
	strcpy(p->sex,b);
	strcpy(p->birthday,c);
	strcpy(p->college,d);
	strcpy(p->secretnum,e);
	p->ID=n;
	
}
/*
�������ܣ��������е�ͼ����Ϣ�����ļ�
*/
void storagebook(struct bookinf *b)                
{
	int n=1;
	pb=fopen("book.txt","w+");
	while(b!=NULL)
	{
		if(n!=1)
			fprintf(pb,"\n");
		fprintf(pb,"%s %s %s %s %d %d %s %d %d",
			b->name,b->author,b->pubcompany,
			b->pubdate,b->price,b->ISBN,
			b->category,b->condition,b->borrowednum);
		n++;
		b1=b;
		b=b->next;
		free(b1);
	}
	fclose(pb);
}


//�߻���������ǰ���췢���߻�֪ͨ����������ʱ�䷢���߻�֪ͨ
void cuihuan()                     
{
	printf("\t\t|-----------------------------------------------|\n");
	printf("\t\t\t\t    �߻�֪ͨ\n");
	printf("\t\t|-----------------------------------------------|\n");
	int i;
	struct readerinf *p,*p2;
	struct tm *t;
	time_t tt;
	time(&tt);
	t=localtime(&tt);
	p2=creat();
	p=p2;
	tt=mktime(t);
	while(p!=NULL)
	{
		for(i=0;i<p->bornum;i++)
		{
			if((t->tm_year+1900+(t->tm_mon+1)/12.0)==(p->b[i].outyear+(p->b[i].outmonth)/12.0))   
			{
				if(p->b[i].outday-t->tm_mday==3)													/*��ǰ���췢�Ŵ߻���ͨ��*/
				{
					p->outdatenum++;
					p->b[i].tim=tt;
					printf("%s��ͼ�黹�����쵽�ڣ��뼰ʱ�黹!\n\n",p->name);
				}
				if(t->tm_mday>p->b[i].outday)														/*�Ѿ�����*/
				{
				
					p->b[i].tim=tt;
					printf("%s��ͼ���Ѿ����ڣ��뼰ʱ�黹!\n\n",p->name);
				} 
			}
			if((t->tm_year+1900+(t->tm_mon+1)/12.0)>(p->b[i].outyear+(p->b[i].outmonth)/12.0))		/*�Ѿ�����*/
			{
				
				p->b[i].tim=tt;
				printf("%s��ͼ���Ѿ����ڣ��뼰ʱ�黹!\n\n",p->name);
			}
		};
		p=p->next;
	}
	system("pause");
	system("cls");
	storagereader(p2);
}




