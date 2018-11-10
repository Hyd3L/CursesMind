#include <ncurses.h>
#include <unistd.h>
#include <string.h>
#include "cursesmind.h"

int main(){
	initscr();
	raw();
	noecho();
	curs_set(FALSE);
	keypad(stdscr,TRUE);

	intro();

	menu();

	endwin();

	return 0;
}

void intro(){
	int i;
	char title[] = {"o   o ooooo ooooo ooooo ooooo ooooo o   o  o  o   o ooo\n"
					"oo oo o   o o       o   o     o   o oo oo  o  oo  o o  o\n"
					"o o o ooooo ooooo   o   oooo  ooooo o o o  o  o o o o   o\n"
					"o   o o   o     o   o   o     o  o  o   o  o  o  oo o  o\n"
					"o   o o   o ooooo   o   ooooo o   o o   o  o  o   o ooo\n\n"};

	for(i=0;i<strlen(title);i++){
		printw("%c",title[i]);
		refresh();
		usleep(DELAY);
	}

	attron(A_BOLD);
	printw("              PRESS ANY KEY TO START...");
	attroff(A_BOLD);
	refresh();
	getch();
}

void menu(){

	int choice=MAIN_MENU_1;
	char main_menu[] = {"o   o ooooo ooooo ooooo ooooo ooooo o   o  o  o   o ooo\n"
						"oo oo o   o o       o   o     o   o oo oo  o  oo  o o  o\n"
						"o o o ooooo ooooo   o   oooo  ooooo o o o  o  o o o o   o\n"
						"o   o o   o     o   o   o     o  o  o   o  o  o  oo o  o\n"
						"o   o o   o ooooo   o   ooooo o   o o   o  o  o   o ooo\n"
						"=MAIN=MENU===============================================\n\n"

						"[1] New Game\n"
						"[2] Manual\n"
						"[3] Credits\n"
						"[4] Quit"};

	while(choice!=SIG_QUIT){
		clear();
		refresh();
		printw(main_menu);
		mvprintw(LINES-2,1,"Type number in brackets to select an option");
		refresh();

		choice=getch();

		switch(choice){
			case MAIN_MENU_1:
				new_game();
				continue;
			case MAIN_MENU_2:
				manual();
				continue;
			case MAIN_MENU_3:
				credits();
				continue;
			case MAIN_MENU_4:
				if(confirm_quit()!=TRUE){
					choice=MAIN_MENU_1;
					continue;
				}
				else
					choice=SIG_QUIT;
		}
	}

}

void manual(){
	char helpscr[]={ "o   o ooooo ooooo ooooo ooooo ooooo o   o  o  o   o ooo\n"
					 "oo oo o   o o       o   o     o   o oo oo  o  oo  o o  o\n"
					 "o o o ooooo ooooo   o   oooo  ooooo o o o  o  o o o o   o\n"
					 "o   o o   o     o   o   o     o  o  o   o  o  o  oo o  o\n"
					 "o   o o   o ooooo   o   ooooo o   o o   o  o  o   o ooo\n"
					 "=MANUAL==================================================\n\n"

					 "The goal is to crack a four digit secret PIN.\n"
					 "Digits are from 0 to 9 and can be repeated.\n"
					 "You have 12 attempts to guess the secret code.\n"
					 "While you do attempts, the AI will give you tips like\n"
					 "this:\n\n"

					 " [3] [4] [5] [6]  |\n\n"

					 " o <-- This means that you have guessed a digit\n"
					 "       in the wrong position.\n"
					 " x <-- This means that you have guessed a digit\n"
					 "       in the right position.\n\n"

					 "WARNING. This doesn't tell you in which position is the\n"
					 "digit you have guessed, it tells you just how many digits\n"
					 "you have guessed.\n\nHave fun! :-)"};
	clear();
	printw(helpscr);
	mvprintw(LINES-2,1,"Press any key to go back to the MAIN MENU");
	attron(A_BOLD);mvprintw(13,21,"xxo");attroff(A_BOLD);
	refresh();
	getch();
}

void credits(){
	char creditscr[]= { "o   o ooooo ooooo ooooo ooooo ooooo o   o  o  o   o ooo\n"
					 	"oo oo o   o o       o   o     o   o oo oo  o  oo  o o  o\n"
					 	"o o o ooooo ooooo   o   oooo  ooooo o o o  o  o o o o   o\n"
					 	"o   o o   o     o   o   o     o  o  o   o  o  o  oo o  o\n"
					 	"o   o o   o ooooo   o   ooooo o   o o   o  o  o   o ooo\n"
					 	"=CREDITS=================================================\n\n"

					 	"CursesMind v.2.1\n"
					 	"Author: Hyd3L\n"};
	clear();
	printw(creditscr);
	mvprintw(LINES-2,1,"Press any key to go back to the MAIN MENU");
	refresh();
	getch();
}

int confirm_quit(){
	int val;
	char answer='Y';

	mvprintw(15,10,"----------------------------------------");
	mvprintw(16,10,"| Are you sure you want to quit? [Y/N] |");
	mvprintw(17,10,"----------------------------------------");
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

