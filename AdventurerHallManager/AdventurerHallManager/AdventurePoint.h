#include <cstdlib>
#include <iostream>
#include <random>
using namespace std;

struct Encounter
{
public:
    string name;
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
    Encounter(const string& name, bool is_battle, const string& description, int dmg, int hp)
        : name(name),
          isBattle(is_battle),
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
    Encounter* possibleEncounters;
    Encounter chosenEncounter;
protected:
public:
    AdventurePoint()
    {
        possibleEncounters = new Encounter[]{Encounter(), Encounter(), Encounter()};
        chosenEncounter = Encounter();
    }

    ~AdventurePoint() = default;

    AdventurePoint(const string& name, const string& description)
        : name(name),
          description(description)
    {
        possibleEncounters = new Encounter[]{Encounter(), Encounter(), Encounter()};
        chosenEncounter = Encounter();
    }

    AdventurePoint(const string& name, const string& description, Encounter encounter_1, Encounter encounter_2, Encounter encounter_3)
        : name(name),
          description(description)
    {
        possibleEncounters = new Encounter[]{encounter_1, encounter_2, encounter_3};
        chosenEncounter = ChooseEncounter();
    }

    void SetPossibleEncounters(Encounter encounter_1, Encounter encounter_2, Encounter encounter_3)
    {
        possibleEncounters = new Encounter[]{encounter_1, encounter_2, encounter_3};
    }

    Encounter ChooseEncounter()
    {
        srand((unsigned) time(NULL));
        int index = rand() %  3;
        return possibleEncounters[index];
    }
};
