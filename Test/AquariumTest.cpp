/**
 * @file AquariumTest.cpp
 * @author Quinton Strausbaugh
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <wx/filename.h>
#include <regex>
#include <string>
#include <fstream>
#include <streambuf>
#include <Aquarium.h>
#include <Item.h>
#include <FishBeta.h>
#include <FishGoldeen.h>
#include <FishNemo.h>
#include <FishMagikarp.h>
#include <DecorCastle.h>

using namespace std;

// Random seed number
const unsigned int RandomSeed = 1238197374;

class AquariumTest : public ::testing::Test {
protected:
    /**
     * Create a path to a place to put temporary files
     */
     wxString TempPath()
    {
         // Creat a temporary filename we can use
         auto path = wxFileName::GetTempDir() + L"/aquarium";
         if (!wxFileName::DirExists(path))
         {
             wxFileName::Mkdir(path);
         }

         return path;
    }

    /**
     * Read a file into a wstring and return it.
     * @param filename Name of the file to read
     * @return File contents
     */
     wstring ReadFile(const wxString &filename)
    {
         ifstream t(filename.ToStdString());
         wstring str((istreambuf_iterator<char>(t)),
                     istreambuf_iterator<char>());

         return str;
    }

    /**
     * Test to ensure an aquarium .aqua file is empty
     * @param filename The name of the xml file
     */
     void TestEmpty(wxString filename)
    {
         cout << "Temp file: " << filename <<endl;

         auto xml = ReadFile(filename);
         cout << xml << endl;

        ASSERT_TRUE(regex_search(xml, wregex(L"<\\?xml.*\\?>")));
        ASSERT_TRUE(regex_search(xml, wregex(L"<aqua/>")));
    }

    /**
    *  Populate an aquarium with three Beta fish
    * @param aquarium The aquarium these three betas are members of
    */
    void PopulateThreeBetas(Aquarium *aquarium)
    {
        aquarium->GetRandom().seed(RandomSeed);

        auto fish1 = make_shared<FishBeta>(aquarium);
        aquarium->Add(fish1);
        fish1->SetLocation(100, 200);
//        fish1->SetSpeedX(10);
//        fish1->SetSpeedY(10);

        auto fish2 = make_shared<FishBeta>(aquarium);
        aquarium->Add(fish2);
        fish2->SetLocation(400, 400);
//        fish2->SetSpeedX(20);
//        fish2->SetSpeedY(20);

        auto fish3 = make_shared<FishBeta>(aquarium);
        aquarium->Add(fish3);
        fish3->SetLocation(600, 100);
//        fish3->SetSpeedX(30);
//        fish3->SetSpeedY(30);
    }

    /**
    *  Populate an aquarium with all types of fish
    * @param aquarium The aquarium these items are apart of
    */
    void PopulateAllTypes(Aquarium *aquarium)
    {
        aquarium->GetRandom().seed(RandomSeed);

        auto fish_beta = make_shared<FishBeta>(aquarium);
        aquarium->Add(fish_beta);
        fish_beta->SetLocation(200, 200);
//        fish_beta->SetSpeedX(10);
//        fish_beta->SetSpeedY(10);

        auto fish_goldeen = make_shared<FishGoldeen>(aquarium);
        aquarium->Add(fish_goldeen);
        fish_goldeen->SetLocation(300, 300);
//        fish_goldeen->SetSpeedX(20);
//        fish_goldeen->SetSpeedY(20);

        auto fish_magikarp = make_shared<FishMagikarp>(aquarium);
        aquarium->Add(fish_magikarp);
        fish_magikarp->SetLocation(400, 400);
//        fish_magikarp->SetSpeedX(30);
//        fish_magikarp->SetSpeedY(30);

        auto fish_nemo = make_shared<FishNemo>(aquarium);
        aquarium->Add(fish_nemo);
        fish_nemo->SetLocation(500,500);
//        fish_nemo->SetSpeedX(40);
//        fish_nemo->SetSpeedY(40);

        auto castle = make_shared<DecorCastle>(aquarium);
        aquarium->Add(castle);
        castle->SetLocation(200, 600);
    }

    /**
     * Tests if the three fish are saved into the xml file
     * @param filename The filename of the xml file is saved into
     */
    void TestThreeBetas(wxString filename)
    {
        cout << "Temp file: " << filename << endl;

        auto xml = ReadFile(filename);
        cout << xml << endl;

        // Ensure three items
        ASSERT_TRUE(regex_search(xml, wregex(L"<aqua><item.*<item.*<item.*</aqua>")));

        // Ensure the positions are correct
        ASSERT_TRUE(regex_search(xml, wregex(L"<item x=\"100\" y=\"200\" x-speed=\"34\\.6892\" y-speed=\"50\"")));
        ASSERT_TRUE(regex_search(xml, wregex(L"<item x=\"400\" y=\"400\" x-speed=\"40\\.6032\" y-speed=\"50\"")));
        ASSERT_TRUE(regex_search(xml, wregex(L"<item x=\"600\" y=\"100\" x-speed=\"40\\.6797\" y-speed=\"50\"")));

        // Ensure the types are correct
        ASSERT_TRUE(regex_search(xml,
                    wregex(L"<aqua><item.* type=\"beta\"/><item.* type=\"beta\"/><item.* type=\"beta\"/></aqua>")));
    }

    /**
     * Tests if all of the items in the aquarium are saving correctly
     * @param filename The name of the xml file
     */
     void TestAllTypes(wxString filename)
    {
         cout << "File Name: " << filename << endl;

         auto xml = ReadFile(filename);
         cout << xml << endl;

        // Ensure five items
        ASSERT_TRUE(regex_search(xml, wregex(L"<aqua><item.*<item.*<item.*<item.*<item.*</aqua>")));

        // Ensure the positions are correct
        ASSERT_TRUE(regex_search(xml, wregex(L"<item x=\"200\" y=\"200\" x-speed=\"34\\.6892\" y-speed=\"50\"")));
        ASSERT_TRUE(regex_search(xml, wregex(L"<item x=\"300\" y=\"300\" x-speed=\"100\" y-speed=\"75\"")));
        ASSERT_TRUE(regex_search(xml, wregex(L"<item x=\"400\" y=\"400\" x-speed=\"40\\.6797\" y-speed=\"11\"")));
        ASSERT_TRUE(regex_search(xml, wregex(L"<item x=\"500\" y=\"500\" x-speed=\"42\\.1756\" y-speed=\"100\"")));
        ASSERT_TRUE(regex_search(xml, wregex(L"<item x=\"200\" y=\"600\"")));

        // Ensure the types are correct
        ASSERT_TRUE(regex_search(xml, wregex(L"<aqua>"
                                        "<item.* type=\"beta\"/>"
                                        "<item.* type=\"goldeen\"/>"
                                        "<item.* type=\"magikarp\"/>"
                                        "<item.* type=\"nemo\"/>"
                                        "<item.* type=\"castle\"/>"
                                        "</aqua>")));
    }

};

TEST_F(AquariumTest, Construct){
    Aquarium aquarium;
}

TEST_F(AquariumTest, HitTest) {
    Aquarium aquarium;

    ASSERT_EQ(aquarium.HitTest(100, 200), nullptr) <<
                                                   L"Testing empty aquarium";

    shared_ptr<FishBeta> fish1 = make_shared<FishBeta>(&aquarium);
    aquarium.Add(fish1);
    fish1->SetLocation(100, 200);

    ASSERT_TRUE(aquarium.HitTest(100, 200) == fish1) <<
                                                     L"Testing fish at 100, 200";
}

TEST_F(AquariumTest, DuplicateTest) {
    Aquarium aquarium;

    shared_ptr<FishBeta> fish1 = make_shared<FishBeta>(&aquarium);
    aquarium.Add(fish1);
    fish1->SetLocation(100,200);
    shared_ptr<FishBeta> fish2 = make_shared<FishBeta>(&aquarium);
    aquarium.Add(fish2);
    fish2->SetLocation(100,200);

    ASSERT_EQ(aquarium.HitTest(100,200), fish2);
}

TEST_F(AquariumTest, Save) {
    // Create path
    auto path = TempPath();
    // Create aquarium
    Aquarium aquarium;
    aquarium.GetRandom().seed(RandomSeed);
    //
    // First test, saving an empty aquarium
    //
    auto file1 = path + L"/test1.aqua";
    aquarium.Save(file1);

    // test if the file is empty
    TestEmpty(file1);

    //
    // Now populate the aquarium
    //

    PopulateThreeBetas(&aquarium);

    auto file2 = path + L"/test2.aqua";
    aquarium.Save(file2);

    TestThreeBetas(file2);

    //
    // Test all types
    //
    Aquarium aquarium3;
    PopulateAllTypes(&aquarium3);

    auto file3 = path + L"/test3.aqua";
    aquarium3.Save(file3);

    TestAllTypes(file3);
}

TEST_F(AquariumTest, Clear) {
    // Create aquarium to fill and leave empty
    Aquarium aquarium;

    // Populate the entire aquarium1
    PopulateAllTypes(&aquarium);

    // Clear the members out of aquarium1
    aquarium.Clear();

    // Test the locations as false for x and y coordinates of fish populated
    ASSERT_FALSE(aquarium.HitTest(200,200));
    ASSERT_FALSE(aquarium.HitTest(300,300));
    ASSERT_FALSE(aquarium.HitTest(400,400));
    ASSERT_FALSE(aquarium.HitTest(500,500));
    ASSERT_FALSE(aquarium.HitTest(200,600));
}

TEST_F(AquariumTest, Load) {
    // Create a path to temporary files
    auto path = TempPath();

    // Create an aquarium
    Aquarium aquarium;
    Aquarium aquarium2;

    //
    // First test, saving an empty aquarium
    //
    auto file1 = path + L"/test1.aqua";
    aquarium.Save(file1);

    TestEmpty(file1);

    aquarium2.Load(file1);
    aquarium2.Save(file1);
    TestEmpty(file1);

    //
    // Now populate the aquarium
    //

    PopulateThreeBetas(&aquarium);

    auto file2 = path + L"/test2.aqua";
    aquarium.Save(file2);

    TestThreeBetas(file2);

    aquarium2.Load(file2);
    aquarium2.Save(file2);
    TestThreeBetas(file2);

    //
    // Test all types
    //
    Aquarium aquarium3;
    PopulateAllTypes(&aquarium3);

    auto file3 = path + L"/test3.aqua";
    aquarium3.Save(file3);

    TestAllTypes(file3);

    aquarium2.Load(file3);
    aquarium2.Save(file3);
    TestAllTypes(file3);
}