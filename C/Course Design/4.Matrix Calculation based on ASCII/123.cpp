
/*
          C���Գ������
		  ����ASCII�ļ��ľ��������ʾϵͳ
	
*/

#include<stdio.h> /*��׼�������ͷ�ļ�*/
#include<stdlib.h> /*��׼��ͷ�ļ�*/
#include<windows.h> /*����Windows API ����ͷ�ļ�*/
#include<conio.h> /*����̨�������ͷ�ļ�*/
#define m 3
#define n 4
void mainmenu();/*�Զ������˵�����*/
void  menu2();/*�Զ�������˵�����*/
void  menu3();/*�Զ�������˵�����*/
void fun1();/*�Զ�������˵��ӹ��ܺ���*/
void fun2();/*�Զ���һ���˵��ӹ��ܺ���*/
void fun3();/*�Զ���һ���˵��ӹ��ܺ���*/
void fun4();/*�Զ���һ���˵��ӹ��ܺ���*/
void fun5();/*�Զ���һ���˵��ӹ��ܺ���*/
void fun6();/*�Զ�������˵��ӹ��ܺ���*/
void fun7();/*�Զ�������˵��ӹ��ܺ���*/
void fun8();/*�Զ���һ���˵��ӹ��ܺ���*/
void welcome1();/*�Զ���˵�ͷ����(��ɫ���)*/
void welcome2();/*�Զ���˵�ͷ����(�����ƶ�)*/
void error();/*�Զ���ѡ�������*/



main() /*������*/
{
	int choose;
	system("color 5E");
	welcome2();  /*welcome1();*/
	while(1)
	{
    	mainmenu();
     	scanf("%d",&choose);/*����ѡ���ܵı��*/
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
			printf("\n\n\n\n\n\t|--------��лʹ�ã��ټ�!------|\t\n\n\n\n\n");
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
	system("cls");/*��������*/
	printf("\n\n\n");
	printf("\t\t|--------------------------------------------------|");
	printf("\t\t\t\t|\t ����ASCII�ļ��ľ��������ʾϵͳ           |\t\t\t\n");
	printf("\t\t|--------------------------------------------------|\n\n\n");
	printf("\t\t|-----------------��ѡ�����ֽ��в���---------------|\n");
	printf("\t\t|\t\t1.�����/��                        |\n");
	printf("\t\t|\t\t2.�������                         |\n");
	printf("\t\t|\t\t3.����ת��                         |\n");
	printf("\t\t|\t\t4.����Խ���֮��                   |\n");
	printf("\t\t|\t\t0.�˳�ϵͳ                         |\n");
	printf("\t\t|-----------------��ѡ���Ӧ����0--4---------------|\n");
    printf("\n\n\n\t˵��:\n\t\t2��4Ϊһ���˵�,1��3Ϊ�����˵�,0Ϊ�˳�ϵͳ\n");
}

void fun1()
{
	int choose;
	while(1)
	{
		menu2();
     	scanf("%d",&choose);/*����ѡ���ܵı��*/
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
			 printf("\n\n\n\t\t\t�����������������һ���˵�\n");
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
{/*ʵ�־������ӣ�Ҫ���ļ��б������2������*/ 
	int a[m][n],b[m][n];int c[m][n];
	int i,j;
	//ʵ���ļ��Ķ�ȡ 
	FILE *fp1; 
	FILE *fp2; 
	FILE *fp3;
	fp1 = fopen("A.txt", "r"); 
	if (!fp1)
	{
		printf("���ļ�ʧ��");
	}
	for (i = 0; i<m; i++)
		for (j = 0; j<n; j++)
			fscanf(fp1, "%d", &a[i][j]); 
        printf("\n����AΪ��\n");
		for (i = 0; i<m; i++)
		{
		for (j = 0; j<n; j++)
			printf("%d\t",a[i][j]);
		printf("\n"); 
		} 
        fclose(fp1);
        fp2 = fopen("B.txt", "r");
        if (!fp2){
		printf("���ļ�ʧ��");
	}
	for (i= 0; i<m; i++)
		for (j = 0; j<n; j++)
			fscanf(fp2, "%d", &b[i][j]);
		printf("\n����BΪ��\n");
		for (i = 0; i<m; i++)
		{
		for (j = 0; j<n; j++)
			printf("%d\t",b[i][j]);
		printf("\n"); 
		} 
	fclose(fp2);					//��ȡ��Ϲر��ļ� 
	//�����ݽ��д���ʵ�־�����Ӳ���ֵ��c 
	for (i= 0;i<m;i++)
		for (j = 0; j<n; j++)
			c[i][j]=a[i][j]+b[i][j]; 
        printf("\n����CΪ��\n");
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
/*ʵ�־���������Ҫ���ļ��б������2������*/ 
{
	int a[m][n],b[m][n];
	int c[m][n];
	int i,j;
	//ʵ���ļ��Ķ�ȡ 
	FILE *fp1; 
	FILE *fp2; 
	FILE *fp3;
	fp1 = fopen("A.txt", "r"); 
	if (!fp1)
	{
		printf("���ļ�ʧ��");
	}
	for (i = 0; i<m; i++)
		for (j = 0; j<n; j++)
			fscanf(fp1, "%d", &a[i][j]); 
        printf("\n����AΪ��\n");
		for (i = 0; i<m; i++)
		{
		for (j = 0; j<n; j++)
			printf("%d\t",a[i][j]);
		printf("\n"); 
		} 
        fclose(fp1);
        fp2 = fopen("B.txt", "r");
        if (!fp2){
		printf("���ļ�ʧ��");
	}
	for (i= 0; i<m; i++)
		for (j = 0; j<n; j++)
			fscanf(fp2, "%d", &b[i][j]);
		printf("\n����BΪ��\n");
		for (i = 0; i<m; i++)
		{
		for (j = 0; j<n; j++)
			printf("%d\t",b[i][j]);
		printf("\n"); 
		} 
	fclose(fp2);					//��ȡ��Ϲر��ļ� 
	//�����ݽ��д���ʵ�־����������ֵ��c 
	for (i= 0;i<m;i++)
		for (j = 0; j<n; j++)
			c[i][j]=a[i][j]-b[i][j]; 
        printf("\n����CΪ��\n");
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
/*ʵ�־������ˣ�Ҫ���ļ��б������2������*/ 
{
		int a[m][n],b[m][n];int c[m][n];
	int i,j;
	//ʵ���ļ��Ķ�ȡ 
	FILE *fp1; 
	FILE *fp2; 
	FILE *fp3;
	fp1 = fopen("A.txt", "r"); 
	if (!fp1)
	{
		printf("���ļ�ʧ��");
	}
	for (i = 0; i<m; i++)
		for (j = 0; j<n; j++)
			fscanf(fp1, "%d", &a[i][j]); 
        printf("\n����AΪ��\n");
		for (i = 0; i<m; i++)
		{
		for (j = 0; j<n; j++)
			printf("%d\t",a[i][j]);
		printf("\n"); 
		} 
        fclose(fp1);
        fp2 = fopen("B.txt", "r");
        if (!fp2){
		printf("���ļ�ʧ��");
	}
	for (i= 0; i<m; i++)
		for (j = 0; j<n; j++)
			fscanf(fp2, "%d", &b[i][j]);
		printf("\n����BΪ��\n");
		for (i = 0; i<m; i++)
		{
		for (j = 0; j<n; j++)
			printf("%d\t",b[i][j]);
		printf("\n"); 
		} 
	fclose(fp2);					//��ȡ��Ϲر��ļ� 
	//�����ݽ��д���ʵ�־�����˲���ֵ��c 
	for (i= 0;i<m;i++)
		for (j = 0; j<n; j++)
			c[i][j]=a[i][j]*b[i][j]; 
        printf("\n����CΪ��\n");
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
/*ʵ�־����ת�ã�Ҫ���ļ��б������1������*/ 
{
	int a[m][n],b[n][m];
	int i,j;
	//ʵ���ļ��Ķ�ȡ 
    FILE *fp1; FILE *fp2;
	fp1 = fopen("A.txt", "r"); 
	if (!fp1){
		printf("���ļ�ʧ��");
	}
	for (i = 0; i<m; i++)
		for (j = 0; j<n; j++)
			fscanf(fp1, "%d", &a[i][j]); 
		printf("\nԭ����AΪ��\n");
		for (i = 0; i<m; i++)
		{
		for (j = 0; j<n; j++)
			printf("%d\t",a[i][j]);
		printf("\n"); 
		} 
        fclose(fp1);      //��ȡa��Ϻ�ر��ļ�  
  	for(i=0;i<m;i++)      
		for(j=0;j<n;j++)
				b[j][i]=a[i][j];
        //�����ݽ��д���ʵ�־���aת��
		printf("\n���ת�ú����Ϊ��\n");
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
     	scanf("%d",&choose);/*����ѡ���ܵı��*/
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
			 printf("\n\n\n\t\t\t�����������������һ���˵�\n");
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
/*ʵ�־����ת�ã�Ҫ���ļ��б������1������*/ 
{
	int a[m][n];
	int i,j,t;
	//ʵ���ļ��Ķ�ȡ 
	if (m==n)
	{
	FILE *fp1; FILE *fp2;
	fp1 = fopen("A.txt", "r"); 
	if (!fp1){
		printf("���ļ�ʧ��");
	}
	for (i = 0; i<m; i++)
		for (j = 0; j<n; j++)
			fscanf(fp1, "%d", &a[i][j]); 
		printf("\nԭ����AΪ��\n");
		for (i = 0; i<m; i++)
		{
		for (j = 0; j<n; j++)
			printf("%d\t",a[i][j]);
		printf("\n"); 
		} 
        fclose(fp1);      //��ȡa��Ϻ�ر��ļ�  
  	for(i=0;i<m-1;i++)      
		for(j=0;j<i-1;j++)
		{
				t=a[j][i];
				a[j][i]=a[i][j];
				a[i][j]=t;
		}
        //�����ݽ��д���ʵ�־���aת��
		printf("\n�͵�ת�ú����Ϊ��\n");
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
      else printf("\t�������m!=n,�޷��ó����");  
}

void fun8()
{
	int a[m][n];
	int i,j,zdjx=0,fdjx=0;
	//ʵ���ļ��Ķ�ȡ 
	if (m==n)
	{	FILE *fp1; FILE *fp2;
	fp1 = fopen("A.txt", "r"); 
	if (!fp1){
		printf("���ļ�ʧ��");
	}
	for (i = 0; i<m; i++)
		for (j = 0; j<n; j++)
			fscanf(fp1, "%d", &a[i][j]); 
		printf("\nԭ����AΪ��\n");
		for (i=0; i<m; i++)
		{
		for (j=0; j<n; j++)
			printf("%d\t",a[i][j]);
		printf("\n"); 
		} 
        fclose(fp1);      //��ȡa��Ϻ�ر��ļ�
		for (i=0; i<m; i++)
		  zdjx+=a[i][i];
		for (j=n;j>=1;j--)
		  fdjx+=a[n-j][j-1];
		printf("\n���Խ��ߵĺ�Ϊ:%d",zdjx);	
		printf("\n���Խ��ߵĺ�Ϊ:%d",fdjx);
        fp2 = fopen("djx.txt", "wb");
			fprintf(fp2,"���Խ��ߵĺ�Ϊ:%d",zdjx);
			fprintf(fp2,"\r\n" );
			fprintf(fp2,"���Խ��ߵĺ�Ϊ%d",fdjx);
        fclose(fp2);}		
        else printf("\t�������m!=n,�޷��ó����");
}

void  menu2()
{
	system("cls");
	printf("\n\n\n\t\t��ѡ�����\n");
	printf("\t\t|-----------------------------|\n");
	printf("\t\t|\t1.�������            |\n");
	printf("\t\t|\t2.�������            |\n");
	printf("\t\t|\t3.����                |\n");
	printf("\t\t|-----------------------------|\n\n");
}

void error()
{
	printf("\n\n\n\n\n\t\t|\t\tѡ�����!������ѡ��\t\t|\n");
	printf("\n\n\n\t\t\t    �����������������һ���˵�\n");
}

void  menu3()
{
	system("cls");
	printf("\n\n\n\t\t��ѡ�����\n");
	printf("\t\t|-----------------------------|\n");
	printf("\t\t|\t1.�͵�ת��            |\n");
	printf("\t\t|\t2.���ת��            |\n");
	printf("\t\t|\t3.����                |\n");
	printf("\t\t|-----------------------------|\n\n");
}

/*

void welcome1()
{
	 /*��ɫ�仯Ч��
	
	int i;
	int t=8;
	printf("\t\t***********************************\n");
	printf("\t\t   ����ASCII�ļ��ľ��������ʾϵͳ\n");
	printf("\t\t***********************************\n");
    while(--t)
	{ 
	  /*ÿ��forѭ������ÿ����ɫ������ʱ��
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
	   printf("\n\t  �����ﻶӭ�������ASCII�ļ��ľ��������ʾϵͳ�����\n\n"); 
	   printf("\n\n\t*************************************************************\n");
	   printf("\n\n\n\t\t\t���������������\n");
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
