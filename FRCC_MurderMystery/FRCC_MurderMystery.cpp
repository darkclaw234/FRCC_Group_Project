// FRCC_MurderMystery.cpp : This is our murdery mystery project in its most basic form.

//Extra Comment

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <ctime>
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

void view_inventory(int roomNum, vector<bool>& currentUserChoices, vector<string>& clueList, string userKeyword);
void print_inventory_item_description(int itemNum, vector<bool>& currentUserChoices, vector<string>& clueList);

int count_clues(vector<string>& clueList);

//These seven functions print requests for user input. 
//This function asks what a user wants to investigate in their current room
void print_keyword_request(int roomNum);
//This function asks what a user wants to investigate further in their current room
//It is mainly used for looking for clues within smaller spaces
//For example, this would be called if you were investigating books within a bookcase 
void print_further_keyword_request();
//This function asks a player what they want to investigate in the safe
void print_safe_request();
//This function asks the player for a new room name.
void print_new_room_request(int roomNum);
//These functions ask the player what questions they want to ask an NPC
//or which clue they want to interrogate an NPC with.
void print_questioning_request(int roomNum);
void print_pendleton_help_request(int roomNum);
void print_interrogation_request(int roomNum, vector<bool>& currentUserChoices, vector<string>& clueList);

//These functions print a pretty title for each room, the actual name of each room,
//and the names of adjacent rooms to the player's current location.
string get_room_name(int roomNum);
void print_room_title(int roomNum);
void print_adjacent_rooms(int roomNum);
void print_map(int roomNum);

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
const int GETFLASHLIGHT = 1;
const int GETUVLIGHT = 2;
const int ACCUSEMRSSTRONGHOLD = 3;
const int GIVELATECHECK = 4;
const int ASKABOUTEXPENSEREPORTS = 5;
const int ASKABOUTREDVELVETCHAIRS = 6;
const int ASKABOUTCUTNIGHTSHADE = 7;
const int ASKABOUTSTONEBUTTON= 8;
const int ASKABOUTEMPTYDISPLAY = 9;
const int ASKABOUTCLEANEDFLOOR = 10;
const int ASKABOUTGLASSSHARDS = 11;
const int ASKABOUTFOAMEDMOUTH = 12;
const int ASKABOUTWETBOOTS = 13;
const int ASKABOUTCUFFLINK = 14;
const int ENTERWINECELLAR = 15;

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
const int STONEBUTTON = 10;
const int EMPTYDISPLAY = 11;
const int BLOODSTAINS = 12;
const int CLEANEDFLOOR = 13;
const int GLASSSHARDS = 14;
const int BREAKERBOX = 15;
const int BROKENLOCK = 16;
const int SLASHEDTHROAT = 17;
const int FOAMEDMOUTH = 18;
const int BLOODYGARMENT = 19;
const int WETBOOTS = 20;
const int CUFFLINK = 21;
const int WASHEDSINK = 22;
const int SNOWYFOOTPRINTS = 23;


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
const int NUMCLUES = 24;




//Main Program
int main()
{

    srand(static_cast<int>(time(0)));

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

    //FIXME: REDISTRIBUTE clues to appropriate places around house

    userChoices.at(ACCUSEMRSSTRONGHOLD) = true;
    userChoices.at(GETUVLIGHT) = true;

    //FIXME: REMOVE ONCE GAME IS FINISHED
    //Prints clueList
    for (size_t i = 0; i < clueList.size(); i++) {
        cout << clueList.at(i) << endl;
    }

    type_and_continue();

    //Prints introduction to story
    beginning();

    enter_tutorial(userChoices, clueList);

    //Loops Until roomNum is -1, which will only be the case once the player
    //Submits their final answer of who the murderer is etc.
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
            
            //Empties console screen
            system("CLS");
            //Sets New Room Number to User's Input
            roomNum = leave_room(roomNum);

            //Loops until player has chosen new room to enter
            while (roomNum == 0) {
                //Clears Screen
                system("CLS");
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

                //Describes Room 1
                describe_room(roomNum, userChoices, clueList);
                userKeyword = investigate_room(roomNum, userChoices, clueList);
            }
            
            //Empties console screen
            system("CLS");
            //Sets New Room Number to User's Input
            roomNum = leave_room(roomNum);

            //Loops until player has chosen new room to enter
            while (roomNum == 1) {
                //Clears Screen
                system("CLS");
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

                //Describes Room 2
                describe_room(roomNum, userChoices, clueList);
                userKeyword = investigate_room(roomNum, userChoices, clueList);
            }
            
            //Empties console screen
            system("CLS");
            //Sets New Room Number to User's Input
            roomNum = leave_room(roomNum);

            //Loops until player has chosen new room to enter
            while (roomNum == 2) {
                //Clears Screen
                system("CLS");
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

                //Describes Room 3
                describe_room(roomNum, userChoices, clueList);
                userKeyword = investigate_room(roomNum, userChoices, clueList);
            }
            
            //Empties console screen
            system("CLS");
            //Sets New Room Number to User's Input
            roomNum = leave_room(roomNum);

            //Loops until player has chosen new room to enter
            while (roomNum == 3) {
                //Clears Screen
                system("CLS");
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

                //Describes Room 4
                describe_room(roomNum, userChoices, clueList);
                userKeyword = investigate_room(roomNum, userChoices, clueList);
            }
            
            //Empties console screen
            system("CLS");
            //Sets New Room Number to User's Input
            roomNum = leave_room(roomNum);

            //Loops until player has chosen new room to enter
            while (roomNum == 4) {
                //Clears Screen
                system("CLS");
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

                //Describes Room 5
                describe_room(roomNum, userChoices, clueList);
                userKeyword = investigate_room(roomNum, userChoices, clueList);
            }
            
            //Empties console screen
            system("CLS");
            //Sets New Room Number to User's Input
            roomNum = leave_room(roomNum);

            //Loops until player has chosen new room to enter
            while (roomNum == 5) {
                //Clears Screen
                system("CLS");
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

                //Describes Room 6
                describe_room(roomNum, userChoices, clueList);
                userKeyword = investigate_room(roomNum, userChoices, clueList);
            }
            
            //Empties console screen
            system("CLS");
            //Sets New Room Number to User's Input
            roomNum = leave_room(roomNum);

            //Loops until player has chosen new room to enter
            while (roomNum == 6) {
                //Clears Screen
                system("CLS");
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

                //Describes Room 7
                describe_room(roomNum, userChoices, clueList);
                userKeyword = investigate_room(roomNum, userChoices, clueList);
            }
            
            //Empties console screen
            system("CLS");
            //Sets New Room Number to User's Input
            roomNum = leave_room(roomNum);

            //Loops until player has chosen new room to enter
            while (roomNum == 7) {
                //Clears Screen
                system("CLS");
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

                //Describes Room 8
                describe_room(roomNum, userChoices, clueList);
                userKeyword = investigate_room(roomNum, userChoices, clueList);
            }
            
            //Empties console screen
            system("CLS");
            //Sets New Room Number to User's Input
            roomNum = leave_room(roomNum);

            //Loops until player has chosen new room to enter
            while (roomNum == 8) {
                //Clears Screen
                system("CLS");
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

                //Describes Room 9
                describe_room(roomNum, userChoices, clueList);
                userKeyword = investigate_room(roomNum, userChoices, clueList);
            }
            
            //Empties console screen
            system("CLS");
            //Sets New Room Number to User's Input
            roomNum = leave_room(roomNum);

            //Loops until player has chosen new room to enter
            while (roomNum == 9) {
                //Clears Screen
                system("CLS");
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

                //Describes Room 10
                describe_room(roomNum, userChoices, clueList);
                userKeyword = investigate_room(roomNum, userChoices, clueList);
            }
            
            //Empties console screen
            system("CLS");
            //Sets New Room Number to User's Input
            roomNum = leave_room(roomNum);

            //Loops until player has chosen new room to enter
            while (roomNum == 10) {
                //Clears Screen
                system("CLS");
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

                //Describes Room 11
                describe_room(roomNum, userChoices, clueList);
                userKeyword = investigate_room(roomNum, userChoices, clueList);
            }

            //Empties console screen
            system("CLS");
            //Sets New Room Number to User's Input
            roomNum = leave_room(roomNum);

            //Loops until player has chosen new room to enter
            while (roomNum == 11) {
                //Clears Screen
                system("CLS");
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

                //Describes Room 12
                describe_room(roomNum, userChoices, clueList);
                userKeyword = investigate_room(roomNum, userChoices, clueList);
            }

            //Empties console screen
            system("CLS");
            //Sets New Room Number to User's Input
            roomNum = leave_room(roomNum);

            //Loops until player has chosen new room to enter
            while (roomNum == 12) {
                //Clears Screen
                system("CLS");
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

                //Describes Room 13
                describe_room(roomNum, userChoices, clueList);
                userKeyword = investigate_room(roomNum, userChoices, clueList);
            }

            //Empties console screen
            system("CLS");
            //Sets New Room Number to User's Input
            roomNum = leave_room(roomNum);

            //Loops until player has chosen new room to enter
            while (roomNum == 13) {
                //Clears Screen
                system("CLS");
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

    system("CLS");

    cout << "At the edge of the Black Hills in South Dakota, a storm is swirling over the peaks of the lowest mountains." << endl;
    cout << "The only lights visible through the thick snow come from one of two places: " << endl;
    cout << "A small mining town deeper in the mountain's crest, and a lone mansion tucked in the side of Black Elk's Peak. " << endl;
    cout << "As you travel up the hill towards the mansion, you prepare yourself for the night to come. " << endl;
     
    type_and_continue();

    cout << "\nYou roll down your car window and listen to the rustling wind through the thick snow." << endl;
    cout << "It makes a whistling sound, as if nature itself is gleefully snapping branches and pounding the forest into the ground." << endl;
    cout << "There's nothing quite this forest in the middle of a storm." << endl;
    cout << "Luckily you're making your way towards a much more hypothetical storm." << endl;

    type_and_continue();

    cout << "\nAs the mansion grows closer on the horizon, the wind seems to die down a little." << endl;
    cout << "You imagine this won't be easy. It's your first real murder investigation, after all." << endl;
    cout << "But you're not easily pushed over. You'll figure out exactly who murdered Dr. Stronghold." << endl;

    type_and_continue();

    system("CLS");


    cout << "BBBB" << "  L" << "      AAA " << "  CCCC" << " K   K" << "     EEEEE" << " L" << "     K   K" << endl;
    cout << "B  BB" << " L" << "     A   A" << " CC" << "    K  K" << "      E " << "    L" << "     K  K" << endl;
    cout << "BBBB" << "  L" << "     AAAAA" << " C" << "     KKK" << "       EEEEE" << " L" << "     KKK" << endl;
    cout << "B  BB" << " L" << "     A   A" << " CC" << "    K  K" << "      E " << "    L" << "     K  K" << endl;
    cout << "BBBB" << "  LLLLL" << " A   A" << "  CCCC" << " K   K" << "     EEEEE" << " LLLLL" << " K   K" << endl;

    type_and_continue();

    cout << "\nWelcome to Black Elk Manor!" << endl;
    cout << "----------------------------------------" << endl;
    cout << "This is a text adventure meant to simulate a murder mystery!" << endl;
    cout << "You can interact with your environment by typing keywords when prompted." << endl;
    cout << "Keywords will always be in the room description unless you need to uncover other mysteries first." << endl;

    type_and_continue();
}



//Gives player brief tutorial of user input system.
void enter_tutorial(vector<bool>& currentUserChoices, vector<string>& clueList) {
    //Declares user input string
    string userKeyword;

    system("CLS");



    print_room_title(TROPHYHALL);
    cout << "You enter the mansion and find yourself in an ornate " << get_room_name(TROPHYHALL) << "." << endl;
    cout << "Glass cupboards line the edges of the room with glimmering bronze and silver figures." << endl;
    cout << "Dracaena plants cradle some shelves filled with well dusted black and white photos." << endl;
    cout << "There's even a golden lion head attached to the wall, right above the double doors that lead into the mansion's core." << endl;

    cout << "\nSeveral junior recruits are sitting around a plastic table that clashes with the mansion's sophisticated decor." << endl;
    cout << "They've set up the evidence table for your convenience." << endl;
    cout << "Your closest confidant, " << get_character_name(CLYDE, FORMAL) << ", seems eager to greet you." << endl;
    cout << "He probably has a case file prepared for you." << endl;

    cout << "\nTry typing \"clyde\" to talk to your investigative partner." << endl;

    //Gets userInput and sets it to lowercase
    userKeyword = get_keyword_input();

    //Loops until user has typed "clyde"
    while (userKeyword.compare("clyde") != 0) {

        cout << "\nIncorrect input." << endl;
        cout << "Try typing \"clyde\" to talk to your investigative partner." << endl;

        //Gets userInput and sets it to lowercase
        userKeyword = get_keyword_input();

    }

    system("CLS");

    cout << "You are talking to " << get_character_name(TROPHYHALL) << ":" << endl;
    cout << "----------------------------------------" << endl;
    cout << "\"Welcome Detective!" << endl;
    cout << "We need to go over some things before we get started with this case." << endl;
    cout << "It is important that you know how to interact with different clues.\"" << endl;
    cout << endl << get_character_name(TROPHYHALL) << " hands you the case file." << endl;
    cout << "\"Try typing \'case file\' to investigate that clue.\"" << endl;

    userKeyword = get_keyword_input();
    while (userKeyword.compare("Mud") != 0)
    {
        if ((userKeyword.compare("case") == 0)
            || (userKeyword.compare("file") == 0))
        {
            cout << "\n\"Great job detective!\"" << endl;
            if ((clueList.at(CASEFILE)).compare("???") == 0) {
                cout << "\n----------------------------------------" << endl;
                cout << "You've found a clue! You can now access this clue in your inventory." << endl;
                cout << "----------------------------------------" << endl;
                clueList.at(CASEFILE) = "\"Case File\" in the " + get_room_name(TROPHYHALL);
            }
            type_and_continue();
            break;
        }
        cout << "\nIncorrect input." << endl;
        cout << "Try typing \"case file\"." << endl;
        userKeyword = get_keyword_input();
    }

    system("CLS");

    cout << "You are talking to " << get_character_name(TROPHYHALL) << ":" << endl;
    cout << "----------------------------------------" << endl;
    cout << "\"That should be all you need to know for now." << endl;
    cout << "Be sure to investigate as much as possible." << endl;
    cout << "Good luck, Detective.\"" << endl;



    currentUserChoices.at(MEETCLYDE) = true;

    type_and_continue();

    //Empties console screen
    system("CLS");

}



//Prints ending on the story, which may differ based on userChoices
void ending(vector<bool>& currentUserChoices, vector<string>& clueList) {
    //Empties console screen
    system("CLS");
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

            cout << "\n" << get_character_name(CLYDE, INFORMAL) << " sits by a plastic table of evidence, prepared to answer any questions you might have." << endl;
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

        cout << "\n" << get_character_name(WINECRAFTER, FORMAL) << ", The Wine Crafter, is kneeling beside the grape vines, picking them in the dark with a flashlight." << endl;
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
        cout << "The " << get_room_name(BALCONY) << " is covered in snow from the storm." << endl;
        cout << "White flakes of snow from the rooftop are still swirling in the crisp winter air." << endl;
        cout << "You take a deep breath and enjoy the view. The mountain view is truly incredible." << endl;

        cout << "\nYou focus back on the deck." << endl;
        cout << "There appear to be two sets of footprints in the snow out here." << endl;
        cout << "Also, the door to the observatory has clearly been forced open." << endl;
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
    if ((userKeyword.compare("leave") != 0)
        && (userKeyword.compare("back") != 0)
        && (userKeyword.compare("close") != 0)
        && (userKeyword.compare("stop") != 0)) {
        print_input(userKeyword);
    }

    //Prints descriptions of object within current room if user keyword matches item name
    switch (roomNum) {
    case 0:

        if ((userKeyword.compare("inventory") == 0)) {
            view_inventory(roomNum, currentUserChoices, clueList, userKeyword);
        }

        if ((userKeyword.compare("plastic") == 0)
            || (userKeyword.compare("table") == 0)
            || (userKeyword.compare("evidence") == 0)) {
            //Empties console screen
            system("CLS");

            if ((userKeyword.compare("plastic") == 0)
                || (userKeyword.compare("table") == 0)) {
                //Empties console screen
                system("CLS");

                cout << "Plastic Table of Evidence: " << endl;
                cout << "----------------------------------------" << endl;
                cout << "On the plastic table of evidence sits a case file that contains an overview of the murder case, as well as a pair of handcuffs." << endl;
                cout << "Type 'case file' to open the case file, or 'handcuffs' to accuse a suspect." << endl;

                while (userKeyword.compare("back") != 0) {

                    //Asks for user input and gets user input
                    print_further_keyword_request();
                    userKeyword = get_keyword_input();

                    if ((userKeyword.compare("case") == 0)
                        || (userKeyword.compare("file") == 0)) {
                        //Empties console screen
                        system("CLS");

                        cout << "\n" << get_character_name(MRSSTRONGHOLD) << " is the widow of the late " << get_character_name(DRSTRONGHOLD) << endl;
                        cout << "The Butler cleaned for " << get_character_name(DRSTRONGHOLD, INFORMAL) << " and maintained the grounds." << endl;
                        cout << "The Sous Chef was " << get_character_name(DRSTRONGHOLD, INFORMAL) << "'s personal chef." << endl;
                        cout << "The Wine Crafter was a bussiness partner of " << get_character_name(DRSTRONGHOLD, INFORMAL) << "'s." << endl;
                        cout << "And lastly, the Astronomer was an old friend and associate of " << get_character_name(DRSTRONGHOLD) << "'s." << endl;
                        cout << get_character_name(BUTLER) << " did some cleaning in the ballroom" << endl;
                        cout << get_character_name(SOUSCHEF) << " went to the kitchen to clean." << endl;
                        cout << get_character_name(MRSSTRONGHOLD) << " took a bath." << endl;
                        cout << get_character_name(WINECRAFTER) << " collected some grapes." << endl;
                        cout << get_character_name(ASTRONOMER) << " conducted an experiment in her lab." << endl;
                        cout << "\n" << get_character_name(DRSTRONGHOLD) << " was found on his bed in the masterbedroom." << endl;
                        cout << "He was found with his throat slashed." << endl;

                        if ((clueList.at(CASEFILE)).compare("???") == 0) {
                            type_and_continue();
                            cout << "\n----------------------------------------" << endl;
                            cout << "You've found a clue! You can now access this clue in your inventory." << endl;
                            cout << "----------------------------------------" << endl;
                            clueList.at(CASEFILE) = "\"Case File\" in the " + get_room_name(TROPHYHALL);
                        }

                        type_and_continue();
                    }

                    if ((userKeyword.compare("handcuffs") == 0)
                        || (userKeyword.compare("hand") == 0)
                        || (userKeyword.compare("cuffs") == 0)) {
                        //Empties console screen
                        system("CLS");

                        cout << "Handcuffs: " << endl;
                        cout << "----------------------------------------" << endl;
                        cout << "A pair of silver handcuffs." << endl;

                        if (count_clues(clueList) >= 10 || count_clues(clueList) <= 19) {
                            type_and_continue();
                            ending(currentUserChoices, clueList);
                        }
                        else if (count_clues(clueList) > 19) {
                            roomNum = -1;
                            break;
                        }
                        else {
                            cout << "You need at least ten clues to accuse a suspect." << endl;
                            type_and_continue();
                        }
                        
                    }
                    //Empties console screen
                    system("CLS");

                    cout << "Plastic Table of Evidence: " << endl;
                    cout << "----------------------------------------" << endl;
                    cout << "On the plastic table of evidence sits a case file that contains an overview of the murder case, as well as a pair of handcuffs." << endl;
                    cout << "Type 'case file' to open the case file, or 'handcuffs' to accuse a suspect." << endl;
                }
            }
        }

        if ((userKeyword.compare("glass") == 0)
            || (userKeyword.compare("cupboards") == 0)
            || (userKeyword.compare("bronze") == 0)
            || (userKeyword.compare("silver") == 0)
            || (userKeyword.compare("figures") == 0)) {
            //Empties console screen
            system("CLS");

            cout << "Glass Trophy Cupboards: " << endl;
            cout << "----------------------------------------" << endl;
            cout << get_character_name(DRSTRONGHOLD) << " has an arrangement of trophies proudly presented in the glass cupboards." << endl;
            cout << "It seems he's achieved quite a lot in the scientific world." << endl;
            cout << "He received several awards for renovating the world of astronomy with his telescope designs." << endl;
            cout << "He's also a prime benefactor of a nearby coal mining town." << endl;
        }

        if ((userKeyword.compare("dracaena") == 0)
            || (userKeyword.compare("plants") == 0)) {
            //Empties console screen
            system("CLS");

            cout << "Dracaena Plants:" << endl;
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
            //Empties console screen
            system("CLS");

            cout << "Well Dusted Photos:" << endl;
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
            //Empties console screen
            system("CLS");

            cout << "Golden Lion Head:" << endl;
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

        if ((userKeyword.compare("inventory") == 0)) {
            view_inventory(roomNum, currentUserChoices, clueList, userKeyword);
        }

        if ((userKeyword.compare("sparkling") == 0)
            || (userKeyword.compare("vinyl") == 0)
            || (userKeyword.compare("floor") == 0)) {
            //Empties console screen
            system("CLS");

            cout << "Vinyl Floors:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "The Butler has clearly been wiping the floors down." << endl;
            cout << "You wonder if there's any reason for that..." << endl;
            cout << "Maybe he's just desperate to get his mind off of things." << endl;
        }

        if ((userKeyword.compare("marble") == 0)
            || (userKeyword.compare("columns") == 0)) {
            //Empties console screen
            system("CLS");

            cout << "Marble Columns:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "If these are important to the case, you're not seeing why." << endl;
            cout << "They're just gorgeous pillars. They don't have much use beyond their appeal to the eye." << endl;
        }

        if ((userKeyword.compare("intricate") == 0)
            || (userKeyword.compare("chandeliers") == 0)
            || (userKeyword.compare("ceiling") == 0)) {
            //Empties console screen
            system("CLS");

            cout << "Intricate Chandeliers:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "An old friend told you about a case of theirs where a chandelier fell onto the victim's head." << endl;
            cout << "Luckily these chandeliers seem rather attached to the ceiling." << endl;
        }

        if ((userKeyword.compare("mr.") == 0)
            || (userKeyword.compare("mr") == 0)
            || (userKeyword.compare("butler") == 0)
            || (userKeyword.compare("sebastian") == 0)
            || (userKeyword.compare("gilmore") == 0)) {
            questioning_butler(roomNum, currentUserChoices, clueList);
        }
        break;

    case 2:

        if ((userKeyword.compare("inventory") == 0)) {
            view_inventory(roomNum, currentUserChoices, clueList, userKeyword);
        }

        if ((userKeyword.compare("paperwork") == 0)
            || (userKeyword.compare("papers") == 0)
            || (userKeyword.compare("paper") == 0)
            || (userKeyword.compare("work") == 0)) {
            //Empties console screen
            system("CLS");

            cout << "Paperwork:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "Piles of paperwork have scattered throughout the room." << endl;
            cout << "It seems " << get_character_name(DRSTRONGHOLD) << " wasn't particularly organized." << endl;
        }

        if ((userKeyword.compare("velvet") == 0)
            || (userKeyword.compare("curtains") == 0)
            || (userKeyword.compare("curtain") == 0)) {
            //Empties console screen
            system("CLS");

            cout << "Velvet Curtains:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "Behind the curtains, you find some gleaming stained glass windows." << endl;
            cout << "They're painted and shaped to form the visage of a shooting star." << endl;
            cout << "You look beyond the glass. The view outside is disconcerting." << endl;
            cout << "It feels very cold tonight, and another storm looks to be heading this way." << endl;
            cout << "Hopefully the sunrise will be visible tomorrow." << endl;
        }

        if ((userKeyword.compare("rotating") == 0)
            || (userKeyword.compare("bookshelf") == 0)
            || (userKeyword.compare("book") == 0)
            || (userKeyword.compare("shelf") == 0)) {
            //Empties console screen
            system("CLS");

            cout << "Rotating Bookshelf:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "You imagine this kind of gimmicky furniture cost the Strongholds a lot of money." << endl;
            cout << "It seems like quite a waste since there's papers all over the floor." << endl;
            cout << "There's almost nothing on the bookshelf but some dull self help books and expense reports." << endl;

            while (userKeyword.compare("back") != 0){

                //Asks for user input and gets user input
                print_further_keyword_request();
                userKeyword = get_keyword_input();

                if ((userKeyword.compare("expense") == 0)
                    || (userKeyword.compare("reports") == 0)
                    || (userKeyword.compare("report") == 0)) {
                    //Empties console screen
                    system("CLS");

                    cout << "Expense Reports:" << endl;
                    cout << "----------------------------------------" << endl;
                    cout << "These expense reports pertain to " << get_character_name(DRSTRONGHOLD) << "'s business endeavors." << endl;
                    cout << "However, it's not easy for you to understand their relevance." << endl;
                    cout << "You should ask around about these to learn more about " << get_character_name(DRSTRONGHOLD) << "'s finances." << endl;

                    if ((clueList.at(EXPENSEREPORTS)).compare("???") == 0) {
                        type_and_continue();
                        cout << "\n----------------------------------------" << endl;
                        cout << "You've found a clue! You can now access this clue in your inventory." << endl;
                        cout << "----------------------------------------" << endl;
                        clueList.at(EXPENSEREPORTS) = "\"Expense Reports\" in the " + get_room_name(OFFICE);
                    }

                    type_and_continue();

                }
                else if ((userKeyword.compare("dull") == 0)
                    || (userKeyword.compare("self") == 0)
                    || (userKeyword.compare("help") == 0)
                    || (userKeyword.compare("book") == 0)
                    || (userKeyword.compare("books") == 0)) {
                    //Empties console screen
                    system("CLS");

                    cout << "Dull Self Help Books:" << endl;
                    cout << "----------------------------------------" << endl;
                    cout << "You flip through the pages of 100 Tips All Successful People May Or May Not Use:" << endl;
                    cout << "\"If you wake up at 5 A.M, you too can be tired!\"" << endl;
                    cout << "\"Don't forget to exercise at least once!\"" << endl;
                    cout << "\"Use money to buy things!\"" << endl;
                    cout << "\"Have a good day!\"" << endl;
                    cout << "\"Eat livers for breakfast!\"" << endl;

                    type_and_continue();

                }

                //Empties console screen
                system("CLS");

                cout << "Rotating Bookshelf:" << endl;
                cout << "----------------------------------------" << endl;
                cout << "You imagine this kind of gimmicky furniture cost the Strongholds a lot of money." << endl;
                cout << "It seems like quite a waste since there's papers all over the floor." << endl;
                cout << "There's almost nothing on the bookshelf but some dull self help books and expense reports." << endl;

            }

        }

        if ((userKeyword.compare("crescent") == 0)
            || (userKeyword.compare("moon") == 0)
            || (userKeyword.compare("lamp") == 0)) {
            //Empties console screen
            system("CLS");

            cout << "Crescent Moon Lamp:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "It seems incredibly expensive." << endl;
            cout << "Designed to resemble a crescent moon, its edges seem to have tiny painted craters." << endl;
            cout << "The detail work must've been excrutiating to paint, but damn, it looks good." << endl;
        }

        if ((userKeyword.compare("large") == 0)
            || (userKeyword.compare("oak") == 0)
            || (userKeyword.compare("desk") == 0)) {
            //Empties console screen
            system("CLS");

            cout << "Large Oak Desk:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "For a man bathing in wealth, " << get_character_name(DRSTRONGHOLD) << "'s desk is relatively normal." << endl;
            cout << "It actually seems quite cozy to sit at." << endl;
            cout << "Perhaps this desk is older than " << get_character_name(DRSTRONGHOLD) << "'s fortune." << endl;
            cout << "Inside the desk's top drawer you find some interesting knick knacks." << endl;
            cout << "But then you find a small safe. Perhaps the knick knacks weren't that interesting after all." << endl;
        
            while (userKeyword.compare("back") != 0) {

                //Asks for user input and gets user input
                print_further_keyword_request();
                userKeyword = get_keyword_input();

                if ((userKeyword.compare("knick") == 0)
                    || (userKeyword.compare("knacks") == 0)) {
                    //Empties console screen
                    system("CLS");

                    cout << "Knick Knacks:" << endl;
                    cout << "----------------------------------------" << endl;
                    cout << "The knick knacks you find in " << get_character_name(DRSTRONGHOLD) << "'s desk are actually quite quaint." << endl;
                    cout << "There's something rather intimate about the different toys he's collected." << endl;
                    cout << "Wooden tops from his travels are laid delicately through the drawer." << endl;
                    cout << "There's also some custom shot glasses, a magnet, and some postcards." << endl;
                    cout << "You feel their paper surfaces and stare at the splendid backgrounds of places near and far." << endl;
                    cout << "For a moment, just a moment, " << get_character_name(DRSTRONGHOLD) << " seems rather normal for an rich man." << endl;

                    type_and_continue();
                }

                if ((userKeyword.compare("small") == 0)
                    || (userKeyword.compare("safe") == 0)) {
                    //Empties console screen
                    system("CLS");

                    if (currentUserChoices.at(ACCUSEMRSSTRONGHOLD) == false) {
                        cout << "Small Safe:" << endl;
                        cout << "----------------------------------------" << endl;
                        cout << "This seems to be the kind of place " << get_character_name(DRSTRONGHOLD) << " would keep his secrets." << endl;
                        cout << "You'll need a four digit code to open it." << endl;
                    }
                    
                    if (currentUserChoices.at(ACCUSEMRSSTRONGHOLD) == true) {
                        cout << "Small Safe:" << endl;
                        cout << "----------------------------------------" << endl;
                        cout << "A small metal safe with a four digit combination lock." << endl;
                        cout << "It seems more sinister now that you know why " << get_character_name(MRSSTRONGHOLD) << " didn't want you to open it." << endl;
                        cout << "You type in the combination " << get_character_name(MRSSTRONGHOLD) << " gave you." << endl;

                        type_and_continue();

                        cout << "\nInside, there are three objects of interest: " << endl;
                        cout << "A scroll of papers, an unbanked check, and an anonymous letter." << endl;
                    

                        while (userKeyword.compare("close") != 0) {

                            //Asks for user input and gets user input
                            print_safe_request();
                            userKeyword = get_keyword_input();

                            if ((userKeyword.compare("scroll") == 0)
                                || (userKeyword.compare("paper") == 0)
                                || (userKeyword.compare("papers") == 0)) {
                                //Empties console screen
                                system("CLS");

                                    cout << "Life Insurance Policy:" << endl;
                                    cout << "----------------------------------------" << endl;
                                    cout << "It's a life insurance policy that will give " << get_character_name(MRSSTRONGHOLD) << " lots of compensation for " << get_character_name(DRSTRONGHOLD) << "'s death." << endl;
                                    cout << "Looking at it makes you sick." << endl;

                                    if ((clueList.at(INSURANCEPOLICY)).compare("???") == 0) {
                                    type_and_continue();
                                    cout << "\n----------------------------------------" << endl;
                                    cout << "You've found a clue! You can now access this clue in your inventory." << endl;
                                    cout << "----------------------------------------" << endl;
                                    clueList.at(INSURANCEPOLICY) = "\"Insurance Policy\" in the Safe";
                                }

                                type_and_continue();

                            }
                            
                            if ((userKeyword.compare("unbanked") == 0)
                                || (userKeyword.compare("check") == 0)) {
                                //Empties console screen
                                system("CLS");

                                cout << "Late Check:" << endl;
                                cout << "----------------------------------------" << endl;
                                cout << "It's a check with " << get_character_name(ASTRONOMER) << "'s name written on it." << endl;
                                cout << "Under the memo, it looks like " << get_character_name(DRSTRONGHOLD) << " just wrote \'I'm sorry.\'" << endl;

                                if ((clueList.at(LATECHECK)).compare("???") == 0) {
                                    type_and_continue();
                                    cout << "\n----------------------------------------" << endl;
                                    cout << "You've found a clue! You can now access this clue in your inventory." << endl;
                                    cout << "----------------------------------------" << endl;
                                    clueList.at(LATECHECK) = "\"Late Check\" in the Safe";
                                }

                                type_and_continue();

                            }

                            if ((userKeyword.compare("ornate") == 0)
                                || (userKeyword.compare("letter") == 0)) {
                                //Empties console screen
                                system("CLS");

                                cout << "Anonymous Letter:" << endl;
                                cout << "----------------------------------------" << endl;
                                cout << "This seems to be a letter with no clear author. They write as follows:" << endl;
                                cout << "\"At Dinner I sat in the furthest chair to your right." << endl;
                                cout << "Meet me in the " << get_room_name(WINECELLAR) << " two hours after Dinner."<< endl;
                                cout << "Let's celebrate.\"" << endl;

                                if ((clueList.at(ANONYMOUSLETTER)).compare("???") == 0) {
                                    type_and_continue();
                                    cout << "\n----------------------------------------" << endl;
                                    cout << "You've found a clue! You can now access this clue in your inventory." << endl;
                                    cout << "----------------------------------------" << endl;
                                    clueList.at(ANONYMOUSLETTER) = "\"Anonymous Letter\" in the Safe";
                                }

                                type_and_continue();

                            }

                            //Empties console screen
                            system("CLS");
                            cout << "Small Safe:" << endl;
                            cout << "----------------------------------------" << endl;
                            cout << "A small metal safe with a four digit combination lock." << endl;
                            cout << "Inside, there are three objects of interest: " << endl;
                            cout << "A scroll of papers, an unbanked check, and an ornate letter." << endl;
                        }
                    }

                    if ((clueList.at(SMALLSAFE)).compare("???") == 0) {
                        type_and_continue();
                        cout << "\n----------------------------------------" << endl;
                        cout << "You've found a clue! You can now access this clue in your inventory." << endl;
                        cout << "----------------------------------------" << endl;
                        clueList.at(SMALLSAFE) = "\"Small Safe\" in the " + get_room_name(OFFICE);
                    }

                    type_and_continue();

                }

                //Empties console screen
                system("CLS");

                cout << "Large Oak Desk:" << endl;
                cout << "----------------------------------------" << endl;
                cout << "For a man bathing in wealth, " << get_character_name(DRSTRONGHOLD) << "'s desk is relatively normal." << endl;
                cout << "It actually seems quite cozy to sit at." << endl;
                cout << "Perhaps this desk is older than " << get_character_name(DRSTRONGHOLD) << "'s fortune." << endl;
                cout << "Inside the desk's top drawer you find some interesting knick knacks." << endl;
                cout << "But then you find a small safe. Perhaps the knick knacks weren't that interesting after all." << endl;

            }

        }
        break;

    case 3:

        if ((userKeyword.compare("inventory") == 0)) {
            view_inventory(roomNum, currentUserChoices, clueList, userKeyword);
        }

        if ((userKeyword.compare("twin") == 0)
            || (userKeyword.compare("beds") == 0)
            || (userKeyword.compare("bed") == 0)) {
            //Empties console screen
            system("CLS");

            cout << "Twin Beds:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "It's crazy how similar the twin beds look." << endl;
            cout << "Thankfully one of them has short hair so you can tell them apart." << endl;
        }

        if ((userKeyword.compare("old") == 0)
            || (userKeyword.compare("fashioned") == 0)
            || (userKeyword.compare("grandfather") == 0)
            || (userKeyword.compare("clock") == 0)) {
            //Empties console screen
            system("CLS");

            cout << "Grandfather Clock:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "There's something quite stunning about this clock's complex shape." << endl;
            cout << "It looks like a wooden hourglass, yet has the functionality of a real clock." << endl;
            cout << "Its ticking is also rather peaceful. You wish it could be heard throughout the house." << endl;
        }

        if ((userKeyword.compare("wooden") == 0)
            || (userKeyword.compare("chests") == 0)
            || (userKeyword.compare("chest") == 0)) {
            //Empties console screen
            system("CLS");

            cout << "Wooden Chests:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "As you approach the wooden chests, " << get_character_name(SOUSCHEF) << "shoos you away." << endl;
            cout << "\"Please don't try to sniff out our personal belongings." << endl;
            cout << get_character_name(BUTLER) << " and I have agreed to keep our treasured possessions private.\"" << endl;

            if ((clueList.at(LOCKEDCHESTS)).compare("???") == 0) {
                type_and_continue();
                cout << "\n----------------------------------------" << endl;
                cout << "You've found a clue! You can now access this clue in your inventory." << endl;
                cout << "----------------------------------------" << endl;
                clueList.at(LOCKEDCHESTS) = "\"Locked Chests\" in the " + get_room_name(SERVANTSQUARTERS);
            }
        }

        if ((userKeyword.compare("ms.") == 0)
            || (userKeyword.compare("ms") == 0)
            || (userKeyword.compare("sous") == 0)
            || (userKeyword.compare("chef") == 0)
            || (userKeyword.compare("sue") == 0)
            || (userKeyword.compare("davis") == 0)) {
            questioning_souschef(roomNum, currentUserChoices, clueList);
        }
        break;

    case 4:

        if ((userKeyword.compare("inventory") == 0)) {
            view_inventory(roomNum, currentUserChoices, clueList, userKeyword);
        }

        if ((userKeyword.compare("tall") == 0)
            || (userKeyword.compare("wooden") == 0)
            || (userKeyword.compare("bookcases") == 0)
            || (userKeyword.compare("bookcase") == 0)) {
            //Empties console screen
            system("CLS");

            cout << "Tall Wooden Bookcases:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "There are more books on these shelves than you could read in a lifetime." << endl;
            cout << "However, the shelves are all quite dirty, and there's nothing in the few clean spots you find." << endl;
            cout << "It seems unlikely that someone hid anything here." << endl;
        }

        if ((userKeyword.compare("antique") == 0)
            || (userKeyword.compare("fireplace") == 0)
            || (userKeyword.compare("fire") == 0)
            || (userKeyword.compare("place") == 0)) {
            //Empties console screen
            system("CLS");

            cout << "Antique Fireplace:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "This would certainly be the first place a guilty party would get rid of evidence." << endl;
            cout << "Thankfully, however, it seems recently lit." << endl;
            cout << "Since it was likely started after Pendleton arrived, it's probably not of importance." << endl;
        }

        if ((userKeyword.compare("large") == 0)
            || (userKeyword.compare("granite") == 0)
            || (userKeyword.compare("chunks") == 0)) {
            //Empties console screen
            system("CLS");

            cout << "Large Granite Chunks:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "Just more proof of Dr. Stronghold's influence." << endl;
            cout << "He must've had them delivered from the coal mine..." << endl;
            cout << "Well, with all of his donations he's certainly a saint in the eyes of the mining townsfolk." << endl;
        }

        if ((userKeyword.compare("mrs.") == 0)
            || (userKeyword.compare("mrs") == 0)
            || (userKeyword.compare("stronghold") == 0)
            || (userKeyword.compare("diane") == 0)) {
            questioning_mrsstronghold(roomNum, currentUserChoices, clueList);
        }
        break;

    case 5:

        if ((userKeyword.compare("inventory") == 0)) {
            view_inventory(roomNum, currentUserChoices, clueList, userKeyword);
        }

        if ((userKeyword.compare("stovetop") == 0)
            || (userKeyword.compare("stove") == 0)
            || (userKeyword.compare("oven") == 0)) {
            //Empties console screen
            system("CLS");

            cout << "Stovetop Oven:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "Several half-empty skillets and baking trays line the stove." << endl;
            cout << "They truly had a feast tonight. There's bacon wrapped steaks, some lobster and scallops." << endl;
            cout << "Although... it may just be a feast to you." << endl;
            cout << "You couldn't imagine eating this well at home, but they probably considered this dinner to be average." << endl;
        }

        if ((userKeyword.compare("stainless") == 0)
            || (userKeyword.compare("steel") == 0)
            || (userKeyword.compare("sink") == 0)) {
            //Empties console screen
            system("CLS");

            cout << "Stainless Steel Sink:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "Dirty plates and silverware fill the sink." << endl;
            cout << "You pick up a jewel encrusted fork and imagine that this alone would pay for a trip to the Maldives." << endl;
        }

        if (userKeyword.compare("cupboards") == 0) {
            //Empties console screen
            system("CLS");

            cout << "Cupboards:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "There's nothing interesting in here. Just a lot of glass cups and stained clay bowls." << endl;
        }

        if ((userKeyword.compare("knife") == 0)
            || (userKeyword.compare("block") == 0)
            || (userKeyword.compare("knives") == 0)) {
            //Empties console screen
            system("CLS");

            cout << "Knife Block:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "A block of different sized knives." << endl;
            cout << "The smallest seems too small for human use, while the largest seems less for cutting and more for butchering." << endl;
            cout << "One of the larger knives is missing from the end of the block." << endl;

            if ((clueList.at(MISSINGKNIFE)).compare("???") == 0) {
                type_and_continue();
                cout << "\n----------------------------------------" << endl;
                cout << "You've found a clue! You can now access this clue in your inventory." << endl;
                cout << "----------------------------------------" << endl;
                clueList.at(MISSINGKNIFE) = "\"Missing Knife\" in the " + get_room_name(KITCHEN);
            }
        }

        if ((userKeyword.compare("basket") == 0)
            || (userKeyword.compare("kitchen") == 0)
            || (userKeyword.compare("utensils") == 0)) {
            //Empties console screen
            system("CLS");

            cout << "Kitchen Utensils Basket:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "Some wooden spoons, spatulas, and ladles rest in a basket for future use." << endl;
            cout << "It seems strange to see such old fashioned tools in a sparkling room like this." << endl;
            cout << "To each their own, you suppose." << endl;
        }

        if ((userKeyword.compare("hors") == 0)
            || (userKeyword.compare("d'oeuvres") == 0)
            || (userKeyword.compare("tray") == 0)) {
            //Empties console screen
            system("CLS");

            cout << "Hors D'oeuvres Tray:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "You take an Hors D'oeuvre from the tray and you it it so fast it seems to disappear from your hand." << endl;
            cout << "That's absolutely delicious. You never imagined ham and roast beef would pair so well." << endl;
        }
        break;

    case 6:

        if ((userKeyword.compare("inventory") == 0)) {
            view_inventory(roomNum, currentUserChoices, clueList, userKeyword);
        }

        if ((userKeyword.compare("elegant") == 0)
            || (userKeyword.compare("diamond") == 0)
            || (userKeyword.compare("chandelier") == 0)) {
            //Empties console screen
            system("CLS");

            cout << "Diamond Chandelier: " << endl;
            cout << "----------------------------------------" << endl;
            cout << "You feel like if this chandelier fell on you, your hospital bills would cost less than its replacement." << endl;
        }

        if ((userKeyword.compare("ornate") == 0)
            || (userKeyword.compare("dining") == 0)
            || (userKeyword.compare("table") == 0)) {
            //Empties console screen
            system("CLS");

            cout << "Ornate Dining Table: " << endl;
            cout << "----------------------------------------" << endl;
            cout << "This table seems to have one head chair and three chairs on each longer side." << endl;
            cout << "There's one giant chair at the end of the table for " << get_character_name(DRSTRONGHOLD) << " and three smaller " << endl;
            cout << "Two black stone vases rest near the table's center, offsetting its intricate white surface." << endl;
            cout << "Some Red Dianthus flowers poke out from within them." << endl;
        }

        if ((userKeyword.compare("red") == 0)
            || (userKeyword.compare("velvet") == 0)
            || (userKeyword.compare("chairs") == 0)) {
            //Empties console screen
            system("CLS");

            cout << "Red Velvet Chairs: " << endl;
            cout << "----------------------------------------" << endl;
            cout << "You stand beside the chair " << get_character_name(DRSTRONGHOLD) << " used." << endl;
            cout << "You wonder how the conversation went at dinner." << endl;
            cout << "But then you think about what Clyde told you earlier." << endl;
            cout << "Clyde said that including the mining town's mayor and wife, eight people were here for dinner." << endl;
            cout << "However... there's only seven chairs. You should ask around about that." << endl;

            if ((clueList.at(REDVELVETCHAIRS)).compare("???") == 0) {
                type_and_continue();
                cout << "\n----------------------------------------" << endl;
                cout << "You've found a clue! You can now access this clue in your inventory." << endl;
                cout << "----------------------------------------" << endl;
                clueList.at(REDVELVETCHAIRS) = "\"Red Velvet Chairs\" in the " + get_room_name(DININGROOM);
            }
        }
        break;

    case 7:

        if ((userKeyword.compare("inventory") == 0)) {
            view_inventory(roomNum, currentUserChoices, clueList, userKeyword);
        }

        if ((userKeyword.compare("shelves") == 0)
            || (userKeyword.compare("potted") == 0)
            || (userKeyword.compare("plants") == 0)) {
            //Empties console screen
            system("CLS");

            cout << "Potted Flowers:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "Shelves of potted plants are scattered throughout the " << get_room_name(GREENHOUSE) << endl;
            cout << "There seems to be three types of flowers planted." << endl;
            cout << "There's some maroon ones labeled \"Red Dianthus\"." << endl;
            cout << "There's some cobalt ones labeled \"Blue Lobelias\"." << endl;
            cout << "And, there's some purple ones labeled \"Belladonna Nightshades\"." << endl;

            while (userKeyword.compare("back") != 0) {

                //Asks for user input and gets user input
                print_further_keyword_request();
                userKeyword = get_keyword_input();

                if ((userKeyword.compare("maroon") == 0)
                    || (userKeyword.compare("red") == 0)
                    || (userKeyword.compare("dianthus") == 0)) {
                    //Empties console screen
                    system("CLS");

                    cout << "Red Dianthus Flowers:" << endl;
                    cout << "----------------------------------------" << endl;
                    cout << "The Red Dianthuses float on their stems like sparkling red jellyfish." << endl;
                    cout << "They produce beautiful waves of red and white color that swirl around each bud." << endl;
                    cout << "You're truly calmed by their presence." << endl;

                    type_and_continue();
                }

                if ((userKeyword.compare("cobalt") == 0)
                    || (userKeyword.compare("blue") == 0)
                    || (userKeyword.compare("lobelias") == 0)) {
                    //Empties console screen
                    system("CLS");

                    cout << "Blue Lobelias:" << endl;
                    cout << "----------------------------------------" << endl;
                    cout << "The Blue Lobelias appear to poof out like sugar rich cotton candy." << endl;
                    cout << "Their scent is that of a berry bush, serene and comforting." << endl;
                    cout << "You find yourself craving sweets while you stand near them." << endl;

                    type_and_continue();
                }

                if ((userKeyword.compare("belladonna") == 0)
                    || (userKeyword.compare("bella") == 0)
                    || (userKeyword.compare("donna") == 0)
                    || (userKeyword.compare("nightshade") == 0)
                    || (userKeyword.compare("nightshades") == 0)
                    || (userKeyword.compare("night") == 0)
                    || (userKeyword.compare("shade") == 0)
                    || (userKeyword.compare("shades") == 0)
                    || (userKeyword.compare("purple") == 0)) {
                    //Empties console screen
                    system("CLS");

                    cout << "Belladonna Nightshades:" << endl;
                    cout << "----------------------------------------" << endl;
                    cout << "The flowers of the belladonna are shriveled but still feel powerful." << endl;
                    cout << "Their leaves emit a fierce air that makes you hesitant to approach them." << endl;
                    cout << "You pause, concerned. Some of the stems appear to be recently cut." << endl;

                    if ((clueList.at(CUTNIGHTSHADE)).compare("???") == 0) {
                        type_and_continue();
                        cout << "\n----------------------------------------" << endl;
                        cout << "You've found a clue! You can now access this clue in your inventory." << endl;
                        cout << "----------------------------------------" << endl;
                        clueList.at(CUTNIGHTSHADE) = "\"Cut Nightshade\" in the " + get_room_name(GREENHOUSE);
                    }

                    type_and_continue();
                }

                //Empties console screen
                system("CLS");

                cout << "Potted Flowers:" << endl;
                cout << "----------------------------------------" << endl;
                cout << "Shelves of potted plants are scattered throughout the " << get_room_name(GREENHOUSE) << endl;
                cout << "There seems to be three types of flowers planted." << endl;
                cout << "There's some maroon ones labeled \"Red Dianthus\"." << endl;
                cout << "There's some cobalt ones labeled \"Blue Lobelias\"." << endl;
                cout << "And, there's some purple ones labeled \"Belladonna Nightshades\"." << endl;

            }

        }

        if ((userKeyword.compare("sky") == 0)
            || (userKeyword.compare("skylight") == 0)) {
            //Empties console screen
            system("CLS");

            cout << "Skylight:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "Moonlight rains through the cloudy sky above." << endl;
            cout << "The wet plants glisten with little bits of the moonlight, giving the room a luminous glow." << endl;
            cout << "The effect it has on the room is indescribable. It feels incredibly quaint in here." << endl;
        }

        if ((userKeyword.compare("gardening") == 0)
            || (userKeyword.compare("tools") == 0)
            || (userKeyword.compare("tool") == 0)) {
            //Empties console screen
            system("CLS");

            cout << "Gardening Tools:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "You find an old shovel resting against the wall." << endl;
            cout << "There's also a watering can and some fertilizer sitting around." << endl;
        
            while (userKeyword.compare("back") != 0) {

                //Asks for user input and gets user input
                print_further_keyword_request();
                userKeyword = get_keyword_input();

                if (userKeyword.compare("shovel") == 0) {
                    //Empties console screen
                    system("CLS");

                    cout << "Shovel:" << endl;
                    cout << "----------------------------------------" << endl;
                    cout << "A rusty shovel sits against the bag of fertilizer." << endl;
                    cout << "The handle is splintered from years of wear." << endl;

                    type_and_continue();
                }
                if ((userKeyword.compare("watering") == 0)
                    || (userKeyword.compare("can") == 0)) {
                    //Empties console screen
                    system("CLS");

                    cout << "Watering Can:" << endl;
                    cout << "----------------------------------------" << endl;
                    cout << "The watering can is half full." << endl;
                    cout << "The water's surface is littered with dead bugs." << endl;

                    type_and_continue();
                }
                if (userKeyword.compare("fertilizer") == 0) {
                    //Empties console screen
                    system("CLS");

                    cout << "Fertilizer:" << endl;
                    cout << "----------------------------------------" << endl;
                    cout << "The fertilizer is sitting in the corner of the room." << endl;
                    cout << "The top is sealed and the bag looks to be about half empty." << endl;

                    type_and_continue();
                }

                //Empties console screen
                system("CLS");

                cout << "Gardening Tools:" << endl;
                cout << "----------------------------------------" << endl;
                cout << "You find an old shovel resting against the wall." << endl;
                cout << "There's also a watering can and some fertilizer sitting around." << endl;

            }
        }

        if ((userKeyword.compare("logs") == 0)
            || (userKeyword.compare("log") == 0)) {
            //Empties console screen
            system("CLS");

            cout << "Logs:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "Some thick spruce logs have been set in a pyramid by the gardening supplies." << endl;
            cout << "These are likely used to fuel the fireplace and fertilize the flowers." << endl;
        }

        if ((userKeyword.compare("mr.") == 0)
            || (userKeyword.compare("mr") == 0)
            || (userKeyword.compare("wine") == 0)
            || (userKeyword.compare("crafter") == 0)
            || (userKeyword.compare("louis") == 0)
            || (userKeyword.compare("arbert") == 0)) {
            questioning_winecrafter(roomNum, currentUserChoices, clueList);
        }
        break;

    case 8:

        if ((userKeyword.compare("inventory") == 0)) {
            view_inventory(roomNum, currentUserChoices, clueList, userKeyword);
        }

        if ((userKeyword.compare("aged") == 0)
            || (userKeyword.compare("bathroom") == 0)) {
            //Empties console screen
            system("CLS");

            cout << "Aged Bathroom:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "The bathroom next to the stairs is pretty worn down." << endl;
            cout << "It seems to function as both the guest bathroom and the staff bathroom." << endl;
            cout << "The facilities are not desireable compared to the rest of the mansion." << endl;
        }

        if ((userKeyword.compare("worn") == 0)
            || (userKeyword.compare("red") == 0)
            || (userKeyword.compare("carpet") == 0)) {
            //Empties console screen
            system("CLS");

            cout << "Worn Red Carpet:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "The carpet here seems almost stretched by time." << endl;
            cout << "It seems just a year or so away from being ripped with holes." << endl;
            cout << "Oh. Halfway up them you spot a stone button on the floor." << endl;

            while (userKeyword.compare("back") != 0) {

                //Asks for user input and gets user input
                print_further_keyword_request();
                userKeyword = get_keyword_input();

                if ((userKeyword.compare("stone") == 0)
                    || (userKeyword.compare("button") == 0)) {
                    //Empties console screen
                    system("CLS");

                    cout << "Stone Button:" << endl;
                    cout << "----------------------------------------" << endl;
                    cout << "You find a suit button made of granite." << endl;
                    cout << "Some fabric hangs out of its holes, suggesting it was torn from something." << endl;

                    if ((clueList.at(STONEBUTTON)).compare("???") == 0) {
                        type_and_continue();
                        cout << "\n----------------------------------------" << endl;
                        cout << "You've found a clue! You can now access this clue in your inventory." << endl;
                        cout << "----------------------------------------" << endl;
                        clueList.at(STONEBUTTON) = "\"Stone Button\" in the " + get_room_name(STAIRWELL);
                    }

                    type_and_continue();
                }

                //Empties console screen
                system("CLS");

                cout << "Worn Red Carpet:" << endl;
                cout << "----------------------------------------" << endl;
                cout << "The carpet here seems almost stretched by time." << endl;
                cout << "It seems just a year or so away from being ripped with holes." << endl;
                cout << "Oh. Halfway up them you spot a stone button on the floor." << endl;

            }
        }

        if ((userKeyword.compare("globe") == 0)
            || (userKeyword.compare("light") == 0)
            || (userKeyword.compare("lights") == 0)) {
            //Empties console screen
            system("CLS");

            cout << "Globe Lights:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "Small spherical lights line the walls." << endl;
            cout << "Dust and cobwebs cover their rounded tops." << endl;
        }
        break;

    case 9:

        if ((userKeyword.compare("inventory") == 0)) {
            view_inventory(roomNum, currentUserChoices, clueList, userKeyword);
        }

        if ((userKeyword.compare("flashlight") != 0)
            && (userKeyword.compare("flash") != 0)
            && (userKeyword.compare("uv") != 0)
            && (userKeyword.compare("light") != 0)) {
            //Empties console screen
            system("CLS");

            cout << "???:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "It's too dark in here to investigate at the moment." << endl;
            cout << "Maybe you could find a source of light elsewhere." << endl;

            currentUserChoices.at(ENTERWINECELLAR) = true;

        }

        if (((userKeyword.compare("flashlight") == 0)
            || (userKeyword.compare("flash") == 0))
            && currentUserChoices.at(GETFLASHLIGHT) == true) {
            //Empties console screen
            system("CLS");

            cout << "You can see the Wine Cellar clearly now:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "While the bottles on the shelves seem unopened, something you couldn't see before pops out at you." << endl;
            cout << "In the back of the room, there's a glass display for a wine bottle, labeled \"Alain Hudelot\"." << endl;
            cout << "However, there's no bottle of wine inside." << endl;
            cout << "Hmm... That's peculiar." << endl;

            if ((clueList.at(EMPTYDISPLAY)).compare("???") == 0) {
                type_and_continue();
                cout << "\n----------------------------------------" << endl;
                cout << "You've found a clue! You can now access this clue in your inventory." << endl;
                cout << "----------------------------------------" << endl;
                clueList.at(EMPTYDISPLAY) = "\"Empty Display\" in the " + get_room_name(WINECELLAR);
            }
        }

        if (((userKeyword.compare("uv") == 0)
            || (userKeyword.compare("light") == 0))
            && currentUserChoices.at(GETUVLIGHT) == true) {
            //Empties console screen
            system("CLS");

            cout << "You use the Astronomer's UV Light here:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "On the floor by the glass display case, there are several spurts of blood." << endl;
            cout << "Getting closer, you smell a hint of bleach. Someone's cleaned the floor here recently." << endl;

            if (((clueList.at(BLOODSTAINS)).compare("???") == 0)
                || ((clueList.at(CLEANEDFLOOR).compare("???") == 0))){
                type_and_continue();
                cout << "\n----------------------------------------" << endl;
                cout << "You've found two clues! You can now access both clues in your inventory." << endl;
                cout << "----------------------------------------" << endl;
                clueList.at(BLOODSTAINS) = "\"Bloodstains\" in the " + get_room_name(WINECELLAR);
                clueList.at(CLEANEDFLOOR) = "\"Cleaned Floor\" in the " + get_room_name(WINECELLAR);
            }
        }
        break;

    case 10:

        if ((userKeyword.compare("inventory") == 0)) {
            view_inventory(roomNum, currentUserChoices, clueList, userKeyword);
        }

        if (userKeyword.compare("heater") == 0) {
            //Empties console screen
            system("CLS");

            cout << "Heater:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "You take a moment to enjoy the room's warmth." << endl;
            cout << "For whatever reason, the heat doesn't seem to carry well upstairs." << endl;
            cout << "It's probably because of the winter storm." << endl;
        }

        if ((userKeyword.compare("garbage") == 0)
            || (userKeyword.compare("bin") == 0)) {
            //Empties console screen
            system("CLS");

            cout << "Garbage Bin:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "The smell here is rather atrocious. Half a dozen black bags are stacked up inside." << endl;
            cout << "Hmm... That's odd. A small piece of glass is laying on one of the bags." << endl;
            cout << "Shifting the bags around, you find larger shards of glass beneath them." << endl;
            cout << "Someone definitely tried to hide this glass at the bottom of the bin... but why?" << endl;

            if ((clueList.at(GLASSSHARDS)).compare("???") == 0) {
                type_and_continue();
                cout << "\n----------------------------------------" << endl;
                cout << "You've found a clue! You can now access this clue in your inventory." << endl;
                cout << "----------------------------------------" << endl;
                clueList.at(GLASSSHARDS) = "\"Glass Shards\" in the " + get_room_name(BOILERROOM);
            }
        }

        if ((userKeyword.compare("hanging") == 0)
            || (userKeyword.compare("light") == 0)
            || (userKeyword.compare("lightbulb") == 0)) {
            //Empties console screen
            system("CLS");

            cout << "Hanging Lightbulb:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "What a tragedy. It's a shame this lightbulb decided to kill itself." << endl;
        }

        if ((userKeyword.compare("breaker") == 0)
            || (userKeyword.compare("box") == 0)) {
            //Empties console screen
            system("CLS");

            cout << "Breaker Box:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "Clyde told you that the power was turned off around the time of the murder." << endl;
            cout << "There doesn't seem to be any mechanism to turn off the power in advance though." << endl;
            cout << "That means whoever turned off the mansion's lights had to be in this room around the time of the murder." << endl;

            if ((clueList.at(BREAKERBOX)).compare("???") == 0) {
                type_and_continue();
                cout << "\n----------------------------------------" << endl;
                cout << "You've found a clue! You can now access this clue in your inventory." << endl;
                cout << "----------------------------------------" << endl;
                clueList.at(BREAKERBOX) = "\"Breaker Box\" in the " + get_room_name(BOILERROOM);
            }
        }

        if ((userKeyword.compare("mud") == 0)
            || (userKeyword.compare("man") == 0)) {
            questioning_mudman(roomNum, currentUserChoices, clueList);
        }
        break;

    case 11:

        if ((userKeyword.compare("inventory") == 0)) {
            view_inventory(roomNum, currentUserChoices, clueList, userKeyword);
        }

        if ((userKeyword.compare("gigantic") == 0)
            || (userKeyword.compare("telescope") == 0)) {
            //Empties console screen
            system("CLS");

            cout << "Telescope:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "It's a beautiful mechanical device with too many parts to count." << endl;
            cout << "(FIXME: CREATE NAME) ASTROPHYSICIST/ARCHEOLOGIST walks up to you." << endl;
            cout << "\"Unfortunately there are too many clouds to view the stars tonight.\"" << endl;
            cout << "\"Dr.Armstrong always loved show the sky off to his visitors. I wish I could show you Saturn." << endl;
            cout << "She smiles wistfully. \"It was his favorite planet. He loved how unique it was.\"" << endl;
        }

        if ((userKeyword.compare("little") == 0)
            || (userKeyword.compare("statues") == 0)
            || (userKeyword.compare("statue") == 0)) {
            //Empties console screen
            system("CLS");

            cout << "Astronomy Displays:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "Three gorgeous statues have been placed behind glass for your viewing pleasure." << endl;
            cout << "One represents the solar system, another is built to resemble the sun, and the last is a representation of a black hole." << endl;
        }

        if ((userKeyword.compare("solar") == 0)
            || (userKeyword.compare("system") == 0)) {
            //Empties console screen
            system("CLS");

            cout << "You read the Solar System exhibit's plaque:" << endl;
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
            || (userKeyword.compare("tool") == 0)
            || (userKeyword.compare("experiments") == 0)
            || (userKeyword.compare("experiment") == 0)) {
            //Empties console screen
            system("CLS");

            cout << "Lab Area:" << endl;
            cout << "Luckily for you, Clyde's cleared out this area with the junior detectives already." << endl;
            cout << "The tools and experiments weren't touched tonight, so there's not anything of interest here." << endl;
        }

        if ((userKeyword.compare("dr.") == 0)
            || (userKeyword.compare("dr") == 0)
            || (userKeyword.compare("astronomer") == 0)
            || (userKeyword.compare("jill") == 0)
            || (userKeyword.compare("tyson") == 0)) {
            questioning_astronomer(roomNum, currentUserChoices, clueList);
        }
        break;

    case 12:

        if ((userKeyword.compare("inventory") == 0)) {
            view_inventory(roomNum, currentUserChoices, clueList, userKeyword);
        }

        if ((userKeyword.compare("mr.") == 0)
            || (userKeyword.compare("mr") == 0)
            || (userKeyword.compare("stronghold's") == 0)
            || (userKeyword.compare("stronghold") == 0)
            || (userKeyword.compare("nathan") == 0)
            || (userKeyword.compare("body") == 0)) {
            //Empties console screen
            system("CLS");

            cout << get_character_name(DRSTRONGHOLD) << "'s Body: " << endl;
            cout << "----------------------------------------" << endl;
            cout << "Standing directly over the dead body, it is clear that the victim's throat was slashed." << endl;
            cout << "That was his cause of death on Clyde's report." << endl;
            cout << "However, you can't help but notice how sickly pale Mr. Stronghold's face has become." << endl;
            cout << "Peering closer, you notice something startling. There seems to be some foam in his mouth." << endl;
            cout << "What could this mean?" << endl;

            if (((clueList.at(SLASHEDTHROAT)).compare("???") == 0)
                || ((clueList.at(FOAMEDMOUTH).compare("???") == 0))) {
                type_and_continue();
                cout << "\n----------------------------------------" << endl;
                cout << "You've found two clues! You can now access both clues in your inventory." << endl;
                cout << "----------------------------------------" << endl;
                clueList.at(SLASHEDTHROAT) = "\"Slashed Throat\" of " + get_character_name(DRSTRONGHOLD) + "'s";
                clueList.at(FOAMEDMOUTH) = "\"Foamed Mouth\" of " + get_character_name(DRSTRONGHOLD) + "'s";
            }
        }

        if ((userKeyword.compare("lavish") == 0)
            || (userKeyword.compare("blood") == 0)
            || (userKeyword.compare("stained") == 0)
            || (userKeyword.compare("bed") == 0)) {
            //Empties console screen
            system("CLS");

            cout << "Blood Stained Bed: " << endl;
            cout << "----------------------------------------" << endl;
            cout << "Looking more carefully at the blood stained bed, you notice a garment poking out from under it." << endl;
            cout << "It seems to be a pair of pajamas... with some blood on the sleeves." << endl;

            if ((clueList.at(BLOODYGARMENT)).compare("???") == 0) {
                type_and_continue();
                cout << "\n----------------------------------------" << endl;
                cout << "You've found a clue! You can now access this clue in your inventory." << endl;
                cout << "----------------------------------------" << endl;
                clueList.at(BLOODYGARMENT) = "\"Bloody Garment\" in the " + get_room_name(MASTERBEDROOM);
            }
        }

        if ((userKeyword.compare("victorian") == 0)
            || (userKeyword.compare("era") == 0)
            || (userKeyword.compare("armoires") == 0)
            || (userKeyword.compare("armoire") == 0)) {
            //Empties console screen
            system("CLS");

            cout << "Victorian Era Armoires: " << endl;
            cout << "----------------------------------------" << endl;
            cout << "It seems " << get_character_name(DRSTRONGHOLD) << " and " << get_character_name(MRSSTRONGHOLD) << "both had their own armoires." << endl;
            cout << get_character_name(DRSTRONGHOLD) << "'s is sturdy and made of spruce wood." << endl;
            cout << get_character_name(MRSSTRONGHOLD) << "'s is lighter and made of birch wood." << endl;

            while (userKeyword.compare("back") != 0) {

                //Asks for user input and gets user input
                print_further_keyword_request();
                userKeyword = get_keyword_input();

                if ((userKeyword.compare("dr.") == 0)
                    || (userKeyword.compare("dr") == 0)
                    || (userKeyword.compare("stronghold") == 0)
                    || (userKeyword.compare("stronghold's") == 0)
                    || (userKeyword.compare("sturdy") == 0)
                    || (userKeyword.compare("spruce") == 0)) {
                    //Empties console screen
                    system("CLS");

                    cout << get_character_name(DRSTRONGHOLD) << "'s Armoire:" << endl;
                    cout << "----------------------------------------" << endl;
                    cout << "Inside " << get_character_name(DRSTRONGHOLD) << "'s armoire you find lots of expensive suits." << endl;
                    cout << "It seems a man of his stature was always dressing up." << endl;
                    cout << "But then you pause. You notice a small puddle dripping away from a few dress shirts." << endl;
                    cout << "Lifting them up, you find a pair of wet boots. They still feel cold..." << endl;

                    if ((clueList.at(WETBOOTS)).compare("???") == 0) {
                        type_and_continue();
                        cout << "\n----------------------------------------" << endl;
                        cout << "You've found a clue! You can now access this clue in your inventory." << endl;
                        cout << "----------------------------------------" << endl;
                        clueList.at(WETBOOTS) = "\"Wet Boots\" in the " + get_room_name(MASTERBEDROOM);
                    }

                    type_and_continue();
                }

                if ((userKeyword.compare("mrs.") == 0)
                    || (userKeyword.compare("mrs") == 0)
                    || (userKeyword.compare("stronghold") == 0)
                    || (userKeyword.compare("stronghold's") == 0)
                    || (userKeyword.compare("light") == 0)
                    || (userKeyword.compare("birch") == 0)) {
                    //Empties console screen
                    system("CLS");

                    cout << get_character_name(MRSSTRONGHOLD) << "'s Armoire:" << endl;
                    cout << "----------------------------------------" << endl;
                    cout << "Unsurprisingly, " << get_character_name(MRSSTRONGHOLD) << "'s armoire is filled with a dozen flowing dresses." << endl;
                    cout << "Hmm... In the corner of the armoire you find a cufflink. That doesn't seem to belong here." << endl;
                    cout << "Why is there a cufflink in such a feminine closet?" << endl;

                    if ((clueList.at(CUFFLINK)).compare("???") == 0) {
                        type_and_continue();
                        cout << "\n----------------------------------------" << endl;
                        cout << "You've found a clue! You can now access this clue in your inventory." << endl;
                        cout << "----------------------------------------" << endl;
                        clueList.at(CUFFLINK) = "\"Cufflink\" in the " + get_room_name(MASTERBEDROOM);
                    }

                    type_and_continue();
                }

                //Empties console screen
                system("CLS");

                cout << "Victorian Era Armoires: " << endl;
                cout << "----------------------------------------" << endl;
                cout << "It seems " << get_character_name(DRSTRONGHOLD) << " and " << get_character_name(MRSSTRONGHOLD) << "both had their own armoires." << endl;
                cout << get_character_name(DRSTRONGHOLD) << "'s is sturdy and made of spruce wood." << endl;
                cout << get_character_name(MRSSTRONGHOLD) << "'s is lighter and made of birch wood." << endl;

            }
        }

        if (userKeyword.compare("tub") == 0) {
            //Empties console screen
            system("CLS");

            cout << "Giant Tub: " << endl;
            cout << "----------------------------------------" << endl;
            cout << "The tub's still full from " << get_character_name(MRSSTRONGHOLD) << "'s bath." << endl;
            cout << "Some rose scented candles rest nearby. It looks like they've been put out." << endl;
        }

        if ((userKeyword.compare("glamorous") == 0)
            || (userKeyword.compare("vanity") == 0)
            || (userKeyword.compare("vanities") == 0)) {
            //Empties console screen
            system("CLS");

            cout << "Bathroom Vanity: " << endl;
            cout << "----------------------------------------" << endl;
            cout << "The vanities seem relatively untouched." << endl;
            cout << "However, as you grow close to them, the smell of lavender overwhelms your nose." << endl;
            cout << "It's a nice escape from death, but it's peculiar." << endl;
            type_and_continue();

            cout << "You find that the scent is strongest on " << get_character_name(MRSSTRONGHOLD) << "'s side." << endl;
            cout << "It seems to be coming from the sink under her vanity... which is wet and sparkling clean." << endl;
            cout << "Did Mrs. Stronghold clean her sink recently?" << endl;

            if ((clueList.at(WASHEDSINK)).compare("???") == 0) {
                type_and_continue();
                cout << "\n----------------------------------------" << endl;
                cout << "You've found a clue! You can now access this clue in your inventory." << endl;
                cout << "----------------------------------------" << endl;
                clueList.at(WASHEDSINK) = "\"Washed Sink\" in the " + get_room_name(MASTERBEDROOM);
            }
        }

        if ((userKeyword.compare("golden") == 0)
            || (userKeyword.compare("toilet") == 0)) {
            //Empties console screen
            system("CLS");

            cout << "Golden Toilet: " << endl;
            cout << "----------------------------------------" << endl;
            cout << "If you stole this toilet you could probably buy yourself a new house." << endl;
            cout << "If only " << get_character_name(CLYDE, INFORMAL) << "was a little less caring for the rules." << endl;
        }
        break;

    case 13:

        if ((userKeyword.compare("inventory") == 0)) {
            view_inventory(roomNum, currentUserChoices, clueList, userKeyword);
        }

        if ((userKeyword.compare("observatory") == 0)
            || (userKeyword.compare("door") == 0)
            || (userKeyword.compare("forced") == 0)
            || (userKeyword.compare("open") == 0)) {
            //Empties console screen
            system("CLS");

            cout << "Broken Lock:" << endl;
            cout << "----------------------------------------" << endl;
            cout << "It looks like this door was forced open." << endl;
            cout << "The door's lock has been completely destroyed, along with its handle." << endl;

            if ((clueList.at(BROKENLOCK)).compare("???") == 0) {
                type_and_continue();
                cout << "\n----------------------------------------" << endl;
                cout << "You've found a clue! You can now access this clue in your inventory." << endl;
                cout << "----------------------------------------" << endl;
                clueList.at(BROKENLOCK) = "\"Broken Lock\" on the " + get_room_name(BALCONY) + "'s door to the " + get_room_name(OBSERVATORY);
            }
        }
        if ((userKeyword.compare("two") == 0)
            || (userKeyword.compare("sets") == 0)
            || (userKeyword.compare("foot") == 0)
            || (userKeyword.compare("prints") == 0)
            || (userKeyword.compare("footprints") == 0)
            || (userKeyword.compare("snow") == 0)) {
            //Empties console screen
            system("CLS");

            cout << "Snowy Footprints: " << endl;
            cout << "----------------------------------------" << endl;
            cout << "There seems to be two sets of footprints in the snow here." << endl;
            cout << "One set of prints was made by a large pair of boots, and the other a set of dress shoes." << endl;
            cout << "The size of the dress shoes seems relatively normal, so it's hard to say whether a man or woman wore them." << endl;

            if ((clueList.at(SNOWYFOOTPRINTS)).compare("???") == 0) {
                type_and_continue();
                cout << "\n----------------------------------------" << endl;
                cout << "You've found a clue! You can now access this clue in your inventory." << endl;
                cout << "----------------------------------------" << endl;
                clueList.at(SNOWYFOOTPRINTS) = "\"Snowy Footprints\" on the " + get_room_name(BALCONY);
            }
        }
        break;

    default:
        break;
    }

    if ((userKeyword.compare("leave") != 0)
        && (userKeyword.compare("back") != 0) 
        && (userKeyword.compare("close") != 0)
        && (userKeyword.compare("stop") != 0)) {
        type_and_continue();
    }

    return userKeyword;
}

//Prints adjacent rooms to user and then changes roomNum to newRoomNum based on the user's input
int leave_room(int roomNum) {

    int newRoomNum = roomNum;

    //Prints map of rooms for user's reference
    print_map(roomNum);
    //Asks user which room they'd like to go to
    print_new_room_request(roomNum);
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
        if ((userKeyword.compare("servant's") == 0)
            || (userKeyword.compare("servants") == 0)
            || (userKeyword.compare("servant") == 0)
            || (userKeyword.compare("quarters") == 0)
            || (userKeyword.compare("quarter") == 0)) {
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
            || (userKeyword.compare("stair") == 0)
            || (userKeyword.compare("well") == 0)
            || (userKeyword.compare("stairs") == 0)) {
            newRoomNum = 8;
        }
        break;

    case 2:
        if (userKeyword.compare("ballroom") == 0) {
            newRoomNum = 1;
        }
        if ((userKeyword.compare("servant's") == 0)
            || (userKeyword.compare("servants") == 0)
            || (userKeyword.compare("servant") == 0)
            || (userKeyword.compare("quarters") == 0)
            || (userKeyword.compare("quarter") == 0)) {
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
        if ((userKeyword.compare("servant's") == 0)
            || (userKeyword.compare("servants") == 0)
            || (userKeyword.compare("servant") == 0)
            || (userKeyword.compare("quarters") == 0)
            || (userKeyword.compare("quarter") == 0)) {
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
            || (userKeyword.compare("stair") == 0)
            || (userKeyword.compare("well") == 0)
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
            || (userKeyword.compare("stair") == 0)
            || (userKeyword.compare("well") == 0)
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
            || (userKeyword.compare("stair") == 0)
            || (userKeyword.compare("well") == 0)
            || (userKeyword.compare("stairs") == 0)) {
            newRoomNum = 8;
        }
        if (userKeyword.compare("master bedroom") == 0
            || userKeyword.compare("master") == 0
            || userKeyword.compare("bedroom") == 0) {
            newRoomNum = 12;
        }
        if (userKeyword.compare("balcony") == 0) {
            newRoomNum = 13;
        }
        break;

    case 12:
        if ((userKeyword.compare("stairwell") == 0)
            || (userKeyword.compare("stair") == 0)
            || (userKeyword.compare("well") == 0)
            || (userKeyword.compare("stairs") == 0)) {
            newRoomNum = 8;
        }
        if (userKeyword.compare("observatory") == 0) {
            newRoomNum = 11;
        }
        if (userKeyword.compare("balcony") == 0) {
            newRoomNum = 13;
        }
        break;

    case 13:
        if (userKeyword.compare("observatory") == 0) {
            newRoomNum = 11;
        }
        if (userKeyword.compare("master bedroom") == 0
            || userKeyword.compare("master") == 0
            || userKeyword.compare("bedroom") == 0) {
            newRoomNum = 12;
        }
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
    //Prints a title to tell the player which character they are questioning
    print_character_questioning_title(roomNum);
    cout << "As you approach him, he smiles at you with confidence." << endl;
    cout << "\"Hello, Detective. What do you need?\"" << endl;
    //Asks player which questions they'd like to ask Pendleton
    print_pendleton_help_request(roomNum);
    string userKeyword = get_keyword_input();

    //FIXME: REMOVE INPUT PRINTER WHEN GAME IS FINISHED
    while (userKeyword.compare("stop") != 0) {

        //Don't forget quotes when they speak
        if (userKeyword.compare("1") == 0) {

            //Empties console screen
            system("CLS");
            //Prints a title to tell the player which character they are questioning
            print_character_questioning_title(roomNum);

            cout << "You ask " << get_character_name(CLYDE, INFORMAL) << " about the case file's contents."<< endl;
            cout << "He opens your case file up and points to the different sections." << endl;
            cout << "\"This case file will provide you with a basic introduction to the case." << endl;
            cout << "It contains information on the following subjects:" << endl;
            cout << "Some background information on the suspects, the order of events before the murder, " << endl;
            cout << "and a rough autopsy of Dr.Stronghold's body.\"" << endl;
            type_and_continue();

            cout << "\n" << get_character_name(CLYDE, INFORMAL) << " pats you on the shoulder." << endl;
            cout << "\"And that's about it!" << endl;
            cout << "Once you've read up on the case, you should begin investigating the house and interrogating the suspects.\"" << endl;
            cout << "He smiles at you." << endl;
            cout << "\"Hopefully you'll have it solved in no time.\"" << endl;
            type_and_continue();
        }
        if (userKeyword.compare("2") == 0) {

            //Empties console screen
            system("CLS");
            //Prints a title to tell the player which character they are questioning
            print_character_questioning_title(roomNum);

            cout << "You ask " << get_character_name(CLYDE, INFORMAL) << " how to investigate each room." << endl;
            cout << "He ponders the question while chewing some gum." << endl;
            cout << "\"Well, when you enter a room, you should take a good look at its description." << endl;
            cout << "Then you just need to type an object's name to investigate it." << endl;
            cout << "For example, if you see a plant in a room, you could type \'plant\' to investigate it." << endl;
            cout << "When you do, you'll receive a more in-depth description of it.\"" << endl;
            type_and_continue();

            cout << "\n" << get_character_name(CLYDE, INFORMAL) << "'s eyes light up." << endl;
            cout << "\"Oh! One more thing though." << endl;
            cout << "Sometimes, when you investigate an object, " << endl;
            cout << "you'll be given an opportunity to investigate it even further." << endl;
            cout << "If the room's main description disappears, " << endl; 
            cout << "and you can only see the object's description, " << endl; 
            cout << "and a prompt asks you to investigate further, " << endl;
            cout << "then you should be able to investigate items within that object's description!\"" << endl;
            type_and_continue();

            cout << "\n" << "He scratches his chin." << endl;
            cout << "\"For example, let's say I'm investigating a bookshelf." << endl;
            cout << "It says that there's a book about nature, and a book about snails." << endl;
            cout << "If I'm asked to investigate further, I could type \'nature\' or \'snails\' to find out more on either book!\"" << endl;
            type_and_continue();
        }
        if (userKeyword.compare("3") == 0) {

            //Empties console screen
            system("CLS");
            //Prints a title to tell the player which character they are questioning
            print_character_questioning_title(roomNum);

            cout << "You ask " << get_character_name(CLYDE, INFORMAL) << " how to tell when you've found a clue." << endl;
            cout << "\"Good question!\"" << endl;
            cout << get_character_name(CLYDE, INFORMAL) << " points to the case file." << endl;
            cout << "\"When you find a clue, let's say your case file, a message will pop up on the screen letting you know." << endl;
            cout << "It'll say something along the lines of \'You've found a clue! You can access this clue in your inventory.\'" << endl;
            type_and_continue();

            cout << "\n" << "\"Once you've found a clue, you can access it by typing \'inventory\' in any room." << endl;
            cout << "Typing \'inventory\' will allow you to look at any of the clues you've already found.\"" << endl;
            type_and_continue();
        }
        if (userKeyword.compare("4") == 0) {

            //Empties console screen
            system("CLS");
            //Prints a title to tell the player which character they are questioning
            print_character_questioning_title(roomNum);

            cout << "You ask " << get_character_name(CLYDE, INFORMAL) << " how to question the suspects." << endl;
            cout << "\"In order to question a suspect, first you need to go to the room they're in." << endl;
            cout << "Then, you need to type their name or profession when asked what you'd like to investigate.\"" << endl;
            type_and_continue();

            cout << "\n" << "\"When questioning a suspect, you can either type \'1\' to ask who they are," << endl;
            cout << "\'2\' to ask about their whereabouts last night, or \'3\' to ask who they think the murderer is.\"" << endl;
            type_and_continue();

            cout << "\n" << "\"And, if you want to ask the suspect about any clues you've found, you can type \'interrogate\'." << endl;
            cout << "This will bring up the interrogation menu, and tell you which clues you can ask them about." << endl;
            cout << "Then you just type a clue's name to ask about it." << endl;
            cout << "For example, you could type \'case\' or \'file\' or \'case file\' to ask about the case file.\"" << endl;
            type_and_continue();
        }
        if (userKeyword.compare("5") == 0) {

            //Empties console screen
            system("CLS");
            //Prints a title to tell the player which character they are questioning
            print_character_questioning_title(roomNum);

            cout << "You ask " << get_character_name(CLYDE, INFORMAL) << " how to end the game when you've solved the murder and he chuckles."<< endl;
            cout << "\"Already excited to wrap this thing up? So impatient, Detective." << endl; 
            cout << "Well, whenever you're ready to end the game, come back here and investigate the plastic table.\"" << endl;
            type_and_continue();

            cout << "\n" << "\"Once you've found at least ten clues, you can make your final guess by investigating the handcuffs." << endl;
            cout << "Be warned, though. You only get one guess at the murderer's identity, Detective." << endl;
            cout << "Try not to ruin an innocent man or woman's life.\"" << endl;
            type_and_continue();
        }
        if (userKeyword.compare("interrogate") == 0) {

            //Empties console screen
            system("CLS");
            //Prints a title to tell the player which character they are questioning / interrogating
            print_character_questioning_title(roomNum);
            //Asks player which piece of evidence they'd like to interrogate the suspect about
            print_interrogation_request(roomNum, currentUserChoices, clueList);
            userKeyword = get_keyword_input();

            while (userKeyword.compare("end") != 0) {

                if (((userKeyword.compare("case") == 0)
                    || (userKeyword.compare("file") == 0)
                    || (userKeyword.compare("casefile") == 0))
                    && ((clueList.at(CASEFILE)).compare("???") != 0)) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);

                    cout << "You hand over the Case File to " << get_character_name(CLYDE, INFORMAL) << "." << endl;
                    cout << "\"Ah, a question about the case file? Unfortunately, I can't answer many of them.\"" << endl;
                    type_and_continue();

                    cout << "\n" << "\"Here's what I can say about the Case File:" << endl;
                    cout << "The information in this case file is true to my knowledge." << endl;
                    cout << "I took brief notes whilst talking to each suspect and looked around the rooms myself." << endl;
                    cout << "You may get more information by talking to the suspects yourself or investigating rooms yourself, however." << endl;
                    type_and_continue();

                    cout << "\n" << "Also, don't take my information as gospel, Detective." << endl;
                    cout << "If something in there contradicts your evidence, trust your gut." << endl;
                    cout << "I'm human. I'm sure I could've made a mistake or two, or been told a lie.\"" << endl;
                    type_and_continue();
                }
                else if (((userKeyword.compare("expense") == 0)
                    || (userKeyword.compare("report") == 0)
                    || (userKeyword.compare("reports") == 0))
                    && ((clueList.at(EXPENSEREPORTS)).compare("???") != 0)) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);

                    cout << get_character_name(CLYDE, INFORMAL) << " frowns." << endl;
                    cout << "\"Yes, I'm quite aware of these expense reports." << endl;
                    cout << get_character_name(DRSTRONGHOLD) << " had just secured a grant before he died." << endl;
                    cout << "It seems the mining town's mayor and his wife came to dinner to discuss it." << endl;
                    type_and_continue();

                    cout << "\n" << "They're not suspects, however. They left right after dinner, and were seen arriving in town before the murder." << endl;
                    cout << "Our suspects are just " << get_character_name(BUTLER) << ", " << get_character_name(SOUSCHEF) << ", " 
                    << get_character_name(MRSSTRONGHOLD) << ", " << get_character_name(WINECRAFTER) << ", and " << get_character_name(ASTRONOMER) << "." << endl;
                    type_and_continue();
                }
                else if (((userKeyword.compare("small") == 0)
                    || (userKeyword.compare("safe") == 0))
                    && ((clueList.at(SMALLSAFE)).compare("???") != 0)) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);

                    cout << "You ask " << get_character_name(CLYDE, INFORMAL) << " about the safe in the " << get_room_name(OFFICE) << "." << endl;
                    cout << "\"Ah, I've asked " << get_character_name(MRSSTRONGHOLD) << " about that safe." << endl;
                    cout << "Apparently only her and her husband could open it, but she's not willing to do so for us." << endl;
                    cout << "Maybe you could convince her to open it somehow, just to make sure neither of them are hiding anything.\"" << endl;
                    type_and_continue();
                }
                else if (((userKeyword.compare("locked") == 0)
                    || (userKeyword.compare("chest") == 0)
                    || (userKeyword.compare("chests") == 0))
                    && ((clueList.at(LOCKEDCHESTS)).compare("???") != 0)) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);

                    cout << get_character_name(CLYDE, INFORMAL) << " snickers as you mention the Butler and Sous Chef's locked chests." << endl;
                    cout << "\"It seems even the servants are filled with paranoia too, eh?" << endl;
                    cout << "Unfortunately, I think the servants are less likely to cooperate. Those are their closest belongings." << endl;
                    cout << "I wouldn't waste your time trying to open their chests.\"" << endl;
                    type_and_continue();
                }
                else  if (((userKeyword.compare("missing") == 0)
                    || (userKeyword.compare("knife") == 0))
                    && ((clueList.at(MISSINGKNIFE)).compare("???") != 0)) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);

                    cout << get_character_name(CLYDE, INFORMAL) << " clears his throat as you mention the missing kitchen knife." << endl;
                    cout << "\"Yes, I'm quite positive that's our murder weapon." << endl;
                    cout << "It seems to be the same one found in the " << get_room_name(MASTERBEDROOM) << ".\"" << endl;
                    type_and_continue();

                    cout << "\n" << "\"The sliced throat makes that rather obvious." << endl;
                    cout << "Unless there's some wild evidence I couldn't find, our victim died of blood loss from that wound." << endl;
                    type_and_continue();
                }
                else if (((userKeyword.compare("blood") == 0)
                    || (userKeyword.compare("stain") == 0)
                    || (userKeyword.compare("stains") == 0)
                    || (userKeyword.compare("bloodstain") == 0)
                    || (userKeyword.compare("bloodstains") == 0))
                    && ((clueList.at(BLOODSTAINS)).compare("???") != 0)) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);
                    
                    cout << get_character_name(CLYDE, INFORMAL) << "'s brow furrows." << endl;
                    cout << "\"There are some cleaned blood stains in the " << get_room_name(WINECELLAR) << "?\"" << endl;
                    cout << "You explain that you used a UV light to find them thanks to the Astronomer." << endl;
                    cout << "\"That changes everything..." << endl;
                    type_and_continue();
                    
                    cout << "\n" << get_character_name(CLYDE, INFORMAL) << " paces the room." << endl;
                    cout << "\"Well, none of the suspects claimed to be in the " << get_room_name(WINECELLAR) << " last night."<< endl;
                    cout << "Because of that, I think we can safely assume that's Dr. Stronghold's blood." << endl;
                    cout << "Now we have to figure out how it got there." << endl;
                    type_and_continue();
                }
                else if (((userKeyword.compare("cleaned") == 0)
                    || (userKeyword.compare("floor") == 0))
                    && ((clueList.at(CLEANEDFLOOR)).compare("???") != 0)) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);
                    
                    cout << get_character_name(CLYDE, INFORMAL) << " thinks for a moment." << endl;
                    cout << "\"The cleaned floor smells like bleach?\"" << endl;
                    cout << "\"Isn't the Butler using bleach to clean the " << get_room_name(BALLROOM) << "?\"" << endl;
                    type_and_continue();
                }
                else if (((userKeyword.compare("broken") == 0)
                    || (userKeyword.compare("lock") == 0))
                    && ((clueList.at(BROKENLOCK)).compare("???") != 0)) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);
                    
                    cout << "You ask " << get_character_name(CLYDE, INFORMAL) << " about the broken lock." << endl;
                    cout << "\"Mmm... Ask the Astronomer for more details, but I was told the lock broke during the blackout." << endl;
                    cout << "Whoever murdered " << get_character_name(DRSTRONGHOLD) << " probably used the balcony to escape the " << get_room_name(MASTERBEDROOM) << "." << endl;
                    type_and_continue();

                    cout << "\n" << "I'm still not sure why, though." << endl;
                    cout << "You'd think leaving through the room's main entrance would be easier." << endl;
                    type_and_continue();
                }
                else if (((userKeyword.compare("slashed") == 0)
                    || (userKeyword.compare("throat") == 0))
                    && ((clueList.at(SLASHEDTHROAT)).compare("???") != 0)) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);

                    cout << get_character_name(CLYDE, INFORMAL) << "'s eyes fill with anger." << endl;
                    cout << "\"A painful way to die... but at least it was quick.\"" << endl;
                    type_and_continue();
                }
                else if (((userKeyword.compare("foamed") == 0)
                    || (userKeyword.compare("mouth") == 0))
                    && ((clueList.at(FOAMEDMOUTH)).compare("???") != 0)) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);

                    cout << get_character_name(CLYDE, INFORMAL) << " seems a little stunned." << endl;
                    cout << "\"What?" << endl;
                    cout << "I didn't see that during my investigation." << endl;
                    cout << "I'm... truly unable to say why that happened.\"" << endl;
                    type_and_continue();
                }
                else if (((userKeyword.compare("bloody") == 0)
                    || (userKeyword.compare("garment") == 0))
                    && ((clueList.at(BLOODYGARMENT)).compare("???") != 0)) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);

                    cout << get_character_name(CLYDE, INFORMAL) << " scowls." << endl;
                    cout << "\"Detective, you found this under the bed?\"" << endl;
                    cout << "You nod at him." << endl;
                    cout << "\"This seems rather incriminating... but I'm not sure who for.\"" << endl;
                    type_and_continue();
                }
                else if (((userKeyword.compare("snowy") == 0)
                    || (userKeyword.compare("foot") == 0)
                    || (userKeyword.compare("prints") == 0)
                    || (userKeyword.compare("footprints") == 0))
                    && ((clueList.at(SNOWYFOOTPRINTS)).compare("???") != 0)) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);

                    cout << get_character_name(CLYDE, INFORMAL) << " holds his breath at the mention of the footprints." << endl;
                    cout << "\"That confused the hell out of me. I was prepared to find one set of footprints, but two?" << endl;
                    cout << "I have no idea why there are two sets.\"" << endl;
                    type_and_continue();
                }
                else {
                    int replyNum = ((rand() % 4) + 1);
                    if (replyNum == 1) {
                        cout << "\n\"I didn't find that in my investigation... Interesting.\"" << endl;
                    }
                    if (replyNum == 2) {
                        cout << "\n\"I'm not sure this is relevant to the case. Sorry.\"" << endl;
                    }
                    if (replyNum == 3) {
                        cout << "\n\"I'm not sure I can help with that.\"" << endl;
                    }
                    if (replyNum == 4) {
                        cout << "\n\"I don't know anything about that.\"" << endl;
                    }
                    type_and_continue();
                }


                //Empties console screen
                system("CLS");
                
                print_input(userKeyword);

                //Prints a title to tell the player which character they are questioning / interrogating
                print_character_questioning_title(roomNum);
                //Asks player which piece of evidence they'd like to interrogate the suspect about
                print_interrogation_request(roomNum, currentUserChoices, clueList);
                userKeyword = get_keyword_input();
            }

        }

        //Empties console screen
        system("CLS");
        //Prints a title to tell the player which character they are questioning
        print_character_questioning_title(roomNum);

        print_input(userKeyword);

        //Asks player which questions they'd like to ask Pendleton
        print_pendleton_help_request(roomNum);
        userKeyword = get_keyword_input();
    }

}

void questioning_butler(int roomNum, vector<bool>& currentUserChoices, vector<string>& clueList) {

    //Empties console screen
    system("CLS");
    //Prints a title to tell the player which character they are questioning
    print_character_questioning_title(roomNum);
    cout << "As you approach him, he bows to you with great fervor." << endl;
    cout << "\"Hello, Detective. I can be at your service whenever you wish.\"" << endl;
    //Asks player which questions they'd like to ask the suspect
    print_questioning_request(roomNum);
    string userKeyword = get_keyword_input();

    //FIXME: REMOVE INPUT PRINTER WHEN GAME IS FINISHED
    while (userKeyword.compare("stop") != 0) {

        if (userKeyword.compare("1") == 0) {

            //Empties console screen
            system("CLS");
            //Prints a title to tell the player which character they are questioning
            print_character_questioning_title(roomNum);

            cout << "\"Good evening, Detective.\"" << endl;
            cout << "He shakes your hand." << endl;
            cout << "\"My name is Sebation Gilmore." << endl;
            cout << "I serve the Stronghold family as a butler. I've also been given the opportunity to live here.\"" << endl;
            type_and_continue();

            cout << "\n" << "He looks away from you and sighs." << endl;
            cout << "\"I'd like to think I'm a no nonsense kind of person, Detective. Hard working. Efficient." << endl;
            cout << "In that same vein, I'd like to do everything in my power to find our killer." << endl;
            cout << "Please ask me any questions you have, even if they incriminate me.\"" << endl;
            type_and_continue();
        }
        if (userKeyword.compare("2") == 0) {

            //Empties console screen
            system("CLS");
            //Prints a title to tell the player which character they are questioning
            print_character_questioning_title(roomNum);

            cout << "\"He pauses to think for a moment." << endl;
            cout << "After Dinner, I grabbed a hors d'oeuvre or two from the " << get_room_name(KITCHEN) << "." << endl;
            cout << "I started cleaning the " << get_room_name(BALLROOM) << ", and did so for an hour or so.\"" << endl;
            type_and_continue();

            cout << "\n" << "His brows furrow." << endl;
            cout << "\"Oh yes, then I was told that Mrs. Stronghold wanted to sit by the " << get_room_name(LIBRARY) << " fireplace after her bath." << endl;
            cout << "I gathered some firewood from the " << get_room_name(GREENHOUSE) << " and saw the Wine Crafter." << endl;
            cout << "Then I grabbed some hors d'oeuvres for " << get_character_name(MRSSTRONGHOLD) << " and made my way to the " << get_room_name(LIBRARY) << "." << endl;
            cout << "Around the time I finished lighting the fire, " << get_character_name(MRSSTRONGHOLD) << " screamed." << endl;
            cout << "I made my way to the " << get_room_name(MASTERBEDROOM) << " and nobody left each other's sides since." << endl;
            type_and_continue();

            cout << "\n" << "\"It's a shame though. I wanted to finish cleaning the " << get_room_name(BALLROOM) << " today." << endl;
            cout << "The Butler gets a little teary eyed." << endl;
            cout << "I've been cleaning all week, but I couldn't finish " << get_character_name(DRSTRONGHOLD) << "'s final order before he died.\"" << endl;
            type_and_continue();
        }
        if (userKeyword.compare("3") == 0) {

            //Empties console screen
            system("CLS");
            //Prints a title to tell the player which character they are questioning
            print_character_questioning_title(roomNum);

            cout << "A little frown appears on " << get_character_name(BUTLER) << "'s face." << endl;
            cout << "\"I'm sure everyone is thrilled to get out their distaste for someone with meaningless gossip." << endl;
            cout << "But frankly, Detective, I think all of us would have a reason to kill " << get_character_name(DRSTRONGHOLD) << "." << endl;
            type_and_continue();

            cout << "\n" << "\"That doesn't mean I think all of us here would've, or that " << get_character_name(DRSTRONGHOLD) << " was a bad man." << endl;
            cout << "I just think it's human nature to be crushed when your wishes or hopes are denied." << endl;
            cout << "And truthfully, he's denied all of our wishes at times.\"" << endl;
            type_and_continue(); 
        }
        if (userKeyword.compare("interrogate") == 0) {

            //Empties console screen
            system("CLS");
            //Prints a title that tells the player which character they are questioning / interrogating
            print_character_questioning_title(roomNum);
            //Asks player which piece of evidence they'd like to interrogate the suspect about
            print_interrogation_request(roomNum, currentUserChoices, clueList);
            userKeyword = get_keyword_input();

            while (userKeyword.compare("end") != 0) {

                if (((userKeyword.compare("case") == 0)
                    || (userKeyword.compare("file") == 0)
                    || (userKeyword.compare("casefile") == 0))
                    && ((clueList.at(CASEFILE)).compare("???") != 0)) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);

                    cout << "As he turns the case file's pages, he looks disturbed." << endl;
                    cout << "\"It's a shame he died in an undignified fashion." << endl;
                    cout << "I always thought he would just pass in his sleep peacefully.\"" << endl;
                    type_and_continue();
                }
                else if (((userKeyword.compare("anonymous") == 0)
                    || (userKeyword.compare("letter") == 0))
                    && ((clueList.at(ANONYMOUSLETTER).compare("???") != 0))) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);

                    cout << "You show " << get_character_name(BUTLER, INFORMAL) << " the letter." << endl;
                    cout << "\"You found this in " << get_character_name(DRSTRONGHOLD) << "'s safe?" << endl;
                    cout << "I suppose he is the kind of man to be sentimental in private.\"" << endl;
                    type_and_continue();

                    cout << "\n" << "He raises his eyebrow." << endl;
                    cout << "The handwriting is quite sloppy, however.\"" << endl;
                    cout << "I think it's too sloppy to be " << get_character_name(MRSSTRONGHOLD) << "'s or mine." << endl;
                    type_and_continue();
                }
                else if (((userKeyword.compare("locked") == 0)
                    || (userKeyword.compare("chest") == 0)
                    || (userKeyword.compare("chests") == 0))
                    && ((clueList.at(LOCKEDCHESTS)).compare("???") != 0)) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);

                    cout << get_character_name(BUTLER, INFORMAL) << " shakes his head as you mention the chests." << endl;
                    cout << "\"I apologize, but I'm not interested in having you ruffle through our things." << endl;
                    cout << "I don't think you'll lose any valuable evidence if you don't inspect my undergarments.\"" << endl;
                    type_and_continue();
                }
                else if (((userKeyword.compare("red") == 0)
                    || (userKeyword.compare("velvet") == 0)
                    || (userKeyword.compare("chair") == 0) 
                    || (userKeyword.compare("chairs") == 0))
                    && ((clueList.at(REDVELVETCHAIRS)).compare("???") != 0)) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);

                    cout << "You ask " << get_character_name(BUTLER) << " where he sat during Dinner." << endl;
                    cout << "He lightly knocks his fist on his skull while trying to remember." << endl;
                    cout << "\"We tend to switch seats depending on the occassion, but we're always seated to " << get_character_name(DRSTRONGHOLD) << "'s right.\"" << endl;
                    type_and_continue();

                    cout << "\n" << "You tell " << get_character_name(BUTLER, INFORMAL) << " to clarify who this \'we\' is." << endl;
                    cout << "\"Because " << get_character_name(SOUSCHEF, INFORMAL) << " and I are " << get_character_name(DRSTRONGHOLD) << "'s staff, " << endl;
                    cout << "we don't often sit down for the whole of dinner." << endl;
                    cout << "Last night we just popped in and out of the kitchen to check on the guests and used the same empty chair.\"" << endl;
                    type_and_continue();

                    currentUserChoices.at(ASKABOUTREDVELVETCHAIRS) = true;

                }
                else if (((userKeyword.compare("stone") == 0)
                    || (userKeyword.compare("button") == 0))
                    && ((clueList.at(STONEBUTTON)).compare("???") != 0)) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);

                    cout << "The Butler's eyes widen as you hand him the button." << endl;
                    cout << "\"This is " << get_character_name(DRSTRONGHOLD) << "'s." << endl;
                    cout << "It's a part of the suit jacket he wore tonight...\"" << endl;
                    type_and_continue();

                    cout << "\n" << "He continues to study it." << endl;
                    cout << "\"The buttons are carved from granite because the townsfolk made him the suit." << endl;
                    cout << "He wore it to impress the mayor and his wife..." << endl;
                    cout << "Where did you find this?\"" << endl;
                    type_and_continue();

                    currentUserChoices.at(ASKABOUTSTONEBUTTON) = true;

                }
                else if (((userKeyword.compare("empty") == 0)
                    || (userKeyword.compare("display") == 0))
                    && ((clueList.at(EMPTYDISPLAY)).compare("???") != 0)) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);

                    cout << get_character_name(BUTLER) << " nods enthusiastically." << endl;
                    cout << "\"Ah, the \'Alain Hudelot\'. He was saving that for a special occasion." << endl;
                    cout << "He must have downed it because he secured us that grant.\"" << endl;
                    type_and_continue();

                    cout << "\n" << "But then the Butler bites his finger." << endl;
                    cout << "\"Actually, I'm unsure why the bottle would be missing though. He usually asked me to box finished bottles." << endl;
                    cout << "He liked to recycle them for the townsfolk, and to be honest, he hates cleaning for himself." << endl;
                    cout << "He would've left it on the display and requested I clean it up. I'm sure of it.\"" << endl;
                    type_and_continue();

                    currentUserChoices.at(ASKABOUTEMPTYDISPLAY) = true;

                }
                else if (((userKeyword.compare("cleaned") == 0)
                    || (userKeyword.compare("floor") == 0))
                    && ((clueList.at(CLEANEDFLOOR)).compare("???") != 0)) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);

                    cout << "You mention that the floor in the " << get_room_name(WINECELLAR) << " smells recently cleaned." << endl;
                    cout << "\"I haven't cleaned the wine cellar recently. Why are you asking me about that?\"" << endl;
                    type_and_continue();

                    cout << "\n" << "You explain that the floor smells like his bleach." << endl;
                    cout << "His face drains white." << endl;
                    cout << "\"I can only assume someone stole my cleaning supplies, but I have no idea who did.\"" << endl;
                    type_and_continue();
                }
                else if (((userKeyword.compare("glass") == 0)
                    || (userKeyword.compare("shard") == 0)
                    || (userKeyword.compare("shards") == 0))
                    && ((clueList.at(GLASSSHARDS)).compare("???") != 0)) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);

                    cout << "You hand " << get_character_name(BUTLER, INFORMAL) << " one of the glass shards." << endl;
                    cout << "\"This looks like it came from a wine bottle." << endl;
                    cout << "We don't throw away glass in this manor, however." << endl;
                    cout << "We box bottles like these and recycle them for the mining townsfolk.\"" << endl;
                    type_and_continue();

                    currentUserChoices.at(ASKABOUTGLASSSHARDS) = true;

                }
                else if (((userKeyword.compare("breaker") == 0)
                    || (userKeyword.compare("box") == 0))
                    && ((clueList.at(BREAKERBOX)).compare("???") != 0)) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);

                    cout << "You mention the breaker box and " << get_character_name(BUTLER) << " mutters something to himself." << endl;
                    cout << "\"Ah, yes. Whilst I was lighting the fire in the " << get_room_name(LIBRARY) << "I noticed the lights go off." << endl;
                    cout << "After the logs finally caught ablaze I went to the boiler room and turned them back on.\"" << endl;
                    type_and_continue();

                    cout << "\n" << get_character_name(BUTLER, INFORMAL) << "sighs." << endl;
                    cout << "\"I just did so because it's my job, but suppose that makes me a major suspect now.\"" << endl;
                    type_and_continue();
                }
                else if (((userKeyword.compare("slashed") == 0)
                    || (userKeyword.compare("throat") == 0))
                    && ((clueList.at(SLASHEDTHROAT)).compare("???") != 0)) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);

                    cout << "The Butler holds his breath." << endl;
                    cout << "\"That's very odd. I don't remember his throat being like that during dinner.\"" << endl;
                    type_and_continue();
                }
                else if (((userKeyword.compare("wet") == 0)
                    || (userKeyword.compare("boot") == 0)
                    || (userKeyword.compare("boots") == 0))
                    && ((clueList.at(WETBOOTS)).compare("???") != 0)) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);

                    cout << "You mention the boots and " << get_character_name(BUTLER, INFORMAL) << " blinks with confusion." << endl;
                    cout << "\"" << get_character_name(DRSTRONGHOLD) << " is the only one who'd own boots like that." << endl;
                    cout << "He didn't wear them to Dinner, however, and I doubt he would've gone outside in the storm.\"" << endl;
                    type_and_continue();
                }
                else if (((userKeyword.compare("cufflink") == 0))
                && ((clueList.at(CUFFLINK)).compare("???") != 0)) {

                //Empties console screen
                system("CLS");
                //Prints a title to tell the player which character they are questioning
                print_character_questioning_title(roomNum);

                cout << "You hand " << get_character_name(BUTLER, INFORMAL) << " the cufflink." << endl;
                cout << "\"Oh, you found this at the scene of the crime?" << endl;
                cout << "No, this isn't mine. I'm very careful with my belongings. Losing one doesn't suit me.\"" << endl;
                type_and_continue();
                }
                else {
                    int replyNum = ((rand() % 4) + 1);
                    if (replyNum == 1) {
                        cout << "\n\"Should I know something about that?\"" << endl;
                    }
                    if (replyNum == 2) {
                        cout << "\n\"Why are you showing me this?\"" << endl;
                    }
                    if (replyNum == 3) {
                        cout << "\n\"I'm sorry, but I have no idea how this is relevant to me.\"" << endl;
                    }
                    if (replyNum == 4) {
                        cout << "\n\"I don't know anything about that.\"" << endl;
                    }
                    type_and_continue();
                }

                //Empties console screen
                system("CLS");

                print_input(userKeyword);

                //Prints a title to tell the player which character they are questioning / interrogating
                print_character_questioning_title(roomNum);
                //Asks player which piece of evidence they'd like to interrogate the suspect about
                print_interrogation_request(roomNum, currentUserChoices, clueList);
                userKeyword = get_keyword_input();
            }

        }

        //Empties console screen
        system("CLS");
        //Prints a title to tell the player which character they are questioning
        print_character_questioning_title(roomNum);

        print_input(userKeyword);

        //Asks player which questions they'd like to ask the suspect
        print_questioning_request(roomNum);
        userKeyword = get_keyword_input();
    }
}

void questioning_souschef(int roomNum, vector<bool>& currentUserChoices, vector<string>& clueList) {

    //Empties console screen
    system("CLS");
    //Prints a title to tell the player which character they are questioning
    print_character_questioning_title(roomNum);
    cout << "As you approach her, she kicks her feet against the covers." << endl;
    cout << "\"Hi there, Detective. I can answer some questions if you have any for me.\"" << endl;
    print_questioning_request(roomNum);
    string userKeyword = get_keyword_input();

    //FIXME: REMOVE INPUT PRINTER WHEN GAME IS FINISHED
    while (userKeyword.compare("stop") != 0) {

        //Don't forget quotes when they speak
        if (userKeyword.compare("1") == 0) {

            //Empties console screen
            system("CLS");
            //Prints a title to tell the player which character they are questioning
            print_character_questioning_title(roomNum);

            cout << "\"Good to see you, Detective.\"" << endl;
            cout << "She smiles at you kindly." << endl;
            cout << "\"My name is Sue Davis." << endl;
            cout << "I'm the Head Chef of this mansion, although my official title is Sous Chef.\"" << endl;
            type_and_continue();

            cout << "\n" << "The Strongholds call me Sous Chef because they think it's funny and don't understand cooking terminology." << endl;
            cout << "Unfortunately, they aren't bright all the time.\"" << endl;
            type_and_continue();

            cout << "\n" << "\"Obviously my top priority is finding the killer so I can leave this place for good." << endl;
            cout << "Without " << get_character_name(DRSTRONGHOLD) << ", this manor will fall apart.\"" << endl;
            cout << "She frowns rather sincerely while looking at the Grandfather Clock." << endl;
            cout << "\"Ask me any questions you have. I'm happy to help." << endl;
            cout << "I'd like you to solve this quickly and efficiently so us innocent folk can go.\"" << endl;
            type_and_continue();
        }
        if (userKeyword.compare("2") == 0) {

            //Empties console screen
            system("CLS");
            //Prints a title to tell the player which character they are questioning
            print_character_questioning_title(roomNum);
            
            cout << "She stretches for a moment, thinking." << endl;
            cout << "\"Oh, whereabouts? I didn't do too much today after Dinner." << endl;
            cout << "After Dinner, I spoke to the Butler in the " << get_room_name(KITCHEN) << " for a bit." << endl;
            cout << "Then I watched the Gardener harvest some grapes and he let me have some.\"" << endl;
            type_and_continue();

            cout << "\n" << "She yawns." << endl;
            cout << "\"My apologies, it's quite late for me." << endl;
            cout << "I think after that I checked up on " << get_character_name(MRSSTRONGHOLD) << " during her bath." << endl;
            cout << "Then I just went to my room for the rest of the night.\"" << endl;
            type_and_continue();

            cout << "\n" << "\"Once I was here I took a nap, but I was awoken by " << get_character_name(MRSSTRONGHOLD) << "'s scream." << endl;
            cout << "Unfortunately, I don't believe anyone can corroberate my story, but it's the truth!\"" << endl;
            cout << "She smiles sleepily." << endl;
            cout << "\"In fact, once you leave me here, I think I'll try to finish that nap.\"" << endl;
            type_and_continue();
        }
        if (userKeyword.compare("3") == 0) {

            //Empties console screen
            system("CLS");
            //Prints a title to tell the player which character they are questioning
            print_character_questioning_title(roomNum);

            cout << get_character_name(SOUSCHEF, INFORMAL) << " sighs." << endl;
            cout << "\"I don't think I'd feel right accusing anyone outright." << endl;
            cout << "But, I think several people would have a motive.\""<< endl;
            type_and_continue();

            cout << "\n" << "\"" << get_character_name(BUTLER, INFORMAL) << " is treated more like a donkey than a worker sometimes.\"" << endl;
            cout << "He deserves more respect." << endl;
            type_and_continue();

            cout << "\n" << "\"" << get_character_name(MRSSTRONGHOLD, INFORMAL) << " is a very cold woman, too." << endl;
            cout << "I could see her slicing any of our throats open really, if she had a reason.\"" << endl;
            type_and_continue();

            cout << "\n" << "\"" << "And I don't think " << get_character_name(WINECRAFTER, INFORMAL) << "would kill anyone... " << endl;
            cout << "But " << get_character_name(DRSTRONGHOLD) << " sold some of " << get_character_name(WINECRAFTER, INFORMAL) << "'s best bottles against his wishes.\"" << endl;
            type_and_continue();
        }
        if (userKeyword.compare("interrogate") == 0) {

            //Empties console screen
            system("CLS");
            //Prints a title that tells the player which character they are questioning / interrogating
            print_character_questioning_title(roomNum);
            //Asks player which piece of evidence they'd like to interrogate the suspect about
            print_interrogation_request(roomNum, currentUserChoices, clueList);
            userKeyword = get_keyword_input();

            while (userKeyword.compare("end") != 0) {

                if (((userKeyword.compare("case") == 0)
                    || (userKeyword.compare("file") == 0)
                    || (userKeyword.compare("casefile") == 0))
                    && ((clueList.at(CASEFILE)).compare("???") != 0)) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);

                    cout << "You hand " << get_character_name(SOUSCHEF) << " the case file. She reads through it palely." << endl;
                    cout << "\"This is so wrong, detective. To kill someone so grusomely." << endl;
                    cout << "Whoever slashed " << get_character_name(DRSTRONGHOLD) << "'s throat deserves to rot in prison.\"" << endl;
                    type_and_continue();
                }
                else if (((userKeyword.compare("anonymous") == 0)
                    || (userKeyword.compare("letter") == 0))
                    && ((clueList.at(ANONYMOUSLETTER).compare("???") != 0))) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);

                    cout << "You show " << get_character_name(SOUSCHEF, INFORMAL) << " the anonymous letter. She shakes her head." << endl;
                    cout << "\"I'd bet this is a letter from one of those silly boys to celebrate the grant." << endl;
                    cout << "You'd think they could share their emotions freely instead of writing anonymous letters.\"" << endl;
                    type_and_continue();

                    cout << "\n" << "Worry fills her eyes." << endl;
                    cout << "\"You don't think this has anything to do with the murder, do you?" << endl;
                    cout << get_character_name(DRSTRONGHOLD, INFORMAL) << " died in the " << get_room_name(MASTERBEDROOM) << ", didn't he?\"" << endl;
                    type_and_continue();
                }
                else  if (((userKeyword.compare("missing") == 0)
                    || (userKeyword.compare("knife") == 0))
                    && ((clueList.at(MISSINGKNIFE)).compare("???") != 0)) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);

                    cout << get_character_name(SOUSCHEF) << "bites her lip when you ask her about the missing knife." << endl;
                    cout << "\"Oh... You must think the kitchen knife is the murder weapon since he was killed with a knife.\"" << endl;
                    type_and_continue();

                    cout << "\n" << "She seems to realize something." << endl;
                    cout << "\"I think I can help with this question." << endl;
                    cout << "After Dinner, I talked with " << get_character_name(BUTLER, INFORMAL) << " and " << get_character_name(MRSSTRONGHOLD) << " in the " << get_room_name(KITCHEN) << endl;
                    cout << "And, just as the Wine Crafter came in to escort me to the " << get_room_name(GREENHOUSE) << ", I noticed a knife was missing." << endl;
                    cout << "I didn't think much of it then. We went to the " << get_room_name(GREENHOUSE) << " soon after.\"" << endl;
                    type_and_continue();

                    cout << "\n" << "She yawns." << endl;
                    cout << "\"But... I was in the " << get_room_name(KITCHEN) << " after Dinner that whole time, and nobody else came in." << endl;
                    cout << "I think that means one of those two had to have taken it.\"" << endl;
                    type_and_continue();
                }
                else if (((userKeyword.compare("red") == 0)
                    || (userKeyword.compare("velvet") == 0)
                    || (userKeyword.compare("chair") == 0)
                    || (userKeyword.compare("chairs") == 0))
                    && ((clueList.at(REDVELVETCHAIRS)).compare("???") != 0)) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);

                    cout << "You ask " << get_character_name(SOUSCHEF, INFORMAL) << " where she sat during Dinner." << endl;
                    cout << "She taps her lips with her index finger." << endl;
                    cout << "\"Well, I wasn't sitting the whole time. I had to cook after all.\"" << endl;
                    type_and_continue();

                    cout << "\n" << "\"But... I think I sat to the right of " << get_character_name(MRSSTRONGHOLD) << ".\"" << endl;
                    cout << "We had a nice discussion about... about me making a chocolate cake for " << get_character_name(MRSSTRONGHOLD) << "'s birthday next week.\"" << endl;
                    type_and_continue();

                    cout << "\n" << "She begins to sniffle." << endl;
                    cout << "\"Sorry, I think I need a moment.\"" << endl;
                    type_and_continue();
                }
                else if (((userKeyword.compare("nightshade") == 0)
                    || (userKeyword.compare("nightshades") == 0)
                    || (userKeyword.compare("cut") == 0)
                    || (userKeyword.compare("night") == 0)
                    || (userKeyword.compare("shade") == 0)
                    || (userKeyword.compare("shades") == 0))
                    && ((clueList.at(CUTNIGHTSHADE)).compare("???") != 0)) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);

                    cout << "You tell " << get_character_name(SOUSCHEF) << " about the cut Nightshades and she frowns." << endl;
                    cout << "\"Oh, those were so pretty. I don't know why anyone would be cruel enough to cut them.\"" << endl;
                    type_and_continue();
                }
                else if (((userKeyword.compare("breaker") == 0)
                    || (userKeyword.compare("box") == 0))
                    && ((clueList.at(BREAKERBOX)).compare("???") != 0)) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);

                    cout << "You mention the breaker box and " << get_character_name(SOUSCHEF) << " smiles at you politely." << endl;
                    cout << "\"I didn't notice the lights go off. I was taking a nap, remember?\"" << endl;
                    type_and_continue();
                }
                else if (((userKeyword.compare("blood") == 0)
                    || (userKeyword.compare("stain") == 0)
                    || (userKeyword.compare("stains") == 0)
                    || (userKeyword.compare("bloodstain") == 0)
                    || (userKeyword.compare("bloodstains") == 0))
                    && ((clueList.at(BLOODSTAINS)).compare("???") != 0)) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);

                    cout << get_character_name(SOUSCHEF, INFORMAL) << "looks disturbed." << endl;
                    cout << "\"I... I'll bet one of those silly boys hurt themselves celebrating." << endl;
                    cout << "That has to be it. Right?\"" << endl;
                    type_and_continue();
                }
                else if (((userKeyword.compare("slashed") == 0)
                    || (userKeyword.compare("throat") == 0))
                    && ((clueList.at(SLASHEDTHROAT)).compare("???") != 0)) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);
                    
                    cout << get_character_name(SOUSCHEF, INFORMAL) << "looks ghastly as you talk about the slashed throat." << endl;
                    cout << "\"Stop talking about that. Please.\"" << endl;
                    type_and_continue();
                }
                else if (((userKeyword.compare("cufflink") == 0))
                    && ((clueList.at(CUFFLINK)).compare("???") != 0)) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);
                    
                    cout << "You tell her about the cufflink and she stretches." << endl;
                    cout << "\"Oh, that's odd. You found this in " << get_character_name(DRSTRONGHOLD) << "'s armoire?" << endl;
                    cout << "I suppose it must be one of " << get_character_name(BUTLER, INFORMAL) << "'s cufflinks. I wonder why that was there?\"" << endl;
                    type_and_continue();
                }
                else {
                    int replyNum = ((rand() % 4) + 1);
                    if (replyNum == 1) {
                        cout << "\n\"I don't know anything about that, Detective.\"" << endl;
                    }
                    if (replyNum == 2) {
                        cout << "\n\"I'm so tired. Stop making me focus on unimportant details.\"" << endl;
                    }
                    if (replyNum == 3) {
                        cout << "\n\"I have nothing to say on that matter.\"" << endl;
                    }
                    if (replyNum == 4) {
                        cout << "\n\"I wish I could help, but I'm not sure what to say.\"" << endl;
                    }
                    type_and_continue();
                }

                //Empties console screen
                system("CLS");

                print_input(userKeyword);

                //Prints a title to tell the player which character they are questioning / interrogating
                print_character_questioning_title(roomNum);
                //Asks player which piece of evidence they'd like to interrogate the suspect about
                print_interrogation_request(roomNum, currentUserChoices, clueList);
                userKeyword = get_keyword_input();
            }

        }

        //Empties console screen
        system("CLS");
        //Prints a title to tell the player which character they are questioning
        print_character_questioning_title(roomNum);

        print_input(userKeyword);

        //Asks player which questions they'd like to ask the suspect
        print_questioning_request(roomNum);
        userKeyword = get_keyword_input();
    }

}

void questioning_mrsstronghold(int roomNum, vector<bool>& currentUserChoices, vector<string>& clueList) {

    //Empties console screen
    system("CLS");
    //Prints a title to tell the player which character they are questioning
    print_character_questioning_title(roomNum);
    cout << "As you approach her, she taps her fountain pen on the page blankly." << endl;
    cout << "\"I don't suppose you're just going to stand there, are you?\"" << endl;
    //Asks player which questions they'd like to ask the suspect
    print_questioning_request(roomNum);
    string userKeyword = get_keyword_input();

    //FIXME: REMOVE INPUT PRINTER WHEN GAME IS FINISHED
    while (userKeyword.compare("stop") != 0) {

        
        if (userKeyword.compare("1") == 0) {

            //Empties console screen
            system("CLS");
            //Prints a title to tell the player which character they are questioning
            print_character_questioning_title(roomNum);

            cout << "You ask " << get_character_name(MRSSTRONGHOLD, INFORMAL) << " for an introduction and she scowls at you." << endl;
            cout << "\"I'm Mrs. Stronghold, obviously. Shouldn't you already know that, detective?\"" << endl;
            cout << "She sighs and returns to her writing." << endl;
            type_and_continue();
        }
        if (userKeyword.compare("2") == 0) {

            //Empties console screen
            system("CLS");
            //Prints a title to tell the player which character they are questioning
            print_character_questioning_title(roomNum);

            cout << get_character_name(MRSSTRONGHOLD, INFORMAL) << " rubs her forehead." << endl;
            cout << "\"After Dinner, I had a quick chat with my husband. It wasn't about anything particularly exciting." << endl;
            cout << "He told me he had some paperwork to do, so I went upstairs to take a nice bath and freshen up before bed." << endl;
            cout << "To my knowledge, he went into his " << get_room_name(OFFICE) << ".\""<< endl;
            type_and_continue();

            cout << "\n" << get_character_name(MRSSTRONGHOLD) << " takes a moment to collect herself." << endl;
            cout << "\"Almost an hour into my bath, " << get_character_name(SOUSCHEF, INFORMAL) << " checked up on me." << endl;
            cout << "She seemed in good spirits, and I was glad for that." << endl;
            cout << "I finished my skin cleanse soon after, and then the lights shut off.\"" << endl;
            type_and_continue();

            cout << "\n" << get_character_name(MRSSTRONGHOLD, INFORMAL) << " crosses her arms, clearly tensing up." << endl;
            cout << "\"When the lights shut off, I stayed in my bath for a while after, trying to relax." << endl;
            cout << "But, frankly, the " << get_room_name(MASTERBEDROOM) << " felt rather eerie in the candlelight." << endl;
            cout << "Against my better instincts, I came out of the bathroom because I thought I heard my husband!" << endl;
            cout << "Instead, I found my husband's body on the bed and the balcony door wide open.\"" << endl;
            type_and_continue();
        }
        if (userKeyword.compare("3") == 0) {

            //Empties console screen
            system("CLS");
            //Prints a title to tell the player which character they are questioning
            print_character_questioning_title(roomNum);

            cout << get_character_name(MRSSTRONGHOLD, INFORMAL) << " smirks." << endl;
            cout << "\"Yes, as a matter of fact I do." << endl;
            cout << get_character_name(ASTRONOMER, INFORMAL) << ", my husband's colleague, is a money hungry whore." << endl;
            cout << "She's so desperate for some money my husband \'owed\' her that she probably slit his throat.\"" << endl;
            type_and_continue();
        }
        if (userKeyword.compare("interrogate") == 0) {

            //Empties console screen
            system("CLS");
            //Prints a title that tells the player which character they are questioning / interrogating
            print_character_questioning_title(roomNum);
            //Asks player which piece of evidence they'd like to interrogate the suspect about
            print_interrogation_request(roomNum, currentUserChoices, clueList);
            userKeyword = get_keyword_input();

            while (userKeyword.compare("end") != 0) {

                if (((userKeyword.compare("case") == 0)
                    || (userKeyword.compare("file") == 0)
                    || (userKeyword.compare("casefile") == 0))
                    && ((clueList.at(CASEFILE)).compare("???") != 0)) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);

                    cout << "You show " << get_character_name(MRSSTRONGHOLD) << " the case file and she crosses her arms." << endl;
                    cout << "\"I think you added me as a suspect on accident." << endl;
                    cout << "Perhaps you should remove me from the pool and start looking for the real murderer.\"" << endl;
                    type_and_continue();
                }
                else if (((userKeyword.compare("small") == 0)
                    || (userKeyword.compare("safe") == 0))
                    && ((clueList.at(SMALLSAFE)).compare("???") != 0)) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);

                    cout << get_character_name(MRSSTRONGHOLD, INFORMAL) << "glares at you as you talk about the safe." << endl;
                    cout << "\"Oh, you'd like to look in the safe?" << endl;
                    cout << "Sure! I can get out my baby pictures and we can invade my privacy together!\"" << endl;
                    type_and_continue();
                }
                else if (((userKeyword.compare("insurance") == 0)
                    || (userKeyword.compare("policy") == 0))
                    && ((clueList.at(INSURANCEPOLICY)).compare("???") != 0)) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);

                    cout << "You wave the insurance policy in " << get_character_name(MRSSTRONGHOLD) << "'s face and she tears up." << endl;
                    cout << "\"Don't rub it in, Detective. Just arrest me and move on. Let me rot in peace.\"" << endl;
                    type_and_continue();
                }
                else if (((userKeyword.compare("anonymous") == 0)
                    || (userKeyword.compare("letter") == 0))
                    && ((clueList.at(ANONYMOUSLETTER).compare("???") != 0))) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);

                    cout << "You show " << get_character_name(MRSSTRONGHOLD) << " the letter. She seems concerned." << endl;
                    cout << "\"I was unaware a letter liked this existed." << endl;
                    cout << "I don't know why anyone would want him celebrating alone.\"" << endl;
                    type_and_continue();

                    cout << "\n" << "She looks at you with pained eyes." << endl;
                    cout << "\"Is there another murderer in this house besides me?\"" << endl;
                    type_and_continue();
                }
                else if (((userKeyword.compare("missing") == 0)
                    || (userKeyword.compare("knife") == 0))
                    && ((clueList.at(MISSINGKNIFE)).compare("???") != 0)) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);

                    cout << get_character_name(MRSSTRONGHOLD) << " cracks her fingers." << endl;
                    cout << "\"Someone took a knife from my kitchen?" << endl;
                    cout << "That must be the murder weapon then, yes?\"" << endl;
                    type_and_continue();

                    cout << "\n" << "\"Perhaps " << get_character_name(SOUSCHEF, INFORMAL) << " is more vicious than I thought.\"" << endl;
                    cout << "I suppose she chops fish heads. Chopping up a husband would be a simple task for her.\"" << endl;
                    type_and_continue();
                }
                else if (((userKeyword.compare("red") == 0)
                    || (userKeyword.compare("velvet") == 0)
                    || (userKeyword.compare("chair") == 0)
                    || (userKeyword.compare("chairs") == 0))
                    && ((clueList.at(REDVELVETCHAIRS)).compare("???") != 0)) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);

                    cout << get_character_name(MRSSTRONGHOLD, INFORMAL) << " puts down her pen." << endl;
                    cout << "\"Well, I don't remember too much, but I think I sat directly across from the mayor." << endl;
                    cout << "And... I think the mayor's wife was to the mayor's left." << endl;
                    cout << "Why do you ask, Detective? Playing Duck Duck Goose?\"" << endl;
                    type_and_continue();
                }
                else if (((userKeyword.compare("stone") == 0)
                    || (userKeyword.compare("button") == 0))
                    && ((clueList.at(STONEBUTTON)).compare("???") != 0)) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);

                    cout << "You offer " << get_character_name(MRSSTRONGHOLD, INFORMAL) << " a chance to inspect the button and she snickers." << endl;
                    cout << "\"A button? How in God's name is this relevant to the case?\"" << endl;
                    type_and_continue();

                    cout << "\n" << "She sighs and lays on her escritoire." << endl;
                    cout << "\"I suppose this is all hopeless. You'll never find the killer, will you?\"" << endl;
                    type_and_continue();
                }
                else if (((userKeyword.compare("breaker") == 0)
                    || (userKeyword.compare("box") == 0))
                    && ((clueList.at(BREAKERBOX)).compare("???") != 0)) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);

                    cout << "You ask " << get_character_name(MRSSTRONGHOLD) << " when the lights went off. She ponders it" << endl;
                    cout << "\"Well, it was definitely during my bath, but it was well after " << get_character_name(SOUSCHEF, INFORMAL) << "checked in on me.\"" << endl;
                    type_and_continue();

                    cout << "\n\"As for when they turned on?" << endl;
                    cout << "They turned on right around the time the murderer made their escape." << endl;
                    cout << "As I walked out of the bathroom, I saw them, but I didn't think to follow them because I saw his body." << endl;
                    cout << "After seeing my husband like that, I just screamed, and everyone came running.\"" << endl;
                    type_and_continue();
                }
                else if (((userKeyword.compare("slashed") == 0)
                    || (userKeyword.compare("throat") == 0))
                    && ((clueList.at(SLASHEDTHROAT)).compare("???") != 0)) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);

                    cout << "She rubs her neck at the mention of the slashed throat." << endl;
                    cout << "\"Yes, considering I found his body, I got an excruciatingly long look at my husband's slashed throat." << endl;
                    cout << "Perhaps next you'd like me to recreate my tears so you can taste them?\"" << endl;
                    type_and_continue();
                }
                else if (((userKeyword.compare("foamed") == 0)
                    || (userKeyword.compare("mouth") == 0))
                    && ((clueList.at(FOAMEDMOUTH)).compare("???") != 0)) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);

                    cout << get_character_name(MRSSTRONGHOLD) << " looks visably shocked when you ask her about " << get_character_name(DRSTRONGHOLD) << "'s foamed mouth." << endl;
                    cout << "\"Why are you getting distracted by a foamy mouth? My husband's throat was slashed!" << endl;
                    cout << "Focus, Detective. Don't start talking about what he ate for breakfast or other nonsense!\"" << endl;
                    type_and_continue();
                }
                else if (((userKeyword.compare("bloody") == 0)
                    || (userKeyword.compare("garment") == 0))
                    && ((clueList.at(BLOODYGARMENT)).compare("???") != 0)) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);

                    cout << get_character_name(MRSSTRONGHOLD) << " takes a deep breath as you show her the bloody garment." << endl;
                    cout << "\"I suppose the blood must've dripped under the bed. How awful.\"" << endl;
                    type_and_continue();
                }
                else if (((userKeyword.compare("wet") == 0)
                    || (userKeyword.compare("boot") == 0)
                    || (userKeyword.compare("boots") == 0))
                    && ((clueList.at(WETBOOTS)).compare("???") != 0)) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);

                    cout << "You take out the boots and " << get_character_name(MRSSTRONGHOLD) << " gnashes her teeth." << endl;
                    cout << "\"Oh. Those were in my armoire? How strange.\"" << endl;
                    type_and_continue();
                }
                else if (((userKeyword.compare("cufflink") == 0))
                    && ((clueList.at(CUFFLINK)).compare("???") != 0)) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);

                    cout << "You hand " << get_character_name(MRSSTRONGHOLD, INFORMAL) << " the cufflink." << endl;
                    cout << "\"You found this in my husband's armoire?" << endl;
                    cout << "This looks like one of the staff's...\"" << endl;
                    type_and_continue();

                    currentUserChoices.at(ASKABOUTCUFFLINK) = true;

                }
                else if (((userKeyword.compare("washed") == 0)
                    || (userKeyword.compare("sink") == 0))
                    && ((clueList.at(WASHEDSINK)).compare("???") != 0)) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);

                    cout << get_character_name(MRSSTRONGHOLD) << "'s eyes fill with malice." << endl;
                    cout << "\"I don't see what's so strange about a washed sink." << endl;
                    cout << "Like I said earlier, I was in the bathroom when my husband was killed." << endl;
                    cout << "I probably used the sink before my bath. Why does it matter?\"" << endl;
                    type_and_continue();
                }
                else if (((userKeyword.compare("snowy") == 0)
                || (userKeyword.compare("foot") == 0)
                || (userKeyword.compare("prints") == 0)
                || (userKeyword.compare("footprints") == 0))
                && ((clueList.at(SNOWYFOOTPRINTS)).compare("???") != 0)) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);

                    cout << get_character_name(MRSSTRONGHOLD) << " looks at you like you're crazy." << endl;
                    cout << "\"How could there be two sets of footprints in the snow?" << endl;
                    cout << "Are you blind, Detective?\"" << endl;
                    type_and_continue();
                }
                else {
                    int replyNum = ((rand() % 4) + 1);
                    cout << replyNum;
                    if (replyNum == 1) {
                        cout << "\n\"Why would I know anything about that?\"" << endl;
                    }
                    if (replyNum == 2) {
                        cout << "\n\"You probably know more about that than me, Detective, since you're so smart.\"" << endl;
                    }
                    if (replyNum == 3) {
                        cout << "\n\"Do you have to show me every pointless thing you find sniffing around my home?\"" << endl;
                    }
                    if (replyNum == 4) {
                        cout << "\n\"I have no idea why this \'evidence\' is relevant to your case." << endl;
                        cout << "Why don't you use those scattered brain cells of yours to determine that yourself?\"" << endl;
                    }
                    type_and_continue();
                }
                
                //Empties console screen
                system("CLS");

                print_input(userKeyword);

                //Prints a title to tell the player which character they are questioning / interrogating
                print_character_questioning_title(roomNum);
                //Asks player which piece of evidence they'd like to interrogate the suspect about
                print_interrogation_request(roomNum, currentUserChoices, clueList);
                userKeyword = get_keyword_input();

            }

        }

        //Empties console screen
        system("CLS");
        //Prints a title to tell the player which character they are questioning
        print_character_questioning_title(roomNum);

        print_input(userKeyword);

        //Asks player which questions they'd like to ask the suspect
        print_questioning_request(roomNum);
        userKeyword = get_keyword_input();
    }

}

void questioning_winecrafter(int roomNum, vector<bool>& currentUserChoices, vector<string>& clueList) {

    //Empties console screen
    system("CLS");
    //Prints a title to tell the player which character they are questioning
    print_character_questioning_title(roomNum);
    cout << "As you approach him, he drops a handful of grapes into a nearby bucket." << endl;
    cout << "\"Question me, but be quick. Grapes aren't in season forever.\"" << endl;
    //Asks player which questions they'd like to ask the suspect
    print_questioning_request(roomNum);
    string userKeyword = get_keyword_input();

    //FIXME: REMOVE INPUT PRINTER WHEN GAME IS FINISHED
    while (userKeyword.compare("stop") != 0) {

        //Don't forget quotes when they speak
        if (userKeyword.compare("1") == 0) {

            //Empties console screen
            system("CLS");
            //Prints a title to tell the player which character they are questioning
            print_character_questioning_title(roomNum);

            cout << "The Wine Crafter shakes your hand sternly." << endl;
            cout << "\"Nice to meet you, Detective." << endl;
            cout << "My name is Louis Arbert. Snooping detectives and friends call me Lou.\"" << endl;
            type_and_continue();

            cout << "\n" << "He smiles warmly." << endl;
            cout << "\"Bad joke, my apologies." << endl;
            cout << "I'm a friend and long time colleague of " << get_character_name(DRSTRONGHOLD) << "'s." << endl;
            cout << "I came for Dinner tonight because we were supposed to celebrate " << get_character_name(DRSTRONGHOLD) << "'s latest achievement." << endl;
            cout << "He secured a grant from the local mining town and wanted to get drunk.\"" << endl;
            type_and_continue();
        }
        if (userKeyword.compare("2") == 0) {

            //Empties console screen
            system("CLS");
            //Prints a title to tell the player which character they are questioning
            print_character_questioning_title(roomNum);

            cout << get_character_name(WINECRAFTER, INFORMAL) << " sets down his bucket to think." << endl;
            cout << "\"When everyone left the " << get_room_name(DININGROOM) << " I stayed to finish my meal." << endl;
            cout << "The Sous Chef prepared me some tender seared scallops that I paired with a beautiful Chenin Blanc." << endl;
            cout << "I headed to the " << get_room_name(KITCHEN) << " once I finished them.\"" << endl;
            type_and_continue();

            cout << "\n" << "He mutters something to himself." << endl;
            cout << "\"Ah, yes." << endl;
            cout << "I then offered " << get_character_name(SOUSCHEF, INFORMAL) << " a tour of the " << get_room_name(GREENHOUSE) << " since she'd been so lovely tonight." << endl;
            cout << "She accepted my offer and I gave her a personalized tour to discuss the vines and the flowers." << endl;
            cout << "Once we finished the tour she went on her way, and I've been picking grapes since.\"" << endl;
            type_and_continue();

            cout << "\n" << "\"Oh, I suppose after that " << get_character_name(BUTLER) << " also came in to grab some logs." << endl;
            cout << "I presume he had some reason to do so.\"" << endl;
            type_and_continue();
        }
        if (userKeyword.compare("3") == 0) {

            //Empties console screen
            system("CLS");
            //Prints a title to tell the player which character they are questioning
            print_character_questioning_title(roomNum);

            cout << "You ask about " << get_character_name(WINECRAFTER, INFORMAL) << "'s suspicions and he takes a deep breath." << endl;
            cout << "\"I'm not a very insightful person, to be honest." << endl;
            cout << "I do think, however, that " << get_character_name(MRSSTRONGHOLD) << " was oddly quiet during dinner." << endl;
            cout << "She seemed quite preoccupied and didn't say a word to her husband. I think that's rather unlike her.\"" << endl;
            type_and_continue();
        }
        if (userKeyword.compare("4") == 0) {

            //Empties console screen
            system("CLS");
            //Prints a title to tell the player which character they are questioning
            print_character_questioning_title(roomNum);

            if (currentUserChoices.at(ENTERWINECELLAR) == true) {
                cout << get_character_name(WINECRAFTER) << " sighs as you explain how dim the " << get_room_name(WINECELLAR) << " is." << endl;
                cout << "\"Fine, Detective. Take my flashlight, but you'd better find something worthwhile down there." << endl;
                cout << "Just type \'flashlight\' when you're asked what you'd like to investigate. It'll do the work from there.\"" << endl;
                type_and_continue();

                currentUserChoices.at(GETFLASHLIGHT) = true;

            }
            else {
                cout << get_character_name(WINECRAFTER) << " scowls at you." << endl;
                cout << "\"What could you possibly need my flashlight for?\"" << endl;
                type_and_continue();
             }

        }
        if (userKeyword.compare("interrogate") == 0) {

            //Empties console screen
            system("CLS");
            //Prints a title that tells the player which character they are questioning / interrogating
            print_character_questioning_title(roomNum);
            //Asks player which piece of evidence they'd like to interrogate the suspect about
            print_interrogation_request(roomNum, currentUserChoices, clueList);
            userKeyword = get_keyword_input();

            while (userKeyword.compare("end") != 0) {

                if (((userKeyword.compare("case") == 0)
                    || (userKeyword.compare("file") == 0)
                    || (userKeyword.compare("casefile") == 0))
                    && ((clueList.at(CASEFILE)).compare("???") != 0)) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);

                    cout << get_character_name(WINECRAFTER, INFORMAL) << " looks over the papers emptily." << endl;
                    cout << "\"It's such a tragedy. We were celebrating the chance of a better future hours ago." << endl;
                    cout << "Past grants always brought us good fortune, but this one will just mark" << get_character_name(DRSTRONGHOLD) << "'s bitter end.\"" << endl;
                    type_and_continue();

                }
                else if (((userKeyword.compare("expense") == 0)
                    || (userKeyword.compare("report") == 0)
                    || (userKeyword.compare("reports") == 0))
                    && ((clueList.at(EXPENSEREPORTS)).compare("???") != 0)) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);

                    cout << "\"Ah, some of these are from our buisness." << endl;
                    cout << "We sold my luxury wines together, although " << get_character_name(DRSTRONGHOLD) << " overstepped at times.\"" << endl;
                    type_and_continue();

                    currentUserChoices.at(ASKABOUTEXPENSEREPORTS) = true;
                }
                else if (((userKeyword.compare("anonymous") == 0)
                    || (userKeyword.compare("letter") == 0))
                    && ((clueList.at(ANONYMOUSLETTER).compare("???") != 0))) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);

                    cout << get_character_name(WINECRAFTER) << " looks over the letter with shock." << endl;
                    cout << "\"I was wondering why " << get_character_name(DRSTRONGHOLD) << " didn't call me to celebrate after Dinner." << endl;
                    cout << "I guess this explains it, but it certainly creates more questions than answers.\"" << endl;
                }
                else if (((userKeyword.compare("red") == 0)
                    || (userKeyword.compare("velvet") == 0)
                    || (userKeyword.compare("chair") == 0)
                    || (userKeyword.compare("chairs") == 0))
                    && ((clueList.at(REDVELVETCHAIRS)).compare("???") != 0)) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);

                    cout << "You ask " << get_character_name(WINECRAFTER, INFORMAL) << " where he sat during Dinner." << endl;
                    cout << "He squeezes some grapes in the bucket." << endl;
                    cout << "\"Hmm... I believe I was on the third chair to the left of " << get_character_name(DRSTRONGHOLD) << ".\"" << endl;
                    type_and_continue();

                    cout << "I'm also quite sure " << get_character_name(MRSSTRONGHOLD) << " was sat directly to her husband's right." << endl;
                    type_and_continue();
                }
                else if (((userKeyword.compare("nightshade") == 0)
                    || (userKeyword.compare("nightshades") == 0)
                    || (userKeyword.compare("cut") == 0)
                    || (userKeyword.compare("night") == 0)
                    || (userKeyword.compare("shade") == 0)
                    || (userKeyword.compare("shades") == 0))
                    && ((clueList.at(CUTNIGHTSHADE)).compare("???") != 0)) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);

                    cout << get_character_name(WINECRAFTER) << "'s jaw drops." << endl;
                    cout << "\"That's news to me. As a responsible gardener, I would never cut a Nightshade's stem off without extreme caution." << endl;
                    cout << "Ingesting even the smallest of its leaves could kill a man.\"" << endl;
                    type_and_continue();

                    currentUserChoices.at(ASKABOUTCUTNIGHTSHADE) = true;

                }
                else if (((userKeyword.compare("empty") == 0)
                    || (userKeyword.compare("display") == 0))
                    && ((clueList.at(EMPTYDISPLAY)).compare("???") != 0)) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);

                    cout << get_character_name(WINECRAFTER, INFORMAL) << " nods his head." << endl;
                    cout << "Yes yes, we were planning to celebrate with that bottle tonight." << endl;
                    cout << "You're saying it's gone?" << endl;
                    type_and_continue();

                    cout << "\n" << "He crosses his arms, clearly hurt." << endl;
                    cout << "\"Apparently he celebrated without me.\"" << endl;
                    type_and_continue();

                    currentUserChoices.at(ASKABOUTEMPTYDISPLAY) = true;

                }
                else if (((userKeyword.compare("glass") == 0)
                    || (userKeyword.compare("shard") == 0)
                    || (userKeyword.compare("shards") == 0))
                    && ((clueList.at(GLASSSHARDS)).compare("???") != 0)) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);

                    cout << "You hand " << get_character_name(WINECRAFTER) << " a shard of glass." << endl;
                    cout << "\"Yes, this looks as though it came from the bottle we were going to use in celebration tonight.\"" << endl;
                    cout << "He points to a ripped sticker on the shard's edge." << endl;
                    cout << "\"I can make out the \'Ala\' of \'Alain Hudelot\' if I look closely.\"" << endl;
                    type_and_continue();

                    currentUserChoices.at(ASKABOUTGLASSSHARDS) = true;

                }
                else if (((userKeyword.compare("breaker") == 0)
                    || (userKeyword.compare("box") == 0))
                    && ((clueList.at(BREAKERBOX)).compare("???") != 0)) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);

                    cout << "You ask " << get_character_name(WINECRAFTER, INFORMAL) << " about the blackout. He chuckles." << endl;
                    cout << "\"I wouldn't have noticed it, Detective." << endl;
                    cout << "We don't have lights installed out here, hence the flashlight.\"" << endl;
                    type_and_continue();
                }
                else {
                    int replyNum = ((rand() % 4) + 1);
                    if (replyNum == 1) {
                        cout << "\n\"I'm not sure what that is or what that means, Detective.\"" << endl;
                    }
                    if (replyNum == 2) {
                        cout << "\n\"That has nothing to do with wine.\"" << endl;
                    }
                    if (replyNum == 3) {
                        cout << "\n\"I'll be honest, Detective, that evidence means nothing to me.\"" << endl;
                    }
                    if (replyNum == 4) {
                        cout << "\n\"Please don't show me anything boring or gross, thank you very much.\"" << endl;
                    }
                    type_and_continue();
                }

                //Empties console screen
                system("CLS");

                print_input(userKeyword);

                //Prints a title to tell the player which character they are questioning / interrogating
                print_character_questioning_title(roomNum);
                //Asks player which piece of evidence they'd like to interrogate the suspect about
                print_interrogation_request(roomNum, currentUserChoices, clueList);
                userKeyword = get_keyword_input();

            }

        }

        //Empties console screen
        system("CLS");
        //Prints a title to tell the player which character they are questioning
        print_character_questioning_title(roomNum);

        print_input(userKeyword);

        //Asks player which questions they'd like to ask the suspect
        print_questioning_request(roomNum);
        userKeyword = get_keyword_input();
    }

}

void questioning_mudman(int roomNum, vector<bool>& currentUserChoices, vector<string>& clueList) {

    //Empties console screen
    system("CLS");
    //Prints a title to tell the player which character they are questioning
    print_character_questioning_title(roomNum);
    cout << "\"Mud. Mud mud mud.\"" << endl;
    //Asks player which questions they'd like to ask the suspect
    print_questioning_request(roomNum);
    string userKeyword = get_keyword_input();

    //FIXME: REMOVE INPUT PRINTER WHEN GAME IS FINISHED
    while (userKeyword.compare("stop") != 0) {

        //Don't forget quotes when they speak
        if (userKeyword.compare("1") == 0) {
            cout << "\"MUDMAN!!!\"" << endl;
            type_and_continue();
        }
        if (userKeyword.compare("2") == 0) {
            cout << "\"MUD!!!\"" << endl;
            type_and_continue();
        }
        if (userKeyword.compare("3") == 0) {
            cout << "\"mud....\"" << endl;
            type_and_continue();
        }
        if (userKeyword.compare("interrogate") == 0) {

            //Empties console screen
            system("CLS");
            //Prints a title that tells the player which character they are questioning / interrogating
            print_character_questioning_title(roomNum);
            //Asks player which piece of evidence they'd like to interrogate the suspect about
            print_interrogation_request(roomNum, currentUserChoices, clueList);
            userKeyword = get_keyword_input();

            while (userKeyword.compare("end") != 0) {

                if (((userKeyword.compare("late") == 0)
                    || (userKeyword.compare("check") == 0))
                    && ((clueList.at(LATECHECK)).compare("???") != 0)) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);

                    cout << "\"Mud. Mud Mud.\"" << endl;
                    type_and_continue();
                }
                else if (((userKeyword.compare("anonymous") == 0)
                    || (userKeyword.compare("letter") == 0))
                    && ((clueList.at(ANONYMOUSLETTER)).compare("???") != 0)) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);

                    cout << "\"MUUUDDD!!!\"" << endl;
                    type_and_continue();
                }
                else if (((userKeyword.compare("missing") == 0)
                    || (userKeyword.compare("knife") == 0))
                    && ((clueList.at(MISSINGKNIFE)).compare("???") != 0)) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);

                    cout << "\"Mud is love. Mud is life.\"" << endl;
                    type_and_continue();
                }
                else if (((userKeyword.compare("red") == 0)
                    || (userKeyword.compare("velvet") == 0)
                    || (userKeyword.compare("chair") == 0)
                    || (userKeyword.compare("chairs") == 0))
                    && ((clueList.at(REDVELVETCHAIRS)).compare("???") != 0)) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);

                    cout << "\"Mud....\"" << endl;
                    type_and_continue();
                }
                else if (((userKeyword.compare("cut") == 0)
                    || (userKeyword.compare("night") == 0)
                    || (userKeyword.compare("shade") == 0)
                    || (userKeyword.compare("shades") == 0)
                    || (userKeyword.compare("nightshade") == 0)
                    || (userKeyword.compare("nightshades") == 0))
                    && ((clueList.at(CUTNIGHTSHADE)).compare("???") != 0)) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);

                    cout << "\"Mud???\"" << endl;
                    type_and_continue();
                }
                else if (((userKeyword.compare("broken") == 0)
                    || (userKeyword.compare("lock") == 0))
                    && ((clueList.at(BROKENLOCK)).compare("???") != 0)) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);

                    cout << "The Mudman doesn't respond, he simply starts rolling in his mud excitedly." << endl;
                    type_and_continue();
                }
                else if (((userKeyword.compare("wet") == 0)
                    || (userKeyword.compare("boot") == 0)
                    || (userKeyword.compare("boots") == 0))
                    && ((clueList.at(WETBOOTS)).compare("???") != 0)) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);

                    cout << "The Mudman seems to become very angry at this question and begins screaming incoherently while he throws mud at you." << endl;
                    type_and_continue();
                }
                else {
                    int replyNum = ((rand() % 4) + 1);
                    if (replyNum == 1) {
                        cout << "\n\"Mud.\"" << endl;
                    }
                    if (replyNum == 2) {
                        cout << "\n\"Mud Mud Mud.\"" << endl;
                    }
                    if (replyNum == 3) {
                        cout << "\n\"MUD!\"" << endl;
                    }
                    if (replyNum == 4) {
                        cout << "\n\"Mud Mud?\"" << endl;
                    }
                    type_and_continue();
                }

                //Empties console screen
                system("CLS");

                print_input(userKeyword);

                //Prints a title to tell the player which character they are questioning / interrogating
                print_character_questioning_title(roomNum);
                //Asks player which piece of evidence they'd like to interrogate the suspect about
                print_interrogation_request(roomNum, currentUserChoices, clueList);
                userKeyword = get_keyword_input();

            }

        }

        //Empties console screen
        system("CLS");
        //Prints a title to tell the player which character they are questioning
        print_character_questioning_title(roomNum);

        print_input(userKeyword);

        //Asks player which questions they'd like to ask the suspect
        print_questioning_request(roomNum);
        userKeyword = get_keyword_input();
    }

}

void questioning_astronomer(int roomNum, vector<bool>& currentUserChoices, vector<string>& clueList) {

    //Empties console screen
    system("CLS");
    //Prints a title to tell the player which character they are questioning
    print_character_questioning_title(roomNum);
    cout << "As you approach her, she sits down in a small chair beside the telescope." << endl;
    cout << "She sighs. \"It's a shame that the stars aren't out tonight.\"" << endl;
    cout << "\"What can I do for you?\"" << endl;
    //Asks player which questions they'd like to ask the suspect
    print_questioning_request(roomNum);
    string userKeyword = get_keyword_input();

    //FIXME: REMOVE INPUT PRINTER WHEN GAME IS FINISHED
    while (userKeyword.compare("stop") != 0) {

        //Don't forget quotes when they speak
        if (userKeyword.compare("1") == 0) {

            //Empties console screen
            system("CLS");
            //Prints a title to tell the player which character they are questioning
            print_character_questioning_title(roomNum);

            cout << "The Astronomer gives you a respectful bow in her chair." << endl;
            cout << "\"My name is Dr. Jill Tyson." << endl;
            cout << "I've worked very closely with Dr.Stronghold for years." << endl;
            cout << "The work we've done through the years has been incredible for our scientific fields.\"" << endl;
            type_and_continue();

            cout << "\n" << "She swears under her breath." << endl;
            cout << "\"It's not fair that he died in such a cruel fashion." << endl;
            cout << "He wasn't perfect, but he truly cared about the science. He taught me so much, too.\"" << endl;
            type_and_continue();
        }
        if (userKeyword.compare("2") == 0) {

            //Empties console screen
            system("CLS");
            //Prints a title to tell the player which character they are questioning
            print_character_questioning_title(roomNum);

            cout << get_character_name(ASTRONOMER) << " nods eagerly." << endl;
            cout << "\"After Dinner I came straight up to the observatory." << endl;
            cout << "I'm doing some experiments on fluorescent rocks so I continued my research." << endl;
            cout << "Some of them glow like fireflies under the purple UV light. It's truly spectacular." << endl;
            type_and_continue();

            cout << "\n" << get_character_name(ASTRONOMER, INFORMAL) << " scratches her head." << endl;
            cout << "I had a big problem when the power went out though." << endl;
            cout << "See, the door to my mini lab is secured with a keycard, so when the power went out I was trapped inside." << endl;
            type_and_continue();

            cout << "\n" << "She bites her lip." << endl;
            cout << "The problem is, no one can account for my story." << endl;
            cout << "See, When the power turned back on, I immediately ran to the " << get_room_name(MASTERBEDROOM) << "." << endl;
            cout << "Unfortunately, I was much more concerned about " << get_character_name(MRSSTRONGHOLD) << "'s scream than securing an alibi." << endl;
            type_and_continue();
        }
        if (userKeyword.compare("3") == 0) {

            //Empties console screen
            system("CLS");
            //Prints a title to tell the player which character they are questioning
            print_character_questioning_title(roomNum);

            cout << get_character_name(ASTRONOMER, INFORMAL) << " shrugs when you ask about potential motives." << endl;
            cout << "\"I don't really know." << endl;
            cout << "I'm not close with most of the people here... well..." << endl;
            cout << get_character_name(DRSTRONGHOLD) << " did tell me he was going to fire " << get_character_name(SOUSCHEF) << ".\"" << endl;
            type_and_continue();

            cout << "\n" << "She ponders something for a moment." << endl;
            cout << "\"However, I don't think " << get_character_name(DRSTRONGHOLD) << " told her that yet." << endl;
            cout << "It's not a solid motive if she didn't know she was being fired.\"" << endl;
            type_and_continue();
        }
        if (userKeyword.compare("4") == 0) {

            //Empties console screen
            system("CLS");
            //Prints a title to tell the player which character they are questioning
            print_character_questioning_title(roomNum);

            if (currentUserChoices.at(GIVELATECHECK) != true) {
                cout << get_character_name(ASTRONOMER) << " sighs." << endl;
                cout << "Detective, I'd be happy to help, but I want you to do something for me first." << endl;
                cout << get_character_name(DRSTRONGHOLD) << " owed me some money, and no, I didn't kill him over it." << endl;
                cout << "If you can find me that money, I'll let you have access to my supplies if you really need them." << endl;
                type_and_continue();
            }
            else {
                cout << get_character_name(ASTRONOMER) << " smiles at you wistfully." << endl;
                cout << "Of course, Detective. Here's my best UV Light." << endl;
                cout << "Just type \'uv\' or \'light\' to use it." << endl;

                currentUserChoices.at(GETUVLIGHT) = true;
                type_and_continue();
            }

        }
        if (userKeyword.compare("interrogate") == 0) {

            //Empties console screen
            system("CLS");
            //Prints a title that tells the player which character they are questioning / interrogating
            print_character_questioning_title(roomNum);
            //Asks player which piece of evidence they'd like to interrogate the suspect about
            print_interrogation_request(roomNum, currentUserChoices, clueList);
            userKeyword = get_keyword_input();

            while (userKeyword.compare("end") != 0) {

                if (((userKeyword.compare("case") == 0)
                    || (userKeyword.compare("file") == 0)
                    || (userKeyword.compare("casefile") == 0))
                    && ((clueList.at(CASEFILE)).compare("???") != 0)) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);

                    cout << get_character_name(ASTRONOMER, INFORMAL) << " winces. She seems to be thinking about the murder." << endl;
                    cout << "\"He deserved to die peacefully." << endl;
                    cout << "He deserved to discover even more than he had.\"" << endl;
                    type_and_continue();
                }
                else if (((userKeyword.compare("small") == 0)
                    || (userKeyword.compare("safe") == 0))
                    && ((clueList.at(SMALLSAFE)).compare("???") != 0)) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);

                    cout << "She smiles politely." << endl;
                    cout << "\"You should ask his wife about his safe. I have no knowledge on the matter.\"" << endl;
                    type_and_continue();
                }
                else if (((userKeyword.compare("late") == 0)
                    || (userKeyword.compare("check") == 0))
                    && ((clueList.at(LATECHECK)).compare("???") != 0)) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);

                    cout << get_character_name(ASTRONOMER) << " chuckles solemnly." << endl;
                    cout << "\"So he was planning on paying me afterall.\"" << endl;
                    type_and_continue();

                    cout << "\n" << "She gets a little teary." << endl;
                    cout << "\"He owed me money because I'd come up with an addition for the telescope that he put his name on." << endl;
                    cout << "He eventually gave me credit, but he was a stubborn man..." << endl;
                    cout << "I was convinced he wouldn't come through. I guess I was wrong.\"" << endl;
                    type_and_continue();

                    currentUserChoices.at(GIVELATECHECK) = true;
                }
                else if (((userKeyword.compare("anonymous") == 0)
                    || (userKeyword.compare("letter") == 0))
                    && ((clueList.at(ANONYMOUSLETTER)).compare("???") != 0)) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);

                    cout << get_character_name(ASTRONOMER) << " carefully inspects the letter." << endl;
                    cout << "\"This is peculiar." << endl;
                    cout << "I've never seen this before, and I don't recognize this handwriting either." << endl;
                    cout << "That means " << get_character_name(MRSSTRONGHOLD) << "definitely didn't write this.\"" << endl;
                    type_and_continue();
                }
                else if (((userKeyword.compare("red") == 0)
                    || (userKeyword.compare("velvet") == 0)
                    || (userKeyword.compare("chair") == 0)
                    || (userKeyword.compare("chairs") == 0))
                    && ((clueList.at(REDVELVETCHAIRS)).compare("???") != 0)) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);

                    cout << get_character_name(ASTRONOMER, INFORMAL) << " looks up towards the ceiling." << endl;
                    cout << "\"Hmm... See, I really can't remember where I sat." << endl;
                    cout << "I just remember that I sat across from the Wine Crafter.\"" << endl;
                    type_and_continue();
                }
                else if (((userKeyword.compare("empty") == 0)
                    || (userKeyword.compare("display") == 0))
                    && ((clueList.at(EMPTYDISPLAY)).compare("???") != 0)) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);

                    cout << get_character_name(ASTRONOMER, INFORMAL) << " nods her head at the mention of the display." << endl;
                    cout << "\"Dr. Stronghold's prized wine was missing from his display?" << endl;
                    cout << "He was saving that for a special occasion. I guess he decided that occasion was tonight.\"" << endl; 
                    type_and_continue();

                    currentUserChoices.at(ASKABOUTEMPTYDISPLAY) = true;

                }
                else if (((userKeyword.compare("breaker") == 0)
                    || (userKeyword.compare("box") == 0))
                    && ((clueList.at(BREAKERBOX)).compare("???") != 0)) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);

                    cout << "You ask " << get_character_name(ASTRONOMER) << " where she was during the blackout." << endl;
                    cout << "\"Oh. I was actually stuck in the lab.\"" << endl;
                    cout << "She brushes her hair aside." << endl;
                    cout << "See, we put a keycard lock on the door to the lab to keep people out.\"" << endl;
                    cout << "The problem is, it uses an electronic card, so when the power went out, I got stuck inside." << endl;
                    type_and_continue();

                    cout << "You ask when she got out of the lab. She looks distressed." << endl;
                    cout << "\"I didn't think to look at the time when I got out." << endl;
                    cout << "I just heard someone banging on the balcony door in the dark." << endl;
                    cout << "I thought someone was breaking in, so I... I hid under my lab desk." << endl;
                    type_and_continue();

                    cout << get_character_name(ASTRONOMER) << "'s eyes are wet with tears now. She wipes them carefully." << endl;
                    cout << "I listened to them walk through the " << get_room_name(OBSERVATORY) << ", praying they didn't know I was there." << endl;
                    cout << "It took a few minutes after that for the power to turn on, but I didn't come out right away." << endl;
                    cout << "I waited in the lab until I heard " << get_character_name(MRSSTRONGHOLD) << "'s screaming." << endl;
                    cout << "Then I left to make sure she was okay." << endl;
                    type_and_continue();

                }
                else if (((userKeyword.compare("broken") == 0)
                    || (userKeyword.compare("lock") == 0))
                    && ((clueList.at(BROKENLOCK)).compare("???") != 0)) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);

                    cout << get_character_name(ASTRONOMER, INFORMAL) << " shivers at the mention of the broken lock." << endl;
                    cout << "\"I'm relieved it was just a broken lock." << endl;
                    cout << "When I was trapped in my lab during the blackout, I heard someone forcing the door in." << endl;
                    cout << "I thought someone had attempted to break into our lab, but now I assume it was the killer.\"" << endl;
                    type_and_continue();

                    cout << "\n" << "\"They likely made their way through the observatory to escape detection from something." << endl;
                    cout << "I'd presume " << get_character_name(MRSSTRONGHOLD) << " since she was in the Master Bathroom at the time.\"" << endl;
                    type_and_continue();
                }
                else if (((userKeyword.compare("foamed") == 0)
                    || (userKeyword.compare("mouth") == 0))
                    && ((clueList.at(FOAMEDMOUTH)).compare("???") != 0)) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);

                    cout << "\"That's extremely odd." << endl;
                    cout << "Foaming of the mouth would suggest " << get_character_name(DRSTRONGHOLD) << " was poisoned or had a seizure." << endl;
                    cout << "He shouldn't have a foamed mouth if his throat was slashed.\"" << endl;
                    type_and_continue();

                    currentUserChoices.at(ASKABOUTFOAMEDMOUTH) = true;

                }
                else if (((userKeyword.compare("snowy") == 0)
                    || (userKeyword.compare("foot") == 0)
                    || (userKeyword.compare("prints") == 0)
                    || (userKeyword.compare("footprints") == 0))
                    && ((clueList.at(SNOWYFOOTPRINTS)).compare("???") != 0)) {

                    //Empties console screen
                    system("CLS");
                    //Prints a title to tell the player which character they are questioning
                    print_character_questioning_title(roomNum);

                    cout << "\"There are two sets of footprints in the snow?" << endl;
                    cout << "That's peculiar..." << endl;
                    cout << "If the prints are from two sets of shoes, that would suggest two different people walked across the balcony." << endl;
                    cout << "There's no way the killer would return to the scene and risk being found, right?\"" << endl;
                    type_and_continue();
                }
                else {
                    int replyNum = ((rand() % 4) + 1);
                    if (replyNum == 1) {
                        cout << "\n\"Sorry Detective, I don't know about that.\"" << endl;
                    }
                    if (replyNum == 2) {
                        cout << "\n\"I think you'd have more expertise in that area.\"" << endl;
                    }
                    if (replyNum == 3) {
                        cout << "\n\"I wish I could help you, but I don't have any information about that.\"" << endl;
                    }
                    if (replyNum == 4) {
                        cout << "\n\"That's rather peculiar. I'm not sure what this evidence means.\"" << endl;
                    }
                    type_and_continue();
                }
                
                //Empties console screen
                system("CLS");

                print_input(userKeyword);

                //Prints a title to tell the player which character they are questioning / interrogating
                print_character_questioning_title(roomNum);
                //Asks player which piece of evidence they'd like to interrogate the suspect about
                print_interrogation_request(roomNum, currentUserChoices, clueList);
                userKeyword = get_keyword_input();

            }

        }

        //Empties console screen
        system("CLS");
        //Prints a title to tell the player which character they are questioning
        print_character_questioning_title(roomNum);

        print_input(userKeyword);

        //Asks player which questions they'd like to ask the suspect
        print_questioning_request(roomNum);
        userKeyword = get_keyword_input();
    }

}

void view_inventory(int roomNum, vector<bool>& currentUserChoices, vector<string>& clueList, string userKeyword) {

    while (userKeyword.compare("back") != 0) {
        //Empties console screen
        system("CLS");
        cout << "You are viewing your Inventory:" << endl;
        cout << "----------------------------------------" << endl;

        cout << clueList.at(CASEFILE) << endl;
        cout << clueList.at(EXPENSEREPORTS) << endl;
        cout << clueList.at(SMALLSAFE) << endl;

        if (currentUserChoices.at(ACCUSEMRSSTRONGHOLD) == true) {
            cout << clueList.at(INSURANCEPOLICY) << endl;
            cout << clueList.at(LATECHECK) << endl;
            cout << clueList.at(ANONYMOUSLETTER) << endl;
        }
        cout << clueList.at(LOCKEDCHESTS) << endl;
        cout << clueList.at(MISSINGKNIFE) << endl;
        cout << clueList.at(REDVELVETCHAIRS) << endl;
        cout << clueList.at(CUTNIGHTSHADE) << endl;
        cout << clueList.at(STONEBUTTON) << endl;
        cout << clueList.at(EMPTYDISPLAY) << endl;

        if (currentUserChoices.at(ACCUSEMRSSTRONGHOLD) == true) {
            cout << clueList.at(BLOODSTAINS) << endl;
            cout << clueList.at(CLEANEDFLOOR) << endl;
        }
        cout << clueList.at(GLASSSHARDS) << endl;
        cout << clueList.at(BROKENLOCK) << endl;
        cout << clueList.at(SLASHEDTHROAT) << endl;
        cout << clueList.at(FOAMEDMOUTH) << endl;
        cout << clueList.at(BLOODYGARMENT) << endl;
        cout << clueList.at(WETBOOTS) << endl;
        cout << clueList.at(CUFFLINK) << endl;
        cout << clueList.at(WASHEDSINK) << endl;
        cout << clueList.at(SNOWYFOOTPRINTS) << endl;

        cout << "----------------------------------------" << endl;
        cout << "Type the name of a clue to view it's description:" << endl;
        cout << "(Or type \"back\" to return to your current room.)" << endl;
        cout << "----------------------------------------" << endl;

        userKeyword = get_keyword_input();

        if (((userKeyword.compare("case") == 0)
            || (userKeyword.compare("file") == 0)
            || (userKeyword.compare("casefile") == 0))
            && ((clueList.at(CASEFILE)).compare("???") != 0)) {

            print_inventory_item_description(CASEFILE, currentUserChoices, clueList);

        }
        else if (((userKeyword.compare("expense") == 0)
            || (userKeyword.compare("report") == 0)
            || (userKeyword.compare("reports") == 0))
            && ((clueList.at(EXPENSEREPORTS)).compare("???") != 0)) {

            print_inventory_item_description(EXPENSEREPORTS, currentUserChoices, clueList);

        }
        else if (((userKeyword.compare("small") == 0)
            || (userKeyword.compare("safe") == 0))
            && ((clueList.at(SMALLSAFE)).compare("???") != 0)) {

            print_inventory_item_description(SMALLSAFE, currentUserChoices, clueList);

        }
        else if (((userKeyword.compare("insurance") == 0)
            || (userKeyword.compare("policy") == 0))
            && ((clueList.at(INSURANCEPOLICY)).compare("???") != 0)) {

            print_inventory_item_description(INSURANCEPOLICY, currentUserChoices, clueList);

        }
        else if (((userKeyword.compare("late") == 0)
            || (userKeyword.compare("check") == 0))
            && ((clueList.at(LATECHECK)).compare("???") != 0)) {

            print_inventory_item_description(LATECHECK, currentUserChoices, clueList);

        }
        else if (((userKeyword.compare("anonymous") == 0)
            || (userKeyword.compare("letter") == 0))
            && ((clueList.at(ANONYMOUSLETTER).compare("???") != 0))) {

            print_inventory_item_description(ANONYMOUSLETTER, currentUserChoices, clueList);

        }
        else if (((userKeyword.compare("locked") == 0)
            || (userKeyword.compare("chest") == 0)
            || (userKeyword.compare("chests") == 0))
            && ((clueList.at(LOCKEDCHESTS)).compare("???") != 0)) {

            print_inventory_item_description(LOCKEDCHESTS, currentUserChoices, clueList);

        }
        else  if (((userKeyword.compare("missing") == 0)
            || (userKeyword.compare("knife") == 0))
            && ((clueList.at(MISSINGKNIFE)).compare("???") != 0)) {

            print_inventory_item_description(MISSINGKNIFE, currentUserChoices, clueList);

        }
        else if (((userKeyword.compare("red") == 0)
            || (userKeyword.compare("velvet") == 0)
            || (userKeyword.compare("chair") == 0)
            || (userKeyword.compare("chairs") == 0))
            && ((clueList.at(REDVELVETCHAIRS)).compare("???") != 0)) {

            print_inventory_item_description(REDVELVETCHAIRS, currentUserChoices, clueList);

        }
        else if (((userKeyword.compare("nightshade") == 0)
            || (userKeyword.compare("nightshades") == 0)
            || (userKeyword.compare("cut") == 0)
            || (userKeyword.compare("night") == 0)
            || (userKeyword.compare("shade") == 0)
            || (userKeyword.compare("shades") == 0))
            && ((clueList.at(CUTNIGHTSHADE)).compare("???") != 0)) {

            print_inventory_item_description(CUTNIGHTSHADE, currentUserChoices, clueList);

        }
        else if (((userKeyword.compare("stone") == 0)
            || (userKeyword.compare("button") == 0))
            && ((clueList.at(STONEBUTTON)).compare("???") != 0)) {

            print_inventory_item_description(STONEBUTTON, currentUserChoices, clueList);

        }
        else if (((userKeyword.compare("empty") == 0)
            || (userKeyword.compare("display") == 0))
            && ((clueList.at(EMPTYDISPLAY)).compare("???") != 0)) {

            print_inventory_item_description(EMPTYDISPLAY, currentUserChoices, clueList);

        }
        else if (((userKeyword.compare("blood") == 0)
            || (userKeyword.compare("stain") == 0)
            || (userKeyword.compare("stains") == 0)
            || (userKeyword.compare("bloodstain") == 0)
            || (userKeyword.compare("bloodstains") == 0))
            && ((clueList.at(BLOODSTAINS)).compare("???") != 0)) {

            print_inventory_item_description(BLOODSTAINS, currentUserChoices, clueList);

        }
        else if (((userKeyword.compare("cleaned") == 0)
            || (userKeyword.compare("floor") == 0))
            && ((clueList.at(CLEANEDFLOOR)).compare("???") != 0)) {

            print_inventory_item_description(CLEANEDFLOOR, currentUserChoices, clueList);

        }
        else if (((userKeyword.compare("glass") == 0)
            || (userKeyword.compare("shard") == 0)
            || (userKeyword.compare("shards") == 0))
            && ((clueList.at(GLASSSHARDS)).compare("???") != 0)) {

            print_inventory_item_description(GLASSSHARDS, currentUserChoices, clueList);

        }
        else if (((userKeyword.compare("broken") == 0)
            || (userKeyword.compare("lock") == 0))
            && ((clueList.at(BROKENLOCK)).compare("???") != 0)) {

            print_inventory_item_description(BROKENLOCK, currentUserChoices, clueList);

        }
        else if (((userKeyword.compare("slashed") == 0)
            || (userKeyword.compare("throat") == 0))
            && ((clueList.at(SLASHEDTHROAT)).compare("???") != 0)) {

            print_inventory_item_description(SLASHEDTHROAT, currentUserChoices, clueList);

        }
        else if (((userKeyword.compare("foamed") == 0)
            || (userKeyword.compare("mouth") == 0))
            && ((clueList.at(FOAMEDMOUTH)).compare("???") != 0)) {

            print_inventory_item_description(FOAMEDMOUTH, currentUserChoices, clueList);

        }
        else if (((userKeyword.compare("bloody") == 0)
            || (userKeyword.compare("garment") == 0))
            && ((clueList.at(BLOODYGARMENT)).compare("???") != 0)) {

            print_inventory_item_description(BLOODYGARMENT, currentUserChoices, clueList);

        }
        else if (((userKeyword.compare("wet") == 0)
            || (userKeyword.compare("boot") == 0)
            || (userKeyword.compare("boots") == 0))
            && ((clueList.at(WETBOOTS)).compare("???") != 0)) {

            print_inventory_item_description(WETBOOTS, currentUserChoices, clueList);

        }
        else if (((userKeyword.compare("cufflink") == 0))
            && ((clueList.at(CUFFLINK)).compare("???") != 0)) {

            print_inventory_item_description(CUFFLINK, currentUserChoices, clueList);

        }
        else if (((userKeyword.compare("washed") == 0)
        || (userKeyword.compare("sink") == 0))
        && ((clueList.at(WASHEDSINK)).compare("???") != 0)) {

            print_inventory_item_description(WASHEDSINK, currentUserChoices, clueList);

        }
        else if (((userKeyword.compare("snowy") == 0)
            || (userKeyword.compare("foot") == 0)
            || (userKeyword.compare("prints") == 0)
            || (userKeyword.compare("footprints") == 0))
            && ((clueList.at(SNOWYFOOTPRINTS)).compare("???") != 0)) {

            print_inventory_item_description(SNOWYFOOTPRINTS, currentUserChoices, clueList);

        }
        else {
        if (userKeyword.compare("back") != 0) {
            cout << "That is an invalid inventory item. (Check your spelling.)" << endl;
            }
        }
        
    }

}

void print_inventory_item_description(int itemNum, vector<bool>& currentUserChoices, vector<string>& clueList) {

    //Empties console screen
    system("CLS");

    cout << "You are viewing the " << clueList.at(itemNum) << endl;
    cout << "----------------------------------------" << endl;

    switch (itemNum) {
    case CASEFILE:
        cout << "\n" << get_character_name(MRSSTRONGHOLD) << " is the widow of the late " << get_character_name(DRSTRONGHOLD) << endl;
        cout << "The Butler cleaned for " << get_character_name(DRSTRONGHOLD, INFORMAL) << " and maintained the grounds." << endl;
        cout << "The Sous Chef was " << get_character_name(DRSTRONGHOLD, INFORMAL) << "'s personal chef." << endl;
        cout << "The Wine Crafter was a bussiness partner of " << get_character_name(DRSTRONGHOLD, INFORMAL) << "'s." << endl;
        cout << "And lastly, the Astronomer was an old friend and associate of " << get_character_name(DRSTRONGHOLD) << "'s." << endl;
        break;

    case EXPENSEREPORTS:
        cout << "These are " << get_character_name(DRSTRONGHOLD) << "'s business expense reports." << endl;
        if (currentUserChoices.at(ASKABOUTEXPENSEREPORTS) == true) {
            cout << "They're mostly write ups about recent wine transactions and the grant." << endl;
        }
        else {
            cout << "You can learn about their importance by asking around." << endl;
        }
        break;

    case SMALLSAFE:
        cout << get_character_name(DRSTRONGHOLD) << " has a safe in his " << get_room_name(OFFICE) << "." << endl;
        cout << "You should try to find a way to open it." << endl;
        break;

    case INSURANCEPOLICY:
        cout << "This is a life insurance policy " << get_character_name(MRSSTRONGHOLD) << " prepared for her husband." << endl;
        cout << "She probably planned on killing him and banking the money." << endl;
        break;

    case LATECHECK:
        cout << "This is a late check written out to " << get_character_name(ASTRONOMER) << "." << endl;
        if (currentUserChoices.at(GIVELATECHECK) == false) {
            cout << "You should give this to her." << endl;
        }
        else {
            cout << get_character_name(ASTRONOMER) << " gave you the UV LIGHT in exchange for this." << endl;
        }
        break;

    case ANONYMOUSLETTER:
        cout << "This is an anonymous letter written to " << get_character_name(DRSTRONGHOLD) << "." << endl;
        cout << "It requests " << get_character_name(DRSTRONGHOLD) << " head to the " << get_room_name(WINECELLAR) << " two hours after Dinner." << endl;
        cout << "It says the person who wrote the letter sat on his far right." << endl;
        cout << "You'll need to figure out where everyone was sitting to find the author." << endl;
        break;

    case LOCKEDCHESTS:
        cout << "The Butler and Sous Chef have both decided to hide their belongings away in locked chests." << endl;
        cout << "They don't seem likely to open them." << endl;
        break;

    case MISSINGKNIFE:
        cout << "A knife went missing from the kitchen around the time of the murder." << endl;
        cout << "It was likely used to slash " << get_character_name(DRSTRONGHOLD) << "'s throat." << endl;
        break;

    case REDVELVETCHAIRS:
        cout << "There are only seven chairs at the table, but there were eight people at Dinner before the murder." << endl;
        if (currentUserChoices.at(ASKABOUTREDVELVETCHAIRS) == true) {
            cout << "This is because The Butler and The Sous Chef trade chairs whilst taking care of the guests." << endl;
        }
        else {
            cout << "You should find out why that is." << endl;
        }
        break;

    case CUTNIGHTSHADE:
        cout << "Some of the Belladonna Nightshades were cut near the time of the murder." << endl;
        if (currentUserChoices.at(ASKABOUTCUTNIGHTSHADE) == true) {
            cout << "They're quite poisonous... Perhaps they were used for sinister purposes?" << endl;
        }
        else {
            cout << "You are unsure why that is." << endl;
        }
        break;

    case STONEBUTTON:
        cout << "A small button was found on the stairs to the " << get_room_name(MASTERBEDROOM) << endl;
        if (currentUserChoices.at(ASKABOUTSTONEBUTTON) == true) {
            cout << "It was ripped out of the suit " << get_character_name(DRSTRONGHOLD) << " wore to Dinner." << endl;
        }
        else {
            cout << "It seems to be ripped out of something, but you're not sure what." << endl;
        }
        break;

    case EMPTYDISPLAY:
        cout << "The display case for one of " << get_character_name(DRSTRONGHOLD) << "'s prized wines was empty." << endl;
        if (currentUserChoices.at(ASKABOUTEXPENSEREPORTS) == true) {
            cout << "It's likely because " << get_character_name(DRSTRONGHOLD) << " planned on celebrating his grant with a drink." << endl;
        }
        else {
            cout << "There must be a reason for that, but what is it?" << endl;
        }
        break;

    case BLOODSTAINS:
        cout << "Bloodstains were found on the floor of the " << get_room_name(WINECELLAR) << "." << endl;
        cout << "They form less of a pool and seem more like spurts of blood." << endl;
        break;

    case CLEANEDFLOOR:
        cout << "Someone cleaned the floor here recently..." << endl;
        cout << "It smells like bleach." << endl;
        break;

    case GLASSSHARDS:
        cout << "Glass shards were found at the bottom of the " << get_room_name(BOILERROOM) << "'s trash bin." << endl;
        if (currentUserChoices.at(ASKABOUTGLASSSHARDS) == true) {
            cout << "They appear to be fragments of a wine bottle." << endl;
        }
        else {
            cout << "You're not sure where they came from." << endl;
        }
        break;

    case BREAKERBOX:
        cout << "The power was turned off last night around the time of the murder." << endl;
        cout << "Because you can't turn off the power remotely or on a timer, the murderer had to be here to turn them off." << endl;
        break;

    case BROKENLOCK:
        cout << "The door to the " << get_room_name(OBSERVATORY) << "was forced open around the time of the murder." << endl;
        cout << "The lock was completely destroyed." << endl;
        break;

    case SLASHEDTHROAT:
        cout << get_character_name(DRSTRONGHOLD) << " had his throat slashed with a knife." << endl;
        cout << "This is the most likely cause of death." << endl;
        break;

    case FOAMEDMOUTH:
        cout << "Small bubbles had formed at the edges of " << get_character_name(DRSTRONGHOLD) << "'s mouth around the time of his death." << endl;
        if (currentUserChoices.at(ASKABOUTFOAMEDMOUTH) == true) {
            cout << "It's possible this foam formed because " << get_character_name(DRSTRONGHOLD) << " was poisoned or had a seizure." << endl;
        }
        else {
            cout << "That doesn't seem normal." << endl;
        }
        break;

    case BLOODYGARMENT:
        cout << "A bloody garment was found underneath the bed " << get_character_name(DRSTRONGHOLD) << " died in." << endl;
        cout << "It seems to be a set of pajamas." << endl;
        break;

    case WETBOOTS:
        cout << "You found some wet boots inside of " << get_character_name(DRSTRONGHOLD) << "'s armoire." << endl;
        if (currentUserChoices.at(ASKABOUTWETBOOTS) == true) {
            cout << "They were his, but he didn't wear them tonight." << endl;
        }
        else {
            cout << "You're not sure why they're important." << endl;
        }
        break;

    case CUFFLINK:
        cout << "A cufflink was found inside of " << get_character_name(MRSSTRONGHOLD) << "'s armoire." << endl;
        if (currentUserChoices.at(ASKABOUTCUFFLINK) == true) {
            cout << "The cufflink may belong to The Butler or The Sous Chef." << endl;
        }
        else {
            cout << "You can learn about their importance by asking around." << endl;
        }
        break;

    case WASHEDSINK:
        cout << "The sink inside the Master Bathroom was recently washed." << endl;
        cout << "Did " << get_character_name(MRSSTRONGHOLD) << "clean it? Why?" << endl;
        break;

    case SNOWYFOOTPRINTS:
        cout << "There are two sets of footprints on the " << get_room_name(BALCONY) << " heading toward the " << get_room_name(OBSERVATORY) << "." << endl;
        cout << "One set of footprints was made by a pair of large boots, and the other was made by a pair of indistinguishable dress shoes." << endl;
        break;
    }

    type_and_continue();

}

int count_clues(vector<string>& clueList) {
    int numClues = 0;
    for (int i = 0; i < clueList.size(); i++) {
        if ((clueList.at(i)).compare("???") != 0){
        // numClues++
        numClues++;
        }
    }
    return numClues;
}

//Asks user what they want to investigate
void print_keyword_request(int roomNum) {
    cout << "\n----------------------------------------" << endl;
    cout << "What do you want to investigate in the " << get_room_name(roomNum) << "?" << endl;
    cout << "(Type a word from the room description to investigate that item.)" << endl;
    cout << "(Type \"inventory\" to view your clues.)" << endl;
    cout << "(Type \"leave\" to move between rooms.)" << endl;
    cout << "----------------------------------------" << endl;
}

//Asks user what they'd like to investigate further
//when they're investigating something within an object description
void print_further_keyword_request() {
    cout << "\n----------------------------------------" << endl;
    cout << "What do you want to investigate further?" << endl;
    cout << "(Type \"back\" to return to your current room.)" << endl;
    cout << "----------------------------------------" << endl;
}

void print_safe_request() {
    cout << "\n----------------------------------------" << endl;
    cout << "What do you want to investigate in the safe?" << endl;
    cout << "(Type \"close\" to close the safe.)" << endl;
    cout << "----------------------------------------" << endl;
}


//Asks user which room they want to enter
void print_new_room_request(int roomNum) {
    cout << "Where do you want to go from the " << get_room_name(roomNum) << "?" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
}

//Asks user what they want to question their suspect about
void print_questioning_request(int roomNum) {
    cout << "\nWhat do you want to ask?" << endl;
    cout << "----------------------------------------" << endl;

    cout << "\"1\": Would you care to introduce yourself?" << endl;
    cout << "\"2\": What did you do tonight after the dinner party?" << endl;
    cout << "\"3\": Do you think anyone else has a reason to kill " << get_character_name(DRSTRONGHOLD) << "?" << endl;
    if (roomNum == GREENHOUSE) {
        cout << "\"4\": Can I borrow your flashlight for a bit?" << endl;
    }
    if (roomNum == OBSERVATORY) {
        cout << "\"4\": Can I use a UV light from your lab to investigate some dark spaces?" << endl;
    }

    cout << "\n(Type \"stop\" to stop questioning your suspect and return to your current room." << endl;
    cout << "Or, if you've asked this character all of the three questions above, you should try typing \"interrogate\"." << endl;
    cout << "This will allow you to ask them about any of the clues you've found so far that they may recognize.)" << endl;
}

void print_pendleton_help_request(int roomNum) {
    cout << "\nWhat do you want to ask?" << endl;
    cout << "----------------------------------------" << endl;

    cout << "\"1\": What's in the case file?" << endl;
    cout << "\"2\": How do I investigate objects?" << endl;
    cout << "\"3\": How do I know when I've found a clue?" << endl;
    cout << "\"4\": How do I question the suspects?" << endl;
    cout << "\"5\": How do I end the game when I've figured out the killer?" << endl;

    cout << "\n(Type \"stop\" to stop questioning your suspect and return to your current room." << endl;
    cout << "Or, if you've asked this character all of the five questions above, you should try typing \"interrogate\"." << endl;
    cout << "This will allow you to ask them about any of the clues you've found so far that they may recognize.)" << endl;
}

//Asks user what clue they want to interrogate a suspect with
void print_interrogation_request(int roomNum, vector<bool>& currentUserChoices, vector<string>& clueList) {
    cout << "Which clue do you want to use to interrogate " << get_character_name(roomNum) << "?" << endl;
    cout << "----------------------------------------" << endl;
    switch (roomNum) {
    case CLYDE:
        if (currentUserChoices.at(ACCUSEMRSSTRONGHOLD)) {
            cout << clueList.at(CASEFILE) << endl;
            cout << clueList.at(EXPENSEREPORTS) << endl;
            cout << clueList.at(SMALLSAFE) << endl;
            cout << clueList.at(LOCKEDCHESTS) << endl;
            cout << clueList.at(MISSINGKNIFE) << endl;
            cout << clueList.at(BLOODSTAINS) << endl;
            cout << clueList.at(CLEANEDFLOOR) << endl;
            cout << clueList.at(BROKENLOCK) << endl;
            cout << clueList.at(SLASHEDTHROAT) << endl;
            cout << clueList.at(FOAMEDMOUTH) << endl;
            cout << clueList.at(BLOODYGARMENT) << endl;
            cout << clueList.at(SNOWYFOOTPRINTS) << endl;
        }
        else {
            cout << clueList.at(CASEFILE) << endl;
            cout << clueList.at(EXPENSEREPORTS) << endl;
            cout << clueList.at(SMALLSAFE) << endl;
            cout << clueList.at(LOCKEDCHESTS) << endl;
            cout << clueList.at(MISSINGKNIFE) << endl;
            cout << clueList.at(BROKENLOCK) << endl;
            cout << clueList.at(SLASHEDTHROAT) << endl;
            cout << clueList.at(FOAMEDMOUTH) << endl;
            cout << clueList.at(BLOODYGARMENT) << endl;
            cout << clueList.at(SNOWYFOOTPRINTS) << endl;
        }
        break;

    case BUTLER:
        if (currentUserChoices.at(ACCUSEMRSSTRONGHOLD)) {
            cout << clueList.at(CASEFILE) << endl;
            cout << clueList.at(ANONYMOUSLETTER) << endl;
            cout << clueList.at(LOCKEDCHESTS) << endl;
            cout << clueList.at(REDVELVETCHAIRS) << endl;
            cout << clueList.at(STONEBUTTON) << endl;
            cout << clueList.at(EMPTYDISPLAY) << endl;
            cout << clueList.at(CLEANEDFLOOR) << endl;
            cout << clueList.at(GLASSSHARDS) << endl;
            cout << clueList.at(BREAKERBOX) << endl;
            cout << clueList.at(SLASHEDTHROAT) << endl;
            cout << clueList.at(WETBOOTS) << endl;
            cout << clueList.at(CUFFLINK) << endl;
        }
        else {
            cout << clueList.at(CASEFILE) << endl;
            cout << clueList.at(LOCKEDCHESTS) << endl;
            cout << clueList.at(REDVELVETCHAIRS) << endl;
            cout << clueList.at(STONEBUTTON) << endl;
            cout << clueList.at(EMPTYDISPLAY) << endl;
            cout << clueList.at(GLASSSHARDS) << endl;
            cout << clueList.at(BREAKERBOX) << endl;
            cout << clueList.at(SLASHEDTHROAT) << endl;
            cout << clueList.at(WETBOOTS) << endl;
            cout << clueList.at(CUFFLINK) << endl;
        }
        break;

    case SOUSCHEF:
        if (currentUserChoices.at(ACCUSEMRSSTRONGHOLD)) {
            cout << clueList.at(CASEFILE) << endl;
            cout << clueList.at(ANONYMOUSLETTER) << endl;
            cout << clueList.at(MISSINGKNIFE) << endl;
            cout << clueList.at(REDVELVETCHAIRS) << endl;
            cout << clueList.at(CUTNIGHTSHADE) << endl;
            cout << clueList.at(BLOODSTAINS) << endl;
            cout << clueList.at(BREAKERBOX) << endl;
            cout << clueList.at(SLASHEDTHROAT) << endl;
            cout << clueList.at(CUFFLINK) << endl;
        }
        else {
            cout << clueList.at(CASEFILE) << endl;
            cout << clueList.at(MISSINGKNIFE) << endl;
            cout << clueList.at(REDVELVETCHAIRS) << endl;
            cout << clueList.at(CUTNIGHTSHADE) << endl;
            cout << clueList.at(BREAKERBOX) << endl;
            cout << clueList.at(SLASHEDTHROAT) << endl;
            cout << clueList.at(CUFFLINK) << endl;
        }
        break;

    case MRSSTRONGHOLD:
        if (currentUserChoices.at(ACCUSEMRSSTRONGHOLD)) {
            cout << clueList.at(CASEFILE) << endl;
            cout << clueList.at(SMALLSAFE) << endl;
            cout << clueList.at(INSURANCEPOLICY) << endl;
            cout << clueList.at(ANONYMOUSLETTER) << endl;
            cout << clueList.at(MISSINGKNIFE) << endl;
            cout << clueList.at(REDVELVETCHAIRS) << endl;
            cout << clueList.at(STONEBUTTON) << endl;
            cout << clueList.at(BREAKERBOX) << endl;
            cout << clueList.at(SLASHEDTHROAT) << endl;
            cout << clueList.at(FOAMEDMOUTH) << endl;
            cout << clueList.at(BLOODYGARMENT) << endl;
            cout << clueList.at(WETBOOTS) << endl;
            cout << clueList.at(CUFFLINK) << endl;
            cout << clueList.at(WASHEDSINK) << endl;
            cout << clueList.at(SNOWYFOOTPRINTS) << endl;
        }
        else {
            cout << clueList.at(CASEFILE) << endl;
            cout << clueList.at(SMALLSAFE) << endl;
            cout << clueList.at(MISSINGKNIFE) << endl;
            cout << clueList.at(REDVELVETCHAIRS) << endl;
            cout << clueList.at(STONEBUTTON) << endl;
            cout << clueList.at(BREAKERBOX) << endl;
            cout << clueList.at(SLASHEDTHROAT) << endl;
            cout << clueList.at(FOAMEDMOUTH) << endl;
            cout << clueList.at(BLOODYGARMENT) << endl;
            cout << clueList.at(WETBOOTS) << endl;
            cout << clueList.at(CUFFLINK) << endl;
            cout << clueList.at(WASHEDSINK) << endl;
            cout << clueList.at(SNOWYFOOTPRINTS) << endl;
        }
        break;

    case WINECRAFTER:
        if (currentUserChoices.at(ACCUSEMRSSTRONGHOLD)) {
            cout << clueList.at(CASEFILE) << endl;
            cout << clueList.at(EXPENSEREPORTS) << endl;
            cout << clueList.at(ANONYMOUSLETTER) << endl;
            cout << clueList.at(REDVELVETCHAIRS) << endl;
            cout << clueList.at(CUTNIGHTSHADE) << endl;
            cout << clueList.at(EMPTYDISPLAY) << endl;
            cout << clueList.at(GLASSSHARDS) << endl;
            cout << clueList.at(BREAKERBOX) << endl;
        }
        else {
            cout << clueList.at(CASEFILE) << endl;
            cout << clueList.at(EXPENSEREPORTS) << endl;
            cout << clueList.at(REDVELVETCHAIRS) << endl;
            cout << clueList.at(CUTNIGHTSHADE) << endl;
            cout << clueList.at(EMPTYDISPLAY) << endl;
            cout << clueList.at(GLASSSHARDS) << endl;
            cout << clueList.at(BREAKERBOX) << endl;
        }
        break;

    case MUDMAN:
        if (currentUserChoices.at(ACCUSEMRSSTRONGHOLD)) {
            cout << clueList.at(LATECHECK) << endl;
            cout << clueList.at(ANONYMOUSLETTER) << endl;
            cout << clueList.at(MISSINGKNIFE) << endl;
            cout << clueList.at(REDVELVETCHAIRS) << endl;
            cout << clueList.at(CUTNIGHTSHADE) << endl;
            cout << clueList.at(BROKENLOCK) << endl;
            cout << clueList.at(WETBOOTS) << endl;
        }
        else {
            cout << clueList.at(LATECHECK) << endl;
            cout << clueList.at(MISSINGKNIFE) << endl;
            cout << clueList.at(REDVELVETCHAIRS) << endl;
            cout << clueList.at(CUTNIGHTSHADE) << endl;
            cout << clueList.at(BROKENLOCK) << endl;
            cout << clueList.at(WETBOOTS) << endl;
        }
        break;

    case ASTRONOMER:
        if (currentUserChoices.at(ACCUSEMRSSTRONGHOLD)) {
            cout << clueList.at(CASEFILE) << endl;
            cout << clueList.at(SMALLSAFE) << endl;
            cout << clueList.at(LATECHECK) << endl;
            cout << clueList.at(ANONYMOUSLETTER) << endl;
            cout << clueList.at(REDVELVETCHAIRS) << endl;
            cout << clueList.at(EMPTYDISPLAY) << endl;
            cout << clueList.at(BREAKERBOX) << endl;
            cout << clueList.at(BROKENLOCK) << endl;
            cout << clueList.at(FOAMEDMOUTH) << endl;
            cout << clueList.at(SNOWYFOOTPRINTS) << endl;
        }
        else {
            cout << clueList.at(CASEFILE) << endl;
            cout << clueList.at(SMALLSAFE) << endl;
            cout << clueList.at(REDVELVETCHAIRS) << endl;
            cout << clueList.at(EMPTYDISPLAY) << endl;
            cout << clueList.at(BREAKERBOX) << endl;
            cout << clueList.at(BROKENLOCK) << endl;
            cout << clueList.at(FOAMEDMOUTH) << endl;
            cout << clueList.at(SNOWYFOOTPRINTS) << endl;
        }
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
        return "Balcony";

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

    cout << "Adjacent Rooms: " << endl;

    switch (roomNum) {

    case 0:
        cout << endl;
        cout << "[" << get_room_name(1) << "]" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        break;

    case 1:
        cout << "\nWEST WING\t| " << get_room_name(2) << ", " << get_room_name(3) << ", " << get_room_name(4) << endl;
        cout << "FRONT AND BACK  | " << get_room_name(8) << ", " << get_room_name(0) << endl;
        cout << "EAST WING\t| " << get_room_name(5) << ", " << get_room_name(6) << ", " << get_room_name(7) << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        break;

    case 2:
        cout << endl;
        cout << "[" << get_room_name(1) << "], " << "[" << get_room_name(3) << "], " << "[" << get_room_name(4) << "]" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        break;

    case 3:
        cout << endl;
        cout << "[" << get_room_name(1) << "], " << "[" << get_room_name(2) << "], " << "[" << get_room_name(4) << "]" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        break;

    case 4:
        cout << endl;
        cout << "[" << get_room_name(1) << "], " << "[" << get_room_name(2) << "], " << "[" << get_room_name(3) << "]" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        break;

    case 5:
        cout << endl;
        cout << "[" << get_room_name(1) << "], " << "[" << get_room_name(6) << "], " << "[" << get_room_name(7) << "]" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        break;

    case 6:
        cout << endl;
        cout << "[" << get_room_name(1) << "], " << "[" << get_room_name(5) << "], " << "[" << get_room_name(7) << "]" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        break;

    case 7:
        cout << endl;
        cout << "[" << get_room_name(1) << "], " << "[" << get_room_name(5) << "], " << "[" << get_room_name(6) << "]" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        break;

    case 8:
        cout << "\nUPSTAIRS    | " << get_room_name(11) << ", " << get_room_name(12) << endl;
        cout << "MAIN FLOOR  | " << get_room_name(1) << endl;
        cout << "DOWNSTAIRS  | " << get_room_name(9) << ", " << get_room_name(10) << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        break;

    case 9:
        cout << endl;
        cout << "[" << get_room_name(10) << "], " << "[" << get_room_name(8) << "]" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        break;

    case 10:
        cout << endl;
        cout << "[" << get_room_name(9) << "], " << "[" << get_room_name(8) << "]" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        break;

    case 11:
        cout << endl;
        cout << "[" << get_room_name(12) << "], " << "[" << get_room_name(13) << "], " << "[" << get_room_name(8) << "]" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        break;

    case 12:
        cout << endl;
        cout << "[" << get_room_name(11) << "], " << "[" << get_room_name(13) << "], " << "[" << get_room_name(8) << "]" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        break;

    case 13:
        cout << endl;
        cout << "[" << get_room_name(11) << "], " << "[" << get_room_name(12) << "]" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        break;

    }
}


void print_map(int roomNum) {

    switch (roomNum) {

    case TROPHYHALL:
        cout << "You are in the " << get_room_name(TROPHYHALL) << " / <TH>" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "         ______________________                        ______________________       " << endl;
        cout << "               MAIN FLOOR                                     UPSTAIRS              " << endl;
        cout << "         ______________________                        ______________________       " << endl;
        cout << "  ____________________________________                 ______________________       " << endl;
        cout << "  |      |      |      |      |      |                 |                    |       " << endl;
        cout << "  |      |      |      |      |      |          _______|_()______________()_|_______" << endl;
        cout << "  |      |      |__()__|      |      |          |            |        |            |" << endl;
        cout << "  |      ---()---      ---()---      |          |           ()        ()           |" << endl;
        cout << "  |     ()        [BL]        ()     |          |____________|________|____________|" << endl;
        cout << "  |      ---()---      ---()---      |                 ______________________       " << endl;
        cout << "  |      |      |      |      |      |                       DOWNSTAIRS             " << endl;
        cout << "  |      |      |      |      |      |                 ______________________       " << endl;
        cout << "  |______|______|__()__|______|______|               __________________________     " << endl;
        cout << "                |      |                             |       |        |       |     " << endl;
        cout << "                | <TH> |                             |      ()        ()      |     " << endl;
        cout << "                |______|                             |_______|________|_______|     " << endl;
        cout << "\n--------------------------------------------------------------------------------" << endl;
        break;

    case BALLROOM:
        cout << "You are in the " << get_room_name(BALLROOM) << " / <BL>" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "         ______________________                        ______________________       " << endl;
        cout << "               MAIN FLOOR                                     UPSTAIRS              " << endl;
        cout << "         ______________________                        ______________________       " << endl;
        cout << "  ____________________________________                 ______________________       " << endl;
        cout << "  |      |      |      |      |      |                 |                    |       " << endl;
        cout << "  |      | [OF] | [ST] | [KT] |      |          _______|_()______________()_|_______" << endl;
        cout << "  |      |      |__()__|      |      |          |            |        |            |" << endl;
        cout << "  |      ---()---      ---()---      |          |           ()  [ST]  ()           |" << endl;
        cout << "  | [LB]()        <BL>        ()[GH] |          |____________|________|____________|" << endl;
        cout << "  |      ---()---      ---()---      |                 ______________________       " << endl;
        cout << "  |      |      |      |      |      |                       DOWNSTAIRS             " << endl;
        cout << "  |      | [SQ] |      | [DR] |      |                 ______________________       " << endl;
        cout << "  |______|______|__()__|______|______|               __________________________     " << endl;
        cout << "                |      |                             |       |        |       |     " << endl;
        cout << "                | [TH] |                             |      ()  [ST]  ()      |     " << endl;
        cout << "                |______|                             |_______|________|_______|     " << endl;
        cout << "\n--------------------------------------------------------------------------------" << endl;
        break;

    case OFFICE:
        cout << "You are in the " << get_room_name(OFFICE) << " / <OF>" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "         ______________________                        ______________________       " << endl;
        cout << "               MAIN FLOOR                                     UPSTAIRS              " << endl;
        cout << "         ______________________                        ______________________       " << endl;
        cout << "  ____________________________________                 ______________________       " << endl;
        cout << "  |      |      |      |      |      |                 |                    |       " << endl;
        cout << "  |      | <OF> |      |      |      |          _______|_()______________()_|_______" << endl;
        cout << "  |      |      |__()__|      |      |          |            |        |            |" << endl;
        cout << "  |      ---()---      ---()---      |          |           ()        ()           |" << endl;
        cout << "  | [LB]()        [BL]        ()     |          |____________|________|____________|" << endl;
        cout << "  |      ---()---      ---()---      |                 ______________________       " << endl;
        cout << "  |      |      |      |      |      |                       DOWNSTAIRS             " << endl;
        cout << "  |      | [SQ] |      |      |      |                 ______________________       " << endl;
        cout << "  |______|______|__()__|______|______|               __________________________     " << endl;
        cout << "                |      |                             |       |        |       |     " << endl;
        cout << "                |      |                             |      ()        ()      |     " << endl;
        cout << "                |______|                             |_______|________|_______|     " << endl;
        cout << "\n--------------------------------------------------------------------------------" << endl;
        break;

    case SERVANTSQUARTERS:
        cout << "You are in the " << get_room_name(SERVANTSQUARTERS) << " / <SQ>" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "         ______________________                        ______________________       " << endl;
        cout << "               MAIN FLOOR                                     UPSTAIRS              " << endl;
        cout << "         ______________________                        ______________________       " << endl;
        cout << "  ____________________________________                 ______________________       " << endl;
        cout << "  |      |      |      |      |      |                 |                    |       " << endl;
        cout << "  |      | [OF] |      |      |      |          _______|_()______________()_|_______" << endl;
        cout << "  |      |      |__()__|      |      |          |            |        |            |" << endl;
        cout << "  |      ---()---      ---()---      |          |           ()        ()           |" << endl;
        cout << "  | [LB]()        [BL]        ()     |          |____________|________|____________|" << endl;
        cout << "  |      ---()---      ---()---      |                 ______________________       " << endl;
        cout << "  |      |      |      |      |      |                       DOWNSTAIRS             " << endl;
        cout << "  |      | <SQ> |      |      |      |                 ______________________       " << endl;
        cout << "  |______|______|__()__|______|______|               __________________________     " << endl;
        cout << "                |      |                             |       |        |       |     " << endl;
        cout << "                |      |                             |      ()        ()      |     " << endl;
        cout << "                |______|                             |_______|________|_______|     " << endl;
        cout << "\n--------------------------------------------------------------------------------" << endl;
        break;

    case LIBRARY:
        cout << "You are in the " << get_room_name(LIBRARY) << " / <LB>" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "         ______________________                        ______________________       " << endl;
        cout << "               MAIN FLOOR                                     UPSTAIRS              " << endl;
        cout << "         ______________________                        ______________________       " << endl;
        cout << "  ____________________________________                 ______________________       " << endl;
        cout << "  |      |      |      |      |      |                 |                    |       " << endl;
        cout << "  |      | [OF] |      |      |      |          _______|_()______________()_|_______" << endl;
        cout << "  |      |      |__()__|      |      |          |            |        |            |" << endl;
        cout << "  |      ---()---      ---()---      |          |           ()        ()           |" << endl;
        cout << "  | <LB>()        [BL]        ()     |          |____________|________|____________|" << endl;
        cout << "  |      ---()---      ---()---      |                 ______________________       " << endl;
        cout << "  |      |      |      |      |      |                       DOWNSTAIRS             " << endl;
        cout << "  |      | [SQ] |      |      |      |                 ______________________       " << endl;
        cout << "  |______|______|__()__|______|______|               __________________________     " << endl;
        cout << "                |      |                             |       |        |       |     " << endl;
        cout << "                |      |                             |      ()        ()      |     " << endl;
        cout << "                |______|                             |_______|________|_______|     " << endl;
        cout << "\n--------------------------------------------------------------------------------" << endl;
        break;

    case KITCHEN:
        cout << "You are in the " << get_room_name(KITCHEN) << " / <KT>" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "         ______________________                        ______________________       " << endl;
        cout << "               MAIN FLOOR                                     UPSTAIRS              " << endl;
        cout << "         ______________________                        ______________________       " << endl;
        cout << "  ____________________________________                 ______________________       " << endl;
        cout << "  |      |      |      |      |      |                 |                    |       " << endl;
        cout << "  |      |      |      | <KT> |      |          _______|_()______________()_|_______" << endl;
        cout << "  |      |      |__()__|      |      |          |            |        |            |" << endl;
        cout << "  |      ---()---      ---()---      |          |           ()        ()           |" << endl;
        cout << "  |     ()        [BL]        ()[GH] |          |____________|________|____________|" << endl;
        cout << "  |      ---()---      ---()---      |                 ______________________       " << endl;
        cout << "  |      |      |      |      |      |                       DOWNSTAIRS             " << endl;
        cout << "  |      |      |      | [DR] |      |                 ______________________       " << endl;
        cout << "  |______|______|__()__|______|______|               __________________________     " << endl;
        cout << "                |      |                             |       |        |       |     " << endl;
        cout << "                |      |                             |      ()        ()      |     " << endl;
        cout << "                |______|                             |_______|________|_______|     " << endl;
        cout << "\n--------------------------------------------------------------------------------" << endl;
        break;

    case DININGROOM:
        cout << "You are in the " << get_room_name(DININGROOM) << " / <DR>" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "         ______________________                        ______________________       " << endl;
        cout << "               MAIN FLOOR                                     UPSTAIRS              " << endl;
        cout << "         ______________________                        ______________________       " << endl;
        cout << "  ____________________________________                 ______________________       " << endl;
        cout << "  |      |      |      |      |      |                 |                    |       " << endl;
        cout << "  |      |      |      | [KT] |      |          _______|_()______________()_|_______" << endl;
        cout << "  |      |      |__()__|      |      |          |            |        |            |" << endl;
        cout << "  |      ---()---      ---()---      |          |           ()        ()           |" << endl;
        cout << "  |     ()        [BL]        ()[GH] |          |____________|________|____________|" << endl;
        cout << "  |      ---()---      ---()---      |                 ______________________       " << endl;
        cout << "  |      |      |      |      |      |                       DOWNSTAIRS             " << endl;
        cout << "  |      |      |      | <DR> |      |                 ______________________       " << endl;
        cout << "  |______|______|__()__|______|______|               __________________________     " << endl;
        cout << "                |      |                             |       |        |       |     " << endl;
        cout << "                |      |                             |      ()        ()      |     " << endl;
        cout << "                |______|                             |_______|________|_______|     " << endl;
        cout << "\n--------------------------------------------------------------------------------" << endl;
        break;

    case GREENHOUSE:
        cout << "You are in the " << get_room_name(GREENHOUSE) << " / <GH>" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "         ______________________                        ______________________       " << endl;
        cout << "               MAIN FLOOR                                     UPSTAIRS              " << endl;
        cout << "         ______________________                        ______________________       " << endl;
        cout << "  ____________________________________                 ______________________       " << endl;
        cout << "  |      |      |      |      |      |                 |                    |       " << endl;
        cout << "  |      |      |      | [KT] |      |          _______|_()______________()_|_______" << endl;
        cout << "  |      |      |__()__|      |      |          |            |        |            |" << endl;
        cout << "  |      ---()---      ---()---      |          |           ()        ()           |" << endl;
        cout << "  |     ()        [BL]        ()<GH> |          |____________|________|____________|" << endl;
        cout << "  |      ---()---      ---()---      |                 ______________________       " << endl;
        cout << "  |      |      |      |      |      |                       DOWNSTAIRS             " << endl;
        cout << "  |      |      |      | [DR] |      |                 ______________________       " << endl;
        cout << "  |______|______|__()__|______|______|               __________________________     " << endl;
        cout << "                |      |                             |       |        |       |     " << endl;
        cout << "                |      |                             |      ()        ()      |     " << endl;
        cout << "                |______|                             |_______|________|_______|     " << endl;
        cout << "\n--------------------------------------------------------------------------------" << endl;
        break;

    case STAIRWELL:
        cout << "You are in the " << get_room_name(STAIRWELL) << " / <ST>" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "         ______________________                        ______________________       " << endl;
        cout << "               MAIN FLOOR                                     UPSTAIRS              " << endl;
        cout << "         ______________________                        ______________________       " << endl;
        cout << "  ____________________________________                 ______________________       " << endl;
        cout << "  |      |      |      |      |      |                 |                    |       " << endl;
        cout << "  |      |      | <ST> |      |      |          _______|_()______________()_|_______" << endl;
        cout << "  |      |      |__()__|      |      |          |            |        |            |" << endl;
        cout << "  |      ---()---      ---()---      |          |    [OB]   ()  <ST>  ()   [MB]    |" << endl;
        cout << "  |     ()        [BL]        ()     |          |____________|________|____________|" << endl;
        cout << "  |      ---()---      ---()---      |                 ______________________       " << endl;
        cout << "  |      |      |      |      |      |                       DOWNSTAIRS             " << endl;
        cout << "  |      |      |      |      |      |                 ______________________       " << endl;
        cout << "  |______|______|__()__|______|______|               __________________________     " << endl;
        cout << "                |      |                             |       |        |       |     " << endl;
        cout << "                |      |                             | [WC] ()  <ST>  () [BR] |     " << endl;
        cout << "                |______|                             |_______|________|_______|     " << endl;
        cout << "\n--------------------------------------------------------------------------------" << endl;
        break;

    case WINECELLAR:
        cout << "You are in the " << get_room_name(WINECELLAR) << " / <WC>" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "         ______________________                        ______________________       " << endl;
        cout << "               MAIN FLOOR                                     UPSTAIRS              " << endl;
        cout << "         ______________________                        ______________________       " << endl;
        cout << "  ____________________________________                 ______________________       " << endl;
        cout << "  |      |      |      |      |      |                 |                    |       " << endl;
        cout << "  |      |      | [ST] |      |      |          _______|_()______________()_|_______" << endl;
        cout << "  |      |      |__()__|      |      |          |            |        |            |" << endl;
        cout << "  |      ---()---      ---()---      |          |           ()  [ST]  ()           |" << endl;
        cout << "  |     ()                    ()     |          |____________|________|____________|" << endl;
        cout << "  |      ---()---      ---()---      |                 ______________________       " << endl;
        cout << "  |      |      |      |      |      |                       DOWNSTAIRS             " << endl;
        cout << "  |      |      |      |      |      |                 ______________________       " << endl;
        cout << "  |______|______|__()__|______|______|               __________________________     " << endl;
        cout << "                |      |                             |       |        |       |     " << endl;
        cout << "                |      |                             | <WC> ()  [ST]  () [BR] |     " << endl;
        cout << "                |______|                             |_______|________|_______|     " << endl;
        cout << "\n--------------------------------------------------------------------------------" << endl;
        break;

    case BOILERROOM:
        cout << "You are in the " << get_room_name(BOILERROOM) << " / <BR>" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "         ______________________                        ______________________       " << endl;
        cout << "               MAIN FLOOR                                     UPSTAIRS              " << endl;
        cout << "         ______________________                        ______________________       " << endl;
        cout << "  ____________________________________                 ______________________       " << endl;
        cout << "  |      |      |      |      |      |                 |                    |       " << endl;
        cout << "  |      |      | [ST] |      |      |          _______|_()______________()_|_______" << endl;
        cout << "  |      |      |__()__|      |      |          |            |        |            |" << endl;
        cout << "  |      ---()---      ---()---      |          |           ()  [ST]  ()           |" << endl;
        cout << "  |     ()                    ()     |          |____________|________|____________|" << endl;
        cout << "  |      ---()---      ---()---      |                 ______________________       " << endl;
        cout << "  |      |      |      |      |      |                       DOWNSTAIRS             " << endl;
        cout << "  |      |      |      |      |      |                 ______________________       " << endl;
        cout << "  |______|______|__()__|______|______|               __________________________     " << endl;
        cout << "                |      |                             |       |        |       |     " << endl;
        cout << "                |      |                             | [WC] ()  [ST]  () <BR> |     " << endl;
        cout << "                |______|                             |_______|________|_______|     " << endl;
        cout << "\n--------------------------------------------------------------------------------" << endl;
        break;

    case OBSERVATORY:
        cout << "You are in the " << get_room_name(OBSERVATORY) << " / <OB>" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "         ______________________                        ______________________       " << endl;
        cout << "               MAIN FLOOR                                     UPSTAIRS              " << endl;
        cout << "         ______________________                        ______________________       " << endl;
        cout << "  ____________________________________                 ______________________       " << endl;
        cout << "  |      |      |      |      |      |                 |        [BA]        |       " << endl;
        cout << "  |      |      | [ST] |      |      |          _______|_()______________()_|_______" << endl;
        cout << "  |      |      |__()__|      |      |          |            |        |            |" << endl;
        cout << "  |      ---()---      ---()---      |          |    <OB>   ()  [ST]  ()   [MB]    |" << endl;
        cout << "  |     ()                    ()     |          |____________|________|____________|" << endl;
        cout << "  |      ---()---      ---()---      |                 ______________________       " << endl;
        cout << "  |      |      |      |      |      |                       DOWNSTAIRS             " << endl;
        cout << "  |      |      |      |      |      |                 ______________________       " << endl;
        cout << "  |______|______|__()__|______|______|               __________________________     " << endl;
        cout << "                |      |                             |       |        |       |     " << endl;
        cout << "                |      |                             |      ()  [ST]  ()      |     " << endl;
        cout << "                |______|                             |_______|________|_______|     " << endl;
        cout << "\n--------------------------------------------------------------------------------" << endl;
        break;

    case MASTERBEDROOM:
        cout << "You are in the " << get_room_name(MASTERBEDROOM) << " / <MB>" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "         ______________________                        ______________________       " << endl;
        cout << "               MAIN FLOOR                                     UPSTAIRS              " << endl;
        cout << "         ______________________                        ______________________       " << endl;
        cout << "  ____________________________________                 ______________________       " << endl;
        cout << "  |      |      |      |      |      |                 |        [BA]        |       " << endl;
        cout << "  |      |      | [ST] |      |      |          _______|_()______________()_|_______" << endl;
        cout << "  |      |      |__()__|      |      |          |            |        |            |" << endl;
        cout << "  |      ---()---      ---()---      |          |    [OB]   ()  [ST]  ()   <MB>    |" << endl;
        cout << "  |     ()                    ()     |          |____________|________|____________|" << endl;
        cout << "  |      ---()---      ---()---      |                 ______________________       " << endl;
        cout << "  |      |      |      |      |      |                       DOWNSTAIRS             " << endl;
        cout << "  |      |      |      |      |      |                 ______________________       " << endl;
        cout << "  |______|______|__()__|______|______|               __________________________     " << endl;
        cout << "                |      |                             |       |        |       |     " << endl;
        cout << "                |      |                             |      ()  [ST]  ()      |     " << endl;
        cout << "                |______|                             |_______|________|_______|     " << endl;
        cout << "\n--------------------------------------------------------------------------------" << endl;
        break;

    case BALCONY:
        cout << "You are in the " << get_room_name(BALCONY) << " / <BA>" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "         ______________________                        ______________________       " << endl;
        cout << "               MAIN FLOOR                                     UPSTAIRS              " << endl;
        cout << "         ______________________                        ______________________       " << endl;
        cout << "  ____________________________________                 ______________________       " << endl;
        cout << "  |      |      |      |      |      |                 |        <BA>        |       " << endl;
        cout << "  |      |      |      |      |      |          _______|_()______________()_|_______" << endl;
        cout << "  |      |      |__()__|      |      |          |            |        |            |" << endl;
        cout << "  |      ---()---      ---()---      |          |    [OB]   ()        ()   [MB]    |" << endl;
        cout << "  |     ()                    ()     |          |____________|________|____________|" << endl;
        cout << "  |      ---()---      ---()---      |                 ______________________       " << endl;
        cout << "  |      |      |      |      |      |                       DOWNSTAIRS             " << endl;
        cout << "  |      |      |      |      |      |                 ______________________       " << endl;
        cout << "  |______|______|__()__|______|______|               __________________________     " << endl;
        cout << "                |      |                             |       |        |       |     " << endl;
        cout << "                |      |                             |      ()        ()      |     " << endl;
        cout << "                |______|                             |_______|________|_______|     " << endl;
        cout << "\n--------------------------------------------------------------------------------" << endl;
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



