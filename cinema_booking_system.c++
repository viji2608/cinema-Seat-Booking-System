#include <iostream>
using namespace std;

const int ROWS = 5, COLS = 7;
int seats[ROWS][COLS] = {0}; // 0 = available, 1 = booked


// Shows the full seating layout, 0 for available and 1 for booked seats
void viewSeats() {
    cout << "\n--- Seat Layout (0 = Available, 1 = Booked) ---\n";
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << seats[i][j] << " ";
        }
        cout << "\n";
    }
}


// Books a single seat if it's available
void bookSingleSeat() {
    int r, c;
    cout << "Enter row and column to book (0-based): ";
    cin >> r >> c;

    // Check if within range and seat is available
    if (r >= 0 && r < ROWS && c >= 0 && c < COLS && seats[r][c] == 0) {
        seats[r][c] = 1;
        cout << "Seat booked successfully.\n";
    } else {
        cout << "Invalid or already booked seat.\n";
    }
}


// Books a group of adjacent seats in a row
void bookBlockSeats() {
    int row, startCol, count;
    cout << "Enter row, starting column, and number of seats to book (0-based): ";
    cin >> row >> startCol >> count;

    // Validate input range
    if (row >= 0 && row < ROWS && startCol >= 0 && startCol + count <= COLS) {
        bool canBook = true;

        // Check all seats in block are free
        for (int i = 0; i < count; i++) {
            if (seats[row][startCol + i] == 1) {
                canBook = false;
                break;
            }
        }

        // Book if all are free
        if (canBook) {
            for (int i = 0; i < count; i++) {
                seats[row][startCol + i] = 1;
            }
            cout << "Block booked successfully.\n";
        } else {
            cout << "One or more seats already booked in this block.\n";
        }
    } else {
        cout << "Invalid row or seat range.\n";
    }
}


// Cancels a booking if seat is valid and currently booked
void cancelSeat() {
    int r, c;
    cout << "Enter row and column to cancel (0-based): ";
    cin >> r >> c;

    if (r >= 0 && r < ROWS && c >= 0 && c < COLS && seats[r][c] == 1) {
        seats[r][c] = 0;
        cout << "Booking cancelled.\n";
    } else {
        cout << "Invalid seat or not booked.\n";
    }
}


// Shows only the seats that are currently free
void displayAvailableSeats() {
    cout << "\n--- Available Seats ---\n";
    bool found = false;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (seats[i][j] == 0) {
                cout << "Seat (" << i << "," << j << ") is available\n";
                found = true;
            }
        }
    }

    if (!found)
        cout << "No seats are available.\n";
}

// Menu-driven dashboard to perform seat booking operations
int main() {
    int choice;

    while (true) {
        cout << "\n====== Cinema Seat Booking Menu ======\n";
        cout << "1. View Seat Layout\n";
        cout << "2. Book a Single Seat\n";
        cout << "3. Book a Block of Seats\n";
        cout << "4. Cancel a Seat Booking\n";
        cout << "5. Display Available Seats Only\n";
        cout << "6. Exit\n";
        cout << "Enter your choice (1 to 6) to select a function: ";
        cin >> choice;

        switch (choice) {
            case 1: viewSeats(); break;
            case 2: bookSingleSeat(); break;
            case 3: bookBlockSeats(); break;
            case 4: cancelSeat(); break;
            case 5: displayAvailableSeats(); break;
            case 6:
                cout << "Exiting system. Thank you!\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}