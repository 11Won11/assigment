#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct st_person{
	char name[20]; 	// Name (single word, no duplicates)
	int gender;  	// 0 - Female, 1 - Male
	int country;	// Country code (index of COUNTRY_NAME 0~5)
	int birthyear; 	// Birthyear
};

int getCountry(char* str);
//파라미터: 국적을 나타내는 문자열(str) 
//리턴값: 국적에 해당되는 인덱스 (0~5)
//수행내용: 국적 문자열에 해당하는 인덱스를 찾는다.
void printInfo(struct st_person* p);
//파라미터: 학생정보 구조체 포인터(p) 
//리턴값: 없음
//수행내용: 해당 학생 정보의 내용을 출력한다.
int countGender(struct st_person* data[], int size, int gender, int country);
float averageAge(struct st_person* data[], int size, int country);
int main(){
    struct st_person* pdata[20]; // 최대 20명의 데이터	
	char country[5]; // 국적입력을 위한 문자열
	int count;  // 인원수
	char countryName[6][5] = {"KR", "US", "JP", "CN", "FR", "--"};
	scanf("%d", &count);
	for(int i = 0; i < count; i++){
		pdata[i] = (struct st_person*)malloc(sizeof(struct st_person));
		scanf("%s %d %s %d", pdata[i]->name, &pdata[i]->gender, country, &pdata[i]->birthyear);
		pdata[i]->country = getCountry(country);
	}
	for(int i = 0; i < count; i++){
		printf("%d) ", i+1);
		printInfo(pdata[i]);
	}
	for(int i = 0; i < 6; i++){
		printf("[%s] Female:%d Male:%d average age:%.1f\n", countryName[i], countGender(pdata, count, 0, i),  countGender(pdata, count, 1, i), averageAge(pdata, count, i));
	}
	for(int i = 0; i < count; i++) {
        free(pdata[i]);
    }
    return 0;
}

int getCountry(char* str) {
    if (strcmp(str, "KR") == 0) {
        return 0;
    }
    else if (strcmp(str, "US") == 0) {
        return 1;
    }
    else if (strcmp(str, "JP") == 0) {
        return 2;
    }
    else if (strcmp(str, "CN") == 0) {
        return 3;
    }
    else if (strcmp(str, "FR") == 0) {
        return 4;
    }
    else {
        return 5;
    }
}

void printInfo(struct st_person* p){
	char country[6][5] = {"KR", "US", "JP", "CN", "FR", "--"};
	char gender[2][10] = {"Female", "Male"};
	printf("%s (%s, age:%d, from %s)\n", p->name, gender[p->gender], 2025 - p->birthyear, country[p->country]);
}

int countGender(struct st_person* data[], int size, int gender, int country){
	int count = 0;
	for(int i = 0; i < size; i++){
		if(data[i]->country == country){
			if(data[i]->gender == gender){
			count++;
			}
		}
	}
	return count;
}

float averageAge(struct st_person* data[], int size, int country){
	float avg = 0;
	int count = 0;
	for(int i = 0; i < size; i++){
		if(data[i]->country == country){
			count++;
			avg = avg + 2025 - data[i]->birthyear;
		}
	}
	if(count == 0){
		return 0;
	}
	else{
		return avg/count;
	}
}