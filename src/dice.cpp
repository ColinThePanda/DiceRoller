#include <random>
#include "dice.h"

static std::random_device rd;
static std::mt19937 gen(rd());

int roll_dice(DiceRoll roll) {
    std::uniform_int_distribution<> dis(1, roll.sides);
    int total = 0;
    for (int i = 0; i < roll.count; i++) {
        if (roll.type == RollType::NONE) {
            total += dis(gen);
            continue;
        };
        int roll1 = dis(gen);
        int roll2 = dis(gen);
        if (roll.type == RollType::ADVANTAGE) {
            total += std::max(roll1, roll2);
        } else {
            total += std::min(roll1, roll2);
        }
    }
    return total + roll.modifier;
}

