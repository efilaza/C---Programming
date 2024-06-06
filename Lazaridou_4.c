#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 15


/*������� ����� data */
struct data{
	int AM;
	char OE[NAME_LEN];
	int XS;
};

typedef struct data member_data ;          

/*������� ������ ������ */
struct node{
   member_data  data; 			   
   struct node *next;      
};

typedef struct node Node;  // �������� ������
typedef struct node *ptr; // �������� ������ ���� �����

/*������� ����������� */

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
		printf("1. �������� ���� ������.\n");
		printf("2. �������� ��������� �����.\n");
		printf("3. ������� ���������\n");
		printf("4. ������.\n");
		printf("�������� �������: ");
		scanf("%d", &choice);
		getchar();

		switch(choice)
		{
			case 1:
				insert_member(&list, am);
				am +=1;
				printf("� �������� ������ �����.\n\n");
				break;
			case 2:
  				display_list(list);
				printf("\n\n");
				break;
   			case 3:
				 reduce_debt(&list);
				 break;
			case 4:
				printf("��������� ����� ��� �� ���������");
				free_memory(&list);
				exit(0);
		}
	  	printf("\n");
	}while(choice!=4);
}

void initialize_list(ptr *head){
	//������������ ��� ������ 
	*head=NULL;
}


int check_debt(){
	/*������� ��� ���������� ����� �� �������� �������������� */
	int num;
	do{
		printf("�������� �������� ����� ���� �� ������� (������� �������): ");
		scanf("%d",&num);
	}while(num<0);
	return num;
}

void insert_member(ptr *head,int am){
	/*��������� ��������� ���� ������ ���� ���� ��� ������
	������� ������ ���� ������ �� ������ ������, ��� ��� integer */

	member_data member;
	ptr newnode;

	newnode=(ptr)malloc(sizeof(Node)); //Node *
	if (!newnode)
	{
		printf("�������� ��������� ������");
		exit(0);
	}
	member.AM = am;
	printf("�������� �������� ������������� (��� 14 ����������): ");
	gets(member.OE);
	fseek(stdin,0,SEEK_END);
	member.XS = check_debt();
	newnode->data=member;
	newnode->next=*head;
	*head=newnode;

}

void display_list(ptr head){
	/*��������� ���������� ��� ������ ��� ��������� ��� ������ ��� �����
	������� ������ ���� ������ �� ����� */
	ptr p;

	p = head;
	if(p == NULL){
		puts("��� �������� ������������ ����.");
	}
	while(p!=NULL)
	{
		printf("%d\t\t%s\t\t%d\n",p->data.AM,p->data.OE, p->data.XS);
		p=p->next;
	}
}
void reduce_debt(ptr *head){
	/*� ��������� ������� ������ ���� ������ �� ������ ������ 
	��� ���� ��� ��� ������ �� ���� �������� ��� ��������� ��� ������
	��� �� ������� ��� �� ���������� ����� */
	ptr p;
	p = *head;
	int num;
	int choice;
	printf("�������� �������� �� ������: ");
	scanf("%d",&choice);
	while(1){
		if (p->data.AM == choice){
			do{
				printf("�������� �������� ������ ���� �������� ��������� � ��� ��� 30: ");
				scanf("%d",&num);
			}while(num<0 || num > 30 || num > p->data.XS);
			p->data.XS = p->data.XS - num;
			printf("\n� ������� �����\n");
			break;
		}
		p = p->next;
		if (p == NULL){
			 printf("\n� ������� ������� ��� �������� ��� �������. ����������� ����.");
			 break;
		}
		
	}

}

void free_memory(ptr *head){
	/*������������� ��� ����� ��� ����������� �� malloc() */
	ptr p;
	while (*head!=NULL)
	{
		p=*head;
		*head=(*head)->next;
		free(p);
	}
}

