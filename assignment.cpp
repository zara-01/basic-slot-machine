// big bunch of includes

#include <stdio.h>
#include <stdlib.h> 
#include <ctype.h> 
#include <string> 
#include <iostream> 
#include <conio.h>
#include <string>
#include <ctime>
#include <windows.h>
#include <iomanip> 
using namespace std;



//globals

HANDLE hconsole;
CONSOLE_SCREEN_BUFFER_INFO con_info;



//  functions


// function #1


int slots1(int firstslot, int secondslot, int thirdslot) // function that makes all three columns rotate
{

	firstslot = rand() % 10 + 1;
	secondslot = rand() % 10 + 1;
	thirdslot = rand() % 10 + 1;

	cout << "\r" << "**********************[" << firstslot << "] [" << secondslot << "] [" << thirdslot << "]********************";// show slots
	return firstslot; // return value
}



// function #2


int slots2(int firstslot, int secondslot, int thirdslot) // function that makes the second and third columns spin; first slot is static
{
	firstslot = firstslot; // disables first column
	secondslot = rand() % 10 + 1;
	thirdslot = rand() % 10 + 1;

	cout << "\r" << "*********************[" << firstslot << "] [" << secondslot << "] [" << thirdslot << "]********************";// show slots
	return secondslot; // return value
}


// function #3


int slots3(int firstslot, int secondslot, int thirdslot) // only makes the last column spin; first and second slots are static
{
	firstslot = firstslot; // disables first column
	secondslot = secondslot; // disables second column
	thirdslot = rand() % 10 + 1;

	cout << "\r" << "*********************[" << firstslot << "] [" << secondslot << "] [" << thirdslot << "]********************";// show slots
	return thirdslot; // return value
}



// function #4


void displayslots(int firstslot, int secondslot, int thirdslot) // displays all three columns once they've stopped rotating
{
	cout << "\r" << "*********************[" << firstslot << "] [" << secondslot << "] [" << thirdslot << "]********************";// show slots
}




// the main execute program

int main()
{

	// variables 

	char key;

	double total_money = 0;
	double total_wins = 0;
	double total_tries = 0;
	double win_percentage;

	char machine_running = 'Y';

	//cout << "**************Welcome to Virtual Slots.***************" << endl;  //     explains
	//cout << "**************Match 2, win that amount.***************" << endl;  //     rules and 
	//cout << "************Match 3, win 3x that amount.**************" << endl;  //   jackpot prizes;
	//cout << "**********Press A to stop the first wheel,************" << endl;  //    establishing
	//cout << "****S to stop the second, and D to stop the third.****" << endl;  //      controls

	do
	{
		// set slot values

		int slot1 = 0;
		int slot2 = 0;
		int slot3 = 0;

		// set control values

		int stopslot1 = 0;
		int stopslot2 = 0;
		int stopslot3 = 0;

		bool reset = false;

		// print slot layout

		cout << "**************Welcome to Virtual Slots.***************" << endl;  //     explains
		cout << "**************Match 2, win that amount.***************" << endl;  //     rules and 
		cout << "************Match 3, win 3x that amount.**************" << endl;  //   jackpot prizes;
		cout << "**********Press A to stop the first wheel,************" << endl;  //    establishing
		cout << "****S to stop the second, and D to stop the third.****" << endl;  //      controls
		cout << "*************************SLOTS************************" << endl;
		cout << "******************************************************" << endl;


		// start loops for roating slots whilst taking character inputs

		while (stopslot1 == 0)
		{
			if (_kbhit())
			{
				key = toupper(_getch());

				if (key == 'A') // stops the first column
				{
					stopslot1 = stopslot1 + 1;
				}
				// end if
			}
			// end if

			// call the function to rotate the slots

			slot1 = slots1(slot1, slot2, slot3); 

			// set refresh

			Sleep(100);

		}

		

		while (stopslot2 == 0)
		{
			if (_kbhit())
			{
				key = toupper(_getch());

				if (key == 'S')
				{
					stopslot2 = stopslot2 + 1;
				}
				//end if
			}
			//end if

			// call function to rotate slots

			slot2 = slots2(slot1, slot2, slot3);

			// set refresh

			Sleep(100);
		}
		

		while (stopslot3 == 0)
		{
			if (_kbhit())
			{
				key = toupper(_getch());

				if (key == 'D')
				{
					stopslot3 = stopslot3 + 1;
				}
				//end if
			}
			//end if

			// call function to rotate slots

			slot3 = slots3(slot1, slot2, slot3);

			// set refresh

			Sleep(100);

		}

		// prizes

		if (slot1 == slot2 == slot3) 
		
		{  // If all three slots match, user getx 3x money

			cout << "\n";
			cout << "THREE TIMES MATCH!!!" << endl;
			cout << "You win $" << (slot1 * 3) << ".\n" << endl;

			total_money += slot1;  // Count money
			total_wins++;  // Count wins
		}

		else if (slot1 == slot2 || slot1 == slot3 || slot2 == slot3) {  // if user gets 2 slots matched, user gets that amount of money

			cout << "\n";
			cout << "TWO TIMES MATCH!!" << endl;
			cout << "You win $" << slot1 << ".\n" << endl;

			total_money += slot1;  // Count money
			total_wins++;  // Count wins
		}

		else {  // No match, no money

			cout << "\n";
			cout << "NO MATCH.\n" << endl;
		}

		total_tries++;  // Count tries

		win_percentage = (total_wins / total_tries);  // Percentage of wins

		cout << "Current Total: $" << setprecision(4) << total_money << endl;                // show user their statistics
		cout << "Win Percentage: " << setprecision(3) << win_percentage << "%" << endl;		// set precision sets number precision to set places

		cout << "Enter Y if you would like to spin again, press N to quit.\n" << endl;  // Ask the user if s/he wants to play again
		
		while (reset == false)
		{

			if (_kbhit())
			{
				key = toupper(_getch());

				if (key == 'N')
				{
					machine_running = 'N';
					reset = true;
				}
				//end if

				else if (key == 'Y')
				{
					reset = true;
				}

				else
				{
					cout << "Please enter a valid input: " << endl;
					reset = false;
				}
			}
			//end if

			
		} 

		

		system("PAUSE");
		system("CLS"); // clear screen



	} while (machine_running != 'N'); // check loop conditions

	system("CLS"); // clear screen

	cout << "Your total winnings is: $" << setprecision(4) << total_money << endl;
	cout << "Your overall win percantage is: " << setprecision(3) << win_percentage << "%" << endl;
	//cout << "game over"; // display game over screen

	return 0;
}

// end of program loop