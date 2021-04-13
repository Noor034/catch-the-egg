#ifndef SCORES_H_INCLUDED
#define SCORES_H_INCLUDED

void getHigh(){

	final_s = total;
	FILE *fptr = fopen("HIGHSCORE.txt", "r");
	fscanf(fptr, "%d", &high_s);
	if (final_s > high_s)
	{
		high_s = final_s;
		FILE *fp = fopen("HIGHSCORE.txt", "w");
		fprintf(fp, "%d", high_s);
		fclose(fp);
	}
	fclose(fptr);
}

void showHigh(){

	FILE *fptr = fopen("HIGHSCORE.txt", "r");
	fscanf(fptr, "%d", &high_s);

	sprintf(HIGH, "%d", high_s);
	iSetColor(230, 45, 45);
	iText(100, 450, "HIGH SCORE  :  ", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(350, 450, HIGH, GLUT_BITMAP_TIMES_ROMAN_24);
	fclose(fptr);
}


#endif // SCORES_H_INCLUDED
