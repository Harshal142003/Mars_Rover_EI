

class Command {
public:
    virtual void execute(Rover& rover) = 0;
};

// Define classes for 'M', 'L', and 'R'
class Move: public Command {
public:
    void execute(Rover& rover) override{
        rover.move();
    }
    
};

class TurnLeft : public Command {
public:
    void execute(Rover& rover) override{ 
         rover.turnLeft();
    }
};

class TurnRight : public Command {
public:
    void execute(Rover& rover) override{
        rover.turnRight();
    }
};

// Define the CommandInvoker class
class CommandInvoker {
private:
    vector<Command*> commands;
    
public:
    
    void addCommand(Command* cmd){
    commands.push_back(cmd);
}

    void executeCommands(Rover& rover) {
    for (Command* cmd : commands) {
        cmd->execute(rover);
    }
}
};


