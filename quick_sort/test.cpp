#include "quick_sort.h"
#include <gtest/gtest.h>

TEST(swap_test, test_for_int){
    int element_1 = 2;
int element_2 = 3;
swap (element_1, element_2);
EXPECT_EQ (2, element_2);
EXPECT_EQ (3, element_1);
}
TEST(swap_test, test_for_arr) {
int arr[] = {1, 2};
swap (arr[0], arr[1]);
EXPECT_EQ (1, arr[1]);
EXPECT_EQ (2, arr[0]);
}
TEST(partition_test, test) {
    int arr[] = {10, 80, 30, 90, 40};
    int sol[] = {10, 30, 40, 90, 80};
    partition (arr, 0, 4);
    for (int index = 0; index < 5; index ++)
    EXPECT_EQ (arr[index], sol[index]);
}
TEST(quick_sort_test, test) {
    int arr[] = {-4, -10, -3, -5, -1};
    int sol[] = {-10, -5, -4, -3, -1};
    int number_of_elements = sizeof(arr) / sizeof(arr[0]);
    quick_sort(arr, 0, number_of_elements - 1);

    for (int i = 0; i < number_of_elements; ++i)
        EXPECT_EQ(arr[i], sol[i]);
}
int main(int argc, char ** argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}