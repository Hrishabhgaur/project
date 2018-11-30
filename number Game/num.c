#include<stdio.h>
#define ESC 0
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
int c[16]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
void makematrix(int A[][4]);
void showmm(int A[][4]);
int gamer(int A[][4]);
int shiftRight(int A[][4]);
int shiftLeft(int A[][4]);
int shiftUp(int A[][4]);
int shiftDown(int A[][4]);
int readkey();
void main(){
    int A[4][4],move=500;
makematrix(A);
if(gamer(A)){
    printf("YOU WON");
}

while(move>0){
       printf("remaming chance = %d",move);
showmm(A);
switch(readkey()){
case ESC:
    exit(0);
      case UP:
            if(!shiftUp(A))
                move++;
            break;
        case DOWN:
            if(!shiftDown(A))
                move++;
            break;
        case LEFT:
            if(!shiftLeft(A))
                move++;
            break;
        case RIGHT:
            if(!shiftRight(A))
                move++;
            break;
        default:
            move++;
}
move--;
system("cls");
}
}
int gamer(int A[][4]){
int i,j,k=0;
     for(i=0;i<=3;i++){
        for(j=0;j<=3;j++){
                k<15?k++:(k=0);
            if(A[i][j]!=k)
                return(0);
        }
     }
     return(1);

}
int readkey(){
int ch;
ch=getch();
if(ch==224){
  ch=getch();
  switch(ch){
  case 27:
        return(ESC);
    case 72:
        return(UP);
    case 80:
        return(DOWN);
    case 75:
        return(LEFT);
    case 77:
        return(RIGHT);
    default:
        return(5);

  }
}


}
int shiftLeft(int A[][4]){
  int i,j,temp,zeroFound=0;

    for(i=0;i<=3;i++){
        for(j=0;j<=3;j++){
            if(A[i][j]==0){
                zeroFound=1;
                break;
            }
        }
        if(zeroFound)
            break;
    }
    if(j==3)
        return(0);//shifting not possible
    else{
        temp=A[i][j];
        A[i][j]=A[i][j+1];
        A[i][j+1]=temp;
        return(1);
    }

}

int shiftRight(int A[][4]){
  int i,j,temp,zeroFound=0;

    for(i=0;i<=3;i++){
        for(j=0;j<=3;j++){
            if(A[i][j]==0){
                zeroFound=1;
                break;
            }
        }
        if(zeroFound)
            break;
    }
    if(j==0)
        return(0);//shifting not possible
    else{
        temp=A[i][j];
        A[i][j]=A[i][j-1];
        A[i][j-1]=temp;
        return(1);
    }

}
int shiftUp(int A[][4]){
  int i,j,temp,zeroFound=0;

    for(i=0;i<=3;i++){
        for(j=0;j<=3;j++){
            if(A[i][j]==0){
                zeroFound=1;
                break;
            }
        }
        if(zeroFound)
            break;
    }
    if(i==3)
        return(0);//shifting not possible
    else{
        temp=A[i][j];
        A[i][j]=A[i+1][j];
        A[i+1][j]=temp;
        return(1);
    }

}
int shiftDown(int A[][4]){
  int i,j,temp,zeroFound=0;

    for(i=0;i<=3;i++){
        for(j=0;j<=3;j++){
            if(A[i][j]==0){
                zeroFound=1;
                break;
            }
        }
        if(zeroFound)
            break;
    }
    if(i==0)
        return(0);//shifting not possible
    else{
        temp=A[i][j];
        A[i][j]=A[i-1][j];
        A[i-1][j]=temp;
        return(1);
    }

}

void makematrix(int A[][4]){
    int f=14,d,i,j;
    srand(time(NULL));
for( i=0;i<4;i++){
    for( j=0;j<4;j++){
            if(f>=0){
            d=rand()%(f+1);
        A[i][j]=c[d];
        c[d]=c[f];
    f--;
    }
    else{
        A[i][j]=0;
    }
    }

}
}
void showmm(int A[][4]){
 int i,j;
 printf("\n-------------------------\n|");
 for(i=0;i<=3;i++){
    for(j=0;j<=3;j++){
        if(A[i][j]!=0)
            printf(" %-2d | ",A[i][j]);
        else
            printf("    | ");
    }
    printf("\n-------------------------\n");
    if(i!=3)
        printf("|");

 }

}
