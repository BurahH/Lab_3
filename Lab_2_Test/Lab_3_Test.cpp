#include "pch.h"
#include "CppUnitTest.h"

#include "../АИСД_Lab_2/Class.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab2Test
{
	TEST_CLASS(Test_Classcpp)
	{
	public:
		
		TEST_METHOD(Test_contains)
		{
			Binary_Tree tree;
			tree.insert(8);
			tree.insert(10);
			tree.insert(3);
			tree.insert(1);
			tree.insert(6);
			tree.insert(4);
            Assert::AreEqual(tree.contains(8), true);
			Assert::AreEqual(tree.contains(10), true);
			Assert::AreEqual(tree.contains(3), true);
			Assert::AreEqual(tree.contains(1), true);
			Assert::AreEqual(tree.contains(6), true);
			Assert::AreEqual(tree.contains(4), true);
			Assert::AreEqual(tree.contains(11), false);
			Assert::AreEqual(tree.contains(2), false);
			Assert::AreEqual(tree.contains(5), false);
		}
		TEST_METHOD(Test_insert)
		{
			Binary_Tree tree;
			tree.insert(8);
			tree.insert(10);
			tree.insert(3);
			tree.insert(1);
			tree.insert(6);
			tree.insert(4);
			Assert::AreEqual(tree.contains(8), true);
			Assert::AreEqual(tree.contains(10), true);
			Assert::AreEqual(tree.contains(3), true);
			Assert::AreEqual(tree.contains(1), true);
			Assert::AreEqual(tree.contains(6), true);
			Assert::AreEqual(tree.contains(4), true);
		}
		TEST_METHOD(Test_remove_no_descemdants)
		{
			Binary_Tree tree;
			tree.insert(8);
			tree.insert(10);
			tree.insert(3);
			tree.insert(1);
			tree.insert(6);
			tree.insert(4);
			tree.remove(4);
			Assert::AreEqual(tree.contains(8), true);
			Assert::AreEqual(tree.contains(10), true);
			Assert::AreEqual(tree.contains(3), true);
			Assert::AreEqual(tree.contains(1), true);
			Assert::AreEqual(tree.contains(6), true);
			Assert::AreEqual(tree.contains(4), false);
			tree.remove(1);
			Assert::AreEqual(tree.contains(8), true);
			Assert::AreEqual(tree.contains(10), true);
			Assert::AreEqual(tree.contains(3), true);
			Assert::AreEqual(tree.contains(1), false);
			Assert::AreEqual(tree.contains(6), true);
			Assert::AreEqual(tree.contains(4), false);
			tree.remove(10);
			Assert::AreEqual(tree.contains(8), true);
			Assert::AreEqual(tree.contains(10), false);
			Assert::AreEqual(tree.contains(3), true);
			Assert::AreEqual(tree.contains(1), false);
			Assert::AreEqual(tree.contains(6), true);
			Assert::AreEqual(tree.contains(4), false);
			tree.remove(6);
			Assert::AreEqual(tree.contains(8), true);
			Assert::AreEqual(tree.contains(10), false);
			Assert::AreEqual(tree.contains(3), true);
			Assert::AreEqual(tree.contains(1), false);
			Assert::AreEqual(tree.contains(6), false);
			Assert::AreEqual(tree.contains(4), false);
			tree.remove(3);
			Assert::AreEqual(tree.contains(8), true);
			Assert::AreEqual(tree.contains(10), false);
			Assert::AreEqual(tree.contains(3), false);
			Assert::AreEqual(tree.contains(1), false);
			Assert::AreEqual(tree.contains(6), false);
			Assert::AreEqual(tree.contains(4), false);
			tree.remove(8);
			Assert::AreEqual(tree.contains(8), false);
			Assert::AreEqual(tree.contains(10), false);
			Assert::AreEqual(tree.contains(3), false);
			Assert::AreEqual(tree.contains(1), false);
			Assert::AreEqual(tree.contains(6), false);
			Assert::AreEqual(tree.contains(4), false);
		}
		TEST_METHOD(Test_remove_one_descemdants)
		{
			Binary_Tree tree;
			tree.insert(8);
			tree.insert(10);
			tree.insert(3);
			tree.insert(1);
			tree.insert(6);
			tree.insert(4);
			tree.remove(6);
			Assert::AreEqual(tree.contains(8), true);
			Assert::AreEqual(tree.contains(10), true);
			Assert::AreEqual(tree.contains(3), true);
			Assert::AreEqual(tree.contains(1), true);
			Assert::AreEqual(tree.contains(6), false);
			Assert::AreEqual(tree.contains(4), true);
			tree.remove(10);
			Assert::AreEqual(tree.contains(8), true);
			Assert::AreEqual(tree.contains(10), false);
			Assert::AreEqual(tree.contains(3), true);
			Assert::AreEqual(tree.contains(1), true);
			Assert::AreEqual(tree.contains(6), false);
			Assert::AreEqual(tree.contains(4), true);
			tree.remove(8);
			Assert::AreEqual(tree.contains(8), false);
			Assert::AreEqual(tree.contains(10), false);
			Assert::AreEqual(tree.contains(3), true);
			Assert::AreEqual(tree.contains(1), true);
			Assert::AreEqual(tree.contains(6), false);
			Assert::AreEqual(tree.contains(4), true);
		}
		TEST_METHOD(Test_remove_two_descemdants)
		{
			Binary_Tree tree;
			tree.insert(8);
			tree.insert(10);
			tree.insert(3);
			tree.insert(1);
			tree.insert(6);
			tree.insert(4);
			tree.remove(3);
			Assert::AreEqual(tree.contains(8), true);
			Assert::AreEqual(tree.contains(10), true);
			Assert::AreEqual(tree.contains(3), false);
			Assert::AreEqual(tree.contains(1), true);
			Assert::AreEqual(tree.contains(6), true);
			Assert::AreEqual(tree.contains(4), true);
			tree.remove(4);
			Assert::AreEqual(tree.contains(8), true);
			Assert::AreEqual(tree.contains(10), true);
			Assert::AreEqual(tree.contains(3), false);
			Assert::AreEqual(tree.contains(1), true);
			Assert::AreEqual(tree.contains(6), true);
			Assert::AreEqual(tree.contains(4), false);
			tree.remove(8);
			Assert::AreEqual(tree.contains(8), false);
			Assert::AreEqual(tree.contains(10), true);
			Assert::AreEqual(tree.contains(3), false);
			Assert::AreEqual(tree.contains(1), true);
			Assert::AreEqual(tree.contains(6), true);
			Assert::AreEqual(tree.contains(4), false);
		}

		TEST_METHOD(Test_DFT)
		{
			Binary_Tree tree;
			ListStack stack;
			tree.insert(8);
			tree.insert(10);
			tree.insert(14);
			tree.insert(13);
			tree.insert(3);
			tree.insert(1);
			tree.insert(6);
			tree.insert(4);
			tree.insert(7);
			myiterator* lst_iterator = tree.create_DFT_itetator();
			Assert::AreEqual(lst_iterator->next(&stack), 8);
			Assert::AreEqual(lst_iterator->next(&stack), 3);
			Assert::AreEqual(lst_iterator->next(&stack), 1);
			Assert::AreEqual(lst_iterator->next(&stack), 6);
			Assert::AreEqual(lst_iterator->next(&stack), 4);
			Assert::AreEqual(lst_iterator->next(&stack), 7);
			Assert::AreEqual(lst_iterator->next(&stack), 10);
			Assert::AreEqual(lst_iterator->next(&stack), 14);
			Assert::AreEqual(lst_iterator->next(&stack), 13);
		}
		TEST_METHOD(Test_BFT)
		{
			Binary_Tree tree;
			ListQueue queue;
			tree.insert(8);
			tree.insert(10);
			tree.insert(14);
			tree.insert(13);
			tree.insert(3);
			tree.insert(1);
			tree.insert(6);
			tree.insert(4);
			tree.insert(7);
			myiterator* lst_iterator = tree.create_BFT_itetator();
			Assert::AreEqual(lst_iterator->next(&queue), 8);
			Assert::AreEqual(lst_iterator->next(&queue), 3);
			Assert::AreEqual(lst_iterator->next(&queue), 10);
			Assert::AreEqual(lst_iterator->next(&queue), 1);
			Assert::AreEqual(lst_iterator->next(&queue), 6);
			Assert::AreEqual(lst_iterator->next(&queue), 14);
			Assert::AreEqual(lst_iterator->next(&queue), 4);
			Assert::AreEqual(lst_iterator->next(&queue), 7);
			Assert::AreEqual(lst_iterator->next(&queue), 13);
		}
		TEST_METHOD(Test_stack_add_item)
		{
			ListStack stack;
			Tree tree(1);
			Tree tree1(2);
			Tree tree2(3);
			Tree tree3(4);
			Tree tree4(5);
			stack.add_item(&tree);
			Assert::AreEqual(stack.gettree()->data, 1);
			stack.add_item(&tree1);
			Assert::AreEqual(stack.gettree()->data, 2);
			stack.add_item(&tree2);
			Assert::AreEqual(stack.gettree()->data, 3);
			stack.add_item(&tree3);
			Assert::AreEqual(stack.gettree()->data, 4);
			stack.add_item(&tree4);
			Assert::AreEqual(stack.gettree()->data, 5);
		}
		TEST_METHOD(Test_stack_delete_item)
		{
			try {
				ListStack stack;
				Tree tree(1);
				Tree tree1(2);
				Tree tree2(3);
				Tree tree3(4);
				stack.add_item(&tree);
				stack.add_item(&tree1);
				stack.add_item(&tree2);
				stack.add_item(&tree3);
				stack.delete_item();
				Assert::AreEqual(stack.gettree()->data, 3);
				stack.delete_item();
				Assert::AreEqual(stack.gettree()->data, 2);
				stack.delete_item();
				Assert::AreEqual(stack.gettree()->data, 1);
				stack.delete_item();
				stack.delete_item();
			}
			catch (const std::out_of_range expection)
			{
				Assert::AreEqual("deletion isn't possible, the list is empty", expection.what());
			}
		}
		TEST_METHOD(Test_stack_get_tree)
		{
			try {
				ListStack stack;
				Tree tree(1);
				stack.add_item(&tree);
				Assert::AreEqual(stack.gettree()->data, 1);
				stack.delete_item();
				stack.gettree();
			}
			catch (const std::out_of_range expection)
			{
				Assert::AreEqual("The stack is empty", expection.what());
			}
		}
		TEST_METHOD(Test_stack_empty)
		{
			ListStack stack;
			Tree tree(1);
			stack.add_item(&tree);
			Assert::AreEqual(stack.Empty(), false);
			stack.delete_item();
			Assert::AreEqual(stack.Empty(), true);
		}

		TEST_METHOD(Test_queue_add_item)
		{
			ListQueue queue;
			Tree tree(1);
			Tree tree1(2);
			queue.add_item(&tree);
			Assert::AreEqual(queue.gettree()->data, 1);
			queue.add_item(&tree1);
			Assert::AreEqual(queue.gettree()->data, 1);
		}
		TEST_METHOD(Test_queue_delete_item)
		{
			try {
				ListQueue queue;
				Tree tree(1);
				Tree tree1(2);
				Tree tree2(3);
				Tree tree3(4);
				queue.add_item(&tree);
				queue.add_item(&tree1);
				queue.add_item(&tree2);
				queue.add_item(&tree3);
				queue.delete_item();
				Assert::AreEqual(queue.gettree()->data, 2);
				queue.delete_item();
				Assert::AreEqual(queue.gettree()->data, 3);
				queue.delete_item();
				Assert::AreEqual(queue.gettree()->data, 4);
				queue.delete_item();
				queue.delete_item();
			}
			catch (const std::out_of_range expection)
			{
				Assert::AreEqual("deletion isn't possible, the list is empty", expection.what());
			}
		}
		TEST_METHOD(Test_queue_get_tree)
		{
			try {
				ListQueue queue;
				Tree tree(1);
				queue.add_item(&tree);
				Assert::AreEqual(queue.gettree()->data, 1);
				queue.delete_item();
				queue.gettree();
			}
			catch (const std::out_of_range expection)
			{
				Assert::AreEqual("The stack is empty", expection.what());
			}
		}
		TEST_METHOD(Test_queue_empty)
		{
			ListQueue queue;
			Tree tree(1);
			queue.add_item(&tree);
			Assert::AreEqual(queue.Empty(), false);
			queue.delete_item();
			Assert::AreEqual(queue.Empty(), true);
		}
	};
}
