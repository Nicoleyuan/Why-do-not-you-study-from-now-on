//c���Կγ����
//copyright @�����
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
void transform(char *str,int a[][2],int *n);//��������ַ���ת��Ϊ��ʽ���������Լ�¼����ı��ʽ��strΪ������ַ�����aΪĿ�����飬n��¼����a�Ĵ�С 
void poland(int a[][2],int n,int p[][2],int *m);//����ʽ������ת��Ϊ�沨�����ʽ��aΪ��������飬nΪ�䳤�ȣ�pΪ����沨�����ʽ��Ŀ�꣬m��¼�沨�����ʽ�ĳ��� 
double evaluate(int p[][2],int m);//���沨�����ʽ��ֵ��pΪ�沨�����ʽ��mΪ���ʽ����
void menu();//����򵥵�printf������ӡ����
void printfline();//����ߵĺ���
void easy();//������
void mixed();//��ѧ������������
void tentotwo();//ʮ����ת������
void twotoeight();//������ת�˽���
void twototen();//������תʮ����
void twotosixteen();//������תʮ������
void lnx();//logx����
void ex();//e��x�η��ĺ���
void emul();//e�Ľ׳˵ĺ���
void xy();//x��y�η��ĺ���
void sinx();//sinx�ĺ���
void cosx();//cosx�ĺ���
void tanx();//tanx�ĺ���
void function1();//����ģ��1
void function2();//����ģ��2
void function3();//����ģ��3
void function4();//����ģ��4
void function5();//����ģ��5
int main()
{
	MessageBox(NULL,"��ӭ�������׼�������","��ã�",MB_OK);
	//system("color ");
	//system("title ");
	int choose;
	while(1)
	{	
		system("cls");
		menu();//����򵥵�printf��ӡ����
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
			printf("\t\t\t\t    ף��ʹ����죡\n");
			system("pause");
			exit(0);
		default:
			system("cls");
			printf("\t\t\tѡ���������ѡ��");
			system("pause");
			break;
		}
	}


	return 0;

}
void transform(char *str,int a[][2],int *n)//��������ַ���ת��Ϊ��ʽ���������Լ�¼����ı��ʽ��strΪ������ַ�����aΪĿ�����飬n��¼����a�Ĵ�С 
{
    int i;
    *n=1;
    a[0][0]=1;
    a[0][1]='(';//�ڱ��ʽ�����һ������
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
    a[*n][1]=')';//�ڱ��ʽβ���һ��������
    (*n)++;
}
void poland(int a[][2],int n,int p[][2],int *m)//����ʽ������ת��Ϊ�沨�����ʽ��aΪ��������飬nΪ�䳤�ȣ�pΪ����沨�����ʽ��Ŀ�꣬m��¼�沨�����ʽ�ĳ��� 
{
    int i;
    int stack[1000];//ת�����õ�ջ
    int depth;//ջ�����
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
double evaluate(int p[][2],int m)//���沨�����ʽ��ֵ��pΪ�沨�����ʽ��mΪ���ʽ����
{
    double stack[1000];//��ֵ���õ�ջ
    int depth;//ջ�����
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
	printf("                        ������������������������������������\n");
}
void menu()
{

	printf("                       ��������������������������������������\n");
	printf("                       ��      ��ӭ����������ۼ�����      ��\n");
	printf("                       ��          1.��������              ��\n");
	printf("                       ��          2.���Ƶȼ۽���          ��\n");
	printf("                       ��          3.���Ǻ���              ��\n");
	printf("                       ��          4.ָ������(ln(x),e^x)   ��\n");
	printf("                       ��          5.��������(x!,x^y)      ��\n");
	printf("                       ��          0.�˳�ϵͳ              ��\n");
	printf("                       ��������������������������������������\n");
	printf("                               ѡ���Ӧ���ֽ������:");
}	
void easy()
{
	system("cls");
	double x,y;
	char m;
	printf("\t\t\t֧�ֶ�Ŀ����\n");
	printf("\t\t\t�����һ������:");
	scanf("%lf",&x);
	printf("\n");
	printf("\t\t\t����ڶ�������:");
	scanf("%lf",&y);
	printf("\n");
	printf("\t\t\t���������(֧��+��-��*��/)ֱ�ӻ�ý��:");
	m=getch();
	system("cls");
	switch(m)
	{
		
	case '+':
		printf("\t\t\t���Ľ����:%lf",x+y);
		system("pause");
		break;
	case '-':
		printf("\t\t\t���Ľ����:%lf",x-y);
		system("pause");
		break;
	case '*':
		printf("\t\t\t���Ľ����:%lf",x*y);
		system("pause");
		break;
	case '/':
		if(y==0)
		{
			printf("\t\t\t��������Ϊ0!");
			system("pause");
			break;
		}
		printf("\t\t\t���Ľ����:%lf",x/y);
		system("pause");
		break;
	default:
		printf("\t\t\t�������");
		system("pause");
		break;
	}
}
void  mixed()
{
	system("cls");
	int a[k][2],n,p[k][2],m;
	printf("\t\t\t������һ�����ʽ(����=��β)(��֧�����ţ���֧��С��):\n");
	printf("\t\t\t");
	char text[200];
    scanf("%s",text);
    transform(text,a,&n);
    poland(a,n,p,&m);
    system("cls");
    printf("\t\t\t������ʽ�Ľ��Ϊ:%.2f",evaluate(p,m));
	system("pause");
}
void tentotwo()
{
	system("cls");
	unsigned x;
	int a[16],i=0;
	printf("\t\t\t����ʮ���Ƶ���:");
	scanf("%d",&x);
	while(x>0)
	{
		a[i]=x%2;
		x=x/2;
		i++;	
	}
	system("cls");
	printf("\t\t\t���Ķ�������:");
	for(i=i-1;i>=0;i--)
		printf("%d",a[i]);
	system("pause");
}
void twotoeight()
{
	system("cls");
	int n,w=1,num=0;
	printf("\t\t\t֧������ϵ�û�з��ŵĶ����Ƶ�ת��\n");
	printf("\t\t\t����һ����������:");
	char b[64];
	scanf("%s",b);
	n=strlen(b);
	while(n--)
	{
		num+=(int)(b[n]-'0')*w;
		w*=8;
	}
	system("cls");
	printf("\t\t\t����ʮ��������:%d",num);
	system("pause");
}
void twototen()
{
	system("cls");
	int n,w=1,num=0;
	printf("\t\t\t֧������ϵ�û�з��ŵĶ����Ƶ�ת��\n");
	printf("\t\t\t����һ����������:");
	char b[64];
	scanf("%s",b);
	n=strlen(b);
	while(n--)
	{
		num+=(int)(b[n]-'0')*w;
		w*=2;
	}
	system("cls");
	printf("\t\t\t����ʮ������:%d",num);
	system("pause");
}
void twotosixteen()
{
	system("cls");
	int n,w=1,num=0;
	printf("\t\t\t֧������ϵ�û�з��ŵĶ����Ƶ�ת��\n");
	printf("\t\t\t����һ����������:");
	char b[64];
	scanf("%s",b);
	n=strlen(b);
	while(n--)
	{
		num+=(int)(b[n]-'0')*w;
		w*=16;
	}
	system("cls");
	printf("\t\t\t����ʮ��������:%d",num);
	system("pause");
}
void sinx()
{
	system("cls");
	int i,s=1;
	double x,a,sum=0,b=1;  //sum����ͣ�aΪ���ӣ�bΪ��ĸ
	printf("\t\t\t���뻡������:");
	scanf("%lf",&x);
	if(x>PI)
		x/=PI;
	a=x;     //��ĸ����ֵ
	for(i=1;a/b>=1e-006;i++)
	{
		sum=sum+s*a/b;    //�ۼ�һ��
		a=a*x*x;     //����һ�����
		b=b*2*i*(2*i+1);   //����һ���ĸ
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
	printf("\t\t\t���뻡������:");
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
	printf("\t\t\t���Ľ����:%lf",sum);
	system("pause");
}
void tanx()
{
	system("cls");
	int i,s=1,j;
	double x,a,sum=0,b=1,y,sum1=1.0;  //sum����ͣ�aΪ���ӣ�bΪ��ĸ
	printf("\t\t\t���뻡������:");
	scanf("%lf",&x);
	if(x>PI)
		x/=PI;
	a=x;     //��ĸ����ֵ
	for(i=1;a/b>=1e-006;i++)
	{
		sum=sum+s*a/b;    //�ۼ�һ��
		a=a*x*x;     //����һ�����
		b=b*2*i*(2*i+1);   //����һ���ĸ
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
	printf("\t\t\t���Ľ����:%lf",sum/sum1);
		system("pause");
}
void lnx()
{
	system("cls");
	int n,nk,N=10000;
	double a,x,z,y;
	printf("\t\t\t����Ҫ���X��ֵ:");
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
	printf("\t\t\t���Ľ����:%lf",2.0*x*y);
	system("pause");

}
void ex()
{
	system("cls");
	int x;
	double result=1;
	printf("\t\t\t����e^x��ֵ\n");
	printf("\t\t\t����x��ֵ:");
	scanf("%d",&x);
	for(int i=1;i<=x;i++)
	{
		result*=E;
	}
	system("cls");
	printf("\t\t\t�����:%lf",result);
	system("pause");
}
void emul()
{
	system("cls");
	int e=1,x;
	printf("\t\t\t����Ҫ��׳˵���:");
	scanf("%d",&x);
	for(int i=1;i<=x;i++)
	{
		e*=i;
	}
	system("cls");
	printf("\t\t\t���Ľ����:%d",e);
	system("pause");
}
void xy()
{
	system("cls");
	int x,y,xy=1;
	printf("\t\t\t�����Ӧ��x,y:");
	scanf("%d%d",&x,&y);
	for(int i=1;i<=y;i++)
	{
		xy*=x;
	}
	system("cls");
	printf("\t\t\t���Ľ����:%d",xy);
	system("pause");
}
void function1()
{
	int choose;
	while(1)
	{
		system("cls");
		printfline();
		printf("\t\t\t\t    1.�򵥵�����\n");
		printfline();
		printf("\t\t\t\t    2.��ѧ������\n");
		printfline();
		printf("\t\t\t\t    0.������һ��\n");
		printfline();
		printf("\t\t\t\t    ������������:");
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
			printf("\t\t\tѡ�����");
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
		printf("\t\t\t\t   1.ʮ����ת������\n");
		printfline();
		printf("\t\t\t\t   2.������תʮ����\n");
		printfline();
		printf("\t\t\t\t   3.������ת�˽���\n");
		printfline();
		printf("\t\t\t\t   4.������תʮ������\n");
		printfline();
		printf("\t\t\t\t   0.������һ��\n");
		printfline();
		printf("\t\t\t\t   ������������:");
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
			printf("\t\t\tѡ�����");
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
		printf("\t\t\t\t     0.������һ��\n");
		printfline();
		printf("\t\t\t\t     ������������:");
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
			printf("\t\t\tѡ�����");
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
		printf("\t\t\t\t     0.������һ��\n");
		printfline();
		printf("\t\t\t\t     ������������:");
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
			printf("\t\t\tѡ�����");
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
		printf("\t\t\t\t      0.������һ��\n");
		printfline();
		printf("\t\t\t\t      ������������:");
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
			printf("\t\t\tѡ�����");
			system("pause");
		}
	}
}
 
