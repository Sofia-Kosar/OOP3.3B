#include "pch.h"
#include "CppUnitTest.h"
#include "../OOP3.3B/LongLong.h"
#include "../OOP3.3B/Pair.h"
#include "../OOP3.3B/LongLong.cpp"
#include "../OOP3.3B/Pair.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest33В
{
	TEST_CLASS(UnitTest33В)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Pair pair1(10, 20);
			Pair pair2(5, 15);
			Pair expected_sum(15, 35);

			// Act
			Pair actual_sum = pair1 + pair2;

			// Assert
			Assert::IsTrue(actual_sum == expected_sum);
		}
	};
}
