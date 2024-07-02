#include <iostream>
#include <windows.h>
#include <cstdlib> // For rand() and srand()
#include <ctime> 
#include "project1.h"
using namespace std;

enum choices
{
    paper = 3, stone = 2, scissors = 1
};

int main()
{
    bool ans = true;
    while (ans){
        int c_win = 0, p_win = 0, no_win = 0;
        srand(static_cast<unsigned int>(time(0)));
        int num; cout << "What the number of rounds you want to play ? \n"; cin >> num; cout << endl;
        int scissors = 1, stone = 2, paper = 3;
        for (int i = 1; i <= num; i++){
            int player_choice;
            cout << "Round [ " << i << " ] begin : \n";
            cout << "\nyour choice : [1]scissors , [2]stone , [3]paper ? "; cin >> player_choice;
            if (player_choice < 1 || player_choice > 3){
                cout << "Invalid choice! Please choose 1, 2, or 3.\n";
                i--;
                continue;
            }
            int computer_choice = rand() % 3 + 1;
            cout << "\n------------------Round[ " << i << " ]---------------------\n";
            cout << "Player choice : ";
            if (player_choice == 1){
                cout << "scissors\n";
            }
            else if (player_choice == 2){
                cout << "stone\n";
            }
            if (player_choice == 3){
                cout << "paper\n";
            }
            cout << "computer choice : ";
            if (computer_choice == 1){
                cout << "scissors\n";
            }
            else if (computer_choice == 2){
                cout << "stone\n";
            }
            if (computer_choice == 3){
                cout << "paper\n";
            }
            if ((computer_choice == 1 && player_choice == 3) || (computer_choice == 2 && player_choice == 1) || (computer_choice == 3 && player_choice == 2)){
                cout << "Round Winner : [Computer]\n";
                cout << "------------------------------------------------\n\n\n";
                 Beep(500, 1500);
                 cin.get();
                system("color 4e");
                c_win++;
            }
            else if ((computer_choice == 3 && player_choice == 1) || (computer_choice == 1 && player_choice == 2) || (computer_choice == 2 && player_choice == 3)){
                cout << "Round Winner : [Player]\n";
                cout << "------------------------------------------------\n\n\n";
                system("color 2F");
                p_win++;
            }
            else if (computer_choice == player_choice){
                cout << "No winner in this Round!\n";
                cout << "------------------------------------------------\n\n\n";
                system("color 3F");
                no_win++;
            }

        }
        cout << "                           ---------------------------------------------\n\n";
        cout << "                                 +++  G A M E    O V E R +++ \n\n";
        cout << "                           ---------------------------------------------\n\n";
        cout << "                           ___________[G A M E  R E S U L T S]___________\n\n";
        cout << "                           Game Rounds        : " << num; cout << "\n\n";
        cout << "                           Player win Times   : " << p_win; cout << "\n\n";
        cout << "                           Player lost Times  : " << c_win; cout << "\n\n";
        cout << "                           Computer win Times : " << c_win; cout << "\n\n";
        cout << "                           Draw Times         : " << no_win; cout << "\n\n";
        cout << "                           The Winner         : ";
        if (p_win > c_win){
            cout << "[Player] \n\n";
        }
        else if (p_win < c_win){
            cout << "[Computer] \n\n";
        }
        else{
            cout << "[No Winner] \n\n";
        }
        cout << "                           ______________________________________________\n\n";
        char p_ans;
        cout << "                           Do you want to play Again? Y/N? "; cin >> p_ans;
        if ( p_ans == 'Y' || p_ans == 'y' ){
            ans = true;
        }
        else if (p_ans == 'N' || p_ans == 'n'){
            ans = false;
        }
        else{
            cout << "Invalid answer : exsiting.........\n";
            ans = false;
        }
    }
    return 0;
}
