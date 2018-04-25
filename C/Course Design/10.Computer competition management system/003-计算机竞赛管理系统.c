/*===================================ѧ �ţ�151303138===================================*/
/*====================================�� ������ʫԨ=====================================*/
/*===================================�� �������1501====================================*/
/*=================================ָ����ʦ�������=====================================*/
/*=============================�������ƣ��������������ϵͳ ============================*/



#include<stdio.h>          /*��׼�������ͷ�ļ�*/
#include<stdlib.h>         /*��׼��ͷ�ļ�*/
#include<string.h>         /*���������ͷ�ļ�*/
#include<conio.h>          /*��Ļ����������*/
#include<windows.h>        /*����Windows API ����ͷ�ļ�*/
#define SIZE 100

/*�ṹ������ student*/

struct student
{
	int Number;             /*���*/
	char Name[20];          /*����*/
	char Class[40];         /*�༶*/
	char Task[50];          /*��������*/
	int Judge[6];           /*��ί���*/
	int Total;            /*�ܳɼ�*/
}stu[100];

int all=100;                 /*��ʼ��ѡ��Ϊ100��*/
int current,n=0;             /*nΪ��ǰѡ������*/

void Mainmenu();             /*���˵�����*/
void CreatFile();            /*������Ϣ�ļ�*/
void EnterRecord();          /*¼����Ϣ*/
void Downloadfile();         /*���ļ��е�����Ϣ*/
void ChangeRrcord();         /*����ѡ����Ϣ*/
void AddRecord();            /*����ѡ����Ϣ*/
void DelRecord();            /*ɾ��ѡ����Ϣ������������*/
void ModifyByNumber();       /*�޸�ѡ����Ϣ��������ţ�*/
void PtintByNumber();        /*��ѡ�ֱ����ʾ��Ϣ*/
void QueryBySeatNum();       /*��ѡ�ֱ�Ų�ѯ*/
void Sortmain();             /*ͳ�ƺ���*/ 
void Error();                /*�Զ��������*/
void Welcome();              /*�Զ��延ӭ����*/
void Header();               /*�Զ�����⺯��*/
void inputscore(int a);      /*��ί������*/
void Save();                 /*�洢��Ϣ*/
int  menu1();                /*�����˵�1*/ 




/*===������===*/
int main()
{
	int choose;
    Welcome();
	while(1)
	{
    	Mainmenu();
     	scanf("%d",&choose);/*����ѡ���ܵı��*/
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
			printf("\n\n\n\n\n\t|--------��лʹ�ã��ټ�!------|\t\n\n\n\n\n");
			exit(0);
		default:
			system("cls");
            Error();
			break;
		}
		getch();
	}

}


/*====================���ܼ���������====================*/
/*��ӭ����*/
void Welcome()
{
	int i;
	int t=4;
	system("color f9");
	printf("\n\n\n\n\n\n\n");
	printf("\t\t*******************************************\n");
	printf("\t\t                                           \n");
	printf("\t\t����ﻶӭ����������������ϵͳ �����\n");
	printf("\t\t                                           \n");
	printf("\t\t*******************************************\n");
	printf("\n\n\n\t\t\t                         Loading...");
    while(--t)
	{ 
	  /*ÿ��forѭ������ÿ����ɫ������ʱ��*/
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
	printf("\t\t|-----------------��ѡ�����ֽ��в���---------------|\n");
    printf("\t\t|\t\t1.������Ϣ�ļ�                     |\n");
	printf("\t\t|\t\t2.¼����Ϣ                         |\n");
	printf("\t\t|\t\t3.������Ϣ                         |\n");
	printf("\t\t|\t\t4.��ʾ��Ϣ                         |\n");
	printf("\t\t|\t\t5.��ѯ��Ϣ                         |\n");
	printf("\t\t|\t\t6.ͳ��                             |\n");
	printf("\t\t|\t\t7.��������                         |\n");
	printf("\t\t|\t\t0.�˳�ϵͳ                         |\n");
	printf("\t\t|\t\t\t\t\t\t   |\n");
	printf("\t\t|                ��ѡ���Ӧ����0-7                 |\n");
	printf("\t\t|--------------------------------------------------|\n");
}

void Header()
{	
	printf("***************************************************************\n");
	printf("                      �������������ϵͳ                       \n");
	printf("***************************************************************\n\n");
}


void CreatFile()
{
	Header();
	FILE *fp;            /*����ָ���ļ���ָ��*/

	char DataFile[40]; 
	int i,j,k,count=1,Total=0;


	/*���ļ��������ļ�*/
	fp=fopen("DataFile.txt","w+");
		/*��ʧ��*/
		if(fp==NULL)
		{
			printf("\n ���ļ�%sʧ�ܣ������������\n",DataFile);
			perror("Open file fail");

		    getch();     /*���뵫�����Ժ����ַ�*/
			exit(1);     /*�쳣�˳�*/
		}
		/*�򿪳ɹ�*/
		else printf("��ʾ������������ ��� ���� �༶ �������� ��ί1~6�Ĵ�����\n\n");
		while(n<=SIZE)
		{
			printf("\n ��������=0�������\n");
			printf("������ѡ�ֱ�ţ�");
			scanf("%d",&n);
			stu[n].Number=n;
			if(stu[n].Number==0) break;
			printf("������ѡ��������");
			scanf("%s",stu[n].Name);
			printf("������ѡ�ְ༶��");
			scanf("%s",stu[n].Class);
			printf("������������ƣ�");
			scanf("%s",stu[n].Task);
			printf("��������ί���\n");
			inputscore(n);
			for(i=0;i<6;i++)
			printf("%d ",stu[n].Judge[i]);
	        printf("\n\t\t\t�ܳɼ�:");
			printf("%d",stu[n].Total);
			printf("\n");

			if(n>SIZE)
				printf("�Բ����������ݳ����������Χ�����ݲ��ܱ�¼�룡");
			fclose(fp);
			n++;
		}
}



void EnterRecord()
      { 
        Header();
	    int i,j,k,Total=0;
	    char ch;
        printf("��������Ҫ¼���ѧ��������:");
        scanf("%d",&current);
        if(current>=all)
        {printf("�Բ���������������������������µ�ѧ����Ϣ\n");
          EnterRecord();
         }
        else
        {
           for(i=0;i<current;i++)
          {
		  printf("\n ��������=0�������\n");
			printf("������ѡ�ֱ�ţ�");
			scanf("%d",&n);
			stu[n].Number=n;
			if(stu[n].Number==0) break;
			printf("������ѡ��������");
			scanf("%s",stu[n].Name);
			printf("������ѡ�ְ༶��");
			scanf("%s",stu[n].Class);
			printf("������������ƣ�");
			scanf("%s",stu[n].Task);
			printf("��������ί���\n");
			inputscore(n);
			for(i=0;i<6;i++)
			printf("%d ",stu[n].Judge[i]);
	        printf("\n\t\t\t�ܳɼ�:");
			printf("%d",stu[n].Total);
			printf("\n");
		  getchar();
		  
		  while(1)
		{
		system("cls");
		printf("ѡ�ֱ��:%d\n",stu[n].Number);
		printf("����:%s\n",stu[n].Name);
		printf("�༶:%s\n",stu[n].Class);
		printf("��������:%s\n",stu[n].Task);
		inputscore(n);
			for(i=0;i<6;i++)
			printf("%d ",stu[n].Judge[i]);
	        printf("\n\t\t\t�ܳɼ�:");
			printf("%d",stu[n].Total);
			printf("\n");
		printf("\n\n��ѡ��:\n1.�������\n2.������һ���˵�\n");
	        	switch(ch)
	        	{
	        		case'1':break;
		            case'2':return;
		            default:printf("��������ȷ�ı��!");
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
	    printf("\t\t\t   *****������Ϣ***** \n");                               
        printf("\t\t������������������������������������������\n");                   
	    printf("\t\t��\t        1. ��Ӽ�¼\t\t��\n"); 
	    printf("\t\t��\t        2. ɾ����¼\t\t��\n"); 
	    printf("\t\t��\t        3. �޸ļ�¼\t\t��\n"); 
	    printf("\t\t��\t        0. ������һ��\t\t��\n");
	    printf("\t\t������������������������������������������\n"); 
	    printf("\t\t\t����ѡ��(0-3):"); 
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
		printf("ѡ���Ѵ����ޣ�����������ӣ�\n");
		system("pause");                                               /*��ͣ���ȴ��������������*/
		return;
	}
	printf("��������\n ����   �༶   ����   ��ί��� :\n");
	fflush(stdin);
	
			printf("������ѡ��������");
			gets(stu[n+1].Name);
			printf("\n������ѡ�ְ༶��");
			gets(stu[n+1].Class);
			printf("\n������������ƣ�");
			gets(stu[n+1].Task);
			printf("\n��������ί���\n");
			inputscore(n);
			for(i=0;i<6;i++)
			printf("%d ",stu[n].Judge[i]);
	        printf("\n\t\t\t�ܳɼ�:");
			printf("%d",stu[n].Total);
			printf("\n");
			n+=1;
			printf("\n");
	        printf("�������µ�ѡ����Ϣ\n");
	        printf("��ţ�%d\n",n);
	        printf("������");puts(stu[n].Name);
	        printf("\n�༶��");puts(stu[n].Class);
	        printf("\n���⣺");puts(stu[n].Task);
	        for(i=0;i<6;i++)
			printf("��ί%d���:%d\n",i+1,stu[n].Judge[i]);
		    printf("�ܳɼ�:%d\n",stu[n].Total);
		    printf("\t�Ƿ�ȷ����ӣ���ѡ��y or n:");
	        scanf("%c", &ch);
	        if(ch=='y'||ch=='Y')
	        {
	        	printf("\n\n��ѡ��:\n1.�������\n2.������һ���˵�\n3.ȡ��\n");
	        	switch(ch)
	        	{
	        		case'1':x=1,z=0,n++;break;
		            case'2':x=0,z=0;n=n++;break;
		            case'3':x=0,z=0;break;
		            default:printf("��������ȷ�ı��!");
					getchar();
				}
			 } 
			 else 
			 printf("δ����κ���Ϣ\n�밴����������ϼ��˵�");
			 system("pause");
			 return;
}




void DelRecord()
{
	char s[12],c; 
	int i=1,j; 
	Header();
	printf("��������ɾ����ѡ������:"); 
	fflush(stdin);
	gets(s); 
	while(strcmp(stu[i].Name,s)!=0&&i<=n) i++; 
	if(i>n) 
	{
		printf("ͨѶ¼��û�д���!\n");
		system("pause"); 
		return; 
	} 
	printf("��ѡ����Ϣ:\n��ţ�%d\n",i);
	printf("������");puts(stu[i].Name);
	printf("�༶��");puts(stu[i].Class);
	printf("���⣺");puts(stu[i].Task);
	printf("�ܷ֣�");scanf("%d",stu[i].Total);
	printf("�Ƿ�ȷ��ɾ��?(����yɾ����n����)\n");
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
	    printf("�ɹ�ɾ����ѡ��!\n");
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
	printf("���������޸�ѡ�ֵı��:"); 
	fflush(stdin);
	scanf("%d",&j);
	while((stu[i].Number=j)!=0&&i<=n) i++; 
	if(i>n) 
	{ 
		printf("ϵͳ��û�д���!\n"); 
		system("pause"); 
		return; 	
	}  
	printf("��������\n ����   �༶   ����   ��ί��� :\n");
	fflush(stdin);
    gets(stu[i].Name);
	gets(stu[i].Class);
	gets(stu[i].Task);
	printf("\n��������ί���\n");
			inputscore(i);
			for(i=0;i<6;i++)
			printf("%d ",stu[i].Judge[k]);
	        printf("\n\t\t\t�ܳɼ�:");
			printf("%d",stu[i].Total);
			printf("\n");
			n+=1;
			printf("\n");

	printf("���ĺ��ѡ����Ϣ��\n");
	printf("��ţ�%d\n",i);
	printf("������");puts(stu[i].Name);
	printf("�༶��");puts(stu[i].Class);
	printf("���⣺");puts(stu[i].Task);
    for(i=0;i<6;i++)
    printf("��ί%d���:%d\n",k,stu[i].Judge[k]);
	printf("�ܳɼ�:%d\n",stu[i].Total);
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
    	printf("��� ����     �༶      ����              ��ίһ    ��   ��   ��   ��   ��  �ܷ� \n");     
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
        printf("          1:��һҳ                      2:��һҳ                       0:�˳�\n");
        printf("����ѡ��(0-2):");
		fflush(stdin);
    	c=getchar();
    	if(c=='1')
		{
		    if(page<max)page+=1;
			else{printf("�������һҳ!");system("pause");}
		}
    	else if(c=='2')
		{
		    if(page>1)page-=1;
			else{printf("���ǵ�һҳ!");system("pause");}
		}
	}while(c!='0');
}

 
 
 
 void QueryBySeatNum() 
{
	int i,k=0; 
	Header();
	printf("���������ѯѡ�ֵı��:"); 
	scanf("%d",&i); 
	if(i>n) 
	{
		printf("ͨѶ¼��û�д˼�¼!\n"); 
		system("pause"); 
		return; 
	} 
	printf("��ţ�%d\n",i);
	printf("������");puts(stu[i].Name);
	printf("�༶��");puts(stu[i].Class);
	printf("���⣺");puts(stu[i].Task);
	for(k=1;k<=6;k++)
    printf("��ί%d���:%d\n",k,stu[i].Judge[k]);
	printf("�ܷ֣�%d",stu[i].Total);
	system("pause"); 
	return;
}
 
 
 
 
 void Sortmain() 
 {
    system("cls");
	char ch,k[20];int m,n=0,count=0;
	printf("\n\n\t\t\t****************************\n");
	printf("\t\t\t*1.�����ܷ���ʾ���ڸ÷�����ѡ��\n");
	printf("\t\t\t*2.����༶��ʾ��������\n");
	printf("\n\t\t\t****************************\n");
	printf("\t\t\t����Ҫ��");
	getchar();
	ch=getchar();
	switch(ch)
	{
	case'1':system("cls");
	        printf("�������");
		    scanf("%d",&m);
			for(n=0;n<all;n++)
			{
				if(stu[n].Total>=m)
				{   printf("������%s\n",stu[n].Name);
		            printf("�༶��%s\n",stu[n].Class);
		            printf("���⣺%s\n",stu[n].Task);
					printf("�ܷ֣�%d\n\n\n",stu[n].Total);
				} 
			};system("pause");break;



	case'2':system("cls");
	        printf("����༶:");
		    scanf("%s",&k);
			for(n=0;n<all;n++)
			{
				if(strcmp(stu[n].Class,k)==0)
					count++;
			}
			printf("\n�ð༶��������Ϊ��%d\n",count);
			system("pause");
			break;
	}
}
 
 
 
 
void Downloadfile()
{
	FILE *fp;
	char Filename[30];
	Header();
	printf("���������:\n");
	printf("��������д��������ļ���:"); 
	scanf("%s",Filename); 
	if((fp=fopen(Filename,"rb"))==NULL)                   
	{ 
		printf("�޷����ļ�...\n"); 
		system("pause"); 
		return; 
	} 
	fread(stu,sizeof(struct student),n+1,fp);
	fclose(fp);
	printf("����ɹ���\n");
	system("pause");
}
  
  
 void inputscore(int a)/*�������ɼ�*/
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
		{ printf("���ܴ��ļ�!\n");
	    return;
        }
     for(i=0;i<all;i++)
     if (fwrite(&stu[N],sizeof(struct student),1,fp)!=1)
 		 printf("д���ļ�����!\n");
         fclose(fp);
     }
     


void Error()
{
	Header();
	printf("\n\n\n\n\n\t\t|\t\tѡ�����!������ѡ��\t\t|\n");
	printf("\n\n\n\t\t\t    �����������������һ���˵�\n");
	return;
}
