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
    user *User = nullptr;
    user loginuser;
    FileIO inventoryfile("inventory.txt");
    FileIO dishfile("dish.txt");
    FileIO Loginlist("Loginlist.txt");
    inventory myinventory(inventoryfile.readAllStream());
    vector<dish> mydish = dishfile.readdish(myinventory);
    menu mymenu(mydish, myinventory), ordermenu;
    bool success = true;
    string name, id;
    double Grossprofit = 0.0;
    double price = 0.0;
    int materialinventory;
    string searchmaterial, addmaterial, modifymaterial;
    job userjob;
    do
    {
        system("cls");
        cout << "-------------------------------------------\n";
        cout << "|" << setw(42) << " |" << endl;
        cout << "| Welcome to Restaurant Management System |" << endl;
        cout << "|" << setw(42) << " |" << endl;
        cout << "|-----------------------------------------|\n";
        cout << setw(42) << setiosflags(ios::left) << "|Please login: " << "|\n";
        cout << setw(42) << setiosflags(ios::left) << "|(Input anything login as a custemer)" << "|\n";
        cout << "-------------------------------------------\n";
        try
        {
            userjob = loginuser.Login(Loginlist.readAllStream());
            if (userjob == man) {
                User = new manager();
            }
            else if (userjob == che) {
                User = new chef();
            }
            else {
                User = new customer();
            }
            success = false;
        }
        catch (const char* expect)
        {
            cout << expect;
        }
    } while (success);
    system("cls");
    cout << "Login as ";
    if (userjob == 0) { cout << "manager "; }
    else if (userjob == 1) { cout << "chef "; }
    else { cout << "customer "; }
    cout<< "successful" << endl;
    system("pause");
    int choseAction;
    success = true;
    userjob = man;
    do
    {
        int No = 0;
        try
        {
            system("cls");
            cout << " -----------------------\n";
            //customer level
            cout << "| " << No++ << "." << setw(20) << "exit " << "|\n";
            cout << "| " << No++ << "." << setw(20) << "Order" << "|\n";
            //chef level
            if (userjob == che || userjob == man) {
                cout << "| " << No++ << "." << setw(20) << "Add a dish " << "|\n";
                cout << "| " << No++ << "." << setw(20) << "Delete a dish " << "|\n";
                cout << "| " << No++ << "." << setw(20) << "Show menu  " << "|\n";
                cout << "| " << No++ << "." << setw(20) << "Search material " << "|\n";
                cout << "| " << No++ << "." << setw(20) << "show materials " << "|\n";
            }
            //manager level
            if (userjob == man) {
                cout << "| " << No++ << "." << setw(20) << "add a material " << "|\n";
                cout << "| " << No++ << "." << setw(20) << "delete a material " << "| \n";
                cout << "| " << No++ << "." << setw(20) << "modify a material " << "|\n";
                cout << "| " << No << "." << setw(19) << "showGrossprofit" << "|\n";
            }
            cout << " -----------------------\n";
            cout << "Please choose what to do next: \n";
            cin >> choseAction;
            if (userjob == 2 && choseAction > 1) {
                throw NoPermissionException();
            }
            else if (userjob == 1 && (choseAction > 6 || choseAction == 1)) {
                throw NoPermissionException();
            }
        }
        catch (const exception& e)
        {
            cout << e.what();
            system("pause");
            continue;
        }
       
        switch (choseAction)
        {
        case 0:
            success = false;
            break;
        case 1:
            int orderact;
            int dishact;
            do
            {
                system("cls");
                mymenu.showmenu();
                cout << "Please choose what to do next:\n";
                cout << "1. Order a dish\n2. Cancel a dish\n3. show oederd menu\n4. check(exit)\n";
                cin >> orderact;
                switch (orderact)
                {
                case 1: // order a dish
                    try
                    {
                        cout << "Please type dish No to order:\n";
                        cin >> dishact;
                        User->order(mymenu.getMenuList()[dishact]);
                        cout << "Order successful\n";
                        system("pause");
                    }
                    catch (const exception& e)
                    {
                        cout << e.what() << endl;
                        system("pause");
                        break;
                    }
                    break;
                case 2: // Cancel a dish
                    try
                    {
                        cout << "Please type dish No to cancel:\n";
                        cin >> dishact;
                        User->deletedish(mymenu.getMenuList()[dishact]);
                        cout << "Cancel successful\n";
                        mymenu.refresh(myinventory);
                        system("pause");
                    }
                    catch (const exception& e)
                    {
                        cout << e.what() << endl;
                        system("pause");
                        break;
                    }
                    break;
                case 3: //show ordered menu
                    try
                    {
                        User->displaymenu();
                        system("pause");
                        mymenu.refresh(myinventory);
                    }
                    catch (const exception& e)
                    {
                        cout << e.what() << endl;
                        system("pause");
                        break;
                    }
                    break;
                case 4: //check
                    cout << "The total price is: \n";
                    Grossprofit = User->check();
                    system("pause");
                    break;
                default:
                    break;
                }
            } while (orderact != 4);
            break;
        case 2:   //2. Add a dish to menu
            try
            {
                string dishname, material;
                double price = 0.0;
                vector<string> totalmaterial;
                cout << "Please input dish name(between 2 to 20 charactors): " << endl;
                cin >> dishname;
                int success = 1;
                cout << "Please input price:\n";
                cin >> price;
                while (success)
                {
                    cout << "Please input dish matrials(between 2 to 20 charactors)" << endl;
                    cin >> material;
                    totalmaterial.push_back(material);
                    cout << "If that is all materials, please input 0 to exit, if not, input 1 to continue\n";
                    cin >> success;
                }
                dish newdish(dishname, totalmaterial, myinventory, price);
                price = 0.0;
                for (int i = 0; i < mydish.size(); i++) {
                    if (dishname == mydish[i].getname()) {
                        throw DishexistException();
                    }
                }
                mydish.push_back(newdish);
 //               User->newDish(newdish, mydish, &mymenu, myinventory);
                cout << "Add a dish successful";
                system("pause");
            }
            catch (const exception& e)
            {
                cout << e.what() << endl;
                system("pause");
                break;
            }
            break;
        case 3: //3. Delete a dish from menu
            try
            {
                system("cls");
                cout << " ------------------------------------------ \n";
                cout << "|No.|        name        |price| materials |\n";
                cout << " ------------------------------------------ \n";
                for (int i = 0; i < mydish.size(); i++) {
                    cout << "|" << setw(2) << i << ".|" << setw(20) << mydish[i].getname() << "|" << setw(5) << mydish[i].getprice() << "|" << setw(10) << mydish[i].getmaterials()[0] << " |" << endl;
                    for (int j = 1; j < mydish[i].getmaterials().size(); j++) {
                        cout << "|" << setw(3) << " " << setw(21) << "|" << setw(6) << "|" << "|" << setw(10) << mydish[i].getmaterials()[j] << " |" << endl;
                    }
                    cout << " ------------------------------------------ \n";
                }
                cout << "Please input delete dish:";
                cin >> dishact;
                for (auto iter = mydish.begin(); iter != mydish.end(); iter++) {
                    if (distance(mydish.begin(), iter) == dishact) {
                        mymenu.deleteDish(mydish[distance(mydish.begin(), iter)]);
                        mydish.erase(iter);
                        break;
                    }
                }
                cout << "Delete dish successful";
                system("pause");
            }
            catch (const exception& e)
            {
                cout<<e.what()<<endl;
                system("pause");
                break;
            }
            break;
        case 4: //4. Show menu
            mymenu.showmenu();
            system("pause");
            break;
        case 5: //Search material
            try
            {
                cout << "Please input material name:\n";
                cin >> searchmaterial;
                cout << searchmaterial << myinventory.getInventory(searchmaterial);
                system("pause");
            }
            catch (const exception& e)
            {
                cout << e.what() << endl;
                system("pause");
                break;
            }
            break;
        case 6: //show materials
            system("pause");
            break;
        case 7: //add materials
            try
            {
                cout << "Please input material name:\n";
                cin >> addmaterial;
                cout << "Please input material inventory:\n";
                cin >> materialinventory;
                cout << "Please input material price:\n";
                cin >> price;
                myinventory.add(addmaterial, materialinventory, price);
                cout << "Add successful";
                system("pause");
            }
            catch (const exception& e)
            {
                cout << e.what() << endl;
                system("pause");
                break;
            }
            break;
        case 8: //delete materials
            system("pause");
            break;
        case 9: //modify a material
            try
            {
                cout << "Please input modify material name:\n";
                cin >> modifymaterial;
                cout << "Please input modify material price:\n";
                cin >> price;
                myinventory.changePrice(modifymaterial, price);
                cout << "modify successful";
                system("pause");
            }
            catch (const exception& e)
            {
                cout << e.what() << endl;
                system("pause");
                break;
            }
            break;
        case 10:
            cout << "The total profit is: " << Grossprofit << endl;
        default:
            cout << "Invalid input, please enter an integer between 1 and " << No << endl;
            system("pause");
            break;
        }
    } while (success);

//    inventoryfile.writeinventoryToFile(matetials,myinventory);
    dishfile.writedishToFile(mydish);
    return 0;
}
