#include <iostream>
#include <string>
int main() {
	float numberofpizzas;	//number of total pizzas
	int slicesperpizza;		//slices per each pizza
	int numberofpeople;		//total number of people
	float costperpizza;		//cost per each pizza
	float splitbill = 0;		//the cost that each person would have to pay
	float totalbill;		//the total money that the transaction will cost
	float slicesperperson;		//the number of slices that each person wants in a equal split situation
	std::string typeofsplit;		//the type of split decider
	int totslices=0;		//total number of slices
	int *slicepparr;
	float sliceshare;
	std::cout << "How many slices does each pizza have?" << std::endl;	//assigns value to slices per pizza
	std::cin >> slicesperpizza;
	std::cout << "How many people do you have?" << std::endl;	//assigns value to people
	std::cin >> numberofpeople;
	numberofpeople--;
	slicepparr = new int[numberofpeople];
	std::cout << "What is the cost per pizza?" << std::endl;		//assigns value to cost per pizza
	std::cin >> costperpizza;
	std::cout << "What type of slice split do you want to do?" << std::endl<<"Equal or Manual?"<<std::endl;		//asks user what type of split it wants to do
	std::cin >> typeofsplit;
	if (typeofsplit == "Equal") {	//if statement that calculates the total bill and split bill by asking for slices per person if the user chooses to go for an equal slice split
		std::cout << "How many slices per person?" << std::endl;
		std::cin >> slicesperperson;
		numberofpizzas = (numberofpeople*slicesperperson) / slicesperpizza;
		totalbill = numberofpizzas*costperpizza;
		splitbill = totalbill / numberofpeople;
		std::cout << "The number of pizzas you will need is " << numberofpizzas << std::endl;
		std::cout << "The total bill will be $" << totalbill << std::endl;
		std::cout << "The bill per person will be $" <<splitbill <<std::endl;
	};
	if (typeofsplit == "Manual") {
		for (int y=0;y<=numberofpeople ;y++ ) {
			std::cout << "Enter the number of slices that person "<<(y+1)<<" wants" << std::endl;
			std::cin >> slicepparr[y];
			totslices += slicepparr[y];
		};
		numberofpizzas =static_cast<float>(totslices / slicesperpizza);
		std::cout << "The total number of slices are " << totslices << std::endl;
		std::cout << "The number of pizzas you will need to order is " << numberofpizzas << std::endl;
		totalbill = numberofpizzas*costperpizza;
		std::cout << "The total bill will be $" << totalbill<<std::endl;
		for (int y = 0; y <= numberofpeople; y++) {
			sliceshare = static_cast<float>(slicepparr[y])/static_cast<float>(totslices);
			splitbill = sliceshare*totalbill;
			std::cout << "The amount that person "<<(y+1)<<" has to pay is $" <<splitbill<<std::endl;
		};

	};

	return 0;

}

