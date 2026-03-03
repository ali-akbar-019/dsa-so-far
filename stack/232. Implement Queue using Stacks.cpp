
class MyQueue
{
public:
    stack<int> input;
    stack<int> output;
    int peekEl = -1;
    MyQueue()
    {
    }

    void push(int x)
    {
        // agar first ha then is ko peek me store karo
        if (input.empty())
        {
            peekEl = x;
        }
        input.push(x);
    }

    int pop()
    {
        if (output.empty())
        {
            // first push in the output
            while (!input.empty())
            {
                int val = input.top();
                input.pop();
                output.push(val);
            }
            //
        }
        int val = output.top();
        output.pop();
        return val;
    }

    int peek()
    {
        if (output.empty())
        {
            return peekEl;
        }
        return output.top();
    }

    bool empty()
    {
        return input.empty() && output.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */