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
    double Grossprofit;
    double price, materialinventory;
    string searchmaterial, addmaterial, modifymaterial;
    cout << "Welcome to Restaurant Management System" << endl;
   do
    {
        cout << "What would you like to log in as?" << endl
             << "1. Manager\t2. Chef\t3. Customer\t4. exit\t" << endl;
        cin >> choseJob;
        switch (choseJob)
        {
        case 1: //login in as manager
            cout << "Please input your manager name:\n";
            cin >> name;
            cout << "Please input your manager id:\n";
            cin >> id;
            user = new manager(name,id);
            if(user->Login(managerlist.readAllStream()))
            {
                cout<< "The manager name does not exist or the id is incorrect";
            }
            finishLog = user->Login(managerlist.readAllStream());
            break;
        case 2: //Chef
            cout << "Please input your chef name:\n";
            cin >> name;
            cout << "Please input your chef id:\n";
            cin >> id;
            user = new chef(name, id);
            if (user->Login(cheflist.readAllStream()))
            {
                cout << "The chef name does not exist or the id is incorrect"; 
            }
            finishLog = user->Login(cheflist.readAllStream());
            break;
        case 3: //customer
            user = new customer(mymenu);
            finishLog = true;
            break;
        case 4: //exit
            exit(0);
        default:
            cout << "Invalid input, please enter an integer between 1 and 4" << endl;
            break;
        }
    } while (finishLog == false);
    system("cls");
    cout << "Login successful" << endl;
    bool theEnd = false;
    int choseAction;
    //cout << "What do you want to do?" << endl;
    //switch (choseJob)
    //{
    //case 1: //1. Order
    do
    {
        system("cls");
        int No = 0;
        cout << "---------------";
        //customer level
        cout << "|" << No++ << "." << setw(12) << "Order |\t";
        //const int choose = 0;
        //chef level
        cout << "|" << No++ << "." << setw(12) << "Add a dish |\t";
        cout << "|" << No++ << "." << setw(12) << "Delete a dish |\t";
        cout << "|" << No++ << "." << setw(12) << "Show menu |\t";
        cout << "|" << No++ << "." << setw(12) << "Search material|\t";
        cout << "|" << No++ << "." << setw(12) << "show materials |\t";
        //const int choose = 1;
        //manager level
        cout << "|" << No++ << "." << setw(12) << "add a material |\t";
        cout << "|" << No++ << "." << setw(12) << "delete a material |\t";
        cout << "|" << No++ << "." << setw(12) << "modify a material |\t";
        cout << "---------------";
        cin >> choseAction;
        switch (choseAction)
        {
        case 1:
        {
            int orderact;
            int dishact;
            do
            {
                system("cls");
                mymenu.showmenu();
                cout << "Please choose what to do next:\n";
                cout << "1. Order a dish\n2. Cancel a dish\n3. show oederd menu\n4. check\n";
                cin >> orderact;
                switch (orderact)
                {
                case 1: // order a dish
                    cout << "Please type dish No to order:\n";
                    cin >> dishact;
                    try
                    {
                        user->order(mymenu.getMenuList()[dishact]);
                    }
                    catch (const char* expect)
                    {
                        cout << expect << endl;
                        break;
                    }
                    break;
                case 2: // Cancel a dish
                    cout << "Please type dish No to delete:\n";
                    cin >> dishact;
                    try
                    {
                        user->deletedish(mymenu.getMenuList()[dishact]);
                    }
                    catch (const char* except)
                    {
                        cout << except << endl;
                        break;
                    }
                    mymenu.refresh(myinventory);
                    break;
                case 3: //show ordered menu
                    try
                    {
                        user->displaymenu();
                        system("pause");
                    }
                    catch (const char* except)
                    {
                        cout << except << endl;
                        break;
                    }
                    mymenu.refresh(myinventory);
                    break;
                case 4: //check
                    Grossprofit = user->check();
                    system("pause");
                    break;
                default:
                    break;
                }
            } while (orderact != 4);
            break;
        }
        case 2:   //2. Add to menu
            try
            {
                string dishname, material;
                double price = 0.0;
                vector<string> totalmaterial;
                cout << "Please input dish name(between 2 to 20 charactors): " << endl;
                cin >> dishname;
                int success = 1;
                while (success)
                {
                    cout << "Please input dish matrials(between 2 to 20 charactors)" << endl;
                    cin >> material;
                    totalmaterial.push_back(material);
                    cout << "If that is all materials, please input 0 to exit, if not, input 1 to continue";
                    cin >> success;
                }
                dish newdish(dishname, totalmaterial, myinventory, price);
                user->newDish(newdish, mydish, &mymenu, myinventory);
            }
            catch (const char* except)
            {
                cout << except << endl;
            }
            break;
        case 3: //3. Delete meal
            int dishact;
            system("cls");
            cout << "-----------------------------------------------------";
            cout << "|No.|        name        |count|price|";
            for (int i = 0; i < mydish.size(); i++) {
                cout << "|" << setw(2) << i << ".|" << setw(20) << mydish[i].getname() << "|" << setw(5) << mydish[i].getprice() << "|" << setw(20) << mydish[i].getmaterials()[0] << " |" << endl;
                for (int j = 1; j < mydish[i].getmaterials().size(); j++) {
                    cout << "|" << setw(4) << ".|" << setw(21) << "|" << setw(6) << "|" << setw(20) << mydish[i].getmaterials()[0] << " |" << endl;
                }
                cout << "----------------------------------------------------";
            }
            cout << "Please input delete dish:";
            cin >> dishact;
            for (auto iter = mydish.begin(); iter != mydish.end(); iter++) {
                if (distance(mydish.begin(), iter) == dishact) {
                    mymenu.deleteDish(mydish[distance(mydish.begin(), iter)]);
                    mydish.erase(iter);
                }
            }
            break;
        case 4: //4. Show menu
            mymenu.showmenu();
            break;
        case 5: //Search material
            cout << "Please input material name:\n";
            cin >> searchmaterial;
            try
            {
                cout << searchmaterial << myinventory.getInventory(searchmaterial);
            }
            catch (const char* except)
            {
                cout << except << endl;
            }
            break;
        case 6: //show materials
            break;
        case 7: //add materials
            cout << "Please input material name:\n";
            cin >> addmaterial;
            cout << "Please input material inventory:";
            cin >> materialinventory;
            cout << "Please input material price";
            cin >> price;
            try
            {
                myinventory.add(addmaterial, materialinventory, price);
            }
            catch (const char* except)
            {
                cout << except << endl;
            }
            break;
        case 8: //delete materials
            break;
        case 9: //modify a material
            cout << "Please input modify material name:\n";
            cin >> modifymaterial;
            cout << "Please input modify material price:\n";
            cin >> price;
            myinventory.changePrice(modifymaterial, price);
            break;
        default:
            cout << "Invalid input, please enter an integer between 1 and " << No << endl;
            break;
        }
    } while (theEnd == false);

 //   inventoryfile.writeinventoryToFile(matetials,myinventory);
    dishfile.writedishToFile(mydish);
        //case 2: //chef
        //    do
        //    {
        //        cout << "1. Search\t2. Add to menu\t3. Delete meal" << endl;
        //        cin >> choseAction;
        //        switch (choseAction)
        //        {
        //        case 1:
        //        {
        //            string targetmaterial;
        //        cin >> targetmaterial;
        //        user->searchMaterial(targetmaterial, searchinventory);
        //        //1. Search
        //        break;
        //        }
        //        case 2:
        //            user->newDish(*currentmenu,currentinventory);
        //            //2. Add to menu
        //            break;
        //        case 3:

        //            //3. Delete meal
        //            break;
        //        default:
        //            cout << "Invalid input, please enter an integer between 1 and 3" << endl;
        //            break;
        //        }
        //    } while (theEnd = false);

        //    break;
        //case 3: //customer
        //    do
        //    {
        //        cout << "1. Show menu\t2. Order\t3. Checkout" << endl;
        //        cin >> choseAction;
        //        switch (choseAction)
        //        {
        //        case 1:
        //            //1. Show menu
        //            break;
        //        case 2:
        //            order(newDish);
        //            //2. Order
        //            break;
        //        case 3:
        //            //3. Checkout
        //            break;
        //        default:
        //            cout << "Invalid input, please enter an integer between 1 and 3" << endl;
        //            break;
        //        }
        //    } while (theEnd = false);

        //    break;
        //}
    return 0;
}
