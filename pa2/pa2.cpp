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
int findMaximumPlace(int robot_x, int robot_y, int robot_energy, int robot_full_energy, char result_map[MAP_HEIGHT][MAP_WIDTH], char temp_map[MAP_HEIGHT][MAP_WIDTH]);
int findMaximumPlace(int robot_x, int robot_y, int robot_energy, int robot_full_energy, char result_map[MAP_HEIGHT][MAP_WIDTH], char temp_map[MAP_HEIGHT][MAP_WIDTH]){
   int visited_times=0;
       if(robot_x<0||robot_y<0||robot_x>MAP_WIDTH||robot_y>MAP_HEIGHT){
        return;
    }else{
        visit_space(robot_x,robot_y,result_map);//base case
        visited_times++;
    }
   return visited_times;
}
bool is_visited(int x,int y, char result_map[MAP_HEIGHT][MAP_WIDTH]){
   if(result_map[y][x]=='V'){
      return true;
   }else{ return false;}
}
void visit_space(int x,int y, char result_map[MAP_HEIGHT][MAP_WIDTH]){
      if(result_map[y][x]==' '){
         result_map[y][x]='V';   }
}
bool is_charger(int x,int y, char result_map[MAP_HEIGHT][MAP_WIDTH]){
   if(result_map[y][x]=='C'){
      return true;
   }else{ return false;}
}