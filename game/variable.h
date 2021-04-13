#ifndef VARIABLE_H_INCLUDED
#define VARIABLE_H_INCLUDED

#define sHeight 705
#define sWidth 500
int cnt = 0;

char menupage[50] = "image//menupage.bmp";
int egg[500];
int over[500];
int background[500];
int chicken[500];

/// variables for movements of chickens ///
int dp = 2;
int dq = 2;
int da = 2;
int db = 2;
int de = 2;
int df = 2;

/// booleun for game over condition ///
bool isGameOver = false;
bool isGameOver1 = false;

/// movement of eggs ///
int dm = 3;   // movement of regular egg //
int dn = 4;  // movement of dark egg    //
int dk = 2; // movement of bonus egg   //

char basket[100] = "image//game//basket1.bmp";

bool game = false; //flag to start game

//initial co-ordinates of basket
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

int drop = 1; ///////////////////////////for game over/////////////////////



int egg2_x = chicken3_x + 40;
int egg2_y = chicken3_y - 30;



int score = 0;  //initial score
char SCORE[1000];
int bonus = 0;
char BONUS[1000];
int total = 0;
char TOTAL[1000];
int final_s, high_s;
char HIGH[1000];

//music
bool musicOn = true;

void getHigh();
void showHigh();


#endif // VARIABLE_H_INCLUDED
