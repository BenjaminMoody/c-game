#include <stdio.h>
#include <string.h>
#include "object.h"
#include "misc.h"
#include "noun.h"

void executeLook(const char *noun)
{
    if (noun != NULL && strcmp(noun, "around") == 0)
    {
        printf("you are %s.\n", player->location->description);
        listObjectsAtLocation(player->location);
    }
    else
    {
        printf("you're eyes dont find anything of interest.\n")
    }
}

void executeGo(const char *noun)
{
    unsigned i;
    for (i = 0; i < numberOfLocations; i++)
    {
        if (noun != NULL && strcmp(noun, "around") == 0)
        {
            if (i == locationOfPlayer)
            {
                printf("You're here, what more can you do?");
            }
            else
            {
                printf("");
                locationOfPlayer = i;
                executeLook("around");
            }
        }
    }
    printf("You're talking funny, %c doesn't exist! silly.\n", noun);
}