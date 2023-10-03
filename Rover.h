#include <iostream>
#include <vector>
#include <string>
#include<unordered_map>
using namespace std;


// Define the Rover class
class Rover{
private:
    int x;
    int y;
    char direction;
    int gridSizeX;
    int gridSizeY;
    vector<pair<int, int>> obstacles;

public:
    Rover(){}
    Rover(int startX, int startY, char startDirection,int n,int m)
    : x(startX), y(startY), direction(startDirection), gridSizeX(n), gridSizeY(m) {}

    // add obstacle to list
    void addObstacle(int obstacleX, int obstacleY) {
        obstacles.push_back(make_pair(obstacleX, obstacleY));
    }
    // entered index is on obstacle or not
    bool hasObstacle(int checkX, int checkY){
        for (const auto& obstacle : obstacles) {
            if (obstacle.first == checkX && obstacle.second == checkY) {
                return true;
            }
        }
        return false;
    }
    // current index is inside the grid or not
    bool isWithinGrid(int checkX, int checkY) {
        return (checkX >= 0 && checkX <= gridSizeX && checkY >= 0 && checkY <= gridSizeY);
    }

   // 'M' command execution
    void move() {
    int newX = x;
    int newY = y;

        unordered_map<char, pair<int, int>> directions = {
        {'N', {0, 1}},
        {'S', {0, -1}},
        {'E', {1, 0}},
        {'W', {-1, 0}}
    };

    if (directions.find(direction) != directions.end()) {
        pair<int, int> change = directions[direction];
         newX = x + change.first;
         newY = y + change.second;
    }
    if (isWithinGrid(newX, newY)) {
        if (!hasObstacle(newX, newY)) {
            x = newX , y = newY;
        } else {
            cout<<"\n \x1b[31mObstacle detected. Rover cannot move.\x1b[0m"<<endl;
        }
    } else {
        cout << "\n \x1b[32mOut of grid. Rover cannot move.\x1b[0m" << endl;
    }
}

   // 'L' command execution
    
void turnLeft() {
    unordered_map<char, char> mp2 = {
    {'N', 'W'},
    {'S', 'E'},
    {'E', 'N'},
    {'W', 'S'}};

        if(mp2.find(direction)!=mp2.end()){
            direction = mp2[direction];
        }
    
    }
   // 'R' command execution
    void turnRight() {
        unordered_map<char, char> mp1 = {
                    {'N', 'E'},
                    {'S', 'W'},
                    {'E', 'S'},
                    {'W', 'N'}};

        if(mp1.find(direction)!=mp1.end()){
            direction = mp1[direction];
        }
}

    
string getStatusReport() const {
    return "Rover is at (" + to_string(x) + ", " + to_string(y) + ") facing " + direction + ". No obstacles detected.";
}


    
    int getX() const {return x;}
    int getY() const{return y;}
    char getDirection() const{ return direction;}
};

