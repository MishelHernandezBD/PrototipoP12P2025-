#include <iostream>
#include "facultad.h"
using namespace std;

int main()
{
    facultad facultades;

    srand(getpid());

    facultades.llamaCiclo();
    return 0;
}
