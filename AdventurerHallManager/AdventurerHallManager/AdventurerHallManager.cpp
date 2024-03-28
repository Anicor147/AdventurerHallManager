

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
    
    Character* Bob = new Character(10, 50, Human, Fighter, "Bob", 1);
    Character Bob1 = Character(10, 50, Human, Fighter, "Bob1", 1);

    Bob1.DisplayCharInfo();
    
    
    MainMenu();
    return 0;
}
