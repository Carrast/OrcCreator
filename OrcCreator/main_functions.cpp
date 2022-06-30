#include "main_functions.h"

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

Orc* CreateOrc(const std::string& name, int strength, int dexterity, int endurance, int intelligence, int charisma) {
    Orc* orc = new Orc(name, strength, dexterity, endurance);
    orc->SetIntelligence(intelligence);
    orc->mana = 20 + intelligence;
    orc->SetCharisma(charisma);
    std::cout << name << " screams: ";
    orc->Roar(intelligence, charisma, orc->GetColor());
    return orc;
}

MutatedOrc* CreateMutatedOrc(const std::string& name, int strength, int dexterity, int endurance, int intelligence, int charisma) {
    MutatedOrc* orc = new MutatedOrc(name, strength, dexterity, endurance);
    orc->SetIntelligence(intelligence);
    orc->mana = 20 + intelligence;
    orc->SetCharisma(charisma);
    orc->SetColor("black");
    std::cout << name << " screams: ";
    orc->Roar(intelligence, charisma, orc->GetColor(), orc->its_rage);
    return orc;
}

void ListOrcs(int number_orcs, const std::vector<Orc*>& array_orcs) {

    // mutation string
    std::string is_mutated[2] = { "", "mutated " };

    std::cout << "Number of orcs: " << number_orcs << "\n";

    for (std::size_t i = 0; i < array_orcs.size(); i++)
    {
        std::cout << "Name:\t\t\t" << array_orcs[i]->its_name << "\n";
        std::cout << "Level " << array_orcs[i]->level << " " << is_mutated[array_orcs[i]->is_mutated] << "orc.\n\n";
        std::cout << "Experience:\t\t" << array_orcs[i]->experience << "\n";
        std::cout << "Number of kills:\t" << array_orcs[i]->num_kills << "\n\n";
        std::cout << "Strength:\t\t" << array_orcs[i]->strength << "\n";
        std::cout << "Dexterity:\t\t" << array_orcs[i]->dexterity << "\n";
        std::cout << "Endurance:\t\t" << array_orcs[i]->endurance << "\n";
        std::cout << "Intellect:\t\t" << array_orcs[i]->GetIntelligence() << "\n";
        std::cout << "Charisma:\t\t" << array_orcs[i]->GetCharisma() << "\n\n";
        std::cout << "Hit points:\t\t[" << array_orcs[i]->health << "/" << array_orcs[i]->health << "]\n";
        std::cout << "Mana:\t\t\t[" << array_orcs[i]->mana << "/" << array_orcs[i]->mana << "]\n\n";
    }

    system("pause");
    system("CLS");
}