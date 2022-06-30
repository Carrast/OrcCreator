// *****************************************************************************
// Source code for the Orc Creator!
// v1.0
// 
// Developed by:	Carrast
//                  Csanyi Bence
//                  csanyibence@gmail.com
//
// 2021/11 
// All rights reserved!
// *****************************************************************************
//
// TODO
// -let the user decide which orc fights (if there more than two ofc)
// -ability to create mutated orcs using virtual functions (Roar)
// -there's a 30% chance that the random generator will create a mutated, uruk-hai orc, then we will use the virtual function there
//
// QUESTIONS
// -szétszedtem a maint, orc_names.h és main_functions.h
// -tovább írtam a weapons-t
// -static változók! hogyan használjuk õket? number_orcs vagy num_orcs?
// -hogyan használja az ork a fegyót? hogyan érdemes megmondani, hogy õ ezt birtokolja? egyik class használja a másik classt

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <string>
#include "orc.h"
#include "mutated_orc.h"
#include "weapons.h"
#include "orc_names.h"
#include "main_functions.h"

// main static variables
int Weapon::num_weapons = 0;
unsigned short Orc::num_orcs = 0;

int main()
{
    Sword kard;
    Axe csatabard;
    Bow ij;
    //OneHandedAxe egykezes_balta;
    Mace buzogany;

    ij.SetRange(5.4);
    int sebzes1 = kard.Attack();
    int sebzes2 = csatabard.Attack();
    int sebzes3 = ij.Attack();
    
    std::vector<Weapon*> fegyvertar;
    fegyvertar.push_back(&kard);
    fegyvertar.push_back(&csatabard);
    fegyvertar.push_back(&ij);


    int sebzes4 = fegyvertar[0]->Attack();
    int sebzes5 = fegyvertar[1]->Attack();
    int sebzes6 = fegyvertar[2]->Attack();

    Bow* fegyverPtr = dynamic_cast <Bow*> (fegyvertar[2]);
    if (fegyverPtr)
    {
        fegyverPtr->SetRange(6.7);
    }

    Axe* bardPrt = dynamic_cast <Axe*> (fegyvertar[1]);
    if (bardPrt)
    {
        sebzes5 = bardPrt->Attack();
    }

    std::cout << fegyvertar[2]->GetNumWeapons();
    std::string fegyver_neve = fegyvertar[0]->GetName();

    // testing pairs!
    typedef std::pair<Orc*, Orc*> OrcPair;
    std::vector<OrcPair> torzs;

    OrcPair uj_tipusu_valami;
    // testing end





    // ----------------------------------------------------------------
    // ------------------------TRUE MAIN-------------------------------
    // ----------------------------------------------------------------

    // orc attributes
    std::string orc_name;
    int orc_strength;
    int orc_dexterity;
    int orc_endurance;
    int orc_intelligence;
    int orc_charisma;
  
    // vector
    int number_orcs = 0;
    std::vector<Orc*> array_orcs;

    // user choices
    std::string user_choice;
    char real_choice;
    int user_clone_choice = 0;

    // fight
    int max_health_fighter0 = 0;
    int max_health_fighter1 = 0;
    int max_mana_fighter0 = 0;
    int max_mana_fighter1 = 0;

    int health_fighter0 = 0;
    int health_fighter1 = 0;
    int mana_fighter0 = 0;
    int mana_fighter1 = 0; 

    int d6 = 0;
    int damage = 0;
    int magic_damage = 0;
    srand(int(time(0)));

    do
    {
        WelcomeText();
        ShowOptions();
        std::cout << "\nUser choice:\t\t - ";
        std::cin >> user_choice;
        real_choice = user_choice[0];
        std::cout << "\n";

        if (real_choice == 'a') // Create orc
        {
            std::cout << "Give name of the orc: ";
            std::cin.ignore();
            std::getline(std::cin, orc_name);

            std::cout << "\nValues must be between [5-20]!";
            std::cout << "\nStrength:\t\t";
            std::cin >> orc_strength;
            orc_strength = std::min(std::max(5, orc_strength), 20);
            std::cout << "Dexterity:\t\t";
            std::cin >> orc_dexterity;
            orc_dexterity= std::min(std::max(5, orc_dexterity), 20);
            std::cout << "Endurance:\t\t";
            std::cin >> orc_endurance;
            orc_endurance = std::min(std::max(5, orc_endurance), 20);
            std::cout << "Intelligence:\t\t";
            std::cin >> orc_intelligence;
            orc_intelligence = std::min(std::max(5, orc_intelligence), 20);
            std::cout << "Charisma:\t\t";
            std::cin >> orc_charisma;
            orc_charisma = std::min(std::max(5, orc_charisma), 20);

            std::cout << "\nOrc with the name " << orc_name << " is born!\n";
            number_orcs++;

            // create orc with function call
            array_orcs.push_back(CreateOrc(orc_name, orc_strength, orc_dexterity, orc_endurance, orc_intelligence, orc_charisma));
            system("pause");
            system("CLS");
            continue;

        } if (real_choice == 'b')   // Create 2 random orcs
        {
            // create 1. with function call
            array_orcs.push_back(CreateOrc(GetRandomOrcName(), (rand() % 15 + 6), (rand() % 15 + 6), (rand() % 15 + 6), (rand() % 15 + 6), (rand() % 15 + 6)));
            number_orcs++;

            // create 2. with function call /mutated/
            array_orcs.push_back(CreateMutatedOrc(GetRandomOrcName(), (rand() % 15 + 6), (rand() % 15 + 6), (rand() % 15 + 6), (rand() % 15 + 6), (rand() % 15 + 6)));
            number_orcs++;

            std::cout << "Two random orcs have been created!\n\n";

            system("pause");
            system("CLS");
            continue;

        } if (real_choice == 'c')   // List orcs
        {
            if (array_orcs[0]->GetNumOrcs())
            {
                ListOrcs(array_orcs[0]->GetNumOrcs(), array_orcs);
            }
            continue;

        } if (real_choice == 'd')   // let them fight!
        {
            if (number_orcs < 2)
            {
                std::cout << "There is only one orc, please create another to fight!\n\n";
                system("pause");
                system("CLS");
                continue;
            }
            else
            {
                std::cout << "\tLET THE FIGHT BEGIN!\n\n";
                std::cout << "\tChoose you warriors!\n";
                
                std::cout << "\t" << array_orcs[0]->its_name << " VS " << array_orcs[1]->its_name << "\n\n";

                // who strikes first
                if (array_orcs[0]->its_dexterity > array_orcs[1]->its_dexterity)
                {
                    std::cout << array_orcs[0]->its_name << " is quicker, he beings the fight!\n";
                }
                else
                {
                    std::cout << array_orcs[1]->its_name << " is quicker, he beings the fight!\n";
                    std::swap(array_orcs[0], array_orcs[1]);
                }

                // max health - max mana
                max_health_fighter0 = array_orcs[0]->its_health;
                max_health_fighter1 = array_orcs[1]->its_health;
                max_mana_fighter0 = array_orcs[0]->its_mana;
                max_mana_fighter1 = array_orcs[1]->its_mana;

                // health - mana pool
                health_fighter0 = array_orcs[0]->its_health;
                health_fighter1 = array_orcs[1]->its_health;
                mana_fighter0 = array_orcs[0]->its_mana;
                mana_fighter1 = array_orcs[1]->its_mana;

                do
                {
                    // orc 0 attack
                    std::cout << array_orcs[0]->its_name << " is attacking. " << array_orcs[0]->its_name << " is swinging his sword, doing ";
                    d6 = rand() % 6 + 1;
                    damage = (std::max(10, array_orcs[0]->its_strength) - 10) + d6;
                    std::cout << (std::max(10, array_orcs[0]->its_strength) - 10)  << " + " << d6 << " = "<< damage << " damage!\n";
                    health_fighter1 -= damage;
 
                    // orc 0 magic
                    if (array_orcs[0]->GetCharisma() > 14 && mana_fighter0 > 0)
                    {
                        std::cout << array_orcs[0]->its_name << " is using his magic skills, doing ";
                        d6 = rand() % 6 + 1;
                        magic_damage = d6;
                        health_fighter1 -= magic_damage;
                        mana_fighter0 -= magic_damage;
                        if (mana_fighter0 < 0) { mana_fighter0 = 0; }
                        std::cout << d6 << " extra damage! " << array_orcs[0]->its_name << "'s mana is [" << max_mana_fighter0 << "/" << mana_fighter0 << "]\n";
                    }
                    std::cout << array_orcs[1]->its_name << "'s health is [" << max_health_fighter1 << "/" << health_fighter1 << "].\n";

                    // death
                    if (health_fighter1 < 1) {
                        std::cout << array_orcs[0]->its_name << " has slain " << array_orcs[1]->its_name  << "!\n";
                        array_orcs[0]->its_experience += array_orcs[1]->its_health;
                        array_orcs[0]->its_kills++;
                        delete array_orcs[1];
                        array_orcs.erase(array_orcs.begin()+1);
                        number_orcs--;
                        break;
                    }

                    // orc 1 attack
                    std::cout << array_orcs[1]->its_name << " is attacking. " << array_orcs[1]->its_name << " is swinging his sword, doing ";
                    d6 = rand() % 6 + 1;
                    damage = (std::max(10, array_orcs[1]->its_strength) - 10) + d6;
                    std::cout << (std::max(10, array_orcs[1]->its_strength) - 10) << " + " << d6 << " = " << damage << " damage!\n";
                    health_fighter0 -= damage;
 
                    // orc 1 magic
                    if (array_orcs[1]->GetCharisma() > 14 && mana_fighter1 > 0)
                    {
                        std::cout << array_orcs[1]->its_name << " is using his magic skills, doing ";
                        d6 = rand() % 6 + 1;
                        magic_damage = d6;
                        health_fighter0 -= magic_damage;
                        mana_fighter1 -= magic_damage;
                        if (mana_fighter1 < 0) { mana_fighter1 = 0; }
                        std::cout << d6 << " extra damage! " << array_orcs[1]->its_name << "'s mana is [" << max_mana_fighter1 << "/" << mana_fighter1 << "]\n";
                    }
                    std::cout << array_orcs[0]->its_name << "'s health is [" << max_health_fighter0 << "/" << health_fighter0 << "].\n";

                    // death
                    if (health_fighter0 < 1) {
                        std::cout << array_orcs[1]->its_name << " has slain " << array_orcs[0]->its_name << "!\n";
                        array_orcs[1]->its_experience += array_orcs[0]->its_health;
                        array_orcs[1]->its_kills++;
                        delete array_orcs[0];
                        array_orcs.erase(array_orcs.begin() + 0);
                        number_orcs--;
                        break;
                    }

                } while (health_fighter0 > 0 && health_fighter1 > 0);

                system("pause");
                system("CLS");
                continue;
            }
        } if (real_choice == 'e')   // clone orc
        {
            std::cout << "Welcome to the orc cloning facility!\n\n";
            std::cout << "Number of orcs: " << number_orcs << "\n";
            for (std::size_t i = 0; i < array_orcs.size(); i++)
            {
                std::cout << i + 1 << ". " << array_orcs[i]->its_name << "\n";
            }

            std::cout << "\nGive the number of the orc you want to clone: \n";
            std::cin.ignore();
            std::cin >> user_clone_choice;
            if (user_clone_choice < 1) { user_clone_choice = 1; }
            if (user_clone_choice > number_orcs) { user_clone_choice = number_orcs; }

            // copy construcor call
            Orc *copy_orc = new Orc(*array_orcs[user_clone_choice-1]);
            number_orcs++;
            array_orcs.push_back(copy_orc);

            std::cout << array_orcs[user_clone_choice-1]->its_name << " has been cloned!\n\n";

            system("pause");
            system("CLS");
            continue;
        } if (real_choice == 'f')   // pointers
        {
            std::cout << "Pointer testing!\n\n";
            Orc *pointerOrc;
            int *pointerOrc_strength;

            pointerOrc = array_orcs[0];
            pointerOrc_strength = &array_orcs[0]->its_strength;

            std::cout << "Accessing data with pointer:\n";
            std::cout << "pointerOrc:" << pointerOrc << "\n";
            std::cout << "*pointerOrc:" << pointerOrc->its_strength << "\n";
            std::cout << "*pointerOrc_strength:" << *pointerOrc_strength << "\n";
            
            system("pause");
            system("CLS");
            continue;
        } if (real_choice == 'x' or real_choice != 'X')   // exit
        {
            std::cout << "Exiting application...\n";
            break;

        } else
        {
            system("CLS");
            std::cout << "\nWrong character. Please give another!\n";
            continue;
        }
    } while (real_choice != 'x' && real_choice != 'X');
    
    // must release memory occupied by orcs, everything created with new must be deleted...
    // this is iteration you could use it in ListOrcs but there you could use a const iterator
    for (std::vector<Orc*>::iterator o = array_orcs.begin(); o != array_orcs.end(); ) {
        delete *o;                      // delete from heap
        o = array_orcs.erase(o);        // erase from array in stack
    }

    return 0;
}
