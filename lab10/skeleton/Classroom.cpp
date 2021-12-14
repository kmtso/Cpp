#include "Classroom.h"
#include <cstring>
#include <iostream>
using namespace std;

//====================
//Task 2: Implement the constructor
//  Copy ID and q to room_ID and quota, respectively
//  Initialize app_list and exam_list via 'new Course [MAX_NUM_COURSE_APP]'
//  Set num_app and num_exams to 0
Classroom::Classroom(char *ID, int q)
{
    //Put your code here
    room_ID=ID;
    quota=q;
    app_list=new Course[MAX_NUM_COURSE_APP];
    exam_list=new Course[MAX_NUM_COURSE_APP];
    num_app=0;
    num_exams=0;
}
//Implementaton of the destructor
Classroom::~Classroom()
{
    delete [] app_list;
    delete [] exam_list;
}

//===================
//Implementation of the accessor functions
char* Classroom::get_room_ID()
{
    return room_ID;
}

int Classroom::get_quota() const
{
    return quota;
}

Course* Classroom::get_app_list()
{   
    return app_list;
}

Course* Classroom::get_exam_list()
{
    return exam_list;
}

int Classroom::get_num_exams()
{
    return num_exams;
}

//Task 3: Implement the member function receive_app()
//  If the number of students of Course c is less than or equal to the quota of the classroom 
//  Add the c to app_list and increment num_app
void Classroom::receive_app(Course c)
{
    //Put your code here
    if(c.get_num_stu()<=quota){
        app_list[num_app]=c;
        num_app++;}
}

//Task 4: Implement the member function gen_time_table() using the greedy algorithm
//  Step 1: Sort the app_list according to the courses' end_time
//  Step 2: From the beginning of app_list,
//          if a course (in app_list) has no time conflicts with those courses already added in exam_list,
//          add it to exam_list and increment num_exams 
void Classroom::gen_timetable()
{
    //Put your code here
    bool swapped;
    Course temp;
         do{
            swapped=false;
            for(int i=0;i<num_app-1;i++){
               if(app_list[i].get_end_time()>app_list[i+1].get_end_time()){
                  temp=app_list[i];
                  app_list[i]=app_list[i+1];
                  app_list[i+1]=temp;
                  swapped=true;
                }
        
            }}while (swapped);
            /*for(int i=0;i<num_app;i++){
                cout<<app_list[i].get_start_time()<<" "<<app_list[i].get_end_time()<<endl;
            }*/
            exam_list[0]=app_list[0];
            num_exams++;
            bool added;
         do{
            added=false;
            for (int i=0;i<num_app;i++){
                if(exam_list[num_exams-1].get_end_time()<app_list[i].get_start_time())
                    {
                  //                      cout<<"exam"<<app_list[i].get_start_time()<<" "<<app_list[i].get_end_time()<<endl;

                    exam_list[num_exams]=app_list[i];
                    num_exams++;
                    added=true;
                    }
            }  }while (added);      
}

void Classroom::print_timetable()
{
    cout<<"========================================"<<endl;
    cout<<"Final Week Time Table of "<<room_ID<<endl;
    cout<<"========================================"<<endl;
    cout<<" Course ID\tCourse Name\tTime\t#Students"<<endl;
    for(int i=0; i<num_exams;i++)
    {
        Course c = exam_list[i];
        cout<<i<<" "<<c.get_course_ID()<<" "<<c.get_course_name()<<" "<<c.get_start_time()
            <<"--"<<c.get_end_time()<<" "<<c.get_num_stu()<<endl;
    }
    cout<<"========================================"<<endl;
    cout<<"Number of (Valid) Applications: "<<num_app<<endl;
    cout<<"Number of Exams: "<<num_exams<<endl;
}