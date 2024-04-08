#include <string>

#include "Adventure.h"
#include "Character.h"

bool inMainMenu = true;
bool inSecondMenu = false;
string userChoice;
int userInt;

void SecondMenu()
{
    std::cout << "Adventure Hall Manager\n1: Go Adventure\n2: Shop\n3: Recruit\n4: View Hall\n5: View Party\n6: Exit";
    while (inSecondMenu)
    {
        try
        {
            cin >> userChoice;
            userInt = stoi(userChoice);
            if (userInt == 1 || userInt == 2 || userInt == 3 || userInt == 4 || userInt == 5|| userInt == 6)
            {
                
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
                switch (userInt)
                {
                case 1:
                    system("CLS");
                    SecondMenu();
                    inSecondMenu = true;
                    break;
                case 2:
                    system("CLS");
                    inSecondMenu = true;
                    SecondMenu();
                    break;
                case 3:
                    exit(0);
                    break;
                }
               
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

Adventure CreateAdventure(string name)
{
    Adventure newAdventure = Adventure(name);
    //set root node
    newAdventure.AdventureTree->Root = new TreeNode<AdventurePoint>(AdventurePoint());
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
