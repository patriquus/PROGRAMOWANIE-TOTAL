#include <cstdlib>
#include <iostream>

using namespace std;

class Punkt {
	protected:
	int x, y;
              
	public:
	Punkt() {
		x = 0;
		y = 0;
		}
	
	Punkt (int x, int y) {
	  	this -> x = x;
		this -> y = y;
		}
			
	void setX(int x) {
		this -> x = x;
	}			
	
	int getX() {
		return x;
	}
		
	void setY(int y) {
		this -> y = y;
	}
	
	int getY() {
		return y;
	}
	
	void przesunPunkt(int dx, int dy) {
		x = x + dx;
		y = y + dy;
	}
	
	void wyswietl() {
	    cout << getX() << endl;
    	cout << getY() << endl;	
	}	 
};	

class Punkt3D: public Punkt {
	private:
		int z;
	public:
	Punkt3D() {
		x = 0;
		y = 0;
		z = 0;
	}
	
	Punkt3D (int x, int y, int z) {
		this -> x = x;
		this -> y = y;
		this -> z = z;
	}
	
	void setZ(int z) {
		this -> z = z;
	}
	
	int getZ() {
		return z;
	}

	void przesunPunkt(int dx, int dy, int dz) {
		x = x + dx;
		y = y + dy;
		z = z + dz;
	}
	
	void ustawPozycje (int x, int y, int z) {
		this -> x = x;
		this -> y = y;
		this -> z = z;	
	}
		
	void wyswietl() {
		cout << getX() << endl;
    	cout << getY() << endl;	
    	cout << getZ() << endl;				
	}
	
};	 			  

int main(int argc, char *argv[])
{
	/*Punkt p1;
	p1.setX(10);
	p1.setY(5);
	p1.wyswietl();
	p1.przesunPunkt(2, 2);
	p1.wyswietl();*/
	
	Punkt3D p1; 
/*	p1.setX(10);
	p1.setY(5);
	p1.setZ(7);*/
	p1.ustawPozycje(2,3,4);
	p1.wyswietl(); 
	p1.przesunPunkt(5, 5, 6);	
	p1.wyswietl(); 	
    system("pause");
    return 0;
}
