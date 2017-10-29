#include "globalvariables.h"
#include "structvariables.h"
#include "loadlinkedlists.h"

void viewmypayments(char sid1[10])
{
   
 int count=0;
 struct payment* key;
 key=head;
do
 	{
  		if(strcmp(key->id,sid1)==0)
   		{
                        count=1;
		       printf("%d %d %d %d %s %d \n",key->busfees,key->libraryfees,key->labfees,key->examfees, key->datetime,key->transid);


		}
            key=key->next;
        }while(key!=NULL);
      
            if(count==0)
            {
		printf("no payments done till date.. Press Enter to continue..");
                scanf("%c",&tempchar);
                  return;
            }
}
