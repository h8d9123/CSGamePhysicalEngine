#include <iostream>
#include <cppunit/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include "vector3.h"

class Test:public CPPUNIT_NS::TestCase{
	CPPUNIT_TEST_SUITE(Test);
	CPPUNIT_TEST(testHelloWorld);
	CPPUNIT_TEST(testVector3Add);
	CPPUNIT_TEST_SUITE_END();
	public:
	void setUp(void){}
	void tearDown(void){}
	protected:
	void testHelloWorld(void){std::cout<<"hello"<<std::endl;}
	void testVector3Add(){
		phy::Vector3 v(1,2,3);
		v+=v;
		bool flag = false;
		for(int i=0;i<3;i++){
			if(v.x==2 && v.y == 4 && v.z==6)
				flag=true;
		}
		CPPUNIT_ASSERT(flag);
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

