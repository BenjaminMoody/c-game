#include <stdio.h>
#include <string.h>

struct locations 
{
    const char *description;
    const char *tag;
}

locations[] = {
    {"in your bed", "bed"},
    {"next to your dirty clothes basket", "basket"},
    {"by the window", "window"},
    {"just out the door", "door"}
};

#define numberOfLocations (sizeof locations / sizeof *locations)
static unsigned locationOfPlayer = 0;

void executeLook(const char *noun)
{
    if (noun != NULL && strcmp(noun, "around") == 0)
    {
        printf("you are %s.\n", locations[locationOfPlayer].description);
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