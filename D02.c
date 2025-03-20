#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct st_movie{
	char title[100];
	int year, genre, playtime, viewers;
	char description[255];
} MOVIE;

const char* genre_name[] = {
	"Sci-Fi",
	"Thriller",
	"Action",
	"Romance",
	"Musical",
	"Drama",
	"Animation",
	"War"
};

int loadRecords(MOVIE* list[]);
void printMovie(MOVIE* p);
void printReport(MOVIE* list[], int size);
int indexGenre(char* name);
void printGenreCount(MOVIE* list[], int size);
int maxViewers(MOVIE* list[], int size);
int maxPlaytime(MOVIE* list[], int size);

int main() {
	MOVIE* mlist[50];
	int count;

	count = loadRecords(mlist);	
	for(int i=0; i<count; i++){
		printf("%d) ", i+1);
		printMovie(mlist[i]);
	}
	printReport(mlist, count);
	return 0;
}

int loadRecords(MOVIE* list[]){
    int count;
    char genre[10];
    scanf("%d", &count);
    for(int i = 0; i < count; i++){
        list[i] = (MOVIE*)malloc(sizeof(MOVIE));
        getchar();
        fgets(list[i]->title, 100, stdin);
        fgets(list[i]->description, 255, stdin);
        scanf("%d %s %d %d", &list[i]->year, genre, &list[i]->playtime, &list[i]->viewers);
        list[i]->genre = indexGenre(genre);
    }
    printf("%d records loaded.\n");
    for(int i = 0; i < count; i++){
        free(list[i]);
    }
    return count;
}

void printMovie(MOVIE* p){
    printf("%s [%d, %s, %d min, %d viewers]\n", p->title, p->year, genre_name[p->genre], p->playtime, p->viewers);
}

void printReport(MOVIE* list[], int size){
    printf("\n1. Number of movies by genre\n");
    printGenreCount(list, size);
    int maxP = maxPlaytime(list, size);
    printf("\n2. Longest\n");
    printf("%s [%d, %s, %d min %d viewers]\n%s\n\n", list[maxP]->title ,list[maxP]->year, genre_name[list[maxP]->genre], list[maxP]->playtime, list[maxP]->viewers, list[maxP]->description);
    int maxV = maxViewers(list, size);
    printf("3. Most popular\n");
    printf("%s [%d, %s, %d min %d viewers]\n%s\n", list[maxV]->title ,list[maxV]->year, genre_name[list[maxV]->genre], list[maxV]->playtime, list[maxV]->viewers, list[maxV]->description);
}

int indexGenre(char* name){
    if(strcmp(name , "Sci-Fi") == 0){
        return 0;
    }
    else if(strcmp(name , "Thriller") == 0){
        return 1;
    }
    else if(strcmp(name , "Action") == 0){
        return 2;
    }
    else if(strcmp(name , "Romance") == 0){
        return 3;
    }
    else if(strcmp(name , "Musical") == 0){
        return 4;
    }
    else if(strcmp(name , "Drama") == 0){
        return 5;
    }
    else if(strcmp(name , "Animation") == 0){
        return 6;
    }
    else if(strcmp(name , "War") == 0){
        return 7;
    }
    else{
        return -1;
    }
}

void printGenreCount(MOVIE* list[], int size){
    int genreCount[8] = {0};
    for(int i = 0; i < size; i++){
        if(list[i]->genre == 0){
            genreCount[0]++;
        }
        else if(list[i]->genre == 1){
            genreCount[1]++;
        }
        else if(list[i]->genre == 2){
            genreCount[2]++;
        }
        else if(list[i]->genre == 3){
            genreCount[3]++;
        }
        else if(list[i]->genre == 4){
            genreCount[4]++;
        }
        else if(list[i]->genre == 5){
            genreCount[5]++;
        }
        else if(list[i]->genre == 6){
            genreCount[6]++;
        }
        else{
            genreCount[7]++;
        }
    }
    for(int i = 0; i < 8; i++){
        printf("[%d] %s %16d movies\n", i+1, genre_name[i], genreCount[i]);
    }
}

int maxViewers(MOVIE* list[], int size){
    int max = list[0]->viewers;
    int index = 0;
    for(int i = 0; i < size; i++){
        if(max <= list[i]->viewers){
            max = list[i]->viewers;
            index = i;
        }
    }
    return index;
}

int maxPlaytime(MOVIE* list[], int size){
    int max = list[0]->playtime;
    int index = 0;
    for(int i = 0; i < size; i++){
        if(max <= list[i]->playtime){
            max = list[i]->playtime;
            index = i;
        }
    }
    return index;
}