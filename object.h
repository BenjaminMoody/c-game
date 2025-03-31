typedef struct object {
    const char    *description;
    const char    *tag;
    struct object *location;
 } OBJECT;

 extern OBJECT objs[];

 #define room (objs + 0)
 #define basket (objs + 1)
 #define window (objs + 2)
#define desk (objs + 3)
#define door (objs + 4)
#define key (objs + 5)
#define clothes (objs + 6)
#define bag (objs + 7)
#define player (objs + 8)
#define phone (objs + 9)

 #define endOfObjs (objs + 10)