#include <cstdio>
#include <iostream>
#include<cstring>
#include<stdlib.h>

//https://stackoverflow.com/questions/23504901/convert-16-bit-stereo-sound-to-16-bit-mono-sound

using namespace std;
          
char array[128]= {
                  0X7F,0x7F,0x00,0x00,0x7F,0x7F,0x00,0x00, 0x7F,0x7F,0x00,0x00, 0x7F,0x7F,0x00,0x00,
                  0X7F,0x7F,0x00,0x00,0x7F,0x7F,0x00,0x00, 0x7F,0x7F,0x00,0x00, 0x7F,0x7F,0x00,0x00,
                  0X7F,0x7F,0x00,0x00,0x7F,0x7F,0x00,0x00, 0x7F,0x7F,0x00,0x00, 0x7F,0x7F,0x00,0x00,
                  0X7F,0x7F,0x00,0x00,0x7F,0x7F,0x00,0x00, 0x7F,0x7F,0x00,0x00, 0x7F,0x7F,0x00,0x00,
                  0X7F,0x7F,0x00,0x00,0x7F,0x7F,0x00,0x00, 0x7F,0x7F,0x00,0x00, 0x7F,0x7F,0x00,0x00,
                  0X7F,0x7F,0x00,0x00,0x7F,0x7F,0x00,0x00, 0x7F,0x7F,0x00,0x00, 0x7F,0x7F,0x00,0x00,
                  0X7F,0x7F,0x00,0x00,0x7F,0x7F,0x00,0x00, 0x7F,0x7F,0x00,0x00, 0x7F,0x7F,0x00,0x00,
                  0X7F,0x7F,0x00,0x00,0x7F,0x7F,0x00,0x00, 0x7F,0x7F,0x00,0x00, 0x7F,0x7F,0x00,0x00,                            
          };
          
enum  Type_Channel
{
    LEFT_CHANELL,
    RIGHT_CHANELL    
};










          
          //int channelType stereoToMono  monoToStereo
void stereoToMono(char * stereoIN ,int lenth, short ** monoOut, int monoLenth ,Type_Channel channelType)
{
    printf("splitReadStream --Called \n");   
    int i;    
    int j=0;
    int local;
    int counter =0;
    int splitCounter =0;
    int monoI =0;
    
#if 0   
    for(local=0; local< 128; local++)  
    {
       printf("%d",stereoIN[local]);           
    }
 #endif 
     
    short *ptrMonoLocal  = *monoOut;    
    for (unsigned i = 0; i < lenth; i += 4)
    {
      short leftChanel = *(short *)&stereoIN[i];
      short rightChanel = *(short *)&stereoIN[i + 2];    
      printf("\nLeft =%d Right =%d ",leftChanel,rightChanel);     
      if(monoI <= monoLenth )  
      {    
          if(channelType == LEFT_CHANELL) 
          {     
            ptrMonoLocal[monoI] =  leftChanel ;  
          } 
          else if(channelType == RIGHT_CHANELL)
          {
            ptrMonoLocal[monoI] =  rightChanel ;
          }  
          //printf("\n left= %d  ptrMonoLocal[monoI]=%d  splitCounter =%d \n",leftChanel, ptrMonoLocal[monoI],splitCounter);      
          monoI = monoI+1;        
          splitCounter++; // check what is the problem from 
      }    
    }    
    printf("\nPrint all mono value\n");     
    for(j=0; j<32;j++)  
    {
        printf(" mono =%d counter=%d \n",ptrMonoLocal[j],counter); 
        counter++;   
    }     
}

int main()
{
 
 #if 0 
  //============================================================
  Use case 1
        1) int stereoLenth = 128;
        2) int stereoLenth = 129
  Use case 2
  Use case 3
  Use case 4
  //============================================================
 #endif 
 
 
  char *ptrStereo = array;
  char *ptrMono  = NULL;
  int stereoLenth = 128;
  int monolenth =  stereoLenth /2;
  int k;
  int j;
  for(k=0 ;k<128; k++)
  {
    printf("%d",array[k]);
  }
  



  //short *ptrMonoLocal  = (short*)malloc(128*sizeof(short));
   short *ptrMonoLocal  = (short*)malloc(128*sizeof(short));

   printf("\n =================Get Right Data=====================\n");
   stereoToMono(ptrStereo,stereoLenth,&ptrMonoLocal,monolenth,RIGHT_CHANELL);
   
   
   printf("\n =================Get Left  Data=====================\n");
   
   stereoToMono(ptrStereo,stereoLenth,&ptrMonoLocal,monolenth,LEFT_CHANELL);
   
#if 0
   printf("\nPrint  Splited  mono value\n");     
   for(j=0; j<32;j++)  
   {
     if(NULL != ptrMonoLocal )
     {
        printf("%d\n",ptrMonoLocal[j]); 
     }
     else
     {
       printf("Data is Null");
     }   
   }  
#endif
   
   free(ptrMonoLocal); 
   return 0;
}




