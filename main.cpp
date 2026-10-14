#include <iostream>
#include <string>
#include <cstdlib> // This gives me access to the rand() function which gernates random numbers and the srand() function which generates a seed for rand
#include <ctime> // This works with the local time on the pc so if its passed into srand then the seed constantly changes


int wallet = 0; //making sure wallet value starts at 0
int health = 100;
int stamina = 100;
int goblinRoll = 0;



struct goblin
{
    std::string type;
    int option;
};

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


void mineOre(int& wallet, int& stamina); //return nothing but get the memory address of the wallet and stamina
bool handleGoblin(int& stamina, int& health, int&, bool& feldToShop);
int main(){



    srand(static_cast<unsigned int> (time(0))); //im converting time to an unsigned int becuase time(0) allows negitive numbers but srand doesnt and an unsigned int only allows postive numbers and zero. This prevents complier warnings

    goblin options [3] {
        {"Attack", 20},
        {"Defend", 15},
        {"Heal", 25}
    };

    item inventory [4] { //stores a single data type under one name and can be accessed under index
        {"Iron Sword",15},
        {"Wooden Shield",10},
        {"Bandage", 20},
        {"Steak", 15}
    };

    stat Title [4] {
        {"Attack", 20},
        {"Defence", 15},
        {"Healing", 25},
        {"Stamina", 50}
    }; // i can re use this for the attacking phase



int choice = 0; //starts value of the user choice on 0

while (true) { // this makes sure that the code executes aslong as the value stays true, if it turns false this ends

std::cout << "\n===============================\n";
std::cout << "=== BlackSmith (wallet: $" << wallet << ") ===\n"; //prints the wallet value of the user
std::cout << "===============================\n";

//this for loop is for the inventory



for (int i = 0; i < 4; i++) { //counts from 1 to 3
    std::cout << (i + 1) << ". " << inventory[i].name  // evertime the loop repeats it adds 1 to the i in the loop, then prints the item name
    << "(cost $:" << inventory[i].cost << ")\n"; //prints cost and then the item cost
}

std::cout << "5. Mining: ";

std::cin >> choice; //cin is for character input and choice is the variable being called upon


// new for loop for the mines
if (choice == 5) {  // double == is for comparing and one = is for assiging
int minechoice = 0; // making a new choice of the mines to allow a choice in the mining section


    while (minechoice != 2) { // this mean the code will run aslong as the minechoice is not equal to 2
    std::cout << "=== The Mines ===\n";
    std::cout << "1. Start mining""\n";
    std::cout << "2. exit""\n";
    std::cin >> minechoice; // this is then asking for the users choice to either leave or go mining

// this is where the combat starts

if (minechoice == 1) { // if the user choice is equal to 1 then print

    mineOre(wallet, stamina); 

    int goblinRoll = rand() % 10;

    if (goblinRoll == 0) {
    int goblinHealth = 100;
    int goblinChoice = 0;
    

    while (goblinHealth > 0) {
    std::cout << "You have encountered a goblin\n";
    std::cout << "1. Fight""\n";
    std::cout << "2. Flee (cost 25 stamina)""\n";
    std::cin >> goblinChoice;

    if (goblinChoice == 1) { // if the user choice is to fight then print the options

    std::cout << "\n" << "=== Player health: " << health << "===" << "\n";
    std::cout << "\n" << "Goblin Health: " << goblinHealth << "\n\n";
    
    goblin options[3] {
    {"Attack", 20},
    {"Defend", 15},
    {"Heal", 25}
};
for (int i = 0; i < 3; i++) {
std::cout << (i + 1) << ". " << options[i].type << "\n";
}


int attackChoice = 0;
std::cin >> attackChoice;


if (attackChoice == 1) {
    std::cout << "You choice too attack ";
    goblinHealth -= 20;
}

else if (attackChoice == 2) {
        std::cout << "You defended against that attack";
        stamina -= 15;
    }
}
else if (goblinChoice == 2) {
    std::cout << "You got scared and fled back to the shop\n";
    stamina -=25;
    break;
    }
}
    

if (minechoice == 2) { // if the user choice is 2 then print
    std::cout << "Thanks for visting""\n";
                }
            }
        }
    }
}



else{
    int index = choice - 1; //this makes sure that the number the user selected alligns with what they get
if (index >= 0 && index <4){ //this makes sure that they are both true, if one is false then they both are
if (wallet >= inventory[index].cost) { //if the wallet amount is greater then the item cost
    wallet -= inventory[index].cost; // then minus the amount from the wallet
    std::cout << "you have bought: " << inventory[index].name << "\n"; // print you have bought then the item name
    std::cout << "Funds left: $" << wallet << "\n"; // print the amount left after the transaction
    if (choice == 4) {stamina += 50;} // adds 50 stamina to the player when they buy a steak

}
else { //if the user doesnt have enough money then print the item name and then cost of the item, then the amount of money the user has
    std::cout << "You cant afford this item you need $" << inventory[index].cost << " \nand you have: $" << wallet;
}

std::cout << "\n=== ACTION LOG ===\n";
std::cout << "You selected: " << inventory[index].name  //show the user what they selected
<< " with " << Title[index].statvalue <<" " << Title[index].StatName; //print the number of how strong the item is and then the name of the ablity



}
else {
    std::cout << "invalid number"; //if the user picks a number other then 1-4 print
}
}
if (choice == 4) {
   
}

}
return 0;


//mining function outside of main

}


void mineOre(int& wallet, int& stamina) {
    int staminaCost = 10;

    if (stamina < staminaCost) {
        std::cout << "\nYou are too exhausted to keep mining! Buy food at the shop to increase stamina.\n";
        return;
    }

stamina -= staminaCost; //minus the amout off the cost which is 10



    mine ore[5] {
        {"Dirt", 1},
        {"Stone", 3},
        {"Coal", 5},
        {"Iron", 8},
        {"Gold", 10},
    };
    

    int randomIndex = rand() % 5; //randomIdex = genarate a random number. % 5 means it only has 5 numbers to pick from which is 0-4
    wallet += ore[randomIndex].value; //wallet plus the value of the random ore that was given

    std::cout << "You swung your pickaxe and found: "
    << ore[randomIndex].mining << "($: " << ore[randomIndex].value << ")" << "\n"; // this prints the name of the ore and the value based on the number genareted
    std::cout << "Stamina left: " << stamina <<  " | Total wallet: $" << wallet << "\n";
} 



// if the player dies they get full reset like hardcore
// give the player the option to use the items they have bought like press 1. to attack with iron sword 2. block with wooden shield 3. heal with bandage
// player needs health
// make is so the user can flee but it cost 25 stamina




// make it so flee does something and returns the user back to the shop

// if you attack and then press 2 it then breaks and takes you back to the mines but if you try and flee normally it will just loop