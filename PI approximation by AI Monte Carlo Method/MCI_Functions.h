double Uniform_Mersenne(double Low, double Up) {
	random_device seed;
	mt19937 gen(seed());
	uniform_real_distribution<double> dist(Low, Up);
	return dist(gen);
}

void MCI::PointsGenerating() {
	for (int i = 0; i < SamplesQuantity; i++) {
		for (int j = 0; j < Dimension; j++) {
			Points[i].AxisN.push_back ( Uniform_Mersenne(integrationLimitStart, integrationLimitStop));
		}
	}
}

double MCI::ValueCalculating(vector<double> x) {
	double Value{ 0 };
	
		for (int j = 0; j < Dimension; j++) {
			Value += (x[j]*x[j]);
		}
	
	return Value;
}

void MCI::FunctionValueCalculating() {
	for (int i = 0; i < Points.size(); i++) {
	
			Points[i].Value = ValueCalculating(Points[i].AxisN);
		
	}
}

void MCI::PointsChecking() {
	for (int i = 0; i < Points.size(); i++) {
		for (int j = 1; j < Points[i].AxisN.size(); j++) {
			if (Points[i].AxisN[j] > 0 && Points[i].AxisN[j] <= Points[i].Value) {
				Hits++;
			}
			else
				if (Points[i].AxisN[j] < 0 && Points[i].AxisN[j] >= Points[i].Value) {
					Hits--;
				}
		}
}
	
}
void MCI::CircleSampling() {
	double Radius = ((integrationLimitStop-integrationLimitStart) / 2);
	double Circle{ 0 };
	for (int i = 0; i < Points.size(); i++) {
		double Circle = (((Points[i].AxisN[0] - Radius)*(Points[i].AxisN[0] - Radius)) + ((Points[i].AxisN[1] - Radius)*(Points[i].AxisN[1] - Radius)));
		if (Circle <= (Radius * Radius)) {
			Hits++;
		}
		
	}

}

void MCI::MainFunctionCalling() {
	PointsGenerating();
	//FunctionValueCalculating();  //function integrating
	//PointsChecking();

	CircleSampling();   //Circle area approximating

	double RectangleArea = abs(integrationLimitStop - integrationLimitStart)*abs(ValueLimitStop - ValueLimitStart);
	double Integral = (RectangleArea * (Hits / SamplesQuantity));

	double Pi = Integral / (0.5*0.5);
	cout << "Integral calculated by AI: " << Integral << "\napproximated Pi: "<<Pi<<"\n"<<"For "<<SamplesQuantity<<" Samples\n";
}