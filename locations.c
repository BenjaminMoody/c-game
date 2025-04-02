#include <stdio.h>
#include <string.h>

typedef struct {
    const int id;
	const char *description;
    const char *name;
    const int ids[10];
}Location;

static int locationOfPlayer = 0; // The player starts in the first location

Location locations[] = 
{
	{0, "\nA phone is on the table to your left. \nWarm light surrounds the room.\nThe door to the bathroom is held open by a laundry basket and the door to the hall is unlocked.", "room", {1}},
	{1, "\nYour bathroom is clean...ish.\nA toothbrush lies by the sink.", "bathroom", {0,2}},
	{1, "\nA hallway full of doors, a new person lives behind every single one.\nThe kitchen is near. Hunger beckons you.\n Only responsibility lies outside.", "hall", {0,2}},
	{2, "\nYour kitchen, your shelf of the fridge is empty, but your roommate's shelf has much food.", "kitchen", {1}},
	{2, "\nYou breath in the fresh air, you could go to class or just go on a walk. Life goes on.", "outside", {1}},
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
    printf("You try to go %s.\n", noun);
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