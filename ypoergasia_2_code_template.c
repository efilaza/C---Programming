#include <stdio.h>
#include <stdlib.h>
int N;/* ����������� � ������� ��� ��������� �� ���������� �������� COVID-19 (������ ������� ����������, ����� ����������) */

/* ������� ����� */

typedef struct hospital_admissions  /* ���� ��� ���������� ������ ����������� */
{
	int patient_id; /* ������� �������� */
	int vaccination_status; /* ������������ ������ �������� */
	int number_of_days; /* ������ ��������� */
	int unit; /* ������ ��������� */
	struct hospital_admissions * next;
} hospital_admission;

typedef hospital_admission * pHospital_Admission;

typedef struct admissions  /* ���� ��� ������ ����� ����������� */
{
    int patient_id; /* ������� �������� */
	int vaccination_status; /* ������������ ������ �������� */
    int hospital; /* ������� ����������� �������� */
	int number_of_days; /* ������ ��������� */
	int unit; /* ������ ��������� */
	struct admissions * next;
} admissions;

typedef admissions * pAdmission;

/* ��� ����� �������� ���������� ����������� (AN ������� ���������� �� �������� ��� ���������) */

/* ��������� ��� �� ���������� ��� ��� ���������� ������ ��� ����������� �������� */
void insert(pHospital_Admission *q, int patient_id, int vaccination_status, int number_of_days, int unit)
{
/* � ������� ��� ��� */
}

/* ��������� ����������� ��� ������� ������ �����������, �� ���������� */
void merge(pHospital_Admission q1, pHospital_Admission q2, pAdmission *q)
{
/* � ������� ��� ��� */

}

/* ��������� ��������� ��� ��������� ������� ������ ����������� */
void printcomplete(pAdmission q)
{
	/* � ������� ��� ��� */
}

/* ��������� ��������� ��� ������ ���� ����������� �������� */
void print(pHospital_Admission q1)
{
	/* � ������� ��� ��� */ 
}


int main()
{

	pAdmission q;     /* ������ ����� ����������� */
	pHospital_Admission q1, q2;  /* ������ ��� �� ��������� ���������� �������� */
	int i, patientCode, vaccination, hospitalCode, daysOfStay, hospitalUnit; /* ���������� ��� ����������� ��� ���������� ������� ��� ���� ������ */

    system("chcp 1253>nul"); /* ���������� ��������� ���������� */

/* �������������� */
	q=NULL;
	q1=NULL;
	q2=NULL;
	do
		{
			printf("\n ���� ������ ��������� (>0): ");
			scanf("%d", &N);
    	}
	while (N<=0);

    /* ���������������� � �������� ��� � ������� ��� ��������� ��� */

	for (i=1;i<=N;i++)
    {

		/* � ������� ��� �Ŀ ��� �������� �� �M�N���� �������������� ��� ����� ��� ����������
            patientCode, vaccination, hospitalCode, hospitalUnit */

	/* ���������������� � ����������� ��� ��������� ��� ���������� ���������� �������� */
    	if (hospitalCode==1) insert(&q1, patientCode, vaccination,  daysOfStay, hospitalUnit);
		else insert(&q2, patientCode, vaccination,  daysOfStay, hospitalUnit);
	}


    /* ���������������� � ���������� ��� ������� ������ ����������� �� ����� ��� merge */
    merge(q1, q2, &q);

    /* �������� ������� ������ ����������� */
    printcomplete(q);

    /* ���������� ��� �� ���������� �������� */
	printf("   ��������� ��� ������ ������� \n");
	print(q1);
	printf("   ��������� ��� ����� \n");
	print(q2);


return 0;
}
