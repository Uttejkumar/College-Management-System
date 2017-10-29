#ifndef STRUCTVARIABLES_H_
#define STRUCTVARIABLES_H_

struct node
{
	char name[10];
	char id[10];
	char branch[10];
	char pass[10];
	char contact[10];
   	int year;
	struct node *next;
};

struct payment
{
	char studentid[10];
	int busfees;
	int libraryfees;
	int labfees;
	int examfees;
	char datetime[30];
	int transid;
	struct payment* next1;
};

struct payment* head = NULL;
struct payment* tail;

struct node* first = NULL;
struct node* last;

#endif 
