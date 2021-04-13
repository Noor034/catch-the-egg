#ifndef GRAPHICS_H_INCLUDED
#define GRAPHICS_H_INCLUDED

void graphicscode()
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
		total = bonus + score;
		sprintf(TOTAL, "%d", total);
		iSetColor(230, 45, 45);
		iText(350, 610, "TOTAL= ", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(450, 610, TOTAL, GLUT_BITMAP_TIMES_ROMAN_24);


		if (isGameOver)
		{
			getHigh();
			iShowImage(0, 0, 500, 705, over[0]);
		}
		if (isGameOver1)
		{
			getHigh();
			iShowImage(0, 0, 500, 705, over[0]);
		}


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
		showHigh();
	}
	if (n == 6 && !game)
	{
		exit(0);
	}
}

#endif // GRAPHICS_H_INCLUDED
