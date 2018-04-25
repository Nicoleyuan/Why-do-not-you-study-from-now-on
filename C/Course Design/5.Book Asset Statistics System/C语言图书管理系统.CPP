#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
void editbnum(int n);
void editbname(int n);
void editwname(int n);
void editprice(int n);
void editpubcom(int n);
void editpubtime(int n);
void editclanum(int n);
void mainmenu();
void input();
void protect(int n);
void search();
void scan();
void procount();
void add(int n);
void del(int n);
void modify(int n);
void error();
void star();
void clacount();
void totalcount();
void search1();
void search2();
void search3();
void fileopen();
void filesave();
int num;
int booksnum=0;
void information();
void print();
struct books
{
	int  bnum;
	char bname[20];
	char wname[20];
	char clanum[4];
	char pubcom[10];
	char pubtime[10];
	float price;
}books[100];

void main(int n)
{
	printf("\n\n\n\n\n\n\n\n\n\n");
	star();
	printf("\t\t\t***欢迎使用图书资产统计系统***\n");
	star();
	Sleep(888);
	while(1)
	{
		int select;
		mainmenu();
		scanf("%d",&select);
		switch(select)
		{
		case 1:system("cls");input();break;
	    case 2:system("cls");protect(n);break;
	    case 3:system("cls");search();break;
	    case 4:system("cls");scan();break;
	    case 5:system("cls");totalcount();break;
		case 6:system("cls");print();break;
		case 7:system("cls");fileopen();break;
		case 8:system("cls");filesave();break;
	    case 0:system("cls");printf("\t\t\t***谢谢使用，再见！***\n\n\n");
		exit(0);break;
	    default: system("cls");error();break;
		}
	    getchar();
	}
}
void mainmenu()
{
	system("cls");
	printf("\t\t\t***图书资产统计系统***\n");
	star();
	printf("\t\t请选择相应的数字操作: \n");
	printf("\t\t\t*1.录入图书信息\n");
	printf("\t\t\t*2.图书信息维护\n");
	printf("\t\t\t*3.查询检索\n");
	printf("\t\t\t*4.图书信息浏览\n");
	printf("\t\t\t*5.资产统计\n");
	printf("\t\t\t*6.打印图书信息\n");
	printf("\t\t\t*7.文件打开\n");
	printf("\t\t\t*8.文件保存\n");
	printf("\t\t\t*0.退出系统\n");
	star();
	printf("\t\t所选功能编号: ");
}
void input()
{
	int n;
	int j,k;
	char ch;
	j=1;
	while(j)
	{
		n=booksnum;
		system("cls");
		printf("请按如下格式输入书籍分类:\n1中文专著\n2英文专著\n3中文期刊\n4英文期刊");
		printf("\n书号:%d",n);
        books[n].bnum=n;
        printf("\n书名:");
		scanf("%s",&books[n].bname);
        printf("\n作者:");
		scanf("%s",&books[n].wname);
        printf("\n书籍分类:");
		scanf("%s",&books[n].clanum);
        printf("\n出版社:");
        scanf("%s",&books[n].pubcom);
        printf("\n出版日期:");
		scanf("%s",&books[n].pubtime);
		printf("\n价格:");
        scanf("%f",&books[n].price);
		k=1;
		getchar();
		while(k)
		{
            printf("\n请选择:\n1.继续录入\n2.停止录入并返回\n");
			ch=getchar();
			getchar();
			switch(ch)
			{
			case '1':j=1,k=0;booksnum++;break;
			case '2':j=0,k=0;booksnum++;break;
			default:printf("请输入正确的编号！点击enter返回");
				getchar();
				getchar();
			}
		}
	}
}


void protect(int n)
{
	int flag=1;
	int choose;
	while(1)
	{
		printf("请选择以下功能:\n");
		printf("1、添加图书信息\n");
		printf("2、删除图书信息\n");
		printf("3、修改图书信息\n");
		printf("0、返回上一级菜单\n");
		scanf("%d",&choose);
		switch(choose)
		{
		case 1:add(n);system("cls");break;
        case 2:del(n);system("cls");break;
		case 3:modify(n);system("cls");break;
		case 0:flag=0;break;
		default:system("cls");error();break;
		}
		if(flag==0)break;
		getchar();
	}
}
void search()
{
	int flag=1;
	int choose;
	while(1)
	{
		printf("请选择以下功能:\n");
		printf("1、查询某本书的出版社\n");
		printf("2、查询某本书的作者\n");
		printf("3、查询某本书的价格\n");
		printf("0、返回上一级菜单\n");
		scanf("%d",&choose);
		switch(choose)
		{
		case 1:search1();break;
		case 2:search2();break;
		case 3:search3();break;
		case 0:flag=0;break;
		default:system("cls");error();break;
		}
		if(flag==0)break;
		getchar();
	}
}


void scan()
{
	int i;
	int flag=1;
	char m[20];
    printf("输入作者名字，查询作者的书籍");
	printf("\n请输入作者名字:");
	scanf("%s",&m);
	for(i=0;i<booksnum;i++)
	{
		if(strcmp(m,books[i].wname)==0)
			printf("\n书名:%s\n",books[i].bname);
	}
	printf("\n输入任意键返回上一级菜单");
	getchar();
}

void procount()
{
	int i;
	int count=0;
	float sum=0;
	char m[30];
	system("cls");
	printf("请输入需要检索的书名:");
	scanf("%s",m);
	for(i=0;i<booksnum;i++)
		if(strcmp(m,books[i].bname)==0)
		{
			count++;
			sum+=books[i].price;
		}
    system("cls");
	printf("\n您检索的图书的总册书:%d",count);
	printf("\n您检索的图书的总金额:%f",sum);
	printf("\n按回车继续");
	getchar();
}

void clacount()
{
	int i;
	int count=0;
	float sum=0;
	char m[30];
	system("cls");
	printf("请输入检索的专著类别:");
	scanf("%s",m);
	for(i=0;i<booksnum;i++)
		if(strcmp(m,books[i].clanum)==0)
		{
			count++;
			sum+=books[i].price;
		}
		system("cls");
		printf("\n专著的总册书:%d",count);
		printf("\n专著的总金额:%f",sum);
		printf("\n按回车继续");
		getchar();
}



void add(int n)
{
    int a;
	int j,k;
	char ch;
	j=1;
	while(j)
	{
		a=booksnum;
		system("cls");
        printf("请按如下格式输入书籍分类:\n1中文专著\n2英文专著\n3中文期刊\n4英文期刊");
		printf("\n书号:%d",a);
        books[n].bnum=n;
        printf("\n书名:");
		scanf("%s",&books[a].bname);
        printf("\n作者:");
		scanf("%s",&books[a].wname);
        printf("\n书籍分类:");
		scanf("%s",&books[a].clanum);
        printf("\n出版社:");
        scanf("%s",&books[a].pubcom);
        printf("\n出版日期:");
		scanf("%s",&books[a].pubtime);
		printf("\n价格:");
		scanf("%f",&books[a].price);
		k=1;
		getchar();
		while(k)
		{
            printf("\n请选择:\n1.确认添加\n2.取消添加\n");
			ch=getchar();
			getchar();
            system("cls");
			switch(ch)
			{
			case '1':j=0;k=0;booksnum++;printf("添加成功");getchar();break;
			case '2':j=0;k=0;break;
			default:printf("请输入正确的编号！点击enter返回");break;
				getchar();
				getchar();
			}
		}
	}
}

void del(int n)
{
	int i,k;
	int a=1;
	char ch;
	while(a)
	{
		system("cls");
	    printf("请输入要删除的书号:");
	    scanf("%d",&i);
		if(i>booksnum-1)
		{
			printf("输入的编号有误\n");
			printf("输入任意键重新输入");
			getchar();
			getchar();
		}
		else
		{
			books[i].bnum=books[i+1].bnum;
		    strcpy(books[i].bname,books[i+1].bname);
		    strcpy(books[i].wname,books[i+1].wname);
		    strcpy(books[i].clanum,books[i+1].clanum);
		    strcpy(books[i].pubcom,books[i+1].pubcom);
		    strcpy(books[i].pubtime,books[i+1].pubtime);
		    books[i].price=books[i+1].price;
	    booksnum--;
		k=1;
		while(k)
		{
		printf("\n请选择:\n1.确认\n2.取消\n");
        getchar();
        ch=getchar();       
		switch(ch)
		{
		    case '1':a=0;k=0;booksnum--;printf("删除成功");getchar();break;
		    case '0':a=0;break;
		    default:printf("请输入正确的编号！点击enter返回");break;
		}
		getchar();
		getchar();
		}
		}
	}
}

void editbnum(int n)
{
	printf("\n 请输入新的书号: ");
	scanf("%d",&books[n].bnum);
}

void editbname(int n)
{
	printf("\n 请输入新的书名: ");
	scanf("%s",books[n].bname);
}

void editwname(int n)
{
	printf("\n 请输入新的作者名: ");
	scanf("%s",books[n].wname);
}

void editprice(int n)
{
	printf("\n 请输入新的价格: ");
	scanf("%f",&books[n].price);
}

void editclanum(int n)
{
	printf("\n 请输入新的书分类: ");
	scanf("%s",books[n].clanum);
}

void editpubcom(int n)
{
	printf("\n 请输入新的出版社: ");
	scanf("%s",books[n].pubcom);
}

void editpubtime(int n)
{
	printf("\n 请输入新的出版时间: ");
	scanf("%s",books[n].pubtime);
}

void modify(int n)
{
	int i,k;
    char ch;
	int a=1;
	while(a)
	{
		system("cls");
		printf("请输入要修改的书号:\n");
		scanf("%d",&i);
		if(i>booksnum-1)
		{
			printf("输入的编号有误\n");
			printf("输入任意键重新输入");
			getchar();
			getchar();
		}
		else
		{
			system("cls");
		    printf("\n请输入你要修改的内容:");
		    printf("\n1、书号");
	 	    printf("\n2、书名");
		    printf("\n3、作者");
		    printf("\n4、价格");
		    printf("\n5、书籍分类");
		    printf("\n6、出版社");
		    printf("\n7、出版时间");
	        getchar();
		    ch=getchar();
		    switch(ch)
			{
			case '1':editbnum(n);break;
		    case '2':editbname(n);break;
		    case '3':editwname(n);break;
		    case '4':editprice(n);break;
		    case '5':editclanum(n);break;
		    case '6':editpubcom(n);break;
		    case '7':editpubtime(n);break;
            default:printf("请输入正确的编号！点击enter返回");
				getchar();
				getchar();
			}
        k=1;
		while(k)
		{
		printf("\n确认修改？1.确认0.取消");
		getchar();
        ch=getchar();
		system("cls");
		switch(ch)
		{
		case'1':a=0;k=0;break;
		case'0':a=0;break;
		}
		getchar();	
		}
		}
	}
}

void star()
{
    printf("\t\t***************************************\n");
}
void error()
{
	printf("\n\n\n\n\n\n\n\t\t\t**选择错误!请重新选择**\t\t\n");
	printf("\n\n\t\t\t请输入任意键返回上一级菜单\n");
    getchar();
}

void totalcount()
{
	int flag=1;
	int choose;
	while(1)
	{
		printf("请选择以下功能:\n");
		printf("1、统计某本书的总册书和总金额\n");
		printf("2、统计专著总册书和金额\n");
		printf("0、返回上一级菜单\n");
		scanf("%d",&choose);
		switch(choose)
		{
		case 1:procount();break;
        case 2:clacount();break;
		case 0:flag=0;break;
		printf("请输入任意键返回上一级菜单\n");
		default:system("cls");error();break;
		}
		if(flag==0)break;
		getchar();
	}
}

void search1()
{
	int i,bi=-9;
	char m[30];
	system("cls");
	printf("请输入要检索的书名:");
	scanf("%s",m);
	for(i=0;i<booksnum;i++)
		if(strcmp(m,books[i].bname)==0)
			bi=i;
		if(bi<0)
			printf("该书不存在，请重新输入书名");
	for(i=0;i<booksnum;i++)
		if(strcmp(m,books[i].bname)==0)
	{
			printf("出版社:%s\n",books[i].pubcom);
	}
	printf("\n请输入任意键返回上一级菜单");
	getchar();
}

void search2()
{
	int i,bi=-9;
	char m[30];
	system("cls");
	printf("请输入要检索的书名:");
	scanf("%s",m);
	for(i=0;i<booksnum;i++)
	if(strcmp(m,books[i].bname)==0)
		bi=i;
	if(bi<0)
		printf("该书不存在，请重新输入书名");
	for(i=0;i<booksnum;i++)
		if(strcmp(m,books[i].bname)==0)
		{
			printf("作者:%s\n",books[i].wname);
		}
    printf("\n请输入任意键返回上一级菜单");
	getchar();
}

void search3()
{
	int i,bi=-9;
	char m[30];
	system("cls");
	printf("请输入要检索的书名:");
	scanf("%s",m);
    for(i=0;i<booksnum;i++)
	 if(strcmp(m,books[i].bname)==0)
		 bi=i;
	 if(bi<0)
		 printf("该书不存在，请重新输入书名");
	for(i=0;i<booksnum;i++) 
		if(strcmp(m,books[i].bname)==0)
	{
		printf("价格%f\n",books[i].price);
	}
	
	printf("\n请输入任意键返回上一级菜单");
	getchar();
}

void fileopen()
{
	FILE *fp;
	int n=0;
	fp=fopen("data.txt","r");
	while(!feof(fp))
	{
		
	  fread(&books[n],sizeof(struct books),1,fp);
	  n++;
	  booksnum++;
	}
	printf("打开成功\n");
	printf("请按任意键返回主菜单");

	getchar();
	fclose(fp);
}

void filesave()
{
	int n=0;
	FILE *fp;
	fp=fopen("data.txt","w");
    while(n<booksnum)
	{
	  fwrite(&books[n],sizeof(struct books),1,fp);
	  n++;
	}
	printf("保存成功\n");
	printf("请按任意键返回主菜单");
	getchar();
	fclose(fp);
}

void print()
{
	information();
	printf("\t\t   **请输入任意键返回上一级菜单**\n");
	getchar();
}

void information()
{
	int i;
	star();
	printf("\t\t\t**图书总册书:%d**\n",booksnum);
	printf("\t\t\t**图书信息如下:**\n");
	printf("\t书号\t书名\t作者\t书籍分类\t出版社\t出版时间\t价格\n");
	for(i=0;i<=booksnum-1;i++)
		printf("\t%d\t%2s\t%2s\t%2s\t\t%2s\t%2s\t\t%2f\n",books[i].bnum,books[i].bname,books[i].wname,books[i].clanum,books[i].pubcom,books[i].pubtime,books[i].price);
	star();
}