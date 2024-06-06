#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define ROWS 10
#define COLS 20

//Πρότυπα συναρτήσεων
void createRandomRatings(int MovieRatings[][COLS]);
void printMovieRatings(int MovieRatings[][COLS]);
void printMovieRatingsAverage(int MovieRatings[][COLS], int j);
float movieAverage(int MovieRatings[][COLS], int j);
int findBestRatedMovie(int MovieRatings[][COLS]);
int findWorstRatedMovie(int MovieRatings[][COLS]);
void sortFriendsRatings(int MovieRatings[][COLS]);
float* friendsRating(int MovieRatings[][COLS]);
void bubblesort(float array[],int n);

int main(){
	
    system("chcp 1253>nul");
    int MovieRatings[ROWS][COLS]={0};
    
    int i;
    srand(time(NULL));
    createRandomRatings(MovieRatings);
    printMovieRatings(MovieRatings);
    printf("\n");
    puts("\n***************************************************");
    //Κώδικας για την εκτύπωση του ΜΟ των βαθμολογιών κάθε κινηματογραφικής ταινίας
    puts("Εκτύπωση του ΜΟ των βαθμολογιών κάθε κινηματογραφικής ταινίας: ");
    for(i = 0; i < COLS;i++){
		printMovieRatingsAverage(MovieRatings,i);
	}
	puts("\n***************************************************");
    //Κώδικας για την εμφάνιση της στήλης με τον υψηλότερο ΜΟ βαθμολογίας
    printf("\nΗ ταινία με τον υψηλότερο ΜΟ βαθμολογίας βρίσκεται στην  %dη στήλη.",findBestRatedMovie(MovieRatings) + 1);

    //Κώδικας για την εμφάνιση της στήλης με τον χαμηλότερο ΜΟ βαθμολογίας
	printf("\nΗ ταινία με τον χαμηλότερο ΜΟ βαθμολογίας βρίσκεται στην  %dη στήλη.",findWorstRatedMovie(MovieRatings) + 1);
	puts("");
	puts("\n***************************************************");
    //Κώδικας για την εμφάνιση του ΜΟ των βαθμολογιών κάθε ενός από τους δέκα φίλους για τις δέκα κινηματογραφικές ταινίες σε αύξουσα σειρά
   	sortFriendsRatings(MovieRatings);
    //Κώδικας για την εμφάνιση της σειράς του πίνακα όπου βρίσκονται οι βαθμολογίες του πιο αυστηρού και του πιο επιεικούς κριτή
	puts("");
	puts("\n***************************************************");
    system("PAUSE");
    return 0;
}
/******************Συναρτήσεις ***************************************/

 //Η συνάρτηση γεμίζει έναν πίνακα με τυχαίες τιμές
void createRandomRatings(int MovieRatings[][COLS]){
     int i, j;
     for(i=0; i<ROWS; i++)
       for(j=0; j<COLS; j++)
          MovieRatings[i][j] = 0 + rand() % 11;
}
//Η συνάρτηση εμφανίζει στην οθόνη το ΜΟ των βαθμολογιών που έχει λάβει μια κινηματογραφική ταινία
void printMovieRatings(int MovieRatings[][COLS]){
	 int i, j;
	 printf("Οι βαθμολογίες των κινηματογραφικών ταινιών είναι: \n");
     for (i =1; i<21;i++)printf("T%-2d   ",i);
	 puts("");
     for(i=0; i<ROWS; i++){
     	for(j=0; j<COLS; j++){
     		printf("%-6d",MovieRatings[i][j]);
		 }
     puts("");
	 }

}
//Η συνάρτηση υπολογίζει τον ΜΟ μιας ταινίας
float movieAverage(int MovieRatings[][COLS], int j){
	int row;
	int sum = 0;
	for(row = 0; row <ROWS; row++){
		sum += MovieRatings[row][j];
	}
	return (float)sum/ROWS;
}
//Η συνάρτηση εμφανίζει στην οθόνη το ΜΟ των βαθμολογιών που έχει λάβει μια κινηματογραφική ταινία
void printMovieRatingsAverage(int MovieRatings[][COLS], int j){
	float mo;
	mo = movieAverage(MovieRatings,j);
	printf("\nO MO βαθμολογίας της %d ταινίας είναι:\t%.2f.",j+1,mo);
}

//Η συνάρτηση επιστρέφει τον αριθμό της στήλης στην οποία βρίσκεται η ταινία με τον μεγαλύτερο ΜΟ βαθμολογίας
int findBestRatedMovie(int MovieRatings[][COLS]){
	float best_movie = 0.0 ;
	int col;
	float mo;
	int i;
	for (i = 0;i<COLS;i++){
		mo = movieAverage(MovieRatings,i);
		if(mo > best_movie){
			best_movie =mo;
			col = i;
		}
	}
	return col;
}
//Η συνάρτηση επιστρέφει τον αριθμό της στήλης στην οποία βρίσκεται η ταινία με τον μικρότερο  ΜΟ βαθμολογίας
int findWorstRatedMovie(int MovieRatings[][COLS]){
	float worst_movie = 100 ; //Η μέγιστη βαθμολογία που μπορεί να πάρει μια ταινία
	int col = 0;
	float mo;
	int i;
	for (i = 0;i<COLS;i++){
		mo = movieAverage(MovieRatings,i);
		if(mo < worst_movie){
			worst_movie = mo;
			col = i;
		}
	}
	return col;
}

//H συνάρτηση ταξινομεί τον ΜΟ των βαθμολογιών των ταινιών των 10 φίλων.
void sortFriendsRatings(int MovieRatings[][COLS]){
	
	float friendsRatingsAverage[ROWS];
	int row,col,i;
	int sum = 0;
	float strict,lenient;
	int strict_row,lenient_row;
	
	for( row = 0; row<ROWS;row++){
		sum = 0;
		for (col = 0; col<COLS;col++){
			sum += MovieRatings[row][col];
		}
		friendsRatingsAverage[row] = (float)sum/COLS;
		printf("\nO ΜΟ βαθμολογίας του %dου φίλου είναι:\t%.2f",row+1,friendsRatingsAverage[row]);
	}
	strict = 10,lenient = 0;
	for(row = 0; row<ROWS; row++){
		if (friendsRatingsAverage[row] < strict){
			strict = friendsRatingsAverage[row];
			strict_row = row;
		}
		if (friendsRatingsAverage[row] > lenient){
			lenient = friendsRatingsAverage[row];
  			lenient_row = row;
		}
	}
	bubblesort(friendsRatingsAverage,ROWS);
	puts("\n***************************************************");
	puts("\nO MO βαθμολογίας κάθε ενός από τους δέκα φίλους για τις δέκα κινηματογραφικές ταινίες σε αύξουσα σειρά: ");
	for (i =0; i< ROWS;i++) printf("%.2f   ",friendsRatingsAverage[i]);
	printf("\nΟ πιο αυστηρός κριτής βρίσκεται στην %dη γραμμή.",strict_row+1);
	printf("\nΟ πιο επιεικής κριτής βρίσκεται στην %dη γραμμή.",lenient_row+1);

}
// Αλγόριθμος ταξινόμησης Bubble sort.
void bubblesort(float array[],int n){
	int i,j;
	float temp;
	for(i =0;i<n;i++){
		for(j = n-1;j>=i;j--){
			if(array[j]<array[j-1]){
				temp = array[j];
				array[j] = array[j-1];
				array[j-1] = temp;
			}
		}
	}
}

