#ifndef ADDLANEBUTTON_H
#define ADDLANEBUTTON_H

class Lane;

class AddLaneButton
{
private:
	int x;
	int y;
	int w;
	int h;
	Lane* lane;
	bool isVisible;

public:
	AddLaneButton(Lane* lane, int position);
	~AddLaneButton();
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
