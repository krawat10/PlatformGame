#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H
#include <iostream>
class Serializable
{
public:
	Serializable() {}
	virtual ~Serializable() {}
private:
	virtual void serialize(std::ostream& stream) = 0;
	virtual void deserialize(std::istream& stream) = 0;
};
#endif // !SERIALIZABLE_H

