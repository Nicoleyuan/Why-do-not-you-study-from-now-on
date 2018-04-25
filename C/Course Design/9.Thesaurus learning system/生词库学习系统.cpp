/*生词库学习系统  张晨*/
#include<stdio.h>                   /*标准输入输出头文件*/
#include<stdlib.h>                  /*标准库头文件*/
#include<windows.h>                 /*加载Windows API 函数头文件*/
#define MAX 10000
int n;                              /*词条数*/
struct word
{
	char a[16];                     /*单词*/
    char b[6];                      /*词性*/
    char c[10];                     /*释义*/
    int  m;                         /*频率*/
};
struct word x[MAX];
void create();                      /*录入函数*/
void modify();                      /*修改函数*/
void modify0();
void insert();                      /*插入函数*/
void insert0();
void del();                         /*删除函数*/
void del0();
void search();                      /*查找函数*/
void search1(); 
void search2(); 
void main();                        /*主函数*/              
void print();                       /*显示函数*/
void print1();                      /*以字典顺序显示函数*/
void print2();                      /*以频率顺序显示函数*/
void error();                       /*自定义选择错误函数*/
void star();                        /*打印星横线*/
int read(struct word[]);            /*从文件中读入数据*/
void main()                         /*主函数*/
{   
    printf("\n\n\n\n\n\n\n\n\n\n");
	star();
	printf("\t\t\t**欢迎使用生词库学习系统**\n");
    star();
    Sleep(888);
	while(1)
	{   
	    int select;
	    system("cls");
        printf("\n\n\n\n\t\t\t**生词库学习系统**\n");
        star();
        printf("\t\t请选择数字进行操作：\n");
        printf("\t\t\t*1.录入词条\n");
        printf("\t\t\t*2.修改词条\n");
        printf("\t\t\t*3.添加词条\n");
        printf("\t\t\t*4.删除词条\n");
        printf("\t\t\t*5.查找词条\n");
        printf("\t\t\t*6.显示词条\n");
        printf("\t\t\t*0.退出系统\n");
        star();
        printf("\t\t所选择的功能编号：");
	    scanf("%d",&select);
        switch(select) 
		{
            case 1: system("cls"); create();break;
	        case 2: system("cls"); modify();break;
            case 3: system("cls"); insert();break;
			case 4: system("cls"); del();break;
            case 5: system("cls"); search();break;
            case 6: system("cls"); print();break;
            case 0: system("cls"); printf("\n\n\n\n\n\n\n\n\n\t\t\t**感谢使用，再见！**\n\t\t\t");
		    exit(0);break;
	        default:system("cls"); error();   break;
	    }
	    getchar();
	}  
}
void create()
{ int i;
  FILE *fp,*p;
  fp=fopen("C:\\word.txt","a");
  p=fopen("C:\\frequency.txt","ab");
  if(fp==NULL)
  {
	  printf("文件打开失败\n");
	  return;
  }
  printf("请输入要输入词条的数目：\n");
  scanf("%d",&n);
  printf("以单词、词性、释义的顺序输入词条：\n");
  for(i=0;i<n;i++)
  {  
     printf("单词:");scanf("%s",&x[i].a);
     printf("词性:");scanf("%s",&x[i].b);
     printf("释义:");scanf("%s",&x[i].c);
     x[i].m=1;
	 fprintf(fp,"%16s%6s%10s%",&x[i].a,&x[i].b,&x[i].c);
	 fwrite(&x[i].m,sizeof(int),1,p);
	 fflush(stdin);
  }
  fclose(fp);
  fclose(p);
  printf("请输入任意键返回\n");
  return;
}                
void print()
{   
	while(1)
	{   int select;
	    system("cls");
        printf("\n\n\n\n\t\t\t**请选择**\n");
        star();
        printf("\t\t请选择数字进行操作：\n");
        printf("\t\t\t*1.以单词顺序显示\n");
        printf("\t\t\t*2.以使用频率显示\n");
        printf("\t\t\t*0.返回上一级菜单\n");
        star();
        printf("\t\t所选择的功能编号：");
	    scanf("%d",&select);	
		switch(select)
		{
		   case 1:system("cls");print1();break;
		   case 2:system("cls");print2();break;
		   case 0:printf("\n\n\n\t\t\t请输入任意键返回上一级菜单\n");return;
		   default:system("cls");error();break;
		}
		getchar();
	}
}
void print1()
{ int i=0,j;
  struct word change;
  n=read(x);
  for(i=0;i<n-1;i++)
    for(j=i+1;j<n;j++)
	{ if(strcmp(x[i].a,x[j].a)>0)
	   {
		change=x[i];
		x[i]=x[j];
		x[j]=change;
	   }
	}
  printf("以字典顺序如下:\n");
  for(i=0;i<n;i++)
  printf("单词:%-16s词性:%-6s释义:%-10s频率:%-2d\n",x[i].a,x[i].b,x[i].c,x[i].m);
  printf("请输入任意键返回\n");
  getchar();
}      
void print2()
{ 
  int i=0,j;
  struct word change;
  n=read(x);
  for(i=0;i<n-1;i++)
    for(j=i+1;j<n;j++)
	{  
		if(x[i].m>x[j].m)
        {
		  change=x[i];
		  x[i]=x[j];
		  x[j]=change;
	    }
	}
  printf("以频率顺序如下:\n");
  for(i=0;i<n;i++)
  printf("单词:%-16s词性:%-6s释义:%-10s频率:%-2d\n",x[i].a,x[i].b,x[i].c,x[i].m);
  printf("请输入任意键返回\n");
  getchar();
}                          
void modify()
{
    modify0();
    while(1)
	{   int select;       
        printf("***************************************\n");
        printf("\t是否继续：*1.是*0.否\n");
        printf("***************************************\n");
        printf("所选择的数字：");
	    scanf("%d",&select);	
		switch(select)
		{
		   case 1:system("cls");modify0();break;
		   case 0:printf("\n\n\n\t\t\t请输入任意键返回\n");return;
		   default:system("cls");error();break;
		}
		getchar();
	}

}
void modify0()
{ int i;
  char y[16];
  n=read(x);
  FILE *fp,*p;
  fp=fopen("C:\\word.txt","w");
  p=fopen("C:\\frequency.txt","w");
  printf("请输入要修改的单词:\n");
  scanf("%s",&y);
  for(i=0;i<n;i++)
	  if(strcmp(x[i].a,y)==0)break;
  if(i<n)
  {  
	  printf("请输入修改后单词、词性、释义:\n");
	  printf("单词:");scanf("%s",&x[i].a);
      printf("词性:");scanf("%s",&x[i].b);
      printf("释义:");scanf("%s",&x[i].c);
      x[i].m=1;
  }
  else printf("无此词条！！\n");  
  for(i=0;i<n;i++)
  {
		 fprintf(fp,"%16s%6s%10s%",&x[i].a,&x[i].b,&x[i].c);
	     fwrite(&x[i].m,sizeof(int),1,p);
	     fflush(stdin);
  }
  fclose(fp);
  fclose(p);
  return;
}                
void insert()
{
    insert0();
    while(1)
	{   int select;
        printf("***************************************\n");
        printf("\t是否继续：*1.是*0.否\n");
        printf("***************************************\n");
        printf("所选择的数字：");
	    scanf("%d",&select);	
		switch(select)
		{
		   case 1:system("cls");insert0();break;
		   case 0:printf("\n\n\n\t\t\t请输入任意键返回\n");return;
		   default:system("cls");error();break;
		}
		getchar();
	}
}
void insert0()
{ 

  FILE *fp,*p;
  fp=fopen("C:\\word.txt","a");
  p=fopen("C:\\frequency.txt","ab");
  if(fp==NULL)
  {
	  printf("文件打开失败\n");
	  return;
  }
  printf("以单词、词性、释义的顺序输入词条：\n");
  printf("单词:");scanf("%s",&x[0].a);
  printf("词性:");scanf("%s",&x[0].b);
  printf("释义:");scanf("%s",&x[0].c);
  x[0].m=1;
  fprintf(fp,"%16s%6s%10s%",&x[0].a,&x[0].b,&x[0].c);
  fwrite(&x[0].m,sizeof(int),1,p);
  fflush(stdin);
  fclose(fp);
  fclose(p);
  return;
}                
void del()
{
    del0();
    while(1)
	{   int select;
	    printf("***************************************\n");
        printf("\t是否继续：*1.是*0.否\n");
        printf("***************************************\n");
        printf("所选择的数字：");
	    scanf("%d",&select);	
		switch(select)
		{
		   case 1:system("cls");del0();break;
		   case 0:printf("\n\n\n\t\t\t请输入任意键返回\n");return;
		   default:system("cls");error();break;
		}
		getchar();
	}

}
void del0()
{ int i,j;
  char y[16];
  n=read(x);
  printf("请输入要删除的单词:\n");
  scanf("%s",&y);
  for(i=0;i<n;i++)
	  if(strcmp(x[i].a,y)==0)break;
  if(i<n)
  {  
	  for(j=i;j<n;j++)x[j]=x[j+1];
  }
  else printf("无此词条！！\n");  
  FILE *fp,*p;
  fp=fopen("C:\\word.txt","w");
  p=fopen("C:\\frequency.txt","w");
  for(i=0;i<n-1;i++)
  {
		 fprintf(fp,"%16s%6s%10s%",&x[i].a,&x[i].b,&x[i].c);
	     fwrite(&x[i].m,sizeof(int),1,p);
	     fflush(stdin);
  }
  fclose(fp);
  fclose(p);
  return;
}                            
void search()
{   
	while(1)
	{   int select;
	    system("cls");
        printf("\n\n\n\n\t\t\t**请选择**\n");
        star();
        printf("\t\t请选择数字进行操作：\n");
        printf("\t\t\t*1.顺序查找\n");
        printf("\t\t\t*2.折半查找\n");
        printf("\t\t\t*0.返回上一级菜单\n");
        star();
        printf("\t\t所选择的功能编号：");
	    scanf("%d",&select);	
		switch(select)
		{
		   case 1:system("cls");search1();break;
		   case 2:system("cls");search2();break;
		   case 0:printf("\n\n\n\t\t\t请输入任意键返回\n");return;
		   default:system("cls");error();break;
		}
		getchar();
	}
}
void search1()
{ 
  int i,j;
  char y[16];
  n=read(x);
  FILE *p;
  p=fopen("C:\\frequency.txt","w");
  printf("请输入要查找的单词:\n");
  scanf("%s",&y);
  for(i=0;i<n;i++)
	  if(strcmp(x[i].a,y)==0)break;
  if(i<n)
  {   x[i].m++;
	  printf("单词:%-16s词性:%-6s释义:%-10s频率:%-2d\n",x[i].a,x[i].b,x[i].c,x[i].m);
      for(j=0;j<n;j++)
           fwrite(&x[j].m,sizeof(int),1,p);
      fclose(p);
  }
  else printf("无此词条！！\n");  
  printf("请输入任意键返回\n");
  getchar();
}   
void search2()
{ 
  int i,j,k;
  char y[16];
  struct word change;
  n=read(x);
  k=n-1;
  for(i=0;i<n-1;i++)
    for(j=i+1;j<n;j++)
	{ if(strcmp(x[i].a,x[j].a)>0)
	   {
		change=x[i];
		x[i]=x[j];
		x[j]=change;
	   }
	}
 
  i=0;
  
  printf("请输入要查找的单词:\n");
  scanf("%s",&y);
  while(i<=k)
  {  j=(i+k)/2;
	  if(strcmp(x[j].a,y)<0)i=j+1;
      else if(strcmp(x[j].a,y)>0)k=j-1;
      else break;
  }
  x[j].m++;
  printf("单词:%-16s词性:%-6s释义:%-10s频率:%-2d\n",x[j].a,x[j].b,x[j].c,x[j].m);
  FILE *p,*fp;
  fp=fopen("C:\\word.txt","w+");
  p=fopen("C:\\frequency.txt","w");
  for(j=0;j<n;j++)
  {
	  fprintf(fp,"%16s%6s%10s%",&x[j].a,&x[j].b,&x[j].c);
	  fwrite(&x[j].m,sizeof(int),1,p);
  }
  fclose(fp);
  fclose(p);
  printf("请输入任意键返回\n");
  getchar();
}
int read(struct word y[MAX])
{ 
  int i=0;
  FILE *fp,*p;
  fp=fopen("C:\\word.txt","r");
  p=fopen("C:\\frequency.txt","r+");
  while(fscanf(fp,"%16s%6s%10s",&y[i].a,&y[i].b,&y[i].c)!=EOF)
  {  
	  fread(&y[i].m,sizeof(int),1,p);
	  i++;
  }
  fclose(fp);
  fclose(p);
  return i;
}
void error() 
{ 
 printf("\n\n\n\n\n\n\n\t\t\t**选择错误!请重新选择**\t\t\n");
	printf("\n\n\t\t\t请输入任意键返回上一级菜单\n");
    getchar();
}                    
void star()  
{ 
 printf("\t\t***************************************\n");
}  