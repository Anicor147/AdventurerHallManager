#pragma once
#include <iostream>

using namespace std;

enum Race
{
    Elf,
    Human,
    Dwarf,
    Tiefling,
    Halfling,
    HalfOrc,
    Dragonborn,
    Gnome,
    HalfElf
};

enum Classe
{
    Fighter,
    Cleric,
    Rogue,
    Wizard
};


class Character
{
public:
    int damage;
    int hp;
    string name;
    int level;
    Race race;
    Classe classe;

    Character(int _damage, int _hp, Race _race, Classe _classe, const string& _name, int _level)
        : damage(_damage),
          hp(_hp),
          race(_race),
          classe(_classe),
          name(_name),
          level(_level)
    {
    }
     void DisplayCharInfo()
    {
        //switch pour la race et classe??
        std::cout << "Name: " << name+"\t" << "Race: " << race+"\t"<<"Classe: " << classe+"\t"<<"Level: "<<level+"\t";
    }
    ~Character()= default;
    
    

private:

protected:
};
