#include <iostream>
#include <Eigen>
#include "bmpNew.h"

using namespace std;
using namespace Eigen;

// eigen library 생성방법
// https://www.youtube.com/watch?v=kP7VpzXBuhg

// bmp file 문제
// https://www.youtube.com/watch?v=qBuzXpmg8vw

void affineXform(int xp, int yp, float* Ai, int* x, int* y) {
	*x = (int)(xp * Ai[0] + yp * Ai[1]);
	*y = (int)(xp * Ai[2] + yp * Ai[3]);
}

int main() {

	//sprint1 - A의 역행렬 구하기. 
	MatrixXd A(2,2);
	A << 1, 1, 1, -3;

	MatrixXd Ainv = A.inverse(); // 역행렬 구할 때 (2,2)는 뺀다.
	cout << A << endl;
	cout << "----------------------\n";
	cout << Ainv << endl;
	cout << "----------------------\n";

	//sprint2 - sunflower.bmp 파일을 그대로 읽어오기. 
	int X, Y;
	int x, y, yX, ixx;

	unsigned char* bmpB = ReadBmp("sunflower.bmp", &X, &Y); // sunflower.bmp파일 그대로 읽기. 
	if (!bmpB) {
		cout << "bmp 이미지를 찾을 수 없습니다.\n";
		return 111;
	}

	WriteBmp("sunflower2.bmp", bmpB, X, Y);

	cout << "가로 x : " << X<< endl;
	cout << "세로 y : " << Y << endl;

	unsigned char* aff = new unsigned char[X * Y * 3];
	float ai[4] = { 0.75,0.25,0.25,-0.25 }; // Ainv값. 

	//sprint3 - Ainv에 의해 변형된 이미지 출력. 
	for (int iy = 0; iy < Y; iy++) {
		yX = iy * X * 3;

		for (int ix = ixx = 0; ix < X; ix++, ixx += 3) {
			affineXform(ix - X / 2, iy - Y / 2, ai, &x, &y);
			x += X / 2;
			y += Y / 2;
			if (x > -1 && x<X && y>-1 && y < Y) {
				int xy = (y * X + x) * 3;
				aff[yX + ixx] = bmpB[xy];
				aff[yX + ixx + 1] = bmpB[xy + 1];
				aff[yX + ixx + 2] = bmpB[xy + 2];
			}
		}
	}
	// sprint3 - 변형된 이미지 bmp file. 
	WriteBmp("sunflowertransformed.bmp", aff, X, Y);

	unsigned char* bmpBm = new unsigned char[X * Y * 3];
	unsigned char* xxx;

	// 3. modify, 오른쪽 아래 끝에 100*50 크기만큼 빨간색 배경 넣기. 
	int jj;
	for (int i = 0; i < X * Y * 3; i++) bmpBm[i] = bmpB[i];
	for (int i = 0; i < 50; i++) {
		xxx = bmpBm + i * X * 3 + (X - 100) * 3;
		for (int j = jj = 0; j < 100; j++, jj += 3) {
			xxx[jj] = 0; // B
			xxx[jj + 1] = 0; // G
			xxx[jj + 2] = 255; // R
		}
	}
	// 4. write the modified image
	WriteBmp("sunflowerM.bmp", bmpBm, X, Y);

	//sprint4 - 고유벡터와 고유값 구하기.
	EigenSolver<MatrixXd> es;
	es.compute(A);
	cout << "----------------------\n";
	cout << "The eigenvalues of A are:" << endl << es.eigenvalues() << endl; // 고유치 lambda1,lambda2

	MatrixXd P(2,2);
	for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++)
		P(i, j) = es.eigenvectors()(i, j).real();

	cout << "----------------------\n";
	cout << "eigen vector v1, v2 in P: \n" << P << endl; // 고유벡터 v1, v2

	delete[] bmpBm;
	delete[] aff;

	return 0; 

}