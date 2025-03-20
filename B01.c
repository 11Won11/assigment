#include <stdio.h>

int studentSum(int s[5][3], int size, int index);
//파라미터 : 점수배열(s)과 학생번호(0,1,2,3,4) 
//리턴값 : 해당 학생의 총점
char getGrade(float score);
//파라미터 : 평균 점수(score) 
//리턴값 : 해당 평균 점수의 등급 ('A','B','C','D','F')
int classSum(int s[5][3], int size, int number);
//파라미터 : 점수배열(s)과 과목번호(0,1,2) 
//리턴값 : 해당 과목의 총점
int firstRanking(int s[20], int size);
//파라미터 : 점수배열(s)과 인원수(size) 
//리턴값 : 가장 높은 점수를 가진 배열 인덱스

int main(){
	int jumsu[20][3]; // 최대 20명의 3과목 점수를 저장하고 있는 2차원 배열 
	int sum_student[20]; // 최대 20명의 학생별 총점
	float average_student[20];  // 최대 20명의 학생별 평균
	char grade[20]; // 최대 20명의 학생별 등급 
	int first;	// 1등 학생 번호
	int all;	// 인원수
	int sum_class[3]; // 과목별 총점
	float average_class[3]; // 과목별 평균
	char class_name[3][20] = {"Korean", "English", "Math"};

	// Your code here.
    scanf("%d", &all);
    for(int i = 0; i  < all; i++){
        scanf("%d %d %d", &jumsu[i][0], &jumsu[i][1], &jumsu[i][2]);
    }
    for(int i = 0; i < all; i++){
        sum_student[i] = studentSum(jumsu, all, i);
        average_student[i] = sum_student[i]/3.0;
        grade[i] = getGrade(average_student[i]);
    }
    for(int i = 0; i < 3; i++){
        sum_class[i] = classSum(jumsu, all ,i);
        average_class[i] = sum_class[i]/(all*1.0);

    }
    for(int i = 0; i < all; i++){
        printf("%d) %d %.1f %c\n", i+1, sum_student[i], average_student[i], grade[i]);
    }
    for(int i = 0; i < 3; i++){
        printf("%s %d %.1f\n", class_name[i], sum_class[i], average_class[i]);
    }
    printf("1st Ranking: %d", firstRanking(sum_student, all));
	return 0;
}

int studentSum(int s[5][3], int size, int index){
    int total = 0;
    for(int i = 0; i < 3; i++){
        total += s[index][i];
    }
    return total;
}

char getGrade(float score){
    if(score >= 90){
        return 'A';
    }
    else if(score >= 80){
        return 'B';
    }
    else if(score >= 70){
        return 'C';
    }
    else if(score >= 60){
        return 'D';
    }
    else{
        return 'F';
    }
}

int classSum(int s[5][3], int size, int number){
    int total = 0;
    for(int i = 0; i < size; i++){
        total += s[i][number];
    }
    return total;
}

int firstRanking(int s[20], int size){
    int max = 0;
    int index;
    for(int i = 0; i < size; i++){
        if(s[i] >= max){
            max = s[i];
            index = i;
        }
    }
    return index+1;
}