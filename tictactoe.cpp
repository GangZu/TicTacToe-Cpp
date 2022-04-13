#include<iostream>
#include<cstring>
#include<cstdlib>
#include<time.h>
#include<Windows.h>
#include<conio.h>
using namespace std;
#define max 100
void SET_COLOR(int color)
{
	WORD wColor;
     

     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          wColor = (csbi.wAttributes & 0xF0) + (color & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
}
struct Board{
    int row;
    int col;
    char pos[max][max];
    char xo[max][max];
    int choose;
    int a,b;
    

};
struct Player{
    char name[2][100];
    float countt[2];
    int win;
    int save[max][max];
    int choose;
    
};
void gotoxy(short x, short y)
{
 HANDLE hConsoleOutput;
 COORD Cursor_an_Pos = { x, y };
 hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
 SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
void suggestion4x4( Board &draw){
    for(int i=0;i<draw.row;i++){
        for(int j=0;j<draw.col;j++ ){
            if(draw.pos[i][j]=='X'&&draw.pos[i][j+1]=='X'&&draw.pos[i][j+2]=='X' ){
                if(draw.pos[i][j+3]==' ')
                draw.pos[i][j+3]='!';
                
                if(draw.pos[i][j-1]==' ')
                draw.pos[i][j-1]='!';

            }
            if(draw.pos[i][j]=='X'&&draw.pos[i][j+2]=='X'&&draw.pos[i][j+3]=='X'  ){
                if(draw.pos[i][j+1]==' ')
                draw.pos[i][j+1]='!';

            }
            if(draw.pos[i][j]=='X'&&draw.pos[i][j+1]=='X'&&draw.pos[i][j+3]=='X'  ){
                if(draw.pos[i][j+2]==' ')
                draw.pos[i][j+2]='!';

            }
            if(draw.pos[i][j]=='X'&&draw.pos[i+1][j]=='X'&&draw.pos[i+2][j]=='X'){
                if(draw.pos[i+3][j]==' ')
                draw.pos[i+3][j]='!';
                if(draw.pos[i-1][j]==' ')
                draw.pos[i-1][j]='!';
                
            }
            if(draw.pos[i][j]=='X'&&draw.pos[i+2][j]=='X'&&draw.pos[i+3][j]=='X'){
                if(draw.pos[i+1][j]==' ')
                draw.pos[i+1][j]='!';
            }
             if(draw.pos[i][j]=='X'&&draw.pos[i+1][j]=='X'&&draw.pos[i+3][j]=='X'){
                if(draw.pos[i+2][j]==' ')
                draw.pos[i+2][j]='!';
            }
            if(draw.pos[i][j]=='X'&&draw.pos[i+1][j+1]=='X'&&draw.pos[i+2][j+2]=='X'){
                if(draw.pos[i+3][j+3]==' ')
                draw.pos[i+3][j+3]='!';
                if(draw.pos[i-1][j-1]==' ')
                draw.pos[i-1][j-1]='!';
                
            }
            if(draw.pos[i][j]=='X'&&draw.pos[i+2][j+2]=='X'&&draw.pos[i+3][j+3]=='X'){
                if(draw.pos[i+1][j+1]==' ')
                draw.pos[i+1][j+1]='!';                             
            }
            if(draw.pos[i][j]=='X'&&draw.pos[i+1][j+1]=='X'&&draw.pos[i+3][j+3]=='X'){
                if(draw.pos[i+2][j+2]==' ')
                draw.pos[i+2][j+2]='!';                             
            }
            if(draw.pos[draw.row-i][j]=='X'&&draw.pos[draw.row-i-1][j+1]=='X'&&draw.pos[draw.row-i-2][j+2]=='X'){
                if(draw.pos[draw.row-i-3][j+3]==' ')
                draw.pos[draw.row-i-3][j+3]='!';
                if(draw.pos[draw.row-i+1][j-1]==' ')
                draw.pos[draw.row-i+1][j-1]='!';
                
            }
            if(draw.pos[draw.row-i][j]=='X'&&draw.pos[draw.row-i-2][j+2]=='X'&&draw.pos[draw.row-i-3][j+3]=='X'){
                if(draw.pos[draw.row-i-1][j+1]==' ')
                draw.pos[draw.row-i-1][j+1]='!';     
            }
            if(draw.pos[draw.row-i][j]=='X'&&draw.pos[draw.row-i-1][j+1]=='X'&&draw.pos[draw.row-i-3][j+3]=='X'){
                if(draw.pos[draw.row-i-2][j+2]==' ')
                draw.pos[draw.row-i-2][j+2]='!';     
            }
            
            
           if(draw.pos[i][j]=='O'&&draw.pos[i][j+1]=='O'&&draw.pos[i][j+2]=='O' ){
                if(draw.pos[i][j+3]==' ')
                draw.pos[i][j+3]='!';
                
                if(draw.pos[i][j-1]==' ')
                draw.pos[i][j-1]='!';

            }
            if(draw.pos[i][j]=='O'&&draw.pos[i][j+2]=='O'&&draw.pos[i][j+3]=='O'  ){
                if(draw.pos[i][j+1]==' ')
                draw.pos[i][j+1]='!';

            }
            if(draw.pos[i][j]=='O'&&draw.pos[i][j+1]=='O'&&draw.pos[i][j+3]=='O'){
                if(draw.pos[i][j+2]==' ')
                draw.pos[i][j+2]='!';

            }
            if(draw.pos[i][j]=='O'&&draw.pos[i+1][j]=='O'&&draw.pos[i+2][j]=='O'){
                if(draw.pos[i+3][j]==' ')
                draw.pos[i+3][j]='!';
                if(draw.pos[i-1][j]==' ')
                draw.pos[i-1][j]='!';
                
            }
            if(draw.pos[i][j]=='O'&&draw.pos[i+2][j]=='O'&&draw.pos[i+3][j]=='O'){
                if(draw.pos[i+1][j]==' ')
                draw.pos[i+1][j]='!';
            }
             if(draw.pos[i][j]=='O'&&draw.pos[i+1][j]=='O'&&draw.pos[i+3][j]=='O'){
                if(draw.pos[i+2][j]==' ')
                draw.pos[i+2][j]='!';
            }
            if(draw.pos[i][j]=='O'&&draw.pos[i+1][j+1]=='O'&&draw.pos[i+2][j+2]=='O'){
                if(draw.pos[i+3][j+3]==' ')
                draw.pos[i+3][j+3]='!';
                if(draw.pos[i-1][j-1]==' ')
                draw.pos[i-1][j-1]='!';
                
            }
            if(draw.pos[i][j]=='O'&&draw.pos[i+2][j+2]=='O'&&draw.pos[i+3][j+3]=='O'){
                if(draw.pos[i+1][j+1]==' ')
                draw.pos[i+1][j+1]='!';                             
            }
            if(draw.pos[i][j]=='O'&&draw.pos[i+1][j+1]=='O'&&draw.pos[i+3][j+3]=='O'){
                if(draw.pos[i+2][j+2]==' ')
                draw.pos[i+2][j+2]='!';                             
            }
            if(draw.pos[draw.row-i][j]=='O'&&draw.pos[draw.row-i-1][j+1]=='O'&&draw.pos[draw.row-i-2][j+2]=='O'){
                if(draw.pos[draw.row-i-3][j+3]==' ')
                draw.pos[draw.row-i-3][j+3]='!';
                if(draw.pos[draw.row-i+1][j-1]==' ')
                draw.pos[draw.row-i+1][j-1]='!';
                
            }
            if(draw.pos[draw.row-i][j]=='O'&&draw.pos[draw.row-i-2][j+2]=='O'&&draw.pos[draw.row-i-3][j+3]=='O'){
                if(draw.pos[draw.row-i-1][j+1]==' ')
                draw.pos[draw.row-i-1][j+1]='!';     
            }
            if(draw.pos[draw.row-i][j]=='O'&&draw.pos[draw.row-i-1][j+1]=='O'&&draw.pos[draw.row-i-3][j+3]=='O'){
                if(draw.pos[draw.row-i-2][j+2]==' ')
                draw.pos[draw.row-i-2][j+2]='!';     
            }

        }
    

     }
}
void suggestion3x3( Board &draw){
    for(int i=0;i<draw.row;i++){
            for(int j=0;j<draw.col;j++ ){
            if(draw.pos[i][j]=='X'&&draw.pos[i][j+1]=='X' ){
                if(draw.pos[i][j+2]==' ')
                draw.pos[i][j+2]='!';
                
                if(draw.pos[i][j-1]==' ')
                draw.pos[i][j-1]='!';

            }
            if(draw.pos[i][j]=='X'&&draw.pos[i][j+2]=='X' ){
                if(draw.pos[i][j+1]==' ')
                draw.pos[i][j+1]='!';

            }
            if(draw.pos[i][j]=='X'&&draw.pos[i+1][j]=='X'){
                if(draw.pos[i+2][j]==' ')
                draw.pos[i+2][j]='!';
                if(draw.pos[i-1][j]==' ')
                draw.pos[i-1][j]='!';
                
            }
            if(draw.pos[i][j]=='X'&&draw.pos[i+2][j]=='X'){
                if(draw.pos[i+1][j]==' ')
                draw.pos[i+1][j]='!';
            }
            if(draw.pos[i][j]=='X'&&draw.pos[i+1][j+1]=='X'){
                if(draw.pos[i+2][j+2]==' ')
                draw.pos[i+2][j+2]='!';
                if(draw.pos[i-1][j-1]==' ')
                draw.pos[i-1][j-1]='!';
                
            }
            if(draw.pos[i][j]=='X'&&draw.pos[i+2][j+2]=='X'){
                if(draw.pos[i+1][j+1]==' ')
                draw.pos[i+1][j+1]='!';                             
            }
            if(draw.pos[draw.row-i][j]=='X'&&draw.pos[draw.row-i-1][j+1]=='X'){
                if(draw.pos[draw.row-i-2][j+2]==' ')
                draw.pos[draw.row-i-2][j+2]='!';
                if(draw.pos[draw.row-i+1][j-1]==' ')
                draw.pos[draw.row-i+1][j-1]='!';
                
            }
            if(draw.pos[draw.row-i][j]=='X'&&draw.pos[draw.row-i-2][j+2]=='X'){
                if(draw.pos[draw.row-i-1][j+1]==' ')
                draw.pos[draw.row-i-1][j+1]='!';     
            }
            
            
            if(draw.pos[i][j]=='O'&&draw.pos[i][j+1]=='O' ){
                if(draw.pos[i][j+2]==' ')
                draw.pos[i][j+2]='!';
                
                if(draw.pos[i][j-1]==' ')
                draw.pos[i][j-1]='!';
            }
            if(draw.pos[i][j]=='O'&&draw.pos[i][j+2]=='O' ){
                if(draw.pos[i][j+1]==' ')
                draw.pos[i][j+1]='!';

            }
            if(draw.pos[i][j]=='O'&&draw.pos[i+1][j]=='O'){
                    if(draw.pos[i+2][j]==' ')
                draw.pos[i+2][j]='!';
                if(draw.pos[i-1][j]==' ')
                draw.pos[i-1][j]='!';
            }
             if(draw.pos[i][j]=='O'&&draw.pos[i+2][j]=='O'){
                if(draw.pos[i+1][j]==' ')
                draw.pos[i+1][j]='!';
            }
            if(draw.pos[i][j]=='O'&&draw.pos[i+1][j+1]=='O'){
              if(draw.pos[i+2][j+2]==' ')
                draw.pos[i+2][j+2]='!';
                if(draw.pos[i-1][j-1]==' ')
                draw.pos[i-1][j-1]='!';
            }
                if(draw.pos[i][j]=='O'&&draw.pos[i+2][j+2]=='O'){
                if(draw.pos[i+1][j+1]==' ')
                draw.pos[i+1][j+1]='!';                             
            }
            if(draw.pos[draw.row-i][j]=='O'&&draw.pos[draw.row-i-1][j+1]=='O'){
                 if(draw.pos[draw.row-i-2][j+2]==' ')
                draw.pos[draw.row-i-2][j+2]='!';
                if(draw.pos[draw.row-i+1][j-1]==' ')
                draw.pos[draw.row-i+1][j-1]='!';
                
            }
             if(draw.pos[draw.row-i][j]=='O'&&draw.pos[draw.row-i-2][j+2]=='O'){
                if(draw.pos[draw.row-i-1][j+1]==' ')
                draw.pos[draw.row-i-1][j+1]='!';     
            }
            

     }
    

            }
}
void checkDraw( Board draw,Player &player){
    int count=0;
        for(int i=0;i<draw.row;i++){
            for(int j=0;j<draw.col;j++ ){
                if(draw.pos[i][j]==' '||draw.pos[i][j]=='!'){
                    count++;
                }
            }
        }
        if(count==0)
        player.win = 2;
}
void checkwin3x3( Board draw,Player &player){
        for(int i=0;i<draw.row;i++){
            for(int j=0;j<draw.col;j++ ){
            if(draw.pos[i][j]=='X'&&draw.pos[i][j+1]=='X' &&  draw.pos[i][j+2]=='X'){
             player.win = 1;
             return;
            }
            if(draw.pos[i][j]=='X'&&draw.pos[i+1][j]=='X'&&draw.pos[i+2][j]=='X'){
             player.win = 1;
             return;
            }
            if(draw.pos[i][j]=='X'&&draw.pos[i+1][j+1]=='X'&&draw.pos[i+2][j+2]=='X'){
             player.win = 1;
             return;
            }
            if(draw.pos[draw.row-i][j]=='X'&&draw.pos[draw.row-i-1][j+1]=='X'&&draw.pos[draw.row-i-2][j+2]=='X'){
                player.win =1;
                return;
            }
            if(draw.pos[i][j]=='O'&&draw.pos[i][j+1]=='O' &&  draw.pos[i][j+2]=='O'){
             player.win = 1;
             return;
            }
            if(draw.pos[i][j]=='O'&&draw.pos[i+1][j]=='O'&&draw.pos[i+2][j]=='O'){
             player.win = 1;
             return;
            }
            if(draw.pos[i][j]=='O'&&draw.pos[i+1][j+1]=='O'&&draw.pos[i+2][j+2]=='O'){
             player.win = 1;
             return;
            }
            if(draw.pos[draw.row-i][j]=='O'&&draw.pos[draw.row-i-1][j+1]=='O'&&draw.pos[draw.row-i-2][j+2]=='O'){
                player.win =1;
                return;
            }

             }
        }
 }
void checkwin4x4( Board draw,Player &player){
        for(int i=0;i<draw.row;i++){
            for(int j=0;j<draw.col;j++ ){
            if(draw.pos[i][j]=='X'&&draw.pos[i][j+1]=='X' &&  draw.pos[i][j+2]=='X'&&draw.pos[i][j+3]=='X'){
             player.win = 1;
             return;
            }
            if(draw.pos[i][j]=='X'&&draw.pos[i+1][j]=='X'&&draw.pos[i+2][j]=='X'&&draw.pos[i+3][j]=='X'){
             player.win = 1;
             return;
            }
            if(draw.pos[i][j]=='X'&&draw.pos[i+1][j+1]=='X'&&draw.pos[i+2][j+2]=='X'&&draw.pos[i+3][j+3]=='X'){
             player.win = 1;
             return;
            }
            if(draw.pos[draw.row-i][j]=='X'&&draw.pos[draw.row-i-1][j+1]=='X'&&draw.pos[draw.row-i-2][j+2]=='X'&&draw.pos[draw.row-i-3][j+3]=='X'){
                player.win =1;
                return;
            }
            if(draw.pos[i][j]=='O'&&draw.pos[i][j+1]=='O' &&  draw.pos[i][j+2]=='O'&&  draw.pos[i][j+3]=='O'){
             player.win = 1;
             return;
            }
            if(draw.pos[i][j]=='O'&&draw.pos[i+1][j]=='O'&&draw.pos[i+2][j]=='O'&&draw.pos[i+3][j]=='O'){
             player.win = 1;
             return;
            }
            if(draw.pos[i][j]=='O'&&draw.pos[i+1][j+1]=='O'&&draw.pos[i+2][j+2]=='O'&&draw.pos[i+3][j+3]=='O'){
             player.win = 1;
             return;
            }
            if(draw.pos[draw.row-i][j]=='O'&&draw.pos[draw.row-i-1][j+1]=='O'&&draw.pos[draw.row-i-2][j+2]=='O'&&draw.pos[draw.row-i-3][j+3]=='O'){
                player.win =1;
                return;
            }

             }
        }
 }
void printBoard(Board draw){
    cout<<"   ";
    for(int i=0;i<draw.col;i++){

        cout<<"    "<<i<<"   ";
    }cout<<endl;
    cout<<"   ";
    
    for(int i=0;i<draw.col;i++){

        cout<<" -------";
    }cout<<endl;
    
    for(int i=0;i<draw.row;i++){
    

    cout<<"   ";
        cout<<"|";

    for(int j =0;j<draw.col;j++){
            cout<<"       |";

        }cout<<endl;
    cout<<" "<<i<<" ";

        cout<<"|";

        
    for(int j =0;j<draw.col;j++){
            
            if(i==draw.a&&j==draw.b){
             SET_COLOR(4);   
            cout<<"   "<<draw.pos[i][j]<<"   ";
            SET_COLOR(2);
            cout<<"|";
            }
            else
            cout<<"   "<<draw.pos[i][j]<<"   |";


        }cout<<endl;
    cout<<"   ";

        cout<<"|";

    for(int j =0;j<draw.col;j++){
            cout<<"       |";

        }cout<<endl;
    cout<<"   ";

    for(int i=0;i<draw.col;i++){

        cout<<" -------";
    }cout<<endl;
}
}
void playgame(Player &player, Board &draw){
    int crow,ccol;
    int a=10;
      player.win =0;
 int *temp1=new int[draw.col*draw.row];
 int *temp2=new int[draw.col*draw.row];
int m=0;
int n=0;
int z=0;
int limit =0;
      
    while(player.win==0){
        for(int k=0;k<2;k++){
           checkDraw( draw,player);

            if(player.win == 2){
                cout<<"DRAW!!\n";
            break;
            }
       cout<<player.name[k]<<" turn \n";
      
      
       char c;
        int mx=8,my=3;
        clock_t ok;

      int temp=clock();
             while(c!=13){
                TEST: gotoxy(mx,my);
        cout<<"<";
        char c = getch();
        if(c==13){
            limit =0;
             break;
        }
        if(c=='z'){
                 limit ++;
                    z=1;
                    goto pick;
                 break;
             }
        if(c == -32){
            c = getch();
            if(c == 72){
                my = my-4;
                
            }
            if(c == 80){
                my = my+4;
                
            }
            if(c == 75){
                mx=mx-8;
                
            }
            if(c == 77){
                mx= mx+8;
                
            }
            if(c == 13)
             break;
             
        }
        if(mx>8+8*(draw.col-1))
        mx=8;
        if(my>3+4*(draw.row-1))
        my=4;

        if(mx<8)
        mx=8+8*(draw.col-1);
        if(my<3)
        my=3+4*(draw.row-1);
        system("cls");
            //setBoard(   draw);

            printBoard( draw);

        cout<<player.name[k]<<" turn ";
        if(limit >2){
                gotoxy(80,20);
                cout<<"can't undo!! (1 for turn)";
                goto TEST;
            }
        gotoxy(80,0);
                 
                 ok=clock()-temp;
             
                    cout<<"Time: "<< 10-ok/1000<<endl; 
                    if(10-ok/1000<0){
                     a=0;
                    goto OKE;

                    }
    }
     

    pick:    for(int i=0;i<draw.row;i++){
        for(int j=0;j<draw.col;j++){
            if(limit >2){
                goto TEST;}
            if(z==1&&limit ==1){
                   draw.pos[temp1[m-1]][temp2[n-1]]=' ';
                    system("cls");
            //setBoard(   draw);
            if(k==1)
            k--;
            else 
            k++;
            limit ++;
            printBoard( draw);
            z=0;
            
                   goto TEST ;
                }
           if(i == (my-3)/4&&j==(mx-8)/8){
               if(draw.pos[i][j]=='X'|| draw.pos[i][j]=='O'){
           
                cout<<"Invalid choice!!";
                goto TEST;
                }
        if(draw.pos[i][j]==' '||draw.pos[i][j]=='!'){
            if(player.choose ==2){
           if(k==0){
         draw.pos[i][j]='O';
         temp1[m++]=i;
         temp2[n++]=j;
         draw.a=i;
         draw.b=j;
           }
         else {
         draw.pos[i][j]='X';
         temp1[m++]=i;
         temp2[n++]=j;
         draw.a=i;
         draw.b=j;
           }  
            }
            else{
            if(k==0){
         draw.pos[i][j]='X';
         temp1[m++]=i;
         temp2[n++]=j;
         draw.a=i;
         draw.b=j;
           }
         else{ 
         draw.pos[i][j]='O';
         temp1[m++]=i;
         temp2[n++]=j;
         draw.a=i;
         draw.b=j;
           } 

            }
        }
           }
        }
    }
      OKE:  if(a==0){
          a=10;
             do{
            crow=rand()%draw.row;
            ccol=rand()%draw.col;
        
        
        
        }
        while(draw.pos[crow][ccol]=='X'||draw.pos[crow][ccol]=='O');
        if(player.choose ==2){
           if(k==0)
         draw.pos[crow][ccol]='O';
         else 
         draw.pos[crow][ccol]='X';  
            }
            else{
            if(k==0)
         draw.pos[crow][ccol]='X';
         else 
         draw.pos[crow][ccol]='O'; 

            }
      }
      

    
    system("cls");

            
            //setBoard(   draw);
            if(draw.col*draw.row<=16)
            suggestion3x3( draw);
            else
            suggestion4x4(draw);
        
        

            printBoard( draw);
            if(draw.col*draw.row<=16)
            checkwin3x3(draw,player);
            else
            checkwin4x4(draw,player);
     
         if (player.win==1){
             cout<<player.name[k]<<" is the winner!!";
             player.countt[k]++;
             break;
         }
            }
     
        }
        
}
void playgameE(Player &player,Board &draw){
    int crow,ccol;
     player.win =0;
     int i=0;
                int z=0;
int *temp1=new int[draw.col*draw.row];
int *temp2=new int[draw.col*draw.row];
int *temp3=new int[draw.col*draw.row];
int *temp4=new int[draw.col*draw.row];
int m=0;
int n=0;
int o,p;
o = p= 0;
    while(player.win==0){
        // nguoi

        checkDraw( draw,player);

            if(player.win == 2){
                cout<<"DRAW!!\n";
            break;
            }
        cout<<player.name[0]<<" turn \n";
        char c;
        int mx=8,my=3;
                 
                
                  clock_t ok;
                 ok=clock();
                    int temp=ok;
             while(c!=13){
        TEST: gotoxy(mx,my);
        cout<<"<";
        char c = getch();
        if(c==13) break;
        if(c=='z'){
                 
                    z=1;
                    goto pick;
                 break;
             }
        if(c == -32){
            c = getch();
            if(c == 72){
                my = my-4;
                
            }
            if(c == 80){
                my = my+4;
                
            }
            if(c == 75){
                mx=mx-8;
                
            }
            if(c == 77){
                mx= mx+8;
                
            }
            if(c == 13)
             break;
             
             
        }
        if(mx>8+8*(draw.col-1))
        mx=8;
        if(my>3+4*(draw.row-1))
        my=4;

        if(mx<8)
        mx=8+8*(draw.col-1);
        if(my<3)
        my=3+4*(draw.row-1);
        system("cls");
            //setBoard(   draw);
                 
            printBoard( draw);
        cout<<player.name[0]<<" turn ";
                 gotoxy(80,0);
                 
                 ok=clock()-temp;
                 
                    cout<<"Time: "<< 10-ok/1000<<endl; 
                    if(10-ok/1000<0)
                    goto COMPUTER;



    }

      pick:   for(int i=0;i<draw.row;i++){
        for(int j=0;j<draw.col;j++){
            if(z==1){
                   draw.pos[temp1[--m]][temp2[--n]]=' ';
                    
            
                   goto COMPUTER ;
                }
           if(i == (my-3)/4&&j==(mx-8)/8){
               
               if(draw.pos[i][j]=='X'|| draw.pos[i][j]=='O'){
           
                cout<<"Invalid choice!!";
                goto TEST;
                }
                
                if(draw.pos[i][j]==' '||draw.pos[i][j]=='!'){
                 draw.pos[i][j]='X';
                    temp1[m++]=i;
                    temp2[n++]=j;
                    draw.a=i;
                    draw.b=j;
                    
                }
           }
        }
    }
     
            system("cls");
           
            //setBoard(   draw);
            if(draw.col*draw.row<=16)
            suggestion3x3( draw);
            else
            suggestion4x4(draw);
            
            printBoard( draw);
            if(draw.col*draw.row<=16)
            checkwin3x3(draw,player);
            else 
            checkwin4x4(draw,player);
         if (player.win==1){
             cout<<player.name[0]<<" is the winner!!";
             player.countt[i]++;

             break;
            }
            i++;

            if(player.win ==1) break;

            // may


            checkDraw( draw,player);

            if(player.win == 2){
                cout<<"DRAW!!\n";
            break;
            }
     COMPUTER:
     if(z==1){
         draw.pos[temp3[--o]][temp4[--p]]=' ';
         z=0;
         for(int i=0;i<draw.row;i++){
        for(int j=0;j<draw.col;j++){
            if(draw.pos[i][j]=='!')
            draw.pos[i][j]=' ';
        }
         }
             system("cls");
            //setBoard(   draw);
                 
            printBoard( draw);

         goto TEST;
     }
       cout<<"Computer turn \n";
     
        
        do{
            crow=rand()%draw.row;
            ccol=rand()%draw.col;
        
        
        
        }
        while(draw.pos[crow][ccol]=='X'||draw.pos[crow][ccol]=='O');
         
         draw.pos[crow][ccol]='O'; 
         temp3[o++]=crow;
         temp4[p++]=ccol;
         draw.a =crow;
         draw.b=ccol;

         
       
    

            system("cls");
            
            //setBoard(   draw);
            if(draw.col*draw.row<=16)
            suggestion3x3( draw);
            else    
            suggestion4x4(draw);
            
            printBoard( draw);
            if(draw.col*draw.row<=16)
            checkwin3x3(draw,player);
            else 
            checkwin4x4(draw,player);
         if (player.win==1){
             cout<<"Computer win!!";
             player.countt[i]++;
             break;
            }
             i--;

            if(player.win ==1) break;
        }
    }
int main(){
    system("cls");
    Board draw;
    Player player;
    
    int mode,color;
   
    
    cout<<"SELECT MODE:\n(1) PvP\n(2) PvE\n";
    do{
    cout<<"Select: ";
    cin>>mode;
    if(mode>2)
    cout<<"Invalid choice!\n";
    }
    while(mode >2);
    cout<<"RULE: IF YOUR BOARD LARGER THAN 4X4\nPlayers alternate placing Xs and Os on the game board until either oppent has 4 in a row or all squares are filled\nSmallest board is 3x3!!\n";
    do{
    cout<<"enter row: ";cin>>draw.row;
    cout<<"enter col: ";cin>>draw.col;
    if(draw.row<3||draw.col<3)
    cout<<"Invalid choice!\n";
    }
    while(draw.row<3||draw.col<3);
    int countt=0;
    int ok=1;
    for(int i =0;i<2;i++)
    player.countt[i]=0.0;

    if(mode==1){
    for(int i=0;i<2;i++){
        cout<<"enter name of player : ";cin>>player.name[i];
    }
    
    cout<<"(1) "<<player.name[0]<<" :X and "<<player.name[1]<<"  :O \n(2) "<<player.name[0]<<" :0 and "<<player.name[1]<<"  :X \n";
    cout<<"Which symbol do you like: ";
    do{
    cin>>player.choose;
    if(player.choose != 1 && player.choose != 2){
        cout<<"Invalid choice, please choose again!\n";
           cout<<"choose: "; 
    }
    }
    while(player.choose != 1 && player.choose != 2);
    system("cls");
    
           
    srand(time(NULL));
    while(ok ==1){
    for(int i=0;i<draw.row;i++){
        for(int j=0;j<draw.col;j++){
            draw.pos[i][j]=' ';
        }
    }
    cout<<"Custom color background: \n1. Black \n2. Gray  \n3. Blue \n4. Red \n5. Yellow \n";
    do{
    cin>>color;
    if(color ==1)
    system("color 02");
    else if (color ==2)
    system("color 82");
    else if (color ==3)
    system("color 12");
    else if (color ==4)
    system("color 42");
    else if (color ==5)
    system("color 62");
    else 
    cout<<"Invalid choice, please choose again!";
    
    }
    while(color>5||color<1);
    system("cls");
    cout<<"3\n";
    Sleep(1000);
    cout<<"2\n";
    Sleep(1000);
    cout<<"1\n";
    Sleep(1000);
    cout<<"LETS PLAY!!\n";
    Sleep(1000);
    system("cls");

    
    printBoard( draw);
    playgame( player ,draw);
    countt++;

    cout<<" Do you want to play again?\nPress 1 to play again and any key to quit";
    cin>>ok;
    system("cls");

    }
    cout<<"Total number of games are "<<countt<<endl;
    for(int i =0;i<2;i++)
    cout<<player.name[i]<<" win "<<player.countt[i]<<" round\t Pecentage win is "<< player.countt[i]*100.0/countt<<" %"<<endl;
    }
    else{
        cout<<"Enter your name: ";
        cin>>player.name[0];
        cout<<player.name[0]<<" is X and computer is O\n";
        srand(time(NULL));
        Sleep(2000);
       system("cls");
       

        while(ok ==1){
        for(int i=0;i<draw.row;i++){
            for(int j=0;j<draw.col;j++){
                draw.pos[i][j]=' ';
            }
        }
        cout<<"Custom color background: \n1. Black \n2. Gray  \n3. Blue \n4. Red \n5. Yellow \n";
    do{
    cin>>color;
    if(color ==1)
    system("color 02");
    else if (color ==2)
    system("color 82");
    else if (color ==3)
    system("color 12");
    else if (color ==4)
    system("color 42");
    else if (color ==5)
    system("color 62");
    else 
    cout<<"Invalid choice, please choose again!";
    
    }
    while(color>5||color<1);
           system("cls");
       cout<<"3\n";
       Sleep(700);
       cout<<"2\n";
       Sleep(700);
       cout<<"1\n";
       Sleep(700);
       cout<<"LETS PLAY!!\n";
       Sleep(1000);
       system("cls");

      printBoard( draw);
          
       playgameE( player ,draw);
         
      countt++;

       cout<<" Do you want to play again?\nPress 1 to play again and any key to quit";
       cin>>ok;
       system("cls");

      }
      

        cout<<"Total number of games: "<<countt<<endl;

      
        cout<<player.name[0]<<" win "<<player.countt[0]<<" round\nPercentage "<<player.name[0]<<" win is "<< player.countt[0]*100.0/countt<<" %"<<endl;
        cout<<"Computer win "<<player.countt[1]<<" round\nPecentage computer win is "<<player.countt[1]*100.0/countt<<" %"<<endl;

    }
    system("pause");
}
