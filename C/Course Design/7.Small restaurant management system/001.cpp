#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define NAMESIZE 20
struct Dishes		/*声明一个结构体dishes，包含4个成员*/ 
{ 
 	char ndish[20];			/*菜品编号*/ 
 	char dishes[30];		/*菜品名称*/ 
 	float pay;				/*单价*/ 
 	int amo;				/*数量*/
}dis;						/*定义了一个结构体数组*/
void menu2();		/*菜单函数*/
void scan_1();		/*第一次输入并保存在文件中*/
void scan2();		/*浏览函数*/
void find();		/*查询函数*/
void scan_2();		/*第二次输入并保存在文件中即添加函数*/
void  print();		/*打印菜单*/
void myexit();	/*退出系统*/  
void menuz();		/*总菜单*/
void quitz();		/*总退出*/
void ordz();
void dianz();
void menuz()				/*总菜单*/
{
	system("cls");
	printf("\n");
	printf("			 **********小型餐馆系统***********				");
	printf("\n"); 
	printf("**************************************************************\n");
	printf("			1.订餐系统									\n");
	printf("			2.点餐结账系统								\n");
	printf("***************************************************************");
	printf("\n");
	printf("请输入你需要操作的序号(0-2):\n");
	putchar(10);
}
int main()		/*主函数*/ 
{
	int a;
	menuz();
	do
	{
		scanf("%d",&a);
		switch(a)
		{
			case 1:ordz();break;
			case 2:dianz();break;
			default:printf("输入错误！！请重新输入：\t");
			system("pause");break;
		}
		menu2();
	}while(true);
	return 0;
}
void quitz()		/*总退出*/ 
{
	char ch, buff[20];
	gets(buff);
	printf("\t是否确定退出？请选择y or n:");
	scanf("%c", &ch);
	if(ch=='y'||ch=='Y') exit(0);
	else menuz();
}
void menu2();		/*菜单函数*/
void scan_1();		/*第一次输入并保存在文件中*/
void scan2();		/*浏览函数*/
void find();		/*查询函数*/
void scan_2();		/*第二次输入并保存在文件中即添加函数*/
void  print();		/*打印菜单*/
void myexit();	/*退出系统*/ 
void menu2()		/*菜单函数*/ 
{
	system("cls");
	printf("\n");
	printf("            ********小型餐馆点餐结账系统********              ");
	printf("\n");
	printf("**************************************************************\n");
	printf("			  点餐信息管理		        \n");
	printf("			  1.录入菜品信息                \n");
	printf(" 			  2.浏览菜品信息				\n");
	printf("			  3.添加菜品信息  				\n");
	printf("  			  4.查询菜品信息                \n");
	printf("			  5.打印菜单信息				\n");
	printf("			  0.退出系统					\n");
	printf("***************************************************************");
	printf("\n");
	printf("请输入你需要操作的序号(0-5):\n");
	putchar(10);
}
void dianz()		/*点餐总函数*/ 
{
	int a;
	menu2();
	do
	{
		scanf("%d",&a);
		switch(a)
		{
			case 1:scan_1();break;
			case 2:scan2();break;
			case 3:scan_2();break;
			case 4:find();break;
			case 5:print();break;
			case 0:myexit();break;
			default:printf("输入错误！！请重新输入：\t");
			system("pause");break;
		}
		menu2();
	}while(true);
}
void scan_1()		/*第一次输入并保存在文件中*/
{
	char ch,buff[10];
	FILE *fp3;
	if((fp3=fopen("F:\\check.text","wb+"))==NULL)
	{
		printf("Can't open the file!\n");
		system("pause");
		exit(0);
	}
	do
	{
		printf("请输入菜品编号：\t");
		scanf("%s",dis.ndish);
		printf("菜品名称：\t");
		scanf("%s",dis.dishes);
		printf("单价：\t");
		scanf("%f",&dis.pay);
		printf("数量：\t");
		scanf("%d",&dis.amo);
		system("cls");
		if(fwrite(&dis,sizeof(struct Dishes),1,fp3)!=1)
		{
			printf("File write error!\n");
			exit(0);
		}
		gets(buff);
		printf("是否继续输入y or n?\t");
		scanf("%c",&ch);
	}while(ch=='y'||ch=='Y');
	fclose(fp3);
} 
void scan2()		/*浏览函数*/
{
	FILE *fp3;
	if((fp3=fopen("F:\\check.text","rb"))==NULL)
	{
		printf("Can't open the file!\n");
		return;
	}
	printf("编号   菜名   单价   数量\n");
	while(fread(&dis,sizeof(struct Dishes),1,fp3)==1)
	printf("\n%-5s\t%-5s\t%-3.3f\t%-5d\n",dis.ndish,dis.dishes,dis.pay,dis.amo);
	system("pause");
	fclose(fp3);
} 
void find()			/*查询函数*/
{
	int a,b=0;
	char ch[20];//,buff[20];
	FILE *fp3;
	if((fp3=fopen("F:\\check.text","rb"))==NULL)
	{
		printf("Can't open the file!\n");
		system("pause");
		exit(0);
	}
	printf("请输入要查询的方式\n\t1.菜品编号 2.菜品名称\n\t请选择1 or 2\t");
	scanf("%d",&a);
	if(a==1)
	{
		printf("请输入菜品编号：\t");
		getchar();
		gets(ch);
		while(fread(&dis,sizeof(struct Dishes),1,fp3)==1)
		if(strcmp(dis.ndish,ch)==0)
		{
			b++;
			printf("编号   菜名   单价   数量\n");
			printf("\n%-5s\t%-5s\t%-3.3f\t%-5d\n",dis.ndish,dis.dishes,dis.pay,dis.amo);
		}
		system("pause");
		if(b==0) printf("输入错误！！！\n");
	}
	else if(a==2)
	{
		printf("请输入菜品名称：\t");
		getchar();
		gets(ch);
		while(fread(&dis,sizeof(struct Dishes),1,fp3)==1)
		if(strcmp(dis.dishes,ch)==0)
		{
			b++;
			printf("编号   菜名   单价   数量\n");
			printf("\n%-5s\t%-5s\t%-3.3f\t%-5d\n",dis.ndish,dis.dishes,dis.pay,dis.amo);
		}
		system("pause");
		if(b==0) printf("输入错误！！！\n");
	}
	fclose(fp3);
} 
void scan_2()		/*第二次输入并保存在文件中即添加函数*/
{
	char ch;
	FILE *fp3;
	if((fp3=fopen("F:\\check.text","ab"))==NULL)
	{
		printf("Can't open the file!\n");
		exit(0);
	}
	do
	{
		printf("请输入要添加菜品的编号：");
		getchar();
		gets(dis.ndish);
		printf("菜品名称：");
		gets(dis.dishes);
		printf("单价：");
		scanf("%f",&dis.pay);
		printf("数量：");
		scanf("%d",&dis.amo);
		system("cls");
		if(fwrite(&dis,sizeof(struct Dishes),1,fp3)!=1)
		{
			printf("File write error!\n");
			exit(0);
		}
		printf("是否继续输入y or n?\t");
		getchar();
		ch=getchar();
	}while(ch=='y'||ch=='Y');
	fclose(fp3);
}
void  print()		/*打印菜单*/
{
	float sum;
	FILE *fp3;
	if((fp3=fopen("F:\\check.text","rb"))==NULL)
	{
		printf("Can't open the file!\n");
		return;
	}
	printf("编号   菜名   单价   数量\n");
	while(fread(&dis,sizeof(struct Dishes),1,fp3)==1)
	{
		printf("\n%-5s\t%-5s\t%-3.3f\t%-5d\n",dis.ndish,dis.dishes,dis.pay,dis.amo);
		sum=dis.pay*dis.amo;
		printf("结算金额：%.2f\n",sum);
	}
	system("pause"); 
	fclose(fp3);
} 
void myexit()	/*退出系统*/ 
{
	//int a;
	char ch;
	printf("\t是否确定退出？请选择y or n:");
	getchar();
	ch=getchar();
	if(ch=='y'||ch=='Y') exit(0);
	else menuz();
}
#define NAMESIZE 20

struct telord               /*声明一个结构体tel-ord,包含6个成员*/ 
{
 	char num[20];			/*编号*/ 
 	char name[NAMESIZE];	/*姓名*/ 
 	int qty;				/*人数*/ 
 	char time[5];			/*用餐时间*/ 
 	int table;				/*桌号*/ 
 	char arg;				/*是否已安排*/ 
}ord;
void menu();				/*声明菜单函数*/
void scanf_1();				/*录入顾客信息*/
int baocun();				/*保存顾客信息*/
void scan();				/*浏览顾客信息*/ 
void scanf_2();				/*添加订餐信息*/
void search_inf();			/*查询订餐信息*/
void delete_inf();			/*删除订餐信息*/
void update_inf();			/*修改订餐信息*/
void quit();				/*退出系统*/

void ordz()		/*订餐主函数*/ 
{
	int a;
	menu();
	do{
		scanf("%d",&a);
		switch(a){
		case 1: scanf_1();break;/*录入顾客信息*/
		case 2: scan();break;/*浏览顾客信息*/
		case 3: scanf_2();break;/*添加顾客信息*/
		case 4: search_inf();break;/*查询顾客信息*/
		case 5: delete_inf();break;/*删除退订顾客*/
		case 6: update_inf();break;/*修改预订信息*/
		case 0:  quit();break;/*退出系统*/
		default : printf("输入错误！！！请重新输入：\t"); system("pause"); break;
		}
		menu();
	}while(true);
}
void scanf_1()/*录入信息并保存在文件中*/
{
	char ch, buff[10];
	FILE*fp;
	if((fp=fopen("F:\\telord.txt","wb+"))==NULL)
	{
		printf("Can't open the file!\n");
		system("pause");
		exit(0);
	}
	do
	{
		printf("请输入顾客编号：");
		scanf("%s",ord.num);
		printf("\n");
		printf("请输入姓名：");
		scanf("%s",ord.name);
		printf("请输入用餐人数：");
		scanf("%d",&ord.qty);
		printf("请输入用餐时间：");
		scanf("%s",ord.time);
		printf("请输入桌号：");
		scanf("%d",&ord.table);
		printf("是否已安排：");
		gets(buff);
		scanf("%c",&ord.arg);
		system("cls");
		if(fwrite(&ord,sizeof(struct telord),1,fp)!=1)
		{
			printf("File write error!\n");
			exit(0);
		}
		gets(buff);
		printf("是否继续输入y or n?\t");
		scanf("%c", &ch);
	}while(ch=='y'||ch=='Y');
	fclose(fp);
 } 
 void search_inf()		/*查询函数*/ 
 {
 	int t,b=0;
 	char ch[20], buff[20];
 	FILE *fp;
 	if((fp=fopen("F:\\telord.txt","rb"))==NULL)
 	{
 		printf("Can't open the file!\n");
		system("pause");
		exit(0);	
	}
	printf("\n按姓名查询请按1;\n按用餐时间查询请按2;\n按桌号查询请按3;\n按是否已安排查询请按4；\n");
	scanf("%d",&t);
	if(t==1)
	{
		printf("请输入姓名：\t");
		getchar();
		gets(ch);
		while(fread(&ord,sizeof(struct telord),1,fp)==1)
		if(strcmp(ord.name,ch)==0)
		{
			b++;
			printf("编号 姓名   人数  用餐时间  桌号  是否已安排\n");
			printf("\n%-5s%-7s%-6d%-11s%-5d%c\n",
			ord.num,ord.name,ord.qty,ord.time,ord.table,ord.arg);
		}
		if(b==0) printf("对不起！没有找到相关信息：\n");
	}
	else if(t==2)
	{
		printf("请输入用餐时间：\t");
		getchar();
		gets(ch);
		while(fread(&ord,sizeof(struct telord),1,fp)==1)
		if(strcmp(ord.time,ch)==0)
		{
			b++;
			printf("编号 姓名   人数  用餐时间  桌号  是否已安排\n");
			printf("\n%-5s%-7s%-6d%-11s%-5d%c\n",
			ord.num,ord.name,ord.qty,ord.time,ord.table,ord.arg);
		}
		if(b==0) printf("对不起！没有找到相关信息：\n");
	}
	else if(t==3)
	{
		int table1=0;
		printf("请输入要查找的桌号：\t");
		scanf("%d",&table1);
		while(fread(&ord,sizeof(struct telord),1,fp)==1)
		if(table1==ord.table)
		{
			b++;
			printf("编号 姓名   人数  用餐时间  桌号  是否已安排\n");
			printf("\n%-5s%-7s%-6d%-11s%-5d%c\n",
			ord.num,ord.name,ord.qty,ord.time,ord.table,ord.arg);
		}
		if(b==0) printf("对不起！没有找到相关信息：\n");
	}
	else if(t==4)
	{
		char arg1;
		printf("请输入要查找的安排：\n");
		gets(buff);
		scanf("%c",&arg1);
		while(fread(&ord,sizeof(struct telord),1,fp)==1)
		if(arg1==ord.arg)
		{
			b++;
			printf("编号 姓名   人数  用餐时间  桌号  是否已安排\n");
			printf("\n%-5s%-7s%-6d%-11s%-5d%c\n",
			ord.num,ord.name,ord.qty,ord.time,ord.table,ord.arg);
		}
		if(b==0) printf("对不起！没有找到相关信息：\n");
	}
	fclose(fp);
	system("pause");
}
void  scanf_2()		/*添加信息*/
{
	char ch, buff[10];
	FILE*fp;
	if((fp=fopen("F:\\telord.txt","ab+"))==NULL)
	{
		printf("Can't open the file!\n");
		exit(0);
	}
	do
	{
		printf("请输入顾客编号：");
		scanf("%s",ord.num);
		printf("\n");
		printf("请输入姓名：");
		scanf("%s",ord.name);
		printf("请输入用餐人数：");
		scanf("%d",&ord.qty);
		printf("请输入用餐时间：");
		scanf("%s",ord.time);
		printf("请输入桌号：");
		scanf("%d",&ord.table);
		printf("是否已安排：");
		gets(buff);
		scanf("%c",&ord.arg);
		system("cls");
		if(fwrite(&ord,sizeof(struct telord),1,fp)!=1)
		{
			printf("File write error!\n");
			exit(0);
		}
		gets(buff);
		printf("是否继续输入y or n?\t");
		scanf("%c", &ch);
	}while(ch=='y'||ch=='Y');
	fclose(fp);
} 
void scan()		/*浏览文档中的信息*/
{
	FILE *fp;
 	if((fp=fopen("F:\\telord.txt","rb"))==NULL)
 	{
 		printf("Can't open the file!\n");
		system("pause");
		return;	
	}
	printf("编号 姓名   人数  用餐时间  桌号  是否已安排\n");
	while(fread(&ord,sizeof(struct telord),1,fp)==1){
		printf("\n%-5s%-7s%-6d%-11s%-5d%c\n",
	 	ord.num,ord.name,ord.qty,ord.time,ord.table,ord.arg);
	}
	fclose(fp);
	system("pause");
}
void update_inf() /*修改信息的函数，定义另一个文件，把要修改的信息放到该文件中 */ 
{
	FILE *fp2;
	int b=0,c=0,n=0;
	char ch[20],ck, buff[20];
	FILE *fp;
	do
	{
		if((fp=fopen("F:\\telord.txt","rb+"))==NULL)
		{	
			printf("Can't open the file!\n");
			exit(0);
		}
		if((fp2=fopen("F:\\temp.txt","wb"))==NULL)
		{
			printf("Can't open the file!\n");
			exit(0);
		}
		printf("请输入要修改的顾客编号：\t");
		scanf("%s",ch);
		n++;
		while(fread(&ord,sizeof(struct telord),1,fp)==1)
		{
			if(strcmp(ord.num,ch)==0)
			{
				b++;		
				printf("编号 姓名   人数  用餐时间  桌号  是否已安排\n");
				printf("\n%-5s%-7s%-6d%-11s%-5d%c\n",
					ord.num,ord.name,ord.qty,ord.time,ord.table,ord.arg);
	 			printf("请输入顾客的新编号：");
				scanf("%s",ord.num);
				printf("\n");
				printf("请输入姓名：");
				scanf("%s",ord.name);
				printf("请输入用餐人数：");
				scanf("%d",&ord.qty);
				printf("请输入用餐时间：");
				scanf("%s",ord.time);
				printf("请输入桌号：");
				scanf("%d",&ord.table);
				printf("是否已安排：");
				gets(buff);
				scanf("%c",&ord.arg);
				system("cls");
				fwrite(&ord,sizeof(struct telord),1,fp2);
			}
			else{
				fwrite(&ord,sizeof(struct telord),1,fp2);
			}
		}
		if(b==0)
		{
			printf("没有找到相关信息！\n");
			system("pause");
		}
		gets(buff);
		printf("是否继续修改y or n?\t");
		ck=getchar();
		fclose(fp);
		fclose(fp2);
		remove("F:\\telord.txt");
		rename("F:\\temp.txt","F:\\telord.txt");
	}while(ck=='y'||ck=='Y');
}
void delete_inf()
{
	FILE *fp, *fp2;
	int b=0,c=0,n=0;
	char ch[20],ck, buff[20];
	do
	{
		if((fp=fopen("F:\\telord.txt","rb"))==NULL)
 		{
			printf("Can't open the file!\n");
			system("pause");
			exit(0);
		}
		if((fp2=fopen("F:\\temp.txt","wb"))==NULL)
		{
			printf("Can't open the file!\n");
			system("pause");
			exit(0);
		}
		printf("请输入要删除的顾客编号：\t");
		scanf("%s",ch);
		n++;
		while(fread(&ord,sizeof(struct telord),1,fp)==1)
		{
			if(strcmp(ord.num,ch)==0)
			{
				b++;
				printf("编号 姓名   人数  用餐时间  桌号  是否已安排\n");
				printf("\n%-5s%-7s%-6d%-11s%-5d%c\n",
				ord.num,ord.name,ord.qty,ord.time,ord.table,ord.arg);
	 		}
			else{
				fwrite(&ord,sizeof(struct telord),1,fp2); 
			}
		}
		if(b==0)
		{
			printf("没有找到相关信息！\n");
			system("pause");
		}
		else{
			printf("删除成功！\n");
			system("pause");
		}
		printf("是否继续删除y or n?\t");
		gets(buff);
		ck=getchar();
		fclose(fp);
		fclose(fp2);
		remove("F:\\telord.txt");
		rename("F:\\temp.txt","F:\\telord.txt");
	}while(ck=='y'||ck=='Y');
}
void quit()
{
	char ch, buff[20];
	gets(buff);
	printf("\t是否确定退出？请选择y or n:");
	scanf("%c", &ch);
	if(ch=='y'||ch=='Y') exit(0);
	else menuz();
}

void menu()		            /*菜单函数*/ 
{
	system("cls");
	printf("\n");
	printf("            ********小型餐馆电话订餐系统********              ");
	printf("\n");
	printf("**************************************************************\n");
	printf("			  电话预约信息管理		        \n");
	printf("			  1.录入顾客信息                \n");
	printf(" 			  2.浏览顾客信息				\n");
	printf("			  3.添加顾客信息  				\n");
	printf("  			  4.查询顾客信息                \n");
	printf("			  5.删除退订顾客 				\n");
	printf("			  6.修改预订信息				\n");
	printf("			  0.退出系统					\n");
	printf("***************************************************************");
	printf("\n");
	printf("请输入你需要操作的序号(0-6):\n");
	putchar(10);
}

 
