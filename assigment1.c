
#include <stdio.h>
/*별로 트로피 모양 찍기
1. size 값 입력 받기
2. 주어진 size값에 맞쳐 역삼각형 만들기
3. size*2만큼 별을 찍고 줄 바꾸며 그걸 size 크기 만큼 만들기
4. size*2만큼 별을 찍고 줄 바꾸며 양옆에서 하니씩 없에면서 짝가
5. size*2만큼 별 찍기기 
*/

int main() {
    int size; // 크기
    int stars, blank1, blank2; // , 1 , 2 별의 갯수 빈칸 의 갯수 빈칸 의 갯수
    int i, j; // 반복문을 위한 변수 
    //1. size 입력받기
    scanf("%d", &size);
    //2. 주어진 크기값으로 역삼각형 만들기
    for(i = 0; i < size; i++){
        blank1 = size*2 -2 - i*2;
        //앞에 공백 찍기기
        for(j = 0; j < i; j++){
            printf(" ");
        }
        //앞에 별 찍기
        printf("*");
        //사이 공백 찍기
        for(j = 0; j < blank1; j++){
            printf(" ");
        }
        //마지막 별 찍고 줄 바꿈
        printf("*\n");
        //공백 줄이기 
    }
    //3. size*2만큼 가로 size만큼 세로인 직사각형 만들기
    //가로 만큼 반복
    for(i = 0; i < size; i++){
        //세로만큼 반복
        for(j = 0; j < size*2; j++){
            printf("*");
        }
        //마지막 줄바꿈
        printf("\n");
    } 
    //4. 3에서 만든거에서 양쪽 하나씩 뺴면서 내려오기 
    for(i = 0; i < size; i++){
        blank1 = i;
        for(int j = 0; j < blank1; j++){
            printf(" ");
        }
        for(j = 0; j < size*2 - i*2; j++){
            printf("*");
        }
        printf("\n");
    } 
    //5. 마지막 size*2만큼 별 한줄 찍기
    for(i = 0; i < size*2; i++){
        printf("*");
    }
    return 0;
}