//written by ʩ���
#include<stdio.h>              /*��׼�������ͷ�ļ�*/
#include<stdlib.h>  
#include<windows.h>            /*����Windows API ����ͷ�ļ�*/
#include<time.h>
void star();
void mainmenu();                /*�Զ������˵�����*/
void input();                  /*¼�뺯��*/
void modify();                 /*�޸ĺ���*/
void insert();                 /*��Ӻ���*/
void del();                    /*ɾ������*/
void search();                 /*��ѯ����*/
void print();                  /*��ʾ����*/
void sort();               /*�ɼ�����*/
void error();                  /*�Զ���ѡ�������*/
void tongji();
void filesave();
void fileopen();
void manage();                   //����
void k();
int stunum=0;
struct student
{
	int id;                   /*���*/
	char name[20];              /*����*/
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
            case '0': system("cls"); printf("\n\n\n\n\n\n\n\n\n\t\t\t**��лʹ�ã��ټ���**\n\t\t\t");
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

    printf("\n\n\n\n\t\t\t**��ӭʹ�þ�������ϵͳ**\n");
    star();
    printf("\t\t��ѡ�����ֽ��в�����\n");
    printf("\t\t\t*1.����ѡ����Ϣ\n");
    printf("\t\t\t*2.��ʾѡ����Ϣ\n");
    printf("\t\t\t*3.ѡ����Ϣ����\n");
    printf("\t\t\t*4.��ѯѡ����Ϣ\n");
    printf("\t\t\t*5.ͳ��ѡ����Ϣ\n");
    printf("\t\t\t*0.�˳�ϵͳ\n");
    star();
    printf("\t\t��ѡ��Ĺ��ܱ�ţ�");
	
}




void star()
{ 
    printf("\t\t***************************************\n");
}
void error()
{
	printf("\n\n\n\n\n\n\n\t\t\t**ѡ�����!������ѡ��**\t\t\n");
	printf("\n\n\t\t\t�����������������һ���˵�\n");
    getchar();
}
    


void input()
{
	int a,n=1,m;int i,total=0,c;
	while(n)
	{   

		a=stunum;
		system("cls");
        printf("��ʼ¼��ѡ����Ϣ:\n");

        
		std[a].id=(a+1);

		printf("���%d\n",std[a].id);
		printf("����:");
		scanf("%s",&std[a].name);
		printf("\n�༶:");
		scanf("%s",&std[a].clas);
		printf("\n����:");
		scanf("%s",&std[a].project);
		printf("�����Զ�¼����ί���\n");
      srand((unsigned)time(NULL));
	for(i=0;i<6;i++)
	{
	    std[a].score[i]=1+rand()%100;
	    printf("��ί�ķ���Ϊ%d\t",std[a].score[i]);
	    total+=std[a].score[i];
	}
     printf("\n�ܷ֣�%d",total);
	 std[a].total=total;
           
		   m=1;
		   while(m)
		   {
			printf("\n��ѡ��1.ȷ�ϲ�����  2.������д  3.����������  4.ȷ�ϲ�����");
			scanf("%d",&c);
			switch(c)
			{
			case 1:m=0;stunum++;break;
			case 2:stunum,m=0;break;
			case 3:m=0,n=0;break;						//ѡ�����ʱ��m=0��ѭ����ֹ
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
			printf("���:%d\t",std[i].id);
			printf("����:%s\t",std[i].name);
			printf("�༶:%s\t",std[i].clas);
			printf("����:%s         ",std[i].project);
			printf("�ܷ�:%d\n",std[i].total);
			};system("pause");
			
}
void print()
{
	int b;
	
	printf("*1.���ձ����ʾ\n");
    printf("*2.���ճɼ��ɵ͵�����ʾ\n");
	printf("*0.����\n");
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
				   printf("���:%d\n",std[i].id);
		           printf("����:%s",std[i].name);
				   printf("\n�༶:%s",std[i].clas);
      	           printf("\n����:%s",std[i].project);
		           printf("\n�ܷ�:\n%d\n\n",std[i].total);
	}system("pause");//�ó���ͣ�ڴ˴�
}
void manage()
{
    int b;
	
	printf("*1.��Ϣ���\n");
    printf("*2.��Ϣɾ��\n");
	printf("*3.��Ϣ�޸�\n");
	printf("*0.����");
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
	printf("������Ҫɾ��������");
loop:
	scanf("%s",m);
	for(n=0;n<stunum;n++)
	{
		if(strcmp(std[n].name,m)==0)
		{
			printf("�ҵ�������");
			printf("�Ƿ�ɾ������Ϣ?(y/n)");
            getchar();
			ch=getchar();
			switch(ch)
			{
			case 'y':std[n].id=std[n+1].id;
				     
				     strcpy(std[n].name,std[n+1].name);				//������һ��ѧ����Ϣ��ǰһ�����ϡ�
		             std[n].score[6]=std[n+1].score[6];
		             std[n].total=std[n+1].total;
		             strcpy(std[n].clas,std[n+1].clas);
		             strcpy(std[n].project,std[n+1].project);
					 stunum--;
					 printf("ɾ���ɹ�");
					 system("pause");return;
		
			case 'n':return;

			}
		}
			
		else
			{ 
				printf("δ�ҵ���ѧ��������������\n");
				goto loop;
				system("pause");

				
			
			}
	}
}

void insert()
{ 
	printf("���ѡ����Ϣ");
	input();
}




void modify()
{
	int i,n=0;
	char ch;
	printf("�����������޸�ѧ���ı�ţ�");
loop1:
	scanf("%d",&i);
	for(n=0;n<stunum;n++)
	{
		if(i!=std[n].id)
		continue;
			printf("�ҵ��ñ�ŵ�ѧ��\n");
			printf("�Ƿ�ȷ���޸ģ���y/n��");
			getchar();
			ch=getchar();
			switch(ch)
			{
			case 'y':printf("�µ����֣�\n");
				     scanf("%s",&std[n].name);
					 printf("�µİ༶��\n");
					 scanf("%s",&std[n].clas);
					 printf("�µĿ��⣺\n");
					 scanf("%s",&std[n].project);
					 
					 printf("�޸ĳɹ�");
					 system("pause");return;
		
			case 'n':return;
			}
	}   
		{
			printf("δ�ҵ���ѧ����������������\n");
		   goto loop1;
		   system("pause");
		}
		
}
	


void search()
{
	int j,n,i;
	printf("********************����ѡ���********************");
loop2:
	scanf("%d",&j);
	for(n=0;n<stunum;n++)
	{
	   if(j!=(std[n].id))
		   continue;
	       printf("������%s\n",std[n].name);
		   printf("�༶��%s\n",std[n].clas);
		   printf("���⣺%s\n",std[n].project);
		   printf("6����ί�ķ���Ϊ��");
		   for(i=0;i<6;i++)
		   {
			   printf("%d\t",std[n].score[i]);
		   }
		   printf("\n�ܷ�Ϊ��%d\n\n\n",std[n].total);system("pause");return;
	}
		
	   
	   {
		   printf("δ�ҵ���ѡ�֣�����������\n");
		   goto loop2;
		   system("pause");
	   }
}

void tongji()
{
    char ch,k[20];int m,n=0,count=0;
	printf("*1.�����ܷ���ʾ���ڸ÷�����ѡ��\n");
	printf("*2.����༶��ʾ��������");
	getchar();
	ch=getchar();
	switch(ch)
	{
	case'1':printf("�������");
		    scanf("%d",&m);
			for(n=0;n<stunum;n++)
			{
				if(std[n].total>=m)
				{   printf("������%s\n",std[n].name);
		            printf("�༶��%s\n",std[n].clas);
		            printf("���⣺%s\n",std[n].project);
					printf("�ܷ֣�%d\n\n\n",std[n].total);
				} 
			};system("pause");break;



	case'2':printf("����༶:\n");
		    scanf("%s",&k);
			for(n=0;n<stunum;n++)
			{
				if(strcmp(std[n].clas,k)==0)
					count++;
			}
			printf("�ð༶��������Ϊ��%d",count);
			system("pause");
			break;
	}
}