#include "gtest/gtest.h"
#include "Lotto.h"
#include "UserMock.h"
#include "RandomEngineMock.h"

using testing::UnorderedElementsAre;


struct LottoTests : public ::testing::Test
{
protected:
	Lotto createSut()
	{
		return Lotto(std::move(randomEngineMock), std::move(userMock));
	}
	std::unique_ptr<testing::NiceMock<RandomEngineMock>> randomEngineMock{ std::make_unique<testing::NiceMock<RandomEngineMock>>() };
	std::unique_ptr<testing::NiceMock<UserMock>> userMock{ std::make_unique<testing::NiceMock<UserMock>>() };
};

// change to parametric gtest 
TEST_F(LottoTests, testWithAllNumbersGuessedWrong)
{
	Numbers playerNumbers = Numbers{ 2,5,6,1,3,8 };
	Numbers randomNumbers = Numbers{ 10, 16, 12, 18, 26, 42};
	EXPECT_CALL(*randomEngineMock, GetUniqueRandomNumbers(::testing::_, ::testing::_, ::testing::_)).Times(1).WillOnce(testing::Return(randomNumbers));
	EXPECT_CALL(*userMock, GetUserNumbers(::testing::_, ::testing::_, ::testing::_)).Times(1).WillOnce(testing::Return(playerNumbers));
	Lotto lotto = createSut();
	Results result = lotto.GetResult();
	EXPECT_EQ(result.correctNumbers, Numbers{});
	EXPECT_EQ(result.playerNumbers, playerNumbers);
	EXPECT_EQ(result.randomNumbers, randomNumbers);
	//UnorderedElementsAre(
}

TEST_F(LottoTests, testWithFewNubersGuessedCorrectly)
{
	Numbers playerNumbers = Numbers{ 49,5,40,21,3,0 };
	Numbers randomNumbers = Numbers{ 49,3,41,21,2,0 };
	Numbers correctNumbers = Numbers{ 21, 0, 49, 3};
	EXPECT_CALL(*randomEngineMock, GetUniqueRandomNumbers(::testing::_, ::testing::_, ::testing::_)).Times(1).WillOnce(testing::Return(randomNumbers));
	EXPECT_CALL(*userMock, GetUserNumbers(::testing::_, ::testing::_, ::testing::_)).Times(1).WillOnce(testing::Return(playerNumbers));
	Lotto lotto = createSut();
	Results result = lotto.GetResult();
	EXPECT_EQ(result.correctNumbers, correctNumbers);
	EXPECT_EQ(result.playerNumbers, playerNumbers);
	EXPECT_EQ(result.randomNumbers, randomNumbers);
}

TEST_F(LottoTests, testWithAllNumbersGuessedCorrectly)
{
	Numbers playerNumbers = Numbers{ 49,5,42,21,9,0 };
	Numbers randomNumbers = Numbers{ 49,5,42,21,9,0 };
	Numbers correctNumbers = Numbers{49,0,42,21,9,5 };
	EXPECT_CALL(*randomEngineMock, GetUniqueRandomNumbers(::testing::_, ::testing::_, ::testing::_)).Times(1).WillOnce(testing::Return(randomNumbers));
	EXPECT_CALL(*userMock, GetUserNumbers(::testing::_, ::testing::_, ::testing::_)).Times(1).WillOnce(testing::Return(playerNumbers));
	Lotto lotto = createSut();
	Results result = lotto.GetResult();
	EXPECT_EQ(result.correctNumbers, correctNumbers);
	EXPECT_EQ(result.playerNumbers, playerNumbers);
	EXPECT_EQ(result.randomNumbers, randomNumbers);
}
// add NOK cases (empty playerNumbers, too many numbers...)
// tests with exceptions (mock exception)