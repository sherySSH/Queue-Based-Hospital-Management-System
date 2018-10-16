#include "Queue.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int Queue::idCounter = 1;

Queue::Queue() : numberOfElements(0){
	rear = -1;
	front = -1;
	cout << "\n--------------------------------------\n";
	cout << "Give Size of Patient Queue : ";
	cin >> size;
	cout << "--------------------------------------\n";
	cin.ignore();
	PatientArray = new Patient[size];

	nullPatient.name = "null";
	nullPatient.id = 0;
}

void Queue::enqueue() {
			
	if (!isFull()) {
		rear++;
		enterTheName();
		registerPatient();
		cout << "Quened the Patient ( " << PatientArray[rear].name << " / " 
		     << PatientArray[rear].id << " ) at the index " << rear;
		
		numberOfElements++;

		if (front == -1) {
			front = 0;
		}
		cout << endl;
	}
	else {
		cout << "\n  Queue is Full";
	}

}

Patient Queue::dequeue() {
	if (!isEmpty()) {
		numberOfElements--;
		return PatientArray[front++];
	}
	else {
		cout << "\n  Queue is Empty";
		return nullPatient;
	}
}

bool Queue::isFull() {
	
	if (rear == size - 1)
		return true;
	else
		return false;

}

bool Queue::isEmpty() {
	if (front == rear+1 || rear == -1) // rear = 1
		return true;
	else
		return false;

}

void Queue::enterTheName() {
	cout << "\n-----------------------------------------------------\n";
	cout << "Enter Your Name : ";
	getline(cin, PatientArray[rear].name);
	cout << "\n-----------------------------------------------------\n";
}

void Queue::registerPatient() {
		PatientArray[rear].id = idCounter;
		idCounter++;
}

void Queue::servePatient() {
	Patient *patient;
	if (!isEmpty()) {
		patient = &dequeue();
		cout << "\n-------------------------------------------------------------------\n";
		cout << "Patient " << patient->name << "( id = " << patient->id << ") has been served" << endl;
		cout << "---------------------------------------------------------------------\n";
		//delete patient;
	}
	else {
		cout << "ALL Patients have been served" << endl;
	}

}

void Queue::cancelAll(){

	if (!isEmpty()) {
		for (int counter = 0; counter < numberOfElements; counter++) {
			dequeue();
		}
		cout << "ALL APPOINTMENTS ARE CANCELLED, Queue is empty, \n";
	}
	else {
		cout << "\nQueue is already empty.\n";
	}
}

void Queue::doctorCanGoHome() {

	if (isEmpty()) {
		cout << "\n Doctor Can go home\n";
	}
	else {
		cout << "\n Some Patients are Waiting, Doctor can't go home\n";
	}
}

void Queue::showAllPatient() {
	Patient *displayPatient = new Patient[rear-front+1]; //rear-front+1 is equal to total size of an queue of 
													   	 //patients in real time
	int i = 0;
	/*int index = front;
	for (int counter = 0; counter <= rear && index<=rear; counter++) {
		for (int i = 0; i <  ; i++) {
			if (PatientArray[index].name[i] > PatientArray[index + 1].name[i]) {
				displayPatient[]
			}
			else {

			}
		}
		index++;
	}*/
	/*int tempFront = front;
	while (front <= rear && front < rear ) {
		if (PatientArray[front].id < PatientArray[front + 1].id) {
			displayPatient[i] = PatientArray[front];
		}
		else {
			displayPatient[i] = PatientArray[front+1];
		}
		front++;
		i++;
	}
*/
	cout << "\n-------------------------------------------------\n";
	cout << " NAME" << setw(15) << "ID" << setw(5) << endl << endl;

	for (int counter = 0; counter < numberOfElements; counter++) {
		
		cout << PatientArray[counter].name << setw(15) << PatientArray[counter].id << setw(5) <<endl;
	}
	
//	front = tempFront;
}
