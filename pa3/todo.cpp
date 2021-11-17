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
                

            //current->next = pre;
 
            // Move pointers one position ahead.
         //   pre = current;
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
        if(ascending==false){
            do{
                swapped=false;
                current=head->next;
                count=1;

                while(current->next!=nullptr){
                if(current->load<current->next->load && current->next!=nullptr){//

                        swapCar(head,count,count+1);
                        

                        swapped=true;
                    }if(current->next!=nullptr)
                    current=current->next;         count+=1;

                } 
            }while (swapped);
        }else
        {
            do{
                swapped2=false;
                current=head->next;
                count=1;

                while(current->next!=nullptr){
                if(!((current->load)<(current->next->load))&&current->next!=nullptr){//

                        swapCar(head,count,count+1);
                        swapped2=true;

                        
                    }if(current->next!=nullptr)
                    current=current->next;            count+=1;

                }  
               // cout<<swapped2<<endl;
            }while (swapped2==true);            
        }
        
}
TrainCar* ll_search(TrainCar* head, CarType type)
{
    for (TrainCar* p = head; p != nullptr; p = p->next)
    {

        if (p->type == type)
            {if(p->load==p->maxLoad){
                //cout<<"true:"<<p->maxLoad;
                continue;}
            if(p->load<p->maxLoad){
                //cout<<"return true:"<<p->maxLoad;
                return p;
            }
        }   // printTrain(p);

    }
    return nullptr;
}

bool load(TrainCar* head, CarType type, int amount)
{ 
    int count=0;
    int remain=amount;
    TrainCar* current = head;
                while(current->next!=nullptr){
                    if(current->next->type==type){
                        count++;
                    }if(current->next!=nullptr)
                    current=current->next;
                } 
                   
    //TrainCar* car=ll_search(head,type);
    do{        TrainCar* car=ll_search(head,type);

       // cout<<"cartype"<<car->type<<"carload"<<car->load;
        if (car==nullptr||(count==1&&car->maxLoad<remain))
            return false;
        if (car->load+remain<car->maxLoad)
            car->load=car->load+remain;
        else if(!(car->load+remain<car->maxLoad)){
            remain=remain+car->load-car->maxLoad;
            car->load=car->maxLoad;
        //printTrain(head);
        }
       // cout<<count;
        count--;
        //if(count>0)

    }while(count>0);            

            
    return 1;
}
TrainCar* rev_search(TrainCar* tail, CarType type)
{
    for (TrainCar* p = tail->prev; p != nullptr; p = p->prev)
    {
        //printTrain(p);

        if (p->type == type)
            {if(p->load==0){
                continue;}
            if(p->load>0){
                return p;
            }
        }   
    }
    return nullptr;
   /*
       for (TrainCar* p = head; p != nullptr; p = p->next)
    {

        if (p->type == type)
            {if(p->load==0||count>1){
                //cout<<"true:"<<p->maxLoad;
                continue;}
            if(p->load>0){
                //cout<<"return true:"<<p->maxLoad;
                return p;
            }
        }   
        }   // printTrain(p);

    }
    return nullptr; */
    return nullptr;
}
bool unload(TrainCar* head, CarType type, int amount)
{   //TrainCar* prev=nullptr;
    TrainCar* p = head;
    int count=0;
    TrainCar* current=head;
    int request=amount;

    int b=ll_length(p)-1;
    for (int i = 0; 
        i < b  &&  p->next != nullptr; 
    p = p->next, ++i)
            cout<<p->next->prev->type;
            printTrain(p);
; 

            printTrain(p);

cout<<p->prev->type;
            //printTrain(p);
cout<<current->type;
   // TrainCar* prev=p;
    //cout<<p->next->prev->type;

    while(current->next!=nullptr){
        if(current->next->type==type){
            count++;
        }if(current->next!=nullptr)
            current=current->next;
    } 
    do{        TrainCar* car=rev_search(p,type);

       // cout<<"cartype"<<car->type<<"carload"<<car->load;
        if (car==nullptr||(count==1&&car->maxLoad<request))
            return false;
        if (request<car->load)
            car->load=car->load-request;
        else if(!(car->load<request)){
            request=request-car->load;
            car->load=0;
        //printTrain(head);
        }
       // cout<<count;
        count--;
        //if(count>0)

    }while(count>0); 
/*
    int unload_amount=amount;
    TrainCar* current = head;
    //
    /*

         cout<<p->type;
        // TrainCar* prev=nullptr;prev->prev=p;
       //  cout<<prev->prev->type;

     //cout<<prev->prev->type;
   // prev->prev=p;printTrain(prev);
                while(p!=nullptr){
                    //cout<<p->type;
                    if(p->type==type){
                        count++;
                    }if(p!=nullptr)
                        p=p->prev;
                } 
                         cout<<p->type;

    //TrainCar* car=ll_search(head,type);
    do{        TrainCar* car=rev_search(head,type,count);

       // cout<<"cartype"<<car->type<<"carload"<<car->load;
        if (car==nullptr||(count==1&&car->load<unload_amount))
            return false;
        if (car->load-unload_amount>0)
            car->load=car->load-unload_amount;
        else if(!(car->load-unload_amount>0)){
            unload_amount=unload_amount-car->load;
            car->load=0;
        printTrain(head);
        }
       // cout<<count;
        count--;
        //if(count>0)

    }while(count>0);            

  */          
    return 1;
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
