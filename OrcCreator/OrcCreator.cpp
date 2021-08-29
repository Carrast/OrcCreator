// OrcCreator.cpp
// v1.0
// by Carrast
// 
// TODO
// -let the user decide which orc fights (if there more than two ofc)

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <string>
#include "orc.h"

void WelcomeText();
void ShowOptions();

// TODO
Orc *CreateOrc(const std::string& name, int strength, int dexterity, int endurance, int intelligence, int charisma);
void ListOrcs(int number_orcs, const std::vector<Orc*>& orcs);

int main()
{
    // random orc names
    std::string random_orc_names_start[10] = { "Ugh", "Ug", "Aba", "Uh", "Zaba", "Abz", "Cucu", "Ragna", "Kraz", "Frah" };
    std::string random_orc_names_end[10] = { "luk", "burz", "gog", "fark", "gug", "lug", "luk", "ork", "mug", "kuk" };
    std::string random_name1;
    std::string random_name2;

    int number_orcs = 0;
    std::string orc_name;
    int orc_strength;
    int orc_dexterity;
    int orc_endurance;
    int orc_intelligence;
    int orc_charisma;
    
    std::vector<Orc*> array_orcs;

    std::string user_choice;
    char real_choice;
    int user_clone_choice = 0;

    // fight
    int user_fighter_choice_0 = 0;  // unused right now
    int user_fighter_choice_1 = 0;  // unused right now
    int health_fighter0 = 0;
    int health_fighter1 = 0;
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
            // 1
            random_name1 = random_orc_names_start[rand() % 10] + random_orc_names_end[rand() % 10];
            Orc *random_orc1 = new Orc(random_name1, (rand()%15 + 6), (rand()%15 + 6), (rand()%15 + 6));
            random_orc1->SetIntelligence(rand()%15 + 6);
            random_orc1->SetCharisma(rand() % 15 + 6);
            number_orcs++;
            array_orcs.push_back(random_orc1);

            // 2
            random_name2 = random_orc_names_start[rand() % 10] + random_orc_names_end[rand() % 10];
            Orc *random_orc2 = new Orc(random_name2, (rand() % 15 + 6), (rand() % 15 + 6), (rand() % 15 + 6));
            random_orc2->SetIntelligence(rand() % 15 + 6);
            random_orc2->SetCharisma(rand() % 15 + 6);
            number_orcs++;
            array_orcs.push_back(random_orc2);

            std::cout << "Two random orcs have been created!\n\n";

            system("pause");
            system("CLS");
            continue;

        } if (real_choice == 'c')   // List orcs
        {
            ListOrcs(number_orcs, array_orcs);
            continue;

        } if (real_choice == 'd')   // let them fight!
        {
            if (number_orcs < 2)
            {
                std::cout << "There are only one orc, please create another to fight!\n\n";
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

                // max health pool
                health_fighter0 = array_orcs[0]->its_health;
                health_fighter1 = array_orcs[1]->its_health;

                do
                {
                    // orc 0 attack
                    std::cout << array_orcs[0]->its_name << " is attacking. " << array_orcs[0]->its_name << " is swinging his sword, doing ";
                    d6 = rand() % 6 + 1;
                    damage = (std::max(10, array_orcs[0]->its_strength) - 10) + d6 + array_orcs[0]->its_kills;
                    std::cout << (std::max(10, array_orcs[0]->its_strength) - 10)  << " + " << d6 << " + " << array_orcs[0]->its_kills << " = "<< damage << " damage!\n";
                    array_orcs[1]->its_health -= damage;
 
                    // orc 0 magic
                    if (array_orcs[0]->GetCharisma() > 16 && array_orcs[0]->its_mana > 0)
                    {
                        std::cout << array_orcs[0]->its_name << " is using his magic skills, doing ";
                        d6 = rand() % 6 + 1;
                        magic_damage = d6;
                        std::cout << d6 << " extra damage!\n";
                        array_orcs[1]->its_health -= magic_damage;
                        array_orcs[0]->its_mana -= magic_damage;

                        if (array_orcs[0]->its_mana < 0) { array_orcs[0]->its_mana = 0; }
                    }
                    std::cout << array_orcs[1]->its_name << "'s health is [" << health_fighter1 << "/" << array_orcs[1]->its_health << "].\n";

                    // death
                    if (array_orcs[1]->its_health < 1) {
                        std::cout << array_orcs[0]->its_name << " has slain " << array_orcs[1]->its_name  << "!\n";
                        array_orcs[0]->its_health = array_orcs[0]->its_endurance * 3;
                        array_orcs[0]->its_kills++;
                        array_orcs.erase(array_orcs.begin()+1);
                        number_orcs--;
                        break;
                    }

                    // orc 1 attack
                    std::cout << array_orcs[1]->its_name << " is attacking. " << array_orcs[1]->its_name << " is swinging his sword, doing ";
                    d6 = rand() % 6 + 1;
                    damage = (std::max(10, array_orcs[1]->its_strength) - 10) + d6 + array_orcs[1]->its_kills;
                    std::cout << (std::max(10, array_orcs[1]->its_strength) - 10) << " + " << d6 << " + " << array_orcs[1]->its_kills << " = " << damage << " damage!\n";
                    array_orcs[0]->its_health -= damage;
 
                    // orc 1 magic
                    if (array_orcs[1]->GetCharisma() > 16 && array_orcs[1]->its_mana > 0)
                    {
                        std::cout << array_orcs[1]->its_name << " is using his magic skills, doing ";
                        d6 = rand() % 6 + 1;
                        magic_damage = d6;
                        std::cout << d6 << " extra damage!\n";
                        array_orcs[0]->its_health -= magic_damage;
                        array_orcs[1]->its_mana -= magic_damage;
                        if (array_orcs[1]->its_mana < 0) { array_orcs[0]->its_mana = 0; }
                    }
                    std::cout << array_orcs[0]->its_name << "'s health is [" << health_fighter0 << "/" << array_orcs[0]->its_health << "].\n";

                    // death
                    if (array_orcs[0]->its_health < 1) {
                        std::cout << array_orcs[1]->its_name << " has slain " << array_orcs[0]->its_name << "!\n";
                        array_orcs[1]->its_health = array_orcs[1]->its_endurance * 3;
                        array_orcs[1]->its_kills++;
                        array_orcs.erase(array_orcs.begin() + 0);
                        number_orcs--;
                        break;
                    }

                } while (array_orcs[0]->its_health > 0 && array_orcs[1]->its_health > 0);

                system("pause");
                system("CLS");
                continue;
            }
        } if (real_choice == 'e')   // clone orc
        {
            std::cout << "Welcome to the orc cloning facility!\n\n";
            std::cout << "Number of orcs: " << number_orcs << "\n";
            for (int i = 0; i < number_orcs; i++)
            {
                std::cout << i + 1 << ". " << array_orcs[i]->its_name << "\n";
            }

            std::cout << "\nGive the number of the orc you want to clone: \n";
            std::cin.ignore();
            std::cin >> user_clone_choice;
            if (user_clone_choice < 1) { user_clone_choice = 1; }
            if (user_clone_choice > number_orcs) { user_clone_choice = number_orcs; }

            // copy construcor called
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
            Orc* pointerOrc;
            int pointerOrc_strength;

            pointerOrc = array_orcs[0];
            pointerOrc_strength = array_orcs[0]->its_strength;

            std::cout << "Accessing data with pointer:\n";
            std::cout << "pointerOrc:" << pointerOrc << "\n";
            std::cout << "*pointerOrc:" << pointerOrc->its_strength << "\n";
            std::cout << "*pointerOrc_strength:" << pointerOrc_strength << "\n";
            
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
    // this is iteration you could use it in ListOrcs but there you coud use a const iterator
    for (std::vector<Orc*>::iterator o = array_orcs.begin(); o != array_orcs.end(); ) {
        delete* o;
        o = array_orcs.erase(o);
    }

    return 0;
}

void WelcomeText() {
    std::cout << "-------------------------------------\n";
    std::cout << "--------Welcome to Orc Creator-------\n";
    std::cout << "--------------by Carrast-------------\n";
    std::cout << "----------------v1.0-----------------\n\n";
}

void ShowOptions() {
    std::cout << "Choose from the options below:\n\n";
    std::cout << "Create new orc\t\t - a\n";
    std::cout << "Create 2 randoms\t - b\n";
    std::cout << "List existing orcs\t - c\n";
    std::cout << "Let them fight!\t\t - d\n";
    std::cout << "Clone orc\t\t - e\n";
    std::cout << "Pointer testing\t\t - f\n";
    std::cout << "Exit\t\t\t - x\n";
}

Orc *CreateOrc(const std::string& name, int strength, int dexterity, int endurance, int intelligence, int charisma) {
    Orc *orc = new Orc(name, strength, dexterity, endurance);
    orc->SetIntelligence(intelligence);
    orc->SetCharisma(charisma);
    orc->Roar(intelligence, charisma);
    return orc;
}

void ListOrcs(int number_orcs, const std::vector<Orc*>& array_orcs) {

    std::cout << "Number of orcs: " << number_orcs << "\n";

    for (std::size_t i = 0; i < array_orcs.size(); i++)
    {
        std::cout << "Name:\t\t\t" << array_orcs[i]->its_name << "\n";
        std::cout << "Number of kills:\t" << array_orcs[i]->its_kills << "\n\n";
        std::cout << "Strength:\t\t" << array_orcs[i]->its_strength << "\n";
        std::cout << "Dexterity:\t\t" << array_orcs[i]->its_dexterity << "\n";
        std::cout << "Endurance:\t\t" << array_orcs[i]->its_endurance << "\n";
        std::cout << "Intellect:\t\t" << array_orcs[i]->GetIntelligence() << "\n";
        std::cout << "Charisma:\t\t" << array_orcs[i]->GetCharisma() << "\n\n";
        std::cout << "Hit points:\t\t[" << array_orcs[i]->its_health << "/" << array_orcs[i]->its_health << "]\n";
        std::cout << "Mana:\t\t\t[" << 20 << "/" << array_orcs[i]->its_mana << "]\n\n";
    }

    system("pause");
    system("CLS");
}
