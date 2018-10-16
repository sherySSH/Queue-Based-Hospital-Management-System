#include <iostream>
#include "Queue.h"

using namespace std;

int main() {
	
	int input=0;

	cout << "\n------------------------------------------------------------------------------------------------------------------------\n";
	cout << "					Queue-Based Hospital Management System" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------\n";
	cout << " Give Input from 1 to 6 to accomplish a given task. Press any other key to exit from the program.\n" << endl;

	cout << "1. Enquene\n2. Dequene\n3. Serve Patient\n4. Cancel All\n5. Doctor Can Go Home\n6. Show All Patient" <<endl;

	Queue patientQueue;


	while (1) {
		std::cout << "\nGive Your Input : ";

		cin.ignore();
		switch (input) {
		case 1:
			cout << "1. Enqueue " << endl;
			patientQueue.enqueue();
			break;
		case 2:
			cout << "2. Dequeue " << endl;
			patientQueue.dequeue();
			break;
		case 3:
			cout << "3. Serve Patient" << endl;
			patientQueue.servePatient();
			break;
		case 4:
			cout << "4. Cancel All" << endl;
			patientQueue.cancelAll();
			break;
		case 5:
			cout << "5. Doctor Can Go Home" << endl;
			patientQueue.doctorCanGoHome();
			break;
		case 6:
			cout << "6. Show All Patient" << endl;
			patientQueue.showAllPatient();
		default:
			break;
		}
	}
	cout << "\n";
	system("pause");
	return 0;
}