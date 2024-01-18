Ticket Booking System (Console-based Mini Project)
This repository contains a C++ program that serves as a console-based mini project simulating a ticket booking system for a cinema with different seating categories - Platinum, Gold, and Silver. The system employs a circular doubly linked list to manage the seating arrangement.
How to Use.

1) Compile the Code: To compile the code, use a C++ compiler like g++.
CMD: g++ filename.cpp -o cinemax (g++ filename.cpp -o cinemax)

3) Run the Executable: After compilation, run the executable:
   ./cinemax
   
5) Navigate the Menu:
Use option 1 to book tickets.
Use option 2 to cancel booked tickets.
Use option 3 to exit the program.
After completing an operation (booking or cancellation), you will be prompted to return to the main menu or exit the program.

6) Understanding the Seating Arrangement:
The seating arrangement consists of three categories: Platinum, Gold, and Silver.
The display shows the layout of the cinema with booked seats marked in red and available seats in green.

7) Important Notes:
During the booking process, you will be asked to input the number of tickets you want to buy and the seat numbers.
Pins are generated for each booked seat and are required for cancellation.

Code Explanation

1) Class and Structure:
The program uses a class named dcll (circular doubly linked list) to manage the seating arrangement.
A structure node is used to represent each seat, storing information such as row number, seat number, PIN, and booking status.

2) Seating Arrangement Creation:
The create method initializes the circular doubly linked list representing the seating arrangement.
Seats are categorized into rows labeled A to H and numbered 1 to 7.

3) Displaying Seating Status:
The display method visualizes the current seating status, highlighting booked seats in red and available seats in green.

4) Booking Seats:
The book_seat method allows users to book tickets by selecting the number of tickets and providing seat numbers.
Booked seats are marked as 'b', and corresponding PINs are generated for future cancellations.

5) Canceling Seats:
The cancel method enables users to cancel booked seats by providing the seat number and PIN.

6) Main Function:
The main function initializes the dcll object, creates the seating arrangement, and presents a menu for booking, canceling, or exiting the program.
