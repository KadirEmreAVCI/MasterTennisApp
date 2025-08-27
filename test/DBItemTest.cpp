#include "DBItemTest.h"

TEST_F(DBItemTest, DeleteMatchFromDB)
{
    EXPECT_CALL(*m_spMockDatabase, DeleteItem("Match", "ID", "1")).Times(1).WillOnce(testing::Return(true));
    
    m_Match.DeleteFromDB();
}
TEST_F(DBItemTest, DeleteTournamentFromDB)
{
    EXPECT_CALL(*m_spMockDatabase, DeleteItem("Tournament", "ID", "7")).Times(1).WillOnce(testing::Return(true));
    
    m_Tournament.DeleteFromDB();
}
TEST_F(DBItemTest, DeleteOrganizationFromDB)
{
    EXPECT_CALL(*m_spMockDatabase, DeleteItem("Organization", "ID", "3")).Times(1).WillOnce(testing::Return(true));
    
    m_Organization.DeleteFromDB();
}
TEST_F(DBItemTest, DeleteProfileFromDB)
{
    EXPECT_CALL(*m_spMockDatabase, DeleteItem("Profile", "ID", "2")).Times(1).WillOnce(testing::Return(true));
    
    m_Profile.DeleteFromDB();       
}
TEST_F(DBItemTest, DeserializingString)
{
    const std::string sSerialized = "A,B,C,D,E";
    const std::vector<std::string> vecExpected{ "A", "B", "C", "D", "E" };
    const auto vecActual = Deserialize(sSerialized);
    
    EXPECT_EQ(vecExpected, vecActual);
}
TEST_F(DBItemTest, DeserializingEmptyString)
{
    const std::string sSerialized = "";
    const std::vector<std::string> vecExpected{};
    const auto vecActual = Deserialize(sSerialized);
    
    EXPECT_EQ(vecExpected, vecActual);
}
TEST_F(DBItemTest, EditMatchInDB)
{
    m_Match = Match{ m_Match.GetID(), 0, "U", "Final 16", "Baris Sahin", "", QDate{2024, 2, 11}, QTime{18, 0, 0}, {Set{Score(6, 0)}, Set{Score(6, 1)}, Set{Score(1, 6)}, Set{Score(7, 5)}}};
    
    EXPECT_CALL(*m_spMockDatabase, EditItem("Match", testing::_, 1)).Times(1).WillOnce(testing::Return(true));
    
    m_Match.EditInDB();
}
TEST_F(DBItemTest, EditTournamentInDB)
{
    m_Tournament = Tournament{m_Tournament.GetID(), 0, 0, "Ahal Teke", "2023 Summer", "Ilk Turnuvam", "Double Men", "Alp Emre Kamis", 36, false, false, 3};
    
    EXPECT_CALL(*m_spMockDatabase, EditItem("Tournament", testing::_, 7)).Times(1).WillOnce(testing::Return(true));
    
    m_Tournament.EditInDB();
}
TEST_F(DBItemTest, EditOrganizationInDB)
{
    m_Organization = Organization{m_Organization.GetID(), "Karayollari", "/pp_addr_new", std::vector<std::string>{"A", "B", "C"}};
    
    EXPECT_CALL(*m_spMockDatabase, RetrieveValue("Organization", "ImageFileName", "ID", std::to_string(m_Organization.GetID()), 0)).Times(1).WillOnce(testing::Return("/pp_addr"));
    EXPECT_CALL(*m_spMockDatabase, EditItem("Organization", testing::_, 3)).Times(1).WillOnce(testing::Return(true));
    
    m_Organization.EditInDB();
}
TEST_F(DBItemTest, EditProfileInDB)
{
    m_Profile = Profile{ m_Profile.GetID(), "Emre Avci", "/pp_addr", Gender::Male};
    
    EXPECT_CALL(*m_spMockDatabase, RetrieveValue("Profile", "PPAddress", "ID", std::to_string(m_Profile.GetID()), 0)).Times(1).WillOnce(testing::Return("/pp_addr"));
    EXPECT_CALL(*m_spMockDatabase, EditItem("Profile", testing::_, 2)).Times(1).WillOnce(testing::Return(true));
    
    m_Profile.EditInDB();
}
TEST_F(DBItemTest, LoadMatchFromDB)
{
    Match m{};

    EXPECT_CALL(*m_spMockDatabase, RetrieveValue("Match", "ID", 0)).Times(1).WillOnce(testing::Return(std::to_string(m_Match.GetID())));
    EXPECT_CALL(*m_spMockDatabase, RetrieveValue("Match", "TournamentID", "ID", std::to_string(m_Match.GetID()), 0)).Times(1).WillOnce(testing::Return(std::to_string(0)));
    EXPECT_CALL(*m_spMockDatabase, RetrieveValue("Match", "Statu", "ID", std::to_string(m_Match.GetID()), 0)).Times(1).WillOnce(testing::Return("U"));
    EXPECT_CALL(*m_spMockDatabase, RetrieveValue("Match", "Stage", "ID", std::to_string(m_Match.GetID()), 0)).Times(1).WillOnce(testing::Return("Final 16"));
    EXPECT_CALL(*m_spMockDatabase, RetrieveValue("Match", "Opponent1", "ID", std::to_string(m_Match.GetID()), 0)).Times(1).WillOnce(testing::Return("Mustafa Yavuz Kirli"));
    EXPECT_CALL(*m_spMockDatabase, RetrieveValue("Match", "Opponent2", "ID", std::to_string(m_Match.GetID()), 0)).Times(1).WillOnce(testing::Return(""));
    EXPECT_CALL(*m_spMockDatabase, RetrieveValue("Match", "Date", "ID", std::to_string(m_Match.GetID()), 0)).Times(1).WillOnce(testing::Return(QDate{2024, 2, 11}.toString().toStdString()));
    EXPECT_CALL(*m_spMockDatabase, RetrieveValue("Match", "Time", "ID", std::to_string(m_Match.GetID()), 0)).Times(1).WillOnce(testing::Return(QTime{18, 0, 0}.toString().toStdString()));
    EXPECT_CALL(*m_spMockDatabase, RetrieveValue("Match", "Sets", "ID", std::to_string(m_Match.GetID()), 0)).Times(1).WillOnce(testing::Return("6-0\n6-1\n1-6\n7-5"));

	m.LoadFromDB(m.GetID());

    EXPECT_EQ(m, m_Match);
}
TEST_F(DBItemTest, LoadTournamentFromDB)
{
    Tournament t{};

    EXPECT_CALL(*m_spMockDatabase, RetrieveValue("Tournament", "ID", 0)).Times(1).WillOnce(testing::Return(std::to_string(m_Tournament.GetID())));
    EXPECT_CALL(*m_spMockDatabase, RetrieveValue("Tournament", "ProfileID", "ID", std::to_string(m_Tournament.GetID()), 0)).Times(1).WillOnce(testing::Return(std::to_string(0)));
    EXPECT_CALL(*m_spMockDatabase, RetrieveValue("Tournament", "OrganizationID", "ID", std::to_string(m_Tournament.GetID()), 0)).Times(1).WillOnce(testing::Return(std::to_string(0)));
    EXPECT_CALL(*m_spMockDatabase, RetrieveValue("Tournament", "Season", "ID", std::to_string(m_Tournament.GetID()), 0)).Times(1).WillOnce(testing::Return("2023 Summer"));
    EXPECT_CALL(*m_spMockDatabase, RetrieveValue("Tournament", "Category", "ID", std::to_string(m_Tournament.GetID()), 0)).Times(1).WillOnce(testing::Return("Ilk Turnuvam"));
    EXPECT_CALL(*m_spMockDatabase, RetrieveValue("Tournament", "Type", "ID", std::to_string(m_Tournament.GetID()), 0)).Times(1).WillOnce(testing::Return("Double Men"));
    EXPECT_CALL(*m_spMockDatabase, RetrieveValue("Tournament", "Teammate", "ID", std::to_string(m_Tournament.GetID()), 0)).Times(1).WillOnce(testing::Return("Alp Emre Kamis"));
    EXPECT_CALL(*m_spMockDatabase, RetrieveValue("Tournament", "Participant", "ID", std::to_string(m_Tournament.GetID()), 0)).Times(1).WillOnce(testing::Return(std::to_string(36)));
    EXPECT_CALL(*m_spMockDatabase, RetrieveValue("Tournament", "Locked", "ID", std::to_string(m_Tournament.GetID()), 0)).Times(1).WillOnce(testing::Return(std::to_string(0)));
    EXPECT_CALL(*m_spMockDatabase, RetrieveValue("Tournament", "ThirdPlaceGameAvailable", "ID", std::to_string(m_Tournament.GetID()), 0)).Times(1).WillOnce(testing::Return(std::to_string(0)));
    EXPECT_CALL(*m_spMockDatabase, RetrieveValue("Tournament", "SetsBestOf", "ID", std::to_string(m_Tournament.GetID()), 0)).Times(1).WillOnce(testing::Return(std::to_string(3)));

    t.LoadFromDB(t.GetID());

    EXPECT_EQ(t, m_Tournament);
}
TEST_F(DBItemTest, LoadOrganizationFromDB)
{
    Organization org{};

    EXPECT_CALL(*m_spMockDatabase, RetrieveValue("Organization", "ID", 0)).Times(1).WillOnce(testing::Return(std::to_string(m_Organization.GetID())));
    EXPECT_CALL(*m_spMockDatabase, RetrieveValue("Organization", "Name", "ID", std::to_string(m_Organization.GetID()), 0)).Times(1).WillOnce(testing::Return("Karayollari"));
    EXPECT_CALL(*m_spMockDatabase, RetrieveValue("Organization", "ImageFileName", "ID", std::to_string(m_Organization.GetID()), 0)).Times(1).WillOnce(testing::Return("/pp_addr"));
    EXPECT_CALL(*m_spMockDatabase, RetrieveValue("Organization", "Categories", "ID", std::to_string(m_Organization.GetID()), 0)).Times(1).WillOnce(testing::Return("A,B,C"));

    org.LoadFromDB(org.GetID());

    EXPECT_EQ(org, m_Organization);
}
TEST_F(DBItemTest, LoadProfileFromDB)
{
    Profile p{};

    EXPECT_CALL(*m_spMockDatabase, RetrieveValue("Profile", "ID", 0)).Times(1).WillOnce(testing::Return(std::to_string(m_Profile.GetID())));
    EXPECT_CALL(*m_spMockDatabase, RetrieveValue("Profile", "FullName", "ID", std::to_string(m_Profile.GetID()), 0)).Times(1).WillOnce(testing::Return("Kadir Emre Avci"));
    EXPECT_CALL(*m_spMockDatabase, RetrieveValue("Profile", "Gender", "ID", std::to_string(m_Profile.GetID()), 0)).Times(1).WillOnce(testing::Return("Male"));
    EXPECT_CALL(*m_spMockDatabase, RetrieveValue("Profile", "PPAddress", "ID", std::to_string(m_Profile.GetID()), 0)).Times(1).WillOnce(testing::Return("/pp_addr"));
	
    p.LoadFromDB(p.GetID());

    EXPECT_EQ(p, m_Profile);
}