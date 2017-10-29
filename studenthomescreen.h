#include "studentviewmarks.h"
#include "studentviewpayments.h"
#include "globalvariables.h"

void hellostudent(char sid[10])
{
        
        printf("\t\t\t-------------Student Module-------------\n");
	printf("\t\t\t1.View Marks\n");
	printf("\t\t\t2.View Payments\n");
	printf("\t\t\tenter your choice : ");
	scanf("%d",&choice);
	
	switch(choice)
	{
	    case 1:   viewmymarks(sid3);
           	      break;
	    case 2:   viewmypayments(sid3);
                      break;
            default:  hellostudent(sid);
                      break;
	} 
}
