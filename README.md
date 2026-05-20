# 💼 C++ Payroll System

A console-based payroll management system written in C++. The program reads employee records from a text file, prompts the user to enter hours worked, and calculates each employee's gross pay, tax deductions (based on UK tax rules), and net pay.

> **Course:** CO1409 – Assignment 2  
> **Author:** K.A.I. Piumika  
> **Student ID:** G21328023

---

## 📋 Features

- Reads employee data (ID, name, hourly rate) from `employees.txt`
- Accepts hours worked input per employee with input validation
- Calculates gross pay based on hourly rate × hours worked
- Applies UK-style income tax calculation:
  - Personal allowance: £12,570/year
  - Basic tax rate: 20% on taxable income
- Displays a formatted payroll summary including gross pay, tax, and net pay
- Dynamic memory allocation for any number of employees

---

## 📁 Repository Structure

```
cpp-payroll-system/
│
├── main.cpp            # Main source file containing all logic
├── employees.txt       # Input file with employee records
└── README.md           # Project documentation
```

---

## 📄 employees.txt Format

The `employees.txt` file must follow this format — one employee per line, with fields separated by spaces:

```
<EmployeeID> <Name> <HourlyRate>
```

### Example

```
E001 Alice 15.50
E002 Bob 12.00
E003 Carol 20.75
```

> ⚠️ **Note:** Employee names must not contain spaces (use a single word or underscore-separated names like `John_Smith`).

---

## ⚙️ How to Compile & Run

### Prerequisites

- A C++ compiler supporting C++11 or later (e.g., `g++`, `clang++`, MSVC)

### Compile

```bash
g++ -o payroll main.cpp
```

### Run

```bash
./payroll        # Linux / macOS
payroll.exe      # Windows
```

### Expected Interaction

```
Enter hours worked for Alice: 160
Enter hours worked for Bob: 140
Enter hours worked for Carol: 175

Payroll Details:
ID: E001 | Name: Alice | Rate: 15.50 | Hours: 160.00 | Gross Pay: 2480.00 | Tax: 163.50 | Net Pay: 2316.50
ID: E002 | Name: Bob   | Rate: 12.00 | Hours: 140.00 | Gross Pay: 1680.00 | Tax: 57.50  | Net Pay: 1622.50
ID: E003 | Name: Carol | Rate: 20.75 | Hours: 175.00 | Gross Pay: 3631.25 | Tax: 363.21 | Net Pay: 3268.04
```

---

## 🧮 Tax Calculation Logic

Tax is calculated on a **monthly basis** using annualised income:

```
Annual Income      = Monthly Gross Pay × 12
Taxable Income     = Annual Income − £12,570 (personal allowance)
Annual Tax         = Taxable Income × 20%
Monthly Tax        = Annual Tax ÷ 12
```

If the annual income is below £12,570, **no tax is deducted**.

---

## 🔍 Input Validation

- The program rejects non-numeric and negative values for hours worked
- On invalid input, the user is prompted to re-enter the value

---

## ⚠️ Known Limitations

- Employee names cannot contain spaces
- No overtime pay calculation
- Tax calculation uses a simplified flat-rate model (no higher-rate bands)
- Data is not saved to an output file (console display only)

---

## 🚀 Future Improvements

- [ ] Support multi-word employee names using `getline`
- [ ] Add higher tax rate bands (40%, 45%)
- [ ] Export payroll results to a `.txt` or `.csv` file
- [ ] Add National Insurance (NI) contribution calculation
- [ ] Implement a simple menu-driven interface

---

## 📜 License

This project was created for academic purposes as part of the CO1409 module. Feel free to use it as a reference for learning C++ file I/O, dynamic memory, and basic payroll logic.
