#pragma once
#include <list>
#include <time.h>

class Pound_queue {
private:
	struct Animal {
		bool is_cat;
		time_t arrival_time;
	};

	std::list<Animal> cat_queue;
	std::list<Animal> dog_queue;
public:
	bool enqueue(char animel_type);
	bool dequeue_any();
	bool dequeue_dog();
	bool dequeue_cat();
};