# include "iGraphics.h"
# include "myheader.h"

int image[10];
int planex = 350, planey = 0, bally = planey + 130;
int speed = 100;
int planespeed = 50;
int shoot = 0;
int screenheight = 800;
int screenwidth = 800;
int planeheight = 160;
int planewidth = 160;
int enemyx = 20;
int enemyy = 800;
int enemyspeed = 20;
int enemyheight = 160;
int enemywidth = 160;
bool start = true;
bool game = true;
bool ins = true;
int r, g, b, n = 5;
int planes, bullets;
int s = 0;
char score[100];

struct Plane
{
	int enemyx;
	int enemyy;
	bool start;
};

struct Plane plane[5];



void iDraw()
{


	iClear();


	iShowImage(0, 0, 800, 800, image[1]);
	iShowImage(10, 20, 150, 50, image[8]);
	if (!ins)
	{
		iShowImage(0, 0, 800, 800, image[7]);
		iSetColor(r, g, b);
		iText(300, 30, "Press space to start", GLUT_BITMAP_TIMES_ROMAN_24);
	}
	iSetColor(r, g, b);
	iText(300, 30, "Press space to start", GLUT_BITMAP_TIMES_ROMAN_24);
	sprintf_s(score,"%d", s);

	if (!game)
	{
		iClear();

		iShowImage(0, 0, 800, 800, image[0]);
		
		
		iShowImage(planex, planey, 160, 160, image[2]);
		iSetColor(150, 250, 250);
		iText(700, 750, "Score : ", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(770, 750, score, GLUT_BITMAP_TIMES_ROMAN_24);
		iShowImage(650, 740, 40, 40, image[6]);

		for (int i = 0; i < n; i++)
		{
			if (plane[i].start)
				iShowImage(plane[i].enemyx, plane[i].enemyy, enemyheight, enemywidth, image[4]);
		}

		if (shoot == 1)
		{
			iShowImage(planex + 50, bally, 60, 60, image[3]);
		}
	}


}

void iMouseMove(int mx, int my)
{

}

void iPassiveMouse(int mx, int my)
{

}

void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		shoot = 1;
		if (mx >= 10 && mx <= 170 || my <= 20 && my >= 70)
		{
			ins = false;
		}
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		shoot = 0;

		iPauseTimer(bullets);
	}
}


void iKeyboard(unsigned char key)
{
	if (key == 'p')
	{

		iPauseTimer(bullets);
		iPauseTimer(planes);
	}
	if (key == 'r')
	{
		iResumeTimer(bullets);
		iResumeTimer(planes);
	}
	if (key == 'w')
	{

	}
	if (key == 'a')
	{
		if (planex >= planespeed)
			planex -= planespeed;

	}
	if (key == 's')
	{

	}
	if (key == 'd')
	{
		if (planex <= screenwidth - planewidth)
			planex += planespeed;
	}

	if (key == ' ')
	{
		game = false;
	}


}


void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_END)
	{
		exit(0);
	}
	


}


void restart()
{
	for (int i = 0; i < n; i++)
	{
		int a = 20;
		int bo = 800;
		plane[i].start = true;
		a += 140;
	}


}

void planechange()
{
	
	for (int i = 0; i<5; i++)
	{
		plane[i].enemyy -= enemyspeed;

		if (plane[i].enemyy <= 0)
		{
			plane[i].enemyy = screenheight;
		}
		if (plane[i].enemyx >= screenwidth - 160 || plane[i].enemyx <= 0)
		{
			enemyspeed *= (-1);
		}
	}

	for (int i = 0; i<5; i++)
	{
		if (plane[i].start)
		{
			if ((planex + 50) >= plane[i].enemyx && (planex + 50) <= (plane[i].enemyx + 80))
			{
				if (bally >= plane[i].enemyy && bally <= plane[i].enemyy + 80)
				{
					plane[i].start = false;
					s++;
				}
			}
			else if (bally >= plane[i].enemyy && bally <= plane[i].enemyy + 80)
			{
				if ((planex + 50) >= plane[i].enemyx && (planex + 50) <= (plane[i].enemyx + 80))
				{
					plane[i].start = false;
					s++;
				}
			}

			
		}
		if (!plane[0].start  && !plane[1].start  && !plane[2].start  && !plane[3].start  && !plane[4].start)
		{
			restart();
			
		}
		
	}
	

	r = rand() % 255;
	g = rand() % 255;
	b = rand() % 255;


}

void bulletchange()
{
	bally += speed;
	if (bally >= screenheight || bally <= 0)
	{
		bally = planey + 130;
	}

	
}

int a = 20;
int bo = 800;
void setplane()
{
	for (int i = 0; i < n; i++)
	{

		plane[i].enemyx = a;
		plane[i].enemyy = bo;
		plane[i].start = true;
		a += 140;
	}


}


int main()

{
	setplane();

	planes=iSetTimer(50, planechange);
	bullets = iSetTimer(50, bulletchange);
	iInitialize(screenheight, screenwidth, "Space Pirate");

	image[0] = iLoadImage("images\\skybg.png");
	image[1] = iLoadImage("images\\cover.bmp");
	image[2] = iLoadImage("images\\mainplane.png");
	image[3] = iLoadImage("images\\bullet.png");
	image[4] = iLoadImage("images\\blueplane.png");
	image[5] = iLoadImage("images\\enemy3.png");
	image[6] = iLoadImage("images\\score.png");
	image[7] = iLoadImage("images\\instructions.png");
	image[8] = iLoadImage("images\\instructionsicon.png");

	iStart();

	return 0;
}

