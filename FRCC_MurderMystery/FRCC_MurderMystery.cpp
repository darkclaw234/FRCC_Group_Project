// FRCC_MurderMystery.cpp : This is our murdery mystery project in its most basic form.

//Extra Comment

#include <iostream>
#include <vector>
#include <algorithm>
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

void print_room_title(int roomNum);

void print_keyword_request(int roomNum);
void print_room_request(int roomNum);

void describe_room(vector<bool>& currentUserChoices, int roomNum);
void print_adjacent_rooms(int roomNum);
void print_room_name(int roomNum);

string get_keyword_input();
void type_and_continue();

void print_input(string input);

const int meetClyde = 0;





int main()
{
    int roomNum = 0;

    //Declares boolean vector userChoices, which will keep track of progress etc
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
            cout << "Something went wrong with the code." << endl;
            cout << "roomNum is an unknown, unused number." << endl;
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



int enter_room_zero(vector<bool>& currentUserChoices, int roomNum) {
    //Declares user input string
    string userKeyword;

    //Enters tutorial for player if they're just starting the game
    if (currentUserChoices.at(meetClyde) == false) {
        enter_tutorial(currentUserChoices);
        describe_room(currentUserChoices, roomNum);
    }

    //Requests User Input Keyword, Gets Keyword Input
    print_keyword_request(roomNum);
    userKeyword = get_keyword_input();
    //FIXME: REMOVE INPUT PRINTER WHEN GAME IS FINISHED
    print_input(userKeyword);

    //Loops Until User Decides to leave room
    while (userKeyword.compare("leave") != 0) {

        //Requests User Input Keyword, Gets Keyword Input
        print_keyword_request(roomNum);
        userKeyword = get_keyword_input();
        //FIXME: REMOVE INPUT PRINTER WHEN GAME IS FINISHED
        print_input(userKeyword);
    }

    //Asks user for input, prints adjacent rooms for reference, and then gets user chosen room
    print_room_request(roomNum);
    print_adjacent_rooms(roomNum);
    userKeyword = get_keyword_input();

    if (userKeyword.compare("ballroom") == 0) {
        roomNum = 1;
    }
    
    //Loops while room number hasn't changed
    //So player must move to another room after typing leave
    while (roomNum == 0) {

        //Asks user for input, prints adjacent rooms for reference, and then gets user chosen room
        print_room_request(roomNum);
        print_adjacent_rooms(roomNum);
        userKeyword = get_keyword_input();

        //Sets roomNum to user's chosen room
        if (userKeyword.compare("ballroom") == 0) {
            roomNum = 1;
        }
    }

    return roomNum;
}



int enter_room_one(vector<bool>& currentUserChoices, int roomNum) {
    //Declares user input string
    string userKeyword;

    //Requests User Input Keyword, Gets Keyword Input
    print_keyword_request(roomNum);
    userKeyword = get_keyword_input();
    //FIXME: REMOVE INPUT PRINTER WHEN GAME IS FINISHED
    print_input(userKeyword);

    //Loops Until User Decides to leave room
    while (userKeyword.compare("leave") != 0) {
        print_keyword_request(roomNum);
        userKeyword = get_keyword_input();
        //FIXME: REMOVE INPUT PRINTER WHEN GAME IS FINISHED
        print_input(userKeyword);
    }

    //Asks user for input, prints adjacent rooms for reference, and then gets user chosen room
    print_room_request(roomNum);
    print_adjacent_rooms(roomNum);
    userKeyword = get_keyword_input();

    //Sets roomNum to user's chosen room
    if (userKeyword.compare("trophy hall") == 0) {
        roomNum = 0;
    }
    if (userKeyword.compare("office") == 0) {
        roomNum = 2;
    }
    if (userKeyword.compare("servant's") == 0
        || userKeyword.compare("servant") == 0
        || userKeyword.compare("quarters") == 0){
        roomNum = 3;
    }
    if (userKeyword.compare("library") == 0) {
        roomNum = 4;
    }
    if (userKeyword.compare("kitchen") == 0) {
        roomNum = 5;
    }
    if (userKeyword.compare("dining room") == 0) {
        roomNum = 6;
    }
    if (userKeyword.compare("green house") == 0) {
        roomNum = 7;
    }
    if (userKeyword.compare("stairwell") == 0) {
        roomNum = 8;
    }

    //Loops while room number hasn't changed
    //So player must move to another room after typing leave
    while (roomNum == 1) {
        //Asks user for input, prints adjacent rooms for reference, and then gets user chosen room
        print_room_request(roomNum);
        print_adjacent_rooms(roomNum);
        userKeyword = get_keyword_input();

        //Sets roomNum to user's chosen room
        if (userKeyword.compare("trophy hall") == 0) {
            roomNum = 0;
        }
        if (userKeyword.compare("office") == 0) {
            roomNum = 2;
        }
        if (userKeyword.compare("servant's") == 0
            || userKeyword.compare("servant") == 0
            || userKeyword.compare("quarters") == 0) {
            roomNum = 3;
        }
        if (userKeyword.compare("library") == 0) {
            roomNum = 4;
        }
        if (userKeyword.compare("kitchen") == 0) {
            roomNum = 5;
        }
        if (userKeyword.compare("dining room") == 0) {
            roomNum = 6;
        }
        if (userKeyword.compare("green house") == 0) {
            roomNum = 7;
        }
        if (userKeyword.compare("stairwell") == 0) {
            roomNum = 8;
        }
    }

    return roomNum;
}



int enter_room_two(vector<bool>& currentUserChoices, int roomNum) {
    //Declares user input string
    string userKeyword;

    //Requests User Input Keyword, Gets Keyword Input
    print_keyword_request(roomNum);
    userKeyword = get_keyword_input();
    //FIXME: REMOVE INPUT PRINTER WHEN GAME IS FINISHED
    print_input(userKeyword);

    //Loops Until User Decides to leave room
    while (userKeyword.compare("leave") != 0) {

        //Requests User Input Keyword, Gets Keyword Input
        print_keyword_request(roomNum);
        userKeyword = get_keyword_input();
        //FIXME: REMOVE INPUT PRINTER WHEN GAME IS FINISHED
        print_input(userKeyword);
    }

    //Asks user for input, prints adjacent rooms for reference, and then gets user chosen room
    print_room_request(roomNum);
    print_adjacent_rooms(roomNum);
    userKeyword = get_keyword_input();

    //Sets roomNum to user's chosen room
    if (userKeyword.compare("ballroom") == 0) {
        roomNum = 1;
    }

    if (userKeyword.compare("servant") == 0 ||
        userKeyword.compare("servant's") == 0 ||
        userKeyword.compare("quarters") == 0) {
        roomNum = 3;
    }

    if (userKeyword.compare("library") == 0) {
        roomNum = 4;
    }

    return roomNum;
}



int enter_room_three(vector<bool>& currentUserChoices, int roomNum) {
    //Declares user input string
    string userKeyword;

    //FIXME: ADD ROOM 3 INTERACTIONS
    cout << "FIXME: ADD ROOM 3 INTERACTIONS." << endl;
    cout << "entered magic room 3" << endl;

    //FIXME: RETURN USER'S DESIRED ROOMNUM
    cout << "FIXME: RETURN USER'S DESIRED ROOMNUM." << endl;
    return 0;
}



int enter_room_four(vector<bool>& currentUserChoices, int roomNum) {
    //Declares user input string
    string userKeyword;

    //FIXME: ADD ROOM 4 INTERACTIONS
    cout << "FIXME: ADD ROOM 4 INTERACTIONS." << endl;
    cout << "entered magic room 4" << endl;

    //FIXME: RETURN USER'S DESIRED ROOMNUM
    cout << "FIXME: RETURN USER'S DESIRED ROOMNUM." << endl;
    return 0;
}



int enter_room_five(vector<bool>& currentUserChoices, int roomNum) {
    //Declares user input string
    string userKeyword;

    //FIXME: ADD ROOM 5 INTERACTIONS
    cout << "FIXME: ADD ROOM 5 INTERACTIONS." << endl;
    cout << "entered magic room 5" << endl;

    //FIXME: RETURN USER'S DESIRED ROOMNUM
    cout << "FIXME: RETURN USER'S DESIRED ROOMNUM." << endl;
    return 0;
}



int enter_room_six(vector<bool>& currentUserChoices, int roomNum) {
    //Declares user input string
    string userKeyword;

    //FIXME: ADD ROOM 6 INTERACTIONS
    cout << "FIXME: ADD ROOM 6 INTERACTIONS." << endl;
    cout << "entered magic room 6" << endl;

    //FIXME: RETURN USER'S DESIRED ROOMNUM
    cout << "FIXME: RETURN USER'S DESIRED ROOMNUM." << endl;
    return 0;
}



int enter_room_seven(vector<bool>& currentUserChoices, int roomNum) {
    //Declares user input string
    string userKeyword;

    //FIXME: ADD ROOM 7 INTERACTIONS
    cout << "FIXME: ADD ROOM 7 INTERACTIONS." << endl;
    cout << "entered magic room 7" << endl;

    //FIXME: RETURN USER'S DESIRED ROOMNUM
    cout << "FIXME: RETURN USER'S DESIRED ROOMNUM." << endl;
    return 0;
}



int enter_room_eight(vector<bool>& currentUserChoices, int roomNum) {
    //Declares user input string
    string userKeyword;

    //FIXME: ADD ROOM 8 INTERACTIONS
    cout << "FIXME: ADD ROOM 8 INTERACTIONS." << endl;
    cout << "entered magic room 8" << endl;

    //FIXME: RETURN USER'S DESIRED ROOMNUM
    cout << "FIXME: RETURN USER'S DESIRED ROOMNUM." << endl;
    return 0;
}



int enter_room_nine(vector<bool>& currentUserChoices, int roomNum) {
    //Declares user input string
    string userKeyword;

    //FIXME: ADD ROOM 9 INTERACTIONS
    cout << "FIXME: ADD ROOM 9 INTERACTIONS." << endl;
    cout << "entered magic room 9" << endl;

    //FIXME: RETURN USER'S DESIRED ROOMNUM
    cout << "FIXME: RETURN USER'S DESIRED ROOMNUM." << endl;
    return 0;
}



int enter_room_ten(vector<bool>& currentUserChoices, int roomNum) {
    //Declares user input string
    string userKeyword;

    //FIXME: ADD ROOM 10 INTERACTIONS
    cout << "FIXME: ADD ROOM 10 INTERACTIONS." << endl;
    cout << "entered magic room 10" << endl;

    //FIXME: RETURN USER'S DESIRED ROOMNUM
    cout << "FIXME: RETURN USER'S DESIRED ROOMNUM." << endl;
    return 0;
}



int enter_room_eleven(vector<bool>& currentUserChoices, int roomNum) {
    //Declares user input string
    string userKeyword;

    //FIXME: ADD ROOM 11 INTERACTIONS
    cout << "FIXME: ADD ROOM 11 INTERACTIONS." << endl;
    cout << "entered magic room 11" << endl;

    //FIXME: RETURN USER'S DESIRED ROOMNUM
    cout << "FIXME: RETURN USER'S DESIRED ROOMNUM." << endl;
    return 0;
}



int enter_room_twelve(vector<bool>& currentUserChoices, int roomNum) {
    //Declares user input string
    string userKeyword;

    //FIXME: ADD ROOM 12 INTERACTIONS
    cout << "FIXME: ADD ROOM 12 INTERACTIONS." << endl;
    cout << "entered magic room 12" << endl;

    //FIXME: RETURN USER'S DESIRED ROOMNUM
    cout << "FIXME: RETURN USER'S DESIRED ROOMNUM." << endl;
    return 0;
}



int enter_room_thirteen(vector<bool>& currentUserChoices, int roomNum) {
    //Declares user input string
    string userKeyword;

    //FIXME: ADD ROOM 13 INTERACTIONS
    cout << "FIXME: ADD ROOM 13 INTERACTIONS." << endl;
    cout << "entered magic room 13" << endl;

    //FIXME: RETURN USER'S DESIRED ROOMNUM
    cout << "FIXME: RETURN USER'S DESIRED ROOMNUM." << endl;
    return 0;
}



void ending(vector<bool>& currentUserChoices) {
    //Empties console screen
    system("CLS");

    //FIXME: RETURN USER'S DESIRED ROOMNUM
    cout << "FIXME: ADD ENDING TO STORY." << endl;
    cout << "This is the end." << endl;

}



void print_room_title(int roomNum) {
    cout << "You are in the ";
    print_room_name(roomNum);
    cout << "." << endl;
    cout << "----------------------------------------" << endl;
}



void print_keyword_request(int roomNum) {

    cout << "What do you want to investigate in the ";
    print_room_name(roomNum);
    cout << "?" << endl;

    cout << "(Type \"leave\" to move between rooms.)" << endl;
}



void print_room_request(int roomNum) {

    cout << "Which room do you want to enter from the ";
    print_room_name(roomNum);
    cout << "?" << endl;
}



void describe_room(vector<bool>& currentUserChoices, int roomNum) {

    string userInput;

    switch (roomNum) {
    
    case 0:
        //Prints basic room description if player has met clyde
        if(currentUserChoices.at(meetClyde) == true){
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

        cout << endl;

        break;

    case 1:
        //FIXME: DESCRIBE ROOM 1
        print_room_title(roomNum);
        cout << "FIXME: DESCRIBE ROOM 1." << endl;

        cout << endl;

        break;

    case 2:
        //FIXME: DESCRIBE ROOM 2
        print_room_title(roomNum);
        cout << "FIXME: DESCRIBE ROOM 2." << endl;

        cout << endl;

        break;

    case 3:
        //FIXME: DESCRIBE ROOM 3
        print_room_title(roomNum);
        cout << "FIXME: DESCRIBE ROOM 3." << endl;

        cout << endl;

        break;

    case 4:
        //FIXME: DESCRIBE ROOM 4
        print_room_title(roomNum);
        cout << "FIXME: DESCRIBE ROOM 4." << endl;

        cout << endl;

        break;

    case 5:
        //FIXME: DESCRIBE ROOM 5
        print_room_title(roomNum);
        cout << "FIXME: DESCRIBE ROOM 5." << endl;

        cout << endl;

        break;

    case 6:
        //FIXME: DESCRIBE ROOM 6
        print_room_title(roomNum);
        cout << "FIXME: DESCRIBE ROOM 6." << endl;

        cout << endl;

        break;

    case 7:
        //FIXME: DESCRIBE ROOM 7
        print_room_title(roomNum);
        cout << "FIXME: DESCRIBE ROOM 7." << endl;

        cout << endl;

        break;

    case 8:
        //FIXME: DESCRIBE ROOM 8
        print_room_title(roomNum);
        cout << "FIXME: DESCRIBE ROOM 8." << endl;

        cout << endl;

        break;

    case 9:
        //FIXME: DESCRIBE ROOM 9
        print_room_title(roomNum);
        cout << "FIXME: DESCRIBE ROOM 9." << endl;

        cout << endl;

        break;

    case 10:
        //FIXME: DESCRIBE ROOM 10
        print_room_title(roomNum);
        cout << "FIXME: DESCRIBE ROOM 10." << endl;

        cout << endl;

        break;

    case 11:
        //FIXME: DESCRIBE ROOM 11
        print_room_title(roomNum);
        cout << "FIXME: DESCRIBE ROOM 11." << endl;

        cout << endl;

        break;

    case 12:
        //FIXME: DESCRIBE ROOM 12
        print_room_title(roomNum);
        cout << "FIXME: DESCRIBE ROOM 12." << endl;

        cout << endl;

        break;
    
    case 13:
        //FIXME: DESCRIBE ROOM 13
        print_room_title(roomNum);
        cout << "FIXME: DESCRIBE ROOM 13." << endl;

        cout << endl;

        break;
    }

}



void print_adjacent_rooms(int roomNum) {

    cout << "Which room would you like to go to?" << endl;
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
        cout << "FIXME: COUT ADJACENT ROOMS" << endl;
        break;

    }
}

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
        cout << "Dining Room";
        break;

    case 6:
        cout << "Kitchen";
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

string get_keyword_input() {
    string keywordInput;
    cin >> keywordInput;
    transform(keywordInput.begin(), keywordInput.end(), keywordInput.begin(), ::tolower);

    return keywordInput;
}

void type_and_continue() {
    string tempString;

    //Requests user input to continue
    cout << "\nType anything and press enter to continue..." << endl;
    cin >> tempString;
    cout << endl;
}

void print_input(string input) {
    cout << "FIXME: Remove userInput printer when game is finished." << endl;
    cout << "The user input is: " << input << endl;
}
