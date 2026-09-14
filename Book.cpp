#include <iostream>
#include <vector>
#include <fstream>
#include <string>


class Book{
    public:
    std::vector<std::string> rooms = {};    // insert from text file

    bool CheckAvailable(int Choice){
    return Choice > 0 && Choice <= 10;
}



void FileCreationOrOverride(int Choice, int decision){
        std::ifstream FileWrite("hotel.txt");    //read file "hotel.txt"
        std::string line;
        if(decision == 1){
        for(int i = 0; i < 10; i++){
            std::getline(FileWrite, line);
            rooms.push_back(line);
        if(i == Choice - 1  && rooms.at(i) == "available"){
            CheckRoom(Choice, decision);
            rooms.at(i) = "occupied";
        }
        else if( i == Choice - 1 && rooms.at(i) == "occupied"){
            CheckRoom(Choice, decision);
        }
    }
    }
    else if(decision == 2){
        for(int i = 0; i < 10; i++){
            std::getline(FileWrite, line);
            rooms.push_back(line);
        if(i == Choice - 1 && rooms.at(i) == "occupied"){
            CheckRoom(Choice, decision);    //override the choosen room by index
            rooms.at(i) = "available";
        }
        else if( i == Choice - 1 && rooms.at(i) == "available"){
            CheckRoom(Choice, decision);
        }
    }
    }
}
int FileCheck(){
    std::ifstream  File("hotel.txt");    //tries to read file
    if(!File.is_open()){
        std::ofstream FileCreate("hotel.txt");    //creates the text file if it fails to open through ifstream
        for(int m = 0;m < 10; m++){
            FileCreate << "available" << "\n";    //insert text contents via loops
        }
        return 1;
    }

    return 0;
}

void FileOverride(int Choice){
    Choice -= 1; 
    std::ofstream FileOverride("hotel.txt");    //using ofstream again to override text content inside the text file
    for(int i =0; i < 10;i++){
        FileOverride << rooms.at(i) << '\n';
    }
}

void CheckRoom(int choice, int decision){
    if(decision == 1){    
    if(rooms.at(choice - 1) == "occupied"){
        std::cout << "This room is not available" << "\n";
    }
    else
    {
        std::cout << "Room " << choice << " is available and is now yours" << "\n";
    }
    }
    else if(decision == 2){
        if(rooms.at(choice - 1) == "available"){
            std::cout << "This room is already available" << "\n";
        }
        else
        {
            std::cout << "Room " << choice << " is now available" << "\n";
        }
    }

}

};

int main(){
    int Bookdecision, NumberTyped;;
    std::cout << "Press 1 to book a room or 2 to unbook a room :\t";
    std::cin >> Bookdecision;  
    Book Customer1;
    std::cout << "Please enter a room number fromm 1 to 10 :\t";
    std::cin >> NumberTyped;
    if(!Customer1.CheckAvailable(NumberTyped)){
        return 0;
}
    Customer1.FileCheck();
    Customer1.FileCreationOrOverride(NumberTyped, Bookdecision); 
    Customer1.FileOverride(NumberTyped);
    return 0;
}
