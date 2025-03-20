/*
*[Full Name]: <홍진원>
*[Student ID]: <22200803>
*[Honor Code Pledge] 나 홍진원은 하나님과 사람 앞에서 정직하고 성시하게 테스트를 수행하겠습니다.
*/
#include <stdio.h>

int main(){
    const char *monthname[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    char name[100][20];
    int birthdate[100];
    int count;
    int minYear;
    int index = 0;
    scanf("%d", &count);
    for(int i = 0; i < count; i++){
        scanf("%s %d", name[i], &birthdate[i]);
    }
    minYear = birthdate[0];
    for(int i = 0; i < count; i++){
        if(minYear >= birthdate[i]){
            minYear = birthdate[i];
            index = i;
        }
    }
    int age;
    int day;
    int month;
    int year;
    day = birthdate[index]%10 + ((birthdate[index]/10)%10)*10;
    month = (birthdate[index]/100)%10 + ((birthdate[index]/1000)%10)*10;
    year = birthdate[index]/10000;
    age = 2025 - year;
    printf("%s - %d (%s %d, %d)", name[index], age, monthname[month-1], day, year);
}