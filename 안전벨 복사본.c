#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// 집 구조체 정의
typedef struct {
    int x;
    int y;
} House;

// 두 집 사이의 맨해튼 거리 계산 함수
int manhattan_distance(House a, House b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

// 안전벨을 설치할 K개의 집을 선택하는 모든 조합을 생성하는 함수
void generate_combinations(int *comb, int n, int k, int start, int depth, void (*callback)(int *)) {
    if (depth == k) {
        callback(comb);
        return;
    }
    for (int i = start; i < n; i++) {
        comb[depth] = i;
        generate_combinations(comb, n, k, i + 1, depth + 1, callback);
    }
}

int N, K;
House houses[50];
int min_max_distance = INT_MAX;

// 각 조합을 평가하는 함수
void evaluate_combination(int *comb) {
    int max_distance = 0;
    for (int i = 0; i < N; i++) {
        int min_distance = INT_MAX;
        for (int j = 0; j < K; j++) {
            int distance = manhattan_distance(houses[i], houses[comb[j]]);
            if (distance < min_distance) {
                min_distance = distance;
            }
        }
        if (min_distance > max_distance) {
            max_distance = min_distance;
        }
    }
    if (max_distance < min_max_distance) {
        min_max_distance = max_distance;
    }
}

int main() {
    // 입력 받기
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &houses[i].x, &houses[i].y);
    }

    // K개의 안전벨을 설치할 집의 조합을 담을 배열
    int comb[3];

    // 모든 조합을 생성하여 평가
    generate_combinations(comb, N, K, 0, 0, evaluate_combination);

    // 결과 출력
    printf("%d\n", min_max_distance);

    return 0;
}
