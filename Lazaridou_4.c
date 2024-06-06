#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 15


/*Ορισμός δομής data */
struct data{
	int AM;
	char OE[NAME_LEN];
	int XS;
};

typedef struct data member_data ;          

/*Ορισμός Κόμβου Λίστας */
struct node{
   member_data  data; 			   
   struct node *next;      
};

typedef struct node Node;  // Ονομασία κόμβου
typedef struct node *ptr; // Ονομασία δείκτη στον Κόμβο

/*Πρότυπα Συναρτήσεων */

void initialize_list(ptr *head);
int check_debt();
void insert_member(ptr *head,int x);
void display_list(ptr head);
void reduce_debt(ptr *head);
void free_memory(ptr *head);


int main(void){
	system("chcp 1253>nul");
	int am = 1;
	ptr list;
	int choice;
	
	initialize_list(&list);
	
	do{
		printf("MENU\n");
		printf("1. Εισαγωγή νέου μέλους.\n");
		printf("2. Εμφάνιση στοιχείων μελών.\n");
		printf("3. Πληρωμή συνδρομής\n");
		printf("4. Έξοδος.\n");
		printf("Εισάγετε επιλογή: ");
		scanf("%d", &choice);
		getchar();

		switch(choice)
		{
			case 1:
				insert_member(&list, am);
				am +=1;
				printf("Η εισαγωγή μέλους έγινε.\n\n");
				break;
			case 2:
  				display_list(list);
				printf("\n\n");
				break;
   			case 3:
				 reduce_debt(&list);
				 break;
			case 4:
				printf("Επιλέξατε έξοδο από το πρόγραμμα");
				free_memory(&list);
				exit(0);
		}
	  	printf("\n");
	}while(choice!=4);
}

void initialize_list(ptr *head){
	//Αρχικοποίηση της λίστας 
	*head=NULL;
}


int check_debt(){
	/*Έλεγχος του εισαόμενου ποσού με αμυντικό προγραμματισμό */
	int num;
	do{
		printf("Παρακαλώ εισάγετε χρέος προς το σύλλογο (θετικός αριθμός): ");
		scanf("%d",&num);
	}while(num<0);
	return num;
}

void insert_member(ptr *head,int am){
	/*Συνάρτηση εισαγωγής νέου κόμβου στην αρχή της λίστας
	Παίρνει όρισμα έναν δείκτη σε δείκτη κόμβου, και ένα integer */

	member_data member;
	ptr newnode;

	newnode=(ptr)malloc(sizeof(Node)); //Node *
	if (!newnode)
	{
		printf("Αποτυχία δέσμευσης μνήμης");
		exit(0);
	}
	member.AM = am;
	printf("Παρακαλώ εισάγετε Ονοματεπώνυμο (έως 14 χαρακτήρες): ");
	gets(member.OE);
	fseek(stdin,0,SEEK_END);
	member.XS = check_debt();
	newnode->data=member;
	newnode->next=*head;
	*head=newnode;

}

void display_list(ptr head){
	/*Συνάρτηση διαπέρασης της λίστας και εμφάνισης των πεδίων των μελών
	Παίρνει όρισμα έναν δείκτη σε κόμβο */
	ptr p;

	p = head;
	if(p == NULL){
		puts("Δεν υπάρχουν εγγεγραμμένα μέλη.");
	}
	while(p!=NULL)
	{
		printf("%d\t\t%s\t\t%d\n",p->data.AM,p->data.OE, p->data.XS);
		p=p->next;
	}
}
void reduce_debt(ptr *head){
	/*Η συνάρτηση παίρνει όρισμα έναν δείκτη σε δείκτη κόμβου 
	και ζητά απο τον χρήστη το πόσό πληρωμής της συνδρομής του μέλους
	και το αφαιρεί από το αντίστοιχο πεδίο */
	ptr p;
	p = *head;
	int num;
	int choice;
	printf("Παρακαλώ εισάγετε ΑΜ μέλους: ");
	scanf("%d",&choice);
	while(1){
		if (p->data.AM == choice){
			do{
				printf("Παρακαλώ εισάγετε θετικό ποσό πληρωμής μικρότερο ή ίσο του 30: ");
				scanf("%d",&num);
			}while(num<0 || num > 30 || num > p->data.XS);
			p->data.XS = p->data.XS - num;
			printf("\nΗ πληρωμή έγινε\n");
			break;
		}
		p = p->next;
		if (p == NULL){
			 printf("\nΟ αριθμός μητρώου που εισάγατε δεν υπάρχει. Προσπαθήστε ξανά.");
			 break;
		}
		
	}

}

void free_memory(ptr *head){
	/*Απελευθερώνει την μνήμη που δευσμέυτηκε με malloc() */
	ptr p;
	while (*head!=NULL)
	{
		p=*head;
		*head=(*head)->next;
		free(p);
	}
}

