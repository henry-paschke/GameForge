#include <iostream>

#ifdef GF_USING_CHIPMUNK2D 
    #include <chipmunk/chipmunk.h>
#endif
#ifdef GF_USING_SFML
    #include <SFML/System.hpp>
#endif

namespace gf
{
    void print_versions();

} // namespace gf
