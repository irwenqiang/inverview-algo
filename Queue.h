#include <stdio.h>
#include <stack>
#include <exception>

using namespace std;

template <typename T> class iQueue {
	public:
		iQueue();
		~iQueue();

		void append(const T& node);

		T pop();
	private:
		stack<T> stackin;
		stack<T> stackout;
};

template <typename T> iQueue<T>::iQueue(){}

template <typename T> iQueue<T>::~iQueue() {}

template <typename T> void iQueue<T>::append(const T& node) {
	stackin.push(node);
}

template <typename T> T iQueue<T>::pop() {
	if(stackout.size() <= 0) {
		while(stackin.size() > 0) {
			T& data = stackin.top();
			stackin.pop();
			stackout.push(data);
		}
	}

	if (stackout.size() == 0)
		return 'n';
	
	T head = stackout.top();
	stackout.pop();

	return head;
}


