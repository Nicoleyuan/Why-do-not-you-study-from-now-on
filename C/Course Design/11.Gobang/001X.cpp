#include <stdio.h>
#include<windows.h>
#include <stdlib.h>
#include<conio.h>			//使用getch()函数

int startchoice,winner,player,Q[200][200]= {0};		//Q数组记录旗子
char button;										//读入键盘输入的指令，如→

struct Point			//点坐标的结构体
{
    int x,y;
} point,game_xy;

struct Piece			//棋子的坐标记录
{
    struct Point coord;
    struct Piece *fore;
};

struct Piece *head,*p,*ptr,*ptr1;

void goto_xy(int x, int y)          //光标移动函数
{
    COORD c;
    c.X=2*x;
    c.Y=y;
    SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void Init()				//初始化函数，将记录棋子的数组初始化
{
    for(int i=0; i<200; i++)
        for(int j=0; j<200; j++)
            Q[i][j]=0;

    startchoice=0;
	player=1;
    p=(struct Piece *)malloc(sizeof(struct Piece));
    head=p;
}

void Welcome()      //欢迎界面
{
	system("color 2F");				//#include<windows.h>  2 背景绿色  F  字体亮白色
    goto_xy(10,3);
    printf("-→");
    goto_xy(17,1);
    printf("主菜单");
    goto_xy(13,3);
    printf("   ***人人对战***");
    goto_xy(13,4);
    printf("     ***退出***");
    point.x=12;
    point.y=3;
    goto_xy(0,0);
}

void Draw()                //绘画游戏界面
{   int m;
	game_xy.x=10;
    game_xy.y=3;
    system("cls");
    system("color 3F");			//3 湖蓝色  F 亮白色
    goto_xy(15,1);
	const int i=8;				//const 定义的数据不可以被改变 而且修改数据比较方便
    const int j=19;
	const int k=3;

    for(int k1=0; k1<200; k1++)					//初始化棋子记录，在第二局时有明确的作用
        for(int k2=0; k2<200; k2++)
            Q[k1][k2]=0;
//system("pause");
    for(m=0; m<18; m++)					//画棋盘
    {

        if(m==0)							//画第一行
        {
            goto_xy(10,m+3);
            printf("┌┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┐");

        }
        if(m!=0&&m!=17)						//画出中间16行
        {
            goto_xy(10,m+3);
            printf("├┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┼┤");
        }
        if(m==17)							//画最后一行
        {
            goto_xy(10,m+3);
            printf("└┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┴┘");
        }
    }
    point.x=19;
    point.y=12;
    goto_xy(19,12);
}

void Clean()					//清除-→运动的轨迹
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

void menu_choose(char press)			//选择游戏还是退出
{
	if(press==72)				//↑的ASCLL码
    {
        if(point.y==3)
            point.y=4;
        else
            point.y=3;
        Clean();
        goto_xy(10,point.y);
        printf("-→");
    }
    if(press==80)			//↓的ASCLL码
    {
        if(point.y==4)
			point.y=3;
        else
			point.y=4;
        Clean();
        goto_xy(10,point.y);
        printf("-→");
    }
    if(press==13)		// 13：回车键的ASCLL码
    {
        startchoice=point.y-2;				//startchoice 为1或2
    }
}

void Record()              //记录棋子的情况
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

void PutDown()					//显示落子函数
{
    if(Q[point.x][point.y]==0)				//先判断该位置是否有棋子
    {
        if(player)
        {
            printf("●");
            printf("\a");					//'\a'表示蜂鸣声
            Record();
        }
		else
        {
            printf("○");
            printf("\a");
            Record();
        }
        goto_xy(point.x,point.y);
    }
}

void Play(char ch)					//键盘的操作 移动光标 下棋
{
    if(ch==72)			//↑的ASCLL码 光标上移
    {
        if(point.y<=3)
			point.y=20;
        else
			point.y--;
        goto_xy(point.x,point.y);

    }
    if(ch==75)						//←的ASCLL码    光标左移
    {
        if(point.x<=10)
			point.x=27;
        else
			point.x--;
        goto_xy(point.x,point.y);

    }
    if(ch==77)						//→的ASCLL码  光标右移
    {
        if(point.x>=27)
			point.x=10;
        else
			point.x++;
        goto_xy(point.x,point.y);

    }
    if(ch==80)						//↓的ASCLL码   光标下移
    {
        if(point.y>=20)
			point.y=3;
        else
			point.y++;
        goto_xy(point.x,point.y);

    }
    if(ch==13)				//回车键的ASCLL码		下棋
    {
        PutDown();
    }

    }


int Judge()
{
    int count=0;
    int pp=player==0?2:1;				//三目运算
    for(int c=0; c<200; c++)
    {
        for(int r=0; r<200; r++)
        {
            if(Q[r][c]!=pp)
                continue;
			//检查列
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
			//检查行
            count=0;
            while(--rr>=10 &&Q[rr][cc]==pp)
				count++;
            rr=r;
            while(++rr<30 &&Q[rr][cc]==pp)
				count++;
            rr=r;
            if(count>=4)
                return pp;
			//检查反斜边
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
			//检查正斜边
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
        Init();						//初始化
        int winner=0;
        Welcome();					//欢迎界面

        while(1)					//读取菜单选项
       {
            char choice=getch();
            menu_choose(choice);
            if(startchoice!=0)
                break;
        }
        startchoice=1;
        if(startchoice==1)				//选择人人对战
        {

            Draw();
        
		    goto_xy(10,21);
            printf("白色为甲方落子，黑色为乙方落子");
            goto_xy(point.x,point.y);//}
          
            while(1)
            {
                button=getch();
                Play(button);      //读取键盘的操作 移动光标 下棋和悔棋操作

                if(button==27)			//ESC的ASCLL码
                {
					if(MessageBox(NULL,TEXT("确定退出？"),TEXT(""),MB_ICONQUESTION|MB_OKCANCEL)==IDOK)
					{
						system("cls");
						printf("\n				谢谢使用！\n");
						return 0;
					}
				}

                if(button==13)				//回车键ASCLL码		按下后开始判断输赢
                    winner=Judge();

                if(winner!=0)
                {
                    goto_xy(15,24);
                    if(winner==2)
                    {
                        printf("恭喜！甲方赢！\n");
                    }
                    if(winner==1)
                    {
                        printf("恭喜！乙方赢！\n");
                    }
                }

                if(winner!=1&&winner!=2)
                {
                    continue;
                }

                goto_xy(13,22);
                printf("   继续游戏?(Y/N):    ");
                while(1)
                {
                    button=getch();
                    if(button=='n'||button=='N'||button=='y'||button=='Y')
                        break;
                }

                if(button=='n'||button=='N')
				{
					if(MessageBox(NULL,TEXT("  确定退出？"),TEXT(""),MB_ICONQUESTION|MB_OKCANCEL)==IDOK)
					{
						system("cls");
						printf("\n				谢谢使用！\n");
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
			if(MessageBox(NULL,TEXT("  确定退出？"),TEXT(""),MB_ICONQUESTION|MB_OKCANCEL)==IDOK)
			{
				printf("\n\n				谢谢使用！\n");
				return 0;
			}
		}
    }
    return 0;
}
