#include <stdio.h>
#include <string.h>

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
	{0, "A phone is on the table to your left. \nWarm light surrounds the room.\n The door to the bathroom is held open by a laundry basket and the door to the hall is unlocked.", "room", {1}},
	{1, "Your bathroom is clean...ish.\n A toothbrush lies by the sink.", "bathroom", {0,2}},
	{1, "A hallway full of doors, a new person lives behind every single one.\n The kitchen is near. Hunger beckons you.\n Only responsibility lies outside.", "hall", {0,2}},
	{2, "Your kitchen, your shelf of the fridge is empty, but your roommate's shelf has much food.", "kitchen", {1}},
	{2, "You breath in the fresh air, you could go to class or just go on a walk. Life goes on.", "outside", {1}},
};

Items items[] = 
{
    {0, "Your phone lets you know its about time to go to class.", "phone"},
    {1, "You brush your teeth. It's not enjoyable, but at least others will percieve you better.", "toothbrush"},
    {2, "You find some food, guilt racks through you but your stomach lets you ignore it.", "food"},

};

#define numLocations (sizeof(locations) / sizeof(locations[0]))

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
    for (int i = 0; i < numLocations; i++)
    {
        if (noun != NULL && strcmp(noun, locations[locationOfPlayer].name) == 0)
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
}

void doGrab(const char *noun)
{
    if (noun != NULL && strcmp(noun, items[locationOfPlayer].name == 0) && locationOfPlayer == items[locationOfPlayer].id)
    {
        printf("%s\n", items[locationOfPlayer].description);
        return;
    }
    else
    {
        printf("You're not sure what you want to take.\n");
        return;
    } 
}