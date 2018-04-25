/*���ʿ�ѧϰϵͳ  �ų�*/
#include<stdio.h>                   /*��׼�������ͷ�ļ�*/
#include<stdlib.h>                  /*��׼��ͷ�ļ�*/
#include<windows.h>                 /*����Windows API ����ͷ�ļ�*/
#define MAX 10000
int n;                              /*������*/
struct word
{
	char a[16];                     /*����*/
    char b[6];                      /*����*/
    char c[10];                     /*����*/
    int  m;                         /*Ƶ��*/
};
struct word x[MAX];
void create();                      /*¼�뺯��*/
void modify();                      /*�޸ĺ���*/
void modify0();
void insert();                      /*���뺯��*/
void insert0();
void del();                         /*ɾ������*/
void del0();
void search();                      /*���Һ���*/
void search1(); 
void search2(); 
void main();                        /*������*/              
void print();                       /*��ʾ����*/
void print1();                      /*���ֵ�˳����ʾ����*/
void print2();                      /*��Ƶ��˳����ʾ����*/
void error();                       /*�Զ���ѡ�������*/
void star();                        /*��ӡ�Ǻ���*/
int read(struct word[]);            /*���ļ��ж�������*/
void main()                         /*������*/
{   
    printf("\n\n\n\n\n\n\n\n\n\n");
	star();
	printf("\t\t\t**��ӭʹ�����ʿ�ѧϰϵͳ**\n");
    star();
    Sleep(888);
	while(1)
	{   
	    int select;
	    system("cls");
        printf("\n\n\n\n\t\t\t**���ʿ�ѧϰϵͳ**\n");
        star();
        printf("\t\t��ѡ�����ֽ��в�����\n");
        printf("\t\t\t*1.¼�����\n");
        printf("\t\t\t*2.�޸Ĵ���\n");
        printf("\t\t\t*3.��Ӵ���\n");
        printf("\t\t\t*4.ɾ������\n");
        printf("\t\t\t*5.���Ҵ���\n");
        printf("\t\t\t*6.��ʾ����\n");
        printf("\t\t\t*0.�˳�ϵͳ\n");
        star();
        printf("\t\t��ѡ��Ĺ��ܱ�ţ�");
	    scanf("%d",&select);
        switch(select) 
		{
            case 1: system("cls"); create();break;
	        case 2: system("cls"); modify();break;
            case 3: system("cls"); insert();break;
			case 4: system("cls"); del();break;
            case 5: system("cls"); search();break;
            case 6: system("cls"); print();break;
            case 0: system("cls"); printf("\n\n\n\n\n\n\n\n\n\t\t\t**��лʹ�ã��ټ���**\n\t\t\t");
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
	  printf("�ļ���ʧ��\n");
	  return;
  }
  printf("������Ҫ�����������Ŀ��\n");
  scanf("%d",&n);
  printf("�Ե��ʡ����ԡ������˳�����������\n");
  for(i=0;i<n;i++)
  {  
     printf("����:");scanf("%s",&x[i].a);
     printf("����:");scanf("%s",&x[i].b);
     printf("����:");scanf("%s",&x[i].c);
     x[i].m=1;
	 fprintf(fp,"%16s%6s%10s%",&x[i].a,&x[i].b,&x[i].c);
	 fwrite(&x[i].m,sizeof(int),1,p);
	 fflush(stdin);
  }
  fclose(fp);
  fclose(p);
  printf("���������������\n");
  return;
}                
void print()
{   
	while(1)
	{   int select;
	    system("cls");
        printf("\n\n\n\n\t\t\t**��ѡ��**\n");
        star();
        printf("\t\t��ѡ�����ֽ��в�����\n");
        printf("\t\t\t*1.�Ե���˳����ʾ\n");
        printf("\t\t\t*2.��ʹ��Ƶ����ʾ\n");
        printf("\t\t\t*0.������һ���˵�\n");
        star();
        printf("\t\t��ѡ��Ĺ��ܱ�ţ�");
	    scanf("%d",&select);	
		switch(select)
		{
		   case 1:system("cls");print1();break;
		   case 2:system("cls");print2();break;
		   case 0:printf("\n\n\n\t\t\t�����������������һ���˵�\n");return;
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
  printf("���ֵ�˳������:\n");
  for(i=0;i<n;i++)
  printf("����:%-16s����:%-6s����:%-10sƵ��:%-2d\n",x[i].a,x[i].b,x[i].c,x[i].m);
  printf("���������������\n");
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
  printf("��Ƶ��˳������:\n");
  for(i=0;i<n;i++)
  printf("����:%-16s����:%-6s����:%-10sƵ��:%-2d\n",x[i].a,x[i].b,x[i].c,x[i].m);
  printf("���������������\n");
  getchar();
}                          
void modify()
{
    modify0();
    while(1)
	{   int select;       
        printf("***************************************\n");
        printf("\t�Ƿ������*1.��*0.��\n");
        printf("***************************************\n");
        printf("��ѡ������֣�");
	    scanf("%d",&select);	
		switch(select)
		{
		   case 1:system("cls");modify0();break;
		   case 0:printf("\n\n\n\t\t\t���������������\n");return;
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
  printf("������Ҫ�޸ĵĵ���:\n");
  scanf("%s",&y);
  for(i=0;i<n;i++)
	  if(strcmp(x[i].a,y)==0)break;
  if(i<n)
  {  
	  printf("�������޸ĺ󵥴ʡ����ԡ�����:\n");
	  printf("����:");scanf("%s",&x[i].a);
      printf("����:");scanf("%s",&x[i].b);
      printf("����:");scanf("%s",&x[i].c);
      x[i].m=1;
  }
  else printf("�޴˴�������\n");  
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
        printf("\t�Ƿ������*1.��*0.��\n");
        printf("***************************************\n");
        printf("��ѡ������֣�");
	    scanf("%d",&select);	
		switch(select)
		{
		   case 1:system("cls");insert0();break;
		   case 0:printf("\n\n\n\t\t\t���������������\n");return;
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
	  printf("�ļ���ʧ��\n");
	  return;
  }
  printf("�Ե��ʡ����ԡ������˳�����������\n");
  printf("����:");scanf("%s",&x[0].a);
  printf("����:");scanf("%s",&x[0].b);
  printf("����:");scanf("%s",&x[0].c);
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
        printf("\t�Ƿ������*1.��*0.��\n");
        printf("***************************************\n");
        printf("��ѡ������֣�");
	    scanf("%d",&select);	
		switch(select)
		{
		   case 1:system("cls");del0();break;
		   case 0:printf("\n\n\n\t\t\t���������������\n");return;
		   default:system("cls");error();break;
		}
		getchar();
	}

}
void del0()
{ int i,j;
  char y[16];
  n=read(x);
  printf("������Ҫɾ���ĵ���:\n");
  scanf("%s",&y);
  for(i=0;i<n;i++)
	  if(strcmp(x[i].a,y)==0)break;
  if(i<n)
  {  
	  for(j=i;j<n;j++)x[j]=x[j+1];
  }
  else printf("�޴˴�������\n");  
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
        printf("\n\n\n\n\t\t\t**��ѡ��**\n");
        star();
        printf("\t\t��ѡ�����ֽ��в�����\n");
        printf("\t\t\t*1.˳�����\n");
        printf("\t\t\t*2.�۰����\n");
        printf("\t\t\t*0.������һ���˵�\n");
        star();
        printf("\t\t��ѡ��Ĺ��ܱ�ţ�");
	    scanf("%d",&select);	
		switch(select)
		{
		   case 1:system("cls");search1();break;
		   case 2:system("cls");search2();break;
		   case 0:printf("\n\n\n\t\t\t���������������\n");return;
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
  printf("������Ҫ���ҵĵ���:\n");
  scanf("%s",&y);
  for(i=0;i<n;i++)
	  if(strcmp(x[i].a,y)==0)break;
  if(i<n)
  {   x[i].m++;
	  printf("����:%-16s����:%-6s����:%-10sƵ��:%-2d\n",x[i].a,x[i].b,x[i].c,x[i].m);
      for(j=0;j<n;j++)
           fwrite(&x[j].m,sizeof(int),1,p);
      fclose(p);
  }
  else printf("�޴˴�������\n");  
  printf("���������������\n");
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
  
  printf("������Ҫ���ҵĵ���:\n");
  scanf("%s",&y);
  while(i<=k)
  {  j=(i+k)/2;
	  if(strcmp(x[j].a,y)<0)i=j+1;
      else if(strcmp(x[j].a,y)>0)k=j-1;
      else break;
  }
  x[j].m++;
  printf("����:%-16s����:%-6s����:%-10sƵ��:%-2d\n",x[j].a,x[j].b,x[j].c,x[j].m);
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
  printf("���������������\n");
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
 printf("\n\n\n\n\n\n\n\t\t\t**ѡ�����!������ѡ��**\t\t\n");
	printf("\n\n\t\t\t�����������������һ���˵�\n");
    getchar();
}                    
void star()  
{ 
 printf("\t\t***************************************\n");
}  