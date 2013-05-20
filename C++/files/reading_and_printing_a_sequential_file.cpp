#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;

void outputline(int, const string, double);

int main() {
    ifstream in_client_file("client.txt", ios::in);

    if(!in_client_file) {
        cerr << "File could not opened" << endl;
        exit(1);
    }

    int account;
    string name;
    double balance;

    cout << left << setw(10) << "Account" << setw(13)
         << "Name" << "Balance" << endl << fixed << showpoint;

    while (true) {
        in_client_file >> account >> name >> balance;
        if (in_client_file.eof()) break;
        outputline(account, name, balance);
    }

    return 0;
}


void outputline(int account, const string name, double balance) {
    cout << left << setw( 10 ) << account << setw( 13 ) << name
         << setw( 7 ) << setprecision( 2 ) << right << balance << endl;
}
