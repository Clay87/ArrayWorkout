//Clayton Bradford
//Third Program
//Array Workout

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

//Constant for program handling
const int MAX = 100;

//Prototypes
void ReadArray(int[],int&);
void PrintArray(int[], int&);
double Total(int[],int);
double AverageArray(int[], int);
double AverageArray(double, int);
int LargerThanAverage(int[],int, double);
int SmallerThanAverage(int[], int, double);
void NegativeToPositive(int[],int);
double LargestNumber(int[],int, int&);
double SmallestNumber(int[],int, int&);
void ZeroOutEvens(int[],int);
void ReadParameters(int[],int&);
void PrintParameters(int[],int&);
int Parameterfirst(int[],int[],int);
int Parametersecond(int[],int[],int);
int secondThird(int[], int[], int);
int MultipleOfFourth(int[],int[],int&);
int MultipleOfFifth(int[],int[],int);
void NewArray(int[],int[],int&);
void ReverseOrder(int[],int&);


//File I/O
ifstream inf("Array.in");
ofstream out("Array.out");
ifstream in2("Parameters.in");

//Function to read values into the array
void ReadArray(int ary[], int& counter)
{
    int num;
    counter=0;
    while(inf >> num && counter < MAX)
    {
        ary[counter] = num;
        counter++;
    }
}

//Function to print the data to the desired file
void PrintArray(int bry[],int& counter)
{
    out << setprecision(2) << fixed;

    for(int i=0; i<counter; i++)
    {
        out << bry[i] << ", ";
        if((i+1)% 10 == 0)
            out << endl;
    }
}

//Function that totals up the numbers of the infile
double Total(int ory[], int z)
{
        int sum=0;
        for(int k=0; k<z; k++)
            sum+=ory[k];
    return sum;
}

//Function that averages the array
double AverageArray(int gry[], int h)
{
    double sum = Total(gry, h);

    return sum/h;
}

//Function replicated because of overload
double AverageArray(double sum, int counter)
{
    return sum/counter;
}

//Function that determines the numbers that are larger than the average
int LargerThanAverage(int jry[], int i, double avg)
{
    int cnt=0;
    for(int j=0; j<i; j++)
    {
        if(jry[j]>avg)
            cnt++;
    }
    return cnt;
}

//Function that calculates the amount of numbers smaller than the average.
int SmallerThanAverage(int pry[], int i, double avg)
{
    int cnt = 0;
    for(int j=0; j<i; j++)
    {
        if(pry[j]<avg)
            cnt++;
    }
    return cnt;
}

//Function that converts negative integers to positive.
void NegativeToPositive(int ury[], int m)
{
    out << "\n\nSecond Array: Negative to Positive\n";
    for(int n=0; n<m; n++)
    {
        if(ury[n]<0)
           ury[n] *= -1;
    }
}

//Function that finds the largest value and its position
double LargestNumber(int ary[], int counter, int& position)
{
    int largest=ary[0];
    for(int i=0;i<counter;i++)
    {
        if(largest<ary[i])
        {
            largest=ary[i];
            position=i;
        }
    }
    return largest;
}

//Function that finds the smallest value and its position
double SmallestNumber(int ary[], int counter, int& position)
{
    int smallest=ary[0];
    for(int i=0;i<counter;i++)
    {
        if(smallest>ary[i])
        {
            smallest=ary[i];
            position=i;
        }
    }
    return smallest;
}

//Function that zeros out even values
void ZeroOutEvens(int ary[], int counter)
{
    out << "\n\nThird Array: Zero-out Even Values\n";
    for(int i=0;i<counter;i++)
        if(ary[i]%2 == 0)
           ary[i]=0;
}

//Function reads the second file
void ReadParameters(int param[],int& counter)
{
    int num;
    counter=0;
    while(in2 >> num && counter < MAX)
    {
        param[counter] = num;
        counter++;
    }
}

//Function that prints the Parameters to the file
void PrintParameters(int par[], int& counter)
{
    out << setprecision(2) << fixed;
    for(int i=0; i<counter; i++)
        out << par[i] << ", ";
}

//Function determines the values less than first input
int Parameterfirst(int ary[], int bry[],int counter)
{
    int values=0;
    for(int i=0;i<counter;i++)
        if(bry[i]<ary[0])
           values++;
    return values;
}

//Function determines the values greater than second input
int Parametersecond(int ary[], int bry[],int counter)
{
    int values=0;
    for(int i=0;i<counter;i++)
        if(bry[i]>ary[1])
           values++;
    return values;
}

//Function determines values greater than third input
int secondThird(int ary[], int bry[],int counter)
{
    int values=0;
    for(int i=0;i<counter;i++)
        if(bry[i]>ary[2])
           values++;
    return values;
}

//Function for multiples of fourth
int MultipleOfFourth(int ary[],int bry[], int& counter)
{
      int cnt=0;
    for(int i=0;i<counter;i++)
        if(bry[i] % ary[3] == 0)
           cnt++;
    return cnt;
}

//Function for multiples of fifth
int MultipleOfFifth(int ary[], int bry[], int counter)
{
      int cnt=0;
    for(int i=0; i<counter; i++)
        if(bry[i] % ary[4] == 0)
           cnt++;
    return cnt;
}

void NewArray(int New[],int old[],int& sizes)
{
    out << "\nNew Array: \n";
    for(int i=0; i<sizes;i++)
    {
        New[i] = old[i];
        out << New[i] << ", ";
        if((i+1)%10==0)
            out<<endl;
    }
}

//Function call to Reverse the order of the array
void ReverseOrder(int rev[],int& counter)
{
    out << "\nReversed Order: \n";
    for(int i=counter-1;i>=0;i--)
    {
        out<<rev[i] << ", ";
        if((i)%10==0)
        out<< endl;
    }
}

int main()
{
    //Variables
    int MyArray[MAX],counter,cnt,large,largest,first,third,fourth,
        fifth,smallest,pos1,pos2,Array2[MAX],small,zero,second,Parameters[MAX];

    double average,sum;

    //Outfile Header
    out << "\tArray Work-Out Program\n"
         << "First Array: \n";

    //Function call to read in the numbers and print to file
    ReadArray(MyArray, counter);
    PrintArray(MyArray,counter);

    //Function call to average the array
    sum=Total(MyArray,counter);
    average=AverageArray(sum, counter);

    out << "Sum = " << sum << " COUNT = " << counter
        << " AVERAGE = " << average;

    //Function call for number larger/smaller than average
    large=LargerThanAverage(MyArray,counter,average);
    small=SmallerThanAverage(MyArray,counter,average);

    out << "\n\nValues LARGER than AVERAGE: " << large
        << "\nValues SMALLER than AVERAGE: " << small;

    //Function call to change negatives to positive
    NegativeToPositive(MyArray,counter);
    PrintArray(MyArray,counter);
    sum=Total(MyArray,counter);
    average=AverageArray(sum,counter);

    out << "Sum = " << sum << " COUNT = " << counter
        << " AVERAGE = " << average;

    //Function call to determine min/max number of the array.
    largest=LargestNumber(MyArray,counter,pos1);
    smallest=SmallestNumber(MyArray,counter,pos2);

    out << "\n\nLargest Number of the Array is: " << largest
        << "\nPosition: " << pos1
        << "\n\nSmallest Number of the Array is: " << smallest
        << "\nPosition: " << pos2;

    //Function call to zero out even
    ZeroOutEvens(MyArray,counter);
    PrintArray(MyArray,counter);
    sum=Total(MyArray,counter);
    average=AverageArray(sum,counter);

    out << "Sum = " << sum << " COUNT = " << counter
        << " AVERAGE = " << average;

    //Function calls for second half of assignment
    out << "\n\nParameters File Listing: \n";
    ReadParameters(Parameters,cnt);
    PrintParameters(Parameters,cnt);
    first=Parameterfirst(Parameters,MyArray,counter);
    second=Parametersecond(Parameters,MyArray,counter);
    third=secondThird(Parameters,MyArray,counter);
    fourth= MultipleOfFourth(Parameters, MyArray, counter);
    fifth= MultipleOfFifth(Parameters, MyArray, counter);

    out << "\nValues Less than First Input: " << first
        << "\nValues Greater than Second Input: " << second
        << "\nValues Greater than Third Input: " << third
        << "\nMultiples of Fourth Input: " << fourth
        << "\nMultiples of Fifth Input: " << fifth << endl;

    //Function call for new array
    NewArray(Array2,MyArray,counter);
    ReverseOrder(Array2,counter);

    out.close();
    inf.close();
    in2.close();
    return 0;
}
