#include<stdio.h> /*��׼�������ͷ�ļ�*/
#include<stdlib.h> /*��׼��ͷ�ļ�*/
#include<windows.h> /*����Windows API ����ͷ�ļ�*/
#include<conio.h> /*����̨�������ͷ�ļ�*/
#include<string.h>
#include<math.h>
#define PI 3.1415926
#define E 1e-6
int  mainmenu();/*�Զ������˵�����*/
int  menu2_1();/*�Զ�������˵�����*/
int  menu2_2();
int  menu2_3(); 
int  menu3_1();/*�Զ��������˵�����*/
int  menu3_2();
int  menu3_3();
float cal();/*�Զ���һ���˵��ӹ��ܺ���*/
void number();/*�Զ�������˵��ӹ��ܺ���*/
void binary();/*������ת��*/
int binary1();/*������ת����ʮ����*/
int binary2();/*ʮ����ת���ɶ�����*/
void octonary();/*�˽���ת��*/
int octonary1();/*�˽���ת����ʮ����*/
int octonary2();/*ʮ����ת���ɰ˽���*/ 
void hex();/*ʮ������*/
char hex1();/*ʮ������ת����ʮ����*/
char hex2();/*ʮ����ת����ʮ������*/
void tri();/*���Ǻ����˵�*/
double Sin();/*���Һ���*/
double Cos();/*���Һ���*/
double zhi();/*ָ��������ݺ�������˵�*/
double dui();/*��������˵�*/ 
void other();/*������������*/
int add();/*��ͺ���*/
int xxx();/*�׳˺���*/ 
void error();/*�Զ���ѡ�������*/
void head1();/*�Զ���˵�ͷ����(��ɫ���)*/
void head2();/*�Զ���˵�ͷ����(�����ƶ�)*/



main() /*������*/
{
	head2();/*head1()*/
	while(1)
	{
		switch(mainmenu())
		{
		case 1:
			system("cls");
			cal();break;

		case 2:
			system("cls");
			number();break;

		case 3:
			system("cls");
			tri();break;

		case 4:
			system("cls");
			zhi();break;

		case 5:
			system("cls");
		    dui();break;

        case 6:
			system("cls");
			other();break;

		case 0:
			system("cls");
			printf("\n\n\n\n\n\t\t|**********��лʹ�ã��ټ�!**********|\t\n\n\n\n\n");
			exit(0);
		default:
			system("cls");
            error();
			break;
		}
		getchar();
	}
return 0;
}

int mainmenu()
{
	int  select;
	system("cls");/*��������*/
	printf("\n\n\n");
	printf("\t\t|==================================================|");
	printf("\t\t\t\t|\t\t   ������\t\t           |\n");
	printf("\t\t|==================================================|\n\n\n");
	printf("\t\t|*****************��ѡ�����ֽ��в���***************|\n");
	printf("\t\t|\t\t��1����������                      |\n");
	printf("\t\t|\t\t��2������ת��                      |\n");
	printf("\t\t|\t\t��3�����Ǻ���                      |\n");
	printf("\t\t|\t\t��4����ָ����                      |\n");
	printf("\t\t|\t\t��5������                          |\n");
	printf("\t\t|\t\t��6����������                      |\n");
	printf("\t\t|\t\t��0���˳�ϵͳ                      |\n");
	printf("\t\t|*****************��ѡ���Ӧ����0**6***************|\n");
	scanf("%d",&select);/*����ѡ���ܵı��*/
	return select;
}

void error()
{
	printf("\n\n\n\n\n\t\t|\t\tѡ�����!������ѡ��\t\t|\n");
	printf("\n\n\n\t\t\t    �����������������һ���˵�\n");
}

void number()
{
	while(1)
	{
		switch(menu2_1())
		{
		case 1:
			 system("cls");
             binary();
	         break;
		case 2:
			 system("cls");
             octonary();
	         break;
	    case 3:
			 system("cls");
             hex();
	         break;     
		case 4:
			 printf("\n\n\n\t\t\t�����������������һ���˵�\n");
             return;
		default:
			system("cls");
            error();
			break;
		}
		getchar();
	}
}


float cal()/*֧�ּ򵥵��������㣬��֧������*/
{
float deal(char deal_char[]);/*������������char������ת����float��*/ 
void add(float num[],int t);/*����t�������������������*/  
void reduce(float num[],int t);/*����t������������������� */ 
void ride(float num[],int t);/*����t������������������� */
void divide(float num[],int t);/*����t������������������� */
void remove_space(char a[]);/*������Ĵ��пո���ַ����ո�ȥ���������ɱ�׼�״������ַ��� */

while(1)/*���˳�ѭ��*/ 
{
int i=0,j=0,k=0,x=0,flag;/*���ָ���  ���������*/    
/*
*i��ѭ�����Ʊ���
*j����¼c_figure�����ݶ��� 
*k����¼c_figure�����ÿһ������ʱ����k��¼��䵽��һ�����
*x����¼�ж��ٸ������������¼c_operator�������
*flag��ÿ�δ���һ���������������ݣ�flag���ڼ�¼ĳ���Ƿ��Ѿ����������� 
*/ 
char input_char[100],deal_char[20];
/*
*�������������ʽ��¼��input_char�У����ַ���ʽ��¼ 
*����ÿһ�������ַ����ݴ���deal_char�� 
*/
float num[20]={0};/*����μ�����ľ������֣��ѱ�������float�ͣ���num��*/ 
char c_figure[20][20];/*��ÿһchar�����ֱַ����c_figureÿһ���� */
char c_operator[20];/*����� */
printf("���������ʽ:\n");
scanf("%s",&input_char);/*����һ����ʽ����Ϊ�ַ����洢*/ 

while(input_char[i]!='\0')/*��char��������������ֿ�*/ 
   {
    if((input_char[i]>=48&&input_char[i]<=57)||(input_char[i]=='.'))/*��֤������ǺϷ����֣�С���㴦��Ϊ�Ϸ� */
    {
        c_figure[j][k]=input_char[i];
        k++;
    }
    else if(input_char[i]=='+'||input_char[i]=='-'||input_char[i]=='*'||input_char[i]=='/')/*���������*/ 
    {
        c_operator[x]=input_char[i];
        c_figure[j][k]=0;
        j++;
        k=0;
        x++;
    }
    else if(input_char[i]=='=')/*�ȺŴ�����֧��û�еȺŵĵ�ʽ*/
	{
        input_char[i+1]=0;
        c_figure[j][k]=0;
    }
    i++;
    }
    c_figure[j][k]=0;
    if(k==0) j--;/*���޵ȺŴ�����k==0���޵Ⱥ�*/ 
    else;
    if(x==j);
    else /*�жϵ�ʽ�Ƿ�����Ϸ�*/ 
    {
        printf("�������������һ��\n");
        system("pause");
        return 0; 
    }
    for(i=0;i<=j;i++)/*��char������ת����float�� */
    {
        strcpy(deal_char,c_figure[i]);
        num[i]=deal(deal_char);
    }
    while(x--)/*����������ȼ����зֱ棬���в�ͬ���� */
    {
        flag=0; /*flagΪ0��ʾδ����������1��ʾ�������� */
        int t;
        for(i=0;i<=x&&flag==0;i++)
        {
            if(c_operator[i]=='/')
                {
                    t=i;
                    divide(num,t);
                    flag=1;
                }
        }
        for(i=0;i<=x&&flag==0;i++)
		{
            if(c_operator[i]=='*')
			{
                t=i;
                ride(num,t);
                flag=1; 
            }   
        } 
        for(i=0;i<=x&&flag==0;i++)
		{
            if(c_operator[i]=='-')
            {
                t=i;
                reduce(num,t);
                flag=1;
            }
        }          
        for(i=0;i<=x&&flag==0;i++)
		{
            if(c_operator[i]=='+')
			{
                t=i;
                add(num,t);
                flag=1;
            }
        }
        for(i=t;i<=x;i++)c_operator[i]=c_operator[i+1];//ÿ����һ�β������������ɾ�� 
    }
    printf("��ʽ�Ľ���ǣ�%f\n\n",num[0]);/*������*/	
	printf("����'-'����������߼���");
}

} 


void add(float num[],int t)/*�ӷ�ʵ��*/
{
    int i;
    num[t]=num[t]+num[t+1];
    for(i=t+1;i<20;i++)
	{
    num[i]=num[i+1];
    }
    return;
}


void reduce(float num[],int t)/*����ʵ��*/ 
{
    int i;
    num[t]=num[t]-num[t+1];
    for(i=t+1;i<20;i++)
	{
        num[i]=num[i+1];
    }
    return;
}


void ride(float num[],int t)/*�˷�ʵ��*/
{
    int i;
    num[t]=num[t]*num[t+1];
    for(i=t+1;i<20;i++)
	{
    num[i]=num[i+1];
    }
    return;
}


void divide(float num[],int t)/*����ʵ��*/ 
{
    int i;
    num[t]=num[t]/num[t+1];
    for(i=t+1;i<20;i++)
	{
    num[i]=num[i+1];
    }
    return;
}

float deal(char deal_char[])/*��char������ת����float�� */
{
    int i=0,flag=0;
    float m=0.0,n=1.0;
    while(deal_char[i]!=0)
	{
        if(deal_char[i]=='.') flag=1;
        else if(flag==0)
		{
            m=m*10+deal_char[i]-48;
        }
        else 
		{
            m+=(deal_char[i]-48)/(10*n);
            n*=10;
        }
        i++;
    }
    return(m);
}

int  menu2_1()/*������ת��*/ 
{
	int   select;
	system("cls");
	printf("\n\n\n\t\t��ѡ�����\n");
	printf("\t\t|*****************************|\n");
	printf("\t\t|    ��1��������ת��          |\n");
	printf("\t\t|    ��2���˽���ת��          |\n");
	printf("\t\t|    ��3��ʮ������ת��        |\n");
	printf("\t\t|    ��4������                |\n");
	printf("\t\t|*****************************|\n\n");
	scanf("%d",&select);
	return select;
}


void binary()/*������ת��*/ 
{
	while(1)
	{
		switch(menu3_1())
		{
		case 1:
			 system("cls");
             binary1();
	         break;
		case 2:
			 system("cls");
             binary2();
	         break;
		case 3:
			 printf("\n\n\n\t\t\t�����������������һ���˵�\n");
             return;
		default:
			system("cls");
            error();
			break;
		}
		getchar();
	}
}

int menu3_1()
{
	int   select;
	system("cls");
	printf("\t\t|********************************|\n");
	printf("\t\t|         ��ѡ�����             |\n");
	printf("\t\t|================================|\n");
	printf("\t\t|    ��1��������ת����ʮ����     |\n");
	printf("\t\t|    ��2��ʮ����ת���ɶ�����     |\n");
    printf("\t\t|    ��3��������һ���˵�         |\n");
	printf("\t\t|********************************|\n");
	scanf("%d",&select);
	return select;
}

int binary2()/*ʮ����ת���ɶ�����*/ 
{
	int a[16],i;
	unsigned n;
	printf("����һ��ʮ������\n");
	scanf("%d",&n);
	i=0;
	do
	{
		a[i]=n%2;
		n=n/2;
		i++;	
	}while(n>0);
	printf("ת���ɶ�������Ϊ��");
	while(i>=1) printf("%d",a[--i]);
	printf("\n\n�����������");
	getchar();
	return 0;
}  


int binary1()/*������ת����ʮ����*/
{	
	int i,t;
    long sum=0;
	char s[50];
	printf("������������� ");
    scanf("%s",s);
    for(i=0;s[i];i++)
	{
    if(s[i]<='9')t=s[i]-'0';
    sum=sum*2+t;
	}
    printf("%ld\n",sum);
    printf("\n�����������");
    getchar();
    return 0;
}

void octonary()/*�˽���ת��*/ 
{
	while(1)
	{
		switch(menu3_2())
		{
		case 1:
			 system("cls");
             octonary1();
	         break;
		case 2:
			 system("cls");
             octonary2();
	         break;
		case 3:
			 printf("\n\n\n\t\t\t�����������������һ���˵�\n");
             return;
		default:
			system("cls");
            error();
			break;
		}
		getchar();
	}
}

int  menu3_2()
{
	int   select;
	system("cls");
	printf("\t\t|**************************|\n");
	printf("\t\t|\t��ѡ�����\t   |\n");
	printf("\t\t|==========================|\n");
	printf("\t\t|    1.�˽���ת����ʮ����  |\n");
	printf("\t\t|    2.ʮ����ת���ɰ˽���  |\n");
    printf("\t\t|    3.������һ���˵�      |\n");
	printf("\t\t|**************************|\n");
	scanf("%d",&select);
	return select;
}

int octonary2()/*ʮ����ת���ɰ˽���*/
{
	int a[16],i;
	unsigned n;
	printf("����һ��ʮ������\n"); 
	scanf("%d",&n);
	i=0;
	do
	{
		a[i]=n%8;
		n=n/8;
		i++;	
	}while(n>0);
	printf("ת��Ϊ�˽�����Ϊ:o");
	while(i>=1) printf("%d",a[--i]);
	printf("\n\n�����������");
	getchar();
    return 0;
 } 


int octonary1()/*�˽���ת����ʮ����*/
/*{	
	char *p,s[6];
	int n;
	p=s;
	printf("����һ���˽�����\n");
	gets(p);
	n=*p-'0';
	while(*(++p)!='\0')
		n=n*8+*p-'0';
	printf("ת��Ϊʮ������Ϊ��%d\n",n);
	system("pause");
return 0;
}*/

{
	int i,t;
    long sum=0;
	char s[50];
	printf("����˽������� ");
    scanf("%s",s);
    for(i=0;s[i];i++)
{
    if(s[i]<='9')t=s[i]-'0';
    
    sum=sum*8+t;
}
printf("%ld\n",sum);
printf("\n�����������");
getchar();
return 0;
}

void hex()/*ʮ������ת��*/
{
	while(1)
	{
		switch(menu3_3())
		{
		case 1:
			 system("cls");
             hex1();
	         break;
		case 2:
			 system("cls");
             hex2();
	         break;
		case 3:
			 printf("\n\n\n\t\t\t�����������������һ���˵�\n");
             return;
		default:
			system("cls");
            error();
			break;
		}
		getchar();
	}
}

int  menu3_3()
{
	int   select;
	system("cls");
	printf("\t\t|**************************|\n");
	printf("\t\t|\t��ѡ�����\t   |\n");
	printf("\t\t|==========================|\n");
	printf("\t\t|1.ʮ������ת����ʮ����    |\n");
	printf("\t\t|2.ʮ����ת����ʮ������    |\n");
    printf("\t\t|3.������һ���˵�          |\n");
	printf("\t\t|**************************|\n");
	scanf("%d",&select);
	return select;
}

char hex2()/*ʮ����ת����ʮ������*/ 
{
int num=0;
int a[100]; 
int i=0; 
int m=0;
int yushu; 
char hex[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
printf("������һ��ʮ����������"); 
scanf("%d",&num); 
while(num>0) 
    { 
    yushu=num%16; 
    a[i++]=yushu; 
    num=num/16; 
    } 
    printf("ת��Ϊʮ��������Ϊ��0x"); 
for(i=i-1;i>=0;i--)//������� 
{ 
m=a[i];
printf("%c",hex[m]); 
} 
printf("\n\n�����������"); 
getchar();
return 0;	
}


char hex1()/*ʮ������ת����ʮ����*/ 
{
	int i,t;
    long sum=0;
	char s[50];
	printf("����ʮ���������� ");
    scanf("%s",s);
    for(i=0;s[i];i++)
{
    if(s[i]<='9')t=s[i]-'0';
    else  t=s[i]-'a'+10;
    sum=sum*16+t;
}
printf("%ld\n",sum);
printf("�����������");
getchar();
return 0;
}

double Pow(double x,double y)
{
	double t=1.0;
	int i;
	for(i=1;i<=y;i++)
	 t*=x;
	return t;
}



double zhi()/*��ָ����*/ 
{
    double Pow(double,double);
	double x,y,m;
	 printf("�������:\t\n");
	scanf("%lf",&x); 
    printf("����ָ��:\t\n");
    scanf("%lf",&y);
	m=Pow(x,y);
    printf("%f",m);
    printf("\n�����������");
	getchar();
	return 0;
}

double LN(double a)/*��������*/ 
{  
   int N = 15;/*ȡ��ǰ15+1�������� */ 
   int k,nk;  
   double x,xx,y;  
   x = (a-1)/(a+1);  
   xx = x*x;  
   nk = 2*N+1;  
   y = 1.0/nk;  
   for(k=N;k>0;k--)  
   {  
     nk = nk - 2;  
     y = 1.0/nk+xx*y;  
       
   }  
   return 2.0*x*y;  
     
}  
  
double dui() /*��������*/ 
{  
    double b; 
	double n;
	printf("������Ȼ����������:");
    scanf("%lf",&n);
    b = LN(n);    
    printf("��Ȼ����ֵΪ %lf\n",b);
	printf("�����������");
    getchar();  
    return 0;  
} 



void tri()/*���Ǻ���*/ 
{
	while(1)
	{
		switch(menu2_2())
		{
		case 1:
			 system("cls");
             Sin();
	         break;
		case 2:
			 system("cls");
             Cos();
	         break;
		case 3:
			 printf("\n\n\n\t\t\t�����������������һ���˵�\n");
             return;
		default:
			system("cls");
            error();
			break;
		}
		getchar();
	}
}

int  menu2_2()
{
	int   select;
	system("cls");
	printf("\t\t|==========================|\n");
	printf("\t\t|      ��ѡ�����          |\n");
	printf("\t\t|--------------------------|\n");
	printf("\t\t|  1.���Һ���              |\n");
	printf("\t\t|  2.���Һ���              |\n");
    printf("\t\t|  3.������һ���˵�        |\n");
	printf("\t\t|==========================|\n");
	scanf("%d",&select);
	return select;
}

double Sin()
{
	int a,b=1,c=1,n=1;
	double z,x,d=0,sinx=0;/*����˫����*/
	printf("������Ƕ� z=");/*����Ϊ�Ƕ�*/
	scanf("%lf",&z);
	x=z*PI/180;
	for(n=1,a=1,c=1;;a++)
	{
		d=Pow(x,n)/c;
		sinx+=b*d;
		b*=-1;
		n++;
		c*=n;
		n++;
		c*=n;
		if(d<E)
		{
			break;
		} 
	}
	printf("sin(%lf)=:%lf\n",z,sinx); 
    printf("\n�����������");
	getchar();
	return 0;
}

double Cos()
{
    double x,z;
    double COS(double x);
    printf("������Ƕ�Ϊ z=");
    scanf("%lf",&z);
	x=z*PI/180;
    printf("cos (%lf)=%lf\n",z,COS(x));
    printf("�����������");
	getchar();
    return 0;
}

double COS(double x)
{
    double COS=0,item=1.0,temp;
    int n=0,sign=1;
    do 
	{
    temp=item;
    for(int i=1;i<=2*n;i++) temp/=i;
    COS +=sign*temp;
    item*=x*x;//item=x^(2n);
    sign *=-1;//sign=-sign;
    n++;
	}while (temp>E);
    return COS;
}

void other()
{
	while(1)
	{
		switch(menu2_3())
		{
		case 1:
			 system("cls");
             add();
	         break;
		case 2:
			 system("cls");
             xxx();
	         break;     
		case 3:
			 printf("\n\n\n\t\t\t�����������������һ���˵�\n");
             return;
		default:
			system("cls");
            error();
			break;
		}
		getchar();
	}
}

int  menu2_3()/**/ 
{
	int   select;
	system("cls");
	printf("\n\n\n\t\t��ѡ�����\n");
	printf("\t\t|-----------------------------|\n");
	printf("\t\t|\t1.���                |\n");
	printf("\t\t|\t2.�׳�                |\n");
	printf("\t\t|\t3.����                |\n");
	printf("\t\t|-----------------------------|\n\n");
	scanf("%d",&select);
	return select;
}

int xxx()/*�׳˺���*/
{
	int n,i,t=1;
	printf("������һ��30���ڵ���:\t");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	t*=i;
	printf("�׳�Ϊ%d\n",t);
	printf("\n�����������");
	getchar();
    return 0;
}

int add()/*��ͺ���*/
{
	int n,sum=0,i;
	printf("������һ����:  ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	sum+=i;
	printf("��Ϊ%d\n",sum);
	printf("\n�����������");
	getchar();
    return 0;
}

void head1()
{
	 /*��ɫ�仯Ч��*/
	int i;
	int t=8;
	printf("\t\t***********************************\n");
	printf("\t\t     ��ӭ����򵥼�����\n");
	printf("\t\t***********************************\n");
    while(--t)
	{ 
	  /*ÿ��forѭ������ÿ����ɫ������ʱ��*/
		for(i=0;i<199;i++);
		system("color d");
		for(i=0;i<199;i++);
		system("color a");
		for(i=0;i<199;i++);
		system("color c");
		for(i=0;i<199;i++);
		system("color b");
		for(i=0;i<199;i++);
		system("color f");
		for(i=0;i<199;i++);
		system("color e");
	}      
}


void head2()
{
	int i,j;
	for(i=0;i<7;i++)
	{
	   printf("\t************************************************************\n\n\n");
	   printf("\n\t\t�������ﻶӭ����򵥼������������\n\n"); 
	   printf("\n\n\t************************************************************\n");
	   printf("\n\n\n\t\t\t���������������\n");
	   Sleep(66);
	   	if(i!=6) 
			system("cls");

		for(j=0;j<i;j++) 
			printf("\n");

	}
    getchar();
}
