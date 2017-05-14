#include "testcommon.h"

double rosenbrock(RealGenotype &g, void *par) {
	double dx1 = g.gene[0]*g.gene[0]-g.gene[1];
	double dx2 = 1.0 - g.gene[0];
	return 100*dx1*dx1+dx2*dx2;
}

void test_rosenbrock(GAOptions opt, bool &converged, int &iter, double &bestFitness, float &exTime) {
	cout << "================================"<<endl;
	cout << "        Rosenbrock benchmark" << endl;
	cout << "================================"<<endl; 

	float LB[] = {-2048.0, -2048.0},
				UB[] = { 2048.0,  2048.0};

	RealGenotype expMin(2);
	expMin.gene[0] = 1.0;
	expMin.gene[1] = 1.0;

	RealGen ga(200, 2, LB, UB, opt);
	ga.setFitnessFunction(rosenbrock, NULL);

	testRealGen(ga, 50000, 1e-4, expMin, converged, iter, bestFitness, exTime);
}