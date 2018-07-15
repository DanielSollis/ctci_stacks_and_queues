#include "pound_queue.h"
#include <ctype.h>

bool Pound_queue::enqueue(char animel_type) {
	if (toupper(animel_type) != 'C' && toupper(animel_type) != 'D') {
		return false;
	}
	else {
		bool is_cat = toupper(animel_type) == 'C';
		Animal animal{ is_cat, time(nullptr)};
		is_cat ? cat_queue.push_back(animal) : dog_queue.push_back(animal);
		return true;
	}
}


bool Pound_queue::dequeue_any() {
	bool result = false;
	if (cat_queue.front().arrival_time < dog_queue.front().arrival_time) {
		result = dequeue_cat();
	}
	else {
		result = dequeue_dog();
	}
	return result;
}


bool Pound_queue::dequeue_dog() {
	if (!dog_queue.empty()) {
		dog_queue.pop_front();
		return true;
	}
	return false;
}


bool Pound_queue::dequeue_cat() {
	if (!cat_queue.empty()) {
		cat_queue.pop_front();
		return true;
	}
	return false;
}