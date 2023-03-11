#include <stdio.h>
#include <Stdlib.h>
#include <conio.h>
#include <graphics.h>



int WIDTH_LEFT = 10;
int HEIGHT_TOP = 24;
int WIDTH_RIGHT = 600;
int HEIGHT_BOTTOM = 450;
int BALL_RADIUS = 10;
float BALL_POS_X = 295;
float BALL_POS_Y = 220;
float PADDLE_POS_TOP1 = 175;
float PADDLE_POS_BOTTOM1 = 260;
float PADDLE_POS_TOP2 = 175;
float PADDLE_POS_BOTTOM2 = 260;
float PAD_HEIGHT = 52 ;
int score(int);
int score1 = 0;
int score2 = 0;

void main()
{
char name1[50], name2[50];
int x,y=0,t=HEIGHT_TOP,c=1,d=1,ch,chh;
//int count1=0,count2=0;
int bh;
float i = 5 , j=5 ;
int gd=DETECT,gm;
	printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t PONG");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n press any key to continue_____");
	getch();
	system("cls");
printf("Enter name of player I:");
gets(name1);
printf("Enter name of player II:");
gets(name2);
initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
setbkcolor(BLUE);
bar(20,193,25,245);
bar(585,193,590,245);
start:
for(x=200;x<=getmaxx();x=x+2)
{

bar(20,PADDLE_POS_TOP1,25,PADDLE_POS_BOTTOM1);
bar(585,PADDLE_POS_TOP2,590,PADDLE_POS_BOTTOM2);


rectangle(WIDTH_LEFT,HEIGHT_TOP-20,WIDTH_RIGHT,HEIGHT_BOTTOM);
//floodfill(5,MAXHEIGHT+3,WHITE);
//Draw Ball
pieslice(x-20,y-20,0,360,10);
//floodfill(x,y,RED);
delay(100);
if(y>=HEIGHT_BOTTOM)
{
c=0;
//t=t-40;
}
if(y<=HEIGHT_TOP)
{
c=1;
}
if(t>=24)
{
       //	if ((y<=PADDLE_POS_TOP1 && y>=PADDLE_POS_BOTTOM1)||(y<=PADDLE_POS_TOP2 && y>=PADDLE_POS_BOTTOM2))
		y=y+(c?10:-10);
}
if (x == 40)
{
if (y<PADDLE_POS_BOTTOM1 && y>PADDLE_POS_TOP1)
{
	d = 1;
}
else
	goto xx;
}
if (x >=575)
{
if (y<PADDLE_POS_BOTTOM2 && y>PADDLE_POS_TOP2)
	d=0;
}
if (x>600)
{
	score1=score(score1);
	goto xx;
}
if (x ==20 || x==585 )
{
	//if (x>=(PADDLE_POS_TOP2-PADDLE_POS_BOTTOM2)||x<=(PADDLE_POS_TOP1-PADDLE_POS_BOTTOM1))
		d = 0;
}
if (x < 0)
{
	score2=score(score2);
	goto xx;
	}
if (t>=10)
{
	//if (x > PADDLE_POS_TOP2 && y < PADDLE_POS_TOP2)
		x = x + (d? 10:-10);

	}
//if (t <= 600)
// x = x+(d?15:-15);
if (kbhit())
{
	ch = getch();
	if (ch==115)
	{
		PADDLE_POS_TOP1 = PADDLE_POS_TOP1 + i;
		PADDLE_POS_BOTTOM1 = PADDLE_POS_BOTTOM1 + i;
		//bar(20,PADDLE_POS_TOP1,25,PADDLE_POS_BOTTOM1);
	}
	if (ch==119)
	{
		PADDLE_POS_TOP1 = PADDLE_POS_TOP1 - i;
		PADDLE_POS_BOTTOM1 = PADDLE_POS_BOTTOM1 - i;
		//bar(20,PADDLE_POS_TOP1,25,PADDLE_POS_BOTTOM1);
	}
	if (ch==111)
	{
		PADDLE_POS_TOP2 = PADDLE_POS_TOP2 - j;
		PADDLE_POS_BOTTOM2 = PADDLE_POS_BOTTOM2 - j;
		//bar(20,PADDLE_POS_TOP2,25,PADDLE_POS_BOTTOM2);
	}
	if (ch==107)
	{
		PADDLE_POS_TOP2 = PADDLE_POS_TOP2  + j;
		PADDLE_POS_BOTTOM2 = PADDLE_POS_BOTTOM2 + j;
		//bar(20,PADDLE_POS_TOP2,25,PADDLE_POS_BOTTOM2);
	}
	if (ch == 27)
		exit(0);
}
cleardevice();
//Exit upon keypress
//outtext(25,455 , name1);
//outtext(550,455 , name2);
}
xx:
//if (count1 == 3 || count2 == 3)
       //	{
	 //	outtextxy(245,200,"GAME OVER");
	   //	if (count1 == 3)
	     //		outtextxy(245,220,"PLAYER2 WINS");
	       //	else
		 //	outtextxy(245,220,"PLAYER1 WINS");

		   //	}
//else
//{
	outtextxy(220,200,"PRESS 'b' TO RESPAWN THE BALL");
	bh = getch();
	if (bh == 98)
	{
		goto start;
		}
//}
getch();
closegraph();
}
int score(int c)
{
	c++;
	return c;
}



