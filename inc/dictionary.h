#include <string>

class Dictionary
{
public:
	dictionary(const std::string & filename);
	~dictionary();

	void check(const std::string & word) const;
};