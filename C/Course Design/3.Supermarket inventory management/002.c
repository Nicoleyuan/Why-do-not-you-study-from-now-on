//////////////////////////////////////////////////////////////////////////////////////////////////
/* **********************************************************************************************
 * ���п�����ϵͳ
 *
 * ���ݴ�ѧ��Ϣ����ѧԺ���1502��
 *
 * ָ����ʦ�������
 *
 * �汾������־:
 *
 * 2015��12��22�� 23:06:31    V0.1.0_Build 352
                 ��ɲ˵��Ȼ������
   2015��12��26�� 16:33:21    V0.1.2_Build 402
                 ���������֤ģ��
   2015��12��26�� 20:54:53    V0.1.5_Build 501
                 �����Ϣ¼�빦�ܡ��˵���ɫ���ù���
   2015��12��27�� 11:57:33    V0.1.8 Build 788
                 �����Ϣ��ѯģ�� 
   2015��12��28�� 11:14:37    V0.2.0 Build 925
                 ����������а�
				 �޸���֪BUG
   2015��12��29�� 11:04:35    V0.3.0 Build 967
                 ������Ϣ���¹���
   2015��12��29�� 17:19:02    Bata V 1.0.0 Build 1058
                 ��һ���԰�
   2015��12��30�� 21:25:02    Bata V 1.5.0 Build 1112
                 �Ľ����ֹ��ܴ���

 * BY �
 *
 * lijing394@163.com
 *
 * Ҫ��
 *
 * 1.��������:

   ����һ�����п�����ϵͳ���ɶ���Ʒ�Ŀ����Ϣ�����ճ�����Ԥ�������У������Ϣ��������Ʒ���š�
   ���ơ����������������ޡ�������ޡ������۸����ۼ۸񡢽������ڡ����������������ڡ�������
   �ҡ������ڵȡ���Ҫ�������£�
     �� �����Ϣ¼�룺�Ժ������ݽṹ¼�벢�洢�����Ϣ����ʾ���ṹ����������ļ���
	 �� ��Ϣ���£����ṩ��Ϣ�Ĳ��롢ɾ�����޸ĸ��²���������Ʒ����ʱ����������Ʒ����µ���Ʒ��Ϣ
	 ��ӵ������Ϣ�У�����������Ʒ�������Ʒ�������������ȷ������������Ȼ����ݽ���ʵ�������
	 �ĸ���Ʒ��������ݡ�
	 �� ��Ϣ��ѯ���ṩ����;���Ĳ�ѯ���ܣ��簴��Ų���Ʒ�۸���������ڡ�ĳ��Ʒ�������ĳ��Ʒ������
	 �ȡ�
	 �� �����ϢԤ����ͳ�Ƴ�������ٽ����ޣ�����п��Ԥ������Ʒ��������ٽ����ޣ�����п��Ԥ����
	 ��Ʒ�������ڵ���һ������۴�������Ʒ��
	 �� �ṩ����ͳ�ƹ��ܣ�ʳƷ��Ч��������Ʒ������������Ʒ���������ȣ���������ƣ���

   2.�������Ҫ��

        �� ϵͳ�Բ˵�������ʽ�������Է����û�������Ҫ���й���ѡ��
        �� ����������ƣ�Ҫ���û���������ʱ���������������ȷ����ʾ��Ϣ������������������ݡ���ʽ������
           ��ʽ�ȡ�
        �� ������棺����Ľ��Ҫ�������ۣ����Ա����ʽ�������Ϣ��Ӧ���¶��롣

   3.�������Ҫ��

         �� �����е�Դ���򣺿���������ͨ����������������Ҫ���C����
         �� �γ���Ʊ��棺׫д�γ���Ʊ��棬�ܷ�ӳ�����������ơ����ݽṹ��ơ���ϸ��ơ����Է������̡�
            Ҫ�����ݻ�����ȷ��ͼ�����ش����

///////////////////////////////////////////////////////////////////////////////////////////

/**********ͷ�ļ����궨��***************/
#include<stdio.h>
#include<stdlib.h> 
#include<windows.h> 
#include<conio.h>
#define NUM 100

/**** �ṹ�嶨�� ****/
struct item
{	
//	int   id;      ����
	char  brand[10];  //����
	int   in_price;  //����
	int   out_price; //�ۼ�
	int   stock_quantity;   //�������
	int   purchase_quantity;//������
	int   upper_limit; //�������
	int   lower_limit; //�������
	char  category[8]; //���
	char  manufacture_factory[8];//��������
	int   expiry_date;//������
	int   in_date;//��������
	int   manufacture_date;//��������
	char  remarks[8];//��ע
}goods[NUM];

/*********ȫ�ֱ���*************/
int nn = 0;  //��ǰ��Ʒ�ܸ���

/**** �������� ****/
void start();
void loading();
void main_menu();
int  Password_Authentification();
//void Modify_Password();
void establish();
void look_up();
void find_category();
void find_id();
void find_stock_quantity();
void update();
void insert_message();
void del_message();
void revise_message();
void chart();
void sort_amount();
void sort_profit();
void sort_id();
void earlywarning();
void colorsetting();
void indevelopment();
void error();
void gotoxy(int x,int y);
void HideCursor();
void help();
void leave();
void read();
void save();
//int validateID(int id);

/*************������*****************/
main()
{
	int choose;
	start();
	while(1)
	{	
    	main_menu();
     	scanf("%d",&choose);
    	switch(choose)
		{
		case 1:
			system("cls");
			establish();break;

		case 2:
			system("cls");
			update();break;

		case 3:
			system("cls");
			look_up();break;

		case 4:
			system("cls");
			earlywarning();break;

		case 5:
			system("cls");
		    chart();break;

		case 6:
			system("cls");
		    read();break;

        case 7:
			system("cls");
			colorsetting();break;

		case 0:
			save();
			printf("�ѱ���!\n");
			leave();

		default:
			system("cls");
            error();break;
		}
		getch();
	}
}

/*************���˵�*****************/
void main_menu()
{
	system("cls");
	printf("\n\n\n");
	printf("\t\t|--------------------------------------------------|");
	printf("\t\t\t\t|\t\t���п�����ϵͳ\t\t   |\n");
	printf("\t\t|--------------------------------------------------|\n\n\n");
	printf("\t\t|-----------------��ѡ�����ֽ��в���---------------|\n");
	printf("\t\t|\t\t1.�����Ϣ¼��                     |\n");
	printf("\t\t|\t\t2.������Ʒ��Ϣ                     |\n");
	printf("\t\t|\t\t3.��Ʒ��Ϣ��ѯ                     |\n");
	printf("\t\t|\t\t4.�����ϢԤ��                     |\n");
	printf("\t\t|\t\t5.���������ܰ�                     |\n");
	printf("\t\t|\t\t6.��ȡ��Ʒ��Ϣ                     |\n");
	printf("\t\t|\t\t7.ϵͳ��ɫ����                     |\n");
	printf("\t\t|\t\t0.�˳�ϵͳ                         |\n");
	printf("\t\t|-----------------��ѡ���Ӧ����0--6---------------|\n");
}
/*
int validateID(int id)
	{   
		FILE *fp;
		struct item i;
        fp=fopen("goods.dat","r");
		if(fp==NULL)
		{printf("\t\t\tϵͳ������������........");exit(0);}
		fread(&i,sizeof(struct item),1,fp);
		while(!feof(fp))
		{
			if(i.id==id)
			{	fclose(fp);return 1;break;	}
			fread(&i,sizeof(struct item),1,fp);
		}
		fclose(fp);	return 0;
	}
*/

/*************�����Ϣ¼��*****************/
void establish()
{       
	if( nn >= NUM-1)
	{printf("��Ʒ��Ϣ�Ѵ����ޣ�\n");system("pause"); return;}
/*labID:		printf("\n\t��������Ҫ�����Ʒ����Ϣ...\n");
			printf("\t\t\t\t   ����:");
			scanf("%d",&goods[i].id);
			if(validateID(goods[i].id)==1)
			{
				printf("\t\t\t\t�˱���ѱ�ʹ�ã�������������......");
				goto labID;
			}
	*/
	printf("\n\t��������� %d ����Ʒ��Ϣ\n\n\t������������Ʒ��Ϣ:\n",NUM);
	printf("----------------------------\n");
	printf("���: ");fflush(stdin);
	gets(goods[nn+1].category);
	printf("Ʒ��: ");fflush(stdin);
	gets(goods[nn+1].brand);
	/*	printf("����: ");fflush(stdin);
	scanf("%d",&goods[nn+1].id);*/
	printf("����: ");fflush(stdin);
	scanf("%d",&goods[nn+1].in_price);
	printf("�ۼ�: ");fflush(stdin);
	scanf("%d",&goods[nn+1].out_price);
	printf("��������: ");fflush(stdin);
	scanf("%d",&goods[nn+1].in_date);
	printf("������: ");fflush(stdin);
	scanf("%d",&goods[nn+1].purchase_quantity);
	printf("�������: ");fflush(stdin);
	scanf("%d",&goods[nn+1].upper_limit);
	printf("�������: ");fflush(stdin);
	scanf("%d",&goods[nn+1].lower_limit);
	printf("��������: ");fflush(stdin);
	scanf("%d",&goods[nn+1].manufacture_factory);
	printf("��������: ");fflush(stdin);
	scanf("%d",&goods[nn+1].manufacture_date);
	printf("������: ");	fflush(stdin);
	scanf("%d",&goods[nn+1].expiry_date);
	printf("��ע: ");fflush(stdin);
	gets(goods[nn+1].remarks);
	nn+=1;
	printf("\n\n");
	printf("��ţ�%d\n",nn);
	printf("Ʒ����");puts(goods[nn].brand);
	printf("���");puts(goods[nn].category);
	printf("���ۣ�%d\n",goods[nn].in_price);
	printf("�ۼۣ�%d\n",goods[nn].out_price);
	printf("��ע��");puts(goods[nn].remarks);
	printf("\n�밴���������!\n");
	getch();
}

/**********��Ϣ���º���**********/
void update()
{
	int choose;
    while(1)
	{
		system("cls");
		printf("\n\n\n     *******��Ʒ��Ϣ����*******\n\n");
		printf("             1:������Ʒ��Ϣ\n\n");
		printf("             2:ɾ����Ʒ��Ϣ\n\n");
		printf("             3:�޸���Ʒ��Ϣ\n\n");
		printf("             0:����\n\n");
		printf("             ��ѡ��(0-3):");
		scanf("%d",&choose);
	    switch(choose)
		{
	       case 1:insert_message();break;
		   case 2:del_message();break;
		   case 3:revise_message();break;
		   case 0:return;
		   default: error(); break;	
		}
		getch();
	}
}


void insert_message()
{	
	int i;char choose;
	printf("\n\t����������������Ʒ��Ϣ:\n",NUM);
	printf("----------------------------\n");
	for(i=1;i<=NUM;i++)
	{ 
		printf("���: ");fflush(stdin);
		gets(goods[i].category);
		printf("Ʒ��: ");fflush(stdin);
		gets(goods[i].brand);
	/*	printf("����: ");fflush(stdin);
		scanf("%d",&goods[i].id);*/
		printf("����: ");fflush(stdin);
		scanf("%d",&goods[i].in_price);
		printf("�ۼ�: ");fflush(stdin);
		scanf("%d",&goods[i].out_price);
		printf("��������: ");fflush(stdin);
		scanf("%d",&goods[i].in_date);
		printf("������: ");fflush(stdin);
		scanf("%d",&goods[i].purchase_quantity);
        printf("�������: ");fflush(stdin);
		scanf("%d",&goods[i].upper_limit);
		printf("�������: ");fflush(stdin);
		scanf("%d",&goods[i].lower_limit);
		printf("��������: ");fflush(stdin);
		scanf("%d",&goods[i].manufacture_factory);
		printf("��������: ");fflush(stdin);
		scanf("%d",&goods[i].manufacture_date);
		printf("������: ");fflush(stdin);
		scanf("%d",&goods[i].expiry_date);
		printf("��ע: ");fflush(stdin);
		gets(goods[i].remarks);

		printf("\n**** �Ѿ����� %d ����Ʒ!--\n",i);
		printf("\n\n�Ƿ�Ҫ����?Y/N?");
		choose=getch();
		if( choose == 'y' || choose == 'Y' ) {printf("\n�����������Ʒ��Ϣ\n"); continue;}
		else if( choose == 'n' || choose == 'N' ) {printf("\n��ֹ������Ʒ��Ϣ!\n�밴���������!\n"); break;}
		else  {printf("\nѡ������!��ֹ������Ʒ��Ϣ!\n�밴���������!\n"); break;}
	}
}
 
/***********ɾ��*************/
void del_message()
{ 
	char s[12],c; 
	int i=1,j; 
	printf("��������ɾ����Ʒ��:"); 
	fflush(stdin);
	gets(s); 
	while(strcmp(goods[i].brand,s) != 0 && i <= nn) i++; 
	if(i > nn) 
	{		printf("û�д���Ʒ!\n");		system("pause"); 	return; 	} 
	printf("����Ʒ��Ϣ:\n��ţ�%d\n",i);
	printf("��ţ�%d\n",nn);
    printf("Ʒ����");puts(goods[nn].brand);
    printf("���");puts(goods[nn].category);
    printf("���ۣ�%d\n",&goods[nn].in_price);
    printf("�ۼۣ�%d\n",&goods[nn].out_price);
    printf("��ע��");puts(goods[nn].remarks);
	printf("�Ƿ�ɾ��?(����\"1\"ɾ���������\"1\"������)\n");
	fflush(stdin);
	c=getchar();
	if(c=='1')
	{
	    for(j=i;j < nn;j++)
	    { 
	    	strcpy(goods[j].brand,goods[j+1].brand); 
	    	strcpy(goods[j].category,goods[j+1].category);
	    	goods[j].in_price  = goods[j+1].in_price;
	    	goods[j].out_price = goods[j+1].out_price;
	    	strcpy(goods[j].remarks,goods[j+1].remarks);
	    }
	    nn-=1;
	    printf("�ɹ�ɾ��!\n");
	    system("pause");
	    return;
	}
	return;
}
	/*
	FILE *fp;
	int del_id,i;
	fp=fopen("goods.dat","rb");
	if(fp == NULL)
	{		printf("��ȡ�ļ�����!������!");exit(0);	}
	for(i=0; i<NUM; i++)
		fscanf(fp,"%s%s%d%d",goods[i].category,goods[i].brand,goods[i].in_price,goods[i].out_price);
	printf("\n --������Ҫɾ����Ʒ�Ļ���:--\n");
	scanf("%d",&del_id);
	for(i=del_id; i<NUM; i++)
		goods[i-1]=goods[i];
		del_id--;
        fp=fopen("porder_list","wb");
	    fwrite(goods,sizeof(struct item),del_id,fp);
	    fclose(fp);
	printf("\t\t\t\t\t��Ʒ��Ϣ�����!!!\n");
	*/

/**************�޸�**************/
void revise_message()
{   
	int i=1,id,choose; 
	printf("���������޸ĵĻ���:"); 
	fflush(stdin);
	scanf("%d",&id);
	while( i != id  && i <= nn ) i++; 
	if( i > nn ) 
	{ 	printf("û�д���Ʒ!\n"); system("pause"); return; 	}  
	printf("\n   ----����Ʒ��Ҫ��Ϣ----\n");
	printf("����--Ʒ��--���--����--�ۼ�--������\n");
	printf("%d--%d--%5s--%d--%d--%d\n",nn,goods[i].brand,goods[i].category,goods[i].in_price,goods[i].out_price,goods[i].expiry_date);
	printf("\nҪ�޸�ʲô��Ϣ?\n      ");
	printf("\n        1:Ʒ��\n");
	printf("\n        2:���\n");
	printf("\n        3:����\n");
	printf("\n        4:�ۼ�\n");
	printf("\n        5:������\n");
	printf("\n        0:����\n");
	printf("\n        please choose(0-5)");
	scanf("%d",&choose);
	switch(choose)
	{
		case 1:printf("\n �޸ĺ��Ʒ����?:  "); gets(goods[i].brand);break;
		case 2:printf("\n �޸ĺ�������?:  "); gets(goods[i].category);break;
		case 3:printf("\n �޸ĺ�Ľ�����?:  "); scanf("%d",&goods[i].in_price);break;
		case 4:printf("\n �޸ĺ���ۼ���?:  "); scanf("%d",&goods[i].out_price);break;
		case 5:printf("\n �޸ĺ�ı�������?:"); scanf("%d",&goods[i].expiry_date);break;
		case 0: return;
		default: error(); break;
	}
	printf("�޸ĳɹ�!\n");
	printf("\n�밴���������\n");
	getch();
}


/*****************��ѯ*******************/
void look_up()
{
	int choose;
	while(1)
	{
		system("cls");
		printf("\n\n\n\t\t��ѡ�����\n");
		printf("\t\t|----------------------------------|\n");
		printf("\t\t|\t1.������ѯ��Ʒ��Ϣ       |\n");
		printf("\t\t|\t2.�����Ų�ѯ��Ʒ��Ϣ       |\n");
		printf("\t\t|\t3.������ѯ��Ʒ��Ϣ       |\n");
		printf("\t\t|\t0.����                     |\n");
		printf("\t\t|----------------------------------|\n\n");
		scanf("%d",&choose);
		switch(choose)
		{
	       case 1:find_category();break;
		   case 2:find_id();break;
		   case 3:find_stock_quantity();break;
		   case 0:return;
		   default: error(); break;	
		}
		getch();
	}
}

/************������**********/
void find_category()
{
    char s[12]; 
	int i=1; 
	printf("���������ѯ������:"); 	fflush(stdin);
	gets(s); 
	while(strcmp( goods[i].category,s) != 0 && i <= nn ) i++; 
	if( i > nn ) 
	{		printf("û�д�����Ʒ!\n"); return; 	} 
	printf("-------��Ʒ��Ϣ------\n");
//	printf("���ţ�");printf("%d",&goods[i].id);
	printf("Ʒ����");puts(goods[i].brand);
	printf("���ࣺ");puts(goods[i].category);
	printf("���ۣ�");printf("%d",&goods[i].in_price);
	printf("�ۼۣ�");printf("%d",&goods[i].out_price);
	printf("��ע��");puts(goods[i].remarks);
	getch(); 
	return;
}

/************�����Ų�*********/
void find_id()
{
    int i; 
	printf("��������Ʒ����:"); 
	scanf("%d",&i); 
	if( i > nn) 
	{printf("û�д˼�¼!\n"); system("pause"); return; } 
//	printf("���ţ�");printf("%d",&goods[i].id);
	printf("Ʒ����");puts(goods[i].brand);
	printf("���ࣺ");puts(goods[i].category);
	printf("���ۣ�");printf("%d",&goods[i].in_price);
	printf("�ۼۣ�");printf("%d",&goods[i].out_price);
	printf("��ע��");puts(goods[i].remarks);
	system("pause"); 
	return;
} 

/************������*********/
void find_stock_quantity()
{
	indevelopment();
/*
	struct item *p,*q[NUM];
    int i,j,k;
	system("cls");
	printf("\n            ����������� \n");
	printf("     ------------------------------------------------------\n");
	printf("\n      rank     id     name     kind     stock_quantity\n");
	p=goods;
	for(i=0;i<NUM;i++)
		q[i]=p++;
	for(i=0;i<NUM-1;i++)
	{k=i;
	for(j=i+1;j<NUM;j++)
		if((q[k]->stock_quantity)<(q[j]->stock_quantity))  k=j;
		if(k!=i)
		{p=q[i];q[i]=q[k];q[k]=p;}}
	for(i=0;i<NUM;i++)
		printf("\n   %6d     %6d    %8s     %8s     %5d\n",i+1,q[i]->id,q[i]->category,q[i]->out_price-q[i]->in_price);
	getch();
	*/
}

/*****************���Ԥ��******************/
void earlywarning()
{
	int i,page=1,max; char c;
	max=(nn+9)/10;
	do
	{
		system("cls");                      
     	printf("\n           ������������Ʒ \n");
    	printf("     ------------------------------------------------------\n");
	    printf("\n    id     name     kind     stock_quantity      \n");
		if(page<max)
    	{
    		for(i=page*10-9;i<=page*10;i++)                                                            
        	{ 
        		printf("     %-3d%-12s%-12s%-10d",i,goods[i].brand,goods[i].category,goods[i].stock_quantity);
				if(i%10!=0)printf("\n"); 
        	}
		}
    	else if(page==max)
    	{
    		for(i=page*10-9;i<=nn;i++)                                                            
        	{ 
        		printf("     %-3d%-12s%-12s%-10d",i,goods[i].brand,goods[i].category,goods[i].stock_quantity);
        		if(i%10!=0)printf("\n"); 
        	}
		}
		printf("-------------------------------------------------------------------------------\n");
        printf("1:��һҳ                            2:��һҳ                             0:����\n");
        printf("����ѡ��(0-2):");
		fflush(stdin);
      	c=getchar();
    	if(c=='1')
		{
		    if(page<max)page+=1;
			else{printf("�������һҳ!");system("pause");}
		}
    	else if(c=='2')
		{
		    if(page>1)page-=1;
			else{printf("���ǵ�һҳ!");system("pause");}
		}
	}while(c!='0');

}


/******************���а�*******************/
void chart()
{
   int choose;
   while(1)
   {
	   system("cls");
	   printf("\n\n          **********���������ܰ�**********\n\n");
	   printf("                 1:���������\n\n");
	   printf("                 2:����������\n\n"); 
	   printf("                 3:����������\n\n"); 
	   printf("                 0:����\n\n");
	   printf("                 ��ѡ��(0-3):");
	   scanf("%d",&choose);
	   switch(choose)
	   {
	   case 1:sort_amount(); break;
	   case 2:sort_profit(); break;
	   case 3:sort_id(); break;
	   case 0: return;
	   default: error(); break;
	   }
	   getch();
   }
}

/**********�������*************/
void sort_amount()
{
	indevelopment();
/*
	struct item *p,*q[NUM];
    int i,j,k;
	system("cls");
	printf("\n            ����������� \n");
	printf("     ------------------------------------------------------\n");
	printf("\n      rank     id     name     kind     stock_quantity\n");
	p=goods;
	for(i=0;i<NUM;i++)
		q[i]=p++;
	for(i=0;i<NUM-1;i++)
	{k=i;
	for(j=i+1;j<NUM;j++)
		if((q[k]->stock_quantity)<(q[j]->stock_quantity))  k=j;
		if(k!=i)
		{p=q[i];q[i]=q[k];q[k]=p;}}
	for(i=0;i<NUM;i++)
		printf("\n        %6d     %8s     %8s     %5d\n",i+1,q[i]->category,q[i]->out_price-q[i]->in_price);
	getch();
*/
}

/****************��������*************/
void sort_profit()
{
    indevelopment();
/*
	struct item *p,*q[NUM];
	int i,j,k;
	system("cls");
	printf("/n            ���������� \n");
	printf("     ------------------------------------------------------\n");
	printf("\n      rank    id    brand    category    profit\n");
	p=goods;
	for(i=0;i<NUM;i++)
		q[i]=p++;
	for(i=0;i<NUM-1;i++)
	{
		k=i;
	for(j=i+1;j<NUM;j++)
		if((q[k]->out_price-q[k]->in_price)<(q[i]->out_price-q[j]->in_price))  k=j;
		if(k!=i)
		{p=q[i];q[i]=q[k];q[k]=p;}}
	for(i=0;i<NUM;i++)
		printf("\n   %6d   %8s     %8s     %5d\n",i+1,q[i]->category,q[i]->out_price-q[i]->in_price);
	getch();
*/
}

/*************��������*************/
void sort_id()
{
	int i,page=1,max; char c;
	max=(nn+9)/10;
	do
	{
		system("cls");                      
    	printf("     ------------------------------------------------------\n");
	    printf("\n    id     name     kind  \n");
		if(page<max)
    	{
    		for(i=page*10-9;i<=page*10;i++)                                                            
        	{ 
        		printf("     %-3d%-12s%-12s",i,goods[i].brand,goods[i].category);
				if(i%10!=0)printf("\n"); 
        	}
		}
    	else if(page==max)
    	{
    		for(i=page*10-9;i<=nn;i++)                                                            
        	{ 
        		printf("     %-3d%-12s%-12s",i,goods[i].brand,goods[i].category);
        		if(i%10!=0)printf("\n"); 
        	}
		}
		printf("-------------------------------------------------------------------------------\n");
        printf("1:��һҳ                            2:��һҳ                             0:����\n");
        printf("����ѡ��(0-2):");
		fflush(stdin);
      	c=getchar();
    	if(c=='1')
		{
		    if(page<max)page+=1;
			else{printf("�������һҳ!");system("pause");}
		}
    	else if(c=='2')
		{
		    if(page>1)page-=1;
			else{printf("���ǵ�һҳ!");system("pause");}
		}
	}while(c!='0');
/*
	int i,j;
	struct item temp;
	system("cls");
	printf("\n            ���������� \n");
	printf("     ------------------------------------------------------\n");
	printf("\n  rank     id     name     kind     stock_quantity     in_price   out_price\n");
	for(i=0; i<NUM-1; i++)
		for(j=i+1;j < NUM; j++)
		{  
		     if(goods[i].id < goods[j].id)
			 {
		     temp=goods[i];
		     goods[i]=goods[j];
		     goods[j]=temp;
			 }
		}
  for(i=0;i < NUM ;i++)
       printf("%-2d  %-2d   %-6s  %-2d  %-2d  %-2d\n",i,goods[i].brand,goods[i].category,goods[i].stock_quantity,goods[i].in_price,goods[i].out_price);
  printf("���������������!");
  getch();
  */
}


/*****************ѡ�������ʾ*****************/
void error()
{
	printf("\n\n\n\n\n\t\t|\t\tѡ�����!������ѡ��\t\t|\n");
	printf("\n\n\n\t\t\t    �����������������һ���˵�\n");
}


/****************�з�����ʾ*********************/
void indevelopment()
{
	system("cls");
	printf("\n\n\n\n\n\n\tLoading....\t\n\n\n\n");
	printf("\n\n\n\t\t\t�����������������һ���˵�\n");
}

/**********��ʼ����**********/
void start()
{
	int m=28,n=12;
	char c1;
	system("color F0");
    printf("�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[");
	printf("�U20151230_Bata_V2.2                                                          �U");
	printf("�U                                                                            �U");
	printf("�U  �������Щ������������r�������ة��������������������Шr���Шr���Щ����Шr  �U");
	printf("�U  �������������������Щ����������������q�����������������ة���������������  �U");
	printf("�U  �����t�s�������������������q���s�����������������������������q����������  �U");
	printf("�U  �����������������������������������������������s�����������s������������  �U");
	printf("�U  �����������������������������������������������������������������������s  �U");
	printf("�U  ���t�������������������s�s�����������t�����t���������������s�t�بt���ة�  �U");
	printf("�U                                                                            �U");
	printf("�U                                                                            �U");
	printf("�U                              ������������                                  �U");
	printf("�U                     ��   ��  ����    �멧                                  �U");
	printf("�U                              ������������                                  �U");
	printf("�U                              ������������                                  �U");
	printf("�U                     ��       ����    �ک�                                  �U");
	printf("�U                              ������������                                  �U");
	printf("�U                              ������������                                  �U");
	printf("�U                     ��       ����    ����                                  �U");
	printf("�U                              ������������                                  �U");
	printf("�U                                                                            �U");
	printf("�U                                                         Copyright   @Lixeon�U");
	printf("�U                                                          lijing394@163.com �U");
	printf("�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a");
	HideCursor();
	gotoxy(m,n);
    while(1)
	{
		c1=getch();
		switch(c1)
		{
		case 72 :  //UP
			printf("  ");
			n-=3;
			if(n<12)n=18;
			gotoxy(m,n);
			printf("��");
			gotoxy(m-1,n);
			break;
		case 80 :   //DOWN
   			printf("  ");
			n+=3;
			if(n>18)n=12;
			gotoxy(m,n);
			printf("��");
			gotoxy(m-1,n);
			break;
		case'\r':   //ENTER
			if(18==n)
				leave();
			if(15==n)
			{
				system("cls");
			    help();
				while(getch()){system("cls");start();}
			}
			if(12==n)
			{	
				system("cls");
				loading();
				return;
				/*
				switch ( Password_Authentification() )
				{
				  case 0:
					system("color 4E");
					printf("\n\n\n\n\t\t\t    ������󣬼����˳�ϵͳ!\n\n\n"); 
					Sleep(1000);
				    exit(0);
				  case 1:
					printf("\n\n\n\n\t\t\t    ���ڽ��룬��ӭ����Ա!\n\n\n"); 
					Sleep(1000);
					return;
				}
				*/
			}
			break;
		}
	}
}

/*
/**************������֤*****************
int Password_Authentification()
{
	char password[]="admin12345",temp_password[16];//��������û����������
    printf("\n");
	printf("\n\n\n\n\t\t\t*****��ӭ���볬�п�����ϵͳ*****\n");
    printf("\n\n\n\n\t\t\t����������:");
    gets(temp_password);
	if(strcmp(password,temp_password)==0)//�Ƚ�����
		return 1;
	else
		return 0;
}
/**************�޸�����*********/  //������ 16���ַ�
/*
   void Modify_Password()
   FILE *fp;
   char temp_mima[20],temp1[20],temp2[20];temp_mima[20]//��������û���������룬temp1[20],temp2[20]�ֱ���������û�����������޸ĵ�����
   printf("\n");
    printf("\t\t         ======================        \n");
    printf("\t\t                 �޸�����                 \n");
    printf("\t\t         ======================        \n");
    printf("\n");
	printf("\t\t           ������ԭʼ����:");
	scanf("\t\t%s",temp_mima);
    while(1)
    {
	if(strcmp(temp_mima,mima)==0)//�Ƚ�����
	{
		printf("\t������������:");
		scanf("%s",temp1);
		printf("\t��������һ��:");
		scanf("%s",temp2);
		if(strcmp(temp1,temp2)==0)//�����������������붼��ͬ
		{
			printf("\t�޸�����ɹ�!!���������,���������...");
			strcpy(mima,temp1);
			getch();break;
		}
		else
		{
			printf("\t�����������벻��ͬ���޸�ʧ��!���������...");
			getch();break;
		}
	}
	else
	{
		printf("\t�������!�����ܽ��������޸�!���������...");
		getch();break;
	}
*/

/************����**************/
void help()
{
	system("color 5A");
	printf("                    �������������������              \n");
	printf("                    ��    �� �� �� �� �� �� ϵ ͳ     ��              \n");
    printf("                    ��          Bata 1.5              ��              \n");
    printf("                    ��     ��               ��        ��              \n");
	printf("                    ��                                ��              \n");
	printf("                    �������������������              \n");
	printf("                                                                      \n");
	printf("                                                                      \n");
	printf("                           ���ǵ�һ�β��԰棬                         \n");
	printf("         UP                �ܶ๦�ܻ������ơ�                         \n");
	printf("         ��                 ����bug��Ȼ�Զ࣬                         \n");
	printf("                           �������ϵ��Կ�����                         \n");
	printf("                     ��������������������������������    ��������     \n");
	printf("   ��   ���   ��    ���������ǵ�ϵͳ��Խ��Խ���� !��    ��ȷ�ϩ�     \n");
	printf("                     ��������������������������������    ��������     \n");
	printf("                               �汾������־��                         \n");
	printf("         ��            2015.12.24 V0.1.0  ��ɻ������     �س�       \n");
	printf("        DOWN           2015.12.26 V0.3.0  ��ɻ�������                \n");
	printf("                       2015.12.27 V1.0.0   Bata���԰�                 \n");
	printf("                       2015.12.30 V1.5.0   ���԰�����                 \n");
	printf("                              ������������                            \n");
	printf("                                                  ��C���Կγ���ơ�   \n");
	printf("                             �밴���������        ���1502   �    \n");
}

/**********���ؽ���**********/
void loading()
{
    int i=0,m=4,n=3;
	printf("�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[");
    printf("�U                                                                            �U");
    printf("�U  �u�������������������������������������������������������������������������U");
    printf("�U  ��                                                                  ��%%  �U");
    printf("�U  �v�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x���x���U");
    printf("�U                                                                            �U");
    printf("�U                                                                            �U");
    printf("�U                                                                            �U");
    printf("�U                                                                            �U");
    printf("�U                     ���������������ǩ����q�������ǩ�����                   �U");
    printf("�U                     ���ǩ����������ߩ��ǩ���������������                   �U");            
    printf("�U                     ���������������ǩ��t�r��������������                   �U");
    printf("�U                     �����������������Ǩs����������������                   �U");
    printf("�U                     �����������������ǩ��Ǩs�����ǩ����s                   �U");
    printf("�U                     ���s���s���s�t�������t��������������                   �U");
    printf("�U                                                                            �U");
    printf("�U                                                                            �U");
    printf("�U                                                                            �U");
    printf("�U                                                                            �U");
    printf("�U                                                                            �U");
    printf("�U                                                                            �U");
    printf("�U                                                                            �U");
    printf("�U                                                                            �U");
    printf("�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a");
    while(1)
	{
		  Sleep(50);
		  gotoxy(m+=2,n);
		  printf("��");
		  gotoxy(76,n);
		  printf("%2d",i+=3);
		  if(i==99)
		  {Sleep(1000);break;}
	}
	system("cls");
}

void gotoxy(int x,int y)//������ƶ�������Ϊ(x,y)�ĵط�
{
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;                            
    HANDLE hConsoleOut;
    hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hConsoleOut,&csbiInfo);
    csbiInfo.dwCursorPosition.X = x;                                    
    csbiInfo.dwCursorPosition.Y = y;                                    
    SetConsoleCursorPosition(hConsoleOut,csbiInfo.dwCursorPosition);  
}

void HideCursor()//���ع��
{
     CONSOLE_CURSOR_INFO cursor_info = {1, 0}; 
     SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}


/*****************��ȡ����******************/
void read()
{
	FILE *fp;
	char name[10];                    
	printf("��������д��������ļ���:"); 
	scanf("%s",name); 
	printf("���ڵ�������.......:\n");
	Sleep(555);
	fp=fopen(name,"rb");
	if(fp == NULL)                   
	{ printf("���ļ�����...\n"); system("pause"); return; } 
	fread(&nn,sizeof(int),1,fp);
	fread(goods,sizeof(struct item),nn+1,fp);
	fclose(fp);
	printf("����ɹ�!\n");
	printf("�밴������������˵�");
	getchar();
}


/*************ϵͳ��ɫ����*************/
void colorsetting()
{
	int choose_1; char choose_2;
	system("cls");
	printf("\n\n\t\tѡ�����·���\n");
	printf("\n\n\t\t1**************��׺���\n");
	printf("\n\n\t\t2**************�׵׺���\n");
	printf("\n\n\t\t3**************�ڵ׺���\n");
	printf("\n\n\t\t4**************�̵�����\n");
	printf("\n\n\t\t5**************�Ƶ�����\n");
	printf("\n\n\t\t6**************ϵͳĬ��\n");
	printf("\n\n\t\t\t\t\t����ѡ��ϲ������ɫ<1-5>......");
	scanf("%d",&choose_1);
	switch(choose_1)
	{
			case 1:	system("color 40");	break;
			case 2:	system("color 70");	break;
			case 3:	system("color 04");	break;
			case 4:	system("color 21"); break;
			case 5:	system("color 65");	break;
			case 6:	system("color 3f");	break;
			default:system("cls");error();getch();return;
	}
	printf("\nѡ�����ɫ����������?(y�������˵�/n����ѡ��)");
    scanf("%c",&choose_2); 
    if(choose_2=='Y'|| choose_2=='y') { system("cls"); main_menu();}
    else    colorsetting(); 
}


/****************��������********************/
void save()
{
	FILE *fp;
	fp=fopen("data.dat","wb");
	fwrite(&nn,sizeof(int),1,fp);
	fwrite(goods,sizeof(struct item),nn+1,fp);
	fclose(fp);
}

/*******�����ļ�****************
void WritetoText()
{
	int i=0; 
	FILE *fp;                                     
	char filename[30];                              
	printf("д�뵽�ļ�:\n");                     
	printf("��������д����ļ���:"); 
	scanf("%s",filename); 
	if((fp=fopen(filename,"w"))==NULL)                   
	{ 
		printf("�޷����ļ�\n"); 
		system("pause"); 
		return; 
	} 
	fprintf(fp,"-------------------------------------------------------------------------------\n");                         
	fprintf(fp,"��� ����        �绰            �ʼ�                ��˾                ����  \n"); 
	fprintf(fp,"-------------------------------------------------------------------------------\n"); 
	for(i=1;i<=n;i++)                                                            
	{ 
		fprintf(fp,"%-3d  %-12s%-16s%-20s%-20s%-8s\n",i,per[i].name,per[i].tel,per[i].email,per[i].company,per[i].classify); 
		if(i>1&&i%10==0)                                                          
		{
			fprintf(fp,"-------------------------------------------------------------------------------\n");
		} 
	}
    fprintf(fp,"-------------------------------------------------------------------------------\n");
	fclose(fp);                                         //�ر��ļ� 
	printf("д��ɹ�!\n");
	system("pause"); 
}
*/
/************�˳�ϵͳ****************/
void leave()
{
			system("cls");
			printf("\n\n\n\n\n\n\n\n\t\t|--------��лʹ�ã��ټ�!------|\t\n\n\n\n\n");
			exit(0);
}