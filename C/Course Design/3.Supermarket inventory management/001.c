//���п�����ϵͳ
//�༶�����1501
//ѧ�ţ�151303128
//���������ӽ�
//ָ����ʦ�������

# include <stdio.h>
# include <windows.h>
# include <stdlib.h>
# include <conio.h> 
# include <string.h>
# define LIM 100
# define DATE 20
# define NUMBER 100 //��Ʒ����//
void menu(); //���˵�//
void findmenu(); // ��ѯ�˵�//
void welcome(); //��ӭ����//
void error(); // ���������//
void Append();//�����Ʒ ���� // 
void Findin(); //����Ų�ѯ����//
void find();//��ѯ����// 
void Browse();//�������//
void Amend();//�޸ĺ���//
void Del();//ɾ������//
void NmFindin();//�������Ʋ�ѯ//
void Arrange();//����˵�����//
void saleparrange();//���ۼ�����//
void stockarrange();//���ս���������//
void numberarrange();//���������//
void Alarm();//�����ϢԤ��ϵͳ//
void showlimup();//��ʾ�ٽ����������Ʒ//
void showlimdown();//��ʾ�ٽ����������Ʒ//
void showdate();//��ʾ����������Ʒ//
void colorsetting(); //ϵͳ��ɫ�趨//
void Update();//��Ʒ��Ϣ����//

struct ima
{
	int id;  //��Ʒ����
	char name[20];//����
	char kind[20];//���
	int number;//����
	int limup;//�������
	int limdown;//�������
	float stockp;//�����۸�
	float salep;//���ۼ۸�
	long int stockdate;//��������
	int stocknum;//������
	long int producedate;//��������
	char producename[20];//��������
	int guaranteedate;//������
};


void welcome() //��ӭ����// 
{
	int i,j;
	for(i=0;i<7;i++)
	{
	   printf("\t   ************************************************************\n\n\n");
	   printf("\n\t         ������ﻶӭ���볬�п�����ϵͳ�������\n\n"); 
	   printf("\n\n\t   ************************************************************\n");
	   printf("\n\t\t\t\t\t\t���������������......\n");
	   Sleep(222);
	   	if(i!=6) 
			system("cls");
			
		for(j=0;j<i;j++) 
			printf("\n");

	}
    getch();
	
}

void error() // ѡ�������// 
{
	system("cls");
	printf("\n\n\n\n\n\t\t|\t\tѡ�����!������ѡ��\t\t|\n");
	printf("\n\n\n\t\t\t    ������������˳�\n");
} 

int evaluateID(int id) //�ж���Ʒ����Ƿ��ظ�  ����//
{
	struct ima i;
	FILE * fp;
	fp=fopen("ima.date","r");
	if(fp==NULL)
	{
		printf("\t\t\t ϵͳ������������......");
		exit(0); 
	}
	fread(&i,sizeof(struct ima),1,fp);
	
	while(!feof(fp))
	{
		if(i.id==id)
		{
			fclose(fp);
			return 1;
			break;
		}
		fread(&i,sizeof(struct ima),1,fp); 
	}
	fclose(fp);
	return 0;
} 
void Append() //�����Ʒ  ���� // 
{       struct ima i;
	    char choice;
		FILE *fp;
		fp=fopen("ima.date","ab");
		if(fp==NULL)
		{
			printf("\t\t\tϵͳ������������........");
			exit(0);
		}
		
	  ID:
		printf("\n\t\t\t��������Ҫ�����Ʒ����Ϣ...\n");
		printf("\t\t\t   ��Ʒ�ı��:");
		scanf("%d",&i.id);
		if(evaluateID(i.id)==1)
		{
			printf("\t\t\t\t�˱���ѱ�ʹ�ã�������������......");
			goto ID;
		}
	    printf("\t\t\t   ��Ʒ�����ƣ�");
	    scanf("%s",i.name); 
	    printf("\t\t\t   ��Ʒ�����");
	    scanf("%s",i.kind); 
	    printf("\t\t\t   ��Ʒ��������");
	    scanf("%d",&i.number); 
	    printf("\t\t\t   ��Ʒ�Ŀ�����ޣ�");
	    scanf("%d",&i.limup); 
	    printf("\t\t\t   ��Ʒ�Ŀ�����ޣ�");
	    scanf("%d",&i.limdown); 
	    printf("\t\t\t   ��Ʒ�Ľ����۸�");
	    scanf("%f",&i.stockp);
	    printf("\t\t\t   ��Ʒ�ĳ��ۼ۸�");
	    scanf("%f",&i.salep);  
	    printf("\t\t\t   ��Ʒ�Ľ������ڣ�����19970706����");
	    scanf("%ld",&i.stockdate); 
	    printf("\t\t\t   ��Ʒ�Ľ�������");
	    scanf("%d",&i.stocknum); 
	    printf("\t\t\t   ��Ʒ���������ڣ�");
	    scanf("%ld",&i.producedate); 
	    printf("\t\t\t   ��Ʒ�ĳ��ң�");
	    scanf("%s",i.producename); 
	    printf("\t\t\t   ��Ʒ�ı����ڣ�");
	    scanf("%d",&i.guaranteedate); 
		fwrite(&i,sizeof(struct ima),1,fp);
		fclose(fp);
		printf("\t\t\t\t\t\t  ��Ʒ��Ϣ�����ɹ�!!!\n");
		
		printf("\n���������?(y/n)");
		scanf(" %c",&choice);
		if(choice=='Y'||choice=='y')
		{
			Append();
		}
		else
		{
			system("cls");
			menu();
		}
}
void Del()//ɾ������//
{
	FILE * fp;
	int delID,count=0,j=0;
	char choice;
	struct ima temp;
	struct ima i[NUMBER];
	fp=fopen("ima.date","r");
    
	if (fp==NULL)
	{
		printf("\t\t\tϵͳ������������......");
		exit(0);
	}
	
	fread(&temp,sizeof(struct ima),1,fp);
	while(!feof(fp))
	{
		i[count]=temp;
		count++;
        fread(&temp,sizeof(struct ima),1,fp);
	}fclose(fp);
	
	printf("\n\t����������Ҫɾ����Ʒ�ı��......");
	scanf("%d",&delID);
	fp=fopen("ima.date","wb");
	if(fp==NULL)
	{
		printf("\t\t\t ϵͳ����������������......");
		exit(0);
	}

	for(j=0;j<count;j++)
	{
		if(i[j].id!=delID)
			fwrite(&i[j],sizeof(struct ima),1,fp);
	}fclose(fp);
	printf("\t\t\t����Ʒ��ɾ��������\n");
	printf("\n���������?(y/n)");
		
	scanf(" %c",&choice);
	if(choice=='Y'||choice=='y')
	{
	    Del();
	}
	else
	{
		system("cls");
		menu();
	}



}
void Amend()
{
	FILE * fp;
	int amendID ,count=0,j;
	char choice;
	struct ima i[NUMBER];
	struct ima temp;
    
	fp=fopen("ima.date","r");
	if(fp==NULL)
	{	
		printf("\t\t\t ϵͳ������������......");
        exit(0);
	}
    // �������ļ����ݶ���ṹ����struct ima i��// 
	fread(&temp,sizeof(struct ima),1,fp);
	while(!feof(fp))
	{
		i[count]=temp;
		count++;
		fread(&temp,sizeof(struct ima),1,fp);
	}fclose(fp);     
    
	//���޸ĺ������д��//
	fp=fopen("ima.date","w");
    if(fp==NULL)
	{
		printf("\t\t\t  ϵͳ������������......");
		exit(0);
	}
    
	printf("\n\t ����������Ҫ�޸ĵ���Ʒ���......");
	scanf("%d",&amendID);
	for(j=0 ; j<=count-1 ;j++)
	{
		if(i[j].id!=amendID)
		{
			fwrite(&i[j],sizeof(struct ima),1,fp);
		}
		else
		{   
			printf("\t\t   ��������Ҫ�޸ĵ���Ϣ......\n");
			printf("\t\t   ��Ʒ�����ƣ�");
	        scanf("%s",i[j].name); 
	        printf("\t\t   ��Ʒ�����");
	        scanf("%s",i[j].kind); 
	        printf("\t\t   ��Ʒ��������");
	        scanf("%d",&i[j].number); 
	        printf("\t\t   ��Ʒ�Ŀ�����ޣ�");
	        scanf("%d",&i[j].limup); 
	        printf("\t\t   ��Ʒ�Ŀ�����ޣ�");
	        scanf("%d",&i[j].limdown); 
	        printf("\t\t   ��Ʒ�Ľ����۸�");
	        scanf("%f",&i[j].stockp);
	        printf("\t\t   ��Ʒ�ĳ��ۼ۸�");
	        scanf("%f",&i[j].salep);  
	        printf("\t\t   ��Ʒ�Ľ������ڣ�����19970706����");
	        scanf("%ld",&i[j].stockdate); 
	        printf("\t\t   ��Ʒ�Ľ�������");
	        scanf("%d",&i[j].stocknum); 
 	        printf("\t\t   ��Ʒ�ĳ��ң�");
     	    scanf("%s",i[j].producename); 
    	    printf("\t\t   ��Ʒ�ı����ڣ�");
	        scanf("%d",&i[j].guaranteedate); 
			fwrite(&i[j],sizeof(struct ima),1,fp);
		
		}
	}fclose(fp);
		  
	      printf("\t\t\t��Ʒ��Ϣ���޸�......");
	      printf("\n���������?(y/n)");
		  scanf(" %c",&choice);
		  if(choice=='Y'||choice=='y')
			{
			  Amend();
			}
		  else
		   {
			  system("cls");
		   	  menu();
			}
	   
}
void Findin()  //����Ų�ѯ����//
{ 
	
		FILE *fp;
		int findID;char choice;struct ima i;
		fp=fopen("ima.date","r");
		if(fp==NULL)
		{		
			printf("\t\t\tϵͳ������������........");
			exit(0);
		}
      	printf("\n\t������Ҫ��ѯ����Ʒ�ı��(����-1�˳�)......");
		scanf("%d",&findID);
		if(findID==-1) findmenu();
		
		fread(&i,sizeof(struct ima),1,fp);
		
		while(!feof(fp))
		{  
			if(i.id==findID)
			{   
			   printf("\n\t   ��Ʒ�����ƣ�%s\n",i.name);
	           printf("\t   ��Ʒ�����%s\n",i.kind);
	           printf("\t   ��Ʒ��������%d\n",i.number);
	           printf("\t   ��Ʒ�Ŀ�����ޣ�%d\n",i.limup);
	           printf("\t   ��Ʒ�Ŀ�����ޣ�%d\n",i.limdown);
	           printf("\t   ��Ʒ�Ľ����۸�%.2f\n",i.stockp);
	           printf("\t   ��Ʒ�ĳ��ۼ۸�%.2f\n",i.salep);
	           printf("\t   ��Ʒ�Ľ������ڣ�����19970706����%d\n",i.stockdate);
	           printf("\t   ��Ʒ�Ľ�������%d\n",i.stocknum);
	           printf("\t   ��Ʒ���������ڣ�%d\n",i.producedate);
	           printf("\t   ��Ʒ�ĳ��ң�%s\n",i.producename);
	           printf("\t   ��Ʒ�ı����ڣ�%d\n",i.producedate);
			   printf("�Ƿ��������y/n��");
			   scanf(" %c",&choice);
				if(choice=='Y'||choice=='y')
				{
					Findin();
				}
				else
				{
					system("cls");
					findmenu();
				}
			}
			fread(&i,sizeof(struct ima),1,fp);
		}
		   fclose(fp);
		   printf("\t\t\t\t\t����ı�Ų����ڣ�������������......");
           Findin();
}

void NmFindin()  //�����Ʋ�ѯ����//
{ 
	
		FILE *fp;
		char find[20];char choice;struct ima i;char s1[5]="exit";
		fp=fopen("ima.date","r");
		if(fp==NULL)
		{		
			printf("\t\t\tϵͳ������������........");
			exit(0);
		}
      	printf("\n\t������Ҫ��ѯ����Ʒ������(����exit�˳�)......");
		scanf("%s",find);
        if(strcmp(find,s1)==0)  findmenu();
		
		fread(&i,sizeof(struct ima),1,fp);
		
		while(!feof(fp))
		{  
			if(strcmp(find,i.name)==0)
			{   
			   printf("\n\t   ��Ʒ�����ƣ�%s\n",i.name);
	           printf("\t   ��Ʒ�����%s\n",i.kind);
	           printf("\t   ��Ʒ��������%d\n",i.number);
	           printf("\t   ��Ʒ�Ŀ�����ޣ�%d\n",i.limup);
	           printf("\t   ��Ʒ�Ŀ�����ޣ�%d\n",i.limdown);
	           printf("\t   ��Ʒ�Ľ����۸�%.2f\n",i.stockp);
	           printf("\t   ��Ʒ�ĳ��ۼ۸�%.2f\n",i.salep);
	           printf("\t   ��Ʒ�Ľ������ڣ�����19970706����%d\n",i.stockdate);
	           printf("\t   ��Ʒ�Ľ�������%d\n",i.stocknum);
	           printf("\t   ��Ʒ���������ڣ�%d\n",i.producedate);
	           printf("\t   ��Ʒ�ĳ��ң�%s\n",i.producename);
	           printf("\t   ��Ʒ�ı����ڣ�%d\n",i.producedate);
			   printf("�Ƿ��������y/n��");
			   scanf(" %c",&choice);
				if(choice=='Y'||choice=='y')
				{
					NmFindin();
				}
				else
				{
					system("cls");
					findmenu();
				}
			}
			fread(&i,sizeof(struct ima),1,fp);
		}
		   fclose(fp);
		   printf("\t\t\t\t\t��������Ʋ����ڣ�������������......");
           NmFindin();
}


void Browse() //�������//
{ 
	struct ima i;
	char choice; FILE * fp;
	int count=0;
	fp=fopen("ima.date","r");
	fread(&i,sizeof(struct ima),1,fp);
	if(fp==NULL)
	{
		printf("\t\t\tϵͳ������������......");
		exit(0);
	}
	
	while(!feof(fp))
	{
		count++;
		printf("\n\n\t****************��Ʒ��Ϣ%d*****************",count);
        printf("\n\t   ��Ʒ�����ƣ�%s\n",i.name);
	    printf("\t   ��Ʒ�����%s\n",i.kind);
	    printf("\t   ��Ʒ��������%d\n",i.number);
	    printf("\t   ��Ʒ�Ŀ�����ޣ�%d\n",i.limup);
	    printf("\t   ��Ʒ�Ŀ�����ޣ�%d\n",i.limdown);
	    printf("\t   ��Ʒ�Ľ����۸�%.2f\n",i.stockp);
	    printf("\t   ��Ʒ�ĳ��ۼ۸�%.2f\n",i.salep);
	    printf("\t   ��Ʒ�Ľ������ڣ�����19970706����%d\n",i.stockdate);
	    printf("\t   ��Ʒ�Ľ�������%d\n",i.stocknum);
	    printf("\t   ��Ʒ���������ڣ�%d\n",i.producedate);
	    printf("\t   ��Ʒ�ĳ��ң�%s\n",i.producename);
	    printf("\t   ��Ʒ�ı����ڣ�%d\n",i.producedate);
		fread(&i,sizeof(struct ima),1,fp);
	}
	fclose(fp);
		printf("\n���������?(y/n)");
		scanf(" %c",&choice);
		if(choice=='Y'||choice=='y')
		{
			Browse();
		}
		else
		{
			system("cls");
			menu();
		}
}

void saleparrange()//���ۼ�����//
{
	struct ima i[NUMBER];
	struct ima temp;
	struct ima t;
	int count=1,j,m;
	FILE * fp;

	fp=fopen("ima.date","r");

	if(fp==NULL)
	{
		printf("\t\tϵͳ������������......");
		exit(0);
	}

	fread(&temp,sizeof(struct ima),1,fp);
	while(!feof(fp))
	{
		i[count]=temp;
		count++;
		fread(&temp,sizeof(struct ima),1,fp);
	
	}fclose(fp);
    
	for(m=1 ;m<=count-2; m++)
	{   for(j=1;j<=count-1-m;j++)	
	{
		if(i[j].salep>i[j+1].salep) //С����ǰ//
		{ 
			t=i[j];i[j]=i[j+1];i[j+1]=t;
		} 
	}}
	
	printf("\t\t\t----------���ս���������----------");
    for(j=1 ; j<=count-1;j++)
	{     printf("\n\n\t****************��Ʒ��Ϣ%d*****************",i[j].id);
		  printf("\n\t   ��Ʒ�����ƣ�%s\n",i[j].name);
	      printf("\t   ��Ʒ�����%s\n",i[j].kind);
	      printf("\t   ��Ʒ��������%d\n",i[j].number);
          printf("\t   ��Ʒ�Ŀ�����ޣ�%d\n",i[j].limup);
		  printf("\t   ��Ʒ�Ŀ�����ޣ�%d\n",i[j].limdown);
	      printf("\t   ��Ʒ�Ľ����۸�%.2f\n",i[j].stockp);
          printf("\t   ��Ʒ�ĳ��ۼ۸�%.2f\n",i[j].salep);
	      printf("\t   ��Ʒ�Ľ������ڣ�����19970706����%d\n",i[j].stockdate);
          printf("\t   ��Ʒ�Ľ�������%d\n",i[j].stocknum);
		  printf("\t   ��Ʒ���������ڣ�%d\n",i[j].producedate);
	      printf("\t   ��Ʒ�ĳ��ң�%s\n",i[j].producename);
          printf("\t   ��Ʒ�ı����ڣ�%d\n",i[j].producedate);
	}
    printf("\t�밴����������ϼ��˵�......");
	getch();
	Arrange();
}
void stockarrange()//����������//
{
	struct ima i[NUMBER];
	struct ima temp;
	struct ima t;
	int count=1,j,m;
	FILE * fp;

	fp=fopen("ima.date","r");

	if(fp==NULL)
	{
		printf("\t\tϵͳ������������......");
		exit(0);
	}

	fread(&temp,sizeof(struct ima),1,fp);
	while(!feof(fp))
	{
		i[count]=temp;
		count++;
		fread(&temp,sizeof(struct ima),1,fp);
	
	}fclose(fp);
    
	for(m=1 ;m<=count-2; m++)
	{   for(j=1;j<=count-1-m;j++)	
	{
		if(i[j].stocknum>i[j+1].stocknum) //С����ǰ//
		{ 
			t=i[j];i[j]=i[j+1];i[j+1]=t;
		} 
	}}
	printf("\t\t\t----------���ս���������----------");
    for(j=1 ; j<=count-1;j++)
	{     printf("\n\n\t****************��Ʒ��Ϣ%d*****************",i[j].id);
		  printf("\n\t   ��Ʒ�����ƣ�%s\n",i[j].name);
	      printf("\t   ��Ʒ�����%s\n",i[j].kind);
	      printf("\t   ��Ʒ��������%d\n",i[j].number);
          printf("\t   ��Ʒ�Ŀ�����ޣ�%d\n",i[j].limup);
		  printf("\t   ��Ʒ�Ŀ�����ޣ�%d\n",i[j].limdown);
	      printf("\t   ��Ʒ�Ľ����۸�%.2f\n",i[j].stockp);
          printf("\t   ��Ʒ�ĳ��ۼ۸�%.2f\n",i[j].salep);
	      printf("\t   ��Ʒ�Ľ������ڣ�����19970706����%d\n",i[j].stockdate);
          printf("\t   ��Ʒ�Ľ�������%d\n",i[j].stocknum);
		  printf("\t   ��Ʒ���������ڣ�%d\n",i[j].producedate);
	      printf("\t   ��Ʒ�ĳ��ң�%s\n",i[j].producename);
          printf("\t   ��Ʒ�ı����ڣ�%d\n",i[j].producedate);
	}
    printf("\t�밴����������ϼ��˵�......");
	getch();
	Arrange();
    
}
void numberarrange()//���������//
{
	struct ima i[NUMBER];
	struct ima temp;
	struct ima t;
	int count=1,j,m;
	FILE * fp;

	fp=fopen("ima.date","r");

	if(fp==NULL)
	{
		printf("\t\tϵͳ������������......");
		exit(0);
	}

	fread(&temp,sizeof(struct ima),1,fp);
	while(!feof(fp))
	{
		i[count]=temp;
		count++;
		fread(&temp,sizeof(struct ima),1,fp);
	
	}fclose(fp);
    
	for(m=1 ;m<=count-2; m++)
	{   for(j=1;j<=count-1-m;j++)	
	{
		if(i[j].number>i[j+1].number) //С����ǰ//
		{ 
			t=i[j];i[j]=i[j+1];i[j+1]=t;
		} 
	}}
    
	printf("\t\t\t----------���ս���������----------");
    for(j=1 ; j<=count-1;j++)
	{     printf("\n\n\t****************��Ʒ��Ϣ%d*****************",i[j].id);
		  printf("\n\t   ��Ʒ�����ƣ�%s\n",i[j].name);
	      printf("\t   ��Ʒ�����%s\n",i[j].kind);
	      printf("\t   ��Ʒ��������%d\n",i[j].number);
          printf("\t   ��Ʒ�Ŀ�����ޣ�%d\n",i[j].limup);
		  printf("\t   ��Ʒ�Ŀ�����ޣ�%d\n",i[j].limdown);
	      printf("\t   ��Ʒ�Ľ����۸�%.2f\n",i[j].stockp);
          printf("\t   ��Ʒ�ĳ��ۼ۸�%.2f\n",i[j].salep);
	      printf("\t   ��Ʒ�Ľ������ڣ�����19970706����%d\n",i[j].stockdate);
          printf("\t   ��Ʒ�Ľ�������%d\n",i[j].stocknum);
		  printf("\t   ��Ʒ���������ڣ�%d\n",i[j].producedate);
	      printf("\t   ��Ʒ�ĳ��ң�%s\n",i[j].producename);
          printf("\t   ��Ʒ�ı����ڣ�%d\n",i[j].producedate);
	}
    printf("\t�밴����������ϼ��˵�......");
	getch();
	Arrange();
    
}
void main()//������//
{	
	welcome();
	while(1)
	{ menu();
	 getch();
	}
	
}

void find()//��ѯ����//
{
	while(1)
	{  
		findmenu();
		getch();
	}
}

void menu()  //�˵�����// 
{   int choose;
	system("cls"); 
	printf("\n�ޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡ����п�����ϵͳ���ޡޡޡޡޡޡޡޡޡޡޡޡޡޡ�\n");
	printf("--------------------------------ϵͳ�˵���ʾ����--------------------------------\n");
	printf("\n\t��=====================��           ��Ʒ��Ϣ����         ��\n");
	printf("\n\t��=====================��           ��Ʒ��Ϣ��ѯ         ��\n");
	printf("\n\t��=====================��           ��Ʒ��Ϣ���         ��\n");
	printf("\n\t��=====================��           ��Ʒͳ������         ��\n");
	printf("\n\t��=====================��           �����ϢԤ��         ��\n");
	printf("\n\t��=====================��           ϵͳ��ɫ�趨         ��\n");
	printf("\n\t��=====================��           �˳�����ϵͳ         ��\n");
	printf("\n\t��������Ҫѡ��Ĺ��ܲ˵���......");
	scanf("%d",&choose);
		switch(choose)
		{
			case 1:
				system("cls");
				Update();;break;
			
			case 2:
				system("cls");
				find();break;
			
			case 3:
				system("cls");
				Browse();break;
					
			case 4:
				system("cls");
				Arrange();break;
			
			case 5:
				system("cls");
				Alarm();break;
			
			case 6:
				system("cls");
                colorsetting();break;
			
			case 7:
				system("cls");
				printf("\n�ޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡ���лʹ�ã�лл�����ޡޡޡޡޡޡޡޡޡޡޡޡޡޡ�\n");
				getchar();
				exit(0);
				
			default:
			    system("cls");
                error();break;
		}

}

void findmenu() // ��ѯ���� �����˵�//
{  int choose;
   system("cls");
   printf("\n--------------------------------��ѯ������ʾ����--------------------------------\n");
   printf("\n\t��=====================��           ���ձ�Ų�ѯ         ��\n");
   printf("\n\t��=====================��           �������Ʋ�ѯ         ��\n");
   printf("\n\t��=====================��           �����ϼ��˵�         ��\n");
   printf("\n��������Ҫѡ��Ĺ��ܲ˵���......");
   scanf("%d",&choose);
		switch(choose)
		{   case 1:
			   system("cls");
			   Findin();break;
		    
		    case 2:
		       system("cls");
			   NmFindin();break;
		    
			case 3:
			   printf("�밴�����ȷ�ϻص���һ���˵�......");menu();
			
			default :
				error();
				getch();
				find();
		}

}


void Arrange()
{
   int choose;
   system("cls");
   printf("\n--------------------------------���򷽷���ʾ����--------------------------------\n");
   printf("\n\t��=====================��           �������ۼ�����        ��\n");
   printf("\n\t��=====================��           ���ս���������         ��\n");
   printf("\n\t��=====================��           ���տ��������         ��\n");
   printf("\n\t��=====================��           ������һ���˵�         ��\n");
   printf("\n��������Ҫѡ��Ĺ��ܲ˵���......");
   scanf("%d",&choose);
		switch(choose)
		{   case 1:
			   system("cls");
			   saleparrange();break;
		    
		    case 2:
			   system("cls");
			   stockarrange();break;
		    
			case 3:
				system("cls");
				numberarrange();break;
			
			case 4:
			   printf("�밴�����ȷ�ϻص���һ���˵�......");return;
			
			default :
				error();
				break;
		}
		getchar();

}

void Alarm()
{  
   int choose;
   system("cls");
   printf("\n--------------------------------������ʾ����--------------------------------\n");
   printf("\n\t��=====================��           ��ʾ�ٽ����������Ʒ    ��\n");
   printf("\n\t��=====================��           ��ʾ�ٽ����������Ʒ    ��\n");
   printf("\n\t��=====================��           ��ʾ�ٽ�������Ʒ        ��\n");
   printf("\n\t��=====================��           ������һ���˵�          ��\n");
   printf("\n��������Ҫѡ��Ĺ��ܲ˵���......");
   scanf("%d",&choose);
		switch(choose)
		{   case 1:
			   system("cls");
			   showlimup();break;
		    
		    case 2:
			   system("cls");
			   showlimdown();break;
		    
			case 3:
				system("cls");
				showdate();break;
			
			case 4:
			   printf("�밴�����ȷ�ϻص���һ���˵�......");return;
			
			default :
				error();
				break;
		}

}

void showlimup()//��ʾ�ٽ����������Ʒ//
{
	struct ima i[NUMBER];
	struct ima temp;
	int count=1,j;
	FILE * fp;

	fp=fopen("ima.date","r");

	if(fp==NULL)
	{
		printf("\t\tϵͳ������������......");
		exit(0);
	}

	fread(&temp,sizeof(struct ima),1,fp);
	while(!feof(fp))
	{
		i[count]=temp;
		count++;
		fread(&temp,sizeof(struct ima),1,fp);
	
	}fclose(fp);
    
	printf("\t\t �ٽ�������޵���Ʒ��ϢΪ......\n");
	for(j=1 ; j<=count-1 ;j++)
	{
		if((i[j].limup-i[j].number)<=LIM)
		{ 
		  printf("\n\n\t****************��Ʒ��Ϣ%d*****************",i[j].id);
		  printf("\n\t   ��Ʒ�����ƣ�%s\n",i[j].name);
	      printf("\t   ��Ʒ�����%s\n",i[j].kind);
	      printf("\t   ��Ʒ��������%d\n",i[j].number);
          printf("\t   ��Ʒ�Ŀ�����ޣ�%d\n",i[j].limup);
		  printf("\t   ��Ʒ�Ŀ�����ޣ�%d\n",i[j].limdown);
	      printf("\t   ��Ʒ�Ľ����۸�%.2f\n",i[j].stockp);
          printf("\t   ��Ʒ�ĳ��ۼ۸�%.2f\n",i[j].salep);
	      printf("\t   ��Ʒ�Ľ������ڣ�����19970706����%d\n",i[j].stockdate);
          printf("\t   ��Ʒ�Ľ�������%d\n",i[j].stocknum);
		  printf("\t   ��Ʒ���������ڣ�%d\n",i[j].producedate);
	      printf("\t   ��Ʒ�ĳ��ң�%s\n",i[j].producename);
          printf("\t   ��Ʒ�ı����ڣ�%d\n",i[j].producedate);
		}
	}
	printf("\t �밴����������ϼ��˵�......");
	getch();
	Alarm();
    
}

void showlimdown()//��ʾ�ٽ����������Ʒ//
{
	struct ima i[NUMBER];
	struct ima temp;
	int count=1,j;
	FILE * fp;

	fp=fopen("ima.date","r");

	if(fp==NULL)
	{
		printf("\t\tϵͳ������������......");
		exit(0);
	}

	fread(&temp,sizeof(struct ima),1,fp);
	while(!feof(fp))
	{
		i[count]=temp;
		count++;
		fread(&temp,sizeof(struct ima),1,fp);
	
	}fclose(fp);
    
	printf("\t\t �ٽ�������޵���Ʒ��ϢΪ......\n");
	for(j=1 ; j<=count-1 ;j++)
	{
		if((i[j].number-i[j].limdown)<=LIM)
		{ 
		  printf("\n\n\t****************��Ʒ��Ϣ%d*****************",i[j].id);
		  printf("\n\t   ��Ʒ�����ƣ�%s\n",i[j].name);
	      printf("\t   ��Ʒ�����%s\n",i[j].kind);
	      printf("\t   ��Ʒ��������%d\n",i[j].number);
          printf("\t   ��Ʒ�Ŀ�����ޣ�%d\n",i[j].limup);
		  printf("\t   ��Ʒ�Ŀ�����ޣ�%d\n",i[j].limdown);
	      printf("\t   ��Ʒ�Ľ����۸�%.2f\n",i[j].stockp);
          printf("\t   ��Ʒ�ĳ��ۼ۸�%.2f\n",i[j].salep);
	      printf("\t   ��Ʒ�Ľ������ڣ�����19970706����%d\n",i[j].stockdate);
          printf("\t   ��Ʒ�Ľ�������%d\n",i[j].stocknum);
		  printf("\t   ��Ʒ���������ڣ�%d\n",i[j].producedate);
	      printf("\t   ��Ʒ�ĳ��ң�%s\n",i[j].producename);
          printf("\t   ��Ʒ�ı����ڣ�%d\n",i[j].producedate);
		}
	}
	printf("\t �밴����������ϼ��˵�......");
	getch();
	Alarm();
    
}

void showdate()//��ʾ�ٽ���������Ʒ//
{
	struct ima i[NUMBER];
	struct ima temp;
	struct ima t;
	int count=1,j;
	FILE * fp;

	fp=fopen("ima.date","r");

	if(fp==NULL)
	{
		printf("\t\tϵͳ������������......");
		exit(0);
	}

	fread(&temp,sizeof(struct ima),1,fp);
	while(!feof(fp))
	{
		i[count]=temp;
		count++;
		fread(&temp,sizeof(struct ima),1,fp);
	
	}fclose(fp);
    
	printf("\t\t �ٽ������ڵ���Ʒ��ϢΪ......\n");
	for(j=1 ; j<=count-1 ;j++)
	{
		if(i[j].guaranteedate<=DATE)
		{ 
		  printf("\n\n\t****************��Ʒ��Ϣ%d*****************",i[j].id);
		  printf("\n\t   ��Ʒ�����ƣ�%s\n",i[j].name);
	      printf("\t   ��Ʒ�����%s\n",i[j].kind);
	      printf("\t   ��Ʒ��������%d\n",i[j].number);
          printf("\t   ��Ʒ�Ŀ�����ޣ�%d\n",i[j].limup);
		  printf("\t   ��Ʒ�Ŀ�����ޣ�%d\n",i[j].limdown);
	      printf("\t   ��Ʒ�Ľ����۸�%.2f\n",i[j].stockp);
          printf("\t   ��Ʒ�ĳ��ۼ۸�%.2f\n",i[j].salep);
	      printf("\t   ��Ʒ�Ľ������ڣ�����19970706����%d\n",i[j].stockdate);
          printf("\t   ��Ʒ�Ľ�������%d\n",i[j].stocknum);
		  printf("\t   ��Ʒ���������ڣ�%d\n",i[j].producedate);
	      printf("\t   ��Ʒ�ĳ��ң�%s\n",i[j].producename);
          printf("\t   ��Ʒ�ı����ڣ�%d\n",i[j].producedate);
		}
	}
	printf("\t �밴����������ϼ��˵�......");
    getch();
	Alarm();
}

void colorsetting()
{       int a;
	    char choice;
		system("cls");
		printf("\n\n\t\tѡ�����·���\n");
		printf("\n\n\t\t1**************��׺���\n");
		printf("\n\n\t\t2**************�׵׺���\n");
		printf("\n\n\t\t3**************�ڵ׺���\n");
		printf("\n\n\t\t4**************�̵�����\n");
		printf("\n\n\t\t5**************�Ƶ�����\n");
		printf("\n\n\t\t6**************��������\n");
		printf("\n\n\t\t\t\t\t����ѡ��ϲ������ɫ<1-5>......");
	    
		scanf("%d",&a);
		switch(a)
		{
			case 1:
				system("color 40");
				break;
			case 2:
				system("color F0");
				break;
			case 3:
				system("color 04");
				break;
			case 4:
				system("color 21");
				break;
			case 5:
				system("color 65");
				break;
			case 6:
				system("color 1a");
				break;
			default:
			printf("\n\n\t\t\t\t\t������Ч,��������......");
			getch();
			colorsetting();
	
		}
		
		printf("\nѡ�����ɫ����������?(y�������˵�/n����ѡ��)");
		scanf(" %c",&choice);
		if(choice=='Y'||choice=='y')
		{
			
			system("cls");
			menu();
		}
		else
		{
			colorsetting();
		}
}

void Update()
{
   int choose;
   system("cls");
   printf("\n--------------------------------���·�����ʾ����--------------------------------\n");
   printf("\n\t��=====================��          �¹���Ʒ���       ��\n");
   printf("\n\t��=====================��          ��Ʒ��Ϣ�޸�       ��\n");
   printf("\n\t��=====================��          ��Ʒ��Ϣɾ��       ��\n");
   printf("\n\t��=====================��          �����ϼ��˵�       ��\n");
   printf("\n\t��������Ҫѡ��Ĺ��ܲ˵���......");
   scanf("%d",&choose);
		switch(choose)
		{   case 1:
			   system("cls");
			   Append();break;
		    
		    case 2:
			   system("cls");
			   Amend();break;
		    
			case 3:
				system("cls");
				Del();break;
			
			case 4:
			   printf("�밴�����ȷ�ϻص���һ���˵�......");return;
			
			default :
				error();
				break;
		}getchar();

}