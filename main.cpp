#include <iostream>
#include <string>

class Wut{
public:
    float numberOfPizzas;	//number of total pizzas
	int slicesPerPizza;		//slices per each pizza
	int numberOfPeople;		//total number of people
	float costPerPizza;		//cost per each pizza
	float splitBill = 0;		//the cost that each person would have to pay
	float totalBill;		//the total money that the transaction will cost
	float slicesPerPerson;		//the number of slices that each person wants in a equal split situation
	std::string typeOfSplit;		//the type of split decider
	int totSlices = 0;		//total number of slices
	int *slicepparr;
	float sliceShare;
    int loopNumber = 1;
    std::string loopChoice;
};

int main() {
    Wut foo;
    while (foo.loopNumber<2){
        std::cout<<"Enter 'calc' to enter the program and 'quit' to quit"<<std::endl;
        std::cin>>foo.loopChoice;
        if (foo.loopChoice == "calc"){
            std::cout << "How many slices does each pizza have?" << std::endl;	//assigns value to slices per pizza
            std::cin >> foo.slicesPerPizza;
            std::cout << "How many people do you have?" << std::endl;	//assigns value to people
            std::cin >> foo.numberOfPeople;
            foo.numberOfPeople--;
            foo.slicepparr = new int[foo.numberOfPeople];
            std::cout << "What is the cost per pizza?" << std::endl;		//assigns value to cost per pizza
            std::cin >> foo.costPerPizza;
            std::cout << "What type of slice split do you want to do?" << std::endl<<"Equal or Manual?"<<std::endl;		//asks user what type of split it wants to do
            std::cin >> foo.typeOfSplit;
            if (foo.typeOfSplit == "Equal") {	//if statement that calculates the total bill and split bill by asking for slices per person if the user chooses to go for an equal slice split
                std::cout << "How many slices per person?" << std::endl;
                std::cin >> foo.slicesPerPerson;
                foo.numberOfPizzas = (foo.numberOfPeople*foo.slicesPerPerson) / foo.slicesPerPizza; //mathy stuff
                foo.totalBill = foo.numberOfPizzas*foo.costPerPizza;    //mathy stuff
                foo.splitBill = foo.totalBill / foo.numberOfPeople; //more mathy stuff
                std::cout << "The number of pizzas you will need is " << foo.numberOfPizzas << std::endl;   //displays values
                std::cout << "The total bill will be $" << foo.totalBill << std::endl;
                std::cout << "The bill per person will be $" <<foo.splitBill <<std::endl;
            }else if (foo.typeOfSplit == "Manual") {
                for (int y=0;y<=foo.numberOfPeople ;y++ ) {
                    std::cout << "Enter the number of slices that person "<<(y+1)<<" wants" << std::endl;
                    std::cin >> foo.slicepparr[y];
                    foo.totSlices += foo.slicepparr[y];
                }
                foo.numberOfPizzas =static_cast<float>(foo.totSlices / foo.slicesPerPizza);
                std::cout << "The total number of slices are " << foo.totSlices << std::endl;
                std::cout << "The number of pizzas you will need to order is " << foo.numberOfPizzas << std::endl;
                foo.totalBill = foo.numberOfPizzas*foo.costPerPizza;
                std::cout << "The total bill will be $" << foo.totalBill<<std::endl;
                for (int y = 0; y <= foo.numberOfPeople; y++) {
                    foo.sliceShare = static_cast<float>(foo.slicepparr[y])/static_cast<float>(foo.totSlices);
                    foo.splitBill = foo.sliceShare*foo.totalBill;
                    std::cout << "The amount that person "<<(y+1)<<" has to pay is $" <<foo.splitBill<<std::endl;
                }
            }
        }else if (foo.loopChoice == "quit"){
            break;
        }
	}
	return 0;
}

