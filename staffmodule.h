#include "globalvariables.h"
#include "staffhomescreen.h"

void stafflogin()
{
   char eid[10];
   char pass[10];

   char ename[10];
   char empid[10];
   char ebranch[10];
   char desig[10];
   int sal; 

   FILE* fs;
   fs=fopen("staff.txt","r");
   printf(" enter id:");
   scanf("%s",eid);
   printf("enter password");
   scanf("%s",pass);
    while(!feof(fs))
     {

         fscanf(fs,"%s %s %s %s %d",ename,empid,ebranch,desig,&sal);
          if(strcmp(eid,empid)==0)
              {
                 if(strcmp(empid,pass)==0)
		{
                    printf("\t\t\t\t\tlogged in successfully\n");
                       hellostaff(eid);
                     
                }
		else
		{
		    printf("\t\tPassword incorrectly specified..Press Enter to continue..");
                    scanf("%c",&tempchar);
                    return;
                 }
               }
            else
               {
		   printf("\t\t\tUesr does not exist..Press Enter to continue..");
		   scanf("%c",&tempchar);
                   return;
                }
	}
}

