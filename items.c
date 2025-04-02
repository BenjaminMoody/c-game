#include <stdio.h>
#include <string.h>
#include "locations.h"
#include "locations.c"

typedef struct {
    const int id;
	const char *description;
    const char *name;
}Items;

#define numItems (sizeof(items) / sizeof(items[0]))

Items items[] = 
{
    {0, "Your phone lets you know its about time to go to class.", "phone"},
    {1, "You brush your teeth. It's not enjoyable, but at least others will percieve you better.", "toothbrush"},
    {2, "You find some food, guilt racks through you but your stomach lets you ignore it.", "food"},

};

static char itemsInInventory[200][20]; // Array to hold items in inventory

void doGrab(const char *noun)
{
    if (noun != NULL && strcmp(noun, items[locationOfPlayer].name) == 0 && locationOfPlayer == items[locationOfPlayer].id)
    {
        printf("%s\n", items[locationOfPlayer].description);
        for (int i = 0; i < numItems; i++)
        {
            if (strcmp(itemsInInventory[i], items[locationOfPlayer].name) == 0) // Check if item is already in inventory
            {
                break; //item already in inventory
            }
            if (itemsInInventory[i][0] == '\0') // Find an empty slot
            {
                strcpy(itemsInInventory[i], items[locationOfPlayer].name); //add item to inventory
                printf("You put the %s in your bag.\n", items[locationOfPlayer].name);
                break;
            }
        }
        return;
    }
    else
    {
        printf("You're not sure what you want to take.\n");
        return;
    } 
}