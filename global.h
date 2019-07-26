#pragma once

#define _USE_MATH_DEFINES

#include <math.h>
#include <stdlib.h>
#include "LWindow.h"

struct Point {
	Point() {};
	Point(float _x, float _y) {
		x = _x;
		y = _y;
	}

	float x;
	float y; 
};

inline Point operator+(Point a, Point b) {
	return Point(a.x + b.x, a.y + b.y);
}

inline Point operator*(Point a, float b) {
	return Point(a.x * b, a.y *b);
}

inline float pointDistance(Point a, Point b) {
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

inline float vectorLength(Point a) {
	return sqrt(a.x*a.x + a.y*a.y);
}

inline float vectorLengthSquared(Point a) {
	return a.x*a.x + a.y*a.y;
}

inline bool oppositeVectors(Point a, Point b) {
	if ((a.x*b.x + a.y*b.y)*(a.x*b.x + a.y*b.y) / (vectorLengthSquared(a) * vectorLengthSquared(b)) == -1) {
		return true;
	}

	return false;
}

inline float randomFloat(float lo, float hi) {
	return static_cast<float>(lo + rand()) / static_cast<float>(RAND_MAX / ( hi - lo) );
}

inline Point rotateVector(Point a, float angle) {
	Point rotatedPoint;

	rotatedPoint.x = a.x * cos(angle) - a.y * sin(angle);
	rotatedPoint.y = a.x * sin(angle) + a.y * cos(angle);

	return rotatedPoint;
}

inline float radToDeg(float a) {
	return a * (180.f / M_PI) ;
}

inline float degToRad(float a) {
	return a * (M_PI / 180.f);
}

inline Point randomPointOnScreen() {
	return Point(randomFloat(0, LWindow::SCREEN_WIDTH) , randomFloat(0, LWindow::SCREEN_HEIGHT - 50));
}