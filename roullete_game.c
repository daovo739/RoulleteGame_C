#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <windows.h>
#define WHITE 15
#define GREEN 10
#define RED 12
#define YELLOW 14
#define PINK 13
#define LIGHT 11

//Change color
void setColor( int code ) {
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute( color , code );
}

// A function to get current time
void currentTime()
{	
	setColor(LIGHT);
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	printf("  %02d-%02d-%d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
	printf("   %02d:%02d:%02d\n", tm.tm_hour, tm.tm_min, tm.tm_sec);
}

// Functions menu
int menuOption()
{	
	setColor(15);
	int option;
	setColor(79);
	printf(" WELCOME TO ROULETTE GAME \n");
	setColor(12);
	printf("-------------------------\n");
	setColor(14);
	printf("     1. New game\n");
	printf("     2. Continue\n");
	printf("     3. How to play?\n");
	printf("     4. Exit!\n");
	setColor(12);
	printf("-------------------------\n");
	setColor(15);
	printf("Please choose : ");
	scanf("%d", &option);
	printf("\n");
	system("cls");
	return option;
}

int menuGame()
{
	int option;
	setColor(12);
	printf("-------------------------\n");
	setColor(WHITE);
	printf("1. BLACK / RED / GREEN \n");
	printf("2. NUMBER\n");
	printf("3. HIGH / LOW \n");
	printf("4. ODD / EVEN\n");
	printf("5. Back to menu game\n");
	printf("\nPlease choose a game mod: ");
	scanf("%d", &option);
	printf("\n");
	return option;
}

int menuColors()
{	
	setColor(WHITE);
	int n;
	setColor(12);
	printf("-------------------------\n");
	setColor(WHITE);
	printf("1. BLACK\n");
	setColor(RED);
	printf("2. RED\n");
	setColor(GREEN);
	printf("3. GREEN\n");
	setColor(WHITE);
	printf("\nPlease choose a game mod: ");
	scanf("%d", &n);
	printf("\n");
	return n;
}

int menuOddEven()
{	
	int n;
	setColor(12);
	printf("-------------------------\n");
	setColor(WHITE);
	setColor(PINK);
	printf("1. EVEN\n");
	setColor(YELLOW);
	printf("2. ODD\n");
	setColor(WHITE);
	printf("\nPlease choose a game mod: ");
	scanf("%d", &n);
	printf("\n");
	return n;
}

int menuHighLow()
{	
	setColor(12);
	int n;
	printf("-------------------------\n");
	setColor(WHITE);
	setColor(YELLOW);
	printf("1. High\n");
	setColor(PINK);
	printf("2. Low\n");
	setColor(WHITE);
	printf("\nPlease choose a game mod: ");
	scanf("%d", &n);
	printf("\n");
	return n;
}
// Tutorial 
int tutorial()
{	
	setColor(YELLOW);
	int n;
	printf("\t\tTUTORIAL\n\n");
	setColor(WHITE);
	setColor(11);
	printf("Each player initially has 1000$. They have 4 option to play:\n");
	setColor(WHITE);
	printf("- BLACK / RED / GREEN, if bot rolls your color you win\n");
	printf("- NUMBERS (0-36), if bot rolls your number you win\n");
	printf("- HIGH / LOW, low = 1-18, high = 19-36\n");
	printf("- ODD / EVEN, odd = 1, 3, 5 ..., 35, even = 2, 4, 6, ..., 36\n");
	printf("\nNumbers:\n");
	setColor(GREEN);
	printf("Green: 0\n");
	setColor(WHITE);
	printf("Black: 2, 4, 6, 8, 10, 11, 13, 15, 17, 20, 22, 24, 26, 28, 29, 31, 33, 35\n");
	setColor(RED);
	printf("Red: 1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36\n");
	setColor(11);
	printf("\nPrize:\n");
	setColor(WHITE);
	printf(" black/red - 2x\n");
	printf(" numbers - 35x\n");
	printf(" high/low - 2x\n");
	printf(" odd/even - 2x\n");
	setColor(11);
	printf("\nRule: Accepts only integers. The system will automatically save after each game\n");
	setColor(WHITE);
	do
	{
		printf("\nPress 1 to return the menu game: ");
		scanf("%d", &n);
		printf("\n");
	} while (n != 1);
	system("cls");
	return n;
}

// Function to check the player continue play or stop playing
int checkContinue()
{	
	setColor(WHITE);
	int n;
	printf("-------------------------\n");
	printf("Do you want to continue?\n");
	printf("1. Continue\n");
	printf("2. Back to menu game\n");
	printf("Please choose an option: ");
	scanf("%d", &n);
	printf("\n");
	return n;
}

// Functions for 4 game mode
int colorPlay(int point)
{	
	int color, i, count;
	int black[18] = {2, 4, 6, 8, 10, 11, 13, 15, 17, 20, 22, 24, 26, 28, 29, 31, 33, 35};
	int red[18] = {1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36};
	if (point == 0)
	{
		return 3;
	}
	for (i = 0; i < 18; i++)
	{
		if (point == black[i])
		{
			return 1;
		}
	}
	for (i = 0; i < 18; i++)
	{
		if (point == red[i])
		{
			return 2;
		}
	}
}

int numPlay(int point, int numberChosen)
{
	return point == numberChosen;
}

int highLowPlay(int point)
{
	if (37 > point && point > 18)
	{
		return 1;
	}
	if (18 >= point && point > 0)
	{
		return 2;
	}
}

int oddEvenPlay(int point)
{
	if (point == 0)
		return 0;
	if (point % 2 == 0)
		return 1;
	return 0;
}

// Funcstion to create a file to save old data
void createDirectory(){
/*Create a directory to store the player's data,
 including player's identities, money, and game history. 
 */
	char *dirname = "gamedata";
	mkdir(dirname);
}

int checkIfFileExists()
{
    /*Check if the player data is in the game data directory.
*Return 1 if yes, there exists the player's data.
*Return 0 if no, the player has not created an account, or it
*has been removed.
*/
    struct stat buffer;
    int exist = stat("gamedata\\player.txt", &buffer);
    if (exist == 0)
        return 1;
    else
        return 0;
}

void encryptingData()
/*Encrypting a file to prevent unwanted data changes. */
{
    FILE *playerdata = fopen("gamedata\\player.txt", "r");
    FILE *temp = fopen("gamedata\\temp.txt", "w");
    char ch;

    /*Encrypting process*/
    ch = fgetc(playerdata);
    while (ch != EOF)
    {
        ch = ch + 100;
        fputc(ch, temp);
        ch = fgetc(playerdata);
    }
    fclose(playerdata);
    fclose(temp);

    /*Copy the encrypted content from the temp file to the data file.*/
    playerdata = fopen("gamedata\\player.txt", "w");
    temp = fopen("gamedata\\temp.txt", "r");
    ch = fgetc(temp);
    while (ch != EOF)
    {
        ch = fputc(ch, playerdata);
        ch = fgetc(temp);
    }
    fclose(playerdata);
    fclose(temp);

    /*Remove the temp file.*/
    remove("gamedata\\temp.txt");
}

void decryptingData()
{
    FILE *playerdata = fopen("gamedata\\player.txt", "r");
    FILE *temp = fopen("gamedata\\temp.txt", "w");
    char ch;

    /*Copy the content from the data file to a temp file for decrypting.*/
    ch = fgetc(playerdata);
    while (ch != EOF)
    {
        ch = fputc(ch, temp);
        ch = fgetc(playerdata);
    }
    fclose(playerdata);
    fclose(temp);

    /*Decrypt the data file.*/
    playerdata = fopen("gamedata\\player.txt", "w");
    temp = fopen("gamedata\\temp.txt", "r");
    ch = fgetc(temp);
    while (ch != EOF)
    {
        ch = ch - 100;
        fputc(ch, playerdata);
        ch = fgetc(temp);
    }
    fclose(playerdata);
    fclose(temp);

    /*Remove the temp file.*/
    remove("gamedata\\temp.txt");
}

void writeData(int money, char name[])
{
     decryptingData();
    FILE *playerdata = fopen("gamedata\\player.txt", "w");
    char money_text[100];
    char nameFile[100];
    strcpy(nameFile, name);
    itoa(money, money_text, 10);
    strcat(nameFile, "\n"); //chinh lai \n neu muon xuong dong
    strcat(nameFile, money_text);
    fprintf(playerdata, "%s", nameFile);
    fclose(playerdata);
     encryptingData();
}

int loadMoney()
{
     decryptingData();
    FILE *playerdata = fopen("gamedata\\player.txt", "r");
    int money, i = 0;
    char name[100], money_text[100], line[100];
    char data[2][100];

    while (fscanf(playerdata, "%[^\n]%*c", data[i]) != EOF)
    {
        i++;
    }
    strcpy(money_text, data[1]);
    fclose(playerdata);
    money = atoi(money_text);
     encryptingData();

    return money;
}

void loadName(char *names){
	decryptingData();
    FILE *playerdata = fopen("gamedata\\player.txt", "r");
	fscanf(playerdata, "%[^\n]", names);
	fclose(playerdata);  /* close the file */
	encryptingData();
}

//Sub function for each game mode
//Case 1 colors
void checkBlack(int numRandom, char name[], int *money, int bet)
{
	int result = colorPlay(numRandom);
	setColor(WHITE);
	printf("Winning number: %d\n", numRandom);
	if (result == 1)
	{	
		printf("%s choose BLACK. You win\n\n", name);
		*money += bet * 2;
	}
	else
	{
		printf("%s choose BLACK. You lose\n\n", name);
	}
	writeData(*money, name);
}

void checkRed(int numRandom, char name[], int *money, int bet)
{	
	setColor(WHITE);
	int result = colorPlay(numRandom);
	printf("Winning number: %d\n", numRandom);
	if (result == 2)
	{
		setColor(RED);
		printf("%s choose RED. You win\n\n", name);
		*money += bet * 2;
	}
	else
	{	
		setColor(RED);
		printf("%s choose RED. You lose\n\n", name);
	}
	writeData(*money, name);
}

void checkGreen(int numRandom, char name[], int *money, int bet)
{	
	setColor(WHITE);
	int result = colorPlay(numRandom);
	printf("Winning number: %d\n", numRandom);
	if (result == 3)
	{	
		setColor(GREEN);
		printf("%s choose GREEN. You win\n\n", name);
		*money += bet * 35;
	}
	else
	{	
		setColor(GREEN);
		printf("%s choose GREEN. You lose\n\n", name);
	}
	writeData(*money, name);
}

//Case 2 numbers
void checkNumbers(int numRandom, int number, char name[], int *money, int bet)
{
	if (numPlay(numRandom, number))
	{
		*money += bet * 35;
		printf("Your number: %d\n", number);
		printf("Winning number: %d\n", numRandom);
		printf("%s win\n\n", name);
	}
	else
	{
		printf("Your number: %d\n", number);
		printf("Winning number: %d\n", numRandom);
		printf("%s lose\n\n", name);
	}
	writeData(*money, name);
}

// Case 3 high / low
void checkHigh(int numRandom, char name[], int *money, int bet)
{
	int result = highLowPlay(numRandom);
	printf("Winning number: %d\n", numRandom);
	if (result == 1)
	{
		printf("%s choose HIGH. You win\n\n", name);
		*money += bet * 2;
	}
	else
	{
		printf("%s choose HIGH. You lose\n\n", name);
	}
	writeData(*money, name);
}

void checkLow(int numRandom, char name[], int *money, int bet)
{
	int result = highLowPlay(numRandom);
	printf("Winning number: %d\n", numRandom);
	if (result == 2)
	{
		printf("%s choose LOW. You win\n\n", name);
		*money += bet * 2;
	}
	else
	{
		printf("%s choose LOW. You lose\n\n", name);
	}
	writeData(*money, name);
}

//Case 4 even / odd
void checkEven(int numRandom, char name[], int *money, int bet)
{
	int result = highLowPlay(numRandom);
	printf("Winning number: %d\n", numRandom);
	if (result == 1)
	{
		printf("%s choose EVEN. You win\n\n", name);
		*money += bet * 2;
	}
	else
	{
		printf("%s choose EVEN. You lose\n\n", name);
	}
	writeData(*money, name);
}

void checkOdd(int numRandom, char name[], int *money, int bet)
{
	int result = highLowPlay(numRandom);
	printf("Winning number: %d\n", numRandom);
	if (result == 0)
	{
		printf("%s choose ODD. You win\n\n", name);
		*money += bet * 2;
	}
	else
	{
		printf("%s choose ODD. You lose\n\n", name);
	}
	writeData(*money, name);
}

// Main menu
void mainMenu()
{
	int option, number, numRandom, result, bet, money;
	char name[100];
	option = menuOption();
	switch (option)
	{
	case 1:
		setColor(YELLOW);
		printf("Your name: ");
		setColor(WHITE);
		fflush(stdin);
		gets(name);
		printf("\n");
		money = 1000;
		writeData(money, name);
		while (1)
		{
			if (money <= 0)
			{
				printf("Not enough money!\n");
				mainMenu();
				return;
			}
			currentTime();
			setColor(12);
			printf("\nYour money: ");
			setColor(WHITE);
			printf("%d\n\n", money);
//			setColor(WHITE);
			do
			{	
				setColor(YELLOW);
				printf("Enter your bet: ");
				setColor(WHITE);
				scanf("%d", &bet);
			} while (bet <= 0 || bet > money);
			
			money -= bet;
			srand(time(NULL));
			numRandom = rand() % 37;
			do
			{
				option = menuGame();
			} while (option < 1 || option > 5);
			switch (option)
			{
			case 1:
				do
				{
					option = menuColors();
				} while (option < 0 || option > 4);
				switch (option)
				{
				case 1:
					checkBlack(numRandom, name, &money, bet);
					do
					{
						result = checkContinue();
					} while (result < 0 || result > 2);
					if (result == 1)
					{	
						system("cls");
						continue;
					}
					else
					{	
						system("cls");
						mainMenu();
					}
					break;
				case 2:
					checkRed(numRandom, name, &money, bet);
					do
					{
						result = checkContinue();
					} while (result < 0 || result > 2);
					if (result == 1)
					{	
						system("cls");
						continue;
					}
					else
					{
						system("cls");
						mainMenu();
					}
					break;
				case 3:
					checkGreen(numRandom, name, &money, bet);
					do
					{
						result = checkContinue();
					} while (result < 0 || result > 2);
					if (result == 1)
					{	
						system("cls");
						continue;
					}
					else
					{	
						system("cls");
						mainMenu();
					}
					break;
				}
				break;
			case 2:
				do
				{
					printf("-------------------------\n");
					printf("Enter your number (0-36): ");
					scanf("%d", &number);
				} while (number < 0 || number > 36);
				checkNumbers(numRandom, number, name, &money, bet);
				do
				{
					result = checkContinue();
				} while (result < 0 || result > 2);
				if (result == 1)
				{
					system("cls");
					continue;
				}
				else
				{
					system("cls");
					mainMenu();
				}
				break;
			case 3:
				do
				{
					option = menuHighLow();
				} while (option < 0 || option > 2);
				switch (option)
				{
				case 1:
					checkHigh(numRandom, name, &money, bet);
					do
					{
						result = checkContinue();
					} while (result < 0 || result > 2);
					if (result == 1)
					{	
						system("cls");
						continue;
					}
					else
					{
						system("cls");
						mainMenu();
					}
					break;
				case 2:
					checkLow(numRandom, name, &money, bet);
					do
					{
						result = checkContinue();
					} while (result < 0 || result > 2);
					if (result == 1)
					{
						system("cls");	
						continue;
					}
					else
					{	
						system("cls");
						mainMenu();
					}
					break;
				}
				break;
			case 4:
				do
				{
					option = menuOddEven();
				} while (option < 0 && option > 2);
				switch (option)
				{
				case 1:
					checkEven(numRandom, name, &money, bet);
					do
					{
						result = checkContinue();
					} while (result < 0 || result > 2);
					if (result == 1)
					{
						system("cls");
						continue;
					}
					else
					{
						system("cls");
						mainMenu();
					}
					break;
				case 2:
					checkOdd(numRandom, name, &money, bet);
					do
					{
						result = checkContinue();
					} while (result < 0 || result > 2);
					if (result == 1)
					{
						system("cls");
						continue;
					}
					else
					{
						system("cls");
						mainMenu();
					}
					break;
				}
				break;
			case 5:
				money += bet;
				system("cls");
				mainMenu();
				break;
			}
		}
		break;
	case 2:
		if (checkIfFileExists() == 1)
		{
			money = loadMoney();
			char nameSub[100];
			loadName(nameSub);
			printf("Welcome back %s\n\n", &nameSub);
			while (1)
			{
				if (money <= 0)
				{
					printf("Not enough money!\n\n");
					mainMenu();
					return;
				}
			 	currentTime();
			 	setColor(WHITE);
				printf("\nYour money: %d\n\n", money);
				do
				{
					printf("Enter your bet: ");
					scanf("%d", &bet);
				} while (bet <= 0 || bet > money);
				money -= bet;
				srand(time(NULL));
				numRandom = rand() % 37;
				do
				{
					option = menuGame();
				} while (option < 1 || option > 5);
				switch (option)
				{
				case 1:
					do
					{
						option = menuColors();
					} while (option < 0 || option > 4);
					switch (option)
					{
					case 1:
						checkBlack(numRandom, nameSub, &money, bet);
						do
						{
							result = checkContinue();
						} while (result < 0 || result > 2);
						if (result == 1)
						{
							system("cls");
							continue;
						}
						else
						{
							system("cls");
							mainMenu();
						}
						break;
					case 2:
						checkRed(numRandom, nameSub, &money, bet);
						do
						{
							result = checkContinue();
						} while (result < 0 || result > 2);
						if (result == 1)
						{
							system("cls");
							continue;
						}
						else
						{
							system("cls");
							mainMenu();
						}
						break;
					case 3:
						checkGreen(numRandom, nameSub, &money, bet);
						do
						{
							result = checkContinue();
						} while (result < 0 || result > 2);
						if (result == 1)
						{
							system("cls");
							continue;
						}
						else
						{
							system("cls");
							mainMenu();
						}
						break;
					}
					break;
				case 2:
					do
					{
						printf("-------------------------\n");
						printf("Enter your number (0-36): ");
						scanf("%d", &number);
					} while (number < 0 || number > 36);
					checkNumbers(numRandom, number, nameSub, &money, bet);
					do
					{
						result = checkContinue();
					} while (result < 0 || result > 2);
					if (result == 1)
					{
						system("cls");
						continue;
					}
					else
					{
						system("cls");
						mainMenu();
					}
					break;
				case 3:
					do
					{
						option = menuHighLow();
					} while (option < 0 || option > 2);
					switch (option)
					{
					case 1:
						checkHigh(numRandom, nameSub, &money, bet);
						do
						{
							result = checkContinue();
						} while (result < 0 || result > 2);
						if (result == 1)
						{
							system("cls");
							continue;
						}
						else
						{
							system("cls");
							mainMenu();
						}
						break;
					case 2:
						checkLow(numRandom, nameSub, &money, bet);
						do
						{
							result = checkContinue();
						} while (result < 0 || result > 2);
						if (result == 1)
						{
							system("cls");
							continue;
						}
						else
						{
							system("cls");
							mainMenu();
						}
						break;
					}
					break;
				case 4:
					do
					{
						option = menuOddEven();
					} while (option < 0 && option > 2);
					switch (option)
					{
					case 1:
						checkEven(numRandom, nameSub, &money, bet);
						do
						{
							result = checkContinue();
						} while (result < 0 || result > 2);
						if (result == 1)
						{
							system("cls");
							continue;
						}
						else
						{
							system("cls");
							mainMenu();
						}
						break;
					case 2:
						checkOdd(numRandom, nameSub, &money, bet);
						do
						{
							result = checkContinue();
						} while (result < 0 || result > 2);
						if (result == 1)
						{
							system("cls");
							continue;
						}
						else
						{
							system("cls");
							mainMenu();
						}
						break;
					}
					break;
				case 5:
					money += bet;
					system("cls");
					mainMenu();
					break;
				}
			}
		}
		else
		{
			system("cls");
			mainMenu();
		}
		break;
	case 3:
		do{
			result = tutorial();
		}while(result != 1);
		if (result == 1) mainMenu();
		break;
	case 4:
		system("cls");
		printf("Thanks for playing! See u again!");
		exit(0);
		break;
	}
}

//Main function
int main(int argc, char *argv[])
{
	createDirectory();
	mainMenu();
	getch();
	return 0;
}
