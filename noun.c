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