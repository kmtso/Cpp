// COMP2011 Fall 2021
// skeleton.cpp -- lab 3

#include <iostream>
#include <climits> // limits for integral types
#include<vector>
#include <algorithm>

using namespace std;
// This function will return the number of occurrence of a digit in a number.
int occurrence_counting(unsigned int number_to_process, unsigned int digit){
    unsigned int num= number_to_process;
    unsigned int dig=digit;
    int count=0;

        
    do{
        if(num%10==dig){
           count++;
        }
        num/=10;
    }while (num!=0);

    return count;
}

// This function will return the index of a digit at its n-th occurrence (order) in a number.
// Index starts with 0 from left to right.
// This function returns -1 when the occurrence of the digit is smaller than "order".
int index_finding(unsigned int number_to_process, unsigned int digit, unsigned int order){
    unsigned int num= number_to_process;
    unsigned int num2= number_to_process;
    unsigned int dig=digit;
    unsigned int ord=order;
    int count=0;
    int occurrence_count=0;
    int visit_time=0;
    vector<int>digits;
    while(num){
        digits.push_back(num%10);
        num=num/10;
    }
        // reversing the order of the elements inside vector "digits" as they are collected from last to first and we want them from first to last.
    reverse(digits.begin(), digits.end());
    
    // Now the vector "digits" contains the digits of the given number. You can access the elements of a vector using their indices in the same way you access the elements of an array.
    for(int i = 0; i < digits.size(); i++){
        if (digits[i]==dig){
            visit_time++;
            if(visit_time==order)
                return i;
        }
    }


    return count-1;
}

// This function will print all digits in a number with the occurrence larger than a threshold.
// Printed digits should be in an ascending order. 
// Prints nothing if none of the digits occurs more than the thresold.
// You may call the above functions in this function.
void filtering_by_occurrence(unsigned int number_to_process, unsigned int occurrence_threshold){
    unsigned int num=number_to_process;
    unsigned int occ=occurrence_threshold;
    vector<int>digits;
    vector<int>digits_fulfill;

        while(num){
        digits.push_back(num%10);
        num=num/10;
    }
        // reversing the order of the elements inside vector "digits" as they are collected from last to first and we want them from first to last.
    reverse(digits.begin(), digits.end());
    int count=0;
    if (number_to_process>9){
        for (int j=0; j<=9;j++){
                
                do{
                    if(num%10==j){
                         count++;
               //     cout<<count<<endl;

                        }
                    
                    if (count>occurrence_threshold){
                    digits_fulfill.push_back(j);
         
                    }
                    num/=10;}while (num!=0);
                num=number_to_process;
                count=0;
        }
}else{
    if (occurrence_threshold==0){
        digits_fulfill.push_back(number_to_process);
    }
}
                  for(int i = 0; i < digits_fulfill.size(); i++){
               if(digits_fulfill[i]!=digits_fulfill[i-1])
                cout<<digits_fulfill[i]<<" ";
         }
}


int main() {
    int reply, output;
    unsigned int number_list_to_process;
    unsigned int digit, order, threshold;

    do {
        cout << "===========================================" << endl;
        cout << "Choose what to do next:" << endl;
        cout << "1: Occurrence counting" << endl;
        cout << "2: Index finding" << endl;
        cout << "3: Filtering by occurrence" << endl;
        cout << "4: Quit" << endl;
        cin >> reply;

        switch(reply) {
        case 1:
            cout << "Please enter a number (0 to " << UINT_MAX << "):" ;
            cin >> number_list_to_process;
            cout << "Please enter the digit-of-interest:";
            cin >> digit;
            output = occurrence_counting(number_list_to_process, digit);
            cout << "Digit " << digit << " occurs " << output << " times." << endl;
            break;
        case 2:
            cout << "Please enter a number (0 to " << UINT_MAX << "):" ;
            cin >> number_list_to_process;
            cout << "Please enter the digit-of-interest:";
            cin >> digit;
            cout << "Please enter the order of that digit:";
            cin >> order;
            output = index_finding(number_list_to_process, digit, order);
            switch (order)
            {
            case 1:
                cout << "The " << order << "st" << " occurrence of digit " << digit << " is at " << output << '.' << endl;
                break;
            case 2:
                cout << "The " << order << "nd" << " occurrence of digit " << digit << " is at " << output << '.' << endl;
                break;
            default:
                cout << "The " << order << "th" << " occurrence of digit " << digit << " is at " << output << '.' << endl;
                break;
            }
            
            break;
        case 3:
            cout << "Please enter a number (0 to " << UINT_MAX << "):" ;
            cin >> number_list_to_process;
            cout << "Please enter the occurrence threshold:";
            cin >> threshold;
            cout << "Digits occurs more than " << threshold << " times are: " ;
            filtering_by_occurrence(number_list_to_process, threshold);
            cout << endl;
            break;
        default:
            break;
        }

    } while (reply != 4);

    return 0;
}


