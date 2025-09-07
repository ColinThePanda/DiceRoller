#include <iostream>
#include "dice.h"
#include "parser.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        // No arguments - roll default 1d6
        int result = roll_dice(DiceRoll{1, 6, 0, RollType::NONE});
        std::cout << "Result: " << result << std::endl;
        return 0;
    }

    try {
        DiceRoll roll = parse_dice(argv[1], (argc >= 3) ? argv[2] : "");
        int result = roll_dice(roll);
        std::cout << "Result: " << result << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}