#include <stdio.h>
#include <string.h>
#include <stdbool.h>
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

typedef struct {
    const int id;
    const char *speach[10];
    const char *name;
    const int where[10];
    const char hiddenSpeach[2][400];
}People;

static int locationOfPlayer = 0; // The player starts in the first location

Location locations[] = 
{
	{0, "\nA phone is on the table to your left. \nWarm light surrounds the room.\nThe door to the bathroom is held open by a laundry basket and the door to the hall is unlocked.", "room", {1,2,30}},
	{1, "\nYour bathroom is clean...ish.\nA toothbrush lies by the sink.", "bathroom", {0,2}},
	{2, "\nA hallway full of doors, a new person lives behind every single one.\nThe kitchen is near. Hunger beckons you.\nOnly responsibility lies outside.", "hall", {0,3,4}},
	{3, "\nYour kitchen, your shelf of the fridge is empty, but your roommate's shelf has much food.", "kitchen", {2}},
	{4, "\nYou breath in the fresh air, you could go to class or just go on a walk. Life goes on.", "outside", {2, 5}},
    {5, "\nYou head to the class of the time. You make it just in time.\nThe lecturer drones on about something you should be interested in.\nYou have a notebook infront of you, Eisso and Noel sit near you.", "class", {6}},
    {6},
    {7},
    {8},
    {9},
    {10},
    {11},
    {12},
    {13},
    {14},
    {15},
    {16},
    {17},
    {18},
    {19},
    {20},
    {21},
    {22},
    {23},
    {24},
    {25},
    {26},
    {27},
    {28},
    {29, "\nYou lie in bed, you could stay here forever", "bed",{30,0}},
    {30, "\nThoughts you'd rather not have swim in your mind, sleeping would be better", "bed",{31,32,0}},
    {31, "\nYou manage to sleep, your mind wanders from topic to topic............................", "sleep", },
    {32, "\nYou could stay here forever\n\nBut what's the point of that?", "bed", {33,32,0}},
    {33, "\nOh yeah, its kinda safe here, very easy to ignore everything.\n\nIsn't it.", "bed", {34,32,0}},
    {34, "\nSuuuuuper peaceful\nwarm\nheavy\ncomforting\nfamiliar", "bed", {32,0,35}},
    {35, "\nYou fall into a slumber, wasting away the day in favour of a feeling of safety.", "bed", }
};

Items items[] = 
{
    {0, "\nYour phone lets you know its about time to go to class. Its 8:45", "phone"},
    {0, "\nKeys, these let you into your building. If you can get someone to help you unlock the door you dont need keys.", "desk"},
    {0, "\nA laundry basket filled with dirty clothes. Need to wash them.", "laundry"},
    {1, "\nYou brush your teeth. It's not enjoyable, but at least others will percieve you better.", "toothbrush"},
    {3, "\nYou find some food, guilt racks through you but your stomach lets you ignore it.", "food"},
    {4, "\nOh NICE, you found a cool bug.\nIt's a queen ant, it still has it's wings so it hasnt found a mate or suitable place to start a nest...", "bug"},
    {5, "\nYou doodle in your notebook,\n..........................:++=++*+:..................................\n........................:+==--:::::=-................................\n........................+---::::::::-=...............................\n.......................:-:::::::::::-=:..............................\n.......................=::::::::::::-=-..............................\n.......................+-:::::::::::-=:..............................\n...............::--::.=--::::::::::--+...............................\n..........-++++======+++++-::::::---=:...............................\n.......-*=======-==========++----==+:................................\n.....=++==----------------:-=+*+++:..:--=---==-----:.................\n...:++==-----:::::::::::::::::==+-==-----=@%#*%+--::----.............\n..-+==------::::::::::::::::::::=++--:::+#-:::::::::-------..........\n.-===-----::::=--::::::::::::::::-+-::::::::::::::::::::*%%%*:.......\n:+==-----::::::::::-=-::::::::::::=+::::::::::::::::::::::-+%*=......\n====---::::::::::::::::=+:::::::---+::::::===-:::::::::::::-*+==-....\n+==----:::::::::::::::::::==::----=+-:::-:-::::-::::::::::::--===-...\n+==----::::::::::::::::::::::*:--==+:::-:..=-...-::::-=--===:--====..\n++=----::::::::::::::::::::::--+--+::::-.+:=##:.::::-::--.::=--===+-.\n===----::::+*-::::::::::::::::--+:::-=:::#@@@#=.::::-*:=%#...--==+++:\n:+==----::::::::==:::::::::::::-=--==-::-*%-+#:.-:::=*#@@#*..-====++-\n.====----::::::::::-+::::::::::-=-::::::::==-::-:::::#%-=#:.:-====++=\n..+===-----:::::::::::+-::-----=+-::-==:::::---::::::-=+=:..:===+++++\n...=+===-----:::::::::--*----=++----::=:::::-:::::::::--:===+**++++++\n.....++===-----::::::::--++++===------:%=:::::::::::::-=---===+++++++\n.......=+======--------==+++++===------*@=+-::::::::------=+**+=++++-\n..........=+++=+======++*+++++=====-----%@=:.:==-------==+*+++++++++:\n..............:-=+==--++++++========----+@@%:.:..::-:#%#+++++++++++=.\n......................:+=+============---*#%@@#=---=%%*=++++++++++=:.\n.......................:=====----------==+***%%%%%%%%%++++++++++++:..\n........................:==----::::-----==+%%%%%%%%%%*+++++++++++....\n..........................---:::::::::---===*%%%%%%%+++++++++++:.....\n...........................:-::::::::::--=====+++++++++++++++=.......\n..............................:::::::::--=====++++++++++++=:.........\n................................:--:::----===++++++++++=-............\n.....................................:--====++++++==::...............\n Eisso comments that your drawings are wierd.", "notebook"},

};

People people[] = 
{
    {0, {"\nYou- 'Hi'\nEisso- 'Damn bro, I thought you were gonna miss this one as well. Good job making it here'\nYou- 'Yeah, the bed misses me tho'",}, "Eisso", {5}, {"\nYou- 'Hi'\nEisso- 'Damn bro, I thought you were gonna miss this one as well. Good job making it here'\nYou- 'Yeah, I found this cool bug!'\nYou look for the bug but cant find it...\nYou- 'Oh well, I lost it'\nEisso- 'Good'", "bug"}},
    {1, {"\nYou- 'I made it'\n~~~ooo\nNoel- 'Yeah, you look like shit'\nYou- 'I didn't have time to brush my hair, I also barely slept'"}, "Noel", {5}, {"\nYou- 'I made it'\n~~~ooo\nNoel- 'Yeah, he's already started...'\nYou- 'I didn't have time to brush my hair, I also barely slept. But i brushed my teeth!'", "toothbrush"}},
};



#define numLocations (sizeof locations / sizeof locations[0] )
#define numItems (sizeof items  / sizeof items[0] )
#define numPeople (sizeof people / sizeof people[0])
static char itemsInInventory[numItems][40]; // Array to hold items in inventory

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
    for (int iter = 0; iter < numLocations; iter++)
    {
        if (strcmp(noun, locations[iter].name) == 0)
        break;
        if (iter == numLocations - 1)
        {
            printf("\nYou can't go somewhere that doesnt exist.\n");
            return;
        }
    }
    int ind;
    for (int i = 0; i < numLocations; i++)
    {
        if (strcmp(noun, locations[i].name) == 0)
        {
            ind = i;
            break;
        }
    }
    for (int j = 0; j < sizeof locations[locationOfPlayer].ids / sizeof locations[locationOfPlayer].ids[0]; j++)
    {
        if (noun != NULL && ind == locations[locationOfPlayer].ids[j])
        {
            locationOfPlayer = locations[ind].id;
            printf("%s\n", locations[ind].description);
            return;
        } 
    }
    printf("\nYou can't go somewhere that doesnt exist.\n");
}

void doGrab(const char *noun)
{
    int ind;
    for (int i = 0; i < numItems; i++)
    {
        if (strcmp(items[i].name, noun) == 0)
        {
            ind = i;
            break;
        }
    }
    if (noun != NULL && strcmp(noun, items[ind].name) == 0 && locationOfPlayer == items[ind].id)
    {
        printf("%s\n", items[ind].description);
        for (int i = 0; i < numItems; i++)
        {
            if (strcmp(itemsInInventory[i], items[ind].name) == 0) // Check if item is already in inventory
            {
                break; //item already in inventory
            }
            if (itemsInInventory[i][0] == '\0') // Find an empty slot
            {
                strcpy(itemsInInventory[i], items[ind].name); //add item to inventory
                printf("You put the %s in your bag.\n", items[ind].name);
                break;
            }
        }
        return;
    }
    else
    {
        printf("\nYou're not sure what you want to take.\n");
        return;
    } 
}

void doTalk(const char *noun)
{
    int i = 0;
    for (int i = 0; i < numLocations; i++)
    {
        if (noun != NULL && strcmp(people[i].name, noun) ==0)
        {
            int j = 0;
            for  (j; j < sizeof people[i].where / sizeof people[i].where[0]; j++)
            {
                if (people[i].where[j] == locationOfPlayer)
                {
                    for (int iter = 0; iter < sizeof itemsInInventory / sizeof itemsInInventory[0]; iter++)
                    {
                        if (strcmp(itemsInInventory[iter], people[i].hiddenSpeach[1]) == 0)
                        {
                            printf("%s\n", people[i].hiddenSpeach[0]);
                            return;
                        }
                    }
                    printf("%s\n", people[i].speach[j]);
                    return;
                }
            }
        }
    }
    printf("Hey are you ok? They're not here right now, it's okay.\n");
    return;
}