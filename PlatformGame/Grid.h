#ifndef GRID_H
#define GRID_H




//
//Class which have only one instance (we have only one console)
//
class Grid
{
public:
	Grid(int sizeX, int sizeY);
	~Grid();
	void setObject(int x, int y);
	void setObject(int x, int y, char symbol);
	void deleteObject(int x, int y);
	void setNewMessage(char* message);
	void refreshScreen();
private:	
	static bool isInstance;
	int sizeX;
	int sizeY;
	int visibleMessage;
	char** screen;
	
};


#endif // !GRID_H