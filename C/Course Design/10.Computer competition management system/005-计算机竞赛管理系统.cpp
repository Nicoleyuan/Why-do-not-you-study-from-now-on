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
	printf("\n\n\n\t\t\t******�������������ϵͳ******");
	printf("\n\t\t\t----------V 1.0.0 ----------");
	printf("\n\t\t\t       1.¼��ѧ����Ϣ");
	printf("\n\t\t\t       2.���ѧ����Ϣ");
	printf("\n\t\t\t       3.�޸�ѧ����Ϣ");
	printf("\n\t\t\t       4.ɾ��ѧ����Ϣ");
	printf("\n\t\t\t       5.��ѯѧ����Ϣ");
	printf("\n\t\t\t       6.ͳ��ѧ����Ϣ");
	printf("\n\t\t\t       7.��ʾѧ����Ϣ"); 
	printf("\n\t\t\t       0.�˳���Ϣ����");
	printf("\n\t\t\t-----By 151303236 ������-----");
	printf("\n\t\t\t****************************\n");
	printf("\n\t\t\t����Ҫ��");
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
	printf("\n��������");
	scanf("%s",stu[n].name);
}

void editcla(int n)
{
	printf("\n�������༶��");
	scanf("%s",stu[n].cla);
}

void editsubject(int n)
{
	printf("\n�²������⣺");
	scanf("%s",stu[n].subject);
}

void editscore(int n)
{
	int i;
	printf("\n�³ɼ�");
}

void insert()
{
	printf("������Ҫ��ӵ�ѧ����Ϣ:\n"); 
	void writeinfo(); 
}  
void edittoal(int n)
{
	printf("\n���ܳɼ���");
	scanf("%s",stu[n].total);
}
/*�������ɼ�*/ 
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
	printf("******�������������ϵͳ******");
	printf("\n----------��    ѯ----------");
	printf("\n�Ѳ�ѯ��ĩβ��");
	printf("\nPress any key to continue..");
	printf("\n\n-----By 151303236 ������-----");
	printf("\n****************************\n");
}
/*�޸�*/ 
void edit(int n)
{
	char ch;
	int a=1,b;
		while (a)
	{
		system("cls");
		printf("******�������������ϵͳ******");
		printf("\n----------��    ��----------");
		printf("\n������Ҫ�޸�ѧ����ѧ�ţ�");
		scanf("%d",&n);
		n=n-1; 
		printf("\n1.���� 2.�����༶ 3.�������� 4.�ɼ�\n");
		printf("\n\n\n�����������޸ĵ����ݣ�");
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
		    printf("\nȷ����(y/n)");
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
	printf("\n\n\t\t\t******�������������ϵͳ******");
	printf("\n\t\t\t----------��    ��----------\n");
	writeinfo();
} 
/*ɾ��*/ 
void del(int n)
{   
	char ch;
	char m[20];
	system("cls");
	loop:
	        printf("������Ҫɾ��������:");
	        scanf("%s",m);
	     	for(n=0;n<stunum;n++)
		    {
			    if(strcmp(stu[n].name,m)==0)
			   {
				    printf("\n�ҵ�������");
				    printf("\n�Ƿ�ɾ������Ϣ?(y/n)");
	                getchar();
				    ch=getchar();
				    switch(ch)
				    {
				        case 'y':
					    for(n=0;n<stunum;n++)
						{
						    strcpy(stu[n].name,stu[n+1].name);				//������һ��ѧ����Ϣ��ǰһ�����ϡ�
			                stu[n].total=stu[n+1].total;
			                strcpy(stu[n].cla,stu[n+1].cla);
			                strcpy(stu[n].subject,stu[n+1].subject);
					    }
							stunum--;
						    printf("ɾ���ɹ�");
						    system("pause");return;
	                        case 'n':break;
						
						
	                }
			    }
				else
				{ 
					printf("\nδ�ҵ���ѧ��������������\n");
					goto loop;
					system("pause");
				}
		   }
}
/*�����˵�*/ 
int editpr(int n)
{
	int a=1;
	char ch;
	while(a)
	{
		getchar(); 
		printf("\n\n1.�޸�ѧ����Ϣ");
		printf("\n2.ɾ��������Ϣ");
		printf("\n3.�����ϼ��˵�\n");
		printf("\n����Ҫ��");
		ch=getchar();
		switch(ch)
		{
		    case '1':edit(n),a=0;break;
		    case '2':del(n),a=0;break;
		    case '3':a=0;return(0);break;
	    }
	}

}
/*��ѯ*/ 
void jsid()
{
	system("cls");
	int n,m,i,j=0;
	printf("\n\n\n\t\t\t******�������������ϵͳ******");
	printf("\n\t\t\t----------��    ѯ----------");
	printf("\n\n\t\t\t-----By 151303236 ������-----");
	printf("\n\t\t\t****************************\n");
	printf("\n\t\t\t��������Ҫ������ѧ�ţ�");
	scanf("%d",&n);
	if(n<=stunum)
	{   
	    n=n-1; 
		printf("ѧ��  ");
		printf("%4d\n",stu[n].id);
		printf("����  ");
		printf("%10s\n",stu[n].name);
		printf("�����༶  ");
		printf("%10s\n",stu[n].cla);
		printf("��������  ");
		printf("%30s\n",stu[n].subject);
        for(i=0;i<M;i++)
        printf("%6d\n",stu[n].score[i]);
		printf("�ܳɼ�  ");
		printf("%d\n", stu[n].total);
		j=editpr(n);
		m++;
	}
	if(m==0)
	{
	     printf("\nError:�޴�ѧ����");
	     printf("\n-----By 151303236 ������-----");
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
/*����*/ 
void writeinfo()
{
	int a,n=1,m,i;
	char ch;
	while (n)
	{
		a=stunum;
		printf("\n\t\t\t���:");
		stu[a].id=(a+1);
		printf("%d",stu[a].id);
		printf("\n\t\t\t����:");
		scanf("%s",stu[a].name);
		printf("\n\t\t\t�����༶:");
		scanf("%s",stu[a].cla);
		printf("\n\t\t\t��������:");
		scanf("%s",stu[a].subject);
		m=1;
		while (m)										
		{
			system("cls");
			printf("\n\t\t\t���:");
			printf("%d",stu[a].id);
			printf("\n\t\t\t����:");
			printf("%s",stu[a].name);
			printf("\n\t\t\t�����༶:");
			printf("%s",stu[a].cla);
			printf("\n\t\t\t��������:");
			printf("%s",stu[a].subject);
			printf("\n\t\t\t��ί���:");
			inputscore(a);
			for(i=0;i<M;i++)
			printf("%d ",stu[a].score[i]);
	        printf("\n\t\t\t�ܳɼ�:");
			printf("%d",stu[a].total);
			printf("\n\t\t\t��ѡ��:\n\t\t\t1.ȷ�ϲ�����\n\t\t\t2.������д\n\t\t\t3.����������\n\t\t\t4.ȷ�ϲ�����\n\t\t\t����Ҫ��");
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
/*ͳ��*/ 
void tongji()
{
    system("cls");
	char ch,k[20];int m,n=0,count=0;
	printf("\n\n\t\t\t******�������������ϵͳ******\n");
	printf("\t\t\t*1.�����ܷ���ʾ���ڸ÷�����ѡ��\n");
	printf("\t\t\t*2.����༶��ʾ��������\n");
	printf("\n\t\t\t-----By 151303236 ������-----");
	printf("\n\t\t\t****************************\n");
	printf("\t\t\t����Ҫ��");
	getchar();
	ch=getchar();
	switch(ch)
	{
	case'1':system("cls");
	        printf("�������");
		    scanf("%d",&m);
			for(n=0;n<stunum;n++)
			{
				if(stu[n].total>=m)
				{   printf("������%s\n",stu[n].name);
		            printf("�༶��%s\n",stu[n].cla);
		            printf("���⣺%s\n",stu[n].subject);
					printf("�ܷ֣�%d\n\n\n",stu[n].total);
				} 
			};system("pause");break;



	case'2':system("cls");
	        printf("����༶:");
		    scanf("%s",&k);
			for(n=0;n<stunum;n++)
			{
				if(strcmp(stu[n].cla,k)==0)
					count++;
			}
			printf("\n�ð༶��������Ϊ��%d\n",count);
			system("pause");
			break;
	}
}
/*��ʾ*/
void printf()
{
	system("cls");
	int b;
    printf("\n\n\n\t\t\t******�������������ϵͳ******\n");
	printf("\t\t\t*1.���ձ����ʾ\n");
    printf("\t\t\t*2.���ճɼ�˳����ʾ\n");
	printf("\t\t\t*0.����\n"); 
	printf("\n\t\t\t-----By 151303236 ������-----");
	printf("\n\t\t\t****************************\n");
	printf("\t\t\t����Ҫ: ");
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
		printf("���%d\t",stu[n].id);
		printf("����:%s\t",stu[n].name);
		printf("�༶:%s\t",stu[n].cla);
      	printf("����:%s\t",stu[n].subject);
		printf("�ܷ�:%d\n",stu[n].total);
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
			    printf("���:%d\t",stu[i].id);
			    printf("����:%s\t",stu[i].name);
			    printf("�༶:%s\t",stu[i].cla);
			    printf("����:%s\t",stu[i].subject);
			    printf("�ܷ�:%d\n",stu[i].total);
			}system("pause");
			
}


/*������*/ 
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
			printf("\t\t\t******�������������ϵͳ******");
	        printf("\n\t\t\t----------¼    ��----------\n");
			writeinfo();break;
		    case '2':add();break;
		    case '3':edit(n);break;
		    case '4':del(n);break; 
			case '5':jsid();break;
		    case '6':tongji();break;
		    case '7':printf();break;
			case '0':system("cls");n=0;printf("\n\n\n\n\n\n\n\n\n\t\t\t**��лʹ�ã��ټ���**\n\t\t\t");break;
		}
	}
	filesave();
}
