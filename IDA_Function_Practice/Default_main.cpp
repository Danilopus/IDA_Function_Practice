#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>


int Get_Int();
int Get_Dbl();

int Random_Number_Int(int Range_min, int Range_max) 
{
	//srand(time(NULL));
	return Range_min + rand() % (Range_max - Range_min + 1); 
}

template <typename T> void Array_cout(T arr[], int const Size)
{
	for (int i = 0; i < Size; i++)
		std::cout << arr[i] << "\t";
	std::cout << "\n";
}

template <typename T> void Array_Fill_Random(T arr[], int const Size, int Range_min=100, int Range_max=999)
{
	srand(time(NULL));
	for (int i = 0; i < Size; i++)
		arr[i] = Random_Number_Int(Range_min, Range_max);
}

void Data_Type(int var){ std::cout << "\nINTEGER\n";	}
void Data_Type(double var) { std::cout << "\nDOUBLE\n"; }
void Data_Type(char var) { std::cout << "\nCHAR\n"; }
void Data_Type(float var) { std::cout << "\nFLOAT\n"; }

void Data_Type_demo()
{
	std::cout << "\nData type 7\n";
	Data_Type(7);
	std::cout << "\nData type 7.5\n";
	Data_Type(7.5);
	std::cout << "\nData type \'7\'\n";
	Data_Type('7');
	std::cout << "\nData type 7.0F\n";
	Data_Type(7.0F);
}

long long Summ_through_Recursion(int A, int B)
{
	if (A == B) return A;
	return Summ_through_Recursion(A,B-1) + B;
}
long long Summ_through_Recursion_inverted(int A, int B)
{
	if (A == B) return A;
	return Summ_through_Recursion(A+1, B) + A;
}

void Summ_through_Recursion_demo()
{
	std::cout << "\nEnter a start of Range\n";
	int Start_Summ = Get_Int();
	std::cout << "\nEnter a end of Range\n";
	int End_Summ = Get_Int();
	if (Start_Summ > End_Summ) std::swap(End_Summ, Start_Summ);
	std::cout << "\nSumm through Recursion -> " << Summ_through_Recursion(Start_Summ, End_Summ);
	std::cout << "\nSumm through Recursion inverted -> " << Summ_through_Recursion_inverted(Start_Summ, End_Summ);
}

//Task3
template <typename T> int Linear_Search(T arr[], int const Size)
{	
	for (int i = 0; i < Size; i++)
		if (arr[i] < 0) return i;
}
template <typename T> int Linear_Search_from_behind(T arr[], int const Size)
{
	for (int i = Size - 1; i >= 0; i--)
		if (arr[i] < 0) return i;
}
template <typename T> void Array_Bubble_Sort(T arr[], int const Size, int Start_position, int End_position)
{
	for (int i = End_position-1; i >= Start_position; i--)
		for (int j = Start_position; j<i; j++)
			if (arr[j] > arr[j+1]) std::swap(arr[j] , arr[j + 1]);
}
void Task3_demo()
{
	int const Array_Size = 20;
	int Test_Array[Array_Size];
	Array_Fill_Random(Test_Array, Array_Size, -999, 999);
	//Array_Fill_Random(Test_Array, Array_Size, 0, 999);
	Array_cout(Test_Array, Array_Size);

	std::cout << "\nLinear_Search(Test_Array, Array_Size)\n" << Linear_Search(Test_Array, Array_Size);
	std::cout << "\nLinear_Search_from_behind(Test_Array, Array_Size)\n" << Linear_Search_from_behind(Test_Array, Array_Size);
	std::cout << "\n";
	if (Linear_Search(Test_Array, Array_Size) == Array_Size) { std::cout << "\nNo negative elements in array\n"; system("pause");  return; }
	//int Test_Array2[Array_Size] = Test_Array;
	std::sort(Test_Array + Linear_Search(Test_Array, Array_Size)+1, Test_Array + Linear_Search_from_behind(Test_Array, Array_Size));
	std::cout << "\nSort with sort()\n";
	Array_cout(Test_Array, Array_Size);

	std::cout << "\nSort with bubble()\n";
	Array_Bubble_Sort(Test_Array, Array_Size, Linear_Search(Test_Array, Array_Size) + 1, Linear_Search_from_behind(Test_Array, Array_Size));
	Array_cout(Test_Array, Array_Size);
}

//Task 4
template <typename T> void Array_shift(T Test_Array[], int const Array_Size, int shift=1)
{

	for (int i = 0; i < shift; i++)
	{
		T tmp = Test_Array[Array_Size - 1];
		for (int j = Array_Size - 1; j >= 1; j--)
			Test_Array[j] = Test_Array[j - 1];
		Test_Array[0] = tmp;
	}
}
void Array_shift_demo()
{
	int const Array_Size = 10;
	int Test_Array[Array_Size];
	for (int i = 0; i < Array_Size; i++)
		Test_Array[i] = i + 1;

Array_cout(Test_Array, Array_Size);		
std::cout << "\nEnter a number to shift Test_Array ";
int My_Number = Get_Int();
Array_shift(Test_Array, Array_Size, My_Number);
Array_cout(Test_Array, Array_Size);
}

//Task 5
template <typename T> double Array_Average_Above_Value(T Test_Array[], int const Array_Size, T value)
{
	T Summ = 0;
	int Counter = 0;

	for (int i = 0; i < Array_Size; i++)
	{
		if(Test_Array[i] > value)
		{
			Summ += Test_Array[i];
			Test_Array[i] = 0;
			Counter++;
		}		
	}
	return double(Summ) / double(Counter);
}



int main()
{
	int const Array_Size = 10;
	int Test_Array[Array_Size];
	//Array_Fill_Random(Test_Array, Array_Size);
	for (int i = 0; i < Array_Size; i++)
		Test_Array[i] = i + 1;


	//Task 1. Data type determine
	//Data_Type_demo();

	//Task 2. Summ from A to B through recursion
	//Summ_through_Recursion_demo();

	//Task 3. Search and sort in random Array
	//Task3_demo();

	//Task 4. Array shift
	Array_shift_demo();


	//Task 5. Average in Array
	Array_cout(Test_Array, Array_Size);
	//std::cout << "\nEnter a number ";
	//int My_Number = Get_Int();
	int Value_Number = 4;
	std::cout << "\nAverage of elements above 4 = " << Array_Average_Above_Value(Test_Array, Array_Size, Value_Number);
	std::cout << "\n\n";
	Array_cout(Test_Array, Array_Size);


	//std::cout << "\nEnter a number to determine data type\n";
	//int My_Number = Get_Int();



	//std::cout << "\nFactorial ";
	//std::cout << Factorial(My_Number);
	//std::cout << "\nFibanachi_Number ";
	



	std::cout << "\n\n";
	system("pause");
	return 0;
}

int Get_Int()
{
	int a;
	while (!(std::cin >> a) || (std::cin.peek() != '\n'))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "[Input error! Integer expected]\n";
	}
	return a;
}
int Get_Dbl()
{
	double a;
	while (!(std::cin >> a) || (std::cin.peek() != '\n'))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "[Input error! Integer expected]\n";
	}
	return a;
}