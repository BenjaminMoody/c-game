#include <stdio.h> //me libraries
#include <string.h>
#include <stdbool.h>
#include "locations.h"
#include "parsexec.h"

typedef struct { //a structure to contain the an array of locations made from multiple variables
    const int id;
	const char *description;
    const char *name;
    const int ids[10];
}Location; 

typedef struct { // another structure to contain the an array of items made from multiple variables
    const int id;
	const char *description;
    const char *name;
}Items;

typedef struct { //third and fnal structure to contain the an array of people made from multiple variables
    const int id;
    const char *speach[10];
    const char *name;
    const int where[10];
    const char hiddenSpeach[2][400];
}People;

static int locationOfPlayer = 0; // The player starts in the first location

Location locations[] = //the array of locations of structure Location
{  //id , description, name, connetction to other ids's (what other rooms this room leads to)
	{0, "\nA phone is on the table to your left. \nWarm light surrounds the room.\nThe door to the bathroom is held open by a laundry basket and the door to the hall is unlocked.", "room", {1,2,29}},
	{1, "\nYour bathroom is clean...ish.\nA toothbrush lies by the sink.", "bathroom", {0,6}},
	{2, "\nA hallway full of doors, a new person lives behind every single one.\nThe kitchen is near. Hunger beckons you.\nOnly responsibility lies outside.", "hall", {0,3,4}},
	{3, "\nYour kitchen, your shelf of the fridge is empty, but your roommate's shelf has much food.", "kitchen", {2}},
	{4, "\nYou breath in the fresh air, you could go to class or just go on a walk. Life goes on.", "outside", {2, 5, 10}},
    {5, "\nYou head to the class of the time. You make it just in time.\nThe lecturer drones on about something you should be interested in.\nYou have a notebook infront of you, Eisso and Noel sit near you.", "class", {7}},
    {6, "\n*plop*\n\n*wipe?*", "toilet", {0, 1}},
    {7, "\nYou arive on time here, mainly because you're following Noel and Eisso.\nOn the way Pottap and Dinoel join your group!\nBefore the class you go to the shop", "robotics", {8}},
    {8, "\nGoing into the shop there are many items like food, energy drinks and hot chocolate sachets.\n\nNoel- 'Lets be quick to get to the grid'", "shop", {9}},
    {9, "\n", "grid", {31}},
    {10, "\n", "walk", {31}},
    {11, "\n", "", {31}},
    {12, "\n", "", {31}},
    {13, "\n", "", {31}},
    {14, "\n", "", {31}},
    {15, "\n", "", {31}},
    {16, "\n", "", {31}},
    {17, "\n", "", {31}},
    {18, "\n", "", {31}},
    {19, "\n", "", {31}},
    {20, "\n", "", {31}},
    {21, "\n", "", {31}},
    {22, "\n", "", {31}},
    {23, "\n", "", {31}},
    {24, "\n", "", {31}},
    {25, "\n", "", {31}},
    {26, "\n", "", {31}},
    {27, "\n", "", {31}},
    {28, "\n", "", {31}},
    {29, "\nYou lie in bed, you could stay here forever\nThoughts you'd rather not have swim in your mind, sleeping would be better", "bed",{30,0}},
    {30, "\nYou manage to sleep, your mind wanders from topic to topic............................\nYou fall into a slumber, wasting away the day in favour of a feeling of safety.", "sleep", },
};

Items items[] = 
{  //what room id the item is in, description, name
    {0, "\nYour phone lets you know its about time to go to class. Its 8:45", "phone"},
    {0, "\nKeys, these let you into your building. If you can get someone to help you unlock the door you dont need keys.", "desk"},
    {0, "\nA laundry basket filled with dirty clothes. Need to wash them.", "laundry"},
    {1, "\nYou brush your teeth. It's not enjoyable, but at least others will percieve you better.", "toothbrush"},
    {3, "\nYou find some food, guilt racks through you but your stomach lets you ignore it.", "food"},
    {4, "\nOh NICE, you found a cool bug.\nIt's a queen ant, it still has it's wings so it hasnt found a mate or suitable place to start a nest...", "bug"},
    {5, "\nYou doodle in your notebook,\n..........................:++=++*+:..................................\n........................:+==--:::::=-................................\n........................+---::::::::-=...............................\n.......................:-:::::::::::-=:..............................\n.......................=::::::::::::-=-..............................\n.......................+-:::::::::::-=:..............................\n...............::--::.=--::::::::::--+...............................\n..........-++++======+++++-::::::---=:...............................\n.......-*=======-==========++----==+:................................\n.....=++==----------------:-=+*+++:..:--=---==-----:.................\n...:++==-----:::::::::::::::::==+-==-----=@%#*%+--::----.............\n..-+==------::::::::::::::::::::=++--:::+#-:::::::::-------..........\n.-===-----::::=--::::::::::::::::-+-::::::::::::::::::::*%%%*:.......\n:+==-----::::::::::-=-::::::::::::=+::::::::::::::::::::::-+%*=......\n====---::::::::::::::::=+:::::::---+::::::===-:::::::::::::-*+==-....\n+==----:::::::::::::::::::==::----=+-:::-:-::::-::::::::::::--===-...\n+==----::::::::::::::::::::::*:--==+:::-:..=-...-::::-=--===:--====..\n++=----::::::::::::::::::::::--+--+::::-.+:=##:.::::-::--.::=--===+-.\n===----::::+*-::::::::::::::::--+:::-=:::#@@@#=.::::-*:=%#...--==+++:\n:+==----::::::::==:::::::::::::-=--==-::-*%-+#:.-:::=*#@@#*..-====++-\n.====----::::::::::-+::::::::::-=-::::::::==-::-:::::#%-=#:.:-====++=\n..+===-----:::::::::::+-::-----=+-::-==:::::---::::::-=+=:..:===+++++\n...=+===-----:::::::::--*----=++----::=:::::-:::::::::--:===+**++++++\n.....++===-----::::::::--++++===------:%=:::::::::::::-=---===+++++++\n.......=+======--------==+++++===------*@=+-::::::::------=+**+=++++-\n..........=+++=+======++*+++++=====-----%@=:.:==-------==+*+++++++++:\n..............:-=+==--++++++========----+@@%:.:..::-:#%#+++++++++++=.\n......................:+=+============---*#%@@#=---=%%*=++++++++++=:.\n.......................:=====----------==+***%%%%%%%%%++++++++++++:..\n........................:==----::::-----==+%%%%%%%%%%*+++++++++++....\n..........................---:::::::::---===*%%%%%%%+++++++++++:.....\n...........................:-::::::::::--=====+++++++++++++++=.......\n..............................:::::::::--=====++++++++++++=:.........\n................................:--:::----===++++++++++=-............\n.....................................:--====++++++==::...............\n Eisso comments that your drawings are wierd.\nA previous note says you're next class is robotics", "notebook"},
};

People people[] = 
{  //person id, text, name, what room id accessible from, array with secret text and what item is needed to get it
    {0, {"\nYou- 'Hi'\nEisso- 'Damn bro, I thought you were gonna miss this one as well. Good job making it here'\nYou- 'Yeah, the bed misses me tho'",}, "Eisso", {5}, {"\nYou- 'Hi'\nEisso- 'Damn bro, I thought you were gonna miss this one as well. Good job making it here'\nYou- 'Yeah, I found this cool bug!'\nYou look for the bug but cant find it...\nYou- 'Oh well, I lost it'\nEisso- 'Good'", "bug"}},
    {1, {"\nYou- 'I made it'\n~~~ooo\nNoel- 'Yeah, you look like shit'\nYou- 'I didn't have time to brush my hair, I also barely slept'"}, "Noel", {5}, {"\nYou- 'I made it'\n~~~ooo\nNoel- 'Yeah, he's already started...'\nYou- 'I didn't have time to brush my hair, I also barely slept. But i brushed my teeth!'", "toothbrush"}},
    {2, {"\nNoel- 'C'mon, we need to be quick!'"}, "Noel", {8}, {"\nNoel- 'You already have food, we can go now, Right?'\n", "food"}},
    {3, {""},"",{4},{"",""}},
};

//defining lengths of all content arrays, define lets this happen during compile time
#define numLocations (sizeof locations / sizeof locations[0] )
#define numItems (sizeof items  / sizeof items[0] )
#define numPeople (sizeof people / sizeof people[0])

//this changes -> cant be defined at compile time
static char itemsInInventory[numItems][40]; // Array to hold items in inventory

//funtion to output the desription of current area
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

//function to move between areas
//this function checks if the noun is a location, if it is it checks if the player can go there and moves them there if they can
//if the location is not in the room or the player has already been there it does nothing
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
            for (int j = 0; j < sizeof locations[locationOfPlayer].ids / sizeof locations[locationOfPlayer].ids[0]; j++)
            {
                if (noun != NULL && ind == locations[locationOfPlayer].ids[j])
                {
                    locationOfPlayer = locations[ind].id;
                    printf("%s\n", locations[ind].description);
                    return;
                } 
            }
        }
    }
    printf("\nYou can't go somewhere that doesnt exist.\n");
}

//function to pick up items, this function checks if the noun is an item, if it is it checks if the player can pick it up and adds it to their inventory if they can
//if the item is already in the players inventory it does nothing
void doGrab(const char *noun)
{
    int ind;
    for (int i = 0; i < numItems; i++)
    {
        if (noun != NULL && strcmp(items[i].name, noun) == 0)
        {
            ind = i;
            if (strcmp(noun, items[ind].name) == 0 && locationOfPlayer == items[ind].id)
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
            }
       }
    }
    printf("\nYou reach for the air, you cant grab what lives in your mind...\n");
}

//function to talk to people, this function checks if the noun is a person, if it is it checks if the player can talk to them and outputs their speach if they can
//if the person is not in the room or the player has already spoken to them it does nothing
void doTalk(const char *noun)
{
    int ind;
    int i = 0;
    for (int i = 0; i < numPeople - 1; i++)
    {
        if (noun != NULL && strcmp(people[i].name, noun) == 0)
        {
            ind = i;
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
    printf("\nHey are you ok? They're not here right now, it's okay.\n");
    return;
}