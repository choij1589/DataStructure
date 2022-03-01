#include <cstdio>
#define WIDTH	20
#define HEIGHT	9

void labelComponent(unsigned char img[HEIGHT][WIDTH], int x, int y, int label) {
	if (x<0 || y<0 || x>=WIDTH || y>=HEIGHT)
		return;

	if (img[x][y] == 0) {	// 처리가 안된 화소이면
		img[y][x] = label;
		labelComponent(img, x-1, y, label);
		labelComponent(img, x, y-1, label);
		labelComponent(img, x+1, y, label);
		labelComponent(img, x, y+1, label);
	}
}

// 이진 영상의 영역 채색 함수
void blobColoring(unsigned char img[HEIGHT][WIDTH]) {
	int label = 1;

	for (int y = 0; y < HEIGHT; y++)
		for (int x = 0; x < WIDTH; x++) {
			if (img[y][x] == 9)
				labelComponent(img, x, y, label++);
		}
}

void printImage(unsigned char img[HEIGHT][WIDTH], char *msg) {
	printf("%s\n", msg);
	for (int y=0; y<HEIGHT; y++) {
		for (int x=0; x<WIDTH; x++) {
			if (img[y][x] == 0)
				printf(".");
			else
				printf("%-1d", img[y][x]);
		}
		printf("\n");
	}
	printf("\n");
}

int main() {
	unsigned char image[HEIGHT][WIDTH] = {
		0,0,0,0,0,0,9,0,0,0,0,9,9,9,9,9,0,0,9,9,
		9,9,9,9,9,0,9,0,0,0,0,0,0,0,0,9,0,0,9,9,
		0,0,9,0,0,0,9,0,0,0,0,9,9,9,9,9,0,0,9,9,
		0,9,9,9,0,0,9,9,9,0,0,9,0,0,0,0,0,0,9,9,
		0,9,0,9,0,0,9,0,0,0,0,9,9,9,9,9,0,0,9,9,
		9,9,0,9,9,0,9,0,0,0,0,0,0,0,0,0,0,0,9,9,
		9,0,0,0,9,0,9,0,0,0,0,0,9,0,9,0,0,0,0,0,
		9,0,0,0,9,0,9,0,0,0,0,0,9,0,9,0,0,0,9,9,
		0,0,0,0,0,0,9,0,0,0,0,9,9,9,9,9,0,0,9,9
	};

	printImage(image, "<Original image>");
	blobColoring(image);
	printImage(image, "<Labelled image>");

	return 0;
}

