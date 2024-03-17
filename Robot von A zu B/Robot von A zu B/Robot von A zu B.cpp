//Robot von A zu B
#include <iostream>

class Robot {
private:
    int current_position;

public:
    Robot(int current_position) : current_position(current_position) {}

    void move_forward() {
        
        current_position++;
    }

    void move_backward() {
        
        current_position--;
    }

    void move_to_destination(int destination) {
        while (current_position != destination) {
            if (current_position < destination) {
                move_forward();
            }
            else {
                move_backward();
            }
            std::cout << "Robot move to the Position " << current_position << std::endl;
        }
    }

    int get_current_position() {
        return current_position;
    }
};

int main() {
    Robot robot(0);
    int destination = 10;  
    std::cout << "Robot move to the punkt B." << std::endl;
    robot.move_to_destination(destination);
    std::cout << "Robot is on B." << std::endl;
    return 0;
}
