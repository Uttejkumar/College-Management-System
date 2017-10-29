#include "loadlinkedlists.h"
#include "globalvariables.h"
#include "structvariables.h"

#include <time.h>

void addstudent()
{
	clear();

	time_t t;
	time(&t);

	char st[10];
	char sd[10];

	struct node* newnode=(struct node*)malloc(sizeof(struct node));
        struct payment* initializefee=(struct payment*)malloc(sizeof(struct payment));

	FILE* details;
	details = fopen("details.txt","a");

	FILE* payments;
	payments = fopen("payments.txt","a");

	printf("Enter name: ");
	scanf("%s",newnode->name);

	printf("Enter ID: ");
	scanf("%s",newnode->id);

	printf("Enter Branch: ");
	scanf("%s",newnode->branch);

	printf("Enter Password: ");
	scanf("%s",newnode->pass);

	printf("Enter Contact: ");
	scanf("%s",newnode->contact);

        printf("enter year: ");
        fflush(stdin);
        scanf("%d",&newnode->year);
	
	studentrecordnumber++;

	if(first == NULL)
	{
		first = newnode;
		first->next = NULL;
		last = newnode;
	}

	else
	{
		last -> next = newnode;
		last = newnode;
		last -> next = NULL;
	}

	strcpy(initializefee->studentid,newnode->id);
        initializefee->busfees=20000;
        initializefee->libraryfees=5000;
        initializefee->labfees=10000;
        initializefee->examfees=1000;
	strcpy(initializefee->datetime,ctime(&t));
	initializefee->transid = 0;

	if(head == NULL)
	{
		head = initializefee;
		head->next1 = NULL;
		tail = initializefee;
	}

	else
	{
		tail-> next1 = initializefee;
		tail = initializefee;
		tail -> next1 = NULL;
	}

	paymentrecordnumber++;

	fclose(details);
	fclose(payments);

	modifyflag = 1;
}

void modifydata()
{
	clear();

	char ch;
	struct node* key;
	char s_id[10];

	printf("\nEnter student id: ");
	scanf("%s",s_id);

	key=first;
	do
 	{
  		if(strcmp(key->id,s_id)==0)
   			break;

		key = key->next;

 	}while(key!=NULL);

 	if(key==NULL)
	{
		clear();
		printf("\nStudent data not found\n");
		printf("Press enter to continue...");
		scanf("%c",&tempchar);
		return;
	}

	while(1)
	{
		printf("Current Data: \n %s %s %s %s %s %d\n",key->name,key->id,key->branch,key->pass,key->contact,key->year);
 		printf("\nDo you want to modify the above data:y/n\n");

		//fflush(stdin);

		scanf("%c",&tempchar);
		scanf("%c",&ch);

		if(ch=='y')
		{
   			printf("\nUpdate:\n 1.Name\t2.ID\t3.Branch\t4.Password\t5.Contact number\t6.Year\n");
			scanf("%d",&choice);

			switch(choice)
			{
				case 1: scanf("%s",key->name); break;
				case 2: scanf("%s",key->id); break;
				case 3: scanf("%s",key->branch); break;
				case 4: scanf("%s",key->pass); break;
				case 5: scanf("%s",key->contact); break;
				case 6: scanf("%d",&key->year); break;
				default: printf("\nInvalid choice");
			}
		}

 		else
 		{
   			break;
 		}
       	}

	modifyflag = 1;
}

void deletestudent()
{
	struct node* key;
	struct node* prev;
	char ch[10];

	clear();

	printf("\n Delete Record of\nStudent ID: ");
	scanf("%s",ch);

	key=first;

	do
 	{
  		if(strcmp(key->id,ch)==0)
   		break;

		key = key->next;

 	}while(key!=NULL);

 	if(key==NULL)
	{
		clear();
		printf("\nStudent data not found");
		printf("\nPress enter to return...");
		scanf("%c",&tempchar);
		return;
	}

	prev = first;

	if(key == first)
	{
		clear();
		first = key->next;
		
		studentrecordnumber--;
	}
		
	else
	{
		while(prev->next != key)
			prev = prev->next;

		prev->next = key->next;
		studentrecordnumber--;
	}

	modifyflag = 1;

	printf("\nStudent Record with ID %s deleted",ch);
	printf("Press enter to continue...\n");
	scanf("%c",&tempchar);
}

void saveandexit()
{
	updaterecords();

	printf("Called saved and exit");
	scanf("%c",&tempchar);
	scanf("%c",&tempchar);

	//if(modifydata == 1)
	//{
			FILE* fp;
			FILE* pays;

			struct payment* temppay;
			struct node* tempnode;

			pays = fopen("payments.txt","w");
			fp = fopen("details.txt","w");
	
			tempnode = first;

			do
			{
				fprintf(fp, "%s %s %s %s %s %d\n", tempnode->name,tempnode->id,tempnode->branch,tempnode->pass,tempnode->contact,tempnode->year);

				tempnode = tempnode->next;
			}while(tempnode!=NULL);

        		printf("\n Student data modified...");

			temppay = head;

			do
			{
				fprintf(pays, "%s %d %d %d %d %s %d\n", temppay->studentid,temppay->busfees,temppay->libraryfees,temppay->labfees,temppay->examfees,temppay->datetime,temppay->transid);

					temppay = temppay->next1;
			}while(temppay!=NULL);

	      		printf("\n Payment data modified... ");
			printf("Press enter to continue...");
			scanf("%c",&tempchar);	
	//}
}

void updaterecords()
{
	FILE* records;
	records = fopen("recordcount.txt","w");

	fprintf(records, "%d %d %d", studentrecordnumber, paymentrecordnumber, trans);

	fclose(records);
}

void displaystudentdetails()
{
	int insertpos = 0;	
	char readchar;
				
	struct node* temp;			
	struct payment* pays;

	temp = first;
	pays = head;

    	printf("\nCURRENT DATA\n");
	printf("Student Data\n");

	while(temp!=NULL)
	{

		printf("Name: %s ID: %s Branch:%s Password: %s Contact: %s Year: %d\n", temp->name,temp->id,temp->branch,temp->pass,temp->contact,temp->year);
		temp = temp -> next;
	}

	printf("\n\npayment data:\n\n");
	
	while(pays!=NULL)
	{
		printf("ID: %s Bus: %d Library: %d Lab:%d Exam:%d DateTime:%s\n", pays->studentid,pays->busfees,pays->libraryfees,pays->labfees,pays->examfees,pays->datetime);	
		pays = pays->next1;
	}

	printf("\n\n\nPress enter to continue...");
	scanf("%c",&tempchar);
	scanf("%c",&tempchar);
}

void searchstudent()
{
        int yr;
	//char ch,ch1;
	struct node* key;
	char s_branch[10],s_id[10];

	Reperformsearch:

        printf("\nHow do u want to perform search: \n1.Branchwise\n2.year wise\n3.branch&year wise \n4.RollNo wise\n");
        scanf("%d",&choice);

        switch(choice)
	{
	  	case 1:
		{
		  printf("\n student info branch wise");

	          printf("\nenter student branch: ");
	          scanf("%s",s_branch);

	          key=first;
		  do
	       	  {
	  		if(strcmp(key->branch,s_branch)==0)
   			display_node(key);

			key = key->next;

		 	}while(key!=NULL);

		 	break;
         	 }
		 
		 case 2:
		 {
			printf("\nEnter the year");
                 	scanf("%d",&yr);

			key=first;

			do
			{
				if(key->year==yr)
					display_node(key);

				key=key->next;
			 }while(key!=NULL);

			        break;
			}
		case 3:
			{
				printf("Enter branch and year: ");
				scanf("%s%d",s_branch,&yr);
				key=first;

				if(key == NULL)
				{
					printf("No data to search\n");
				}

				else
				{
					while(key != NULL)
					{
						if( strcmp(key->branch,s_branch) == 0 && (key->year == yr) )
							display_node(key);
						key = key->next;
					}
				}
				break;
			}
		case 4:
			{
				printf("\nenter student id: ");
				scanf("%s",s_id);

				key=first;
				do
			 	{
			  		if(strcmp(key->id,s_id)==0)
					{	display_node(key);
						break;
					}

					key = key->next;

			 	}while(key!=NULL);
			break;
			}

		default:
			printf("invalid choice\n");
			goto Reperformsearch;
	}
	printf("\n\nPress enter to continue...");
	scanf("%c",&tempchar);
	scanf("%c",&tempchar);
}

void display_node(struct node* key)
{
	if(key == NULL)
	{
		printf("No record with given data exists\n");
	}
	else
	{
		printf("Name: %s\t ID:%s Branch:%s \tYear:%d \tContact:%s\n", key->name, key->id, key->branch, key->year,key->contact);
	}
	scanf("%c",&tempchar);

}

void studentmanagement()
{
	clear();

	if(stu_loadstatus == 0){
		loadstudentLL();
		stu_loadstatus = 1;
	}
	if(pay_loadstatus == 0){
		loadpaymentLL();
		pay_loadstatus = 1;	
	}

	while(1)
	{
		clear();

		printf("\t\t----------STUDENT MANAGEMENT----------\n");
		printf("\t\t\t1. ADD STUDENT\n");
		printf("\t\t\t2. MODIFY STUDENT DATA\n");
		printf("\t\t\t3. DELETE STUDENT DATA\n");
		printf("\t\t\t4. DISPLAY EXISTING DATA\n");
		printf("\t\t\t5. SEARCH EXISTING DATA\n");
		printf("\t\t\t6. SAVE AND EXIT\n");
		printf("\t\t\t7. EXIT\n");

		scanf("%d",&choice);
	
		switch(choice)
		{
			case 1: 
				addstudent();
				break;
			case 2:
				modifydata();
				break;
			case 3: 
				deletestudent();
				break;
			case 4:
				displaystudentdetails();
				break;
			case 5:
				searchstudent();
				break;
			case 6: 
				saveandexit();
				return;
			case 7:	
				return;
			default:
				printf("\nInvalid choice. Press enter to retry...");
				scanf("%c",&tempchar);
				studentmanagement();
				break;
		}
	}
}




