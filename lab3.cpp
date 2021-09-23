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
    int arr[10];
    int count=0;
    if (num==dig){
        count++;
    }
    for (int i=9;i>=0;i--){
        arr[i]=num%10;
        if(num==0){
            arr[i]=-1;
        }
        num/=10;

    }
    for(int i=9;i>=0;i--){
        if (arr[i]==dig){
            count++;
        }
    }

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
    } //cout << digits[i] << " ";

    /*
    int arr[10];
    // You may count the number of digits of number_to_process first
    do{
        count++;
        if(num%10==dig){
            occurrence_count++;
        }
        num/=10;
    }while (num!=0);
    cout << count <<endl;
    cout << occurrence_count <<endl;

    cout << num2/100 <<endl;*/
    // then you can extract the digit at position i as the remainder by dividing appropriate number
    /*for (int i=count;i>0;i--){
        int n=pow(10,i-1);
        (int) num2% n;
        if ((int) num2% n==dig)
    }

    
    while(num2!=0){
        if(ord=1 && num2%10==dig){
            return count-1;
        }
        if (dig<ord)
            return count=-1;
        num2/=10;
        count--;
    }*/


    return count-1;
}

// This function will print all digits in a number with the occurrence larger than a threshold.
// Printed digits should be in an ascending order. 
// Prints nothing if none of the digits occurs more than the thresold.
// You may call the above functions in this function.
void filtering_by_occurrence(unsigned int number_to_process, unsigned int occurrence_threshold){
    unsigned int num=number_to_process;
    unsigned int occ=occurrence_threshold;
    char str[]="";
    vector<int>digits;

        while(num){
        digits.push_back(num%10);
        num=num/10;
    }
        // reversing the order of the elements inside vector "digits" as they are collected from last to first and we want them from first to last.
    reverse(digits.begin(), digits.end());
    
    // Now the vector "digits" contains the digits of the given number. You can access the elements of a vector using their indices in the same way you access the elements of an array.
    for(int i = 0; i < digits.size(); i++){
        cout<< occurrence_counting(num,i)<<endl;
        if (occurrence_counting(num,i) >occurrence_threshold){
        str+i;
        }
        }
    cout<< str<<endl;    
        /*
    if (occurrence_counting(num,0)>occurrence_threshold){
        str+0;
    }
    if (occurrence_counting(num,1)>occurrence_threshold){
        if(str=="")
            str+1;
    }
    if (occurrence_counting(num,2)>occurrence_threshold){
        str+2;
    }
    if (occurrence_counting(num,3)>occurrence_threshold){
        str+3;
    }
    if (occurrence_counting(num,1)>occurrence_threshold){
        str+1;
    }*/


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


