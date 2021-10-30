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
bool is_available(int x,int y, const char result_map[MAP_HEIGHT][MAP_WIDTH],char temp_map[MAP_HEIGHT][MAP_WIDTH]){
   return ((y >= 0 && y <MAP_HEIGHT&&x >= 0 && x <MAP_WIDTH)&& result_map[y][x]==AVAILABLE && temp_map[y][x]!=VISITED);
   /*if(result_map[y][x]==AVAILABLE){
      return true;
   }else{ return false;}
   */
}
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

int visit_space(int x,int y, char result_map[MAP_HEIGHT][MAP_WIDTH],int& robot_energy,int& robot_full_energy, int& visited_times,char temp_map[MAP_HEIGHT][MAP_WIDTH]){
      
      if((result_map[y][x]==' '||result_map[y][x]=='R'||is_charger(x,y,result_map))&&result_map[y][x]!='B'){
         if(is_charger(x,y,result_map)){
            robot_energy=robot_full_energy;
            
         }
         if (!is_visited(x,y,result_map)){
            result_map[y][x]='V';   visited_times++;
            temp_map[y][x]='V';
            //cout<<visited_times<<endl;
         }
         
      } 
         return visited_times;
}
void count(char result_map[MAP_HEIGHT][MAP_WIDTH]){

}
void findShortestPath(int robot_x, int robot_y, int target_x, int target_y, int robot_energy, int robot_full_energy, const char map[MAP_HEIGHT][MAP_WIDTH], char temp_map[MAP_HEIGHT][MAP_WIDTH],int& min_distance, int distance){
   if(robot_x==target_x &&robot_y ==target_y){
      if (min_distance>=distance)
         {min_distance=distance;
         return;
         }
   }//if(robot_x!=target_x &&robot_y !=target_y&&(robot_energy==0)){min_distance=PA2_MAX_PATH};
   temp_map[robot_y][robot_x]=VISITED;
   //robot_energy--;
   //cout<<min_distance<<","<<distance;
   if (robot_energy>0&&is_available(robot_x,robot_y-1,map,temp_map)){
      findShortestPath(robot_x,robot_y-1,target_x,target_y,robot_energy-1,robot_full_energy,map,temp_map,min_distance,distance+1);
   }

      if (robot_energy>0&&is_available(robot_x+1,robot_y,map,temp_map)){
      findShortestPath(robot_x+1,robot_y,target_x,target_y,robot_energy-1,robot_full_energy,map,temp_map,min_distance,distance+1);
   }
      if (robot_energy>0&&is_available(robot_x,robot_y+1,map,temp_map)){
      findShortestPath(robot_x,robot_y+1,target_x,target_y,robot_energy-1,robot_full_energy,map,temp_map,min_distance,distance+1);
   }   if (robot_energy>0&&is_available(robot_x-1,robot_y,map,temp_map)){
      findShortestPath(robot_x-1,robot_y,target_x,target_y,robot_energy-1,robot_full_energy,map,temp_map,min_distance,distance+1);
   }
   temp_map[robot_y][robot_x]=AVAILABLE;
   
}

int findMaximumPlace(int robot_x, int robot_y, int robot_energy, int robot_full_energy, char result_map[MAP_HEIGHT][MAP_WIDTH], char temp_map[MAP_HEIGHT][MAP_WIDTH]);
int findMaximumPlace(int robot_x, int robot_y, int robot_energy, int robot_full_energy, char result_map[MAP_HEIGHT][MAP_WIDTH], char temp_map[MAP_HEIGHT][MAP_WIDTH]){
   int visited_times=0;
       if(robot_x<0||robot_y<0||robot_x>MAP_WIDTH||robot_y>MAP_HEIGHT){
        return 0;//base case
    }else{
       if(robot_energy==robot_full_energy){
         result_map[robot_y][robot_x]==VISITED;
       }
        visit_space(robot_x,robot_y,result_map,robot_energy,robot_full_energy,visited_times,temp_map);
         robot_energy--;

        
         
    }

    if (robot_energy>-1&&is_visited(robot_x,robot_y,result_map)){//if (robot_energy==0) 

       findMaximumPlace(robot_x,robot_y-1, robot_energy,robot_full_energy,result_map,temp_map);//up
        findMaximumPlace(robot_x+1,robot_y, robot_energy,robot_full_energy,result_map,temp_map);//right      
   
       findMaximumPlace(robot_x,robot_y+1, robot_energy,robot_full_energy,result_map,temp_map);//down
       findMaximumPlace(robot_x-1,robot_y, robot_energy,robot_full_energy,result_map,temp_map);//left
       
      } 
      copyMap(temp_map,result_map);
   return  visit_space(robot_x,robot_y,result_map,robot_energy,robot_full_energy,visited_times,temp_map);
}
int findShortestDistance(int robot_x, int robot_y, int target_x, int target_y, int robot_energy, int robot_full_energy, const char map[MAP_HEIGHT][MAP_WIDTH], char temp_map[MAP_HEIGHT][MAP_WIDTH]){
   int d_y=robot_y-target_y;
   int d_x=robot_x-target_x;
      if(robot_x<0||robot_y<0||robot_x>MAP_WIDTH||robot_y>MAP_HEIGHT){
          return 0;//base case
      }
      /*
      if(d_y==0 && d_x==0){
         return 1;
      }*/
      //temp_map[robot_y][robot_x]=VISITED;
      int min_distance=144;
      /*min_distance=*/findShortestPath(robot_x,robot_y,target_x,target_y,robot_energy,robot_full_energy,map,temp_map,min_distance,1);
      //cout<<min_distance;
      if(min_distance!=PA2_MAX_PATH){
         return min_distance;
      }
      
      /*else if(robot_energy>0 &&(d_y>=0||d_x>=0){
         if(d_)
        visit_space(robot_x,robot_y,result_map,robot_energy,robot_full_energy,visited_times,temp_map);

      }*/
   return min_distance;
}
int findPathSequence(int robot_x, int robot_y, int target_x, int target_y, int robot_energy, int robot_full_energy, char result_sequence[], const char map[MAP_HEIGHT][MAP_WIDTH], char temp_map[MAP_HEIGHT][MAP_WIDTH]){
   return 0;
}
int findFarthestPossibleCharger(int robot_x, int robot_y, int robot_original_x, int robot_original_y, int &target_x, int &target_y, int robot_energy, int robot_full_energy, const char map[MAP_HEIGHT][MAP_WIDTH], char temp_map[MAP_HEIGHT][MAP_WIDTH]){
   return 0;
}
