#include <stdio.h>
#include <string.h>
#include "object.h"
#include "misc.h"
#include "noun.h"

void executeLook(const char *noun)
{
    if (noun != NULL && strcmp(noun, "around") == 0)
    {
        printf("You are %s.\n", player->location->description);
        listObjectsAtLocation(player->location);
    }
    else
    {
        printf("Your eyes dont find anything of interest.\n");
    }
}

void executeGo(const char *noun)
{
    OBJECT *obj = getVisible("where you want to go", noun);
    if (obj == NULL)
    {
        //this is unneeded due to getVisible returning NULL if not found
    }
    else if (obj->location == NULL && obj != player->location)
    {
        printf("Alright!.\n");
        player->location = obj;
        executeLook("around");
    }
    else
    {
    printf("Where else could you be but here already?.\n");
    }
}