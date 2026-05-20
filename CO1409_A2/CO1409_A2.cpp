// CO1409_A2 - Payroll System
// Student Name: K.A.I.Piumika
// Student ID: G21328023
// Description: This program calculates employee wages, including tax deductions.

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

struct Employee {
    std::string id;
    std::string name;
    double hourlyRate;
    double hoursWorked;
};

// Function to read employee details from employees.txt
void readEmployeeData(Employee*& employees, int& count) {
    std::ifstream file("employees.txt");
    if (!file) {
        std::cerr << "Error opening employees.txt" << std::endl;
        return;
    }

    count = 0;
    std::string id, name;
    double rate;

    // First, count the number of employees
    while (file >> id >> name >> rate) {
        count++;
    }

    // Allocate memory for employees
    employees = new Employee[count];

    // Reset file to beginning
    file.clear();
    file.seekg(0, std::ios::beg);

    // Read employee data
    for (int i = 0; i < count; i++) {
        file >> employees[i].id >> employees[i].name >> employees[i].hourlyRate;
        employees[i].hoursWorked = 0; // Default to zero
    }

    file.close();
}

// Function to input hours worked manually
void readHoursWorked(Employee* employees, int count) {
    for (int i = 0; i < count; i++) {
        std::cout << "Enter hours worked for " << employees[i].name << ": ";
        std::cin >> employees[i].hoursWorked;

        // Validate input
        while (std::cin.fail() || employees[i].hoursWorked < 0) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Invalid input. Enter hours again: ";
            std::cin >> employees[i].hoursWorked;
        }
    }
}

// Function to calculate tax based on income
double calculateTax(double monthlyIncome) {
    double annualIncome = monthlyIncome * 12;
    double taxableIncome = annualIncome - 12570; // Personal allowance

    if (taxableIncome <= 0) {
        return 0.0; // No tax if below allowance
    }

    double annualTax = taxableIncome * 0.20; // 20% tax rate
    return annualTax / 12; // Convert to monthly tax
}

// Function to calculate and display payroll
void calculatePayroll(Employee* employees, int count) {
    std::cout << "\nPayroll Details:\n";
    std::cout << std::fixed << std::setprecision(2);

    for (int i = 0; i < count; i++) {
        double grossPay = employees[i].hourlyRate * employees[i].hoursWorked;
        double tax = calculateTax(grossPay);
        double netPay = grossPay - tax;

        std::cout << "ID: " << employees[i].id
            << " | Name: " << employees[i].name
            << " | Rate: " << employees[i].hourlyRate
            << " | Hours: " << employees[i].hoursWorked
            << " | Gross Pay: " << grossPay
            << " | Tax: " << tax
            << " | Net Pay: " << netPay << "\n";
    }
}

int main() {
    Employee* employees = nullptr;
    int employeeCount = 0;

    readEmployeeData(employees, employeeCount);
    if (employeeCount == 0) {
        std::cerr << "No employees found. Exiting program.\n";
        return 1;
    }

    readHoursWorked(employees, employeeCount);
    calculatePayroll(employees, employeeCount);

    // Clean up allocated memory
    delete[] employees;

    return 0;
}
