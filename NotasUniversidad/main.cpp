#include <iostream>
#include "facultad.h"
using namespace std;

int main()
{
    Facultad facultades;

    srand(getpid());
    facultades.llamaCiclo();
    return 0;
}
