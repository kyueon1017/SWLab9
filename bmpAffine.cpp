// Author: Doug Young Suh
// Date:   July 7, 2020
//
//   Modify a bmp file
// 1. read a bmp file
// 2. width, height -> affine transformed image memory allocation
// 3. affine transform
// 4. write the modified image

//
//#include <iostream>
//#include "bmpNew.h"
////  vec(x) = Ai vec(x')
//void affineXform(int xp, int yp, float* Ai, int* x, int* y) {
//	*x = (int)(xp * Ai[0] + yp * Ai[1]);
//	*y = (int)(xp * Ai[2] + yp * Ai[3]);
//}
//int main() {
//	// 1. read a bmp file
//	// read a bmp image
//	int X, Y, x, y, yX, ixx;
//	// return raw image pointer
//	unsigned char* original = ReadBmp("sunflower.bmp", &X, &Y); // 24bits bmp
//	if (!original) { // if the bmp file does not exist in this folder....
//		std::cout << " cannot find image file" << std::endl;
//		return 666;
//	}
//	std::cout << "   width " << X << "  height " << Y << "\n";
//	// 2. width, height --> modified memory allocation
//	unsigned char* aff = new unsigned char[X * Y * 3];
//	// 3-1. translation (dx dy)=(100,50)
//	//int dx=100,dy=50;
//	/*for(int iy=0; iy<Y; iy++){
//		yX = iy * X * 3;
//		for (int ix = ixx = 0; ix < X; ix++,ixx+=3) {
//			x = ix - dx;
//			y = iy - dy;
//			if (x > -1 && x<X && y>-1 && y < Y) {
//				int xy = (y*X + x) * 3;
//				aff[yX + ixx] = original[xy];
//				aff[yX + ixx+1] = original[xy+1];
//				aff[yX + ixx+2] = original[xy+2];
//			}
//		}
//	}
//	// 4-1. write the modified image
//	WriteBmp("sunflowerTrans10050.bmp", aff, X, Y);
//	// 3-2.scaling
//	float ai[4] = { 0.5, 0, 0, 2 };
//	for (int iy = 0; iy<Y; iy++) {
//		yX = iy * X * 3;
//		for (int ix = ixx = 0; ix < X; ix++, ixx += 3) {
//			affineXform(ix-X/2, iy-Y/2, ai,&x,&y);
//			x += X/2;
//			y += Y/2;
//			if (x > -1 && x<X && y>-1 && y < Y) {
//				int xy = (y*X + x) * 3;
//				aff[yX + ixx] = original[xy];
//				aff[yX + ixx + 1] = original[xy + 1];
//				aff[yX + ixx + 2] = original[xy + 2];
//			}
//		}
//	}
//	 4-2. write the modified image
//	WriteBmp("sunflowerScale.bmp", aff, X, Y);
//
//	// 3-3 rotation
//	const float pi = 3.141592;
//	float ai[4] = { cos(pi/6.0), sin(pi / 6.0), -sin(pi / 6.0), cos(pi / 6.0) };
//	for (int iy = 0; iy<Y; iy++) {
//		yX = iy * X * 3;
//		for (int ix = ixx = 0; ix < X; ix++, ixx += 3) {
//			affineXform(ix - X / 2, iy - Y / 2, ai, &x, &y);
//			x += X / 2;
//			y += Y / 2;
//			if (x > -1 && x<X && y>-1 && y < Y) {
//				int xy = (y*X + x) * 3;
//				aff[yX + ixx] = original[xy];
//				aff[yX + ixx + 1] = original[xy + 1];
//				aff[yX + ixx + 2] = original[xy + 2];
//			}
//		}
//	}
//	// 4-3. write the modified image
//	WriteBmp("sunflowerRotate.bmp", aff, X, Y);*/
//	// 3-4 mixed
//
//	float ai[4] = { 2, 1, -0.5, 0.7 };
//	for (int iy = 0; iy < Y; iy++) {
//		yX = iy * X * 3;
//		for (int ix = ixx = 0; ix < X; ix++, ixx += 3) {
//			affineXform(ix - X / 2, iy - Y / 2, ai, &x, &y);
//			x += X / 2;
//			y += Y / 2;
//			if (x > -1 && x<X && y>-1 && y < Y) {
//				int xy = (y * X + x) * 3;
//				aff[yX + ixx] = original[xy];
//				aff[yX + ixx + 1] = original[xy + 1];
//				aff[yX + ixx + 2] = original[xy + 2];
//			}
//		}
//	}
//	// 4-3. write the modified image
//	WriteBmp("sunflowerMixed.bmp", aff, X, Y);
//	return 123;
//}