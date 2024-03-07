#include "gtest/gtest.h"
#include "Lotto.h"
#include "UserMock.h"
#include "RandomEngineMock.h"

struct LottoTests : public ::testing::Test
{
	Lotto createSut()
	{
		std::unique_ptr<RandomEngineMock> randomEngineMock;
		std::unique_ptr<UserMock> userMock;
		return Lotto(std::move(randomEngineMock), std::move(userMock));
	}
};


TEST_F(LottoTests, TestName) 
{

}