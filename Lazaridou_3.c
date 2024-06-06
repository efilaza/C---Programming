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

/* ������� ����������� */
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
		printf("\n�������� ���������� ��������: %.2f\n",array[i].total);
	}
	best_mark = best_submission(array);
	printf("� ��������� �������� �������� ����� %.2f",best_mark);
	for (i=0;i<N;i++){
		set_decision(&array[i],best_mark);
	}
	print_info(array);
	print_best_submissions(array,best_mark);

 }

void fill_submission(submission *p){
	/*� ��������� ������� �� ������ ���� ������
	�� ���� submission ��� ������� �� ����� ��� �����
	�� ������ ��� ��� ������. ��� ���������� ����*/
	static int serial = 0;
	char message[40];
	serial +=1;
    p->a_a = serial;
  	printf("%s","���� ��� ����� ��� ��������:");
	gets(p->title);
 	strcpy(message, "\n����� ��� �������� ��� 1�� �����. �� ��������� ����� ����� ��� -3 ��� 3:");
	p->first_judge_relevance = check_numbers(-3,3,message);
	strcpy(message, "\n����� ��� ����� ��� 1�� �����. �� ��������� ����� ����� 0,1,2 � 3: ");
	p->first_judge_grade = check_numbers(0,3,message);
	strcpy(message, "\n����� ��� �������� ��� 2�� �����. �� ��������� ����� ����� ��� -3 ��� 3:");
	p->second_judge_relevance = check_numbers(-3,3,message);
	strcpy(message, "\n����� ��� ����� ��� 2�� �����. �� ��������� ����� ����� 0,1,2 � 3: ");
	p->second_judge_grade = check_numbers(0,3,message);
	total_grade(p);
	fseek(stdin,0,SEEK_END);//���������� pointer ��� ����� ��� input stream

	
}
int check_numbers(int start,int finish,char str[]){
	/*��������� ��������� ��� ��� ������ �������
	�������  �������� �� ����� ��� ���������� �����
	����� ������ ��� ���� ������ ���������� ���
	������� ��� ���������� ���������
	���������� ��� ��������� ������.*/
	int num;
	do{
		printf("%s",str);
		scanf("%d",&num);
		if (start > num || num> finish){
			printf("\n�� ���� ��� ������ ��� ����� ��������. ����������� ����.");
		}
		
	}while(start > num || num >finish);
	return num;
}

void total_grade(submission *p){
	/*���������� ��� �������� ���������� ��� ��������
	������� �� ��� ������� ����.������� ������ ���� ������
	�� ���� ����� submission.��� ���������� ����*/
	p->total = (float)((p->first_judge_grade * p->first_judge_relevance) +(p->second_judge_grade * p->second_judge_relevance))/2;
}

float best_submission(submission a[]){
	/*� ��������� �������� ���� ������ ��� ����� �����
	submission ��� ������� ��� ����������
	 ��� ������� �������� ����������*/
	float best = -10;
	int i;
	for(i = 0; i<N;i++){
		if(a[i].total > best) best = a[i].total;
	}
	return best;
}

void set_decision(submission a[],float best_mark){
	/*� ��������� ������� �� �������� ���� ������ ���
	����� ����� submission ��� ���� ������ float ���
	�������������� ��� ������� ���������� ��� �������� ���� ����
	��� ������ �������� ��� ����� decision �� ��������� string.*/
	int i;
	for(i =0;i<N;i++){
		if(a[i].total > AR * best_mark)
		{
			strcpy(a[i].decision, "�����");
		 } 
		else{
			strcpy(a[i].decision,"����������");
		}
	}
}

void print_info(submission a[]){
	/*� ��������� ������� �� �������� ���� ������ ���
	����� ����� submission ��� �������� ������������� ����� ��� ������ ��� ���� �����.*/
	int i;
	for(i=0;i<N;i++){
		printf("\n\t%d",i+1);
		printf("\t%s",a[i].title);
		printf("\t%.2f",a[i].total);
		printf("\t%s",a[i].decision);
	}
}

bool comparison(float a,float b){
	/* � ��������� ������� ��� �������� float ��� 
	�� � ������� ���� ����� ��������� ��� 0.00001 
	���������� true ������ ���������� false */
	if(a - b < 0.0001) {
	 return true;
	}
	else {
	 return false;
	}
}

void print_best_submissions(submission a[],float best_mark){
		/*� ��������� ������� �� �������� ���� ������ ���
	����� ����� submission ��� ���� ������ float ���
	�������������� ��� ������� ���������� ��� �� � ���������� 
	��� �������� �������� ����� ��� �� ��� ������ ��� ������� 
	�������������.*/
	int i;
	printf("\n��������/�� �������/�� �����: ");
	for(i =0;i<N;i++){
		if(comparison(best_mark,a[i].total)) {
	    	printf("\n\t%d\t%s",a[i].a_a,a[i].title);
		}
	}
	
}
