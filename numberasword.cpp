#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <sstream>
using namespace std;

string returnword(string num);

string returnworddigit(int digit, int place, int length, int birler, bool onlarenter);

string secondplace(int digit, int birler);

string secondplaceten(int digit);

string firstplace(int digit);

int main(){

int bottles;
cout << "How many bottles do we have on the wall? ";
cin >> bottles;

string bottlesstr = to_string(bottles);

cout << endl << returnword(bottlesstr) << endl;

return 0;
}

string returnword(string num){ 
	int length = 0;
	for (;num[length];length++); 
	string word = "";
	string digit;
	string birler = string(1, num[length-1]);
	string onlar = string(1, num[length - 2]);
	int birlerint; 
	stringstream container2(birler);
	container2 >> birlerint;
	int onlarint;
	stringstream container3(onlar);
	container3 >> onlarint;
	bool onlarenter;
	
	if (onlarint != 1)
		onlarenter = true;
	else
		onlarenter = false;
	
	for(int i = 0; i < length; i++){
		int k = i;
		string out = "";
		digit = string(1, num[i]);
		int intdigit;
		stringstream container(digit);
		container >> intdigit;
		word += (returnworddigit(intdigit, k, length, birlerint, onlarenter));
		word += " ";
			
		}
		return word;
		
	}

string returnworddigit(int digit, int place, int length, int birler, bool onlarenter){ 
	string word, pre;
		if (place == (length - 1)){ 
		if (onlarenter){
		word = firstplace(digit);
		}
		}
		else {
		if (place == (length - 2)){
			word = secondplace(digit, birler);
		}
		else {
		if (place == (length - 3)){
		pre = firstplace(digit);
		word = (pre) + "hundred";
		}
		else {
		
		if (place == (length - 4)){
			//cout << " F " << endl;
		pre = firstplace(digit);
		word = (pre) + "Thousand";
		//cout << pre << " Thousand";
		}
		}
		}
		}
	return word;
}

string secondplace(int digit, int birler){
	string word = "";
		if (digit == 1){ 
		word = secondplaceten(birler);
		}
		if (digit == 2){
		word = "Twenty";
		}
		if (digit == 3){
		word = "Thirty";
		}
		if (digit == 4){
		word = "Fourty";
		}
		if (digit == 5){
		word = "Fifty";
		}
		if (digit == 6){
		word = "Sixty";
		}
		if (digit == 7){
		word = "Seventy";
		}
		if (digit == 8){
		word = "Eighty";
		}
		if (digit == 9){
		word = "Ninety";
		}
	return word;
	
}

string secondplaceten(int digit){ // burada digit birler basamağı
	string word;
	switch (digit){
		case 0:
		word = "Ten";
		break;
		case 1:
		word = "Eleven";
		break;
		case 2:
		word = "Twelve";
		break;
		case 3:
		word = "Thirteen";
		break;
		case 4:
		word = "Fourteen";
		break;
		case 5:
		word = "Fifteen";
		break;
		case 6:
		word = "Sixteen";
		break;
		case 7:
		word = "Seventeen";
		break;
		case 8:
		word = "Eighteen";
		break;
		case 9:
		word = "Nineteen";
		break;
	}
	return (word + " ");
	
}

string firstplace(int digit){
	string word = "";
	switch (digit){
		case 1:
		word = "One";
		break;
		case 2:
		word = "Two";
		break;
		case 3:
		word = "Three";
		break;
		case 4:
		word = "Four";
		break;
		case 5:
		word = "Five";
		break;
		case 6:
		word = "Six";
		break;
		case 7:
		word = "Seven";
		break;
		case 8:
		word = "Eight";
		break;
		case 9:
		word = "Nine";
		break;
		case 0:
		break;
		
	}
	return (word + " ");
}