#include <iostream>
#include "Tasks.h"

using namespace std;

int main()
{
	int choice;
	do {
		cout << "Input a number to call a function for a corresponding task or 0 to exit (e.g 1 for first task, 2 for second, etc) : ";
		cin >> choice;
		cout << "\033[2J\033[0H";
		switch (choice) {
		case 0:
			return 0;
		case 1:
			cout << "\033[32mTask 1 called: \033[0m\n\n";
			Tasks::task1main();
			cout << "\n\033[32mTask 1 function ended.\033[0m\n\n";
			break;
		case 2:
			cout << "\033[32mTask 2 called: \033[0m\n\n";
			Tasks::task2main();
			cout << "\n\033[32mTask 2 function ended.\033[0m\n\n";
			break;
		case 3:
			cout << "\033[32mTask 3 called: \033[0m\n\n";
			//Tasks::task3main();
			cout << "\n\033[32mTask 3 function ended.\033[0m\n\n";
			break;
		case 4:
			cout << "\033[32mTask 4 called: \033[0m\n\n";
			//Tasks::task4main();
			cout << "\n\033[32mTask 4 function ended.\033[0m\n\n";
			break;
		default:
			cout << "\033[31mInvalid input.\033[0m Try again!" << endl;
			break;
		}
	} while (true);
}
