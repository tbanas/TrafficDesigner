#ifndef ButtonAddRoad_H
#define ButtonAddRoad_H

class Road;

class ButtonAddRoad
{
private:
	int x, y, w, h;
	Road* road;
	bool isVisible;

public:
	ButtonAddRoad(Road* road);
	~ButtonAddRoad();
	int getX();
	int getY();
	int getW();
	int getH();
	Road* getRoad();
	bool getVisiblity();
	void setVisiblity(bool isVisible);
	void changePosition();
};

#endif
