#include "iGraphics.h"
#include "bitmap_loader.h"
#include<iostream>
#define sHeight 705
#define sWidth 500
using namespace std;

char menupage[50] = "image//menupage.bmp";
int egg[500];
int over[500];
int background[500];
int chicken[500];

//chickens
int dp = 2;
int dq = 2;
int da = 2;
int db = 2;
int de = 2;
int df = 2;

bool isGameOver = false;
bool isGameOver1 = false;

//eggs
int dm = 2;
int dn = 2;
int dk = 2;

char basket[100] = "image//game//basket1.bmp";

bool game = false;//flag to start game
//basket co-ordinates
int basketx = 250;
int baskety = 30;

int n = 0; //flag for multiple option choice in menu


int chicken1_x = 250;
int chicken1_y = 550;
int chicken2_x = 200;
int chicken2_y = 500;
int chicken3_x = 300;
int chicken3_y = 400;

int egg_x = chicken1_x + 40;
int egg_y = chicken1_y - 30;

int egg1_x = chicken2_x + 40;
int egg1_y = chicken2_y - 30;



int egg2_x = chicken3_x + 40;
int egg2_y = chicken3_y - 30;



int score = 0;  //initial score
char SCORE[1000];
int bonus = 0;
char BONUS[1000];
int total = 0;
char TOTAL[1000];

//music
bool musicOn = true;
void iDraw()
{
	iClear();
	iShowImage(0, 0, 500, 705, background[0]);
	//button
	iShowImage(140, 400, 186, 47, background[1]);
	iShowImage(140, 340, 186, 47, background[2]);
	iShowImage(140, 280, 186, 47, background[3]);
	iShowImage(140, 220, 186, 47, background[4]);
	iShowImage(140, 160, 186, 47, background[5]);
	iShowImage(140, 100, 186, 47, background[6]);
	iShowImage(90, 600, 320, 57, background[7]);
	//1st level
    if (n == 1)
	{

		if (score <= 150)
		{

			iShowImage(0, 0, 500, 705, background[8]);

			iShowImage(chicken1_x, chicken1_y, 110, 140, chicken[0]);

			iShowBMP2(basketx, baskety, basket, 0);
			iShowImage(egg_x, egg_y, 20, 20, egg[0]);

		}
//2nd level
		if (score >150)
		{
			iShowImage(0, 0, 500, 705, background[14]);
			iShowImage(chicken2_x, chicken2_y, 100, 120, chicken[1]);
			iShowImage(chicken1_x, chicken1_y, 110, 140, chicken[0]);
			iShowBMP2(basketx, baskety, basket, 0);
			iShowImage(egg_x, egg_y, 20, 20, egg[0]);
			iShowImage(egg1_x, egg1_y, 20, 20, egg[1]);
		}
//3rd level
		if (score > 250)
		{
			iShowImage(0, 0, 500, 705, background[15]);
			iShowImage(chicken3_x, chicken3_y, 100, 120, chicken[2]);
			iShowImage(chicken2_x, chicken2_y, 100, 120, chicken[1]);
			iShowImage(chicken1_x, chicken1_y, 110, 140, chicken[0]);
			iShowBMP2(basketx, baskety, basket, 0);
			iShowImage(egg_x, egg_y, 20, 20, egg[0]);
			iShowImage(egg1_x, egg1_y, 20, 20, egg[1]);
			iShowImage(egg2_x, egg2_y, 30, 30, egg[2]);
		}
		//score
		sprintf(SCORE, "%d", score);
		iSetColor(0, 0, 0);
		iText(350, 650, "SCORE= ", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(450, 650, SCORE, GLUT_BITMAP_TIMES_ROMAN_24);
		//bonus
		sprintf(BONUS, "%d", bonus);
		iSetColor(0, 0, 0);
		iText(350, 630, "BONUS= ", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(450, 630, BONUS, GLUT_BITMAP_TIMES_ROMAN_24);

	//total

		sprintf(TOTAL, "%d", score+bonus);
		iSetColor(0, 0, 0);
		iText(350, 610, "TOTAL= ", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(450, 610, TOTAL, GLUT_BITMAP_TIMES_ROMAN_24);



		if (isGameOver)
			iShowImage(0, 0, 500, 705, over[0]);
		if (isGameOver1)
			iShowImage(0, 0, 500, 705, over[0]);


	}

	if (n == 2 && !game)
	{
		iShowImage(0, 0, 500, 705, background[10]);
	}
	if (n == 3 && !game)
	{
		iShowImage(0, 0, 500, 705, background[9]);
	}
	if (n == 4 && !game)
	{
		iShowImage(0, 0, 500, 705, background[11]);
	}
	if (n == 5 && !game)
	{
		iShowImage(0, 0, 500, 705, background[12]);
	}
	if (n == 6 && !game)
	{
		exit(0);
	}




}



void iMouseMove(int mx, int my)
{

}


void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//cout << mx <<endl<< my << endl;
		//to start game
		if (my >= 400 && my <= 447){ n = 1; }

		//to enter manual
		if (my >= 340 && my <= 387){ n = 2; } 

		//to enter controls
		if (my >= 280 && my <= 327){ n = 3; }

		//to enter music
		if (my >= 220 && my <= 267){ n = 4; }

		//to enter high score
		if (my >= 160 && my <= 207){ n = 5; }

		//to quit
		if (my >= 100 && my <= 147){ n = 6; }


	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{

	}
}


void iKeyboard(unsigned char key)
{
	if (key == 'a')
	{


	}

	if (key == 'm')
	{
		if (musicOn)
		{
			musicOn = false;
			PlaySound(0, 0, 0);
		}
		else
		{
			musicOn = true;
			PlaySound("music\\GameMusic.wav", NULL, SND_LOOP | SND_ASYNC);
		}

	}
	if (key == 'r')
	{

	}

	if (key == 'c')
	{

	}

	if (key == 'r')
	{

	}

	if (key == ' ')
	{


	}

	if (key == '\b')
	{
		n = 0;
	}

}
void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_HOME)
	{
		game = true;
	}


	if (key == GLUT_KEY_RIGHT)
	{
		if (basketx <= 425)
			basketx += 10;

	}
	if (key == GLUT_KEY_LEFT)
	{
		if (basketx>5)
			basketx -= 10;

	}
	if (key == GLUT_KEY_F3)
	{

	}


	if (key == GLUT_KEY_END)
	{
		exit(0);
	}



}
void iPassiveMouse(int a, int b)
{

}

void move1()
{
	chicken1_x += dp;
	chicken1_y += dq;
	if (chicken1_x + 110 >= sWidth || chicken1_x <= 0)
		dp *= (-1);
	if (chicken1_y + 140 >= sHeight || chicken1_y <= 500)
		dq *= (-1);

}
void move2()
{
	chicken2_x += da;
	chicken2_y += db;
	if (chicken2_x + 100 >= sWidth || chicken2_x <= 0)
		da *= (-1);
	if (chicken2_y + 120 >= sHeight || chicken2_y <= 500)
		db *= (-1);

}


void move3()
{
	chicken3_x += de;
	chicken3_y += df;
	if (chicken3_x + 100 >= sWidth || chicken3_x <= 0)
		de *= (-1);
	if (chicken3_y + 120 >= sHeight || chicken3_y <= 400)
		df *= (-1);

}

void moveDim1()
{
	egg_y -= dm;


	if ( egg_y <= baskety + 30 && egg_x > basketx && egg_x < basketx + 70)
	{
		egg_x = chicken1_x + 40;
		egg_y = chicken1_y - 30;

		score += 30;

	}
	else if (egg_y < 10)
	{

		isGameOver = true;
	}

}
void moveDim2()
{
	if (score>150)
	{

		egg1_y -= dn;


		if (egg1_y <= baskety + 20 && egg1_x > basketx && egg1_x < basketx + 70)

		{

			isGameOver1 = true;
		}
		else if (egg1_y <= baskety + 30 && ((egg1_x < basketx) || (egg1_x > basketx + 70)))

		{

			egg1_x = chicken2_x + 40;
			egg1_y = chicken2_y - 30;

		}
	}
}


void moveDim3()
{
	egg2_y -= dk;


	if (score>250 && egg2_y <= baskety + 30 && egg2_x > basketx && egg2_x < basketx + 70)
	{
		egg2_x = chicken3_x + 40;
		egg2_y = chicken3_y - 30;

	bonus += 50;
	}

	else if (egg2_y < 0)
	{
		egg2_x = chicken3_x + 40;
	egg2_y = chicken3_y - 30;
}
}

int main()
{
	iSetTimer(5, move1);
	iSetTimer(5, move2);
	iSetTimer(5, move3);
	iSetTimer(5, moveDim1);
	iSetTimer(3, moveDim2);
	iSetTimer(3, moveDim3);
	iInitialize(sWidth, sHeight, "catch the EGGS");


	background[0] = iLoadImage("image\\menu\\menu.png");
	//egg
	egg[0] = iLoadImage("image\\game\\egg.png");
	egg[1] = iLoadImage("image\\game\\egg1.png");
	egg[2] = iLoadImage("image\\game\\egg2.png");

	//homepage & menu buttons
	background[1] = iLoadImage("image\\options\\button (1).png");
	background[2] = iLoadImage("image\\options\\button (2).png");
	background[3] = iLoadImage("image\\options\\button (3).png");
	background[4] = iLoadImage("image\\options\\button (4).png");
	background[5] = iLoadImage("image\\options\\high.png");
	background[6] = iLoadImage("image\\options\\button (6).png");
	background[7] = iLoadImage("image\\options\\gamename.jpg");
	//game
	background[8] = iLoadImage("image\\level\\game.png");
	background[14] = iLoadImage("image\\level\\game1.png");
	background[15] = iLoadImage("image\\level\\game2.png");
	//chicken
	chicken[0] = iLoadImage("image\\game\\chicken1.png");
	chicken[1] = iLoadImage("image\\game\\chicken2.png");
	chicken[2] = iLoadImage("image\\game\\chicken3.png");

	//gameover
	over[0] = iLoadImage("image\\game\\over.png");

	//control page
	background[9] = iLoadImage("image\\options\\Control page.png");
	//manual
	background[10] = iLoadImage("image\\options\\manual.png");
	//music
	background[11] = iLoadImage("image\\options\\music.png");
	//highscore
	background[12] = iLoadImage("image\\options\\highscore.png");

	if (musicOn)
		PlaySound("music\\GameMusic.wav", NULL, SND_LOOP | SND_ASYNC);

	iStart();

	return 0;
}
