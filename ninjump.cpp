#include <iostream> 
#include "SBDL.h"
#include <fstream>
#include <time.h>
#include <cmath>
using namespace std;

// constant ints
const int window_width = 600;
const int window_height = 800;
const int FPS = 30;
const int delay = 1000 / FPS;

//parameters
int speed = 10, random = 1000, counter = 0, counter1 = 0, counter2 = 0, counter3 = 0, counterr = 0, score = 0, bestscore = 0;
bool isLeft = true, flag = true, inway = true, musicStat = true, shield = true, isMusicPlay = true;

//sdl rects
SDL_Rect startbg;
SDL_Rect playagain_icon;
SDL_Rect quit_iconL;
SDL_Rect SCORE;
SDL_Rect SCOREPIC;
SDL_Rect BESTSCOREPIC;
SDL_Rect pause_panel;
SDL_Rect gameover_panel;
SDL_Rect gaming_background1;
SDL_Rect gaming_background2;
SDL_Rect StartIcon;
SDL_Rect restart_icon;
SDL_Rect play_icon;
SDL_Rect quit_icon;
SDL_Rect quit_iconP;
SDL_Rect home_icon;
SDL_Rect soundoff_icon;
SDL_Rect soundon_icon;
SDL_Rect musicon_icon;
SDL_Rect musicoff_icon;
SDL_Rect setting_icon;
SDL_Rect wall_L[20];
SDL_Rect wall_R[20];
SDL_Rect ninja;
SDL_Rect ninjaa;
SDL_Rect homeL;
SDL_Rect homeR;
SDL_Rect bubbleL;
SDL_Rect bubbleR;
SDL_Rect ropee;
SDL_Rect sq;
SDL_Rect birdL;
SDL_Rect birdR;
SDL_Rect tirR;
SDL_Rect tirL;
SDL_Rect trl;
SDL_Rect trr;

void buildninja()
{
	ninja = { 50 , 650 , 50 , 80 };
	ninjaa = { 50 , 650 , 80 , 80 };
}

void buildbirdL()
{
	birdL = { 0 , -300 , 50 , 50 };
}

void buildbirdR()
{
	birdR = { 550 , -200 , 50 , 50 };
}

void buildwallL()
{
	wall_L[20];
	for (int i = 0, y = 50; i < 20; i++, y -= 50)
		wall_L[i] = { 0 , y , 50 , 50 };
}

void buildwallR()
{
	wall_R[20];
	for (int i = 0, y = 80; i < 20; i++, y -= 50)
		wall_R[i] = { 550 , y , 50 , 50 };
}

void buildrope()
{
	ropee = { 50 , -500 , 500 , 50 };
}

void buildsq()
{
	sq = { 0 , -550, 60 , 40 };
}

void buildhomeL()
{
	homeL = { 0  , -200 , 100 , 80 };
}

void buildhomeR()
{
	homeR = { 500 , -600 , 100 , 80 };
}

void buildbubbleL()
{
	bubbleL = { 48 , -3200 , 50 , 50 };
}

void buildbubbleR()
{
	bubbleR = { 500 , -2500 , 50 ,50 };
}

void buildtrL()
{
	trl = { 30 , -2500 , 60 , 80 };
}

void buildtrR()
{
	trr = { 510 , -5500 , 60 , 80 };
}

void buildtirL()
{
	tirL = { 50 , -2500 , 30 , 30 };
}

void buildtirR()
{
	tirR = { 550 , -4500 , 30 , 30 };
}

void showwallL()
{
	for (int i = 0; i < 20; i++)
	{
		Texture wall_l = SBDL::loadTexture("assets/img/wall_l.png");
		wall_L[i].y += speed;
		if (wall_L[i].y >= 800)
			wall_L[i].y -= 20 * 50;
	}
}

void showwallR()
{
	for (int i = 0; i < 20; i++)
	{
		Texture wall_r = SBDL::loadTexture("assets/img/wall_r.png");
		wall_R[i].y += speed;
		if (wall_R[i].y >= 800)
			wall_R[i].y -= 20 * 50;
	}
}

void showhomeL()
{
	homeL.y += speed;
	if (homeL.y >= 850)
	{
		homeL.y = -280;
		do {
			int Rand = -rand() % random;
			homeL.y = Rand;
		} while (homeL.y < -1000 && homeL.y > -2000);
	}
}

void showhomeR()
{
	homeR.y += speed;
	if (homeR.y >= 850)
	{
		homeR.y = -150;
		do {
			int Rand1 = -rand() % random;
			homeR.y = Rand1;
		} while (homeR.y < -1000 && homeR.y > -2000);
	}
}

void showrope()
{
	ropee.y += speed;
	if (ropee.y >= 850)
	{
		ropee.y = -320;
		do {
			int R = -rand() % random;
			ropee.y = R;
		} while (ropee.y < -1000 && ropee.y > -2000);
	}
}

void showsq1()
{
	sq.y = ropee.y - 40;
	if (sq.x < 550)
		sq.x += speed + 2;
}

void showsq2()
{
	sq.y = ropee.y - 40;
	sq.x -= speed + 2;
}


void showbubbleL()
{
	bubbleL.y += speed;
	if (bubbleL.y >= 850)
	{
		bubbleL.y = -420;
		do {
			int R1 = -rand() % random;
			bubbleL.y = R1;
		} while (bubbleL.y < -1000 && bubbleL.y > -2000);
	}
}

void showbubbleR()
{
	bubbleR.y += speed;
	if (bubbleR.y >= 850)
	{
		bubbleR.y = -220;
		do {
			int r2 = -rand() % random;
			bubbleR.y = r2;
		} while (bubbleR.y < -1000 && bubbleR.y > -2000);
	}
}

void showbirdL()
{
	birdL.y += speed * 2;
	birdL.x += speed * 2;
	if (birdL.x >= 550 || birdL.y >= 800) {
		birdL.x = 0;
		birdL.y = -2800;
	}
}

void showbirdR()
{
	birdR.y += speed * 2;
	birdR.x -= speed * 2;
	if (birdR.x < 50 || birdR.y > 800)
	{
		birdR.x = 550;
		birdR.y = -3000;
	}
}

void showtrl()
{
	trl.y += speed;
	if (trl.y >= 800)
	{
		trl.y = -5500;
		do {
			int ro = -rand() % random;
			trl.y = ro;
		} while (trl.y < -1000 && trl.y > -2000);
	}
}

void showtrr()
{
	trr.y += speed;
	if (trr.y >= 800)
	{
		trr.y = -3500;
		do {
			int ron = -rand() % random;
			trr.y = ron;
		} while (trr.y < -1000 && trr.y > -2000);
	}
}

void showtirL()
{
	tirL.y = trl.y;
	tirL.y += speed;
	if (tirL.y > 0)
	{
		tirL.x += speed;
	}
	if (tirL.x >= 550)
	{
		tirL.x = 50;
	}
}

void showtirR()
{
	tirR.y = trr.y;
	tirR.y += speed;
	if (tirR.y >= 0)
	{
		tirR.x -= speed;
	}
	if (tirR.x <= 0)
	{
		tirR.x = 550;
	}
}

int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

enum gameStatus {
	pause, gameover, setting, menu, game, help
};
gameStatus gameStat;



int main(int argc, const char* argv[]) {
	srand(time(NULL));

	//window size
	SBDL::InitEngine("NinJump", window_width, window_height);

	//load assets
	Texture tr1 = SBDL::loadTexture("assets/img/thrower/thrower_left.png");
	Texture tr2 = SBDL::loadTexture("assets/img/thrower/thrower_right.png");
	Texture tir1 = SBDL::loadTexture("assets/img/blade/1.png");
	Texture tir2 = SBDL::loadTexture("assets/img/blade/2.png");
	Texture tir3 = SBDL::loadTexture("assets/img/blade/3.png");
	Texture tir4 = SBDL::loadTexture("assets/img/blade/4.png");
	Texture birdL1 = SBDL::loadTexture("assets/img/bird/bird1_left.png");
	Texture birdL2 = SBDL::loadTexture("assets/img/bird/bird2_left.png");
	Texture birdL3 = SBDL::loadTexture("assets/img/bird/bird3_left.png");
	Texture birdR1 = SBDL::loadTexture("assets/img/bird/bird1_right.png");
	Texture birdR2 = SBDL::loadTexture("assets/img/bird/bird2_right.png");
	Texture birdR3 = SBDL::loadTexture("assets/img/bird/bird3_right.png");
	Texture sq1 = SBDL::loadTexture("assets/img/squirrels/1.png");
	Texture sq2 = SBDL::loadTexture("assets/img/squirrels/2.png");
	Texture sq3 = SBDL::loadTexture("assets/img/squirrels/3.png");
	Texture sq4 = SBDL::loadTexture("assets/img/squirrels/4.png");
	Texture sq11 = SBDL::loadTexture("assets/img/squirrels/5.png");
	Texture sq12 = SBDL::loadTexture("assets/img/squirrels/6.png");
	Texture sq13 = SBDL::loadTexture("assets/img/squirrels/7.png");
	Texture sq14 = SBDL::loadTexture("assets/img/squirrels/8.png");
	Texture ninjaR1 = SBDL::loadTexture("assets/img/ninja/1.png");
	Texture ninjaR2 = SBDL::loadTexture("assets/img/ninja/2.png");
	Texture ninjaR3 = SBDL::loadTexture("assets/img/ninja/3.png");
	Texture ninjaL1 = SBDL::loadTexture("assets/img/ninja/4.png");
	Texture ninjaL2 = SBDL::loadTexture("assets/img/ninja/5.png");
	Texture ninjaL3 = SBDL::loadTexture("assets/img/ninja/6.png");
	Texture ninjaaR1 = SBDL::loadTexture("assets/img/shield/b4.png");
	Texture ninjaaR2 = SBDL::loadTexture("assets/img/shield/b5.png");
	Texture ninjaaR3 = SBDL::loadTexture("assets/img/shield/b6.png");
	Texture ninjaaL1 = SBDL::loadTexture("assets/img/shield/b1.png");
	Texture ninjaaL2 = SBDL::loadTexture("assets/img/shield/b2.png");
	Texture ninjaaL3 = SBDL::loadTexture("assets/img/shield/b3.png");
	Texture ninjaa1 = SBDL::loadTexture("assets/img/shield/b7.png");
	Texture ninjaa2 = SBDL::loadTexture("assets/img/shield/b8.png");
	Texture ninjaa3 = SBDL::loadTexture("assets/img/shield/b9.png");
	Texture ninja1 = SBDL::loadTexture("assets/img/ninja/7.png");
	Texture ninja2 = SBDL::loadTexture("assets/img/ninja/8.png");
	Texture ninja3 = SBDL::loadTexture("assets/img/ninja/9.png");
	Texture ninja4 = SBDL::loadTexture("assets/img/ninja/10.png");
	Texture wall_l = SBDL::loadTexture("assets/img/wall_l.png");
	Texture wall_r = SBDL::loadTexture("assets/img/wall_r.png");
	Texture homel = SBDL::loadTexture("assets/img/homel.png");
	Texture homer = SBDL::loadTexture("assets/img/homer.png");
	Texture rope = SBDL::loadTexture("assets/img/rope.png");
	Texture bubble = SBDL::loadTexture("assets/img/bubble.png");
	Texture background_gaming2 = SBDL::loadTexture("assets/img/background.png");
	Texture background_start = SBDL::loadTexture("assets/img/startback.png");
	Texture background_gaming1 = SBDL::loadTexture("assets/img/back1.png");
	Texture pausepanel = SBDL::loadTexture("assets/img/pause_panel.png");
	Texture gameoverpanel = SBDL::loadTexture("assets/img/gameover_panel.png");
	Texture musicon = SBDL::loadTexture("assets/img/musicon.png");
	Texture musicoff = SBDL::loadTexture("assets/img/musicoff.png");
	Texture starticon = SBDL::loadTexture("assets/img/PLAYBTN.png");
	Texture quiticon = SBDL::loadTexture("assets/img/QUITBTN.png");
	Texture playicon = SBDL::loadTexture("assets/img/play.png");
	Texture settingicon = SBDL::loadTexture("assets/img/options.png");
	Texture homeicon = SBDL::loadTexture("assets/img/home.png");
	Texture restarticon = SBDL::loadTexture("assets/img/again.png");
	Texture scorepic = SBDL::loadTexture("assets/img/score.png");
	Texture playagainicon = SBDL::loadTexture("assets/img/again.png");
	Texture bestscorepic = SBDL::loadTexture("assets/img/1.png");
	Music* bMusic = SBDL::loadMusic("assets/music/1.wav");
	Sound* SoundOnEffect = SBDL::loadSound("assets/music/carrot.wav");
	Sound* birdoninja = SBDL::loadSound("assets/music/hit_bird_3.wav");
	Sound* tironinja = SBDL::loadSound("assets/music/hit_hooker_1.wav");
	Sound* sanjaboninja = SBDL::loadSound("assets/music/hit_squirrel_2.wav");
	Sound* homeoninja = SBDL::loadSound("assets/music/hit_bomb_2.wav");
	Font* scorefont = SBDL::loadFont("assets/fonts/1.ttf", 50);
	Font* losefont = SBDL::loadFont("assets/fonts/2.ttf", 50);
	Texture scorepoint;
	Texture bestscorepoint;


	//sdl rect size
	gaming_background1 = { 0 , 0 , 600 , 800 };
	gaming_background2 = { 0 , 0 , 600 , 800 };
	pause_panel = { 0 , 0 , 600 , 600 };
	gameover_panel = { 0 , 0 , 600 , 800 };
	startbg = { 0 , 0 , 600 , 800 };
	StartIcon = { 250 , 600 , 100 , 90 };
	setting_icon = { 520 , 720 , 70 , 70 };
	musicon_icon = { 250 , 500 , 100 , 100 };
	musicoff_icon = { 250 , 500 , 100 , 100 };
	quit_icon = { 0 , 750 , 150 , 50 };
	quit_iconP = { 220 , 350 , 150 , 50 };
	quit_iconL = { 220 , 200 , 150 , 50 };
	playagain_icon = { 260 , 70 , 60 , 60 };
	play_icon = { 200 , 200 , 200 , 90 };
	home_icon = { 250 , 670 , 100 , 100 };
	SCORE = { 230 , 35 , 150 , 30 };
	SCOREPIC = { 210 , 0 , 200 , 90 };
	BESTSCOREPIC = { 120 , 500 , 350 , 290 };
	buildwallL();
	buildwallR();
	buildhomeL();
	buildhomeR();
	buildrope();
	buildbubbleL();
	buildbubbleR();
	buildninja();
	buildsq();
	buildtirL();
	buildtirR();
	buildtrL();
	buildtrR();
	buildbirdL();
	buildbirdR();

	ifstream myfile;
	myfile.open("best.txt");
	myfile >> bestscore;
	myfile.close();

	bestscorepoint = SBDL::createFontTexture(losefont, "Best Score :" + to_string(bestscore), 0, 0, 0);

	if (isMusicPlay && musicStat)
	{
		SBDL::playMusic(bMusic, 1);
		isMusicPlay = false;
	}
	if (!isMusicPlay && !musicStat)
	{
		SBDL::stopMusic();
		SBDL::stopAllSounds();
	}

	gameStat = menu;

	while (SBDL::isRunning()) {
		int startTime = SBDL::getTime();
		SBDL::updateEvents();
		SBDL::clearRenderScreen();

		if (gameStat == menu)
		{
			bestscore = max(score, bestscore);
			SBDL::showTexture(background_start, startbg);
			if (SBDL::mouseInRect(StartIcon) && SBDL::Mouse.clicked(SDL_BUTTON_LEFT, 1, SDL_PRESSED))
			{
				gameStat = game;
				gaming_background1 = { 0 , 0 , 600 , 800 };
				buildwallL(); buildwallR(); buildhomeL(); buildhomeR(); buildrope();
				buildbubbleL(); buildbubbleR(); buildninja(); buildsq();
				buildtirL(); buildtirR(); buildtrL(); buildtrR(); buildbirdL(); buildbirdR();
			}
			else {
				SBDL::showTexture(quiticon, quit_icon);
				SBDL::showTexture(starticon, StartIcon);
				SBDL::showTexture(settingicon, setting_icon);
			}
			if (SBDL::mouseInRect(quit_icon) && SBDL::Mouse.clicked(SDL_BUTTON_LEFT, 1, SDL_PRESSED))
			{
				break;
			}
			else {
				SBDL::showTexture(quiticon, quit_icon);
				SBDL::showTexture(starticon, StartIcon);
				SBDL::showTexture(settingicon, setting_icon);
			}
			if (SBDL::mouseInRect(setting_icon) && SBDL::Mouse.clicked(SDL_BUTTON_LEFT, 1, SDL_PRESSED))
			{
				gameStat = setting;
				soundon_icon = { 250 , 350 , 50 , 50 };
				soundoff_icon = { 250 , 350 , 50 , 50 };
			}
			else {
				SBDL::showTexture(quiticon, quit_icon);
				SBDL::showTexture(starticon, StartIcon);
				SBDL::showTexture(settingicon, setting_icon);
			}

			bestscorepoint = SBDL::createFontTexture(losefont, " YOUR BEST SCORE : " + to_string(bestscore), 0, 0, 0);
			SBDL::showTexture(bestscorepoint, 630, 630);

		}

		if (gameStat == game)
		{
			SBDL::showTexture(background_gaming2, gaming_background2);

			SBDL::showTexture(background_gaming1, gaming_background1);
			gaming_background1.y += speed;


			//score point
			scorepoint = SBDL::createFontTexture(scorefont, " YOUR SCORE : " + to_string(score), 0, 0, 0);

			showwallL();
			for (int i = 0; i < 20; i++)
				SBDL::showTexture(wall_l, wall_L[i]);

			showwallR();
			for (int i = 0; i < 20; i++)
				SBDL::showTexture(wall_r, wall_R[i]);

			showhomeL();
			SBDL::showTexture(homel, homeL);

			showhomeR();
			SBDL::showTexture(homer, homeR);

			showrope();
			SBDL::showTexture(rope, ropee);

			showbubbleR();
			SBDL::showTexture(bubble, bubbleR);

			showbubbleL();
			SBDL::showTexture(bubble, bubbleL);



			//ro be ro shdne mane ha
			if (abs(homeL.y - homeR.y) <= 100)
				homeL.y = -800;
			if (abs(bubbleL.y - bubbleR.y) <= 550)
				bubbleR.y = -8000;
			if (abs(trr.y - trl.y) <= 250)
				trr.y = -300;
			if (abs(trl.y - bubbleL.y) <= 100)
				bubbleL.y = -7000;
			if (abs(trr.y - bubbleR.y) <= 100)
				bubbleR.y = -5000;
			if (abs(ropee.y - bubbleL.y) <= 100)
				bubbleL.y = -6000;
			if (abs(ropee.y - bubbleR.y) <= 100)
				bubbleR.y = -4000;
			if (abs(bubbleL.y - homeL.y) <= 100)
				homeL.y = -200;
			if (abs(bubbleR.y - homeR.y) <= 100)
				homeR.y = -300;
			if (abs(ropee.y - homeL.y) <= 50)
				ropee.y = -350;
			if (abs(ropee.y - homeR.y) <= 50)
				ropee.y = -450;
			if (abs(ropee.y - trl.y) <= 100)
				trl.y = -500;
			if (abs(ropee.y - trr.y) <= 100)
				trr.y = -1500;
			if (abs(homeR.y - trr.y) <= 150)
				homeR.y = -1000;
			if (abs(homeL.y - trl.y) <= 150)
				homeL.y = -1800;


			if (SBDL::hasIntersectionRect(bubbleR, ninja) || SBDL::hasIntersectionRect(bubbleL, ninja))
			{
				shield = false;
			}
			//ninja stuff
			if (ninja.x <= 50 || ninja.x >= 500)
			{
				inway = false;
			}
			if (SBDL::keyPressed(SDL_SCANCODE_SPACE) && !inway) {
				inway = true;
				isLeft = !isLeft;
			}

			if (shield == true)
			{
				if (isLeft) {
					if (ninja.x > 50) {
						ninja.x -= speed * 3;
						if (counter % 12 == 0 || counter % 12 == 1 || counter % 12 == 2)
							SBDL::showTexture(ninja1, ninja);
						if (counter % 12 == 3 || counter % 12 == 4 || counter % 12 == 5)
							SBDL::showTexture(ninja2, ninja);
						if (counter % 12 == 6 || counter % 12 == 7 || counter % 12 == 8)
							SBDL::showTexture(ninja3, ninja);
						if (counter % 12 == 9 || counter % 12 == 10 || counter % 12 == 11)
							SBDL::showTexture(ninja4, ninja);
					}

					if (ninja.x <= 50) {
						ninja.x = 50;
						if (counter % 9 == 0 || counter % 9 == 1 || counter % 9 == 2)
							SBDL::showTexture(ninjaL1, ninja);
						if (counter % 9 == 3 || counter % 9 == 4 || counter % 9 == 5)
							SBDL::showTexture(ninjaL2, ninja);
						if (counter % 9 == 6 || counter % 9 == 7 || counter % 9 == 8)
							SBDL::showTexture(ninjaL3, ninja);
					}
				}
				else {

					if (ninja.x < 500) {
						ninja.x += speed * 3;
						if (counter % 12 == 0 || counter % 12 == 1 || counter % 12 == 2)
							SBDL::showTexture(ninja1, ninja);
						if (counter % 12 == 3 || counter % 12 == 4 || counter % 12 == 5)
							SBDL::showTexture(ninja2, ninja);
						if (counter % 12 == 6 || counter % 12 == 7 || counter % 12 == 8)
							SBDL::showTexture(ninja3, ninja);
						if (counter % 12 == 9 || counter % 12 == 10 || counter % 12 == 11)
							SBDL::showTexture(ninja4, ninja);
					}
					if (ninja.x >= 500) {
						ninja.x = 500;
						if (counter % 9 == 0 || counter % 9 == 1 || counter % 9 == 2)
							SBDL::showTexture(ninjaR1, ninja);
						if (counter % 9 == 3 || counter % 9 == 4 || counter % 9 == 5)
							SBDL::showTexture(ninjaR2, ninja);
						if (counter % 9 == 6 || counter % 9 == 7 || counter % 9 == 8)
							SBDL::showTexture(ninjaR3, ninja);
					}
				}
				counter++;
			}

			if (!shield) {
				if (isLeft) {
					if (ninja.x > 50) {
						ninja.x -= speed * 3;
						if (counterr % 9 == 0 || counterr % 12 == 1 || counterr % 12 == 2)
							SBDL::showTexture(ninjaa1, ninja);
						if (counterr % 9 == 3 || counterr % 12 == 4 || counterr % 12 == 5)
							SBDL::showTexture(ninjaa2, ninja);
						if (counterr % 9 == 6 || counterr % 12 == 7 || counterr % 12 == 8)
							SBDL::showTexture(ninjaa3, ninja);

					}

					if (ninja.x <= 50) {
						ninja.x = 50;
						if (counterr % 9 == 0 || counterr % 9 == 1 || counterr % 9 == 2)
							SBDL::showTexture(ninjaaL1, ninja);
						if (counterr % 9 == 3 || counterr % 9 == 4 || counterr % 9 == 5)
							SBDL::showTexture(ninjaaL2, ninja);
						if (counterr % 9 == 6 || counterr % 9 == 7 || counterr % 9 == 8)
							SBDL::showTexture(ninjaaL3, ninja);
					}
				}
				else {

					if (ninja.x < 500) {
						ninja.x += speed * 3;
						if (counterr % 12 == 0 || counterr % 12 == 1 || counterr % 12 == 2)
							SBDL::showTexture(ninjaa1, ninja);
						if (counterr % 12 == 3 || counterr % 12 == 4 || counterr % 12 == 5)
							SBDL::showTexture(ninjaa2, ninja);
						if (counterr % 12 == 6 || counterr % 12 == 7 || counterr % 12 == 8)
							SBDL::showTexture(ninjaa3, ninja);

					}
					if (ninja.x >= 500) {
						ninja.x = 500;
						if (counterr % 9 == 0 || counterr % 9 == 1 || counterr % 9 == 2)
							SBDL::showTexture(ninjaaR1, ninja);
						if (counterr % 9 == 3 || counterr % 9 == 4 || counterr % 9 == 5)
							SBDL::showTexture(ninjaaR2, ninja);
						if (counterr % 9 == 6 || counterr % 9 == 7 || counterr % 9 == 8)
							SBDL::showTexture(ninjaaR3, ninja);
					}
				}
				counterr++;
			}



			//bird stuff
			birdR.y += 2;
			birdL.y += 2;
			if (birdR.y <= 100)
			{
				if (counter1 % 9 == 0 || counter1 % 9 == 1 || counter1 % 9 == 2)
					SBDL::showTexture(birdR1, birdR);
				if (counter1 % 9 == 3 || counter1 % 9 == 4 || counter1 % 9 == 5)
					SBDL::showTexture(birdR2, birdR);
				if (counter1 % 9 == 6 || counter1 % 9 == 7 || counter1 % 9 == 8)
					SBDL::showTexture(birdR3, birdR);
			}
			if (birdR.y > 100)
			{
				showbirdR();
				if (counter1 % 9 == 0 || counter1 % 9 == 1 || counter1 % 9 == 2)
					SBDL::showTexture(birdR1, birdR);
				if (counter1 % 9 == 3 || counter1 % 9 == 4 || counter1 % 9 == 5)
					SBDL::showTexture(birdR2, birdR);
				if (counter1 % 9 == 6 || counter1 % 9 == 7 || counter1 % 9 == 8)
					SBDL::showTexture(birdR3, birdR);
			}
			if (birdL.y <= 100)
			{
				if (counter1 % 9 == 0 || counter1 % 9 == 1 || counter1 % 9 == 2)
					SBDL::showTexture(birdL1, birdL);
				if (counter1 % 9 == 3 || counter1 % 9 == 4 || counter1 % 9 == 5)
					SBDL::showTexture(birdL2, birdL);
				if (counter1 % 9 == 6 || counter1 % 9 == 7 || counter1 % 9 == 8)
					SBDL::showTexture(birdL3, birdL);
			}
			if (birdL.y > 100)
			{
				showbirdL();
				if (counter1 % 9 == 0 || counter1 % 9 == 1 || counter1 % 9 == 2)
					SBDL::showTexture(birdL1, birdL);
				if (counter1 % 9 == 3 || counter1 % 9 == 4 || counter1 % 9 == 5)
					SBDL::showTexture(birdL2, birdL);
				if (counter1 % 9 == 6 || counter1 % 9 == 7 || counter1 % 9 == 8)
					SBDL::showTexture(birdL3, birdL);
			}
			counter1++;


			//sanjab stuff
			if (sq.x < 540 && flag)
			{
				showsq1();
				if (counter2 % 12 == 0 || counter2 % 12 == 1 || counter2 % 12 == 2)
					SBDL::showTexture(sq1, sq);
				if (counter2 % 12 == 3 || counter2 % 12 == 4 || counter2 % 12 == 5)
					SBDL::showTexture(sq2, sq);
				if (counter2 % 12 == 6 || counter2 % 12 == 7 || counter2 % 12 == 8)
					SBDL::showTexture(sq3, sq);
				if (counter2 % 12 == 9 || counter2 % 12 == 10 || counter2 % 12 == 11)
					SBDL::showTexture(sq4, sq);
			}
			if (sq.x >= 540)
			{
				flag = false;
			}
			if (sq.x >= 50 && flag == false)
			{
				showsq2();
				if (counter2 % 12 == 0 || counter2 % 12 == 1 || counter2 % 12 == 2)
					SBDL::showTexture(sq11, sq);
				if (counter2 % 12 == 3 || counter2 % 12 == 4 || counter2 % 12 == 5)
					SBDL::showTexture(sq12, sq);
				if (counter2 % 12 == 6 || counter2 % 12 == 7 || counter2 % 12 == 8)
					SBDL::showTexture(sq13, sq);
				if (counter2 % 12 == 9 || counter2 % 12 == 10 || counter2 % 12 == 11)
					SBDL::showTexture(sq14, sq);
			}
			if (sq.y > 800 || sq.y < 50)
			{
				sq.y = ropee.y - 40;
				sq.x = 0;
				flag = 1;
			}
			counter2++;

			
			//thrower stuff
			showtrl();
			SBDL::showTexture(tr1, trl);
			showtrr();
			SBDL::showTexture(tr2, trr);


			//tiq stuff
			showtirR();
			if (counter3 % 12 == 0 || counter3 % 12 == 1 || counter3 % 12 == 2)
				SBDL::showTexture(tir1, tirR);
			if (counter3 % 12 == 3 || counter3 % 12 == 4 || counter3 % 12 == 5)
				SBDL::showTexture(tir2, tirR);
			if (counter3 % 12 == 6 || counter3 % 12 == 7 || counter3 % 12 == 8)
				SBDL::showTexture(tir3, tirR);
			if (counter3 % 12 == 9 || counter3 % 12 == 10 || counter3 % 12 == 11)
				SBDL::showTexture(tir4, tirR);
			showtirL();
			if (counter3 % 12 == 0 || counter3 % 12 == 1 || counter3 % 12 == 2)
				SBDL::showTexture(tir1, tirL);
			if (counter3 % 12 == 3 || counter3 % 12 == 4 || counter3 % 12 == 5)
				SBDL::showTexture(tir2, tirL);
			if (counter3 % 12 == 6 || counter3 % 12 == 7 || counter3 % 12 == 8)
				SBDL::showTexture(tir3, tirL);
			if (counter3 % 12 == 9 || counter3 % 12 == 10 || counter3 % 12 == 11)
				SBDL::showTexture(tir4, tirL);
			counter3++;


			//intersections
			if(shield == true)
			{
				if (ninja.x <= 50 || ninja.x >= 500)
				{
					if (SBDL::hasIntersectionRect(ninja, trr) || SBDL::hasIntersectionRect(ninja, trl) || 
						SBDL::hasIntersectionRect(ninja, tirL) || SBDL::hasIntersectionRect(ninja, tirR)
						|| SBDL::hasIntersectionRect(ninja, birdR) || SBDL::hasIntersectionRect(ninja, birdL) || SBDL::hasIntersectionRect(ninja, homeL) 
						|| SBDL::hasIntersectionRect(ninja, homeR) || SBDL::hasIntersectionRect(ninja, sq))
					{
						gameStat = gameover;
					}
				}
				if (ninja.x > 50 || ninja.x < 500)
				{
					if (SBDL::hasIntersectionRect(ninja, tirL) || SBDL::hasIntersectionRect(ninja, tirR) ||
						SBDL::hasIntersectionRect(ninja, birdR) || SBDL::hasIntersectionRect(ninja, birdL) ||
						SBDL::hasIntersectionRect(ninja, homeL) || SBDL::hasIntersectionRect(ninja, homeR) || SBDL::hasIntersectionRect(ninja, sq))
					{
						score += 20;
					}
				}
			}
			if (shield == false)
			{
				if (ninja.x <= 50 || ninja.x >= 500)
				{
					if (SBDL::hasIntersectionRect(ninja, trr) || SBDL::hasIntersectionRect(ninja, trl) ||
						SBDL::hasIntersectionRect(ninja, tirL) || SBDL::hasIntersectionRect(ninja, tirR)
						|| SBDL::hasIntersectionRect(ninja, birdR) || SBDL::hasIntersectionRect(ninja, birdL)
						|| SBDL::hasIntersectionRect(ninja, homeL) || SBDL::hasIntersectionRect(ninja, homeR)
						|| SBDL::hasIntersectionRect(ninja, sq))
					{
						shield = true;
					}
				}
				if (ninja.x > 50 || ninja.x < 500)
				{
					if (SBDL::hasIntersectionRect(ninja, tirL) || SBDL::hasIntersectionRect(ninja, tirR) ||
						SBDL::hasIntersectionRect(ninja, birdR) || SBDL::hasIntersectionRect(ninja, birdL) ||
						SBDL::hasIntersectionRect(ninja, homeL) || SBDL::hasIntersectionRect(ninja, homeR) || SBDL::hasIntersectionRect(ninja, sq))
					{
						score += 20;
					}
				}
			}
			
			


			//sounds
			if (SBDL::hasIntersectionRect(ninja, homeL) || SBDL::hasIntersectionRect(ninja, homeR))
				SBDL::playSound(homeoninja, 1);
			if (SBDL::hasIntersectionRect(ninja, sq))
				SBDL::playSound(sanjaboninja, 1);
			if (SBDL::hasIntersectionRect(ninja, birdL) || SBDL::hasIntersectionRect(ninja, birdR))
				SBDL::playSound(birdoninja, 1);
			if (SBDL::hasIntersectionRect(ninja, tirR) || SBDL::hasIntersectionRect(ninja, tirL) || 
				SBDL::hasIntersectionRect(ninja,trr) || SBDL::hasIntersectionRect(ninja,trl))
				SBDL::playSound(tironinja, 1);

			//show score
			score++;
			SBDL::showTexture(scorepic, SCOREPIC);
			SBDL::showTexture(scorepoint, SCORE);

			if (SBDL::keyPressed(SDL_SCANCODE_P))
				gameStat = pause;

		}

		if (gameStat == setting)
		{
			Texture tutioral1 = SBDL::createFontTexture(losefont, "Press P = Pause", 0, 0, 0);
			Texture tutioral2 = SBDL::createFontTexture(losefont, " Press SPACE = Jump", 0, 0, 0);
			Texture back = SBDL::createFontTexture(losefont, " Press 0 = Menu", 0, 0, 0);
			SBDL::showTexture(tutioral1, 170, 100);
			SBDL::showTexture(tutioral2, 120, 200);
			SBDL::showTexture(back, 170, 300);

			if (musicStat)
				SBDL::showTexture(musicoff, musicoff_icon);
			if (!musicStat)
				SBDL::showTexture(musicon, musicon_icon);

			if (SBDL::mouseInRect(musicoff_icon) && SBDL::Mouse.clicked(SDL_BUTTON_LEFT, 1, SDL_PRESSED))
			{
				musicStat = !musicStat;
				isMusicPlay = true;
				if (musicStat)
				{
					SBDL::playSound(SoundOnEffect, 1);
					SBDL::playMusic(bMusic, -1);
				}

				if (!musicStat)
				{
					SBDL::stopMusic();
					SBDL::stopAllSounds;
				}
			}
			if (SBDL::keyPressed(SDL_SCANCODE_0))
				gameStat = menu;

		}

		if (gameStat == pause)
		{
			SBDL::showTexture(pausepanel, pause_panel);
			Texture resume = SBDL::createFontTexture(losefont, "play", 0, 0, 0);
			if (SBDL::mouseInRect(quit_icon) && SBDL::Mouse.clicked(SDL_BUTTON_LEFT, 1, SDL_PRESSED))
			{
				break;
			}
			else {
				SBDL::showTexture(playicon, play_icon);
				SBDL::showTexture(quiticon, quit_iconP);
				SBDL::showTexture(homeicon, home_icon);
			}
			if (SBDL::mouseInRect(play_icon) && SBDL::Mouse.clicked(SDL_BUTTON_LEFT, 1, SDL_PRESSED))
			{
				gameStat = game;
			}
			else {
				SBDL::showTexture(playicon, play_icon);
				SBDL::showTexture(quiticon, quit_iconP);
				SBDL::showTexture(homeicon, home_icon);
			}
			if (SBDL::mouseInRect(home_icon) && SBDL::Mouse.clicked(SDL_BUTTON_LEFT, 1, SDL_PRESSED))
			{
				gameStat = menu; score = 0;
			}
			else {
				SBDL::showTexture(playicon, play_icon);
				SBDL::showTexture(quiticon, quit_iconP);
				SBDL::showTexture(homeicon, home_icon);
			}
			SBDL::showTexture(resume, 240, 210);
		}

		if (gameStat == gameover)
		{
			bestscore = max(score, bestscore);

			buildwallL(); buildwallR(); buildhomeL(); buildhomeR(); buildrope(); buildbubbleL(); buildbubbleR();
			buildninja(); buildsq(); buildtirL(); buildtirR(); buildtrL(); buildtrR(); buildbirdL(); buildbirdR();
			gaming_background1 = { 0 , 0 , 600 , 800 };

			SBDL::showTexture(gameoverpanel, gameover_panel);
			if (SBDL::mouseInRect(playagain_icon) && SBDL::Mouse.clicked(SDL_BUTTON_LEFT, 1, SDL_PRESSED))
			{
				gameStat = game; score = 0;
			}
			else {
				SBDL::showTexture(quiticon, quit_iconL);
				SBDL::showTexture(playagainicon, playagain_icon);
			}
			if (SBDL::mouseInRect(quit_iconL) && SBDL::Mouse.clicked(SDL_BUTTON_LEFT, 1, SDL_PRESSED))
				break;
			else {
				SBDL::showTexture(quiticon, quit_iconL);
				SBDL::showTexture(playagainicon, playagain_icon);
			}

			scorepoint = SBDL::createFontTexture(losefont, "SCORE : " + to_string(score), 0, 0, 0);
			bestscorepoint = SBDL::createFontTexture(losefont, "BEST SCORE : " + to_string(bestscore), 225, 225, 225);
			SBDL::showTexture(bestscorepic, BESTSCOREPIC);
			SBDL::showTexture(scorepoint, 200, 450);
			SBDL::showTexture(bestscorepoint, 150, 525);
		}

		if (score > bestscore)
		{
			bestscore = score;
			ofstream myfile;
			myfile.open("best.txt");
			myfile << bestscore << "\n";
			myfile.close();
		}

		SBDL::updateRenderScreen();
		int elapsedTime = SBDL::getTime() - startTime;
		if (delay > elapsedTime)
			SBDL::delay(delay - elapsedTime);
	}
	return 0;
}