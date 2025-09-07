#include <string>
#include <iostream>
#include <map>
#include "parser.hpp"

DiceRoll parse_dice(const std::string& input, const std::string& type_str) {
    DiceRoll roll = DiceRoll{1, 6, 0, RollType::NONE};

    size_t dPos = input.find('d');
    if (dPos == std::string::npos) {
        throw std::invalid_argument("Invalid dice string: missing 'd'");
    }

    roll.count = std::stoi(input.substr(0, dPos));

    size_t plusPos = input.find('+', dPos + 1);
    size_t minusPos = input.find('-', dPos + 1);

    size_t modPos = (plusPos != std::string::npos) ? plusPos : minusPos;

    if (modPos == std::string::npos) {
        std::string after_d = input.substr(dPos + 1);
        size_t space_pos = after_d.find(' ');
        if (space_pos != std::string::npos) {
            roll.sides = std::stoi(after_d.substr(0, space_pos));
        } else {
            roll.sides = std::stoi(after_d);
        }
    } else {
        // Split into sides and modifier
        roll.sides = std::stoi(input.substr(dPos + 1, modPos - (dPos + 1)));
        roll.modifier = std::stoi(input.substr(modPos));
    }

    if (!type_str.empty() && type_str != "none") {
        std::map<std::string, RollType> roll_map = {
            {"adv", RollType::ADVANTAGE},
            {"dis", RollType::DISADVANTAGE}
        };

        if (roll_map.find(type_str) != roll_map.end()) {
            roll.type = roll_map[type_str];
        } else {
            throw std::invalid_argument("Invalid roll type: " + type_str);
        }
    }

    return roll;
}