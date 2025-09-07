# DiceRoller

A command-line dice rolling utility written in C++ that supports standard dice notation, modifiers, and advantage/disadvantage mechanics commonly used in tabletop RPGs like D&D 5e.

## Features

- **Standard Dice Notation**: Roll dice using the classic `XdY` format (e.g., `2d6`, `1d20`)
- **Modifiers**: Add or subtract values from your rolls (e.g., `1d20+5`, `2d6-1`)
- **Advantage/Disadvantage**: Roll twice and take the higher/lower result
- **Multiple Dice**: Roll multiple dice of the same type and sum the results
- **Random Number Generation**: Uses modern C++ random number generation for fair results

## Usage

### Basic Syntax
```bash
./DiceRoller <dice_expression> <roll_type>
```

### Examples

**Standard Rolls:**
```bash
./DiceRoller "1d20" "none"      # Roll a 20-sided die
./DiceRoller "2d6" "none"       # Roll two 6-sided dice and sum them
./DiceRoller "1d8+3" "none"     # Roll a d8 and add 3
./DiceRoller "3d4-2" "none"     # Roll three d4s and subtract 2
```

**Advantage/Disadvantage:**
```bash
./DiceRoller "1d20+5" "adv"     # Roll with advantage (roll twice, take higher)
./DiceRoller "1d20+2" "dis"     # Roll with disadvantage (roll twice, take lower)
```

**Default Roll:**
```bash
./DiceRoller                    # Rolls 1d6 if no arguments provided
```

## Dice Expression Format

- **Count**: Number of dice to roll (e.g., `2` in `2d6`)
- **Sides**: Number of sides on each die (e.g., `6` in `2d6`)
- **Modifier**: Optional addition or subtraction (e.g., `+3` or `-1`)

### Roll Types

| Type | Description |
|------|-------------|
| `none` | Standard roll |
| `adv` | Advantage - roll twice per die, take the higher result |
| `dis` | Disadvantage - roll twice per die, take the lower result |

## Building

This project uses CMake. To build:

```bash
mkdir build
cd build
cmake ..
make
```

### Requirements

- C++11 or later
- CMake 3.0 or later
- A compatible C++ compiler (GCC, Clang, MSVC)

## Project Structure

```
DiceRoller/
├── src/
│   ├── dice.cpp
│   ├── dice.h  
│   ├── parser.cpp
│   ├── parser.h
│   └── main.cpp
├── README.md
├── CMakeLists.txt
└── build.bat
```

## How It Works

1. **Parsing**: The `parse_dice()` function breaks down dice expressions like "2d6+1" into components
2. **Rolling**: The `roll_dice()` function handles the actual random number generation
3. **Advantage/Disadvantage**: For each die, two rolls are made and the appropriate one is selected
4. **Summation**: All dice results are summed together with any modifiers applied

## Examples in Action

```bash
$ ./build/dice_roll "1d20+5"
Result: 18

$ ./build/dice_roll "2d6" "adv"
Result: 11

$ ./build/dice_roll "1d20-2" "dis"
Result: 3
```

## License

This project is open source and available under standard open source terms.