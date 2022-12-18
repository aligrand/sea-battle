
#include <ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

//printing two 2d arr beside each other by pointers
/*
like this

@0123456789         @0123456789
0~~~~~~~~~~         0~~~~~~~~~~
1~~~~~~~~~~         1~~~~~~~~~~
2~~*~~~~~~~         2~~~~~~~~~~
3~~~*~*~~~~         3~~~~~~~~~~
4~~~~~~~~~~         4~~~~~~~~~~
5~~~~~~~~~~         5~~~~~~~~~~
6~~~~~~~~~~         6~~~~~~~~~~
7~~~~~~~~~~         7~~~~~~~~~~
8~~~~~~~~~~         8~~~~~~~~~~
9~~~~~~~~~~         9~~~~~~~~~~

*/
//updated for maps greater than 10
void printer(char *p1,char *p2,int n){
    system("clear");
    system("figlet sea-battle");
    printf("     ");
    for(int i=0;i<n-2;i++){printf("%d ",i);if(i<10){printf(" ");}}
    printf("                 ");
    for(int i=0;i<n-2;i++){printf("%d ",i);if(i<10){printf(" ");}}
    printf("\n"); 
    for(int i=-1;i<n-2;i++){
        if(i<10){printf(" ");}printf("%d",i);if(i==-1){printf("\b\b");}
        for (int j = 0; j < n; j++)
        {
            printf("%c  ",*p1++);
        }
        printf("         ");
        if(i<10){printf(" ");}printf("%d",i);if(i==-1){printf("\b\b");}
        
        for (int j = 0; j < n; j++)
        {
            printf("%c  ",*p2++);
        }
        printf("\n");
    }
}
//filling two 2d array with filler variable
void fill_board(char *p,int n,char filler){
    for(int i=0;i<n;i++){
        for (int j = 0; j < n; j++)
        {
            //boardp1[i][j]='~';
            //boardp2[i][j]='~';
            if(i*j==0 || i==n-1 || j==n-1){*p = ' '; }
            else{*p = filler;}
            
            *p++;
            
        }
    }
}
// getting boat locations
void get_boats(char *p,int n,int boatsNumber,char *empt,int player){
    int tmpx,tmpy;
    char tmpc;
    char *body; 
    if(player==1){printer(p-n-1,empt,n);}else{printer(empt,p-n-1,n);} //printer //left side board (1) or right side (2)
    
    printf("player%d !! enter %d boat location\nex: 3 4 v or 4 2 h\n",player,boatsNumber);
    
    for(int i=0;i<boatsNumber;i++){
        int sw =0;
        scanf("%d %d %c",&tmpx,&tmpy,&tmpc);

        //chek if the x and y are proper in the board
        if(tmpx<n && 0<=tmpx  && tmpy<n && 0<=tmpy && (tmpc=='v' || tmpc=='h') && ((tmpc=='h' && tmpy<n-1 && 0<tmpy && *(p+((tmpx)*n)+tmpy+1)!='@' && *(p+((tmpx)*n)+tmpy-1)!='@')||(tmpc=='v' && tmpx<n-1 && 0<tmpx && *(p+((tmpx+1)*n)+tmpy)!='@' && *(p+((tmpx-1)*n)+tmpy)!='@'))){
            
            body = (p+(tmpx*(n))+tmpy); // putting body of the boat
            //*body= '@'; // putting body of the boat
            if(tmpc=='h'){for(int k=-1;k<=1;k++){for(int j=-2;j<=2;j++){ if( *(body+(k*(n))+j)=='@'  ){sw=1;}    }}}
            if(tmpc=='v'){for(int k=-2;k<=2;k++){for(int j=-1;j<=1;j++){ if( *(body+(k*(n))+j)=='@'  ){printf("%d %d\n",k,j);sw=1;}    }}}
            if(sw==1){i--;printf("wrong inputttt!! try this one agane\n");continue;}
            if(tmpc=='v'){ *body=*(body+(n))=*(body-(n))= '@'; } //putting the head and tail of the boat vertically
            if(tmpc=='h'){ *body =*(body+1)=*(body-1)= '@'; } //putting the head and tail of the boat horizentally

            if(player==1){printer(p-n-1,empt,n);}else{printer(empt,p-n-1,n);} //printer

        }
        //if x and y are not proper ask for them again
        else{
            i--;
            if(player==1){printer(p-n-1,empt,n);}else{printer(empt,p-n-1,n);}//printer
            printf("wrong input!! try this one agane\n");
            }


    }
    

}
void fight(char *boardp1,char *boardp2,char *boatp1,char *boatp2, char n,int boatsNumber){
    int sw =1,tmpx=0,tmpy=0 , p1point=0,p2point=0,inp; 
    char tmpc;
    printf("\n");
    while(sw==1){
        do{
            printer(boardp1-n-1,boardp2-n-1,n);
            printf("player 1 enter a location -->\nex 7 7 a or 10 4 h ");inp = scanf("%d%d %c",&tmpx,&tmpy,&tmpc);
            //tmpc = *(boatp2+(n*tmpx)+tmpy);
            if(tmpx<n && tmpy<n && 0<=tmpx && 0<=tmpy && inp == 3){
                if(tmpc=='a'){
                    tmpc = *(boatp2+(n*tmpx)+tmpy);
                    if(tmpc == '@'){*(boardp2+(n*tmpx)+tmpy) = '@';p1point++;}else{*(boardp2+(n*tmpx)+tmpy) = '*';}
                    break;
                }
                else if(tmpc=='h'){
                    tmpc = *(boardp1+(n*tmpx)+tmpy);
                    if(tmpc == '@'){*(boardp1+(n*tmpx)+tmpy) = '~';p2point--;}else{*(boardp1+(n*tmpx)+tmpy) = '~';}
                    break;


                }
            }
            //if(tmpc == '@'){*(boardp2+(n*tmpx)+tmpy) = '@';}else{*(boardp2+(n*tmpx)+tmpy) = '*';}
            
        }while(1==1);
        if(p1point >= boatsNumber*3){system("clear"),system("figlet p1_won_!!");break;}
        
        do{
            printer(boardp1-n-1,boardp2-n-1,n);
            printf("player 2 enter a location -->\nex 7 7 a or 10 4 h ");inp = scanf("%d%d %c",&tmpx,&tmpy,&tmpc);
            //tmpc = *(boatp2+(n*tmpx)+tmpy);
            if(tmpx<n && tmpy<n && 0<=tmpx && 0<=tmpy && inp==3){
                if(tmpc=='a'){
                    tmpc = *(boatp1+(n*tmpx)+tmpy);
                    if(tmpc == '@'){*(boardp1+(n*tmpx)+tmpy) = '@';p2point++;}else{*(boardp1+(n*tmpx)+tmpy) = '*';}
                    break;
                }
                else if(tmpc=='h'){
                    tmpc = *(boardp2+(n*tmpx)+tmpy);
                    if(tmpc == '@'){*(boardp2+(n*tmpx)+tmpy) = '~';p1point--;}else{*(boardp2+(n*tmpx)+tmpy) = '~';}
                    break;

                }
            }
            //if(tmpc == '@'){*(boardp2+(n*tmpx)+tmpy) = '@';}else{*(boardp2+(n*tmpx)+tmpy) = '*';}
            
        }while(1==1);
        if(p2point >= boatsNumber*3){system("clear"),system("figlet p2_won_!!");break;}



         //*(boardp2+(n*tmpx)+tmpy) = '*';
        printer(boardp1-n-1,boardp2-n-1,n);
        
        //printf("%c",*(boatp2+(n*tmpx)+tmpy)); 
    }
}



int main(){
    int n,tmpx,tmpy,boatsNumber;
    printf("enter board size:");scanf("%d",&n);
    printf("how many boats do we have? ");scanf("%d",&boatsNumber);
    char boardp1[n+2][n+2];
    char boardp2[n+2][n+2];
    char boatp1[n+2][n+2];
    char boatp2[n+2][n+2];
    char emptboard[n+2][n+2];
    char tmpc;
    
    fill_board(&emptboard[0][0],n+2,'?');
    
    fill_board(&boardp1[0][0],n+2,'~');    
    fill_board(&boardp2[0][0],n+2,'~');

    fill_board(&boatp1[0][0],n+2,'~');
    fill_board(&boatp2[0][0],n+2,'~');

    //printer(&boatp1[0][0],&boatp1[0][0],n+2);

    get_boats(&boatp1[1][1],n+2,boatsNumber,&emptboard[0][0],1);
    

    system("figlet clearing");sleep(2);system("clear");//printf("enter any thing to claer\n");scanf(" %c",&tmpc);system("clear");//pres a key to clear
    get_boats(&boatp2[1][1],n+2,boatsNumber,&emptboard[0][0],2);
    system("figlet clearing");sleep(2);system("clear");//printf("enter any thing to claer\n");scanf(" %c",&tmpc);system("clear");//pres a key to clear
    
    printer(&boatp1[0][0],&boatp2[0][0],n+2);


    fight(&boardp1[1][1],&boardp2[1][1],&boatp1[1][1],&boatp2[1][1],n+2,boatsNumber);

return 0;}