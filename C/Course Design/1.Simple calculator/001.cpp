#include<stdio.h> /*标准输入输出头文件*/
#include<stdlib.h> /*标准库头文件*/
#include<windows.h> /*加载Windows API 函数头文件*/
#include<conio.h> /*控制台输入输出头文件*/
#include<string.h>
#include<math.h>
#define PI 3.1415926
#define E 1e-6
int  mainmenu();/*自定义主菜单函数*/
int  menu2_1();/*自定义二级菜单函数*/
int  menu2_2();
int  menu2_3(); 
int  menu3_1();/*自定义三级菜单函数*/
int  menu3_2();
int  menu3_3();
float cal();/*自定义一级菜单子功能函数*/
void number();/*自定义二级菜单子功能函数*/
void binary();/*二进制转换*/
int binary1();/*二进制转换成十进制*/
int binary2();/*十进制转换成二进制*/
void octonary();/*八进制转换*/
int octonary1();/*八进制转换成十进制*/
int octonary2();/*十进制转换成八进制*/ 
void hex();/*十六进制*/
char hex1();/*十六进制转换成十进制*/
char hex2();/*十进制转换成十六进制*/
void tri();/*三角函数菜单*/
double Sin();/*正弦函数*/
double Cos();/*余弦函数*/
double zhi();/*指数运算和幂函数运算菜单*/
double dui();/*对数运算菜单*/ 
void other();/*其他常见运算*/
int add();/*求和函数*/
int xxx();/*阶乘函数*/ 
void error();/*自定义选择错误函数*/
void head1();/*自定义菜单头函数(彩色变幻)*/
void head2();/*自定义菜单头函数(渐变移动)*/



main() /*主函数*/
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
			printf("\n\n\n\n\n\t\t|**********感谢使用，再见!**********|\t\n\n\n\n\n");
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
	system("cls");/*清屏函数*/
	printf("\n\n\n");
	printf("\t\t|==================================================|");
	printf("\t\t\t\t|\t\t   计算器\t\t           |\n");
	printf("\t\t|==================================================|\n\n\n");
	printf("\t\t|*****************请选择数字进行操作***************|\n");
	printf("\t\t|\t\t【1】四则运算                      |\n");
	printf("\t\t|\t\t【2】数制转换                      |\n");
	printf("\t\t|\t\t【3】三角函数                      |\n");
	printf("\t\t|\t\t【4】幂指函数                      |\n");
	printf("\t\t|\t\t【5】对数                          |\n");
	printf("\t\t|\t\t【6】其他运算                      |\n");
	printf("\t\t|\t\t【0】退出系统                      |\n");
	printf("\t\t|*****************请选择对应数字0**6***************|\n");
	scanf("%d",&select);/*输入选择功能的编号*/
	return select;
}

void error()
{
	printf("\n\n\n\n\n\t\t|\t\t选择错误!请重新选择\t\t|\n");
	printf("\n\n\n\t\t\t    请输入任意键返回上一级菜单\n");
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
			 printf("\n\n\n\t\t\t请输入任意键返回上一级菜单\n");
             return;
		default:
			system("cls");
            error();
			break;
		}
		getchar();
	}
}


float cal()/*支持简单的四则运算，不支持括号*/
{
float deal(char deal_char[]);/*处理函数，将char型数字转换成float型*/ 
void add(float num[],int t);/*将第t个运算符两侧的数字相加*/  
void reduce(float num[],int t);/*将第t个运算符两侧的数字相减 */ 
void ride(float num[],int t);/*将第t个运算符两侧的数字相乘 */
void divide(float num[],int t);/*将第t个运算符两侧的数字相除 */
void remove_space(char a[]);/*将输入的带有空格的字符串空格去掉，处理成标准易处理的字符串 */

while(1)/*无退出循环*/ 
{
int i=0,j=0,k=0,x=0,flag;/*数字个数  运算符个数*/    
/*
*i：循环控制变量
*j：记录c_figure的数据多少 
*k：记录c_figure，填充每一行数据时，由k记录填充到那一项，纵向
*x：记录有多少个运算符，并记录c_operator的填充项
*flag：每次处理一个运算符两侧的数据，flag用于记录某次是否已经处理过数据 
*/ 
char input_char[100],deal_char[20];
/*
*输入的完整的整式记录在input_char中，以字符形式记录 
*处理每一个数字字符串暂存于deal_char中 
*/
float num[20]={0};/*储存参加运算的具体数字，已被处理成float型，在num中*/ 
char c_figure[20][20];/*将每一char型数字分别存在c_figure每一行中 */
char c_operator[20];/*运算符 */
printf("请输入计算式:\n");
scanf("%s",&input_char);/*读入一个整式，作为字符串存储*/ 

while(input_char[i]!='\0')/*将char型数字与运算符分开*/ 
   {
    if((input_char[i]>=48&&input_char[i]<=57)||(input_char[i]=='.'))/*保证输入的是合法数字，小数点处理为合法 */
    {
        c_figure[j][k]=input_char[i];
        k++;
    }
    else if(input_char[i]=='+'||input_char[i]=='-'||input_char[i]=='*'||input_char[i]=='/')/*运算符处理*/ 
    {
        c_operator[x]=input_char[i];
        c_figure[j][k]=0;
        j++;
        k=0;
        x++;
    }
    else if(input_char[i]=='=')/*等号处理，支持没有等号的等式*/
	{
        input_char[i+1]=0;
        c_figure[j][k]=0;
    }
    i++;
    }
    c_figure[j][k]=0;
    if(k==0) j--;/*有无等号处理，k==0，无等号*/ 
    else;
    if(x==j);
    else /*判断等式是否输入合法*/ 
    {
        printf("按任意键返回上一级\n");
        system("pause");
        return 0; 
    }
    for(i=0;i<=j;i++)/*将char型数字转换成float型 */
    {
        strcpy(deal_char,c_figure[i]);
        num[i]=deal(deal_char);
    }
    while(x--)/*对运算符优先级进行分辨，进行不同处理 */
    {
        flag=0; /*flag为0表示未经过处理，1表示经过处理 */
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
        for(i=t;i<=x;i++)c_operator[i]=c_operator[i+1];//每进行一次操作，将运算符删除 
    }
    printf("整式的结果是：%f\n\n",num[0]);/*输出结果*/	
	printf("输入'-'结束计算或者继续");
}

} 


void add(float num[],int t)/*加法实现*/
{
    int i;
    num[t]=num[t]+num[t+1];
    for(i=t+1;i<20;i++)
	{
    num[i]=num[i+1];
    }
    return;
}


void reduce(float num[],int t)/*减法实现*/ 
{
    int i;
    num[t]=num[t]-num[t+1];
    for(i=t+1;i<20;i++)
	{
        num[i]=num[i+1];
    }
    return;
}


void ride(float num[],int t)/*乘法实现*/
{
    int i;
    num[t]=num[t]*num[t+1];
    for(i=t+1;i<20;i++)
	{
    num[i]=num[i+1];
    }
    return;
}


void divide(float num[],int t)/*除法实现*/ 
{
    int i;
    num[t]=num[t]/num[t+1];
    for(i=t+1;i<20;i++)
	{
    num[i]=num[i+1];
    }
    return;
}

float deal(char deal_char[])/*将char型数字转换成float型 */
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

int  menu2_1()/*二进制转换*/ 
{
	int   select;
	system("cls");
	printf("\n\n\n\t\t请选择操作\n");
	printf("\t\t|*****************************|\n");
	printf("\t\t|    【1】二进制转换          |\n");
	printf("\t\t|    【2】八进制转换          |\n");
	printf("\t\t|    【3】十六进制转换        |\n");
	printf("\t\t|    【4】返回                |\n");
	printf("\t\t|*****************************|\n\n");
	scanf("%d",&select);
	return select;
}


void binary()/*二进制转换*/ 
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
			 printf("\n\n\n\t\t\t请输入任意键返回上一级菜单\n");
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
	printf("\t\t|         请选择操作             |\n");
	printf("\t\t|================================|\n");
	printf("\t\t|    【1】二进制转换成十进制     |\n");
	printf("\t\t|    【2】十进制转换成二进制     |\n");
    printf("\t\t|    【3】返回上一级菜单         |\n");
	printf("\t\t|********************************|\n");
	scanf("%d",&select);
	return select;
}

int binary2()/*十进制转换成二进制*/ 
{
	int a[16],i;
	unsigned n;
	printf("输入一个十进制数\n");
	scanf("%d",&n);
	i=0;
	do
	{
		a[i]=n%2;
		n=n/2;
		i++;	
	}while(n>0);
	printf("转化成二进制数为：");
	while(i>=1) printf("%d",a[--i]);
	printf("\n\n按任意键返回");
	getchar();
	return 0;
}  


int binary1()/*二进制转换成十进制*/
{	
	int i,t;
    long sum=0;
	char s[50];
	printf("输入二进制数： ");
    scanf("%s",s);
    for(i=0;s[i];i++)
	{
    if(s[i]<='9')t=s[i]-'0';
    sum=sum*2+t;
	}
    printf("%ld\n",sum);
    printf("\n按任意键返回");
    getchar();
    return 0;
}

void octonary()/*八进制转换*/ 
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
			 printf("\n\n\n\t\t\t请输入任意键返回上一级菜单\n");
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
	printf("\t\t|\t请选择操作\t   |\n");
	printf("\t\t|==========================|\n");
	printf("\t\t|    1.八进制转换成十进制  |\n");
	printf("\t\t|    2.十进制转换成八进制  |\n");
    printf("\t\t|    3.返回上一级菜单      |\n");
	printf("\t\t|**************************|\n");
	scanf("%d",&select);
	return select;
}

int octonary2()/*十进制转换成八进制*/
{
	int a[16],i;
	unsigned n;
	printf("输入一个十进制数\n"); 
	scanf("%d",&n);
	i=0;
	do
	{
		a[i]=n%8;
		n=n/8;
		i++;	
	}while(n>0);
	printf("转化为八进制数为:o");
	while(i>=1) printf("%d",a[--i]);
	printf("\n\n按任意键返回");
	getchar();
    return 0;
 } 


int octonary1()/*八进制转换成十进制*/
/*{	
	char *p,s[6];
	int n;
	p=s;
	printf("输入一个八进制数\n");
	gets(p);
	n=*p-'0';
	while(*(++p)!='\0')
		n=n*8+*p-'0';
	printf("转化为十进制数为：%d\n",n);
	system("pause");
return 0;
}*/

{
	int i,t;
    long sum=0;
	char s[50];
	printf("输入八进制数： ");
    scanf("%s",s);
    for(i=0;s[i];i++)
{
    if(s[i]<='9')t=s[i]-'0';
    
    sum=sum*8+t;
}
printf("%ld\n",sum);
printf("\n按任意键返回");
getchar();
return 0;
}

void hex()/*十六进制转换*/
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
			 printf("\n\n\n\t\t\t请输入任意键返回上一级菜单\n");
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
	printf("\t\t|\t请选择操作\t   |\n");
	printf("\t\t|==========================|\n");
	printf("\t\t|1.十六进制转换成十进制    |\n");
	printf("\t\t|2.十进制转换成十六进制    |\n");
    printf("\t\t|3.返回上一级菜单          |\n");
	printf("\t\t|**************************|\n");
	scanf("%d",&select);
	return select;
}

char hex2()/*十进制转换成十六进制*/ 
{
int num=0;
int a[100]; 
int i=0; 
int m=0;
int yushu; 
char hex[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
printf("请输入一个十进制整数："); 
scanf("%d",&num); 
while(num>0) 
    { 
    yushu=num%16; 
    a[i++]=yushu; 
    num=num/16; 
    } 
    printf("转化为十六进制数为：0x"); 
for(i=i-1;i>=0;i--)//倒序输出 
{ 
m=a[i];
printf("%c",hex[m]); 
} 
printf("\n\n按任意键返回"); 
getchar();
return 0;	
}


char hex1()/*十六进制转换成十进制*/ 
{
	int i,t;
    long sum=0;
	char s[50];
	printf("输入十六进制数： ");
    scanf("%s",s);
    for(i=0;s[i];i++)
{
    if(s[i]<='9')t=s[i]-'0';
    else  t=s[i]-'a'+10;
    sum=sum*16+t;
}
printf("%ld\n",sum);
printf("按任意键返回");
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



double zhi()/*幂指函数*/ 
{
    double Pow(double,double);
	double x,y,m;
	 printf("输入底数:\t\n");
	scanf("%lf",&x); 
    printf("输入指数:\t\n");
    scanf("%lf",&y);
	m=Pow(x,y);
    printf("%f",m);
    printf("\n按任意键返回");
	getchar();
	return 0;
}

double LN(double a)/*函数调用*/ 
{  
   int N = 15;/*取了前15+1项来估算 */ 
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
  
double dui() /*对数函数*/ 
{  
    double b; 
	double n;
	printf("输入自然对数的真数:");
    scanf("%lf",&n);
    b = LN(n);    
    printf("自然对数值为 %lf\n",b);
	printf("按任意键返回");
    getchar();  
    return 0;  
} 



void tri()/*三角函数*/ 
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
			 printf("\n\n\n\t\t\t请输入任意键返回上一级菜单\n");
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
	printf("\t\t|      请选择操作          |\n");
	printf("\t\t|--------------------------|\n");
	printf("\t\t|  1.正弦函数              |\n");
	printf("\t\t|  2.余弦函数              |\n");
    printf("\t\t|  3.返回上一级菜单        |\n");
	printf("\t\t|==========================|\n");
	scanf("%d",&select);
	return select;
}

double Sin()
{
	int a,b=1,c=1,n=1;
	double z,x,d=0,sinx=0;/*定义双精度*/
	printf("请输入角度 z=");/*输入为角度*/
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
    printf("\n按任意键返回");
	getchar();
	return 0;
}

double Cos()
{
    double x,z;
    double COS(double x);
    printf("请输入角度为 z=");
    scanf("%lf",&z);
	x=z*PI/180;
    printf("cos (%lf)=%lf\n",z,COS(x));
    printf("按任意键返回");
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
			 printf("\n\n\n\t\t\t请输入任意键返回上一级菜单\n");
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
	printf("\n\n\n\t\t请选择操作\n");
	printf("\t\t|-----------------------------|\n");
	printf("\t\t|\t1.求和                |\n");
	printf("\t\t|\t2.阶乘                |\n");
	printf("\t\t|\t3.返回                |\n");
	printf("\t\t|-----------------------------|\n\n");
	scanf("%d",&select);
	return select;
}

int xxx()/*阶乘函数*/
{
	int n,i,t=1;
	printf("请输入一个30以内的数:\t");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	t*=i;
	printf("阶乘为%d\n",t);
	printf("\n按任意键返回");
	getchar();
    return 0;
}

int add()/*求和函数*/
{
	int n,sum=0,i;
	printf("请输入一个数:  ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	sum+=i;
	printf("和为%d\n",sum);
	printf("\n按任意键返回");
	getchar();
    return 0;
}

void head1()
{
	 /*颜色变化效果*/
	int i;
	int t=8;
	printf("\t\t***********************************\n");
	printf("\t\t     欢迎进入简单计算器\n");
	printf("\t\t***********************************\n");
    while(--t)
	{ 
	  /*每个for循环代表每个颜色持续的时间*/
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
	   printf("\n\t\t★★★★★★★欢迎进入简单计算器★★★★★★\n\n"); 
	   printf("\n\n\t************************************************************\n");
	   printf("\n\n\n\t\t\t请输入任意键进入\n");
	   Sleep(66);
	   	if(i!=6) 
			system("cls");

		for(j=0;j<i;j++) 
			printf("\n");

	}
    getchar();
}

