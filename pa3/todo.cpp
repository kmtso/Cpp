//modify and submit this file only
#include "pa3.h"
#include <iostream>
using namespace std;
//you are NOT allowed to include any additional library; see FAQ

int ll_length(const TrainCar* head)
{
    int length = 0;
    for (const TrainCar* p = head; p != nullptr; p = p->next)
        ++length;
    return length;
}

TrainCar* createTrainHead(){
    TrainCar* head=new TrainCar; head->type=HEAD; head ->load=0; head->maxLoad=0; head->prev=nullptr; head->next=nullptr;
    return head;
}

bool addCar(TrainCar* head, int position, CarType type, int maxLoad){

    if(position<1 || maxLoad<1||position>ll_length(head))
        return false;
    /*    if(position==1)
            {TrainCar* car=new TrainCar; car->type=type; car ->load=0; car->maxLoad=maxLoad; car->prev=head; car->next=nullptr;head->next=car;}
    */    TrainCar* p=head;
      
    for (int i = 0; 
            i < position-1  &&  p->next != nullptr; 
         p = p->next, ++i)
         ;
    //TrainCar* pNextOriginal=p->next;
    TrainCar* new_car=new TrainCar; new_car->type=type; new_car ->load=0; new_car->maxLoad=maxLoad;
    //cout<<p->next->prev->type;
    if(p->next != nullptr)
        p->next->prev=new_car;
    new_car->next=p->next;
    //new_car->next->prev=new_car;
    new_car->prev=p; 
    p->next=new_car;

    return true;
}

bool deleteCar(TrainCar* head, int position)
{
    return 0;
}

bool swapCar(TrainCar* head, int a, int b)
{
    return 0;
}

void sortTrain(TrainCar* head, bool ascending)
{
}

bool load(TrainCar* head, CarType type, int amount)
{
    return 0;
}

bool unload(TrainCar* head, CarType type, int amount)
{
    return 0;
}

void printCargoStats(const TrainCar* head)
{
}

void divide(const TrainCar* head,  TrainCar* results[CARGO_TYPE_COUNT])
{
}

TrainCar* optimizeForMaximumPossibleCargos(const TrainCar* head, int upperBound)
{
    return 0;
}

void deallocateTrain(TrainCar* head)
{
}
