#include<fstream.h>
#include<conio.h>
#include<process.h>

// CLASS FOR TICTACTOE
class ttt
{
    int r,c,ch;
    char p[2][20];
    char play[2];
    char board[3][3];
public:
    void reset()                                        //Function to reset board to blank
    {
	for( int i=0;i<3;i++)
	    for(int j=0;j<3;j++)
		board[i][j]=' ';
	play[0]='X';    play[1]='O';
    }
    void display()                                      //Function to display board
    {
	cout<<"\n\t    1   2   3 "<<endl;
	cout<<"\t  -------------"<<endl;
	cout<<"\t1 | "<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<" |"<<endl;
	cout<<"\t  -------------"<<endl;
	cout<<"\t2 | "<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<" |"<<endl;
	cout<<"\t  -------------"<<endl;
	cout<<"\t3 | "<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<" |"<<endl;
	cout<<"\t  -------------"<<endl;
    }
    int checkvalid()                                    //Function to check if move valid
    {
	int flag = 1;
	for(int i=0;i<=2;i++)
	{

		if(board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[1][1]!=' ')
		{
		    flag = 0;
		}
		else if(board[2][0]==board[1][1] && board[1][1]==board[0][2] && board[1][1]!=' ')
		{
		    flag = 0;
		}
		else if(board[i][0]==board[i][1] && board[i][0]==board[i][2] && board[i][0]!=' ')
		{
		    flag = 0;
		}
		else if(board[0][i]==board[1][i] && board[1][i]==board[2][i] && board[0][i]!=' ')
		{
		    flag = 0;
		}

	}
	return flag;
    }
    int checkfull()                                     //Function to check if board full
    {
	int flag = 1;
	for(int i=0;i<=2;i++)
	{
	    for(int j=0;j<=2;j++)
	    {
		if(board[i][j]==' ')
		{
		    flag = 0;
		}
	    }
	}
	return flag;
    }

    void inputplayer()                                  //Function to input names of two players
{

	clrscr();
	display();
	cout<<"Enter name of player 1: ";
	cin>>p[0];
	cout<<"Enter name of player 2: ";
	cin>>p[1];


}
    int inputmove()                                     //Function to check and input players' moves and modify board accordingly
    {
	reset();
	int i=0;
	a:
	clrscr();
	display();
	do
	{
	    cout<<p[i]<<"'s turn: \n";
	    cin>>r>>c;
	    if(r<1 || r>3 || c<1 || c>3)
	    {
		cout<<"Invalid input!"<<endl;
		getch();
		goto a;
	    }
	    for(int x=1;x<=3;x++)
	    {
		for(int y=1;y<=3;y++)
		{
		    if(r==x && c==y)
		    {
			if(board[x-1][y-1]==' ')
			{
			    board[x-1][y-1]=play[i];
			    i=(i+1)%2;
			}
			else
			{
			    cout<<"Location already occupied!"<<endl;
			    getch();
			    goto a;
			}
		    }
		}
	    }
	    clrscr();
	    display();
	}while(checkfull()==0 && checkvalid()==1);
	return i;
    }
    void game()                                             //Function to play game
    {
	reset();
	inputplayer();
	int gno, score[2];
	score[0]=0; score[1]=0;
	cout<<"How many games do you wanna play?\n";
	cin>>gno;
	for(int j=0;j<gno;j++)
	{
	    int i = inputmove();
	    if(checkvalid() == 1 && checkfull()==1)
	    {
		cout<<"\n\nIts a draw!\n\n\n"<<endl;
	    }
	    else
	    {
		i=(i+1)%2;
		score[i]++;
	    }
	    cout<<"Score: \n"<<p[0]<<": "<<score[0]<<"\n"<<p[1]<<": "<<score[1]<<"\n";
	    getch();
	}
    }


};
//CLASS FOR CONNECT 4
class c4
{
    int a,b;
    char board[5][7];
    char p[2][20], play[2];
    public:
    void reset()
    {
	for(int i=0;i<5;i++)
	    for(int j=0;j<7;j++)
		board[i][j]=' ';
	play[0]='X';    play[1]='O';
    }
    void display()
    {
	cout<<"   1   2   3   4   5   6   7  "<<endl;
	cout<<" _____________________________";
	for(int i=0;i<=4;i++)
	{
	    cout<<endl;
	    for(int j=0;j<7;j++)
	    {
		cout<<" | "<<board[i][j];
	    }
	    cout<<" |";
	}
	cout<<endl<<" _____________________________";
	cout<<endl;
    }
    int checkfull()
    {
	int flag = 1;
	for(int i=0;i<=5;i++)
	{
	    for(int j=0;j<7;j++)
	    {
		if(board[i][j]==' ')
		{
		    flag = 0;
		}
	    }
	}
	return flag;
    }
    int checkwin()                                    //Function to check validity of move
    {
	int i;
	int j;
	int counter;
	for(j = 0; j < 7; j++)                                      //Check vertical
	{
	    counter = 0;
	    for(i = 0; i < 4; i++)
	    {
		if(board[i][j] == board[i+1][j] && board[i][j]!=' ')
		    counter++;

		if(counter == 3)
		    return 1;
	    }
	}
	for(i = 4; i >= 0; i--)                                     //Check horizontal
	{
	    counter = 0;
	    for(j = 0; j < 6; j++)
	    {
		if(board[i][j] == board[i][j+1] && board[i][j]!=' ')
		    counter++;
		if(counter == 3)
		    return 1;
	    }
	}
	for(i=4; i>2; i--)                                          //Check diagonal (/)
	{
	    counter = 0;
	    for(j=0; j<4; j++)
		if(board[i][j] == board[i-1][j+1] && board[i-1][j+1] == board[i-2][j+2] && board[i-2][j+2] == board[i-3][j+3] && board[i][j]!=' ')
		    return 1;
	}
	for(i=4; i>2; i--)                                          //Check diagonal (\)
	{
	    counter = 0;
	    for(j=6; j>2; j--)
		if(board[i][j] == board[i-1][j-1] && board[i-1][j-1] == board[i-2][j-2] && board[i-2][j-2] == board[i-3][j-3] && board[i][j]!=' ')
		    return 1;
	}
	return 0;
    }
    void inputplayer()                                  //Function to input names of two players
    {
	clrscr();
	display();
	cout<<"Enter name of player 1: ";
	cin>>p[0];
	cout<<"Enter name of player 2: ";
	cin>>p[1];
    }
    int inputmove()                                     //Function to check and input players' moves and modify board accordingly
    {
	reset();
	int i=0,c,k;
	a:
	clrscr();
	display();
	do
	{
	    cout<<p[i]<<"'s turn: \n";
	    choice:
	    cout<<endl<<"Enter column number:"<<endl;
	    cin>>c;
	    if(c>7||c<1)
	    {
		cout<<"Wrong choice!"<<endl;
		goto choice;
	    }
	    else
	    {
		for(k=4;board[k][c-1]!=' ';k--);
		if(k>=0)
		{
		    board[k][c-1]=play[i];
		    i=(i+1)%2;
		}
		else
		{
		    cout<<"Column full!"<<endl;
		    goto choice;
		}
	    }
	    clrscr();
	    display();
	}while(checkfull()==0 && checkwin()==0);
	return i;
    }
    void game()
    {
	reset();
	inputplayer();
	int gno, score[2];
	score[0]=0; score[1]=0;
	cout<<"How many games do you wanna play?\n";
	cin>>gno;
	for(int j=0;j<gno;j++)
	{
	    int i = inputmove();
	    if(checkwin() == 0 && checkfull()==1)
	    {
		cout<<"\n\nIts a draw!\n\n\n"<<endl;
	    }
	    else
	    {
		i=(i+1)%2;
		score[i]++;
	    }
	    cout<<"Score: \n"<<p[0]<<": "<<score[0]<<"\n"<<p[1]<<": "<<score[1]<<"\n";
	    getch();
	}

    }
};
void main()
{
    mainmenu:
    clrscr();
    int c;
    cout<<"\n\t<><><><><><><><><><><><><><><><><><><><><>"<<endl;
    cout<<"\t||              GAME ZONE               ||"<<endl;
    cout<<"\t<><><><><><><><><><><><><><><><><><><><><>"<<endl;                                          //Main Menu
    cout<<"\n\n\tSelect the game you want to play : \n\n\t1. TicTacToe \n\t2. Connect 4 \n\t3. Exit"<<endl;
    cin>>c;
    if(c==1)
{    clrscr();
     int ch;
     point:
     cout<<" -------------------"<<endl;
     cout<<" | Tic | Tac | Toe |"<<endl;
     cout<<" -------------------"<<endl;
     cout<<"\n\n1. Play \n2. Instructions \n3. Back to main menu"<<endl;
     select:
     cin>>ch;
     if(ch==1)
      {
	ttt t;
	t.game();
	getch();
	goto mainmenu;
      }
      else if(ch==2)
      {
	clrscr();
	char text[200];
	ifstream fin;
	fin.open("ttt.txt");
	while(!fin.eof())
	{
		fin.getline(text,200);
		cout<<text<<endl;
	}
	fin.close();
	goto select;
      }
      else if(ch==3)
    {
	goto mainmenu;
    }
    else
    {
	cout<<"invalid input";
	clrscr();
	goto point;
    }
}
    else if(c==2)
    {   clrscr();
	int jk;
	show:
	cout<<" --------------------"<<endl;
	cout<<" ||   Connect 4    || "<<endl;
	cout<<" --------------------"<<endl;
	cout<<"\n\n1. Play \n2. Instructions \n3. Back to main menu"<<endl;
	alt:
	cin>>jk;
	if(jk==1)
	{
		c4 c;
		c.game();
		getch();
		goto mainmenu;
	}
	else if(jk==2)
	{
		clrscr();
		char c[200];
		ifstream file;
		file.open("c4.txt");
		while(!file.eof())
	  {
		file.getline(c,200);
		cout<<c<<endl;
	  }
		file.close();
		goto alt;
	}
	 else if(jk==3)
    {
	goto mainmenu;
    }

    else
    {
	cout<<"invalid input";
	clrscr();
	goto alt;
    }
}
    else
    {
	cout<<"Thank you!\n\nGame by: Karma\nVersion: 2.0"<<endl;
	getch();
    }
}