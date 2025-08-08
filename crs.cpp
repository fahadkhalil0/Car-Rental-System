#include <iostream>
#include <fstream>
#include <string>
#include <iomanip> //these all are libraries that included in this mini program.
using namespace std;

//Animated Menu Funtions (ASCII-ART).
void clearScreen();
void setMagentaColor();
void resetColor();

// Here I am defining the class with named as Car to input all the details
class Car
{
public:
    string brand;
    string model;
    int year;
    float rentperDay;
    bool isRented;

    void display()
    {
        cout << "\nBrand: " << brand;
        cout << "\nModel: " << model;
        cout << "\nYear: " << year;
        cout << "\nRent/Day: Rs. " << rentperDay;
        // cout << "\nStatus: " << (isRented ? "Available" : "Rented") << endl;
        //condition
        if (isRented == 1){
            cout << " \nStatus: Rented " <<endl;
        } else if (isRented == 0){
            cout <<" \nStatus: Car is Available " <<endl;
        } else {
            cout << " \nStatus: No car available right now "  <<endl;
        }
    }
};

// second class for rental system
class RentalSystem
{
public:
    Car cars[100];
    int count = 0;

    void Banner();
    void addCar();
    void viewCars();
    void rentCar();
    void returnCar();
    void savetoFile();
    void loadfromFile();
} rs;

int main()
{
    system("cls");
    rs.loadfromFile();

    char repeat; // character variable..
    // loop for iteration.
    do
    {
        rs.Banner();
        cout << " Perform The Operation :: " << endl;
        cout << "\n 1--> Add The Car :: ";
        cout << "\n 2-->  View All Cars :: ";
        cout << "\n 3--> Rent A Car :: ";
        cout << "\n 4--> Return A Car :: ";
        cout << "\n 0--> Exit The Program :: ";

        // Enter the choice::
        int choice;
        cin >> choice;

        // Selectional Strucutre
        // Control Statement.

        switch (choice)
        {
        case 1:
            rs.addCar();
            break;
        case 2:
            rs.viewCars();
            break;
        case 3:
            rs.rentCar();
            break;
        case 4:
            rs.returnCar();
            break;
        case 0:
            cout << " Exiting from this program... " << endl;
            break;
        default:
            cout << "Invalid Choice, Please Try Again With A Valid Choice " << endl;
            break;
        }
        // asking the user for more !!!.
        cout << " Do you want to perform any other operation (y/n) ? " << endl;
        cin >> repeat;

    } while (repeat == 'y' || repeat == 'Y'); // do while loop is used, it means it will run one time but second time it runs the condition.

    rs.savetoFile();
    cout << "\nThank you for using the Car Rental System. Goodbye!\n";
    return 0;
}

// function defination outside the main function

void RentalSystem ::Banner()
{
     clearScreen(); // Clear the screen before showing menu

    setMagentaColor();
    cout << R"(
_________                __________               __         .__      _________               __                  
\_   ___ \_____ _______  \______   \ ____   _____/  |______  |  |    /   _____/__.__. _______/  |_  ____   _____  
/    \  \/\__  \\_  __ \  |       _// __ \ /    \   __\__  \ |  |    \_____  <   |  |/  ___/\   __\/ __ \ /     \ 
\     \____/ __ \|  | \/  |    |   \  ___/|   |  \  |  / __ \|  |__  /        \___  |\___ \  |  | \  ___/|  Y Y  \
 \______  (____  /__|     |____|_  /\___  >___|  /__| (____  /____/ /_______  / ____/____  > |__|  \___  >__|_|  /
        \/     \/                \/     \/     \/          \/               \/\/         \/            \/      \
                                                                    
                                                                    
)" << endl;
    resetColor();

    cout << "Welcome to the Car Rental System!\n";
    cout << "----------------------------------\n";
}

void RentalSystem ::addCar()
{
    system("cls");
    rs.Banner();

    cout << " COUNTS? :: " << endl;
    cin >> count;

    for (int i = 0; i < count; i++)
    {
        cout << " Enter the detail of Car :: " << i + 1 << endl; // index no

        cout << " BRAND :: " << endl;
        cin >> cars[i].brand;
        cout << " MODEL :: " << endl;
        cin >> cars[i].model;
        cout << " YEAR :: " << endl;
        cin >> cars[i].year;
        cout << " RENT PER DAY " << endl;
        cin >> cars[i].rentperDay;
        cout << " IS RENTED ?" << endl;
        cin >> cars[i].isRented;

        // cars[i].isRented = false;
    }

    cout << "\n"
         << count << " car(s) successfully added!\n";
}

void RentalSystem::viewCars() // viewAll cars function
{
    system("cls");
    rs.Banner();
    if (count == 0)
    {
        cout << "No Car is available for now .. " << endl;
    }

    for (int i = 0; i < count; i++)
    {
        cout << "Car ID :: " << i + 1 << endl;
        cars[i].display();
    }
}

void RentalSystem ::rentCar()
{
    system("cls");
    rs.Banner();

    int id;
    cout << "Enter the car ID to rent :: ";
    cin >> id;

    int index = id - 1;
    if (cars[index].isRented)
    {
        cout << "Sorry this car is on rent already... " << endl;
    }
    else
    {
        cars[index].isRented = true;
        cout << " Car has been successfully rented.... " << endl;
    }
}

void RentalSystem ::returnCar()
{
    system("cls");
    rs.Banner();
    int id;
    cout << "Enter the ID :: " << endl;
    cin >> id;

    int index = id - 1;

    if (index < 0 || index >= count)
    {
        cout << "Invalid Car ID.\n";
        return;
    }

    if (cars[index].isRented)
    {
        cars[index].isRented = false;
        cout << " Car has been return successfully \n";
    }
    else
    {
        // cars[index].isRented = true;
        cout << " The car is not returned.. " << endl;
    }
}

// function of  savetofile
void RentalSystem ::savetoFile()
{
    ofstream file("car.txt", ios ::in | ios ::app);

    if (!file)
    {
        cout << "Failed Operation, file is not opened." << endl;
    }

    for (int i = 0; i < count; ++i)
    {
        file << cars[i].brand << ",";
        file << cars[i].model << ",";
        file << cars[i].year << ",";
        file << cars[i].rentperDay << ",";
        file << cars[i].isRented <<endl;
    }
    file.close();
}


//function load from the file

// void RentalSystem::loadfromFile()
// {
//     ifstream file("car.txt", ios ::out);

//     if (!file)
//     {
//         cout << "No car data found.\n";
//         return;
//     }

//     count = 0;
//     while (file >> cars[count].brand)
//     {
//         // file.ignore();

//         getline(file, cars[count].model, ',');
//         file >> cars[count].year;
//         // file.ignore();

//         file >> cars[count].isRented;
//         // file.ignore();

//         file >> cars[count].rentperDay;
//         // file.ignore();

//         count++;
//     }

//     file.close();
// }


//gpt built function using 
void RentalSystem:: loadfromFile() {

    ifstream file("car.txt", ios :: in);

    if (!file.is_open()) {
        cout << "No saved car data found.\n";
        return;
    }

    count = 0;

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string brand, model, yearStr, rentStr, rentedStr;

        getline(ss, brand, ',');
        getline(ss, model, ',');
        getline(ss, yearStr, ',');
        getline(ss, rentStr, ',');
        getline(ss, rentedStr); 


        // If any field is missing, skip this line
        if (brand.empty() || model.empty() || yearStr.empty() || rentStr.empty() || rentedStr.empty()) {
            continue;
        }

        cars[count].brand = brand;
        cars[count].model = model;
        cars[count].year = stoi(yearStr);           // string → int
        cars[count].rentperDay = stof(rentStr);     // string → float
        cars[count].isRented = (rentedStr == "1"); // store 1 for rented, 0 for not

        count++;
    }
    file.close();
}

void clearScreen() {
    system("cls");
}

void setMagentaColor() {
    // Windows-specific ANSI escape codes

    cout << "\033[35m"; // Set text color to magenta
}

void resetColor() {
    cout << "\033[0m"; // Reset color to default
}
