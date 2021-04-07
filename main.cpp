/*

10*20         width*height

20*20


*/

#define BLOCK_SIZE 25		// 25*25 (pixel)
#define MAP_WIDTH 10
#define MAP_HEIGHT 18

#include <conio.h>
#include <windows.h>

HWND myconsole;
HDC mydc;

bool draw(int data[][3][2],int* x,int* y,int index) {
	Rectangle(mydc, *x * BLOCK_SIZE, *y * BLOCK_SIZE, (*x + 1) * BLOCK_SIZE, (*y + 1) * BLOCK_SIZE);
	for (int i = 0; i < 3; i++) { 
		Rectangle(mydc, (*x + data[index][i][0]) * BLOCK_SIZE, (*y + data[index][i][1]) * BLOCK_SIZE, (*x + data[index][i][0] + 1) * BLOCK_SIZE, (*y + data[index][i][1] + 1) * BLOCK_SIZE); 
	}
	return true;
}

int main() {

	int x = 5, y = 5;
	
	int BLOCK_DATA[7][3][2] = {
		{{1,0},{2,0},{3,0}},				// ±ä°Å
		{{0,1},{1,1},{2,1}},				// ¦±
		{{0,1},{-1,1},{-2,1}},				//   ¦°
		{{1,0},{1,1},{0,1}},				//	¡à
		{{1,0},{1,1},{2,1}},				//	¹ìÃ³·³ ²ªÀÎ°Å 1
		{{-1,0},{-1,1},{-2,1}},			//             ``            2
		{{0,1},{-1,1},{1,1}}				// ôÈ
	};

	myconsole = GetConsoleWindow();
	mydc = GetDC(myconsole);

	for (int i = 0; i <= MAP_WIDTH * BLOCK_SIZE; i++) {
		SetPixel(mydc, i + 10, 10, RGB(255, 255, 255));
		SetPixel(mydc, i + 10, 10 + MAP_HEIGHT * BLOCK_SIZE, RGB(255, 255, 255));
	}			
	// Draw map width

	for (int i = 0; i <= MAP_HEIGHT * BLOCK_SIZE; i++) {
		SetPixel(mydc, 10, i + 10, RGB(255, 255, 255));
		SetPixel(mydc, 10 + MAP_WIDTH * BLOCK_SIZE, i + 10, RGB(255, 255, 255));
	}
	//Draw map height

	draw(BLOCK_DATA, &x, &y, 1);
	while (1);
	ReleaseDC(myconsole, mydc);

}