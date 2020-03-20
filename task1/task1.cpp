#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <iomanip>

using namespace std;

int comp1 (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

double Percentile(double percNum, int *array, int size)
{
    if (percNum < 0 || percNum > 100)
    {
	    cout << "Неправильное значение перценталя" << endl;;
	    exit(0);
    }
    if (size == 1)
    {
        return array[0];
    }
    double interval = 1.0 / (size - 1);
    int leftBoundInd = static_cast<int>((percNum / 100.0) / interval);
    int rightBoundInd;
	if (leftBoundInd == size - 1)
	    rightBoundInd = leftBoundInd;
	else
	    rightBoundInd = leftBoundInd + 1;
    double percentile = ((((percNum / 100.0) - interval*leftBoundInd) 
	                / interval))*(array[rightBoundInd] - 
			array[leftBoundInd]) + array[leftBoundInd];
    return percentile;
}

int main(int argc, char *argv[])
{
    char *namefile = argv[1];
    string line;
    vector<string> data;
    int index = 0;
    ifstream f_in(namefile);
    if (argc > 1)
    {
        if (f_in.is_open())
        {
            while (getline(f_in, line))
	    {
	        data.push_back(line);
		index++;
	    }
            
	    int *number = new int[index];

            for (int i = 0; i < index; i++)
                number[i] = atoi(data[i].c_str());
            
            qsort (number, index, sizeof(int), comp1);

            float sum = 0;
            for (int i = 0; i < index; ++i)
            {
		sum += number[i];
            }
            float percentile = 0;
	    percentile = Percentile(90.0, number, index);
	    cout << fixed << setprecision(2) << percentile << endl;
	    float median = 0;
	    if (index % 2 == 1)
	        median = number[index / 2 + 1];
	    else
		median = (number[index / 2] + number[index / 2 + 1]) / 2;
	    cout << fixed << setprecision(2) << median << endl;

	    float maximum = number[index - 1];
	    cout << fixed << setprecision(2) << maximum << endl;

	    float minimum = number[0];
            cout << fixed << setprecision(2) << minimum << endl;

	    float middle = sum / index;
            cout << fixed << setprecision(2) << middle << endl;
        }
    }
    else
	cout << "нет файла" << endl;
    return 0;
}
