// Lazaridou_1.c
// ����� ������������ �����, 
// ��������� ���������������, �����������

#include <stdio.h>
#include <stdbool.h>

//������� ����� Date{}
typedef struct{
	int day;
	int month;
	int year;
}Date;

//������� �����������
Date get_date();
bool is_leap(int year);
bool chkday(Date d);
bool chkmonth(Date d);
bool chkyear(Date d);
int month_days(int month,int year);
void day_of_year(Date d);

//��������� main()
int main(void){
	system("chcp 1253>nul");

	Date date1;
	date1 = get_date();
	day_of_year(date1);
	return 0;
}


//������� �����������
Date  get_date(){
	/*� ��������� ������� ������ ��� ��� ������ ���
	���������� ��� �����������  ��� ����� date */
	int d,m,y;
	Date my_date; //������ ���������� ����� Date

	do {
		printf("\n�������� ����� ��� ����: ");
		scanf("%d",&d);
		printf("�������� ��� ����: ");
		scanf("%d",&m);
		printf("�������� �� ����: ");
		scanf("%d",&y);
		my_date.day = d;
		my_date.month = m;
		my_date.year = y;

  	}while(!(chkmonth(my_date) && chkday(my_date) && chkyear(my_date)));
	return my_date;
}

bool is_leap(int year){
	/*� ��������� ������� �� ������ ���� ������ ��� �������������� ��� ����
	 ��� ���������� �� ����� ������� � ���.
	���������� ���� :1  ��� �������
	���������� ���� :0  ��� ������� */
  if (((year % 4 == 0) && (year % 100!= 0)) || (year %400 == 0)) return true;
  else return false;

}
bool chkday(Date d){
	/*H ��������� ������� �� ������ ��� ���� Date, ��� ������� ��
	� ��������� d.day ����� ���� ���� ������������� ����� */
	int max;
	int month = d.month;
	max = month_days(month, d.year); //����� ��� ���������� month_days ��� ��� �������� ������������� �����.
	if (d.day < 0 || d.day > max){
		printf("%s","� ���� ��� ��� ����� ��� ����� �����!\n");
		return false;
	}
	else return true;

}
bool chkmonth(Date d){
	/*H ��������� ������� �� ������ ��� ���� Date, ��� ������� ��
	� ��������� d.month ����� ���� ���� ������������� ����� */
	if (d.month <=0 || d.month > 12){
		printf("%s","� ���� ��� ��� ���� ��� ����� �����!\n");
 		return false;
	}
	else return true;
}
bool chkyear(Date d){
	/*H ��������� ������� �� ������ ��� ��������� ��� ����� Date,
	��� ������� �� 	� ��������� d.year ����� ���� ���� ������������� ����� */
	if (d.year <=0){
		printf("%s","� ���� ��� �� ���� ��� ����� �����!\n");
		return false;
	}
	else return true;
}
int month_days(int month,int year){
	/*� ��������� ������� ��� ��������
	���� ������� ��� ��� ���� ��� ���� ������� ��� �� ����
	��� ���������� ���� �������	��� �������������� ���
	����� ��� ���� � ������������� �����*/
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
	/*� ��������� ������� �� ������  ��� ��������� ��� ����� Date ���
	���������� ��� ������ ��� ������ ��� ����� �������� ��� ��� ���� ��� �����
	����� ��� ��� ������������� ��� �� ����� ���, ��� ������� ��������� ������.
	��� ���������� ������ ����.*/
	int sum_of_days = 0;
	int rest_of_days;
	int i;
	for(i = 1;i<d.month;i++){
		sum_of_days += month_days(i,d.year);
 	}
	sum_of_days += d.day;
	if(is_leap(d.year))	rest_of_days = 366 - sum_of_days;
	else rest_of_days = 365 - sum_of_days;
	printf("� ����� ��� ����� ����� � %d�, ������������ %d ����� ��� �� ����� ��� ������.",sum_of_days,rest_of_days);

}
