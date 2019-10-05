#include "pch.h"
#include "CppUnitTest.h"
#include "Item.h"
#include "FishBeta.h"
#include "Aquarium.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
	class CFishBetaMock : public CFishBeta
	{

	};

	TEST_CLASS(CFishBetaTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
	};
}