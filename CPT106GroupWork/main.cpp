#include <iostream>
#include <customer.cpp>
#include <manager.cpp>
#include <chef.cpp>
using namespace std;

int main()
{
    user *user = nullptr;
    bool finishLog = false;
    int choseJob;
    cout << "Welcome to Restaurant Management System" << endl;
    do
    {
        cout << "What would you like to log in as?" << endl
             << "1. Manager\t2. Chef\t3. Customer\t4. exit\t1. Show menu\t2. Order\t3. Checkout" << endl;
        cin >> choseJob;
        switch (choseJob)
        {
        case 1: //login in as manager
            user = new manager();
            finishLog = true;
            break;
        case 2: //Chef
            user = new chef();
            finishLog = true;
            break;
        case 3: //customer
            user = new customer();
            finishLog = true;
            break;
        case 4: //exit
            exit(0);
        default:
            cout << "Invalid input, please enter an integer between 1 and 4" << endl;
            break;
        }
    } while (finishLog = false);
    system("cls");
    cout << "Login successful" << endl;
    bool theEnd = false;
    int choseAction;
    cout << "What do you want to do?" << endl;
    switch (choseJob)
    {
    case 1: //manager
        do
        {
            cout << "1. Search\t2. Add to menu\t3. Delete meal" << endl;
            cin >> choseAction;
            switch (choseAction)
            {
            case 1:
                //1. Show menu
                break;
            case 2:
                //2. Order
                break;
            case 3:
                //3. Checkout
                break;
            default:
                cout << "Invalid input, please enter an integer between 1 and 3" << endl;
                break;
            }
        } while (theEnd = false);
        break;
    case 2: //chef
        do
        {
            cout << "1. Search\t2. Add to menu\t3. Delete meal" << endl;
            cin >> choseAction;
            switch (choseAction)
            {
            case 1:
                //1. Show menu
                break;
            case 2:
                //2. Order
                break;
            case 3:
                //3. Checkout
                break;
            default:
                cout << "Invalid input, please enter an integer between 1 and 3" << endl;
                break;
            }
        } while (theEnd = false);

        break;
    case 3: //customer
        do
        {
            cout << "1. Show menu\t2. Order\t3. Checkout" << endl;
            cin >> choseAction;
            switch (choseAction)
            {
            case 1:
                //1. Show menu
                break;
            case 2:
                //2. Order
                break;
            case 3:
                //3. Checkout
                break;
            default:
                cout << "Invalid input, please enter an integer between 1 and 3" << endl;
                break;
            }
        } while (theEnd = false);

        break;
    }

    return 0;
}