#include "SetScore.h"
SetScore::SetScore(SetType type, unsigned int uiPlayerScore, unsigned int uiOpponentScore, unsigned int uiPlayerTiebreakScore, unsigned int uiOpponentTiebreakScore)
{
	m_SetType = type;
	m_Score = std::make_pair(uiPlayerScore, uiOpponentScore);
	if (type == eSetWithTiebreak)
		m_TiebreakScore = std::make_pair(uiPlayerTiebreakScore, uiOpponentTiebreakScore);
}
std::pair<unsigned int, unsigned int> SetScore::getSetScore() const
{
	return m_Score;
}
SetType SetScore::getSetType() const
{
	return m_SetType;
}