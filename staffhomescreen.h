#include "globalvariables.h"
#include "structvariables.h"
#include "loadlinkedlists.h"


void hellostaff(char eid1[10])
{

  	 
	 printf("             ----------Staff Module----------\n");
 	 printf("\t\t\t1.View my Salary Payments\n");
 	 printf("\t\t\t2.View my details\n");
 	 printf("Enter your choice");
         scanf("%d",&choice);
  switch(choice)
   {
      case 1:viewmysal(eid1);
              break;
      case 2:viewmydetails(eid1);
              break;
      default:hellostaff(eid1);
              break;
   }
 return;
}

void viewmysal(char eid2[10])
{

	FILE* fs;
	int count=0;
	fs=fopen("salinfo.txt","r");
        while(!feof(fs))
        {
		fscanf(fs,"%s %s %d %d %d %d %d %d ",empid,mon,&bs,&hra,&ta,&PF,&LOP,&ts);
                if(strcmp(empid,eid2)==0)
                 {
                    count=1;
                 printf("%s %d %d %d %d %d %d\n ",mon,bs,hra,ta,PF,LOP,ts);
		}

	}
        if(count==0)
	printf("No salary payment done till date.. Press Enter to continue..");
        scanf("%c",&tempchar);
 return;
}
 
void viewmydetails(char eid3[10])
{
        FILE* fd;
	 
	fd=fopen("staff.txt","r");
        while(!feof(fd))
	{
		fscanf(fd,"%s %s %s %s %d ",ename,empid,ebranch,desig,&sal);
                 if(strcmp(empid,eid3)==0)
		{
	
                        printf("%s  %s %s %s %d",ename,empid,ebranch,desig,sal); 
                        break;   
		}
	}
}
           
	
	
