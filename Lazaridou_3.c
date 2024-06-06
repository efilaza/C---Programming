#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define N 3
#define AR 0.6
#define SIZE 80

typedef struct {
	int a_a;
	char title[SIZE];
	int first_judge_relevance;
	int first_judge_grade;
	int second_judge_relevance;
	int second_judge_grade;
	float total;
	char decision[12];

}submission;

/* Πρότυπα Συναρτήσεων */
void fill_submission(submission *p);
int check_numbers(int start,int finish,char str[]);
void print_sub(submission p);
void total_grade(submission *p);
float best_submission(submission a[]);
void set_decision(submission a[],float best_mark);
void print_info(submission a[]);
void print_best_submissions(submission a[],float best_mark);
bool comparison(float a,float b);


int main (void){
 	system("chcp 1253>nul");
	submission array[N];
	int i;
	float best_mark;
	
	for( i = 0;i<N;i++){
		fill_submission(&array[i]);
		printf("\nΣυνολική αξιολόγηση εργασίας: %.2f\n",array[i].total);
	}
	best_mark = best_submission(array);
	printf("Η υψηλότερη συνολική αξιολόγη είναι %.2f",best_mark);
	for (i=0;i<N;i++){
		set_decision(&array[i],best_mark);
	}
	print_info(array);
	print_best_submissions(array,best_mark);

 }

void fill_submission(submission *p){
	/*Η συνάρτηση δέχεται ως όρισαμ έναν δείκτη
	σε δομή submission και γεμίζει τα πεδία της δομής
	με είσοδο από τον χρήστη. Δεν επιστρέφει τιμή*/
	static int serial = 0;
	char message[40];
	serial +=1;
    p->a_a = serial;
  	printf("%s","Δώσε τον τίτλο της εργασίας:");
	gets(p->title);
 	strcpy(message, "\nΔώστε την συνάφεια του 1ου κριτή. Οι αποδεκτές τιμές είναι από -3 έως 3:");
	p->first_judge_relevance = check_numbers(-3,3,message);
	strcpy(message, "\nΔώστε τον βαθμό του 1ου κριτή. Οι αποδεκτές τιμές είναι 0,1,2 ή 3: ");
	p->first_judge_grade = check_numbers(0,3,message);
	strcpy(message, "\nΔώστε την συνάφεια του 2ου κριτή. Οι αποδεκτές τιμές είναι από -3 έως 3:");
	p->second_judge_relevance = check_numbers(-3,3,message);
	strcpy(message, "\nΔώστε τον βαθμό του 2ου κριτή. Οι αποδεκτές τιμές είναι 0,1,2 ή 3: ");
	p->second_judge_grade = check_numbers(0,3,message);
	total_grade(p);
	fseek(stdin,0,SEEK_END);//Τοποθέτηση pointer στο τέλος του input stream

	
}
int check_numbers(int start,int finish,char str[]){
	/*Βοηθητική συνάρτηση για τον έλεγχο εισόδου
	Δεχεται  ορίσματα το εύρος των επιθυμητών τιμών
	καθώς επίσης και έναν πίνακα χαρακτήρων για
	προβολή του κατάλληλου μηνύματος
	Επιστρέφει τον επιθυμητό αριθμό.*/
	int num;
	do{
		printf("%s",str);
		scanf("%d",&num);
		if (start > num || num> finish){
			printf("\nΟι τιμή που δώσατε δεν είναι αποδεκτή. Προσπαθήστε ξανά.");
		}
		
	}while(start > num || num >finish);
	return num;
}

void total_grade(submission *p){
	/*Υπολογίζει την συνολική αξιολόγηση της εργασίας
	σύμφωνα με τον δοθέντα τύπο.Δέχεται όρισμα έναν δείκτη
	σε δομή τύπου submission.Δεν επιστρέφει τιμή*/
	p->total = (float)((p->first_judge_grade * p->first_judge_relevance) +(p->second_judge_grade * p->second_judge_relevance))/2;
}

float best_submission(submission a[]){
	/*Η συνάρτηση διαπερνά έναν πίνακα από δομές τύπου
	submission και αναζητά και επιστρέφει
	 την μέγιστη συνολική αξιολόγηση*/
	float best = -10;
	int i;
	for(i = 0; i<N;i++){
		if(a[i].total > best) best = a[i].total;
	}
	return best;
}

void set_decision(submission a[],float best_mark){
	/*Η συνάρτηση δέχεται ως ορίσματα έναν πίνακα από
	δομές τύπου submission και έναν αριθμό float που
	αντιπροσωπεύει την μέγιστη αξιολόγηση και διαπερνά κάθε δομή
	του πίνακα θέτοντας στο πεδίο decision το κατάλληλο string.*/
	int i;
	for(i =0;i<N;i++){
		if(a[i].total > AR * best_mark)
		{
			strcpy(a[i].decision, "ΔΕΚΤΗ");
		 } 
		else{
			strcpy(a[i].decision,"ΑΠΟΡΡΙΠΤΕΑ");
		}
	}
}

void print_info(submission a[]){
	/*Η συνάρτηση δέχεται ως ορίσματα έναν πίνακα από
	δομές τύπου submission και προβάλει μορφοποιημένη έξοδο των πεδίων της κάθε δομής.*/
	int i;
	for(i=0;i<N;i++){
		printf("\n\t%d",i+1);
		printf("\t%s",a[i].title);
		printf("\t%.2f",a[i].total);
		printf("\t%s",a[i].decision);
	}
}

bool comparison(float a,float b){
	/* Η συνάρτηση δέχεται δύο αριθμούς float και 
	αν η διαφορά τους είναι μικρότερη από 0.00001 
	επιστρέφει true αλλιώς επιστρέφει false */
	if(a - b < 0.0001) {
	 return true;
	}
	else {
	 return false;
	}
}

void print_best_submissions(submission a[],float best_mark){
		/*Η συνάρτηση δέχεται ως ορίσματα έναν πίνακα από
	δομές τύπου submission και έναν αριθμό float που
	αντιπροσωπεύει την μέγιστη αξιολόγηση και αν η βαθμολογία 
	της εκάστοτε εργασίας είναι ίση με την μέγστη την τυπώνει 
	μορφοποιημένα.*/
	int i;
	printf("\nΚαλύτερη/ες εργασία/ες είναι: ");
	for(i =0;i<N;i++){
		if(comparison(best_mark,a[i].total)) {
	    	printf("\n\t%d\t%s",a[i].a_a,a[i].title);
		}
	}
	
}
