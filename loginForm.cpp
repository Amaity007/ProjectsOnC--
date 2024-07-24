#include <iostream>
#include <fstream>
using namespace std;

class Registration
{
private:
    string un, email, psswd;
    string searchUN, searchEMAIL, searchPSSWD;
    fstream file;

public:
    void login()
    {
        cout << "-----Login Page-----" << endl;
        cout << "Enter your User Name:";
        cin.ignore();
        getline(cin, searchUN);
        cout << "Enter the password: ";
        getline(cin, searchPSSWD);

        file.open("login-data.txt", ios::in);
        bool found = false;

        while (getline(file, un, '*') && getline(file, email, '*') && getline(file, psswd, '\n'))
        {
            if (un == searchUN && psswd == searchPSSWD)
            {
                found = true;
                cout << "Login Successfully!!!" << endl;
                cout << "User Name: " << un << endl;
                cout << "Email ID: " << email << endl;
                break;
            }
        }

        file.close();

        if (!found)
        {
            cout << "Invalid User Name or Password!!!" << endl;
        }
    }

    void signUp()
    {
        cout << "Enter your User Name:" << endl;
        cin.ignore();
        getline(cin, un);
        cout << "Enter your Email:" << endl;
        getline(cin, email);
        cout << "Enter your Password:" << endl;
        getline(cin, psswd);

        file.open("login-data.txt", ios::out | ios::app);
        if (file.is_open())
        {
            file << un << "*" << email << "*" << psswd << endl;
            file.close();
            cout << "Sign-up Successful!" << endl;
        }
        else
        {
            cout << "Error: Unable to open file for writing." << endl;
        }
    }

    void forgotPassword()
    {
        cout << "Enter your User Name:";
        cin.ignore();
        getline(cin, searchUN);
        cout << "Enter your Email:";
        getline(cin, searchEMAIL);

        file.open("login-data.txt", ios::in);
        bool found = false;

        while (getline(file, un, '*') && getline(file, email, '*') && getline(file, psswd, '\n'))
        {
            if (un == searchUN && email == searchEMAIL)
            {
                found = true;
                cout << "Your Password is: " << psswd << endl;
                break;
            }
        }

        file.close();

        if (!found)
        {
            cout << "Account not Found!!!" << endl;
        }
    }

} obj;
int main()
{
    char choice;
    cout << "1)Login" << endl;
    cout << "2)Sign-Up" << endl;
    cout << "3)Forgot Password" << endl;
    cout << "4)Exit" << endl;
    cout << "Enter your Choice:";
    cin >> choice;
    cin.ignore();
    switch (choice)
    {
    case '1':
        obj.login();
        break;

    case '2':
        obj.signUp();
        break;

    case '3':
        obj.forgotPassword();
        break;

    case '4':
        return 0;
        break;

    default:
        cout << "Invalid Input!!!" << endl;
    }
}