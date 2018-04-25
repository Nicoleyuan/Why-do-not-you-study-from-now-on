/*===================================学 号：151303138===================================*/
/*====================================姓 名：张诗渊=====================================*/
/*===================================班 级：软件1501====================================*/
/*=================================指导老师：邹姝稚=====================================*/
/*=============================课题名称：计算机竞赛管理系统 ============================*/



#include<stdio.h>          /*标准输入输出头文件*/
#include<stdlib.h>         /*标准库头文件*/
#include<string.h>         /*函数定义的头文件*/
#include<conio.h>          /*屏幕操作函数库*/
#include<windows.h>        /*加载Windows API 函数头文件*/
#define SIZE 100

/*结构体类型 student*/

struct student
{
	int Number;             /*编号*/
	char Name[20];          /*姓名*/
	char Class[40];         /*班级*/
	char Task[50];          /*课题名称*/
	int Judge[6];           /*评委打分*/
	int Total;            /*总成绩*/
}stu[100];

int all=100;                 /*初始化选手为100人*/
int current,n=0;             /*n为当前选手人数*/

void Mainmenu();             /*主菜单函数*/
void CreatFile();            /*创建信息文件*/
void EnterRecord();          /*录入信息*/
void Downloadfile();         /*从文件中导入信息*/
void ChangeRrcord();         /*更改选手信息*/
void AddRecord();            /*增加选手信息*/
void DelRecord();            /*删除选手信息（给定姓名）*/
void ModifyByNumber();       /*修改选手信息（给定编号）*/
void PtintByNumber();        /*按选手编号显示信息*/
void QueryBySeatNum();       /*按选手编号查询*/
void Sortmain();             /*统计函数*/ 
void Error();                /*自定义错误函数*/
void Welcome();              /*自定义欢迎界面*/
void Header();               /*自定义标题函数*/
void inputscore(int a);      /*评委随机打分*/
void Save();                 /*存储信息*/
int  menu1();                /*二级菜单1*/ 




/*===主函数===*/
int main()
{
	int choose;
    Welcome();
	while(1)
	{
    	Mainmenu();
     	scanf("%d",&choose);/*输入选择功能的编号*/
    	switch(choose)
		{
		case 1:
			system("cls");
			CreatFile();break;

		case 2:
			system("cls");
			EnterRecord();break;

		case 3:
			system("cls");
			ChangeRrcord();break;

		case 4:
			system("cls");
			PtintByNumber();break;

		case 5:
			system("cls");
		    QueryBySeatNum();break;

        case 6:
			system("cls");
			Sortmain();break;

        case 7:
			system("cls");
			Downloadfile();break;

		case 0:
			system("cls");
			printf("\n\n\n\n\n\t|--------感谢使用，再见!------|\t\n\n\n\n\n");
			exit(0);
		default:
			system("cls");
            Error();
			break;
		}
		getch();
	}

}


/*====================功能及操作界面====================*/
/*欢迎界面*/
void Welcome()
{
	int i;
	int t=4;
	system("color f9");
	printf("\n\n\n\n\n\n\n");
	printf("\t\t*******************************************\n");
	printf("\t\t                                           \n");
	printf("\t\t★★★★欢迎进入计算机竞赛管理系统 ★★★★\n");
	printf("\t\t                                           \n");
	printf("\t\t*******************************************\n");
	printf("\n\n\n\t\t\t                         Loading...");
    while(--t)
	{ 
	  /*每个for循环代表每个颜色持续的时间*/
		for(i=0;i<66;i++);
		system("color fe");
		for(i=0;i<66;i++);
		system("color fb");
		for(i=0;i<66;i++);
		system("color fa");
		for(i=0;i<66;i++);
		system("color fd");
		for(i=0;i<66;i++);
		system("color f9");
	} 
}


void Mainmenu()
{
	system("cls");
	printf("\n\n\n");
	printf("\t\t|--------------------------------------------------|\n");
	printf("\t\t|Welcome to Computer Competition Management System |\n");
	printf("\t\t|--------------------------------------------------|\n\n\n");
	printf("\t\t|-----------------请选择数字进行操作---------------|\n");
    printf("\t\t|\t\t1.创建信息文件                     |\n");
	printf("\t\t|\t\t2.录入信息                         |\n");
	printf("\t\t|\t\t3.更改信息                         |\n");
	printf("\t\t|\t\t4.显示信息                         |\n");
	printf("\t\t|\t\t5.查询信息                         |\n");
	printf("\t\t|\t\t6.统计                             |\n");
	printf("\t\t|\t\t7.导入数据                         |\n");
	printf("\t\t|\t\t0.退出系统                         |\n");
	printf("\t\t|\t\t\t\t\t\t   |\n");
	printf("\t\t|                请选择对应数字0-7                 |\n");
	printf("\t\t|--------------------------------------------------|\n");
}

void Header()
{	
	printf("***************************************************************\n");
	printf("                      计算机竞赛管理系统                       \n");
	printf("***************************************************************\n\n");
}


void CreatFile()
{
	Header();
	FILE *fp;            /*定义指向文件的指针*/

	char DataFile[40]; 
	int i,j,k,count=1,Total=0;


	/*打开文件，创建文件*/
	fp=fopen("DataFile.txt","w+");
		/*打开失败*/
		if(fp==NULL)
		{
			printf("\n 打开文件%s失败！按任意键结束\n",DataFile);
			perror("Open file fail");

		    getch();     /*输入但不回显函数字符*/
			exit(1);     /*异常退出*/
		}
		/*打开成功*/
		else printf("提示：请依次输入 编号 姓名 班级 课题名称 评委1~6的打分情况\n\n");
		while(n<=SIZE)
		{
			printf("\n 如果“编号=0”则结束\n");
			printf("请输入选手编号：");
			scanf("%d",&n);
			stu[n].Number=n;
			if(stu[n].Number==0) break;
			printf("请输入选手姓名：");
			scanf("%s",stu[n].Name);
			printf("请输入选手班级：");
			scanf("%s",stu[n].Class);
			printf("请输入课题名称：");
			scanf("%s",stu[n].Task);
			printf("请输入评委打分\n");
			inputscore(n);
			for(i=0;i<6;i++)
			printf("%d ",stu[n].Judge[i]);
	        printf("\n\t\t\t总成绩:");
			printf("%d",stu[n].Total);
			printf("\n");

			if(n>SIZE)
				printf("对不起，输入数据超过最大允许范围，数据不能被录入！");
			fclose(fp);
			n++;
		}
}



void EnterRecord()
      { 
        Header();
	    int i,j,k,Total=0;
	    char ch;
        printf("请你输入要录入的学生总人数:");
        scanf("%d",&current);
        if(current>=all)
        {printf("对不起，由于人数已满，不能再添加新的学生信息\n");
          EnterRecord();
         }
        else
        {
           for(i=0;i<current;i++)
          {
		  printf("\n 如果“编号=0”则结束\n");
			printf("请输入选手编号：");
			scanf("%d",&n);
			stu[n].Number=n;
			if(stu[n].Number==0) break;
			printf("请输入选手姓名：");
			scanf("%s",stu[n].Name);
			printf("请输入选手班级：");
			scanf("%s",stu[n].Class);
			printf("请输入课题名称：");
			scanf("%s",stu[n].Task);
			printf("请输入评委打分\n");
			inputscore(n);
			for(i=0;i<6;i++)
			printf("%d ",stu[n].Judge[i]);
	        printf("\n\t\t\t总成绩:");
			printf("%d",stu[n].Total);
			printf("\n");
		  getchar();
		  
		  while(1)
		{
		system("cls");
		printf("选手编号:%d\n",stu[n].Number);
		printf("姓名:%s\n",stu[n].Name);
		printf("班级:%s\n",stu[n].Class);
		printf("参赛课题:%s\n",stu[n].Task);
		inputscore(n);
			for(i=0;i<6;i++)
			printf("%d ",stu[n].Judge[i]);
	        printf("\n\t\t\t总成绩:");
			printf("%d",stu[n].Total);
			printf("\n");
		printf("\n\n请选择:\n1.继续添加\n2.返回上一级菜单\n");
	        	switch(ch)
	        	{
	        		case'1':break;
		            case'2':return;
		            default:printf("请输入正确的编号!");
					getchar();
				}
		ch=getchar();
		getchar();
         }
       }
    Save();
    Mainmenu(); 
        }
    }
  
  

void ChangeRrcord()
{
	Header();
	while(1)
	{
		switch(menu1())
	    {
	     case 1:
		      system("cls");
              AddRecord();
              break;
	    case 2:
		     system("cls");
             DelRecord();
             break;
        case 3:    
             system("cls");
		     ModifyByNumber(); 
		     break;
	    case 0:
             return;
        default:
			 system("cls");
             Error();
			 break;
	    }
	} 
} 




int  menu1()
{
	char c;
	Header(); 
	do
	{ 
	    system("cls"); 
		printf("\n\n\n");
		Header(); 
	    printf("\t\t\t   *****更改信息***** \n");                               
        printf("\t\t┌───────────────────┐\n");                   
	    printf("\t\t│\t        1. 添加记录\t\t│\n"); 
	    printf("\t\t│\t        2. 删除记录\t\t│\n"); 
	    printf("\t\t│\t        3. 修改记录\t\t│\n"); 
	    printf("\t\t│\t        0. 返回上一级\t\t│\n");
	    printf("\t\t└───────────────────┘\n"); 
	    printf("\t\t\t请您选择(0-3):"); 
	    fflush(stdin);
	    c=getchar();  
	}while(c<'0'||c>'3'); 
	return(c-'0'); 
} 




void AddRecord()
{
	int i,j,k,Total=0;
	int x,z; 
	char ch;
	Header();
	if(n>=all)
	{
		printf("选手已达上限，不可以再添加！\n");
		system("pause");                                               /*暂停，等待输入任意键继续*/
		return;
	}
	printf("依次输入\n 姓名   班级   课题   评委打分 :\n");
	fflush(stdin);
	
			printf("请输入选手姓名：");
			gets(stu[n+1].Name);
			printf("\n请输入选手班级：");
			gets(stu[n+1].Class);
			printf("\n请输入课题名称：");
			gets(stu[n+1].Task);
			printf("\n请输入评委打分\n");
			inputscore(n);
			for(i=0;i<6;i++)
			printf("%d ",stu[n].Judge[i]);
	        printf("\n\t\t\t总成绩:");
			printf("%d",stu[n].Total);
			printf("\n");
			n+=1;
			printf("\n");
	        printf("已生成新的选手信息\n");
	        printf("编号：%d\n",n);
	        printf("姓名：");puts(stu[n].Name);
	        printf("\n班级：");puts(stu[n].Class);
	        printf("\n课题：");puts(stu[n].Task);
	        for(i=0;i<6;i++)
			printf("评委%d打分:%d\n",i+1,stu[n].Judge[i]);
		    printf("总成绩:%d\n",stu[n].Total);
		    printf("\t是否确定添加？请选择y or n:");
	        scanf("%c", &ch);
	        if(ch=='y'||ch=='Y')
	        {
	        	printf("\n\n请选择:\n1.继续添加\n2.返回上一级菜单\n3.取消\n");
	        	switch(ch)
	        	{
	        		case'1':x=1,z=0,n++;break;
		            case'2':x=0,z=0;n=n++;break;
		            case'3':x=0,z=0;break;
		            default:printf("请输入正确的编号!");
					getchar();
				}
			 } 
			 else 
			 printf("未添加任何信息\n请按任意键返回上级菜单");
			 system("pause");
			 return;
}




void DelRecord()
{
	char s[12],c; 
	int i=1,j; 
	Header();
	printf("请输入想删除的选手姓名:"); 
	fflush(stdin);
	gets(s); 
	while(strcmp(stu[i].Name,s)!=0&&i<=n) i++; 
	if(i>n) 
	{
		printf("通讯录中没有此人!\n");
		system("pause"); 
		return; 
	} 
	printf("该选手信息:\n编号：%d\n",i);
	printf("姓名：");puts(stu[i].Name);
	printf("班级：");puts(stu[i].Class);
	printf("课题：");puts(stu[i].Task);
	printf("总分：");scanf("%d",stu[i].Total);
	printf("是否确认删除?(输入y删除，n返回)\n");
	fflush(stdin);
	c=getchar();
	if(c=='y'&&c=='Y')
	{
	    for(j=i;j<n;j++)
	    { 
	    	strcpy(stu[j].Name,stu[j+1].Name); 
	    	strcpy(stu[j].Class,stu[j+1].Class);
	    	strcpy(stu[j].Task,stu[j+1].Task);
	    	stu[j].Total=stu[j+1].Total;
	    }
	    n-=1;
	    printf("成功删除该选手!\n");
	    system("pause");
	    return;
	}
	return;
}




void ModifyByNumber()
{ 
	int i=1,j,k,o,p;
	int Total=0;
	Header(); 
	printf("请输入想修改选手的编号:"); 
	fflush(stdin);
	scanf("%d",&j);
	while((stu[i].Number=j)!=0&&i<=n) i++; 
	if(i>n) 
	{ 
		printf("系统中没有此人!\n"); 
		system("pause"); 
		return; 	
	}  
	printf("依次输入\n 姓名   班级   课题   评委打分 :\n");
	fflush(stdin);
    gets(stu[i].Name);
	gets(stu[i].Class);
	gets(stu[i].Task);
	printf("\n请输入评委打分\n");
			inputscore(i);
			for(i=0;i<6;i++)
			printf("%d ",stu[i].Judge[k]);
	        printf("\n\t\t\t总成绩:");
			printf("%d",stu[i].Total);
			printf("\n");
			n+=1;
			printf("\n");

	printf("更改后的选手信息：\n");
	printf("编号：%d\n",i);
	printf("姓名：");puts(stu[i].Name);
	printf("班级：");puts(stu[i].Class);
	printf("课题：");puts(stu[i].Task);
    for(i=0;i<6;i++)
    printf("评委%d打分:%d\n",k,stu[i].Judge[k]);
	printf("总成绩:%d\n",stu[i].Total);
	system("pause"); 
	return;
} 




void PtintByNumber()
{
	int i,page=1,max; 
	char c;
	max=(n+9)/10;
	do
	{
		system("cls");                      
    	printf("编号 姓名     班级      课题              评委一    二   三   四   五   六  总分 \n");     
    printf("--------------------------------------------------------------------------------\n"); 
    	if(page<max)
    	{
    		for(i=page*10-9;i<=page*10;i++)                                                            
        	{ 
        		printf("%-3d %-8s%-10s%-20s%-2d%-2d%-2d%-2d%-2d%-2d%-8s",i,stu[i].Name,stu[i].Class,stu[i].Task,stu[i].Judge[1],
				stu[i].Judge[2],stu[i].Judge[3],stu[i].Judge[4],stu[i].Judge[5],stu[i].Judge[6],stu[i].Total); 
        		if(i%10!=0)printf("\n");  
        	}
		}
    	else if(page==max)
    	{
    		for(i=page*10-9;i<=n;i++)                                                            
        	{ 
        		printf("%-3d %-8s%-10s%-20s%-2d%-2d%-2d%-2d%-2d%-2d%-8s",i,stu[i].Name,stu[i].Class,stu[i].Task,stu[i].Judge[1],
				stu[i].Judge[2],stu[i].Judge[3],stu[i].Judge[4],stu[i].Judge[5],stu[i].Judge[6],stu[i].Total); 
        		if(i%10!=0)printf("\n"); 
        	}
		}
		printf("------------------------------------------------------------------------------- \n");
        printf("          1:下一页                      2:上一页                       0:退出\n");
        printf("请您选择(0-2):");
		fflush(stdin);
    	c=getchar();
    	if(c=='1')
		{
		    if(page<max)page+=1;
			else{printf("已是最后一页!");system("pause");}
		}
    	else if(c=='2')
		{
		    if(page>1)page-=1;
			else{printf("已是第一页!");system("pause");}
		}
	}while(c!='0');
}

 
 
 
 void QueryBySeatNum() 
{
	int i,k=0; 
	Header();
	printf("请输入想查询选手的编号:"); 
	scanf("%d",&i); 
	if(i>n) 
	{
		printf("通讯录中没有此纪录!\n"); 
		system("pause"); 
		return; 
	} 
	printf("编号：%d\n",i);
	printf("姓名：");puts(stu[i].Name);
	printf("班级：");puts(stu[i].Class);
	printf("课题：");puts(stu[i].Task);
	for(k=1;k<=6;k++)
    printf("评委%d打分:%d\n",k,stu[i].Judge[k]);
	printf("总分：%d",stu[i].Total);
	system("pause"); 
	return;
}
 
 
 
 
 void Sortmain() 
 {
    system("cls");
	char ch,k[20];int m,n=0,count=0;
	printf("\n\n\t\t\t****************************\n");
	printf("\t\t\t*1.输入总分显示大于该分数的选手\n");
	printf("\t\t\t*2.输入班级显示参赛人数\n");
	printf("\n\t\t\t****************************\n");
	printf("\t\t\t您想要：");
	getchar();
	ch=getchar();
	switch(ch)
	{
	case'1':system("cls");
	        printf("输入分数");
		    scanf("%d",&m);
			for(n=0;n<all;n++)
			{
				if(stu[n].Total>=m)
				{   printf("姓名：%s\n",stu[n].Name);
		            printf("班级：%s\n",stu[n].Class);
		            printf("课题：%s\n",stu[n].Task);
					printf("总分：%d\n\n\n",stu[n].Total);
				} 
			};system("pause");break;



	case'2':system("cls");
	        printf("输入班级:");
		    scanf("%s",&k);
			for(n=0;n<all;n++)
			{
				if(strcmp(stu[n].Class,k)==0)
					count++;
			}
			printf("\n该班级参赛人数为：%d\n",count);
			system("pause");
			break;
	}
}
 
 
 
 
void Downloadfile()
{
	FILE *fp;
	char Filename[30];
	Header();
	printf("导入的数据:\n");
	printf("请输入所写入的数据文件名:"); 
	scanf("%s",Filename); 
	if((fp=fopen(Filename,"rb"))==NULL)                   
	{ 
		printf("无法打开文件...\n"); 
		system("pause"); 
		return; 
	} 
	fread(stu,sizeof(struct student),n+1,fp);
	fclose(fp);
	printf("导入成功！\n");
	system("pause");
}
  
  
 void inputscore(int a)/*随机输入成绩*/
{
	int i; 
	stu[a].Total=0;
	srand((unsigned)time(NULL));
	for(i=0;i<6;i++)
	{
	    stu[a].Judge[i]=1+(int)10*rand()/(RAND_MAX+1);
	    stu[a].Total+=stu[a].Judge[i];
	}    
} 
    
    
 void Save()
	  {
	    FILE *fp;
        int i,N;
        Header();
        if ((fp=fopen("DataFile.txt","wb"))==NULL)
		{ printf("不能打开文件!\n");
	    return;
        }
     for(i=0;i<all;i++)
     if (fwrite(&stu[N],sizeof(struct student),1,fp)!=1)
 		 printf("写入文件错误!\n");
         fclose(fp);
     }
     


void Error()
{
	Header();
	printf("\n\n\n\n\n\t\t|\t\t选择错误!请重新选择\t\t|\n");
	printf("\n\n\n\t\t\t    请输入任意键返回上一级菜单\n");
	return;
}
