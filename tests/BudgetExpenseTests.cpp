#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Budget.h"
#include "Expense.h"
#include <fstream>
#include <sstream>
#include <streambuf>

// Mock class for std::cout testing
class CoutMock {
public:
    MOCK_METHOD(void, output, (const std::string&));
};

// Helper function to capture std::cout output
std::string captureOutput(std::function<void()> func) {
    std::streambuf* originalCoutStreamBuf = std::cout.rdbuf();
    std::ostringstream capturedOutput;
    std::cout.rdbuf(capturedOutput.rdbuf());

    func(); // Execute the passed function

    std::cout.rdbuf(originalCoutStreamBuf); // Restore original buffer before returning
    return capturedOutput.str();
}

// Tests for Budget class
class BudgetTest : public ::testing::Test {
protected:
    Budget budget;

    void SetUp() override {
        // Initialization code here
    }

    void TearDown() override {
        // Cleanup code here
    }
};

TEST_F(BudgetTest, ConstructorInitializesToZero) {
    EXPECT_EQ(budget.getAmount(), 0.0);
}

TEST_F(BudgetTest, AddAmount) {
    budget.addAmount(100.0);
    EXPECT_EQ(budget.getAmount(), 100.0);
}

TEST_F(BudgetTest, SubtractAmount) {
    budget.addAmount(100.0); // Setting initial amount
    budget.subtractAmount(50.0);
    EXPECT_EQ(budget.getAmount(), 50.0);
}

TEST_F(BudgetTest, DisplayRemainingBudget) {
    std::string output = captureOutput([&](){ budget.displayRemainingBudget(); });
    EXPECT_TRUE(output.find("Remaining Budget: $") != std::string::npos);
}

// Tests for Expense class
class ExpenseTest : public ::testing::Test {
protected:
    Expense expense;

    void SetUp() override {
        // Initialization code here
    }

    void TearDown() override {
        // Cleanup code here
    }
};

TEST_F(ExpenseTest, ConstructorInitializesCorrectly) {
    std::string date = "2024-04-07";
    std::string description = "Test Expense";
    double amount = 100.0;
    Expense customExpense(date, description, amount);

    EXPECT_EQ(customExpense.getDate(), date);
    EXPECT_EQ(customExpense.getDescription(), description);
    EXPECT_EQ(customExpense.getAmount(), amount);
}

TEST_F(ExpenseTest, DisplayExpenseDetails) {
    std::string output = captureOutput([&](){ expense.displayExpenseDetails(); });
    EXPECT_TRUE(output.find("Date:") != std::string::npos);
    EXPECT_TRUE(output.find("Description:") != std::string::npos);
    EXPECT_TRUE(output.find("Amount: $") != std::string::npos);
}

// Integration Tests
class IntegrationTest : public ::testing::Test {
protected:
    Budget budget;
    Expense expenses[10]; // Assuming a maximum of 10 expenses for simplicity
    int numExpenses;

    void SetUp() override {
        // Load data from file or initialize variables
    }

    void TearDown() override {
        // Cleanup, including saving data if necessary
    }

    // Additional helper functions for testing as necessary
};

// Add integration test cases here
// Example:
TEST_F(IntegrationTest, SaveAndLoadData) {
    // Implement saving and loading test
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
