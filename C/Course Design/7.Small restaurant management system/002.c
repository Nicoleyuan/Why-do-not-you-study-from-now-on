#include<stdio.h>
#include<stdlib.h> 
#include<windows.h> 
#include<conio.h>
int porder_num=0;
int order_num=0;
int income=0;

struct order/*��͵Ľṹ��*/ 
{
	int table;/*����*/ 
	int dish_num;/*��Ʒ���*/ 
	char dish_name[200];/*��Ʒ����*/ 
	int price;/*����*/ 
	int num;/*����*/ 
	char name[20];/*�˿�����*/ 
	int pay;/* ���*/ 
};

struct porder/*�绰���͵Ľṹ��*/ 
{
		long int s_num;/*���*/ 
     	char name[20];/*����*/ 
	    int num;/*����*/ 
	    char time[15];/*�ò�ʱ��*/ 
	    int table;/*����*/ 
	    char arrangred[5];/*�Ƿ���*/ 
};

void error()
{
	printf("\n\n\n\n\n\t\t|\t\tѡ�����!������ѡ��\t\t|\n");
	printf("\n\n\n\t\t\t    �����������������һ���˵�\n");
}

void welcome()
{
	int i,j,t;
	for(i=0;i<7;i++)
	{
	   printf("\t************************************************************\n\n\n");
	   printf("\n\t\t�������ﻶӭ����С�Ͳ͹ݹ���ϵͳ�������\n\n"); 
	   printf("\n\n\t************************************************************\n");
	   printf("\n\n\n\t\t\t���������������\n");
	   	for(t=0;t<100;t++);
		system("color d");
		for(t=0;t<100;t++);
		system("color a");
		for(t=0;t<100;t++);
		system("color c");
		for(t=0;t<100;t++);
		system("color b");
		for(t=0;t<100;t++);
		system("color f");
		for(t=0;t<100;t++);
		system("color e");
	   Sleep(222);
	   	if(i!=6) 
			system("cls");
		for(j=0;j<i;j++) 
			printf("\n");
	}
    getch();	
}

void input_porder()
{	
    struct porder cos;
	FILE *fp;
	fp=fopen("porder_list","ab+");
    printf("\n\n\n\t\t�������������ݣ�\n\t\t���:");
	scanf("%ld",&cos.s_num) ;
	printf("\n\t\t����:");
	scanf("%s",cos.name);
	printf("\n\t\t������");
	scanf("%d",&cos.num);
	printf("\n\t\t�ò�ʱ��:");
	scanf("%s",cos.time) ;
	printf("\n\t\t����:");
	scanf("%d",&cos.table);
	printf("\n\t\t�Ƿ���:");
	scanf("%s",cos.arrangred);
    if( fwrite(&cos,sizeof(struct porder),1,fp)!=1)
			 {
			   printf ("file write error\n");
			   fclose(fp);
			   printf("\n\n\n\t\t\t    �����������������һ���˵�\n");
			   return;}
	fclose(fp);
	system("cls");
	printf("\n\t\t�����ɹ����밴����������ϼ���");
	porder_num++;

}

void del_porder()
{
	FILE *fp;
	int ch;
	if((fp=fopen("porder_list","rb+"))==NULL||((ch=fgetc(fp))==EOF))
	{
		printf("\n\t\t��ԤԼ���������޸ģ�������������ϼ���");
		return;
	}
	rewind(fp);     
	struct porder cos[99];
	int i,a,b;
	fread(cos,sizeof(struct porder),porder_num,fp);
	fclose(fp);
	for(i=0,a=1;i<porder_num;i++,a++)
	printf("\n\t\t���:%d���:%ld   ����:%s    ����:%d   �ò�ʱ��:%s    Ԥ������:%d   �Ƿ���:%s\n",a,cos[i].s_num,cos[i].name,cos[i].num,cos[i].time,cos[i].table,cos[i].arrangred);
	printf("\n\t\t������Ҫɾ������Ϣ���:");
	scanf("%d",&b);
	if(b<1||b>=a)
	{ error();return;	}
	for(i=b;i<porder_num;i++)
	cos[i-1]=cos[i];
	porder_num--;
	fp=fopen("porder_list","wb");
	fwrite(&cos,sizeof(struct porder),porder_num,fp);
	fclose(fp);
	system("cls");
	printf("\n\t\t�����ɹ����밴����������ϼ���");

}

void modify_porder()
{
	FILE *fp;
	int ch;
	if((fp=fopen("porder_list","rb+"))==NULL||((ch=fgetc(fp))==EOF))
	{
		printf("\n\t\t��ԤԼ���������޸ģ�������������ϼ���");
		return;
	}    
	rewind(fp);
	struct porder cos[99];
	int i,a,b;
	fread(cos,sizeof(struct porder),porder_num,fp);
	for(i=0,a=1;i<porder_num;i++,a++)
	printf("\n\t���:%d���:%ld   ����:%s    ����:%d   �ò�ʱ��:%s    Ԥ������:%d   �Ƿ���:%s\n",a,cos[i].s_num,cos[i].name,cos[i].num,cos[i].time,cos[i].table,cos[i].arrangred);
	fclose(fp);
	printf("\n\t\t������Ҫ�޸ĵ���Ϣ���:");
	scanf("%d",&b);
	if(b<1||b>=a)
	{error(); return;}
	system("cls");
	printf("\n\n\n\t\t�������µ����ݣ�\n\t\t���:");
	scanf("%ld",&cos[b-1].s_num) ;
	printf("\n\t\t����:");
	scanf("%s",cos[b-1].name);
	printf("\n\t\t������");
	scanf("%d",&cos[b-1].num);
	printf("\n\t\t�ò�ʱ��:");
	scanf("%s",cos[b-1].time) ;
	printf("\n\t\t����:");
	scanf("%d",&cos[b-1].table);
	printf("\n\t\t�Ƿ���:");
	scanf("%s",cos[b-1].arrangred);
	fp=fopen("porder_list","wb+");
	fwrite(&cos,sizeof(struct porder),porder_num,fp); 
	fclose(fp);
	system("cls");
	printf("\n\t\t�����ɹ����밴����������ϼ���");

}

void insert_porder()
{
	FILE *fp;
	int ch;
	if((fp=fopen("porder_list","rb+"))==NULL||((ch=fgetc(fp))==EOF))
	{
		printf("\n\t\t��ԤԼ���������޸ģ�������������ϼ���");
		return;
	}     
	rewind(fp);
	struct porder cos[99];
	int i,a,b;
	fread(cos,sizeof(struct porder),porder_num,fp);
	fclose(fp);
	for(i=0,a=1;i<porder_num;i++,a++)
	printf("\n\t\t���:%d���:%ld   ����:%s    ����:%d   �ò�ʱ��:%s    Ԥ������:%d   �Ƿ���:%s\n",a,cos[i].s_num,cos[i].name,cos[i].num,cos[i].time,cos[i].table,cos[i].arrangred);
	printf("\n\t\t������Ҫ�������Ϣ���:");
	scanf("%d",&b);
	if(b<1||b>=a)
	{error(); return;}
	for(i=porder_num-1;i>=b-1;i--)
	cos[i+1]=cos[i];
	system("cls");
	printf("\n\n\n\t\t����������Ҫ��������ݣ�\n\t\t���:");
	scanf("%ld",&cos[b-1].s_num) ;
	printf("\n\t\t����:");
	scanf("%s",cos[b-1].name);
	printf("\n\t\t������");
	scanf("%d",&cos[b-1].num);
	printf("\n\t\t�ò�ʱ��:");
	scanf("%s",cos[b-1].time) ;
	printf("\n\t\t����:");
	scanf("%d",&cos[b-1].table);
	printf("\n\t\t�Ƿ���:");
	scanf("%s",cos[b-1].arrangred);
	porder_num++;
	fp=fopen("porder_list","wb");
    fwrite(&cos,sizeof(struct porder),porder_num,fp);
	fclose(fp);
	system("cls");
	printf("\n\t\t�����ɹ����밴����������ϼ���");
}

void print_porder()
{
	FILE *fp;
	int ch;
	if((fp=fopen("porder_list","rb+"))==NULL||((ch=fgetc(fp))==EOF))
	{
		printf("\n\t\t��ԤԼ���������޸ģ�������������ϼ���");
		return;
	}    
	rewind(fp);
	struct porder cos[99];
	int i,a,b;
	fread(cos,sizeof(struct porder),porder_num,fp);
	for(i=0,a=1;i<porder_num;i++,a++)
	printf("\n\t���:%d���:%ld   ����:%s    ����:%d   �ò�ʱ��:%s    Ԥ������:%d   �Ƿ���:%s\n",a,cos[i].s_num,cos[i].name,cos[i].num,cos[i].time,cos[i].table,cos[i].arrangred);
    fclose(fp);	
	printf("\n\t\t�밴����������ϼ���");
}

void porder()
{
	printf("\n\n\n");
	int choose;
	while(1)
	{
		system("cls");
		printf("\n\n\t\t|-----------------------------|\n");
	    printf("\t\t|1.����ԤԼ                   |\n");
	    printf("\t\t|2.ȡ��ԤԼ                   |\n");
	    printf("\t\t|3.�޸�ԤԼ                   |\n");
	    printf("\t\t|4.����ԤԼ                   |\n");
	    printf("\t\t|5.��ʾ����ԤԼ               |\n");
	    printf("\t\t|0.�����ϼ��˵�               |");
	    printf("\n\t\t|-----------------------------|\n");
		scanf("%d",&choose);
		switch(choose)
		{
	    	case 1: system("cls"); input_porder();   break;
	        case 2: system("cls"); del_porder();  break;
            case 3: system("cls"); modify_porder();  break;
	     	case 4: system("cls"); insert_porder();     break;
	     	case 5: system("cls"); print_porder();     break;
	     	case 0: system("cls"); printf("\n\n\t\t�������������"); return;
	        default: system("cls"); printf("\n\n\n\n\n\t\t|\t\tѡ�����!������ѡ��\t\t|\n"); break;
	    }
	    getch();
	}
}

void input_order()
{
	struct order cos;
	FILE *fp;
	fp=fopen("order_list","ab+");
	printf("\n\n\n\t\t��������������:��ע:һ������ֻ��������һ�ֲ�Ʒ��һ���������������ͬ��������!\n\t\t����:");
	scanf("%d",&cos.table) ;
	printf("\n\t\t��Ʒ���:");
	scanf("%d",&cos.dish_num);
	printf("\n\t\t��Ʒ����:");
	scanf("%s",cos.dish_name);
	printf("\n\t\t����:");
	scanf("%d",&cos.price) ;
	printf("\n\t\t����:");
	scanf("%d",&cos.num);
	printf("\n\t\t�˿�����:");
	scanf("%s",cos.name);
	cos.pay=cos.price*cos.num;
	if( fwrite(&cos,sizeof(struct order),1,fp)!=1)
			 {
			   printf ("file write error\n");
			   fclose(fp);
			   printf("\n\n\n\t\t\t    �����������������һ���˵�\n");
			   return;}
	fclose(fp);
	system("cls");
	printf("\n\t\t�����ɹ����밴����������ϼ���");
	order_num++;
}

void del_order()
{
	FILE *fp;
	int ch;
	if((fp=fopen("order_list","rb+"))==NULL||((ch=fgetc(fp))==EOF))
	{
		printf("\n\t\t�޶������������޸ģ�������������ϼ���");
		return;
	}     
	rewind(fp);
	struct order cos[99];
	int i,a,b;
	fread(cos,sizeof(struct order),order_num,fp);
	fclose(fp);
	for(i=0,a=1;i<order_num;i++,a++)
	printf("\n\t\t���:%d����:%d   ��Ʒ���:%d    ��Ʒ����:%s   ����:%d    ����:%d   �˿�����:%s   ���:%d\n",a,cos[i].table,cos[i].dish_num,cos[i].dish_name,cos[i].price,cos[i].num,cos[i].name,cos[i].pay);
	printf("\n\t\t������Ҫɾ������Ϣ���:");
	scanf("%d",&b);
	if(b<1||b>=a)
	{error();return;	}
	for(i=b;i<order_num;i++)
	cos[i-1]=cos[i];
	order_num--;
	fp=fopen("order_list","wb");
	fwrite(&cos,sizeof(struct order),order_num,fp);
	fclose(fp);
	system("cls");
	printf("\n\t\t�����ɹ����밴����������ϼ���");
}

void modify_order()
{
	FILE *fp;
	int ch;
	if((fp=fopen("order_list","rb+"))==NULL||((ch=fgetc(fp))==EOF))
	{
		printf("\n\t\t�޶������������޸ģ�������������ϼ���");
		return;
	}    
	rewind(fp) ;
	struct order cos[99];
	int i,a,b;
	fread(cos,sizeof(struct order),order_num,fp);
	fclose(fp);
	for(i=0,a=1;i<order_num;i++,a++)
	printf("\n\t\t���:%d����:%d   ��Ʒ���:%d    ��Ʒ����:%s   ����:%d    ����:%d   �˿�����:%s   ���:%d\n",a,cos[i].table,cos[i].dish_num,cos[i].dish_name,cos[i].price,cos[i].num,cos[i].name,cos[i].pay);
	printf("\n\t\t������Ҫ�޸ĵ���Ϣ���:");
	scanf("%d",&b);
	if(b<1||b>=a)
	{error();return;	}
	system("cls");
	printf("\n\n\n\t\t�������µ����ݣ�\n\t\t����:");
	scanf("%d",&cos[b-1].table) ;
	printf("\n\t\t��Ʒ���:");
	scanf("%d",&cos[b-1].dish_num);
	printf("\n\t\t��Ʒ���ƣ�");
	scanf("%s",cos[b-1].dish_name);
	printf("\n\t\t����:");
	scanf("%d",&cos[b-1].price) ;
	printf("\n\t\t����:");
	scanf("%d",&cos[b-1].num);
	printf("\n\t\t�˿�����:");
	scanf("%s",cos[b-1].name);
	cos[b-1].pay=cos[b-1].price*cos[b-1].num;
	fp=fopen("order_list","wb+");
	fwrite(&cos,sizeof(struct order),order_num,fp);
	fclose(fp);
	system("cls");
	printf("\n\t\t�����ɹ����밴����������ϼ���");
}

void insert_order()
{
	FILE *fp;
	int ch;
	if((fp=fopen("order_list","rb+"))==NULL||((ch=fgetc(fp))==EOF))
	{
		printf("\n\t\t�޶������������޸ģ�������������ϼ���");
		return;
	}     
	rewind(fp);
	struct order cos[99];
	int i,a,b;
	fread(cos,sizeof(struct order),order_num,fp);
	fclose(fp);
	for(i=0,a=1;i<order_num;i++,a++)
	printf("\n\t\t���:%d����:%d   ��Ʒ���:%d    ��Ʒ����:%s   ����:%d    ����:%d   �˿�����:%s   ���:%d\n",a,cos[i].table,cos[i].dish_num,cos[i].dish_name,cos[i].price,cos[i].num,cos[i].name,cos[i].pay);
	printf("\n\t\t������Ҫ�޸ĵ���Ϣ���:");
	scanf("%d",&b);
	if(b<1||b>=a)
	{error();return;	}
	system("cls");
	for(i=order_num-1;i>=b-1;i--)
	cos[i+1]=cos[i];
	printf("\n\n\n\t\t�������µ����ݣ�\n\t\t����:");
	scanf("%d",&cos[b-1].table) ;
	printf("\n\t\t��Ʒ���:");
	scanf("%d",&cos[b-1].dish_num);
	printf("\n\t\t��Ʒ���ƣ�");
	scanf("%s",cos[b-1].dish_name);
	printf("\n\t\t����:");
	scanf("%d",&cos[b-1].price) ;
	printf("\n\t\t����:");
	scanf("%d",&cos[b-1].num);
	printf("\n\t\t�˿�����:");
	scanf("%s",cos[b-1].name);
	cos[b-1].pay=cos[b-1].price*cos[b-1].num;
	order_num++;
    fp=fopen("order_list","wb");
    fwrite(&cos,sizeof(struct order),order_num,fp);
	fclose(fp);
	system("cls");
	printf("\n\t\t�����ɹ����밴����������ϼ���");
} 

void print_order()
{
	FILE *fp;
	int ch;
	if((fp=fopen("order_list","rb+"))==NULL||((ch=fgetc(fp))==EOF))
	{
		printf("\n\t\t�޶������ݣ�������������ϼ���");
		return;
	}     
	rewind(fp);
	struct order cos[99];
	int i,a;
	fread(cos,sizeof(struct order),order_num,fp);
	fclose(fp);
	for(i=0,a=1;i<order_num;i++,a++)
	printf("\n\t\t���:%d����:%d   ��Ʒ���:%d    ��Ʒ����:%s   ����:%d    ����:%d   �˿�����:%s   ���:%d\n",a,cos[i].table,cos[i].dish_num,cos[i].dish_name,cos[i].price,cos[i].num,cos[i].name,cos[i].pay);	
	printf("\n\t\t�밴����������ϼ���");
}

void order()
{
	printf("\n\n\n");
	int choose;
	while(1)
	{
		system("cls");
		printf("\n\n\t\t|-----------------------------|\n");
	    printf("\t\t|1.�������                   |\n");
	    printf("\t\t|2.ȡ�����                   |\n");
	    printf("\t\t|3.�޸ĵ��                   |\n");
	    printf("\t\t|4.������                   |\n");
	    printf("\t\t|5.��ʾ���е��               |\n");
	    printf("\t\t|0.�����ϼ��˵�               |");
	    printf("\n\t\t|-----------------------------|\n");
		scanf("%d",&choose);
		switch(choose)
		{
	    	case 1: system("cls"); input_order();   break;
	        case 2: system("cls"); del_order();  break;
            case 3: system("cls"); modify_order();  break;
	     	case 4: system("cls"); insert_order();     break;
	     	case 5: system("cls"); print_order();     break;
	     	case 0: system("cls"); printf("\n\n\t\t�������������"); return;
	        default: system("cls"); printf("\n\n\n\n\n\t\t|\t\tѡ�����!������ѡ��\t\t|\n"); break;
	    }
	    getch();
	}
}

void print_pay()
{
	int num;
	printf("\n\n\t\t����Ҫ��ѯ�����ţ�");
	scanf("%d",&num);
	FILE *fp;
	int ch,i,a,sum=0;
	if((fp=fopen("order_list","rb+"))==NULL||((ch=fgetc(fp))==EOF))
	{
		printf("\n\t\t�޶������ݣ�������������ϼ���");
		return;
	}     
	rewind(fp);
	struct order cos[99];
	fread(cos,sizeof(struct order),order_num,fp);
	fclose(fp);
	system("cls");
	for(i=0,a=0;i<order_num;i++)
	{
		if(cos[i].table==num)
		{
			a++;sum+=cos[i].pay;
			printf("\n\t\t����:%d   ��Ʒ���:%d    ��Ʒ����:%s   ����:%d    ����:%d   �˿�����:%s   ���:%d\n",cos[i].table,cos[i].dish_num,cos[i].dish_name,cos[i].price,cos[i].num,cos[i].name,cos[i].pay);
		}
 	}	
	if(a==0) printf("\n\t\t������Ŀǰ���˾���");
	else printf("\n\t\t�ܼ�Ϊ:%d",sum);
	printf("\n\t\t�밴����������ϼ���");
}

void over_pay()
{
	printf("\n\n\t\t����Ҫ���˵����ţ�");
	int num;
	scanf("%d",&num);
	FILE *fp;
	int ch,i,j,a,sum=0,n;
	if((fp=fopen("order_list","rb+"))==NULL||((ch=fgetc(fp))==EOF))
	{
		printf("\n\t\t�޶������ݣ�������������ϼ���");
		return;
	}     
	rewind(fp);
	struct order cos[99];
	fread(cos,sizeof(struct order),order_num,fp);
	fclose(fp);
	n=order_num;
	for(i=0,a=0;i<n;i++)
	{
		if(cos[i].table==num)
		{
			a++;sum+=cos[i].pay;
			for(j=i;j<n-1;j++)
			cos[j]=cos[j+1];
			n--;
			i--;
		}
	}	
	if(a==0) {printf("\n\t\t������Ŀǰ���˾���");printf("\n\t\t�밴����������ϼ���");return;}
	else printf("\n\t\tӦ����%dԪ��",sum);
	while(1)
	{
	   printf("\n\t\t1:ȷ������   2:ȡ������\n");
	   scanf("%d",&num);
	   system("cls");
	   switch(num) 
    	{
		    case 1: system("cls"); fp=fopen("order_list","wb"); order_num=n; fwrite(&cos,sizeof(struct order),order_num,fp); fclose(fp); income+=sum; printf("\n\t\t�����ɹ�!"); printf("\n\t\t�밴����������ϼ���"); return;
	    	case 2: system("cls"); printf("\n\t\t��ȡ�����ˣ�"); printf("\n\t\t�밴����������ϼ���"); return;
	    	default: system("cls"); error(); break;
     	}
    }	
}

void pay()  
{
	printf("\n\n\n");
	int choose;
	while(1)
	{
		system("cls");
		printf("\n\n\t\t|-----------------------------|\n");
	    printf("\t\t|1.�鿴ĳһ�������е��       |\n");
	    printf("\t\t|2.����(��ɾ����ص��)       |\n");
	    printf("\t\t|0.�����ϼ��˵�               |");
	    printf("\n\t\t|-----------------------------|\n");
		scanf("%d",&choose);
		switch(choose)
		{
	    	case 1: system("cls"); print_pay();   break;
	        case 2: system("cls"); over_pay();  break;
	     	case 0: system("cls"); printf("\n\n\t\t�������������"); return;
	        default: system("cls"); printf("\n\n\n\n\n\t\t|\t\tѡ�����!������ѡ��\t\t|\n"); break;
	    }
	    getch();
	}
	
}

void print_income()
{
	printf("\n\t\t����������:%d",income);
	printf("\n\t\t�밴����������ϼ���");
}

void dish_count()
{
	FILE *fp;
	int ch;
	if((fp=fopen("order_list","rb+"))==NULL||((ch=fgetc(fp))==EOF))
	{
		printf("\n\t\t�����ݣ�������������ϼ���");
		return;
	}    
	rewind(fp) ;
	struct order cos[99];
	int i,a,b,count=0;
	fread(cos,sizeof(struct order),order_num,fp);
	fclose(fp);
	printf("\n\t\t�����Ʒ�ı��:");
	scanf("%d",&b);
	for(i=0;i<order_num;i++)
	{
		if(cos[i].dish_num==b)
		count+=cos[i].num;
	}
	printf("\n\t\t�ñ�ŵĲ�Ʒ������������Ϊ:%d",count);
	printf("\n\t\t�밴����������ϼ���");
}

void fun()
{
	printf("\n\n\n");
	int choose;
	while(1)
	{
		system("cls");
		printf("\n\n\t\t|-----------------------------|\n");
	    printf("\t\t|1.�鿴����������             |\n");
	    printf("\t\t|2.�鿴ĳ��Ʒ����������       |\n");
	    printf("\t\t|0.�����ϼ��˵�               |");
	    printf("\n\t\t|-----------------------------|\n");
		scanf("%d",&choose);
		switch(choose)
		{
	    	case 1: system("cls"); print_income();   break;
	        case 2: system("cls"); dish_count();  break;
	     	case 0: system("cls"); printf("\n\n\t\t�������������"); return;
	        default: system("cls"); printf("\n\n\n\n\n\t\t|\t\tѡ�����!������ѡ��\t\t|\n"); break;
	    }
	    getch();
	}
}

void main()
{
	FILE *data1,*data2;
	if((data1=fopen("data1","rb+"))==NULL)
	data1=fopen("data1","wb+");
	else fread(&porder_num,4,1,data1);
	if((data2=fopen("data2","rb+"))==NULL)
    data2=fopen("data2","wb+");
	else fread(&order_num,4,1,data2);
	fclose(data1);
    fclose(data2);
	int choose;
	welcome();
	while(1)
	{
			system("cls");
	        printf("\n\n\n");
	        printf("\t\t|--------------------------------------------------|\n");
	        printf("\t\t|\t\t   С�Ͳ͹ݹ���ϵͳ\t\t   |\n");
          	printf("\t\t|--------------------------------------------------|\n\n\n");
         	printf("\t\t|-----------------��ѡ�����ֽ��в���---------------|\n");
         	printf("\t\t|\t\t  1.Ԥ����Ϣ                       |\n");
         	printf("\t\t|\t\t  2.�����Ϣ                       |\n");
        	printf("\t\t|\t\t  3.��������                       |\n");
        	printf("\t\t|\t\t  4.����ͳ��                       |\n");
        	printf("\t\t|\t\t  0.�˳�ϵͳ                       |\n");
 	        printf("\t\t|-----------------��ѡ���Ӧ����0--4---------------|\n");
 	        printf("\t\t|-----------------�������˳���ϵͳ!----------------|\n");
            scanf("%d",&choose);
            switch(choose)
            {
	        	case 1:	system("cls"); porder();break;
	         	case 2: system("cls"); order();break;
	     		case 3: system("cls"); pay();break;
		        case 4: system("cls"); fun();break;
				case 0: system("cls"); data1=fopen("data1","wb+");
				                       data2=fopen("data2","wb+");
				                       fwrite(&porder_num,sizeof(int),1,data1);
                                       fwrite(&order_num,sizeof(int),1,data2);
	                                   fclose(data1);
                                       fclose(data2);
									   printf("\n\n\n\n\n\t|--------��лʹ�ã��ټ�!------|\t\n\n\n\n\n");	exit(0);
	         	default:system("cls"); printf("\n\n\n\n\n\t\t|\t\tѡ�����!������ѡ��\t\t|\n");break;
	     	}
		getch();     
	}
}
