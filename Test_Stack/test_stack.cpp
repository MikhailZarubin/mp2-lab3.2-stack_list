#include "gtest.h"
#include "../Stack/Stack.h"


TEST(Stack, can_create_stack)
{
  ASSERT_NO_THROW(Stack<int> s);
}

TEST(Stack, can_copy_the_stack)
{
  Stack<int> s;
  s.Push(5);
 ASSERT_NO_THROW(Stack<int> copy(s));
}

TEST(Stack, the_copied_stack_is_the_same_as_the_original_one)
{
    Stack<int> s;
    s.Push(5);
    Stack<int> copy(s);
    EXPECT_EQ(s.Pop(), copy.Pop());
}
TEST(Stack, when_you_change_the_original_stack_the_copied_stack_does_not_change)
{
    Stack<int> s;
    s.Push(5);
    Stack<int> copy(s);
    copy.Pop();
    EXPECT_EQ(true, copy.Empty());
    EXPECT_EQ(5, s.Top());
}
TEST(Stack, can_assign_stacks_of_the_same_data_types)
{
    Stack<int> s1;
    Stack<int> s2;
    s1.Push(5);
    s1.Push(7);
    s2.Push(3);
    ASSERT_NO_THROW(s2 = s1);
    EXPECT_EQ(s1.Pop(), s2.Pop());
}

TEST(Stack, can_compare_stacks)
{
    Stack<int> s1;
    Stack<int> s2;
    s1.Push(5);
    s2.Push(3);
    ASSERT_NO_THROW(s2 == s1);
}

TEST(Stack, comparing_the_stack_with_itself_gives_the_truth)
{
    Stack<int> s;
    EXPECT_EQ(true, s == s);
}

TEST(Stack, comparing_the_same_stack_gives_the_truth)
{
    Stack<int> s1;
    Stack<int> s2;
    s1.Push(5);
    s2.Push(5);
    EXPECT_EQ(true, s1 == s2);
}

TEST(Stack, comparing_different_stack_gives_the_lie)
{
    Stack<int> s1;
    Stack<int> s2;
    s1.Push(0);
    s2.Push(5);
    EXPECT_EQ(true, s1 != s2);
}
TEST(Stack, can_check_the_stack_for_emptiness)
{
    Stack<int> s;
    ASSERT_NO_THROW(s.Empty());
}
TEST(Stack, initially_the_stack_is_empty)
{
    Stack<int> s;
    EXPECT_EQ(true, s.Empty());
}
TEST(Stack, checking_for_the_emptiness_of_a_non_empty_stack_returns_false)
{
    Stack<int> s;
    s.Push(5);
    EXPECT_EQ(false, s.Empty());
}
TEST(Stack, can_add_an_item_to_an_incomplete_stack)
{
    Stack<int> s;
    ASSERT_NO_THROW(s.Push(5));
}
TEST(Stack, can_see_what_is_at_the_top_of_a_non_empty_stack)
{
    Stack<int> s;
    s.Push(5);
    ASSERT_NO_THROW(s.Top());
}
TEST(Stack, viewing_the_top_of_the_stack_does_not_change_the_state_of_the_stack)
{
    Stack<int> s;
    s.Push(5);
    int a=s.Top();
    EXPECT_EQ(a, s.Top());
}
TEST(Stack, cant_look_at_the_top_of_an_empty_stack)
{
    Stack<int> s;
    ASSERT_ANY_THROW(s.Top());
}
TEST(Stack, can_take_an_element_from_a_non_empty_non_empty_stack)
{
        Stack<int> s;
        s.Push(5);
        ASSERT_NO_THROW(s.Pop());
}
TEST(Stack, taking_an_element_from_the_stack_reduces_its_size_by_one)
{
    Stack<int> s;
    s.Push(5);
    s.Pop();
    EXPECT_EQ(true, s.Empty());
}
TEST(Stack, cant_take_an_element_from_an_empty_stack)
{
    Stack<int> s;
    ASSERT_ANY_THROW(s.Pop());
}