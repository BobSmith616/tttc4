#include<fstream.h>
#include<conio.h>
#include<process.h>

// CLASS FOR TICTACTOE
class ttt
{
    int r,c;
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
            cout<<endl<<"Enter row number and column number: [eg. (1-3) for right-top corner]: "<<endl;
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
    char board[5][10];
    char p[2][20];
public:
    void reset()
    {
        for(int i=0;i<5;i++)
            for(int j=0;j<10;j++)
                board[i][j]=' ';
    }
    void display()
    {
        cout<<"   1   2   3   4   5   6   7   8   9   10 "<<endl;
        cout<<" _________________________________________";
        for(int i=0;i<=4;i++)
        {
            cout<<endl;
            for(int j=0;j<=9;j++)
            {
                cout<<" | "<<board[i][j];
            }
            cout<<" |";
        }
        cout<<endl<<" _________________________________________";
        cout<<endl;
    }
    int checkfull()
    {
        int flag = 1;
        for(int i=0;i<=5;i++)
        {
            for(int j=0;j<=9;j++)
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
    {
        ttt t;
        t.game();
        getch();
        goto mainmenu;
    }
    else if(c==2)
    {
        c4 c;
        c.reset();
        c.display();
        getch();
        goto mainmenu;
    }
    else
    {

    }
}
