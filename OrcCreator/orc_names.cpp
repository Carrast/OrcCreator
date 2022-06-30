#include "orc_names.h"

std::string GetRandomOrcName() {
	return random_orc_names_start[rand() % 10] + random_orc_names_end[rand() % 10];
}