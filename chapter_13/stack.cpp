#include <iostream>
#include <cassert>
#include <array>

class Stack
{   
    using Array = std::array<int, 10>;
    using Size = Array::size_type;
    private:
        Array m_stack{};
        Size m_stack_size{};

    public:
        void reset()
        {
            m_stack_size = 0;
        }

        bool push(int value)
        {
            if (m_stack_size == m_stack.size())
                return false;
            
            m_stack[m_stack_size++] = value;
            return true;
        }

        int pop()
        {
            assert(m_stack_size > 0 && "Cannot pop from empty stack");
            return m_stack[--m_stack_size];
        }

        void print()
        {   
            std::cout << "( ";
            for (int i{ 0 }; i < m_stack_size; ++i)
            {
                std::cout << m_stack[i] << ' ';
            }
            std::cout << ")\n";
        }
};

int main()
{
	Stack stack;
	stack.print();

	stack.push(5);
	stack.push(3);
	stack.push(8);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();

	stack.print();

	return 0;
}
