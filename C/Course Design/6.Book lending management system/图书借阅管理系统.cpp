#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<malloc.h>
#include<time.h>
#define LEN sizeof(struct readerinf)
#define LON sizeof(struct bookinf)
FILE *pf,*pb;
struct borrow                /*定义被借图书简单信息*/
{
	long int book;
    int outyear;             /*为查看用户信息时，可以查看书本超期时间所定*/
	int outmonth;
	int outday;
	long int tim;            /*为简化超期函数所定*/
};
struct bookinf                /*定义图书结构体*/
{
	char name[31];
	char author[21];
	char pubcompany[100];      /*出版社*/
	char pubdate[20];         /*出版时间*/
	int price;                /*价格*/
	long int ISBN;                 /*图书编号*/
	char category[30];             /*分类*/
    int condition;            /*是否在架 1:在架 0:已借 2:再借*/
	int borrowednum;          /*借阅次数*/
    struct bookinf *next;
};
struct readerinf              /*定义学生结构体*/
{
	char name[30]; 
	char sex[4]; 
	char birthday[20]; 	        /*出生年月*/
	char college[20];           /*学院*/
	char secretnum[10];         /*secretnum=(密码-20)*2 */
	long int ID;                /*学号*/
	char type[20];              /*读者类型*/
	int balance;                /*定额数*/
	int bornum;                 /*当前借阅数*/ 
	int outdatenum;             /*超期图书数*/
	struct borrow b[30];        /*一个结构体变量，记录图书和超期时间*/
	struct readerinf *next;		/*指向下一位同学的指针*/
};
struct readerinf *head1,*p1,*p2;
struct bookinf *head2,*b1,*b2;


void cuihuan();
/*以下是对系统管理员模块使用函数的声明*/

void managementone();                                  /*进入管理员的各种操作*/
struct readerinf *creat();                             /*初始化链表函数*/ 
struct readerinf *addperson(struct readerinf *head);   /*添加用户函数*/
struct readerinf *delperson(struct readerinf *head);   /*删除用户函数*/
void showperson(struct readerinf *head);               /*查看用户信息*/
void delsecret(struct readerinf *head);                /*清空用户密码*/
void storagereader(struct readerinf *p);            /*将链表信息存至文件*/

/*以下是对图书管理员模块使用函数的声明*/
void managementtwo();                                  /*进入管理员的各种操作*/
struct bookinf *addbook(struct bookinf *head);        /*添加图书*/
struct bookinf *delbook(struct bookinf *head);        /*删除图书*/
void rewritebook(struct bookinf *b);                /*修改图书信息*/


/*以下是对读者模块函数使用的声明*/
struct readerinf *loadthree();                 /*登陆*/
void operation();                                      /*进入读者的各种操作*/
struct bookinf *begin();                               /*初始化链表函数*/
void borrowbook(struct bookinf *b1,struct readerinf *p);                 /*借书*/
void renewbook(struct readerinf *p);                  /*续借*/  
void returnbook(struct readerinf *p);                 /*还书*/
void checkbook(struct bookinf *b);                  /*查找图书*/
void rewritereader(struct readerinf *p3);            /*修改读者信息*/
void storagebook(struct bookinf *b);                /*将链表信息存至文件*/




int fh1=4;/*返回上层功能所需，方便修改*/

char a[5]={'<','@','D','H'},c;/*实际密码为2468*/

/*
函数功能：选择用户类型，进入对应登陆界面
*/
void main()
{   
	int op;
	while(1)
	{
		printf("\t\t|-----------------------------------------------|\n");
		printf("\t\t|\t\t图书借阅管理系统                |\n");
		printf("\t\t|-----------------------------------------------|\n");
		printf("\t\t|\t\t请选择数字进行操作              |\n");
		printf("\t\t|\t\t1.系统管理员                    |\n");
		printf("\t\t|\t\t2.图书管理员                    |\n");
		printf("\t\t|\t\t3.读者操作                      |\n");
		printf("\t\t|\t\t4.催还通知                      |\n");
		printf("\t\t|\t\t5.退出系统                      |\n");
		printf("\t\t|\t\t请输入0--5!                     |\n");
		printf("\t\t|-----------------------------------------------|\n\n");
		printf("\n\n\n请输入数字:");
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
		
		default : printf("没有对应的系统指令，请查证重输\n");
		}
	}
}

/*以下是系统管理员模块中的函数定义*/



/*
函数功能：系统管理员选择对应功能，进行操作
*/
void managementone()                                   
{
	int choice=0;
	head1=creat();
	while(choice!=fh1)
	{   
		printf("\t\t|-----------------------------------------------|\n");
		printf("\t\t|\t\t图书借阅管理系统                |\n");
		printf("\t\t|-----------------------------------------------|\n");
		printf("\t\t|\t\t添加用户请按0                   |\n");
		printf("\t\t|\t\t删除用户请按1                   |\n");
		printf("\t\t|\t\t查看用户信息请按2               |\n");
		printf("\t\t|\t\t清空用户密码请按3               |\n");
		printf("\t\t|\t\t返回上层请按4		        |\n");
		printf("\t\t|-----------------------------------------------|\n");
		printf("\n\n\n请输入您的选择:");
		scanf("%d",&choice);
		switch (choice)
		{
		case 0:
			system("cls");head1=addperson(head1);break; /*添加用户*/
		case 1:system("cls");head1=delperson(head1);break; /*删除用户*/
		case 2:system("cls");showperson(head1);break;    /*查看用户信息*/
		case 3:system("cls");delsecret(head1);break;     /*清空用户密码*/
		case 4:system("cls");choice=4;break;             /*返回*/
		default: printf("没有对应的系统指令，请查证重输\n");break;	
		}	
	}	
	storagereader(head1);
}


/*
函数功能：读取文件中的信息，存至链表中对应位置
输出参数：head--链表头指针
函数流程：
    1.打开文件
	2.文件没有结束则读取文件信息并存至链表
	3.文件结束则返回头指针
*/
struct readerinf *creat(void)       /*初始化读者信息链表函数*/
{
	int i;
	struct readerinf *head;
	pf=fopen("reader.txt","r+");
	if(pf==NULL)
	{
		printf("不能打开文件\n");
		exit(0);
	}
	if(pf==NULL)                /*若文件为空文件*/
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
			p1=(struct readerinf*)malloc(LEN);          /*申请一块空间给P1*/
			fscanf(pf,"%s %s %s %s %s %d %s %d %d %d",
				p1->name,p1->sex,p1->birthday,p1->college,p1->secretnum,
				&p1->ID,p1->type,&p1->balance,&p1->bornum,&p1->outdatenum);/*读取信息*/
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
函数功能：添加用户
输入/输出参数：均为链表指头针head
函数流程：
    1.若链表为空，申请一块空间给头指针
	2.否则申请一块空间给p
	3.输入用户的信息，并对密码加密
	4.将p指向的节点连到链表上
*/
struct readerinf *addperson(struct readerinf *head)          
{
	int j;
	struct readerinf *p,*p3;
	printf("请输入要添加用户的信息\n");
	printf("姓名 性别 出生年月 学院  密码   学号/工号   读者类型 借阅定额 借书数 超期图书数\n");
	if(head==NULL)
	{	
		head=(struct readerinf*)malloc(LEN);
		scanf("%s	%s	%s	%s %s	%d	%s	%d	%d	%d",
			head->name,head->sex,head->birthday,head->college,head->secretnum,
			&head->ID,head->type,&head->balance,&head->bornum,&head->outdatenum);
		head->next=NULL;
		for(j=0;head->secretnum[j]!='\0';j++)
			head->secretnum[j]=(head->secretnum[j]-20)*2;
		printf("添加成功！\n");
	}
	else
	{
		p3=head;                    /*每次添加一本图书，不用多输入数据以判断添加是否结束*/
		while(p3->next!=NULL)
			p3=p3->next;            /*找到链表末尾节点*/
		p=(struct readerinf*) malloc(LEN);
		p->next=NULL;
		scanf("%s %s %s %s %s %d %s %d %d %d",
			p->name,p->sex,p->birthday,p->college,p->secretnum,
			&p->ID,p->type,&p->balance,&p->bornum,&p->outdatenum);
		for(j=0;p->secretnum[j]!='\0';j++)
			p->secretnum[j]=(p->secretnum[j]-20)*2;
		p3->next=p;                /*将p连接到链表末尾节点之后*/
		printf("添加成功！\n");
	}
	return(head);                    /*因为有空链表的情况，头指针可能改变，所以需要返回值*/
}
/*
函数功能：删除用户
输入/输出参数：均为链表头指针head
函数流程：
    1.输入要删除用户的ID
	2.若为头指针的用户，则使后一个节点为头节点
	3.否则寻找该用户
	4.若找到该用户，则删除该节点
	5.否则向用户输出“无此用户”
*/
struct readerinf *delperson(struct readerinf *head)          
{
	int n;
	struct readerinf *p,*p3;
	printf("请输入要删除用户的ID\n");
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
			printf("删除成功！\n");
		}
		else
			printf("无此用户\n");
	}
	return(head);                     /*因为存在头指针改变的情况，所以需要返回值*/
}
/*
函数功能：查看用户信息
输入参数：head--链表头指针
函数流程：
    1.输入要查看用户的ID
	2.寻找该户
	3.若找到该用户，则输出该用户信息
	4.查找所借图书信息并输出
	5.否则向用户输出“无此用户”
*/
void showperson(struct readerinf *head)         
{
	int n,m,i,j;
	char a[10];
	struct readerinf *p;
	struct bookinf *b,*b1;
	b=begin();
	p=head;
	printf("请输入要查看用户的ID\n");
	scanf("%d",&n);
	while(p->ID!=n&&p->next!=NULL)
		p=p->next;
	if(p->ID==n)
	{
		strcpy(a,p->secretnum);
		for(j=0;a[j]!='\0';j++)
			a[j]=(a[j]/2+20);
		m=p->bornum;
		printf("姓名 性别 出生年月 学院  密码 学号/工号  读者类型 借阅定额 借书数 超期图书数\n");
		printf("%s  %s  %s  %s %s  %d   %s       %d       %d       %d\n",
			p->name,p->sex,p->birthday,p->college,a,p->ID,
			p->type,p->balance,p->bornum,p->outdatenum);
		printf("\n\n所借图书信息\n");
		printf("书名 作者 出版社 出版时间 价格 图书编号 分类 是否在架 借阅次数 超期时间\n");
		for(i=0;i<m;i++)
		{
			b1=b;
			while(b1->ISBN!=p->b[i].book&&b1->next!=NULL)
				b1=b1->next;
			printf("%s %s %s %s %d %d %s %d %d %d年%d月%d日\n",
				b1->name,b1->author,b1->pubcompany,
				b1->pubdate,b1->price,b1->ISBN,
				b1->category,b1->condition,b1->borrowednum,
				p->b[i].outyear,p->b[i].outmonth,p->b[i].outday);
		}
	} 
	else
		printf("无此用户\n");
	system("pause");
	system("cls");
}
/*
函数功能：清空用户密码
输入参数：head--链表头指针
*/
void delsecret(struct readerinf *head)        
{
	int n;
	struct readerinf *p;
	p=head;
	printf("请输入清空密码用户的ID\n");
	scanf("%d",&n);
	while(p->ID!=n&&p->next!=NULL)
		p=p->next;
	if(p->ID==n)
		strcpy(p->secretnum, "8888");/*实际密码为0000*/
	else
		printf("无此用户\n");
}
/*
函数功能：将链表中读者信息存至文件
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
		for(i=0;i<(p->bornum);i++)/*依据所借图书数目，将被借图书简单信息存至文件*/
		{
			fprintf(pf," %d %d %d %d %d",p->b[i].book,p->b[i].outyear,
				p->b[i].outmonth,p->b[i].outday,p->b[i].tim);/*此处输出格式前必须加个空格*/
		}
		n++;
		p1=p;
		p=p->next;
		free(p1);
	}
	fclose(pf);
}
/*以下是对图书管理员模块使用函数的定义*/


/*
函数功能：图书管理员选择对应功能，进行操作
*/
void managementtwo()                                  
{
	int choice=0;
	head2=begin();		
	while(choice!=fh1)
	{
		printf("\t\t|-----------------------------------------------|\n");
		printf("\t\t|\t\t图书借阅管理系统                |\n");
		printf("\t\t|-----------------------------------------------|\n");
		printf("\t\t|\t\t添加图书请按0                   |\n");
		printf("\t\t|\t\t删除图书请按1                   |\n");
		printf("\t\t|\t\t修改图书信息请按2               |\n");
		printf("\t\t|\t\t返回上层请按3                   |\n");
		printf("\t\t|\t\t请输入0--3，其他指令不可用!     |\n");
		printf("\t\t|-----------------------------------------------|\n");
		printf("\n\n\n请输入您的选择:");
		scanf("%d",&choice);
		switch (choice)
		{
		case 0:system("cls");head2=addbook(head2);break;
		case 1:system("cls");head2=delbook(head2);break;
		case 2:system("cls");rewritebook(head2);break;
		case 3:system("cls");main();break;
		default : printf("没有对应的系统指令，请查证重输\n");break;	
		}	
	}
	storagebook(head2);	
}
/*
函数功能：添加图书
输入/输出参数：均为链表指头针head
函数流程：
    1.若链表为空，申请一块空间给头指针
	2.否则申请一块空间给p
	3.输入图书的信息
	4.将p指向的节点连到链表上
*/
struct bookinf *addbook(struct bookinf *head)      
{
	struct bookinf *b,*b3;
	printf("请输入要添加图书的信息\n");
	printf("书名 作者 出版社 出版时间 价格 图书编号 分类 是否在架 借阅次数\n");
	if(head==NULL)
	{	
		head=(struct bookinf*)malloc(LON);
		scanf("%s %s %s %s %d %d %s %d %d",
			head->name,head->author,head->pubcompany,head->pubdate,&head->price,
			&head->ISBN,head->category,&head->condition,&head->borrowednum);
		head->next=NULL;
		printf("添加成功！\n");
	}
	else
	{
		b3=head;                 /*如此处理可以省去free语句，也不用多输入数据以判断添加是否结束*/
		b=(struct bookinf*) malloc(LON);
		b->next=NULL;
		scanf("%s %s %s %s %d %d %s %d %d",
			b->name,b->author,b->pubcompany,b->pubdate,&b->price,
			&b->ISBN,b->category,&b->condition,&b->borrowednum);
		while(b3->next!=NULL)
			b3=b3->next;  
		b3->next=b;
		printf("添加成功！\n");
	}
	return(head);/*因为有空链表的情况，头指针可能改变，所以需要返回值*/
}
/*
函数功能：删除图书
输入/输出参数：均为链表头指针head
函数流程：
    1.输入要删除图书的ISBN
	2.若为头指针的图书，则使后一个节点为头节点
	3.否则寻找该图书
	4.若找到该图书，则删除该节点
	5.否则向用户输出“无此图书”
*/
struct bookinf *delbook(struct bookinf *head)        
{
	int n;
	struct bookinf *b,*b3;
	printf("请输入要删除图书的ISBN\n");
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
			printf("删除成功！\n");
		}
		else
			printf("无此图书\n");
				system("pause");
		system("cls");
	}
	return(head);/*因为存在头指针改变的情况，所以需要返回值*/
}
/*
函数功能：修改图书信息
输入参数：head--链表头指针
函数流程：
    1.输入要修改图书的ISBN
	2.寻找该图书
	3.若找到该图书，则输入修改信息
	4.否则向用户输出“无此图书”
*/
void rewritebook(struct bookinf *b)                
{
	int n;
	char a[31],au[21],c[30],d[20];
	printf("请输入要修改图书的ISBN\n");
	scanf("%d",&n);
	while(b->ISBN!=n&&b->next!=NULL)
		b=b->next;
	if(b->ISBN==n)
	{
		printf("请输入要修改图书的全部信息\n");
		printf("书名 作者 出版社 出版时间 价格 图书编号 分类 是否在架 借阅次数:\n");
		scanf("%s %s %s %s %d %d %s %d %d",
			a,b,c,d,&b->price,&b->ISBN,b->category,
			&b->condition,&b->borrowednum);
		strcpy(b->name,a);
		strcpy(b->author,au);
		strcpy(b->pubcompany,c);
		strcpy(b->pubdate,d);
		printf("修改成功!");
	}
	else
		printf("无此图书\n");
			system("pause");
		system("cls");
}



/*以下是对读者模块函数使用的定义*/


/*
函数功能：读者登陆
输出参数：1--登陆成功，0--返回上层
函数流程：
    1.打开用户信息文件，存至链表
	2. 输入用户名，若返回上层输入4
	3. 若有这个用户，则继续输入密码。密码正确则返回1，
	4. 否则继续输入。
*/
struct readerinf * loadthree()                 
{
	
	int i=0,j=1,n=0;
	char c;
	struct readerinf *p;
	head1=creat();
	p=head1;
	printf("\t\t|-----------------------------------------------|\n");
	printf("\t\t\t\t    用户登录\n");
	printf("\t\t|-----------------------------------------------|\n(PS:测试帐号1000 密码6666\n");
	printf("请输入用户ID:");
	scanf("%d",&n);
	if(fh1==n)
		return(NULL);
	while(p->ID!=n&&p->next!=NULL)
		p=p->next;
	if(p->ID==n)
	{
		printf("请输入密码:");
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
				printf("您输入的密码有误!请重新输入:\n");
		}
		return(p);
	}
	else
	{
		printf("用户不存在\n");
		system("pause");
		system("cls");
	}
	
}
/*
函数功能：读者选择对应功能，进行操作
*/
void operation()                                   
{
	int choice=0;                                /*p1为读者登录后对应的指针*/
	while(choice!=fh1)
	{
		printf("\n+++++++++++++++++++++++++++++++++++++++++\n");
		printf("借书请按1\n");

		printf("还书请按2\n");
		printf("返回请按3\n");
		printf("查寻图书请按4\n");
		printf("修改读者信息请按5\n");
		scanf("%d",&choice);
		switch (choice)
		{
		case 1:system("cls");head2=begin();borrowbook(head2,p1);storagebook(head2);break;

		case 2:system("cls");returnbook(p1);break;
		case 3:system("cls");choice=4;break;
		case 4:system("cls");head2=begin();checkbook(head2);storagebook(head2);break;
		case 5:system("cls");rewritereader(p1);break;
		default : printf("没有对应的系统指令，请查证重输\n");break;	
		}
	}
	storagereader(head1);/*如果参数为p1则会出错,head1在loadthree()中已经被赋值*/
}
/*
函数功能：读取图书文件中的信息，存至链表中
输出参数：head--链表头指针
函数流程：
    1.打开文件
	2.文件没有结束则读取文件信息并存至链表
	3.文件结束则返回头指针
*/
struct bookinf *begin(void)                         
{   
	struct bookinf *head;
	pb=fopen("book.txt","r+");
	if(pb==NULL)
	{
		printf("不能打开文件\n");
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
函数功能：借书
输入参数：b1--图书头指针，p--登陆后读者指针
函数流程：
    1.读取系统时间
	2.判断读者类型
	3.若为教师可借30本，期限6个月；博士生可借20本，期限3个月；硕士生可借10本；期限2个月；本科生可借6本，期限1个月；
	4.判断所借图书数是否到达上限
	5.若没有则输入要借图书ISBN，否则不允许借
	6.查找图书
	7.若有该书则借阅，若没有则告诉读者没有该书	
*/
void borrowbook(struct bookinf *b1,struct readerinf *p)                /*借书*/
{
	struct bookinf *b;
	int n,m;
	struct tm *t;
	time_t tt;
	time(&tt);
	t=localtime(&tt);
	tt=mktime(t);
	b=b1;
	if(strcmp(p->type,"本科生")==0)
	{
		if(p->bornum<10)
		{
			printf("请输入要借图书的ISBN\n");
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
					printf("借阅成功！\n");
				}
				else
					printf("该图书已经被借\n");
			}
			else
				printf("无此图书\n");
		}
		else
			printf("您的借书书已达上限，不能再借\n");
	}
	if(strcmp(p->type,"教师")==0)
	{
		if(p->bornum<30)
		{
			printf("请输入要借图书的ISBN\n");
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
						p->b[m].outmonth=(t->tm_mon-5);/*经过数学推导得到的公式*/
					}
					else
					{
						p->b[m].outyear=t->tm_year+1900;
						p->b[m].outmonth=t->tm_mon+5;
					}
					printf("借阅成功！\n");
				}
				else
					printf("该图书已经被借\n");
			}
			else
				printf("无此图书\n");
		}
		else
			printf("您的借书书已达上限，不能再借\n");
	}
	if(strcmp(p->type,"博士生")==0)
		{
		if(p->bornum<20)
		{
			printf("请输入要借图书的ISBN\n");
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
						p->b[m].outmonth=(t->tm_mon-8);/*经过数学推导得到的公式*/
					}
					else
					{
						p->b[m].outyear=t->tm_year+1900;
						p->b[m].outmonth=t->tm_mon+8;
					}
					printf("借阅成功！\n");
				}
				else
					printf("该图书已经被借\n");
			}
			else
				printf("无此图书\n");
		}
		else
			printf("您的借书书已达上限，不能再借\n");
	}

		if(strcmp(p->type,"硕士生")==0)
		{
		if(p->bornum<10)
		{
			printf("请输入要借图书的ISBN\n");
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
						p->b[m].outmonth=(t->tm_mon-9);/*经过数学推导得到的公式*/
					}
					else
					{
						p->b[m].outyear=t->tm_year+1900;
						p->b[m].outmonth=t->tm_mon+9;
					}
					printf("借阅成功！\n");
				}
				else
					printf("该图书已经被借\n");
			}
			else
				printf("无此图书\n");
		}
		else
			printf("您的借书书已达上限，不能再借\n");
	}
}



/*
函数功能：还书
输入参数：p--读者登陆后对应指针
函数流程：
    1.输入要还图书ISBN
	2.查找该图书
	3.若借了该书被借图书数减1，并判断是否超期
	4.若超期则使超期图书数减1
	5.调整被借图书数组b[30];
	6.若没借该书，则输出“未借此图书”
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
	printf("请输入要还图书的ISBN\n");/*因为有些书的数目不为一，防止出错*/
	scanf("%d",&n);
	for(d=0;p->b[d].book!=n&&d<p->bornum;d++);
	while(b->ISBN!=n&&b->next!=NULL)
		b=b->next;
	if(p->b[d].book==n)
	{
		b->condition=1;        /*若满足上述条件，该书肯定存在*/
		p->bornum=p->bornum-1;
		if((t->tm_year+1900+(t->tm_mon+1)/12.0)==(p->b[d].outyear+(p->b[d].outmonth)/12.0))  /*调整超期图书数*/
		{
			if(p->b[d].outday<t->tm_mday)
				p->outdatenum--;
		}
		if((t->tm_year+1900+(t->tm_mon+1)/12.0)>(p->b[d].outyear+(p->b[d].outmonth)/12.0))
			p->outdatenum--;
		m=p->bornum;
		for(;d<m;d++)      /*调整被借图书数组*/
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
		printf("还书成功！\n");
	}
	else
		printf("未借此图书\n");
	storagebook(b1);
}
/*
函数功能：查找图书
*/
void checkbook(struct bookinf *b)                  
{
	char a[31],n=0;
	printf("请输入要查找图书的书名:");
	scanf("%s",a);
	while(b!=NULL)/*因为有某本书的数目大于1的情况*/
	{	
		if(strcmp(b->name,a)==0)
		{
			printf("书名 作者 出版社 出版时间 价格 图书编号 图书分类 是否在架 借阅次数\n");
			printf("%s %s %s %s %d %d %s %d %d\n",
				b->name,b->author,b->pubcompany,
				b->pubdate,b->price,b->ISBN,
				b->category,b->condition,b->borrowednum);
			n=1;
		}
		b=b->next;
	}
	if(n==0)
		printf("无此图书\n");
				system("pause");
		system("cls");
}
/*
函数功能：修改读者信息
*/
void rewritereader(struct readerinf *p3)            
{
	struct readerinf *p;
	char a[30],b[4],c[20],d[20],e[10];
	long int n;
	p=p3;
	printf("请输入所要修改的信息\n");
	printf("姓名 性别 出生年月 学院 密码 学号:\n");/*按实际情况读者只能修改一部分信息*/
	scanf("%s %s %s %s %s %s %d",a,b,c,d,e,&n);
	strcpy(p->name,a);
	strcpy(p->sex,b);
	strcpy(p->birthday,c);
	strcpy(p->college,d);
	strcpy(p->secretnum,e);
	p->ID=n;
	
}
/*
函数功能：将链表中的图书信息存至文件
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


//催还函数：提前三天发布催还通知，超过借阅时间发布催还通知
void cuihuan()                     
{
	printf("\t\t|-----------------------------------------------|\n");
	printf("\t\t\t\t    催还通知\n");
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
				if(p->b[i].outday-t->tm_mday==3)													/*提前三天发放催还书通告*/
				{
					p->outdatenum++;
					p->b[i].tim=tt;
					printf("%s的图书还有三天到期，请及时归还!\n\n",p->name);
				}
				if(t->tm_mday>p->b[i].outday)														/*已经超期*/
				{
				
					p->b[i].tim=tt;
					printf("%s的图书已经超期，请及时归还!\n\n",p->name);
				} 
			}
			if((t->tm_year+1900+(t->tm_mon+1)/12.0)>(p->b[i].outyear+(p->b[i].outmonth)/12.0))		/*已经超期*/
			{
				
				p->b[i].tim=tt;
				printf("%s的图书已经到期，请及时归还!\n\n",p->name);
			}
		};
		p=p->next;
	}
	system("pause");
	system("cls");
	storagereader(p2);
}




