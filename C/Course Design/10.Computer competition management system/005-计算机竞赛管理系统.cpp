#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define M 6        
void pr();
void fileopen();
void filesave();
void editname(int n);
void editcla(int n);
void editsubject(int n);
void editscore(int n);
void insert(int n);
void inputscore(int a);
void edittoal(int n);
void last(int n);
void del(int n);
int editpr(int n);
void jsid();
void writeinfo();
void add();
void tongji();
void printf();
void edit(int n);
void k();
void sort();

int stunum=0;
struct student
{
	int id;
	char name[10];
	char cla[10];
	char subject[30];
	char score[M];
	int total;
}stu[100];
void pr()
{
	system("cls");
	printf("\n\n\n\t\t\t******计算机竞赛管理系统******");
	printf("\n\t\t\t----------V 1.0.0 ----------");
	printf("\n\t\t\t       1.录入学生信息");
	printf("\n\t\t\t       2.添加学生信息");
	printf("\n\t\t\t       3.修改学生信息");
	printf("\n\t\t\t       4.删除学生信息");
	printf("\n\t\t\t       5.查询学生信息");
	printf("\n\t\t\t       6.统计学生信息");
	printf("\n\t\t\t       7.显示学生信息"); 
	printf("\n\t\t\t       0.退出信息管理");
	printf("\n\t\t\t-----By 151303236 周翔宇-----");
	printf("\n\t\t\t****************************\n");
	printf("\n\t\t\t您想要：");
}
void fileopen()
{
	FILE *fp;
	int n;
	if((fp=fopen("data","r+"))==NULL)
	fp=fopen("data","w+");
	for(n=0;n<100;n++)
	fread(&stu[n],sizeof(struct student),1,fp);fread(&stunum,4,1,fp);fclose(fp);
}

void filesave()
{
	int n;
	FILE *fp;
	fp=fopen("data","r+");
	for(n=0;n<100;n++)
	fwrite(&stu[n],sizeof(struct student),1,fp);
	fwrite(&stunum,4,1,fp);
	fclose(fp);
}
void editname(int n)
{
	printf("\n新姓名：");
	scanf("%s",stu[n].name);
}

void editcla(int n)
{
	printf("\n新隶属班级：");
	scanf("%s",stu[n].cla);
}

void editsubject(int n)
{
	printf("\n新参赛主题：");
	scanf("%s",stu[n].subject);
}

void editscore(int n)
{
	int i;
	printf("\n新成绩");
}

void insert()
{
	printf("请输入要添加的学生信息:\n"); 
	void writeinfo(); 
}  
void edittoal(int n)
{
	printf("\n新总成绩：");
	scanf("%s",stu[n].total);
}
/*随机输入成绩*/ 
void inputscore(int a)
{
	int i;
	stu[a].total=0;
	srand((unsigned)time(NULL));
	for(i=0;i<M;i++)
	{
	    stu[a].score[i]=1+(int)10*rand()/(RAND_MAX+1);
	    stu[a].total+=stu[a].score[i];
	}    
}
void last(int n)
{
	if(n==stunum)
	system("cls");
	printf("******计算机竞赛管理系统******");
	printf("\n----------查    询----------");
	printf("\n已查询到末尾。");
	printf("\nPress any key to continue..");
	printf("\n\n-----By 151303236 周翔宇-----");
	printf("\n****************************\n");
}
/*修改*/ 
void edit(int n)
{
	char ch;
	int a=1,b;
		while (a)
	{
		system("cls");
		printf("******计算机竞赛管理系统******");
		printf("\n----------修    改----------");
		printf("\n请输入要修改学生的学号：");
		scanf("%d",&n);
		n=n-1; 
		printf("\n1.姓名 2.隶属班级 3.参赛主题 4.成绩\n");
		printf("\n\n\n请输入你想修改的内容：");
		getchar();
		ch=getchar();
		switch(ch)
		{
		    case '1':editname(n);break;
		    case '2':editcla(n);break;
		    case '3':editsubject(n);break;
		    case '4':editscore(n);break;
		}
		b=1;
		while (b)
		{
		    printf("\n确认吗？(y/n)");
		    getchar();
		    ch=getchar();
		    switch(ch)
		    {
		        case 'Y':
		        case 'y':b=0;a=0;break;
		        case 'N':
		        case 'n':b=0;break;
		    }
	    }
    }
}
void add()
{
    system("cls");
	printf("\n\n\t\t\t******计算机竞赛管理系统******");
	printf("\n\t\t\t----------添    加----------\n");
	writeinfo();
} 
/*删除*/ 
void del(int n)
{   
	char ch;
	char m[20];
	system("cls");
	loop:
	        printf("输入想要删除的名字:");
	        scanf("%s",m);
	     	for(n=0;n<stunum;n++)
		    {
			    if(strcmp(stu[n].name,m)==0)
			   {
				    printf("\n找到该名字");
				    printf("\n是否删除该信息?(y/n)");
	                getchar();
				    ch=getchar();
				    switch(ch)
				    {
				        case 'y':
					    for(n=0;n<stunum;n++)
						{
						    strcpy(stu[n].name,stu[n+1].name);				//拷贝后一个学生信息到前一个人上。
			                stu[n].total=stu[n+1].total;
			                strcpy(stu[n].cla,stu[n+1].cla);
			                strcpy(stu[n].subject,stu[n+1].subject);
					    }
							stunum--;
						    printf("删除成功");
						    system("pause");return;
	                        case 'n':break;
						
						
	                }
			    }
				else
				{ 
					printf("\n未找到该学生，请重新输入\n");
					goto loop;
					system("pause");
				}
		   }
}
/*二级菜单*/ 
int editpr(int n)
{
	int a=1;
	char ch;
	while(a)
	{
		getchar(); 
		printf("\n\n1.修改学生信息");
		printf("\n2.删除该条信息");
		printf("\n3.返回上级菜单\n");
		printf("\n您想要：");
		ch=getchar();
		switch(ch)
		{
		    case '1':edit(n),a=0;break;
		    case '2':del(n),a=0;break;
		    case '3':a=0;return(0);break;
	    }
	}

}
/*查询*/ 
void jsid()
{
	system("cls");
	int n,m,i,j=0;
	printf("\n\n\n\t\t\t******计算机竞赛管理系统******");
	printf("\n\t\t\t----------查    询----------");
	printf("\n\n\t\t\t-----By 151303236 周翔宇-----");
	printf("\n\t\t\t****************************\n");
	printf("\n\t\t\t请输入想要检索的学号：");
	scanf("%d",&n);
	if(n<=stunum)
	{   
	    n=n-1; 
		printf("学号  ");
		printf("%4d\n",stu[n].id);
		printf("姓名  ");
		printf("%10s\n",stu[n].name);
		printf("隶属班级  ");
		printf("%10s\n",stu[n].cla);
		printf("参赛主题  ");
		printf("%30s\n",stu[n].subject);
        for(i=0;i<M;i++)
        printf("%6d\n",stu[n].score[i]);
		printf("总成绩  ");
		printf("%d\n", stu[n].total);
		j=editpr(n);
		m++;
	}
	if(m==0)
	{
	     printf("\nError:无此学生。");
	     printf("\n-----By 151303236 周翔宇-----");
	     printf("\n****************************\n");
	}
	else
	{
	     if(j==0)
		 goto end;
	     else
	     {
	          system("cls");
	          last(n);
	          getchar();
	     }
	}
    end:getchar();
}
/*输入*/ 
void writeinfo()
{
	int a,n=1,m,i;
	char ch;
	while (n)
	{
		a=stunum;
		printf("\n\t\t\t编号:");
		stu[a].id=(a+1);
		printf("%d",stu[a].id);
		printf("\n\t\t\t姓名:");
		scanf("%s",stu[a].name);
		printf("\n\t\t\t隶属班级:");
		scanf("%s",stu[a].cla);
		printf("\n\t\t\t参赛主题:");
		scanf("%s",stu[a].subject);
		m=1;
		while (m)										
		{
			system("cls");
			printf("\n\t\t\t编号:");
			printf("%d",stu[a].id);
			printf("\n\t\t\t姓名:");
			printf("%s",stu[a].name);
			printf("\n\t\t\t隶属班级:");
			printf("%s",stu[a].cla);
			printf("\n\t\t\t参赛主题:");
			printf("%s",stu[a].subject);
			printf("\n\t\t\t评委打分:");
			inputscore(a);
			for(i=0;i<M;i++)
			printf("%d ",stu[a].score[i]);
	        printf("\n\t\t\t总成绩:");
			printf("%d",stu[a].total);
			printf("\n\t\t\t请选择:\n\t\t\t1.确认并继续\n\t\t\t2.重新填写\n\t\t\t3.放弃并返回\n\t\t\t4.确认并返回\n\t\t\t您想要：");
			ch=getchar();
			switch(ch)
			{
			    case '1':m=0;stunum++;break;
			    case '2':stunum,m=0;break;
			    case '3':m=0,n=0;break;						
			    case '4':m=0,n=0;a=stunum++;break;
			}
		}
	}

}
/*统计*/ 
void tongji()
{
    system("cls");
	char ch,k[20];int m,n=0,count=0;
	printf("\n\n\t\t\t******计算机竞赛管理系统******\n");
	printf("\t\t\t*1.输入总分显示大于该分数的选手\n");
	printf("\t\t\t*2.输入班级显示参赛人数\n");
	printf("\n\t\t\t-----By 151303236 周翔宇-----");
	printf("\n\t\t\t****************************\n");
	printf("\t\t\t您想要：");
	getchar();
	ch=getchar();
	switch(ch)
	{
	case'1':system("cls");
	        printf("输入分数");
		    scanf("%d",&m);
			for(n=0;n<stunum;n++)
			{
				if(stu[n].total>=m)
				{   printf("姓名：%s\n",stu[n].name);
		            printf("班级：%s\n",stu[n].cla);
		            printf("课题：%s\n",stu[n].subject);
					printf("总分：%d\n\n\n",stu[n].total);
				} 
			};system("pause");break;



	case'2':system("cls");
	        printf("输入班级:");
		    scanf("%s",&k);
			for(n=0;n<stunum;n++)
			{
				if(strcmp(stu[n].cla,k)==0)
					count++;
			}
			printf("\n该班级参赛人数为：%d\n",count);
			system("pause");
			break;
	}
}
/*显示*/
void printf()
{
	system("cls");
	int b;
    printf("\n\n\n\t\t\t******计算机竞赛管理系统******\n");
	printf("\t\t\t*1.按照编号显示\n");
    printf("\t\t\t*2.按照成绩顺序显示\n");
	printf("\t\t\t*0.返回\n"); 
	printf("\n\t\t\t-----By 151303236 周翔宇-----");
	printf("\n\t\t\t****************************\n");
	printf("\t\t\t您想要: ");
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
	int n;
	for(n=0;n<stunum;n++)
	{   
		printf("编号%d\t",stu[n].id);
		printf("名字:%s\t",stu[n].name);
		printf("班级:%s\t",stu[n].cla);
      	printf("课题:%s\t",stu[n].subject);
		printf("总分:%d\n",stu[n].total);
    }system("pause");
}
void sort()
{
    int i,j;
	struct student change;
	for(i=0;i<stunum;i++)
	{	for(j=i+1;j<stunum;j++)
			if(stu[i].total>stu[j].total)
			{
				change=stu[i];
				stu[i]=stu[j];
				stu[j]=change;
			}
	}
	        for(i=0;i<stunum;i++)
			{
			    printf("编号:%d\t",stu[i].id);
			    printf("名字:%s\t",stu[i].name);
			    printf("班级:%s\t",stu[i].cla);
			    printf("课题:%s\t",stu[i].subject);
			    printf("总分:%d\n",stu[i].total);
			}system("pause");
			
}


/*主函数*/ 
int main()					
{
	int stunum=0;
	struct student
    {
	    int id;
	    char name[10];
	    char cla[10];
	    char subject[30];
	    char score[M];
	    int total;
    }stu[100];
	int n=1,i;
	char ch;
	fileopen();				
	while (n)
	{
		pr();
		ch=getchar();
		switch(ch)			
		{
		    case '1':system("cls");
			printf("\t\t\t******计算机竞赛管理系统******");
	        printf("\n\t\t\t----------录    入----------\n");
			writeinfo();break;
		    case '2':add();break;
		    case '3':edit(n);break;
		    case '4':del(n);break; 
			case '5':jsid();break;
		    case '6':tongji();break;
		    case '7':printf();break;
			case '0':system("cls");n=0;printf("\n\n\n\n\n\n\n\n\n\t\t\t**感谢使用，再见！**\n\t\t\t");break;
		}
	}
	filesave();
}
