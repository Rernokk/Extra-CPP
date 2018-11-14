#ifndef CYLINDERTYPE
#define CYLINDERTYPE


class cylinderType : public circleType
{
	public:

		cylinderType();
		cylinderType(double radius, double height);

		double getVolume();
		double getSurfaceArea();
		double getHeight();

		void calculateVolume();
		void calculateSurfaceArea();
		
		void setHeight(double h);
		void setBaseRadius(double r);
		//void setCenterBase(); //?

	private:
		double volume;
		double surfaceArea;
		double height;
		
};
#endif // !CIRCLETYPE
