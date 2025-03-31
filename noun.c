#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "object.h"

static bool objectHasTag(OBJECT *object, const char *tag)
{
    return noun != NULL && *noun != '\\0' && strcmp(noun, obj->tag) == 0;
}

static OBJECT *getObject(const char *noun)
{
    OBJECT *obj, *res = NULL;
    for (obj = objs; obj < endOfObjs; obj++)
    {
        if (objectHasTag(obj, noun))
        {
            res = obj;
        }
    }
    return res;
}

OBJECT *getVisable(const char *intention, const char *noun)
{
    OBJECT *obj = getObject(noun);
    if (obj == NULL)
    {
        printf("The word %s means nothing", intention);
    }
    else if (!(obj == player ||
obj == player->location||
obj->location == player ||
obj->location == player->location ||
obj->location == NULL ||
obj->location->location == player ||
obj->location->location == player->location))
    {
        printf("No %s found", noun);
        obj == NULL;
    }

    return obj;
}