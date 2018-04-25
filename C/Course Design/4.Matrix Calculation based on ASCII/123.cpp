
/*
          C语言程序设计
		  基于ASCII文件的矩阵计算演示系统
	
*/

#include<stdio.h> /*标准输入输出头文件*/
#include<stdlib.h> /*标准库头文件*/
#include<windows.h> /*加载Windows API 函数头文件*/
#include<conio.h> /*控制台输入输出头文件*/
#define m 3
#define n 4
void mainmenu();/*自定义主菜单函数*/
void  menu2();/*自定义二级菜单函数*/
void  menu3();/*自定义二级菜单函数*/
void fun1();/*自定义二级菜单子功能函数*/
void fun2();/*自定义一级菜单子功能函数*/
void fun3();/*自定义一级菜单子功能函数*/
void fun4();/*自定义一级菜单子功能函数*/
void fun5();/*自定义一级菜单子功能函数*/
void fun6();/*自定义二级菜单子功能函数*/
void fun7();/*自定义二级菜单子功能函数*/
void fun8();/*自定义一级菜单子功能函数*/
void welcome1();/*自定义菜单头函数(彩色变幻)*/
void welcome2();/*自定义菜单头函数(渐变移动)*/
void error();/*自定义选择错误函数*/



main() /*主函数*/
{
	int choose;
	system("color 5E");
	welcome2();  /*welcome1();*/
	while(1)
	{
    	mainmenu();
     	scanf("%d",&choose);/*输入选择功能的编号*/
    	switch(choose)
		{
		case 1:
			system("cls");
			fun1();break;

		case 2:
			system("cls");
			fun4();break;

		case 3:
			system("cls");
			fun6();break;

		case 4:
			system("cls");
			fun8();break;


		case 0:
			system("cls");
			printf("\n\n\n\n\n\t|--------感谢使用，再见!------|\t\n\n\n\n\n");
			exit(0);
		default:
			system("cls");
            error();
			break;
		}
		getch();
	}

	return 0;

}

void mainmenu()
{
	system("cls");/*清屏函数*/
	printf("\n\n\n");
	printf("\t\t|--------------------------------------------------|");
	printf("\t\t\t\t|\t 基于ASCII文件的矩阵计算演示系统           |\t\t\t\n");
	printf("\t\t|--------------------------------------------------|\n\n\n");
	printf("\t\t|-----------------请选择数字进行操作---------------|\n");
	printf("\t\t|\t\t1.矩阵加/减                        |\n");
	printf("\t\t|\t\t2.矩阵相乘                         |\n");
	printf("\t\t|\t\t3.矩阵转置                         |\n");
	printf("\t\t|\t\t4.矩阵对角线之和                   |\n");
	printf("\t\t|\t\t0.退出系统                         |\n");
	printf("\t\t|-----------------请选择对应数字0--4---------------|\n");
    printf("\n\n\n\t说明:\n\t\t2、4为一级菜单,1、3为二级菜单,0为退出系统\n");
}

void fun1()
{
	int choose;
	while(1)
	{
		menu2();
     	scanf("%d",&choose);/*输入选择功能的编号*/
    	switch(choose)
		{
		case 1:
			 system("cls");
             fun2();
	         break;
		case 2:
			 system("cls");
             fun3();
	         break;
		case 3:
			 printf("\n\n\n\t\t\t请输入任意键返回上一级菜单\n");
             return;
		default:
			system("cls");
            error();
			break;
		}
		getch();
	}
}


void fun2()
{/*实现矩阵的相加，要求文件中必须包含2个数据*/ 
	int a[m][n],b[m][n];int c[m][n];
	int i,j;
	//实现文件的读取 
	FILE *fp1; 
	FILE *fp2; 
	FILE *fp3;
	fp1 = fopen("A.txt", "r"); 
	if (!fp1)
	{
		printf("打开文件失败");
	}
	for (i = 0; i<m; i++)
		for (j = 0; j<n; j++)
			fscanf(fp1, "%d", &a[i][j]); 
        printf("\n矩阵A为：\n");
		for (i = 0; i<m; i++)
		{
		for (j = 0; j<n; j++)
			printf("%d\t",a[i][j]);
		printf("\n"); 
		} 
        fclose(fp1);
        fp2 = fopen("B.txt", "r");
        if (!fp2){
		printf("打开文件失败");
	}
	for (i= 0; i<m; i++)
		for (j = 0; j<n; j++)
			fscanf(fp2, "%d", &b[i][j]);
		printf("\n矩阵B为：\n");
		for (i = 0; i<m; i++)
		{
		for (j = 0; j<n; j++)
			printf("%d\t",b[i][j]);
		printf("\n"); 
		} 
	fclose(fp2);					//读取完毕关闭文件 
	//对数据进行处理，实现矩阵相加并赋值给c 
	for (i= 0;i<m;i++)
		for (j = 0; j<n; j++)
			c[i][j]=a[i][j]+b[i][j]; 
        printf("\n矩阵C为：\n");
		for (i = 0; i<m; i++)
		{
		for (j = 0; j<n; j++)
			printf("%d\t",c[i][j]);
		printf("\n"); 
		} 
        fp3 = fopen("C.txt", "wb");
	for (i = 0; i<m; i++)
	{
		for (j = 0; j<n; j++)
			fprintf(fp3,"%d\t",c[i][j]);
		fprintf(fp3,"\r\n" );
	}
        fclose(fp3);
	
	
}
void fun3()
/*实现矩阵的相减，要求文件中必须包含2个数据*/ 
{
	int a[m][n],b[m][n];
	int c[m][n];
	int i,j;
	//实现文件的读取 
	FILE *fp1; 
	FILE *fp2; 
	FILE *fp3;
	fp1 = fopen("A.txt", "r"); 
	if (!fp1)
	{
		printf("打开文件失败");
	}
	for (i = 0; i<m; i++)
		for (j = 0; j<n; j++)
			fscanf(fp1, "%d", &a[i][j]); 
        printf("\n矩阵A为：\n");
		for (i = 0; i<m; i++)
		{
		for (j = 0; j<n; j++)
			printf("%d\t",a[i][j]);
		printf("\n"); 
		} 
        fclose(fp1);
        fp2 = fopen("B.txt", "r");
        if (!fp2){
		printf("打开文件失败");
	}
	for (i= 0; i<m; i++)
		for (j = 0; j<n; j++)
			fscanf(fp2, "%d", &b[i][j]);
		printf("\n矩阵B为：\n");
		for (i = 0; i<m; i++)
		{
		for (j = 0; j<n; j++)
			printf("%d\t",b[i][j]);
		printf("\n"); 
		} 
	fclose(fp2);					//读取完毕关闭文件 
	//对数据进行处理，实现矩阵相减并赋值给c 
	for (i= 0;i<m;i++)
		for (j = 0; j<n; j++)
			c[i][j]=a[i][j]-b[i][j]; 
        printf("\n矩阵C为：\n");
		for (i = 0; i<m; i++)
		{
		for (j = 0; j<n; j++)
			printf("%d\t",c[i][j]);
		printf("\n"); 
		} 
        fp3 = fopen("C.txt", "wb");
	for (i = 0; i<m; i++)
	{
		for (j = 0; j<n; j++)
			fprintf(fp3,"%d\t",c[i][j]);
		fprintf(fp3,"\r\n" );
	}
        fclose(fp3);
	
	
}

void fun4()
/*实现矩阵的相乘，要求文件中必须包含2个数据*/ 
{
		int a[m][n],b[m][n];int c[m][n];
	int i,j;
	//实现文件的读取 
	FILE *fp1; 
	FILE *fp2; 
	FILE *fp3;
	fp1 = fopen("A.txt", "r"); 
	if (!fp1)
	{
		printf("打开文件失败");
	}
	for (i = 0; i<m; i++)
		for (j = 0; j<n; j++)
			fscanf(fp1, "%d", &a[i][j]); 
        printf("\n矩阵A为：\n");
		for (i = 0; i<m; i++)
		{
		for (j = 0; j<n; j++)
			printf("%d\t",a[i][j]);
		printf("\n"); 
		} 
        fclose(fp1);
        fp2 = fopen("B.txt", "r");
        if (!fp2){
		printf("打开文件失败");
	}
	for (i= 0; i<m; i++)
		for (j = 0; j<n; j++)
			fscanf(fp2, "%d", &b[i][j]);
		printf("\n矩阵B为：\n");
		for (i = 0; i<m; i++)
		{
		for (j = 0; j<n; j++)
			printf("%d\t",b[i][j]);
		printf("\n"); 
		} 
	fclose(fp2);					//读取完毕关闭文件 
	//对数据进行处理，实现矩阵相乘并赋值给c 
	for (i= 0;i<m;i++)
		for (j = 0; j<n; j++)
			c[i][j]=a[i][j]*b[i][j]; 
        printf("\n矩阵C为：\n");
		for (i = 0; i<m; i++)
		{
		for (j = 0; j<n; j++)
			printf("%d\t",c[i][j]);
		printf("\n"); 
		} 
        fp3 = fopen("C.txt", "wb");
	for (i = 0; i<m; i++)
	{
		for (j = 0; j<n; j++)
			fprintf(fp3,"%d\t",c[i][j]);
		fprintf(fp3,"\r\n" );
	}
        fclose(fp3);
	
	
}
void fun5()
/*实现矩阵的转置，要求文件中必须包含1个数据*/ 
{
	int a[m][n],b[n][m];
	int i,j;
	//实现文件的读取 
    FILE *fp1; FILE *fp2;
	fp1 = fopen("A.txt", "r"); 
	if (!fp1){
		printf("打开文件失败");
	}
	for (i = 0; i<m; i++)
		for (j = 0; j<n; j++)
			fscanf(fp1, "%d", &a[i][j]); 
		printf("\n原矩阵A为：\n");
		for (i = 0; i<m; i++)
		{
		for (j = 0; j<n; j++)
			printf("%d\t",a[i][j]);
		printf("\n"); 
		} 
        fclose(fp1);      //读取a完毕后关闭文件  
  	for(i=0;i<m;i++)      
		for(j=0;j<n;j++)
				b[j][i]=a[i][j];
        //对数据进行处理，实现矩阵a转置
		printf("\n异地转置后矩阵为：\n");
		for (i = 0; i<n; i++)
		{
		for (j = 0; j<m; j++)
			printf("%d\t",b[i][j]);
		printf("\n"); 
		}
        fp2 = fopen("zhuanzhi.txt", "wb");
	    for (i = 0; i<m; i++)
		{
		for (j = 0; j<n; j++)
			fprintf(fp2,"%d\t",b[i][j]);
		fprintf(fp2,"\r\n" );
		}
        fclose(fp2);
}
void fun6()
{
	int choose;
	while(1)
	{
		menu3();
     	scanf("%d",&choose);/*输入选择功能的编号*/
    	switch(choose)
		{
		case 1:
			 system("cls");
             fun7();
	         break;
		case 2:
			 system("cls");
             fun5();
	         break;
		case 3:
			 printf("\n\n\n\t\t\t请输入任意键返回上一级菜单\n");
             return;
		default:
			system("cls");
            error();
			break;
		}
		getch();
	}
}

void fun7()
/*实现矩阵的转置，要求文件中必须包含1个数据*/ 
{
	int a[m][n];
	int i,j,t;
	//实现文件的读取 
	if (m==n)
	{
	FILE *fp1; FILE *fp2;
	fp1 = fopen("A.txt", "r"); 
	if (!fp1){
		printf("打开文件失败");
	}
	for (i = 0; i<m; i++)
		for (j = 0; j<n; j++)
			fscanf(fp1, "%d", &a[i][j]); 
		printf("\n原矩阵A为：\n");
		for (i = 0; i<m; i++)
		{
		for (j = 0; j<n; j++)
			printf("%d\t",a[i][j]);
		printf("\n"); 
		} 
        fclose(fp1);      //读取a完毕后关闭文件  
  	for(i=0;i<m-1;i++)      
		for(j=0;j<i-1;j++)
		{
				t=a[j][i];
				a[j][i]=a[i][j];
				a[i][j]=t;
		}
        //对数据进行处理，实现矩阵a转置
		printf("\n就地转置后矩阵为：\n");
		for (i = 0; i<n; i++)
		{
		for (j = 0; j<m; j++)
			printf("%d\t",a[j][i]);
		printf("\n"); 
		}
        fp2 = fopen("A.txt", "wb");
	    for (i = 0; i<n; i++)
		{
		for (j = 0; j<m; j++)
			fprintf(fp2,"%d\t",a[j][i]);
		fprintf(fp2,"\r\n" );
		}
        fclose(fp2);} 
      else printf("\t所输入的m!=n,无发得出结果");  
}

void fun8()
{
	int a[m][n];
	int i,j,zdjx=0,fdjx=0;
	//实现文件的读取 
	if (m==n)
	{	FILE *fp1; FILE *fp2;
	fp1 = fopen("A.txt", "r"); 
	if (!fp1){
		printf("打开文件失败");
	}
	for (i = 0; i<m; i++)
		for (j = 0; j<n; j++)
			fscanf(fp1, "%d", &a[i][j]); 
		printf("\n原矩阵A为：\n");
		for (i=0; i<m; i++)
		{
		for (j=0; j<n; j++)
			printf("%d\t",a[i][j]);
		printf("\n"); 
		} 
        fclose(fp1);      //读取a完毕后关闭文件
		for (i=0; i<m; i++)
		  zdjx+=a[i][i];
		for (j=n;j>=1;j--)
		  fdjx+=a[n-j][j-1];
		printf("\n主对角线的和为:%d",zdjx);	
		printf("\n副对角线的和为:%d",fdjx);
        fp2 = fopen("djx.txt", "wb");
			fprintf(fp2,"主对角线的和为:%d",zdjx);
			fprintf(fp2,"\r\n" );
			fprintf(fp2,"副对角线的和为%d",fdjx);
        fclose(fp2);}		
        else printf("\t所输入的m!=n,无发得出结果");
}

void  menu2()
{
	system("cls");
	printf("\n\n\n\t\t请选择操作\n");
	printf("\t\t|-----------------------------|\n");
	printf("\t\t|\t1.矩阵相加            |\n");
	printf("\t\t|\t2.矩阵相减            |\n");
	printf("\t\t|\t3.返回                |\n");
	printf("\t\t|-----------------------------|\n\n");
}

void error()
{
	printf("\n\n\n\n\n\t\t|\t\t选择错误!请重新选择\t\t|\n");
	printf("\n\n\n\t\t\t    请输入任意键返回上一级菜单\n");
}

void  menu3()
{
	system("cls");
	printf("\n\n\n\t\t请选择操作\n");
	printf("\t\t|-----------------------------|\n");
	printf("\t\t|\t1.就地转置            |\n");
	printf("\t\t|\t2.异地转置            |\n");
	printf("\t\t|\t3.返回                |\n");
	printf("\t\t|-----------------------------|\n\n");
}

/*

void welcome1()
{
	 /*颜色变化效果
	
	int i;
	int t=8;
	printf("\t\t***********************************\n");
	printf("\t\t   基于ASCII文件的矩阵计算演示系统\n");
	printf("\t\t***********************************\n");
    while(--t)
	{ 
	  /*每个for循环代表每个颜色持续的时间
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

*/

void welcome2()
{
	int i,j;
	for(i=0;i<7;i++)
	{
	   printf("\t**************************************************************\n\n\n");
	   printf("\n\t  ★★★★★欢迎进入基于ASCII文件的矩阵计算演示系统★★★★\n\n"); 
	   printf("\n\n\t*************************************************************\n");
	   printf("\n\n\n\t\t\t请输入任意键进入\n");
	   Sleep(222);
	   	if(i!=6) 
			system("cls");


	   /*
	   if(i==6) 
		   ;                   
	   else
	       system("cls");
       */


		for(j=0;j<i;j++) 
			printf("\n");

	}
    getch();
	
}
