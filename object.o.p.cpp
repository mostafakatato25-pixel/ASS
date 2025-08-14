#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//! definition (encapsulation)
class car
{
private:
    //?properties
    string brand;
    string model;
    int year;

protected:
    bool is_expired()
    {
        int current_year = 2025;
        return (current_year - year) > 15;
    }

public:
    //! Default constructor
    car()
    {
        brand = "unavailable";
        model = "unavailable";
        year = 1;
    }
    //! constructor
    car(string brand, string model, int year)
    {
        set_brand(brand);
        set_model(model);
        set_year(year);
        car::is_expired();
    }

    //?methods
    virtual void displayinfo()
    {

        cout << "brand : " << get_brand() << endl;
        cout << "model : " << get_model() << endl;
        cout << "yaer : " << get_year() << endl;
        cout << "expired : " << (is_expired() ? "yes" : "no") << endl;
        cout << "===================================" << endl;
    }
    //! setters // getters
    void set_brand(string n)
    {
        n.erase(remove_if(n.begin(), n.end(), ::isdigit), n.end());
        brand = n;
    }
    string get_brand()
    {
        return brand;
    }
    void set_model(string m)
    {
        m.erase(remove_if(m.begin(), m.end(), ::isdigit), m.end());
        model = m;
    }
    string get_model()
    {
        return model;
    }
    void set_year(int y)
    {
        year = y;
    }
    int get_year()
    {
        return year;
    }
    //! destrutor
    ~car()
    {
        //! clear resources
        cout << "clennad resources" << endl;
    }
};

//! inheritance
class electricCar : public car
{
private:
    int battery_capacity;

public:
    electricCar(string brand, string model, int year, int battery_capacity)
    {

        car::set_brand(brand);
        car::set_model(model);
        car::set_year(year);
        set_battery_capacity(battery_capacity);
    }

    void set_battery_capacity(int b)
    {
        battery_capacity = b;
    }
    int get_battery_capacity()
    {

        return battery_capacity;
    }
    //! polymorphism
    void displayinfo() override
    {
        car::displayinfo();
        cout << "battery capacity : " << get_battery_capacity() << endl;
        cout << "=============================" << endl;
    }
};

int main()
{

    car car0("nisn", "sunyy", 2008);
    car car1("mercedes55", "cc89", 2021);
    car car2;

    electricCar ecar1("tesla", "modelX", 2024, 1000);

    car0.displayinfo();
    car1.displayinfo();
    car2.displayinfo();
    ecar1.displayinfo();
    return 0;
}




///////////////////////////////
/*
Single Inheritance
class A
class B : public A
Multible Inheritance
class A
class B
class C : public A, public B
Hierarchical Inheritance
class A
class B : public A
class C : public A
Multilevel Inheritance
class A
class B : public A
class C : public B
class D : public C
*/
