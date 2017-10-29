#ifndef LOADLINKEDLISTS_H_
#define LOADLINKEDLISTS_H_

#include "structvariables.h"

void loadrecordcount()
{
	FILE* records;
	records = fopen("recordcount.txt","r");
	if(records == NULL)
	{
		studentrecordnumber = 0;
		paymentrecordnumber = 0;
		trans = 0;
	}
	else
	{
		fscanf(records, "%d", &studentrecordnumber);
		fscanf(records, "%d", &paymentrecordnumber);
		fscanf(records, "%d", &trans);
	}
	fclose(records);
}

void loadstudentLL()
{
	//printf("Inside LOAD STUDENT");
	loadrecordcount();
	
	int linecount = 0;
	struct node* newnode;
	FILE* fp;
	
	fp = fopen("details.txt","r");
	if(fp == NULL)
	{
		last = NULL;
	}
	else
	{
		//printf("Loading student details...\n");
		//sleep(1);
		while(linecount < studentrecordnumber)
		{
			newnode = (struct node*)malloc(sizeof(struct node));

			fscanf(fp, "%s", newnode->name);
			//printf("Taking name: %s\n", newnode->name);
			fscanf(fp, "%s", newnode->id);
			//printf("Taking ID: %s\n", newnode->id);
			fscanf(fp, "%s", newnode->branch);
			//printf("Taking branch: %s\n", newnode->branch);
			fscanf(fp, "%s", newnode->pass);
			//printf("Taking password: %s\n", newnode->pass);
			fscanf(fp, "%s", newnode->contact);
			//printf("Taking contact: %s\n", newnode->contact);
 			fscanf(fp, "%d", &newnode->year);
			//printf("Taking year: %d\n", newnode->year);
	
			linecount++;

			newnode -> next = NULL;

			if(first == NULL)
			{
				first = newnode;
				last = newnode;
			}

			else
			{
				last -> next = newnode;
				last = newnode;
			}
		}
	}
	fclose(fp);	
	//printf("Student LL Loaded...");
}

void loadpaymentLL()
{

	loadrecordcount();

	int linecount = 0;
	int insertpos;
	char readchar;
	
	FILE* pay;
	struct payment* newpay;
	struct payment* temp;

	pay = fopen("payments.txt","r");

		if(pay == NULL)
		{	
			//head = NULL;
			tail = NULL;
			//printf("\nZero payments made till date\n");
			//return;
		}
		
		else
		{
		    //printf("Loading payment details...\n");	
                    //sleep(1);
		    while(linecount < paymentrecordnumber)
			{
				newpay = (struct payment*)malloc(sizeof(struct payment));

				fscanf(pay, "%s", newpay->studentid);
				//printf("\nPayment loaded with ID: %s", newpay->studentid);
				fscanf(pay, "%d", &newpay->busfees);	
				//printf("\nBus fee: %d", newpay->busfees);
				fscanf(pay, "%d", &newpay->libraryfees);
				//printf("\nLibrary fee: %d", newpay->libraryfees);
				fscanf(pay, "%d", &newpay->labfees);
				//printf("\nLab fee: %d",newpay->labfees);
				fscanf(pay, "%d", &newpay->examfees);
				//printf("\nExam Fee: %d", newpay->examfees);
				
				insertpos = 0;
				
				while(1)
				{
					readchar = fgetc(pay);
					if(readchar == '\n' || readchar == EOF)
						break;
					newpay->datetime[insertpos] = readchar;
					insertpos++;
				}

				newpay->datetime[insertpos] = '\0';

				//printf("\nDate and Time: %s", newpay->datetime);
				fscanf(pay, "%d", &newpay->transid);
				
				linecount++;

				newpay -> next1 = NULL;
 		
				if(head == NULL)
				{
					head = newpay;
					tail = newpay;
				}

				else
				{
					tail -> next1 = newpay;
					tail = newpay;
				}
			}
		}
	fclose(pay);
        //printf("Payment details loaded...\n");

	printf("Displaying Payment LL:\n\n");
	temp = head;
	while(temp!=NULL)
	{
		printf(" %s %d %d %d %d\n",temp->studentid,temp->busfees,temp->libraryfees,temp->labfees,temp->examfees);
		temp = temp -> next1;
	}
	
	printf("Press enter to continue...");
	scanf("%c",&tempchar);
	scanf("%c",&tempchar);

}

#endif

	
