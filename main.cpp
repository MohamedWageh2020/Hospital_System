#include <iostream>
using namespace std;

// Define the maximum number of specializations and the maximum queue size
const int MAX_SPECIALIZATION = 21;
const int MAX_QUEUE = 6;

// Struct to represent a hospital queue
struct hospital_queue {
    string names[MAX_QUEUE];  // Array to store patient names
    int status[MAX_QUEUE];    // Array to store patient status (0 for regular, 1 for urgent)
    int spec;                 // Specialization number for this queue
    int len;                  // Current number of patients in the queue

    // Default constructor
    hospital_queue(){
        len = 0;               // Initialize the number of patients to 0
        spec = -1;             // Initialize the specialization to an invalid value
    }

    // Constructor with specialization parameter
    hospital_queue(int _spec){
        len = 0;               // Initialize the number of patients to 0
        spec = _spec;          // Set the specialization to the provided value
    }

    // Add a patient to the end of the queue
    void add_end(string name, int st) {
        len++;                 // Increment the number of patients
        if (len == MAX_QUEUE) {
            return;             // If the queue is full, return without adding the patient
        }
        names[len] = name;     // Add the patient's name to the end of the queue
        status[len] = st;      // Set the patient's status
        return;
    }

    // Add a patient to the front of the queue
    void add_front(string name, int st) {
        len++;                 // Increment the number of patients
        if (len == MAX_QUEUE) {
            return;             // If the queue is full, return without adding the patient
        }
        shift_right();         // Shift existing patients to the right
        names[1] = name;       // Add the new patient's name to the front of the queue
        status[1] = st;        // Set the new patient's status
        return;
    }

    // Shift elements to the right
    void shift_right() {
        for (int i = len - 1; i > 0; i--) {
            names[i + 1] = names[i];   // Shift patient names to the right
            status[i + 1] = status[i]; // Shift patient statuses to the right
        }
    }

    // Remove a patient from the front of the queue
    void remove_front() {
        if (len == 0) {
            cout << "There is no patient at this moment. Have a rest Dr\n";
            return;
        }
        cout << names[1] << " go with the doctor\n";  // Print the name of the patient going to the doctor
        shift_left();           // Shift remaining patients to the left
        len--;                  // Decrement the number of patients
    }

    // Shift elements to the left
    void shift_left() {
        for (int i = 1; i <= len; i++) {
            names[i] = names[i + 1];       // Shift patient names to the left
            status[i] = status[i + 1];     // Shift patient statuses to the left
        }
    }

    // Print details of the queue
    void print() {
        if (len == 0) {
            return;             // If the queue is empty, return without printing
        }
        cout << "There are " << len << " patients in specialization " << spec << "\n";
        for (int i = 1; i <= len; i++) {
            cout << names[i] << " ";
            if (status[i] == 0)
                cout << "regular\n";
            else
                cout << "urgent\n";
        }
        cout << "\n";
    }
};

// Struct to represent the hospital system
struct hospital_system {
    hospital_queue queues[MAX_SPECIALIZATION];  // Array of queues for different specializations

    // Constructor to initialize the hospital system
    hospital_system() {
        for (int i = 0; i < MAX_SPECIALIZATION; ++i) {
            queues[i] = hospital_queue(i);  // Initialize each queue with its specialization number
        }
    }

    // Run the main loop of the hospital system
    void run() {
        while (true) {
            int choice = menu();     // Get user's choice from the menu
            switch (choice) {
                case 1:
                    add_patient();   // Call function to add a patient
                    break;
                case 2:
                    print_patients(); // Call function to print all patients
                    break;
                case 3:
                    get_next_patient(); // Call function to get the next patient
                    break;
                case 4:
                    return;           // Exit the loop
                    break;
                default:
                    printf("Undefined option, please select again");
                    break;
            }
        }
    }

    // Display the menu and get user's choice
    int menu() {
        int op;
        cout << "1- Add new patient\n";
        cout << "2- Print all patients\n";
        cout << "3- Get next Patient\n";
        cout << "4- Exit\n";
        cout << "Enter your choice: ";
        cin >> op;
        return op;
    }

    // Add a new patient to the appropriate queue
    void add_patient() {
        int spec, status;
        string name;
        cout << "Enter specialization, name and status: ";
        cin >> spec >> name >> status;
        if (queues[spec].len + 1 == MAX_QUEUE) {
            cout << "Sorry, we cannot add more patients for this specialization\n";
        } else {
            if (status == 1) {
                queues[spec].add_front(name, status); // Add urgent patient to the front
            } else if (status == 0) {
                queues[spec].add_end(name, status);   // Add regular patient to the end
            }
        }
    }

    // Print all patients in all specializations
    void print_patients() {
        for (int i = 0; i < MAX_SPECIALIZATION; i++) {
            cout << "*******************************\n";
            queues[i].print();  // Print the details of each queue
        }
    }

    // Get the next patient from a specific specialization
    void get_next_patient() {
        int spec;
        cout << "Enter specialization: ";
        cin >> spec;
        queues[spec].remove_front();  // Remove the next patient from the queue
    }
};

// Main function
int main(void) {
    hospital_system hospital = hospital_system(); // Create an instance of the hospital system
    hospital.run();  // Run the hospital system's main loop
}