#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
	int i;
	char seq[1000];
	int length;
printf("Type a valid DNA sequence:\n");//TYPE YOUR SEQUENCE
 while(scanf("%s",seq) ==1 )
 {
	int numATG;
	int numTAG;
        int numTAA;
        int numTGA;
        int numEND;
        numEND = 0;
        numATG = 0;
        numTAG = 0;
        numTAA = 0;
        numTGA = 0;
        length = strlen(seq);
           for(i = 0; i < length ; i++ )
  	    {
              if( strncmp( seq + i, "ATG",3) == 0)//CHECK FOR START CODON. THE COMMAND seq[i]=='A' && seq[i+1]=='T' && seq[i+2]=='G' CAN ALSO BE USED
               {
                 printf("There is start codon at position %d,\n", i+1);
                 numATG++;
               }
              if( numATG>=1){break;}//STOP CHECKING FOR START CODONS AFTER FIRST ONE IS FOUND
            }
	   for( i = i; i < length ; i = i+3)//CHECK THE REMAINNING SEQUNECE PER TRIPLETS
                   {
                        if  (strncmp( seq + i, "TAG",3) == 0)//CHECK FOR THE END CODONS
                           {printf("Stop codon TAG at position %d\n",i+1);
                            numTAG++;}
                        else if (strncmp( seq + i, "TAA",3) == 0)
                           {printf("Stop codon TAA at position %d\n",i+1);
                            numTAA++;}
                        else if (strncmp( seq + i, "TGA",3) == 0)
                           {printf("Stop codon TGA at position %d\n",i+1);
                            numTGA++;}
                   }
           if(numATG == 0){printf("No ATG codon found\n");}
              numEND = numTAG + numTAA + numTGA;
           if(numEND > 1)
               {printf("There is more than 1 end codon in the sequence \n");}
 }
}


