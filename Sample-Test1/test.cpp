#include "gtest/gtest.h"
#include "Lotto.h"
#include "UserMock.h"
#include "RandomEngineMock.h"

struct Mocks : public ::testing::Test
{
protected:
	std::unique_ptr<testing::NiceMock<RandomEngineMock>> randomEngineMock{ std::make_unique<testing::NiceMock<RandomEngineMock>>() };
	std::unique_ptr<testing::NiceMock<UserMock>> userMock{ std::make_unique<testing::NiceMock<UserMock>>() };
};

struct LottoTests : public Mocks
{
protected:
	Lotto createSut()
	{
		return Lotto(std::move(randomEngineMock), std::move(userMock));
	}
};


TEST_F(LottoTests, testWithAllNumbersGuessedWrong)
{
	Numbers playerNumbers = Numbers{ 2,5,6,2,3,8 };
	Numbers randomNumbers = Numbers{ 3,6,1,0,2,5 };
	EXPECT_CALL(*randomEngineMock, GetUniqueRandomNumbers(::testing::_, ::testing::_, ::testing::_)).Times(1).WillOnce(testing::Return(randomNumbers));
	EXPECT_CALL(*userMock, GetUserNumbers(::testing::_)).Times(1).WillOnce(testing::Return(playerNumbers));
	Lotto lotto = createSut();
	Results result = lotto.GetResult();
	EXPECT_EQ(result.correctNumbers, Numbers{});
	EXPECT_EQ(result.playerNumbers, playerNumbers);
	EXPECT_EQ(result.randomNumbers, randomNumbers);
}