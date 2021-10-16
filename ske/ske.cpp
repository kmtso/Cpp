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
    string str;
    vector <string> arr;
    string temp="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 ";
    string s;

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
    while(getline(ss, str,' ')){
            if(str=="")
                continue;
            arr.push_back(str);
        //cout<< arr[index]<<","<<index<<endl;

    if(index%2==1){
        ofs<<arr[index-1]<<' '<< arr[index]<<endl;   
    }
        index++;
    }     }while (!ifs.eof());        
        for(int i=1; i<arr.size();i+=2){
        }
    ifs.close();
    ofs.close();

}

// TASK3: Analyze a file, that is, to find the two students who have got the lowest and the highest grade, respectively.
// If two or more students got the same lowest/highest grade, you only need to return the first-appeared ones.
void analyzeFile(const string filename, string &low_name, string &high_name, int &low_grade, int &high_grade){
    ifstream ifs; ifs.open(filename);
    string line;
            int low_temp=100;
            int high_temp=0;
            while (!ifs.eof())
        {
            getline(ifs,line);
            string name;
            int grade;    
            stringstream ss;

            ss.str(line);
            ss >> name >> grade;
            if(grade>high_temp){
                high_grade=grade;
                high_name=name;
                high_temp=grade;
            }
            if (grade<low_temp){
                low_grade=grade;
                low_name=name;
                low_temp=grade;
            }
            

        }
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