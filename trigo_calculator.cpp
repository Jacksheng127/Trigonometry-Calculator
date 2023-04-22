#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<cfloat>
using namespace std;

const double PI = 3.14159265;
void menu();
double check(double);
double func_angle (char angle, double angle_value);
double func_sin (double x ,char angle, double angle_value);
double func_cos (double z, char angle, double angle_value );
double func_tan(double e, char angle, double angle_value);
double f_abs(double y);

int main()
{   
    char choice;
    do
    {
        menu();
        cout << "\nDo you want to continue?" << endl;
        cout <<"\tType any key to continue" << endl;
        cout <<"\tType N to stop" << endl;
        cout <<"Your response => " ;
        cin >> choice;
    }while (tolower(choice) != 'n');
    if (tolower(choice) == 'n')
        cout << "\nThank You for using this program!" << endl;
        cout << "Goodbye !!!" << endl;;

    return 0;
}

void menu()
{   double angle_value;
    char angle;
    double angle_in_rad;

    cout << "\n******* Trigonometry Program ***********" << endl;
    cout << "Please enter a angle value => ";

    while(!(cin >> angle_value))
    {   
        cin >> angle_value;
        cin.clear();
        cin.ignore(999, '\n');
        cout << "Invalid Input !!!" << endl;
        cout << "Please enter a number: ";
    }

    do
    {
        cout << "Is the angle in Degree or Radian ? " <<endl;
        cout << "\tType D if it is in Degree " << endl;
        cout << "\tType R if it is in Radian " << endl;
        cout << "Your response =>  ";
        cin >> angle;

    if (tolower(angle) == 'd' || tolower(angle) == 'r')
        break;

    }while (tolower(angle) != 'd' || tolower(angle) != 'r');

    cout << setprecision(7) << fixed << showpoint;

    if (angle == 'D' || angle == 'd' )
        cout << angle_value << " deg " << " = " << "\t" << func_angle (angle, angle_value) << " rad";

    cout << "\n\n\t\tRESULTS" << endl;
    cout <<"==============================================" << endl;
    cout << setw(9) << "x  =" << "\t" << setw(10) << func_angle(angle, angle_value) << "  Radian" << endl;
    cout << "sin (x) =" << "\t" << setw(10) << func_sin(angle_in_rad, angle, angle_value);
    cout << "\ncos (x) =" << "\t" << setw(10) << func_cos(angle_in_rad, angle, angle_value);

    if (func_tan(angle_in_rad, angle, angle_value) == DBL_MAX )
        cout << "\ntan (x) =" << "\t" << setw(9) << "infinity" ; 
    else
        cout << "\ntan (x) =" << "\t" << setw(10) << func_tan(angle_in_rad, angle, angle_value);

    return;
}

double check(double a )
{   
    if (a > (2 * PI))
        do
        {
            a = a - (2 * PI);
        }
        while (a > (2 * PI));

    return a;
}

double func_angle (char angle, double angle_value)
{   
    double angle_in_rad;
    if (angle == 'D' || angle == 'd')
        angle_in_rad =(angle_value) * PI / 180;
    else if (angle == 'R' || angle == 'r')
        angle_in_rad = angle_value ;
    
    return angle_in_rad;
}    

double func_sin (double x, char angle, double angle_value )
{   
    int  count = 1;
    double sum, num;
    x = func_angle (angle, angle_value);
    x = check(x);
    num = x;
    sum = num;
    
    do
    {   
        count += 2;
        num = -num * x * x/ (count * (count - 1));
        sum = sum + num ;

    }while (!(f_abs(num) < 0.000001) );
    
    return sum;
}

double f_abs(double y)
{
    if (y < 0.0 )
        return -y;

    return y;
}

double func_cos (double z, char angle, double angle_value )
{
    int  count = 0;
    double sum, num;
    z = func_angle (angle, angle_value);
    z = check(z);
    num = 1;
    sum = num;

    do
    {   
        count += 2;
        num = -num * z * z/ (count * (count - 1));
        sum = sum + num ;

    } while (!(f_abs(num) < 0.000001) );
    
    return sum;
}

double func_tan(double e, char angle, double angle_value)
{
    double sin , cos;
    sin = func_sin(e,  angle,  angle_value);
    cos = func_cos(e,  angle,  angle_value);

    if (f_abs(cos)  < 0.00001)
        return DBL_MAX;
    
    return (sin / cos);
}
