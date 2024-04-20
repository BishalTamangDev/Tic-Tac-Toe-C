//tic-tac-toe
#include<stdio.h>
#include<dos.h>
#include<stdlib.h>
#include<conio.h>
#include<graphics.h>

void newgame();
int compare(int *,int *);

int x=640,y=400;

void main()
{
	int ch;

	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

	settextstyle(1,HORIZ_DIR,5);
	outtextxy(x/2-118,y/2-150,"Tic-Tac-Toe");

	settextstyle(1,HORIZ_DIR,2);
	outtextxy(x/2-70,y/2-40,"New Game");
	outtextxy(x/2+50,y/2-40,"[1]");
	outtextxy(x/2-70,y/2,"Quit");
	outtextxy(x/2+50,y/2,"[2]");

	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t");
	scanf("%d",&ch);

	if(ch==1)
		newgame();
	else
		exit(0);

	getch();
	closegraph();
}

void newgame()
{
	int numbers[9];
	int i,j=0,k=0,l=0,m;
	int choice,cmp=0;
	int a1[5],a2[5];
	clrscr();

	for(m=0;m<9;m++)
		numbers[m]=99;

	for(m=0;m<5;m++)
		a1[m]=99;

	for(m=0;m<5;m++)
		a2[m]=99;

	m=0;
	i=1;
	do
	{
		if(i==10)
			break;
			
		setfillstyle(1,BLACK);
		floodfill(20,20,WHITE);

		settextstyle(1,HORIZ_DIR,5);
		setcolor(WHITE);
		outtextxy(x/2-118,y/2-150,"Tic-Tac-Toe");

		setcolor(GREEN);
		settextstyle(1,HORIZ_DIR,1);
		outtextxy(x/2-230,y/2-100,"Player 1 ");

		setcolor(RED);
		settextstyle(1,HORIZ_DIR,1);
		outtextxy(x/2+170,y/2-100,"Player 2");

		//playbox
		setcolor(WHITE);
		rectangle(x/2-90,y/2-90,x/2+90,y/2+90);

		//horizontal line
		line(x/2-90,y/2-30,x/2+90,y/2-30);
		line(x/2-90,y/2+30,x/2+90,y/2+30);

		//vertical line
		line(x/2-30,y/2-90,x/2-30,y/2+90);
		line(x/2+30,y/2-90,x/2+30,y/2+90);

		outtextxy(x/2-60,y/2-75,"7");
		outtextxy(x/2-0 ,y/2-75,"8");
		outtextxy(x/2+60,y/2-75,"9");

		outtextxy(x/2-60,y/2-10,"4");
		outtextxy(x/2-0 ,y/2-10,"5");
		outtextxy(x/2+60,y/2-10,"6");

		outtextxy(x/2-60,y/2+60,"1");
		outtextxy(x/2-0 ,y/2+60,"2");
		outtextxy(x/2+60,y/2+60,"3");

		loop1:
		if(i%2!=0)
		{
			setcolor(GREEN);
			setfillstyle(1,GREEN);
			outtextxy(x/2-230,y/2-80,"Your turn");
		}
		else
		{
			setcolor(RED);
			setfillstyle(1,RED);
			outtextxy(x/2+170,y/2-80,"Your turn");
		}

		outtextxy(x/2-50,y/2+150,"Your Choice : ");
		scanf("%d",&choice);

		if(i>1)
		{
			for(l=0;l<9;l++)
			{
				if(choice==numbers[l])
				{
					outtextxy(x/2-50,y/2+170,"Number Already Taken :( ");
					delay(250);
					setfillstyle(1,BLACK);
					bar(x/2-50,y/2+170,x/2+185,y/2+195);
					goto loop1;
				}
			}
		}
		
		if(choice==1)
			floodfill(x/2-60,y/2+60,WHITE);
		else if(choice==2)
			floodfill(x/2,y/2+60,WHITE);
		else if(choice==3)
			floodfill(x/2+60,y/2+60,WHITE);
		else if(choice==4)
			floodfill(x/2-60,y/2,WHITE);
		else if(choice==5)
			floodfill(x/2,y/2+10,WHITE);
		else if(choice==6)
			floodfill(x/2+60,y/2+10,WHITE);
		else if(choice==7)
			floodfill(x/2-60,y/2-60,WHITE);
		else if(choice==8)
			floodfill(x/2,y/2-85,WHITE);
		else if(choice==9)
			floodfill(x/2+60,y/2-60,WHITE);
		else
		{
			outtextxy(x/2-50,y/2+170,"Invalid Choice :( ");
			delay(500);
			setfillstyle(1,BLACK);
			bar(x/2-50,y/2+170,x/2+175,y/2+195);
			goto loop1;
		}

		numbers[m]=choice;
		m++;

		if(i%2!=0)
		{
			a1[j]=choice;
			j++;
		}
		else
		{
			a2[k]=choice;
			k++;
		}

		cmp=compare(a1,a2);

		i++;

		setfillstyle(1,BLACK);
		bar(x/2-50,y/2+150,x/2+80,y/2+170);
	}while(cmp==0);

	if(cmp==1)
		outtextxy(220,400,"Player 1 won the match");
	else if(cmp==2)
		outtextxy(220,400,"Player 2 won the match");
	else
		outtextxy(250,400,"Game draw !!!");

	getch();
}

int compare(int *a1,int *a2)
{
	int a,b,c;
	int x,y,z,w;

	for(x=0;x<5;x++)
	{
	a=a1[x];
	for(y=0;y<5;y++)
	{
		b=a1[y];
		for(z=0;z<5;z++)
		{
		    c=a1[z];
			    if(a!=b && a!=c && b!=c)
			    {
				if(a==1 || a==2 || a==3)
				{
					if(b==1 || b==2 || b==3)
					{
						if(c==1 || c==2 || c==3)
						{
							w=1;
							return w;
						}
					}
				}

				if(a==4 || a==5 || a==6)
				{
					if(b==4 || b==5 || b==6)
					{
						if(c==4 || c==5 || c==6)
						{
							w=1;
							return w;
						}
					}
				}

				if(a==7 || a==8 || a==9)
				{
					if(b==7 || b==8 || b==9)
					{
						if(c==7 || c==8 || c==9)
						{
							w=1;
							return w;
						}
					}
				}

				if(a==1 || a==4 || a==7)
				{
					if(b==1 || b==4 || b==7)
					{
						if(c==1 || c==4 || c==7)
						{
							w=1;
							return w;
						}
					}
				}

				if(a==2 || a==5 || a==8)
				{
					if(b==2 || b==5 || b==8)
					{
						if(c==2 || c==5 || c==8)
						{
							w=1;
							return w;
						}
					}
				}

				if(a==3 || a==6 || a==9)
				{
					if(b==3 || b==6 || b==9)
					{
						if(c==3 || c==6 || c==9)
						{
							w=1;
							return w;
						}
					}
				}

				if(a==1 || a==5 || a==9)
				{
					if(b==1 || b==5 || b==9)
					{
						if(c==1 || c==5 || c==9)
						{
							w=1;
							return w;
						}
					}
				}

				if(a==3 || a==5 || a==7)
				{
					if(b==3 || b==5 || b==7)
					{
						if(c==3 || c==5 || c==7)
						{
							w=1;
							return w;
						}
					}
				}
			}
		    else
			w=0;
		}
	}
	}

	for(x=0;x<5;x++)
	{
	a=a2[x];
	for(y=0;y<5;y++)
	{
		b=a2[y];
		for(z=0;z<5;z++)
		{
		    c=a2[z];
		    if(a!=b && a!=c && b!=c)
		    {
				if(a==1 || a==2 || a==3)
				{
					if(b==1 || b==2 || b==3)
					{
						if(c==1 || c==2 || c==3)
						{
							w=2;
							return w;
						}
					}
				}

				if(a==4 || a==5 || a==6)
				{
					if(b==4 || b==5 || b==6)
					{
						if(c==4 || c==5 || c==6)
						{
							w=2;
							return w;
						}
					}
				}

				if(a==7 || a==8 || a==9)
				{
					if(b==7 || b==8 || b==9)
					{
						if(c==7 || c==8 || c==9)
						{
							w=2;
							return w;
						}
					}
				}

				if(a==1 || a==4 || a==7)
				{
					if(b==1 || b==4 || b==7)
					{
						if(c==1 || c==4 || c==7)
						{
							w=2;
							return w;
						}
					}
				}

				if(a==2 || a==5 || a==8)
				{
					if(b==2 || b==5 || b==8)
					{
						if(c==2 || c==5 || c==8)
						{
							w=2;
							return w;
						}
					}
				}

				if(a==3 || a==6 || a==9)
				{
					if(b==3 || b==6 || b==9)
					{
						if(c==3 || c==6 || c==9)
						{
							w=2;
							return w;
						}
					}
				}

				if(a==1 || a==5 || a==9)
				{
					if(b==1 || b==5 || b==9)
					{
						if(c==1 || c==5 || c==9)
						{
							w=2;
							return w;
						}
					}
				}

				if(a==3 || a==5 || a==7)
				{
					if(b==3 || b==5 || b==7)
					{
						if(c==3 || c==5 || c==7)
						{
							w=2;
							return w;
						}
					}
				}
			}
		    else
				w=0;
		}
	}
	}
	return w;
}
