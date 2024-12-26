#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void){
    char N[30];
    int B,a,j=0,val=0;
    scanf("%s",&N);
    scanf("%d",&B);
    a = strlen(N);
    for (int i = a-1; i>=0;i--){
        if (N[i] == '1') val += pow(B,j);
        else if (N[i] == '2') val += 2*pow(B,j);
        else if (N[i] == '3') val += 3*pow(B,j);
        else if (N[i] == '4') val += 4*pow(B,j);
        else if (N[i] == '5') val += 5*pow(B,j);
        else if (N[i] == '6') val += 6*pow(B,j);
        else if (N[i] == '7') val += 7*pow(B,j);
        else if (N[i] == '8') val += 8*pow(B,j);
        else if (N[i] == '9') val += 9*pow(B,j);
        else if (N[i] == 'A') val += 10*pow(B,j);
        else if (N[i] == 'B') val += 11*pow(B,j);
        else if (N[i] == 'C') val += 12*pow(B,j);
        else if (N[i] == 'D') val += 13*pow(B,j);
        else if (N[i] == 'E') val += 14*pow(B,j);
        else if (N[i] == 'F') val += 15*pow(B,j);
        else if (N[i] == 'G') val += 16*pow(B,j);
        else if (N[i] == 'H') val += 17*pow(B,j);
        else if (N[i] == 'I') val += 18*pow(B,j);
        else if (N[i] == 'J') val += 19*pow(B,j);
        else if (N[i] == 'K') val += 20*pow(B,j);
        else if (N[i] == 'L') val += 21*pow(B,j);
        else if (N[i] == 'M') val += 22*pow(B,j);
        else if (N[i] == 'N') val += 23*pow(B,j);
        else if (N[i] == 'O') val += 24*pow(B,j);
        else if (N[i] == 'P') val += 25*pow(B,j);
        else if (N[i] == 'Q') val += 26*pow(B,j);
        else if (N[i] == 'R') val += 27*pow(B,j);
        else if (N[i] == 'S') val += 28*pow(B,j);
        else if (N[i] == 'T') val += 29*pow(B,j);
        else if (N[i] == 'U') val += 30*pow(B,j);
        else if (N[i] == 'V') val += 31*pow(B,j);
        else if (N[i] == 'W') val += 32*pow(B,j);
        else if (N[i] == 'X') val += 33*pow(B,j);
        else if (N[i] == 'Y') val += 34*pow(B,j);
        else if (N[i] == 'Z') val += 35*pow(B,j);
        j++;
    }
    printf("%d",val);
}