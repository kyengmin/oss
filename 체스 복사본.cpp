#include <stdio.h>
#define MAX 8 

int chess[MAX][MAX];
void prt();
void prt1();
int promise();
int promise1();
void queen();
void queen2();

int cnt = 0; 



// 현재 위치에 퀸을 놓을 수 있는지 확인
int promise(int row,int col){
    int i,j;
    if(row>=MAX||col>=MAX){
        return 0;
    }
    else{
        for(i=1;row-i>=0;i++){
            if(chess[row-i][col]==1)
                return 0;
            else if(col-i>=0&&chess[row-i][col-i]==1)
                return 0;
            else if (col+i<MAX && chess[row-i][col+i]==1)
                return 0;
        }
    }
    return 1;
}

// 현재 행에 퀸을 놓음
void queen(int row) {
    int i;
    if (row == MAX) {
        cnt++;
        prt();
    }
    if (row < MAX) {
        for (i = 0; i < MAX; i++) {
            if (promise(row, i)) {
                chess[row][i] = 1;
                queen(row + 1);
                chess[row][i] = 0;
            }
        }
    }
    //row 입력 받기 체스판의 크기와 같으면 끝남.
    //체스판 크기보다 작으면 row-i -> 모든 열 
}


void prt() {
    int i, j;
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            printf("%d", chess[i][j]);
        }
        printf("\n");
    }
    printf("%d==============\n", cnt);
}


int promise1(int row, int col) {
    // 현재 열에 퀸 있는지 확인
    for (int i = 0; i < row; i++) {
        if (chess[i][col] == 1)
            return 0;
    }

    // 좌상단 대각선에 퀸 있는지 확인
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (chess[i][j] == 1)
            return 0;
    }

    // 우상단 대각선에 퀸이 있는지 확인
    for (int i = row, j = col; i >= 0 && j < MAX; i--, j++) {
        if (chess[i][j] == 1)
            return 0;
    }

    return 1;
}


void queen2(int row) {
    if (row == MAX) {
        cnt++;
        prt1();
        return;
    }

    for (int col = 0; col < MAX; col++) {
        if (promise1(row, col)) {
            chess[row][col] = 1;
            queen2(row + 1);
            chess[row][col] = 0;
        }
    }
}


void prt1() {
    printf("[%d]:", cnt);
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (chess[i][j] == 1)
                printf(" %d", j);
        }
    }
    printf("\n");
}

int main() {
    queen(0);
    queen2(0);
    prt1();
    return 0;
}