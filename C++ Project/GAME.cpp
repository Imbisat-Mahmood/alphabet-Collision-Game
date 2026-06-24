#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Game {
public:
    char alphabet;
    int x, y;
    int score;

    Game() {
        score = 0;
        spawn();
    }

    void spawn() {
        alphabet = 'A' + rand() % 26;
        x = rand() % 80 + 1;
        y = 1;
    }

    void move() {
        y++;
    }
 void draw() {
        cout << "\r";
        for (int i = 0; i < y; i++) {
            cout << "\n";
        }
        for (int i = 0; i < x; i++) {
            cout << " ";
        }
        cout << alphabet;
    }

    void clear() {
        cout << "\r";
        for (int i = 0; i < y; i++) {
            cout << "\n";
        }
        for (int i = 0; i < x; i++) {
            cout << " ";
        }
        cout << " ";
    }

    void checkInput(char input) {
        if (input == alphabet) {
            score++;
            spawn();
        }
    }
};

int main() {
    Game game;
    char input;
	system("color 5A");
    while (true) {
        game.move();
        game.draw();

        if (_kbhit()) {
            input = _getch();
            game.checkInput(input);
        }

        if (game.y > 20) {
            cout << "Game Over! Final Score: " << game.score << endl;
            break;
        }

        Sleep(300);
        game.clear();
    }

    return 0;
}
