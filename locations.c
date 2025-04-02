#include <stdio.h>
#include <string.h>
#include "locations.h"
#include "parsexec.h"

typedef struct {
    const int id;
	const char *description;
    const char *name;
    const int ids[10];
}Location;

typedef struct {
    const int id;
	const char *description;
    const char *name;
}Items;

static int locationOfPlayer = 0; // The player starts in the first location

Location locations[] = 
{
	{0, "\nA phone is on the table to your left. \nWarm light surrounds the room.\nThe door to the bathroom is held open by a laundry basket and the door to the hall is unlocked.", "room", {1}},
	{1, "\nYour bathroom is clean...ish.\nA toothbrush lies by the sink.", "bathroom", {0,2}},
	{1, "\nA hallway full of doors, a new person lives behind every single one.\nThe kitchen is near. Hunger beckons you.\n Only responsibility lies outside.", "hall", {0,2}},
	{2, "\nYour kitchen, your shelf of the fridge is empty, but your roommate's shelf has much food.", "kitchen", {1}},
	{2, "\nYou breath in the fresh air, you could go to class or just go on a walk. Life goes on.", "outside", {1}},
};

Items items[] = 
{
    {0, "Your phone lets you know its about time to go to class.", "phone"},
    {1, "You brush your teeth. It's not enjoyable, but at least others will percieve you better.", "toothbrush"},
    {2, "You find some food, guilt racks through you but your stomach lets you ignore it.", "food"},

};

static char itemsInInventory[200][40]; // Array to hold items in inventory

#define numLocations (sizeof(locations) / sizeof(locations[0]))
#define numItems (sizeof(items) / sizeof(items[0]))

void doLook(const char *noun)
{
    if (noun != NULL && strcmp(noun, "around") == 0)
    {
        printf("%s\n", locations[locationOfPlayer].description);
        return;
    }
    else
    {
        printf("You're not sure what you want to look at.\n");
        return;
    }
}

void doGo(const char *noun)
{
    printf("You try to go %s.\n", noun);
    for (int i = 0; i < numLocations; i++)
    {
        if (noun != NULL)
        {
            for  (int j; j < sizeof locations[i].ids; j++)
            {
                if (locations[i].ids[j] == locationOfPlayer)
                {
                    locationOfPlayer = locations[i].id;
                    printf("%s\n", locations[i].description);
                    return;
                }
            }
        }    
    }
    printf("You can't go somewhere that doesnt exist.\n");
}

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