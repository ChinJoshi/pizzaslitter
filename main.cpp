#include <iostream>
#include <string>

class wut{
    public:
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

};





int main() {
    wut foo;
	std::cout << "How many slices does each pizza have?" << std::endl;	//assigns value to slices per pizza
	std::cin >> foo.slicesperpizza;
	std::cout << "How many people do you have?" << std::endl;	//assigns value to people
	std::cin >> foo.numberofpeople;
	foo.numberofpeople--;
	foo.slicepparr = new int[foo.numberofpeople];
	std::cout << "What is the cost per pizza?" << std::endl;		//assigns value to cost per pizza
	std::cin >> foo.costperpizza;
	std::cout << "What type of slice split do you want to do?" << std::endl<<"Equal or Manual?"<<std::endl;		//asks user what type of split it wants to do
	std::cin >> foo.typeofsplit;
	if (foo.typeofsplit == "Equal") {	//if statement that calculates the total bill and split bill by asking for slices per person if the user chooses to go for an equal slice split
		std::cout << "How many slices per person?" << std::endl;
		std::cin >> foo.slicesperperson;
		foo.numberofpizzas = (foo.numberofpeople*foo.slicesperperson) / foo.slicesperpizza;
		foo.totalbill = foo.numberofpizzas*foo.costperpizza;
		foo.splitbill = foo.totalbill / foo.numberofpeople;
		std::cout << "The number of pizzas you will need is " << foo.numberofpizzas << std::endl;
		std::cout << "The total bill will be $" << foo.totalbill << std::endl;
		std::cout << "The bill per person will be $" <<foo.splitbill <<std::endl;
	};
	if (foo.typeofsplit == "Manual") {
		for (int y=0;y<=foo.numberofpeople ;y++ ) {
			std::cout << "Enter the number of slices that person "<<(y+1)<<" wants" << std::endl;
			std::cin >> foo.slicepparr[y];
			foo.totslices += foo.slicepparr[y];
		};
		foo.numberofpizzas =static_cast<float>(foo.totslices / foo.slicesperpizza);
		std::cout << "The total number of slices are " << foo.totslices << std::endl;
		std::cout << "The number of pizzas you will need to order is " << foo.numberofpizzas << std::endl;
		foo.totalbill = foo.numberofpizzas*foo.costperpizza;
		std::cout << "The total bill will be $" << foo.totalbill<<std::endl;
		for (int y = 0; y <= foo.numberofpeople; y++) {
			foo.sliceshare = static_cast<float>(foo.slicepparr[y])/static_cast<float>(foo.totslices);
			foo.splitbill = foo.sliceshare*foo.totalbill;
			std::cout << "The amount that person "<<(y+1)<<" has to pay is $" <<foo.splitbill<<std::endl;
		};

	};

	return 0;

}
