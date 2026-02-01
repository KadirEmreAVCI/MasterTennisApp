#ifndef DBITEMTEST_H
#define DBITEMTEST_H

// Standard Headers
#include <vector>
#include <memory>

// External Headers 
#include <gtest/gtest.h>
#include <gmock/gmock.h>

// Project Headers
#include "IDatabase.h"
#include "Match.h"
#include "Tournament.h"
#include "Organization.h"
#include "Profile.h"
#include "Utility.h"

class MockDatabase : public IDatabase {
public:
    MockDatabase() = default;
    MOCK_METHOD(unsigned, GetItemCount, (const std::string& sTable), (const, override));
    MOCK_METHOD(bool, InsertItem, (const std::string& sTable, const std::string& sColumnNames, const std::string& sValues), (const, override));
    MOCK_METHOD(bool, EditItem, (const std::string& sTable, (const QMap<QString, QVariant>& columnValues), unsigned uiID), (const, override));
    MOCK_METHOD(bool, DeleteItem, (const std::string& sTable, const std::string& sColumn, std::string sVal), (const, override));
    MOCK_METHOD(std::string, RetrieveValue, (const std::string& sTable, const std::string& sColumn, unsigned uiRowIdx), (const, override));
    MOCK_METHOD(std::string, RetrieveValue, (const std::string& sTable, const std::string& sColumn, const std::string& sCondColumn, const std::string& sCond, unsigned uiRowIdx), (const, override));
};

class DBItemTest : public testing::Test {
protected:
	void SetUp()
	{
        m_spMockDatabase = std::make_shared<MockDatabase>();
		DBItem::SetDatabase(m_spMockDatabase);
	}
    void TearDown() override
    {
        m_spMockDatabase = nullptr;
    }
    std::vector<std::string> Deserialize(const std::string& sSerialized)
    {
        return utility::Deserialize(sSerialized);
    }
    std::shared_ptr<MockDatabase> m_spMockDatabase;
    Match m_Match{ 1, 0, "U", "Final 16", "Mustafa Yavuz Kirli", "", QDate{2024, 2, 11}, QTime{18, 0, 0}, {Set{Score(6, 0)}, Set{Score(6, 1)}, Set{Score(1, 6)}, Set{Score(7, 5)}}};
    Tournament m_Tournament{7, 0, 0, "Karayollari", "2023 Summer", "Ilk Turnuvam", "Double Men", "Alp Emre Kamis", 36, false, false, 3};
    Organization m_Organization{3, "Karayollari", "/pp_addr", std::vector<std::string>{"A", "B", "C"}};
    Profile m_Profile{2, "Kadir Emre Avci", "/pp_addr", Gender::Male};
};

#endif