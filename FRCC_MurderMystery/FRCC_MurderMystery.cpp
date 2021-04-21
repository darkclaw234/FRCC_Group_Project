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

//This function prints character names.
void print_character_name(int roomNum);

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
const int findFlashlight = 1;
const int findUVLight = 2;




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
            cout << "In the Trophy Hall, glass cupboards line the edges of the room with glimmering bronze and silver figures." << endl;
            cout << "Dracaena plants cradle some shelves filled with well dusted black and white photos." << endl;
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
        cout << "As you approach the desk, you see a small envelope sitting opened." << endl;

        break;

    case 3:
        //Prints Description For Room 3
        print_room_title(roomNum);
        cout << "In the Servant's Quarters, there are two twin beds sitting on opposite sides of the room." << endl;
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
        cout << "In the Library, the air is thick with dust." << endl;
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
        cout << "Under the cupboards, there is a block of knives and a basket of silverware." << endl;
        cout << "Silverware is scattered around the kitchen. Dirty plates fill the sink." << endl;

        break;

    case 6:
        //Prints Description For Room 6
        print_room_title(roomNum);
        cout << "The Dining Room is very bright." << endl;
        cout << "An elegant diamond chandelier hangs high above the table, and its bulbs make the jewels perched on its top glisten." << endl;
        cout << "You shake your head. This was the last room everyone saw Mr. Stronghold in before his death." << endl;
        cout << "An ornate dining table takes up most of the room's space." << endl;
        cout << "It's surrounded by red velvet chairs that are just as pompous as everything else." << endl << endl;

        cout << "Investigatable Items: Red velvet chairs." << endl;

        break;

    case 7:
        //Prints Description For Room 7
        print_room_title(roomNum);
        cout << "A wave of heat blasts through you when you walk through the door to the Greenhouse." << endl;
        cout << "Shelves full of potted plants crowd the room messily." << endl;
        cout << "Beautiful flowers fill the plants." << endl;
        cout << "This room feels rather comfortable, especially thanks to the glimmering moonlight raining down from the skylight." << endl;
        cout << "In the corner, you find a shovel, a watering can, some other gardening tools, and a bag of fresh fertilizer." << endl;

        cout << "\n(FIXME: CREATE NAME) WINE CRAFTER is kneeling beside the grape vines, picking them." << endl;
        cout << "He drops a handful of grapes into a nearby bucket. \"Interrogate me, but be quick. Grapes aren't in season forever.\"" << endl;

        break;

    case 8:
        //Prints Description For Room 8
        print_room_title(roomNum);
        cout << "You approach the delapidated oak Stairwell." << endl;
        cout << "A small, uninteresting bathroom sits beside them." << endl;
        cout << "There is a worn red carpet lain across the middle of them." << endl;
        cout << "Small lights line the walls, providing just enough light to avoid some holes in the cracked planks." << endl;
        cout << "A button is sitting on in the corner of the fourth stair up.";

        break;

    case 9:
        //Prints Description For Room 9
        print_room_title(roomNum);
        cout << "If anything most confirms these people's overindulgence, it's their Wine Cellar." << endl;
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
        cout << "\"What do you want? If you're not here for anything important, leave me to my mud.\"" << endl << endl;
        
        cout << "Investigatable Items: Breaker box." << endl;

        break;

    case 11:
        //Prints Description For Room 11
        print_room_title(roomNum);
        cout << "The first thing you notice about the Observatory is the gigantic telescope at its center." << endl;
        cout << "With all of its sophisticated mechanical parts, you'd guess it would take weeks of practice to use. Months maybe." << endl;
        cout << "Beyond the telescope, there seem to be little statues representing the solar system, the sun, and a black hole on display." << endl;
        cout << "There's also a lab-like area full of scientific tools and half-finished experiments." << endl;

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
        cout << "Of course. There's also a golden toilet." << endl << endl;

        cout << "Investigatable Items: Mr. Stronghold's body, Victorian era armoires, Bathroom vanity." << endl;

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
        if ((userKeyword.compare("glass") == 0)
            || (userKeyword.compare("cupboards") == 0)
            || (userKeyword.compare("bronze") == 0)
            || (userKeyword.compare("silver") == 0)
            || (userKeyword.compare("figures") == 0)) {
            cout << "\nBronze And Silver Trophies: " << endl;
            cout << "Mr. Stronghold has an arrangement of trophies proudly presented in the glass cupboards." << endl;
            cout << "It seems he's achieved quite a lot in the scientific world." << endl;
            cout << "He received several awards for renovating the world of astronomy with his telescope designs." << endl;
            cout << "He's also a prime benefactor of a nearby coal mining town." << endl;
        }
        if ((userKeyword.compare("dracaena") == 0)
            || (userKeyword.compare("plants") == 0)) {
            cout << "\nDracaena Plants:" << endl;
            cout << "These plants are low effort shrubs with beautiful green leaves." << endl;
            cout << "Unsurprisingly, the ones in this room are in great condition." << endl;
            cout << "You would expect no less from a couple with a butler." << endl;
        }
        if ((userKeyword.compare("well") == 0)
            || (userKeyword.compare("dusted") == 0)
            || (userKeyword.compare("black") == 0)
            || (userKeyword.compare("white") == 0)
            || (userKeyword.compare("photos") == 0)) {
            cout << "\nWell Dusted Black And White Photos:" << endl;
            cout << "Dr. Stronghold was clearly a fan of photos." << endl;
            cout << "He has quite a few of each suspect." << endl;
            cout << "In one, the Butler carries an overflowing tray of drinks with a smile." << endl;
            cout << "There's another with Dr. Stronghold's prized sous chef displaying a stuffed fish." << endl;
            cout << "In another, his prized lab partner is holding their shared award for telescope achievement." << endl;
            cout << "You drift to the final set of photos." << endl;
            cout << "Mrs. Stronghold looks truly elegant in all of them. Even as her hair grays, her beauty never fades." << endl;
        }
        if ((userKeyword.compare("golden") == 0)
            || (userKeyword.compare("lion") == 0)
            || (userKeyword.compare("head") == 0)) {
            cout << "\nGolden Lion Head:" << endl;
            cout << "It's well polished... and quite gratutious." << endl;
            cout << "It doesn't seem particularly relevant to the case, however." << endl;
        }
        break;

    case 1:
        if ((userKeyword.compare("sparkling") == 0)
            || (userKeyword.compare("vinyl") == 0)
            || (userKeyword.compare("floor") == 0)) {
            cout << "\nVinyl Floors:" << endl;
            cout << "The Butler has clearly been wiping the floors down." << endl;
            cout << "You wonder if there's any reason for that..." << endl;
            cout << "Maybe he's just desperate to get his mind off of things." << endl;
        }
        if ((userKeyword.compare("marble") == 0)
            || (userKeyword.compare("columns") == 0)) {
            cout << "\nMarble Columns:" << endl;
            cout << "If these are important to the case, you're not seeing why." << endl;
            cout << "They're just gorgeous pillars. They don't have much use beyond their appeal to the eye." << endl;
        }
        if ((userKeyword.compare("intricate") == 0)
            || (userKeyword.compare("chandeliers") == 0)) {
            cout << "\nIntricate Chandeliers:" << endl;
            cout << "An old friend told you about a case of theirs where a chandelier fell onto the victim's head." << endl;
            cout << "Luckily these chandeliers seem rather attached to the ceiling." << endl;
        }
        break;

    case 2:
        if (userKeyword.compare("lamp") == 0) 
            || (userKeyword.compare("small lamp") == 0)
        {
        cout << "Lamp" << endl;
        cout << "----------------------------------------" << endl;
        cout << "A small lamp on the corner of the desk." << endl;
        cout << "It is emitting a faint light." << endl;
        }

        if (userKeyword.compare("desk") == 0)
            || (userKeyword.compare("oak desk") == 0)
        {
            cout << "Desk" << endl;
            cout << "----------------------------------------" << endl;
            cout << "A large desk taking up most of the room." << endl;
            cout << "It has a small lamp on its corner and a note in the center." << endl;
        }
        break;

        if (userKeyword.compare("envelope") == 0)
        {
            cout << "Envelope" << endl;
            cout << "----------------------------------------" << endl;
            cout << "An opened letter sitting in the middle of the desk." << endl;
        }

    case 3:
        break;

    case 4:
        if ((userKeyword.compare("tall") == 0)
            || (userKeyword.compare("wooden") == 0)
            || (userKeyword.compare("bookcases") == 0)) {
            cout << "\nTall Wooden Bookcases:" << endl;
            cout << "There are more books on these shelves than you could read in a liftime." << endl;
            cout << "However, the shelves are all quite dirty." << endl;
            cout << "If anyone's hiding something here, there's nothing in the few clean spots on the shelves." << endl;
        }
        if ((userKeyword.compare("antique") == 0)
            || (userKeyword.compare("fireplace") == 0)) {
            cout << "\nAntique Fireplace:" << endl;
            cout << "This would certainly be the first place a guilty party would get rid of evidence." << endl;
            cout << "Thankfully, however, it seems recently lit." << endl;
            cout << "Since it was likely started after Pendleton arrived, it's probably not of importance." << endl;
        }
        if ((userKeyword.compare("large") == 0)
            || (userKeyword.compare("granite") == 0)
            || (userKeyword.compare("chunks") == 0)) {
            cout << "\nLarge Granite Chunks:" << endl;
            cout << "Just more proof of Dr. Stronghold's influence." << endl;
            cout << "He's certainly a saint in the eyes of the mining townsfolk." << endl;
        }
        break;

    case 5:
        if (userKeyword.compare("oven") == 0)
        {
            cout << "Oven" << endl;
            cout << "----------------------------------------" << endl;
            cout << "A stainless steel oven that doesn't seem to have been cleaned recently." << endl;
        }
        break;

        if (userKeyword.compare("stove") == 0)
        {
            cout << "Stove" << endl;
            cout << "----------------------------------------" << endl;
            cout << "An open stovetop covered with pots and pans." << endl;
            cout << "Nothing is out of order here." << endl;
        }

        if (userKeyword.compare("knife block") == 0)
            || (userKeyword.compare("knife") == 0)
            || (userKeyword.compare("knives") == 0)
            || (userKeyword.compare("silverware") == 0)
            || (userKeyword.compare("silver ware") == 0)
        {
            cout << "Knife block and Silverware" << endl;
            cout << "----------------------------------------" << endl;
            cout << "A block of different sized knives." << endl;
            cout << "Next to it is a basket full of spoons and forks." << endl;
            cout << "One knife is missing from the end of the block." << endl;
        }

    case 6:
        if ((userKeyword.compare("red velvet chairs") == 0)
            || (userKeyword.compare("velvet chairs") == 0)
            || (userKeyword.compare("chairs") == 0)) {
            cout << "\nRed Velvet Chairs: " << endl;
            cout << "As you take a closer look around the dining room, you begin to count the number of chairs." << endl;
            cout << "You realize that there's one less chair than the number of guests at the dinner party." << endl;
            cout << "It is likely that the butler and sous chef alternate between sitting in the same chair, but you should question them to make sure." << endl;
        }
        break;

    case 7:
        if (userKeyword.compare("belladonna") == 0)
            || (userKeyword.compare("belladonna stem") == 0)
            || (userKeyword.compare("flower") == 0)
            || (userKeyword.compare("stem") == 0)
            || (userKeyword.compare("stems") == 0)
            || (userKeyword.compare("plant") == 0)
        {
            cout << "Belladonna Plant" << endl;
            cout << "----------------------------------------" << endl;
            cout << "The flowers of the belladonna are in bloom." << endl;
            cout << "Dead leaves cover the soil." << endl;
            cout << "Some of the stems appear to be cut recently." << endl;
        }

        if (userKeyword.compare("fertilizer") == 0)
        {
            cout << "Fertilizer" << endl;
            cout << "----------------------------------------" << endl;
            cout << "The fertilizer is sitting in the corner of the room." << endl;
            cout << "The top is sealed and the bag looks to be about half empty." << endl;
        }

        if (userKeyword.compare("shovel") == 0)
        {
            cout << "Shovel" << endl;
            cout << "----------------------------------------" << endl;
            cout << "A rusty shovel sits against the bag of fertilizer." << endl;
            cout << "The handle is splintered from years of wear." << endl;
        }
        break;

        if (userKeyword.compare("watering can") == 0)
            || (userKeyword.compare("watering") == 0)
            || (userKeyword.compare("can") == 0)
        {
            cout << "Watering Can" << endl;
            cout << "----------------------------------------" << endl;
            cout << "The watering can is half full." << endl;
            cout << "The top of the water is littered with bugs." << endl;
        }

    case 8:
        if (userKeyword.compare("button") == 0)
        {
            cout << "Small Button" << endl;
            cout << "----------------------------------------" << endl;
            cout << "You pick up the button and see that it is red and scratched." << endl;
            cout << "Some fabric hangs out of the holes." << endl;
        }

        if (userKeyword.compare("light") == 0)
            || (userKeyword.compare("lights") == 0)
            || (userKeyword.compare("wall light") == 0)
            || (userKeyword.compare("wall lights") == 0)
        {
            cout << "Lights" << endl;
            cout << "----------------------------------------" << endl;
            cout << "Small lights line the walls." << endl;
            cout << "Dust and cobwebs cover the top of the lights." << endl;
        }

        break;

    case 9:

        if ((userKeyword.compare("wine") == 0)
            || (userKeyword.compare("bottles") == 0)) {
            cout << "\nIt's too dark in here to investigate at the moment." << endl;
        }
        if ((userKeyword.compare("flashlight") == 0)
             && currentUserChoices.at(findFlashlight) == true) {
            cout << "\nYou can see the Wine Cellar rather clearly now." << endl;
            cout << "While the bottles on the shelves seem unopened, something you couldn't see before pops out at you." << endl;
            cout << "In the back of the room, there's a glass display for a wine bottle, labeled \"Alain Hudelot\"." << endl;
            cout << "However, there's no bottle of wine inside." << endl;
            cout << "This is peculiar. You need to ask around about this." << endl;
        }
        if (((userKeyword.compare("uv") == 0) || userKeyword.compare("light"))
            && currentUserChoices.at(findUVLight) == true) {
            cout << "\nYou were right to use the Astrophysicist's UV Light here." << endl;
            cout << "On the floor by the glass display case, there are several spurts of blood." << endl;
            cout << "Getting closer, you can smell a hint of bleach. Someone's cleaned the floor here recently." << endl;
        }
        break;

    case 10:
        if ((userKeyword.compare("breaker box") == 0)
            || (userKeyword.compare("breaker") == 0)
            || (userKeyword.compare("box") == 0)) {
            cout << "\nBreaker Box:" << endl;
            cout << "You learned from Clyde that the power had been turned off around the time of the murder, so you decide to take a closer look at the breaker box." << endl;
            cout << "The breaker box controls the power to the rest of the house, so the murderer was likely in the boiler room directly before or after they committed the crime." << endl;
            cout << "However, there is no signs of tampering, and the forensics team didn't find any fingerprints on the breaker box." << endl;
        }
        break;

    case 11:
        if ((userKeyword.compare("gigantic") == 0)
            || (userKeyword.compare("telescope") == 0)) {
            cout << "\nTelescope:" << endl;
            cout << "It's a beautiful mechanical device with too many parts to count." << endl;
            cout << "(FIXME: CREATE NAME) ASTROPHYSICIST/ARCHEOLOGIST walks up to you." << endl;
            cout << "\"Unfortunately there are too many clouds to view the stars tonight.\"" << endl;
            cout << "\"Dr.Armstrong always wanted to show off the sky to his visitors. I wish I could show you Saturn." << endl;
            cout << "She smiles wistfully. \"It was his favorite planet. He loved how unique it was.\"" << endl;
        }
        if ((userKeyword.compare("little") == 0)
            || (userKeyword.compare("statues") == 0)) {
            cout << "\nAstronomy Displays:" << endl;
            cout << "Three gorgeous statues have been placed behind glass for your viewing pleasure." << endl;
            cout << "One represents the solar system, another is built to resemble the sun, and the last is a representation of a black hole." << endl;
        }
        if ((userKeyword.compare("solar") == 0)
            || (userKeyword.compare("system") == 0)){
            cout << "\nYou read the Solar System exhibit's plaque:" << endl;
            cout << "\"Our solar system rotates our sun like a gracious family, and each planet is a character." << endl;
            cout << "Mercury rests close to home." << endl;
            cout << "Venus absorbs the dark flames of space." << endl;
            cout << "Earth lays in the perfect spot to coax life from its soil." << endl;
            cout << "Mars drifts near the asteroid belt, admiring it like one admires a stream." << endl;
            cout << "Jupiter feasts off the resources it's accumulated." << endl;
            cout << "Saturn dresses in hope that the planets may one day gather to admire one another." << endl;
            cout << "Uranus sits in eternal winter." << endl;
            cout << "Neptune practices an eternal dance." << endl;
            cout << "And of course, Pluto watches in on them like a child watches bugs.\"" << endl;

            type_and_continue();

            cout << "\nAt the bottom of the plaque there is a quote by Paracelsus:" << endl;
            cout << "\"Man is a microcosm, or a little world, because he is an extract from all the stars" << endl;
            cout << "and planets of the whole firmament, from the earth and the elements; and so he is their quintessence.\"" << endl;

        }
        if ((userKeyword.compare("sun") == 0)) {
            cout << "You read the Sun exhibit's plaque:" << endl;
            cout << "\"The sun is a burning passion we all share.\"" << endl;
            cout << "\"Without it there would be no life, and yet one day the stars will extinguish all.\"" << endl;
            cout << "\"It is a reminder that all life is temporary and magic." << endl;
            
            type_and_continue();
            
            cout << "\nAt the bottom of the plaque there is a quote by Hafiz:" << endl;
            cout << "\"Even" << endl;
            cout << "After" << endl;
            cout << "All this time" << endl;
            cout << "The Sun never says to the Earth," << endl;
            cout << "\n\'You owe me.\'\n" << endl;
            cout << "Look" << endl;
            cout << "What happens" << endl;
            cout << "With a love like that," << endl;
            cout << "It lights the whole sky.\"" << endl;
        }
        if ((userKeyword.compare("black") == 0)
            || (userKeyword.compare("hole") == 0)) {
            cout << "You read the Black Hole exhibit's plaque:" << endl;
            cout << "\"A black hole is everything we fear we cannot see." << endl;
            cout << "It is the desire that holds us back and the silent anger that stabs our hearts." << endl;
            cout << "It is a reminder that we can always create more light, and that our work is never done." << endl;

            type_and_continue();

            cout << "\nAt the bottom of the plaque there is a quote by Sir Martin Rees:" << endl;
            cout << "\"Inside every black hole that collapses may lie the seeds of a new expanding universe.\"" << endl;

        }
        if ((userKeyword.compare("lab") == 0)
            || (userKeyword.compare("area") == 0)
            || (userKeyword.compare("scientific") == 0)
            || (userKeyword.compare("tools") == 0)
            || (userKeyword.compare("experiments") == 0)) {
            cout << "Luckily for you, Clyde's cleared out this area with the junior detectives already." << endl;
            cout << "The tools and experiments weren't touched tonight, so there's not anything of interest here." << endl;
        }
        break;

    case 12:
        if ((userKeyword.compare("body") == 0)
            || (userKeyword.compare("mr. stronghold") == 0)
            || (userKeyword.compare("mr. stronghold's body") == 0)
            || (userKeyword.compare("mr. strongholds body") == 0)
            || (userKeyword.compare("stronghold") == 0)
            || (userKeyword.compare("mr stronghold") == 0)
            || (userKeyword.compare("mr stronghold's body") == 0)
            || (userKeyword.compare("mr strongholds body") == 0)) {
            cout << "Mr. Stronghold's Body: " << endl;
            cout << "As you are drawn in closer to Mr. Stronghold's body, you notice a peculiar pagama garment poking out from under the bed." << endl;
            cout << "Standing directly over the dead body, you can't help but notice how sickly pale Mr. Stronghold's face has become." << endl;
            cout << "It is clear that his throat had been sliced cleanly with a knife. This was his cause of death on Clyde's report." << endl;
        }
        if ((userKeyword.compare("armoires") == 0)
            || (userKeyword.compare("victorian era armoires") == 0)
            || (userKeyword.compare("victorian armoires") == 0)
            || (userKeyword.compare("armoire") == 0)
            || (userKeyword.compare("victorian era armoire") == 0)
            || (userKeyword.compare("victorian armoire") == 0)) {
            cout << "Victorian Era Armoires: " << endl;
            cout << "Even though you normally wouldn't give a second thought to a victim's clothing closet, you decide taking a look inside the Strongholds' armoires might give good insight." << endl;
            cout << "Inside Mr. Stronghold's armoire, you find a pair of snow boots, still wet from trecking through snow." << endl;
            cout << "There had been a big snowstorm the night of the murder, so this didn't seem particularly strange to you, but what was Mr. Stronghold doing outside in such bad weather?" << endl;
            cout << "As you rumage through the rest of Mr. Stronghold's clothing, a small sparkling object catches your eye." << endl;
            cout << "You pick up the object, and realize it is a small, yet elegent, diamond earing. What would Mr. Stronghold be doing with a diamond earing in his armoire?" << endl;
            cout << "Mrs. Stronghold's armoire yeilds no significant evidence." << endl;
        }
        if ((userKeyword.compare("vanity") == 0)
            || (userKeyword.compare("vanities") == 0)
            || (userKeyword.compare("glamorous vanity") == 0)
            || (userKeyword.compare("glamorous vanities") == 0)) {
            cout << "Bathroom Vanity: " << endl;
            cout << "In the bathroom, the smell of lavender soap is overwhelming, even though this is a nice escape from the smell of death radiating from the bedroom." << endl;
            cout << "You immediately trace the smell to the open vanity's sink, as you approach the smell of the soap grows stronger." << endl;
            cout << "The sink glistens, light reflecting off water that remain on the sides." << endl;
        }
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

//Prints name of characters associated with current roomNum
void print_character_name(int roomNum) {
    switch (roomNum) {
        case 0:
        cout << "Clyde Pendleton";
        break;

    case 1:
        cout << "Sebastion Gilmore";
        break;

    case 2:
        cout << "N/A";
        break;

    case 3:
        cout << "Mary Ann Sue";
        break;

    case 4:
        cout << "Mrs. Stronghold";
        break;

    case 5:
        cout << "N/A";
        break;

    case 6:
        cout << "N/A";
        break;

    case 7:
        cout << "Louis Arbert";
        break;

    case 8:
        cout << "N/A";
        break;

    case 9:
        cout << "N/A";
        break;

    case 10:
        cout << "Mud Man";
        break;

    case 11:
        cout << "Dr. Jill Tyson";
        break;

    case 12:
        cout << "Dr. Stronghold";
        break;

    case 13:
        cout << "N/A";
        break;
    }
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


