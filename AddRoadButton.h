#ifndef ADDROADBUTTON_H
#define ADDROADBUTTON_H

class Road;

class AddRoadButton
{
private:
	int x, y, w, h;
	Road* road;
	bool isVisible;

public:
	AddRoadButton(Road* road);
	~AddRoadButton();
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
