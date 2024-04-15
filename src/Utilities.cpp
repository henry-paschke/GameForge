#include "Utilities.hpp"

void gf::print_versions()
{
    #ifdef GF_USING_CHIPMUNK2D
        std::cout << "Chipmunk version: " << CP_VERSION_MAJOR << "." << CP_VERSION_MINOR << "." << CP_VERSION_RELEASE << "\n";
    #endif

    #ifdef GF_USING_SFML
        std::cout << "SFML version: " << SFML_VERSION_MAJOR << "." << SFML_VERSION_MINOR << "." << SFML_VERSION_PATCH << "\n";
    #endif

    std::cout << "GameForge version: 1.0.0\n";

} 