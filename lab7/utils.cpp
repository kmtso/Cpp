#include <iostream> /* COMP2011 Lab 7: utils.cpp */
#include <cstring>
#include "my_include.h"


/* Task One */
void bubbleSort(double arr[], int n, bool ascending)
{
       bool swapped=false;
       bool swapped2=false;
       int arrLen=n;
       double temp;
       if (ascending){
         do{
            swapped=false;
            for(int i=0;i< arrLen-1;i++){
               if(arr[i]>arr[i+1]){
                  temp=arr[i];
                  arr[i]=arr[i+1];
                  arr[i+1]=temp;
                  swapped=true;
            }
        
            }}while (swapped);
      }else{
                  do{
            swapped2=false;
            for(int i=0;i< arrLen-1;i++){
               if(arr[i]<arr[i+1]){
                  temp=arr[i];
                  arr[i]=arr[i+1];
                  arr[i+1]=temp;
                  swapped2=true;
            }
        
            }}while (swapped2);
      }
}

//g++ -o lab7.exe main.cpp utils.cpp

/* Task Two */
void bubbleSort(char arr[][MAX_ARRAY_LENGTH+1], int n, bool ascending)
{

}



/* Given Functions */
void printArray(const double arr[], int size)
{
   for (int i = 0; i < size; i++)
      cout << arr[i] << " ";
   cout << endl;
}

void printArray(const char arr[][MAX_ARRAY_LENGTH+1], int size)
{
   for (int i = 0; i < size; i++)
      cout << arr[i] << endl;
   cout << endl;
}

