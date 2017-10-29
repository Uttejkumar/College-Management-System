#include "adminstudentmanagement.h"
#include "adminfeemanagement.h"
#include "globalvariables.h"

void helloadmin(char adminname[20])
{
	printf("\t\t----------WELCOME %s----------\n",adminname);
	printf("\t\t\t1. Student management\n");
	printf("\t\t\t2. Fee management\n");
	
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1: 
			studentmanagement();
			break;
		case 2:
			feemanagement();
			break;
		default:
			//printf(
			helloadmin(adminname);
			break;
	}
}
