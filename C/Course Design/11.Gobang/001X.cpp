#include <stdio.h>
#include<windows.h>
#include <stdlib.h>
#include<conio.h>			//ʹ��getch()����

int startchoice,winner,player,Q[200][200]= {0};		//Q�����¼����
char button;										//������������ָ����

struct Point			//������Ľṹ��
{
    int x,y;
} point,game_xy;

struct Piece			//���ӵ������¼
{
    struct Point coord;
    struct Piece *fore;
};

struct Piece *head,*p,*ptr,*ptr1;

void goto_xy(int x, int y)          //����ƶ�����
{
    COORD c;
    c.X=2*x;
    c.Y=y;
    SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void Init()				//��ʼ������������¼���ӵ������ʼ��
{
    for(int i=0; i<200; i++)
        for(int j=0; j<200; j++)
            Q[i][j]=0;

    startchoice=0;
	player=1;
    p=(struct Piece *)malloc(sizeof(struct Piece));
    head=p;
}

void Welcome()      //��ӭ����
{
	system("color 2F");				//#include<windows.h>  2 ������ɫ  F  ��������ɫ
    goto_xy(10,3);
    printf("-��");
    goto_xy(17,1);
    printf("���˵�");
    goto_xy(13,3);
    printf("   ***���˶�ս***");
    goto_xy(13,4);
    printf("     ***�˳�***");
    point.x=12;
    point.y=3;
    goto_xy(0,0);
}

void Draw()                //�滭��Ϸ����
{   int m;
	game_xy.x=10;
    game_xy.y=3;
    system("cls");
    system("color 3F");			//3 ����ɫ  F ����ɫ
    goto_xy(15,1);
	const int i=8;				//const ��������ݲ����Ա��ı� �����޸����ݱȽϷ���
    const int j=19;
	const int k=3;

    for(int k1=0; k1<200; k1++)					//��ʼ�����Ӽ�¼���ڵڶ���ʱ����ȷ������
        for(int k2=0; k2<200; k2++)
            Q[k1][k2]=0;
//system("pause");
    for(m=0; m<18; m++)					//������
    {

        if(m==0)							//����һ��
        {
            goto_xy(10,m+3);
            printf("���ЩЩЩЩЩЩЩЩЩЩЩЩЩЩЩЩ�");

        }
        if(m!=0&&m!=17)						//�����м�16��
        {
            goto_xy(10,m+3);
            printf("��������������������");
        }
        if(m==17)							//�����һ��
        {
            goto_xy(10,m+3);
            printf("���ةةةةةةةةةةةةةةةة�");
        }
    }
    point.x=19;
    point.y=12;
    goto_xy(19,12);
}

void Clean()					//���-���˶��Ĺ켣
{
    goto_xy(10,3);
    printf("     ");
    goto_xy(24,3);
    printf("     ");
    goto_xy(10,4);
    printf("     ");
    goto_xy(24,4);
    printf("     ");
}

void menu_choose(char press)			//ѡ����Ϸ�����˳�
{
	if(press==72)				//����ASCLL��
    {
        if(point.y==3)
            point.y=4;
        else
            point.y=3;
        Clean();
        goto_xy(10,point.y);
        printf("-��");
    }
    if(press==80)			//����ASCLL��
    {
        if(point.y==4)
			point.y=3;
        else
			point.y=4;
        Clean();
        goto_xy(10,point.y);
        printf("-��");
    }
    if(press==13)		// 13���س�����ASCLL��
    {
        startchoice=point.y-2;				//startchoice Ϊ1��2
    }
}

void Record()              //��¼���ӵ����
{

    p->coord.x=point.x;
    p->coord.y=point.y;
    ptr=p;
    p=(struct Piece *)malloc(sizeof(struct Piece));
    p->fore=ptr;

    Q[point.x][point.y]=player+1;
    if(player)
    {
        player=0;
        return;
    }
    player=1;
    goto_xy(point.x,point.y);
}

void PutDown()					//��ʾ���Ӻ���
{
    if(Q[point.x][point.y]==0)				//���жϸ�λ���Ƿ�������
    {
        if(player)
        {
            printf("��");
            printf("\a");					//'\a'��ʾ������
            Record();
        }
		else
        {
            printf("��");
            printf("\a");
            Record();
        }
        goto_xy(point.x,point.y);
    }
}

void Play(char ch)					//���̵Ĳ��� �ƶ���� ����
{
    if(ch==72)			//����ASCLL�� �������
    {
        if(point.y<=3)
			point.y=20;
        else
			point.y--;
        goto_xy(point.x,point.y);

    }
    if(ch==75)						//����ASCLL��    �������
    {
        if(point.x<=10)
			point.x=27;
        else
			point.x--;
        goto_xy(point.x,point.y);

    }
    if(ch==77)						//����ASCLL��  �������
    {
        if(point.x>=27)
			point.x=10;
        else
			point.x++;
        goto_xy(point.x,point.y);

    }
    if(ch==80)						//����ASCLL��   �������
    {
        if(point.y>=20)
			point.y=3;
        else
			point.y++;
        goto_xy(point.x,point.y);

    }
    if(ch==13)				//�س�����ASCLL��		����
    {
        PutDown();
    }

    }


int Judge()
{
    int count=0;
    int pp=player==0?2:1;				//��Ŀ����
    for(int c=0; c<200; c++)
    {
        for(int r=0; r<200; r++)
        {
            if(Q[r][c]!=pp)
                continue;
			//�����
            int rr=r;
            int cc=c;
            while(--cc>=3 &&Q[rr][cc]==pp)
				count++;
            cc=c;
            while(++cc<23 &&Q[rr][cc]==pp)
				count++;
            cc=c;
            if(count>=4)
                return pp;
			//�����
            count=0;
            while(--rr>=10 &&Q[rr][cc]==pp)
				count++;
            rr=r;
            while(++rr<30 &&Q[rr][cc]==pp)
				count++;
            rr=r;
            if(count>=4)
                return pp;
			//��鷴б��
            count=0;
            cc--;
            rr--;
            while((cc>=3||rr>=10) &&Q[rr][cc]==pp)
            {
                count++;
                cc--;
                rr--;
            }
            rr=r;
            cc=c;
            cc++;
            rr++;
            while((cc<23||rr<30) &&Q[rr][cc]==pp)
            {
                count++;
                cc++;
                rr++;
            }
            rr=r;
            cc=c;
            if(count+1>=5)
                return pp;
			//�����б��
            count=0;
            cc++;
            rr--;
            while((cc<23||rr>=10) &&Q[rr][cc]==pp)
            {
                count++;
                cc++;
                rr--;
            }
            rr=r;
            cc=c;
            cc--;
            rr++;
            while((cc>=3||rr<30) &&Q[rr][cc]==pp)
            {
                count++;
                cc--;
                rr++;
            }
            rr=r;
            cc=c;
            if(count+1>=5)
                return pp;
            count=0;
        }
    }
    return 0;
}

int main(void)
{

    while(1)
    {
        Init();						//��ʼ��
        int winner=0;
        Welcome();					//��ӭ����

        while(1)					//��ȡ�˵�ѡ��
       {
            char choice=getch();
            menu_choose(choice);
            if(startchoice!=0)
                break;
        }
        startchoice=1;
        if(startchoice==1)				//ѡ�����˶�ս
        {

            Draw();
        
		    goto_xy(10,21);
            printf("��ɫΪ�׷����ӣ���ɫΪ�ҷ�����");
            goto_xy(point.x,point.y);//}
          
            while(1)
            {
                button=getch();
                Play(button);      //��ȡ���̵Ĳ��� �ƶ���� ����ͻ������

                if(button==27)			//ESC��ASCLL��
                {
					if(MessageBox(NULL,TEXT("ȷ���˳���"),TEXT(""),MB_ICONQUESTION|MB_OKCANCEL)==IDOK)
					{
						system("cls");
						printf("\n				ллʹ�ã�\n");
						return 0;
					}
				}

                if(button==13)				//�س���ASCLL��		���º�ʼ�ж���Ӯ
                    winner=Judge();

                if(winner!=0)
                {
                    goto_xy(15,24);
                    if(winner==2)
                    {
                        printf("��ϲ���׷�Ӯ��\n");
                    }
                    if(winner==1)
                    {
                        printf("��ϲ���ҷ�Ӯ��\n");
                    }
                }

                if(winner!=1&&winner!=2)
                {
                    continue;
                }

                goto_xy(13,22);
                printf("   ������Ϸ?(Y/N):    ");
                while(1)
                {
                    button=getch();
                    if(button=='n'||button=='N'||button=='y'||button=='Y')
                        break;
                }

                if(button=='n'||button=='N')
				{
					if(MessageBox(NULL,TEXT("  ȷ���˳���"),TEXT(""),MB_ICONQUESTION|MB_OKCANCEL)==IDOK)
					{
						system("cls");
						printf("\n				ллʹ�ã�\n");
						return 0;
					}
				}

                if(button=='y'||button=='Y')
                {
                    winner=0;
                    system("cls");
                    break;
                }

            }
        }

        if(startchoice==2)
        {
			if(MessageBox(NULL,TEXT("  ȷ���˳���"),TEXT(""),MB_ICONQUESTION|MB_OKCANCEL)==IDOK)
			{
				printf("\n\n				ллʹ�ã�\n");
				return 0;
			}
		}
    }
    return 0;
}