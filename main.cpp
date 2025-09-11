#include <iostream>
#include <string.h>
#include <sstream>
#include <iomanip>
#include <cryptopp/sha.h>
#include <cryptopp/hex.h>
#include <cryptopp/filters.h>

using namespace std;
string sha256(const string& str);

int main() {

    string username;
    string password;
    string enteredUsername;
    string enteredPassword;

    // Create a function to hash password. FINISHED
    // Figure out how I can make code remember the user for next execution. WIP
    // Create a checker so that this prompt only shows if there is no accounts in the future save file. NA

    // - Prompt user for Username -
    cout << "Create Username: ";
    cin >> username;


        // - Prompt user for password - 
    cout << "Create Password: ";
    cin >> password;

        // - Check Length - 
    while (password.length() < 12) {
        cout << "Password must be 12 characters." << endl;
        cout << "Create Password: ";
        cin >> password;
    }
        // - Hash Password -
    string hashedPassword = sha256(password);

        // -Wipe the password from memory -
    fill(password.begin(), password.end(), '\0');


    cout << "Enter Username: ";
    cin >> enteredUsername;

    while (enteredUsername != username) { // To be honest this is a security risk might remove
        cout << "Invalid Username";
        cout << "Enter Username: ";
        cin >> enteredUsername;
    }

        // - Prompt user for password -
    cout << "Enter Password: ";
    cin >> enteredPassword;

    string hashedenteredPassword = sha256(enteredPassword);

        // - Wipe password from memory 
    fill(enteredPassword.begin(), enteredPassword.end(), '\0');

    while (hashedenteredPassword != hashedPassword) {
        cout << "Invalid Password" << endl;
        cout << "Enter Password: ";
        cin >> enteredPassword;
    }

}

string sha256(const string& str) {
    using namespace CryptoPP;

    SHA256 hash;
    string digest;

    StringSource s(
        str,
        true,
        new HashFilter(
            hash,
            new HexEncoder(
                new StringSink(digest),
                false // false = lowercase hex
            )
        )
    );

    return digest;
}