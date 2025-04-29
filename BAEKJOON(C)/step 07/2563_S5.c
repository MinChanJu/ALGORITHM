#include <stdio.h>

int main(void){
    int board[100][100]={0};
    int N,x,y,cnt=0;
    scanf("%d",&N);
    for (int i=0;i<N;i++){
        scanf("%d %d",&x,&y);
        for (int j=x;j<x+10;j++){
            for (int k=y;k<y+10;k++){
                board[j][k]=1;
            }
        }
    }
    for (int j=0;j<100;j++){
        for (int k=0;k<100;k++){
            if (board[j][k] == 1) cnt++;
        }
    }
    printf("%d",cnt);
    return 0;
}