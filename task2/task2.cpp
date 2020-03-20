#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class Point
{
public:
    Point()
    {
        x = y = 0;
    }	
    float x;
    float y;
};
 
Point create (float a, float b)
{
    Point cr;
    cr.x = a;
    cr.y = b;
    return cr;
}

int IsPointInsidePolygon (Point *p, float x, float y)
{
    float S, S1, S2, S3;
    int N, flag, i1, i2, n;
    N = 4;
    for (n = 0; n < N; n++)
    {
        flag = 0;
        i1 = n < N - 1 ? n + 1 : 0;
        while (flag == 0)
        {
            i2 = i1 + 1;
            if (i2 >= N)
                i2 = 0;
            if (i2 == (n < N - 1 ? n + 1 : 0))
                break;
            S = abs (p[i1].x * (p[i2].y - p[n ].y) + 
                     p[i2].x * (p[n ].y - p[i1].y) + 
                     p[n].x  * (p[i1].y - p[i2].y));
            S1 = abs (p[i1].x * (p[i2].y - y) +
                      p[i2].x * (y - p[i1].y) +
                      x * (p[i1].y - p[i2].y));
            S2 = abs (p[n ].x * (p[i2].y - y) +
                      p[i2].x * (y - p[n ].y) +
                      x * (p[n ].y - p[i2].y));
            S3 = abs (p[i1].x * (p[n ].y - y) +
                      p[n ].x * (y - p[i1].y) +
                      x * (p[i1].y - p[n ].y));
            if (S == S1 + S2 + S3)
            {
                flag = 1;
                break;
            }
            i1 = i1 + 1;
            if (i1 >= N)
                i1 = 0;
        }
        if (flag == 0)
            break;
    }
    return flag;
}


int main(int argc, char *argv[])
{
    char *polygon = argv[1];
    char *dots = argv[2];
    string line;
    ifstream f_in;
    float a = 0.0;
    float b = 0.0;
    std::string::size_type sz;
    Point *p = new Point[4];
    f_in.open(polygon);
    if (argc == 3)
    {
        if (f_in.is_open())
        {
	    int i = 0;
            while (getline(f_in, line))
            {
		a = stod (line, &sz);
                b = stod (line.substr(sz));
		p[i] = create(a, b);
		i++;
            }
	}
	f_in.close();

	f_in.open(dots);
	if (f_in.is_open())
        {
	    float x2 = 0.0;
	    float y2 = 0.0;
	    while (getline(f_in, line))
            {
                x2 = stod (line, &sz);
                y2 = stod (line.substr(sz));
		int flag = 0;
		int flag2 = 0;
		for (int i = 0; i < 4; i++)
		{
		    if (p[i].x == x2 && p[i].y == y2)
		    {
			flag = 1;
		        break;
		    }
		    else if (p[i].x == x2 || p[i].y == y2)
	            {
			flag2 = 1;
		    }
		}
	        if (IsPointInsidePolygon (p, x2, y2) == 1 
				&& flag == 0 && flag2 == 0)
	            cout << 2 << endl;
		if (IsPointInsidePolygon (p, x2, y2) == 1 && flag == 1)
		    cout << 0 << endl;
		if (IsPointInsidePolygon (p, x2, y2) == 1 
				&& flag2 == 1 && flag == 0)
                    cout << 1 << endl;
		else if (IsPointInsidePolygon (p, x2, y2) == 0)
		    cout << 3 << endl;
            }
	}
	else
	    cout << "Не открылся" << endl;
	f_in.close();
   }
   else
       cout << "Нет файлов" << endl;
   return 0;
}
