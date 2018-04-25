//c语言课程设计
//copyright @朱嘉新
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<windows.h>
#include<conio.h>
#define E 2.718
#define PI 6.282
#define k 1000
void transform(char *str,int a[][2],int *n);//将输入的字符串转化为格式化的数组以记录输入的表达式，str为输入的字符串，a为目标数组，n记录数组a的大小 
void poland(int a[][2],int n,int p[][2],int *m);//将格式化数组转化为逆波兰表达式，a为输入的数组，n为其长度，p为输出逆波兰表达式的目标，m记录逆波兰表达式的长度 
double evaluate(int p[][2],int m);//对逆波兰表达式求值，p为逆波兰表达式，m为表达式长度
void menu();//用最简单的printf函数打印界面
void printfline();//打横线的函数
void easy();//简单运算
void mixed();//科学的四则混合运算
void tentotwo();//十进制转二进制
void twotoeight();//二进制转八进制
void twototen();//二进制转十进制
void twotosixteen();//二进制转十六进制
void lnx();//logx函数
void ex();//e的x次方的函数
void emul();//e的阶乘的函数
void xy();//x的y次方的函数
void sinx();//sinx的函数
void cosx();//cosx的函数
void tanx();//tanx的函数
void function1();//功能模块1
void function2();//功能模块2
void function3();//功能模块3
void function4();//功能模块4
void function5();//功能模块5
int main()
{
	MessageBox(NULL,"欢迎来到简易计算器！","你好！",MB_OK);
	//system("color ");
	//system("title ");
	int choose;
	while(1)
	{	
		system("cls");
		menu();//用最简单的printf打印界面
		scanf("%d",&choose);
		switch(choose)
		{
		case 1:
			function1();
			break;
		case 2:
			function2();
			break;
		case 3:
			function3();
			break;
		case 4:
			function4();
			break;
		case 5:
			function5();
			break;
		case 0:
			system("cls");
			printf("\t\t\t\t    祝你使用愉快！\n");
			system("pause");
			exit(0);
		default:
			system("cls");
			printf("\t\t\t选择错误，重新选择！");
			system("pause");
			break;
		}
	}


	return 0;

}
void transform(char *str,int a[][2],int *n)//将输入的字符串转化为格式化的数组以记录输入的表达式，str为输入的字符串，a为目标数组，n记录数组a的大小 
{
    int i;
    *n=1;
    a[0][0]=1;
    a[0][1]='(';//在表达式首添加一个括号
    for (i=0;str[i]!='=';)
    {
        if (isdigit(str[i]))
        {
            a[*n][0]=0;
            a[*n][1]=0;
            while (isdigit(str[i]))
            {
                a[*n][1]=a[*n][1]*10+str[i]-'0';
                i++;
            }
        }
        else
        {
            if (str[i]=='(') a[*n][0]=1;
            else if (str[i]==')') a[*n][0]=2;
            else if (str[i]=='*') a[*n][0]=3;
            else if (str[i]=='/') a[*n][0]=4;
            else if (str[i]=='+' || str[i]=='-')
            {
                if (i==0 || (!isdigit(str[i-1]) && str[i-1]!=')'))
                {
                    a[*n][0]=0;
                    a[*n][1]=0;
                    (*n)++;
                }
                if (str[i]=='+') a[*n][0]=5;
                else a[*n][0]=6;
            }
            a[*n][1]=str[i];
            i++;
        }
        (*n)++;
    }
    a[*n][0]=2;
    a[*n][1]=')';//在表达式尾添加一个反括号
    (*n)++;
}
void poland(int a[][2],int n,int p[][2],int *m)//将格式化数组转化为逆波兰表达式，a为输入的数组，n为其长度，p为输出逆波兰表达式的目标，m记录逆波兰表达式的长度 
{
    int i;
    int stack[1000];//转化所用的栈
    int depth;//栈的深度
    depth=0;
    *m=0;
    for (i=0;i<n;i++)
    {
        if (a[i][0]==0) stack[depth++]=i;
        else if (a[i][0]==1) stack[depth++]=i;
        else if (a[i][0]==2)
        {
            while (a[stack[depth-1]][0]!=1)
            {
                depth--;
                p[*m][0]=a[stack[depth]][0];
                p[*m][1]=a[stack[depth]][1];
		
				(*m)++;	
            }
            depth--;
        }
        else if (a[i][0]==3 || a[i][0]==4)
        {
            while (a[stack[depth-1]][0]==0 || a[stack[depth-1]][0]==3 || a[stack[depth-1]][0]==4)
            {
                depth--;
                p[*m][0]=a[stack[depth]][0];
                p[*m][1]=a[stack[depth]][1];
				(*m)++;	
            }
            stack[depth++]=i;
        }
        else if (a[i][0]==5 || a[i][0]==6)
        {
            while (a[stack[depth-1]][0]!=1)
            {
                depth--;
                p[*m][0]=a[stack[depth]][0];
                p[*m][1]=a[stack[depth]][1];
				(*m)++;				
            }
            stack[depth++]=i;
        }
    }
}
double evaluate(int p[][2],int m)//对逆波兰表达式求值，p为逆波兰表达式，m为表达式长度
{
    double stack[1000];//求值所用的栈
    int depth;//栈的深度
    int i;
    depth=0;
    for (i=0;i<m;i++)
    {
        if (p[i][0]==0) stack[depth++]=p[i][1];
        else
        {
            double a,b;
            b=stack[--depth];
            a=stack[--depth];
			if(p[i][0]==3)
			{
				stack[depth++]=a*b;
			}
            else if (p[i][0]==4)
			{
				stack[depth++]=a/b;
			}
            else if (p[i][0]==5)
			{
				stack[depth++]=a+b;
			}
            else
			{
				stack[depth++]=a-b;
			}
        }
    }
    return stack[0];
}
void printfline()
{
	printf("                        ━━━━━━━━━━━━━━━━━━\n");
}
void menu()
{

	printf("                       ┏━━━━━━━━━━━━━━━━━┓\n");
	printf("                       ┃      欢迎来到简易外观计算器      ┃\n");
	printf("                       ┃          1.四则运算              ┃\n");
	printf("                       ┃          2.数制等价交换          ┃\n");
	printf("                       ┃          3.三角函数              ┃\n");
	printf("                       ┃          4.指数运算(ln(x),e^x)   ┃\n");
	printf("                       ┃          5.其他运算(x!,x^y)      ┃\n");
	printf("                       ┃          0.退出系统              ┃\n");
	printf("                       ┗━━━━━━━━━━━━━━━━━┛\n");
	printf("                               选择对应数字进入计算:");
}	
void easy()
{
	system("cls");
	double x,y;
	char m;
	printf("\t\t\t支持二目运算\n");
	printf("\t\t\t输入第一个数字:");
	scanf("%lf",&x);
	printf("\n");
	printf("\t\t\t输入第二个数字:");
	scanf("%lf",&y);
	printf("\n");
	printf("\t\t\t输入运算符(支持+，-，*，/)直接获得结果:");
	m=getch();
	system("cls");
	switch(m)
	{
		
	case '+':
		printf("\t\t\t它的结果是:%lf",x+y);
		system("pause");
		break;
	case '-':
		printf("\t\t\t它的结果是:%lf",x-y);
		system("pause");
		break;
	case '*':
		printf("\t\t\t它的结果是:%lf",x*y);
		system("pause");
		break;
	case '/':
		if(y==0)
		{
			printf("\t\t\t除数不能为0!");
			system("pause");
			break;
		}
		printf("\t\t\t它的结果是:%lf",x/y);
		system("pause");
		break;
	default:
		printf("\t\t\t输入错误！");
		system("pause");
		break;
	}
}
void  mixed()
{
	system("cls");
	int a[k][2],n,p[k][2],m;
	printf("\t\t\t请输入一个表达式(请以=结尾)(不支持括号，不支持小数):\n");
	printf("\t\t\t");
	char text[200];
    scanf("%s",text);
    transform(text,a,&n);
    poland(a,n,p,&m);
    system("cls");
    printf("\t\t\t这个表达式的结果为:%.2f",evaluate(p,m));
	system("pause");
}
void tentotwo()
{
	system("cls");
	unsigned x;
	int a[16],i=0;
	printf("\t\t\t输入十进制的数:");
	scanf("%d",&x);
	while(x>0)
	{
		a[i]=x%2;
		x=x/2;
		i++;	
	}
	system("cls");
	printf("\t\t\t它的二进制是:");
	for(i=i-1;i>=0;i--)
		printf("%d",a[i]);
	system("pause");
}
void twotoeight()
{
	system("cls");
	int n,w=1,num=0;
	printf("\t\t\t支持最简单上的没有符号的二进制的转化\n");
	printf("\t\t\t输入一个二进制数:");
	char b[64];
	scanf("%s",b);
	n=strlen(b);
	while(n--)
	{
		num+=(int)(b[n]-'0')*w;
		w*=8;
	}
	system("cls");
	printf("\t\t\t它的十六进制是:%d",num);
	system("pause");
}
void twototen()
{
	system("cls");
	int n,w=1,num=0;
	printf("\t\t\t支持最简单上的没有符号的二进制的转化\n");
	printf("\t\t\t输入一个二进制数:");
	char b[64];
	scanf("%s",b);
	n=strlen(b);
	while(n--)
	{
		num+=(int)(b[n]-'0')*w;
		w*=2;
	}
	system("cls");
	printf("\t\t\t它的十进制是:%d",num);
	system("pause");
}
void twotosixteen()
{
	system("cls");
	int n,w=1,num=0;
	printf("\t\t\t支持最简单上的没有符号的二进制的转化\n");
	printf("\t\t\t输入一个二进制数:");
	char b[64];
	scanf("%s",b);
	n=strlen(b);
	while(n--)
	{
		num+=(int)(b[n]-'0')*w;
		w*=16;
	}
	system("cls");
	printf("\t\t\t它的十六进制是:%d",num);
	system("pause");
}
void sinx()
{
	system("cls");
	int i,s=1;
	double x,a,sum=0,b=1;  //sum代表和，a为分子，b为分母
	printf("\t\t\t输入弧度制数:");
	scanf("%lf",&x);
	if(x>PI)
		x/=PI;
	a=x;     //分母赋初值
	for(i=1;a/b>=1e-006;i++)
	{
		sum=sum+s*a/b;    //累加一项
		a=a*x*x;     //求下一项分子
		b=b*2*i*(2*i+1);   //求下一项分母
		s*=-1;
	}
	printf("\t\t\tsum=%f",sum);
	system("pause");
}
void cosx()
{	 
	system("cls");
	int i,j; 
	double sum = 1.0,x,y;
	printf("\t\t\t输入弧度制数:");
	scanf("%lf",&x);
	if(x>PI)
		x/=PI;
	y=-x*x;
	for(i = 1; i <= 4; i++) 
	{  
     long term = 1;  
     for(j=2; j <= 2*i; j++) 
	 term=term*j;  
     sum += y/term; 
     y *= -(x * x); 
	}  
	printf("\t\t\t它的结果是:%lf",sum);
	system("pause");
}
void tanx()
{
	system("cls");
	int i,s=1,j;
	double x,a,sum=0,b=1,y,sum1=1.0;  //sum代表和，a为分子，b为分母
	printf("\t\t\t输入弧度制数:");
	scanf("%lf",&x);
	if(x>PI)
		x/=PI;
	a=x;     //分母赋初值
	for(i=1;a/b>=1e-006;i++)
	{
		sum=sum+s*a/b;    //累加一项
		a=a*x*x;     //求下一项分子
		b=b*2*i*(2*i+1);   //求下一项分母
		s*=-1;
	}
	y=-x*x;
	for(i = 1; i <= 4; i++) 
	{  
     long term = 1;  
     for(j=2; j <= 2*i; j++) 
	 term=term*j;  
     sum1 += y/term; 
     y *= -(x * x); 
	} 
	printf("\t\t\t它的结果是:%lf",sum/sum1);
		system("pause");
}
void lnx()
{
	system("cls");
	int n,nk,N=10000;
	double a,x,z,y;
	printf("\t\t\t输入要求的X的值:");
	scanf("%lf",&a);
	x=(a-1)/(a+1);
	z=x*x;
	nk=2*N+1;
	y=1.0/nk;
	for(n=N;n>0;n--)
	{
		nk=nk-2;
		y=1.0/nk+z*y;
	}
	printf("\t\t\t它的结果是:%lf",2.0*x*y);
	system("pause");

}
void ex()
{
	system("cls");
	int x;
	double result=1;
	printf("\t\t\t计算e^x的值\n");
	printf("\t\t\t输入x的值:");
	scanf("%d",&x);
	for(int i=1;i<=x;i++)
	{
		result*=E;
	}
	system("cls");
	printf("\t\t\t结果是:%lf",result);
	system("pause");
}
void emul()
{
	system("cls");
	int e=1,x;
	printf("\t\t\t输入要求阶乘的数:");
	scanf("%d",&x);
	for(int i=1;i<=x;i++)
	{
		e*=i;
	}
	system("cls");
	printf("\t\t\t它的结果是:%d",e);
	system("pause");
}
void xy()
{
	system("cls");
	int x,y,xy=1;
	printf("\t\t\t输入对应的x,y:");
	scanf("%d%d",&x,&y);
	for(int i=1;i<=y;i++)
	{
		xy*=x;
	}
	system("cls");
	printf("\t\t\t它的结果是:%d",xy);
	system("pause");
}
void function1()
{
	int choose;
	while(1)
	{
		system("cls");
		printfline();
		printf("\t\t\t\t    1.简单的运算\n");
		printfline();
		printf("\t\t\t\t    2.科学的运算\n");
		printfline();
		printf("\t\t\t\t    0.返回上一级\n");
		printfline();
		printf("\t\t\t\t    输入计算的类型:");
		scanf("%d",&choose);
		switch(choose)
		{
		case 1:
            easy();
			break;
		case 2:
			mixed();
			break;
		case 0:
			return;
		default :
			printf("\t\t\t选择错误！");
			system("pause");
		}
	}
	
}
void function2()
{
	int choose;
	while(1)
	{
		system("cls");
		printfline();
		printf("\t\t\t\t   1.十进制转二进制\n");
		printfline();
		printf("\t\t\t\t   2.二进制转十进制\n");
		printfline();
		printf("\t\t\t\t   3.二进制转八进制\n");
		printfline();
		printf("\t\t\t\t   4.二进制转十六进制\n");
		printfline();
		printf("\t\t\t\t   0.返回上一级\n");
		printfline();
		printf("\t\t\t\t   输入计算的类型:");
		scanf("%d",&choose);
		switch(choose)
		{
		case 1:
			tentotwo();
			break;
		case 2:
			twototen();
			break;
		case 3:
			twotoeight();
			break;
		case 4:
			twotosixteen();
			break;
		case 0:
			return;
		default :
			printf("\t\t\t选择错误！");
			system("pause");
		}
	}
}
void function3()
{
	int choose;
	while(1)
	{
		system("cls");
		printfline();
		printf("\t\t\t\t     1.sin(x)\n");
		printfline();
		printf("\t\t\t\t     2.cos(x)\n");
		printfline();
		printf("\t\t\t\t     3.tan(x)\n");
		printfline();
		printf("\t\t\t\t     0.返回上一级\n");
		printfline();
		printf("\t\t\t\t     输入计算的类型:");
		scanf("%d",&choose);
		switch(choose)
		{
		case 1:
			sinx();
			break;
		case 2:
			cosx();
			break;
		case 3:
			tanx();
			break;
		case 0:
			return;
		default :
			printf("\t\t\t选择错误！");
			system("pause");
		}
	}
}
void function4()
{
	int choose;
	while(1)
	{
		system("cls");
		printfline();
		printf("\t\t\t\t     1.ln(x)\n");
		printfline();
		printf("\t\t\t\t     2.e^x\n");
		printfline();
		printf("\t\t\t\t     0.返回上一级\n");
		printfline();
		printf("\t\t\t\t     输入计算的类型:");
		scanf("%d",&choose);
		switch(choose)
		{
		case 1:
			lnx();
			break;
		case 2:
			ex();
			break;
		case 0:
			return;
		default :
			printf("\t\t\t选择错误！");
			system("pause");
		}
	}
}
void function5()
{
	int choose;
	while(1)
	{
		system("cls");
		printfline();
		printf("\t\t\t\t      1.x!\n");
		printfline();
		printf("\t\t\t\t      2.x^y\n");
		printfline();
		printf("\t\t\t\t      0.返回上一级\n");
		printfline();
		printf("\t\t\t\t      输入计算的类型:");
		scanf("%d",&choose); 
		switch(choose)
		{
		case 1:
			emul();
			break;
		case 2:
			xy();
			break;
		case 0:
			return;
		default :
			printf("\t\t\t选择错误！");
			system("pause");
		}
	}
}
 
