// Lazaridou_1.c
// Απλές αλγοριθμικές δομές, 
// αμυντικός προγραμματισμός, συναρτήσεις

#include <stdio.h>
#include <stdbool.h>

//Ορισμός δομής Date{}
typedef struct{
	int day;
	int month;
	int year;
}Date;

//Πρότυπα συναρτήσεων
Date get_date();
bool is_leap(int year);
bool chkday(Date d);
bool chkmonth(Date d);
bool chkyear(Date d);
int month_days(int month,int year);
void day_of_year(Date d);

//Συνάρτηση main()
int main(void){
	system("chcp 1253>nul");

	Date date1;
	date1 = get_date();
	day_of_year(date1);
	return 0;
}


//Ορισμός Συναρτήσεων
Date  get_date(){
	/*Η συνάρτηση παίρνει είσοδο από τον χρήστη και
	επιστρέφει ένα αντικείμενο  της δομής date */
	int d,m,y;
	Date my_date; //Δήλωση μεταβλητής τύπου Date

	do {
		printf("\nΕισάγετε ημέρα του μήνα: ");
		scanf("%d",&d);
		printf("Εισάγετε τον μήνα: ");
		scanf("%d",&m);
		printf("Εισάγετε το έτος: ");
		scanf("%d",&y);
		my_date.day = d;
		my_date.month = m;
		my_date.year = y;

  	}while(!(chkmonth(my_date) && chkday(my_date) && chkyear(my_date)));
	return my_date;
}

bool is_leap(int year){
	/*Η συνάρτηση δέχεται ως όρισμα έναν αριθμό που αντιπροσωπεύει ένα έτος
	 και υπολογίζει αν είναι δίσεκτο ή όχι.
	Επιστρέφει τιμή :1  για δίσεκτο
	Επιστρέφει τιμή :0  όχι δίσεκτο */
  if (((year % 4 == 0) && (year % 100!= 0)) || (year %400 == 0)) return true;
  else return false;

}
bool chkday(Date d){
	/*H συνάρτηση δέχεται ως όρισμα μία δομή Date, και ελέγχει αν
	η μεταβλητή d.day είναι μέσα στις επιτρεπόμενες τιμές */
	int max;
	int month = d.month;
	max = month_days(month, d.year); //κλήση της συνάρτησης month_days για τις μέγιστες επιτρεπόμενες μέρες.
	if (d.day < 0 || d.day > max){
		printf("%s","Η τιμή για την ημέρα δεν είναι σωστή!\n");
		return false;
	}
	else return true;

}
bool chkmonth(Date d){
	/*H συνάρτηση δέχεται ως όρισμα μία δομή Date, και ελέγχει αν
	η μεταβλητή d.month είναι μέσα στις επιτρεπόμενες τιμές */
	if (d.month <=0 || d.month > 12){
		printf("%s","Η τιμή για τον μήνα δεν είναι σωστή!\n");
 		return false;
	}
	else return true;
}
bool chkyear(Date d){
	/*H συνάρτηση δέχεται ως όρισμα μία μεταβλητή της δομής Date,
	και ελέγχει αν 	η μεταβλητή d.year είναι μέσα στις επιτρεπόμενες τιμές */
	if (d.year <=0){
		printf("%s","Η τιμή για το έτος δεν είναι σωστή!\n");
		return false;
	}
	else return true;
}
int month_days(int month,int year){
	/*Η συνάρτηση δέχεται δύο ορίσματα
	έναν ακέραιο για τον μήνα και έναν ακέραιο για το έτος
	και επιστρέφει έναν ακέραιο	που αντιπροσωπεύει τις
	μέρες που έχει ο συγκεκριμένος μήνας*/
	switch(month){
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			return  31;
			break;
		case 2:
			if (is_leap(year)) return 29;
			else return 28;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			return 30;
			break;
	}
}
void day_of_year(Date d){
	/*Η συνάρτηση δέχεται ως όρισμα  μια μεταβλητή της δομής Date και
	υπολογίζει των αριθμό των ημερών που έχουν παρέλθει από την αρχή του έτους
	καθώς και τις υπολειπόμενες για το τέλος του, και τυπώνει κατάλληλο μήνυμα.
	Δεν επιστρέφει κάποια τιμή.*/
	int sum_of_days = 0;
	int rest_of_days;
	int i;
	for(i = 1;i<d.month;i++){
		sum_of_days += month_days(i,d.year);
 	}
	sum_of_days += d.day;
	if(is_leap(d.year))	rest_of_days = 366 - sum_of_days;
	else rest_of_days = 365 - sum_of_days;
	printf("Η ημέρα του έτους είναι η %dη, υπολείπονται %d μέρες για το τέλος του χρόνου.",sum_of_days,rest_of_days);

}
