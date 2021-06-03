#include <iostream>
#include"dish.h"
#include"menu.h"
#include"inventory.h"
#include"chef.h"
#include"customer.h"
#include"manager.h"
#include"user.h"
#include"FileIO.h"
using namespace std;

int main()
{
    user *user = nullptr;
    FileIO inventoryfile("inventory.txt");
    FileIO dishfile("dish.txt");
    FileIO cheflist("chef.txt");
    FileIO managerlist("managerlist.txt");
    inventory myinventory(inventoryfile.readAllStream());
    vector<dish> mydish = dishfile.readdish(myinventory);
    menu mymenu(mydish, myinventory);
    bool finishLog = false;
    string name, id;
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
            cout << "Please input your manager name:\n";
            cin >> name;
            cout << "Please input your manager id:\n";
            cin >> id;
            user = new manager(name,id);
            if(user->Login(managerlist.readAllStream())){cout<< "The manager name does not exist or the id is incorrect";}
            finishLog = user->Login(managerlist.readAllStream());
            break;
        case 2: //Chef
            cout << "Please input your chef name:\n";
            cin >> name;
            cout << "Please input your chef id:\n";
            cin >> id;
            user = new chef(name, id);
            if (user->Login(cheflist.readAllStream())) { cout << "The chef name does not exist or the id is incorrect"; }
            finishLog = user->Login(cheflist.readAllStream());
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
            cout << "1. Search\t2. Add to menu\t3. Delete meal\t4. Show menu\t5. Order\t6. Checkout" << endl;
            cin >> choseAction;
            switch (choseAction)
            {
            case 1:
            {
                string targetmaterial;
                cin >> targetmaterial;
                user->searchMaterial(targetmaterial, myinventory);
                break;
            }//1. Search
            case 2:
                user->newDish(*currentmenu, myinventory);
                //2. Add to menu
                break;
            case 3:
                //3. Delete meal
                break;
            case 4:
                //4. Show menu
                break;
            case 5:
                order(newDish);
                //5. Order
                break;
            case 6:
                //6. Checkout
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
            {
                string targetmaterial;
            cin >> targetmaterial;
            user->searchMaterial(targetmaterial, searchinventory);
            //1. Search
            break;
            }
            case 2:
                user->newDish(*currentmenu,currentinventory);
                //2. Add to menu
                break;
            case 3:

                //3. Delete meal
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
                order(newDish);
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
