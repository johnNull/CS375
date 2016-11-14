class point{
	public: int x;
	public: int y;
	public: point(int x, int y){
		this->x = x;
		this->y = y;
	};
	bool operator >(point p2){return(x > p2.x);};
	bool operator <(point p2){return(x < p2.x);};
};
