#ifndef PARSER_H
#define PARSER_H

#include <string>

enum class RollType {
    NONE,
    ADVANTAGE,
    DISADVANTAGE
};

struct DiceRoll {
    int count;
    int sides;
    int modifier;
    RollType type;
};

DiceRoll parse_dice(const std::string& input, const std::string& type_str);

#endif
