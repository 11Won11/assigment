/*
*[Full Name]: <홍진원>
*[Student ID]: <22200803>
*[Honor Code Pledge] 나 홍진원은 하나님과 사람 앞에서 정직하고 성시하게 테스트를 수행하겠습니다.
*/
#include <stdio.h>

int main(){
    const char *monthname[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    char name[20];
    int birthdate;
    int age;
    int day;
    int month;
    int year;
    scanf("%s %d", name, &birthdate);
    day = birthdate%10 + ((birthdate/10)%10)*10;
    month = (birthdate/100)%10 + ((birthdate/1000)%10)*10;
    year = birthdate/10000;
    age = 2025 - year;
    printf("%s - %d (%s %d, %d)", name, age, monthname[month-1], day, year);
    return 0;
}