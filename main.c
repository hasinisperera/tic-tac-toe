//AS2016469
//J D H S PERERA

#include <stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>

//an array store the values of the board
char arr[9];

//to reset the board after a game
void resetBoard(char arr[8]);

//to print the instructions of the game before starting
void printInstructions();

//to read the character the user chose to play with
void readCharacter(char *character, int *player);

//to read if the player wants to play first or send
void readPlayer(int *player);

//to print the game board
void gameBoard();

//to initiate the game
void initiateGame(char character, int player, char arr[9]);

//to let the user play the game
void playHuman(char character, char arr[9]);

//to let the computer play the game
void playComputer(char character);

//to check the winner of the game
void checkWinner(char arr[9], char character);

//main
int main()
{
    system("cls");
    int player; //number to play first or second by the user
    char character; //character which the user chooses to play

    resetBoard(arr);
    printInstructions();
    readCharacter(&character, &player);
    printf("\n");
    gameBoard();

    initiateGame(character, player, arr);
    printf("\n");
    gameBoard();

    int i, j;

    //if the user chose to play first
    if(player==1){
        for(i=0; i<4; i++){
            playComputer(character);
            gameBoard();
            checkWinner(arr, character);
            playHuman(character, arr);
            gameBoard();
            checkWinner(arr, character);
        }
        checkWinner(arr, character);
        printf("\nGAME DRAW!");
        printf("\nPRESS ANY KEY TO RESATRT THE GAME!");
        getch();
        main();
    }

    //if the user chose to play second
    if(player==2){
        for(j=0; j<4; j++){
            playHuman(character, arr);
            gameBoard();
            checkWinner(arr, character);
            playComputer(character);
            gameBoard();
            checkWinner(arr, character);
        }
        playHuman(character, arr);
        checkWinner(arr, character);
        printf("\nGAME DRAW!");
        printf("\nPRESS ANY KEY TO RESATRT THE GAME!");
        getch();
        main();
    }


    return 0;
}

//resets the board after playing the game once
void resetBoard(char arr[8])
{
    arr[0]='1';
    arr[1]='2';
    arr[2]='3';
    arr[3]='4';
    arr[4]='5';
    arr[5]='6';
    arr[6]='7';
    arr[7]='8';
    arr[8]='9';
}

//prints instructions of the game before starting the game. Gives a brief explanation of how to use the game
void printInstructions()
{
    system("color 3");
    printf("\tWELCOME TO TIC TAC TOE");
    printf("\n\n\t   ??HOW TO PLAY??");
    printf("\n\n1.Select which character, 'x' or 'o' you want to play! \n2.Select 1 to play fist, 2 to play send!");
    printf("\n3.Enter the number of the cell of the board to play!");
    printf("\n\n\t-------------");
    printf("\n\t| 1 | 2 | 3 |");
    printf("\n\t-------------");
    printf("\n\t| 4 | 5 | 6 |");
    printf("\n\t-------------");
    printf("\n\t| 7 | 8 | 9 |");
    printf("\n\t-------------");
    printf("\n\nGOOD LUCK!!!");
    printf("\n\nPress any key to start the game");
    getch();
}

//reads the character the user wishes to play 'x' or 'o'
void readCharacter(char *character, int *player)
{
    system("cls");
    system("color 5");
    printf("\n");
    printf("Enter the character you want to play, X or O :");
    scanf(" %c", character);
    if(*character=='x'||*character=='X'){
        *character='x';
    }else if(*character=='o'||*character=='O'){
        *character='o';
    }

    if(*character=='x' || *character=='o'){
        readPlayer(player);
    }
    else
        readCharacter(&character, &player);
}

//reads whether the user wants to play first or let the computer play first
void readPlayer(int *player)
{
    system("color 5");
    printf("\n");
    printf("Enter 1 to play first, 2 to play second      :");
    scanf("%d",player);
    if(*player==1||*player==2){
    }else{
        readPlayer(player);
    }
}

//prints the game board
void gameBoard()
{
    system("cls");
    printf("      Tic Tac Toe\n");
    printf("\n");
    printf("     -------------\n");
    printf("     | %c | %c | %c |\n", arr[0], arr[1], arr[2]);
    printf("     -------------\n");
    printf("     | %c | %c | %c |\n", arr[3], arr[4], arr[5] );
    printf("     -------------\n");
    printf("     | %c | %c | %c |\n", arr[6], arr[7], arr[8]);
    printf("     -------------\n");
}

//initiate the game after reading the character and player
void initiateGame(char character, int player, char arr[9])
{
        if (player == 2){

            if (character=='x'){
                arr[4]='o';
            }
            else {
                arr[4]='x';
            }
        }
        else {
            playHuman(character, arr);
        }
    }

//let the user make a move on the board, chose which cell to play the next move and assign the character to the selected cell
void playHuman(char character, char arr[9])
{
    int cell; //stores the number of the cell input by the user

    printf("\n\nEnter the number of cell:");
    scanf("%d", &cell);

    if(arr[cell-1]=='x' || arr[cell-1]=='o'){
        printf("\n\nCELL ALREADY FILLED!!!\n");
        playHuman(character, arr);
    }
            switch(cell){
                case 1: arr[0]=character;
                break;
                case 2: arr[1]=character;
                break;
                case 3: arr[2]=character;
                break;
                case 4: arr[3]=character;
                break;
                case 5: arr[4]=character;
                break;
                case 6: arr[5]=character;
                break;
                case 7: arr[6]=character;
                break;
                case 8: arr[7]=character;
                break;
                case 9: arr[8]=character;
                break;
                default: printf("\n\nINVALID MOVE!!!");
                        playHuman(character, arr);
            }

}

//analyses the best position to play by the computer and assign the computer's character to the cell analysed
void playComputer(char character)
{
    int points012, points345, points678, points036, points147, points258, points048, points246; //stores points given to rows, '012, 345, 678', columns '036, 147, 258', and diagonals '048, 246
    int valueOfCell[9]; //stores the total of points of cells 1 to 9
    int maximum=0; //stores the value of the cell with the highest points
    int high=0; //stores the number of the cell with the highest points
    int i;

    //calculating the points for each rows, columns and diagonals
    if(arr[0]=='1' && arr[1]=='2' && arr[2]=='3'){
        points012=1;
    }
    if(arr[3]=='4' && arr[4]=='5' && arr[5]=='6'){
        points345=1;
    }
    if(arr[6]=='7' && arr[7]=='8' && arr[8]=='9'){
        points678=1;
     }
     if(arr[0]=='1' && arr[3]=='4' && arr[6]=='7'){
        points036=1;
     }
     if(arr[1]=='2' && arr[4]=='5' && arr[7]=='8'){
        points147=1;
     }
     if(arr[2]=='3' && arr[5]=='6' && arr[8]=='9'){
        points258=1;
     }
     if(arr[0]=='1' && arr[4]=='5' && arr[8]=='9'){
        points048=1;
     }
     if(arr[2]=='3' && arr[4]=='5' && arr[6]=='7'){
        points246=1;
     }



    if((arr[0]=='x' || arr[1]=='x' || arr[2]=='x') && (arr[0]=='o' || arr[1]=='o' || arr[2]=='o'))
       points012=0;
    if((arr[3]=='x' || arr[4]=='x' || arr[5]=='x') && (arr[3]=='o' || arr[4]=='o' || arr[5]=='o'))
       points345=0;
    if((arr[6]=='x' || arr[7]=='x' || arr[8]=='x') && (arr[6]=='o' || arr[7]=='o' || arr[8]=='o'))
       points678=0;
    if((arr[0]=='x' || arr[3]=='x' || arr[6]=='x') && (arr[0]=='o' || arr[3]=='o' || arr[6]=='o'))
       points036=0;
    if((arr[1]=='x' || arr[4]=='x' || arr[7]=='x') && (arr[1]=='o' || arr[4]=='o' || arr[7]=='o'))
       points147=0;
    if((arr[2]=='x' || arr[5]=='x' || arr[8]=='x') && (arr[2]=='o' || arr[5]=='o' || arr[8]=='o'))
       points258=0;
    if((arr[0]=='x' || arr[4]=='x' || arr[8]=='x') && (arr[0]=='o' || arr[4]=='o' || arr[8]=='o'))
       points048=0;
    if((arr[2]=='x' || arr[4]=='x' || arr[6]=='x') && (arr[2]=='o' || arr[4]=='o' || arr[6]=='o'))
       points246=0;


    if((arr[0]=='x' && arr[1]=='x') || (arr[1]=='x' && arr[2]=='x') || (arr[0]=='x' && arr[2]=='x')){
        points012=100;

    }
    else if(arr[0]=='x' || arr[1]=='x' || arr[2]=='x'){
        points012=9;
    }
    if((arr[3]=='x' && arr[4]=='x') || (arr[4]=='x' && arr[5]=='x') || (arr[3]=='x' && arr[5]=='x')){
        points345=100;
    }
    else if(arr[3]=='x' || arr[4]=='x' || arr[5]=='x'){
        points345=9;
    }
    if((arr[6]=='x' && arr[7]=='x') || (arr[7]=='x' && arr[8]=='x') || (arr[6]=='x' && arr[8]=='x')){
        points678=100;
    }
    else if(arr[6]=='x' || arr[7]=='x' || arr[8]=='x'){
        points678=9;
    }
    if((arr[0]=='x' && arr[3]=='x') || (arr[3]=='x' && arr[6]=='x') || (arr[0]=='x' && arr[6]=='x')){
        points036=100;
    }
    else if(arr[0]=='x' || arr[3]=='x' || arr[6]=='x'){
        points036=9;
    }
    if((arr[1]=='x' && arr[4]=='x') || (arr[4]=='x' && arr[7]=='x') || (arr[1]=='x' && arr[7]=='x')){
        points147=100;

    }
    else if(arr[1]=='x' || arr[4]=='x' || arr[7]=='x'){
        points147=9;
    }
    if((arr[2]=='x' && arr[5]=='x') || (arr[5]=='x' && arr[8]=='x') || (arr[2]=='x' && arr[8]=='x')){
        points258=100;
    }
    else if(arr[2]=='x' || arr[5]=='x' || arr[8]=='x'){
        points258=9;
    }
    if((arr[0]=='x' && arr[4]=='x') || (arr[4]=='x' && arr[8]=='x') || (arr[0]=='x' && arr[8]=='x')){
        points048=100;
    }
    else if(arr[0]=='x' || arr[4]=='x' || arr[8]=='x'){
        points048=9;
    }
    if((arr[2]=='x' && arr[4]=='x') || (arr[4]=='x' && arr[6]=='x') || (arr[2]=='x' && arr[6]=='x')){
        points246=100;
    }
    else if(arr[2]=='x' || arr[4]=='x' || arr[6]=='x'){
        points246=9;
    }


    if((arr[0]=='o' && arr[1]=='o') || (arr[1]=='o' && arr[2]=='o') || (arr[0]=='o' && arr[2]=='o')){
        points012=1000;
    }
    else if(arr[0]=='o' || arr[1]=='o' || arr[2]=='o'){
        points012=10;
    }
    if((arr[3]=='o' && arr[4]=='o') || (arr[4]=='o' && arr[5]=='o') || (arr[3]=='o' && arr[5]=='o')){
        points345=1000;
    }
    else if(arr[3]=='o' || arr[4]=='o' || arr[5]=='o'){
        points345=10;
    }
    if((arr[6]=='o' && arr[7]=='o') || (arr[7]=='o' && arr[8]=='o') || (arr[6]=='o' && arr[8]=='o')){
        points678=1000;
    }
    else if(arr[6]=='o' || arr[7]=='o' || arr[8]=='o'){
        points678=10;
    }
    if((arr[0]=='o' && arr[3]=='o') || (arr[3]=='o' && arr[6]=='o') || (arr[0]=='o' && arr[6]=='o')){
        points036=1000;
    }
    else if(arr[0]=='o' || arr[3]=='o' || arr[6]=='o'){
        points036=10;
    }
    if((arr[1]=='o' && arr[4]=='o') || (arr[4]=='o' && arr[7]=='o') || (arr[1]=='o' && arr[7]=='o')){
        points147=1000;
    }
    else if(arr[1]=='o' || arr[4]=='o' || arr[7]=='o'){
        points147=10;
    }
    if((arr[2]=='o' && arr[5]=='o') || (arr[5]=='o' && arr[8]=='o') || (arr[2]=='o' && arr[8]=='o')){
        points258=1000;
    }
    else if(arr[2]=='o' || arr[5]=='o' || arr[8]=='o'){
        points258=10;
    }
    if((arr[0]=='o' && arr[4]=='o') || (arr[4]=='o' && arr[8]=='o') || (arr[0]=='o' && arr[8]=='o')){
        points048=1000;
    }
    else if(arr[0]=='o' || arr[4]=='o' || arr[8]=='o'){
        points048=10;
    }
    if((arr[2]=='o' && arr[4]=='o') || (arr[4]=='o' && arr[6]=='o') || (arr[2]=='o' && arr[6]=='o')){
        points246=1000;
    }
    else if(arr[2]=='o' || arr[4]=='0' || arr[6]=='o'){
        points246=10;
    }

    //calculating the sum of points for each cell
    valueOfCell[0] = points012 + points036 + points048;
    valueOfCell[1] = points147 + points012;
    valueOfCell[2] = points012 + points246 + points258;
    valueOfCell[3] = points036 + points345;
    valueOfCell[4] = points048 + points147 + points246 + points345;
    valueOfCell[5] = points258 + points345;
    valueOfCell[6] = points036 + points246 + points678;
    valueOfCell[7] = points147 + points678;
    valueOfCell[8] = points048 + points258 + points678;

    for(i=0;i<9;i++){

        if(valueOfCell[i]>=maximum){

            if(arr[i]=='x' || arr[i]=='o'){
                maximum=maximum;
                high=high;
            }
            else {
                maximum=valueOfCell[i];
                high=i;
            }
        }
        else {
            maximum=maximum;
            high=high;
        }

        }


    //find the cell with the highest points
    if(character=='x'){
        arr[high]='o';
    }
    else{
        arr[high]='x';
    }
    }

//checks the winner of the game and display the result
void checkWinner(char arr[9], char character)
    {
        if(arr[0]=='1' || arr[1]=='2' || arr[3]=='4' || arr[4]=='5' || arr[5]=='6' || arr[6]=='7' || arr[7]=='8' || arr[8]=='9'){
        }

        if(arr[0]=='x' && arr[1]=='x' && arr[2]=='x') {
            if(character=='x'){
                printf("\n\nCONGRATULATIONS, YOU WON!!!");
                printf("\n\nPRESS ANY KEY TO REPLAY!!!");
                getch();
                main();
            }
            else
                printf("\n\nYOU LOST!");
                printf("\n\nPRESS ANY KEY TO REPLAY!!!");
                getch();
                main();
        }
        if(arr[0]=='o' && arr[1]=='o' && arr[2]=='o'){
            if(character=='o'){
                printf("\n\nCONGRATULATIONS, YOU WON!!!");
                printf("\n\nPRESS ANY KEY TO REPLAY!!!");
                getch();
                main();
            }
            else
                printf("\n\nYOU LOST!");
                printf("\n\nPRESS ANY KEY TO REPLAY!!!");
                getch();
                main();
        }
        if(arr[3]=='x' && arr[4]=='x' && arr[5]=='x'){
            if(character=='x'){
                printf("\n\nCONGRATULATIONS, YOU WON!!!");
                printf("\n\nPRESS ANY KEY TO REPLAY!!!");
                getch();
                main();
            }
            else
                printf("\n\nYOU LOST!");
                printf("\n\nPRESS ANY KEY TO REPLAY!!!");
                getch();
                main();
        }
        if(arr[3]=='o' && arr[4]=='o' && arr[5]=='o'){
            if(character=='o'){
                printf("\n\nCONGRATULATIONS, YOU WON!!!");
                printf("\n\nPRESS ANY KEY TO REPLAY!!!");
                getch();
                main();
            }
            else
                printf("\n\nYOU LOST!");
                printf("\n\nPRESS ANY KEY TO REPLAY!!!");
                getch();
                main();
        }
        if(arr[6]=='x' && arr[7]=='x' && arr[8]=='x'){
            if(character=='x'){
                printf("\n\nCONGRATULATIONS, YOU WON!!!");
                printf("\n\nPRESS ANY KEY TO REPLAY!!!");
                getch();
                main();
            }
            else
                printf("\n\nYOU LOST!");
                printf("\n\nPRESS ANY KEY TO REPLAY!!!");
                getch();
                main();
        }
        if(arr[6]=='o' && arr[7]=='o' && arr[8]=='o'){
            if(character=='o'){
                printf("\n\nCONGRATULATIONS, YOU WON!!!");
                printf("\n\nPRESS ANY KEY TO REPLAY!!!");
                getch();
                main();
            }
            else
                printf("\n\nYOU LOST!");
                printf("\n\nPRESS ANY KEY TO REPLAY!!!");
                getch();
                main();
        }
        if(arr[0]=='x' && arr[3]=='x' && arr[6]=='x') {
            if(character=='x'){
                printf("\n\nCONGRATULATIONS, YOU WON!!!");
                printf("\n\nPRESS ANY KEY TO REPLAY!!!");
                getch();
                main();
            }
            else
                printf("\n\nYOU LOST!");
                printf("\n\nPRESS ANY KEY TO REPLAY!!!");
                getch();
                main();
        }
        if(arr[0]=='o' && arr[3]=='o' && arr[6]=='o'){
            if(character=='o'){
                printf("\n\nCONGRATULATIONS, YOU WON!!!");
                printf("\n\nPRESS ANY KEY TO REPLAY!!!");
                getch();
                main();
            }
            else
                printf("\n\nYOU LOST!");
                printf("\n\nPRESS ANY KEY TO REPLAY!!!");
                getch();
                main();
        }
        if(arr[1]=='x' && arr[4]=='x' && arr[7]=='x'){
            if(character=='x'){
                printf("\n\nCONGRATULATIONS, YOU WON!!!");
                printf("\n\nPRESS ANY KEY TO REPLAY!!!");
                getch();
                main();
            }
            else
                printf("\n\nYOU LOST!");
                printf("\n\nPRESS ANY KEY TO REPLAY!!!");
                getch();
                main();
        }
        if(arr[1]=='o' && arr[4]=='o' && arr[7]=='o'){
            if(character=='o'){
                printf("\n\nCONGRATULATIONS, YOU WON!!!");
                printf("\n\nPRESS ANY KEY TO REPLAY!!!");
                getch();
                main();
            }
            else
                printf("\n\nYOU LOST!");
                printf("\n\nPRESS ANY KEY TO REPLAY!!!");
                getch();
                main();
        }
        if(arr[2]=='x' && arr[5]=='x' && arr[8]=='x') {
            if(character=='x'){
                printf("\n\nCONGRATULATIONS, YOU WON!!!");
                printf("\n\nPRESS ANY KEY TO REPLAY!!!");
                getch();
                main();
            }
            else
                printf("\n\nYOU LOST!");
                printf("\n\nPRESS ANY KEY TO REPLAY!!!");
                getch();
                main();
        }
        if(arr[2]=='o' && arr[5]=='0' && arr[8]=='0'){
            if(character=='o'){
                printf("\n\nCONGRATULATIONS, YOU WON!!!");
                printf("\n\nPRESS ANY KEY TO REPLAY!!!");
                getch();
                main();
            }
            else
                printf("\n\nYOU LOST!");
                printf("\n\nPRESS ANY KEY TO REPLAY!!!");
                getch();
                main();
        }
        if(arr[0]=='x' && arr[4]=='x' && arr[8]=='x') {
            if(character=='x'){
                printf("n\nCONGRATULATIONS, YOU WON!!!");
                printf("\n\nPRESS ANY KEY TO REPLAY!!!");
                getch();
                main();
            }
            else
                printf("\n\nYOU LOST!");
                printf("\n\nPRESS ANY KEY TO REPLAY!!!");
                getch();
                main();
        }
        if(arr[0]=='o' && arr[4]=='o' && arr[8]=='o'){
            if(character=='o'){
                printf("\n\nCONGRATULATIONS, YOU WON!!!");
                printf("\n\nPRESS ANY KEY TO REPLAY!!!");
                getch();
                main();
            }

            else
                printf("\n\nYOU LOST!");
                printf("\n\nPRESS ANY KEY TO REPLAY!!!");
                getch();
                main();
        }
        if(arr[2]=='x' && arr[4]=='x' && arr[6]=='x') {
            if(character=='x'){
                printf("\n\nCONGRATULATIONS, YOU WON!!!");
                printf("\n\nPRESS ANY KEY TO REPLAY!!!");
                getch();
                main();
            }
            else
                printf("\n\nYOU LOST!");
                printf("\n\nPRESS ANY KEY TO REPLAY!!!");
                getch();
                main();
        }
        if(arr[2]=='o' && arr[4]=='o' && arr[6]=='o'){
            if(character=='o'){
                printf("\n\nCONGRATULATIONS, YOU WON!!!");
                printf("\n\nPRESS ANY KEY TO REPLAY!!!");
                getch();
                main();
            }
            else
                printf("\n\nYOU LOST!");
                printf("\n\nPRESS ANY KEY TO REPLAY!!!");
                getch();
                main();
        }
    }
