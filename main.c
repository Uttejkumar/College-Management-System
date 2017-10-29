#include <stdio.h>
#include <string.h>

#include "adminmodule.h"
#include "studentmodule.h"
#include "staffmodule.h"
#include "globalvariables.h"

void main()
{	
	modifyflag = 0;
	while(1)
	{
		clear();

		printf("\t----------COLLEGE MANAGEMENT SYSTEM----------\n");
		printf("\t\t\t1. Administrator\n");
		printf("\t\t\t2. Staff\n");
		printf("\t\t\t3. Student\n");
		printf("\t\t\t4. Exit\n");

		scanf("%d",&choice);
	
		switch(choice)
		{
			case 1:
				adminlogin();
				break;
			case 2:
				//stafflogin();
				break;
			case 3:
				//studentlogin();
				break;
			case 4:
				clear();
				exit(0);
			default:
				printf("Invalid option. Press enter to retry...");
				scanf("%c",&tempchar);
				break;
		}
	}
}

