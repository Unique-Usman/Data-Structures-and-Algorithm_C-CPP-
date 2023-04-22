#include <iostream>
#include <exception>

using namespace std;


// class that manage the speed of a car i.e the content of the error to be thrown. It inherit from the std::exception
class manageSpeed:public exception
{
	protected: 
	int speed;
};

//class which manage the error to be thrown for underSpeed
class underSpeed:public manageSpeed
{
	public:
	void setSpeed(int speed){
		this->speed = speed;
	}
	const char* what(){
		return "The speed is too low, this is not a snail..."; 
	}
	int getSpeed(){
		return this->speed;
	}
};

//class which manage the error to be thrown for overSpeed
class overSpeed: public manageSpeed{
	public:
	const char *what(){
		return "The speed is too high \n This is not a plane ";
	}
	void setSpeed(int speed){
		this->speed = speed;
	}
	int getSpeed(){
		return this->speed;
	}

};

//Class for cars 
class Car{
int speed;
	public:
	Car(){
		speed = 0;
	}
	void decelerate(){
		for(;;){
			speed -= 10;
			if (speed <= -250){
				underSpeed s;
				s.setSpeed(this->speed);
				throw s;
			}
		}
	}

	void accelerate(){
		for (;;){
			speed += 10; 
			if (speed >= 250){
				overSpeed s;
				s.setSpeed(speed);
				throw s;
			}
		}
	}
};

//the main function
int main()
{
	Car c1;
	try{
		c1.accelerate();
		c1.decelerate();
	}catch(overSpeed s){
		cout << s.what() << endl;
		cout << s.getSpeed() << endl;
	}
}
