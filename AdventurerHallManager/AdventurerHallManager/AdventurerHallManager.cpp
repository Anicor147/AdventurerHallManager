#include <string>

#include "Adventure.h"
#include "Character.h"
#include "Shop.h"

bool inMainMenu = true;
bool inSecondMenu = false;
string userChoice;
int userInt;
Character c1 = Character(10, 50, Human, Fighter, 1);
Character c2 = Character(10, 50, Elf, Fighter, 1);
Character c3 = Character(10, 50, HalfOrc, Fighter, 1);
Character c4 = Character(10, 50, Halfling, Cleric, 1);
// Array Pour le Party
Character theParty[4] = {c1,c2,c3,c4};

void CreateShop()
{
    auto firstItem = ShopItem("A warm fire hearth","Fire hearth", 15);
    stack<ShopItem> shop_Item;
    shop_Item.push(firstItem);
    Shop theShop = Shop(shop_Item);
}
void DisplayPartyInfo()
{
    for(Character x : theParty)
        x.DisplayCharInfo();
}

void SecondMenu()
{
    std::cout << "Adventure Hall Manager\n1: Go Adventure\n2: Shop\n3: Recruit\n4: View Hall\n5: View Party\n6: Exit";
    while (inSecondMenu)
    {
        try
        {
            cin >> userChoice;
            userInt = stoi(userChoice);
            switch (userInt)
            {
            case 1:
                // Code pour Adventure
                break;
            case 2:
               CreateShop();
                break;
            case 3:
                //Code pour recruter
                break;
            case 4:
                // Code pour le Hall
            case 5:
                DisplayPartyInfo();
                break;
            case 6:
                exit(0);
                break;
            default:
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
                default:
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

    c1.DisplayCharInfo();
    c2.DisplayCharInfo();
    c3.DisplayCharInfo();
   
    MainMenu();
    return 0;
}
        
    


/*Adventure CreateAdventure(string name)
{
    Adventure newAdventure = Adventure(name);
    //set root node
    newAdventure.AdventureTree->Root = new TreeNode<AdventurePoint>(AdventurePoint());
}
*/
