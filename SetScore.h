#pragma once
#include <utility>
enum class SetType{
	eRegular = 1,
	eSetWithTiebreak = 2,
	eSuperTiebreak = 3
};
class SetScore{
public:
	using enum SetType;
	SetScore(SetType type, unsigned int uiPlayerScore, unsigned int uiOpponentScore, unsigned int uiPlayerTiebreakScore = -1, unsigned int uiOpponentTiebreakScore = -1);
	std::pair<unsigned int, unsigned int> getSetScore() const;
	SetType getSetType() const;
private:
	SetType m_SetType;
	std::pair<unsigned int, unsigned int> m_Score;
	std::pair<unsigned int, unsigned int> m_TiebreakScore;
};

