// Switch Case:
// Substitute for many long if-else statements.
// Compares variable value against case values.
// Match found then "break".

#include <iostream>
#include <string>

using namespace std;

int main()
{
    // char button;
    int button;
    cout << "Click button: ";
    cin >> button;

    // if (button == 'A')
    //     cout << "Hello" << endl;
    // else if (button == 'B')
    //     cout << "Namaste" << endl;
    // else if (button == 'C')
    //     cout << "Salut" << endl;
    // else if (button == 'D')
    //     cout << "Hola" << endl;
    // else if (button == 'E')
    //     cout << "Ciao" << endl;
    // else
    //     cout << "I'm still learning" << endl;



    // switch (button)
    // {
    // case 'A':
    //     cout << "Hello" << endl;
    //     break;
    // case 'B':
    //     cout << "Namaste" << endl;
    //     break;
    // case 'C':
    //     cout << "Salut" << endl;
    //     break;
    // case 'D':
    //     cout << "Hola" << endl;
    //     break;
    // case 'This is me':
    //     cout << "Ciao" << endl;
    //     break;
    // default:
    //     cout << "I'm still learning" << endl;
    //     break;
    // }




    switch (button)
    {
    case 1:
        cout << "Hello" << endl;
        break;
    case -2:
        cout << "Namaste" << endl;
        break;
    case 3:
        cout << "Salut" << endl;
        break;
    case 4:
        cout << "Hola" << endl;
        break;
    case 5:
        cout << "Ciao" << endl;
        break;
    case 6:
        cout << "Hello Ji! Kaise ho saare?" << endl;
        break;
    default:
        cout << "I'm still learning" << endl;
        break;
    }

    return 0;
}