#include "Character.h"

int main(int argc, char* argv[])
{
    Character* Bob = new Character(10, 50, Human, Fighter, "Bob", 1);
    Character Bob1 = Character(10, 50, Human, Fighter, "Bob1", 1);

    cout << Bob->name << endl;
    cout << Bob1.name << endl;
    return 0;
}
