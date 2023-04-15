// Melina Rezaeyan 
// Test 01
// Test 02
/*
   Miss Melina Rezaeyan
   Stn 401441228
   and
   Miss Hanie Afshar
   stn 401441021
*/
#include<iostream>
#include<windows.h>
#include<conio.h>

using namespace std;

int table[3][3];
char nameplayer[4];
int CheckForXo ();
inline void ShowXo ();
int PlayXo (int i, int j, int player);
bool Eventuality (int i, int j);
inline int GameControl ();
inline void Cls();
void showsomeone(int Player);
void nameplayering(int play);
inline void delarray();

typedef HANDLE Handle;
typedef CONSOLE_SCREEN_BUFFER_INFO BufferInfo;
typedef WORD Word;

typedef enum
{
	black = 0, blue = 1, green = 2, aqua = 3, red = 4, purrle = 5,yellow = 6, white = 7, gray = 8, 
    l_blue = 9, l_green = 10,l_aqua = 11, l_red = 12,l_purrle = 13, l_yellow = 14,l_white = 15
} ConsoleColors;

short setTextColor(const ConsoleColors foreground)
{
    Handle consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    BufferInfo bufferInfo;
    if(!GetConsoleScreenBufferInfo(consoleHandle, &bufferInfo))
        return 0;
    Word color = (bufferInfo.wAttributes & 0xF0) + (foreground & 0x0F);
    SetConsoleTextAttribute(consoleHandle, color);
    return 1;
}

void gotoxy(int x, int y)
{
    COORD coordinate;
    coordinate.X = x;
    coordinate.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
}

int main () 
{
   	char ch;
 
	int i, j, someone = 1;
	delarray();
	while (!CheckForXo()) 
	{
ad1:    Cls();
       	ShowXo();
        if(GameControl())
        {
	        nameplayering(someone);
	        setTextColor(white);
	       	cout << "\nPlayer ";
	        showsomeone(someone);
	        setTextColor(white);
			cout<<" Entery Row & Col = ";
    	    cin >> i >> j;
			if (i>2 || j>2 || i<0 || j<0) 
			{
			    setTextColor(yellow);
			    cout <<"\nError!!!\nout of range ";
 	            getch();
			    goto ad1; // loop for row>2 or col>2
			} 
			if (Eventuality(i, j))
		       	PlayXo (i, j, someone);
		    else 
 	        {
 	        	setTextColor(yellow);
 	            cout <<"\nError!!!\nMake another move ";
 	            getch();
			    goto ad1;
   			}
            if(someone == 1)
		        someone = 2;
		    else
	            someone = 1;
	    }
	    else
        { 
            setTextColor(yellow);
			cout <<"\nNobody Win!!!" << endl;
			setTextColor(white);
			goto ad3;
		}	    
	}
    Cls();
   	ShowXo();
	nameplayering(CheckForXo());
	setTextColor(white);
	cout <<"\nPlayer ";
	showsomeone(CheckForXo());
	setTextColor(l_green);
	cout<< " is Win !!!!" << endl;
	setTextColor(white);
ad3:cout<< "Play again (y/n)? ";
ad2:gotoxy(18,5);
    ch=getche();	
	if(ch=='y' || ch=='Y')
	{
		delarray();	
		goto ad1;
	}
	else if(ch=='n' || ch=='N')
    {
	    cout<< "\nGood Bay..." << endl;
	    return 0;
    }
	else
		goto ad2;
}

// CheckFoxXo for revision Cell
int CheckForXo ()
{
	for (int i = 0; i < 3; i++) 
	{
		if (table[i][0] != 0 && table[i][0] == table[i][1] && table[i][1] == table[i][2])   // check row
			return table[i][0];
		if ( table[0][i] != 0 && table[0][i] == table[1][i] && table[1][i] == table[2][i])	// check col
			return table[0][i];
	}
	if ( table[0][0] != 0 && table[0][0] == table[1][1] && table[1][1] == table[2][2])      // check diagonal up to down
		return table[0][0];
	if (table[0][2] != 0 && table[0][2] == table [1][1] && table[1][1] == table[2][0])      // check diagonal down to up
		return table[0][2];
	return 0;
}

// Show for display Xo
inline void ShowXo () 
{
	for (int i =0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
           if (table[i][j] == 0)
		   {
			    setTextColor(white);
			  	cout << "|   "<<i<<" "<<j<<"   |" ;
	       }  
		   else if (table[i][j] == 1)
		   {
		       	setTextColor(white);
		    	cout << "|   ";
		    	setTextColor(l_red);
				cout<<"Red";
				setTextColor(white);
		    	cout<<"   |";
	       }   
		   else if (table[i][j] == 2)
		   {
		       	setTextColor(white);
		    	cout << "|   ";
		    	setTextColor(l_blue);
				cout<<"Blue";
				setTextColor(white);
		    	cout<<"  |";
	       }   
		}				
	cout << endl;	
	}
}
// PlayXo for Contrul 
int PlayXo (int i, int j, int player) 
{	
 	table[i][j] = player == 1 ? 1:2;
	return player;
}

// Eventuality Xo
bool Eventuality (int i, int j) 
{
	return (table[i][j] == 0);
}
// Gamecontrol For End -- 1:continue  0:end
inline int GameControl ()
{
	for (int i =0; i < 3; i++) 
	    for (int j = 0; j < 3; j++)
	        if(table[i][j]== 0)
	           return 1;
   	return 0;
}
// Cls for Clear Screen
inline void Cls(){system("cls");}

// show textcolor SomeOne
void showsomeone(int Player)
{
    if(Player==1)
	{
   		setTextColor(l_red);
   		cout<<nameplayer;
    } 
	else if(Player==2)
	{
	    setTextColor(l_blue);	
		cout<<nameplayer;
    }  
}

// Replace nameplayer
void nameplayering(int play)
{
	if (play==1)
	  	strcpy(nameplayer,"Red");
	else if(play==2)  
	  	strcpy(nameplayer,"Blue");
}

// zero by table
inline void delarray()
{ 
   for(int i=0;i<3;i++)
      for(int j=0;j<3;j++)
      	table[i][j]=0;
}
// End Programing
