#include <iostream>
#include <limits>
#include <cstdlib>
using namespace std;

bool validInput = false;
void checkInput() {
    if (cin.fail()) {
        cout << "Invalid input! Expected a number!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } else {
        validInput = true;
    }
}

int main(int args, char* psvArgs[]) {
    int parties, max, min;
    float sum = 0;
    srand(time(NULL));

    while (!validInput) {
        cout << "Please input the # of Pizza Parties that you wish to test against (Higher # = more accurate): ";
        cin >> parties;
        checkInput();
    }
    validInput = false;

    while (!validInput) {
        cout << "\nPlease input the Maximum # of expected attendees: ";
        cin >> max;
        checkInput();
    }
    validInput = false;

    while (!validInput) {
        cout << "\nPlease input the Minimum # of expected attendees: ";
        cin >> min;
        cout << "\n";
        checkInput();
    }

    int* attendees = new int[parties];
    for (int x = 0; x < parties; x++) {
        attendees[x] = rand() % (max - min + 1) + min;
        sum += attendees[x];
        cout << "# of Attendees for Party " << x + 1 << ": " << attendees[x] << "\n";
    }

    delete[] attendees;
    cout << "The average # of attendees for your next party is: " << sum / parties << "\n";
    system("PAUSE");
    return 0;
}
