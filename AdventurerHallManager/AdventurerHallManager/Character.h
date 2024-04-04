#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <map>
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
    map<Race , string> raceFileMap;
    
    Character(int _damage, int _hp, Race _race, Classe _classe, int _level)
        : damage(_damage),
          hp(_hp),
          race(_race),
          classe(_classe),
          level(_level)
    {
        //Dictionnaire qui contient le chemins pour chaque race
        raceFileMap = {
            { Human, "NamesFolder/HumanNames.txt" },
            { Elf, "NamesFolder/ElfNames.txt" },
            { Dwarf, "NamesFolder/DwarfNames.txt" },
            { Tiefling, "NamesFolder/Tiefling.txt" },
            { Halfling, "NamesFolder/HalflingNames.txt" },
            { HalfOrc, "NamesFolder/HalfOrcNames.txt" },
            { Dragonborn, "NamesFolder/DragonBornNames.txt" },
            { Gnome, "NamesFolder/GnomeNames.txt" },
            { HalfElf, "NamesFolder/ElfNames.txt" }
        };

        name = GetNameFromFile(raceFileMap[race]);
    }

    void DisplayCharInfo()
    {
        //switch pour la race et classe??
        std::cout << "Name: " << name + "\t" << "Race: " << race + "\t" << "Classe: " << classe + "\t" << "Level: " <<
            level + "\t";
    }

    ~Character() = default;

    string GetNameFromFile(const string& filename)
    {
        ifstream file(filename);
        vector<string> names;

        if (file.is_open())
        {
            string line;
            while (getline(file, line))
            {
                names.push_back(line);
            }
            file.close();
            int randomIndex = rand() % names.size();

            return names[randomIndex];
        }
        else
        {
            cout << "Unable to open file." << endl;
            return "DefaultName";
        }
    }

private:

protected:
};
