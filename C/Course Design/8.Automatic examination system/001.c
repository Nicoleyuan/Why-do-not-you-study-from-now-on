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
//����ѡ����ж������Ŀ
void usage()
{
	printf(
		"+******************************+\n"
		"|        �Զ�����ϵͳ          |\n"
		"|    ���1501      ������      |\n"
		"|                              |\n"
		"|  A �½����  |  B �༭���   |\n"
		"|              |               |\n"
		"|  C ��ʼ����  |  D��ѯ�ɼ�    |\n"
		"|              |               |\n"
		"|  E�ɼ�����   |  F�˳�ϵͳ    |\n"
		"|                              |\n"
		"+******************************+\n"
		);
}
void buid(FILE *p1, FILE *p2)//������� 
{
 int choice_buid;
 printf("����1�½�ѡ���⣬����2�½��ж���\n");
 scanf("%d",&choice_buid);
 switch(choice_buid)
 {
 case 1:
 printf(
 "    �밴��һ�¸�ʽ����\n"
 "    @���+����+/��\n"
 "    ������ѡ����(��#����)\n"
 "******************************\n"
 );//˼���������Ѵ��ڵ���� 
 char i, ch;
 printf("������ѡ����(��#����)\n");
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
 "    �밴��һ�¸�ʽ����\n"
 "    @���+����\n"
 "    $��\n"
 "    ������ѡ����(��#����)\n"
 "******************************\n"
 );
 printf("�������ж���(��#����)\n");
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
void usage_edit()//�༭���ӽ��� 
{
 printf
 ("+*************************+\n"
 "                           \n"
 "        1,������Ŀ         \n"
 "        2,�޸���Ŀ         \n"
 "        3,ɾ����Ŀ         \n"
 "                           \n"
 "+*************************+\n");
}
void add(FILE *p1,FILE *p2)//������Ŀ 
{ 
 int choice_add;
 printf("���ѡ����������1���ж�������2\n");
 scanf("%d", &choice_add);
 char ch;
 switch (choice_add)
 {
  case 1:
  p1 = fopen("file1.txt", "a");
  printf(
 "    �밴��һ�¸�ʽ����\n"
 "    @���+����\n"
 "    $��\n"
 "    ������ѡ����(��#����)\n"
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
 "    �밴��һ�¸�ʽ����\n"
 "    @���+����\n"
 "    $��\n"
 "    �����������(��#����)\n"
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
void delet(FILE *p1,FILE *p2)//ɾ����Ŀ 
{ 
  int a1[10]={0};
  char ch,ch1;
  FILE *ftp;
  int choice_dele; 
  int a[10]={0};int i=0,num=0;  
  printf("ɾ��ѡ��������1���ж�������2\n");
  scanf("%d",&choice_dele);
  switch(choice_dele)
  {
  case 1:   
  printf("������Ҫɾ�������\n");
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
  printf("������Ҫɾ�������\n");
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
void changes()//�޸���Ŀ
{
 int i=0; 
 FILE *p1;FILE *p2;
 FILE *ftp;
 char linebuffer[512];
 char ch,ch1;
 int choice=0;
 int c_num=0;int num=0;//��Ҫ�޸ĵ���� 
 int jrh=1;
 printf("�޸�ѡ����������1���ж�������2\n");
 scanf("%d",&choice);
 switch(choice)
 {
 case 1:
 printf("��������Ҫ�޸ĵ����\n");
 scanf("%d",&c_num);
 printf("�������޸Ĺ������Ŀ\n");
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
 printf("��������Ҫ�޸ĵ����\n");
 scanf("%d",&c_num);
 printf("�������޸Ĺ������Ŀ\n");
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
void edit(FILE *p1,FILE *p2)//�༭ 
{
	usage_edit();
    int choice_edit;
	scanf("%d", &choice_edit);
	switch (choice_edit)
	{
	case 1: //������Ŀ                       
	add(p1,p2);
    break;
    case 2: 
    changes(); 
    break;//�޸���Ŀ                       
	case 3://ɾ����Ŀ                       
	delet(p1,p2);
    fflush(stdin);
    printf("ɾ���ɹ�\n");
    break;
    }   
}
void sum(int *num1,int *num2,FILE *p1,FILE *p2)//����ѡ������ж�������� 
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
void radom(int choices[10],int judge[10],int num_choices,int num_judge)//����������                
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
 printf("�ܷ���:%d\n",neww->score);
}
void show(char anwser_choice[10],char anwser_judge[10],struct student *neww,FILE *p1,FILE *p2,int choices[10],int judge[10])//��ʾ��ȷ�𰸺��Լ��Ĵ��ܷ� 
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
     printf("��ȷ����%c\n",linebuffer[1]);
     printf("��Ĵ���%c\n",anwser_choice[n]);
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
     printf("��ȷ����%c\n",linebuffer[1]);
     printf("��Ĵ���%c\n",anwser_judge[n]);
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
void data_save(FILE *p,struct student *neww)//ѧ����Ϣ����
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
 printf("���������ѧ��:");
 scanf("%lld", &neww->id);
 printf("�������������:");
 scanf("%s", &neww->name); 
 return(neww);
}
struct student *analyze(struct student *head,struct student *tail1,struct student *neww)//�ɼ����� 
{
 int low=0,mid1=0,mid2=0,mid3=0,high=0;
 int max,min1;
 long long int average=0,pnum=0;
 struct student *p1=NULL;
 struct student *first=NULL; /*���к��������ı�ͷָ��*/
 struct student *tail=NULL; /*���к��������ı�βָ��*/ 
 struct student *p_min=NULL; /*������ֵ��С�Ľڵ��ǰ���ڵ��ָ��*/
 struct student *min=NULL; /*�洢��С�ڵ�*/ 
 struct student *p=NULL; /*��ǰ�ȽϵĽڵ�*/
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
 while (head != NULL) /*���������Ҽ�ֵ��С�Ľڵ㡣*/
 {
  /*ע�⣺����for����������ѡ������˼��ĵط�*/
  for (p=head,min=head; p->next!=NULL; p=p->next) /*ѭ�����������еĽڵ㣬�ҳ���ʱ��С�Ľڵ㡣*/
  {   
   if (p->next->id< min->id) /*�ҵ�һ���ȵ�ǰminС�Ľڵ㡣*/
   {
    p_min = p; /*�����ҵ��ڵ��ǰ���ڵ㣺��Ȼp->next��ǰ���ڵ���p��*/
    min = p->next; /*�����ֵ��С�Ľڵ㡣*/
   } 
  }
  
  /*����for�������󣬾�Ҫ�������£�һ�ǰ����������������У����Ǹ�����Ӧ�������жϣ��������뿪ԭ��������*/
  
  /*��һ����*/
  if (first == NULL) /*�����������Ŀǰ����һ��������*/
  {
   first = min; /*��һ���ҵ���ֵ��С�Ľڵ㡣*/
   tail = min; /*ע�⣺βָ������ָ������һ���ڵ㡣*/
  }
  else /*�����������Ѿ��нڵ�*/
  {
   tail->next = min; /*�Ѹ��ҵ�����С�ڵ�ŵ���󣬼���βָ���nextָ������*/
   tail = min; /*βָ��ҲҪָ������*/
  } 

  /*�ڶ�����*/
  if (min == head) /*����ҵ�����С�ڵ���ǵ�һ���ڵ�*/
  {
   head = head->next; /*��Ȼ��headָ��ԭhead->next,���ڶ����ڵ㣬��OK*/
  }
  else /*������ǵ�һ���ڵ�*/
  {
   p_min->next = min->next; /*ǰ����С�ڵ��nextָ��ǰmin��next,��������min�뿪��ԭ����*/
  }  
}

 if (first != NULL) /*ѭ�������õ���������first*/
 {
  tail->next = NULL; /*������������һ���ڵ��nextӦ��ָ��NULL*/ 
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
printf("��߷�Ϊ%d����ͷ�Ϊ%d��ƽ����Ϊ%lld\n",max,min1,average/pnum);
printf("60������%d��\n",low);
printf("60��70��%d��\n",mid1);
printf("70��80��%d��\n",mid2);
printf("80��90��%d��\n",mid3);
printf("90�����ϵ�%d��\n",high);
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
 int choices[10], judge[10];//�����жϣ���ѡ�������� 
 FILE *p1; FILE *p2; FILE *num_name;//����ָ�� ѡ������ж����ָ�� 
 struct student *head, *tail1, *neww;
 char choice;//�û������ֵ 
 int choice_edit;
 head = NULL, tail1 = NULL, neww = NULL;
 while(change)
 {
  usage();
  printf("choice>:");
  choice = getchar();//ѡ����Ҫ���еĲ��� 
  sum(num1,num2,p1,p2);
  switch (choice)
  {
  case'a':case'A'://�½����                
  buid(p1, p2);fflush(stdin); break;
  case'b':case'B'://�༭��� 
  edit(p1,p2);
  fflush(stdin);break;
  case'c':case'C'://��ʼ����              
  neww=create(neww);//ѧ����Ϣ¼�� 
  radom(choices,judge,num_choices,num_judge);//���������� 
  fflush(stdin);
  exam(anwser_choice,anwser_judge,p1,p2,choices,judge,neww);//���� 
  data_save(num_name,neww);//�ɼ�chucun 
  show(anwser_choice,anwser_judge,neww,p1,p2,choices,judge);//չʾ�Դ� 
  fflush(stdin);
  break;
  case'd':case'D'://��ѯ�ɼ�              
  fflush(stdin);
  case'e':case'E'://�ɼ�����              
  head=analyze(head,tail1,neww);
  fflush(stdin);break;
  case'f':case'F'://�˳�ϵͳ
  goto end;
  default:printf("error\n");
  }
 } 
 system("PAUSE");
 end:return 0;
}