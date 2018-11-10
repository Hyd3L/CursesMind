#define FALSE 0
#define TRUE 1
#define DELAY 3500
#define ENTER 10
#define KEY_ESC 27

#define MAIN_MENU_1 49
#define MAIN_MENU_2 50
#define MAIN_MENU_3 51
#define MAIN_MENU_4 52
#define SIG_QUIT 53

#define INIT_R 6
#define NUM_R 21
#define NUM_1 2
#define NUM_2 6
#define NUM_3 10
#define NUM_4 14

//main.c
void intro();
void menu();
void manual();
void credits();
int confirm_quit();

//game.c
void new_game();
int confirm_forfeit();
void win();
void lose();

