
#include<stdio.h>
#include<stdlib.h>
#include <conio.h>
#include<time.h>
#define PRICE_PER_DAY 100 
#define NUM_ROOMS 50

struct CustomerDetails  
{
    char name[20];
    char address[25];
    long phonenumber;
    char nationality[15];
    long idproof;
    char email[20];
    char period[10];
    char arrivaldate[10]; 

} s;

void frontpage();

void frontpage() {
    printf(" -------------------------------------------------------------------------\n");
	printf("|                                                                         |\n");      
	printf("|                                                                         |\n");
	printf("|  O       0  OOOOOO  O        OOOOOO  OOOOOOO  OO   OO  OOOO00           |\n");
	printf("|  O       0  0       O        0       0     O  O O 0 O  O                |\n");
	printf("|  O   0   0  OOO0O0  O        O       O     O  O  O  O  OOOO00           |\n");
	printf("|  O  0 0  O  0       O        O       O     O  0     O  O                |\n");
	printf("|  OO0   000  O00000  OOOOOOO  OOOOOO  0OOOOOO  O     O  OOOOOO           |\n");
	printf("|                                                                         |\n");                       
	printf(" -------------------------------------------------------------------------\n");
      
     
   printf("\n                       :::::::::::::::::::::::::::::::::::::::");
   printf("\n                       ::                                   ::");
   printf("\n                       ::     ***********************       ::");
   printf("\n                       ::     *                     *       ::");
   printf("\n                       ::     -      WELCOME TO     -       ::");
   printf("\n                       ::     *       DS HOTEL      *       ::");
   printf("\n                       ::     -                     -       ::");
   printf("\n                       ::     ***********************       ::");
   printf("\n                       ::                                   ::");
   printf("\n                       :::::::::::::::::::::::::::::::::::::\n\n");
  
   
  printf("\n      Kind heartedly we welcome u all,We make u feel luxurious \n");
    
}

void intro() {
   printf("                               AMINITIES\n");
   printf("\t\t\t1. non stop Power Supply.\n");
   printf("\t\t\t2. lift Service available\n");
   printf("\t\t\t3. Huge parking space.\n");
   printf("\t\t\t4. Laundary service.\n");
   printf("\t\t\t5. Both hot and cold water.\n");
   printf("\t\t\t6. Free internet service.\n");
   printf("\t\t\t7. 24 hours room service.\n");
   printf("\nPress any character to continue:\n");
   
  
}


void login() {
    char uname[20];
    char pass[10];

    printf("\n  **************************  LOGIN FORM  **************************  ");
    printf(" \n                       ENTER USERNAME:-");
    scanf("%s", uname); 
    printf(" \n                       ENTER PASSWORD:-");
    scanf("%s", pass);
    printf("    ********************YOUR LOGIN IS SUCCESSFUL*******************  ");
}

void signup() {
    struct CustomerDetails s;
    printf("\n  Enter Customer Details: ");
    printf("\n**************************\n");

    printf("Enter Name:\n");
    scanf("%s", s.name);
    printf("Enter Address:\n");
    scanf("%s", s.address);

    printf("Enter Phone Number:\n");
    scanf("%ld", &s.phonenumber);
    printf("Enter Nationality:\n");
    scanf("%s", s.nationality);
    printf("Enter Aadhar Card Number for Id proof:\n");
    scanf("%ld", &s.idproof);
    printf("Enter Email:\n");
    scanf(" %s", s.email);
    printf("Enter Period( no of days):\n");
    scanf("%s", s.period);
    printf("Enter Arrival date(dd\\mm\\yyyy):\n");
    scanf("%s", s.arrivaldate);

}

typedef enum {
    false,
    true
} bool;

void initializeRooms(bool rooms[], int numRooms) {
    rooms[1] = rooms[4] = rooms[7] = false;
    for (int i = 0; i < numRooms; i++) {
        if (i != 1 && i != 4 && i != 7) {
            rooms[i] = true; 
        }
    }
}

void displayAvailableRooms(bool rooms[], int numRooms) {
    printf("Available Rooms:\n");
    for (int i = 0; i < numRooms; i++) {
        if (rooms[i]) {
            printf("Room %d ", i + 1);
        }
    }
}

void bookRoom(bool rooms[], int roomNumber) {
    if (rooms[roomNumber - 1]) {
        rooms[roomNumber - 1] = false;
        printf("Room %d has been booked.\n", roomNumber);
    } else {
        printf("Room %d is already occupied.\n", roomNumber);
    }
}


void displayMenu() {
    int i;
    int foodCodes[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}; 
    char foodNames[][30] = {"Burger", "Pizza", "Pasta", "Salad", "Sandwich", "Chapati", "Chicken Briyani", "Mutton Briyani", "Prawn Briyani", "Momos", "Idli", "Dosa", "Naan", "Panner Butter Masala", "Meals"};
    int foodPrices[] = {150, 200, 180, 120, 100, 30, 120, 160, 250, 50, 25, 40, 50, 150, 150}; 
    printf("============================================\n");
    printf("                 MENU CARD\n");
    printf("============================================\n");
    printf("%-5s%-20s%-10s\n", "Code", "Food Item", "Price");
    printf("============================================\n");

    for (i = 0; i < sizeof(foodCodes) / sizeof(foodCodes[0]); i++) {
        printf("%-5d%-20s%-10d\n", foodCodes[i], foodNames[i], foodPrices[i]);
    }

    printf("============================================\n");
}

void orderFood(int foodCodes[], char foodNames[][30], int foodPrices[]) {
    int foodCode, quantity;
    int totalCost = 0;
    char choice;

    do {
        displayMenu(foodCodes, foodNames, foodPrices);

        printf("Enter the food code you want to order: ");
        scanf("%d", &foodCode);
        if (foodCode < 1 || foodCode > 15) {
            printf("Invalid food code. Please enter a valid code.\n");
            continue;
        }

        printf("Enter the quantity: ");
        scanf("%d", &quantity);
        printf("Item: %-20s | Quantity: %-5d | Cost: %-5d\n", foodNames[foodCode - 1], quantity, foodPrices[foodCode - 1] * quantity);

        totalCost += foodPrices[foodCode - 1] * quantity;
        

        printf("Do you want to order more items? (Y/N): ");
        scanf(" %c", &choice);

    } while (choice == 'Y' || choice == 'y');

    printf("\nTotal Cost: %d\n", totalCost);
}
int generateOTP() {
    srand(time(NULL)); 
    return rand() % (999999 - 100000 + 1) + 100000;
}

int main() {
    struct CustomerDetails s;
    frontpage();
    intro();
    printf("\t\t\t1.signup \t\t\t\n");
    printf("\t\t\t2.Login \t\t\t\n");
    printf("\t\t\t3.exit \t\t\t\n");
    int User_opinion;
    scanf("%d",&User_opinion);

    switch(User_opinion){
        case 1:
           signup();
           break;
         case 2:
           login();
           break;
         default:
           exit(0);   
          
    }
    bool rooms[NUM_ROOMS];
    int roomPrices[NUM_ROOMS]; 
    int daysStayed;

    initializeRooms(rooms, NUM_ROOMS);

    for (int i = 0; i < NUM_ROOMS; i++) {
        roomPrices[i] = PRICE_PER_DAY * (i + 1); 
    }

    int numRoomsToBook;
    printf("\nHow many rooms do you want to book? ");
    scanf("%d", &numRoomsToBook);

    int roomsBooked[numRoomsToBook];
    int totalBill = 0;

    for (int i = 0; i < numRoomsToBook; i++) {
        printf("\nAvailable Rooms:\n");
        displayAvailableRooms(rooms, NUM_ROOMS);

        int roomChoice;
        printf("\nEnter the room number to book (%d of %d): ", i + 1, numRoomsToBook);
        scanf("%d", &roomChoice);

        if (roomChoice >= 1 && roomChoice <= NUM_ROOMS && rooms[roomChoice - 1]) {
            bookRoom(rooms, roomChoice);
            roomsBooked[i] = roomChoice;
            totalBill += roomPrices[roomChoice - 1]; 
        } else {
            printf("Invalid room number or room already booked. Please try again.\n");
            i--; 
        }
    }

    printf("\nYou have booked the following rooms:\n");
    for (int i = 0; i < numRoomsToBook; i++) {
        printf("Room %d - Price per day: $%d\n", roomsBooked[i], roomPrices[roomsBooked[i] - 1]);
    }

    printf("\nHow many days are you going to stay? ");
    scanf("%d", &daysStayed);

    int totalAmount = totalBill * daysStayed;
    printf("\nTotal Amount Due for %d days of stay: $%d\n", daysStayed, totalAmount);

    char extraBooking;
    printf("\nDo you want to book extra rooms? (y/n): ");
    scanf(" %c", &extraBooking);

    while (extraBooking == 'y' || extraBooking == 'Y') {


        printf("\nDo you want to book more extra rooms? (y/n): ");
        scanf(" %c", &extraBooking);
    }

    printf("\nThank you for using our booking service!\n");

    displayAvailableRooms(rooms, NUM_ROOMS);
    int foodCodes[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}; 
    char foodNames[][30] = {"Burger", "Pizza", "Pasta", "Salad", "Sandwich", "Chapati", "Chicken Briyani", "Mutton Briyani", "Prawn Briyani", "Momos", "Idli", "Dosa", "Naan", "Panner Butter Masala", "Meals"};
    int foodPrices[] = {150, 200, 180, 120, 100, 30, 120, 160, 250, 50, 25, 40, 50, 150, 150}; 
   
    char need_food;
    printf("\nDo u need food (Y/N): ");
    scanf(" %c", &need_food);

    switch (need_food) {
        case 'Y':
           orderFood(foodCodes, foodNames, foodPrices);
           printf("THANK YOU FOR DINING AT OUR RESTAURANT – YOUR PRESENCE IS THE HIGHLIGHT OF OUR DAY");
           break;
        case 'N':
           printf("THANK YOU FOR VISITING US, LET'S CHEER UP AGAIN SOON...");
           break;
        default:
           printf("Invalid choice. Please enter 'Y' or 'N'.");


    }

    int otp = generateOTP();
    printf("\n");
    printf("\nGenerated OTP: %06d\n", otp);


    return 0;
}





