// FRCC_MurderMystery.cpp : This is our murdery mystery project in its most basic form.

//Extra Comment

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

//This function will print the beginning of the story to give the player context.
void beginning();

//This function will give the player a basic tutorial on the game's input system.
void enter_tutorial(vector<bool>& currentUserChoices);

//This function will print the end of the story, which may change based on the player's actions.
void ending(vector<bool>& currentUserChoices);

//These functions print requests for user input. The first requests a keyword to investigate, 
//and the second requests input for a room name.
void print_keyword_request(int roomNum);
void print_new_room_request(int roomNum);

//These functions are the meat of every room's code.
//describe_room prints a basic description, investigate_room allows the player to investigate objects in the room,
//and leave_room lets the player move from room to room.
void describe_room(int roomNum, vector<bool>& currentUserChoices);
string investigate_room(int roomNum, vector<bool>& currentUserChoices);
int leave_room(int roomNum);

//These functions print a pretty title for each room, the actual name of each room,
//and the names of adjacent rooms to the player's current location.
void print_room_title(int roomNum);
void print_room_name(int roomNum);
void print_adjacent_rooms(int roomNum);

//These functions both get user input: the first for investigating and leaving a room,
//and the second is used to pause the game until the player is ready to move forward.
//This will help them read the descriptions etc.
string get_keyword_input();
void type_and_continue();

//This is a function used for testing that prints user input.
void print_input(string input);

//These constants will be used as the indexs for the userChoices vector. The titles keep track of user choices and progress.
//If you meet Clyde in the tutorial, for example, userChoices.at(meetClyde) is set to true to keep track of that progress.
//It prevents you from having to repeat the tutorial every time you enter the trophy hall.
const int meetClyde = 0;




//Main Program
int main()
{
    int roomNum = 0;
    string userKeyword;

    //Declares boolean vector userChoices, which will keep track of the user's progress and decisions through game etc
    vector<bool> userChoices(20);
    //Sets boolean at every index to false
    for (size_t i = 0; i < userChoices.size(); i++) {
        userChoices.at(i) = false;
    }

    //Prints introduction to story
    beginning();

    //Loops Until roomNum is -1, which will only be the case once the player
    //Submits their final answer as to who the murderer is etc.
    //Then the end of the game is set in motion and the user exits the loop.
    while (roomNum != -1) {

        //Switch statement used to keep player in rooms 1 - 12 (a room 13 may be added later)
        //In every case, the code prints aroom description, 
        //allows player to investigate room until they want to leave, 
        //and then helps player move between rooms. 
        //The code is basically identical for each room.
        switch (roomNum) {

        case 0:
            //Empties console screen
            system("CLS");

            //Describes Room 0
            describe_room(roomNum, userChoices);

            //Enters tutorial for player if they're just starting the game
            if (userChoices.at(meetClyde) == false) {
                enter_tutorial(userChoices);
                describe_room(roomNum, userChoices);
            }

            //Investigates chosen keyword from room 0 description, prints info about keyword
            userKeyword = investigate_room(roomNum, userChoices);

            //Loops Until Player decides to leave room
            while (userKeyword.compare("leave") != 0) {
                //Empties console screen
                system("CLS");

                //Describes Room 0
                describe_room(roomNum, userChoices);
                userKeyword = investigate_room(roomNum, userChoices);
            }

            //Sets New Room Number to User's Input
            print_new_room_request(roomNum);
            roomNum = leave_room(roomNum);

            //Loops until player has chosen new room to enter
            while (roomNum == 0) {
                //Clears Screen
                system("CLS");
                cout << "Invalid Selection. Type one of the following room names exactly: \n" << endl;
                //Sets New Room Number to User's Input
                roomNum = leave_room(roomNum);
            }

            break;

        
        case 1:
            //Empties console screen
            system("CLS");

            //Describes Room 1
            describe_room(roomNum, userChoices);

            //Investigates chosen keyword from room 1 description, prints info about keyword
            userKeyword = investigate_room(roomNum, userChoices);

            //Loops Until Player decides to leave room
            while (userKeyword.compare("leave") != 0) {
                //Empties console screen
                system("CLS");

                //Describes Room 0
                describe_room(roomNum, userChoices);
                userKeyword = investigate_room(roomNum, userChoices);
            }

            //Sets New Room Number to User's Input
            print_new_room_request(roomNum);
            roomNum = leave_room(roomNum);

            //Loops until player has chosen new room to enter
            while (roomNum == 1) {
                //Clears Screen
                system("CLS");
                cout << "Invalid Selection. Type one of the following room names exactly: \n" << endl;
                //Sets New Room Number to User's Input
                roomNum = leave_room(roomNum);
            }

            break;


        case 2:
            //Empties console screen
            system("CLS");

            //Describes Room 2
            describe_room(roomNum, userChoices);

            //Investigates chosen keyword from room 2 description, prints info about keyword
            userKeyword = investigate_room(roomNum, userChoices);

            //Loops Until Player decides to leave room
            while (userKeyword.compare("leave") != 0) {
                //Empties console screen
                system("CLS");

                //Describes Room 0
                describe_room(roomNum, userChoices);
                userKeyword = investigate_room(roomNum, userChoices);
            }

            //Sets New Room Number to User's Input
            print_new_room_request(roomNum);
            roomNum = leave_room(roomNum);

            //Loops until player has chosen new room to enter
            while (roomNum == 2) {
                //Clears Screen
                system("CLS");
                cout << "Invalid Selection. Type one of the following room names exactly: \n" << endl;
                //Sets New Room Number to User's Input
                roomNum = leave_room(roomNum);
            }

            break;


        case 3:
            //Empties console screen
            system("CLS");

            //Describes Room 3
            describe_room(roomNum, userChoices);

            //Investigates chosen keyword from room 3 description, prints info about keyword
            userKeyword = investigate_room(roomNum, userChoices);

            //Loops Until Player decides to leave room
            while (userKeyword.compare("leave") != 0) {
                //Empties console screen
                system("CLS");

                //Describes Room 0
                describe_room(roomNum, userChoices);
                userKeyword = investigate_room(roomNum, userChoices);
            }

            //Sets New Room Number to User's Input
            print_new_room_request(roomNum);
            roomNum = leave_room(roomNum);

            //Loops until player has chosen new room to enter
            while (roomNum == 3) {
                //Clears Screen
                system("CLS");
                cout << "Invalid Selection. Type one of the following room names exactly: \n" << endl;
                //Sets New Room Number to User's Input
                roomNum = leave_room(roomNum);
            }

            break;

 
        case 4:
            //Empties console screen
            system("CLS");

            //Describes Room 4
            describe_room(roomNum, userChoices);

            //Investigates chosen keyword from room 4 description, prints info about keyword
            userKeyword = investigate_room(roomNum, userChoices);

            //Loops Until Player decides to leave room
            while (userKeyword.compare("leave") != 0) {
                //Empties console screen
                system("CLS");

                //Describes Room 0
                describe_room(roomNum, userChoices);
                userKeyword = investigate_room(roomNum, userChoices);
            }

            //Sets New Room Number to User's Input
            print_new_room_request(roomNum);
            roomNum = leave_room(roomNum);

            //Loops until player has chosen new room to enter
            while (roomNum == 4) {
                //Clears Screen
                system("CLS");
                cout << "Invalid Selection. Type one of the following room names exactly: \n" << endl;
                //Sets New Room Number to User's Input
                roomNum = leave_room(roomNum);
            }

            break;


        case 5:
            //Empties console screen
            system("CLS");

            //Describes Room 5
            describe_room(roomNum, userChoices);

            //Investigates chosen keyword from room 5 description, prints info about keyword
            userKeyword = investigate_room(roomNum, userChoices);

            //Loops Until Player decides to leave room
            while (userKeyword.compare("leave") != 0) {
                //Empties console screen
                system("CLS");

                //Describes Room 0
                describe_room(roomNum, userChoices);
                userKeyword = investigate_room(roomNum, userChoices);
            }

            //Sets New Room Number to User's Input
            print_new_room_request(roomNum);
            roomNum = leave_room(roomNum);

            //Loops until player has chosen new room to enter
            while (roomNum == 5) {
                //Clears Screen
                system("CLS");
                cout << "Invalid Selection. Type one of the following room names exactly: \n" << endl;
                //Sets New Room Number to User's Input
                roomNum = leave_room(roomNum);
            }

            break;


        case 6:
            //Empties console screen
            system("CLS");

            //Describes Room 6
            describe_room(roomNum, userChoices);

            //Investigates chosen keyword from room 6 description, prints info about keyword
            userKeyword = investigate_room(roomNum, userChoices);

            //Loops Until Player decides to leave room
            while (userKeyword.compare("leave") != 0) {
                //Empties console screen
                system("CLS");

                //Describes Room 0
                describe_room(roomNum, userChoices);
                userKeyword = investigate_room(roomNum, userChoices);
            }

            //Sets New Room Number to User's Input
            print_new_room_request(roomNum);
            roomNum = leave_room(roomNum);

            //Loops until player has chosen new room to enter
            while (roomNum == 6) {
                //Clears Screen
                system("CLS");
                cout << "Invalid Selection. Type one of the following room names exactly: \n" << endl;
                //Sets New Room Number to User's Input
                roomNum = leave_room(roomNum);
            }

            break;


        case 7:
            //Empties console screen
            system("CLS");

            //Describes Room 7
            describe_room(roomNum, userChoices);

            //Investigates chosen keyword from room 7 description, prints info about keyword
            userKeyword = investigate_room(roomNum, userChoices);

            //Loops Until Player decides to leave room

            while (userKeyword.compare("leave") != 0) {
                //Empties console screen
                system("CLS");

                //Describes Room 0
                describe_room(roomNum, userChoices);
                userKeyword = investigate_room(roomNum, userChoices);
            }

            //Sets New Room Number to User's Input
            print_new_room_request(roomNum);
            roomNum = leave_room(roomNum);

            //Loops until player has chosen new room to enter
            while (roomNum == 7) {
                //Clears Screen
                system("CLS");
                cout << "Invalid Selection. Type one of the following room names exactly: \n" << endl;
                //Sets New Room Number to User's Input
                roomNum = leave_room(roomNum);
            }

            break;


        case 8:
            //Empties console screen
            system("CLS");

            //Describes Room 8
            describe_room(roomNum, userChoices);

            //Investigates chosen keyword from room 8 description, prints info about keyword
            userKeyword = investigate_room(roomNum, userChoices);

            //Loops Until Player decides to leave room
            while (userKeyword.compare("leave") != 0) {
                //Empties console screen
                system("CLS");

                //Describes Room 0
                describe_room(roomNum, userChoices);
                userKeyword = investigate_room(roomNum, userChoices);
            }

            //Sets New Room Number to User's Input
            print_new_room_request(roomNum);
            roomNum = leave_room(roomNum);

            //Loops until player has chosen new room to enter
            while (roomNum == 8) {
                //Clears Screen
                system("CLS");
                cout << "Invalid Selection. Type one of the following room names exactly: \n" << endl;
                //Sets New Room Number to User's Input
                roomNum = leave_room(roomNum);
            }

            break;

 
        case 9:
            //Empties console screen
            system("CLS");

            //Describes Room 9
            describe_room(roomNum, userChoices);

            //Investigates chosen keyword from room 9 description, prints info about keyword
            userKeyword = investigate_room(roomNum, userChoices);

            //Loops Until Player decides to leave room
            while (userKeyword.compare("leave") != 0) {
                //Empties console screen
                system("CLS");

                //Describes Room 0
                describe_room(roomNum, userChoices);
                userKeyword = investigate_room(roomNum, userChoices);
            }

            //Sets New Room Number to User's Input
            print_new_room_request(roomNum);
            roomNum = leave_room(roomNum);

            //Loops until player has chosen new room to enter
            while (roomNum == 9) {
                //Clears Screen
                system("CLS");
                cout << "Invalid Selection. Type one of the following room names exactly: \n" << endl;
                //Sets New Room Number to User's Input
                roomNum = leave_room(roomNum);
            }

            break;


        case 10:
            //Empties console screen
            system("CLS");

            //Describes Room 10
            describe_room(roomNum, userChoices);

            //Investigates chosen keyword from room 10 description, prints info about keyword
            userKeyword = investigate_room(roomNum, userChoices);

            //Loops Until Player decides to leave room
            while (userKeyword.compare("leave") != 0) {
                //Empties console screen
                system("CLS");

                //Describes Room 0
                describe_room(roomNum, userChoices);
                userKeyword = investigate_room(roomNum, userChoices);
            }

            //Sets New Room Number to User's Input
            print_new_room_request(roomNum);
            roomNum = leave_room(roomNum);

            //Loops until player has chosen new room to enter
            while (roomNum == 10) {
                //Clears Screen
                system("CLS");
                cout << "Invalid Selection. Type one of the following room names exactly: \n" << endl;
                //Sets New Room Number to User's Input
                roomNum = leave_room(roomNum);
            }

            break;


        case 11:
            //Empties console screen
            system("CLS");

            //Describes Room 11
            describe_room(roomNum, userChoices);

            //Investigates chosen keyword from room 11 description, prints info about keyword
            userKeyword = investigate_room(roomNum, userChoices);

            //Loops Until Player decides to leave room
            while (userKeyword.compare("leave") != 0) {
                //Empties console screen
                system("CLS");

                //Describes Room 0
                describe_room(roomNum, userChoices);
                userKeyword = investigate_room(roomNum, userChoices);
            }

            //Sets New Room Number to User's Input
            print_new_room_request(roomNum);
            roomNum = leave_room(roomNum);

            //Loops until player has chosen new room to enter
            while (roomNum == 11) {
                //Clears Screen
                system("CLS");
                cout << "Invalid Selection. Type one of the following room names exactly: \n" << endl;
                //Sets New Room Number to User's Input
                roomNum = leave_room(roomNum);
            }

            break;


        case 12:
            //Empties console screen
            system("CLS");

            //Describes Room 12
            describe_room(roomNum, userChoices);

            //Investigates chosen keyword from room 12 description, prints info about keyword
            userKeyword = investigate_room(roomNum, userChoices);

            //Loops Until Player decides to leave room
            while (userKeyword.compare("leave") != 0) {
                //Empties console screen
                system("CLS");

                //Describes Room 0
                describe_room(roomNum, userChoices);
                userKeyword = investigate_room(roomNum, userChoices);
            }

            //Sets New Room Number to User's Input
            print_new_room_request(roomNum);
            roomNum = leave_room(roomNum);

            //Loops until player has chosen new room to enter
            while (roomNum == 12) {
                //Clears Screen
                system("CLS");
                cout << "Invalid Selection. Type one of the following room names exactly: \n" << endl;
                //Sets New Room Number to User's Input
                roomNum = leave_room(roomNum);
            }

            break;


        case 13:
            //Empties console screen
            system("CLS");

            //Describes Room 13
            describe_room(roomNum, userChoices);

            //Investigates chosen keyword from room 13 description, prints info about keyword
            userKeyword = investigate_room(roomNum, userChoices);

            //Loops Until Player decides to leave room
            while (userKeyword.compare("leave") != 0) {
                //Empties console screen
                system("CLS");

                //Describes Room 0
                describe_room(roomNum, userChoices);
                userKeyword = investigate_room(roomNum, userChoices);
            }

            //Sets New Room Number to User's Input
            print_new_room_request(roomNum);
            roomNum = leave_room(roomNum);

            //Loops until player has chosen new room to enter
            while (roomNum == 13) {
                //Clears Screen
                system("CLS");
                cout << "Invalid Selection. Type one of the following room names exactly: \n" << endl;
                //Sets New Room Number to User's Input
                roomNum = leave_room(roomNum);
            }

            break;


        default:
            cout << "FIXME: ROOMNUM IS " << roomNum << endl;
            cout << "UNPREDICTED VALUE." << endl;
            break;
        }
    }

    //Calls ending function to finish game.
    ending(userChoices);

    return 0;

}



//Prints lore / context for the player's benefit at beginning of game.
void beginning() {
    //Declares user input string
    string userInput;

    //FIXME: ADD INTRODUCTION, ATMOSPHERE BUILDING HERE
    cout << "FIXME: ADD BEGINNING TO STORY." << endl;
    cout << "Beginning of story, eventual intro." << endl;

    type_and_continue();
}



//Gives player brief tutorial of user input system.
void enter_tutorial(vector<bool>& currentUserChoices) {
    //Declares user input string
    string userKeyword;

    //FIXME: DETERMINE GAME NAME
    cout << "\nFIXME: DETERMINE GAME NAME" << endl;
    cout << "\nWelcome to INSERT GAME NAME!" << endl;

    cout << "\nThis is a text adventure meant to simulate a murder mystery!" << endl;
    cout << "You can interact with your environment by typing keywords when prompted." << endl;
    cout << "Keywords will always be in the room description unless you need to uncover other mysteries first." << endl;
    cout << "Try typing \"clyde\" to talk to your investigative partner." << endl;

    //Gets userInput and sets it to lowercase
    userKeyword = get_keyword_input();

    //Loops until user has typed "clyde"
    while (userKeyword.compare("clyde") != 0) {

        cout << "\nIncorrect input." << endl;
        cout << "Try typing \"clyde\" to talk to your investigative partner." << endl;

        //Gets userInput and sets it to lowercase
        userKeyword = get_keyword_input();

    }

    //FIXME: ADD VISIT WITH CLYDE
    cout << "\nFIXME: describe visit with clyde." << endl;
    currentUserChoices.at(meetClyde) = true;

    type_and_continue();

    //Empties console screen
    system("CLS");

}



//Prints ending on the story, which may differ based on userChoices
void ending(vector<bool>& currentUserChoices) {
    //Empties console screen
    system("CLS");

    //FIXME: RETURN USER'S DESIRED ROOMNUM
    cout << "FIXME: ADD ENDING TO STORY." << endl;
    cout << "This is the end." << endl;

}



//Asks user what they want to investigate
void print_keyword_request(int roomNum) {

    cout << "\nWhat do you want to investigate in the ";
    print_room_name(roomNum);
    cout << "?" << endl;

    cout << "(Type \"leave\" to move between rooms.)" << endl;
}



//Asks user which room they want to enter
void print_new_room_request(int roomNum) {

    cout << "\nWhich room do you want to enter from the ";
    print_room_name(roomNum);
    cout << "?" << endl;
}


//Describes current room, and may change description based on user choices
void describe_room(int roomNum, vector<bool>& currentUserChoices) {

    switch (roomNum) {

    case 0:
        //Prints basic room description if player has met clyde
        if (currentUserChoices.at(meetClyde) == true) {
            print_room_title(roomNum);
            cout << "In the Trophy Hall, Glass cupboards line the edges of the room with glimmering bronze and silver figures." << endl;
            cout << "Juniper shrubs cradle to the shelves of old photographs that appear well dusted." << endl;
            cout << "There's even a golden lion head attached to the wall, right above the double doors that lead into the mansion's core." << endl;

            cout << "\nClyde sits by the plastic table of evidence, prepared to answer any questions you might have." << endl;
        }
        //Prints different description if player hasn't met clyde
        else {
            print_room_title(roomNum);
            cout << "You enter the mansion and find yourself in an ornate Trophy Hall." << endl;
            cout << "Glass cupboards line the edges of the room with glimmering bronze and silver figures." << endl;
            cout << "Juniper shrubs cradle to the shelves of old photographs that appear well dusted." << endl;
            cout << "There's even a golden lion head attached to the wall, right above the double doors that lead into the mansion's core." << endl;

            cout << "\nSeveral junior recruits are sitting around a plastic table that clashes with the sophisticated decor." << endl;
            cout << "They've set it up for your convenience." << endl;
            cout << "Your closest confidant, Clyde Pendleton, seems eager to greet you." << endl;
            cout << "He probably has a case file prepared for you." << endl;
        }

        break;

    case 1:
        //Prints Description For Room 1
        print_room_title(roomNum);
        cout << "The Ballroom before you is gorgeous." << endl;
        cout << "Two shades of sparkling vinyl encompass the floor in a spiral pattern, almost like they're chasing one another." << endl;
        cout << "Marble columns outline the space's edges, stretching at least two stories to the ceiling." << endl;
        cout << "Several intricate chandeliers hang from the ceiling, too." << endl;
        cout << "They almost seem to be intertwined, their supports forming a star-like shape above the dance floor." << endl;

        cout << "\n(FIXME: CREATE NAME) BUTLER is standing by one of the columns, washing it down with some bleach." << endl;
        cout << "He looks at you. \"Hello, Detective. I can be at your service whenever you wish." << endl;

        break;

    case 2:
        //Prints Description For Room 2
        print_room_title(roomNum);
        cout << "As you open the door to the Office, you are met with a dim light." << endl;
        cout << "In the middle of the room, there's a single lamp sitting on a large desk with oak drawers." << endl;
        cout << "Velvet curtains line the walls, covering the tall windows." << endl;
        cout << "There is a small bookcase on your left that is only partially filled." << endl;
        cout << "As you approach the desk, you see a small letter sitting unopened." << endl;

        break;

    case 3:
        //Prints Description For Room 3
        print_room_title(roomNum);
        cout << "In the Servant's quarters, there are two twin beds sitting on opposite sides of the room." << endl;
        cout << "The quarters are relatively small, hardly longer than one of the beds." << endl;
        cout << "The only other furniture along the walls are two small desks set beside each bed." << endl;
        cout << "Their uncushioned chairs seem hardly used." << endl;
        cout << "Some small, wooden chests also sit at the foot of each servant's bed." << endl;
        cout << "An old-fashioned grandfather clock towers over the back wall between the two beds." << endl;
        cout << "Its pendulum slowly moves back and forth as the seconds tick by." << endl;

        cout << "\n(FIXME: CREATE NAME) SOUS CHEF sits on one of the twin beds elegantly." << endl;
        cout << "\"Hi there, Detective. I can answer some questions if you have any for me." << endl;

        break;

    case 4:
        //Prints Description For Room 4
        print_room_title(roomNum);
        cout << "In the library, the air is thick with dust." << endl;
        cout << "The space, though constricted, feels quite cozy." << endl;
        cout << "Tall wooden bookcases form several rows, and they're filled to the brim with books." << endl;
        cout << "At the room's far end, an antique fireplace lets off heat and light." << endl;
        cout << "It looks to be made of large granite chunks, likely from the quarry south of the estate." << endl;

        cout << "\n(FIXME: CREATE NAME) WIDOW is sitting in a nearby escritoire scribbling on some ephemeral paper." << endl;
        cout << "She taps her fountain pen on the page blankly. \"I don't suppose you're just going to stand there, are you?\"" << endl;

        break;

    case 5:
        //Prints Description For Room 5
        print_room_title(roomNum);
        cout << "You enter the Kitchen through a creaky door." << endl;
        cout << "An industrial stovetop oven, along with a stainless steel sink, are set across the back counter." << endl;
        cout << "Under the cupboards, there is a block of knives and a container of cooking utensils." << endl;
        cout << "Silverware is scattered around the kitchen. Dirty plates fill the sink." << endl;

        break;

    case 6:
        //Prints Description For Room 6
        print_room_title(roomNum);
        cout << "The dining room is very bright." << endl;
        cout << "An elegant diamond chandelier hangs high above the table, and its bulbs make the jewels perched on its top glisten." << endl;
        cout << "You shake your head. This was the last room everyone saw Mr. Stronghold in before his death." << endl;
        cout << "An ornate dining table takes up most of the room's space." << endl;
        cout << "It's surrounded by red velvet chairs that are just as pompous as everything else." << endl;

        break;

    case 7:
        //Prints Description For Room 7
        print_room_title(roomNum);
        cout << "A wave of heat blasts through you when you walk through the door to the Greenhouse." << endl;
        cout << "Shelves full of potted plants crowd the room messily." << endl;
        cout << "A fence of grape vines tracks the edge of the room." << endl;
        cout << "This room feels rather comfortable, especially thanks to the glimmering moonlight raining down from the skylight." << endl;
        cout << "In the corner, you find a shovel, a watering can, some other gardening tools, and a bag of fresh fertilizer." << endl;

        cout << "\n(FIXME: CREATE NAME) WINE CRAFTER is kneeling beside the grape vines, picking them." << endl;
        cout << "He drops a handful of grapes into a nearby bucket. \"Interrogate me, but be quick. Grapes aren't in season forever.\"" << endl;

        break;

    case 8:
        //Prints Description For Room 8
        print_room_title(roomNum);
        cout << "You approach the delapidated oak stairwell." << endl;
        cout << "A small, uninteresting bathroom sits beside them." << endl;
        cout << "There is a worn red carpet lain across the middle of them." << endl;
        cout << "Small lights line the walls, providing just enough light to avoid some holes in the cracked planks." << endl;

        break;

    case 9:
        //Prints Description For Room 9
        print_room_title(roomNum);
        cout << "If anything confirms the overindulgence of these people, it's the Wine Cellar." << endl;
        cout << "Several hundred bottles of white and red wine fill up slots on the walls, seeming to sparkle in the dim light." << endl;
        cout << "The room is lit by some ceiling fixtures, but not well enough to read the bottle labels." << endl;
        cout << "You're not sure what you could investigate down here without a flashlight." << endl;

        break;

    case 10:
        //Prints Description For Room 10
        print_room_title(roomNum);
        cout << "As you enter the Boiler Room, you hear the soft hum of the furnace." << endl;
        cout << "There is a singular lightbulb hanging from the ceiling in the center of the room." << endl;
        cout << "As light illuminates the room, you are able to makeout the shape of a man sitting at the back of the room." << endl;
        cout << "The breaker box sits in the corner, quietly." << endl;

        cout << "As you walk further into the room, you notice something move in the corner of your eye." << endl;
        cout << "Frightened, you turn on the light." << endl;
        cout << "\n(FIXME: CREATE NAME) MUD MAN stares directly at you. He's sitting in a pile of dark sticky mud." << endl;
        cout << "Besides the whites of his eyes, almost everything is covered in muck." << endl;
        cout << "\"What do you want? If you're not here for anything important, leave me to my mud.\"" << endl;

        break;

    case 11:
        //Prints Description For Room 11
        print_room_title(roomNum);
        cout << "The first thing you notice about the Observatory is the gigantic telescope at its center." << endl;
        cout << "With all of its sophisticated mechanical parts, you'd guess it would take weeks of practice to use. Months maybe." << endl;
        cout << "Beyond the telescope, there seem to be little exhibits about the solar system, the sun, and black holes on display." << endl;
        cout << "There's also a lab-like area full of scientific tools and half-finished experiments. Some steel cupboards hang above them." << endl;

        cout << "\n(FIXME: CREATE NAME) ASTROPHYSICIST/ARCHEOLOGIST emerges from behind the telescope and waves to you." << endl;
        cout << "\"It's a shame that there's a storm, Detective." << endl;
        cout << "\"I wish I could show you some of Dr. Stronghold's favorite stars.\"" << endl;
        cout << "She sighs. \"What can I do for you?\"" << endl;

        break;

    case 12:
        //Prints Description For Room 12
        print_room_title(roomNum);
        cout << "You enter the Master Bedroom through two heavy french doors." << endl;
        cout << "The smell of death is potent. This definitely seems to be where Mr. Stronghold was murdered." << endl;
        cout << "Mr. Stronghold's body lay sprawled across a lavish blood stained bed." << endl;
        cout << "To the left of the bed there's an old, wooden nightstand with many drawers." << endl;
        cout << "Across the room, two victorian era armoires sit tight against the wall." << endl;

        cout << "You check the Master Bathroom as well. The tub, large enough to be a small pool, is still full." << endl;
        cout << "Two glamorous vanities sit across from it. One of them is open." << endl;
        cout << "Of course. There's also a golden toilet." << endl;

        break;

    case 13:
        //FIXME: DESCRIBE ROOM 13
        print_room_title(roomNum);
        cout << "FIXME: DESCRIBE ROOM 13." << endl;

        break;
    default:
        cout << "Something went wrong with the code." << endl;
        cout << "roomNum is an unknown, unused number." << endl;
        break;
    }

}

//Allows player to investigate objects within a room.
string investigate_room(int roomNum, vector<bool>& currentUserChoices) {

    //Asks for user input and gets user input
    print_keyword_request(roomNum);
    string userKeyword = get_keyword_input();

    //FIXME: REMOVE INPUT PRINTER WHEN GAME IS FINISHED
    if (userKeyword.compare("leave") != 0) {
        print_input(userKeyword);
    }

    //Prints descriptions of object within current room if user keyword matches item name
    switch (roomNum) {
    case 0:
        break;

    case 1:
        break;

    case 2:
        break;

    case 3:
        break;

    case 4:
        break;

    case 5:
        break;

    case 6:
        break;

    case 7:
        break;

    case 8:
        break;

    case 9:
        break;

    case 10:
        break;

    case 11:
        break;

    case 12:
        break;

    case 13:
        break;

    default:
        break;
    }
    
    if (userKeyword.compare("leave") != 0) {
        type_and_continue();
    }

    return userKeyword;
}

//Prints adjacent rooms to user and then changes roomNum to newRoomNum based on the user's input
int leave_room(int roomNum) {

    int newRoomNum = roomNum;

    //Prints adjacent rooms for user's reference
    print_adjacent_rooms(roomNum);
    //Gets user's chosen room
    string userKeyword = get_keyword_input();

    //Sets New Room Num based on user input as long as the input is the name of an adjacent room
    switch (roomNum) {

    case 0:
        if (userKeyword.compare("ballroom") == 0) {
            newRoomNum = 1;
        }
        break;

    case 1:
        if ((userKeyword.compare("trophy hall") == 0)
            || (userKeyword.compare("trophy") == 0)
            || (userKeyword.compare("hall") == 0)) {
            newRoomNum = 0;
        }
        if (userKeyword.compare("office") == 0) {
            newRoomNum = 2;
        }
        if ((userKeyword.compare("servant's quarters") == 0)
            || (userKeyword.compare("servants quarters") == 0)
            || (userKeyword.compare("servant's") == 0)
            || (userKeyword.compare("servants") == 0)
            || (userKeyword.compare("quarters") == 0)) {
            newRoomNum = 3;
        }
        if (userKeyword.compare("library") == 0) {
            newRoomNum = 4;
        }
        if (userKeyword.compare("kitchen") == 0) {
            newRoomNum = 5;
        }
        if ((userKeyword.compare("dining room") == 0)
            || (userKeyword.compare("dining") == 0)
            || (userKeyword.compare("room") == 0)) {
            newRoomNum = 6;
        }
        if ((userKeyword.compare("greenhouse") == 0)
            || (userKeyword.compare("green") == 0)
            || (userKeyword.compare("house") == 0)) {
            newRoomNum = 7;
        }
        if ((userKeyword.compare("stairwell") == 0)
            || (userKeyword.compare("stairs") == 0)) {
            newRoomNum = 8;
        }
        break;

    case 2:
        if (userKeyword.compare("ballroom") == 0) {
            newRoomNum = 1;
        }
        if ((userKeyword.compare("servant's quarters") == 0)
            || (userKeyword.compare("servants quarters") == 0)
            || (userKeyword.compare("servant's") == 0)
            || (userKeyword.compare("servants") == 0)
            || (userKeyword.compare("quarters") == 0)) {
            newRoomNum = 3;
        }
        if (userKeyword.compare("library") == 0) {
            newRoomNum = 4;
        }
        break;

    case 3:
        if (userKeyword.compare("ballroom") == 0) {
            newRoomNum = 1;
        }
        if (userKeyword.compare("office") == 0) {
            newRoomNum = 2;
        }
        if (userKeyword.compare("library") == 0) {
            newRoomNum = 4;
        }
        break;

    case 4:
        if (userKeyword.compare("ballroom") == 0) {
            newRoomNum = 1;
        }
        if (userKeyword.compare("office") == 0) {
            newRoomNum = 2;
        }
        if ((userKeyword.compare("servant's quarters") == 0)
            || (userKeyword.compare("servants quarters") == 0)
            || (userKeyword.compare("servant's") == 0)
            || (userKeyword.compare("servants") == 0)
            || (userKeyword.compare("quarters") == 0)) {
            newRoomNum = 3;
        }
        break;

    case 5:
        if (userKeyword.compare("ballroom") == 0) {
            newRoomNum = 1;
        }
        if ((userKeyword.compare("dining room") == 0)
            || (userKeyword.compare("dining") == 0)
            || (userKeyword.compare("room") == 0)) {
            newRoomNum = 6;
        }
        if ((userKeyword.compare("greenhouse") == 0)
            || (userKeyword.compare("green") == 0)
            || (userKeyword.compare("house") == 0)) {
            newRoomNum = 7;
        }
        break;

    case 6:
        if (userKeyword.compare("ballroom") == 0) {
            newRoomNum = 1;
        }
        if (userKeyword.compare("kitchen") == 0) {
            newRoomNum = 5;
        }
        if ((userKeyword.compare("greenhouse") == 0)
            || (userKeyword.compare("green") == 0)
            || (userKeyword.compare("house") == 0)) {
            newRoomNum = 7;
        }
        break;

    case 7:
        if (userKeyword.compare("ballroom") == 0) {
            newRoomNum = 1;
        }
        if (userKeyword.compare("kitchen") == 0) {
            newRoomNum = 5;
        }
        if ((userKeyword.compare("dining room") == 0)
            || (userKeyword.compare("dining") == 0)
            || (userKeyword.compare("room") == 0)) {
            newRoomNum = 6;
        }
        break;

    case 8:
        if (userKeyword.compare("ballroom") == 0) {
            newRoomNum = 1;
        }
        if (userKeyword.compare("wine cellar") == 0
            || userKeyword.compare("wine") == 0
            || userKeyword.compare("cellar") == 0) {
            newRoomNum = 9;
        }
        if (userKeyword.compare("boiler room") == 0
            || userKeyword.compare("boiler") == 0
            || userKeyword.compare("room") == 0) {
            newRoomNum = 10;
        }
        if (userKeyword.compare("observatory") == 0) {
            newRoomNum = 11;
        }
        if (userKeyword.compare("master bedroom") == 0
            || userKeyword.compare("master") == 0
            || userKeyword.compare("bedroom") == 0) {
            newRoomNum = 12;
        }
        break;

    case 9:
        if ((userKeyword.compare("stairwell") == 0)
            || (userKeyword.compare("stairs") == 0)) {
            newRoomNum = 8;
        }
        if (userKeyword.compare("boiler room") == 0
            || userKeyword.compare("boiler") == 0
            || userKeyword.compare("room") == 0) {
            newRoomNum = 10;
        }
        break;

    case 10:
        if ((userKeyword.compare("stairwell") == 0)
            || (userKeyword.compare("stairs") == 0)) {
            newRoomNum = 8;
        }
        if (userKeyword.compare("wine cellar") == 0
            || userKeyword.compare("wine") == 0
            || userKeyword.compare("cellar") == 0) {
            newRoomNum = 9;
        }
        break;

    case 11:
        if ((userKeyword.compare("stairwell") == 0)
            || (userKeyword.compare("stairs") == 0)) {
            newRoomNum = 8;
        }
        if (userKeyword.compare("master bedroom") == 0
            || userKeyword.compare("master") == 0
            || userKeyword.compare("bedroom") == 0) {
            newRoomNum = 12;
        }
        break;

    case 12:
        if ((userKeyword.compare("stairwell") == 0)
            || (userKeyword.compare("stairs") == 0)) {
            newRoomNum = 8;
        }
        if (userKeyword.compare("observatory") == 0) {
            newRoomNum = 11;
        }
        break;

    case 13:
        cout << "roomNum = 13. FIXME, ROOM13 NOT ADDED" << endl;
        newRoomNum = 0;
        break;

    default:
        cout << "FIXME: ROOMNUM IS " << roomNum << endl;
        cout << "UNPREDICTED VALUE." << endl;
        newRoomNum = 0;
        break;
    }

    return newRoomNum;
}


//Prints a pretty title for each room when called
void print_room_title(int roomNum) {
    cout << "You are in the ";
    print_room_name(roomNum);
    cout << "." << endl;
    cout << "----------------------------------------" << endl;
}

//Prints name of room associated with current roomNum when called
void print_room_name(int roomNum) {

    switch (roomNum) {

    case 0:
        cout << "Trophy Hall";
        break;

    case 1:
        cout << "Ballroom";
        break;

    case 2:
        cout << "Office";
        break;

    case 3:
        cout << "Servant's Quarters";
        break;

    case 4:
        cout << "Library";
        break;

    case 5:
        cout << "Kitchen";
        break;

    case 6:
        cout << "Dining Room";
        break;

    case 7:
        cout << "Greenhouse";
        break;

    case 8:
        cout << "Stairwell";
        break;

    case 9:
        cout << "Wine Cellar";
        break;

    case 10:
        cout << "Boiler Room";
        break;

    case 11:
        cout << "Observatory";
        break;

    case 12:
        cout << "Master Bedroom";
        break;

    case 13:
        cout << "N/A";
        break;
    }

}

//Prints the room names of all adjacent rooms associated with roomNum
void print_adjacent_rooms(int roomNum) {

    cout << "\nAdjacent Rooms: " << endl;

    switch (roomNum) {

    case 0:
        cout << "\"";
        print_room_name(1);
        cout << "\"" << endl;
        break;

    case 1:
        cout << "\"";
        print_room_name(0);
        cout << "\"" << "\n" << "\"";
        print_room_name(2);
        cout << "\"" << "\n" << "\"";
        print_room_name(3);
        cout << "\"" << "\n" << "\"";
        print_room_name(4);
        cout << "\"" << "\n" << "\"";
        print_room_name(5);
        cout << "\"" << "\n" << "\"";
        print_room_name(6);
        cout << "\"" << "\n" << "\"";
        print_room_name(7);
        cout << "\"" << "\n" << "\"";
        print_room_name(8);
        cout << "\"" << endl;

        break;

    case 2:
        cout << "\"";
        print_room_name(1);
        cout << "\"" << "\n" << "\"";
        print_room_name(3);
        cout << "\"" << "\n" << "\"";
        print_room_name(4);
        cout << "\"" << endl;
        break;

    case 3:
        cout << "\"";
        print_room_name(1);
        cout << "\"" << "\n" << "\"";
        print_room_name(2);
        cout << "\"" << "\n" << "\"";
        print_room_name(4);
        cout << "\"" << endl;
        break;

    case 4:
        cout << "\"";
        print_room_name(1);
        cout << "\"" << "\n" << "\"";
        print_room_name(2);
        cout << "\"" << "\n" << "\"";
        print_room_name(3);
        cout << "\"" << endl;
        break;

    case 5:
        cout << "\"";
        print_room_name(1);
        cout << "\"" << "\n" << "\"";
        print_room_name(6);
        cout << "\"" << "\n" << "\"";
        print_room_name(7);
        cout << "\"" << endl;
        break;

    case 6:
        cout << "\"";
        print_room_name(1);
        cout << "\"" << "\n" << "\"";
        print_room_name(5);
        cout << "\"" << "\n" << "\"";
        print_room_name(7);
        cout << "\"" << endl;
        break;

    case 7:
        cout << "\"";
        print_room_name(1);
        cout << "\"" << "\n" << "\"";
        print_room_name(5);
        cout << "\"" << "\n" << "\"";
        print_room_name(6);
        cout << "\"" << endl;
        break;

    case 8:

        cout << "\nUPSTAIRS" << endl;
        cout << "----------------" << endl;

        cout << "\"";
        print_room_name(11);
        cout << "\"" << "\n" << "\"";
        print_room_name(12);
        cout << "\"" << endl;

        cout << "\nGROUND FLOOR" << endl;
        cout << "----------------" << endl;

        cout << "\"";
        print_room_name(1);
        cout << "\"" << endl;

        cout << "\nDOWNSTAIRS" << endl;
        cout << "--------------------" << endl;

        cout << "\"";
        print_room_name(9);
        cout << "\"" << "\n" << "\"";
        print_room_name(10);
        cout << "\"" << endl;

        break;

    case 9:
        cout << "\"";
        print_room_name(10);
        cout << "\"" << "\n" << "\"";
        print_room_name(8);
        cout << "\"" << endl;
        break;

    case 10:
        cout << "\"";
        print_room_name(9);
        cout << "\"" << "\n" << "\"";
        print_room_name(8);
        cout << "\"" << endl;
        break;

    case 11:
        cout << "\"";
        print_room_name(12);
        cout << "\"" << "\n" << "\"";
        print_room_name(8);
        cout << "\"" << endl;
        break;

    case 12:
        cout << "\"";
        print_room_name(11);
        cout << "\"" << "\n" << "\"";
        print_room_name(8);
        cout << "\"" << endl;
        break;

    case 13:
        //FIXME : COUT ADJACENT ROOMS
        cout << "FIXME: ROOM 13 DOES NOT EXIST YET, ADD ADJACENT ROOMS" << endl;
        break;

    }
}


//Gets keyword Input from user and sets keyword to lower case so it can be compared with
//room and object names easier.
string get_keyword_input() {

    string keywordInput;
    cin >> keywordInput;
    transform(keywordInput.begin(), keywordInput.end(), keywordInput.begin(), ::tolower);

    //ignores any input beyond the first string
    cin.ignore(1000, '\n');

    return keywordInput;
}

//Temporarily pauses game so player can read any descriptions and text. 
//Only requires that the user enter text to continue, regardless of what it is.
void type_and_continue() {

    string tempString;
    //Requests user input to continue
    cout << "\nType anything and press enter to continue..." << endl;
    cin >> tempString;

    //ignores any input beyond the first string
    cin.ignore(1000, '\n');
}


//Prints user input for testing
void print_input(string input) {
    cout << "\nFIXME: Remove userInput printer when game is finished." << endl;
    cout << "The user input is: " << input << endl;
}
