// Chapter 8 Practice Problem 4

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

enum SlotMachineOption {
        SMO_BLANK = 0,
        SMO_CHERRY = 1,
        SMO_DOLLAR = 2,
        SMO_DICE = 3,
        SMO_X = 4
};
SlotMachineOption slot1, slot2, slot3 = SMO_BLANK;

void displayslots ();
void displayslot ( SlotMachineOption o );

int main ()
{
    srand( time( NULL ) );
    int rand1 = rand() % ( 4 - 1 + 1 ) + 1;
    int rand2 = rand() % ( 4 - 1 + 1 ) + 1;
    int rand3 = rand() % ( 4 - 1 + 1 ) + 1;

    displayslots();
    cout << "You crank the lever...\n";\
    cout << rand1 << rand2 << rand3 << endl;
    slot1 = SlotMachineOption( rand() % ( 4 - 1 + 1 ) + 1 );
    slot2 = SlotMachineOption( rand() % ( 4 - 1 + 1 ) + 1 );
    slot3 = SlotMachineOption( rand() % ( 4 - 1 + 1 ) + 1 );
    displayslots();

    if ( slot1 == SMO_X && slot1 == slot2 && slot1 == slot3 )
    {
        cout << "Triple X's!\n";
    }
    else if ( slot1 == slot2 && slot1 == slot3 )
    {
        cout << "Three of a kind!\n";
    }
}

void displayslot ( SlotMachineOption o )
{
    switch ( o )
    {
    case SMO_BLANK:
        cout << "BLANK\t";
        break;
    case SMO_CHERRY:
        cout << "CHERRY\t";
        break;
    case SMO_DOLLAR:
        cout << "$\t";
        break;
    case SMO_DICE:
        cout << "[::]\t";
        break;
    case SMO_X:
        cout << "X\t";
        break;
    }
}

void displayslots ()
{
    displayslot ( slot1 );
    displayslot ( slot2 );
    displayslot ( slot3 );
    cout << endl;
}