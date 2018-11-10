#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include "cursesmind.h"

void new_game(){
	int i,j,k;
	int try_count;
	int ok,nope;

	int code[4]={0,0,0,0};
	int code_backup[4]={0,0,0,0};

	int attempt[4]={0,0,0,0};
	int attempt_copy[4]={0,0,0,0};
	int num,num_pos;
	int cmdkey;
	char gamescr[]={"o   o ooooo ooooo ooooo ooooo ooooo o   o  o  o   o ooo\n"
					"oo oo o   o o       o   o     o   o oo oo  o  oo  o o  o\n"
					"o o o ooooo ooooo   o   oooo  ooooo o o o  o  o o o o   o\n"
					"o   o o   o     o   o   o     o  o  o   o  o  o  oo o  o\n"
					"o   o o   o ooooo   o   ooooo o   o o   o  o  o   o ooo\n"
					"=========================================================\n\n"

					" [ ] [ ] [ ] [ ]  |\n"
					" [ ] [ ] [ ] [ ]  |\n"
					" [ ] [ ] [ ] [ ]  |\n"
					" [ ] [ ] [ ] [ ]  |\n"
					" [ ] [ ] [ ] [ ]  |\n"
					" [ ] [ ] [ ] [ ]  |\n"
					" [ ] [ ] [ ] [ ]  |\n"
					" [ ] [ ] [ ] [ ]  |\n"
					" [ ] [ ] [ ] [ ]  |\n"
					" [ ] [ ] [ ] [ ]  |\n"
					" [ ] [ ] [ ] [ ]  |\n"
					" [ ] [ ] [ ] [ ]  |\n"
					" _______________\n\n"

					" [0] [0] [0] [0]"};
	clear();
	printw(gamescr);
	mvprintw(LINES-2,1,"[UP] [DOWN] [0-9]: Change number    [ENTER]: Try.");
	mvprintw(LINES-1,1,"[LEFT] [RIGHT]: Select number.      [ESC]: Main Menu.");
	attron(A_REVERSE);
	mvprintw(NUM_R,NUM_1,"0");
	attroff(A_REVERSE);
	num = 1;
	num_pos = NUM_1;
	try_count = 1;
	refresh();

	srand(time(NULL)); //Generating code
	for(i=0;i<4;i++){
		code[i]=rand()%10;
		code_backup[i]=code[i];
	}

	/*//DEV_MODE
	int col=45;
	mvprintw(6,40,"CODE:");
	mvprintw(7,40,"ATMP:");
	mvprintw(8,40,"TCNT:");
	for(i=0;i<4;i++){
		mvprintw(6,col+i,"%d",code[i]);
		mvprintw(7,col+i,"%d",attempt[i]);
	}//DEV_MODE*/

	while(cmdkey!=KEY_ESC){
		cmdkey=getch();

		switch(cmdkey){

			case KEY_LEFT:
				switch(num){
					case 1: continue;
					case 2:
						num = 1;
						num_pos=NUM_1;
						mvprintw(NUM_R,NUM_2,"%d",attempt[num]);
						attron(A_REVERSE);
						mvprintw(NUM_R,NUM_1,"%d",attempt[num-1]);
						attroff(A_REVERSE);
						continue;
					case 3:
						num = 2;
						num_pos = NUM_2;
						mvprintw(NUM_R,NUM_3,"%d",attempt[num]);
						attron(A_REVERSE);
						mvprintw(NUM_R,NUM_2,"%d",attempt[num-1]);
						attroff(A_REVERSE);
						continue;
					case 4:
						num = 3;
						num_pos = NUM_3;
						mvprintw(NUM_R,NUM_4,"%d",attempt[num]);
						attron(A_REVERSE);
						mvprintw(NUM_R,NUM_3,"%d",attempt[num-1]);
						attroff(A_REVERSE);
						continue;
				}
				continue;

			case KEY_RIGHT:
				switch(num){
					case 1:
						num = 2;
						num_pos = NUM_2;
						mvprintw(NUM_R,NUM_1,"%d",attempt[num-2]);
						attron(A_REVERSE);
						mvprintw(NUM_R,NUM_2,"%d",attempt[num-1]);
						attroff(A_REVERSE);
						continue;
					case 2:
						num = 3;
						num_pos = NUM_3;
						mvprintw(NUM_R,NUM_2,"%d",attempt[num-2]);
						attron(A_REVERSE);
						mvprintw(NUM_R,NUM_3,"%d",attempt[num-1]);
						attroff(A_REVERSE);
						continue;
					case 3:
						num = 4;
						num_pos = NUM_4;
						mvprintw(NUM_R,NUM_3,"%d",attempt[num-2]);
						attron(A_REVERSE);
						mvprintw(NUM_R,NUM_4,"%d",attempt[num-1]);
						attroff(A_REVERSE);
						continue;
					case 4: continue;
				}
				continue;

			case KEY_UP:
				if(attempt[num-1] == 9){
					attempt[num-1] = 0;
					attron(A_REVERSE);
					mvprintw(NUM_R,num_pos,"0");
					attroff(A_REVERSE);
					//mvprintw(7,col+num-1,"%d",attempt[num-1]); //DEV_MODE
					continue;
				}
				attempt[num-1]++;
				attron(A_REVERSE);
				mvprintw(NUM_R,num_pos,"%d",attempt[num-1]);
				attroff(A_REVERSE);
				//mvprintw(7,col+num-1,"%d",attempt[num-1]); //DEV_MODE
				continue;

			case KEY_DOWN:
				if(attempt[num-1] == 0){
					attempt[num-1] = 9;
					attron(A_REVERSE);
					mvprintw(NUM_R,num_pos,"9");
					attroff(A_REVERSE);
					//mvprintw(7,col+num-1,"%d",attempt[num-1]); //DEV_MODE
					continue;
				}
				attempt[num-1]--;
				attron(A_REVERSE);
				mvprintw(NUM_R,num_pos,"%d",attempt[num-1]);
				attroff(A_REVERSE);
				//mvprintw(7,col+num-1,"%d",attempt[num-1]); //DEV_MODE
				continue;

			case 48:
				attempt[num-1]=0;
				attron(A_REVERSE);
				mvprintw(NUM_R,num_pos,"0");
				attroff(A_REVERSE);
				//mvprintw(7,col+num-1,"%d",attempt[num-1]); //DEV_MODE
				continue;
			case 49:
				attempt[num-1]=1;
				attron(A_REVERSE);
				mvprintw(NUM_R,num_pos,"1");
				attroff(A_REVERSE);
				//mvprintw(7,col+num-1,"%d",attempt[num-1]); //DEV_MODE
				continue;
			case 50:
				attempt[num-1]=2;
				attron(A_REVERSE);
				mvprintw(NUM_R,num_pos,"2");
				attroff(A_REVERSE);
				//mvprintw(7,col+num-1,"%d",attempt[num-1]); //DEV_MODE
				continue;
			case 51:
				attempt[num-1]=3;
				attron(A_REVERSE);
				mvprintw(NUM_R,num_pos,"3");
				attroff(A_REVERSE);
				//mvprintw(7,col+num-1,"%d",attempt[num-1]); //DEV_MODE
				continue;
			case 52:
				attempt[num-1]=4;
				attron(A_REVERSE);
				mvprintw(NUM_R,num_pos,"4");
				attroff(A_REVERSE);
				//mvprintw(7,col+num-1,"%d",attempt[num-1]); //DEV_MODE
				continue;
			case 53:
				attempt[num-1]=5;
				attron(A_REVERSE);
				mvprintw(NUM_R,num_pos,"5");
				attroff(A_REVERSE);
				//mvprintw(7,col+num-1,"%d",attempt[num-1]); //DEV_MODE
				continue;
			case 54:
				attempt[num-1]=6;
				attron(A_REVERSE);
				mvprintw(NUM_R,num_pos,"6");
				attroff(A_REVERSE);
				//mvprintw(7,col+num-1,"%d",attempt[num-1]); //DEV_MODE
				continue;
			case 55:
				attempt[num-1]=7;
				attron(A_REVERSE);
				mvprintw(NUM_R,num_pos,"7");
				attroff(A_REVERSE);
				//mvprintw(7,col+num-1,"%d",attempt[num-1]); //DEV_MODE
				continue;
			case 56:
				attempt[num-1]=8;
				attron(A_REVERSE);
				mvprintw(NUM_R,num_pos,"8");
				attroff(A_REVERSE);
				//mvprintw(7,col+num-1,"%d",attempt[num-1]); //DEV_MODE
				continue;
			case 57:
				attempt[num-1]=9;
				attron(A_REVERSE);
				mvprintw(NUM_R,num_pos,"9");
				attroff(A_REVERSE);
				//mvprintw(7,col+num-1,"%d",attempt[num-1]); //DEV_MODE
				continue;

			case ENTER:
				for(i=0;i<4;i++){
					code[i]=code_backup[i];
					attempt_copy[i]=attempt[i];
				}
				ok=0; nope=0;

				for(i=0;i<4;i++){
					mvprintw(INIT_R+try_count,NUM_1+(i*4),"%d",attempt[i]);
					refresh();
					if(attempt_copy[i]==code[i]){
						ok++;
						code[i]=-1;
						attempt_copy[i]=-2;
					}
				}

				for(i=0;i<4;i++){
					for(j=0;j<4;j++){
						if(attempt_copy[i]==code[j]){
							nope++;
							code[j]=-1;
							attempt_copy[i]=-2;
						}
					}
				}

				k=0;
				for(i=0;i<ok;i++){
					mvprintw(INIT_R+try_count,NUM_R+k,"x");
					k++;
				}
				for(i=0;i<nope;i++){
					mvprintw(INIT_R+try_count,NUM_R+k,"o");
					k++;
				}

				if(ok==4){ //Check for win or lose
					win();
					cmdkey = KEY_ESC;
					break;
				}
				else{
					if(try_count>11){
						mvprintw(10,39,"CODE:");
						for(i=0;i<4;i++){
							mvprintw(10,45+i,"%d",code_backup[i]);
						}
						lose();
						cmdkey = KEY_ESC;
						break;
					}
				}

				try_count++;
				//mvprintw(8,col,"%d",try_count); //DEV_MODE
				continue;

			case KEY_ESC:
				if(confirm_forfeit()!=TRUE){
					cmdkey=0;
					mvprintw(12,35,"                  ");
					mvprintw(13,35,"                  ");
					mvprintw(14,35,"                  ");
					refresh();
					continue;
				}
				else
					continue;

			default: continue;
		}
	}
}

int confirm_forfeit(){
	int val;
	char answer='Y';

	mvprintw(12,35,"------------------");
	mvprintw(13,35,"| Forfeit? [Y/N] |");
	mvprintw(14,35,"------------------");
	refresh();

	while(answer!='y' && answer!='n'){
		answer=getch();
		switch(answer){
			case 'n': val=FALSE; continue;
			case 'y': val=TRUE; continue;
			default: continue;
		}
	}
	return val;
}

void win(){

	mvprintw(12,30,"-------------------------");
	mvprintw(13,30,"|      YOU WIN! :-)     |");
	mvprintw(14,30,"|   Press a key to go   |");
	mvprintw(15,30,"| back to the MAIN MENU |");
	mvprintw(16,30,"-------------------------");
	refresh();
	getch();
}

void lose(){

	mvprintw(12,30,"-------------------------");
	mvprintw(13,30,"|      You Lose! :-(    |");
	mvprintw(14,30,"|   Press a key to go   |");
	mvprintw(15,30,"| back to the MAIN MENU |");
	mvprintw(16,30,"-------------------------");
	refresh();
	getch();
}

