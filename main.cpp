
#include <iostream>
#include <string>

int wallet = 0;

struct item{
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
    item inventory [3] {
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


int choice = 0;

while (true) {

std::cout << "===============================\n";
std::cout << "=== BlackSmith (wallet: $" << wallet << ") ===\n";
std::cout << "===============================\n";

//this for loop is for the inventory



for (int i = 0; i < 3; i++) {
    std::cout << (i + 1) << ". " << inventory[i].name
    << "(cost $:" << inventory[i].cost << ")\n";
}

std::cout << "4. Mining: ";

std::cin >> choice;


// new for loop for the mines
if (choice == 4) {
int minechoice = 0;


    while (minechoice != 2) {
    std::cout << "=== The Mines ===\n";
    std::cout << "1. Start mining""\n";
    std::cout << "2. exit""\n";
    std::cin >> minechoice;

if (minechoice == 1) {
    std::cout << "Enjoy the mines!""\n";

// this is where the mining will go

for (int i = 0; i < 5; i++) {
    wallet += ore[i].value;

    std::cout << ". " << "you mined " << ore[i].mining << " Total Wallet: $ " << wallet << "\n";

}

}

else if (minechoice == 2){
    std::cout << "Thanks for visting""\n";
}
    }
}

else    {
    int index = choice - 1; //this makes sure that the number the user selected alligns with what they get



if (index >= 0 && index <3){
if (wallet >= inventory[index].cost) {
    wallet -= inventory[index].cost;
    std::cout << "you have bought: " << inventory[index].name << "\n";
    std::cout << "Funds left: $" << wallet << "\n";
}
else {
    std::cout << "You cant afford this item you need $" << inventory[index].cost << "and you have: $" << wallet;
}

std::cout << "\n=== ACTION LOG ===\n";
std::cout << "You selected: " << inventory[index].name 
<< " with " << Title[index].statvalue << Title[index].StatName;

}
else {
    std::cout << "invalid number";
}
}


}
}