#include <iostream>
#include <cppunit/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include "quaternion.h"
using namespace std;
using namespace phy;
class Test:public CPPUNIT_NS::TestCase{
	CPPUNIT_TEST_SUITE(Test);
	CPPUNIT_TEST(testHelloWorld);
	CPPUNIT_TEST(testquaternionadd);
	CPPUNIT_TEST_SUITE_END();
	public:
	void setUp(void){}
	void tearDown(void){}
	protected:
	void testHelloWorld(void){std::cout<<"hello"<<std::endl;}
	void testquaternionadd(){
		Quaternion q1(1,2,3,4);
		//cout<<q1.r<<","<<q1.i<<","<<q1.j<<","<<q1.k<<endl;
		q1+=q1;
		//cout<<q1.r<<","<<q1.i<<","<<q1.j<<","<<q1.k<<endl;
		q1 = q1+q1;
		//cout<<q1.r<<","<<q1.i<<","<<q1.j<<","<<q1.k<<endl;
		bool flag = false;
	
		if(q1.r==4&&q1.i==8&&q1.j==12&&q1.k==16) flag=true;
		//cout<<q1.r<<q1.i<<q1.j<<q1.k<<endl;
		CPPUNIT_ASSERT_EQUAL(flag,true);
	}
};

CPPUNIT_TEST_SUITE_REGISTRATION(Test);
int main(int argc, char**argv){
	 CPPUNIT_NS::TestResult controller;
	 CPPUNIT_NS::TestResultCollector result;
	 controller.addListener(&result);

	 CPPUNIT_NS::BriefTestProgressListener progress;
	 controller.addListener(&progress);
	 CPPUNIT_NS::TestRunner runner;
	 runner.addTest(CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest());
	 runner.run(controller);
	 return result.wasSuccessful() ?0:1;
}

