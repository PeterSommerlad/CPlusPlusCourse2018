#include "ThreadSafeQueue.h"

#include <future>
#include <string>
#include <chrono>
#include <iostream>
#include <utility>
#include <thread>
#include <ostream>

using Task = std::packaged_task<std::string(unsigned)>;
using TaskQueue = threadsafe_queue<Task>;

void processTasks(TaskQueue & queue) {
	unsigned counter{};
	while (true) {
		auto task = queue.pop();
		task(counter++);
	}
}

void createAndConsume(std::ostream & out, TaskQueue & queue) {
	while (true) {
		Task task{[](unsigned value) {
				using namespace std::string_literals;
				using namespace std::chrono_literals;
				std::this_thread::sleep_for(0.5s);
				return "This is task #"s + std::to_string(value);
			}
		};
		auto future = task.get_future();
		out << "pushing task to queue...\n" << std::flush;
		queue.push(std::move(task));
		out << "waiting for future...\n" << std::flush;
		future.wait();
		out << "result is: " << future.get() << '\n' << std::flush;
	}
}

int main() {
	TaskQueue taskQueue{};
	std::thread processor{[&taskQueue]{
		processTasks(taskQueue);
	}};
	createAndConsume(std::cout, taskQueue);
}
