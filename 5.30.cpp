#include <stdio.h>

    int n;
    int ccase[2000000] = {0}; 
    int p[20];
    int result[60];

int main() {


    printf("카드의 개수를 입력하세요: ");
    scanf("%d", &n);

    printf("카드의 숫자를 입력하세요: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    for(int i = 0; i < n; i++) {
        int card = p[i];
        int index = 1;
        while(ccase[index] != 0) {
            if(card < ccase[index])
                index *= 2;
            else
                index = index * 2 + 1;
        }
        ccase[index] = card;
        result[i] = index;
    }

    for(int c = 0; c < n; c++) {
        printf("%d ", result[c]);
    }

    return 0;
}
