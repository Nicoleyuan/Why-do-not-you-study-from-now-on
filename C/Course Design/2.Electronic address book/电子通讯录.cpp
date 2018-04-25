#define Num 101
#include <stdio.h>      /*I/O����*/
#include <stdlib.h>     /*��׼�⺯��*/
#include <string.h>    /*�ַ�������*/
#include <conio.h>    /*����̨�����������*/
#include<windows.h>    /*ͼ���豸�ӿں���*/



int main_select();        /*���˵���ʾ����*/
int edit_menu();         /*�༭��ϵ�˲˵���ʾ����*/
int search_menu();        /*������ϵ�˲˵���ʾ����*/
int  print_menu();        /*��ʾ��ϵ�˲˵���ʾ����*/
int Blacksheet_menu();    /*�������˵���ʾ����*/
void edit_select();       /*�༭��ϵ�˲˵�ѡ����*/
void search_select();     /*������ϵ�˲˵�ѡ����*/
void print_select();       /*��ʾ��ϵ�˲˵�ѡ����*/
void Input();             /*¼����ϵ�˺���*/
void Query_a_record();    /*����������ϵ�˺���*/
void Search_a_record();   /*��Ų�����ϵ�˺���*/
void Delete_a_record();    /*ɾ����ϵ�˺���*/
void Change();              /*�޸���ϵ�˺���*/
void Blacksheet_select();   /*�������˵�ѡ����*/
void Blackesheet_in();       /*������¼�뺯��*/
void Blackesheet_out();     /*�������ָ�����*/
void Blacksheet_print();     /*��������ʾ����*/
void WritetoText();         /*д���ı��ļ�����*/
void readfromfile();       /*�������ݵ��뺯��*/
void Display();           /*��������ʾ����*/
void Print();            /*�����ʾ����*/
void save();              /*���ݱ��溯��*/
void welcome();           /*��ӭ���溯��*/
void color(const unsigned short color1);



typedef struct 
	{            
		char name[12];                /*����*/
		char tel[16];                 /*�绰*/
		char email[20];		          /*����*/
		char company[20];		      /*��˾*/	
		char classify[8];		      /*����*/
	}Person; 
Person per[Num];                      /*��ϵ����Ϣ�ṹ������*/
int black[Num];                       /*����������(ָ����ϵ�˱��)*/
int n=0;                              /*��ǰ��ϵ������*/
int bn=0;                             /*��ǰ����������*/


void color(const unsigned short color1)
{        
	/*���޸ı�0-15����ɫ;�����0-15��ôʵ��������ɫ   ��Ϊ�������15����ĸı�����ı�����ɫ��*/
    if(color1>=0&&color1<=15)
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1); /*�������0-15�ķ�Χ��ɫ����ô��ΪĬ�ϵ���ɫ��ɫ��*/
    else
		system("color F0");
}




void welcome()
{        /*������дcolor����ɫ���룩������Ǹı����ɫ��ע�⣺�����ǰ��������е���ɫȫ���ı䡣*/
        
		int i;
		for(i=0;i<=16;i++)
        {
        	color(i);
        	printf("\n\n\n");
            printf("\t\t  ������������������������������������������\n");                   
	        printf("\t\t  ��         ********************         ��\n"); 
	        printf("\t\t  ��         *��ӭʹ�õ���ͨѶ¼*         ��\n"); 
	        printf("\t\t  ��         ********************         ��\n");
	        printf("\t\t  ������������������������������������������\n"); 
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
		printf("��ϵ���Ѵ����ޣ�\n");
		system("pause"); 
		return;
	}
	printf("��������\n<����><�绰><����><��˾><����>:\n");
	fflush(stdin);
    gets(per[n+1].name);
	gets(per[n+1].tel);
	gets(per[n+1].email);
	gets(per[n+1].company);
	gets(per[n+1].classify);
	n+=1;
	printf("�������µ���ϵ����Ϣ��\n");
	printf("��ţ�%d\n",n);
	printf("������");puts(per[n].name);
	printf("�绰��");puts(per[n].tel);
	printf("���䣺");puts(per[n].email);
	printf("��˾��");puts(per[n].company);
	printf("���ࣺ");puts(per[n].classify);
	system("pause"); 
	return;
}

void Query_a_record()
{
	char s[12]; 
	int i=1; 
	printf("���������ѯ������:"); 
	fflush(stdin);
	gets(s); 
	while(strcmp(per[i].name,s)!=0&&i<=n) i++; 
	if(i>n) 
	{
		printf("ͨѶ¼��û�д���!\n"); 
		return; 
	} 
	printf("��ţ�%d\n",i);
	printf("������");puts(per[i].name);
	printf("�绰��");puts(per[i].tel);
	printf("���䣺");puts(per[i].email);
	printf("��˾��");puts(per[i].company);
	printf("���ࣺ");puts(per[i].classify);
	system("pause"); 
	return;
}

void Search_a_record()
{
	int i; 
	printf("���������ѯ�����:"); 
	scanf("%d",&i); 
	if(i>n) 
	{
		printf("ͨѶ¼��û�д˼�¼!\n"); 
		system("pause"); 
		return; 
	} 
	printf("��ţ�%d\n",i);
	printf("������");puts(per[i].name);
	printf("�绰��");puts(per[i].tel);
	printf("���䣺");puts(per[i].email);
	printf("��˾��");puts(per[i].company);
	printf("���ࣺ");puts(per[i].classify);
	system("pause"); 
	return;
}

void Delete_a_record()
{
	char s[12],c; 
	int i=1,j; 
	printf("��������ɾ������ϵ������:"); 
	fflush(stdin);
	gets(s); 
	while(strcmp(per[i].name,s)!=0&&i<=n) i++; 
	if(i>n) 
	{
		printf("ͨѶ¼��û�д���!\n");
		system("pause"); 
		return; 
	} 
	printf("����ϵ����Ϣ:\n��ţ�%d\n",i);
	printf("������");puts(per[i].name);
	printf("�绰��");puts(per[i].tel);
	printf("���䣺");puts(per[i].email);
	printf("��˾��");puts(per[i].company);
	printf("���ࣺ");puts(per[i].classify); 
	printf("�Ƿ�ɾ��?(����\"1\"ɾ���������\"1\"������)\n");
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
	    printf("�ɹ�ɾ������ϵ��!\n");
	    system("pause");
	    return;
	}
	return;
}

void Change()
{
	char s[12]; 
	int i=1; 
	printf("���������޸ĵļ�¼�е�����:"); 
	fflush(stdin);
	gets(s);
	while(strcmp(per[i].name,s)!=0&&i<=n) i++; 
	if(i>n) 
	{ 
		printf("ͨѶ¼��û�д���!\n"); 
		system("pause"); 
		return; 	
	}  
	printf("��������\n<����><�绰><����><��˾><����>:\n");
	fflush(stdin);
    gets(per[i].name);
	gets(per[i].tel);
	gets(per[i].email);
	gets(per[i].company);
	gets(per[i].classify);
	printf("���ĺ����ϵ����Ϣ��\n");
	printf("��ţ�%d\n",i);
	printf("������");puts(per[i].name);
	printf("�绰��");puts(per[i].tel);
	printf("���䣺");puts(per[i].email);
	printf("��˾��");puts(per[i].company);
	printf("���ࣺ");puts(per[i].classify);
	system("pause"); 
	return;
}



void WritetoText()
{
	int i=0; 
	FILE *fp;                                           //�����ļ�ָ��
	char filename[30];                                  //�����ļ���
	printf("д�뵽�ļ�:\n");                          //�����ļ���
	printf("��������д����ļ���:"); 
	scanf("%s",filename); 
	if((fp=fopen(filename,"w"))==NULL)                   
	{ 
		printf("�޷����ļ�\n"); 
		system("pause"); 
		return; 
	} 
	fprintf(fp,"-------------------------------------------------------------------------------\n");                          /*��ʽ*/ 
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


void Display()
{ 
	int i,j; 
	int p[Num],t;       /*�������ŵ����*/
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
    	printf("��� ����        �绰            �ʼ�                ��˾                ����  \n");    /*��ʽ*/ 
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
        printf("1:��һҳ                            2:��һҳ                             0:�˳�\n");
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

void Print()
{
	int i,page=1,max; 
	char c;
	max=(n+9)/10;
	do
	{
		system("cls");                      
    	printf("��� ����        �绰            �ʼ�                ��˾                ����  \n");    /*��ʽ*/ 
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
        printf("1:��һҳ                            2:��һҳ                             0:�˳�\n");
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
	FILE *fp;                                           //�����ļ�ָ��
	char filename[30];                                  //�ļ���
	printf("���������:\n");                          //�����ļ���
	printf("��������д��������ļ���:"); 
	scanf("%s",filename); 
	if((fp=fopen(filename,"rb"))==NULL)                   
	{ 
		printf("�޷����ļ�...\n"); 
		system("pause"); 
		return; 
	} 
	fread(&bn,sizeof(int),1,fp);
	fread(&black,sizeof(int),bn+1,fp);
	fread(&n,sizeof(int),1,fp);
	fread(per,sizeof(Person),n+1,fp);
	fclose(fp);
	printf("����ɹ���\n");
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
	printf("�����������ڵ���ϵ������:"); 
	fflush(stdin);
	gets(s); 
	while(strcmp(per[i].name,s)!=0&&i<=n) i++; 
	if(i>n) 
	{
		printf("��������û�д���!\n");
		system("pause"); 
		return; 
	} 
	printf("����ϵ����Ϣ:\n��ţ�%d\n",i);
	printf("������");puts(per[i].name);
	printf("�绰��");puts(per[i].tel);
	printf("���䣺");puts(per[i].email);
	printf("��˾��");puts(per[i].company);
	printf("���ࣺ");puts(per[i].classify); 
	printf("�Ƿ�����?(����\"1\"���ڣ������\"1\"������)\n");
	fflush(stdin);
	c=getchar();
	if(c=='1')
	{
		bn+=1;
	    black[bn]=i;
	    printf("�ɹ�����!\n");
	    system("pause");
	}
	return;
}



void Blackesheet_out()
{
	char s[12],c; 
	int i=1,j; 
	printf("��������ָ�����ϵ������:"); 
	fflush(stdin);
	gets(s); 
	while(strcmp(per[black[i]].name,s)!=0&&i<=n) i++; 
	if(i>bn) 
	{
		printf("��������û�д���!\n");
		system("pause"); 
		return; 
	} 
	printf("����ϵ����Ϣ:\n��ţ�%d\n",i);
	printf("������");puts(per[black[i]].name);
	printf("�绰��");puts(per[black[i]].tel);
	printf("���䣺");puts(per[black[i]].email);
	printf("��˾��");puts(per[black[i]].company);
	printf("���ࣺ");puts(per[black[i]].classify); 
	printf("�Ƿ�ָ�?(����\"1\"�ָ��������\"1\"������)\n");
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
	    printf("�ɹ��ָ�����ϵ����������!\n");
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
    	printf("��� ����        �绰            �ʼ�                ��˾                ����  \n");    /*��ʽ*/ 
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
        printf("1:��һҳ                            2:��һҳ                             0:�˳�\n");
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
	    printf("\t\t\t   *****ͨѶ������***** \n");                               
        printf("\t\t������������������������������������������\n");                   
	    printf("\t\t��\t        1. ���Ϊ������\t\t��\n"); 
	    printf("\t\t��\t        2. �������б�\t\t��\n"); 
	    printf("\t\t��\t        3. �ָ���������\t\t��\n");
	    printf("\t\t��\t        0. ������һ��\t\t��\n");
	    printf("\t\t������������������������������������������\n"); 
	    printf("\t\t\t����ѡ��(0-3):"); 
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
	    printf("\t\t\t   *****����ͨѶ¼***** \n");                               
        printf("\t\t������������������������������������������\n");                   
	    printf("\t\t��\t        1. ��������\t\t��\n"); 
	    printf("\t\t��\t        2. ��Ų���\t\t��\n"); 
	    printf("\t\t��\t        0. ������һ��\t\t��\n");
	    printf("\t\t������������������������������������������\n"); 
	    printf("\t\t\t����ѡ��(0-2):");
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
	    printf("\t\t\t   *****��ʾͨѶ¼***** \n");                               
        printf("\t\t��������������������������������������������\n");                   
	    printf("\t\t��\t        1. ��������ʾ\t\t  ��\n"); 
	    printf("\t\t��\t        2. �������ʾ\t\t  ��\n"); 
	    printf("\t\t��\t        0. ������һ��\t\t  ��\n");
	    printf("\t\t��������������������������������������������\n"); 
	    printf("\t\t\t����ѡ��(0-2):"); 
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
	    printf("\t\t\t   *****�༭ͨѶ¼***** \n");                               
        printf("\t\t������������������������������������������\n");                   
	    printf("\t\t��\t        1. ��Ӽ�¼\t\t��\n"); 
	    printf("\t\t��\t        2. ɾ����¼\t\t��\n"); 
	    printf("\t\t��\t        3. �޸ļ�¼\t\t��\n"); 
	    printf("\t\t��\t        0. ������һ��\t\t��\n");
	    printf("\t\t������������������������������������������\n"); 
	    printf("\t\t\t����ѡ��(0-3):"); 
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
	    printf("\t\t\t       *****ͨѶ¼***** \n");                               
        printf("\t\t��������������������������������������������\n");                   
	    printf("\t\t��\t      1. �༭ͨѶ¼\t\t  ��\n"); 
	    printf("\t\t��\t      2. ����ͨѶ¼\t\t  ��\n"); 
	    printf("\t\t��\t      3. ��ʾͨѶ¼\t\t  ��\n"); 
	    printf("\t\t��\t      4. ͨѶ������\t\t  ��\n");
        printf("\t\t��\t      5. д���ļ�  \t\t  ��\n");
	    printf("\t\t��\t      6. ��ȡ����  \t\t  ��\n");
	    printf("\t\t��\t      0. �˳�      \t\t  ��\n");
	    printf("\t\t��������������������������������������������\n"); 
	    printf("\t\t\t����ѡ��(0-6):"); 
	    fflush(stdin);
	    c=getchar();  
	}while(c<'0'||c>'6'); 
	return(c-'0'); 
} 
	
	
	
main()                                         //������ 
{
    welcome();  
	while(1) 
	{ 
		switch(main_select()) 
		{ 
		case 1: 
		       system("cls");
			   edit_select();                                       //�༭��¼ 
		       break; 
        case 2: 
     	       system("cls");
               search_select();									  //���Ҽ�¼ 
		       break;
		case 3:  
		       system("cls");
			   print_select();								  //��ʾ��¼ 
               break;
		case 4: 
		       system("cls"); 
			   Blacksheet_select();                                           //������ 
		       break;
        case 5: 
		       system("cls");
			   WritetoText();									     //д������ 
		       break; 
        case 6:
		       system("cls");
			   readfromfile();									     //��ȡ���� 
		       break;
     	case 0: 
		       system("cls");
		       save();
		       printf("ͨѶ¼�ѱ��棡\n");
			   exit(0); 
		} 
	} 
}
