#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define NAMESIZE 20
struct Dishes		/*����һ���ṹ��dishes������4����Ա*/ 
{ 
 	char ndish[20];			/*��Ʒ���*/ 
 	char dishes[30];		/*��Ʒ����*/ 
 	float pay;				/*����*/ 
 	int amo;				/*����*/
}dis;						/*������һ���ṹ������*/
void menu2();		/*�˵�����*/
void scan_1();		/*��һ�����벢�������ļ���*/
void scan2();		/*�������*/
void find();		/*��ѯ����*/
void scan_2();		/*�ڶ������벢�������ļ��м���Ӻ���*/
void  print();		/*��ӡ�˵�*/
void myexit();	/*�˳�ϵͳ*/  
void menuz();		/*�ܲ˵�*/
void quitz();		/*���˳�*/
void ordz();
void dianz();
void menuz()				/*�ܲ˵�*/
{
	system("cls");
	printf("\n");
	printf("			 **********С�Ͳ͹�ϵͳ***********				");
	printf("\n"); 
	printf("**************************************************************\n");
	printf("			1.����ϵͳ									\n");
	printf("			2.��ͽ���ϵͳ								\n");
	printf("***************************************************************");
	printf("\n");
	printf("����������Ҫ���������(0-2):\n");
	putchar(10);
}
int main()		/*������*/ 
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
			default:printf("������󣡣����������룺\t");
			system("pause");break;
		}
		menu2();
	}while(true);
	return 0;
}
void quitz()		/*���˳�*/ 
{
	char ch, buff[20];
	gets(buff);
	printf("\t�Ƿ�ȷ���˳�����ѡ��y or n:");
	scanf("%c", &ch);
	if(ch=='y'||ch=='Y') exit(0);
	else menuz();
}
void menu2();		/*�˵�����*/
void scan_1();		/*��һ�����벢�������ļ���*/
void scan2();		/*�������*/
void find();		/*��ѯ����*/
void scan_2();		/*�ڶ������벢�������ļ��м���Ӻ���*/
void  print();		/*��ӡ�˵�*/
void myexit();	/*�˳�ϵͳ*/ 
void menu2()		/*�˵�����*/ 
{
	system("cls");
	printf("\n");
	printf("            ********С�Ͳ͹ݵ�ͽ���ϵͳ********              ");
	printf("\n");
	printf("**************************************************************\n");
	printf("			  �����Ϣ����		        \n");
	printf("			  1.¼���Ʒ��Ϣ                \n");
	printf(" 			  2.�����Ʒ��Ϣ				\n");
	printf("			  3.��Ӳ�Ʒ��Ϣ  				\n");
	printf("  			  4.��ѯ��Ʒ��Ϣ                \n");
	printf("			  5.��ӡ�˵���Ϣ				\n");
	printf("			  0.�˳�ϵͳ					\n");
	printf("***************************************************************");
	printf("\n");
	printf("����������Ҫ���������(0-5):\n");
	putchar(10);
}
void dianz()		/*����ܺ���*/ 
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
			default:printf("������󣡣����������룺\t");
			system("pause");break;
		}
		menu2();
	}while(true);
}
void scan_1()		/*��һ�����벢�������ļ���*/
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
		printf("�������Ʒ��ţ�\t");
		scanf("%s",dis.ndish);
		printf("��Ʒ���ƣ�\t");
		scanf("%s",dis.dishes);
		printf("���ۣ�\t");
		scanf("%f",&dis.pay);
		printf("������\t");
		scanf("%d",&dis.amo);
		system("cls");
		if(fwrite(&dis,sizeof(struct Dishes),1,fp3)!=1)
		{
			printf("File write error!\n");
			exit(0);
		}
		gets(buff);
		printf("�Ƿ��������y or n?\t");
		scanf("%c",&ch);
	}while(ch=='y'||ch=='Y');
	fclose(fp3);
} 
void scan2()		/*�������*/
{
	FILE *fp3;
	if((fp3=fopen("F:\\check.text","rb"))==NULL)
	{
		printf("Can't open the file!\n");
		return;
	}
	printf("���   ����   ����   ����\n");
	while(fread(&dis,sizeof(struct Dishes),1,fp3)==1)
	printf("\n%-5s\t%-5s\t%-3.3f\t%-5d\n",dis.ndish,dis.dishes,dis.pay,dis.amo);
	system("pause");
	fclose(fp3);
} 
void find()			/*��ѯ����*/
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
	printf("������Ҫ��ѯ�ķ�ʽ\n\t1.��Ʒ��� 2.��Ʒ����\n\t��ѡ��1 or 2\t");
	scanf("%d",&a);
	if(a==1)
	{
		printf("�������Ʒ��ţ�\t");
		getchar();
		gets(ch);
		while(fread(&dis,sizeof(struct Dishes),1,fp3)==1)
		if(strcmp(dis.ndish,ch)==0)
		{
			b++;
			printf("���   ����   ����   ����\n");
			printf("\n%-5s\t%-5s\t%-3.3f\t%-5d\n",dis.ndish,dis.dishes,dis.pay,dis.amo);
		}
		system("pause");
		if(b==0) printf("������󣡣���\n");
	}
	else if(a==2)
	{
		printf("�������Ʒ���ƣ�\t");
		getchar();
		gets(ch);
		while(fread(&dis,sizeof(struct Dishes),1,fp3)==1)
		if(strcmp(dis.dishes,ch)==0)
		{
			b++;
			printf("���   ����   ����   ����\n");
			printf("\n%-5s\t%-5s\t%-3.3f\t%-5d\n",dis.ndish,dis.dishes,dis.pay,dis.amo);
		}
		system("pause");
		if(b==0) printf("������󣡣���\n");
	}
	fclose(fp3);
} 
void scan_2()		/*�ڶ������벢�������ļ��м���Ӻ���*/
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
		printf("������Ҫ��Ӳ�Ʒ�ı�ţ�");
		getchar();
		gets(dis.ndish);
		printf("��Ʒ���ƣ�");
		gets(dis.dishes);
		printf("���ۣ�");
		scanf("%f",&dis.pay);
		printf("������");
		scanf("%d",&dis.amo);
		system("cls");
		if(fwrite(&dis,sizeof(struct Dishes),1,fp3)!=1)
		{
			printf("File write error!\n");
			exit(0);
		}
		printf("�Ƿ��������y or n?\t");
		getchar();
		ch=getchar();
	}while(ch=='y'||ch=='Y');
	fclose(fp3);
}
void  print()		/*��ӡ�˵�*/
{
	float sum;
	FILE *fp3;
	if((fp3=fopen("F:\\check.text","rb"))==NULL)
	{
		printf("Can't open the file!\n");
		return;
	}
	printf("���   ����   ����   ����\n");
	while(fread(&dis,sizeof(struct Dishes),1,fp3)==1)
	{
		printf("\n%-5s\t%-5s\t%-3.3f\t%-5d\n",dis.ndish,dis.dishes,dis.pay,dis.amo);
		sum=dis.pay*dis.amo;
		printf("�����%.2f\n",sum);
	}
	system("pause"); 
	fclose(fp3);
} 
void myexit()	/*�˳�ϵͳ*/ 
{
	//int a;
	char ch;
	printf("\t�Ƿ�ȷ���˳�����ѡ��y or n:");
	getchar();
	ch=getchar();
	if(ch=='y'||ch=='Y') exit(0);
	else menuz();
}
#define NAMESIZE 20

struct telord               /*����һ���ṹ��tel-ord,����6����Ա*/ 
{
 	char num[20];			/*���*/ 
 	char name[NAMESIZE];	/*����*/ 
 	int qty;				/*����*/ 
 	char time[5];			/*�ò�ʱ��*/ 
 	int table;				/*����*/ 
 	char arg;				/*�Ƿ��Ѱ���*/ 
}ord;
void menu();				/*�����˵�����*/
void scanf_1();				/*¼��˿���Ϣ*/
int baocun();				/*����˿���Ϣ*/
void scan();				/*����˿���Ϣ*/ 
void scanf_2();				/*��Ӷ�����Ϣ*/
void search_inf();			/*��ѯ������Ϣ*/
void delete_inf();			/*ɾ��������Ϣ*/
void update_inf();			/*�޸Ķ�����Ϣ*/
void quit();				/*�˳�ϵͳ*/

void ordz()		/*����������*/ 
{
	int a;
	menu();
	do{
		scanf("%d",&a);
		switch(a){
		case 1: scanf_1();break;/*¼��˿���Ϣ*/
		case 2: scan();break;/*����˿���Ϣ*/
		case 3: scanf_2();break;/*��ӹ˿���Ϣ*/
		case 4: search_inf();break;/*��ѯ�˿���Ϣ*/
		case 5: delete_inf();break;/*ɾ���˶��˿�*/
		case 6: update_inf();break;/*�޸�Ԥ����Ϣ*/
		case 0:  quit();break;/*�˳�ϵͳ*/
		default : printf("������󣡣������������룺\t"); system("pause"); break;
		}
		menu();
	}while(true);
}
void scanf_1()/*¼����Ϣ���������ļ���*/
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
		printf("������˿ͱ�ţ�");
		scanf("%s",ord.num);
		printf("\n");
		printf("������������");
		scanf("%s",ord.name);
		printf("�������ò�������");
		scanf("%d",&ord.qty);
		printf("�������ò�ʱ�䣺");
		scanf("%s",ord.time);
		printf("���������ţ�");
		scanf("%d",&ord.table);
		printf("�Ƿ��Ѱ��ţ�");
		gets(buff);
		scanf("%c",&ord.arg);
		system("cls");
		if(fwrite(&ord,sizeof(struct telord),1,fp)!=1)
		{
			printf("File write error!\n");
			exit(0);
		}
		gets(buff);
		printf("�Ƿ��������y or n?\t");
		scanf("%c", &ch);
	}while(ch=='y'||ch=='Y');
	fclose(fp);
 } 
 void search_inf()		/*��ѯ����*/ 
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
	printf("\n��������ѯ�밴1;\n���ò�ʱ���ѯ�밴2;\n�����Ų�ѯ�밴3;\n���Ƿ��Ѱ��Ų�ѯ�밴4��\n");
	scanf("%d",&t);
	if(t==1)
	{
		printf("������������\t");
		getchar();
		gets(ch);
		while(fread(&ord,sizeof(struct telord),1,fp)==1)
		if(strcmp(ord.name,ch)==0)
		{
			b++;
			printf("��� ����   ����  �ò�ʱ��  ����  �Ƿ��Ѱ���\n");
			printf("\n%-5s%-7s%-6d%-11s%-5d%c\n",
			ord.num,ord.name,ord.qty,ord.time,ord.table,ord.arg);
		}
		if(b==0) printf("�Բ���û���ҵ������Ϣ��\n");
	}
	else if(t==2)
	{
		printf("�������ò�ʱ�䣺\t");
		getchar();
		gets(ch);
		while(fread(&ord,sizeof(struct telord),1,fp)==1)
		if(strcmp(ord.time,ch)==0)
		{
			b++;
			printf("��� ����   ����  �ò�ʱ��  ����  �Ƿ��Ѱ���\n");
			printf("\n%-5s%-7s%-6d%-11s%-5d%c\n",
			ord.num,ord.name,ord.qty,ord.time,ord.table,ord.arg);
		}
		if(b==0) printf("�Բ���û���ҵ������Ϣ��\n");
	}
	else if(t==3)
	{
		int table1=0;
		printf("������Ҫ���ҵ����ţ�\t");
		scanf("%d",&table1);
		while(fread(&ord,sizeof(struct telord),1,fp)==1)
		if(table1==ord.table)
		{
			b++;
			printf("��� ����   ����  �ò�ʱ��  ����  �Ƿ��Ѱ���\n");
			printf("\n%-5s%-7s%-6d%-11s%-5d%c\n",
			ord.num,ord.name,ord.qty,ord.time,ord.table,ord.arg);
		}
		if(b==0) printf("�Բ���û���ҵ������Ϣ��\n");
	}
	else if(t==4)
	{
		char arg1;
		printf("������Ҫ���ҵİ��ţ�\n");
		gets(buff);
		scanf("%c",&arg1);
		while(fread(&ord,sizeof(struct telord),1,fp)==1)
		if(arg1==ord.arg)
		{
			b++;
			printf("��� ����   ����  �ò�ʱ��  ����  �Ƿ��Ѱ���\n");
			printf("\n%-5s%-7s%-6d%-11s%-5d%c\n",
			ord.num,ord.name,ord.qty,ord.time,ord.table,ord.arg);
		}
		if(b==0) printf("�Բ���û���ҵ������Ϣ��\n");
	}
	fclose(fp);
	system("pause");
}
void  scanf_2()		/*�����Ϣ*/
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
		printf("������˿ͱ�ţ�");
		scanf("%s",ord.num);
		printf("\n");
		printf("������������");
		scanf("%s",ord.name);
		printf("�������ò�������");
		scanf("%d",&ord.qty);
		printf("�������ò�ʱ�䣺");
		scanf("%s",ord.time);
		printf("���������ţ�");
		scanf("%d",&ord.table);
		printf("�Ƿ��Ѱ��ţ�");
		gets(buff);
		scanf("%c",&ord.arg);
		system("cls");
		if(fwrite(&ord,sizeof(struct telord),1,fp)!=1)
		{
			printf("File write error!\n");
			exit(0);
		}
		gets(buff);
		printf("�Ƿ��������y or n?\t");
		scanf("%c", &ch);
	}while(ch=='y'||ch=='Y');
	fclose(fp);
} 
void scan()		/*����ĵ��е���Ϣ*/
{
	FILE *fp;
 	if((fp=fopen("F:\\telord.txt","rb"))==NULL)
 	{
 		printf("Can't open the file!\n");
		system("pause");
		return;	
	}
	printf("��� ����   ����  �ò�ʱ��  ����  �Ƿ��Ѱ���\n");
	while(fread(&ord,sizeof(struct telord),1,fp)==1){
		printf("\n%-5s%-7s%-6d%-11s%-5d%c\n",
	 	ord.num,ord.name,ord.qty,ord.time,ord.table,ord.arg);
	}
	fclose(fp);
	system("pause");
}
void update_inf() /*�޸���Ϣ�ĺ�����������һ���ļ�����Ҫ�޸ĵ���Ϣ�ŵ����ļ��� */ 
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
		printf("������Ҫ�޸ĵĹ˿ͱ�ţ�\t");
		scanf("%s",ch);
		n++;
		while(fread(&ord,sizeof(struct telord),1,fp)==1)
		{
			if(strcmp(ord.num,ch)==0)
			{
				b++;		
				printf("��� ����   ����  �ò�ʱ��  ����  �Ƿ��Ѱ���\n");
				printf("\n%-5s%-7s%-6d%-11s%-5d%c\n",
					ord.num,ord.name,ord.qty,ord.time,ord.table,ord.arg);
	 			printf("������˿͵��±�ţ�");
				scanf("%s",ord.num);
				printf("\n");
				printf("������������");
				scanf("%s",ord.name);
				printf("�������ò�������");
				scanf("%d",&ord.qty);
				printf("�������ò�ʱ�䣺");
				scanf("%s",ord.time);
				printf("���������ţ�");
				scanf("%d",&ord.table);
				printf("�Ƿ��Ѱ��ţ�");
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
			printf("û���ҵ������Ϣ��\n");
			system("pause");
		}
		gets(buff);
		printf("�Ƿ�����޸�y or n?\t");
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
		printf("������Ҫɾ���Ĺ˿ͱ�ţ�\t");
		scanf("%s",ch);
		n++;
		while(fread(&ord,sizeof(struct telord),1,fp)==1)
		{
			if(strcmp(ord.num,ch)==0)
			{
				b++;
				printf("��� ����   ����  �ò�ʱ��  ����  �Ƿ��Ѱ���\n");
				printf("\n%-5s%-7s%-6d%-11s%-5d%c\n",
				ord.num,ord.name,ord.qty,ord.time,ord.table,ord.arg);
	 		}
			else{
				fwrite(&ord,sizeof(struct telord),1,fp2); 
			}
		}
		if(b==0)
		{
			printf("û���ҵ������Ϣ��\n");
			system("pause");
		}
		else{
			printf("ɾ���ɹ���\n");
			system("pause");
		}
		printf("�Ƿ����ɾ��y or n?\t");
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
	printf("\t�Ƿ�ȷ���˳�����ѡ��y or n:");
	scanf("%c", &ch);
	if(ch=='y'||ch=='Y') exit(0);
	else menuz();
}

void menu()		            /*�˵�����*/ 
{
	system("cls");
	printf("\n");
	printf("            ********С�Ͳ͹ݵ绰����ϵͳ********              ");
	printf("\n");
	printf("**************************************************************\n");
	printf("			  �绰ԤԼ��Ϣ����		        \n");
	printf("			  1.¼��˿���Ϣ                \n");
	printf(" 			  2.����˿���Ϣ				\n");
	printf("			  3.��ӹ˿���Ϣ  				\n");
	printf("  			  4.��ѯ�˿���Ϣ                \n");
	printf("			  5.ɾ���˶��˿� 				\n");
	printf("			  6.�޸�Ԥ����Ϣ				\n");
	printf("			  0.�˳�ϵͳ					\n");
	printf("***************************************************************");
	printf("\n");
	printf("����������Ҫ���������(0-6):\n");
	putchar(10);
}

 
