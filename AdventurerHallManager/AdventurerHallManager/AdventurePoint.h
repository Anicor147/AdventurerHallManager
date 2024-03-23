#include <iostream>;
#include <random>
#include <experimental/random>;
using namespace std;

struct Encounter
{
public:
    bool isBattle;
    int GetDamage()
    {
        return dmg;
    }
    void SetDamage(int value)
    {
        dmg = value;
    }
    int GetHP()
    {
        return hp;
    }
    void SetHP(int value)
    {
        hp = value;
    }
    string GetDescription()
    {
        return description;
    }
    
private:
    string description;
    int dmg;
    int hp;
protected:
    

public:
    Encounter() {  }
    ~Encounter() = default;
    Encounter(bool is_battle, const string& description, int dmg, int hp)
        : isBattle(is_battle),
          description(description),
          dmg(dmg),
          hp(hp)
    {
    }
};

class AdventurePoint
{
public:
    string GetName()
    {
        return name;
    }
    string GetDescription()
    {
        return description;
    }
    
private:
    string name;
    string description;
    Encounter possibleEncounter1;
    Encounter possibleEncounter2;
    Encounter possibleEncounter3;
    Encounter chosenEncounter;
protected:
public:
    AdventurePoint()
    {
        possibleEncounter1 = Encounter();
        possibleEncounter2 = Encounter();
        possibleEncounter3 = Encounter();
        chosenEncounter = Encounter();
    }

    ~AdventurePoint() = default;

    AdventurePoint(const string& name, const string& description)
        : name(name),
          description(description)
    {
        possibleEncounter1 = Encounter();
        possibleEncounter2 = Encounter();
        possibleEncounter3 = Encounter();
        chosenEncounter = Encounter();
    }

    AdventurePoint(const string& name, const string& description, Encounter encounter_1, Encounter encounter_2, Encounter encounter_3)
        : name(name),
          description(description)
    {
        possibleEncounter1 = encounter_1;
        possibleEncounter2 = encounter_2;
        possibleEncounter3 = encounter_3;
        chosenEncounter = ChooseEncounter();
    }

    Encounter ChooseEncounter()
    {
     
        
    }
};
