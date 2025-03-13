#include <stdio.h>

int main(){
    int height, weight; // 신장(cm), 체중(kg) 
    float bmi; // 비만도 수치 
    scanf("%d %d", &height, &weight);
    printf("%.1f", (float)weight*10000/(float)(height*height));
}