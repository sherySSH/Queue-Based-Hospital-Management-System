#include <cctype>
#include <string>

using namespace std;

class Patient {
public:
	string name;
	int id;
};


class Queue {
private:
	int size;
	int rear;
	int front;
	int numberOfElements;
	static int idCounter;
	Patient *PatientArray;
	Patient nullPatient;
public :
	Queue();
	void enqueue();
	Patient dequeue();
	bool isEmpty();
	bool isFull();
	void enterTheName();
	void registerPatient();
	void servePatient();
	void cancelAll();
	void doctorCanGoHome();
	void showAllPatient();
};