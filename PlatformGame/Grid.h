#ifndef GRID_H
#define GRID_H
#include <vector>
#include <string>
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
	void setNewMessage(std::string message);
	void refreshScreen();	
	void clearScreen();
	void setNewSize(int x, int y);
private:	
	std::vector<std::string> messages;
	static bool isInstance;
	int sizeX;
	int sizeY;
	char** screen;	
};


#endif // !GRID_H