class Matrix{
public:
	Matrix(int row, int col)
		:_row(row), _col(col)
	{
		//dist of resources
		_pmat = new double[row*col];
	}
	~Matrix()//only use new is necessary
	{
		//free the resources
		delete [] _pmat;
	}
private:
	int _row, _col;
	double* _pmat;
};