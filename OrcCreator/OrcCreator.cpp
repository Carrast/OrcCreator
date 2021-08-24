// OrcCreator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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
void CreateOrc(std::string name, int strength, int endurance, int intelligence, int charisma);
void ListOrcs(int number_orcs);

int main()
{
    std::string random_name1 = "Uglukk";
    std::string random_name2 = "Abzlug";

    int number_orcs = 0;
    std::string orc_name;
    int orc_strength;
    int orc_dexterity;
    int orc_endurance;
    int orc_intelligence;
    int orc_charisma;
    
    std::string user_choice;
    char real_choice;

    int damage = 0;
    srand(time(0));

    std::vector<Orc> array_orcs;

    do
    {
        WelcomeText();
        ShowOptions();
        std::cout << "User choice:\t\t";
        std::cin >> user_choice;
        real_choice = user_choice[0];
        std::cout << "\n";

        if (real_choice == 'a') // Create orc
        {
            std::cout << "Give name of the orc: ";
            std::cin >> orc_name;
            std::cout << "\nValues must be between [5-20]!";
            std::cout << "\nStrength:\t\t";
            std::cin >> orc_strength;
            orc_strength = std::min(std::max(5, orc_strength), 20);
            std::cout << "Dexterity:\t\t";
            std::cin >> orc_dexterity;
            orc_dexterity= std::min(std::max(5, orc_dexterity), 20);
            std::cout << "Endurance\t\t";
            std::cin >> orc_endurance;
            orc_endurance = std::min(std::max(5, orc_endurance), 20);
            std::cout << "Intelligence\t\t";
            std::cin >> orc_intelligence;
            orc_intelligence = std::min(std::max(5, orc_intelligence), 20);
            std::cout << "Charisma\t\t";
            std::cin >> orc_charisma;
            orc_charisma = std::min(std::max(5, orc_charisma), 20);

            std::cout << "\n\nOrc with the name " << orc_name << " is born!\n";

            Orc orc_name(orc_name, orc_strength, orc_dexterity, orc_endurance);
            orc_name.SetIntelligence(orc_intelligence);
            orc_name.SetCharisma(orc_charisma);
            number_orcs++;
            array_orcs.push_back(orc_name);
            orc_name.Roar(orc_intelligence, orc_charisma);

            system("pause");
            system("CLS");
            continue;

        } if (real_choice == 'b')   // Create 2 random orcs
        {
            // 1
            Orc random_name1(random_name1, (rand()%15 + 6), (rand()%15 + 6), (rand()%15 + 6));
            random_name1.SetIntelligence(rand()%15 + 6);
            random_name1.SetCharisma(rand() % 15 + 6);
            number_orcs++;
            array_orcs.push_back(random_name1);

            // 2
            Orc random_name2(random_name2, (rand() % 15 + 6), (rand() % 15 + 6), (rand() % 15 + 6));
            random_name2.SetIntelligence(rand() % 15 + 6);
            random_name2.SetCharisma(rand() % 15 + 6);
            number_orcs++;
            array_orcs.push_back(random_name2);

            std::cout << "Two random orcs have been created!\n\n";

            system("pause");
            system("CLS");
            continue;

        } if (real_choice == 'c')   // List orcs
        {
            std::cout << "Number of orcs: " << number_orcs << ".\n";

            for (int i = 0; i < array_orcs.size(); i++)
            {
                std::cout << "Name:\t\t\t" << array_orcs[i].its_name << "\n";
                std::cout << "Strength:\t\t" << array_orcs[i].its_strength << "\n";
                std::cout << "Dexterity:\t\t" << array_orcs[i].its_dexterity << "\n";
                std::cout << "Endurance:\t\t" << array_orcs[i].its_endurance << "\n";
                std::cout << "Intellect:\t\t" << array_orcs[i].GetIntelligence() << "\n";
                std::cout << "Charisma:\t\t" << array_orcs[i].GetCharisma() << "\n";
                std::cout << "Hit points:\t\t[" << array_orcs[i].its_health << "/" << array_orcs[i].its_health << "]\n\n";
            }

            system("pause");
            system("CLS");
            continue;

        } if (real_choice == 'd')   // let them fight!
        {
            if (number_orcs < 2)
            {
                std::cout << "There are too few orcs, please create another!\n\n";
                system("pause");
                system("CLS");
                continue;
            }
            else
            {
                std::cout << "\tLET THE FIGHT BEGIN!\n\n";
                std::cout << array_orcs[0].its_name << " VS " << array_orcs[1].its_name << "\n\n";

                do
                {
                    // 1
                    std::cout << array_orcs[0].its_name << " is attacking. " << array_orcs[0].its_name << " is swinging his sword, doing ";
                    damage = rand()%6 + 1 + (std::max(10, array_orcs[0].its_strength) - 10);
                    std::cout << damage << " damage!\n";
                    array_orcs[1].its_health -= damage;
                    std::cout << array_orcs[1].its_name << "'s health is " << array_orcs[1].its_health << ".\n";

                    if (array_orcs[1].its_health < 1) {
                        std::cout << array_orcs[0].its_name << " has slain " << array_orcs[1].its_name  << "!\n";
                        break;
                    }

                    // 2
                    std::cout << array_orcs[1].its_name << " is attacking. " << array_orcs[1].its_name << " is swinging his sword, doing ";
                    damage = rand() % 6 + 1 + (std::max(10, array_orcs[1].its_strength) - 10);
                    std::cout << damage << " damage.\n";
                    array_orcs[0].its_health -= damage;
                    std::cout << array_orcs[0].its_name << "'s health is " << array_orcs[0].its_health << ".\n";
                    if (array_orcs[0].its_health < 1) {
                        std::cout << array_orcs[1].its_name << " has slain " << array_orcs[0].its_name << "!\n";
                        
                        break;
                    }
                } while (array_orcs[0].its_health > 0 && array_orcs[1].its_health > 0);

                system("pause");
                system("CLS");
                continue;
            }
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
    std::cout << "Exit\t\t\t - x\n";
}

void CreateOrc(std::string name, int strength, int endurance, int intelligence, int charisma) {

}

void ListOrcs(int number_orcs) {

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
