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
void pop(char* temp_squence[MAX_STRING_SIZE]){
   char* a_squence[MAX_STRING_SIZE]={};
   //a_squence=temp_squence;


}
bool is_available(int x,int y, const char result_map[MAP_HEIGHT][MAP_WIDTH],char temp_map[MAP_HEIGHT][MAP_WIDTH]){
   return ((y >= 0 && y <MAP_HEIGHT&&x >= 0 && x <MAP_WIDTH)&& result_map[y][x]==AVAILABLE||result_map[y][x]==CHARGER && temp_map[y][x]!=VISITED);
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

int visit_space(int x,int y, char result_map[MAP_HEIGHT][MAP_WIDTH],int& robot_energy,int& robot_full_energy, int& visited_times,char countV[],char temp_map[][MAP_WIDTH]){
      
      if((result_map[y][x]==' '||result_map[y][x]=='R'||is_charger(x,y,result_map))&&result_map[y][x]!='B'){
         if(is_charger(x,y,result_map)){
            robot_energy=robot_full_energy;
            
         }
         if (!is_visited(x,y,result_map)){
            result_map[y][x]='V';   visited_times++;
            //temp_map[y][x]='V';
            strcat(countV,"V");
            //cout<<visited_times<<endl;
         }
         
      } 
   return(strlen(countV));
}
void count(char result_map[MAP_HEIGHT][MAP_WIDTH]){

}
bool is_target(int robot_x, int robot_y, int target_x, int target_y){
   return robot_x==target_x &&robot_y ==target_y;
}
void findShortestPath(int robot_x, int robot_y, int target_x, int target_y, int robot_energy, int robot_full_energy, const char map[MAP_HEIGHT][MAP_WIDTH], char temp_map[MAP_HEIGHT][MAP_WIDTH],int& min_distance, int distance){

   if(robot_x==target_x &&robot_y ==target_y){
      if (min_distance>=distance)
         {min_distance=distance;
         //printMap(temp_map);

         return;
         }
   }//if(robot_x!=target_x &&robot_y !=target_y&&(robot_energy==0)){min_distance=PA2_MAX_PATH};
         if(map[robot_y][robot_x]==CHARGER){
            robot_energy=robot_full_energy;
         }
   temp_map[robot_y][robot_x]=VISITED;
   //robot_energy--;
   //cout<<min_distance<<","<<distance;
   

   if (robot_energy>0&&is_available(robot_x,robot_y-1,map,temp_map)){
      findShortestPath(robot_x,robot_y-1,target_x,target_y,robot_energy-1,robot_full_energy,map,temp_map,min_distance,distance+1);

   }

      if (robot_energy>0&&is_available(robot_x+1,robot_y,map,temp_map)&&!is_target(robot_x,robot_y+1,target_x,target_y)&&!is_target(robot_x-1,robot_y,target_x,target_y)){
      findShortestPath(robot_x+1,robot_y,target_x,target_y,robot_energy-1,robot_full_energy,map,temp_map,min_distance,distance+1);
   }
      if (robot_energy>0&&is_available(robot_x,robot_y+1,map,temp_map)){
      findShortestPath(robot_x,robot_y+1,target_x,target_y,robot_energy-1,robot_full_energy,map,temp_map,min_distance,distance+1);
   }   

   if (robot_energy>0&&is_available(robot_x-1,robot_y,map,temp_map)){
      findShortestPath(robot_x-1,robot_y,target_x,target_y,robot_energy-1,robot_full_energy,map,temp_map,min_distance,distance+1);
   }
   temp_map[robot_y][robot_x]=AVAILABLE;

}
//task3
void findShortestPath(int robot_x, int robot_y, int target_x, int target_y, int robot_energy, int robot_full_energy, const char map[MAP_HEIGHT][MAP_WIDTH], char temp_map[MAP_HEIGHT][MAP_WIDTH],int& min_distance, int distance,char result_sequence[],int can_visit,char temp_sqeunence[]){
   temp_map[robot_y][robot_x]=VISITED;
         if(map[robot_y][robot_x]==CHARGER){
         robot_energy=robot_full_energy;
      }
      if(robot_energy==0&&(robot_x!=target_x &&robot_y !=target_y)){//strlen(temp_sqeunence)>min_distance&&

      //cout<< robot_energy;
      //cout<<temp_sqeunence;
      if(map[robot_y][robot_x]==CHARGER){
         robot_energy=robot_full_energy;
      }
      //if (robot_energy==0)
        // strcpy(temp_sqeunence,"");
   }
   //   cout<<(temp_sqeunence)<<"("<<robot_x<<","<<robot_y<<")"<<"-energy remain"<<robot_energy<<"\n";

if(distance==min_distance){

}
   int difference_y=target_y-robot_y;
   int difference_x=target_x-robot_x;

   if (min_distance==1 && robot_x==target_x &&robot_y ==target_y ){//robot_energy==robot_full_energy
      //printMap(temp_map);
      strcpy(result_sequence,"T");
      //return temp_sqeunence;
   }      
   if((robot_x==target_x &&robot_y ==target_y)){
      strcat(temp_sqeunence,"T");
      //cout<<(temp_sqeunence)<<"\n";
      //cout<<distance<<"\n";            printMap(temp_map);

      if(distance==min_distance&&strlen(temp_sqeunence)==min_distance){
        // if(strlen(temp_sqeunence)+1==min_distance){
            strcpy(result_sequence,temp_sqeunence);
            return;
         }//else {strcpy(temp_sqeunence,"");}
      //}
      //}
      
   }  



   //robot_energy--;
   //cout<<min_distance<<","<<distance;
      temp_map[robot_y][robot_x]=VISITED;
//cout<<!(robot_x==target_x &&robot_y ==target_y)<<endl;
   if(!(robot_x==target_x &&robot_y ==target_y)&&distance<min_distance){
//if (difference_y<0){//||!is_available(robot_x+1,robot_y,map,temp_map)&&!is_available(robot_x,robot_y+1,map,temp_map)&&!is_available(robot_x-1,robot_y,map,temp_map)
   if (robot_energy>0&&is_available(robot_x,robot_y-1,map,temp_map)){//&&!is_target(robot_x,robot_y+1,target_x,target_y)&&!is_target(robot_x-1,robot_y,target_x,target_y)&&!is_target(robot_x+1,robot_y,target_x,target_y)){//&&!is_target(robot_x,robot_y+1,target_x,target_y)&&!is_target(robot_x-1,robot_y,target_x,target_y)&&!is_target(robot_x+1,robot_y,target_x,target_y)
            strcat(temp_sqeunence,"U");
      findShortestPath(robot_x,robot_y-1,target_x,target_y,robot_energy-1,robot_full_energy,map,temp_map,min_distance,distance+1,result_sequence,can_visit-1,temp_sqeunence);

   }
//}

//if (difference_x>0&&(difference_y<0&&is_available(robot_x+1,robot_y-1,map,temp_map)||is_available(robot_x+1,robot_y+1,map,temp_map))||difference_x>=0&&difference_y<0&&!is_available(robot_x,robot_y-1,map,temp_map)||difference_x<=0&&difference_y>0&&!is_available(robot_x-1,robot_y+1,map,temp_map)
//){//||difference_x>=0&&||!is_available(robot_x,robot_y-1,map,temp_map)&&!is_available(robot_x-1,robot_y,map,temp_map)&&!is_available(robot_x,robot_y+1,map,temp_map)&&

   if (robot_energy>0&&is_available(robot_x+1,robot_y,map,temp_map)){//&&!is_target(robot_x,robot_y+1,target_x,target_y)&&!is_target(robot_x-1,robot_y,target_x,target_y)){//&&!is_target(robot_x,robot_y+1,target_x,target_y)&&!is_target(robot_x-1,robot_y,target_x,target_y)
      strcat(temp_sqeunence,"R");
      findShortestPath(robot_x+1,robot_y,target_x,target_y,robot_energy-1,robot_full_energy,map,temp_map,min_distance,distance+1,result_sequence,can_visit-1,temp_sqeunence);
   }
//}
//if (difference_y>0||difference_y<0&&!is_available(robot_x+1,robot_y,map,temp_map)&&!is_available(robot_x,robot_y-1,map,temp_map)||difference_x>0&&!is_available(robot_x+1,robot_y,map,temp_map)){//||!is_available(robot_x+1,robot_y,map,temp_map)&&!is_available(robot_x,robot_y-1,map,temp_map)){//&&!is_available(robot_x-1,robot_y,map,temp_map)
   if (robot_energy>0&&is_available(robot_x,robot_y+1,map,temp_map)){  //&&!is_target(robot_x-1,robot_y,target_x,target_y) 
      strcat(temp_sqeunence,"D");
      findShortestPath(robot_x,robot_y+1,target_x,target_y,robot_energy-1,robot_full_energy,map,temp_map,min_distance,distance+1,result_sequence,can_visit-1,temp_sqeunence);

   }  
//}
//if (difference_x<0&&(difference_y<0&&is_available(robot_x-1,robot_y-1,map,temp_map))||(difference_y>0&&is_available(robot_x-1,robot_y+1,map,temp_map))||difference_x>=0&&difference_y>0&&!is_available(robot_x+1,robot_y+1,map,temp_map)){//||difference_y>0&&!is_available(robot_x+1,robot_y+1,map,temp_map)||difference_y>0&&!is_available(robot_x+1,robot_y+1,map,temp_map)){//||!is_available(robot_x+1,robot_y,map,temp_map)&&!is_available(robot_x,robot_y-1,map,temp_map)&&!is_available(robot_y+1,robot_y,map,temp_map)){

   if (robot_energy>0&&is_available(robot_x-1,robot_y,map,temp_map)){//&&!is_target(robot_x,robot_y+1,target_x,target_y)){
      strcat(temp_sqeunence,"L");
      findShortestPath(robot_x-1,robot_y,target_x,target_y,robot_energy-1,robot_full_energy,map,temp_map,min_distance,distance+1,result_sequence,can_visit-1,temp_sqeunence);
   }
//} 
} 
int a=strlen(temp_sqeunence)-1;
   temp_map[robot_y][robot_x]=AVAILABLE;
   strncpy(temp_sqeunence,temp_sqeunence,a);
   temp_sqeunence[a]='\0';



}
void backtrack(int robot_x, int robot_y, int target_x, int target_y, int robot_energy, int robot_full_energy, const char map[MAP_HEIGHT][MAP_WIDTH], char temp_map[MAP_HEIGHT][MAP_WIDTH],int& min_distance, int distance){

}
bool is_start(int visited_time){
   return visited_time;
}
int counting(int*counter){
   (*counter)++;
   return *counter;

}         int visited_times=0;

int findMaximumPlace(int robot_x, int robot_y, int robot_energy, int robot_full_energy, char result_map[MAP_HEIGHT][MAP_WIDTH], char temp_map[MAP_HEIGHT][MAP_WIDTH], int& count){
      char countV[MAX_STRING_SIZE]={};

   //cout<< count<<endl;
   
   if(robot_x<0||robot_y<0||robot_x>MAP_WIDTH||robot_y>MAP_HEIGHT){
        return 0;//base case
    }else{
       if(robot_energy==robot_full_energy){
         result_map[robot_y][robot_x]==VISITED;
       }
        visit_space(robot_x,robot_y,result_map,robot_energy,robot_full_energy,count,countV, temp_map);
        //cout<<visited_times<<endl;
         //robot_energy--;  
        
         //strcat(countV,"V");
    }
    if (robot_energy>0&&is_visited(robot_x,robot_y,result_map)){//if (robot_energy==0) 
       findMaximumPlace(robot_x,robot_y-1, robot_energy-1,robot_full_energy,result_map,temp_map,count);//up
        findMaximumPlace(robot_x+1,robot_y, robot_energy-1,robot_full_energy,result_map,temp_map,count);//right      
   
       findMaximumPlace(robot_x,robot_y+1, robot_energy-1,robot_full_energy,result_map,temp_map,count);//down
       findMaximumPlace(robot_x-1,robot_y, robot_energy-1,robot_full_energy,result_map,temp_map,count);//left
       
    }
    return count;
}
int findMaximumPlace(int robot_x, int robot_y, int robot_energy, int robot_full_energy, char result_map[MAP_HEIGHT][MAP_WIDTH], char temp_map[MAP_HEIGHT][MAP_WIDTH]){
      int visited_times=0;
      char countV[MAX_STRING_SIZE]={};



   findMaximumPlace(robot_x,robot_y, robot_energy,robot_full_energy,result_map,temp_map,visited_times);

    return    findMaximumPlace(robot_x,robot_y, robot_energy,robot_full_energy,result_map,temp_map,visited_times);
;
} 

int findShortestDistance(int robot_x, int robot_y, int target_x, int target_y, int robot_energy, int robot_full_energy, const char map[MAP_HEIGHT][MAP_WIDTH], char temp_map[MAP_HEIGHT][MAP_WIDTH]){
   int d_y=robot_y-target_y;
   int d_x=robot_x-target_x;
      if(robot_x<0||robot_y<0||robot_x>MAP_WIDTH||robot_y>MAP_HEIGHT){
          return 0;//base case
      }

      int min_distance=144;
      //cout<<robot_x<<","<<robot_y<<","<<target_x<<","<<target_y;
      findShortestPath(robot_x,robot_y,target_x,target_y,robot_energy,robot_full_energy,map,temp_map,min_distance,1);

      if(min_distance!=PA2_MAX_PATH){
         return min_distance;
      }
   //cout<<min_distance;
   return min_distance;
}
int findPathSequence(int robot_x, int robot_y, int target_x, int target_y, int robot_energy, int robot_full_energy, char result_sequence[], const char map[MAP_HEIGHT][MAP_WIDTH], char temp_map[MAP_HEIGHT][MAP_WIDTH]){
   int min_distance=findShortestDistance(robot_x,robot_y,target_x,target_y,robot_energy,robot_full_energy,map,temp_map);
   if (min_distance==PA2_MAX_PATH){
      return min_distance;
   }
   int can_visited=min_distance;
   char temp_sqeunence[MAX_STRING_SIZE] = "";
   findShortestPath(robot_x,robot_y,target_x,target_y,robot_energy,robot_full_energy,map,temp_map,min_distance,1,result_sequence,can_visited,temp_sqeunence);

   /*
   if (min_distance==1 && robot_energy==robot_full_energy){
      strcpy(result_sequence,"T");
      return min_distance;
   }
   if(map[robot_y][robot_x]==CHARGER){
      robot_energy=robot_full_energy;
   }
   temp_map[robot_y][robot_x]=VISITED;
      if (robot_energy>0&&is_available(robot_x,robot_y-1,map,temp_map)&&min_distance>1){
            findShortestPath(robot_x+1,robot_y,target_x,target_y,robot_energy-1,robot_full_energy,map,temp_map,min_distance,1,result_sequence,can_visited);
            strcat(result_sequence,"U");
            //can_visited--;
      }
*/
   //if(can_visited==1)
   //strcat(result_sequence,"T");
   return min_distance;
}int findFarthestPossibleCharger(int robot_x, int robot_y, int robot_original_x, int robot_original_y, int &target_x, int &target_y, int robot_energy, int robot_full_energy, const char map[MAP_HEIGHT][MAP_WIDTH], char temp_map[MAP_HEIGHT][MAP_WIDTH],char result_map[MAP_HEIGHT][MAP_WIDTH], int robot_original_energy){
   int count;
  char countV[MAX_STRING_SIZE];
   //cout<<findShortestDistance(robot_original_x,robot_original_y,7, 7, robot_full_energy,robot_full_energy,map,temp_map);
            cout<<findShortestDistance(robot_original_x,robot_original_y,target_x, target_y,robot_original_energy,robot_full_energy,map,temp_map)<<"target("<<target_x<<","<<target_y<<")"<<"robot——0("<<robot_original_x<<","<<robot_original_y<<")"<<endl;

   if(robot_x<0||robot_y<0||robot_x>MAP_WIDTH||robot_y>MAP_HEIGHT){
        return -1;//base case
    }//else{
       if(robot_energy==robot_full_energy){
         result_map[robot_y][robot_x]==VISITED;
       }
          /* code */visit_space(robot_x,robot_y,result_map,robot_energy,robot_full_energy,count,countV, temp_map);
       
       
                 //cout<<"("<<robot_x<<","<<robot_y<<")";

         if (map[robot_y][robot_x]==CHARGER){
            if (target_y==-1&&target_x==-1){
               target_x=robot_x;
               target_y=robot_y;
               //findShortestDistance(robot_original_x,robot_original_y,7, 7,robot_original_energy ,robot_full_energy,map,temp_map);
         //min_distance=PA2_MAX_PATH;//findShortestDistance(robot_original_x,robot_original_y,target_x, target_y, robot_energy,robot_full_energy,map,temp_map);
         cout<<"robot("<<robot_x<<","<<robot_y<<")";
                  cout<<"target("<<target_x<<","<<target_y<<")";

            }
         //cout<<target_y;
         //cout<<findShortestDistance(robot_original_x,robot_original_y,robot_x, robot_y,robot_original_energy,robot_full_energy,map,temp_map)<<"robot("<<robot_x<<","<<robot_y<<")"<<"robot——0("<<robot_original_x<<","<<robot_original_y<<")"<<endl;
            if (findShortestDistance(robot_original_x,robot_original_y,robot_x, robot_y, robot_original_energy,robot_full_energy,map,temp_map)>findShortestDistance(robot_original_x,robot_original_y,target_x, target_y, robot_energy,robot_full_energy,map,temp_map)){
               target_x=robot_x;
               target_y=robot_y;
            findShortestDistance(robot_original_x,robot_original_y,target_x, target_y,robot_original_energy,robot_full_energy,map,temp_map);
            } 
         } 
    
    if (robot_energy>0&&is_visited(robot_x,robot_y,result_map)){//if (robot_energy==0) 
       findFarthestPossibleCharger(robot_x,robot_y-1,robot_original_x,robot_original_y, target_x,target_y,robot_energy-1,robot_full_energy,map,temp_map,result_map,robot_original_energy);//up
       findFarthestPossibleCharger(robot_x+1,robot_y, robot_original_x,robot_original_y, target_x,target_y,robot_energy-1,robot_full_energy,map,temp_map,result_map,robot_original_energy);//right      
   
       findFarthestPossibleCharger(robot_x,robot_y+1, robot_original_x,robot_original_y, target_x,target_y,robot_energy-1,robot_full_energy,map,temp_map,result_map,robot_original_energy);//down
       findFarthestPossibleCharger(robot_x-1,robot_y, robot_original_x,robot_original_y, target_x,target_y,robot_energy-1,robot_full_energy,map,temp_map,result_map,robot_original_energy);//left
       
    }
    return findShortestDistance(robot_original_x,robot_original_y,7,7, robot_full_energy,robot_full_energy,map,temp_map);

}
int findFarthestPossibleCharger(int robot_x, int robot_y, int robot_original_x, int robot_original_y, int &target_x, int &target_y, int robot_energy, int robot_full_energy, const char map[MAP_HEIGHT][MAP_WIDTH], char temp_map[MAP_HEIGHT][MAP_WIDTH]){
   //int min_distance=PA2_MAX_PATH;
 //  int min_distance=findShortestDistance(robot_x,robot_y,7,7,robot_energy,robot_full_energy,map,temp_map);
   char result_map[MAP_HEIGHT][MAP_WIDTH]={};
   copyMap(result_map,map);
     int robot_original_energy=robot_energy;

   int min_distance=findFarthestPossibleCharger(robot_x,robot_y, robot_original_x,robot_original_y, target_x,target_y,robot_energy,robot_full_energy,map,temp_map,result_map,robot_original_energy);
   printMap(result_map);
     /* char result_map[MAP_HEIGHT][MAP_WIDTH]={};
      int count=0;
      char countV[MAX_STRING_SIZE];
      //robot_energy=robot_full_energy;
      copyMap(result_map,map);
      int min_distance=PA2_MAX_PATH;
      if(robot_x<0||robot_y<0||robot_x>MAP_WIDTH||robot_y>MAP_HEIGHT){
        return -1;//base case
    }//else{
       if(robot_energy==robot_full_energy){
         result_map[robot_y][robot_x]==VISITED;
       }
        visit_space(robot_x,robot_y,result_map,robot_energy,robot_full_energy,count,countV, temp_map);
        //cout<<visited_times<<endl;
        // robot_energy--;  
        
         //strcat(countV,"V");
         //if(robot_energy==0)
          //  printMap(result_map);
    //}
      if (map[robot_y][robot_x]==CHARGER){
         if (target_y==-1&&target_x==-1){
         target_x=robot_x;
         target_y=robot_y;
         min_distance=findShortestPath(robot_original_x,robot_original_y,target_x, target_y, robot_energy,robot_full_energy,map,temp_map,min_distance,1);
         //min_distance=PA2_MAX_PATH;//findShortestDistance(robot_original_x,robot_original_y,target_x, target_y, robot_energy,robot_full_energy,map,temp_map);
         cout<<"("<<robot_x<<","<<robot_y<<")";
         return min_distance;
         }
         //cout<<target_y;
         //cout<<findShortestDistance(robot_original_x,robot_original_y,target_x, target_y, robot_energy,robot_full_energy,map,temp_map);
        /* if (findShortestDistance(robot_original_x,robot_original_y,robot_x, robot_y, robot_energy,robot_full_energy,map,temp_map)>findShortestDistance(robot_original_x,robot_original_y,target_x, target_y, robot_energy,robot_full_energy,map,temp_map)){
            target_x=robot_x;
            target_y=robot_y;
            min_distance=findShortestDistance(robot_original_x,robot_original_y,target_x, target_y, robot_energy,robot_full_energy,map,temp_map);
         }*/
      //}


      //findMaximumPlace(robot_x,robot_y, robot_energy,robot_full_energy,result_map,temp_map);

   return min_distance;
}

