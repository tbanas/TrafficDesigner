#ifndef ButtonAddLane_H
#define ButtonAddLane_H

class Lane;

class ButtonAddLane
{
private:
	int x;
	int y;
	int w;
	int h;
	Lane* lane;
	bool isVisible;

public:
	ButtonAddLane(Lane* lane, int position);
	~ButtonAddLane();
	int getX();
	int getY();
	int getW();
	int getH();
	void setLane(Lane* lane);
	void setVisibility(bool isVisible);
	bool getVisibility();
	Lane* getLane();
	void changePosition(int position);
};

#endif
