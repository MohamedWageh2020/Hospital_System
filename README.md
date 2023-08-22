#Hospital Queue Management System
This project implements a Hospital Queue Management System using C++. 
The system is designed to manage patient queues for different medical specializations,
allowing for the addition of patients, viewing the current patient queues, and serving the next patient.

#Features
1-Queue Management: The system provides a dynamic queue management mechanism for multiple medical specializations. 
  Each specialization has its own queue, accommodating both regular and urgent patients.

2-Addition of Patients: Users can add patients to the appropriate queue by specifying the patient's name, specialization, and urgency status. 
  Urgent patients are added to the front of the queue, while regular patients are added to the end.

3-Patient Serving: The system enables doctors to serve the next patient from a specific specialization. 
  Once served, the patient is removed from the queue.

4-Queue Printing: The system allows users to print all patient queues, 
  displaying the names of patients in each specialization along with their status (urgent or regular).

5-Menu Interface: The system offers a user-friendly menu interface to interact with the functionalities. 
  Users can select options to perform tasks such as adding patients, printing patient queues, serving patients, and exiting the system.


#Code Structure
The project is divided into two main structs:

1-hospital_queue: Represents a queue for a specific medical specialization. 
  This struct includes functions to add patients, serve patients, shift the queue, and print the queue's contents.

2-hospital_system: Manages the entire hospital system, which includes multiple specializations. 
  This struct contains functions to run the main loop, display the menu, and manage patient interactions.


#How to Use
1-Clone the repository to your local machine.
2-Compile the C++ code using a C++ compiler (e.g., g++).
3-Run the compiled executable to launch the Hospital Queue Management System.
4-Follow the on-screen menu instructions to add patients, print patient queues, serve patients, and exit the system.
