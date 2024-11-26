# Expense Tracker

Expense Tracker is a simple command-line program implemented in C++ that allows users to manage their budget and track expenses. The program provides a menu-driven interface for users to add budget, record expenses, display remaining budget, and more.

## Features

- Add budget amount to track available funds.
- Record expenses with details including date, description, and amount.
- Display remaining budget and list of recorded expenses.
- Delete all budget and expense data.
- Data is automatically saved and loaded between program runs.

## Getting Started

1. Open a new terminal window and navigate to the repository directory.
2. Compile the program using the following command: make -f Expense_Tracker.mak clean all
4. Run the compiled executable using the following command:./Expense_Tracker

## Usage

1. Choose options from the provided menu to interact with the program.
2. Follow the prompts to add budget, record expenses, display data, or delete records.
3. The program will automatically save and load data to/from "data.txt".

## Testing

1. Open a new terminal and navigate to the "tests" folder inside the source repository.
2. Compile the "BudgetExpenseTests.cpp" file using the following command: g++ -std=c++14 -isystem ~/googletest/googletest/include -isystem ~/googletest/googlemock/include -I../include -pthread -o BudgetExpenseTests BudgetExpenseTests.cpp ../src/Budget.cpp ../src/Expense.cpp ~/googletest/build/lib/libgtest.a ~/googletest/build/lib/libgtest_main.a ~/googletest/build/lib/libgmock.a ~/googletest/build/lib/libgmock_main.a
3. Run the compiled executable using the following command: ./BudgetExpenseTests

## Acknowledgments

- This project was developed as part of the final project for CSI5370 - Software Verification and Testing
- This project is for educational purposes and may not include advanced error handling or production-level features.


