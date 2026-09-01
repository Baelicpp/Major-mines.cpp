// make it so money isnt hardcoded and you start at $0
// add a way to get money


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

std::cout << "=== BlackSmith ===\n";

//this for loop is for the inventory



for (int i = 0; i < 3; i++) {
    std::cout << (i + 1) << ". " << inventory[i].name //this is printing the number of the item and the name of it
    << "(Cost: $" << inventory[i].cost << ")\n"; //this prints the cost of the item
}

std::cout << "4. Mining: ";

std::cin >> choice;


// new for loop for the mines
if (choice == 4) {
    std::cout << "=== The Mines ===\n";
    std::cout << "1. Start mining""\n";
    std::cout << "2. exit""\n";
    std::cin >> choice;

if (choice = 2) {
    return 0;
}
    for (int i = 0; i < 5; i++) {
        
    }
}

else {
    int index = choice - 1; //this makes sure that the number the user selected alligns with what they get



if (index >= 0 && index <3){
if (wallet >= inventory[index].cost) { // if the wallet has more or equal to the amount 
    wallet -= inventory[index].cost; // then minus that amount from the wallet
    std::cout << "you bought " << inventory[index].name << "\n"; // if the user has enough money it will say "you bought" then the item name
    std::cout << "funds left: $" << wallet << "\n"; // print the amount left in the wallet after the transaction
}
else {
    std::cout << "You cant afford this item. You need $" << inventory[index].cost << " but you only have: $" << wallet << ".\n"; // if the wallet has less then the amount then print "you cant afford this"
    
}



std::cout << "\n=== ACTION LOG ===\n";
std::cout << "You selected: " << inventory[index].name //we use index here becuase that is the players choice -1 we dont use [i] becuase thats the for loop number
<< " with " << Title[index].statvalue << Title[index].StatName;  //Name of item -->  players choice --> Stat --> name of stat
}
else {
    std::cout << "invalid number";
}
}
return 0;

}