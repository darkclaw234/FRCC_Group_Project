// FRCC_MurderMystery.cpp : This is our murdery mystery project in its most basic form.

//Extra Comment

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void beginning();

void enter_tutorial(vector<bool>& currentUserChoices);

int enter_room_zero(vector<bool>& currentuserChoices, int roomNum);
int enter_room_one(vector<bool>& currentUserChoices, int roomNum);
int enter_room_two(vector<bool>& currentUserChoices, int roomNum);
int enter_room_three(vector<bool>& currentUserChoices, int roomNum);
int enter_room_four(vector<bool>& currentUserChoices, int roomNum);
int enter_room_five(vector<bool>& currentUserChoices, int roomNum);
int enter_room_six(vector<bool>& currentUserChoices, int roomNum);
int enter_room_seven(vector<bool>& currentUserChoices, int roomNum);
int enter_room_eight(vector<bool>& currentUserChoices, int roomNum);
int enter_room_nine(vector<bool>& currentUserChoices, int roomNum);
int enter_room_ten(vector<bool>& currentUserChoices, int roomNum);
int enter_room_eleven(vector<bool>& currentUserChoices, int roomNum);
int enter_room_twelve(vector<bool>& currentUserChoices, int roomNum);
int enter_room_thirteen(vector<bool>& currentUserChoices, int roomNum);

void ending(vector<bool>& currentUserChoices);



void print_keyword_request(int roomNum);
void print_room_request(int roomNum);

void describe_room(vector<bool>& currentUserChoices, int roomNum);
string investigate_room(vector<bool>& currentUserChoices, int roomNum);
int leave_room(int roomNum);

void print_room_title(int roomNum);
void print_room_name(int roomNum);
void print_adjacent_rooms(int roomNum);

string get_keyword_input();
void type_and_continue();

void print_input(string input);

const int meetClyde = 0;





int main()
{
    int roomNum = 0;

    //Declares boolean vector userChoices, which will keep track of the user's progress and decisions through game etc
    vector<bool> userChoices(20);
    //Sets boolean at every index to false
    for (size_t i = 0; i < userChoices.size(); i++) {
        userChoices.at(i) = false;
    }

    //Prints introduction to story
    beginning();

    while (roomNum != -1) {
        switch (roomNum) {

        case 0:
            //Empties console screen
            system("CLS");
            describe_room(userChoices, roomNum);
            roomNum = enter_room_zero(userChoices, roomNum);
            break;

        case 1:
            //Empties console screen
            system("CLS");
            describe_room(userChoices, roomNum);
            roomNum = enter_room_one(userChoices, roomNum);
            break;

        case 2:
            //Empties console screen
            system("CLS");
            describe_room(userChoices, roomNum);
            roomNum = enter_room_two(userChoices, roomNum);
            break;

        case 3:
            //Empties console screen
            system("CLS");
            describe_room(userChoices, roomNum);
            roomNum = enter_room_three(userChoices, roomNum);
            break;

        case 4:
            //Empties console screen
            system("CLS");
            describe_room(userChoices, roomNum);
            roomNum = enter_room_four(userChoices, roomNum);
            break;

        case 5:
            //Empties console screen
            system("CLS");
            describe_room(userChoices, roomNum);
            roomNum = enter_room_five(userChoices, roomNum);
            break;

        case 6:
            //Empties console screen
            system("CLS");
            describe_room(userChoices, roomNum);
            roomNum = enter_room_six(userChoices, roomNum);
            break;

        case 7:
            //Empties console screen
            system("CLS");
            describe_room(userChoices, roomNum);
            roomNum = enter_room_seven(userChoices, roomNum);
            break;

        case 8:
            //Empties console screen
            system("CLS");
            describe_room(userChoices, roomNum);
            roomNum = enter_room_eight(userChoices, roomNum);
            break;

        case 9:
            //Empties console screen
            system("CLS");
            describe_room(userChoices, roomNum);
            roomNum = enter_room_nine(userChoices, roomNum);
            break;

        case 10:
            //Empties console screen
            system("CLS");
            describe_room(userChoices, roomNum);
            roomNum = enter_room_ten(userChoices, roomNum);
            break;

        case 11:
            //Empties console screen
            system("CLS");
            describe_room(userChoices, roomNum);
            roomNum = enter_room_eleven(userChoices, roomNum);
            break;

        case 12:
            //Empties console screen
            system("CLS");
            describe_room(userChoices, roomNum);
            roomNum = enter_room_twelve(userChoices, roomNum);
            break;

        case 13:
            //Empties console screen
            system("CLS");
            describe_room(userChoices, roomNum);
            roomNum = enter_room_thirteen(userChoices, roomNum);
            break;

        default:
            cout << "FIXME: ROOMNUM IS " << roomNum << endl;
            cout << "UNPREDICTED VALUE." << endl;
            break;
        }
    }

    ending(userChoices);

    return 0;

}



void beginning() {
    //Declares user input string
    string userInput;

    //FIXME: ADD INTRODUCTION, ATMOSPHERE BUILDING HERE
    cout << "FIXME: ADD BEGINNING TO STORY." << endl;
    cout << "Beginning of story, eventual intro." << endl;

    type_and_continue();
}



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



//Prints room description, allows player to investigate room until they want to leave, and then helps player move between rooms
int enter_room_zero(vector<bool>& currentUserChoices, int roomNum) {
    //Declares user input string
    string userKeyword;

    //Enters tutorial for player if they're just starting the game
    if (currentUserChoices.at(meetClyde) == false) {
        enter_tutorial(currentUserChoices);
        describe_room(currentUserChoices, roomNum);
    }

    //Investigates chosen keyword from roomdescription, prints info about keyword
    userKeyword = investigate_room(currentUserChoices, roomNum);

    //Loops Until Player decides to leave room
    while (userKeyword.compare("leave") != 0) {
        userKeyword = investigate_room(currentUserChoices, roomNum);
    }

    //Sets New Room Number to User's Input
    print_room_request(roomNum);
    roomNum = leave_room(roomNum);

    while (roomNum == 0) {
        //Clears Screen
        system("CLS");
        cout << "Invalid Selection. Type one of the following room names exactly: \n" << endl;
        //Sets New Room Number to User's Input
        roomNum = leave_room(roomNum);
    }

    return roomNum;
}



//Prints room description, allows player to investigate room until they want to leave, and then helps player move between rooms
int enter_room_one(vector<bool>& currentUserChoices, int roomNum) {
    //Declares user input string
    string userKeyword;

    //Investigates chosen keyword from roomdescription, prints info about keyword
    userKeyword = investigate_room(currentUserChoices, roomNum);

    //Loops Until Player decides to leave room
    while (userKeyword.compare("leave") != 0) {
        userKeyword = investigate_room(currentUserChoices, roomNum);
    }

    //Sets New Room Number to User's Input
    print_room_request(roomNum);
    roomNum = leave_room(roomNum);

    while (roomNum == 1) {
        //Clears Screen
        system("CLS");
        cout << "Invalid Selection. Type one of the following room names exactly: \n" << endl;
        //Sets New Room Number to User's Input
        roomNum = leave_room(roomNum);
    }

    return roomNum;
}



//Prints room description, allows player to investigate room until they want to leave, and then helps player move between rooms
int enter_room_two(vector<bool>& currentUserChoices, int roomNum) {
    //Declares user input string
    string userKeyword;

    //Investigates chosen keyword from roomdescription, prints info about keyword
    userKeyword = investigate_room(currentUserChoices, roomNum);

    //Loops Until Player decides to leave room
    while (userKeyword.compare("leave") != 0) {
        userKeyword = investigate_room(currentUserChoices, roomNum);
    }

    //Sets New Room Number to User's Input
    print_room_request(roomNum);
    roomNum = leave_room(roomNum);

    while (roomNum == 2) {
        //Clears Screen
        system("CLS");
        cout << "Invalid Selection. Type one of the following room names exactly: \n" << endl;
        //Sets New Room Number to User's Input
        roomNum = leave_room(roomNum);
    }

    return roomNum;
}



//Prints room description, allows player to investigate room until they want to leave, and then helps player move between rooms
int enter_room_three(vector<bool>& currentUserChoices, int roomNum) {
    //Declares user input string
    string userKeyword;

    //Investigates chosen keyword from roomdescription, prints info about keyword
    userKeyword = investigate_room(currentUserChoices, roomNum);

    //Loops Until Player decides to leave room
    while (userKeyword.compare("leave") != 0) {
        userKeyword = investigate_room(currentUserChoices, roomNum);
    }
   
    //Sets New Room Number to User's Input
    print_room_request(roomNum);
    roomNum = leave_room(roomNum);

    while (roomNum == 3) {
        //Clears Screen
        system("CLS");
        cout << "Invalid Selection. Type one of the following room names exactly: \n" << endl;
        //Sets New Room Number to User's Input
        roomNum = leave_room(roomNum);
    }

    return roomNum;
}



//Prints room description, allows player to investigate room until they want to leave, and then helps player move between rooms
int enter_room_four(vector<bool>& currentUserChoices, int roomNum) {
    //Declares user input string
    string userKeyword;

    //Investigates chosen keyword from roomdescription, prints info about keyword
    userKeyword = investigate_room(currentUserChoices, roomNum);

    //Loops Until Player decides to leave room
    while (userKeyword.compare("leave") != 0) {
        userKeyword = investigate_room(currentUserChoices, roomNum);
    }

    //Sets New Room Number to User's Input
    print_room_request(roomNum);
    roomNum = leave_room(roomNum);

    while (roomNum == 4) {
        //Clears Screen
        system("CLS");
        cout << "Invalid Selection. Type one of the following room names exactly: \n" << endl;
        //Sets New Room Number to User's Input
        roomNum = leave_room(roomNum);
    }

    return roomNum;
}



//Prints room description, allows player to investigate room until they want to leave, and then helps player move between rooms
int enter_room_five(vector<bool>& currentUserChoices, int roomNum) {
    //Declares user input string
    string userKeyword;

    //Investigates chosen keyword from roomdescription, prints info about keyword
    userKeyword = investigate_room(currentUserChoices, roomNum);

    //Loops Until Player decides to leave room
    while (userKeyword.compare("leave") != 0) {
        userKeyword = investigate_room(currentUserChoices, roomNum);
    }

    //Sets New Room Number to User's Input
    print_room_request(roomNum);
    roomNum = leave_room(roomNum);

    while (roomNum == 5) {
        //Clears Screen
        system("CLS");
        cout << "Invalid Selection. Type one of the following room names exactly: \n" << endl;
        //Sets New Room Number to User's Input
        roomNum = leave_room(roomNum);
    }

    return roomNum;
}



//Prints room description, allows player to investigate room until they want to leave, and then helps player move between rooms
int enter_room_six(vector<bool>& currentUserChoices, int roomNum) {
    //Declares user input string
    string userKeyword;

    //Investigates chosen keyword from roomdescription, prints info about keyword
    userKeyword = investigate_room(currentUserChoices, roomNum);

    //Loops Until Player decides to leave room
    while (userKeyword.compare("leave") != 0) {
        userKeyword = investigate_room(currentUserChoices, roomNum);
    }

    //Sets New Room Number to User's Input
    print_room_request(roomNum);
    roomNum = leave_room(roomNum);

    while (roomNum == 6) {
        //Clears Screen
        system("CLS");
        cout << "Invalid Selection. Type one of the following room names exactly: \n" << endl;
        //Sets New Room Number to User's Input
        roomNum = leave_room(roomNum);
    }

    return roomNum;
}



//Prints room description, allows player to investigate room until they want to leave, and then helps player move between rooms
int enter_room_seven(vector<bool>& currentUserChoices, int roomNum) {
    //Declares user input string
    string userKeyword;

    //Investigates chosen keyword from roomdescription, prints info about keyword
    userKeyword = investigate_room(currentUserChoices, roomNum);

    //Loops Until Player decides to leave room
    while (userKeyword.compare("leave") != 0) {
        userKeyword = investigate_room(currentUserChoices, roomNum);
    }

    //Sets New Room Number to User's Input
    print_room_request(roomNum);
    roomNum = leave_room(roomNum);

    while (roomNum == 7) {
        //Clears Screen
        system("CLS");
        cout << "Invalid Selection. Type one of the following room names exactly: \n" << endl;
        //Sets New Room Number to User's Input
        roomNum = leave_room(roomNum);
    }

    return roomNum;
}



//Prints room description, allows player to investigate room until they want to leave, and then helps player move between rooms
int enter_room_eight(vector<bool>& currentUserChoices, int roomNum) {
    //Declares user input string
    string userKeyword;

    //Investigates chosen keyword from roomdescription, prints info about keyword
    userKeyword = investigate_room(currentUserChoices, roomNum);

    //Loops Until Player decides to leave room
    while (userKeyword.compare("leave") != 0) {
        userKeyword = investigate_room(currentUserChoices, roomNum);
    }

    //Sets New Room Number to User's Input
    print_room_request(roomNum);
    roomNum = leave_room(roomNum);

    while (roomNum == 8) {
        //Clears Screen
        system("CLS");
        cout << "Invalid Selection. Type one of the following room names exactly: \n" << endl;
        //Sets New Room Number to User's Input
        roomNum = leave_room(roomNum);
    }

    return roomNum;
}



//Prints room description, allows player to investigate room until they want to leave, and then helps player move between rooms
int enter_room_nine(vector<bool>& currentUserChoices, int roomNum) {
    //Declares user input string
    string userKeyword;

    //Investigates chosen keyword from roomdescription, prints info about keyword
    userKeyword = investigate_room(currentUserChoices, roomNum);

    //Loops Until Player decides to leave room
    while (userKeyword.compare("leave") != 0) {
        userKeyword = investigate_room(currentUserChoices, roomNum);
    }

    //Sets New Room Number to User's Input
    print_room_request(roomNum);
    roomNum = leave_room(roomNum);

    while (roomNum == 9) {
        //Clears Screen
        system("CLS");
        cout << "Invalid Selection. Type one of the following room names exactly: \n" << endl;
        //Sets New Room Number to User's Input
        roomNum = leave_room(roomNum);
    }

    return roomNum;
}



//Prints room description, allows player to investigate room until they want to leave, and then helps player move between rooms
int enter_room_ten(vector<bool>& currentUserChoices, int roomNum) {
    //Declares user input string
    string userKeyword;

    //Investigates chosen keyword from roomdescription, prints info about keyword
    userKeyword = investigate_room(currentUserChoices, roomNum);

    //Loops Until Player decides to leave room
    while (userKeyword.compare("leave") != 0) {
        userKeyword = investigate_room(currentUserChoices, roomNum);
    }

    //Sets New Room Number to User's Input
    print_room_request(roomNum);
    roomNum = leave_room(roomNum);

    while (roomNum == 10) {
        //Clears Screen
        system("CLS");
        cout << "Invalid Selection. Type one of the following room names exactly: \n" << endl;
        //Sets New Room Number to User's Input
        roomNum = leave_room(roomNum);
    }

    return roomNum;
}



//Prints room description, allows player to investigate room until they want to leave, and then helps player move between rooms
int enter_room_eleven(vector<bool>& currentUserChoices, int roomNum) {
    //Declares user input string
    string userKeyword;

    //Investigates chosen keyword from roomdescription, prints info about keyword
    userKeyword = investigate_room(currentUserChoices, roomNum);

    //Loops Until Player decides to leave room
    while (userKeyword.compare("leave") != 0) {
        userKeyword = investigate_room(currentUserChoices, roomNum);
    }

    //Sets New Room Number to User's Input
    print_room_request(roomNum);
    roomNum = leave_room(roomNum);

    while (roomNum == 11) {
        //Clears Screen
        system("CLS");
        cout << "Invalid Selection. Type one of the following room names exactly: \n" << endl;
        //Sets New Room Number to User's Input
        roomNum = leave_room(roomNum);
    }

    return roomNum;
}



//Prints room description, allows player to investigate room until they want to leave, and then helps player move between rooms
int enter_room_twelve(vector<bool>& currentUserChoices, int roomNum) {
    //Declares user input string
    string userKeyword;

    //Investigates chosen keyword from roomdescription, prints info about keyword
    userKeyword = investigate_room(currentUserChoices, roomNum);

    //Loops Until Player decides to leave room
    while (userKeyword.compare("leave") != 0) {
        userKeyword = investigate_room(currentUserChoices, roomNum);
    }

    //Sets New Room Number to User's Input
    print_room_request(roomNum);
    roomNum = leave_room(roomNum);

    while (roomNum == 12) {
        //Clears Screen
        system("CLS");
        cout << "Invalid Selection. Type one of the following room names exactly: \n" << endl;
        //Sets New Room Number to User's Input
        roomNum = leave_room(roomNum);
    }

    return roomNum;
}



//Prints room description, allows player to investigate room until they want to leave, and then helps player move between rooms
int enter_room_thirteen(vector<bool>& currentUserChoices, int roomNum) {
    //Declares user input string
    string userKeyword;

    //Investigates chosen keyword from roomdescription, prints info about keyword
    userKeyword = investigate_room(currentUserChoices, roomNum);

    //Loops Until Player decides to leave room
    while (userKeyword.compare("leave") != 0) {
        userKeyword = investigate_room(currentUserChoices, roomNum);
    }

    //Sets New Room Number to User's Input
    print_room_request(roomNum);
    roomNum = leave_room(roomNum);

    while (roomNum == 13) {
        //Clears Screen
        system("CLS");
        cout << "Invalid Selection. Type one of the following room names exactly: \n" << endl;
        //Sets New Room Number to User's Input
        roomNum = leave_room(roomNum);
    }

    return roomNum;
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
void print_room_request(int roomNum) {

    cout << "\nWhich room do you want to enter from the ";
    print_room_name(roomNum);
    cout << "?" << endl;
}


//Describes current room, and may change description based on user choices
void describe_room(vector<bool>& currentUserChoices, int roomNum) {

    switch (roomNum) {

    case 0:
        //Prints basic room description if player has met clyde
        if (currentUserChoices.at(meetClyde) == true) {
            print_room_title(roomNum);
            cout << "Glass cupboards line the edges of the room with glimmering bronze and silver figures." << endl;
            cout << "Juniper shrubs cradle to the shelves of old photographs that appear well dusted." << endl;
            cout << "There's even a golden lion head attached to the wall, right above the double doors that lead into the mansion's core." << endl;

            cout << "\nClyde sits by the plastic table of evidence, prepared to answer any questions you might have." << endl;
        }
        //Prints different description if player hasn't met clyde
        else {
            cout << "You enter the mansion and find yourself in an ornate trophy hall." << endl;
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
        //FIXME: DESCRIBE ROOM 1
        print_room_title(roomNum);
        cout << "FIXME: DESCRIBE ROOM 1." << endl;

        break;

    case 2:
        //FIXME: DESCRIBE ROOM 2
        print_room_title(roomNum);
        cout << "FIXME: DESCRIBE ROOM 2." << endl;

        break;

    case 3:
        //FIXME: DESCRIBE ROOM 3
        print_room_title(roomNum);
        cout << "FIXME: DESCRIBE ROOM 3." << endl;

        break;

    case 4:
        //FIXME: DESCRIBE ROOM 4
        print_room_title(roomNum);
        cout << "FIXME: DESCRIBE ROOM 4." << endl;

        break;

    case 5:
        //FIXME: DESCRIBE ROOM 5
        print_room_title(roomNum);
        cout << "FIXME: DESCRIBE ROOM 5." << endl;

        break;

    case 6:
        //FIXME: DESCRIBE ROOM 6
        print_room_title(roomNum);
        cout << "FIXME: DESCRIBE ROOM 6." << endl;

        break;

    case 7:
        //FIXME: DESCRIBE ROOM 7
        print_room_title(roomNum);
        cout << "FIXME: DESCRIBE ROOM 7." << endl;

        break;

    case 8:
        //FIXME: DESCRIBE ROOM 8
        print_room_title(roomNum);
        cout << "FIXME: DESCRIBE ROOM 8." << endl;

        break;

    case 9:
        //FIXME: DESCRIBE ROOM 9
        print_room_title(roomNum);
        cout << "FIXME: DESCRIBE ROOM 9." << endl;

        break;

    case 10:
        //FIXME: DESCRIBE ROOM 10
        print_room_title(roomNum);
        cout << "FIXME: DESCRIBE ROOM 10." << endl;

        break;

    case 11:
        //FIXME: DESCRIBE ROOM 11
        print_room_title(roomNum);
        cout << "FIXME: DESCRIBE ROOM 11." << endl;

        break;

    case 12:
        //FIXME: DESCRIBE ROOM 12
        print_room_title(roomNum);
        cout << "FIXME: DESCRIBE ROOM 12." << endl;

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

//Allows player to investigate objects within a room. Asks for user input and prints a description of chosen objects that are important to story
string investigate_room(vector<bool>& currentUserChoices, int roomNum) {

    print_keyword_request(roomNum);
    string userKeyword = get_keyword_input();
    //FIXME: REMOVE INPUT PRINTER WHEN GAME IS FINISHED
    print_input(userKeyword);

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

    return userKeyword;
}

//Prints adjacent rooms to user and then changes roomNum to newRoomNum based on the user's input
int leave_room(int roomNum) {

    int newRoomNum = roomNum;

    //Prints adjacent rooms for user's reference
    print_adjacent_rooms(roomNum);
    //Gets user's chosen room
    string userKeyword = get_keyword_input();

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
        if (userKeyword.compare("obervatory") == 0) {
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
        if (userKeyword.compare("obervatory") == 0) {
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
        cout << "Power Room";
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

void print_adjacent_rooms(int roomNum) {

    cout << "Adjacent Rooms: " << endl;

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
        print_room_name(2);
        cout << "\"" << "\n" << "\"";
        print_room_name(6);
        cout << "\"" << "\n" << "\"";
        print_room_name(7);
        cout << "\"" << endl;
        break;

    case 6:
        cout << "\"";
        print_room_name(2);
        cout << "\"" << "\n" << "\"";
        print_room_name(5);
        cout << "\"" << "\n" << "\"";
        print_room_name(7);
        cout << "\"" << endl;
        break;

    case 7:
        cout << "\"";
        print_room_name(2);
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
        print_room_name(2);
        cout << "\"" << "\n" << "\"";
        print_room_name(11);
        cout << "\"" << "\n" << "\"";
        print_room_name(12);
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



string get_keyword_input() {

    string keywordInput;
    cin >> keywordInput;
    transform(keywordInput.begin(), keywordInput.end(), keywordInput.begin(), ::tolower);

    cin.ignore(1000, '\n');

    return keywordInput;
}

void type_and_continue() {

    string tempString;
    //Requests user input to continue
    cout << "\nType anything and press enter to continue..." << endl;
    cin >> tempString;
    
    cin.ignore(1000, '\n');
}



void print_input(string input) {
    cout << "\nFIXME: Remove userInput printer when game is finished." << endl;
    cout << "The user input is: " << input << endl;
}
