#include <iostream>
#include <cstring>
#include "cleaning_robot.h"
using namespace std;

/*
   * Student name: TSO KEI MING
   *
   * Student ID: 20791992
   *
   * Student email: kmtso@ust.hk   
   * 
   * You are not allowed to use extra library
*/

// Please do all your work in this file. You just need to submit this file.
bool is_visited(int,int, char, char);
bool is_visited(int x,int y, char result_map[MAP_HEIGHT][MAP_WIDTH]){
   if(result_map[y][x]=='V'){
      return true;
   }else{ return false;}
}
bool is_charger(int x,int y, char result_map[MAP_HEIGHT][MAP_WIDTH]){
   if(result_map[y][x]=='C'){
      return true;
   }else{ return false;}
}
void visit_space(int x,int y, char result_map[MAP_HEIGHT][MAP_WIDTH],int& robot_energy,int& robot_full_energy){
      if((result_map[y][x]==' '||result_map[y][x]=='R'||is_charger(x,y,result_map))&&result_map[y][x]!='B'){
         if(is_charger(x,y,result_map)){
            robot_energy=robot_full_energy;
         }
         result_map[y][x]='V';   

         } 
         
}


int findMaximumPlace(int robot_x, int robot_y, int robot_energy, int robot_full_energy, char result_map[MAP_HEIGHT][MAP_WIDTH], char temp_map[MAP_HEIGHT][MAP_WIDTH]);
int findMaximumPlace(int robot_x, int robot_y, int robot_energy, int robot_full_energy, char result_map[MAP_HEIGHT][MAP_WIDTH], char temp_map[MAP_HEIGHT][MAP_WIDTH]){
   int visited_times=0;
       if(robot_x<0||robot_y<0||robot_x>MAP_WIDTH||robot_y>MAP_HEIGHT){
        return 0;
    }else{
       if(robot_energy==robot_full_energy){
         result_map[robot_y][robot_x]==ROBOT;
       }
        visit_space(robot_x,robot_y,result_map,robot_energy,robot_full_energy);//base case
         robot_energy--;
        visited_times++;
        
    }

    if (robot_energy>-1&&is_visited(robot_x,robot_y,result_map)){
       findMaximumPlace(robot_x,robot_y-1, robot_energy,robot_full_energy,result_map,temp_map);//up
        findMaximumPlace(robot_x+1,robot_y, robot_energy,robot_full_energy,result_map,temp_map);//right      
   
       findMaximumPlace(robot_x,robot_y+1, robot_energy,robot_full_energy,result_map,temp_map);//down
       findMaximumPlace(robot_x-1,robot_y, robot_energy,robot_full_energy,result_map,temp_map);//left
      } 
   return visited_times;
}
int findShortestDistance(int robot_x, int robot_y, int target_x, int target_y, int robot_energy, int robot_full_energy, const char map[MAP_HEIGHT][MAP_WIDTH], char temp_map[MAP_HEIGHT][MAP_WIDTH]){
   return 0;
}
int findPathSequence(int robot_x, int robot_y, int target_x, int target_y, int robot_energy, int robot_full_energy, char result_sequence[], const char map[MAP_HEIGHT][MAP_WIDTH], char temp_map[MAP_HEIGHT][MAP_WIDTH]){
   return 0;
}
int findFarthestPossibleCharger(int robot_x, int robot_y, int robot_original_x, int robot_original_y, int &target_x, int &target_y, int robot_energy, int robot_full_energy, const char map[MAP_HEIGHT][MAP_WIDTH], char temp_map[MAP_HEIGHT][MAP_WIDTH]){
   return 0;
}
