/*
 * COMP2011 (Fall 2021) Programming Assignment 1
 *
 * Student name: FILL YOUR NAME HERE
 * Student ID: FILL YOUR STUDENT ID NUMBER HERE
 * Student email: FILL YOUR EMAIL HERE
 *
 */

#include <iostream>
#include <limits>
#include<algorithm>
#include<vector>

using namespace std;

// Global Constants
// You cannot modify these global constants
// You cannot use your own global variables
const int MAX_ARR_LEN = 16;
const int MAX_ROTATIONS = 1024;
// End of Global Constants

// Helper Functions
// Declare additional helper functions below when necessary
// int myHelperFunction(int argc, char *argv[])

// End of Helper Functions

// Tasks
// Please write your code under the TODO tag
// You cannot change the function declarations

// Task 1
int rotate(int arr[], int arrLen, int k)
{
   // Task 1 TODO
    if (k<0 || k>=arrLen){
        cout<<"Error: Index k is out of range."<<endl;
        return -1;
    }
    else{
    //for(int i=0; i<arrLen; i++){
    //    arr[i]=arr_o[k-i];
        reverse(arr,arr+(k+1));
        return 0;
    }

    // End of Task 1 TODO

}

//Task 2
int swapAndRecord(int arr[], int arrLen, int indexA, int indexB, int rotations[], int &rotationLen)
{   
    int left=0;
    int right=0;
    rotationLen=0;
    if(indexB>indexA){
        right=indexB;
        left=indexA;
    }else{
        right=indexA;
        left=indexB;        
    }
    // Task 2 TODO
    if (indexA<0 ||indexA>=arrLen ||indexB<0 ||indexB>=arrLen ){
        cout<<"Error: Index out of range."<<endl;
        return -1;
    }else{
        int k=left-1;int c=1;
        if(left==0){
            k=right;
            c=3;
        }
        for(;c<7;c++){
        switch (c)
        {
        case 1:
                    if(k<1){
                continue;
            }
            rotate(arr,arrLen,k);
            rotations[rotationLen]=k;
            rotationLen++;
            break;
        case 2:
        k=left;
            if(k<1){
                continue;
            }
            rotate(arr,arrLen,k);
            rotations[rotationLen]=k;
            rotationLen++;
            break;
        case 3:

            k=right;                    
            
            if(k<1){
                continue;
            }
            rotate(arr,arrLen,k);
            rotations[rotationLen]=k;
            rotationLen++;
            break;
        case 4:
            k=right-left-1;
            if(k<1){
                continue;
            }
            rotate(arr,arrLen,k);
            rotations[rotationLen]=k;
            rotationLen++;
            break;
        case 5:
            k=right-left-2;
                        if(k<1){
                continue;
            }
            rotate(arr,arrLen,k);
            rotations[rotationLen]=k;
            rotationLen++;
            break;
        case 6:

            k=right-1;                    if(k<1){
                continue;
            }
            rotate(arr,arrLen,k);
            rotations[rotationLen]=k;
            rotationLen++;
            k=0;
            break;

        default:
            break;
        }}return 0;
      /*  for (int i=0;i<rotationLen;i++){
            rotations[0]=       
        }
        
        int temp=arr[indexA];
        arr[indexB]=arr[indexA];
        arr[indexA]=temp;
        if (indexA>0){
        reverse(arr,arr+(indexA-1)+1);
        rotations[0]=indexA-1;
        rotationLen++;
        reverse(arr,arr+(indexA)+1);
        rotations[1]=indexA;
        rotationLen++;
        reverse(arr,arr+(indexB)+1);
        rotations[2]=indexB;
        rotationLen++;
        reverse(arr,arr+(indexB-indexA-1)+1);
        rotations[3]=indexB-indexA-1;
        rotationLen++;
        reverse(arr,arr+(indexB-indexA-2)+1);
        rotations[4]=indexB-indexA-2;
        rotationLen++;
        reverse(arr,arr+(indexB-1)+1);
        rotations[5]=indexB-1;
        rotationLen++;}else if(indexA==0){
            reverse(arr,arr+(indexB)+1);
            rotations[0]=indexB;
            rotationLen++;
        }*/
    }
    // End of Task 2 TODO
    
}

//Task 3
void sortAndRecord(int arr[], int arrLen, int rotations[], int &rotationLen)
{
    
    // Task 3 TODO
    bool swapped=false;
    vector<int>digits;
    do{
        swapped=false;
        for(int i=0;i< arrLen-1;i++){
            if(arr[i]>arr[i+1]){
                swapAndRecord(arr,arrLen,i,i+1,rotations,rotationLen);
                for(int j=0; j<rotationLen;j++){
                    //cout<<rotations[j]<<","<<endl;
                    digits.push_back(rotations[j]);
                }
                swapped=true;
            }
        
            }}while (swapped);
    rotationLen=digits.size();
    for (int i=0; i<rotationLen;i++){
        rotations[i]=digits[i];
    }
    // End of Task 3 TODO
}

//Task 4
int transformAndRecord(int src[], int tgt[], int arrLen, int rotations[], int &rotationLen)
{
    // Task 4 TODO
    int* source=src;
    int* target=tgt;
    bool swapped=false;
    vector<int>src_0;
    vector<int>tgt_0;    vector<int>digits;

    for (int i=0;i<arrLen;i++){
        src_0.push_back(src[i]);//copying original array to vector
        tgt_0.push_back(tgt[i]);
    	}/*
        do{
            swapped=false;
            for(int i=0;i<arrLen;i++){
                if(source[i]>source[i+1]){
                int temp=source[i];
                source[i]=source[i+1];
                source[i+1]=temp;
                swapped=true;
            }
   
            }
            }while (swapped); 

        do{
            swapped=false;
            for(int i=0;i<arrLen;i++){
                if(target[i]>target[i+1]){
                int temp=target[i];
                target[i]=target[i+1];
                target[i+1]=temp;
                swapped=true;
            }
            }
            }while (swapped); */

        sortAndRecord(src,arrLen,rotations,rotationLen);
        sortAndRecord(tgt,arrLen,rotations,rotationLen);

    for (int i=0;i<arrLen;i++){
    	if (source[i]!=target[i]){
            return -1;
    	}
    }
    for (int i=0;i<arrLen;i++){
        src[i]=src_0[i];//copying original array to src array
//        cout<<"src"<<i<<"="<<src[i]<<","<<source[i]<<endl;
        tgt[i]=tgt_0[i];
    	}
    
    for(int i=arrLen-1;i>-1;i--){
        while (src[i]!=tgt[i])
        {
            for(int j=0;j<=i;j++){
                swapAndRecord(src,arrLen,i,j,rotations,rotationLen);    
                 //cout<<rotations[j]<<","<<endl;
                for(int j=0; j<rotationLen;j++){
                    //cout<<rotations[j]<<","<<endl;
                    digits.push_back(rotations[j]);
                }
                if(src[j]!=tgt[j]){
                 swapAndRecord(src,arrLen,i,j,rotations,rotationLen);    
                for(int j=0; j<rotationLen;j++){
                    //cout<<rotations[j]<<","<<endl;
                    digits.push_back(rotations[j]);
                }
                }
            }
        }
        rotationLen=digits.size();
    for (int i=0; i<rotationLen;i++){
        rotations[i]=digits[i];
    }    
    }

       
    /*     for (int i=0;i<arrLen;i++){

        cout<<"src"<<i<<"="<<src[i]<<","<<source[i]<<endl;

    	}
    source=src;
    rotate(src,arrLen,1);
    rotations[rotationLen]=1;
    rotationLen++;
    rotate(src,arrLen,2);
    rotations[rotationLen]=2;
    rotationLen++;    rotate(src,arrLen,1);
    rotations[rotationLen]=1;
    rotationLen++;*/
    return 0;
    // End of Task 4 TODO
}

// DO NOT WRITE ANYTHING AFTER THIS LINE. ANYTHING AFTER THIS LINE WILL BE REPLACED

int init(int arr[], int arrLen)
{
    char buffer;
    cout << "? Please enter one digit at a time and press return:" << endl;
    for (int i = 0; i < arrLen; i++)
    {
        cin >> buffer;
        if (buffer > '9' || buffer < '0')
        {
            cout << "Error: Illegal digit input." << endl;
            return -1;
        }
        else
        {
            arr[i] = (int)buffer - 48;
        }
    }
    return 0;
}

void printArr(int arr[], int arrLen)
{
    for (int i = 0; i < arrLen; i++)
    {
        cout << arr[i];
        if (i < arrLen - 1)
        {
            cout << ',';
        }
    }
    cout << endl;
}

void runInit(int arr[], int &arrLen)
{
    cout << "##################################################" << endl;
    cout << "# Initializing" << endl;
    cout << endl;

    int initResult = -1;
    while (initResult < 0)
    {
        cout << "? Enter the length of your array:" << endl;
        cin >> arrLen;
        if (arrLen < 1)
        {
            cout << "! Error: Length should be larger than 0." << endl;
            continue;
        }
        else if (arrLen > MAX_ARR_LEN)
        {
            cout << "Error: arrLen of should be less than or equal to " << MAX_ARR_LEN << endl;
            continue;
        }
        cout << "? Enter " << arrLen << " elements of your array." << endl;
        initResult = init(arr, arrLen);
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    cout << "! Initialization succeeded!" << endl;
    cout << "! Printing the array:" << endl;
    cout << endl;
    printArr(arr, arrLen);
    cout << endl;
}

void runPrint(int arr[], int arrLen)
{
    cout << "##################################################" << endl;
    cout << "# Printing the array" << endl;
    cout << endl;
    printArr(arr, arrLen);
    cout << endl;
}

void runRotate(int arr[], int arrLen)
{
    int k, output;
    cout << "##################################################" << endl;
    cout << "# Rotating the array:" << endl;
    cout << "? Enter the index k:";
    cin >> k;
    output = rotate(arr, arrLen, k);
    if (output < 0)
    {
        cout << "! Error: Rotation failed." << endl;
    }
    else
    {
        cout << "! Rotated." << endl;
        cout << "! Array after rotation:" << endl;
        cout << endl;
        printArr(arr, arrLen);
        cout << endl;
    }
}

void runSwap(int arr[], int arrLen)
{
    int indexA, indexB, rotations[MAX_ROTATIONS], rotationLen, output;
    cout << "##################################################" << endl;
    cout << "# Swapping elements:" << endl;
    cout << "? Enter the 1st index:";
    cin >> indexA;
    cout << "? Enter the 2nd index:";
    cin >> indexB;
    output = swapAndRecord(arr, arrLen, indexA, indexB, rotations, rotationLen);
    if (output < 0)
    {
        cout << "! Error: Swap failed." << endl;
    }
    else
    {
        cout << "! Swapped." << endl;
        cout << "! Array after swap:" << endl;
        cout << endl;
        printArr(arr, arrLen);
        cout << endl;
        cout << "! Rotations:" << endl;
        cout << endl;
        printArr(rotations, rotationLen);
        cout << endl;
    }
}

void runSort(int arr[], int arrLen)
{
    int from, to, rotations[MAX_ROTATIONS], rotationLen, output;
    cout << "##################################################" << endl;
    cout << "# Sorting the array:" << endl;
    sortAndRecord(arr, arrLen, rotations, rotationLen);
    cout << "! Sorted." << endl;
    cout << "! Array after sorting:" << endl;
    cout << endl;
    printArr(arr, arrLen);
    cout << endl;
    cout << "! Rotations:" << endl;
    cout << endl;
    printArr(rotations, rotationLen);
    cout << endl;
}

void runTransform(int arr[], int arrLen)
{
    int from, to, rotations[MAX_ROTATIONS], rotationLen, output;
    cout << "##################################################" << endl;
    cout << "# Transforming src array to the tgt:" << endl;
    int tgt[MAX_ARR_LEN], initResult = -1;
    while (initResult < 0)
    {
        cout << "? Enter " << arrLen << " elements of the tgt array." << endl;
        initResult = init(tgt, arrLen);
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    cout << "! The target array:" << endl;
    cout << endl;
    printArr(tgt, arrLen);
    cout << endl;
    output = transformAndRecord(arr, tgt, arrLen, rotations, rotationLen);
    if (output < 0)
    {
        cout << "! Error: Cannot transform array to target." << endl;
    }
    else
    {
        cout << "! Transformed." << endl;
        cout << "! Array after transformation:" << endl;
        cout << endl;
        printArr(arr, arrLen);
        cout << endl;
        cout << "! Rotations:" << endl;
        cout << endl;
        printArr(rotations, rotationLen);
        cout << endl;
    }
}

void runOption()
{
    int arrLen = 0;
    bool is_initialized = false;
    int src[MAX_ARR_LEN];
    int tgt[MAX_ARR_LEN];
    int option;
    cout << "===========================================" << endl;
    cout << "= Welcome to COMP2011 PA1 1D Rubik's Cube =" << endl;
    cout << "===========================================" << endl;

    while (true)
    {
        if (!is_initialized)
        {
            runInit(src, arrLen);
            is_initialized = true;
        }
        else
        {
            cout << "##################################################" << endl;
            cout << "# Main Menu" << endl;
            cout << endl;
            cout << "1 Initialize" << endl;
            cout << "2 Print" << endl;
            cout << "3 Rotate" << endl;
            cout << "4 Swap" << endl;
            cout << "5 Sort" << endl;
            cout << "6 Transform" << endl;
            cout << "0 Exit" << endl;
            cout << endl;
            cout << "? Please enter an option (0-7): ";
            cin >> option;
            switch (option)
            {
            case 0:
                cout << "! Bye Bye." << endl;
                return;
            case 1:
                runInit(src, arrLen);
                break;
            case 2:
                runPrint(src, arrLen);
                break;
            case 3:
                runRotate(src, arrLen);
                break;
            case 4:
                runSwap(src, arrLen);
                break;
            case 5:
                runSort(src, arrLen);
                break;
            case 6:
                runTransform(src, arrLen);
                break;
            default:
                cout << "Illegal Choice, please try again." << endl;
                break;
            }
            cout << "! Returning to main menu." << endl;
        }
    }
}

int main()
{
    runOption();
    return 0;
}
