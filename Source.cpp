#include <iostream>
#include <cctype>
using namespace std;

//prototypes
int getArraySize(const char userInput[]);
void getInput(char userInput[]);
bool validateUserInput(const char userInput[], int arrSize);
bool validateCardNum(const char userInput[]);
int mathOperations(const char userInput[]);
long long evenMathOperations(const char userInput[],int arr[]);
int oddMathOperations(const char userInput[], int arr[]);
void displayResult(bool cardIsValid);


int main()
{
	bool cardIsValid = false;
	char userInput[18] = { 0 };
	getInput(userInput);
	cardIsValid = validateCardNum(userInput);
	displayResult(cardIsValid);

	return 0;
}


void getInput(char userInput[])
{
	cout << "Please input your card number: " << endl;
	cin.getline(userInput, 18);
	int size = getArraySize(userInput);
	bool isValid = validateUserInput(userInput, size);

	while (!isValid)
	{
		cout << "Error: Input is invalid- Please re-enter: " << endl;
		cin.getline(userInput, 18);
		int size = getArraySize(userInput);
		isValid = validateUserInput(userInput, size);
		if (isValid)
		{
			break;
		}
	}
	
	return;
}


int getArraySize(const char userInput[])
{
	int size = 0;
	for (int i = 0; userInput[i] != 0; i++)
	{
		size++;
	}

	return size;
}


bool validateUserInput(const char userInput[], int arrSize)
{
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //I got this line from googling
		return false;
	}

	if (arrSize < 13)
	{
		return false;
	}

	if (userInput[0] != '4' && userInput[0] != '5' && userInput[0] != '6' && userInput[0] != '3')  {
		return false;

	}

	if (userInput[0] == '3')
	{
		if (userInput[1] != '7') {
			return false;
		}
	}

	
	for (int i = 0; i < arrSize; i++)
	{
		if (!isdigit(userInput[i])) 
		{
			return false;
		}
	}



	return true;
}


bool validateCardNum(const char userInput[])
{
	//int size = getArraySize(userInput);
	int sum = mathOperations(userInput);

	if (sum % 10 == 0)
	{
		return true;

	}
	else
	{

		return false;

	}

}


int mathOperations(const char userInput[])
{
	
	int arr[16] = { 0 };
	int sum = 0;

	sum += evenMathOperations(userInput, arr);
	sum += oddMathOperations(userInput,  arr);
	
	return sum;
}


long long evenMathOperations(const char userInput[], int arr[])
{
	int size = getArraySize(userInput);

	int sum = 0;
	for (int i = 0; i < size; i += 2)
	{

		arr[i] += (userInput[i] - '0') * 2;
		if (arr[i] > 9)
		{
			arr[i] = (arr[i] % 10) + (arr[i] / 10);
		}

	}

	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	return sum;
}


int oddMathOperations(const char userInput[], int arr[]) 
{
	int size = getArraySize(userInput);

	int sum = 0;
	for (int i = 1; i < size; i += 2)
	{

		arr[i] += (userInput[i] - '0');

	}

	for (int i = 1; i < size; i += 2)
	{
		sum += arr[i];
	}

	return sum;

}


void displayResult(bool cardIsValid)
{

	if (cardIsValid)
	{
		cout << "Your card number IS valid!" << endl;
	}
	if (!cardIsValid)
	{
		cout << "Your card number IS NOT valid!" << endl;
	}
	
	return;
}

