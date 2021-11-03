#include <gtest/gtest.h>
#include <string>

extern "C" {
#include <telephone_info.h>
}

TEST(telephone, validation_number) {
    ASSERT_EQ(IsValidNumber(153, 1234567), true);
    ASSERT_EQ(IsValidNumber(9999, 9999999), true);
    ASSERT_EQ(IsValidNumber(123, 12345678), false);
    ASSERT_EQ(IsValidNumber(12345, 1234567), false);
}

TEST(telephone, create_base) {
    base_t base;
    ASSERT_NE(base.capacity_, 0);            // checking for garbage
    CreateBase(&base);
    ASSERT_EQ(base.telephoneCount_, 0);
    ASSERT_EQ(base.capacity_, 1);
    DeleteBase(&base);
}

TEST(telephone, add_number) {
    base_t base;
    CreateBase(&base);
    Add(NULL, 1, 1234567, "Zakhar");
    ASSERT_EQ(base.telephoneCount_, 0);
    Add(&base, 1, 1234567, "Zakhar");
    ASSERT_EQ(base.telephoneCount_, 1);
    Add(&base, 2, 1234567, "Alex");
    Add(&base, 2, 1236788, "John");
    Add(&base, 7, 1124567, "Boris");
    Add(&base, 7, 2234567, "Ivan");
    ASSERT_EQ(base.telephoneCount_, 5);
    ASSERT_EQ(base.capacity_, 8);
    ASSERT_EQ(base.telephones_[0].networkCode_, 1);
    ASSERT_EQ(base.telephones_[0].number_, 1234567);
    ASSERT_EQ(base.telephones_[0].nameOwner_[0], 'Z');
    ASSERT_EQ(base.telephones_[0].nameOwner_[1], 'a');
    ASSERT_EQ(base.telephones_[0].nameOwner_[2], 'k');
    ASSERT_EQ(base.telephones_[0].nameOwner_[3], 'h');
    ASSERT_EQ(base.telephones_[0].nameOwner_[4], 'a');
    ASSERT_EQ(base.telephones_[0].nameOwner_[5], 'r');
    DeleteBase(&base);
}

TEST(telephone, fillBase) {
    base_t base;
    CreateBase(&base);
    ASSERT_EQ(base.telephoneCount_, 0);
    FillBase(NULL);
    ASSERT_EQ(base.telephoneCount_, 0);
    DeleteBase(&base);
}

TEST(telephone, deleteBase) {
    base_t base;
    CreateBase(&base);
    Add(NULL, 1, 1234567, "Zakhar");
    ASSERT_EQ(base.telephoneCount_, 0);
    Add(&base, 1, 1234567, "Zakhar");
    ASSERT_EQ(base.telephoneCount_, 1);
    Add(&base, 2, 1234567, "Alex");
    Add(&base, 2, 1236788, "John");
    Add(&base, 7, 1124567, "Boris");
    Add(&base, 7, 2234567, "Ivan");
    ASSERT_EQ(base.telephoneCount_, 5);
    ASSERT_EQ(base.capacity_, 8);
    ASSERT_EQ(base.telephones_[0].networkCode_, 1);
    ASSERT_EQ(base.telephones_[0].number_, 1234567);
    ASSERT_EQ(base.telephones_[0].nameOwner_[0], 'Z');
    ASSERT_EQ(base.telephones_[0].nameOwner_[1], 'a');
    ASSERT_EQ(base.telephones_[0].nameOwner_[2], 'k');
    ASSERT_EQ(base.telephones_[0].nameOwner_[3], 'h');
    ASSERT_EQ(base.telephones_[0].nameOwner_[4], 'a');
    ASSERT_EQ(base.telephones_[0].nameOwner_[5], 'r');
    DeleteBase(&base);
    ASSERT_EQ(base.telephoneCount_, 0);
}

TEST(telephone, print) {
    base_t base;
    CreateBase(&base);
    Add(&base, 1, 1234567, "Zakhar");
    Add(&base, 2, 1234567, "Alex");
    testing::internal::CaptureStdout();
    Print(&base);
    std::string output = testing::internal::GetCapturedStdout();
    std::string answer = "+11234567 - Zakhar\n"
                         "+21234567 - Alex\n";
    ASSERT_EQ(output, answer);
    DeleteBase(&base);
}

TEST(telephone, sort) {
    base_t base;
    CreateBase(&base);
    Add(&base, 4, 1234567, "Zakhar");
    Add(&base, 2, 1234567, "Alex");
    Add(&base, 1, 1234567, "Anton");
    Add(&base, 3, 1234567, "Daria");
    Sort(&base);
    testing::internal::CaptureStdout();
    Print(&base);
    std::string output = testing::internal::GetCapturedStdout();
    std::string answer = "+11234567 - Anton\n"
                         "+21234567 - Alex\n"
                         "+31234567 - Daria\n"
                         "+41234567 - Zakhar\n";
    ASSERT_EQ(output, answer);
    DeleteBase(&base);
}