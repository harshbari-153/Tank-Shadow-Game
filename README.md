# Tank-Shadow-Game

## Description
Tank Shadow Game is a basic C game where the player controls a tank to shoot at a target. The unique twist in the game is that after the tank's first movement, the target vanishes and only its shadow is displayed. The target is movable, meaning it can change its position as the player attempts to shoot it. The player's challenge is to hit the target by interpreting the movements of its shadow.

## Key Features
- Initial Visibility: The target is visible at the start, but vanishes after the tank's first movement.
- Shadow Mechanism: The target's shadow moves inversely to the target's movements:
- - When the target moves up, its shadow moves down.
- - When the target moves down, its shadow moves up.
- - When the target moves right, its shadow moves left.
- - When the target moves left, its shadow moves right

## Controls
- a: Move tank left
- l: Move tank right
- t: Move tank up
- v: Move tank down
- g: Fire
- e: Exit game

## Language Used
- C

## Installation
### Prerequisites
- C compiler (e.g., GCC)

### Steps
1. Clone the repository:
    ```bash
    git clone https://github.com/harshbari-153/Tank-Shadow-Game.git
    ```
2. Navigate to the project directory:
    ```bash
    cd Tank-Shadow-Game
    ```
3. Compile the program using a C compiler:
    ```bash
    gcc tank_shadow_game.c -o tank_shadow_game
    ```
4. Run the game:
    ```bash
    ./tank_shadow_game
    ```

## Author
- **Harsh Bari**
- Email: bari.harsh2001@gmail.com

## License
This project is licensed under the MIT License - see the LICENSE file for details.

## Contact
For any queries or issues, please contact bari.harsh2001@gmail.com.
