/*
Programming Studio C003
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int findRoom(int persons[5]); // 5개의 호실 중 빈 베드가 있는 방을 찾아낸다. (리턴값 1~5)
void printReport(char mn[10][20], int mr[10], int mc, char wn[10][20], int wr[10], int wc); // 배정 결과를 출력한다.

int main(){
    char mnames[10][20]; // 남학생명단(최대 10명)
    int mroom[10];		// 남학생명단별 호실 배정 목록
    char wnames[10][20]; // 여학생명단(최대 10명)
    int wroom[10];		// 여학생명단별 호실 배정 목록
    int person[2][5]={0};   // 2개 층별 5개 호실의 배정 인원 수 
    int mcount=0, wcount=0; // 인원 합계 (남, 여)
    int menu;

    srand(time(0));
    printf("===========================================\n");
    printf("생활관 호실 배정 프로그램\n");
    printf("===========================================\n");
    while(1){
        printf("메뉴 : 1.남학생 등록 2.여학생 등록 0.종료 > ");
        scanf("%d", &menu);
        if(menu==0) break;
        else if(menu==1) {
            if(mcount>=10) {
                printf("정원 초과입니다. 등록불가!\n");
                continue;
            }
            printf("학생 이름은? > ");
            scanf("%s", mnames[mcount]);
            int roomno = findRoom(person[0]);
            mroom[mcount] = 100+roomno;
            printf("%s 학생 %d호실 배정되었습니다.\n", mnames[mcount], mroom[mcount]);
            mcount++;
        }
        else if(menu==2) {
            if(wcount>=10) {
                printf("정원 초과입니다. 등록불가!\n");
                continue;
            }
            printf("학생 이름은? > ");
            scanf("%s", wnames[wcount]);
            int roomno = findRoom(person[1]);
            wroom[wcount] = 200+roomno;
            printf("%s 학생 %d호실 배정되었습니다.\n", wnames[wcount], wroom[wcount]);
            wcount++;
        }
    }

    printf("===========================================\n");
    printf("생활관 호실 배정 결과는 다음과 같습니다.\n");
    printf("===========================================\n");
    printReport(mnames, mroom, mcount, wnames, wroom, wcount);

    return 0;
}

int findRoom(int persons[5]){
// 이 곳에 생각 정리와 코드 구현
//1. 랜덤으로 0 ~ 4까지의 값을 찾아 나온 값을 random 변수의 배정정  
//2. person[random]이 2보다 작으면 person[random]값의 1을 더 해주고 배정된 랜덤 값 리턴
//3. 만약 2보다 크거나 같으면 다시 1번으로 돌아가기 
    //배치가능 한 호실을 찾을 때 까지 반복복
    while(1){  
        //srand 함수로 시간을 계속 변경해주고  
        srand(time(NULL)); 
        //rand 함수로 난수 생성후 5로 나누어 나오는 나머지 값을 0 ~ 4로 고정
        int random = rand()%5;
        //만약 2명 이상 없으면 배치
        if(persons[random] < 2){
            persons[random]++;
            //10n값에서 n값 리턴
            return random+1;
        }
    }
}

void printReport(char mn[10][20], int mr[10], int mc, char wn[10][20], int wr[10], int wc){
// 이 곳에 생각 정리와 코드 구현
//1.남학생 명단(n명)을 줄 바꿈 작성 후에 n. 이름 [배정호] 줄바꿈 출력
//2.한칸 뛰기
//3.여학생 명단도 동일하게
//4.한칸 뛰기
//5. 호실별 배정 명단 작성 줄바꿈꿈 후 101호부터 순선대로 배정호 : 이름 이름 출력
    //남학생 명단 출력력
    printf("남학생 명단(%d명)\n", mc);
    //반복문으로 n. 이름 [배정호] 출력
    for(int i = 0; i < mc; i++){
        printf("%d. %s [%d]\n", i+1, mn[i], mr[i]);
    }
    printf("\n");
    //여여학생 명단 출력
    printf("여학생 명단(%d명)\n", wc);
    //반복문으로 n. 이름 [배정호] 출력
    for(int i = 0; i < wc; i++){
        printf("%d. %s [%d]\n", i+1, wn[i], wr[i]);
    }
    printf("\n");
    //호실별 배정 명단 출력
    printf("호실별 배정 명단\n");
    for(int i = 0; i < 5; i++){
       // 호실 번호 출력
        printf("%d : ", 101 + i);
        // 출력하는 호실 번호에 index 찾기
        for(int j = 0; j < 10; j++){
            //일치하는 인덱스 값에 있는 이름 출력
            if(mr[j] == i+101){
                printf("%s ", mn[j]);
            }
        }
        printf("\n");
    }
    //위에 남성과 똑같이
    for(int i = 0; i < 5; i++){
        printf("%d : ", 201 + i);
        for(int j = 0; j < 10; j++){
            if(wr[j] == i+201){
                printf("%s ", wn[j]);
            }
        }
        printf("\n");
    }
}

