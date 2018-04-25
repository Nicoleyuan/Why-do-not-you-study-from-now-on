#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <stdarg.h>
#include<time.h>
#include<malloc.h>
struct student
{
    long  long int id;
	char name[50];
	int score;
	struct student *next;
};
//定义选择和判断题的数目
void usage()
{
	printf(
		"+******************************+\n"
		"|        自动考试系统          |\n"
		"|    软件1501      冀若含      |\n"
		"|                              |\n"
		"|  A 新建题库  |  B 编辑题库   |\n"
		"|              |               |\n"
		"|  C 开始考试  |  D查询成绩    |\n"
		"|              |               |\n"
		"|  E成绩分析   |  F退出系统    |\n"
		"|                              |\n"
		"+******************************+\n"
		);
}
void buid(FILE *p1, FILE *p2)//建立题库 
{
 int choice_buid;
 printf("输入1新建选择题，输入2新建判断题\n");
 scanf("%d",&choice_buid);
 switch(choice_buid)
 {
 case 1:
 printf(
 "    请按照一下格式输入\n"
 "    @题号+内容+/答案\n"
 "    请输入选择题(以#结束)\n"
 "******************************\n"
 );//思考如果题库已存在的情况 
 char i, ch;
 printf("请输入选择题(以#结束)\n");
 ch = '\0';
 p1 = fopen("file1.txt", "w");
 ch = getchar();
 while (ch != '#')
 {
 fputc(ch, p1);
 ch = getchar();
 }
 fclose(p1);
 case 2: 
 printf(
 "    请按照一下格式输入\n"
 "    @题号+内容\n"
 "    $答案\n"
 "    请输入选择题(以#结束)\n"
 "******************************\n"
 );
 printf("请输入判断题(以#结束)\n");
 ch = '\0';
 p2 = fopen("file2.txt", "w");
 ch = getchar();
 while (ch != '#')
 {
  fputc(ch, p2);
  ch = getchar();
 }
 fclose(p2);
 break;
 }			   
}
void usage_edit()//编辑的子界面 
{
 printf
 ("+*************************+\n"
 "                           \n"
 "        1,增加题目         \n"
 "        2,修改题目         \n"
 "        3,删除题目         \n"
 "                           \n"
 "+*************************+\n");
}
void add(FILE *p1,FILE *p2)//增加题目 
{ 
 int choice_add;
 printf("添加选择题请输入1，判断题请输2\n");
 scanf("%d", &choice_add);
 char ch;
 switch (choice_add)
 {
  case 1:
  p1 = fopen("file1.txt", "a");
  printf(
 "    请按照一下格式输入\n"
 "    @题号+内容\n"
 "    $答案\n"
 "    请输入选择题(以#结束)\n"
 "******************************\n"
  );
  ch = getchar();
  while (ch != '#')
  {
	fputc(ch, p1);
	ch = getchar();
  }
  fclose(p1);
  break;
 case 2:
 p2 = fopen("file2.txt", "a");
  printf(
 "    请按照一下格式输入\n"
 "    @题号+内容\n"
 "    $答案\n"
 "    请输入填空题(以#结束)\n"
 "******************************\n"
  );
  ch = getchar();
  while (ch != '#')
  {
	fputc(ch, p1);
	ch = getchar();
  }
  fclose(p2);
  break;
 }

} 
void delet(FILE *p1,FILE *p2)//删除题目 
{ 
  int a1[10]={0};
  char ch,ch1;
  FILE *ftp;
  int choice_dele; 
  int a[10]={0};int i=0,num=0;  
  printf("删除选择题输入1，判断题输入2\n");
  scanf("%d",&choice_dele);
  switch(choice_dele)
  {
  case 1:   
  printf("请输入要删除的题号\n");
  scanf("%d",&a[i]);
  while(a[i]!=0)
  {
  i++;
  scanf("%d",&a[i]);
  }
  i=0;
  p1=fopen("file1.txt","r");   
  ftp=fopen("tmp.txt","w");    
  if(p1==NULL||ftp==NULL)    
  {
  printf("Open the file fail\n");                        
  exit(0); 
  }    
  while (fscanf(p1, "%c", &ch) != EOF)
  {
  if(ch==64)      
  num++;      
  if(num==a[i])
  {
  i++;            
  }
  if(num!=a[i-1])      
  {
  fputc(ch,ftp);
  }      
  }
  fclose(p1);
  fclose(ftp);
  remove("file1.txt");
  rename("tmp.txt","file1.txt");
  p1=fopen("file1.txt","r+");
  break;
  case 2: 
  i=0;num=0;    
  printf("请输入要删除的题号\n");
  scanf("%d",&a1[i]);
  while(a1[i]!=0)
  {
  i++;
  scanf("%d",&a1[i]);
  }
  i=0;
  p1=fopen("file2.txt","r");   
  ftp=fopen("tmp.txt","w");    
  if(p2==NULL||ftp==NULL)    
  {
  printf("Open the file fail\n");                        
  exit(0); 
  }    
  while (fscanf(p2, "%c", &ch1) != EOF)
  {
  if(ch1==64)      
  num++;      
  if(num==a1[i])
  {
  i++;            
  }
  if(num!=a1[i-1])      
  {
  fputc(ch1,ftp);
  }      
  }
  fclose(p2);
  fclose(ftp);
  remove("file2.txt");
  rename("tmp.txt","file2.txt");
  p1=fopen("file2.txt","r+");
  break;     
  }
} 
void changes()//修改题目
{
 int i=0; 
 FILE *p1;FILE *p2;
 FILE *ftp;
 char linebuffer[512];
 char ch,ch1;
 int choice=0;
 int c_num=0;int num=0;//你要修改的题号 
 int jrh=1;
 printf("修改选择题请输入1，判断题输入2\n");
 scanf("%d",&choice);
 switch(choice)
 {
 case 1:
 printf("请输入你要修改的题号\n");
 scanf("%d",&c_num);
 printf("请输入修改过后的题目\n");
 scanf("%s",linebuffer);
 p1=fopen("file1.txt","r");   
 ftp=fopen("tmp.txt","w");    
 if(p1==NULL||ftp==NULL)    
 {
 printf("Open the file fail\n");                        
 exit(0); 
 }    
 while (fscanf(p1, "%c", &ch) != EOF)
 {
 if(ch==64)      
 num++;      
 if(num!=c_num)      
 {
 fputc(ch,ftp);
 }      
 if(num==c_num&&jrh!=0)
 {
 fprintf(ftp,"%s",linebuffer);            
 fprintf(ftp,"\n");
 jrh=0;
 }
 }
 fclose(p1);
 fclose(ftp);
 remove("file1.txt");
 rename("tmp.txt","file1.txt");break;
 case 2:
 printf("请输入你要修改的题号\n");
 scanf("%d",&c_num);
 printf("请输入修改过后的题目\n");
 scanf("%s",linebuffer);
 if(p2==NULL||ftp==NULL)    
 {
 printf("Open the file fail\n");                        
 exit(0); 
 }    
 while (fscanf(p2, "%c", &ch1) != EOF)
 {
 if(ch1==64)      
 num++;      
 if(num!=c_num)      
 {
 fputc(ch1,ftp);
 }      
  if(num=c_num&&jrh!=0)
 {
 fprintf(ftp,"%s",linebuffer); 
 fprintf(ftp,"\n"); 
 jrh=0;
 }
 }
 fclose(p2);
 fclose(ftp);
 remove("file2.txt");
 rename("tmp.txt","file2.txt");
 p1=fopen("file2.txt","r+");
 break;     
 }
}
void edit(FILE *p1,FILE *p2)//编辑 
{
	usage_edit();
    int choice_edit;
	scanf("%d", &choice_edit);
	switch (choice_edit)
	{
	case 1: //增加题目                       
	add(p1,p2);
    break;
    case 2: 
    changes(); 
    break;//修改题目                       
	case 3://删除题目                       
	delet(p1,p2);
    fflush(stdin);
    printf("删除成功\n");
    break;
    }   
}
void sum(int *num1,int *num2,FILE *p1,FILE *p2)//计算选择题和判断题的总数 
{
 char ch,ch1;
 p1=fopen("file1.txt","r");
 (*num1)=0;(*num2)=0;
 while (fscanf(p1, "%c", &ch) != EOF)
 {
  if (ch == 64)
  (*num1)++;
 }
 fflush(stdin);
 fclose(p1);
 p2=fopen("file2.txt","r");
 while(fscanf(p2,"%c",&ch1)!=EOF) 
 {
 if(ch1==64)
 (*num2)++;
 }
 fclose(p2);
 fflush(stdin);
}
void radom(int choices[10],int judge[10],int num_choices,int num_judge)//产生随机题号                
{
 int m,n=0,l,i,len=10,k,j;
 for(i=0;i<10;i++)     
 {
 choices[i]=0;
 }     
 for(i=0;i<10;i++)
 {
 judge[i]=0;                 
 }     
 int count=0,random;
 srand((unsigned)time(NULL));
 for(i=0;i<10;i++)
 choices[i]=(rand() % (num_choices)+1);
 for(l=1;l<10;l++) 
 {
 for(i=0;i<10-l;i++)
 {
 if(choices[i]>choices[i+1])
 {
 m=choices[i];
 choices[i]=choices[i+1];
 choices[i+1]=m;
 }
 }                         
 }
 i=0;j=0;k=0;
 while(i<10)
 {
 if(choices[i]==choices[i+1])
 {
 i++;k++;
 continue;
 }
 choices[j]=choices[i];j++;i++;           
 }
 len-=k;
 do
 {
  random=(rand() % (num_choices)+1);
  for(i=0;i<len;i++)
  {
  if(choices[i]!=random)
  j++;
  }
  if(j==len)
  {
  choices[len]=random;
  len++;j=0;count++;
  }
  else
  {
  j=0;
  continue;
  }
 }while(count!=k);
 for(l=1;l<10;l++) 
 {
 for(i=0;i<10-l;i++)
 {
 if(choices[i]>choices[i+1])
 {
 m=choices[i];
 choices[i]=choices[i+1];
 choices[i+1]=m;
 }
 }                         
 }
 srand((unsigned)time(NULL));
 count=0;len=10;
 for(i=0;i<10;i++)
 judge[i]=(rand() % (num_judge)+1);
 for(l=1;l<10;l++) 
 {
 for(i=0;i<10-l;i++)
 {
 if(judge[i]>judge[i+1])
 {
 m=judge[i];
 judge[i]=judge[i+1];
 judge[i+1]=m;
 }
 }                         
 }
 i=0;j=0;k=0;
 while(i<10)
 {
 if(judge[i]==judge[i+1])
 {
 i++;k++;
 continue;
 }
 judge[j]=judge[i];j++;i++;           
 }
 len-=k;
 do
 {
 random=(rand() % (num_choices)+1);
 for(i=0;i<len;i++)
 {
  if(judge[i]!=random)
  j++;
  }
  if(j==len)
  {
  judge[len]=random;
  len++;j=0;count++;
  }
  else
  {
  j=0;
  continue;
  }
 }while(count!=k);
 for(l=1;l<10;l++) 
 {
 for(i=0;i<10-l;i++)
 {
 if(judge[i]>judge[i+1])
 {
 m=judge[i];
 judge[i]=judge[i+1];
 judge[i+1]=m;
 }
 }                         
 }
 fflush(stdin);
}
void exam(char anwser_choice[10],char anwser_judge[10],FILE *p1,FILE *p2,int choices[10],int judge[10],struct student *neww) 
{
 int score=0;
 char linebuffer[512]={0};
 int num=0,i=0,n=0;
 p1=fopen("file1.txt","r"); 
 while(NULL!=fgets(linebuffer, 512, p1))
 {
  if(linebuffer[0]== 64 && num == choices[i])
  {
	i++;
  }
  if (linebuffer[0]== 64)
	num++;
	if (num == choices[i])
	{
     if(linebuffer[0]==36)
     {
     scanf("%c",&anwser_choice[n]);
     if((anwser_choice[n]==linebuffer[1])||(anwser_choice[n]-linebuffer[1]==32))
     {score=score+5;}
     n++;
     fflush(stdin);
     }
     if(linebuffer[0]!=36)
     puts(linebuffer); 
     fflush(stdin);
    }
  }
 fclose(p1);
 p2 = fopen("file2.txt", "r");
 num=0;n=0;i=0;
 while(NULL!=fgets(linebuffer, 512, p2))
 {
  if (linebuffer[0]== 64 && num == judge[i])
  {
	i++;
  }
  if (linebuffer[0]== 64)
	num++;
	if (num == judge[i])
	{
     if(linebuffer[0]==36)
     {
     scanf("%c",&anwser_judge[n]);
     if((linebuffer[1]==anwser_judge[n])||(anwser_judge[n]-linebuffer[1]==32))
     {score=score+5;}
     n++;
     fflush(stdin);
     }
     if(linebuffer[0]!=36)
     puts(linebuffer); 
	 fflush(stdin);
    }
 }
 fclose(p2);
 neww->score=score;
 system("cls");
 puts(neww->name);
 printf("总分是:%d\n",neww->score);
}
void show(char anwser_choice[10],char anwser_judge[10],struct student *neww,FILE *p1,FILE *p2,int choices[10],int judge[10])//显示正确答案和自己的答案总分 
{
 char linebuffer[512]={0};
 int num=0,i=0,n=0;
 p1=fopen("file1.txt","r"); 
 while(NULL!=fgets(linebuffer, 512, p1))
 {
  if(linebuffer[0]== 64 && num == choices[i])
  {
	i++;
  }
  if (linebuffer[0]== 64)
	num++;
	if (num == choices[i])
	{
     if(linebuffer[0]==36)
     {
     printf("正确答案是%c\n",linebuffer[1]);
     printf("你的答案是%c\n",anwser_choice[n]);
     getchar();
     n++;
     fflush(stdin);
     }
     if(linebuffer[0]!=36)
     puts(linebuffer); 
     fflush(stdin);
    }
  }
 fclose(p1);
 p2 = fopen("file2.txt", "r");
 num=0;n=0;i=0;
 while(NULL!=fgets(linebuffer, 512, p2))
 {
  if (linebuffer[0]== 64 && num == judge[i])
  {
	i++;
  }
  if (linebuffer[0]== 64)
	num++;
	if (num == judge[i])
	{
     if(linebuffer[0]==36)
     {
     printf("正确答案是%c\n",linebuffer[1]);
     printf("你的答案是%c\n",anwser_judge[n]);
     getchar();
     n++;
     fflush(stdin);
     }
     if(linebuffer[0]!=36)
     puts(linebuffer); 
	 fflush(stdin);
    }
 }
 fclose(p2);
}
void data_save(FILE *p,struct student *neww)//学生信息储存
{
p=fopen("num_name.txt","a+");
fprintf(p,"%lld",neww->id);     
fprintf(p,"\n"); 
fprintf(p,"%s",neww->name);
fprintf(p,"\n"); 
fprintf(p,"%d",neww->score);
fprintf(p,"\n"); 
free(neww); 
fclose(p);
} 
struct student *create(struct student *neww)
{
 neww =(struct student *)malloc(sizeof(struct student));
 printf("请输入你的学号:");
 scanf("%lld", &neww->id);
 printf("请输入你的名字:");
 scanf("%s", &neww->name); 
 return(neww);
}
struct student *analyze(struct student *head,struct student *tail1,struct student *neww)//成绩分析 
{
 int low=0,mid1=0,mid2=0,mid3=0,high=0;
 int max,min1;
 long long int average=0,pnum=0;
 struct student *p1=NULL;
 struct student *first=NULL; /*排列后有序链的表头指针*/
 struct student *tail=NULL; /*排列后有序链的表尾指针*/ 
 struct student *p_min=NULL; /*保留键值更小的节点的前驱节点的指针*/
 struct student *min=NULL; /*存储最小节点*/ 
 struct student *p=NULL; /*当前比较的节点*/
 FILE *num_name;
 long long int id1;
 char name1[50];
 int score1;   
 num_name=fopen("num_name.txt","r");               
 head=(struct student *)malloc(sizeof(struct student)); 
 fscanf(num_name,"%lld",&id1); 
 fscanf(num_name,"%s",name1); 
 fscanf(num_name,"%d",&score1);
 head->id=id1;
 head->score=score1;
 strcpy(head->name,name1);
 tail1=neww=head;              
 while(EOF!=fscanf(num_name,"%lld",&id1))                
 {
 neww=(struct student *)malloc(sizeof(struct student));                               
 fscanf(num_name,"%s",name1); 
 fscanf(num_name,"%d",&score1);
 neww->id=id1;
 neww->score=score1;
 strcpy(neww->name,name1);                         
 tail1->next=neww;
 tail1=neww;                              
 } 
tail1->next=NULL;
 first = NULL;
 while (head != NULL) /*在链表中找键值最小的节点。*/
 {
  /*注意：这里for语句就是体现选择排序思想的地方*/
  for (p=head,min=head; p->next!=NULL; p=p->next) /*循环遍历链表中的节点，找出此时最小的节点。*/
  {   
   if (p->next->id< min->id) /*找到一个比当前min小的节点。*/
   {
    p_min = p; /*保存找到节点的前驱节点：显然p->next的前驱节点是p。*/
    min = p->next; /*保存键值更小的节点。*/
   } 
  }
  
  /*上面for语句结束后，就要做两件事；一是把它放入有序链表中；二是根据相应的条件判断，安排它离开原来的链表。*/
  
  /*第一件事*/
  if (first == NULL) /*如果有序链表目前还是一个空链表*/
  {
   first = min; /*第一次找到键值最小的节点。*/
   tail = min; /*注意：尾指针让它指向最后的一个节点。*/
  }
  else /*有序链表中已经有节点*/
  {
   tail->next = min; /*把刚找到的最小节点放到最后，即让尾指针的next指向它。*/
   tail = min; /*尾指针也要指向它。*/
  } 

  /*第二件事*/
  if (min == head) /*如果找到的最小节点就是第一个节点*/
  {
   head = head->next; /*显然让head指向原head->next,即第二个节点，就OK*/
  }
  else /*如果不是第一个节点*/
  {
   p_min->next = min->next; /*前次最小节点的next指向当前min的next,这样就让min离开了原链表。*/
  }  
}

 if (first != NULL) /*循环结束得到有序链表first*/
 {
  tail->next = NULL; /*单向链表的最后一个节点的next应该指向NULL*/ 
 }
 head = first;
for(p1=head;p1!=NULL;p1=p1->next) 
{
printf("%lld\n",p1->id);
puts(p1->name);
printf("%d\n",p1->score);   
}
max=min1=head->score;
for(p1=head;p1!=NULL;p1=p1->next) 
{
if(p1->score>max)
max=p1->score; 
if(min1>p1->score)
min1=p1->score;
average=average+p1->score;
pnum++;
if(p1->score<60)
low++;
else if(p1->score<70)
mid1++;
else if(p1->score<80)
mid2++;
else if(p1->score<90)
mid3++;
else if(p1->score<100)
high++;
}
printf("最高分为%d，最低分为%d，平均分为%lld\n",max,min1,average/pnum);
printf("60分以下%d人\n",low);
printf("60到70分%d人\n",mid1);
printf("70到80分%d人\n",mid2);
printf("80到90分%d人\n",mid3);
printf("90分以上的%d人\n",high);
fclose(num_name);
return head;
} 
int main(int argc, char *argv[])
{
 char anwser_choice[10];
 char anwser_judge[10];
 int change=1;
 int *num1,*num2;
 int num_choices=0,num_judge=0;
 num1=&num_choices;num2=&num_judge;
 int choices[10], judge[10];//定义判断，和选择题的题号 
 FILE *p1; FILE *p2; FILE *num_name;//定义指向 选择题和判断题的指针 
 struct student *head, *tail1, *neww;
 char choice;//用户输入的值 
 int choice_edit;
 head = NULL, tail1 = NULL, neww = NULL;
 while(change)
 {
  usage();
  printf("choice>:");
  choice = getchar();//选择你要进行的操作 
  sum(num1,num2,p1,p2);
  switch (choice)
  {
  case'a':case'A'://新建题库                
  buid(p1, p2);fflush(stdin); break;
  case'b':case'B'://编辑题库 
  edit(p1,p2);
  fflush(stdin);break;
  case'c':case'C'://开始考试              
  neww=create(neww);//学生信息录入 
  radom(choices,judge,num_choices,num_judge);//产生随机题号 
  fflush(stdin);
  exam(anwser_choice,anwser_judge,p1,p2,choices,judge,neww);//考试 
  data_save(num_name,neww);//成绩chucun 
  show(anwser_choice,anwser_judge,neww,p1,p2,choices,judge);//展示对错 
  fflush(stdin);
  break;
  case'd':case'D'://查询成绩              
  fflush(stdin);
  case'e':case'E'://成绩分析              
  head=analyze(head,tail1,neww);
  fflush(stdin);break;
  case'f':case'F'://退出系统
  goto end;
  default:printf("error\n");
  }
 } 
 system("PAUSE");
 end:return 0;
}