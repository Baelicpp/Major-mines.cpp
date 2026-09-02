#include <iostream>
#include <string>
#include <cstdlib> // This gives me access to the rand() function which gernates random numbers and the srand() function which generates a seed for rand
#include <ctime> // This works with the local time on the pc so if its passed into srand then the seed constantly changes

int wallet = 0; //making sure wallet value starts at 0

struct item{ //stores diffrent data types under one name to be called to later
    std::string name;
    int cost;
};

struct stat{
    std::string StatName;
   int statvalue;
};

struct mine {
    std::string mining;
    int value;
};


int main(){

    srand(static_cast<unsigned int> (time(0))); //im converting time to an unsigned int becuase time(0) allows negitive numbers but srand doesnt and an unsigned int only allows postive numbers and zero. This prevents complier warnings

    item inventory [3] { //stores a single data type under one name and can be accessed under index
        {"Iron Sword",15},
        {"Wooden Shield",10},
        {"Bandage", 20}
    };

    stat Title [3] {
        {"Attack", 20},
        {"Defence", 15},
        {"Healing", 25}
    };

    mine ore [5] {
        {"Dirt", 1},
        {"Stone", 3},
        {"Coal", 5},
        {"Iron", 8},
        {"Gold", 10},
    };


int choice = 0; //starts value of the user choice on 0

while (true) { // this makes sure that the code executes aslong as the value stays true, if it turns false this ends

std::cout << "===============================\n";
std::cout << "=== BlackSmith (wallet: $" << wallet << ") ===\n"; //prints the wallet value of the user
std::cout << "===============================\n";

//this for loop is for the inventory



for (int i = 0; i < 3; i++) { //counts from 1 to 3
    std::cout << (i + 1) << ". " << inventory[i].name  // evertime the loop repeats it adds 1 to the i in the loop, then prints the item name
    << "(cost $:" << inventory[i].cost << ")\n"; //prints cost and then the item cost
}

std::cout << "4. Mining: ";

std::cin >> choice; //cin is for character input and choice is the variable being called upon


// new for loop for the mines
if (choice == 4) {  // double == is for comparing and one = is for assiging
int minechoice = 0; // making a new choice of the mines to allow a choice in the mining section


    while (minechoice != 2) { // this mean the code will run aslong as the minechoice is not equal to 2
    std::cout << "=== The Mines ===\n";
    std::cout << "1. Start mining""\n";
    std::cout << "2. exit""\n";
    std::cin >> minechoice; // this is then asking for the users choice to either leave or go mining

if (minechoice == 1) { // if the user choice is equal to 1 then print
    std::cout << "Enjoy the mines!""\n";

// this is where the mining will go

for (int i = 0; i < 5; i++) {
    wallet += ore[i].value; // This adds the ore value from the array that stores the name and the value

    std::cout << ". " << "you mined " << ore[i].mining << " Total Wallet: $ " << wallet << "\n"; // this prints the ore which is the array and the mining which is the struct and then it prints the wallet total

} // this closes the for loop

}

else if (minechoice == 2){ // if the user choice is 2 then print
    std::cout << "Thanks for visting""\n";
}
    }
}

else{
    int index = choice - 1; //this makes sure that the number the user selected alligns with what they get
if (index >= 0 && index <3){ //this makes sure that they are both true, if one is false then they both are
if (wallet >= inventory[index].cost) { //if the wallet amount is greater then the item cost
    wallet -= inventory[index].cost; // then minus the amount from the wallet
    std::cout << "you have bought: " << inventory[index].name << "\n"; // print you have bought then the item name
    std::cout << "Funds left: $" << wallet << "\n"; // print the amount left after the transaction
}
else { //if the user doesnt have enough money then print the item name and then cost of the item, then the amount of money the user has
    std::cout << "You cant afford this item you need $" << inventory[index].cost << "and you have: $" << wallet;
}

std::cout << "\n=== ACTION LOG ===\n";
std::cout << "You selected: " << inventory[index].name  //show the user what they selected
<< " with " << Title[index].statvalue << Title[index].StatName; //print the number of how strong the item is and then the name of the ablity

}
else {
    std::cout << "invalid number"; //if the user picks a number other then 1-4 print
}
}


}
}