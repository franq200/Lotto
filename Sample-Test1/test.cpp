#include "gtest/gtest.h"
#include "Lotto.h"
#include "UserMock.h"
#include "RandomEngineMock.h"

class LottoTest
{
protected:
	Lotto createSut()
	{
		return Lotto(std::move(randomEngineMock), std::move(userMock));
	}
	std::unique_ptr<testing::NiceMock<RandomEngineMock>> randomEngineMock{ std::make_unique<testing::NiceMock<RandomEngineMock>>() };
	std::unique_ptr<testing::NiceMock<UserMock>> userMock{ std::make_unique<testing::NiceMock<UserMock>>() };
};

struct LottoTestsFixture : public ::testing::Test, public LottoTest
{
};

struct Parameters
{
	std::vector<uint16_t> playerNumbers;
	std::vector<uint16_t> randomNumbers;
	std::vector<uint16_t> correctNumbers;
};

class LottoParameterizedTestFixture : public ::testing::TestWithParam<Parameters>, public LottoTest
{
protected:
	std::vector<uint16_t> playerNumbers;
	std::vector<uint16_t> randomNumbers;
	std::vector<uint16_t> correctNumbers;
};

TEST_P(LottoParameterizedTestFixture, GetResultTest)
{
	Parameters parameters = GetParam();
	
	EXPECT_CALL(*randomEngineMock, GetRandomNumber(testing::_, testing::_)).Times(6)
		.WillOnce(testing::Return(parameters.randomNumbers.at(0)))
		.WillOnce(testing::Return(parameters.randomNumbers.at(1)))
		.WillOnce(testing::Return(parameters.randomNumbers.at(2)))
		.WillOnce(testing::Return(parameters.randomNumbers.at(3)))
		.WillOnce(testing::Return(parameters.randomNumbers.at(4)))
		.WillOnce(testing::Return(parameters.randomNumbers.at(5)));
	EXPECT_CALL(*userMock, GetUserNumber()).Times(6)
		.WillOnce(testing::Return(parameters.playerNumbers.at(0)))
		.WillOnce(testing::Return(parameters.playerNumbers.at(1)))
		.WillOnce(testing::Return(parameters.playerNumbers.at(2)))
		.WillOnce(testing::Return(parameters.playerNumbers.at(3)))
		.WillOnce(testing::Return(parameters.playerNumbers.at(4)))
		.WillOnce(testing::Return(parameters.playerNumbers.at(5)));

	Lotto lotto = createSut();
	Results result = lotto.GetResult();
	std::set<uint16_t> correctNumbersSet(parameters.correctNumbers.begin(), parameters.correctNumbers.end());
	EXPECT_EQ(result.correctNumbers, correctNumbersSet);
	std::set<uint16_t> playerNumbersSet(parameters.playerNumbers.begin(), parameters.playerNumbers.end());
	EXPECT_EQ(result.playerNumbers, playerNumbersSet);
	std::set<uint16_t> randomNumbersSet(parameters.randomNumbers.begin(), parameters.randomNumbers.end());
	EXPECT_EQ(result.randomNumbers, randomNumbersSet);
}

INSTANTIATE_TEST_SUITE_P(LottoTest, LottoParameterizedTestFixture, ::testing::Values(
	Parameters{ { 20, 43, 36, 11, 3, 8 }, { 10, 16, 12, 18, 26, 42 }, {} },
	Parameters{ { 49,5,40,21,3,1 }, { 49,3,41,21,2,1 }, { 21, 1, 49, 3 } },
	Parameters{ { 49,5,42,21,9,1 }, { 49,5,42,21,9,1 }, { 49,1,42,21,9,5 } }
));

TEST_F(LottoTestsFixture, WrongRandomNumbersShouldThrowAnException)
{
	EXPECT_CALL(*randomEngineMock, GetRandomNumber(testing::_, testing::_)).Times(1).WillOnce(testing::Return(50));
	EXPECT_THROW(Lotto lotto = createSut(), std::exception);
}

TEST_F(LottoTestsFixture, WrongUserNumberShouldThrowAnException)
{
	EXPECT_CALL(*userMock, GetUserNumber()).Times(1).WillOnce(testing::Return(0));
	EXPECT_THROW(Lotto lotto = createSut(), std::exception);
}

TEST_F(LottoTestsFixture, UserAddedTheSameNumberSecondTimeAndItShouldAskHimAgain)
{
	std::vector<uint16_t> playerNumbers = { 49,5,42,21,5,9,1 };
	std::vector<uint16_t> randomNumbers = { 49,5,42,21,9,1 };

	EXPECT_CALL(*randomEngineMock, GetRandomNumber(testing::_, testing::_)).Times(6)
		.WillOnce(testing::Return(randomNumbers.at(0)))
		.WillOnce(testing::Return(randomNumbers.at(1)))
		.WillOnce(testing::Return(randomNumbers.at(2)))
		.WillOnce(testing::Return(randomNumbers.at(3)))
		.WillOnce(testing::Return(randomNumbers.at(4)))
		.WillOnce(testing::Return(randomNumbers.at(5)));
	EXPECT_CALL(*userMock, GetUserNumber()).Times(7)
		.WillOnce(testing::Return(playerNumbers.at(0)))
		.WillOnce(testing::Return(playerNumbers.at(1)))
		.WillOnce(testing::Return(playerNumbers.at(2)))
		.WillOnce(testing::Return(playerNumbers.at(3)))
		.WillOnce(testing::Return(playerNumbers.at(4)))
		.WillOnce(testing::Return(playerNumbers.at(5)))
		.WillOnce(testing::Return(playerNumbers.at(6)));

	Lotto lotto = createSut();
}

TEST_F(LottoTestsFixture, TheSameNumberWasDrawnSecondTimeAndItShouldCallTheFunctionOnceMore)
{
	std::vector<uint16_t> playerNumbers = { 49,5,42,21,9,1 };
	std::vector<uint16_t> randomNumbers = { 49,5,42,21,5,9,1 };

	EXPECT_CALL(*randomEngineMock, GetRandomNumber(testing::_, testing::_)).Times(7)
		.WillOnce(testing::Return(randomNumbers.at(0)))
		.WillOnce(testing::Return(randomNumbers.at(1)))
		.WillOnce(testing::Return(randomNumbers.at(2)))
		.WillOnce(testing::Return(randomNumbers.at(3)))
		.WillOnce(testing::Return(randomNumbers.at(4)))
		.WillOnce(testing::Return(randomNumbers.at(5)))
		.WillOnce(testing::Return(randomNumbers.at(6)));
	EXPECT_CALL(*userMock, GetUserNumber()).Times(6)
		.WillOnce(testing::Return(playerNumbers.at(0)))
		.WillOnce(testing::Return(playerNumbers.at(1)))
		.WillOnce(testing::Return(playerNumbers.at(2)))
		.WillOnce(testing::Return(playerNumbers.at(3)))
		.WillOnce(testing::Return(playerNumbers.at(4)))
		.WillOnce(testing::Return(playerNumbers.at(5)));
	Lotto lotto = createSut();
}