//written by 施金金
#include<stdio.h>              /*标准输入输出头文件*/
#include<stdlib.h>  
#include<windows.h>            /*加载Windows API 函数头文件*/
#include<time.h>
void star();
void mainmenu();                /*自定义主菜单函数*/
void input();                  /*录入函数*/
void modify();                 /*修改函数*/
void insert();                 /*添加函数*/
void del();                    /*删除函数*/
void search();                 /*查询函数*/
void print();                  /*显示函数*/
void sort();               /*成绩排序*/
void error();                  /*自定义选择错误函数*/
void tongji();
void filesave();
void fileopen();
void manage();                   //管理
void k();
int stunum=0;
struct student
{
	int id;                   /*编号*/
	char name[20];              /*姓名*/
	char clas[20];
	char project[20];
	int score[6];
	int total;
};struct student std[100];
void main()
{
	char ch;
    fileopen();	
     while(1)
	{ 
	    mainmenu();
	    ch=getchar();
        switch(ch) 
	   {
            case '1': system("cls");input(); break;
	        case '2': system("cls");print(); break;
            case '3': system("cls"); manage(); break;
			case '4': system("cls");search();  break;
            case '5': system("cls");tongji();  break;
            case '0': system("cls"); printf("\n\n\n\n\n\n\n\n\n\t\t\t**感谢使用，再见！**\n\t\t\t");
		    exit(0);break;
	        default:system("cls"); error();   break;
	    }
	    getchar();
		filesave();
	}  
}





void mainmenu()
{  
    system("cls");
    star();

    printf("\n\n\n\n\t\t\t**欢迎使用竞赛管理系统**\n");
    star();
    printf("\t\t请选择数字进行操作：\n");
    printf("\t\t\t*1.输入选手信息\n");
    printf("\t\t\t*2.显示选手信息\n");
    printf("\t\t\t*3.选手信息管理\n");
    printf("\t\t\t*4.查询选手信息\n");
    printf("\t\t\t*5.统计选手信息\n");
    printf("\t\t\t*0.退出系统\n");
    star();
    printf("\t\t所选择的功能编号：");
	
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
    


void input()
{
	int a,n=1,m;int i,total=0,c;
	while(n)
	{   

		a=stunum;
		system("cls");
        printf("开始录入选手信息:\n");

        
		std[a].id=(a+1);

		printf("编号%d\n",std[a].id);
		printf("名字:");
		scanf("%s",&std[a].name);
		printf("\n班级:");
		scanf("%s",&std[a].clas);
		printf("\n课题:");
		scanf("%s",&std[a].project);
		printf("正在自动录入评委打分\n");
      srand((unsigned)time(NULL));
	for(i=0;i<6;i++)
	{
	    std[a].score[i]=1+rand()%100;
	    printf("评委的分数为%d\t",std[a].score[i]);
	    total+=std[a].score[i];
	}
     printf("\n总分：%d",total);
	 std[a].total=total;
           
		   m=1;
		   while(m)
		   {
			printf("\n请选择：1.确认并继续  2.重新填写  3.放弃并返回  4.确认并返回");
			scanf("%d",&c);
			switch(c)
			{
			case 1:m=0;stunum++;break;
			case 2:stunum,m=0;break;
			case 3:m=0,n=0;break;						//选择此项时，m=0，循环终止
			case 4:m=0,n=0;a=stunum++;break;
			}
		   }
		   
	}
}
	   


void fileopen()
{
	FILE *fp;
	int n;
	if((fp=fopen("data","r+"))==NULL)
	fp=fopen("data","w+");
	for(n=0;n<100;n++)
	fread(&std[n],sizeof(struct student),1,fp);fread(&stunum,4,1,fp);fclose(fp);
}



void filesave()
{
	int n;
	FILE *fp;
	fp=fopen("data","r+");
	for(n=0;n<100;n++)
	fwrite(&std[n],sizeof(struct student),1,fp);
	fwrite(&stunum,4,1,fp);
	fclose(fp);
}


void sort()
{
    int i,j;
	struct student change;
	for(i=0;i<stunum;i++)
	{	for(j=i+1;j<stunum;j++)
			if(std[i].total>std[j].total)
			{
				change=std[i];
				std[i]=std[j];
				std[j]=change;
			}
	}
	for(i=0;i<stunum;i++)
			{
			printf("编号:%d\t",std[i].id);
			printf("名字:%s\t",std[i].name);
			printf("班级:%s\t",std[i].clas);
			printf("课题:%s         ",std[i].project);
			printf("总分:%d\n",std[i].total);
			};system("pause");
			
}
void print()
{
	int b;
	
	printf("*1.按照编号显示\n");
    printf("*2.按照成绩由低到高显示\n");
	printf("*0.返回\n");
	scanf("%d",&b);
	switch(b)
	{
	   case 1:system("cls");k();break;
       case 2:system("cls");sort();break;
	   case 0:return;
    }
}

void k()
{
	int i,j;
	struct student change;
	for(i=0;i<stunum;i++)
	{	for(j=i+1;j<stunum;j++)
			if(std[i].id>std[j].id)
			{
				change=std[i];
				std[i]=std[j];
				std[j]=change;
			}
	}
	for(i=0;i<stunum;i++)
			   {   
				   printf("编号:%d\n",std[i].id);
		           printf("名字:%s",std[i].name);
				   printf("\n班级:%s",std[i].clas);
      	           printf("\n课题:%s",std[i].project);
		           printf("\n总分:\n%d\n\n",std[i].total);
	}system("pause");//让程序停在此处
}
void manage()
{
    int b;
	
	printf("*1.信息添加\n");
    printf("*2.信息删除\n");
	printf("*3.信息修改\n");
	printf("*0.返回");
	scanf("%d",&b);
	switch(b)
	{
	   case 1:system("cls");insert();break;
       case 2:system("cls");del();break;
	   case 3:system("cls");modify();break;
	   case 0:return;
    }
}



void del()
{   
	int n=0;
	char ch;
	char m[20];
	system("cls");;
	printf("输入想要删除的名字");
loop:
	scanf("%s",m);
	for(n=0;n<stunum;n++)
	{
		if(strcmp(std[n].name,m)==0)
		{
			printf("找到该名字");
			printf("是否删除该信息?(y/n)");
            getchar();
			ch=getchar();
			switch(ch)
			{
			case 'y':std[n].id=std[n+1].id;
				     
				     strcpy(std[n].name,std[n+1].name);				//拷贝后一个学生信息到前一个人上。
		             std[n].score[6]=std[n+1].score[6];
		             std[n].total=std[n+1].total;
		             strcpy(std[n].clas,std[n+1].clas);
		             strcpy(std[n].project,std[n+1].project);
					 stunum--;
					 printf("删除成功");
					 system("pause");return;
		
			case 'n':return;

			}
		}
			
		else
			{ 
				printf("未找到该学生，请重新输入\n");
				goto loop;
				system("pause");

				
			
			}
	}
}

void insert()
{ 
	printf("添加选手信息");
	input();
}




void modify()
{
	int i,n=0;
	char ch;
	printf("请输入你想修改学生的编号：");
loop1:
	scanf("%d",&i);
	for(n=0;n<stunum;n++)
	{
		if(i!=std[n].id)
		continue;
			printf("找到该编号的学生\n");
			printf("是否确认修改？（y/n）");
			getchar();
			ch=getchar();
			switch(ch)
			{
			case 'y':printf("新的名字：\n");
				     scanf("%s",&std[n].name);
					 printf("新的班级：\n");
					 scanf("%s",&std[n].clas);
					 printf("新的课题：\n");
					 scanf("%s",&std[n].project);
					 
					 printf("修改成功");
					 system("pause");return;
		
			case 'n':return;
			}
	}   
		{
			printf("未找到该学生，请重新输入编号\n");
		   goto loop1;
		   system("pause");
		}
		
}
	


void search()
{
	int j,n,i;
	printf("********************输入选编号********************");
loop2:
	scanf("%d",&j);
	for(n=0;n<stunum;n++)
	{
	   if(j!=(std[n].id))
		   continue;
	       printf("姓名：%s\n",std[n].name);
		   printf("班级：%s\n",std[n].clas);
		   printf("课题：%s\n",std[n].project);
		   printf("6名评委的分数为：");
		   for(i=0;i<6;i++)
		   {
			   printf("%d\t",std[n].score[i]);
		   }
		   printf("\n总分为：%d\n\n\n",std[n].total);system("pause");return;
	}
		
	   
	   {
		   printf("未找到该选手，请重新输入\n");
		   goto loop2;
		   system("pause");
	   }
}

void tongji()
{
    char ch,k[20];int m,n=0,count=0;
	printf("*1.输入总分显示大于该分数的选手\n");
	printf("*2.输入班级显示参赛人数");
	getchar();
	ch=getchar();
	switch(ch)
	{
	case'1':printf("输入分数");
		    scanf("%d",&m);
			for(n=0;n<stunum;n++)
			{
				if(std[n].total>=m)
				{   printf("姓名：%s\n",std[n].name);
		            printf("班级：%s\n",std[n].clas);
		            printf("课题：%s\n",std[n].project);
					printf("总分：%d\n\n\n",std[n].total);
				} 
			};system("pause");break;



	case'2':printf("输入班级:\n");
		    scanf("%s",&k);
			for(n=0;n<stunum;n++)
			{
				if(strcmp(std[n].clas,k)==0)
					count++;
			}
			printf("该班级参赛人数为：%d",count);
			system("pause");
			break;
	}
}