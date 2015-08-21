#include <iostream>
#include "GameManager.h"

using namespace std;

int main()
{
    GameManager gm;

    gm.onStart();

    while (gm.update())
    {

    }

    gm.onEnd();
    return 0;
}
