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
void enter_tutorial(vector<bool>& currentUserChoices, vector<string>& clueList);

//This function will print the end of the story, which may change based on the player's actions.
void ending(vector<bool>& currentUserChoices, vector<string>& clueList);

//These functions are the meat of every room's code.
//describe_room prints a basic description, investigate_room allows the player to investigate objects in the room,
//and leave_room lets the player move from room to room.
void describe_room(int roomNum, vector<bool>& currentUserChoices, vector<string>& clueList);
string investigate_room(int roomNum, vector<bool>& currentUserChoices, vector<string>& clueList);
int leave_room(int roomNum);

//These functions will allow the player to question a suspect and then return to the room to investigate afterwards.
void questioning_clyde(int roomNum, vector<bool>& currentUserChoices, vector<string>& clueList);
void questioning_butler(int roomNum, vector<bool>& currentUserChoices, vector<string>& clueList);
void questioning_souschef(int roomNum, vector<bool>& currentUserChoices, vector<string>& clueList);
void questioning_mrsstronghold(int roomNum, vector<bool>& currentUserChoices, vector<string>& clueList);
void questioning_winecrafter(int roomNum, vector<bool>& currentUserChoices, vector<string>& clueList);
void questioning_mudman(int roomNum, vector<bool>& currentUserChoices, vector<string>& clueList);
void questioning_astronomer(int roomNum, vector<bool>& currentUserChoices, vector<string>& clueList);

//These functions print requests for user input. The first requests a keyword to investigate, 
//and the second requests input for a room name.
void print_keyword_request(int roomNum);
void print_new_room_request(int roomNum);
void print_questioning_request(int roomNum);
void print_pendleton_help_request(int roomNum);
void print_interrogation_request(int roomNum, vector<string>& clueList);

//These functions print a pretty title for each room, the actual name of each room,
//and the names of adjacent rooms to the player's current location.
string get_room_name(int roomNum);
void print_room_title(int roomNum);
void print_adjacent_rooms(int roomNum);

//This function prints character names.
string get_character_name(int roomNum, int formality = 0);
void print_character_questioning_title(int roomNum);

//These functions both get user input: the first for investigating and leaving a room,
//and the second is used to pause the game until the player is ready to move forward.
//This will help them read the descriptions etc.
string get_keyword_input();
void type_and_continue();

//This is a function used for testing that prints user input.
void print_input(string input);



//These constants will be used as the indexes for the userChoices vector. 
//The booleans keep track of user choices and progress.
//If you meet Clyde in the tutorial, for example, userChoices.at(meetClyde) is set to true to keep track of that progress.
//It prevents you from having to repeat the tutorial every time you enter the trophy hall.
const int MEETCLYDE = 0;
const int FINDFLASHLIGHT = 1;
const int FINDUVLIGHT = 2;

//These constants will be used as the indexes of the clues in the clueList vector.
//They will help title each clue as they are found.
const int CASEFILE = 0;
const int EXPENSEREPORTS = 1;
const int SMALLSAFE = 2;
const int INSURANCEPOLICY = 3;
const int LATECHECK = 4;
const int ANONYMOUSLETTER = 5;
const int LOCKEDCHESTS = 6;
const int MISSINGKNIFE = 7;
const int REDVELVETCHAIRS = 8;
const int CUTNIGHTSHADE = 9;
const int SMALLBUTTON = 10;
const int EMPTYDISPLAY = 11;
const int BLOODSTAINS = 12;
const int CLEANEDFLOOR = 13;
const int GLASSSHARDS = 14;
const int BROKENLOCK = 15;
const int SLASHEDTHROAT = 16;
const int FOAMEDMOUTH = 17;
const int BLOODYGARMENT = 18;
const int WETBOOTS = 19;
const int EARRING = 20;
const int WASHEDSINK = 21;
const int SNOWYFOOTPRINTS = 22;


//These constants will be used as markers for each room's number.
const int TROPHYHALL = 0;
const int BALLROOM = 1;
const int OFFICE = 2;
const int SERVANTSQUARTERS = 3;
const int LIBRARY = 4;
const int KITCHEN = 5;
const int DININGROOM = 6;
const int GREENHOUSE = 7;
const int STAIRWELL = 8;
const int WINECELLAR = 9;
const int BOILERROOM = 10;
const int OBSERVATORY = 11;
const int MASTERBEDROOM = 12;
const int BALCONY = 13;

//These constants will be used as markers for each character's room number.
const int CLYDE = 0;
const int BUTLER = 1;
const int SOUSCHEF = 3;
const int MRSSTRONGHOLD = 4;
const int WINECRAFTER = 7;
const int MUDMAN = 10;
const int ASTRONOMER = 11;
const int DRSTRONGHOLD = 12;

//These constants will be used to mark whether a formal or informal name is called for the print_character_name function.
const int FORMAL = 0;
const int INFORMAL = 1;

//This constant represents the number of important clues within the game
const int NUMCLUES = 30;




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

    //Declares boolean vector clueList, which is a list of all clue names
    vector<string> clueList(NUMCLUES);
    //Sets boolean at every index to false
    for (size_t i = 0; i < clueList.size(); i++) {
        clueList.at(i) = "???";
    }

    clueList.at(CASEFILE) = "\"Case File\"";
    clueList.at(EXPENSEREPORTS) = "\"Expense Reports\" in the " + get_room_name(OFFICE);
    clueList.at(SMALLSAFE) = "\"Small Safe\" in the " + get_room_name(OFFICE);
    clueList.at(INSURANCEPOLICY) = "\"Insurance Policy\" in the " + get_room_name(OFFICE);
    clueList.at(LATECHECK) = "\"Late Check\" in the " + get_room_name(OFFICE);
    clueList.at(ANONYMOUSLETTER) = "\"Anonymous Letter\" in the " + get_room_name(OFFICE);
    clueList.at(LOCKEDCHESTS) = "\"Locked Chests\" in the " + get_room_name(SERVANTSQUARTERS);
    clueList.at(MISSINGKNIFE) = "\"Missing Knife\" in the " + get_room_name(KITCHEN);
    clueList.at(REDVELVETCHAIRS) = "\"Red Velvet Chairs\" in the " + get_room_name(DININGROOM);
    clueList.at(CUTNIGHTSHADE) = "\"Cut Nightshade\" in the " + get_room_name(GREENHOUSE);
    clueList.at(SMALLBUTTON) = "\"Small Button\" in the " + get_room_name(STAIRWELL);
    clueList.at(EMPTYDISPLAY) = "\"Empty Display\" in the " + get_room_name(WINECELLAR);
    clueList.at(BLOODSTAINS) = "\"Bloodstains\" in the " + get_room_name(WINECELLAR);
    clueList.at(CLEANEDFLOOR) = "\"Cleaned Floor\" in the " + get_room_name(WINECELLAR);
    clueList.at(GLASSSHARDS) = "\"Glass Shards\" in the " + get_room_name(BOILERROOM);
    clueList.at(BROKENLOCK) = "\"Broken Lock\" on the " + get_room_name(OBSERVATORY) + " door to the " + get_room_name(BALCONY);
    clueList.at(SLASHEDTHROAT) = get_character_name(DRSTRONGHOLD) + "'s Slashed Throat";
    clueList.at(FOAMEDMOUTH) = get_character_name(DRSTRONGHOLD) + "'s Foaming Mouth";
    clueList.at(BLOODYGARMENT) = "\"Bloody Garment\" in the " + get_room_name(MASTERBEDROOM);
    clueList.at(WETBOOTS) = "\"Wet Boots\" in the " + get_room_name(MASTERBEDROOM);
    clueList.at(EARRING) = "\"Earring\" in the " + get_room_name(MASTERBEDROOM);
    clueList.at(WASHEDSINK) = "\"Washed Sink\" in the " + get_room_name(MASTERBEDROOM);
    clueList.at(SNOWYFOOTPRINTS) = "The \"Snowy Footprints\" on the " + get_room_name(MASTERBEDROOM);

    //FIXME: REMOVE ONCE GAME IS FINISHED
    //Prints clueList
    for (size_t i = 0; i < clueList.size(); i++) {
        cout << clueList.at(i) << endl;
    }

    type_and_continue();

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
            describe_room(roomNum, userChoices, clueList);

            //Enters tutorial for player if they're just starting the game
            if (userChoices.at(MEETCLYDE) == false) {
                enter_tutorial(userChoices, clueList);
                describe_room(roomNum, userChoices, clueList);
            }

            //Investigates chosen keyword from room 0 description, prints info about keyword
            userKeyword = investigate_room(roomNum, userChoices, clueList);

            //Loops Until Player decides to leave room
            while (userKeyword.compare("leave") != 0) {
                //Empties console screen
                system("CLS");

                //Describes Room 0
                describe_room(roomNum, userChoices, clueList);
                userKeyword = investigate_room(roomNum, userChoices, clueList);
            }

            //Sets New Room Number to User's Input
            print_new_room_request(roomNum);
            roomNum = leave_room(roomNum);

            //Loops until player has chosen new room to enter
            while (roomNum == 0) {
                //Clears Screen
                system("CLS");
                cout << "Invalid Selection. Type one of the following room names exactly:" << endl;
                //Sets New Room Number to User's Input
                roomNum = leave_room(roomNum);
            }

            break;


        case 1:
            //Empties console screen
            system("CLS");

            //Describes Room 1
            describe_room(roomNum, userChoices, clueList);

            //Investigates chosen keyword from room 1 description, prints info about keyword
            userKeyword = investigate_room(roomNum, userChoices, clueList);

            //Loops Until Player decides to leave room
            while (userKeyword.compare("leave") != 0) {
                //Empties console screen
                system("CLS");

                //Describes Room 0
                describe_room(roomNum, userChoices, clueList);
                userKeyword = investigate_room(roomNum, userChoices, clueList);
            }

            //Sets New Room Number to User's Input
            print_new_room_request(roomNum);
            roomNum = leave_room(roomNum);

            //Loops until player has chosen new room to enter
            while (roomNum == 1) {
                //Clears Screen
                system("CLS");
                cout << "Invalid Selection. Type one of the following room names exactly:" << endl;
                //Sets New Room Number to User's Input
                roomNum = leave_room(roomNum);
            }

            break;


        case 2:
            //Empties console screen
            system("CLS");

            //Describes Room 2
            describe_room(roomNum, userChoices, clueList);

            //Investigates chosen keyword from room 2 description, prints info about keyword
            userKeyword = investigate_room(roomNum, userChoices, clueList);

            //Loops Until Player decides to leave room
            while (userKeyword.compare("leave") != 0) {
                //Empties console screen
                system("CLS");

                //Describes Room 0
                describe_room(roomNum, userChoices, clueList);
                userKeyword = investigate_room(roomNum, userChoices, clueList);
            }

            //Sets New Room Number to User's Input
            print_new_room_request(roomNum);
            roomNum = leave_room(roomNum);

            //Loops until player has chosen new room to enter
            while (roomNum == 2) {
                //Clears Screen
                system("CLS");
                cout << "Invalid Selection. Type one of the following room names exactly:" << endl;
                //Sets New Room Number to User's Input
                roomNum = leave_room(roomNum);
            }

            break;


        case 3:
            //Empties console screen
            system("CLS");

            //Describes Room 3
            describe_room(roomNum, userChoices, clueList);

            //Investigates chosen keyword from room 3 description, prints info about keyword
            userKeyword = investigate_room(roomNum, userChoices, clueList);

            //Loops Until Player decides to leave room
            while (userKeyword.compare("leave") != 0) {
                //Empties console screen
                system("CLS");

                //Describes Room 0
                describe_room(roomNum, userChoices, clueList);
                userKeyword = investigate_room(roomNum, userChoices, clueList);
            }

            //Sets New Room Number to User's Input
            print_new_room_request(roomNum);
            roomNum = leave_room(roomNum);

            //Loops until player has chosen new room to enter
            while (roomNum == 3) {
                //Clears Screen
                system("CLS");
                cout << "Invalid Selection. Type one of the following room names exactly:" << endl;
                //Sets New Room Number to User's Input
                roomNum = leave_room(roomNum);
            }

            break;


        case 4:
            //Empties console screen
            system("CLS");

            //Describes Room 4
            describe_room(roomNum, userChoices, clueList);

            //Investigates chosen keyword from room 4 description, prints info about keyword
            userKeyword = investigate_room(roomNum, userChoices, clueList);

            //Loops Until Player decides to leave room
            while (userKeyword.compare("leave") != 0) {
                //Empties console screen
                system("CLS");

                //Describes Room 0
                describe_room(roomNum, userChoices, clueList);
                userKeyword = investigate_room(roomNum, userChoices, clueList);
            }

            //Sets New Room Number to User's Input
            print_new_room_request(roomNum);
            roomNum = leave_room(roomNum);

            //Loops until player has chosen new room to enter
            while (roomNum == 4) {
                //Clears Screen
                system("CLS");
                cout << "Invalid Selection. Type one of the following room names exactly:" << endl;
                //Sets New Room Number to User's Input
                roomNum = leave_room(roomNum);
            }

            break;


        case 5:
            //Empties console screen
            system("CLS");

            //Describes Room 5
            describe_room(roomNum, userChoices, clueList);

            //Investigates chosen keyword from room 5 description, prints info about keyword
            userKeyword = investigate_room(roomNum, userChoices, clueList);

            //Loops Until Player decides to leave room
            while (userKeyword.compare("leave") != 0) {
                //Empties console screen
                system("CLS");

                //Describes Room 0
                describe_room(roomNum, userChoices, clueList);
                userKeyword = investigate_room(roomNum, userChoices, clueList);
            }

            //Sets New Room Number to User's Input
            print_new_room_request(roomNum);
            roomNum = leave_room(roomNum);

            //Loops until player has chosen new room to enter
            while (roomNum == 5) {
                //Clears Screen
                system("CLS");
                cout << "Invalid Selection. Type one of the following room names exactly:" << endl;
                //Sets New Room Number to User's Input
                roomNum = leave_room(roomNum);
            }

            break;


        case 6:
            //Empties console screen
            system("CLS");

            //Describes Room 6
            describe_room(roomNum, userChoices, clueList);

            //Investigates chosen keyword from room 6 description, prints info about keyword
            userKeyword = investigate_room(roomNum, userChoices, clueList);

            //Loops Until Player decides to leave room
            while (userKeyword.compare("leave") != 0) {
                //Empties console screen
                system("CLS");

                //Describes Room 0
                describe_room(roomNum, userChoices, clueList);
                userKeyword = investigate_room(roomNum, userChoices, clueList);
            }

            //Sets New Room Number to User's Input
            print_new_room_request(roomNum);
            roomNum = leave_room(roomNum);

            //Loops until player has chosen new room to enter
            while (roomNum == 6) {
                //Clears Screen
                system("CLS");
                cout << "Invalid Selection. Type one of the following room names exactly:" << endl;
                //Sets New Room Number to User's Input
                roomNum = leave_room(roomNum);
            }

            break;


        case 7:
            //Empties console screen
            system("CLS");

            //Describes Room 7
            describe_room(roomNum, userChoices, clueList);

            //Investigates chosen keyword from room 7 description, prints info about keyword
            userKeyword = investigate_room(roomNum, userChoices, clueList);

            //Loops Until Player decides to leave room

            while (userKeyword.compare("leave") != 0) {
                //Empties console screen
                system("CLS");

                //Describes Room 0
                describe_room(roomNum, userChoices, clueList);
                userKeyword = investigate_room(roomNum, userChoices, clueList);
            }

            //Sets New Room Number to User's Input
            print_new_room_request(roomNum);
            roomNum = leave_room(roomNum);

            //Loops until player has chosen new room to enter
            while (roomNum == 7) {
                //Clears Screen
                system("CLS");
                cout << "Invalid Selection. Type one of the following room names exactly:" << endl;
                //Sets New Room Number to User's Input
                roomNum = leave_room(roomNum);
            }

            break;


        case 8:
            //Empties console screen
            system("CLS");

            //Describes Room 8
            describe_room(roomNum, userChoices, clueList);

            //Investigates chosen keyword from room 8 description, prints info about keyword
            userKeyword = investigate_room(roomNum, userChoices, clueList);

            //Loops Until Player decides to leave room
            while (userKeyword.compare("leave") != 0) {
                //Empties console screen
                system("CLS");

                //Describes Room 0
                describe_room(roomNum, userChoices, clueList);
                userKeyword = investigate_room(roomNum, userChoices, clueList);
            }

            //Sets New Room Number to User's Input
            print_new_room_request(roomNum);
            roomNum = leave_room(roomNum);

            //Loops until player has chosen new room to enter
            while (roomNum == 8) {
                //Clears Screen
                system("CLS");
                cout << "Invalid Selection. Type one of the following room names exactly:" << endl;
                //Sets New Room Number to User's Input
                roomNum = leave_room(roomNum);
            }

            break;


        case 9:
            //Empties console screen
            system("CLS");

            //Describes Room 9
            describe_room(roomNum, userChoices, clueList);

            //Investigates chosen keyword from room 9 description, prints info about keyword
            userKeyword = investigate_room(roomNum, userChoices, clueList);

            //Loops Until Player decides to leave room
            while (userKeyword.compare("leave") != 0) {
                //Empties console screen
                system("CLS");

                //Describes Room 0
                describe_room(roomNum, userChoices, clueList);
                userKeyword = investigate_room(roomNum, userChoices, clueList);
            }

            //Sets New Room Number to User's Input
            print_new_room_request(roomNum);
            roomNum = leave_room(roomNum);

            //Loops until player has chosen new room to enter
            while (roomNum == 9) {
                //Clears Screen
                system("CLS");
                cout << "Invalid Selection. Type one of the following room names exactly:" << endl;
                //Sets New Room Number to User's Input
                roomNum = leave_room(roomNum);
            }

            break;


        case 10:
            //Empties console screen
            system("CLS");

            //Describes Room 10
            describe_room(roomNum, userChoices, clueList);

            //Investigates chosen keyword from room 10 description, prints info about keyword
            userKeyword = investigate_room(roomNum, userChoices, clueList);

            //Loops Until Player decides to leave room
            while (userKeyword.compare("leave") != 0) {
                //Empties console screen
                system("CLS");

                //Describes Room 0
                describe_room(roomNum, userChoices, clueList);
                userKeyword = investigate_room(roomNum, userChoices, clueList);
            }

            //Sets New Room Number to User's Input
            print_new_room_request(roomNum);
            roomNum = leave_room(roomNum);

            //Loops until player has chosen new room to enter
            while (roomNum == 10) {
                //Clears Screen
                system("CLS");
                cout << "Invalid Selection. Type one of the following room names exactly:" << endl;
                //Sets New Room Number to User's Input
                roomNum = leave_room(roomNum);
            }

            break;


        case 11:
            //Empties console screen
            system("CLS");

            //Describes Room 11
            describe_room(roomNum, userChoices, clueList);

            //Investigates chosen keyword from room 11 description, prints info about keyword
            userKeyword = investigate_room(roomNum, userChoices, clueList);

            //Loops Until Player decides to leave room
            while (userKeyword.compare("leave") != 0) {
                //Empties console screen
                system("CLS");

                //Describes Room 0
                describe_room(roomNum, userChoices, clueList);
                userKeyword = investigate_room(roomNum, userChoices, clueList);
            }

            //Sets New Room Number to User's Input
            print_new_room_request(roomNum);
            roomNum = leave_room(roomNum);

            //Loops until player has chosen new room to enter
            while (roomNum == 11) {
                //Clears Screen
                system("CLS");
                cout << "Invalid Selection. Type one of the following room names exactly:" << endl;
                //Sets New Room Number to User's Input
                roomNum = leave_room(roomNum);
            }

            break;


        case 12:
            //Empties console screen
            system("CLS");

            //Describes Room 12
            describe_room(roomNum, userChoices, clueList);

            //Investigates chosen keyword from room 12 description, prints info about keyword
            userKeyword = investigate_room(roomNum, userChoices, clueList);

            //Loops Until Player decides to leave room
            while (userKeyword.compare("leave") != 0) {
                //Empties console screen
                system("CLS");

                //Describes Room 0
                describe_room(roomNum, userChoices, clueList);
                userKeyword = investigate_room(roomNum, userChoices, clueList);
            }

            //Sets New Room Number to User's Input
            print_new_room_request(roomNum);
            roomNum = leave_room(roomNum);

            //Loops until player has chosen new room to enter
            while (roomNum == 12) {
                //Clears Screen
                system("CLS");
                cout << "Invalid Selection. Type one of the following room names exactly:" << endl;
                //Sets New Room Number to User's Input
                roomNum = leave_room(roomNum);
            }

            break;


        case 13:
            //Empties console screen
            system("CLS");

            //Describes Room 13
            describe_room(roomNum, userChoices, clueList);

            //Investigates chosen keyword from room 13 description, prints info about keyword
            userKeyword = investigate_room(roomNum, userChoices, clueList);

            //Loops Until Player decides to leave room
            while (userKeyword.compare("leave") != 0) {
                //Empties console screen
                system("CLS");

                //Describes Room 0
                describe_room(roomNum, userChoices, clueList);
                userKeyword = investigate_room(roomNum, userChoices, clueList);
            }

            //Sets New Room Number to User's Input
            print_new_room_request(roomNum);
            roomNum = leave_room(roomNum);

            //Loops until player has chosen new room to enter
            while (roomNum == 13) {
                //Clears Screen
                system("CLS");
                cout << "Invalid Selection. Type one of the following room names exactly:" << endl;
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
    ending(userChoices, clueList);

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
void enter_tutorial(vector<bool>& currentUserChoices, vector<string>& clueList) {
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
    currentUserChoices.at(MEETCLYDE) = true;

    type_and_continue();

    //Empties console screen
    system("CLS");

}



//Prints ending on the story, which may differ based on userChoices
void ending(vector<bool>& currentUserChoices, vector<string>& clueList) {
    //Empties console screen
    system("CLS");

    //FIXME: RETURN USER'S DESIRED ROOMNUM
    cout << "FIXME: ADD ENDING TO STORY." << endl;
    cout << "This is the end." << endl;

}



//Describes current room, and may change description based on user choices
void describe_room(int roomNum, vector<bool>& currentUserChoices, vector<string>& clueList) {

    switch (roomNum) {

    case 0:
        //Prints basic room description if player has met clyde
        if (currentUserChoices.at(MEETCLYDE) == true) {
            print_room_title(roomNum);
            cout << "In the " << get_room_name(TROPHYHALL) << ", glass cupboards line the edges of the room with glimmering bronze and silver figures." << endl;
            cout << "Dracaena plants cradle some shelves filled with well dusted black and white photos." << endl;
            cout << "There's even a golden lion head attached to the wall, right above the double doors that lead into the mansion's core." << endl;

            cout << "\n" << get_character_name(CLYDE, INFORMAL) << " sits by the plastic table of evidence, prepared to answer any questions you might have." << endl;
        }
        //Prints different description if player hasn't met clyde
        else {
            print_room_title(roomNum);
            cout << "You enter the mansion and find yourself in an ornate " << get_room_name(TROPHYHALL) << "." << endl;
            cout << "Glass cupboards line the edges of the room with glimmering bronze and silver figures." << endl;
            cout << "Dracaena plants cradle some shelves filled with well dusted black and white photos." << endl;
            cout << "There's even a golden lion head attached to the wall, right above the double doors that lead into the mansion's core." << endl;

            cout << "\nSeveral junior recruits are sitting around a plastic table that clashes with the mansion's sophisticated decor." << endl;
            cout << "They've set up the evidence table for your convenience." << endl;
            cout << "Your closest confidant, " << get_character_name(CLYDE, FORMAL) << ", seems eager to greet you." << endl;
            cout << "He probably has a case file prepared for you." << endl;

            type_and_continue();
        }
        break;

    case 1:
        //Prints Description For Room 1
        print_room_title(roomNum);
        cout << "The " << get_room_name(BALLROOM) << " before you is gorgeous." << endl;
        cout << "Two shades of sparkling vinyl encompass the floor in a spiral pattern, almost like they're chasing one another." << endl;
        cout << "Marble columns outline the space's edges, stretching at least two stories to the ceiling." << endl;
        cout << "Several intricate chandeliers hang from the ceiling, too." << endl;
        cout << "They almost seem to be intertwined, their supports forming a star-like shape above the dance floor." << endl;
        
        cout << "\n" << get_character_name(BUTLER, FORMAL) << ", The Butler, is standing by one of the columns, washing it down with some bleach." << endl;
        break;

    case 2:
        //Prints Description For Room 2
        print_room_title(roomNum);
        cout << "The " << get_room_name(OFFICE) << " is covered in paperwork." << endl;
        cout << "Velvet curtains line the left and right walls and a rotating bookshelf hides in the corner." << endl;
        cout << "In the middle of the room, light radiates from a crescent moon shaped lamp sitting on a large oak desk." << endl;
        cout << "Looking in its drawers you find some interesting knick knacks, but your attention is stolen soon after." << endl;
        cout << "In the victim's bottom drawer there is a small safe. You'll need a four digit code to open it." << endl;
        break;

    case 3:
        //Prints Description For Room 3
        print_room_title(roomNum);
        cout << "The " << get_room_name(SERVANTSQUARTERS) << " are relatively small." << endl;
        cout << "The quarters are hardly longer than each of the twin beds, which are positioned on opposite sides of the room." << endl;
        cout << "The only other furniture along the walls is an old-fashioned grandfather clock that towers over the back wall." << endl;
        cout << "Its pendulum slowly moves back and forth as the seconds tick by." << endl;
        cout << "Lastly, some small wooden chests sit at the foot of each servant's bed." << endl;

        cout << "\n" << get_character_name(SOUSCHEF, FORMAL) << ", The Sous Chef, is sitting on one of the twin beds elegantly." << endl;
        break;

    case 4:
        //Prints Description For Room 4
        print_room_title(roomNum);
        cout << "In the " << get_room_name(LIBRARY) << ", the air is thick with dust." << endl;
        cout << "The space, though constricted, feels quite cozy." << endl;
        cout << "Tall wooden bookcases divide the room, and they're filled to the brim with books." << endl;
        cout << "At the room's far end, an antique fireplace lets off heat and light." << endl;
        cout << "It looks to be made of large granite chunks, likely from the quarry south of the estate." << endl;

        cout << "\n" << get_character_name(MRSSTRONGHOLD, FORMAL) << ", the murder victim's wife, is sitting in a nearby escritoire scribbling in a thick notebook." << endl;
        break;

    case 5:
        //Prints Description For Room 5
        print_room_title(roomNum);
        cout << "You enter the " << get_room_name(KITCHEN) << " through a creaky door." << endl;
        cout << "An industrial stovetop oven and a stainless steel sink are attached to the back counter." << endl;
        cout << "Under the cupboards, there is a block of knives and a basket of kitchen utensils." << endl;

        cout << "A tray of Hors d'oeuvres has been set on the counter with a note attached:" << endl;
        cout << "\"Feel free to take some Hors d'oeuvres before you investigate. You'll thoroughly enjoy them.\"" << endl;
        cout << "- Ms. Davis" << endl;
        break;

    case 6:
        //Prints Description For Room 6
        print_room_title(roomNum);
        cout << "The " << get_room_name(DININGROOM) << " is very bright." << endl;
        cout << "An elegant diamond chandelier hangs high above the table, and its bulbs make the jewels perched on its top glisten." << endl;
        cout << "You shake your head. This was the last room everyone saw " << get_character_name(DRSTRONGHOLD) << " in before his death." << endl;
        cout << "An ornate dining table takes up most of the room's space." << endl;
        cout << "It's surrounded by red velvet chairs that are just as pompous as everything else." << endl;
        break;

    case 7:
        //Prints Description For Room 7
        print_room_title(roomNum);
        cout << "A wave of heat blasts through you when you walk through the door to the " << get_room_name(GREENHOUSE) << "." << endl;
        cout << "Though this room is crowded with potted flowers, it feels rather safe and sound." << endl;
        cout << "You suppose that's thanks to the moonlight shining down from the skylight." << endl;
        cout << "In the corner you find some gardening tools and logs." << endl;

        cout << "\n" << get_character_name(WINECRAFTER, FORMAL) << ", The Wine Crafter, is kneeling beside the grape vines, picking them." << endl;
        break;

    case 8:
        //Prints Description For Room 8
        print_room_title(roomNum);
        cout << "You approach the delapidated " << get_room_name(STAIRWELL) << "." << endl;
        cout << "An aged bathroom sits beside its entrance." << endl;
        cout << "There is a worn red carpet lain across the middle of the steps." << endl;
        cout << "Small globe lights line the walls, providing just enough light to avoid some holes in the cracked planks." << endl;
        break;

    case 9:
        //Prints Description For Room 9
        print_room_title(roomNum);
        cout << "If anything most confirms these people's overindulgence, it's their " << get_room_name(WINECELLAR) << "." << endl;
        cout << "Several hundred bottles of white and red wine fill up slots on the walls, seeming to sparkle in the dim light." << endl;
        cout << "The room is lit by some ceiling fixtures, but not well enough to read the bottle labels." << endl;
        cout << "You're not sure what you could investigate down here without a flashlight." << endl;
        break;

    case 10:
        //Prints Description For Room 10
        print_room_title(roomNum);
        cout << "As you enter the " << get_room_name(BOILERROOM) << ", you hear the soft hum of the furnace." << endl;
        cout << "A large garbage bin sits in the corner, barely lit by a single hanging lightbulb." << endl;
        cout << "As your eyes adjust to the low light, you are able to makeout the shape of a man sitting at the back of the room." << endl;
        cout << "The breaker box sits in the corner, quietly." << endl;

        cout << "\n" << get_character_name(MUDMAN, FORMAL) << ", The Mud Man, stares directly at you." << endl;
        cout << "He's sitting in a pile of dark, sticky mud." << endl;
        cout << "Besides the whites of his eyes, almost everything is covered in muck." << endl;
        cout << "\"What do you want? If you're not here for anything important, leave me to my mud.\"" << endl;
        break;

    case 11:
        //Prints Description For Room 11
        print_room_title(roomNum);
        cout << "The first thing you notice about the " << get_room_name(OBSERVATORY) << " is the gigantic telescope at its center." << endl;
        cout << "With all of its sophisticated mechanical parts, you'd guess it would take weeks of practice to use. Months maybe." << endl;
        cout << "Beyond the telescope, little statues representing the solar system, the sun, and a black hole are on display." << endl;
        cout << "There's also a lab-like area full of scientific tools and half-finished experiments." << endl;

        cout << "\n" << get_character_name(ASTRONOMER, FORMAL) << ", The Astronomer, emerges from behind the telescope and waves to you." << endl;
        break;

    case 12:
        //Prints Description For Room 12
        print_room_title(roomNum);
        cout << "You enter the " << get_room_name(MASTERBEDROOM) << " through two heavy french doors." << endl;
        cout << "The smell of death is potent. This definitely seems to be where the victim was murdered." << endl;
        cout << get_character_name(DRSTRONGHOLD, INFORMAL) << "'s body is lying across his lavish blood stained bed." << endl;
        cout << "Across from the bed, two victorian era armoires sit tight against the wall." << endl;

        cout << "\nYou check the Master Bathroom as well." << endl;
        cout << "The tub, large enough to be a poor man's pool, is still full." << endl;
        cout << "Two glamorous vanities fill the empty space." << endl;
        cout << "And... Of course. There's also a golden toilet." << endl;
        break;

    case 13:
        //FIXME: DESCRIBE ROOM 13
        print_room_title(roomNum);
        cout << "FIXME: DESCRIBE ROOM 13." << endl;
        break;

    default:
        cout << "FIXME: roomNum is an unknown, unused number." << endl;
        break;
    }

}

//Allows player to investigate objects within a room.
string investigate_room(int roomNum, vector<bool>& currentUserChoices, vector<string>& clueList) {

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
            cout << "\nGlass Trophy Cupboards: " << endl;
            cout << "----------------------------------------" << endl;
            cout << get_character_name(DRSTRONGHOLD) << " has an arrangement of trophies proudly presented in the glass cupboards." << endl;
            cout << "It seems he's achieved quite a lot in the scientific world." << endl;
            cout << "He received several awards for renovating the world of astronomy with his telescope designs." << endl;
            cout << "He's also a prime benefactor of a nearby coal mining town." << endl;
        }

        if ((userKeyword.compare("dracaena") == 0)
            || (userKeyword.compare("plants") == 0)) {
            cout << "\nDracaena Plants:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "These plants are low effort shrubs with beautiful green leaves." << endl;
            cout << "Unsurprisingly, the ones in this room are in great condition." << endl;
            cout << "You would expect no less from a couple with a butler." << endl;
        }

        if ((userKeyword.compare("well") == 0)
            || (userKeyword.compare("dusted") == 0)
            || (userKeyword.compare("black") == 0)
            || (userKeyword.compare("white") == 0)
            || (userKeyword.compare("photos") == 0)) {
            cout << "\nWell Dusted Photos:" << endl;
            cout << "----------------------------------------" << endl;
            cout << get_character_name(DRSTRONGHOLD) << " was clearly a fan of photos." << endl;
            cout << "He has quite a few of each suspect." << endl;
            cout << "In one, the Butler carries an overflowing tray of drinks with a smile." << endl;
            cout << "There's another with " << get_character_name(DRSTRONGHOLD) << "'s prized Sous Chef displaying a stuffed fish." << endl;
            cout << "In another, his talented Astronomy Partner is holding their shared award for technological achievement." << endl;
            cout << "There's even one of his Wine Crafter proudly displaying an \"Alain Hudelot\" bottle" << endl;
            cout << "You drift to the final set of photos, which are all of his wife." << endl;
            cout << get_character_name(MRSSTRONGHOLD) << " looks truly elegant in all of them. Even as her hair grays, her beauty never fades." << endl;
        }

        if ((userKeyword.compare("golden") == 0)
            || (userKeyword.compare("lion") == 0)
            || (userKeyword.compare("head") == 0)) {
            cout << "\nGolden Lion Head:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "It's well polished... and quite gratutious." << endl;
            cout << "It doesn't seem particularly relevant to the case, however." << endl;
        }

        if ((userKeyword.compare("clyde") == 0)
            || (userKeyword.compare("pendleton") == 0)) {
            questioning_clyde(roomNum, currentUserChoices, clueList);
        }
        break;

    case 1:

        if ((userKeyword.compare("sparkling") == 0)
            || (userKeyword.compare("vinyl") == 0)
            || (userKeyword.compare("floor") == 0)) {
            cout << "\nVinyl Floors:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "The Butler has clearly been wiping the floors down." << endl;
            cout << "You wonder if there's any reason for that..." << endl;
            cout << "Maybe he's just desperate to get his mind off of things." << endl;
        }

        if ((userKeyword.compare("marble") == 0)
            || (userKeyword.compare("columns") == 0)) {
            cout << "\nMarble Columns:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "If these are important to the case, you're not seeing why." << endl;
            cout << "They're just gorgeous pillars. They don't have much use beyond their appeal to the eye." << endl;
        }

        if ((userKeyword.compare("intricate") == 0)
            || (userKeyword.compare("chandeliers") == 0)) {
            cout << "\nIntricate Chandeliers:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "An old friend told you about a case of theirs where a chandelier fell onto the victim's head." << endl;
            cout << "Luckily these chandeliers seem rather attached to the ceiling." << endl;
        }

        if ((userKeyword.compare("mr.") == 0)
            || (userKeyword.compare("butler") == 0)
            || (userKeyword.compare("sebastian") == 0)
            || (userKeyword.compare("gilmore") == 0)) {
            questioning_butler(roomNum, currentUserChoices, clueList);
        }
        break;

    case 2:

        if (userKeyword.compare("paperwork") == 0) {
            cout << "\nPaperwork:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "Piles of paperwork have scattered throughout the room." << endl;
            cout << "It seems " << get_character_name(DRSTRONGHOLD) << "" << endl;
        }

        if ((userKeyword.compare("velvet") == 0)
            || (userKeyword.compare("curtains") == 0)) {
            cout << "\nVelvet Curtains:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "Behind the curtains, you find some gleaming stained glass windows." << endl;
            cout << "They're painted and shaped to form the visage of a shooting star." << endl;
            cout << "You look beyond the glass. The view outside is disconcerting." << endl;
            cout << "It feels very cold tonight, and another storm looks to be heading this way." << endl;
            cout << "Hopefully the sunrise will be visible tomorrow." << endl;
        }

        if ((userKeyword.compare("rotating") == 0)
            || (userKeyword.compare("bookshelf") == 0)) {
            cout << "\nSmall Bookshelf:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "There's almost nothing here but dull self help books." << endl;
            cout << "The only item of interest here is a file of expense reports." << endl;
        }
        if ((userKeyword.compare("file") == 0)
            || (userKeyword.compare("expense") == 0)
            || (userKeyword.compare("reports") == 0)) {
            cout << "\nDull Expense Reports:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "FIXME: ADD DESCRIPTION OF ITEM." << endl;
        }

        if ((userKeyword.compare("crescent") == 0)
            || (userKeyword.compare("moon") == 0)
            || (userKeyword.compare("lamp") == 0)) {
            cout << "\nCrescent Moon Lamp:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "FIXME: ADD DESCRIPTION OF ITEM." << endl;
        }

        if ((userKeyword.compare("large") == 0)
            || (userKeyword.compare("oak") == 0)
            || (userKeyword.compare("desk") == 0)) {
            cout << "\nLarge Oak Desk:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "FIXME: ADD DESCRIPTION OF ITEM." << endl;
        }
        if ((userKeyword.compare("knick") == 0)
            || (userKeyword.compare("knacks") == 0)) {
            cout << "\nKnick Knacks:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "FIXME: ADD DESCRIPTION OF ITEM." << endl;
        }

        if ((userKeyword.compare("small") == 0)
            || (userKeyword.compare("safe") == 0)) {
            cout << "\nSmall Safe:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "FIXME: ADD DESCRIPTION OF ITEM." << endl;
        }
        break;

    case 3:

        if ((userKeyword.compare("twin") == 0)
            || (userKeyword.compare("beds") == 0)) {
            cout << "\nTwin Beds:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "FIXME: ADD DESCRIPTION OF ITEM." << endl;
        }

        if ((userKeyword.compare("old") == 0)
            || (userKeyword.compare("fashioned") == 0)
            || (userKeyword.compare("grandfather") == 0)
            || (userKeyword.compare("clock") == 0)) {
            cout << "\nGrandfather Clock:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "FIXME: ADD DESCRIPTION OF ITEM." << endl;
        }

        if ((userKeyword.compare("wooden") == 0)
            || (userKeyword.compare("chests") == 0)) {
            cout << "\nWooden Chests:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "FIXME: ADD DESCRIPTION OF ITEM." << endl;
        }

        if ((userKeyword.compare("ms.") == 0)
            || (userKeyword.compare("sous") == 0)
            || (userKeyword.compare("chef") == 0)
            || (userKeyword.compare("sue") == 0)
            || (userKeyword.compare("davis") == 0)) {
            questioning_souschef(roomNum, currentUserChoices, clueList);
        }
        break;

    case 4:

        if ((userKeyword.compare("tall") == 0)
            || (userKeyword.compare("wooden") == 0)
            || (userKeyword.compare("bookcases") == 0)) {
            cout << "\nTall Wooden Bookcases:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "There are more books on these shelves than you could read in a lifetime." << endl;
            cout << "However, the shelves are all quite dirty, and there's nothing in the few clean spots you find." << endl;
            cout << "It seems unlikely that someone hid anything here." << endl;
        }

        if ((userKeyword.compare("antique") == 0)
            || (userKeyword.compare("fireplace") == 0)) {
            cout << "\nAntique Fireplace:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "This would certainly be the first place a guilty party would get rid of evidence." << endl;
            cout << "Thankfully, however, it seems recently lit." << endl;
            cout << "Since it was likely started after Pendleton arrived, it's probably not of importance." << endl;
        }

        if ((userKeyword.compare("large") == 0)
            || (userKeyword.compare("granite") == 0)
            || (userKeyword.compare("chunks") == 0)) {
            cout << "\nLarge Granite Chunks:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "Just more proof of Dr. Stronghold's influence." << endl;
            cout << "He must've had them delivered from the coal mine..." << endl;
            cout << "Well, with all of his donations he's certainly a saint in the eyes of the mining townsfolk." << endl;
        }

        if ((userKeyword.compare("mrs.") == 0)
            || (userKeyword.compare("stronghold") == 0)
            || (userKeyword.compare("diane") == 0)) {
            questioning_mrsstronghold (roomNum, currentUserChoices, clueList);
        }
        break;

    case 5:

        if ((userKeyword.compare("creaky") == 0)
            || (userKeyword.compare("door") == 0)) {
            cout << "\nCreaky Door:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "FIXME: ADD DESCRIPTION OF ITEM." << endl;
        }

        if ((userKeyword.compare("stovetop") == 0)
            || (userKeyword.compare("stove") == 0)
            || (userKeyword.compare("oven") == 0)) {
            cout << "\nStovetop Oven:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "FIXME: ADD DESCRIPTION OF ITEM." << endl;
        }

        if ((userKeyword.compare("stainless") == 0)
            || (userKeyword.compare("steel") == 0)
            || (userKeyword.compare("sink") == 0)) {
            cout << "\nStainless Steel Sink:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "Dirty plates and silverware fill the sink." << endl;
            cout << "They're so gaudy you could probably sell one fork for a lot of money." << endl;
        }

        if (userKeyword.compare("cupboards") == 0) {
            cout << "\nCupboards:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "FIXME: ADD DESCRIPTION OF ITEM." << endl;
        }

        if ((userKeyword.compare("knife") == 0)
            || (userKeyword.compare("block") == 0)
            || (userKeyword.compare("knives") == 0)) {
            cout << "\nKnife Block:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "A block of different sized knives." << endl;
            cout << "Next to it is a basket full of spoons and forks." << endl;
            cout << "One knife is missing from the end of the block." << endl;
        }

        if ((userKeyword.compare("basket") == 0)
            || (userKeyword.compare("kitchen") == 0)
            || (userKeyword.compare("utensils") == 0)) {
            cout << "\nKitchen Utensils Basket:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "FIXME: ADD DESCRIPTION OF ITEM." << endl;
        }

        if ((userKeyword.compare("hors") == 0)
            || (userKeyword.compare("d'oeuvres") == 0)
            || (userKeyword.compare("tray") == 0)) {
            cout << "\nHors D'oeuvres Tray:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "FIXME: ADD DESCRIPTION OF ITEM." << endl;
        }
        break;

    case 6:

        if ((userKeyword.compare("elegant") == 0)
            || (userKeyword.compare("diamond") == 0)
            || (userKeyword.compare("chandelier") == 0)) {
            cout << "\nDiamond Chandelier: " << endl;
            cout << "----------------------------------------" << endl;
            cout << "You feel like if this chandelier fell on you, your hospital bills would cost less than replacing it." << endl;
        }

        if ((userKeyword.compare("ornate") == 0)
            || (userKeyword.compare("dining") == 0)
            || (userKeyword.compare("table") == 0)) {
            cout << "\nOrnate Dining Table: " << endl;
            cout << "----------------------------------------" << endl;
            cout << "Two black stone vases rest near the table's center, offsetting its intricate white surface." << endl;
            cout << "Some Red Dianthus flowers poke out from within them." << endl;
        }

        if ((userKeyword.compare("red velvet chairs") == 0)
            || (userKeyword.compare("velvet chairs") == 0)
            || (userKeyword.compare("chairs") == 0)) {
            cout << "\nRed Velvet Chairs: " << endl;
            cout << "----------------------------------------" << endl;
            cout << "You stand beside the chair " << get_character_name(DRSTRONGHOLD) << " used." << endl;
            cout << "You wonder how the conversation went at dinner." << endl;
            cout << "But then you think about what Clyde told you earlier." << endl;
            cout << "Clyde said that including the mining town's mayor and wife, eight people were here for dinner." << endl;
            cout << "However... there's only seven chairs. You should ask around about that." << endl;
        }
        break;

    case 7:

        if ((userKeyword.compare("shelves") == 0)
            || (userKeyword.compare("potted") == 0)
            || (userKeyword.compare("plants") == 0)) {
            cout << "\nPotted Flowers:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "FIXME: ADD DESCRIPTION OF ITEM." << endl;
        }
        if ((userKeyword.compare("red") == 0)
            || (userKeyword.compare("dianthus") == 0)) {
            cout << "\nRed Dianthus Flowers:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "FIXME: ADD DESCRIPTION OF ITEM." << endl;
        }

        if ((userKeyword.compare("blue") == 0)
            || (userKeyword.compare("lobelias") == 0)) {
            cout << "\nBlue Lobelias:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "FIXME: ADD DESCRIPTION OF ITEM." << endl;
        }

        if ((userKeyword.compare("belladonna") == 0)
            || (userKeyword.compare("nightshades") == 0)) {
            cout << "\nBelladonna Nightshades:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "The flowers of the belladonna are in bloom." << endl;
            cout << "Dead leaves cover the soil." << endl;
            cout << "Some of the stems appear to be cut recently." << endl;
        }


        if ((userKeyword.compare("sky") == 0)
            || (userKeyword.compare("skylight") == 0)) {
            cout << "\nSkylight:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "FIXME: ADD DESCRIPTION OF ITEM." << endl;
        }


        if ((userKeyword.compare("gardening") == 0)
            || (userKeyword.compare("tools") == 0)) {
            cout << "\nGardening Tools:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "FIXME: ADD DESCRIPTION OF ITEM." << endl;
        }
        if (userKeyword.compare("shovel") == 0) {
            cout << "\nShovel:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "A rusty shovel sits against the bag of fertilizer." << endl;
            cout << "The handle is splintered from years of wear." << endl;
        }
        if ((userKeyword.compare("watering") == 0)
            || (userKeyword.compare("can") == 0)) {
            cout << "\nWatering Can:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "The watering can is half full." << endl;
            cout << "The water's surface is littered with dead bugs." << endl;
        }
        if (userKeyword.compare("fertilizer") == 0) {
            cout << "\nFertilizer:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "The fertilizer is sitting in the corner of the room." << endl;
            cout << "The top is sealed and the bag looks to be about half empty." << endl;
        }

        if (userKeyword.compare("logs") == 0) {
            cout << "\nShovel:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "FIXME: ADD DESCRIPTION OF ITEM." << endl;
        }

        if ((userKeyword.compare("mr.") == 0)
            || (userKeyword.compare("wine") == 0)
            || (userKeyword.compare("crafter") == 0)
            || (userKeyword.compare("louis") == 0)
            || (userKeyword.compare("arbert") == 0)) {
            questioning_winecrafter(roomNum, currentUserChoices, clueList);
        }
        break;

    case 8:

        if ((userKeyword.compare("aged") == 0)
            || (userKeyword.compare("bathroom") == 0)) {
            cout << "\nAged Bathroom:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "FIXME: ADD DESCRIPTION OF ITEM." << endl;
        }

        if ((userKeyword.compare("worn") == 0)
            || (userKeyword.compare("red") == 0)
            || (userKeyword.compare("carpet") == 0)) {
            cout << "\nWorn Red Carpet:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "FIXME: ADD DESCRIPTION OF ITEM." << endl;
        }
        if ((userKeyword.compare("small") == 0)
            || (userKeyword.compare("button") == 0)) {
            cout << "\nSmall Button:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "You pick up the button and see that it is red and scratched." << endl;
            cout << "Some fabric hangs out of the holes." << endl;
        }

        if ((userKeyword.compare("globe") == 0)
            || (userKeyword.compare("light") == 0)
            || (userKeyword.compare("lights") == 0)) {
            cout << "\nLights:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "Small lights line the walls." << endl;
            cout << "Dust and cobwebs cover their star shaped tops." << endl;
        }
        break;

    case 9:

        if ((userKeyword.compare("wine") == 0)
            || (userKeyword.compare("bottles") == 0)) {
            cout << "\nIt's too dark in here to investigate at the moment." << endl;
        }

        if ((userKeyword.compare("ceiling") == 0)
            || (userKeyword.compare("fixtures") == 0)) {
            cout << "\nCeiling Fixtures:" << endl;
            cout << "These don't seem relevant to the case. They look pretty though, like little firebugs." << endl;
        }

        if ((userKeyword.compare("flashlight") == 0)
            && currentUserChoices.at(FINDFLASHLIGHT) == true) {
            cout << "\nYou can see the Wine Cellar rather clearly now:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "While the bottles on the shelves seem unopened, something you couldn't see before pops out at you." << endl;
            cout << "In the back of the room, there's a glass display for a wine bottle, labeled \"Alain Hudelot\"." << endl;
            cout << "However, there's no bottle of wine inside." << endl;
            cout << "Hmm... That's peculiar." << endl;
        }

        if (((userKeyword.compare("uv") == 0)
            || (userKeyword.compare("light") == 0))
            && currentUserChoices.at(FINDUVLIGHT) == true) {
            cout << "\nYou were right to use the Astronomer's UV Light here:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "On the floor by the glass display case, there are several spurts of blood." << endl;
            cout << "Getting closer, you smell a hint of bleach. Someone's cleaned the floor here recently." << endl;
        }
        break;

    case 10:

        if (userKeyword.compare("heater") == 0) {
            cout << "\nHeater:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "You take a moment to enjoy the room's warmth. The heat doesn't seem to carry well upstairs." << endl;
        }

        if ((userKeyword.compare("garbage") == 0)
            || (userKeyword.compare("bin") == 0)) {
            cout << "\nGarbage Bin:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "The smell here is rather atrocious. Half a dozen black bags are stacked up inside." << endl;
            cout << "Hmm... That's odd. A small piece of glass is laying on one of the bags." << endl;
            cout << "Shifting the bags around, you find larger shards of glass beneath them." << endl;
            cout << "Someone definitely tried to hide this glass at the bottom of the bin... but why?" << endl;
        }

        if ((userKeyword.compare("hanging") == 0)
            || (userKeyword.compare("light") == 0)
            || (userKeyword.compare("lightbulb") == 0)) {
            cout << "\nHanging Lightbulb:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "You take a moment to enjoy the room's warmth. The heat doesn't seem to carry well upstairs." << endl;
        }

        if ((userKeyword.compare("breaker box") == 0)
            || (userKeyword.compare("breaker") == 0)
            || (userKeyword.compare("box") == 0)) {
            cout << "\nBreaker Box:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "Clyde told you that the power was turned off around the time of the murder." << endl;
            cout << "There doesn't seem to be any mechanism to turn off the power in advance though." << endl;
            cout << "That means whoever turned off the mansion's lights had to be in this room around the time of the murder." << endl;
        }

        if ((userKeyword.compare("mud") == 0)
            || (userKeyword.compare("man") == 0)) {
            questioning_mudman(roomNum, currentUserChoices, clueList);
        }
        break;

    case 11:

        if ((userKeyword.compare("gigantic") == 0)
            || (userKeyword.compare("telescope") == 0)) {
            cout << "\nTelescope:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "It's a beautiful mechanical device with too many parts to count." << endl;
            cout << "(FIXME: CREATE NAME) ASTROPHYSICIST/ARCHEOLOGIST walks up to you." << endl;
            cout << "\"Unfortunately there are too many clouds to view the stars tonight.\"" << endl;
            cout << "\"Dr.Armstrong always loved show the sky off to his visitors. I wish I could show you Saturn." << endl;
            cout << "She smiles wistfully. \"It was his favorite planet. He loved how unique it was.\"" << endl;
        }

        if ((userKeyword.compare("little") == 0)
            || (userKeyword.compare("statues") == 0)) {
            cout << "\nAstronomy Displays:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "Three gorgeous statues have been placed behind glass for your viewing pleasure." << endl;
            cout << "One represents the solar system, another is built to resemble the sun, and the last is a representation of a black hole." << endl;
        }
        if ((userKeyword.compare("solar") == 0)
            || (userKeyword.compare("system") == 0)) {
            //Empties console screen
            system("CLS");
            cout << "You read the Solar System exhibit's plaque:" << endl;
            cout << "----------------------------------------" << endl;
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
            //Empties console screen
            system("CLS");
            cout << "You read the Sun exhibit's plaque:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "\"The sun is a burning passion we all share.\"" << endl;
            cout << "Without it there would be no life, and yet one day the stars will extinguish all." << endl;
            cout << "It is a reminder that all life is temporary and magic.\"" << endl;

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
            //Empties console screen
            system("CLS");
            cout << "You read the Black Hole exhibit's plaque:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "\"A black hole is everything we fear we cannot see." << endl;
            cout << "It is the desire that holds us back and the silent anger that stabs our hearts." << endl;
            cout << "It is a reminder that we can always create more light, and that our work is never done.\"" << endl;

            type_and_continue();

            cout << "\nAt the bottom of the plaque there is a quote by Sir Martin Rees:" << endl;
            cout << "\"Inside every black hole that collapses may lie the seeds of a new expanding universe.\"" << endl;

        }

        if ((userKeyword.compare("lab") == 0)
            || (userKeyword.compare("area") == 0)
            || (userKeyword.compare("scientific") == 0)
            || (userKeyword.compare("tools") == 0)
            || (userKeyword.compare("experiments") == 0)) {
            cout << "\nLab Area:" << endl;
            cout << "Luckily for you, Clyde's cleared out this area with the junior detectives already." << endl;
            cout << "The tools and experiments weren't touched tonight, so there's not anything of interest here." << endl;
        }

        if ((userKeyword.compare("dr.") == 0)
            || (userKeyword.compare("astronomer") == 0)
            || (userKeyword.compare("jill") == 0)
            || (userKeyword.compare("tyson") == 0)) {
            questioning_astronomer(roomNum, currentUserChoices, clueList);
        }
        break;

    case 12:

        if ((userKeyword.compare("mr.") == 0)
            || (userKeyword.compare("stronghold's") == 0)
            || (userKeyword.compare("stronghold") == 0)
            || (userKeyword.compare("nathan") == 0)
            || (userKeyword.compare("body") == 0)) {
            cout << "\n" << get_character_name(DRSTRONGHOLD) << "'s Body: " << endl;
            cout << "----------------------------------------" << endl;
            cout << "Standing directly over the dead body, it is clear that the victim's throat was slashed." << endl;
            cout << "That was his cause of death on Clyde's report." << endl;
            cout << "However, you can't help but notice how sickly pale Mr. Stronghold's face has become." << endl;
            cout << "Peering closer, you notice something startling. There seems to be some foam in his mouth." << endl;
            cout << "What could this mean?" << endl;
        }

        if ((userKeyword.compare("lavish") == 0)
            || (userKeyword.compare("blood") == 0)
            || (userKeyword.compare("stained") == 0)
            || (userKeyword.compare("bed") == 0)) {
            cout << "\nBlood Stained Bed: " << endl;
            cout << "----------------------------------------" << endl;
            cout << "Looking more carefully at the bed " << get_character_name(DRSTRONGHOLD, INFORMAL) << "may have died in, you notice the edge of garment poking out from under the bed." << endl;
            cout << "It seems to be a pair of pajamas... with some blood on the sleeves." << endl;
        }

        if ((userKeyword.compare("victorian") == 0)
            || (userKeyword.compare("era") == 0)
            || (userKeyword.compare("armoires") == 0)
            || (userKeyword.compare("armoire") == 0)) {
            cout << "\nVictorian Era Armoires: " << endl;
            cout << "----------------------------------------" << endl;
            cout << "Even though you normally wouldn't give a second thought to a victim's clothing closet, you decide taking a look inside the Strongholds' armoires might give good insight." << endl;
            cout << "Inside Mr. Stronghold's armoire, you find a pair of snow boots, still wet from trecking through snow." << endl;
            cout << "There had been a big snowstorm the night of the murder, so this didn't seem particularly strange to you, but what was Mr. Stronghold doing outside in such bad weather?" << endl;
            cout << "As you rumage through the rest of Mr. Stronghold's clothing, a small sparkling object catches your eye." << endl;
            cout << "You pick up the object, and realize it is a small, yet elegent, diamond earing. What would Mr. Stronghold be doing with a diamond earing in his armoire?" << endl;
            cout << "Mrs. Stronghold's armoire yeilds no significant evidence." << endl;
        }

        if (userKeyword.compare("tub") == 0) {
            cout << "\nGiant Tub: " << endl;
            cout << "----------------------------------------" << endl;
            cout << "The tub's still full from " << get_character_name(MRSSTRONGHOLD) << "'s bath." << endl;
            cout << "Some rose scented candles rest nearby. It looks like they've been put out." << endl;
        }

        if ((userKeyword.compare("glamorous") == 0)
            || (userKeyword.compare("vanity") == 0)
            || (userKeyword.compare("vanities") == 0)) {
            cout << "\nBathroom Vanity: " << endl;
            cout << "----------------------------------------" << endl;
            cout << "The vanities seem relatively untouched, but when you grow close to them, the smell of lavender overwhelms your nose." << endl;
            cout << "It's a nice escape from death, but it's peculiar." << endl;
            cout << "You find that the scent is strongest on " << get_character_name(MRSSTRONGHOLD) << "'s side." << endl;
            cout << "It seems to be coming from the sink under her vanity... which is wet and sparkling clean." << endl;
            cout << "Did Mrs. Stronghold clean her sink recently?" << endl;
        }

        if ((userKeyword.compare("golden") == 0)
            || (userKeyword.compare("toilet") == 0)) {
            cout << "\nGolden Toilet: " << endl;
            cout << "----------------------------------------" << endl;
            cout << "If you stole this toilet you could probably buy yourself a new house." << endl;
            cout << "If only " << get_character_name(CLYDE, INFORMAL) << "was a little less respectful of the rules." << endl;
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



void questioning_clyde(int roomNum, vector<bool>& currentUserChoices, vector<string>& clueList) {

    //Empties console screen
    system("CLS");

    print_character_questioning_title(roomNum);
    cout << "As you approach him, he smiles at you with confidence." << endl;
    cout << "\"Hello, Detective. What do you need?\"" << endl;
    print_pendleton_help_request(roomNum);
    string userKeyword = get_keyword_input();

    //FIXME: REMOVE INPUT PRINTER WHEN GAME IS FINISHED
    while (userKeyword.compare("stop") != 0) {
        
        //Don't forget quotes when they speak
        if (userKeyword.compare("1") == 0) {
            cout << "FIXME: ADD CASE FILE EXPLANATION" << endl;
            type_and_continue();
        }
        if (userKeyword.compare("2") == 0) {
            cout << "FIXME: ADD INVESTIGATION EXPLANATION" << endl;
            type_and_continue();
        }
        if (userKeyword.compare("3") == 0) {
            cout << "FIXME: ADD CHARACTER QUESTIONING EXPLANATION" << endl;
            type_and_continue();
        }
        if (userKeyword.compare("4") == 0) {
            cout << "FIXME: EXPLAIN THAT SAVES DON'T WORK RIGHT NOW" << endl;
            type_and_continue();
        }
        if (userKeyword.compare("5") == 0) {
            cout << "FIXME: EXPLAIN HOW THE ENDING WORKS WHEN IT'S FINISHED" << endl;
            type_and_continue();
        }
        if (userKeyword.compare("interrogate") == 0) {

            //Empties console screen
            system("CLS");
            print_interrogation_request(roomNum, clueList);
            userKeyword = get_keyword_input();

            while (userKeyword.compare("end") != 0) {

                if (((userKeyword.compare("case") == 0)
                    || (userKeyword.compare("file") == 0))
                    && ((clueList.at(CASEFILE)).compare("???") != 0)) {
                    cout << "FIXME: ADD CHARACTER RESPONSE TO CASEFILE'S CONTENTS." << endl;
                    type_and_continue();
                }
                if (((userKeyword.compare("expense") == 0)
                    || (userKeyword.compare("reports") == 0)
                    || (userKeyword.compare("report") == 0))
                    && ((clueList.at(EXPENSEREPORTS)).compare("???") != 0)) {
                    cout << "FIXME: ADD CHARACTER RESPONSE TO EXPENSEREPORTS' CONTENTS." << endl;
                    type_and_continue();
                }
                if (((userKeyword.compare("small") == 0)
                    || (userKeyword.compare("safe") == 0))
                    && ((clueList.at(SMALLSAFE)).compare("???") != 0)) {
                    cout << "FIXME: ADD CHARACTER RESPONSE TO SMALLSAFE'S CONTENTS." << endl;
                    type_and_continue();
                }
                if (((userKeyword.compare("insurance") == 0)
                    || (userKeyword.compare("policy") == 0))
                    && ((clueList.at(INSURANCEPOLICY)).compare("???") != 0)) {
                    cout << "FIXME: ADD CHARACTER RESPONSE TO INSURANCEPOLICY'S CONTENTS." << endl;
                    type_and_continue();
                }
                if (((userKeyword.compare("late") == 0)
                    || (userKeyword.compare("check") == 0))
                    && ((clueList.at(LATECHECK)).compare("???") != 0)) {
                    cout << "FIXME: ADD CHARACTER RESPONSE TO THIS LATECHECK'S CONTENTS." << endl;
                    type_and_continue();
                }
                if (((userKeyword.compare("anonymous") == 0)
                    || (userKeyword.compare("letter") == 0))
                    && ((clueList.at(ANONYMOUSLETTER)).compare("???") != 0)) {
                    cout << "FIXME: ADD CHARACTER RESPONSE TO ANONYMOUSLETTER'S CONTENTS." << endl;
                    type_and_continue();
                }
                if (((userKeyword.compare("locked") == 0)
                    || (userKeyword.compare("chests") == 0)
                    || (userKeyword.compare("chest") == 0))
                    && ((clueList.at(LOCKEDCHESTS)).compare("???") != 0)) {
                    cout << "FIXME: ADD CHARACTER RESPONSE TO LOCKEDCHESTS' CONTENTS." << endl;
                    type_and_continue();
                }
                if (((userKeyword.compare("missing") == 0)
                    || (userKeyword.compare("knife") == 0))
                    && ((clueList.at(MISSINGKNIFE)).compare("???") != 0)) {
                    cout << "FIXME: ADD CHARACTER RESPONSE TO MISSINGKNIFE'S CONTENTS." << endl;
                    type_and_continue();
                }
                if (((userKeyword.compare("red") == 0)
                    || (userKeyword.compare("velvet") == 0)
                    || (userKeyword.compare("chairs") == 0)
                    || (userKeyword.compare("chair") == 0))
                    && ((clueList.at(REDVELVETCHAIRS)).compare("???") != 0)) {
                    cout << "FIXME: ADD CHARACTER RESPONSE TO REDVELVETCHAIR'S CONTENTS." << endl;
                    type_and_continue();
                }
                if (((userKeyword.compare("cut") == 0)
                    || (userKeyword.compare("night") == 0)
                    || (userKeyword.compare("shade") == 0)
                    || (userKeyword.compare("nightshade") == 0))
                    && ((clueList.at(CUTNIGHTSHADE)).compare("???") != 0)) {
                    cout << "FIXME: ADD CHARACTER RESPONSE TO CUTNIGHTSHADE'S CONTENTS." << endl;
                    type_and_continue();
                }
                if (((userKeyword.compare("small") == 0)
                    || (userKeyword.compare("button") == 0))
                    && ((clueList.at(SMALLBUTTON)).compare("???") != 0)) {
                    cout << "FIXME: ADD CHARACTER RESPONSE TO SMALLBUTTON'S CONTENTS." << endl;
                    type_and_continue();
                }
                if (((userKeyword.compare("empty") == 0)
                    || (userKeyword.compare("display") == 0))
                    && ((clueList.at(EMPTYDISPLAY)).compare("???") != 0)) {
                    cout << "FIXME: ADD CHARACTER RESPONSE TO EMPTYDISPLAY'S CONTENTS." << endl;
                    type_and_continue();
                }
                if (((userKeyword.compare("blood") == 0)
                    || (userKeyword.compare("stains") == 0)
                    || (userKeyword.compare("stain") == 0))
                    && ((clueList.at(BLOODSTAINS)).compare("???") != 0)) {
                    cout << "FIXME: ADD CHARACTER RESPONSE TO BLOODSTAINS' CONTENTS." << endl;
                    type_and_continue();
                }
                if (((userKeyword.compare("cleaned") == 0)
                    || (userKeyword.compare("floor") == 0))
                    && ((clueList.at(CLEANEDFLOOR)).compare("???") != 0)) {
                    cout << "FIXME: ADD CHARACTER RESPONSE TO CLEANEDFLOOR'S CONTENTS." << endl;
                    type_and_continue();
                }
                if (((userKeyword.compare("glass") == 0)
                    || (userKeyword.compare("shards") == 0)
                    || (userKeyword.compare("shard") == 0))
                    && ((clueList.at(GLASSSHARDS)).compare("???") != 0)) {
                    cout << "FIXME: ADD CHARACTER RESPONSE TO GLASSSHARDS' CONTENTS." << endl;
                    type_and_continue();
                }
                if (((userKeyword.compare("broken") == 0)
                    || (userKeyword.compare("lock") == 0))
                    && ((clueList.at(BROKENLOCK)).compare("???") != 0)) {
                    cout << "FIXME: ADD CHARACTER RESPONSE TO BROKENLOCK'S CONTENTS." << endl;
                    type_and_continue();
                }
                if (((userKeyword.compare("slashed") == 0)
                    || (userKeyword.compare("throat") == 0))
                    && ((clueList.at(SLASHEDTHROAT)).compare("???") != 0)) {
                    cout << "FIXME: ADD CHARACTER RESPONSE TO SLASHEDTHROAT'S CONTENTS." << endl;
                    type_and_continue();
                }
                if (((userKeyword.compare("foamed") == 0)
                    || (userKeyword.compare("mouth") == 0))
                    && ((clueList.at(FOAMEDMOUTH)).compare("???") != 0)) {
                    cout << "FIXME: ADD CHARACTER RESPONSE TO FOAMEDMOUTH'S CONTENTS." << endl;
                    type_and_continue();
                }
                if (((userKeyword.compare("bloody") == 0)
                    || (userKeyword.compare("garment") == 0))
                    && ((clueList.at(BLOODYGARMENT)).compare("???") != 0)) {
                    cout << "FIXME: ADD CHARACTER RESPONSE TO BLOODGARMENT'S CONTENTS." << endl;
                    type_and_continue();
                }
                if (((userKeyword.compare("wet") == 0)
                    || (userKeyword.compare("boots") == 0))
                    && ((clueList.at(WETBOOTS)).compare("???") != 0)) {
                    cout << "FIXME: ADD CHARACTER RESPONSE TO WETBOOTS' CONTENTS." << endl;
                    type_and_continue();
                }
                if (((userKeyword.compare("earring") == 0))
                    && ((clueList.at(EARRING)).compare("???") != 0)) {
                    cout << "FIXME: ADD CHARACTER RESPONSE TO EARRING'S CONTENTS." << endl;
                    type_and_continue();
                }
                if (((userKeyword.compare("washed") == 0)
                    || (userKeyword.compare("sink") == 0))
                    && ((clueList.at(WASHEDSINK)).compare("???") != 0)) {
                    cout << "FIXME: ADD CHARACTER RESPONSE TO WASHEDSINK'S CONTENTS." << endl;
                    type_and_continue();
                }
                if (((userKeyword.compare("snowy") == 0)
                    || (userKeyword.compare("foot") == 0)
                    || (userKeyword.compare("prints") == 0)
                    || (userKeyword.compare("footprints") == 0))
                    && ((clueList.at(SNOWYFOOTPRINTS)).compare("???") != 0)) {
                    cout << "FIXME: ADD CHARACTER RESPONSE TO SNOWYFOOTPRINTS' CONTENTS." << endl;
                    type_and_continue();
                }

                //Empties console screen
                system("CLS");
                print_input(userKeyword);
                print_interrogation_request(roomNum, clueList);
                userKeyword = get_keyword_input();
            }

        }

        //Empties console screen
        system("CLS");
        print_input(userKeyword);
        print_questioning_request(roomNum);
        userKeyword = get_keyword_input();
    }

}

void questioning_butler(int roomNum, vector<bool>& currentUserChoices, vector<string>& clueList) {

    //Empties console screen
    system("CLS");

    print_character_questioning_title(roomNum);
    cout << "As you approach him, he bows to you with great fervor." << endl;
    cout << "\"Hello, Detective. I can be at your service whenever you wish.\"" << endl;
    print_questioning_request(roomNum);
    string userKeyword = get_keyword_input();

    //FIXME: REMOVE INPUT PRINTER WHEN GAME IS FINISHED
    while (userKeyword.compare("stop") != 0) {

        //Don't forget quotes when they speak
        if (userKeyword.compare("1") == 0) {
            cout << "FIXME: ADD CHARACTER'S INTRODUCTION" << endl;
            type_and_continue();
        }
        if (userKeyword.compare("2") == 0) {
            cout << "FIXME: ADD CHARACTER'S WHEREABOUTS AFTER THE DINNER" << endl;
            type_and_continue();
        }
        if (userKeyword.compare("3") == 0) {
            cout << "FIXME: ADD CHARACTER'S SUSPICIONS ABOUT OTHERS" << endl;
            type_and_continue();
        }
        if (userKeyword.compare("interrogate") == 0) {

            //Empties console screen
            system("CLS");
            print_interrogation_request(roomNum, clueList);
            userKeyword = get_keyword_input();

            while (userKeyword.compare("end") != 0) {

                if (((userKeyword.compare("case") == 0)
                    || (userKeyword.compare("file") == 0))
                    && ((clueList.at(CASEFILE)).compare("???") != 0)) {
                    cout << "FIXME: ADD CHARACTER RESPONSE TO CASEFILE'S CONTENTS." << endl;
                    type_and_continue();
                }

                //Empties console screen
                system("CLS");
                print_input(userKeyword);
                print_interrogation_request(roomNum, clueList);
                userKeyword = get_keyword_input();
            }

        }

        //Empties console screen
        system("CLS");
        print_input(userKeyword);
        print_questioning_request(roomNum);
        userKeyword = get_keyword_input();
    }
}

void questioning_souschef(int roomNum, vector<bool>& currentUserChoices, vector<string>& clueList) {

    //Empties console screen
    system("CLS");

    print_character_questioning_title(roomNum);
    cout << "As you approach her, she kicks her feet against the covers." << endl;
    cout << "\"Hi there, Detective. I can answer some questions if you have any for me.\"" << endl;
    print_questioning_request(roomNum);
    string userKeyword = get_keyword_input();

    //FIXME: REMOVE INPUT PRINTER WHEN GAME IS FINISHED
    while (userKeyword.compare("stop") != 0) {

        //Don't forget quotes when they speak
        if (userKeyword.compare("1") == 0) {
            cout << "FIXME: ADD CHARACTER'S INTRODUCTION" << endl;
            type_and_continue();
        }
        if (userKeyword.compare("2") == 0) {
            cout << "FIXME: ADD CHARACTER'S WHEREABOUTS AFTER THE DINNER" << endl;
            type_and_continue();
        }
        if (userKeyword.compare("3") == 0) {
            cout << "FIXME: ADD CHARACTER'S SUSPICIONS ABOUT OTHERS" << endl;
            type_and_continue();
        }
        if (userKeyword.compare("interrogate") == 0) {

            //Empties console screen
            system("CLS");
            print_interrogation_request(roomNum, clueList);
            userKeyword = get_keyword_input();

            while (userKeyword.compare("end") != 0) {

                if (((userKeyword.compare("case") == 0)
                    || (userKeyword.compare("file") == 0))
                    && ((clueList.at(CASEFILE)).compare("???") != 0)) {
                    cout << "FIXME: ADD CHARACTER RESPONSE TO CASEFILE'S CONTENTS." << endl;
                    type_and_continue();
                }

                //Empties console screen
                system("CLS");
                print_input(userKeyword);
                print_interrogation_request(roomNum, clueList);
                userKeyword = get_keyword_input();
            }

        }

        //Empties console screen
        system("CLS");
        print_input(userKeyword);
        print_questioning_request(roomNum);
        userKeyword = get_keyword_input();
    }

}

void questioning_mrsstronghold(int roomNum, vector<bool>& currentUserChoices, vector<string>& clueList) {

    //Empties console screen
    system("CLS");

    print_character_questioning_title(roomNum);
    cout << "As you approach her, she taps her fountain pen on the page blankly." << endl;
    cout << "\"I don't suppose you're just going to stand there, are you?\"" << endl;
    print_questioning_request(roomNum);
    string userKeyword = get_keyword_input();

    //FIXME: REMOVE INPUT PRINTER WHEN GAME IS FINISHED
    while (userKeyword.compare("stop") != 0) {

        //Don't forget quotes when they speak
        if (userKeyword.compare("1") == 0) {
            cout << "FIXME: ADD CHARACTER'S INTRODUCTION" << endl;
            type_and_continue();
        }
        if (userKeyword.compare("2") == 0) {
            cout << "FIXME: ADD CHARACTER'S WHEREABOUTS AFTER THE DINNER" << endl;
            type_and_continue();
        }
        if (userKeyword.compare("3") == 0) {
            cout << "FIXME: ADD CHARACTER'S SUSPICIONS ABOUT OTHERS" << endl;
            type_and_continue();
        }
        if (userKeyword.compare("interrogate") == 0) {

            //Empties console screen
            system("CLS");
            print_interrogation_request(roomNum, clueList);
            userKeyword = get_keyword_input();

            while (userKeyword.compare("end") != 0) {

                if (((userKeyword.compare("case") == 0)
                    || (userKeyword.compare("file") == 0))
                    && ((clueList.at(CASEFILE)).compare("???") != 0)) {
                    cout << "FIXME: ADD CHARACTER RESPONSE TO CASEFILE'S CONTENTS." << endl;
                    type_and_continue();
                }

                //Empties console screen
                system("CLS");
                print_input(userKeyword);
                print_interrogation_request(roomNum, clueList);
                userKeyword = get_keyword_input();
            }

        }

        //Empties console screen
        system("CLS");
        print_input(userKeyword);
        print_questioning_request(roomNum);
        userKeyword = get_keyword_input();
    }

}

void questioning_winecrafter(int roomNum, vector<bool>& currentUserChoices, vector<string>& clueList) {

    //Empties console screen
    system("CLS");

    print_character_questioning_title(roomNum);
    cout << "As you approach him, he drops a handful of grapes into a nearby bucket." << endl;
    cout << "\"Question me, but be quick. Grapes aren't in season forever.\"" << endl;
    print_questioning_request(roomNum);
    string userKeyword = get_keyword_input();

    //FIXME: REMOVE INPUT PRINTER WHEN GAME IS FINISHED
    while (userKeyword.compare("stop") != 0) {

        //Don't forget quotes when they speak
        if (userKeyword.compare("1") == 0) {
            cout << "FIXME: ADD CHARACTER'S INTRODUCTION" << endl;
            type_and_continue();
        }
        if (userKeyword.compare("2") == 0) {
            cout << "FIXME: ADD CHARACTER'S WHEREABOUTS AFTER THE DINNER" << endl;
            type_and_continue();
        }
        if (userKeyword.compare("3") == 0) {
            cout << "FIXME: ADD CHARACTER'S SUSPICIONS ABOUT OTHERS" << endl;
            type_and_continue();
        }
        if (userKeyword.compare("interrogate") == 0) {

            //Empties console screen
            system("CLS");
            print_interrogation_request(roomNum, clueList);
            userKeyword = get_keyword_input();

            while (userKeyword.compare("end") != 0) {

                if (((userKeyword.compare("case") == 0)
                    || (userKeyword.compare("file") == 0))
                    && ((clueList.at(CASEFILE)).compare("???") != 0)) {
                    cout << "FIXME: ADD CHARACTER RESPONSE TO CASEFILE'S CONTENTS." << endl;
                    type_and_continue();
                }

                //Empties console screen
                system("CLS");
                print_input(userKeyword);
                print_interrogation_request(roomNum, clueList);
                userKeyword = get_keyword_input();
            }

        }

        //Empties console screen
        system("CLS");
        print_input(userKeyword);
        print_questioning_request(roomNum);
        userKeyword = get_keyword_input();
    }

}

void questioning_mudman(int roomNum, vector<bool>& currentUserChoices, vector<string>& clueList) {

    //Empties console screen
    system("CLS");

    print_character_questioning_title(roomNum);
    cout << "\"Mud. Mud mud mud.\"" << endl;
    print_questioning_request(roomNum);
    string userKeyword = get_keyword_input();

    //FIXME: REMOVE INPUT PRINTER WHEN GAME IS FINISHED
    while (userKeyword.compare("stop") != 0) {

        //Don't forget quotes when they speak
        if (userKeyword.compare("1") == 0) {
            cout << "FIXME: ADD CHARACTER'S INTRODUCTION" << endl;
            type_and_continue();
        }
        if (userKeyword.compare("2") == 0) {
            cout << "FIXME: ADD CHARACTER'S WHEREABOUTS AFTER THE DINNER" << endl;
            type_and_continue();
        }
        if (userKeyword.compare("3") == 0) {
            cout << "FIXME: ADD CHARACTER'S SUSPICIONS ABOUT OTHERS" << endl;
            type_and_continue();
        }
        if (userKeyword.compare("interrogate") == 0) {

            //Empties console screen
            system("CLS");
            print_interrogation_request(roomNum, clueList);
            userKeyword = get_keyword_input();

            while (userKeyword.compare("end") != 0) {

                if (((userKeyword.compare("case") == 0)
                    || (userKeyword.compare("file") == 0))
                    && ((clueList.at(CASEFILE)).compare("???") != 0)) {
                    cout << "FIXME: ADD CHARACTER RESPONSE TO CASEFILE'S CONTENTS." << endl;
                    type_and_continue();
                }

                //Empties console screen
                system("CLS");
                print_input(userKeyword);
                print_interrogation_request(roomNum, clueList);
                userKeyword = get_keyword_input();
            }

        }

        //Empties console screen
        system("CLS");
        print_input(userKeyword);
        print_questioning_request(roomNum);
        userKeyword = get_keyword_input();
    }

}

void questioning_astronomer(int roomNum, vector<bool>& currentUserChoices, vector<string>& clueList) {

    //Empties console screen
    system("CLS");

    print_character_questioning_title(roomNum);
    cout << "As you approach her, she sits down in a small chair beside the telescope." << endl;
    cout << "\"It's a shame that the stars aren't out tonight.\"" << endl;
    cout << "She sighs. \"What can I do for you?\"" << endl;
    print_questioning_request(roomNum);
    string userKeyword = get_keyword_input();

    //FIXME: REMOVE INPUT PRINTER WHEN GAME IS FINISHED
    while (userKeyword.compare("stop") != 0) {

        //Don't forget quotes when they speak
        if (userKeyword.compare("1") == 0) {
            cout << "FIXME: ADD CHARACTER'S INTRODUCTION" << endl;
            type_and_continue();
        }
        if (userKeyword.compare("2") == 0) {
            cout << "FIXME: ADD CHARACTER'S WHEREABOUTS AFTER THE DINNER" << endl;
            type_and_continue();
        }
        if (userKeyword.compare("3") == 0) {
            cout << "FIXME: ADD CHARACTER'S SUSPICIONS ABOUT OTHERS" << endl;
            type_and_continue();
        }
        if (userKeyword.compare("interrogate") == 0) {

            //Empties console screen
            system("CLS");
            print_interrogation_request(roomNum, clueList);
            userKeyword = get_keyword_input();

            while (userKeyword.compare("end") != 0) {

                if (((userKeyword.compare("case") == 0)
                    || (userKeyword.compare("file") == 0))
                    && ((clueList.at(CASEFILE)).compare("???") != 0)) {
                    cout << "FIXME: ADD CHARACTER RESPONSE TO CASEFILE'S CONTENTS." << endl;
                    type_and_continue();
                }

                //Empties console screen
                system("CLS");
                print_input(userKeyword);
                print_interrogation_request(roomNum, clueList);
                userKeyword = get_keyword_input();
            }

        }

        //Empties console screen
        system("CLS");
        print_input(userKeyword);
        print_questioning_request(roomNum);
        userKeyword = get_keyword_input();
    }

}



//Asks user what they want to investigate
void print_keyword_request(int roomNum) {
    cout << "\nWhat do you want to investigate in the " << get_room_name(roomNum) << "?" << endl;
    cout << "(Type \"leave\" to move between rooms.)" << endl;
}

//Asks user which room they want to enter
void print_new_room_request(int roomNum) {
    cout << "\nWhich room do you want to enter from the " << get_room_name(roomNum) << "?" << endl;
}

//Asks user what they want to question their suspect about
void print_questioning_request(int roomNum) {
    cout << "\nWhat do you want to ask?" << endl;
    cout << "----------------------------------------" << endl;

    cout << "\"1\": Would you care to introduce yourself?" << endl;
    cout << "\"2\": What did you do tonight after the dinner party?" << endl;
    cout << "\"3\": Do you think anyone else has a reason to kill " << get_character_name(DRSTRONGHOLD) << "?" << endl;

    cout << "\n(Type \"stop\" to stop questioning your suspect and return to your current room." << endl;
    cout << "Or, if you've asked this character all of the three questions above, you should try typing \"interrogate\"." << endl;
    cout << "This will allow you to ask them about any of the clues you've found so far that they may recognize.)" << endl;
}

void print_pendleton_help_request(int roomNum) {
    cout << "\nWhat do you want to ask?" << endl;
    cout << "----------------------------------------" << endl;

    cout << "\"1\": What's in the case file?" << endl;
    cout << "\"2\": How do I investigate objects?" << endl;
    cout << "\"2\": How do I question the suspects?" << endl;
    cout << "\"3\": How do I save?" << endl;
    cout << "\"3\": How do I end the game when I've figured out the killer?" << endl;

    cout << "\n(Type \"stop\" to stop questioning your suspect and return to your current room." << endl;
    cout << "Or, if you've asked this character all of the five questions above, you should try typing \"interrogate\"." << endl;
    cout << "This will allow you to ask them about any of the clues you've found so far that they may recognize.)" << endl;
}

//Asks user what clue they want to interrogate a suspect with
void print_interrogation_request(int roomNum, vector<string>& clueList) {
    cout << "Which clue do you want to use to interrogate " << get_character_name(roomNum) << "?" << endl;
    cout << "----------------------------------------" << endl;
    switch (roomNum) {
    case CLYDE:
        for (int i = 0; i < NUMCLUES; i++) {
            cout << clueList.at(i) << endl;
        }
    case BUTLER:
        cout << clueList.at(CASEFILE) << endl;
        break;
    case SOUSCHEF:
        cout << clueList.at(CASEFILE) << endl;
        break;
    case MRSSTRONGHOLD:
        cout << clueList.at(CASEFILE) << endl;
        break;
    case WINECRAFTER:
        cout << clueList.at(CASEFILE) << endl;
        break;
    case MUDMAN:
        cout << clueList.at(CASEFILE) << endl;
        break;
    case ASTRONOMER:
        cout << clueList.at(CASEFILE) << endl;
        break;
    }
    cout << "(Type \"end\" to end the interrogation with " << get_character_name(roomNum) << " and return to the character interaction menu.)" << endl;
}

string get_clue_name(int clueNumber, vector<string>& clueList) {
    return "FIXME: ADD LIST OF CLUES / INVENTORY SYSTEM";
}

//Prints name of characters associated with current roomNum
string get_character_name(int roomNum, int formality) {
    switch (roomNum) {

    case 0:
        if (formality == FORMAL) {
            return "Clyde Pendleton";
        }
        else {
            return "Clyde";
        }

    case 1:
        if (formality == FORMAL) {
            return "Mr. Gilmore";
        }
        else {
            return "Sebastian";
        }

    case 2:
        return "ROOM 2 N/A";

    case 3:
        if (formality == FORMAL) {
            return "Ms. Davis";
        }
        else {
            return "Sue";
        }

    case 4:
        if (formality == FORMAL) {
            return "Mrs. Stronghold";
        }
        else {
            return "Diane";
        }

    case 5:
        return "ROOM 5 N/A";

    case 6:
        return "ROOM 6 N/A";

    case 7:
        if (formality == FORMAL) {
            return "Mr. Arbert";
        }
        else {
            return "Louis";
        }

    case 8:
        return "ROOM 8 N/A";

    case 9:
        return "ROOM 9 N/A";

    case 10:
        if (formality == FORMAL) {
            return "Mud Man";
        }
        else {
            return "Mud Mud Mud";
        }

    case 11:
        if (formality == FORMAL) {
            return "Dr. Tyson";
        }
        else {
            return "Jill";
        }

    case 12:
        if (formality == FORMAL) {
            return "Dr. Stronghold";
        }
        else {
            return "Nathan";
        }

    case 13:
        return "ROOM 13 N/A";

    default:
        return "UNKNOWN ROOM N/A";
    }
}

void print_character_questioning_title(int roomNum) {
    cout << "You are questioning " << get_character_name(roomNum) << ":" << endl;
    cout << "----------------------------------------" << endl;
}



//Prints name of room associated with current roomNum when called
string get_room_name(int roomNum) {

    switch (roomNum) {

    case 0:
        return "Trophy Hall";

    case 1:
        return "Ballroom";

    case 2:
        return "Office";

    case 3:
        return "Servant's Quarters";

    case 4:
        return "Library";

    case 5:
        return "Kitchen";

    case 6:
        return "Dining Room";

    case 7:
        return "Greenhouse";

    case 8:
        return "Stairwell";

    case 9:
        return "Wine Cellar";

    case 10:
        return "Boiler Room";

    case 11:
        return "Observatory";

    case 12:
        return "Master Bedroom";

    case 13:
        return "ROOM 13 N/A";

    default:
        return "UNKNOWN ROOM N/A";
    }

}

//Prints a pretty title for each room when called
void print_room_title(int roomNum) {
    cout << "You are in the " << get_room_name(roomNum) << "." << endl;
    cout << "----------------------------------------" << endl;
}

//Prints the room names of all adjacent rooms associated with roomNum
void print_adjacent_rooms(int roomNum) {

    cout << "\nAdjacent Rooms: " << endl;

    switch (roomNum) {

    case 0:
        cout << "\"" << get_room_name(1) << "\"" << endl;
        break;

    case 1:
        cout << "\"" << get_room_name(0) << "\"" << endl;
        cout << "\"" << get_room_name(2) << "\"" << endl;
        cout << "\"" << get_room_name(3) << "\"" << endl; 
        cout << "\"" << get_room_name(4) << "\"" << endl;
        cout << "\"" << get_room_name(5) << "\"" << endl;
        cout << "\"" << get_room_name(6) << "\"" << endl;
        cout << "\"" << get_room_name(7) << "\"" << endl;
        cout << "\"" << get_room_name(8) << "\"" << endl;
        break;

    case 2:
        cout << "\"" << get_room_name(1) << "\"" << endl;
        cout << "\"" << get_room_name(3) << "\"" << endl;
        cout << "\"" << get_room_name(4) << "\"" << endl;
        break;

    case 3:
        cout << "\"" << get_room_name(1) << "\"" << endl;
        cout << "\"" << get_room_name(2) << "\"" << endl;
        cout << "\"" << get_room_name(4) << "\"" << endl;
        break;

    case 4:
        cout << "\"" << get_room_name(1) << "\"" << endl;
        cout << "\"" << get_room_name(2) << "\"" << endl;
        cout << "\"" << get_room_name(3) << "\"" << endl;
        break;

    case 5:
        cout << "\"" << get_room_name(1) << "\"" << endl;
        cout << "\"" << get_room_name(6) << "\"" << endl;
        cout << "\"" << get_room_name(7) << "\"" << endl;
        break;

    case 6:
        cout << "\"" << get_room_name(1) << "\"" << endl;
        cout << "\"" << get_room_name(5) << "\"" << endl;
        cout << "\"" << get_room_name(7) << "\"" << endl;
        break;

    case 7:
        cout << "\"" << get_room_name(1) << "\"" << endl;
        cout << "\"" << get_room_name(5) << "\"" << endl;
        cout << "\"" << get_room_name(6) << "\"" << endl;
        break;

    case 8:
        cout << "\nUPSTAIRS" << endl;
        cout << "----------------" << endl;
        cout << "\"" << get_room_name(11) << "\"" << endl;
        cout << "\"" << get_room_name(12) << "\"" << endl;

        cout << "\nGROUND FLOOR" << endl;
        cout << "----------------" << endl;
        cout << "\"" << get_room_name(1) << "\"" << endl;

        cout << "\nDOWNSTAIRS" << endl;
        cout << "--------------------" << endl;
        cout << "\"" << get_room_name(9) << "\"" << endl;
        cout << "\"" << get_room_name(10) << "\"" << endl;
        break;

    case 9:
        cout << "\"" << get_room_name(10) << "\"" << endl;
        cout << "\"" << get_room_name(8) << "\"" << endl;
        break;

    case 10:
        cout << "\"" << get_room_name(9) << "\"" << endl;
        cout << "\"" << get_room_name(8) << "\"" << endl;
        break;

    case 11:
        cout << "\"" << get_room_name(12) << "\"" << endl;
        cout << "\"" << get_room_name(8) << "\"" << endl;
        break;

    case 12:
        cout << "\"" << get_room_name(11) << "\"" << endl;
        cout << "\"" << get_room_name(8) << "\"" << endl;
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


