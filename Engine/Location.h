#pragma once

class Location // default access for struct members is public; class default access for members is private
{
public:
	int x;
	int y;
	void Add(const Location& delta_loc)
	{
		x += delta_loc.x;
		y += delta_loc.y;		
	}

	bool operator==(const Location& rhs) const
	{
		return x == rhs.x && y == rhs.y;
	}

	

	/* My overloaded operator*/
	//bool operator==(Location& loc)
	//{
	//	return (x == loc.x && y == loc.y);
	//}

};

