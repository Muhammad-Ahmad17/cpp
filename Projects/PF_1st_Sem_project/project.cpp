/**
  Copyright (c) 2024          
                              
  Name: MUHAMMAD AHMAD.       
                              
  Project Name: PF.          
                              
  Date: 2024-11-25.  
           
  TIME: 1:44 PM.
*/
#include <fstream>  // for file handling
#include <string>   // for including string
#include <iomanip>  // for formating
#include <cmath>    // for mathematical function
#include <iostream> // for cin and cout

using namespace std;

// Constants
const int MAX_COURSES = 5;
const float FINE_RATE = 5;
const string LAST_DATE_TO_ENROLL = "01/01/2024";  // change with requirment

// Structure to represent a course
struct Course
{
    int courseID;
    string courseName;
};

// Number of courses and course information
const int NUM_COURSES = 5;         // change with requirment
Course courses[NUM_COURSES] =
        {
                {1, "Applied Physics"},
                {2, "Calculus"},
                {3, "Programming Fundamentals"},
                {4, "Functional English"},
                {5, "Ideology and Constitution"},
        };

// Structure to represent a course enrollment
struct CourseEnrollment
{
    int courseID;
    string enrollmentDate;
};

// Structure to represent a student
struct Student
{
    int studentID;
    string name;
    string contact;
    int totalCourses;
    CourseEnrollment courses[MAX_COURSES];
};

// Array to store student information
Student students[100];
int totalStudents = 0;

//VIEW
void displayCourseList();
void displayStudentCourses(int studentID);
void displayFines();
void displayDesign1();
//DATABASE
void loadFromFile();
void saveToFile();
void createFile(const string &filename);
//LOGIC (MODEL)
void enrollStudent(int studentID, int courseID, string enrollmentDate);
int daysInMonth(int month);
int differenceInDays(const string &enrollmentDate);
float calculateFine(int studentID);
void addStudent(int id, string name, string contact);
void displayStudents();
bool fileExists(const string &filename);



int main()
{
    // Display the program's decorative header
    displayDesign1();

    // Load student data from the file
    loadFromFile();

    // Declare a variable for user input
    int choice;

    // Main menu loop
    do
    {
        cout << "\n";
        cout << "=====================================|" << endl;
        cout << "|     STUDENT MANAGEMENT             |" << endl;
        cout << "|====================================|" << endl;
        cout << "| 1. Add Student                     |" << endl;
        cout << "| 2. Display Registered Students     |" << endl;
        cout << "| 3. Enroll Student in a Course      |" << endl;
        cout << "| 4. Display Student's Courses       |" << endl;
        cout << "| 5. Calculate Fines                 |" << endl;
        cout << "| 6. Display Fines                   |" << endl;
        cout << "| 7. Save Data to File               |" << endl;
        cout << "| 8. Load Data from File             |" << endl;
        cout << "| 9. Exit                            |" << endl;
        cout << "|=====================================" << endl;
        cout << "\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout << "\n";

        // Switch statement to execute the selected menu option
        switch (choice)
        {
            case 1:
            {
                // Add a new student
                int id;
                string name, contact;
                cout << "Enter student ID: ";
                cin >> id;
                cout << "Enter student name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter contact information: ";
                getline(cin, contact);
                addStudent(id, name, contact);
                break;
            }
            case 2:
                // Display registered students
                displayStudents();
                break;
            case 3:
            {
                // Enroll a student in a course
                int studentID, courseID;
                string enrollmentDate;
                cout << "Enter student ID: ";
                cin >> studentID;

                // Display the list of available courses
                displayCourseList();

                cout << "Enter course ID to enroll: ";
                cin >> courseID;

                cout << "Enter enrollment date (DD/MM/YYYY): ";
                cin.ignore();
                getline(cin, enrollmentDate);

                enrollStudent(studentID, courseID, enrollmentDate);

                // Save enrollment information in the student's struct
                students[totalStudents - 1].courses[students[totalStudents - 1].totalCourses - 1].courseID = courseID;
                students[totalStudents - 1].courses[students[totalStudents - 1].totalCourses - 1].enrollmentDate = enrollmentDate;

                break;
            }
            case 4:
            {
                // Display courses enrolled by a student
                cout << "\n";
                int studentID;
                cout << "Enter student ID: ";
                cin >> studentID;
                displayStudentCourses(studentID);
                break;
            }
            case 5:
            {
                // Calculate fines for a student
                int studentID;
                cout << "Enter student ID: ";
                cin >> studentID;
                float fine = calculateFine(studentID);
                cout << "Fine for Student ID " << studentID << ": $" << fine << endl;
                break;
            }
            case 6:
                // Display fines for all students
                displayFines();
                break;
            case 7:
                // Save student data to file
                saveToFile();
                break;
            case 8:
                // Load student data from file
                loadFromFile();
                break;
            case 9:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please enter a number between 1 and 9." << endl;
                break;
        }
    }
    while (choice != 9); // Continue the loop until the user chooses to exit

    return 0;
}

// --------------------------------------------------------------------------
// Function to display the list of available courses
void displayCourseList()
{
    cout << "Available Courses:" << endl;
    for (int i = 0; i < NUM_COURSES; ++i)
    {
        cout << "ID: " << courses[i].courseID << ", Name: " << courses[i].courseName << endl;
    }
}
// --------------------------------------------------------------------------

// --------------------------------------------------------------------------
// Function to enroll a student in a course
void enrollStudent(int studentID, int courseID, string enrollmentDate)
{
    // Iterate through students to find the matching student ID
    for (int i = 0; i < totalStudents; ++i)
    {
        // Check if student ID matches
        if (students[i].studentID == studentID)
        {
            // Check if the student has not reached the maximum number of courses
            if (students[i].totalCourses < MAX_COURSES)
            {
                // Add course information to the student's record
                students[i].courses[students[i].totalCourses].courseID = courseID;
                students[i].courses[students[i].totalCourses].enrollmentDate = enrollmentDate;
                students[i].totalCourses++;
                cout << "Student enrolled in the course successfully!" << endl;
                return ;
            }
            else
            {
                cout << "Student has already enrolled in the maximum number of courses." << endl;
                return ;
            }

        }
    }
    cout << "Student not found." << endl;
}
// --------------------------------------------------------------------------

// --------------------------------------------------------------------------
// Function to display the courses enrolled by a student
void displayStudentCourses(int studentID)
{
    // Iterate through students to find the matching student ID
    for (int i = 0; i < totalStudents; ++i)
    {
        // Check if student ID matches
        if (students[i].studentID == studentID)
        {
            cout << "Courses enrolled by Student ID " << studentID << ":" << endl;
            // Iterate through the courses and display information
            for (int j = 0; j < students[i].totalCourses; ++j)
            {
                int courseID = students[i].courses[j].courseID;
                string courseName;

                // Find the course name based on the courseID
                for (int k = 0; k < NUM_COURSES; ++k)
                {
                    if (courses[k].courseID == courseID)
                    {
                        courseName = courses[k].courseName;
                        break;
                    }
                }

                cout << "Course ID: " << courseID << ", Course Name: " << courseName << ", Enrollment Date: " << students[i].courses[j].enrollmentDate << endl;
            }
            return;
        }
    }
    cout << "Student not found." << endl;
}
// --------------------------------------------------------------------------

// --------------------------------------------------------------------------
//Function to return days of specific month
int daysInMonth(int month)
{
    // 1st index is 0 so that the month match with index
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return daysInMonth[month];
}
// --------------------------------------------------------------------------


// --------------------------------------------------------------------------
// Function to calculate the difference in days between two dates
int differenceInDays(const string &enrollmentDate)
{
    int day1, month1, year1;
    int day2, month2, year2;
    int diff;

    // Extract day, month, and year from the enrollment date and the last date to enroll
    sscanf(enrollmentDate.c_str(), "%d/%d/%d", &day1, &month1, &year1);
    sscanf(LAST_DATE_TO_ENROLL.c_str(), "%d/%d/%d", &day2, &month2, &year2);

    // Calculate total days for both dates
    int days1 = year1 * 365 + day1;
    for (int i = 1; i <= month1; ++i)
    {
        days1 += daysInMonth(i);
    }

    int days2 = year2 * 365 + day2;
    for (int i = 1; i <= month2; ++i)
    {
        days2 += daysInMonth(i);
    }

    // Calculate the difference in days
    diff = (days1 - days2);
    return diff;
}
// --------------------------------------------------------------------------

// --------------------------------------------------------------------------
// Function to calculate the fine for a student
float calculateFine(int studentID)
{
    float totalFine = 0.0;

    // Iterate through students to find the matching student ID
    for (int i = 0; i < totalStudents; ++i)
    {
        // Check if student ID matches
        if (students[i].studentID == studentID)
        {
            // Iterate through the courses enrolled by the student
            for (int j = 0; j < students[i].totalCourses; ++j)
            {
                int daysDifference = differenceInDays(students[i].courses[j].enrollmentDate);

                // Check if enrollment is late
                if (daysDifference > 0)
                {
                    totalFine += FINE_RATE * daysDifference;
                }
            }
            break;
        }
    }

    return totalFine;
}
// --------------------------------------------------------------------------

// --------------------------------------------------------------------------
// Function to display fines for all students
void displayFines()
{
    cout << "Student Fines:" << endl;
    bool foundFines = false;

    // Iterate through students to calculate and display fines
    for (int i = 0; i < totalStudents; ++i)
    {
        float fine = calculateFine(students[i].studentID);
        if (fine > 0.0)
        {
            cout << "Student ID: " << students[i].studentID << ", Name: " << students[i].name << ", Fine: $" << fine << endl;
            foundFines = true;
        }
    }

    // Display a message if no fines are found
    if (!foundFines)
    {
        cout << "No fines found for any student." << endl;
    }
}
// --------------------------------------------------------------------------

// --------------------------------------------------------------------------
// Function to add a new student to the system
void addStudent(int id, string name, string contact)
{
    // Check if there is space for a new student
    if (totalStudents < 100)
    {
        // Assign values to the new student
        students[totalStudents].studentID = id;
        students[totalStudents].name = name;
        students[totalStudents].contact = contact;
        students[totalStudents].totalCourses = 0; // Initialize total courses to 0 initially.

        // Increment the total number of students
        totalStudents++;

        cout << "Student added successfully!" << endl;
    }
    else
    {
        cout << "Maximum number of students reached!" << endl;
    }
}
// --------------------------------------------------------------------------

// --------------------------------------------------------------------------
// Function to display the list of all registered students
void displayStudents()
{
    cout << "Registered Students:" << endl;
    for (int i = 0; i < totalStudents; ++i)
    {
        cout << "ID: " << students[i].studentID << ", Name: " << students[i].name << ", Contact: " << students[i].contact << endl;
    }
}
// --------------------------------------------------------------------------

// --------------------------------------------------------------------------
// Function to check if a file exists
bool fileExists(const string &filename)
{
    ifstream file(filename);
    return file.good();
}
// --------------------------------------------------------------------------

// --------------------------------------------------------------------------
// Function to create a new file
void createFile(const string &filename)
{
    ofstream outfile(filename);
    if (!outfile)
    {
        cout << "Error creating file '" << filename << "'." << endl;
        return;
    }
    cout << "File '" << filename << "' created successfully." << endl;
    outfile.close();
}
// --------------------------------------------------------------------------
// --------------------------------------------------------------------------
void loadFromFile()
{
    // Check if the file 'info.txt' exists
    if (!fileExists("info.txt"))
    {
        cout << "File 'info.txt' does not exist." << endl;
        return;
    }

    // Open the file for reading
    ifstream inputFile("info.txt");
    if (!inputFile)
    {
        cout << "Unable to open file 'info.txt' for reading." << endl;
        return;
    }

    // Reset the total number of students to 0
    totalStudents = 0;

    // Read student data from the file
    while (inputFile >> students[totalStudents].studentID >> students[totalStudents].name >> students[totalStudents].contact >> students[totalStudents].totalCourses)
    {
        // Read course enrollment information
        for (int j = 0; j < students[totalStudents].totalCourses; ++j)
        {
            inputFile >> students[totalStudents].courses[j].courseID >> students[totalStudents].courses[j].enrollmentDate;
        }

        // Increment the total number of students
        totalStudents++;
    }

    // Close the input file
    inputFile.close();

    cout << "Data loaded from file successfully." << endl;
}
// --------------------------------------------------------------------------

// --------------------------------------------------------------------------
// Function to save student data to a file
void saveToFile()
{
    // Open the file for writing
    ofstream outputFile("info.txt");
    if (!outputFile)
    {
        cout << "Unable to open file 'info.txt' for writing." << endl;
        return;
    }

    // Write student data to the file
    for (int i = 0; i < totalStudents; ++i)
    {
        // Write student information
        outputFile << students[i].studentID << " " << students[i].name << " " << students[i].contact << " " << students[i].totalCourses << "\n";

        // Write course enrollment information
        for (int j = 0; j < students[i].totalCourses; ++j)
        {
            outputFile << students[i].courses[j].courseID << " " << students[i].courses[j].enrollmentDate << "\n";
        }
    }

    // Close the output file
    outputFile.close();

    cout << "Data saved to file successfully." << endl;
}
// --------------------------------------------------------------------------

// --------------------------------------------------------------------------
// Function to display a decorative header
void displayDesign1()
{
    cout << "\n";
    cout << setw(75) << setfill(' ') << "     _-------------------------------------------_     " << endl;
    cout << setw(75) << setfill(' ') << "    -:-      Welcome to STUDENT MANAGEMENT      -:-    " << endl;
    cout << setw(75) << setfill(' ') << "   -:*:-          Registration System          -:*:-   " << endl;
    cout << setw(75) << setfill(' ') << "  -:*:*:-                                     -:*:*:-  " << endl;
    cout << setw(75) << setfill(' ') << " -:*:*:*:-       === Developed by ===        -:*:*:*:- " << endl;
    cout << setw(75) << setfill(' ') << "  -:*:*:-                                     -:*:*:-  " << endl;
    cout << setw(75) << setfill(' ') << "   -:*:-          MUHAMMAD AHMAD               -:*:-   " << endl;
    cout << setw(75) << setfill(' ') << "    -:-            FA23-BCE-113                 -:-    " << endl;
    cout << setw(75) << setfill(' ') << "     -___________________________________________-     " << endl;
    cout << "\n" ;
}
// --------------------------------------------------------------------------


