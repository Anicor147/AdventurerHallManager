#include <string>

#include "Character.h"

bool inMainMenu = true;
string userChoice;
int userInt;

void MainMenu()
{
    std::cout << "Adventure Hall Manager\n1: Continue\n2: New Game\n3: Exit\n";
    while (inMainMenu)
    {
        try
        {
            cin >> userChoice;
            userInt = stoi(userChoice);
            if (userInt == 1 || userInt == 2 || userInt == 3)
            {
                inMainMenu = false;
                // Code suite au choix de l'utilisateur
            }
            else
            {
                throw(userChoice);
            }
        }
        catch (...)
        {
            std::cout << "Please choose a valid option\n";
        }
    }
}

int main(int argc, char* argv[])
{
    // Donne un seed au random seulement au debut du program
    srand(static_cast<unsigned int>(time(nullptr)));

    
    Character c1 = Character(10, 50, Human, Fighter, 1);
    Character c2 = Character(10, 50, Elf, Fighter, 1);
    Character c3 = Character(10, 50, HalfOrc, Fighter, 1);

    c1.DisplayCharInfo();
    c2.DisplayCharInfo();
    c3.DisplayCharInfo();

    MainMenu();
    return 0;
}
