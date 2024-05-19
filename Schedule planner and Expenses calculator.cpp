#include <iostream> 
#include <iomanip>  //  for setw()
#include <string>   //  to use string class
#include <cstring>  //  to use strcpy() function
#include <vector>   //  to use vector container
#include <utility>  //  for pair

using namespace std; 

// Function prototypes
void menu();        // main menu
void mainProgram(); // main program
bool exitProgram(); // exit program status for the main program

// Functions inside  of the mainProgram()
void expenseCalculator(); // expense calculator function
void weekly(); 
void monthly();  

void schedulePlanner(); // schedule planner function

// main function
int main() {
    do {
        menu(); // Display main menu
        mainProgram(); // Execute main program
    } while (!exitProgram()); // Will give the user an option to continue or exit

    return 0;
}

//  Main Menu Function
void menu(){ 
	char name[50]; //  variable to store the users name
	char greetings[] = "\nWelcome to StudyBudget Pro "; //  string to display a welcome message with the name of the program
	cout << "\n------------------------------------------------------------\n"; 
	cout << "\nEnter your name: "; //  prompts the user to enter their name
	cin.getline(name, 50); 
	strcat(greetings, name); // cstring - concatenation of "Hello" and the users name
	cout << greetings << "!";

    //  displays the options available on the main menu
    cout << "\n==============================\n";
    cout << " SCHEDULE PLANNER AND   \n";       
    cout << " EXPENSE CALCULATOR     \n";      
    cout << "                        \n";   
    cout << " [1] Schedule Planner   \n";        
    cout << " [2] Expense Calculator \n";    
    cout << " [3] Exit program       \n";       
}

//  Main Program Function
void mainProgram(){ 
    int choice;

    while(true){ //  loop that will run until a valid option is chosen from the main menu
        cout << " Enter your choice: ";
        cin >> choice;

        if (choice == 1 || choice == 2 || choice == 3){ //  checks if the input matches one of the choices in the main menu
            break;
        } else {
            cout << "\nInvalid input. Try again.\n";
        }
    }

    switch(choice){ //   switch statement that directs the user to the appropriate function based on their choice in the main menu
        case 1: schedulePlanner();
                break;
        case 2: expenseCalculator();
                break;

        case 3: break; // it will automatically go to the exit menu
    }
}

// program exit status menu
bool exitProgram(){ 
    char option;
    cout << endl;
    cout << "\n Press y or Y to exit program. "; //  asking user to confirm if he wants to quit
    cin >> option;
    cin.ignore(); 
    
    if (tolower(option) == 'y') {
        cout << "\n Thank you for using this app!\n"; //   displaying thank you message before closing the application
        return true;
    } else {
        cout << "\n Continuing program... \n";
        return false;
    }
}

// Main functions inside of my program
// Schedule planner and Expenses calculator

//  Schedule Planner
void schedulePlanner(){ 
   	const int daysInWeek = 7; // constant 7 days in a week
	int plansCount = 0; // number of plans is set to 0
	int numPlans[daysInWeek]; //  stores number of plans in each each day of the week

    // for printing what day it is - using for input information
	string days[7] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday","sunday"}; 
	
	cout << "\n=== SCHEDULE PLANNER ===\n";
	cout << "Let's start!\n";
	
	// Getting the number of plans for each day
	cout << "\n=== number of plans\n"; 
	for (int i = 0; i < daysInWeek; ++i) {
		cout << "Enter the number of plans for " << days[i] << ": ";
		cin >> numPlans[i];
		plansCount += numPlans [i];
	}
	
	// 2D array to store plans,time, plan name for each day
	string plans[daysInWeek][plansCount]; // number of plans aligned with what day it is and how many plans it has for each day
	string startHour[daysInWeek][plansCount]; // start hour for what day it is and what number of plan it is in the day
    string endHour[daysInWeek][plansCount]; //  time when the plan ends and aligned with what day it is and what plan it is in the day
	
	//Assign names to each plan for each day
	cout << "\n=== Setting up\n"; 
	for (int i = 0; i < daysInWeek; ++i) { //  loop through each day
        cout << "=== For " << days[i] << ":\n";
        for (int j = 0; j < numPlans[i]; ++j) {
            cout << "\tEnter the name of plan " << j + 1 << ": "; // enter a name for each plan for each day
            cin.ignore();
			getline(cin, plans[i][j]);
            
            // Assigning time for each plan
            cout <<"\n\t=== Assign time\n";  
            cout << "\tEnter the start hour for plan " << plans[i][j] << ": "; // start hour
            cin >>startHour[i][j];
            
            // Setting if AM or PM start hour
        	int am_pm;
        	while(true) {
        		cout << "\tAM (1) or PM (2)? "; 
        		cin >> am_pm;
        		if (am_pm == 1) {
            		startHour[i][j] += " AM";
            		break;
        		} else if (am_pm == 2) {
            		startHour[i][j] += " PM";
            		break;
        		} else {
        			cout << "\n\tEnter a valid option. Try again.\n"; //  If user enters anything other than 1 or 2, it will ask again until they enter correct input
				}
			}
        	
            cout << "\n\tEnter the end hour for plan " << plans[i][j] << ": "; // end hour 
        	cin >> endHour[i][j];
        	
        	// Setting if AM or PM end hour
        	while(true) {
        		cout << "\tAM (1) or PM (2)? "; 
        		cin >> am_pm;
        		if (am_pm == 1) {
            		endHour[i][j] += " AM";
            		break;
        		} else if (am_pm == 2) {
            		endHour[i][j] += " PM";
            		break;
        		} else {
        			cout << "\n\tEnter a valid option. Try again.\n";
				}
			}
        	cout << "------------------------------------------------------------\n";
    	}
	}

    //  Displaying all plans and their details in a table format 
	cout << "\nYour Schedule \n";
    cout << "-----------------------------------------------------------------------\n";
    cout << "| Day       | Plans                          | Hours                  |\n";
    cout << "-----------------------------------------------------------------------\n";

    //  Printing each day's schedule with its respective plans and hours
    for (int i = 0; i < daysInWeek; ++i) {
        bool firstPlan = true; // to check whether it is the first plan of that day
        for (int j = 0; j < numPlans[i]; ++j) {
            
            if (firstPlan) { 
                cout << "| " << setw(9) << left << days[i] << " "; //  If it is the first plan of the day, print the day name
                firstPlan = false; // after the name of the day is printed the firstPlan it = false which does not print any day 
            } else {
                cout << "|            "; //  spacing between two plans of same day - below the day column
            }
            //   printing the plan - start hour - end hour 
            cout << " | " << setw(29) << left << plans[i][j] << " | " << setw(15) << left << startHour[i][j] << " - " << endHour[i][j] << " |\n"; 
        }
       
        if (numPlans[i] == 0) {
            //  If there are no plans on that particular day. No plan will be printed
            cout << "| " << setw(9) << left << days[i] << " | " << setw(29) << left << " " << " | " << setw(15) << left << " " << " |\n";
        }
    }
    cout << "-----------------------------------------------------------------------\n";

			
}

void expenseCalculator() {

    int budgetOpt; //  budget Option 
    float budget = 0; 


    //   Displays the options for how the users would like to budget savings
    
    cout << "\n=== EXPENSE CALCULATOR ===\n";
    cout << "Let's start!\n";
    cout << "\n\tHow would you like to budget your savings? \n";
    cout << "\t[1] Weekly\n";
    cout << "\t[2] Monthly\n";

    while (true) { //   Loop that runs until a valid option is selected for budgeting frequency
        cout << "\tEnter: ";
        cin >> budgetOpt;
        if (budgetOpt == 1 || budgetOpt == 2) { //   If user enters either '1' or '2', then set the variable and exit the loop
            break;
        } else {
            cout << "\tEnter a valid option. Try again.\n";
        }
    }

    //  For entering the amount for budget

    cout << "\n=== setting up\n\n";

    while (true) {
        //    Prompts user to enter their desired weekly or monthly budget 
        cout << "\tHow much is your budget " << (budgetOpt == 1 ? "Weekly? : " : "Monthly? : ");
        cin >> budget;
        if (budget > 0) {
            break;
        }
        cout << "\n\tEnter a positive value. Try again.\n"; //    If input isn't positive, prompts user to try again
    }

    int size = 0; //   Number of items in array
    int additional = 0; //   Additional item added by user
    vector<pair<string, float>> expenses; // a 2d vector for (name of expense, amount)

    // Prompts user to enter the number of expenses
    while (true) { 
        cout << "\tEnter how many expenses do you have: "; 
        cin >> size;
        cin.ignore(); // ignore newline character after reading size
        //  Checks if input is not an integer, and prompts user to try again
        if (size >= 1) { 
            break;
        } else if (size == 0) {
            cout << "\nEnter a non-zero value. Try again.\n"; //  User entered zero, so they probably made an error
        } else {
            cout << "\nEnter a non-negative value. Try again.\n"; //    Error message when inputting negative number
        }
    }

    // naming each expenses and giving amount value
    cout << "\n=== Enter name and the amount you spend on each expenses per day\n";
    for (int i = 0; i < size; i++) {
        string name;
        float amount;
        cout << "\n\tEnter the name of expense " << i + 1 << ": ";
        getline(cin, name);

        while (true) { 
            cout << "\tEnter the amount: "; 
            cin >> amount;
            cin.ignore();
            if (size >= 1) { 
                break;
            } else if (size == 0) {
                cout << "\nEnter a non-zero value. Try again.\n"; //  User entered zero, so they probably made an error
            } else {
                cout << "\nEnter a non-negative value. Try again.\n"; //    Error message when inputting negative number
            }
        }
        expenses.push_back({name, amount});
    }
    // Allows user to add more expenses by pressing 'y'
    cout << "\nWould you like to add another expense? (y/n): ";
    char choice;
    cin >> choice;

    if (tolower(choice) == 'y') {
        while (true) { 
        cout << "\tHow many would you like to add?: "; //    Asks user how many items they will add
        cin >> additional;
       
        //  Checks if input is not an integer, and prompts user to try again
            if (size >= 1) { 
                break;
            } else if (size == 0) {
                cout << "\nEnter a non-zero value. Try again.\n"; //  User entered zero, so they probably made an error
            } else {
                cout << "\nEnter a non-negative value. Try again.\n"; //    Error message when inputting negative number
            }
        }

        // for naming the additional expenses
        for (int i = 0; i < size; i++) {
        string name;
        float amount;
        cin.ignore();
        cout << "\n\tEnter the name of expense " << size + 1 << ": ";
        getline(cin, name);

        // for giving the amount of expenses
            while (true) { 
                cout << "\tEnter the amount: "; 
                cin >> amount;
                if (size >= 1) { 
                    break;
                } else if (size == 0) {
                    cout << "\nEnter a non-zero value. Try again.\n"; //  User entered zero, so they probably made an error
                } else {
                    cout << "\nEnter a non-negative value. Try again.\n"; //    Error message when inputting negative number
                }
            }
        expenses.push_back({name, amount});
        }
    }
    
    cout << "\n=== List of Expenses\n";
    cout << "\n\tExpenses: \n";

    float totalAmount = 0;
   
    for (int i = 0; i < expenses.size(); i++){
        cout << "\t" << expenses[i].first << "\t\tAmount: ₱" << expenses[i].second << endl;
        totalAmount += expenses[i].second;
    }

    if (budgetOpt == 1){
            totalAmount *= 7;
        } else {
            totalAmount *= 30;
        }
    
    float savings = budget - totalAmount;
    cout << "\n\tBudget         : ₱" << setprecision(2) << fixed << budget;
    cout << "\n\tTotal Expenses : ₱" << setprecision(2) << fixed << totalAmount;
    cout << "\n\tTotal Savings  : ₱" << setprecision(2) << fixed << savings;

    cout << "\n-----------------------------------------------------------------------\n";
}