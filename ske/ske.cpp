#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
#define MAX_NUM_STU 20

// TASK1: Merge two files into a new file.
void mergeFile(const string ip_filename1, const string ip_filename2, const string op_filename){
    ifstream ifs; ifs.open(ip_filename1);
    ifstream ifs2; ifs2.open(ip_filename2);
    ofstream ofs; ofs.open(op_filename);
    
    ofs<<ifs.rdbuf()<<'\n'<<ifs2.rdbuf();

    /*
    char c; ifs.get(c); // Try to get the first char
    while (!ifs.eof()) // Check if EOF is reached
    {
    ofs.put(c); // Copy one char at a time
    ifs.get(c); // Try to get the next char
    }
    char c2; ifs2.get(c2); // Try to get the first char
    while (!ifs2.eof()) // Check if EOF is reached
    {
    ofs.put(c2); // Copy one char at a time
    ifs.get(c2); // Try to get the next char
    }
    */
    ifs.close();
    ifs2.close();
    ofs.close();

}

// TASK2: Clean a given file and save it to a new file.
void cleanFile(const string ip_filename, const string op_filename){
    ifstream ifs; ifs.open(ip_filename);
    ofstream ofs; ofs.open(op_filename);
    stringstream buf;
    string str;
    string special_sym;
    vector <string> arr;
        vector <string> NotEmptyarr;

    string temp="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 ";
    const int MAX_SIZE = 128;
    int intArr[20]; // An integer array
    string strArr[20];
    char *totStrArr[40];
    int integer;
    string s;
    int EvenIndex=0;
    int oddIndex=0;
    int index=0; 
    do{
    getline(ifs,s);
        s.erase(remove_if(s.begin(), s.end(),
                        [&temp](const char &c) {
                            return temp.find(c) == std::string::npos;
                        }),
                        s.end());
    stringstream ss(s);
   if(index%2==0){
        
    }
    while(getline(ss, str,' ')){ //cout<<str;
            if(str=="")
                continue;
            arr.push_back(str);
        cout<< arr[index]<<","<<index<<endl;
        /*
    for(int i=0;i<arr.size();i++){
            if (arr[i]!=""){
                NotEmptyarr.push_back(arr[i]);

            }
       }*/
    if(index%2==1){
        ofs<<arr[index-1]<<' '<< arr[index]<<endl;   
    }
       /*if (index%2!=0){
            stringstream is(str);
            int i;
            is>>i;
            intArr[oddIndex]=i;
            oddIndex++;

        }
        //cout<< arr[EvenIndex];
        /*strcpy(totStrArr[index],str.c_str());
       cout << totStrArr[index];
      */

       EvenIndex+=2;
        index++;
    }     }while (!ifs.eof());        
        for(int i=1; i<arr.size();i+=2){

            //intArr[i]=stoi(arr[2+i]);//stoi string to int
            //cout<<intArr[i]<<endl;
            //strArr[i]=arr[i];
            //cout<<strArr[i]<<endl;
            //ofs<<strArr[i];
        }/*
        for(int j=0; j<temp.length();j++){
        }
            for(int i=1;i<NotEmptyarr.size();i++){
              ofs<<NotEmptyarr[index-1]<<' '<< NotEmptyarr[index]<<endl;   
            }
       
   // cout<<s;
   // buf << str;
    /*while(buf.eof()){
        buf>>temp;
                if (stringstream(temp) >> integer)
            cout << integer << " ";
            temp="";
    }*/
    ifs.close();
    ofs.close();

}

// TASK3: Analyze a file, that is, to find the two students who have got the lowest and the highest grade, respectively.
// If two or more students got the same lowest/highest grade, you only need to return the first-appeared ones.
void analyzeFile(const string filename, string &low_name, string &high_name, int &low_grade, int &high_grade){
    
    const int MAX_SIZE = 128;
    int x[MAX_SIZE]; // An integer array
    char ip_file[32]; // Input filename

    ifstream ifs; ifs.open(filename);
    ifs.close();

}

// Display a given file.
void displayFile(const string filename){
    string temp;
    ifstream ifs(filename);
    if (!ifs){
        cerr << "Error: Cannot open " << filename << endl;
        return;
    }
    
    cout << filename << endl;
    while (!ifs.eof()){
        getline(ifs, temp);
        cout << temp << endl;
    }
    cout << endl;
    ifs.close();
    return;
}

int main(){
    string low_name, high_name;
    int low_grade = 0, high_grade = 0;

    displayFile("record1.txt");
    displayFile("record2.txt");

    mergeFile("record1.txt", "record2.txt", "record.txt");
    displayFile("record.txt");

    cleanFile("record.txt", "record_clean.txt");
    displayFile("record_clean.txt");

    analyzeFile("record_clean.txt", low_name, high_name, low_grade, high_grade);
    cout << low_name << " got the lowest grade: " << low_grade << endl;
    cout << high_name << " got the highest grade: " << high_grade << endl;
    return 0;
}