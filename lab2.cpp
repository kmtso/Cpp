// https://magisterrex.files.wordpress.com/2014/07/mastermindrules.pdf
// Cindy https://www.youtube.com/watch?v=dMHxyulGrEk

#include <iostream> 
#include <cstdlib>
#include <time.h>  
using namespace std;

int main() 
{
    srand( time(NULL) );
    //Codemaker's choice of a random 4-color combination among six colors 
    // 1 Yellow, 2 Orange, 3 black, 4 Green, 5 Blue, 6 Purple
    int p0 = rand() % 6 + 1; // 1 to 6
    int p1 = rand() % 6 + 1; // 1 to 6
    int p2 = rand() % 6 + 1; // 1 to 6
    int p3 = rand() % 6 + 1; // 1 to 6

    // variable for code breaker's guess
    int g0;
    int g1;
    int g2;
    int g3;

    // variable for codemaker's response
    // red: correct color and correct position
    // white: correct color but wrong position
    // red overrides white
    int redpin;
    int whitepin=0;

    //you may declare additional variables here  to help you solve the problem:
    







    
    bool debug = true;
    bool isGameover=false;
    int attempt=0;
    cout << "==============================" << endl;
    cout << "Welcome to the Mastermind Game" << endl;
    cout << "==============================" << endl;
    if (debug){
        cout << "Coder maker's colors:" << endl;
        cout << "p0=" << p0 << "\tp1=" << p1 << "\tp2=" << p2 << "\tp3=" << p3 << endl << endl;
    }

    cout << "Code maker has made his choice." << endl;
    cout << "Code breaker, you have 12 attempts to crack his code." << endl;
    cout << "Game starts!" << endl << endl; 

    while(!isGameover){
        
        // Write your code below this section:

        cout << "Attempt "<< ++attempt << "\nPlease input your guess:" <<whitepin<< endl;
        cin >> g0 >> g1 >> g2 >> g3;
        
        //cin >> g1;
        //cin >> g2;
        //cin >> g3;

        if(g0 == p0 || g0 == p1 || g0 ==p2 || g0 ==p3){
            cout << "great" << whitepin << endl;
            if(g0 == p0 )
                redpin++;
            else if ((g0==p1 && g1!=p1)||(g0==p2 && g2!=p2)||(g0==p3 && g3!=p3))
                whitepin++;
            cout<< "Red pins:"<< redpin << ", White pins:" << whitepin <<endl;
        }
        if(g1 == p0 || g1 == p1 || g1 == p2 || g1 == p3){
            cout << "great" << endl;
            if(g1 == p1){
                redpin++;
            }else if ((g1==p0 && g0!=p0)||(g1==p2 && g2!=p2)||(g1==p3 && g3!=p3))
            {whitepin++;}
            cout<< "Red pins:"<< redpin << ", White pins:" << whitepin <<endl;
        }
        if(g2 == p0 || g2 == p1 || g2 == p2 || g2 == p3){
            cout << "great" << endl;
            if(g2 == p2)
                redpin++;
            else if ((g2==p0 && g0!=p0)||(g2==p1 && g1!=p1)||(g2==p3 && g3!=p3))
                whitepin++;
            cout<< "Red pins:"<< redpin << ", White pins:" << whitepin <<endl;
        }
        if(g3 == p0 || g3 == p1 || g3 == p2 || g3 == p3){
            cout << "great" << endl;
            if(g3 == p3)
                redpin++;
            else if ((g3==p0 && g0!=p0)||(g3==p1 && g1!=p1)||(g3==p2 && g2!=p2))
                whitepin++;
            cout<< "Red pins:"<< redpin << ", White pins:" << whitepin <<endl;
        }
        if (redpin ==4){
            cout<< "Code breaker, you have " << attempt <<" attempts to crack his code." << endl;
            isGameover=true;
        }else{
            redpin=0;
            whitepin=0;
        }
        if(attempt==12){
            isGameover=true;
            // Player runs out of attempts and loses 
            cout << "Sorry, you ran out of turns :( "<< endl; 
        }
    }
    if (isGameover)
        cout<<"game over! Thank you for your playing";
    return 0;
}