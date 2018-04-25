#include<stdio.h>
#include<stdlib.h> 
#include<windows.h> 
#include<conio.h>
int porder_num=0;
int order_num=0;
int income=0;

struct order/*点餐的结构体*/ 
{
	int table;/*桌号*/ 
	int dish_num;/*菜品编号*/ 
	char dish_name[200];/*菜品名称*/ 
	int price;/*单价*/ 
	int num;/*数量*/ 
	char name[20];/*顾客姓名*/ 
	int pay;/* 金额*/ 
};

struct porder/*电话订餐的结构体*/ 
{
		long int s_num;/*编号*/ 
     	char name[20];/*姓名*/ 
	    int num;/*人数*/ 
	    char time[15];/*用餐时间*/ 
	    int table;/*桌号*/ 
	    char arrangred[5];/*是否安排*/ 
};

void error()
{
	printf("\n\n\n\n\n\t\t|\t\t选择错误!请重新选择\t\t|\n");
	printf("\n\n\n\t\t\t    请输入任意键返回上一级菜单\n");
}

void welcome()
{
	int i,j,t;
	for(i=0;i<7;i++)
	{
	   printf("\t************************************************************\n\n\n");
	   printf("\n\t\t★★★★★★★欢迎进入小型餐馆管理系统★★★★★★\n\n"); 
	   printf("\n\n\t************************************************************\n");
	   printf("\n\n\n\t\t\t请输入任意键进入\n");
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
    printf("\n\n\n\t\t请输入以下数据：\n\t\t编号:");
	scanf("%ld",&cos.s_num) ;
	printf("\n\t\t姓名:");
	scanf("%s",cos.name);
	printf("\n\t\t人数：");
	scanf("%d",&cos.num);
	printf("\n\t\t用餐时间:");
	scanf("%s",cos.time) ;
	printf("\n\t\t桌号:");
	scanf("%d",&cos.table);
	printf("\n\t\t是否安排:");
	scanf("%s",cos.arrangred);
    if( fwrite(&cos,sizeof(struct porder),1,fp)!=1)
			 {
			   printf ("file write error\n");
			   fclose(fp);
			   printf("\n\n\n\t\t\t    请输入任意键返回上一级菜单\n");
			   return;}
	fclose(fp);
	system("cls");
	printf("\n\t\t操作成功！请按任意键返回上级。");
	porder_num++;

}

void del_porder()
{
	FILE *fp;
	int ch;
	if((fp=fopen("porder_list","rb+"))==NULL||((ch=fgetc(fp))==EOF))
	{
		printf("\n\t\t无预约数据无需修改，按任意键返回上级。");
		return;
	}
	rewind(fp);     
	struct porder cos[99];
	int i,a,b;
	fread(cos,sizeof(struct porder),porder_num,fp);
	fclose(fp);
	for(i=0,a=1;i<porder_num;i++,a++)
	printf("\n\t\t标号:%d编号:%ld   姓名:%s    人数:%d   用餐时间:%s    预定桌号:%d   是否安排:%s\n",a,cos[i].s_num,cos[i].name,cos[i].num,cos[i].time,cos[i].table,cos[i].arrangred);
	printf("\n\t\t输入你要删除的信息标号:");
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
	printf("\n\t\t操作成功！请按任意键返回上级。");

}

void modify_porder()
{
	FILE *fp;
	int ch;
	if((fp=fopen("porder_list","rb+"))==NULL||((ch=fgetc(fp))==EOF))
	{
		printf("\n\t\t无预约数据无需修改，按任意键返回上级。");
		return;
	}    
	rewind(fp);
	struct porder cos[99];
	int i,a,b;
	fread(cos,sizeof(struct porder),porder_num,fp);
	for(i=0,a=1;i<porder_num;i++,a++)
	printf("\n\t标号:%d编号:%ld   姓名:%s    人数:%d   用餐时间:%s    预定桌号:%d   是否安排:%s\n",a,cos[i].s_num,cos[i].name,cos[i].num,cos[i].time,cos[i].table,cos[i].arrangred);
	fclose(fp);
	printf("\n\t\t输入你要修改的信息标号:");
	scanf("%d",&b);
	if(b<1||b>=a)
	{error(); return;}
	system("cls");
	printf("\n\n\n\t\t请输入新的数据：\n\t\t编号:");
	scanf("%ld",&cos[b-1].s_num) ;
	printf("\n\t\t姓名:");
	scanf("%s",cos[b-1].name);
	printf("\n\t\t人数：");
	scanf("%d",&cos[b-1].num);
	printf("\n\t\t用餐时间:");
	scanf("%s",cos[b-1].time) ;
	printf("\n\t\t桌号:");
	scanf("%d",&cos[b-1].table);
	printf("\n\t\t是否安排:");
	scanf("%s",cos[b-1].arrangred);
	fp=fopen("porder_list","wb+");
	fwrite(&cos,sizeof(struct porder),porder_num,fp); 
	fclose(fp);
	system("cls");
	printf("\n\t\t操作成功！请按任意键返回上级。");

}

void insert_porder()
{
	FILE *fp;
	int ch;
	if((fp=fopen("porder_list","rb+"))==NULL||((ch=fgetc(fp))==EOF))
	{
		printf("\n\t\t无预约数据无需修改，按任意键返回上级。");
		return;
	}     
	rewind(fp);
	struct porder cos[99];
	int i,a,b;
	fread(cos,sizeof(struct porder),porder_num,fp);
	fclose(fp);
	for(i=0,a=1;i<porder_num;i++,a++)
	printf("\n\t\t标号:%d编号:%ld   姓名:%s    人数:%d   用餐时间:%s    预定桌号:%d   是否安排:%s\n",a,cos[i].s_num,cos[i].name,cos[i].num,cos[i].time,cos[i].table,cos[i].arrangred);
	printf("\n\t\t输入你要插入的信息标号:");
	scanf("%d",&b);
	if(b<1||b>=a)
	{error(); return;}
	for(i=porder_num-1;i>=b-1;i--)
	cos[i+1]=cos[i];
	system("cls");
	printf("\n\n\n\t\t请输入以下要插入的数据：\n\t\t编号:");
	scanf("%ld",&cos[b-1].s_num) ;
	printf("\n\t\t姓名:");
	scanf("%s",cos[b-1].name);
	printf("\n\t\t人数：");
	scanf("%d",&cos[b-1].num);
	printf("\n\t\t用餐时间:");
	scanf("%s",cos[b-1].time) ;
	printf("\n\t\t桌号:");
	scanf("%d",&cos[b-1].table);
	printf("\n\t\t是否安排:");
	scanf("%s",cos[b-1].arrangred);
	porder_num++;
	fp=fopen("porder_list","wb");
    fwrite(&cos,sizeof(struct porder),porder_num,fp);
	fclose(fp);
	system("cls");
	printf("\n\t\t操作成功！请按任意键返回上级。");
}

void print_porder()
{
	FILE *fp;
	int ch;
	if((fp=fopen("porder_list","rb+"))==NULL||((ch=fgetc(fp))==EOF))
	{
		printf("\n\t\t无预约数据无需修改，按任意键返回上级。");
		return;
	}    
	rewind(fp);
	struct porder cos[99];
	int i,a,b;
	fread(cos,sizeof(struct porder),porder_num,fp);
	for(i=0,a=1;i<porder_num;i++,a++)
	printf("\n\t标号:%d编号:%ld   姓名:%s    人数:%d   用餐时间:%s    预定桌号:%d   是否安排:%s\n",a,cos[i].s_num,cos[i].name,cos[i].num,cos[i].time,cos[i].table,cos[i].arrangred);
    fclose(fp);	
	printf("\n\t\t请按任意键返回上级。");
}

void porder()
{
	printf("\n\n\n");
	int choose;
	while(1)
	{
		system("cls");
		printf("\n\n\t\t|-----------------------------|\n");
	    printf("\t\t|1.新增预约                   |\n");
	    printf("\t\t|2.取消预约                   |\n");
	    printf("\t\t|3.修改预约                   |\n");
	    printf("\t\t|4.插入预约                   |\n");
	    printf("\t\t|5.显示所有预约               |\n");
	    printf("\t\t|0.返回上级菜单               |");
	    printf("\n\t\t|-----------------------------|\n");
		scanf("%d",&choose);
		switch(choose)
		{
	    	case 1: system("cls"); input_porder();   break;
	        case 2: system("cls"); del_porder();  break;
            case 3: system("cls"); modify_porder();  break;
	     	case 4: system("cls"); insert_porder();     break;
	     	case 5: system("cls"); print_porder();     break;
	     	case 0: system("cls"); printf("\n\n\t\t按任意键继续。"); return;
	        default: system("cls"); printf("\n\n\n\n\n\t\t|\t\t选择错误!请重新选择\t\t|\n"); break;
	    }
	    getch();
	}
}

void input_order()
{
	struct order cos;
	FILE *fp;
	fp=fopen("order_list","ab+");
	printf("\n\n\n\t\t请输入以下数据:（注:一组数据只允许输入一种菜品，一桌多菜请逐组以相同桌号输入!\n\t\t桌号:");
	scanf("%d",&cos.table) ;
	printf("\n\t\t菜品编号:");
	scanf("%d",&cos.dish_num);
	printf("\n\t\t菜品名称:");
	scanf("%s",cos.dish_name);
	printf("\n\t\t单价:");
	scanf("%d",&cos.price) ;
	printf("\n\t\t数量:");
	scanf("%d",&cos.num);
	printf("\n\t\t顾客姓名:");
	scanf("%s",cos.name);
	cos.pay=cos.price*cos.num;
	if( fwrite(&cos,sizeof(struct order),1,fp)!=1)
			 {
			   printf ("file write error\n");
			   fclose(fp);
			   printf("\n\n\n\t\t\t    请输入任意键返回上一级菜单\n");
			   return;}
	fclose(fp);
	system("cls");
	printf("\n\t\t操作成功！请按任意键返回上级。");
	order_num++;
}

void del_order()
{
	FILE *fp;
	int ch;
	if((fp=fopen("order_list","rb+"))==NULL||((ch=fgetc(fp))==EOF))
	{
		printf("\n\t\t无订单数据无需修改，按任意键返回上级。");
		return;
	}     
	rewind(fp);
	struct order cos[99];
	int i,a,b;
	fread(cos,sizeof(struct order),order_num,fp);
	fclose(fp);
	for(i=0,a=1;i<order_num;i++,a++)
	printf("\n\t\t标号:%d桌号:%d   菜品编号:%d    菜品名称:%s   单价:%d    数量:%d   顾客姓名:%s   金额:%d\n",a,cos[i].table,cos[i].dish_num,cos[i].dish_name,cos[i].price,cos[i].num,cos[i].name,cos[i].pay);
	printf("\n\t\t输入你要删除的信息标号:");
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
	printf("\n\t\t操作成功！请按任意键返回上级。");
}

void modify_order()
{
	FILE *fp;
	int ch;
	if((fp=fopen("order_list","rb+"))==NULL||((ch=fgetc(fp))==EOF))
	{
		printf("\n\t\t无订单数据无需修改，按任意键返回上级。");
		return;
	}    
	rewind(fp) ;
	struct order cos[99];
	int i,a,b;
	fread(cos,sizeof(struct order),order_num,fp);
	fclose(fp);
	for(i=0,a=1;i<order_num;i++,a++)
	printf("\n\t\t标号:%d桌号:%d   菜品编号:%d    菜品名称:%s   单价:%d    数量:%d   顾客姓名:%s   金额:%d\n",a,cos[i].table,cos[i].dish_num,cos[i].dish_name,cos[i].price,cos[i].num,cos[i].name,cos[i].pay);
	printf("\n\t\t输入你要修改的信息标号:");
	scanf("%d",&b);
	if(b<1||b>=a)
	{error();return;	}
	system("cls");
	printf("\n\n\n\t\t请输入新的数据：\n\t\t桌号:");
	scanf("%d",&cos[b-1].table) ;
	printf("\n\t\t菜品编号:");
	scanf("%d",&cos[b-1].dish_num);
	printf("\n\t\t菜品名称：");
	scanf("%s",cos[b-1].dish_name);
	printf("\n\t\t单价:");
	scanf("%d",&cos[b-1].price) ;
	printf("\n\t\t数量:");
	scanf("%d",&cos[b-1].num);
	printf("\n\t\t顾客姓名:");
	scanf("%s",cos[b-1].name);
	cos[b-1].pay=cos[b-1].price*cos[b-1].num;
	fp=fopen("order_list","wb+");
	fwrite(&cos,sizeof(struct order),order_num,fp);
	fclose(fp);
	system("cls");
	printf("\n\t\t操作成功！请按任意键返回上级。");
}

void insert_order()
{
	FILE *fp;
	int ch;
	if((fp=fopen("order_list","rb+"))==NULL||((ch=fgetc(fp))==EOF))
	{
		printf("\n\t\t无订单数据无需修改，按任意键返回上级。");
		return;
	}     
	rewind(fp);
	struct order cos[99];
	int i,a,b;
	fread(cos,sizeof(struct order),order_num,fp);
	fclose(fp);
	for(i=0,a=1;i<order_num;i++,a++)
	printf("\n\t\t标号:%d桌号:%d   菜品编号:%d    菜品名称:%s   单价:%d    数量:%d   顾客姓名:%s   金额:%d\n",a,cos[i].table,cos[i].dish_num,cos[i].dish_name,cos[i].price,cos[i].num,cos[i].name,cos[i].pay);
	printf("\n\t\t输入你要修改的信息标号:");
	scanf("%d",&b);
	if(b<1||b>=a)
	{error();return;	}
	system("cls");
	for(i=order_num-1;i>=b-1;i--)
	cos[i+1]=cos[i];
	printf("\n\n\n\t\t请输入新的数据：\n\t\t桌号:");
	scanf("%d",&cos[b-1].table) ;
	printf("\n\t\t菜品编号:");
	scanf("%d",&cos[b-1].dish_num);
	printf("\n\t\t菜品名称：");
	scanf("%s",cos[b-1].dish_name);
	printf("\n\t\t单价:");
	scanf("%d",&cos[b-1].price) ;
	printf("\n\t\t数量:");
	scanf("%d",&cos[b-1].num);
	printf("\n\t\t顾客姓名:");
	scanf("%s",cos[b-1].name);
	cos[b-1].pay=cos[b-1].price*cos[b-1].num;
	order_num++;
    fp=fopen("order_list","wb");
    fwrite(&cos,sizeof(struct order),order_num,fp);
	fclose(fp);
	system("cls");
	printf("\n\t\t操作成功！请按任意键返回上级。");
} 

void print_order()
{
	FILE *fp;
	int ch;
	if((fp=fopen("order_list","rb+"))==NULL||((ch=fgetc(fp))==EOF))
	{
		printf("\n\t\t无订单数据，按任意键返回上级。");
		return;
	}     
	rewind(fp);
	struct order cos[99];
	int i,a;
	fread(cos,sizeof(struct order),order_num,fp);
	fclose(fp);
	for(i=0,a=1;i<order_num;i++,a++)
	printf("\n\t\t标号:%d桌号:%d   菜品编号:%d    菜品名称:%s   单价:%d    数量:%d   顾客姓名:%s   金额:%d\n",a,cos[i].table,cos[i].dish_num,cos[i].dish_name,cos[i].price,cos[i].num,cos[i].name,cos[i].pay);	
	printf("\n\t\t请按任意键返回上级。");
}

void order()
{
	printf("\n\n\n");
	int choose;
	while(1)
	{
		system("cls");
		printf("\n\n\t\t|-----------------------------|\n");
	    printf("\t\t|1.新增点餐                   |\n");
	    printf("\t\t|2.取消点餐                   |\n");
	    printf("\t\t|3.修改点餐                   |\n");
	    printf("\t\t|4.插入点餐                   |\n");
	    printf("\t\t|5.显示所有点餐               |\n");
	    printf("\t\t|0.返回上级菜单               |");
	    printf("\n\t\t|-----------------------------|\n");
		scanf("%d",&choose);
		switch(choose)
		{
	    	case 1: system("cls"); input_order();   break;
	        case 2: system("cls"); del_order();  break;
            case 3: system("cls"); modify_order();  break;
	     	case 4: system("cls"); insert_order();     break;
	     	case 5: system("cls"); print_order();     break;
	     	case 0: system("cls"); printf("\n\n\t\t按任意键继续。"); return;
	        default: system("cls"); printf("\n\n\n\n\n\t\t|\t\t选择错误!请重新选择\t\t|\n"); break;
	    }
	    getch();
	}
}

void print_pay()
{
	int num;
	printf("\n\n\t\t输入要查询的桌号：");
	scanf("%d",&num);
	FILE *fp;
	int ch,i,a,sum=0;
	if((fp=fopen("order_list","rb+"))==NULL||((ch=fgetc(fp))==EOF))
	{
		printf("\n\t\t无订单数据，按任意键返回上级。");
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
			printf("\n\t\t桌号:%d   菜品编号:%d    菜品名称:%s   单价:%d    数量:%d   顾客姓名:%s   金额:%d\n",cos[i].table,cos[i].dish_num,cos[i].dish_name,cos[i].price,cos[i].num,cos[i].name,cos[i].pay);
		}
 	}	
	if(a==0) printf("\n\t\t该桌号目前无人就坐");
	else printf("\n\t\t总价为:%d",sum);
	printf("\n\t\t请按任意键返回上级。");
}

void over_pay()
{
	printf("\n\n\t\t输入要结账的桌号：");
	int num;
	scanf("%d",&num);
	FILE *fp;
	int ch,i,j,a,sum=0,n;
	if((fp=fopen("order_list","rb+"))==NULL||((ch=fgetc(fp))==EOF))
	{
		printf("\n\t\t无订单数据，按任意键返回上级。");
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
	if(a==0) {printf("\n\t\t该桌号目前无人就坐");printf("\n\t\t请按任意键返回上级。");return;}
	else printf("\n\t\t应收银%d元。",sum);
	while(1)
	{
	   printf("\n\t\t1:确认收银   2:取消收银\n");
	   scanf("%d",&num);
	   system("cls");
	   switch(num) 
    	{
		    case 1: system("cls"); fp=fopen("order_list","wb"); order_num=n; fwrite(&cos,sizeof(struct order),order_num,fp); fclose(fp); income+=sum; printf("\n\t\t操作成功!"); printf("\n\t\t请按任意键返回上级。"); return;
	    	case 2: system("cls"); printf("\n\t\t已取消结账！"); printf("\n\t\t请按任意键返回上级。"); return;
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
	    printf("\t\t|1.查看某一桌的所有点餐       |\n");
	    printf("\t\t|2.结账(将删除相关点餐)       |\n");
	    printf("\t\t|0.返回上级菜单               |");
	    printf("\n\t\t|-----------------------------|\n");
		scanf("%d",&choose);
		switch(choose)
		{
	    	case 1: system("cls"); print_pay();   break;
	        case 2: system("cls"); over_pay();  break;
	     	case 0: system("cls"); printf("\n\n\t\t按任意键继续。"); return;
	        default: system("cls"); printf("\n\n\n\n\n\t\t|\t\t选择错误!请重新选择\t\t|\n"); break;
	    }
	    getch();
	}
	
}

void print_income()
{
	printf("\n\t\t今日收银额:%d",income);
	printf("\n\t\t请按任意键返回上级。");
}

void dish_count()
{
	FILE *fp;
	int ch;
	if((fp=fopen("order_list","rb+"))==NULL||((ch=fgetc(fp))==EOF))
	{
		printf("\n\t\t无数据，按任意键返回上级。");
		return;
	}    
	rewind(fp) ;
	struct order cos[99];
	int i,a,b,count=0;
	fread(cos,sizeof(struct order),order_num,fp);
	fclose(fp);
	printf("\n\t\t输入菜品的编号:");
	scanf("%d",&b);
	for(i=0;i<order_num;i++)
	{
		if(cos[i].dish_num==b)
		count+=cos[i].num;
	}
	printf("\n\t\t该编号的菜品今日销售数量为:%d",count);
	printf("\n\t\t请按任意键返回上级。");
}

void fun()
{
	printf("\n\n\n");
	int choose;
	while(1)
	{
		system("cls");
		printf("\n\n\t\t|-----------------------------|\n");
	    printf("\t\t|1.查看今日总收银             |\n");
	    printf("\t\t|2.查看某菜品今日销售量       |\n");
	    printf("\t\t|0.返回上级菜单               |");
	    printf("\n\t\t|-----------------------------|\n");
		scanf("%d",&choose);
		switch(choose)
		{
	    	case 1: system("cls"); print_income();   break;
	        case 2: system("cls"); dish_count();  break;
	     	case 0: system("cls"); printf("\n\n\t\t按任意键继续。"); return;
	        default: system("cls"); printf("\n\n\n\n\n\t\t|\t\t选择错误!请重新选择\t\t|\n"); break;
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
	        printf("\t\t|\t\t   小型餐馆管理系统\t\t   |\n");
          	printf("\t\t|--------------------------------------------------|\n\n\n");
         	printf("\t\t|-----------------请选择数字进行操作---------------|\n");
         	printf("\t\t|\t\t  1.预定信息                       |\n");
         	printf("\t\t|\t\t  2.点餐信息                       |\n");
        	printf("\t\t|\t\t  3.收银结账                       |\n");
        	printf("\t\t|\t\t  4.销售统计                       |\n");
        	printf("\t\t|\t\t  0.退出系统                       |\n");
 	        printf("\t\t|-----------------请选择对应数字0--4---------------|\n");
 	        printf("\t\t|-----------------请正常退出本系统!----------------|\n");
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
									   printf("\n\n\n\n\n\t|--------感谢使用，再见!------|\t\n\n\n\n\n");	exit(0);
	         	default:system("cls"); printf("\n\n\n\n\n\t\t|\t\t选择错误!请重新选择\t\t|\n");break;
	     	}
		getch();     
	}
}
