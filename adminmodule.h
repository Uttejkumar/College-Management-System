#include "globalvariables.h"
#include "adminhomescreen.h"

void adminlogin()
{
	char inputid[20];
	char inputpwd[10];
	char adminid[20];
	char adminpwd[10];
	
	FILE* adminfile;
	adminfile = fopen("validate.txt","r");

	clear();

	if(adminfile == NULL)
	{
		printf("There is no administrator registered. Contact your software developer");
		printf("\nPress enter to continue...");
		scanf("%c",&tempchar);
		return;
	}	
	
	printf("Enter Admin ID: ");
	scanf("%s", inputid);
	
	clear();
	
	printf("Enter password (Make sure no one's peeking): ");
	scanf("%s", inputpwd);
	
	fscanf(adminfile,"%s",adminid);
	fscanf(adminfile,"%s",adminpwd);

	if( strcmp(inputid,adminid) == 0 && strcmp(adminpwd,inputpwd) == 0)
	{
		clear();
		helloadmin(inputid);
	}
	
	else
	{
		clear();
		scanf("%c",&tempchar);
		printf("\t\tInvalid Credentials. Press enter to continue...");
		scanf("%c",&tempchar);
		return;
	}
}
		
