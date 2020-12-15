#include "pch.h"
#include "CppUnitTest.h"
#include "../11.1/11.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest111
{
	TEST_CLASS(UnitTest111)
	{
	public:

		TEST_METHOD(TestMethod1)
		{

			ifstream stream("t.txt");
			int count = 0;
			char* FileName = 0;
			if (stream.is_open())
			{
				count = minpluus(FileName);
				stream.close();
			}
			Assert::AreEqual(count, 0);
		}
	};
};