/*
 *CS157 Homework 2
 *
 *This program is the basis of a text-based adventure game
 *It simulates a modular mansion which a player can investigate.
 *
 *The program takes a single command-line argument: the name of a file containing the room information
 *usage: [program name] <room-file>
 *
 *By: Yaowei Zong (zongyw)
 *04/20/2015
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE_LINE 100 // Total maximum size of a data file line
#define MAX_SIZE_NAME 20  // max size of the name of a room
#define MAX_SIZE_DESC 60  // max size of the description of a room
#define MAX_NUM_ROOMS 25  // max number of rooms

int current = 0;    // global varible to keep track of the current room.
// struct Room.
struct Room {
    char north, south, east, west;
    char id;
    char description[MAX_SIZE_DESC];
    char name[MAX_SIZE_NAME];
};

// function prototypes
int buildRooms(char filename[], struct Room rooms[]);
void runGame(struct Room rooms[]);
void printRoom(struct Room *r);
void changeRoom(struct Room rooms[], char to);

int main(int argc, char *argv[])
{
    struct Room rooms[MAX_NUM_ROOMS];   // list of all the rooms
    if (argc != 2) {
        fprintf(stderr, "usage: %s <room-file>\n", argv[0]);
        return 1;
    }
    if (buildRooms(argv[1], rooms) != 0)    // test if buildRooms function succeed
        return 2;
    runGame(rooms);   // call function runGame
    return 0;
}

// --START-- Function Definition Zone

/*
 * Purpose: read lines from given file, and build the room list
 * Input:   name of the file, list of all the rooms
 * Output:  return an error if could not open file, store the room info in the array of rooms
 */
int buildRooms(char filename[], struct Room list[])
{
    FILE *f = fopen(filename, "r");     // open file for reading
    if (f == NULL) {
        fprintf(stderr, "Error opening game file %s.\n", filename);
        return 42;              // failure
    }
    char buf[MAX_SIZE_LINE];
    int i = 0;
    // store the room info in the array of rooms
    while (fgets(buf, sizeof(buf), f) != NULL)   {
        sscanf(buf, "%c %s %c %c %c %c %[^\n]", &list[i].id, list[i].name, &list[i].north, &list[i].south, &list[i].east, &list[i].west, list[i].description);
        i++;
    }
    return 0;                   // success
}
// End of function buildRooms

/*
 * Purpose: print the welcome message, loop while reading in the command from the user
 * Input:   the list of Rooms
 * Output:  no returns
 */
void runGame(struct Room rooms[])
{
    char input[20], cmd;
    printf("Welcome to the Reconfigurable Rooms!\n"
           "Type c for current room, n/e/w/s, or q.");
    // Start do while loop.
    do {
        printf( "\n> " );   // prompt the player with “> ”
        scanf("%s%*c", input);
        if (strlen(input) != 1) // test if input too long
        {
            fprintf(stderr, "Bad command \"%s\".", input);
            continue;
        }
        else cmd = input[0];    // get single letter cmd from input
        // switch on cmd
        switch (cmd) {
        default :
            fprintf(stderr, "Bad command \"%c\".", cmd);
            break;
        case 'c':
            printRoom(&rooms[current]);     // print current room info using printRoom
            break;
        case 'n':
            if ( (rooms[current].north) != '-' )    // check to see if there is a room there or print a “Sorry, can't.” message.
            {
                changeRoom(rooms, rooms[current].north);    // change to destination room using changeRoom
                printRoom(&rooms[current]);         // print current(new) room info using printRoom
            }
            else printf("Sorry, can't.");
            break;
        case 's':
            if ( (rooms[current].south) != '-' )
            {
                changeRoom(rooms, rooms[current].south);
                printRoom(&rooms[current]);
            }
            else printf("Sorry, can't.");
            break;
        case 'e':
            if ( (rooms[current].east) != '-' )
            {
                changeRoom(rooms, rooms[current].east);
                printRoom(&rooms[current]);
            }
            else printf("Sorry, can't.");
            break;
        case 'w':
            if ( (rooms[current].west) != '-' )
            {
                changeRoom(rooms, rooms[current].west);
                printRoom(&rooms[current]);
            }
            else printf("Sorry, can't.");
            break;
        case 'q':       // quit loop on 'q'
            break;
        }
    } while (cmd != 'q');
    // End do while loop.
}
// End of function runGame

/*
 * Purpose: print details of the room: name, description, possible exit doors
 * Input:   pointer to a Room struct
 * Output:  no returns
 */
void printRoom(struct Room *r)
{
    int out = 0;    // track of possible exit
    printf( "Location: %s: %s\n",  r->name, r->description);
    printf( "Directions:");
    if ( (r->north) != '-' ) // check if has a exit
    {
        printf( " north");
        out = 1;
    }
    if ( (r->south) != '-' )
    {
        printf( " south");
        out = 1;
    }
    if ( (r->east) != '-' )
    {
        printf( " east");
        out = 1;
    }
    if ( (r->west ) != '-' )
    {
        printf( " west");
        out = 1;
    }
    if ( out != 1 ) // no exit condition
        printf( " none");
}
// End of function printRoom

/*
 * Purpose: change current location to destination room
 * Input:   pointer to a Room struct, destination room id
 * Output:  no returns
 */
void changeRoom(struct Room rooms[], char to)
{
    int stop = 0, i = 0;
    while ( stop != 1 )
    {
        if ( rooms[i].id == to )
        {
            current = i;
            stop = 1;
            break;
        }
        i++;
    }
}
// End of function changeRoom

// --END-- Function Definition Zone