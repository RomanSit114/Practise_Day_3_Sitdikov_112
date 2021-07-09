#include <iostream>
#include <cmath>
#include <cstdlib>

//вариант 2

using namespace std;
float t = 0;
const float g = 9.8;



struct Task {
	float height = 100; //задаем высоту шарика
	float x = 0;
	float y = height;

	float v0 = 0; //начальная скорость
	float vy = 0;
	float ax = 0;
	float ay = -g;
	float m = 0;
};




void print(Task ball) { //вывод результатов
	cout << abs(ball.ay) << "		" << abs(ball.vy) << "		" << ball.y << endl;
}



void motion(Task* ball, float deltatime) { //физика программы

	t = t + deltatime;
	ball->vy = ball->v0 + ball->ay * t;
	ball->y = ball->height + ball->ay * 0.5 * t * t;
	if (ball->y <= 0) {
		ball->y = 0;
		ball->vy = 0;
	}
}




int main() {
	setlocale(LC_ALL, "ru");
	cout << "Roman Sitdikov М3О-112B-20\n\n";

	cout << "Time		A(y)		V(y)		Height\n\n" ;
	
	float t = 0;
	Task a;
	float raznitsaT = 0.5; //заданный промежуток времени
	for (int i = 0; i < 15; i++) {
		cout << t << "		";
		motion(&a, raznitsaT);
		print(a);
		t = t + raznitsaT;           
	}
}