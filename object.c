#include <stdio.h>
#include "object.h"

OBJECT objs[] = {
{"your room is small", "room", NULL},
{"next to your dirty clothes basket", "basket", NULL},
{"by the window", "window", NULL},
{"your messy desk has many items on it", "desk", NULL},
{"just out the door", "door", NULL},
{"your keychain, 3 small keys hang from it.\n Your home key, room key and letterbox key.", "key", room},
{"you dirty clothes. You put on the cleaner ones", "clothes", basket},
{"your backpack is kinda heavy, many useful items are in it", "bag", room},
{"you", "yourself", room},
{"your phone", "phone", room}
};