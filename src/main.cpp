#include <iostream>
#include "dice.h"
#include "parser.h"

int main(int argc, char* argv[]) {
    if (argc < 3) {
        int result = roll_dice(DiceRoll{1, 6, 0, RollType::NONE});
        std::cout << "Result: " << result << std::endl;
        return 1;
    }

    try {
        DiceRoll roll = parse_dice(argv[1], argv[2]);
        int result = roll_dice(roll) + roll.modifier;
        std::cout << "Result: " << result << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}