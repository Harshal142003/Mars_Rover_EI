#include<bits/stdc++.h>
#include<unordered_set>
#include "Rover.h"
#include "command.h"

using namespace std;
int main() {
    cout<<"Enter the size of grid n x m: ";
    int n,m;
    cin>>n>>m;
    // for valid index 
    while(n<=0 || m<=0){
        cout<<"Please enter index n>0 & m>0 : ";
        cin>>n>>m;
    }
    
    int startX, startY;
    char Direction;
    unordered_set<char>st;
    st.insert('N');st.insert('S');st.insert('E');st.insert('W');

    // Ask the user to input the initial position and direction
    cout << "Enter initial position (x y): ";
    cin >> startX >> startY;

    //for valid input 
    while(startX<0 || startY<0  || startX>=n || startY>=m){
        cout<<"\n \x1b[32mPlease enter valid initial position between grid size :\x1b[0m";
        cin>>startX>>startY;
    }

    cout << "Enter initial direction (N/S/E/W): ";
    cin >> Direction;

    // for valid initial direction 
    while(st.find(Direction)==st.end()){
        cout<<"\n\x1b[32mPlease Enter valid initial direction (N/S/E/W): \x1b[0m";
        cin>>Direction;
    }

    // Initialize the Rover with the user's input
    Rover rover(startX, startY, Direction,n,m);

    int numObstacles;

    //  number of obstacles
    cout << "Enter the number of obstacles: ";
    cin >> numObstacles;

    // Add obstacles 
    int obstacleX, obstacleY;
    while(numObstacles--){
        
        cout << "Enter obstacle position (x y): ";
        cin >> obstacleX >> obstacleY; 
       
        while(obstacleX<0 || obstacleY<0  || obstacleX>=n || obstacleY>=m || (obstacleX==startX && obstacleY==startY)){
           
            cout << "\n\x1b[32mPlease Enter valid obstacle position (x y) either inside grid or \n Don't initialize at starting position: \x1b[0m ";
            cin >> obstacleX >> obstacleY; 
        }
        
        rover.addObstacle(obstacleX,obstacleY);     
    }

    // Commands 
    string commands;
   
    while(true){
    // Input commands
    cout << "Enter commands (L/R/M): ";
    cin >> commands;

   // objects
    Move move;
    TurnLeft turnLeft;
    TurnRight turnRight;

    CommandInvoker starter;

    // Add user-specified commands
    for (char command : commands) {
        if (command == 'M') {
            starter.addCommand(&move);
        } else if (command == 'L') {
            starter.addCommand(&turnLeft);
        } else if (command == 'R') {
            starter.addCommand(&turnRight);
        }
        else{
            cout<<"Invalid command";
        }
    }

    // Execute the commands
    starter.executeCommands(rover);

    // Display the final position and status report
    cout << "Final Position: (" << rover.getX() << ", " << rover.getY() << ", " << rover.getDirection() << ")" << endl;
    cout << "Status Report: " << rover.getStatusReport() << endl;
    }
    return 0;
}

