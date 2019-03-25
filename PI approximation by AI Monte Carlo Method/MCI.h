class Point {
public:
	vector<double> AxisN;
	double Value;
};

class MCI {
public:
	int Dimension{ 2 };
	double SamplesQuantity{ 15000 };

	vector<Point>Points{ SamplesQuantity };
	
	double Hits{ 0 };
	double integrationLimitStart{ 0.0 };
	double integrationLimitStop{ 1.0 };
	double ValueLimitStart{ 0.0 };
	double ValueLimitStop{ 1.0};


void PointsGenerating();
void FunctionValueCalculating();
void PointsChecking();

void CircleSampling();

void MainFunctionCalling();

double ValueCalculating(vector<double> x);
};

