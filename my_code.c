/**
ID:181-35-2288
Name: Khandoker Wakib Rashad
*/
#include <stdio.h>

int main()
{
    int input,j,k;
    scanf("%d",&input);
    int edge[input][input];


    for(int i=0;i<input;i++){
            for(int l=0; l<input; l++){
        edge[i][l] = edge[l][i] = 0;
            }
    }
    for(int i=0;i<input;i++){
        scanf("%d %d",&j,&k);
        edge[j][k] = edge[k][j] = 1;
    }
         printf("   ");
     for (int z=0; z<input;)
     printf("%d ",++z);
     printf("\n");
     int r=1;
    for (int z=0; z<input;++z){
            printf("%d->",z+r);
    for(int l=0; l<input; l++){
        printf("%d ",edge[z][l]);
    }
    printf("\n");
}

    return(0);
}
/**
Input Data Set for testing :
8
1 2
1 3
2 3
2 4
4 7
2 5
3 6
5 8

Output:
   1 2 3 4 5 6 7 8
1->0 0 0 0 0 0 0 0
2->0 0 1 1 0 0 0 0
3->0 1 0 1 1 1 0 0
4->0 1 1 0 0 0 1 0
5->0 0 1 0 0 0 0 1
6->0 0 1 0 0 0 0 0
7->1 0 0 1 0 0 0 0
8->0 0 0 0 1 0 0 0

*/
