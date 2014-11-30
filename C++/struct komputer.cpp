#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

struct komputer {
	string cpu;
	string gpu;
	int ram;
	int hdd;
};


int main(int argc, char *argv[])
{
	
komputer pc[4];

pc[0].cpu="Intel Core 2 Duo";
pc[0].gpu="GF 8600";
pc[0].ram=512;
pc[0].hdd=160;

pc[1].cpu="Intel Core 2 Quad";
pc[1].gpu="GF 9600";
pc[1].ram=1024;
pc[1].hdd=360;

pc[2].cpu="AMD Athlon X4";
pc[2].gpu="Radeon 6995";
pc[2].ram=2048;
pc[2].hdd=500;

pc[3].cpu="Intel i7";
pc[3].gpu="GF GT250";
pc[3].ram=8186;
pc[3].hdd=2000;


for (int i=0; i<4; i++)
{
	cout<<"Procesor: "<<pc[i].cpu<<endl;
	cout<<"Karta graficzna: "<<pc[i].gpu<<endl;
	cout<<"Pamiec RAM: "<<pc[i].ram<<" MB"<<endl;
	cout<<"Dysk twardy: "<<pc[i].hdd<<" GB"<<endl;
	cout<<endl;
}

	system("pause");
	return 0;
}
