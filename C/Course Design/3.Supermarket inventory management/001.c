//超市库存管理系统
//班级：软件1501
//学号：151303128
//姓名：王子杰
//指导老师：邹姝稚

# include <stdio.h>
# include <windows.h>
# include <stdlib.h>
# include <conio.h> 
# include <string.h>
# define LIM 100
# define DATE 20
# define NUMBER 100 //商品个数//
void menu(); //主菜单//
void findmenu(); // 查询菜单//
void welcome(); //欢迎界面//
void error(); // 报告错误函数//
void Append();//添加商品 函数 // 
void Findin(); //按编号查询函数//
void find();//查询函数// 
void Browse();//浏览函数//
void Amend();//修改函数//
void Del();//删除函数//
void NmFindin();//按照名称查询//
void Arrange();//排序菜单函数//
void saleparrange();//零售价排序//
void stockarrange();//按照进货量排序//
void numberarrange();//库存量排序//
void Alarm();//库存信息预警系统//
void showlimup();//显示临近库存上限商品//
void showlimdown();//显示临近库存下限商品//
void showdate();//显示即将过期商品//
void colorsetting(); //系统颜色设定//
void Update();//物品信息更新//

struct ima
{
	int id;  //商品货号
	char name[20];//名称
	char kind[20];//类别
	int number;//总量
	int limup;//库存上限
	int limdown;//库存下限
	float stockp;//进货价格
	float salep;//零售价格
	long int stockdate;//进货日期
	int stocknum;//进货量
	long int producedate;//生产日期
	char producename[20];//生产厂家
	int guaranteedate;//保质期
};


void welcome() //欢迎界面// 
{
	int i,j;
	for(i=0;i<7;i++)
	{
	   printf("\t   ************************************************************\n\n\n");
	   printf("\n\t         ★★★★★★欢迎进入超市库存管理系统★★★★★★\n\n"); 
	   printf("\n\n\t   ************************************************************\n");
	   printf("\n\t\t\t\t\t\t请输入任意键进入......\n");
	   Sleep(222);
	   	if(i!=6) 
			system("cls");
			
		for(j=0;j<i;j++) 
			printf("\n");

	}
    getch();
	
}

void error() // 选择错误函数// 
{
	system("cls");
	printf("\n\n\n\n\n\t\t|\t\t选择错误!请重新选择\t\t|\n");
	printf("\n\n\n\t\t\t    请输入任意键退出\n");
} 

int evaluateID(int id) //判断商品编号是否重复  函数//
{
	struct ima i;
	FILE * fp;
	fp=fopen("ima.date","r");
	if(fp==NULL)
	{
		printf("\t\t\t 系统错误，请你重试......");
		exit(0); 
	}
	fread(&i,sizeof(struct ima),1,fp);
	
	while(!feof(fp))
	{
		if(i.id==id)
		{
			fclose(fp);
			return 1;
			break;
		}
		fread(&i,sizeof(struct ima),1,fp); 
	}
	fclose(fp);
	return 0;
} 
void Append() //添加商品  函数 // 
{       struct ima i;
	    char choice;
		FILE *fp;
		fp=fopen("ima.date","ab");
		if(fp==NULL)
		{
			printf("\t\t\t系统错误，请您重试........");
			exit(0);
		}
		
	  ID:
		printf("\n\t\t\t请您输入要入库物品的信息...\n");
		printf("\t\t\t   物品的编号:");
		scanf("%d",&i.id);
		if(evaluateID(i.id)==1)
		{
			printf("\t\t\t\t此编号已被使用，请您重新输入......");
			goto ID;
		}
	    printf("\t\t\t   商品的名称：");
	    scanf("%s",i.name); 
	    printf("\t\t\t   商品的类别：");
	    scanf("%s",i.kind); 
	    printf("\t\t\t   商品的总量：");
	    scanf("%d",&i.number); 
	    printf("\t\t\t   商品的库存上限：");
	    scanf("%d",&i.limup); 
	    printf("\t\t\t   商品的库存下限：");
	    scanf("%d",&i.limdown); 
	    printf("\t\t\t   商品的进货价格：");
	    scanf("%f",&i.stockp);
	    printf("\t\t\t   商品的出售价格：");
	    scanf("%f",&i.salep);  
	    printf("\t\t\t   商品的进货日期（例如19970706）：");
	    scanf("%ld",&i.stockdate); 
	    printf("\t\t\t   商品的进货量：");
	    scanf("%d",&i.stocknum); 
	    printf("\t\t\t   商品的生产日期：");
	    scanf("%ld",&i.producedate); 
	    printf("\t\t\t   商品的厂家：");
	    scanf("%s",i.producename); 
	    printf("\t\t\t   商品的保质期：");
	    scanf("%d",&i.guaranteedate); 
		fwrite(&i,sizeof(struct ima),1,fp);
		fclose(fp);
		printf("\t\t\t\t\t\t  物品信息已入库成功!!!\n");
		
		printf("\n您想继续吗?(y/n)");
		scanf(" %c",&choice);
		if(choice=='Y'||choice=='y')
		{
			Append();
		}
		else
		{
			system("cls");
			menu();
		}
}
void Del()//删除函数//
{
	FILE * fp;
	int delID,count=0,j=0;
	char choice;
	struct ima temp;
	struct ima i[NUMBER];
	fp=fopen("ima.date","r");
    
	if (fp==NULL)
	{
		printf("\t\t\t系统错误，请你重试......");
		exit(0);
	}
	
	fread(&temp,sizeof(struct ima),1,fp);
	while(!feof(fp))
	{
		i[count]=temp;
		count++;
        fread(&temp,sizeof(struct ima),1,fp);
	}fclose(fp);
	
	printf("\n\t请你输入您要删除商品的编号......");
	scanf("%d",&delID);
	fp=fopen("ima.date","wb");
	if(fp==NULL)
	{
		printf("\t\t\t 系统错误，请您重新输入......");
		exit(0);
	}

	for(j=0;j<count;j++)
	{
		if(i[j].id!=delID)
			fwrite(&i[j],sizeof(struct ima),1,fp);
	}fclose(fp);
	printf("\t\t\t该商品已删除！！！\n");
	printf("\n您想继续吗?(y/n)");
		
	scanf(" %c",&choice);
	if(choice=='Y'||choice=='y')
	{
	    Del();
	}
	else
	{
		system("cls");
		menu();
	}



}
void Amend()
{
	FILE * fp;
	int amendID ,count=0,j;
	char choice;
	struct ima i[NUMBER];
	struct ima temp;
    
	fp=fopen("ima.date","r");
	if(fp==NULL)
	{	
		printf("\t\t\t 系统错误，请您重试......");
        exit(0);
	}
    // 将数据文件内容读入结构数组struct ima i中// 
	fread(&temp,sizeof(struct ima),1,fp);
	while(!feof(fp))
	{
		i[count]=temp;
		count++;
		fread(&temp,sizeof(struct ima),1,fp);
	}fclose(fp);     
    
	//将修改后的数据写入//
	fp=fopen("ima.date","w");
    if(fp==NULL)
	{
		printf("\t\t\t  系统错误，请您重试......");
		exit(0);
	}
    
	printf("\n\t 请您输入需要修改的商品编号......");
	scanf("%d",&amendID);
	for(j=0 ; j<=count-1 ;j++)
	{
		if(i[j].id!=amendID)
		{
			fwrite(&i[j],sizeof(struct ima),1,fp);
		}
		else
		{   
			printf("\t\t   请输入您要修改的信息......\n");
			printf("\t\t   商品的名称：");
	        scanf("%s",i[j].name); 
	        printf("\t\t   商品的类别：");
	        scanf("%s",i[j].kind); 
	        printf("\t\t   商品的总量：");
	        scanf("%d",&i[j].number); 
	        printf("\t\t   商品的库存上限：");
	        scanf("%d",&i[j].limup); 
	        printf("\t\t   商品的库存下限：");
	        scanf("%d",&i[j].limdown); 
	        printf("\t\t   商品的进货价格：");
	        scanf("%f",&i[j].stockp);
	        printf("\t\t   商品的出售价格：");
	        scanf("%f",&i[j].salep);  
	        printf("\t\t   商品的进货日期（例如19970706）：");
	        scanf("%ld",&i[j].stockdate); 
	        printf("\t\t   商品的进货量：");
	        scanf("%d",&i[j].stocknum); 
 	        printf("\t\t   商品的厂家：");
     	    scanf("%s",i[j].producename); 
    	    printf("\t\t   商品的保质期：");
	        scanf("%d",&i[j].guaranteedate); 
			fwrite(&i[j],sizeof(struct ima),1,fp);
		
		}
	}fclose(fp);
		  
	      printf("\t\t\t物品信息已修改......");
	      printf("\n您想继续吗?(y/n)");
		  scanf(" %c",&choice);
		  if(choice=='Y'||choice=='y')
			{
			  Amend();
			}
		  else
		   {
			  system("cls");
		   	  menu();
			}
	   
}
void Findin()  //按编号查询函数//
{ 
	
		FILE *fp;
		int findID;char choice;struct ima i;
		fp=fopen("ima.date","r");
		if(fp==NULL)
		{		
			printf("\t\t\t系统错误，请你重试........");
			exit(0);
		}
      	printf("\n\t请输入要查询的物品的编号(输入-1退出)......");
		scanf("%d",&findID);
		if(findID==-1) findmenu();
		
		fread(&i,sizeof(struct ima),1,fp);
		
		while(!feof(fp))
		{  
			if(i.id==findID)
			{   
			   printf("\n\t   商品的名称：%s\n",i.name);
	           printf("\t   商品的类别：%s\n",i.kind);
	           printf("\t   商品的总量：%d\n",i.number);
	           printf("\t   商品的库存上限：%d\n",i.limup);
	           printf("\t   商品的库存下限：%d\n",i.limdown);
	           printf("\t   商品的进货价格：%.2f\n",i.stockp);
	           printf("\t   商品的出售价格：%.2f\n",i.salep);
	           printf("\t   商品的进货日期（例如19970706）：%d\n",i.stockdate);
	           printf("\t   商品的进货量：%d\n",i.stocknum);
	           printf("\t   商品的生产日期：%d\n",i.producedate);
	           printf("\t   商品的厂家：%s\n",i.producename);
	           printf("\t   商品的保质期：%d\n",i.producedate);
			   printf("是否继续？（y/n）");
			   scanf(" %c",&choice);
				if(choice=='Y'||choice=='y')
				{
					Findin();
				}
				else
				{
					system("cls");
					findmenu();
				}
			}
			fread(&i,sizeof(struct ima),1,fp);
		}
		   fclose(fp);
		   printf("\t\t\t\t\t输入的编号不存在，请您重新输入......");
           Findin();
}

void NmFindin()  //按名称查询函数//
{ 
	
		FILE *fp;
		char find[20];char choice;struct ima i;char s1[5]="exit";
		fp=fopen("ima.date","r");
		if(fp==NULL)
		{		
			printf("\t\t\t系统错误，请你重试........");
			exit(0);
		}
      	printf("\n\t请输入要查询的物品的名称(输入exit退出)......");
		scanf("%s",find);
        if(strcmp(find,s1)==0)  findmenu();
		
		fread(&i,sizeof(struct ima),1,fp);
		
		while(!feof(fp))
		{  
			if(strcmp(find,i.name)==0)
			{   
			   printf("\n\t   商品的名称：%s\n",i.name);
	           printf("\t   商品的类别：%s\n",i.kind);
	           printf("\t   商品的总量：%d\n",i.number);
	           printf("\t   商品的库存上限：%d\n",i.limup);
	           printf("\t   商品的库存下限：%d\n",i.limdown);
	           printf("\t   商品的进货价格：%.2f\n",i.stockp);
	           printf("\t   商品的出售价格：%.2f\n",i.salep);
	           printf("\t   商品的进货日期（例如19970706）：%d\n",i.stockdate);
	           printf("\t   商品的进货量：%d\n",i.stocknum);
	           printf("\t   商品的生产日期：%d\n",i.producedate);
	           printf("\t   商品的厂家：%s\n",i.producename);
	           printf("\t   商品的保质期：%d\n",i.producedate);
			   printf("是否继续？（y/n）");
			   scanf(" %c",&choice);
				if(choice=='Y'||choice=='y')
				{
					NmFindin();
				}
				else
				{
					system("cls");
					findmenu();
				}
			}
			fread(&i,sizeof(struct ima),1,fp);
		}
		   fclose(fp);
		   printf("\t\t\t\t\t输入的名称不存在，请您重新输入......");
           NmFindin();
}


void Browse() //浏览函数//
{ 
	struct ima i;
	char choice; FILE * fp;
	int count=0;
	fp=fopen("ima.date","r");
	fread(&i,sizeof(struct ima),1,fp);
	if(fp==NULL)
	{
		printf("\t\t\t系统错误，请您重试......");
		exit(0);
	}
	
	while(!feof(fp))
	{
		count++;
		printf("\n\n\t****************物品信息%d*****************",count);
        printf("\n\t   商品的名称：%s\n",i.name);
	    printf("\t   商品的类别：%s\n",i.kind);
	    printf("\t   商品的总量：%d\n",i.number);
	    printf("\t   商品的库存上限：%d\n",i.limup);
	    printf("\t   商品的库存下限：%d\n",i.limdown);
	    printf("\t   商品的进货价格：%.2f\n",i.stockp);
	    printf("\t   商品的出售价格：%.2f\n",i.salep);
	    printf("\t   商品的进货日期（例如19970706）：%d\n",i.stockdate);
	    printf("\t   商品的进货量：%d\n",i.stocknum);
	    printf("\t   商品的生产日期：%d\n",i.producedate);
	    printf("\t   商品的厂家：%s\n",i.producename);
	    printf("\t   商品的保质期：%d\n",i.producedate);
		fread(&i,sizeof(struct ima),1,fp);
	}
	fclose(fp);
		printf("\n您想继续吗?(y/n)");
		scanf(" %c",&choice);
		if(choice=='Y'||choice=='y')
		{
			Browse();
		}
		else
		{
			system("cls");
			menu();
		}
}

void saleparrange()//零售价排序//
{
	struct ima i[NUMBER];
	struct ima temp;
	struct ima t;
	int count=1,j,m;
	FILE * fp;

	fp=fopen("ima.date","r");

	if(fp==NULL)
	{
		printf("\t\t系统错误，请您重试......");
		exit(0);
	}

	fread(&temp,sizeof(struct ima),1,fp);
	while(!feof(fp))
	{
		i[count]=temp;
		count++;
		fread(&temp,sizeof(struct ima),1,fp);
	
	}fclose(fp);
    
	for(m=1 ;m<=count-2; m++)
	{   for(j=1;j<=count-1-m;j++)	
	{
		if(i[j].salep>i[j+1].salep) //小者在前//
		{ 
			t=i[j];i[j]=i[j+1];i[j+1]=t;
		} 
	}}
	
	printf("\t\t\t----------按照进货量排序----------");
    for(j=1 ; j<=count-1;j++)
	{     printf("\n\n\t****************物品信息%d*****************",i[j].id);
		  printf("\n\t   商品的名称：%s\n",i[j].name);
	      printf("\t   商品的类别：%s\n",i[j].kind);
	      printf("\t   商品的总量：%d\n",i[j].number);
          printf("\t   商品的库存上限：%d\n",i[j].limup);
		  printf("\t   商品的库存下限：%d\n",i[j].limdown);
	      printf("\t   商品的进货价格：%.2f\n",i[j].stockp);
          printf("\t   商品的出售价格：%.2f\n",i[j].salep);
	      printf("\t   商品的进货日期（例如19970706）：%d\n",i[j].stockdate);
          printf("\t   商品的进货量：%d\n",i[j].stocknum);
		  printf("\t   商品的生产日期：%d\n",i[j].producedate);
	      printf("\t   商品的厂家：%s\n",i[j].producename);
          printf("\t   商品的保质期：%d\n",i[j].producedate);
	}
    printf("\t请按任意键返回上级菜单......");
	getch();
	Arrange();
}
void stockarrange()//进货量排序//
{
	struct ima i[NUMBER];
	struct ima temp;
	struct ima t;
	int count=1,j,m;
	FILE * fp;

	fp=fopen("ima.date","r");

	if(fp==NULL)
	{
		printf("\t\t系统错误，请您重试......");
		exit(0);
	}

	fread(&temp,sizeof(struct ima),1,fp);
	while(!feof(fp))
	{
		i[count]=temp;
		count++;
		fread(&temp,sizeof(struct ima),1,fp);
	
	}fclose(fp);
    
	for(m=1 ;m<=count-2; m++)
	{   for(j=1;j<=count-1-m;j++)	
	{
		if(i[j].stocknum>i[j+1].stocknum) //小者在前//
		{ 
			t=i[j];i[j]=i[j+1];i[j+1]=t;
		} 
	}}
	printf("\t\t\t----------按照进货量排序----------");
    for(j=1 ; j<=count-1;j++)
	{     printf("\n\n\t****************物品信息%d*****************",i[j].id);
		  printf("\n\t   商品的名称：%s\n",i[j].name);
	      printf("\t   商品的类别：%s\n",i[j].kind);
	      printf("\t   商品的总量：%d\n",i[j].number);
          printf("\t   商品的库存上限：%d\n",i[j].limup);
		  printf("\t   商品的库存下限：%d\n",i[j].limdown);
	      printf("\t   商品的进货价格：%.2f\n",i[j].stockp);
          printf("\t   商品的出售价格：%.2f\n",i[j].salep);
	      printf("\t   商品的进货日期（例如19970706）：%d\n",i[j].stockdate);
          printf("\t   商品的进货量：%d\n",i[j].stocknum);
		  printf("\t   商品的生产日期：%d\n",i[j].producedate);
	      printf("\t   商品的厂家：%s\n",i[j].producename);
          printf("\t   商品的保质期：%d\n",i[j].producedate);
	}
    printf("\t请按任意键返回上级菜单......");
	getch();
	Arrange();
    
}
void numberarrange()//库存量排序//
{
	struct ima i[NUMBER];
	struct ima temp;
	struct ima t;
	int count=1,j,m;
	FILE * fp;

	fp=fopen("ima.date","r");

	if(fp==NULL)
	{
		printf("\t\t系统错误，请您重试......");
		exit(0);
	}

	fread(&temp,sizeof(struct ima),1,fp);
	while(!feof(fp))
	{
		i[count]=temp;
		count++;
		fread(&temp,sizeof(struct ima),1,fp);
	
	}fclose(fp);
    
	for(m=1 ;m<=count-2; m++)
	{   for(j=1;j<=count-1-m;j++)	
	{
		if(i[j].number>i[j+1].number) //小者在前//
		{ 
			t=i[j];i[j]=i[j+1];i[j+1]=t;
		} 
	}}
    
	printf("\t\t\t----------按照进货量排序----------");
    for(j=1 ; j<=count-1;j++)
	{     printf("\n\n\t****************物品信息%d*****************",i[j].id);
		  printf("\n\t   商品的名称：%s\n",i[j].name);
	      printf("\t   商品的类别：%s\n",i[j].kind);
	      printf("\t   商品的总量：%d\n",i[j].number);
          printf("\t   商品的库存上限：%d\n",i[j].limup);
		  printf("\t   商品的库存下限：%d\n",i[j].limdown);
	      printf("\t   商品的进货价格：%.2f\n",i[j].stockp);
          printf("\t   商品的出售价格：%.2f\n",i[j].salep);
	      printf("\t   商品的进货日期（例如19970706）：%d\n",i[j].stockdate);
          printf("\t   商品的进货量：%d\n",i[j].stocknum);
		  printf("\t   商品的生产日期：%d\n",i[j].producedate);
	      printf("\t   商品的厂家：%s\n",i[j].producename);
          printf("\t   商品的保质期：%d\n",i[j].producedate);
	}
    printf("\t请按任意键返回上级菜单......");
	getch();
	Arrange();
    
}
void main()//主函数//
{	
	welcome();
	while(1)
	{ menu();
	 getch();
	}
	
}

void find()//查询函数//
{
	while(1)
	{  
		findmenu();
		getch();
	}
}

void menu()  //菜单函数// 
{   int choose;
	system("cls"); 
	printf("\n∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞【超市库存管理系统】∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞\n");
	printf("--------------------------------系统菜单显示如下--------------------------------\n");
	printf("\n\t①=====================【           物品信息更新         】\n");
	printf("\n\t②=====================【           物品信息查询         】\n");
	printf("\n\t③=====================【           物品信息浏览         】\n");
	printf("\n\t④=====================【           物品统计排序         】\n");
	printf("\n\t⑤=====================【           库存信息预警         】\n");
	printf("\n\t⑥=====================【           系统颜色设定         】\n");
	printf("\n\t⑦=====================【           退出管理系统         】\n");
	printf("\n\t请输入您要选择的功能菜单号......");
	scanf("%d",&choose);
		switch(choose)
		{
			case 1:
				system("cls");
				Update();;break;
			
			case 2:
				system("cls");
				find();break;
			
			case 3:
				system("cls");
				Browse();break;
					
			case 4:
				system("cls");
				Arrange();break;
			
			case 5:
				system("cls");
				Alarm();break;
			
			case 6:
				system("cls");
                colorsetting();break;
			
			case 7:
				system("cls");
				printf("\n∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞【感谢使用，谢谢！】∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞\n");
				getchar();
				exit(0);
				
			default:
			    system("cls");
                error();break;
		}

}

void findmenu() // 查询函数 二级菜单//
{  int choose;
   system("cls");
   printf("\n--------------------------------查询方法显示如下--------------------------------\n");
   printf("\n\t①=====================【           按照编号查询         】\n");
   printf("\n\t②=====================【           按照名称查询         】\n");
   printf("\n\t③=====================【           返回上级菜单         】\n");
   printf("\n请输入您要选择的功能菜单号......");
   scanf("%d",&choose);
		switch(choose)
		{   case 1:
			   system("cls");
			   Findin();break;
		    
		    case 2:
		       system("cls");
			   NmFindin();break;
		    
			case 3:
			   printf("请按任意键确认回到上一级菜单......");menu();
			
			default :
				error();
				getch();
				find();
		}

}


void Arrange()
{
   int choose;
   system("cls");
   printf("\n--------------------------------排序方法显示如下--------------------------------\n");
   printf("\n\t①=====================【           按照零售价排序        】\n");
   printf("\n\t②=====================【           按照进货量排序         】\n");
   printf("\n\t③=====================【           按照库存量排序         】\n");
   printf("\n\t④=====================【           返回上一级菜单         】\n");
   printf("\n请输入您要选择的功能菜单号......");
   scanf("%d",&choose);
		switch(choose)
		{   case 1:
			   system("cls");
			   saleparrange();break;
		    
		    case 2:
			   system("cls");
			   stockarrange();break;
		    
			case 3:
				system("cls");
				numberarrange();break;
			
			case 4:
			   printf("请按任意键确认回到上一级菜单......");return;
			
			default :
				error();
				break;
		}
		getchar();

}

void Alarm()
{  
   int choose;
   system("cls");
   printf("\n--------------------------------方法显示如下--------------------------------\n");
   printf("\n\t①=====================【           显示临近库存上限商品    】\n");
   printf("\n\t②=====================【           显示临近库存下限商品    】\n");
   printf("\n\t③=====================【           显示临近过期商品        】\n");
   printf("\n\t④=====================【           返回上一级菜单          】\n");
   printf("\n请输入您要选择的功能菜单号......");
   scanf("%d",&choose);
		switch(choose)
		{   case 1:
			   system("cls");
			   showlimup();break;
		    
		    case 2:
			   system("cls");
			   showlimdown();break;
		    
			case 3:
				system("cls");
				showdate();break;
			
			case 4:
			   printf("请按任意键确认回到上一级菜单......");return;
			
			default :
				error();
				break;
		}

}

void showlimup()//显示临近库存上限商品//
{
	struct ima i[NUMBER];
	struct ima temp;
	int count=1,j;
	FILE * fp;

	fp=fopen("ima.date","r");

	if(fp==NULL)
	{
		printf("\t\t系统错误，请您重试......");
		exit(0);
	}

	fread(&temp,sizeof(struct ima),1,fp);
	while(!feof(fp))
	{
		i[count]=temp;
		count++;
		fread(&temp,sizeof(struct ima),1,fp);
	
	}fclose(fp);
    
	printf("\t\t 临近库存上限的商品信息为......\n");
	for(j=1 ; j<=count-1 ;j++)
	{
		if((i[j].limup-i[j].number)<=LIM)
		{ 
		  printf("\n\n\t****************物品信息%d*****************",i[j].id);
		  printf("\n\t   商品的名称：%s\n",i[j].name);
	      printf("\t   商品的类别：%s\n",i[j].kind);
	      printf("\t   商品的总量：%d\n",i[j].number);
          printf("\t   商品的库存上限：%d\n",i[j].limup);
		  printf("\t   商品的库存下限：%d\n",i[j].limdown);
	      printf("\t   商品的进货价格：%.2f\n",i[j].stockp);
          printf("\t   商品的出售价格：%.2f\n",i[j].salep);
	      printf("\t   商品的进货日期（例如19970706）：%d\n",i[j].stockdate);
          printf("\t   商品的进货量：%d\n",i[j].stocknum);
		  printf("\t   商品的生产日期：%d\n",i[j].producedate);
	      printf("\t   商品的厂家：%s\n",i[j].producename);
          printf("\t   商品的保质期：%d\n",i[j].producedate);
		}
	}
	printf("\t 请按任意键返回上级菜单......");
	getch();
	Alarm();
    
}

void showlimdown()//显示临近库存下限商品//
{
	struct ima i[NUMBER];
	struct ima temp;
	int count=1,j;
	FILE * fp;

	fp=fopen("ima.date","r");

	if(fp==NULL)
	{
		printf("\t\t系统错误，请您重试......");
		exit(0);
	}

	fread(&temp,sizeof(struct ima),1,fp);
	while(!feof(fp))
	{
		i[count]=temp;
		count++;
		fread(&temp,sizeof(struct ima),1,fp);
	
	}fclose(fp);
    
	printf("\t\t 临近库存下限的商品信息为......\n");
	for(j=1 ; j<=count-1 ;j++)
	{
		if((i[j].number-i[j].limdown)<=LIM)
		{ 
		  printf("\n\n\t****************物品信息%d*****************",i[j].id);
		  printf("\n\t   商品的名称：%s\n",i[j].name);
	      printf("\t   商品的类别：%s\n",i[j].kind);
	      printf("\t   商品的总量：%d\n",i[j].number);
          printf("\t   商品的库存上限：%d\n",i[j].limup);
		  printf("\t   商品的库存下限：%d\n",i[j].limdown);
	      printf("\t   商品的进货价格：%.2f\n",i[j].stockp);
          printf("\t   商品的出售价格：%.2f\n",i[j].salep);
	      printf("\t   商品的进货日期（例如19970706）：%d\n",i[j].stockdate);
          printf("\t   商品的进货量：%d\n",i[j].stocknum);
		  printf("\t   商品的生产日期：%d\n",i[j].producedate);
	      printf("\t   商品的厂家：%s\n",i[j].producename);
          printf("\t   商品的保质期：%d\n",i[j].producedate);
		}
	}
	printf("\t 请按任意键返回上级菜单......");
	getch();
	Alarm();
    
}

void showdate()//显示临近保质期商品//
{
	struct ima i[NUMBER];
	struct ima temp;
	struct ima t;
	int count=1,j;
	FILE * fp;

	fp=fopen("ima.date","r");

	if(fp==NULL)
	{
		printf("\t\t系统错误，请您重试......");
		exit(0);
	}

	fread(&temp,sizeof(struct ima),1,fp);
	while(!feof(fp))
	{
		i[count]=temp;
		count++;
		fread(&temp,sizeof(struct ima),1,fp);
	
	}fclose(fp);
    
	printf("\t\t 临近保质期的商品信息为......\n");
	for(j=1 ; j<=count-1 ;j++)
	{
		if(i[j].guaranteedate<=DATE)
		{ 
		  printf("\n\n\t****************物品信息%d*****************",i[j].id);
		  printf("\n\t   商品的名称：%s\n",i[j].name);
	      printf("\t   商品的类别：%s\n",i[j].kind);
	      printf("\t   商品的总量：%d\n",i[j].number);
          printf("\t   商品的库存上限：%d\n",i[j].limup);
		  printf("\t   商品的库存下限：%d\n",i[j].limdown);
	      printf("\t   商品的进货价格：%.2f\n",i[j].stockp);
          printf("\t   商品的出售价格：%.2f\n",i[j].salep);
	      printf("\t   商品的进货日期（例如19970706）：%d\n",i[j].stockdate);
          printf("\t   商品的进货量：%d\n",i[j].stocknum);
		  printf("\t   商品的生产日期：%d\n",i[j].producedate);
	      printf("\t   商品的厂家：%s\n",i[j].producename);
          printf("\t   商品的保质期：%d\n",i[j].producedate);
		}
	}
	printf("\t 请按任意键返回上级菜单......");
    getch();
	Alarm();
}

void colorsetting()
{       int a;
	    char choice;
		system("cls");
		printf("\n\n\t\t选择以下方案\n");
		printf("\n\n\t\t1**************红底黑字\n");
		printf("\n\n\t\t2**************白底黑字\n");
		printf("\n\n\t\t3**************黑底红字\n");
		printf("\n\n\t\t4**************绿底蓝字\n");
		printf("\n\n\t\t5**************黄底紫字\n");
		printf("\n\n\t\t6**************蓝底绿字\n");
		printf("\n\n\t\t\t\t\t请挑选您喜爱的颜色<1-5>......");
	    
		scanf("%d",&a);
		switch(a)
		{
			case 1:
				system("color 40");
				break;
			case 2:
				system("color F0");
				break;
			case 3:
				system("color 04");
				break;
			case 4:
				system("color 21");
				break;
			case 5:
				system("color 65");
				break;
			case 6:
				system("color 1a");
				break;
			default:
			printf("\n\n\t\t\t\t\t输入无效,重新输入......");
			getch();
			colorsetting();
	
		}
		
		printf("\n选择的颜色您还满意吗?(y返回主菜单/n继续选择)");
		scanf(" %c",&choice);
		if(choice=='Y'||choice=='y')
		{
			
			system("cls");
			menu();
		}
		else
		{
			colorsetting();
		}
}

void Update()
{
   int choose;
   system("cls");
   printf("\n--------------------------------更新方法显示如下--------------------------------\n");
   printf("\n\t①=====================【          新购物品入库       】\n");
   printf("\n\t②=====================【          物品信息修改       】\n");
   printf("\n\t③=====================【          物品信息删除       】\n");
   printf("\n\t④=====================【          返回上级菜单       】\n");
   printf("\n\t请输入您要选择的功能菜单号......");
   scanf("%d",&choose);
		switch(choose)
		{   case 1:
			   system("cls");
			   Append();break;
		    
		    case 2:
			   system("cls");
			   Amend();break;
		    
			case 3:
				system("cls");
				Del();break;
			
			case 4:
			   printf("请按任意键确认回到上一级菜单......");return;
			
			default :
				error();
				break;
		}getchar();

}