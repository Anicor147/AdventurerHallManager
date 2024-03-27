
#include "Character.h"

int main(int argc, char* argv[])
{
    Character Bob = Character(10, 50, Human, Fighter, "Bob", 1);

    cout << Bob.name;
    return 0;
}
