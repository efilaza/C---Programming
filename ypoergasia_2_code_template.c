#include <stdio.h>
#include <stdlib.h>
int N;/* Καθορίζεται ο αριθμός των εισαγωγών σε νοσοκομεία αναφοράς COVID-19 (Γενικό Κρατικό Νοσοκομείο, Λαϊκό Νοσοκομείο) */

/* Ορισμοί δομών */

typedef struct hospital_admissions  /* δομή για ξεχωριστές λίστες νοσοκομείων */
{
	int patient_id; /* κωδικός ασθενούς */
	int vaccination_status; /* εμβολιαστική κάλυψη ασθενούς */
	int number_of_days; /* ημέρες νοσηλείας */
	int unit; /* μονάδα νοσηλείας */
	struct hospital_admissions * next;
} hospital_admission;

typedef hospital_admission * pHospital_Admission;

typedef struct admissions  /* δομή για ενιαία λίστα νοσοκομείων */
{
    int patient_id; /* κωδικός ασθενούς */
	int vaccination_status; /* εμβολιαστική κάλυψη ασθενούς */
    int hospital; /* κωδικός νοσοκομείου αναφοράς */
	int number_of_days; /* ημέρες νοσηλείας */
	int unit; /* μονάδα νοσηλείας */
	struct admissions * next;
} admissions;

typedef admissions * pAdmission;

/* ΕΔΩ ΒΑΛΤΕ ΟΡΙΣΜΟΥΣ ΒΟΗΘΗΤΙΚΩΝ ΣΥΝΑΡΤΗΣΕΩΝ (AN ΚΡΙΝΕΤΕ ΑΠΑΡΑΙΤΗΤΟ ΝΑ ΥΠΑΡΧΟΥΝ ΣΤΟ ΠΡΟΓΡΑΜΜΑ) */

/* συνάρτηση για τη δημιουργία και την ταξινόμηση λιστών των νοσοκομείων αναφοράς */
void insert(pHospital_Admission *q, int patient_id, int vaccination_status, int number_of_days, int unit)
{
/* Ο ΚΩΔΙΚΑΣ ΣΑΣ ΕΔΩ */
}

/* συνάρτηση δημιουργίας της ενιαίας λίστας νοσοκομείων, με συγχώνευση */
void merge(pHospital_Admission q1, pHospital_Admission q2, pAdmission *q)
{
/* Ο ΚΩΔΙΚΑΣ ΣΑΣ ΕΔΩ */

}

/* συνάρτηση εκτύπωσης της συνολικής ενιαίας λίστας νοσοκομείων */
void printcomplete(pAdmission q)
{
	/* Ο ΚΩΔΙΚΑΣ ΣΑΣ ΕΔΩ */
}

/* συνάρτηση εκτύπωσης της λίστας ενός νοσοκομείου αναφοράς */
void print(pHospital_Admission q1)
{
	/* Ο ΚΩΔΙΚΑΣ ΣΑΣ ΕΔΩ */ 
}


int main()
{

	pAdmission q;     /* ενιαία λίστα νοσοκομείων */
	pHospital_Admission q1, q2;  /* λίστες για τα ξεχωριστά νοσοκομεία αναφοράς */
	int i, patientCode, vaccination, hospitalCode, daysOfStay, hospitalUnit; /* μεταβλητές που αποθηκεύουν την πληροφορία εισόδου για κάθε ασθενή */

    system("chcp 1253>nul"); /* υποστήριξη ελληνικών χαρακτήρων */

/* αρχικοποιήσεις */
	q=NULL;
	q1=NULL;
	q2=NULL;
	do
		{
			printf("\n Δώσε πλήθος εισαγωγών (>0): ");
			scanf("%d", &N);
    	}
	while (N<=0);

    /* πραγματοποιείται η εισαγωγή και ο έλεγχος των δεδομένων μας */

	for (i=1;i<=N;i++)
    {

		/* Ο ΚΩΔΙΚΑΣ ΣΑΣ ΕΔΏ ΓΙΑ ΕΙΣΑΓΩΓΗ ΜΕ ΑMΥNΤΙΚΟ ΠΡΟΓΡΑΜΜΑΤΙΣΜΟ ΤΩΝ ΤΙΜΩΝ ΤΩΝ ΜΕΤΑΒΛΗΤΩΝ
            patientCode, vaccination, hospitalCode, hospitalUnit */

	/* πραγματοποιείται ο διαχωρισμός των εισαγωγών στα αντίστοιχα νοσοκομεία αναφοράς */
    	if (hospitalCode==1) insert(&q1, patientCode, vaccination,  daysOfStay, hospitalUnit);
		else insert(&q2, patientCode, vaccination,  daysOfStay, hospitalUnit);
	}


    /* πραγματοποιείται η δημιουργία της ενιαίας λίστας νοσοκομείων με κλήση της merge */
    merge(q1, q2, &q);

    /* εκτύπωση ενιαίας λίστας νοσοκομείων */
    printcomplete(q);

    /* εκτυπώσεις για τα νοσοκομεία αναφοράς */
	printf("   Εισαγωγές στο ΓΕΝΙΚΟ ΚΡΑΤΙΚΟ \n");
	print(q1);
	printf("   Εισαγωγές στο ΛΑΪΚΟ \n");
	print(q2);


return 0;
}
