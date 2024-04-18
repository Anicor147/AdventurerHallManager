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

vector<Character> theParty = {c1, c2, c3, c4};

// Adventure init
Adventure currentAdventure = Adventure("temp");

//Queue Pour Recruit
queue<Character> recruit_queue_rogue;
queue<Character> recruit_queue_cleric;
queue<Character> recruit_queue_wizard;
queue<Character> recruit_queue_figther;

// Shop

Shop theShop = Shop(theShop.shopItem);

Adventure CreateAdventure(string name)
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
        Encounter("Spectral Host", true, "The party walks past a long forgotten battlefield. Suddenly a whole army of ghostly figures clad in torn mail and holding battered weapons seems to appear out of thin air. With a cold and quiet stare, they move menacingly towards the party.", 15, 50, 20, 0)));
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
        "A damp cave so dark torchlight seems to wither away as the party enters. A stench hits them with the full force of a hundred rotting carcasses, so foul it takes all the strength in their bodies to avoid retching and falling unconcious. And then a growl comes from deeper in the lair. The troll has awakened!",
        Encounter("Troll", true, "The Troll's nasty club is bigger than the tallest warrior, and its claws as sharp as razors! It laughs gutturally while deciding which member of your party it will eat first.", 40, 100, 50, 0),
        Encounter("Troll", true, "The Troll's nasty club is bigger than the tallest warrior, and its claws as sharp as razors! It laughs gutturally while deciding which member of your party it will eat first.", 40, 100, 50, 0),
        Encounter("Troll", true, "The Troll's nasty club is bigger than the tallest warrior, and its claws as sharp as razors! It laughs gutturally while deciding which member of your party it will eat first.", 40, 100, 50, 0)));
    //Lizardmen Temple
    newAdventure.AdventureTree->Root->left->left->right->right = new TreeNode<AdventurePoint>(AdventurePoint(
        "Lizardmen Temple",
        "This part of the swamps is filled with luxurious vegetation, almost jungle-like. Between the trees, stone totems with angry faces and bone idols representing a serpent god can be seen. Then, a temple, shaped like a pyramid, adorned in gold and precious stones. It is guarded by many a warrior, curled warrior figures with scaly skin, lizard heads and tails, and spears and axes. At the top of the pyramid, a priest, wielding a jeweled mace and a ritual dagger, is about to sacrifice some poor victim while chanting to its serpent god!",
        Encounter("Lizarmen Warriors", true, "The priest sees the party from atop the temple and yells. Suddenly, spears and stones are raining from all directions! The serpent god's worshippers have been angered.", 40, 100, 50, 0),
        Encounter("Lizarmen Warriors", true, "The priest sees the party from atop the temple and yells. Suddenly, spears and stones are raining from all directions! The serpent god's worshippers have been angered.", 40, 100, 50, 0),
        Encounter("Lizarmen Warriors", true, "The priest sees the party from atop the temple and yells. Suddenly, spears and stones are raining from all directions! The serpent god's worshippers have been angered.", 40, 100, 50, 0)));
    //River Road
    newAdventure.AdventureTree->Root->left->right = new TreeNode<AdventurePoint>(AdventurePoint(
        "River Road",
        "A beautiful river streches on the side of this road, twisting and winding. The sound of the rapids and the gentle winds make for a pleasant walk.",
        Encounter("Death from Below", true, "The ground shakes, and all of a sudden two massive insect-like creatures burst out of burrowed holes, shrieking and grinding their huge mandibles. One spits acid while the other crawls at an impressive speed towards the party.", 20, 40, 20, 0),
        Encounter("Just in time", false, "The party approches a group of travellers gathered in a defensive circle on a bridge. a group of ogres are harassing them with rocks. As the party comes in to attack, the ogres flee in a chaotic retreat, yelling angrily at each other. The rescued travelers offer food, medecine and gold as a sign of grattitude.", 0, 0, 10, 10),
        Encounter("Centaur Outriders", true, "A group of Centaurs come galloping towards the party. They claim that this is their hunting grounds and trespass shall not be allowed. After a tense attempt at negotiations, it becomes clear they will not let it go and start circling the party. Suddenly one of them looses an arrow. It's a battle!", 15, 50, 20, 0)));
    //Coast
    newAdventure.AdventureTree->Root->left->right->left = new TreeNode<AdventurePoint>(AdventurePoint(
        "Coast",
        "The sea stretches out before the party's eyes, waves crashing upon the rocky shores. This coast is known for its monstrous inhabitants, pirates and treasures. Fortune may hide there for those brave enough to reach out for it.",
        Encounter("Wyverns", true, "Nesting in cracks in the shoreline cliffs, those nasty flying beasts have poisoned stingers at the tip of their tails. Two of them are patrolling the skies over the road. The party tries to hide, but to no avail. The monsters dive in to attack.", 25, 50, 25, 0),
        Encounter("Mercenary Battalion", true, "These poorly armed mercenaries come from the neighbouring province. Whenever they are without a contract, they roam the country, showing a red banner, plundering and raiding wherever they find riches. Your party will not stand for such dishonorable conduct! They engage in bloody business with the mercenaries.", 10, 80, 25, 0),
        Encounter("Abandonned Wizard's Tower", true, "This strange tower seems to move about, appearing in random places. It is a well known mystery in these parts. As the party enters the worn out building looking for valuables, stone golems step out of alcoves and attack.", 15, 70, 25, 0)));
    //Pirate Hideout
    newAdventure.AdventureTree->Root->left->right->left->left = new TreeNode<AdventurePoint>(AdventurePoint(
        "Pirate Hideout",
        "This cove is well known to be a pirate safe haven. After traversing some well hidden paths between cliffs and trees, the party lay there eyes on a plethora of vessels, from small boats to large frigates, all sporting different versions of the skull and bones flag.",
        Encounter("Pirate King", true, "After fighting a bunch of drunken sailors, the Pirate King emerges from his makeshift palace. He challenges the party to a fair fight... And immediately calls for all his corsairs to attack!", 40, 100, 50, 0),
        Encounter("Pirate King", true, "After fighting a bunch of drunken sailors, the Pirate King emerges from his makeshift palace. He challenges the party to a fair fight... And immediately calls for all his corsairs to attack!", 40, 100, 50, 0),
        Encounter("Pirate King", true, "After fighting a bunch of drunken sailors, the Pirate King emerges from his makeshift palace. He challenges the party to a fair fight... And immediately calls for all his corsairs to attack!", 40, 100, 50, 0)));
    //Fishmen Lagoon
    newAdventure.AdventureTree->Root->left->right->left->right = new TreeNode<AdventurePoint>(AdventurePoint(
        "Fishmen Lagoon",
        "This reef is dotted with beautiful coral formations and rocky formations. With a closer look though, it is possible to see bone statues, fishing boat carcasses and strange, wet, slimy creatures moving about, yapping at each other in their gurgly language.", 
        Encounter("Fishmen Assault", true, "The creatures spot the party and point their crooked harpoons at them. More of them come out of pools and small grottos. And then, a massive, half-octopus, half ogre creature rises from beneath the surface. It charges at the party.", 40, 100, 50, 0),
        Encounter("Fishmen Assault", true, "The creatures spot the party and point their crooked harpoons at them. More of them come out of pools and small grottos. And then, a massive, half-octopus, half ogre creature rises from beneath the surface. It charges at the party.", 40, 100, 50, 0),
        Encounter("Fishmen Assault", true, "The creatures spot the party and point their crooked harpoons at them. More of them come out of pools and small grottos. And then, a massive, half-octopus, half ogre creature rises from beneath the surface. It charges at the party.", 40, 100, 50, 0)));
    //Mountain
    newAdventure.AdventureTree->Root->left->right->right = new TreeNode<AdventurePoint>(AdventurePoint(
        "Mountain",
        "This road is hard to travel. Steep climbs, rock slides, cold winds... nature itself seems to be telling your party a message: You are not welcome here.",
        Encounter("Savage Dwarves", true, "The party passes by a dirty mine, with recent bodies littering the floor of the entrance. A sentry rings a bell. And they come out, screaming, axes and hammers and picks whirling above their heads. The crazy dwarves of the mountains fight with no care for their own life!", 15, 70, 25, 0),
        Encounter("Bear Cave", true, "The party stops to rest in a small cave by the road. Tired and cold, they enjoy a warm broth. But a low growl interrupts their well deserved meal. The growl grows into a full blown rageful roar, as a huge cave bear walks in what the party now realizes to be the den of massive animal.", 25, 50, 25, 0),
        Encounter("Windswept Tower", false, "This tower is known amongst travelers as a place of warmth and respite. The party enjoys a well deserved meal and warm bed for the night. The owner of the tavern helps with injuries while listening to the stories of yout party's adventures.", 0, 0, 0, 15)));
    //Giant's Summit
    newAdventure.AdventureTree->Root->left->right->right->left = new TreeNode<AdventurePoint>(AdventurePoint(
        "Giant's Summit",
        "The top of this mountain is cold, windy, inhospitable. At first, only traces of its inhabitants are visible. Goat bones here, a crude runic painting there. Eventually the party climbs up to what looks like a small fort, made out of torn out trees and boulders tied together with furs and vines. Upon entering, it is obvious the creature that lives here is at least 5 times the size of a regular adventurer.",
        Encounter("Mountain Giant", true, "The giant comes out of its home, axe in hand. Visitors are not welcome in its abode, and the punishment for trespassing is getting cleaved in half.", 40, 100, 50, 0),
        Encounter("Mountain Giant", true, "The giant comes out of its home, axe in hand. Visitors are not welcome in its abode, and the punishment for trespassing is getting cleaved in half.", 40, 100, 50, 0),
        Encounter("Mountain Giant", true, "The giant comes out of its home, axe in hand. Visitors are not welcome in its abode, and the punishment for trespassing is getting cleaved in half.", 40, 100, 50, 0)));
    //Harpy's Nest
    newAdventure.AdventureTree->Root->left->right->right->right = new TreeNode<AdventurePoint>(AdventurePoint(
        "Harpy's Nest",
        "Weird sounds can be heard from a considerable distance from this mountain peak. A mixture between singing and croaking. Then, as the party approaches, the singing is clearer, more beautiful. Climbing up to the top, they find a huge nest of intertwined branches and bones, filled with bird-like creatures, with raven wings and a woman's body. Their eyes glow a deep yellow and their beaks are menacing.",
        Encounter("Harpy Hags", true, "The Harpys lunge and sweep at the party, attacking with their beaks and claws, attempting to push the heroes down the steep cliffs of the mountain.", 40, 100, 50, 0),
        Encounter("Harpy Hags", true, "The Harpys lunge and sweep at the party, attacking with their beaks and claws, attempting to push the heroes down the steep cliffs of the mountain.", 40, 100, 50, 0),
        Encounter("Harpy Hags", true, "The Harpys lunge and sweep at the party, attacking with their beaks and claws, attempting to push the heroes down the steep cliffs of the mountain.", 40, 100, 50, 0)));

    return newAdventure;
}

void AdventureTraversal(Adventure* adventure)
{
    cout << adventure->name;
}

void DisplayShop()
{
    theShop.DisplayTopItem();
    cout << "\nDo you wish to buy the item?\n 1: Buy \n 2: Return to previous Menu\n";
    cin >> userChoice;
    userInt = stoi(userChoice);
   
}
void DisplayPartyInfo()
{
    for (Character x : theParty)
        x.DisplayCharInfo();
}


void RecruitPartyMember(vector<Character>& characters)
{
    cout << "Adventure Hall Manager\n1: Rogue\n2: Cleric\n3: Fighter\n4: Wizard\n5: Exit\n";
    Character r = recruit_queue_rogue.front();
    Character c = recruit_queue_cleric.front();
    Character f = recruit_queue_figther.front();
    Character w = recruit_queue_wizard.front();
    try
    {
        cin >> userChoice;
        userInt = stoi(userChoice);
        switch (userInt)
        {
        case 1:
            characters.emplace_back(r);
            recruit_queue_rogue.pop();
            return;

        case 2:
            characters.emplace_back(c);
            recruit_queue_cleric.pop();
            return;
        case 3:
            characters.emplace_back(f);
            recruit_queue_figther.pop();
            return;
        case 4:
            characters.emplace_back(w);
            recruit_queue_wizard.pop();
            return;
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
                currentAdventure = CreateAdventure("Main Adventure");
                AdventureTraversal(&currentAdventure);
                break;
            case 2:
                DisplayShop();
                inSecondMenu = false;
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
    }
    while (inSecondMenu);
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
    }
    while (inMainMenu);
}

int main(int argc, char* argv[])
{
    for (int i = 0; i < 20; i++)
    {
        Character c = Character(12, 45, Elf, Rogue, 1);
        recruit_queue_rogue.push(c);
        Character v = Character(10, 35, Elf, Cleric, 1);
        recruit_queue_cleric.push(v);
        Character x = Character(15, 50, Elf, Fighter, 1);
        recruit_queue_figther.push(x);
        Character y = Character(15, 30, Elf, Wizard, 1);
        recruit_queue_wizard.push(y);
    }
    // Donne un seed au random seulement au debut du program
    theParty.erase(theParty.begin());
    theParty[0].DisplayCharInfo();
   // Shop creation
    auto firstItem = ShopItem("A large hearth built from stone, providing warmth and a focal point for the common room, with a mantle for displaying trinkets or trophies.", "Stone Fireplace with Hearth", 30);
    auto secondItem = ShopItem("Sturdy wooden tables and benches, where your party can gather to dine and socialize.","Tables and Benches",50);
    auto thirdItem = ShopItem(" Elaborate chandeliers hanging from the ceiling, adorned with magical orbs to provide soft, warm lighting throughout the hall.","Magical Chandeliers", 100);
    auto fourthItem = ShopItem("An old and well construct wooden barrel. It seems like we cant empty it no matters of much we drink.","Bottomless wine barrel", 150);
    
    
    theShop.shopItem.push(fourthItem);
    theShop.shopItem.push(thirdItem);
    theShop.shopItem.push(secondItem);
    theShop.shopItem.push(firstItem);


    MainMenu();
    return 0;
}
