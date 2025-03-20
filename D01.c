#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

void printMovie(MOVIE* p);
int indexGenre(char* name);

int main() {
	MOVIE* list[10];
	int count;
	char title[100], desc[255], genre[50];
	int year, playtime, viewers;
	
	scanf("%d", &count);
	for(int i=0; i<count; i++){
		getchar();
		fgets(title, 100, stdin);
		fgets(desc, 255, stdin);
		scanf("%d %s %d %d", &year, genre, &playtime, &viewers);
		list[i] = (MOVIE*) malloc(sizeof(MOVIE));
        strcpy(list[i]->title, title);
        strcpy(list[i]->description, desc);
        list[i]->year = year;
        list[i]->genre = indexGenre(genre);
        list[i]->playtime = playtime;
        list[i]->viewers = viewers;
    }
	// Your code here!i
	for(int i = 0; i < count; i++){
        printf("%d) ", i+1);
        printMovie(list[i]);
    }
	return 0;
}

void printMovie(MOVIE* p){
    printf("%s [%d, %s, %d min, %d viewers]\n", p->title, p->year, genre_name[p->genre], p->playtime, p->viewers);
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
}