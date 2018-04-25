#define Num 101
#include <stdio.h>      /*I/O函数*/
#include <stdlib.h>     /*标准库函数*/
#include <string.h>    /*字符串函数*/
#include <conio.h>    /*控制台输入输出函数*/
#include<windows.h>    /*图新设备接口函数*/



int main_select();        /*主菜单显示函数*/
int edit_menu();         /*编辑联系人菜单显示函数*/
int search_menu();        /*查找联系人菜单显示函数*/
int  print_menu();        /*显示联系人菜单显示函数*/
int Blacksheet_menu();    /*黑名单菜单显示函数*/
void edit_select();       /*编辑联系人菜单选择函数*/
void search_select();     /*查找联系人菜单选择函数*/
void print_select();       /*显示联系人菜单选择函数*/
void Input();             /*录入联系人函数*/
void Query_a_record();    /*姓名查找联系人函数*/
void Search_a_record();   /*序号查找联系人函数*/
void Delete_a_record();    /*删除联系人函数*/
void Change();              /*修改联系人函数*/
void Blacksheet_select();   /*黑名单菜单选择函数*/
void Blackesheet_in();       /*黑名单录入函数*/
void Blackesheet_out();     /*黑名单恢复函数*/
void Blacksheet_print();     /*黑名单显示函数*/
void WritetoText();         /*写入文本文件函数*/
void readfromfile();       /*磁盘数据导入函数*/
void Display();           /*按姓名显示函数*/
void Print();            /*序号显示函数*/
void save();              /*数据保存函数*/
void welcome();           /*欢迎界面函数*/
void color(const unsigned short color1);



typedef struct 
	{            
		char name[12];                /*姓名*/
		char tel[16];                 /*电话*/
		char email[20];		          /*邮箱*/
		char company[20];		      /*公司*/	
		char classify[8];		      /*分类*/
	}Person; 
Person per[Num];                      /*联系人信息结构体数组*/
int black[Num];                       /*黑名单数组(指向联系人编号)*/
int n=0;                              /*当前联系人人数*/
int bn=0;                             /*当前黑名单人数*/


void color(const unsigned short color1)
{        
	/*仅限改变0-15的颜色;如果在0-15那么实现他的颜色   因为如果超过15后面的改变的是文本背景色。*/
    if(color1>=0&&color1<=15)
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1); /*如果不在0-15的范围颜色，那么改为默认的颜色白色；*/
    else
		system("color F0");
}




void welcome()
{        /*在上面写color（颜色代码）下面便是改变的颜色。注意：这里是把下面所有的颜色全部改变。*/
        
		int i;
		for(i=0;i<=16;i++)
        {
        	color(i);
        	printf("\n\n\n");
            printf("\t\t  ┌───────────────────┐\n");                   
	        printf("\t\t  │         ********************         │\n"); 
	        printf("\t\t  │         *欢迎使用电子通讯录*         │\n"); 
	        printf("\t\t  │         ********************         │\n");
	        printf("\t\t  └───────────────────┘\n"); 
        	Sleep(200);
        	system("cls");
		}
        printf("%s", "hello"); 
        printf("%s\n", " world");
        system("cls");
}





void Input()
{
	if(n>=Num-1)
	{
		printf("联系人已达上限！\n");
		system("pause"); 
		return;
	}
	printf("依次输入\n<姓名><电话><邮箱><公司><分类>:\n");
	fflush(stdin);
    gets(per[n+1].name);
	gets(per[n+1].tel);
	gets(per[n+1].email);
	gets(per[n+1].company);
	gets(per[n+1].classify);
	n+=1;
	printf("已生成新的联系人信息：\n");
	printf("编号：%d\n",n);
	printf("姓名：");puts(per[n].name);
	printf("电话：");puts(per[n].tel);
	printf("邮箱：");puts(per[n].email);
	printf("公司：");puts(per[n].company);
	printf("分类：");puts(per[n].classify);
	system("pause"); 
	return;
}

void Query_a_record()
{
	char s[12]; 
	int i=1; 
	printf("请输入想查询的姓名:"); 
	fflush(stdin);
	gets(s); 
	while(strcmp(per[i].name,s)!=0&&i<=n) i++; 
	if(i>n) 
	{
		printf("通讯录中没有此人!\n"); 
		return; 
	} 
	printf("编号：%d\n",i);
	printf("姓名：");puts(per[i].name);
	printf("电话：");puts(per[i].tel);
	printf("邮箱：");puts(per[i].email);
	printf("公司：");puts(per[i].company);
	printf("分类：");puts(per[i].classify);
	system("pause"); 
	return;
}

void Search_a_record()
{
	int i; 
	printf("请输入想查询的序号:"); 
	scanf("%d",&i); 
	if(i>n) 
	{
		printf("通讯录中没有此纪录!\n"); 
		system("pause"); 
		return; 
	} 
	printf("编号：%d\n",i);
	printf("姓名：");puts(per[i].name);
	printf("电话：");puts(per[i].tel);
	printf("邮箱：");puts(per[i].email);
	printf("公司：");puts(per[i].company);
	printf("分类：");puts(per[i].classify);
	system("pause"); 
	return;
}

void Delete_a_record()
{
	char s[12],c; 
	int i=1,j; 
	printf("请输入想删除的联系人姓名:"); 
	fflush(stdin);
	gets(s); 
	while(strcmp(per[i].name,s)!=0&&i<=n) i++; 
	if(i>n) 
	{
		printf("通讯录中没有此人!\n");
		system("pause"); 
		return; 
	} 
	printf("该联系人信息:\n编号：%d\n",i);
	printf("姓名：");puts(per[i].name);
	printf("电话：");puts(per[i].tel);
	printf("邮箱：");puts(per[i].email);
	printf("公司：");puts(per[i].company);
	printf("分类：");puts(per[i].classify); 
	printf("是否删除?(输入\"1\"删除，任意非\"1\"键返回)\n");
	fflush(stdin);
	c=getchar();
	if(c=='1')
	{
	    for(j=i;j<n;j++)
	    { 
	    	strcpy(per[j].name,per[j+1].name); 
	    	strcpy(per[j].tel,per[j+1].tel);
	    	strcpy(per[j].email,per[j+1].email);
	    	strcpy(per[j].company,per[j+1].company);
	    	strcpy(per[j].classify,per[j+1].classify);
	    }
	    n-=1;
	    printf("成功删除该联系人!\n");
	    system("pause");
	    return;
	}
	return;
}

void Change()
{
	char s[12]; 
	int i=1; 
	printf("请输入想修改的记录中的名字:"); 
	fflush(stdin);
	gets(s);
	while(strcmp(per[i].name,s)!=0&&i<=n) i++; 
	if(i>n) 
	{ 
		printf("通讯录中没有此人!\n"); 
		system("pause"); 
		return; 	
	}  
	printf("依次输入\n<姓名><电话><邮箱><公司><分类>:\n");
	fflush(stdin);
    gets(per[i].name);
	gets(per[i].tel);
	gets(per[i].email);
	gets(per[i].company);
	gets(per[i].classify);
	printf("更改后的联系人信息：\n");
	printf("编号：%d\n",i);
	printf("姓名：");puts(per[i].name);
	printf("电话：");puts(per[i].tel);
	printf("邮箱：");puts(per[i].email);
	printf("公司：");puts(per[i].company);
	printf("分类：");puts(per[i].classify);
	system("pause"); 
	return;
}



void WritetoText()
{
	int i=0; 
	FILE *fp;                                           //定义文件指针
	char filename[30];                                  //定义文件名
	printf("写入到文件:\n");                          //输入文件名
	printf("请输入所写入的文件名:"); 
	scanf("%s",filename); 
	if((fp=fopen(filename,"w"))==NULL)                   
	{ 
		printf("无法打开文件\n"); 
		system("pause"); 
		return; 
	} 
	fprintf(fp,"-------------------------------------------------------------------------------\n");                          /*格式*/ 
	fprintf(fp,"编号 姓名        电话            邮件                公司                分类  \n"); 
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
	fclose(fp);                                         //关闭文件 
	printf("写入成功!\n");
	system("pause"); 
}


void Display()
{ 
	int i,j; 
	int p[Num],t;       /*姓名所排的序号*/
	for(i=0;i<=100;i++)
	{
		p[i]=i;
	}
    for (i=1;i<n;i++)
    {
        for(j=1;j<=n-i;j++)
        {
            if (strcmp(per[p[j]].name,per[p[j+1]].name)>0)
            {
        	    t=p[j],p[j]=p[j+1],p[j+1]=t;
            }
        }        
    }
	int page=1,max; 
	char c;
	max=(n+9)/10;
	do
	{
		system("cls");                      
    	printf("编号 姓名        电话            邮件                公司                分类  \n");    /*格式*/ 
    	printf("-------------------------------------------------------------------------------\n"); 
    	if(page<max)
    	{
    		for(i=page*10-9;i<=page*10;i++)                                                            
        	{ 
        		printf("%-3d %-12s%-16s%-20s%-20s%-8s",p[i],per[p[i]].name,per[p[i]].tel,per[p[i]].email,per[p[i]].company,per[p[i]].classify);
				if(i%10!=0)printf("\n"); 
        	}
		}
    	else if(page==max)
    	{
    		for(i=page*10-9;i<=n;i++)                                                            
        	{ 
        		printf("%-3d %-12s%-16s%-20s%-20s%-8s",i,per[p[i]].name,per[p[i]].tel,per[p[i]].email,per[p[i]].company,per[p[i]].classify); 
        		if(i%10!=0)printf("\n"); 
        	}
		}
		printf("-------------------------------------------------------------------------------\n");
        printf("1:下一页                            2:上一页                             0:退出\n");
        printf("请您选择(0-2):");
		fflush(stdin);
    	c=getchar();
    	if(c=='1')
		{
		    if(page<max)page+=1;
			else{printf("已是最后一页!");system("pause");}
		}
    	else if(c=='2')
		{
		    if(page>1)page-=1;
			else{printf("已是第一页!");system("pause");}
		}
	}while(c!='0');
} 

void Print()
{
	int i,page=1,max; 
	char c;
	max=(n+9)/10;
	do
	{
		system("cls");                      
    	printf("编号 姓名        电话            邮件                公司                分类  \n");    /*格式*/ 
    	printf("-------------------------------------------------------------------------------\n"); 
    	if(page<max)
    	{
    		for(i=page*10-9;i<=page*10;i++)                                                            
        	{ 
        		printf("%-3d %-12s%-16s%-20s%-20s%-8s",i,per[i].name,per[i].tel,per[i].email,per[i].company,per[i].classify);
				if(i%10!=0)printf("\n"); 
        	}
		}
    	else if(page==max)
    	{
    		for(i=page*10-9;i<=n;i++)                                                            
        	{ 
        		printf("%-3d %-12s%-16s%-20s%-20s%-8s",i,per[i].name,per[i].tel,per[i].email,per[i].company,per[i].classify); 
        		if(i%10!=0)printf("\n"); 
        	}
		}
		printf("-------------------------------------------------------------------------------\n");
        printf("1:下一页                            2:上一页                             0:退出\n");
        printf("请您选择(0-2):");
		fflush(stdin);
    	c=getchar();
    	if(c=='1')
		{
		    if(page<max)page+=1;
			else{printf("已是最后一页!");system("pause");}
		}
    	else if(c=='2')
		{
		    if(page>1)page-=1;
			else{printf("已是第一页!");system("pause");}
		}
	}while(c!='0');
}



void save()
{
	FILE *fp;
	fp=fopen("save","wb");
	fwrite(&bn,sizeof(int),1,fp);
	fwrite(&black,sizeof(int),bn+1,fp);
	fwrite(&n,sizeof(int),1,fp);
	fwrite(per,sizeof(Person),n+1,fp);
	fclose(fp);
}




void readfromfile()
{
	FILE *fp;                                           //定义文件指针
	char filename[30];                                  //文件名
	printf("导入的数据:\n");                          //输入文件名
	printf("请输入所写入的数据文件名:"); 
	scanf("%s",filename); 
	if((fp=fopen(filename,"rb"))==NULL)                   
	{ 
		printf("无法打开文件...\n"); 
		system("pause"); 
		return; 
	} 
	fread(&bn,sizeof(int),1,fp);
	fread(&black,sizeof(int),bn+1,fp);
	fread(&n,sizeof(int),1,fp);
	fread(per,sizeof(Person),n+1,fp);
	fclose(fp);
	printf("导入成功！\n");
	system("pause");
}

void search_select()
{
	while(1)
	{
		switch(search_menu())
	    {
	    case 1:
		     system("cls");
             Query_a_record();
             break;
	    case 2:
		     system("cls");
             Search_a_record();
             break;
	    case 0:
             return;
	    }
	}
}


void Blackesheet_in()
{
	char s[12],c; 
	int i=1; 
	printf("请输入想拉黑的联系人姓名:"); 
	fflush(stdin);
	gets(s); 
	while(strcmp(per[i].name,s)!=0&&i<=n) i++; 
	if(i>n) 
	{
		printf("黑名单中没有此人!\n");
		system("pause"); 
		return; 
	} 
	printf("该联系人信息:\n编号：%d\n",i);
	printf("姓名：");puts(per[i].name);
	printf("电话：");puts(per[i].tel);
	printf("邮箱：");puts(per[i].email);
	printf("公司：");puts(per[i].company);
	printf("分类：");puts(per[i].classify); 
	printf("是否拉黑?(输入\"1\"拉黑，任意非\"1\"键返回)\n");
	fflush(stdin);
	c=getchar();
	if(c=='1')
	{
		bn+=1;
	    black[bn]=i;
	    printf("成功拉黑!\n");
	    system("pause");
	}
	return;
}



void Blackesheet_out()
{
	char s[12],c; 
	int i=1,j; 
	printf("请输入想恢复的联系人姓名:"); 
	fflush(stdin);
	gets(s); 
	while(strcmp(per[black[i]].name,s)!=0&&i<=n) i++; 
	if(i>bn) 
	{
		printf("黑名单中没有此人!\n");
		system("pause"); 
		return; 
	} 
	printf("该联系人信息:\n编号：%d\n",i);
	printf("姓名：");puts(per[black[i]].name);
	printf("电话：");puts(per[black[i]].tel);
	printf("邮箱：");puts(per[black[i]].email);
	printf("公司：");puts(per[black[i]].company);
	printf("分类：");puts(per[black[i]].classify); 
	printf("是否恢复?(输入\"1\"恢复，任意非\"1\"键返回)\n");
	fflush(stdin);
	c=getchar();
	if(c=='1')
	{
	    for(j=i;j<bn;j++)
	    { 
	    	black[j]=black[j+1];
	    }
		black[bn]=0;
		bn-=1;
	    printf("成功恢复该联系人至白名单!\n");
	    system("pause");
	    return;
	}
	return;
}



void Blacksheet_print()
{
	int i,page=1,max; 
	char c;
	max=(bn+9)/10;
	do
	{
		system("cls");                      
    	printf("编号 姓名        电话            邮件                公司                分类  \n");    /*格式*/ 
    	printf("-------------------------------------------------------------------------------\n"); 
    	if(page<max)
    	{
    		for(i=page*10-9;i<=page*10;i++)                                                            
        	{ 
        		printf("%-3d %-12s%-16s%-20s%-20s%-8s",i,per[black[i]].name,per[black[i]].tel,per[black[i]].email,per[black[i]].company,per[black[i]].classify);
				if(i%10!=0)printf("\n"); 
        	}
		}
    	else if(page==max)
    	{
    		for(i=page*10-9;i<=bn;i++)                                                            
        	{ 
        		printf("%-3d %-12s%-16s%-20s%-20s%-8s",i,per[black[i]].name,per[black[i]].tel,per[black[i]].email,per[black[i]].company,per[black[i]].classify); 
        		if(i%10!=0)printf("\n"); 
        	}
		}
		printf("-------------------------------------------------------------------------------\n");
        printf("1:下一页                            2:上一页                             0:退出\n");
        printf("请您选择(0-2):");
		fflush(stdin);
    	c=getchar();
    	if(c=='1')
		{
		    if(page<max)page+=1;
			else{printf("已是最后一页!");system("pause");}
		}
    	else if(c=='2')
		{
		    if(page>1)page-=1;
			else{printf("已是第一页!");system("pause");}
		}
	}while(c!='0');
} 



void Blacksheet_select()
{
	while(1)
	{
		switch(Blacksheet_menu())
	    {
        case 1:
		     system("cls");
             Blackesheet_in();
             break;
	    case 2:
		     system("cls");
             Blacksheet_print();
             break;
        case 3:
		     system("cls");
             Blackesheet_out();
             break;    
	    case 0:
             return;
	    }
	}
}


int Blacksheet_menu()
{
	char c; 
	do
	{ 
	    system("cls"); 
		printf("\n\n\n");
	    printf("\t\t\t   *****通讯黑名单***** \n");                               
        printf("\t\t┌───────────────────┐\n");                   
	    printf("\t\t│\t        1. 标记为黑名单\t\t│\n"); 
	    printf("\t\t│\t        2. 黑名单列表\t\t│\n"); 
	    printf("\t\t│\t        3. 恢复至白名单\t\t│\n");
	    printf("\t\t│\t        0. 返回上一级\t\t│\n");
	    printf("\t\t└───────────────────┘\n"); 
	    printf("\t\t\t请您选择(0-3):"); 
	    fflush(stdin);
	    c=getchar();  
	}while(c<'0'||c>'3'); 
	return(c-'0'); 
}


int  search_menu()
{
	char c; 
	do
	{ 
	    system("cls"); 
		printf("\n\n\n");
	    printf("\t\t\t   *****查找通讯录***** \n");                               
        printf("\t\t┌───────────────────┐\n");                   
	    printf("\t\t│\t        1. 姓名查找\t\t│\n"); 
	    printf("\t\t│\t        2. 序号查找\t\t│\n"); 
	    printf("\t\t│\t        0. 返回上一级\t\t│\n");
	    printf("\t\t└───────────────────┘\n"); 
	    printf("\t\t\t请您选择(0-2):");
		fflush(stdin); 
	    c=getchar();  
	}while(c<'0'||c>'2'); 
	return(c-'0'); 
}


void print_select()
{
	while(1)
	{
		switch(print_menu())
	    {
        case 1:
		     system("cls");
             Display();
             break;
	    case 2:
		     system("cls");
             Print();
             break;
	    case 0:
             return;
	    }
	}
}




int  print_menu()
{
	char c; 
	do
	{ 
	    system("cls"); 
		printf("\n\n\n");
	    printf("\t\t\t   *****显示通讯录***** \n");                               
        printf("\t\t┌────────────────────┐\n");                   
	    printf("\t\t│\t        1. 按姓名显示\t\t  │\n"); 
	    printf("\t\t│\t        2. 按序号显示\t\t  │\n"); 
	    printf("\t\t│\t        0. 返回上一级\t\t  │\n");
	    printf("\t\t└────────────────────┘\n"); 
	    printf("\t\t\t请您选择(0-2):"); 
	    fflush(stdin);
	    c=getchar();  
	}while(c<'0'||c>'2'); 
	return(c-'0'); 
}




void edit_select()
{
	while(1)
	{
		switch(edit_menu())
	    {
	     case 1:
		      system("cls");
              Input();
              break;
	    case 2:
		     system("cls");
             Delete_a_record();
             break;
        case 3:    
             system("cls");
		     Change(); 
		     break;
	    case 0:
             return;
	    }
	} 
}



int  edit_menu()
{
	char c; 
	do
	{ 
	    system("cls"); 
		printf("\n\n\n");
	    printf("\t\t\t   *****编辑通讯录***** \n");                               
        printf("\t\t┌───────────────────┐\n");                   
	    printf("\t\t│\t        1. 添加记录\t\t│\n"); 
	    printf("\t\t│\t        2. 删除记录\t\t│\n"); 
	    printf("\t\t│\t        3. 修改记录\t\t│\n"); 
	    printf("\t\t│\t        0. 返回上一级\t\t│\n");
	    printf("\t\t└───────────────────┘\n"); 
	    printf("\t\t\t请您选择(0-3):"); 
	    fflush(stdin);
	    c=getchar();  
	}while(c<'0'||c>'3'); 
	return(c-'0'); 
}


int main_select() 
{ 
	char c; 
	do{ 
	    system("cls"); 
		printf("\n\n\n");
	    printf("\t\t\t       *****通讯录***** \n");                               
        printf("\t\t┌────────────────────┐\n");                   
	    printf("\t\t│\t      1. 编辑通讯录\t\t  │\n"); 
	    printf("\t\t│\t      2. 查找通讯录\t\t  │\n"); 
	    printf("\t\t│\t      3. 显示通讯录\t\t  │\n"); 
	    printf("\t\t│\t      4. 通讯黑名单\t\t  │\n");
        printf("\t\t│\t      5. 写入文件  \t\t  │\n");
	    printf("\t\t│\t      6. 读取数据  \t\t  │\n");
	    printf("\t\t│\t      0. 退出      \t\t  │\n");
	    printf("\t\t└────────────────────┘\n"); 
	    printf("\t\t\t请您选择(0-6):"); 
	    fflush(stdin);
	    c=getchar();  
	}while(c<'0'||c>'6'); 
	return(c-'0'); 
} 
	
	
	
main()                                         //主函数 
{
    welcome();  
	while(1) 
	{ 
		switch(main_select()) 
		{ 
		case 1: 
		       system("cls");
			   edit_select();                                       //编辑纪录 
		       break; 
        case 2: 
     	       system("cls");
               search_select();									  //查找记录 
		       break;
		case 3:  
		       system("cls");
			   print_select();								  //显示记录 
               break;
		case 4: 
		       system("cls"); 
			   Blacksheet_select();                                           //黑名单 
		       break;
        case 5: 
		       system("cls");
			   WritetoText();									     //写入数据 
		       break; 
        case 6:
		       system("cls");
			   readfromfile();									     //读取数据 
		       break;
     	case 0: 
		       system("cls");
		       save();
		       printf("通讯录已保存！\n");
			   exit(0); 
		} 
	} 
}
