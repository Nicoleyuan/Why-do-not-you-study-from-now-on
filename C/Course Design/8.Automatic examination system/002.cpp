#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
int amount1();
int amount2();
int amount3();
void see1();
void see2();
void see3();
void xianshi1(int i);
void xianshi2(int i);
void test1();
void test2();
void add1();
void add2();
void add4();
void modify1();
void modify2();
void del1();
void del2();
void guanli();
void menu() ;
void error();
void ana();
search1(int a[],int n);
search2(int a[],int n);
int grade1=0,grade2=0;
struct xuanze
{
	int num;
	char timu[100];
	char da[50];
	char db[50];
	char dc[50];
	char dd[50];
	char zd[4];
}st[200];
struct shifei
{
	int num;
	char timu[100];
	char y[5];
	char n[5];
char zd[4];
}st2[200];
struct student
{
	int num;
	int score;
}stu[100];


  void main()
  {
	 
	  menu();
  }

int amount1()
{
	FILE *fp;
	int i;
	if((fp=fopen("file1.dat","rb"))==NULL)
		printf("ERROR!");
	for(i=0;!feof(fp);i++)
		fread(&st[i],sizeof(struct xuanze),1,fp);
	fclose(fp);
	return (i-1);
}
int amount2()
{
	FILE *fp;
	int i;
	if((fp=fopen("file2.dat","rb"))==NULL)
		printf("ERROR!");
	for(i=0;!feof(fp);i++)
		fread(&st2[i],sizeof(struct shifei),1,fp);
	fclose(fp);
	return (i-1);
}
int amount3()
{
	FILE *fp;
	int i;
	if((fp=fopen("num_name.dat","rb"))==NULL)
		printf("ERROR!");
	for(i=0;!feof(fp);i++)
		fread(&stu[i],sizeof(struct student),1,fp);
	fclose(fp);
	return (i-1);
}
void see1()
{
	FILE *fp;
	int n,i;
	n=amount1();
	fp=fopen("file1.dat","rb");
	for(i=0;i<n;i++)
	{
		fread(&st[i],sizeof(struct xuanze),1,fp);
		printf("��Ŀ��%d��: %s\n��A��:%s\n��B��:%s\n��C��:%s\n��D��:%s\n����ȷ�𰸡���%s\n",st[i].num,st[i].timu,st[i].da,st[i].db,st[i].dc,st[i].dd,st[i].zd);
	}
	fclose(fp);
}
void see2()
{
	FILE *fp;
	int n,i;
	n=amount2();
	fp=fopen("file2.dat","rb");
	for(i=0;i<n;i++)
	{
		fread(&st2[i],sizeof(struct shifei),1,fp);
		printf("��Ŀ��%d��:%s\n��A��:YES\n��B��:NO\n����ȷ�𰸡���%s\n",st2[i].num,st2[i].timu,st2[i].zd);
	}
	fclose(fp);
}
void xianshi1(int i)
{
	printf("��Ŀ��%d��: %s\n��A��:%s\n��B��:%s\n��C��:%s\n��D��:%s\n",st[i].num,st[i].timu,st[i].da,st[i].db,st[i].dc,st[i].dd);
}
void xianshi2(int i)
{
	printf("��Ŀ��%d��: %s\n��A��:YES\n��B��:NO\n",st2[i].num,st2[i].timu);
}


void test1()
{
	grade1=0;
	int n,f,i,c,r[20];
	char ch[4];
	r[0]=0;
	f=amount1();
	if(f==0)
	{
		printf("\n\t\t������\n\t\t��1�����.\n\t\t��2���������˵�.\n");
		scanf("%d",&c);
		if(c==1) 
		{
			system("cls");add1();
		}
		else
		{
			system("cls");menu();
		}
	}
	for(i=0;i<10;i++)
	{
		srand((unsigned)time(NULL));
		do
		{
			n=search1(r,i+1);
		}while(!(n!=0));
		r[i+1]=n;
		xianshi1(n);
		printf("��ѡ������%d��ѡ����Ĵ𰸣�",i+1);
		scanf("%s",ch);
		if(strcmp(ch,st[n].zd)==0)
		{
			printf("\nright!\n");
			grade1++;
		}
		else
		{
			printf("\nwrong!the correct answer is %s\n",st[n].zd);
		}
	}
	
}
void test2()
{
	int x,y;
	grade2=0;
	int n,f,i,k,c,r[20];
	char ch[4];
	r[0]=0;
	f=amount2();
	if(f==0)
	{
		printf("\n\t\t������\n\t\t��1�����.\n\t\t��2���������˵�.\n");
		scanf("%d",&c);
		if(c==1)
		{
			system("cls");add2();
		}
		else 
		{
			system("cls");menu();
		}
	}
	for(i=0;i<10;i++)
	{
		do
		{
			n=search2(r,i+1);
		}while(!(n!=0));
		r[i+1]=n;
		xianshi2(n);
		printf("��ѡ������%d���Ƿ���Ĵ𰸣�",i+1);
		scanf("%s",ch);
		if(strcmp(ch,st2[n].zd)==0)
		{
			printf("\nright!\n");
			grade2++;
		}
		else
		{
			printf("\nwrong!the correct answer is %s\n ",st2[n].zd);
		}
	}
	x=amount3();
	y=x+1;
	printf("���������ѧ��:");
	scanf("%d",&stu[y].num);
	printf("the %d student's grade is %d \n",stu[y].num,5*(grade1+grade2));
	stu[y].score=5*(grade1+grade2);
	add4();
	printf("\n\t\t��1���������˵�\n");
	scanf("%d",&k);
	system("cls");
	switch(k)
	{
	case 1:menu();break;
	default :system("cls");
	}
	
}
void add1()
{
	int i,n,k;
	FILE *fp;
	n=amount1();
	printf("\n\t\tĿǰ��������С�%d������Ŀ\n",n);
	if((fp=fopen("file1.dat","ab"))==NULL)
		printf("\nerror!\n");
	i=n+1;
	printf("�������%d����Ŀ��Ϣ��",i);
      printf("����š���");
	  scanf("%d",&st[i].num);
	  printf("����Ŀ����");scanf("%s",st[i].timu);
      printf("����A����");scanf("%s",st[i].da);
	  printf("����B����");scanf("%s",st[i].db);
	  printf("����C����");scanf("%s",st[i].dc);
	  printf("����D����");scanf("%s",st[i].dd);
      printf("����ȷ���ǣ�����");scanf("%s",st[i].zd);printf("\n");
	  system("cls");
	  printf("���������ǣ�����Ŀ����%s\n����A����%s\n����B����%s\n����C����%s\n����D����%s\n����ȷ���ǣ�����%s\n",st[i].timu,st[i].da,st[i].db,st[i].dc,st[i].dd,st[i].zd);
	  fwrite(&st[i],sizeof(struct xuanze),1,fp);
	  printf("success!\n");
	  fclose(fp);
	  printf("\t��1���������\n\t��2�����ع���˵�\n\t��3���������˵�\n");
	  printf("\t������:");
		scanf("%d",&k);
		system("cls");
		switch(k)
		{
		case 1:add1();break;
		case 2:guanli();break;
		case 3:printf("�������˵���");break;
		default:system("cls");
			error(); 
		}
}
void add2()
{
	int i,n,k;
	FILE *fp;
	n=amount2();
	printf("\n\t\tĿǰ��������С�%d������Ŀ\n",n);
	if((fp=fopen("file2.dat","ab"))==NULL)
		printf("\nerror!\n");
	i=n+1;
	printf("�������%d����Ŀ��Ϣ��",i);
      printf("����š���");
	  scanf("%d",&st2[i].num);
	  printf("����Ŀ����");scanf("%s",st2[i].timu);
      printf("����A����YES\n");
	  printf("����B����NO\n");
      printf("����ȷ���ǣ�����");scanf("%s",st2[i].zd);printf("\n");
	  system("cls");
	  printf("\n���������ǣ�����Ŀ����%s\n����A����YES\n����B����NO\n����ȷ���ǣ�����%s\n",st2[i].timu,st2[i].zd);
	  fwrite(&st2[i],sizeof(struct shifei),1,fp);
	  printf("success!\n");
	  fclose(fp);
	  printf("\t��1���������\n\t��2�����ع���˵�\n\t��3���������˵�\n");
	  printf("\t������:");
		scanf("%d",&k);
		system("cls");
		switch(k)
		{
		case 1:add2();break;
		case 2:guanli();break;
		case 3:printf("�������˵���");break;
		default:system("cls");
			error(); 
		}
}
void modify1()
{
	int a,i,n,m,h,flag2=0;
	FILE *fp;
	static d;
	see1();
	n=amount1();
	printf("\n\t\t��������Ҫ�޸ĵ���Ŀ��ţ�");
	scanf("%d",&a);
	fp=fopen("file1.dat","rb+");
	for(i=0;i<n;i++)
	{ 
		if(a==st[i].num)
		{
		system("cls");
		xianshi1(i);
		printf("\n����ȷ�𰸡�:%s",st[i].zd);
		d=i;
		flag2=1;break; 
		}
		else flag2=0;
	}
	if(flag2==1)
	{
		printf("\n\t\t������Ҫ�޸ĵ���Ŀ��\n\n");
        printf("\t\t��1����Ŀ\n");
		printf("\t\t��2��Aѡ��\n");
        printf("\t\t��3��Bѡ��\n");
        printf("\t\t��4��Cѡ��\n");
        printf("\t\t��5��Dѡ��\n");
		printf("\t\t��6����ȷ��\n");

		scanf("%d",&m);

		if(m==1)
		{
			printf("�������޸ĺ����Ŀ��\n");
			scanf("%s",st[d].timu);
		}
    	else if(m==2)
		{
			printf("�������޸ĺ��Aѡ�\n");
			scanf("%s",st[d].da);
		}
		else if(m==3)
		{
			printf("�������޸ĺ��Bѡ�\n");
			scanf("%s",st[d].db);
		}
        else if(m==4)
		{
			printf("�������޸ĺ��Cѡ�\n");
			scanf("%s",st[d].dc);
		}
        else if(m==5)
		{
			printf("�������޸ĺ��Dѡ�\n");
			scanf("%s",st[d].dd);
		}
            else if(m==6)
		{
			printf("�������޸ĺ����ȷ�𰸣�\n");
			scanf("%s",st[d].zd);
		}
			fclose(fp);
			fp=fopen("file1.dat","wb");
			for(i=0;i<n;i++)
				fwrite(&st[i],sizeof(struct xuanze),1,fp);
			fclose(fp);
			printf("�޸ĳɹ�!");
			printf("\n\t\t��1�����ع���˵�\n");
			printf("\t\t��2�������޸�\n");
			printf("\t\t������:");
        scanf("%d",&h);
		system("cls");
		switch(h)
		{
		case 1:guanli();break;
		case 2:system("cls");modify1();break;
		default:system("cls");error();
		}
	}
	else 
		printf("\n\t\t�޴���ŵ���Ŀ!\n\t\t");
		system("pause");
		system("cls");
	guanli();
}
void modify2()
{
	int a,i,n,m,h,flag2=0;
	FILE *fp;
	static d;
	see2();
	n=amount2();
	printf("\n\t\t��������Ҫ�޸ĵ���Ŀ��ţ�");
	scanf("%d",&a);
	fp=fopen("file2.dat","rb+");
	for(i=0;i<n;i++)
	{ 
		if(a==st2[i].num)
		{
		system("cls");
		xianshi2(i);
		printf("\n����ȷ�𰸡�:%s",st2[i].zd);
		d=i;
		flag2=1;break; 
		}
		else flag2=0;
	}
	if(flag2==1)
	{
		printf("\n\t\t������Ҫ�޸ĵ���Ŀ��\n\n");
        printf("\t\t��1����Ŀ\n");
		printf("\t\t��2����ȷ�� A:YES  B:NO\n");
		scanf("%d",&m);
		if(m==1)
		{
			printf("�������޸ĺ����Ŀ��\n");
			scanf("%s",st2[d].timu);
		}
    	else if(m==2)
		{
			printf("�������޸ĺ����ȷ�𰸣�\n");
			scanf("%s",st2[d].zd);
		}
			fclose(fp);
			fp=fopen("file2.dat","wb");
			for(i=0;i<n;i++)
				fwrite(&st2[i],sizeof(struct shifei),1,fp);
			fclose(fp);
			printf("�޸ĳɹ�!");
			printf("\n\t\t��1�����ع���˵�\n");
			printf("\t\t��2�������޸�\n");
			printf("\t\t������:");
        scanf("%d",&h);
		system("cls");
		switch(h)
		{
		case 1:guanli();break;
		case 2:system("cls");modify2();break;
		default:system("cls");error();
		}
	}
	else 
		printf("\n\t\t�޴���ŵ���Ŀ!\n\t\t");
		system("pause");
		system("cls");
	guanli();
}
void del1()
{
	int a,n,i,k,j,c,d,flag1=0;
	FILE *fp;
	FILE *fp1;
	n=amount1();
	if(n==0)
	{
		printf("\n\t\tĿǰ�������������\n\t\t��1����ӡ�\n\t\t��2���˳�\n");
		scanf("%d",&c);
		if(c==1)
			add1();
		else exit(0);
	}
	
	else
	{
		see1();
	printf("\n\t��������Ҫɾ��������ţ�");
	scanf("%d",&a);
	fp=fopen("file1.dat","rb");
	for(i=0;i<n;i++)
	{ 
		if(a==st[i].num)
		{     
			flag1=1;break;
		}
	}
	if(flag1==0)
	{
		system("cls");
		printf("\n\t�޴���ŵ���Ŀ\n");
		printf("��1������ɾ��.\n��2�����ع���˵�\n��ѡ��:");
		scanf("%d",&d);
		switch(d)
		{
		case 1:system("cls");del1();break;
		case 2:system("cls");guanli();break;
		default:system("cls");error();
		}
		fclose(fp);
	}
	  
	  else
	  {
		  k=i;
		     for(j=k;j<n-1;j++)
			 {
				 st[j].num=st[j+1].num;
				 strcpy(st[j].timu,st[j+1].timu);
			     strcpy(st[j].da,st[j+1].da);
				 strcpy(st[j].db,st[j+1].db);
				 strcpy(st[j].dc,st[j+1].dc);
				 strcpy(st[j].dd,st[j+1].dd);
				 strcpy(st[j].zd,st[j+1].zd);
			  }
	
	         fclose(fp);
	         fp1=fopen("file1.dat","wb");
		     for(i=0;i<n-1;i++)
     	    fwrite(&st[i],sizeof(struct xuanze),1,fp1);
		    fclose(fp1);
	    	puts("\nɾ�������ɹ���\n");
		    printf("\n\t\t��1������ɾ��\n");
			printf("\t\t��2�����ع���˵�\n");
			printf("\t\t������:");
			scanf("%d",&k);
			system("cls");
	     	switch(k)
			{
	     	case 1:del1();break;
	    	case 2:guanli();break;
			default:system("cls");
			error(); 
			}
		}
	}
}
void del2()
{
	int a,n,i,k,j,c,d,flag1=0;
	FILE *fp;
	FILE *fp1;
	n=amount2();
	if(n==0)
	{
		printf("\n\t\tĿǰ�������������\n\t\t��1����ӡ�\n\t\t��2���˳�\n");
		scanf("%d",&c);
		if(c==1)
			add2();
		else exit(0);
	}
	
	else
	{
		see2();
	printf("\n\t��������Ҫɾ��������ţ�");
	scanf("%d",&a);
	fp=fopen("file2.dat","rb");
	for(i=0;i<n;i++)
	{ 
		if(a==st2[i].num)
		{     
			flag1=1;break;
		}
	}
	if(flag1==0)
	{
		system("cls");
		printf("\n\t�޴���ŵ���Ŀ\n");
		printf("��1������ɾ��.\n��2�����ع���˵�\n��ѡ��:");
		scanf("%d",&d);
		switch(d)
		{
		case 1:system("cls");del2();break;
		case 2:system("cls");guanli();break;
		default:system("cls");error();
		}
		fclose(fp);
	}
	  
	  else
	  {
		  k=i;
		     for(j=k;j<n-1;j++)
			 {
				 st2[j].num=st2[j+1].num;
				 strcpy(st2[j].timu,st2[j+1].timu);
			     strcpy(st2[j].y,st2[j+1].y);
				 strcpy(st2[j].n,st2[j+1].n);
				 strcpy(st2[j].zd,st2[j+1].zd);
			  }
	
	         fclose(fp);
	         fp1=fopen("file2.dat","wb");
		     for(i=0;i<n-1;i++)
     	    fwrite(&st2[i],sizeof(struct shifei),1,fp1);
		    fclose(fp1);
	    	puts("\nɾ�������ɹ���\n");
		    printf("\n\t\t��1������ɾ��\n");
			printf("\t\t��2�����ع���˵�\n");
			printf("\t\t������:");
			scanf("%d",&k);
			system("cls");
	     	switch(k)
			{
	     	case 1:del2();break;
	    	case 2:guanli();break;
			default:system("cls");
			error(); 
			}
		}
	}
}
void guanli()
{
	int n;
	printf("\t\t����������������������������\n");
	printf("\t\t��     1.����ѡ����       ��\n");
	printf("\t\t��     2.�����Ƿ���       ��\n");
	printf("\t\t��     3.�޸�ѡ����       ��\n");
	printf("\t\t��     4.�޸��Ƿ���       ��\n");
	printf("\t\t��     5.ɾ��ѡ����       ��\n");
	printf("\t\t��     6.ɾ���Ƿ���       ��\n");
	printf("\t\t��     7.�鿴ѡ����       ��\n");
	printf("\t\t��     8.�鿴�Ƿ���       ��\n");
	printf("\t\t��     9.�������˵�       ��\n");
	printf("\t\t����������������������������\n");
	printf("\t\t��ѡ��:");
	scanf("%d",&n);
	switch(n)
	{case 1:system("cls");add1();break;
	 case 2:system("cls");add2();break;
	 case 3:system("cls");modify1();break;
	 case 4:system("cls");modify2();break;
	 case 5:system("cls");del1();break;
	 case 6:system("cls");del2();break;
	 case 7:system("cls");see1();system("pause");system("cls");guanli();break;
	 case 8:system("cls");see2();system("pause");system("cls");guanli();break;
	 case 9:system("cls");menu();break;
	 default:system("cls");
		 error();
	}
}
void menu() 
{
	int c;
	while(1)
	{	
		printf("\n\n\n\n\n\t\t     ��ӭ���뿼��ϵͳ     \n");
		printf("\t\t����������������������������\n");
		printf("\t\t��      1.���뿼��        ��\n");
		printf("\t\t��      2.������Ŀ        ��\n");
		printf("\t\t��      3.�ɼ�����        ��\n");
		printf("\t\t��      4.�˳�ϵͳ        ��\n");
		printf("\t\t����������������������������\n");
		printf("\t\t��ѡ��:");

		scanf("%d",&c);
	
		switch(c)
		{
		case 1:system("cls");printf("��������10��ѡ�����10���Ƿ������.\n");
			printf("ѡ�����A,B,C,D��ѡ����ȷ�𰸣��Ƿ����A,B��ѡ����ȷ��.\n");
			system("pause");system("cls");test1();test2();break;
   		case 2:system("cls");guanli();break;
		case 3:system("cls");see3();ana();
			break;
		case 4:printf("\nGoodbye!\n");exit(0);
		default:system("cls");
		error();break;
		}
	system("pause");
	system("cls");
	}
}
void error()
{
	printf("\n\n\n\n\n\t\t|\t\tѡ�����!������ѡ��\t\t|\n");
	printf("\n\n\n\t\t\t    �����������������һ���˵�\n");
}


void see3()
{
	FILE *fp;
	int n,i,j,t,s;
	n=amount3();
	fp=fopen("num_name.dat","rb");
	for(i=0;i<=n-2;i++)
	{
		fread(&stu[i],sizeof(struct student),1,fp);
		for(j=i+1;j<=n-1;j++)
		{
			fread(&stu[j],sizeof(struct student),1,fp);
			if(stu[i].num>stu[j].num)
			{
				t=stu[i].num;
				stu[i].num=stu[j].num;
				stu[j].num=t;
				s=stu[i].score;
				stu[i].score=stu[j].score;
				stu[j].score=s;
			}
		}
	}
	fclose(fp);
	for(i=0;i<n;i++)
	{
		fread(&stu[i],sizeof(struct student),1,fp);
		printf("\t\tѧ��:%d:\t�÷�:%d\n",stu[i].num,stu[i].score);
	}
	fclose(fp);
}
void add4()
{
	FILE *fp;
	int n,i;
	n=amount3();
	i=n+1;
	fp=fopen("num_name.dat","ab");
	fwrite(&stu[i],sizeof(struct student),1,fp);
	fclose(fp);
}
void ana()/*�ɼ�����*/
{
	int a1=0,a2=0,a3=0,a4=0,a5=0;
	int i,j,k,l,low,high,sum=0;
	float aver;
	l=amount3();
	low=high=stu[0].score;
	for(i=1;i<l;i++)
	{
		if(stu[i].score<low)
			low=stu[i].score;
		if(stu[i].score>high)
			high=stu[i].score;
	}
	for(j=0;j<l;j++)
		sum+=stu[j].score;
	aver=(float)sum/l;
	for(k=0;k<l;k++)
	{
		if(stu[k].score<=60)
			a1++;
		else if(stu[k].score>60&&stu[k].score<=70)
			a2++;
		else if(stu[k].score>70&&stu[k].score<=80)
			a3++;
		else if(stu[k].score>80&&stu[k].score<=90)
			a4++;
		else if(stu[k].score>90&&stu[k].score<=100)
			a5++;
	}
	printf("\t\tThe highest grade is: %d\n",high);
	printf("\t\tThe lowest grade is: %d\n",low);
	printf("\t\tThe average grade is: %.2f\n",aver);
	printf("\t\t%d�˳ɼ�С��60��\n",a1);
	printf("\t\t%d�˳ɼ���60��70��֮��\n",a2);
	printf("\t\t%d�˳ɼ���70��80��֮��\n",a3);
	printf("\t\t%d�˳ɼ���80��90��֮��\n",a4);
	printf("\t\t%d�˳ɼ���90��100��֮��\n",a5);
}


search1(int a[],int n)/*���������*/
{
	int i,f,k,s;
	f=amount1();
	srand((unsigned)time(NULL));
	do
	{
		s=rand()%200+1;
		for(i=0;i<n;i++)
		{
			if(s!=a[i])
				k=s;
			else
			{
				k=0;
				break;
			}
		}
		if(k!=0&&k<=f)
			break;
	}while(1);
	return k;
}
search2(int a[],int n)
{
	int i,f,k,s;
	f=amount2();
	srand((unsigned)time(NULL));
	do
	{
		s=rand()%200+1;
		for(i=0;i<n;i++)
		{
			if(s!=a[i])
				k=s;
			else
			{
				k=0;
				break;
			}
		}
		if(k!=0&&k<=f)
			break;
	}while(1);
	return k;
}
