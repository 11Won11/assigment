#include <stdio.h>
//1. Check room (Men) 출력
//2. 반복문으로 Room #10n > 출력
//3. 반복문으로 101 ~ 103호까지 사람수를 입력받기
//4. 20n호도 똑같이 출력후 입력받기
//5. Check room (Women) 출력
//6. 30n와 40n호 도 2,3번과 동일하게 반복
//7. Check Result 출력
//8. Men: 현재인원/총인원 (비율) 출력
//9. 여자와 전체 인원과 비율도 위와 같이 출력
int main() {
    int person[4][3]; // 4 3 개 층별 개 호실의 점호 인원 수 
    int sum[3] = {0}; // ( , , ) 점호 인원 수 합계 남 여 전체
    float ratio[3] = {0}; // ( , , ) 점호 인원 수 비율 남 여 전체
    int i, j; // 반복문을 위한 변수 
    printf("Check room (Men)\n");
    for(i = 0; i < 3; i++){
        printf("Room #10%d > ", i+1);
        scanf("%d", &person[0][i]);
        sum[0] += person[0][i];
        sum[2] += person[0][i];
    }
    for(i = 0; i < 3; i++){
        printf("Room #20%d > ", i+1);
        scanf("%d", &person[1][i]);
        sum[0] += person[1][i];
        sum[2] += person[1][i];
    }
    printf("Check room (Women)\n");
    for(i = 0; i < 3; i++){
        printf("Room #30%d > ", i+1);
        scanf("%d", &person[2][i]);
        sum[1] += person[2][i];
        sum[2] += person[2][i];
    }
    for(i = 0; i < 3; i++){
        printf("Room #40%d > ", i+1);
        scanf("%d", &person[3][i]);
        sum[1] += person[3][i];
        sum[2] += person[3][i];
    }
    for(i = 0; i < 2; i++){
        ratio[i] = ((float)sum[i]/24)*100;
    }
    ratio[2] = (float)sum[2]/48*100;
    printf("Check Result\n");
    printf("Men: %d/24 (%.1f%%)\n", sum[0], ratio[0]);
    printf("Women: %d/24 (%.1f%%)\n", sum[1], ratio[1]);
    printf("Total: %d/48 (%.1f%%)\n", sum[2], ratio[2]);
    return 0;
}