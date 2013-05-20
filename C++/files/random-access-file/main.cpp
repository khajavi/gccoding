#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include "ClientData.h"

using namespace std;

void outputLine( ostream&, const ClientData& );

int main() {
    int accountNumber;
    string lastName;
    string firstName;
    double balance;

    ofstream outCredit( "credit.dat", ios::out | ios::app | ios::binary );

    if( !outCredit ) {
        cerr << "File could not be opened." << endl;
        exit( 1 );
    }

    cout << "Enter account number (1 to 100, 0 to end input)\n?";

    ClientData client;
    cin >> accountNumber;

    for ( int i = 0; i < 100; ++i ) {
        outCredit.write( reinterpret_cast< const char * >( &client ),
                         sizeof( ClientData ) );
    }

    while ( accountNumber > 0 && accountNumber <= 100 ) {
        cout << "Enter lastname, firstname, balance\n?";
        cin >> lastName;
        cin >> firstName;
        cin >> balance;

        client.setAccountNumber( accountNumber );
        client.setFirstName( firstName );
        client.setLastName( lastName );
        client.setBalance( balance );

        outCredit.seekp( ( client.getAccountNumber() - 1 ) *
                         sizeof( ClientData ) );

        outCredit.write( reinterpret_cast< const char * > ( &client ),
                         sizeof( ClientData ) );

        cout << "Enter account number\n?";
        cin >> accountNumber;
    }

    ifstream inCredit( "credit.dat", ios::in | ios::binary );

    if( !inCredit ) {
        cerr << "File could not be opened." << endl;
        exit( 1 );
    }

    cout << left << setw( 10 ) << "Account" << setw( 16 )
         << "Last Name" << setw( 11 ) << "First Name" << left
         << setw( 10 ) << right << "Balance" << endl;

    inCredit.read( reinterpret_cast< char * >( &client ),
                   sizeof( ClientData ) );
    while( inCredit && !inCredit.eof() ) {
        if ( client.getAccountNumber() != 0 ) {
            outputLine( cout, client );
        }
        inCredit.read( reinterpret_cast< char * >( &client ),
                       sizeof( ClientData ) );
    }

    return 0;
}


void outputLine(ostream &output , const ClientData &record ) {
    output << left << setw( 10 ) << record.getAccountNumber()
           << setw( 16 ) << record.getLastName()
           << setw( 11 ) << record.getFirstName()
           << setw( 10 ) << setprecision( 2 ) << right << fixed
           << showpoint << record.getBalance() << endl;
}
