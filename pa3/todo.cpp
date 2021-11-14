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
    if(position<1||position>ll_length(head)-1)
        return false;
    TrainCar* prev=nullptr;
    TrainCar* p=head;
    for (int i = 0; 
            i < position  &&  p->next != nullptr; 
         p = p->next, ++i)
         ;
        if (p != nullptr)  // ptr is found
    {   
        
        prev=p->prev;
        //cout<<p->type;
        prev->next = p->next;
        //        cout<<p->type;
        

    if(prev->next != nullptr)
        prev->next->prev=prev;
        
        delete p;      // STEP 3: Free up the memory of the deleted item
        //p=nullptr;
        
        //if(prev->next->prev != nullptr)
      //  cout<<p->type; 
    deallocateTrain(p);
    //    cout<<"pointer"<<p->type; 

    }

    return true;
}
TrainCar* swap(TrainCar* head, int a, int b)
{
  //      if(a<1||b<1||(a>ll_length(head)-1||b>ll_length(head)-1))
    //    return false;
    TrainCar* carX = new TrainCar;
    TrainCar* carY = new TrainCar;
    TrainCar* prev=nullptr;
    TrainCar* p=head;
    for (int i = 0; 
            i < a  &&  p->next != nullptr; 
         p = p->next, ++i)
         ;
    prev=p->prev;
    carX=p;
    TrainCar* prev2=nullptr;
    TrainCar* p2=head;
    for (int i = 0; 
            i < b  &&  p2->next != nullptr; 
         p2 = p2->next, ++i)
         ;
    prev2=p2->prev;

    carY=p2;
    prev->next=carY;
    prev2->next=carX;
    TrainCar* temp=carY->next;
    carY->next =carX->next;
    carX->next=temp;
    return head;
/*
    TrainCar* temp1 = new TrainCar;
    TrainCar* temp2 = new TrainCar;
    temp1=x;
    temp2=y;
   // y=temp1;
   //head->next=y;
    //temp1->prev->next=y;
    cout<<"y:"<<y->type<<"head:"<<temp1->prev->type;
    y->prev=x->prev;
    y->next=x->next;
    temp1->next->prev=y;
   // temp1->next->prev=y;
   // x=temp2;
    //temp2->prev->next=temp1;
    x->prev=temp2->prev;
    x->next=temp2->next;
    temp2->prev->next=x;
cout<<"y:"<<y->type<<"head:"<<temp1->prev->type;
    delete temp1;
    delete temp2;
    //temp1=nullptr;
cout<<"y:"<<y->type<<"head:"<<temp1->prev->type;
*/
}
void reverse(TrainCar* head){
        TrainCar* current = head;
        TrainCar *pre = nullptr, *next =nullptr;
 int index=0;
        while (current != nullptr) {
        
            if(current->next!=nullptr)//&&index<ll_length(head)-1)//
                current->next->prev=current;
                
            else
                {current->prev=pre;
                //cout<<"currenttype"<<current->type<<"\n";
                //cout<<"pretype"<<pre->type;
                }
                
            //current->next = pre;
 
            // Move pointers one position ahead.
            pre = current;
            current = current->next;//printTrain(head);
        }
       // head = pre;
       
}
bool swapCar(TrainCar* head, int a, int b)
{   
    if(a<1||b<1||(a>ll_length(head)-1||b>ll_length(head)-1))
        return false;
    if(b<a){
        int temp=a;
        a=b;
        b=temp;
    }
    TrainCar* carX = new TrainCar;
    TrainCar* carY = new TrainCar;
    TrainCar* prev=nullptr;
    TrainCar* p=head;
    for (int i = 0; 
            i < a  &&  p->next != nullptr; 
         p = p->next, ++i)
         ;
    prev=p->prev;
    carX=p;
    TrainCar* prev2=nullptr;
    TrainCar* p2=head;
    for (int i = 0; 
            i < b  &&  p2->next != nullptr; 
         p2 = p2->next, ++i)
         ;
    prev2=p2->prev;

    carY=p2;
  //  cout<<"initial Y"<< carY->type;
    TrainCar* carYOriginalNext=carY->next;
    TrainCar* carXOriginalNext=carX->next;

    //carY->next->prev=carX;
    prev->next=carY; //original X position previous next element is carY
    //prev->next->prev=prev;
    
   // carXOriginalNext->prev=carY;
    //prev->next->prev=prev2;
    prev2->next=carX; //original previous next element is carx
    //carYOriginalNext->prev=carX;

    //prev2->next->prev=prev2;

    TrainCar* temp=carY->next; //store orignal Y car next
    //TrainCar* temp_prev=carY->prev;
    carY->next =carX->next; //Y car next change to X car next
    //carY->prev= carX->prev;
    //printTrain(head);
    //carY->prev=prev;
    carX->next=temp; //X car next change to original Y car next
    //cout<< carX->type<< carX->next<<endl;
    //printTrain(head);
    //carX->prev=temp_prev;
    reverse(head);
    //temp->prev=carX;
    //carX->next->prev=temp->prev;
  //  carX->prev=temp_prev;
    //carX->prev=temp_prev;
   // carX->prev->next=
    //swap(head,carX,carY);
    /*
    p->prev->next=carY;
    carY->prev=p->prev;
    carY->next=p->next;*/
    //carX->prev=p2->prev;
    //carX->next=p2->next;
   // p->next->prev=carY;
   // p2->prev->next=carX;
   //delete p;
   //delete p2;
    return true;
}

void sortTrain(TrainCar* head, bool ascending)
{
        bool swapped;
        bool swapped2;
    int count=1;
    TrainCar* current = head->next;
    TrainCar* prev=nullptr;

    //swapCar(head,1,4);
   // printTrain(head);
   // swapCar(head,5,1);
    //swapCar(head,4,3);
        if(ascending=false){
            do{
                swapped=false;
                current=head->next;
                count=1;
                //prev=nullptr;
                while(current->next!=nullptr){
                if(current->load<current->next->load && current->next!=nullptr){//
                     //cout<<"before"<<current->type<<"count"<<count<<endl;
                        //cout<<<<endl;
                        swapCar(head,count,count+1);
                        
                     //cout<<"after"<<current->type<<endl;
                    // printTrain(head);
                        //cout<<"\n"<<count;
                        swapped=true;
                    }if(current->next!=nullptr)
                    current=current->next;         count+=1;

                }  //ptr=current;//current->next=nullptr;
                //cout<<"\n"<<count;
            }while (swapped);
        }else
        {
            do{
                swapped2=false;
                current=head->next;
                count=1;
                //prev=nullptr;
                while(current->next!=nullptr){
                if(!((current->load)<(current->next->load))&&current->next!=nullptr){//
                   //  cout<<"before"<<current->type<<"count"<<count<<endl;
                        //cout<<<<endl;
                        //cout<<current
                        swapCar(head,count,count+1);
                        swapped2=true;
                     //cout<<"after"<<current->type<<endl;
                     
                     printTrain(head);
                     //   cout<<"\n"<<count;
                        
                    }if(current->next!=nullptr)
                    current=current->next;            count+=1;

                }  //ptr=current;//current->next=nullptr;
                //cout<<"\n"<<count;

                cout<<swapped2<<endl;
            }while (swapped2==true);            
        }
        
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
    head=nullptr;
}
