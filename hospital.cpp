#include<iostream>
using namespace std;

// Global variables
const int MAX_SPECIALIZATION = 20; // 20 Available spatializations in hospital ... like- Dental, child, surgery
const int MAX_QUEUE = 5;    // maximum waiting line


string names[MAX_SPECIALIZATION+1][MAX_QUEUE+1];
int status[MAX_SPECIALIZATION+1][MAX_QUEUE+1];		// 0 regular, 1 urgent
int queue_length[MAX_SPECIALIZATION+1];			// for each specialization: how many patients so far

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


// change queue after someone left.Like positon 4 will be 3
void shift_left(int spec, string names_sp[], int status_sp[])
{
	int len = queue_length[spec];
	for (int i = 1; i < len; ++i) {
		names_sp[i-1] = names_sp[i];
		status_sp[i-1] = status_sp[i];
	}
	queue_length[spec]--;
}



void hospital_system() {
	while (true) {
		int choice = menu();

		if (choice == 1)
			add_patient();
		else if (choice == 2)
			print_patients();
		else if (choice == 3)
			get_next_patients();
		else
			break;
	}
}

int main() {
//freopen("c.in", "rt", stdin);
	hospital_system();
	return 0;
}