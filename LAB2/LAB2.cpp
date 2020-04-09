#include <iostream>
#include <windows.h>
#include <thread>
#include <conio.h>

using namespace std;
HWND hwnd = GetConsoleWindow();  //дискриптор
HDC hdc = GetDC(hwnd);

int a[50], b[50], v[50]; //цвета
double x[50], y[50];

class Planet{

private:
	int xo, yo, r[50], mas[50];
	string c[50];
	int n;
	double pi = 3.14;

public:
	Planet(int n){
		this->n = n;
		xo = 1;
		yo = 1;
		for (int i = 0; i < n; i++){
			cout << "Distance " << i + 1 << ' ' << endl;
			cin >> mas[i];
			cout << "Radiys " << i + 1 << ' ' << endl;
			cin >> r[i];
			cout << "Color " << i + 1 << ' ' << endl;
			cin >> c[i];
		}
		Draw_in_console();
	}

	void Draw_in_console(){
		while (1){
			for (double i = 0; i <= 2 * pi; i += 0.1){
				system("cls");
				for (int j = 0; j < n; j++){
					x[j] = (xo * cos(i) * mas[j]);    //координаты круга основ на прямоуг
					y[j] = (yo * sin(i) * mas[j]);
					if (c[j] == "red")
						a[j] = 255;
					if (c[j] == "green")
						b[j] = 255;
					if (c[j] == "blue")
						v[j] = 255;
					if (c[j] == "yellow"){  //смешение  
						a[j] = 255;
						b[j] = 244;
						v[j] = 15;
					}


					SelectObject(hdc, CreatePen(PS_SOLID, 3, RGB(a[j], b[j], v[j])));  //создать объект, оконтовка
					SelectObject(hdc, CreateSolidBrush(RGB(a[j], b[j], v[j])));       //закрасить объект 
					Ellipse(hdc, x[j] + 150 - r[j] / 2, y[j] + 150 - r[j] / 2, x[j] + 150 + r[j] / 2, y[j] + 150 + r[j] / 2);
				}

				Sleep(50);
			}
		}
	}

	~Planet() {}  //очищение 

};

int main(){
	system("cls");    //очищение консоли 
	int n;
	cin >> n;
	Planet  a(n);

	return 0;
}

