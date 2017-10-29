#include "globalvariables.h"
#include "structvariables.h"
#include "loadlinkedlists.h"

void makepayment()
{
      int ch;
      int detectflag = 0;
      int bf,libf,lf,ef;
      FILE* fp;

      time_t t;
      time(&t);
 
      struct payment* key;
      struct payment* lastupdated;
      struct payment* p2=(struct payment*)malloc(sizeof(struct payment));
 
      char s_id[10];
      fp=fopen("payments.txt","a");

      clear();
	
      printf("\nEnter Student ID: ");
      scanf("%s",s_id);
	
      key=head;

	do
 	{
  		if(strcmp(key->studentid,s_id)==0)
   		{
		       	 p2->examfees=key->examfees;
			 strcpy(p2->studentid,key->studentid);
                         p2->busfees=key->busfees;
			 p2->libraryfees=key->libraryfees;
          		 p2->labfees=key->labfees;
		         p2->examfees=key->examfees;
			lastupdated = key;
			 detectflag = 1;

		}

            key=key->next1;

        }while(key->next1!=NULL);
      
        if(detectflag == 0)
        {
		printf("student not found");
                return;
        }
        
	clear();
 
	printf("\nPay\n\t1.Bus Fees\n\t2.Library Fees\n\t3.Laboratory Fees\n\t4.Exam Fees\n");
        scanf("%d",&ch);
	printf("Enter amount: ");
			switch(ch)
			{
				case 1:{
						++trans;
						paymentrecordnumber++;
						scanf("%d",&bf);
                                                p2->busfees=p2->busfees-bf;	
						lastupdated-> busfees = lastupdated ->busfees - bf;			
						p2->transid=trans;
					  	break;
				       }

				case 2:{
                                       		++trans;
						paymentrecordnumber++;
						scanf("%d",&libf);
                                                p2->libraryfees=p2->libraryfees-libf;	
						lastupdated-> libraryfees = lastupdated ->libraryfees - libf;		
						p2->transid=trans;
					  	break;
                                       }

				case 3:{
						++trans;
						paymentrecordnumber++;
						scanf("%d",&lf);
						p2->labfees=p2->labfees-lf;	
						lastupdated-> labfees = lastupdated ->labfees - lf;			
					        p2->transid=trans;
						break;
                                       }

				case 4:{
					        ++trans;
						paymentrecordnumber++;
						scanf("%d",&ef);
					        p2->examfees=p2->examfees - ef;	
						lastupdated-> examfees = lastupdated ->examfees - ef;					
						p2->transid=trans;
					  	break;
                                       }
                                default: 
						clear();
						printf("Invalid Choice. Press enter to continue...");
                                          	break;

				

			}

     strcpy(p2->datetime,ctime(&t));
      
     fprintf(fp,"\n%s %d %d %d %d %s %d",p2->studentid,p2->busfees,p2->libraryfees,p2->labfees,p2->examfees,p2->datetime, p2->transid);	

     updaterecords();

     fclose(fp);	
}

void viewhistory()
{
	char id[10];
	struct payment* key;
	clear();
	printf("View Transaction History\n\t1. Of Student With ID: \n\t2. With Transaction ID: \n\t3. Made On Date\n");
	scanf("%d",&choice);
	clear();

	switch(choice)
	{
		case(1):
			{
				printf("Enter ID: ");
				scanf("%s",id);
			
				key = head;

				do{
					if( strcmp(key->studentid,id) == 0)
						printf("\nID: %s BusFees:%d LibraryFees:%d LabFees:%d ExamFees:%d\n Made on:%s TransactionID:%d\n",key->studentid,key->busfees,key->libraryfees,key->labfees,key->examfees,key->datetime,key->transid);
					key = key->next1;
				  }while(key!=NULL);
				break;
			}

		case(2):
			{
				printf("Enter transaction ID: ");
				scanf("%d",&choice);
		
				key = head;

				do
				{

					if(key->transid == choice && key->transid == 0)
						printf("\nID: %s BusFees:%d LibraryFees:%d LabFees:%d ExamFees:%d\n Made on:%s TransactionID:%d\n",key->studentid,key->busfees,key->libraryfees,key->labfees,key->examfees,key->datetime,key->transid);

					else if(key->transid == choice){
						printf("\nID: %s BusFees:%d LibraryFees:%d LabFees:%d ExamFees:%d\n Made on:%s TransactionID:%d\n",key->studentid,key->busfees,key->libraryfees,key->labfees,key->examfees,key->datetime,key->transid);

					break;
					}
					key = key->next1;
				}while(key!=NULL);

				break;
			}
		case(3):
			printf("Functionality will come soon.\nPress enter to continue...");
			scanf("%c",&tempchar);
			break;
		default:
			printf("Invalid choice. Press enter to continue...");
			scanf("%c",&tempchar);
			break;
	}

	printf("Press Enter to continue...");
	scanf("%c",&tempchar);
	scanf("%c",&tempchar);
}


void displaydues()
{
	char studentid[10];
	int detectflag = 0;

	struct payment* key;
	struct payment* lastupdated;
	
	FILE* fp;

	fp = fopen("payments.txt","r");

	key = head;

	printf("Enter student ID: ");
	scanf("%s",studentid);
	

	do
	{
		if( strcmp(key->studentid,studentid) == 0 )
		{
			lastupdated = key;
			detectflag = 1;
		}

		key = key -> next1;

	}while(key!=NULL);
	
	if(detectflag == 0)
	{
		printf("\n\nNo payments made with the given ID\n");
		printf("Press Enter to continue...");
		scanf("%c",&tempchar);
		return;
	}

	if( (lastupdated -> busfees != 0) || (lastupdated -> libraryfees != 0) || (lastupdated -> labfees != 0) || (lastupdated -> examfees != 0))
	{
		printf("\nStudent %s has following dues: \n",studentid);
		printf("Busfees: %d", lastupdated->busfees);
		printf("Libraryfees: %d",lastupdated->libraryfees);
		printf("Labfees: %d",lastupdated->labfees);
		printf("Examfees: %d",lastupdated->examfees);
		printf("\n\nPress Enter to continue");
		scanf("%c",&tempchar);
	}

	if( (lastupdated -> busfees == 0) && (lastupdated -> libraryfees == 0) && (lastupdated -> labfees == 0) && (lastupdated -> examfees == 0))
	{
		printf("\nStudent %s has NO DUES.\n");
		printf("Press Enter to continue...");
		scanf("%c",&tempchar);	
	}

	printf("\n\nPress Enter to continue...");
	scanf("%c",&tempchar);
	scanf("%c",&tempchar);
}

void displayalldues()
{
	struct payment* lastupdated;
	lastupdated = head;

	do
	{
		if( (lastupdated -> busfees != 0) || (lastupdated -> libraryfees != 0) || (lastupdated -> labfees != 0) || (lastupdated -> examfees != 0))
		{
			printf("\nStudent %s has following dues: \n",lastupdated->studentid);
			printf(" Busfees: %d", lastupdated->busfees);
			printf(" Libraryfees: %d",lastupdated->libraryfees);
			printf(" Labfees: %d",lastupdated->labfees);
			printf(" Examfees: %d",lastupdated->examfees);
			printf("\n");
		}
		lastupdated = lastupdated -> next1;
	}while(lastupdated!=NULL);

	printf("\nPress Enter to Continue...\n");
	scanf("%c",&tempchar);
	scanf("%c",&tempchar);
}

void feemanagement()
{

	if(pay_loadstatus == 0)
	{	
		loadpaymentLL();
		pay_loadstatus = 1;
	}
		
	while(1)
	{

		clear();

		printf("\t\t\t----------FEE MANAGEMENT----------\n");
		printf("\t\t\t\t1. Make Payment\n");
		printf("\t\t\t\t2. View Payment History\n");
		printf("\t\t\t\t3. Display Dues\n");
		printf("\t\t\t\t4. Exit\n");

		scanf("%d",&choice);
	
		switch(choice)
		{
	 		case 1: makepayment();
				break;
	   		case 2: viewhistory();
				break;
			case 3: 
				{
					clear();
					printf("1. Display dues of student ID: ");
					printf("2. Display all dues");
					scanf("%d",&choice);
					if(choice == 1)
						displaydues();
					else if(choice == 2)
						displayalldues();
					else{
						clear();
						printf("Invalid choice. Press enter to coninue...");
						scanf("%c",&tempchar);
					}
				}
			case 4:
				return;
		}
	}
}
		
