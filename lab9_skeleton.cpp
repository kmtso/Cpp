#include <iostream>   
#include <cstdlib>

using namespace std; 

const int MIN_HEIGHT = 120;
const int MAX_HEIGHT = 160;

struct kidNode 
{ 
    int height; 
    kidNode* next; 
}; 


int getRandomHeight(int min, int max){
    return (rand() % (max - min + 1)) + min;
}

void printLinkedList(kidNode* head){
    for (kidNode* p = head; p != nullptr; p = p->next){
        cout << p->height;
        cout << " ";
    }
    cout << endl;
}
kidNode* ll_create(int height)
{
kidNode* p = new kidNode; p->height = height; return p;
}
int ll_length(const kidNode* head)
{
    int length = 0;
    for (const kidNode* p = head; p != nullptr; p = p->next)
        ++length;
    return length;
}

/** Task 1:  create an initial linked list with kid_num nodes with random heights, each presenting a kid. **/
kidNode* createKidList(int kid_num, int min_height, int max_height){
// Please implement task 1 here.
    kidNode* head=ll_create(getRandomHeight(min_height, max_height));
//kidNode* p =new kidNode; p->height=getRandomHeight(min_height, max_height);
    //head->next=nullptr;
        kidNode* p =head;
        p->next=nullptr;
//    head->next=p;
for (int i=1;i<kid_num;i++){
    p->next=ll_create(getRandomHeight(min_height, max_height));
    p=p->next;  
/*   kidNode* p =new kidNode(getRandomHeight(min_height, max_height)); 
    p->next=head;
    head =p;
    */}
    p->next=nullptr;
    //p=nullptr;
    return head;
}

/**Task 2: reverse the initial linked list.**/
kidNode* reverseKidList(kidNode* head){
// Please implement task 2 here.
    kidNode* current = head;
    kidNode *pre = nullptr, *next = nullptr;
 
    while (current != nullptr) {
        next = current->next;
        current->next = pre;
        pre = current;
        current = next;
    }
    head = pre;
    return head;
}
    kidNode* newHead;
    kidNode* sorted;
/**Task 3: line up the kids according to their heights in an ascending order.**/
kidNode* sortKidList(kidNode* head){
// Please implement task 3 here.
    bool swapped;
    int temp;
    kidNode* current = head;
    //kidNode* ptr=nullptr;

         do{
            swapped=false;
            current=head;
            //for(int i=0;i<ll_length(head);i++){
            //for (current = head; current != nullptr; current = current->next){

               // cout<<ll_length(head)<<endl;
                //cout<<current->height;
               // cout<<current->next->height;
               while(current->next!=nullptr){ 
               if(!(current->height>current->next->height) && current->next!=nullptr){//
                  temp=current->height;
                  //current=current;
                  current->height=current->next->height;
                    current->next->height=temp;
                   // cout<<current->next->height;
                  //
                  swapped=true;
                }
               
                current=current->next;
            }  //ptr=current;//current->next=nullptr;
            }while (swapped);
            //head=current;
    return head;

}


int main()
{   
   int kid_num;

   do {
        cout << "===========================================" << endl;
        cout << "Please input the number of kids in the class (no more than 20) or enter an alphabet to exit:" << endl;
        cin >> kid_num;
        if (cin.fail())
            return 0;

        if (kid_num <= 0 || kid_num > 20){
            cout << "Invalid number! Please input a number again." << endl;
            continue;
        }

        kidNode* initial_line_head = createKidList(kid_num, MIN_HEIGHT, MAX_HEIGHT);

        cout << endl;
        cout << "Output:" << endl;
        cout << "The initial list of kids' heights is:" << endl;
        printLinkedList(initial_line_head);

        kidNode* reversed_line_head = reverseKidList(initial_line_head);
        cout << "The reversed list of kids' heights is:" << endl;
        printLinkedList(reversed_line_head);

        kidNode* sorted_line_head = sortKidList(reversed_line_head);
        cout << "The ascending list of kids' heights is:" << endl;
        printLinkedList(sorted_line_head);
   } while(true);

   return 0;
}