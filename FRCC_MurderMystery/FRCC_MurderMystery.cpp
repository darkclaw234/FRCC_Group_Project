// FRCC_MurderMystery.cpp : This is our murdery mystery project in its most basic form.

//Extra Comment

#include <iostream>
#include <vector>
using namespace std;

int beginning();
int in_room_one(vector<bool>& currentUserChoices);
int in_room_two(vector<bool>& currentUserChoices);
int in_room_three(vector<bool>& currentUserChoices);
int in_room_four(vector<bool>& currentUserChoices);
int in_room_five(vector<bool>& currentUserChoices);
int in_room_six(vector<bool>& currentUserChoices);
int in_room_seven(vector<bool>& currentUserChoices);
int in_room_eight(vector<bool>& currentUserChoices);
int in_room_nine(vector<bool>& currentUserChoices);
int in_room_ten(vector<bool>& currentUserChoices);
int in_room_eleven(vector<bool>& currentUserChoices);
int in_room_twelve(vector<bool>& currentUserChoices);
void ending();



int main()
{
    int roomNum = 0;

    vector<bool> userChoices(20);

    for (int i = 0; i < userChoices.size(); i++) {
        userChoices.at(i) = false;
    }

    while (roomNum != -1) {
        switch (roomNum) {

        case 0:
            roomNum = beginning();
            break;

        case 1:
            roomNum = in_room_one(userChoices);
            break;

        case 2:
            roomNum = in_room_two(userChoices);
            break;

        case 3:
            roomNum = in_room_three(userChoices);
            break;

        case 4:
            roomNum = in_room_four(userChoices);
            break;

        case 5:
            roomNum = in_room_five(userChoices);
            break;

        case 6:
            roomNum = in_room_six(userChoices);
            break;

        case 7:
            roomNum = in_room_seven(userChoices);
            break;

        case 8:
            roomNum = in_room_eight(userChoices);
            break;

        case 9:
            roomNum = in_room_nine(userChoices);
            break;

        case 10:
            roomNum = in_room_ten(userChoices);
            break;

        case 11:
            roomNum = in_room_eleven(userChoices);
            break;

        case 12:
            roomNum = in_room_twelve(userChoices);
            break;

        default:
            cout << "Something went wrong with the code." << endl;
            cout << "roomNum is an unknown, unused number." << endl;
        }
    }

    ending();
    return 0;

}



int beginning() {

    // Add Introduction Here, Atmosphere / Setting
    cout << "Beginning of story, eventual intro." << endl;
    return 1;

}



int in_room_one(vector<bool>& currentUserChoices) {

    cout << "entered magic room 1" << endl;

    currentUserChoices.at(0) = true;

    return -1;

}



int in_room_two(vector<bool>& currentUserChoices) {
    //fix to return user output
    return 0;
}



int in_room_three(vector<bool>& currentUserChoices) {
    //fix to return user output
    return 0;
}



int in_room_four(vector<bool>& currentUserChoices) {
    //fix to return user output
    return 0;

}



int in_room_five(vector<bool>& currentUserChoices) {
    //fix to return user output
    return 0;
}



int in_room_six(vector<bool>& currentUserChoices) {
    //fix to return user output
    return 0;
}



int in_room_seven(vector<bool>& currentUserChoices) {
    //fix to return user output
    return 0;
}



int in_room_eight(vector<bool>& currentUserChoices) {
    //fix to return user output
    return 0;
}



int in_room_nine(vector<bool>& currentUserChoices) {
    //fix to return user output
    return 0;
}



int in_room_ten(vector<bool>& currentUserChoices) {
    //fix to return user output
    return 0;
}



int in_room_eleven(vector<bool>& currentUserChoices) {
    //fix to return user output
    return 0;
}



int in_room_twelve(vector<bool>& currentUserChoices) {
    //fix to return user output
    return 0;
}



void ending() {
    //fix to add ending of story, epilogue

    cout << "This is the end." << endl;

}