#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

const long DEALS_NUM=100000;
const long PARTIES_NUM=1000;
const long MIN_DEAL=8000000;
const long MAX_DEAL=12000000;
const double PERCENT_LONG=0.6;
const double STARTING_PRICE=1.4;

struct counterParties{
	double hazardRate;
	int dealProbability;
	long netDeal;
};

void setupCounterparties(counterParties *cp);
void setupDeals(long *deals);

double randomUniform();
void log(string logI);

int main(void)
{
	cout<<endl<<"start";
	counterParties cp[PARTIES_NUM];
	long deals[DEALS_NUM];
	setupCounterparties(cp);
	setupDeals(deals);
	cout<<endl<<"end";
	return 0;
}

void setupCounterparties(counterParties *cp){

	int partiesFifth=PARTIES_NUM/5;
	for (int j=0;j<5;j++)
	{
		double thisHazard=0.02*(1+j);
		double thisDealProb=(double(j+1)/31);
		int startCount=partiesFifth*j;
		for (long i=0;i<partiesFifth;i++)
		{
			cp[startCount+i].hazardRate=thisHazard;
			cp[startCount+i].dealProbability=thisDealProb;
		}
		log("hello");
	}
}

void setupDeals(long *deals){
	long dealSpread=MAX_DEAL-MIN_DEAL;
	for (long i=0;i<DEALS_NUM;i++)
	{
		//get absolute value of deal
		long dealSize=MIN_DEAL+randomUniform()*dealSpread;
		//adjust if short
		if (randomUniform()>PERCENT_LONG)dealSize=(-dealSize);
	}
}

void log(string logI){
	cout<<endl<<logI;
}

void allocateDeals(counterParties *cp,long *deals){
	//for (long i=0)

}

double randomUniform(){
	return double(rand())/double(RAND_MAX);
}
