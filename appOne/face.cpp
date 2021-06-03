#include"libOne.h"

void roundFace(float px, float py) {
	fill(255, 255, 0);
	circle(px, py, 300);
	fill(255);
	circle(px - 50, py, 80);
	circle(px + 50, py, 80);
	fill(0);
	circle(px - 50, py, 30);
	circle(px + 50, py, 30);
	fill(255, 200, 200);
	circle(px, py + 80, 80);
}
void squareFace(float px, float py, float angle) {
	rectMode(CENTER);
	fill(255, 255, 0);
	rect(px, py, 300, 300, angle);
	fill(255);
	rect(px - 50, py, 80, 80, angle);
	rect(px + 50, py, 80, 80, angle);
	fill(0);
	rect(px - 50, py, 30, 30, angle);
	rect(px + 50, py, 30, 30, angle);
	fill(255, 200, 200);
	rect(px, py + 80, 80, 80, angle);
}