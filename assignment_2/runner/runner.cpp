
#include <string>

#include "externallibrary.h"

// Expected calls:
// ./runner 1
// ./runner 1000000
int main(int argc, char * argv[])
{
    
    bool dryRun = atoi(argv[1]) < 1000000;

    initialize(dryRun);

    while (running())
    {
        processEvents();
    }
    
    // TODO: make it reach here!

    return 0;
}
