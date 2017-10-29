#include "globalvariables.h"
#include "structvariables.h"
#include "loadlinkeslists.h"

void viewmymarks(char sid2[10])
{
   int flag=0;
   struct marks1* mey;
  mey=begin;
do
 	{
  		if(strcmp(mey->studentid,sid2)==0)
   		{
                        count=1;
		       printf("%d %d %d %d %d %d %d %d %d\n",mey->sem,mey->sub_1,mey->sub_2,mey->sub_3, mey->sub_4,mey->sub_5,mey->sub_6,mey->lab_1,mey->lab_2);


		}
            mey=mey->next2;
        }while(mey!=NULL);
      
            if(count==0)
            {
		printf("no marks entered till date .. Press enter to continue..");
                scanf("%c",&tempchar);
                  return;
            }
}

