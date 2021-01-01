using namespace std;

// Global variables
const int MAX_SPECIALIZATION = 20; // 20 Available spatializations in hospital ... like- Dental, child, surgery
const int MAX_QUEUE = 5;    // maximum waiting line

// Main Menu
int menu() {
	int choice = -1;
	while (choice == -1) {
		cout << "\nEnter your response:\n";
		cout << "1) Add patient\n";
		cout << "2) Print all patients\n";
		cout << "3) Get next patient\n";
		cout << "4) Exit\n";

		cin >> choice;

		if (!(1 <= choice && choice <= 4)) {
			cout << "Invalid choice. Try again\n";
			choice = -1;	// loop keep working
		}
	}
	return choice;
}