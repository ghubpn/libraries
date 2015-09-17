/*
Dynamically add and remove experimental units (vector?)
*/

#ifndef SAMPLE_H
#define SAMPLE_H

/* standard includes */
#include <vector>

/* Sample */
class Sample {
	
	/* ExpUnit */
	class ExpUnit {
		private:
			double  response;
			int     predCount;
			double* predictors;
		public:
			ExpUnit( int factors );
			void setResponse( double y );
			void setPredictor( int i, double x );
			
	};
	
	private:
		vector<ExpUnit> data;
		int 
	
	public:
		Sample( int factors );
	
};

#endif