#include <string>

#include "Adventure.h"
#include "Character.h"
#include "Shop.h"
#include <queue>

static bool inMainMenu = true;
static bool inSecondMenu = false;
string userChoice;
int userInt;
Character c1 = Character(10, 50, Human, Fighter, 1);
Character c2 = Character(10, 50, Elf, Rogue, 1);
Character c3 = Character(10, 50, HalfOrc, Wizard, 1);
Character c4 = Character(10, 50, Halfling, Cleric, 1);
// Array Pour le Party

vector<Character> theParty = {c1,c2,c3,c4};

//Queue Pour Recruit
queue<Character> recruit_queue_rogue;
queue<Character> recruit_queue_cleric;
queue<Character> recruit_queue_wizard;
queue<Character> recruit_queue_figther;

void CreateShop()
{
    auto firstItem = ShopItem("A warm fire hearth","Fire hearth", 30);
    stack<ShopItem> shop_Item;
    shop_Item.push(firstItem);
    Shop theShop = Shop(shop_Item);
}
void DisplayPartyInfo()
{
    for(Character x : theParty)
        x.DisplayCharInfo();
}

void RecruitPartyMember(vector<Character> &characters)
{
    auto indexOfChar =0;
    cout << "Adventure Hall Manager\n1: Rogue\n2: Cleric\n3: Fighter\n4: Wizard\n5: Exit\n";
    try
    {
        for (int x =0; x < characters.capacity();x++)
        {
            if (characters[x] == 0)
            {
                indexOfChar =x;
            }
        }
        cout << indexOfChar;
        cin >> userChoice;
        userInt = stoi(userChoice);
        switch (userInt)
        {
        case 1:
           
            break;
        case 2:
            
            break;
        case 3:
            
            break;
        case 4:
            
            break;
        case 5:
            exit(0);
            break;
        default:
            throw(userChoice);
            break;
        }
    }
    catch (...)
    {
        cout << "Please choose a valid option\n";
        system("CLS");
        RecruitPartyMember(theParty);
    }
}

void SecondMenu()
{
   inSecondMenu = true;
   
    cout << "Adventure Hall Manager\n1: Go Adventure\n2: Shop\n3: Recruit\n4: View Hall\n5: View Party\n6: Exit\n";
    do
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
                if (theParty.size() < 4)
                {
                    RecruitPartyMember(theParty);
                }
                else
                {
                    cout << "Your party is full. You can't recruit now\n";
                }
                break;
            case 4:
                // Code pour le Hall
                break;
            case 5:
                DisplayPartyInfo();
                break;
            case 6:
                exit(0);
                break;
            default:
                throw(userChoice);
                break;
            }
        }
        catch (...)
        {
            cout << "Please choose a valid option\n";
            system("CLS");
            SecondMenu();
        }
    }while (inSecondMenu);
}

void MainMenu()
{
    std::cout << "Adventure Hall Manager\n1: Continue\n2: New Game\n3: Exit\n";
    do
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
            system("CLS");
            MainMenu();
        }
    }while (inMainMenu);
}

int main(int argc, char* argv[])
{
    for (int i = 0; i < 20; i++)
    {
        Character c = Character(12,45,Elf,Rogue,1);
        recruit_queue_rogue.push(c);
        Character v = Character(10,35,Elf,Cleric,1);
        recruit_queue_cleric.push(v);
        Character x = Character(15,50,Elf,Fighter,1);
        recruit_queue_figther.push(x);
        Character y = Character(15,30,Elf,Wizard,1);
        recruit_queue_wizard.push(y);
    }
    // Donne un seed au random seulement au debut du program
    theParty.erase(theParty.begin());
    srand(static_cast<unsigned int>(time(nullptr)));
   
    MainMenu();
    return 0;
}
        
    


/*Adventure CreateAdventure(string name)
{
    Adventure newAdventure = Adventure(name);
    //set root node --> On the Road
    newAdventure.AdventureTree->Root = new TreeNode<AdventurePoint>(AdventurePoint(
        "On the Road",
        "The long, windy road stretches before the party, the music and comfort of the guildhall slowly disappearing behind them.",
        Encounter("Bandits!", true, "A group of thugs and brigands jump out of the bushes and ambush the party!", 10, 20, 10,0),
        Encounter("Lost travellers", false, "A group of travelers are lost on the road. Your party gratiously escorts them all the way to a roadside inn, where they thank them for their help and reward them with 10 gold pieces.", 0, 0, 10, 0),
        Encounter("A poor soul", false, "On the side of the road lies a courrier of the lord's army, dried blood surrounds a deep stab wound in his belly. Somehow, those who killed him did not find an interest in his pouch. He won't be needing these 5 gold coins.", 0, 0, 5, 0)));
    //Crossroads
    newAdventure.AdventureTree->Root->left = new TreeNode<AdventurePoint>(AdventurePoint(
        "The Crossroads",
        "The crossroads are not always safe. To the West lies the Rocky Road. To the East stretches the River Road.",
        Encounter("Tax Collectors", false, "As frustrating as it is, the roads don't pay for themselves. 5 gold pieces are collected from your party for the road tax.", 0, 0, -5, 0),
        Encounter("Orc Raiders", true, "Orcs from the local warband are roaming the countryside. They spotted your party. It's a fight to the death!", 20, 30, 15, 0),
        Encounter("Death from above", true, "A massive Griffin swoops down from the clouds and attacks the party! Will they become just another meal for this feral predator?", 15, 35, 15, 0)));
    //Rocky Road
    newAdventure.AdventureTree->Root->left->left = new TreeNode<AdventurePoint>(AdventurePoint(
        "Rocky Road",
        "The Rocky Road is dotted with crags, caves and small cliffs. Lots of good spots for ambushes.",
        Encounter("Wandering Priest", false, "A well equipped priest is traveling alone. He offers the blessings of his deity and heals some of the party's wounds as a gesture of good faith.", 0, 0, 0, 10),
        Encounter("Wolf Pack", true, "A pack of feral wolves appear between the rocks, led by a huge Dire Wolf with dagger-like fangs and a coat of pitch black fur.", 20, 40, 20, 0),
        Encounter("Spectral Host", true, "A whole army of ghostly figures clad in torn mail and holding battered weapons seems to appear out of thin air. With a cold and quiet stare, they move menacingly towards the party.", 15, 50, 20, 0)));
    //Forest
    newAdventure.AdventureTree->Root->left->left->left = new TreeNode<AdventurePoint>(AdventurePoint(
        "Forest",
        "Tall trees and thick bush cover this whole area. The road twists and turns around small ponds and quiet clearings. But eyes are watching the party. The forest is home to many a fearsome creature.",
        Encounter("Owlbear", true, "This creature resembles a fusion between a massive bear and an owl. Do not be fooled by its cute beak, it will use it to shred your party to pieces.", 25, 50, 25, 0),
        Encounter("Mystic Pond", false,"A beautiful dryad welcomes the party in her humble domain. Satyrs dance and play the flute, joyfully calling to the party to join them. The mystic pond is majestic and enthralling. The party rests a bit, regaining strength for the final parts of the journey. But the magic of the denizens of the Mystic pond is subtle. Wasn't there gold in that bag before?", 0, 0, -20, 10),
        Encounter("Goblin Skirmishers", true, "A band of goblins hiding in the trees and the overgrowth jump from all around the party. Their numbers are so great, its overwhelming!", 10,80, 25, 0)));
    //Goblin Camp
    newAdventure.AdventureTree->Root->left->left->left->left = new TreeNode<AdventurePoint>(AdventurePoint(
        "Goblin Camp",
        "Huts adorned with animal bones, a big campfire in the center, and so, so many goblins roaming around.",
        Encounter("Goblin Shaman", true, " The goblin shaman cries out incantations in his guttural language, and yells out orders at his tribe. They attack from everywhere, and the shaman's magic is powerful!", 40, 100, 50, 0),
        Encounter("Goblin Shaman", true, " The goblin shaman cries out incantations in his guttural language, and yells out orders at his tribe. They attack from everywhere, and the shaman's magic is powerful!", 40, 100, 50, 0),
        Encounter("Goblin Shaman", true, " The goblin shaman cries out incantations in his guttural language, and yells out orders at his tribe. They attack from everywhere, and the shaman's magic is powerful!", 40, 100, 50, 0)));
    //Druid Grove
    newAdventure.AdventureTree->Root->left->left->left->right = new TreeNode<AdventurePoint>(AdventurePoint(
        "Druid Grove",
        "The plants and animals around here seem to try to drive your party away. The druids do not tolerate intruders in their secret grove.",
        Encounter("Angry Druids", true, "Some of the druids transform into feral beasts and leap at the party while others stay back and use their druidic magic to harass and hinder. They are well coordinated and use the terrain to their advantage.", 40, 100, 50, 0),
        Encounter("Angry Druids", true, "Some of the druids transform into feral beasts and leap at the party while others stay back and use their druidic magic to harass and hinder. They are well coordinated and use the terrain to their advantage.", 40, 100, 50, 0),
        Encounter("Angry Druids", true, "Some of the druids transform into feral beasts and leap at the party while others stay back and use their druidic magic to harass and hinder. They are well coordinated and use the terrain to their advantage.", 40, 100, 50, 0)));
    //Swamp
    newAdventure.AdventureTree->Root->left->left->right = new TreeNode<AdventurePoint>(AdventurePoint(
        "Swamps",
        "Thick bogs and deep marshes cover this foggy area, stretching for miles. It's easy to get lost...",
        Encounter("Forgotten Treasure", false, "A half-sunk wagon lies abandoned on the side of the muddy road. A small chest has fallen in the swamp. A stroke of Luck! it's filled with gold pieces stamped with a neighbouring lord's effigy.", 0, 0, 40, 0),
        Encounter("Giant Alligator", true, "The party has entered a ferocious beast's hunting grounds. A giant alligator preys on anything that moves around here, adventurer or not.", 20, 60, 25, 0),
        Encounter("Ghoul Pack", true, "Those who die in these forsaken swamps rise as mindless undead hungry for living flesh. For some reason they tend to gather in small packs to hunt. They've caught your party's scent!", 15, 70, 25, 0)));
    //Troll Cave
    newAdventure.AdventureTree->Root->left->left->right->left = new TreeNode<AdventurePoint>(AdventurePoint(
        "Troll Cave",
        "",
        Encounter(),
        Encounter(),
        Encounter()));
    //Lizardmen Temple
    newAdventure.AdventureTree->Root->left->left->right->right = new TreeNode<AdventurePoint>(AdventurePoint(
        "Lizardmen Temple",
        "",
        Encounter(),
        Encounter(),
        Encounter()));
    //River Road
    newAdventure.AdventureTree->Root->left->right = new TreeNode<AdventurePoint>(AdventurePoint(
        "River Road",
        "",
        Encounter(),
        Encounter(),
        Encounter()));
    //Coast
    newAdventure.AdventureTree->Root->left->right->left = new TreeNode<AdventurePoint>(AdventurePoint(
        "Coast",
        "",
        Encounter(),
        Encounter(),
        Encounter()));
    //Pirate Hideout
    newAdventure.AdventureTree->Root->left->right->left->left = new TreeNode<AdventurePoint>(AdventurePoint(
        "Pirate Hideout",
        "",
        Encounter(),
        Encounter(),
        Encounter()));
    //Fishmen Lagoon
    newAdventure.AdventureTree->Root->left->right->left->right = new TreeNode<AdventurePoint>(AdventurePoint(
        "Fishmen Lagoon",
        "",
        Encounter(),
        Encounter(),
        Encounter()));
    //Mountain
    newAdventure.AdventureTree->Root->left->right->right = new TreeNode<AdventurePoint>(AdventurePoint(
        "Mountain",
        "",
        Encounter(),
        Encounter(),
        Encounter()));
    //Giant's Summit
    newAdventure.AdventureTree->Root->left->right->right->left = new TreeNode<AdventurePoint>(AdventurePoint(
        "Giant's Summit",
        "",
        Encounter(),
        Encounter(),
        Encounter()));
    //Harpy's Nest
    newAdventure.AdventureTree->Root->left->right->right->right = new TreeNode<AdventurePoint>(AdventurePoint(
        "Harpy's Nest",
        "",
        Encounter(),
        Encounter(),
        Encounter()));
    
}*/

